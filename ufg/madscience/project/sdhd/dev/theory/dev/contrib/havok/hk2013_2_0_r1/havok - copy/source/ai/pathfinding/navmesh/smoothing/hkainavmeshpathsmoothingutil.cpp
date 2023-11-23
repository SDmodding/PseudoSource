// File Line: 50
// RVA: 0xC00D00
__int64 __fastcall hkaiNavMeshPathSmoothingUtil::findSmoothedPathMain(
        hkaiStreamingCollection::InstanceInfo *sectionInfo,
        hkArray<unsigned int,hkContainerHeapAllocator> *visitedEdges,
        unsigned int startFaceKey,
        hkVector4f *startPoint,
        hkVector4f *endPoint,
        unsigned int project,
        unsigned int computeNormals,
        hkVector4f *up,
        float radius,
        bool useSimpleSmoothing,
        hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *pathArrayOut,
        hkaiPath::PathPoint *pathPtrOut,
        int maxPathLength,
        hkSimdFloat32 *stringPulledLength)
{
  unsigned int SimpleSmoothPath; // ebx
  bool v18; // al
  hkaiGeneralAccessor accessor; // [rsp+60h] [rbp-1C8h] BYREF
  hkaiPathWriter writer; // [rsp+80h] [rbp-1A8h] BYREF
  hkaiStringPulling v22; // [rsp+C0h] [rbp-168h] BYREF
  hkaiNavMeshPathSmoothingUtil v23; // [rsp+1D0h] [rbp-58h] BYREF

  accessor.m_sectionInfo = sectionInfo;
  accessor.m_currentSection = -1;
  accessor.m_accessor = 0i64;
  hkaiPathWriter::hkaiPathWriter(&writer);
  hkaiPathWriter::init(&writer, pathArrayOut, pathPtrOut, maxPathLength);
  if ( useSimpleSmoothing )
  {
    hkaiNavMeshPathSmoothingUtil::hkaiNavMeshPathSmoothingUtil(
      &v23,
      &accessor,
      visitedEdges,
      startFaceKey,
      startPoint,
      endPoint,
      up,
      radius,
      &writer);
    SimpleSmoothPath = hkaiNavMeshPathSmoothingUtil::findSimpleSmoothPath(&v23, computeNormals);
  }
  else
  {
    hkaiStringPulling::hkaiStringPulling(
      &v22,
      &accessor,
      visitedEdges,
      startFaceKey,
      startPoint,
      endPoint,
      project,
      computeNormals,
      up,
      radius,
      &writer);
    v18 = hkaiStringPulling::stringPull(&v22);
    v22.m_funnel.m_data.m_size = 0;
    SimpleSmoothPath = v18;
    if ( v22.m_funnel.m_data.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        v22.m_funnel.m_data.m_data,
        48 * (v22.m_funnel.m_data.m_capacityAndFlags & 0x3FFFFFFF));
    v22.m_funnel.m_data.m_data = 0i64;
    v22.m_funnel.m_data.m_capacityAndFlags = 0x80000000;
    hkaiStringPulling::PathEdgeCache::~PathEdgeCache(&v22.m_pathEdgeCache);
  }
  if ( stringPulledLength )
    *stringPulledLength = writer.m_totalDistance;
  return SimpleSmoothPath;
}

// File Line: 93
// RVA: 0xC00ED0
_BOOL8 __fastcall hkaiNavMeshPathSmoothingUtil::projectStraightPath(
        hkaiStreamingCollection::InstanceInfo *sectionInfo,
        hkArray<unsigned int,hkContainerHeapAllocator> *visitedEdges,
        unsigned int startFaceKey,
        hkVector4f *startPoint,
        hkVector4f *endPoint,
        unsigned int project,
        unsigned int computeNormals,
        hkVector4f *up,
        float radius,
        hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *pathArrayOut,
        hkaiPath::PathPoint *pathPtrOut,
        int maxPathLength)
{
  int m_size; // eax
  __m128 m_quad; // xmm0
  bool v17; // cf
  bool v18; // zf
  bool v19; // al
  BOOL v20; // ebx
  hkaiStringPulling::Vertex a; // [rsp+60h] [rbp-A0h] BYREF
  hkaiStringPulling::Vertex b; // [rsp+90h] [rbp-70h] BYREF
  hkaiGeneralAccessor accessor; // [rsp+C0h] [rbp-40h] BYREF
  hkaiPathWriter writer; // [rsp+E0h] [rbp-20h] BYREF
  hkaiStringPulling v26; // [rsp+120h] [rbp+20h] BYREF

  accessor.m_sectionInfo = sectionInfo;
  accessor.m_currentSection = -1;
  accessor.m_accessor = 0i64;
  hkaiPathWriter::hkaiPathWriter(&writer);
  hkaiPathWriter::init(&writer, pathArrayOut, pathPtrOut, maxPathLength);
  hkaiStringPulling::hkaiStringPulling(
    &v26,
    &accessor,
    visitedEdges,
    startFaceKey,
    startPoint,
    endPoint,
    project,
    computeNormals,
    up,
    radius,
    &writer);
  m_size = visitedEdges->m_size;
  a.m_pos = (hkVector4f)startPoint->m_quad;
  a.m_center = a.m_pos;
  m_quad = endPoint->m_quad;
  a.m_clearanceIsNegative.m_bool = startPoint->m_quad.m128_f32[3] < 0.0;
  v17 = endPoint->m_quad.m128_f32[3] > 0.0;
  v18 = endPoint->m_quad.m128_f32[3] == 0.0;
  b.m_pos.m_quad = m_quad;
  b.m_center.m_quad = m_quad;
  *(_WORD *)&a.m_userEdge.m_bool = 0;
  b.m_userEdgeSwapped.m_bool = 0;
  *(_WORD *)&b.m_clearanceIsNegative.m_bool = !v17 && !v18;
  *(_WORD *)&a.m_side.m_storage = 511;
  a.m_index = -1;
  *(_WORD *)&b.m_side.m_storage = 767;
  b.m_index = m_size;
  hkaiStringPulling::addSegmentToPath(&v26, &a, &b);
  v19 = hkaiStringPulling::terminateOutput(&v26);
  v26.m_funnel.m_data.m_size = 0;
  v20 = v19;
  if ( v26.m_funnel.m_data.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      v26.m_funnel.m_data.m_data,
      48 * (v26.m_funnel.m_data.m_capacityAndFlags & 0x3FFFFFFF));
  v26.m_funnel.m_data.m_data = 0i64;
  v26.m_funnel.m_data.m_capacityAndFlags = 0x80000000;
  hkaiStringPulling::PathEdgeCache::~PathEdgeCache(&v26.m_pathEdgeCache);
  return v20;
}

// File Line: 135
// RVA: 0xC01DC0
__int64 __fastcall getLineSegInterpolationValue(
        hkVector4f *A,
        hkVector4f *dA,
        hkVector4f *B,
        hkVector4f *dB,
        float *uOut)
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
  __int64 result; // rax
  float v21; // xmm2_4
  unsigned int v22; // ecx
  float v23; // xmm0_4

  v5 = _mm_sub_ps(B->m_quad, A->m_quad);
  v6 = _mm_mul_ps(dB->m_quad, dA->m_quad);
  v7 = (float)(_mm_shuffle_ps(v6, v6, 85).m128_f32[0] + _mm_shuffle_ps(v6, v6, 0).m128_f32[0])
     + _mm_shuffle_ps(v6, v6, 170).m128_f32[0];
  v8 = _mm_mul_ps(dA->m_quad, v5);
  v9 = _mm_mul_ps(dA->m_quad, dA->m_quad);
  v10 = (float)(_mm_shuffle_ps(v8, v8, 85).m128_f32[0] + _mm_shuffle_ps(v8, v8, 0).m128_f32[0])
      + _mm_shuffle_ps(v8, v8, 170).m128_f32[0];
  v11 = _mm_mul_ps(dB->m_quad, v5);
  v12 = _mm_mul_ps(dB->m_quad, dB->m_quad);
  v13 = (float)(_mm_shuffle_ps(v11, v11, 85).m128_f32[0] + _mm_shuffle_ps(v11, v11, 0).m128_f32[0])
      + _mm_shuffle_ps(v11, v11, 170).m128_f32[0];
  v14 = (float)(_mm_shuffle_ps(v9, v9, 85).m128_f32[0] + _mm_shuffle_ps(v9, v9, 0).m128_f32[0])
      + _mm_shuffle_ps(v9, v9, 170).m128_f32[0];
  v15 = *(float *)&FLOAT_1_0;
  v16 = (float)(_mm_shuffle_ps(v12, v12, 85).m128_f32[0] + _mm_shuffle_ps(v12, v12, 0).m128_f32[0])
      + _mm_shuffle_ps(v12, v12, 170).m128_f32[0];
  v17 = (float)(v16 * v10) - (float)(v13 * v7);
  LODWORD(v18) = (unsigned int)(2 * COERCE_INT((float)(v16 * v14) - (float)(v7 * v7))) >> 1;
  if ( (float)(v17 * v18) >= (float)(v18 * v18) )
    goto LABEL_6;
  if ( v17 <= 0.0 )
  {
    v19 = 0.0;
    result = 2i64;
    goto LABEL_7;
  }
  if ( v18 <= (float)((float)((float)(v7 * v7) + (float)(v16 * v14)) * 0.00000095367432) )
  {
LABEL_6:
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
void __fastcall getProjectedMidpoint(
        hkVector4f *apex,
        hkVector4f *edgeA,
        hkVector4f *edgeB,
        float tA,
        float tB,
        hkVector4f *portalA,
        hkVector4f *portalB,
        hkVector4f *collapse)
{
  __m128 v8; // xmm4
  __m128 v10; // xmm0
  __m128 v11; // xmm4
  __m128 v12; // xmm14
  __m128 v13; // xmm1
  __m128 v14; // xmm11
  __m128 v15; // xmm9
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm7
  __m128 v19; // xmm1
  __m128 v20; // xmm8
  __m128 v21; // xmm6
  __m128 v22; // xmm4
  __m128 v23; // xmm1
  __m128 v24; // xmm3
  __m128 v25; // xmm1
  __m128 v26; // xmm5
  __m128 v27; // xmm6
  __m128 v28; // xmm0
  __m128 v29; // xmm0
  __m128 v30; // xmm3
  __m128 v31; // xmm3
  __m128 v32; // xmm0
  __m128 v33; // xmm1
  __m128 v34; // xmm7
  __m128 v35; // xmm1
  __m128 v36; // xmm14
  __m128 v37; // xmm1
  __m128 v38; // xmm2
  __m128 v39; // xmm3
  __m128 v40; // xmm6
  __m128 v41; // xmm5
  __m128 v42; // xmm4
  __m128 v43; // xmm1
  __m128 v44; // xmm3
  __m128 v45; // xmm1
  __m128 v46; // xmm15
  __m128 v47; // xmm5
  __m128 v48; // xmm1
  __m128 v49; // xmm0
  __m128 v50; // xmm4
  __m128 v51; // xmm4
  __m128 v52; // xmm2
  __m128 v53; // xmm2
  __m128 v54; // [rsp+0h] [rbp-C8h]
  __m128 v55; // [rsp+10h] [rbp-B8h]
  float portalAa; // [rsp+F8h] [rbp+30h]

  v8.m128_f32[0] = tA;
  v10 = _mm_sub_ps(edgeB->m_quad, edgeA->m_quad);
  v11 = _mm_sub_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), v10), edgeA->m_quad), apex->m_quad);
  v55 = _mm_sub_ps(
          _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(tB), (__m128)LODWORD(tB), 0), v10), edgeA->m_quad),
          apex->m_quad);
  v12 = _mm_sub_ps(portalA->m_quad, apex->m_quad);
  v54 = _mm_sub_ps(portalB->m_quad, portalA->m_quad);
  v13 = _mm_mul_ps(v54, v11);
  v14 = _mm_mul_ps(v54, v54);
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  v16 = _mm_mul_ps(v12, v11);
  v17 = _mm_mul_ps(v11, v11);
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  v19 = _mm_mul_ps(v12, v54);
  v20 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v21 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)), _mm_shuffle_ps(v14, v14, 170));
  v22 = _mm_max_ps(
          _mm_sub_ps(
            _mm_mul_ps(
              v21,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
                _mm_shuffle_ps(v17, v17, 170))),
            _mm_mul_ps(v15, v15)),
          *(__m128 *)&epsilon);
  v23 = _mm_rcp_ps(v22);
  v24 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v23, v22)), v23);
  v25 = _mm_rcp_ps(v21);
  v26 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v25, v21)), v25);
  v27 = _mm_sub_ps(_mm_mul_ps(v21, v18), _mm_mul_ps(v20, v15));
  v28 = _mm_cmplt_ps(v27, v22);
  v29 = _mm_mul_ps(_mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v28, v22), _mm_and_ps(v27, v28))), v24);
  v30 = _mm_cmple_ps(v22, *(__m128 *)&epsilon);
  v31 = _mm_sub_ps(
          _mm_mul_ps(_mm_or_ps(_mm_andnot_ps(v30, v29), _mm_and_ps(v30, query.m_quad)), _mm_mul_ps(v26, v15)),
          _mm_mul_ps(v26, v20));
  v32 = _mm_cmplt_ps(v31, query.m_quad);
  v20.m128_f32[0] = fmax(
                      0.0,
                      COERCE_FLOAT(_mm_andnot_ps(v32, query.m_quad).m128_u32[0] | v31.m128_i32[0] & v32.m128_i32[0]));
  v33 = _mm_mul_ps(v54, v55);
  v34 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)), _mm_shuffle_ps(v33, v33, 170));
  v35 = v12;
  v36 = _mm_mul_ps(v12, v54);
  v37 = _mm_mul_ps(v35, v55);
  v38 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)), _mm_shuffle_ps(v37, v37, 170));
  v39 = _mm_mul_ps(v55, v55);
  v40 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)), _mm_shuffle_ps(v36, v36, 170));
  v41 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)), _mm_shuffle_ps(v14, v14, 170));
  v42 = _mm_max_ps(
          _mm_sub_ps(
            _mm_mul_ps(
              v41,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)),
                _mm_shuffle_ps(v39, v39, 170))),
            _mm_mul_ps(v34, v34)),
          *(__m128 *)&epsilon);
  v43 = _mm_rcp_ps(v42);
  v44 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v43, v42)), v43);
  v45 = _mm_rcp_ps(v41);
  v46 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v45, v41)), v45);
  v47 = _mm_sub_ps(_mm_mul_ps(v41, v38), _mm_mul_ps(v40, v34));
  v48 = _mm_cmplt_ps(v47, v42);
  v49 = _mm_or_ps(_mm_andnot_ps(v48, v42), _mm_and_ps(v47, v48));
  v50 = _mm_cmple_ps(v42, *(__m128 *)&epsilon);
  v51 = _mm_sub_ps(
          _mm_mul_ps(
            _mm_or_ps(
              _mm_andnot_ps(v50, _mm_mul_ps(_mm_max_ps(aabbOut.m_quad, v49), v44)),
              _mm_and_ps(v50, query.m_quad)),
            _mm_mul_ps(v46, v34)),
          _mm_mul_ps(v46, v40));
  v52 = _mm_cmplt_ps(v51, query.m_quad);
  portalAa = fmax(0.0, COERCE_FLOAT(_mm_andnot_ps(v52, query.m_quad).m128_u32[0] | v51.m128_i32[0] & v52.m128_i32[0]));
  v53 = (__m128)LODWORD(portalAa);
  v53.m128_f32[0] = (float)(fminf(fmaxf(portalAa, 0.050000001), 0.94999999)
                          + fminf(fmaxf(v20.m128_f32[0], 0.050000001), 0.94999999))
                  * 0.5;
  collapse->m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v53, v53, 0), v54), portalA->m_quad);
}

// File Line: 244
// RVA: 0xC01090
_BOOL8 __fastcall hkaiNavMeshPathSmoothingUtil::findSimpleSmoothPath(
        hkaiNavMeshPathSmoothingUtil *this,
        unsigned int computeNormals)
{
  int v2; // r13d
  hkaiNavMeshPathSmoothingUtil *v4; // rsi
  __int64 m_size; // rdi
  int v6; // ebx
  int v7; // r15d
  hkLifoAllocator *Value; // rax
  int v9; // edx
  char *v10; // rcx
  hkLifoAllocator *v11; // rax
  __m128 *v12; // r15
  int v13; // edx
  char *v14; // rcx
  hkLifoAllocator *v15; // rcx
  hkVector4f *v16; // rax
  int v17; // edx
  char *v18; // r8
  int v19; // r14d
  __int64 v20; // r12
  unsigned int v21; // ebx
  hkaiGeneralAccessor *m_accessor; // rcx
  hkaiNavMesh::Edge *EdgeAndVertsFromPacked; // rax
  unsigned int m_oppositeEdge; // edx
  hkaiNavMesh::Edge *v25; // r15
  char v26; // r8
  unsigned int v27; // ecx
  int v28; // esi
  unsigned int m_oppositeFace; // edx
  unsigned int v30; // eax
  unsigned int v31; // edi
  __int64 v32; // rbx
  __int64 v33; // rax
  int v34; // edx
  __m128 *p_m_quad; // rcx
  int v36; // edx
  __m128 m_quad; // xmm2
  int v38; // edx
  int v39; // edx
  __m128 *v40; // rcx
  int v41; // edx
  __m128 v42; // xmm2
  __int64 v43; // rcx
  hkaiGeneralAccessor **v44; // r13
  __m128 *v45; // r8
  int v46; // eax
  __m128 v47; // xmm0
  int v48; // ecx
  int v49; // r14d
  hkVector4f *v50; // rdi
  int v51; // ebx
  float v52; // xmm9_4
  float v53; // xmm10_4
  __m128 v54; // xmm11
  __m128 v55; // xmm1
  int v56; // esi
  __int64 v57; // r12
  bool v58; // zf
  __m128 *v59; // rax
  __m128 v60; // xmm1
  __m128 *v61; // rax
  __m128 v62; // xmm0
  int LineSegInterpolationValue; // r15d
  int v64; // eax
  float v65; // xmm7_4
  float v66; // xmm2_4
  float v67; // xmm6_4
  float v68; // xmm1_4
  __m128 v69; // xmm8
  int v70; // eax
  __int64 v71; // r15
  __int64 v72; // r12
  __m128 *v73; // rdi
  __int64 v74; // rbx
  __int64 v75; // r14
  __m128 v76; // xmm1
  __m128 v77; // xmm0
  __m128 v78; // xmm7
  __m128 v79; // xmm6
  __m128 v80; // xmm6
  __m128 v81; // xmm2
  __m128 v82; // xmm0
  __int64 v83; // r12
  _OWORD *m128_f32; // rbx
  __int64 v85; // r14
  __m128 v86; // xmm7
  __m128 v87; // xmm6
  _OWORD *v88; // r15
  int v89; // edi
  __int64 v90; // rbx
  int v91; // r14d
  unsigned int v92; // r12d
  unsigned int v93; // edx
  int v94; // r9d
  char v95; // al
  hkaiGeneralAccessor *v96; // rcx
  bool v97; // al
  char *v98; // rdi
  int v99; // eax
  BOOL v100; // esi
  signed int v101; // ebx
  hkLifoAllocator *v102; // rax
  int v103; // r8d
  int v104; // edi
  signed int v105; // ebx
  hkLifoAllocator *v106; // rax
  int v107; // r8d
  int v108; // ebx
  signed int v109; // edi
  hkLifoAllocator *v110; // rax
  int v111; // r8d
  __m128 *m_cur; // [rsp+40h] [rbp-A0h]
  int v114; // [rsp+48h] [rbp-98h]
  int v115; // [rsp+48h] [rbp-98h]
  hkVector4f *array; // [rsp+50h] [rbp-90h] BYREF
  int v117; // [rsp+58h] [rbp-88h]
  int v118; // [rsp+5Ch] [rbp-84h]
  void *v119; // [rsp+60h] [rbp-80h]
  hkVector4f normalOut; // [rsp+68h] [rbp-78h] BYREF
  float v121; // [rsp+78h] [rbp-68h]
  hkVector4f edgeAOut; // [rsp+80h] [rbp-60h] BYREF
  hkVector4f edgeBOut; // [rsp+90h] [rbp-50h] BYREF
  int v124; // [rsp+A0h] [rbp-40h]
  float uOut[3]; // [rsp+A4h] [rbp-3Ch] BYREF
  hkVector4f normal; // [rsp+B0h] [rbp-30h] BYREF
  int v127; // [rsp+C0h] [rbp-20h]
  hkVector4f B; // [rsp+D0h] [rbp-10h] BYREF
  __int64 v129; // [rsp+E0h] [rbp+0h]
  __int64 v130; // [rsp+E8h] [rbp+8h]
  hkVector4f dB; // [rsp+F0h] [rbp+10h] BYREF
  hkVector4f p; // [rsp+100h] [rbp+20h] BYREF
  __int64 v133; // [rsp+110h] [rbp+30h]
  unsigned __int64 v134; // [rsp+118h] [rbp+38h]
  hkVector4f B2; // [rsp+120h] [rbp+40h] BYREF
  __int64 v136; // [rsp+130h] [rbp+50h]
  hkVector4f edgeB; // [rsp+140h] [rbp+60h] BYREF
  unsigned __int64 v138; // [rsp+150h] [rbp+70h]
  hkVector4f v139; // [rsp+160h] [rbp+80h] BYREF
  hkVector4f dA; // [rsp+170h] [rbp+90h] BYREF
  hkaiGeneralAccessor **v141; // [rsp+240h] [rbp+160h]
  float v142; // [rsp+248h] [rbp+168h] BYREF
  int vars0; // [rsp+250h] [rbp+170h]
  int *edgeDataOut; // [rsp+258h] [rbp+178h] BYREF

  v2 = 0;
  v4 = this;
  m_size = this->m_visitedEdges->m_size;
  v6 = 2 * m_size;
  v7 = 2 * m_size + 2;
  v124 = v7;
  if ( 2 * (_DWORD)m_size == -2 )
  {
    m_cur = 0i64;
  }
  else
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (__m128 *)Value->m_cur;
    v9 = (16 * v7 + 127) & 0xFFFFFF80;
    v10 = (char *)m_cur + v9;
    if ( v9 > Value->m_slabSize || v10 > Value->m_end )
      m_cur = (__m128 *)hkLifoAllocator::allocateFromNewSlab(Value, v9);
    else
      Value->m_cur = v10;
  }
  v127 = v7 | 0x80000000;
  if ( 2 * (_DWORD)m_size == -2 )
  {
    v12 = 0i64;
    normalOut.m_quad.m128_u64[1] = 0i64;
  }
  else
  {
    v11 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v12 = (__m128 *)v11->m_cur;
    normalOut.m_quad.m128_u64[1] = (unsigned __int64)v12;
    v13 = (16 * (2 * m_size + 2) + 127) & 0xFFFFFF80;
    v14 = (char *)v12 + v13;
    if ( v13 > v11->m_slabSize || v14 > v11->m_end )
    {
      v12 = (__m128 *)hkLifoAllocator::allocateFromNewSlab(v11, v13);
      normalOut.m_quad.m128_u64[1] = (unsigned __int64)v12;
    }
    else
    {
      v11->m_cur = v14;
    }
  }
  array = 0i64;
  v117 = 0;
  v118 = 0x80000000;
  normalOut.m_quad.m128_i32[0] = 2 * m_size;
  if ( v6 )
  {
    v15 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v16 = (hkVector4f *)v15->m_cur;
    v17 = (96 * m_size + 127) & 0xFFFFFF80;
    v18 = (char *)v16 + v17;
    if ( v17 > v15->m_slabSize || v18 > v15->m_end )
      v16 = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(v15, v17);
    else
      v15->m_cur = v18;
  }
  else
  {
    v16 = 0i64;
  }
  array = v16;
  v119 = v16;
  v118 = v6 | 0x80000000;
  if ( computeNormals )
  {
    hkaiGeneralAccessor::setSection(v4->m_accessor, v4->m_startFaceKey >> 22);
    v19 = 1;
    hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
      (hkaiNavMeshUtils *)&normal,
      (hkSimdFloat32 *)v4->m_accessor->m_accessor,
      (hkaiNavMeshInstance *)(v4->m_startFaceKey & 0x3FFFFF),
      v12);
  }
  else
  {
    v19 = 1;
    *v12 = v4->m_up.m_quad;
  }
  vars0 = -1;
  v129 = m_size;
  v20 = 0i64;
  if ( (int)m_size > 0 )
  {
    v114 = m_size - 1;
    do
    {
      v21 = v4->m_visitedEdges->m_data[v20];
      m_accessor = v4->m_accessor;
      normalOut.m_quad.m128_u64[0] = 0i64;
      LODWORD(edgeDataOut) = v21;
      EdgeAndVertsFromPacked = hkaiGeneralAccessor::getEdgeAndVertsFromPacked(
                                 m_accessor,
                                 v21,
                                 &edgeAOut,
                                 &edgeBOut,
                                 (const int **)&normalOut);
      m_oppositeEdge = EdgeAndVertsFromPacked->m_oppositeEdge;
      v25 = EdgeAndVertsFromPacked;
      v26 = EdgeAndVertsFromPacked->m_flags.m_storage & 0x40;
      if ( v26 )
        v27 = m_oppositeEdge & 0xFFC00000;
      else
        v27 = v4->m_accessor->m_accessor->m_runtimeId << 22;
      v28 = v27 | m_oppositeEdge & 0x3FFFFF;
      v58 = m_oppositeEdge == -1;
      m_oppositeFace = EdgeAndVertsFromPacked->m_oppositeFace;
      if ( v58 )
        v28 = -1;
      if ( v26 )
        v30 = m_oppositeFace & 0xFFC00000;
      else
        v30 = (*v141)->m_accessor->m_runtimeId << 22;
      v31 = v30 | m_oppositeFace & 0x3FFFFF;
      if ( m_oppositeFace == -1 )
        v31 = -1;
      if ( v142 == 0.0 )
      {
        v33 = 16i64 * v19++;
        *(_OWORD *)(normalOut.m_quad.m128_u64[1] + v33) = *((_OWORD *)v141 + 3);
      }
      else
      {
        v32 = v19++;
        hkaiGeneralAccessor::setSection(*v141, v31 >> 22);
        hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
          (hkaiNavMeshUtils *)&normal,
          (hkSimdFloat32 *)(*v141)->m_accessor,
          (hkaiNavMeshInstance *)(v31 & 0x3FFFFF),
          (__m128 *)(normalOut.m_quad.m128_u64[1] + 16 * v32));
        v21 = (unsigned int)edgeDataOut;
      }
      v34 = v117;
      if ( v117 == (v118 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 48);
        v34 = v117;
      }
      v117 = v34 + 1;
      p_m_quad = &array[3 * v34].m_quad;
      v36 = 0;
      *p_m_quad = _mm_shuffle_ps(edgeAOut.m_quad, _mm_unpackhi_ps(edgeAOut.m_quad, (__m128)0i64), 196);
      m_quad = edgeBOut.m_quad;
      p_m_quad[2].m128_i32[0] = v21;
      p_m_quad[1] = _mm_shuffle_ps(m_quad, _mm_unpackhi_ps(m_quad, query.m_quad), 196);
      if ( (v25->m_flags.m_storage & 0x10) != 0 && normalOut.m_quad.m128_u64[0] )
        v36 = *(_DWORD *)normalOut.m_quad.m128_u64[0];
      p_m_quad[2].m128_i32[1] = v36;
      v38 = vars0;
      if ( v2 == v114 )
        v38 = v28;
      p_m_quad[2].m128_i8[8] = (v25->m_flags.m_storage & 0x10) != 0;
      v58 = (v25->m_flags.m_storage & 0x10) == 0;
      vars0 = v38;
      if ( v58 )
      {
        v12 = (__m128 *)normalOut.m_quad.m128_u64[1];
      }
      else
      {
        edgeDataOut = 0i64;
        hkaiGeneralAccessor::getEdgeAndVertsFromPacked(*v141, v28, &edgeAOut, &edgeBOut, (const int **)&edgeDataOut);
        v39 = v117;
        if ( v117 == (v118 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 48);
          v39 = v117;
        }
        v117 = v39 + 1;
        v40 = &array[3 * v39].m_quad;
        v41 = 0;
        *v40 = _mm_shuffle_ps(edgeAOut.m_quad, _mm_unpackhi_ps(edgeAOut.m_quad, (__m128)0i64), 196);
        v42 = edgeBOut.m_quad;
        v40[2].m128_i32[0] = v28;
        v40[1] = _mm_shuffle_ps(v42, _mm_unpackhi_ps(v42, query.m_quad), 196);
        if ( (v25->m_flags.m_storage & 0x10) != 0 && edgeDataOut )
          v41 = *edgeDataOut;
        v12 = (__m128 *)normalOut.m_quad.m128_u64[1];
        v40[2].m128_i32[1] = v41;
        v40[2].m128_i8[8] = 2;
        v43 = v19++;
        v12[v43] = v12[v43 - 1];
      }
      v4 = (hkaiNavMeshPathSmoothingUtil *)v141;
      ++v20;
      ++v2;
    }
    while ( v20 < v129 );
  }
  v44 = v141;
  v45 = m_cur;
  *(float *)&v46 = 0.0;
  v12[v19] = v12[v19 - 1];
  v47 = *((__m128 *)v44 + 1);
  LODWORD(v141) = 0;
  v48 = v117 + 2;
  v115 = v117 + 2;
  *m_cur = v47;
  v49 = v117;
  if ( v117 > 0 )
  {
    v50 = array;
    while ( 1 )
    {
      v51 = v46 + 1;
      normalOut.m_quad.m128_i32[3] = v46;
      v136 = v46;
      v52 = 0.0;
      v53 = *(float *)&FLOAT_1_0;
      normalOut.m_quad.m128_i32[2] = v46;
      v54 = v45[v46];
      edgeAOut.m_quad = v54;
      v134 = 48i64 * v46;
      v138 = 16i64 * v46;
      v55 = v50[v134 / 0x10].m_quad;
      edgeB.m_quad = (__m128)v50[v134 / 0x10 + 1];
      B.m_quad = v55;
      dB.m_quad = _mm_sub_ps(edgeB.m_quad, v55);
      if ( v46 + 1 > v49 )
      {
LABEL_86:
        v70 = (int)v141;
        goto LABEL_87;
      }
      v56 = v46;
      v130 = 48i64 * v46;
      v57 = 48i64 * v51;
      v58 = v51 == v49;
      v133 = v130;
      v142 = *(float *)&v46;
      while ( 1 )
      {
        if ( v58 )
          v59 = (__m128 *)(v44 + 4);
        else
          v59 = &v50[3 * v51].m_quad;
        v60 = *v59;
        if ( v51 == v49 )
          v61 = (__m128 *)(v44 + 4);
        else
          v61 = &v50[3 * v51 + 1].m_quad;
        v62 = _mm_sub_ps(*v61, v54);
        dA.m_quad = _mm_sub_ps(v60, v54);
        v139.m_quad = v62;
        LineSegInterpolationValue = getLineSegInterpolationValue(&edgeAOut, &dA, &B, &dB, uOut);
        v64 = getLineSegInterpolationValue(&edgeAOut, &v139, &B, &dB, (float *)&edgeDataOut);
        v65 = uOut[0];
        if ( (((unsigned __int8)LineSegInterpolationValue | (unsigned __int8)v64) & 3) != 0 )
        {
          if ( LineSegInterpolationValue )
          {
            v66 = v52;
          }
          else
          {
            *(float *)&v119 = v52;
            v121 = uOut[0];
            v66 = fmaxf(v52, uOut[0]);
          }
          v67 = *(float *)&edgeDataOut;
          if ( v64 )
          {
            v68 = v53;
          }
          else
          {
            *(float *)&v119 = v53;
            v121 = *(float *)&edgeDataOut;
            v68 = fminf(v53, *(float *)&edgeDataOut);
          }
          getProjectedMidpoint(
            &edgeAOut,
            &B,
            &edgeB,
            v66,
            v68,
            &v50[3 * SLODWORD(v142)],
            &v50[3 * SLODWORD(v142) + 1],
            &edgeBOut);
          v49 = v117;
          v50 = array;
          v69 = edgeBOut.m_quad;
          goto LABEL_78;
        }
        v67 = *(float *)&edgeDataOut;
        if ( v52 >= *(float *)&edgeDataOut )
        {
          v56 = normalOut.m_quad.m128_i32[3];
          v69 = _mm_add_ps(
                  _mm_mul_ps(
                    _mm_sub_ps(*(__m128 *)((char *)&v50[1].m_quad + v133), *(__m128 *)((char *)&v50->m_quad + v133)),
                    (__m128)_xmm),
                  *(__m128 *)((char *)&v50->m_quad + v133));
          goto LABEL_77;
        }
        if ( v53 <= uOut[0] )
        {
          v56 = normalOut.m_quad.m128_i32[2];
          v69 = _mm_add_ps(
                  _mm_mul_ps(
                    _mm_sub_ps(*(__m128 *)((char *)&v50[1].m_quad + v130), *(__m128 *)((char *)&v50->m_quad + v130)),
                    (__m128)_xmm),
                  *(__m128 *)((char *)&v50->m_quad + v130));
          goto LABEL_77;
        }
        if ( v51 == v49 )
          break;
LABEL_80:
        if ( v65 > v52 )
        {
          v52 = v65;
          normalOut.m_quad.m128_i32[3] = v51;
          v133 = v57;
        }
        if ( v67 < v53 )
        {
          v53 = v67;
          normalOut.m_quad.m128_i32[2] = v51;
          v130 = v57;
        }
        ++v56;
        ++v51;
        v57 += 48i64;
        v142 = *(float *)&v56;
        v58 = v51 == v49;
        if ( v51 > v49 )
        {
          v45 = m_cur;
          goto LABEL_86;
        }
      }
      v69 = *((__m128 *)v44 + 2);
      v56 = v51;
LABEL_77:
      edgeBOut.m_quad = v69;
LABEL_78:
      if ( *(float *)&v56 == NAN )
      {
        *(float *)&v56 = v142;
        goto LABEL_80;
      }
      normal.m_quad = _mm_sub_ps(v69, v54);
      if ( v136 < v56 )
      {
        v83 = v134;
        m128_f32 = (_OWORD *)m_cur[v138 / 0x10 + 1].m128_f32;
        v85 = v56 - v136;
        while ( 1 )
        {
          v86 = *(__m128 *)((char *)&v50->m_quad + v83);
          v87 = _mm_sub_ps(*(__m128 *)((char *)&v50[1].m_quad + v83), v86);
          p.m_quad = v86;
          B2.m_quad = v87;
          getLineSegInterpolationValue(&edgeAOut, &normal, &p, &B2, normalOut.m_quad.m128_f32);
          ++m128_f32;
          v83 += 48i64;
          *(m128_f32 - 1) = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_shuffle_ps(
                                  (__m128)normalOut.m_quad.m128_u32[0],
                                  (__m128)normalOut.m_quad.m128_u32[0],
                                  0),
                                v87),
                              v86);
          if ( !--v85 )
            break;
          v50 = array;
        }
      }
      v45 = m_cur;
      m_cur[v56 + 1] = v69;
      v49 = v117;
      v50 = array;
      v70 = v56;
LABEL_87:
      v46 = v70 + 1;
      LODWORD(v141) = v46;
      if ( v46 >= v49 )
      {
        v48 = v115;
        break;
      }
    }
  }
  v71 = 5i64;
  v45[v48 - 1] = *((__m128 *)v44 + 2);
  normalOut.m_quad.m128_i32[0] = v48 - 1;
  v72 = v48 - 1;
  do
  {
    if ( v72 > 1 )
    {
      v73 = v45 + 1;
      v74 = 0i64;
      v75 = v72 - 1;
      do
      {
        v76 = v73[-1];
        B.m_quad = v76;
        v77 = v73[1];
        v78 = array[v74].m_quad;
        dB.m_quad = v78;
        v79 = array[v74 + 1].m_quad;
        B2.m_quad = v79;
        if ( array[v74 + 2].m_quad.m128_i8[8] == 1 )
        {
          hkLineSegmentUtil::closestPointLineSeg(&B, &dB, &B2, (hkLineSegmentUtil::ClosestPointLineSegResult *)&edgeB);
          v82 = edgeB.m_quad;
        }
        else
        {
          v80 = _mm_sub_ps(v79, v78);
          if ( array[v74 + 2].m_quad.m128_i8[8] == 2 )
          {
            v82 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(query.m_quad, _mm_shuffle_ps(v76, v76, 255)), v80), v78);
          }
          else
          {
            normal.m_quad = v80;
            p.m_quad = _mm_sub_ps(v77, v76);
            getLineSegInterpolationValue(&B, &p, &dB, &normal, &v142);
            LODWORD(v141) = 0;
            LODWORD(edgeDataOut) = 1065353216;
            v142 = (float)(v142 * 1.5) - (float)(v73->m128_f32[3] * 0.5);
            v81 = (__m128)LODWORD(v142);
            v81.m128_f32[0] = fminf(fmaxf(v142, 0.0), 1.0);
            v142 = v81.m128_f32[0];
            v82 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v81, v81, 0), v80), v78);
          }
        }
        *v73++ = v82;
        v74 += 3i64;
        --v75;
      }
      while ( v75 );
      v45 = m_cur;
    }
    --v71;
  }
  while ( v71 );
  v88 = (_OWORD *)normalOut.m_quad.m128_u64[1];
  v89 = 0;
  v90 = 0i64;
  if ( v115 > 0 )
  {
    v91 = normalOut.m_quad.m128_i32[0];
    v92 = vars0;
    do
    {
      p.m_quad = v45[v90];
      normal.m_quad = (__m128)v88[v90];
      if ( v90 )
      {
        if ( v89 == v91 )
        {
          v93 = 0;
          if ( v129 )
            v94 = v92 >> 22;
          else
            v94 = *((_DWORD *)v44 + 16) >> 22;
          v95 = 0;
        }
        else
        {
          v93 = array[3 * v90 - 1].m_quad.m128_u32[1];
          v95 = array[3 * v90 - 1].m_quad.m128_i8[8];
          v94 = (unsigned int)array[3 * v90 - 1].m_quad.m128_i32[0] >> 22;
        }
      }
      else
      {
        v93 = 0;
        v94 = *((_DWORD *)v44 + 16) >> 22;
        v95 = 0;
      }
      hkaiPathWriter::addPointToPath((hkaiPathWriter *)v44[9], &p, &normal, v94, v93, v95);
      v45 = m_cur;
      ++v90;
      ++v89;
    }
    while ( v90 < v115 );
  }
  hkaiPathWriter::addTerminatorToPathPointer((hkaiPathWriter *)v44[9]);
  v96 = v44[9];
  v97 = !v96->m_accessor && SHIDWORD(v96->m_sectionInfo) >= SLODWORD(v96->m_sectionInfo);
  v98 = (char *)v119;
  v58 = !v97;
  v99 = v117;
  v100 = v58;
  if ( v119 == array )
    v99 = 0;
  v117 = v99;
  v101 = (48 * normalOut.m_quad.m128_i32[0] + 127) & 0xFFFFFF80;
  v102 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v103 = (v101 + 15) & 0xFFFFFFF0;
  if ( v101 > v102->m_slabSize || &v98[v103] != v102->m_cur || v102->m_firstNonLifoEnd == v98 )
    hkLifoAllocator::slowBlockFree(v102, v98, v103);
  else
    v102->m_cur = v98;
  v117 = 0;
  if ( v118 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array,
      48 * (v118 & 0x3FFFFFFF));
  v104 = v124;
  array = 0i64;
  v118 = 0x80000000;
  v105 = (16 * v124 + 127) & 0xFFFFFF80;
  v106 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v107 = (v105 + 15) & 0xFFFFFFF0;
  if ( v105 > v106->m_slabSize || (char *)v88 + v107 != v106->m_cur || v106->m_firstNonLifoEnd == v88 )
    hkLifoAllocator::slowBlockFree(v106, v88, v107);
  else
    v106->m_cur = v88;
  v108 = v127;
  if ( v127 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v88, 16 * v127);
  v109 = (16 * v104 + 127) & 0xFFFFFF80;
  v110 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v111 = (v109 + 15) & 0xFFFFFFF0;
  if ( v109 > v110->m_slabSize || (char *)m_cur + v111 != v110->m_cur || v110->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v110, m_cur, v111);
  else
    v110->m_cur = m_cur;
  if ( v108 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, m_cur, 16 * v108);
  return v100;
}e
    v106->m_cur = v88;
  v108 = v127;
  if ( v127 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v88, 16 * v127);
  v109 = (16 * v104 + 127) & 0xFFFFFF80;
  v110 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v111 = (v109 + 15) & 0xFFFFFFF0;
  if ( v109 > v110->m_slabSize || (char *)m_cur + v111 != v110->m_cur || v110->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v110, m_cur, v111);
  else
    v110->m_cur = m_cur;
  if ( v108 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_al

// File Line: 601
// RVA: 0xC01D70
void __fastcall hkaiNavMeshPathSmoothingUtil::hkaiNavMeshPathSmoothingUtil(
        hkaiNavMeshPathSmoothingUtil *this,
        hkaiGeneralAccessor *accessor,
        hkArray<unsigned int,hkContainerHeapAllocator> *visitedEdges,
        unsigned int startFaceKey,
        hkVector4f *startPoint,
        hkVector4f *endPoint,
        hkVector4f *up,
        float radius,
        hkaiPathWriter *writer)
{
  __m128 m_quad; // xmm0

  this->m_accessor = accessor;
  this->m_visitedEdges = visitedEdges;
  this->m_startPoint = (hkVector4f)startPoint->m_quad;
  this->m_endPoint = (hkVector4f)endPoint->m_quad;
  m_quad = up->m_quad;
  this->m_radius = radius;
  this->m_writer = writer;
  this->m_startFaceKey = startFaceKey;
  this->m_up.m_quad = m_quad;
}

