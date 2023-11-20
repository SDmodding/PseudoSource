// File Line: 76
// RVA: 0xC464D0
void __fastcall hkaiNavMeshDebugUtils::SmallEdgeSettings::SmallEdgeSettings(hkaiNavMeshDebugUtils::SmallEdgeSettings *this)
{
  *(_WORD *)&this->m_markSmallEdges.m_bool = 0;
  this->m_smallBoundaryEdgeColor = hkColor::YELLOW;
  this->m_smallEdgeTolerance = 0.02;
  this->m_markerOffset.m_quad = _xmm;
  this->m_smallSharedEdgeColor = hkColor::ORANGE;
}

// File Line: 84
// RVA: 0xC46510
void __fastcall hkaiNavMeshDebugUtils::NonplanarFacesSettings::NonplanarFacesSettings(hkaiNavMeshDebugUtils::NonplanarFacesSettings *this)
{
  *(_WORD *)&this->m_highlightNonplanarFaces.m_bool = 0;
  this->m_scaleMultiplier = 1.0;
}

// File Line: 93
// RVA: 0xC46530
void __fastcall hkaiNavMeshDebugUtils::FaceNormalSettings::FaceNormalSettings(hkaiNavMeshDebugUtils::FaceNormalSettings *this)
{
  *(_WORD *)&this->m_highlightFaceNormals.m_bool = 0;
  this->m_up.m_quad = _xmm;
  *(_QWORD *)&this->m_scaleMultiplier = 1120403456i64;
}

// File Line: 142
// RVA: 0xC46560
void __fastcall hkaiNavMeshDebugUtils::DebugInfo::DebugInfo(hkaiNavMeshDebugUtils::DebugInfo *this)
{
  hkaiNavMeshDebugUtils::DebugInfo *v1; // rbx
  hkaiNavMeshDebugUtils::SmallEdgeSettings *v2; // rcx
  __m128 v3; // xmm1
  __m128 v4; // xmm3
  __m128 v5; // xmm2

  *(_DWORD *)&this->m_allowFaceTransparency.m_bool = 65793;
  *(_QWORD *)&this->m_showUserEdges.m_bool = 1i64;
  *(_WORD *)&this->m_showEdgeConnections.m_bool = 0;
  v1 = this;
  v2 = &this->m_smallEdgeSettings;
  v2[-7].m_markerOffset.m_quad.m128_u64[0] = 0i64;
  v2[-7].m_markerOffset.m_quad.m128_i32[2] = 0;
  *(_QWORD *)&v2[-6].m_markSmallEdges.m_bool = 0i64;
  v2[-6].m_smallSharedEdgeColor = 0;
  LOBYTE(v2[-6].m_smallEdgeTolerance) = 0;
  v2[-6].m_markerOffset.m_quad.m128_i32[0] = hkColor::ORANGE;
  v2[-6].m_markerOffset.m_quad.m128_i32[1] = hkColor::RED;
  v2[-6].m_markerOffset.m_quad.m128_i32[2] = hkColor::BLUE;
  v2[-6].m_markerOffset.m_quad.m128_i32[3] = hkColor::CYAN;
  *(_DWORD *)&v2[-5].m_markSmallEdges.m_bool = hkColor::CYAN;
  v2[-5].m_smallBoundaryEdgeColor = hkColor::LIGHTBLUE;
  v2[-5].m_smallSharedEdgeColor = hkColor::BLACK;
  LODWORD(v2[-5].m_smallEdgeTolerance) = hkColor::BLACK;
  v2[-5].m_markerOffset.m_quad.m128_i32[0] = hkColor::PURPLE;
  v2[-5].m_markerOffset.m_quad.m128_i32[1] = hkColor::BLUE;
  v2[-5].m_markerOffset.m_quad.m128_i32[2] = hkColor::PURPLE;
  v2[-5].m_markerOffset.m_quad.m128_i32[3] = hkColor::BLUE;
  v2[-4].m_markSmallEdges.m_bool = 0;
  v2[-4].m_smallBoundaryEdgeColor = 0;
  v2[-4].m_smallSharedEdgeColor = 1028443341;
  *(_QWORD *)&v2[-4].m_smallEdgeTolerance = -1i64;
  v2[-4].m_markerOffset.m_quad.m128_i8[4] = 0;
  v2[-3].m_markerOffset.m_quad.m128_i8[0] = 0;
  hkaiNavMeshDebugUtils::SmallEdgeSettings::SmallEdgeSettings(v2);
  hkaiNavMeshDebugUtils::NonplanarFacesSettings::NonplanarFacesSettings(&v1->m_nonplanarFacesSettings);
  hkaiNavMeshDebugUtils::FaceNormalSettings::FaceNormalSettings(&v1->m_faceNormalSettings);
  hkaiGraphDebugUtils::DebugInfo::DebugInfo(&v1->m_clusterGraphSettings);
  v1->m_instanceEnabled.m_storage.m_words.m_data = 0i64;
  v1->m_instanceEnabled.m_storage.m_words.m_size = 0;
  v1->m_instanceEnabled.m_storage.m_words.m_capacityAndFlags = 2147483648;
  v1->m_instanceEnabled.m_storage.m_numBits = 0;
  v1->m_displayOffset = (hkVector4f)_xmm;
  v1->m_hiddenFaceOffset = 0i64;
  v1->m_sortDirection = 0i64;
  v1->m_lightDirection.m_quad = g_vectorfConstants[0];
  v3 = _mm_mul_ps(g_vectorfConstants[0], g_vectorfConstants[0]);
  v4 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v3, v3, 85), _mm_shuffle_ps(v3, v3, 0)), _mm_shuffle_ps(v3, v3, 170));
  v5 = _mm_rsqrt_ps(v4);
  v1->m_faceOffset = 0i64;
  v1->m_lightDirection.m_quad = _mm_mul_ps(
                                  _mm_andnot_ps(
                                    _mm_cmpleps(v4, (__m128)0i64),
                                    _mm_mul_ps(
                                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v5, v4), v5)),
                                      _mm_mul_ps(*(__m128 *)_xmm, v5))),
                                  g_vectorfConstants[0]);
  v1->m_pruneLabelsAabb.m_min = (hkVector4f)xmmword_141A712A0;
  v1->m_pruneLabelsAabb.m_max.m_quad = _mm_xor_ps(
                                         (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                         v1->m_pruneLabelsAabb.m_min.m_quad);
}

// File Line: 153
// RVA: 0xC46780
bool __fastcall hkaiNavMeshDebugUtils::DebugInfo::shouldDrawFaces(hkaiNavMeshDebugUtils::DebugInfo *this)
{
  return this->m_showFaces.m_bool
      || this->m_showNormals.m_bool
      || this->m_labelFaces.m_bool
      || this->m_showFaceData.m_bool
      || this->m_nonplanarFacesSettings.m_drawNonplanarity.m_bool
      || this->m_faceNormalSettings.m_drawFaceNormal.m_bool
      || this->m_showHiddenFaces.m_bool;
}

// File Line: 165
// RVA: 0xC467C0
bool __fastcall hkaiNavMeshDebugUtils::DebugInfo::shouldDrawEdges(hkaiNavMeshDebugUtils::DebugInfo *this)
{
  return this->m_showEdges.m_bool
      || this->m_showEdgeConnections.m_bool
      || this->m_showVertices.m_bool
      || *(_WORD *)&this->m_labelVertices.m_bool
      || this->m_showEdgeData.m_bool
      || *(_WORD *)&this->m_showEdgeNormals.m_bool;
}

// File Line: 177
// RVA: 0xC46800
_BOOL8 __fastcall hkaiNavMeshDebugUtils::DebugInfo::shouldDrawUserEdges(hkaiNavMeshDebugUtils::DebugInfo *this)
{
  return this->m_showUserEdges.m_bool != 0;
}

// File Line: 241
// RVA: 0xC47150
void __fastcall hkaiNavMeshDebugUtils::highlightNavMeshEdges(hkaiNavMeshInstance *mesh, hkArrayBase<unsigned int> *edgesVisited, unsigned int highlightColor, hkVector4f *offset)
{
  int v4; // er12
  hkVector4f *v5; // r13
  hkArrayBase<unsigned int> *v6; // rdi
  hkaiNavMeshInstance *v7; // rbx
  hkArray<int,hkContainerHeapAllocator> *instanceMap; // rbp
  __int64 v9; // rsi
  hkaiNavMesh::Edge *v10; // rax
  signed int v11; // edx
  __int64 v12; // rcx
  __m128 *v13; // rcx
  __m128 v14; // xmm4
  __m128 v15; // xmm5
  __int64 v16; // rax
  __m128 v17; // xmm6
  __m128 v18; // xmm7
  __m128 v19; // xmm2
  __m128 *v20; // rax
  __m128 v21; // xmm1
  hkVector4f end; // [rsp+30h] [rbp-68h]
  hkVector4f start; // [rsp+40h] [rbp-58h]
  unsigned int color; // [rsp+B0h] [rbp+18h]

  color = highlightColor;
  v4 = 0;
  v5 = offset;
  v6 = edgesVisited;
  v7 = mesh;
  if ( edgesVisited->m_size > 0 )
  {
    instanceMap = &mesh->m_edgeMap;
    v9 = 0i64;
    do
    {
      v10 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__23(
              v7->m_originalEdges,
              v7->m_numOriginalEdges,
              &v7->m_instancedEdges,
              &v7->m_ownedEdges,
              instanceMap,
              v6->m_data[v9]);
      v11 = v7->m_numOriginalVertices;
      v12 = v10->m_a;
      if ( (signed int)v12 >= v11 )
        v13 = &v7->m_ownedVertices.m_data[(signed int)v12 - v11].m_quad;
      else
        v13 = &v7->m_originalVertices[v12].m_quad;
      v14 = v7->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad;
      v15 = v7->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad;
      v16 = v10->m_b;
      v17 = v7->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad;
      v18 = v7->m_referenceFrame.m_transform.m_translation.m_quad;
      v19 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*v13, *v13, 0), v15),
                  _mm_mul_ps(_mm_shuffle_ps(*v13, *v13, 85), v14)),
                _mm_mul_ps(_mm_shuffle_ps(*v13, *v13, 170), v17)),
              v18);
      if ( (signed int)v16 >= v11 )
        v20 = &v7->m_ownedVertices.m_data[(signed int)v16 - v11].m_quad;
      else
        v20 = &v7->m_originalVertices[v16].m_quad;
      v21 = *v20;
      start.m_quad = _mm_add_ps(v5->m_quad, v19);
      end.m_quad = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), v15),
                           _mm_mul_ps(_mm_shuffle_ps(v21, v21, 85), v14)),
                         _mm_mul_ps(_mm_shuffle_ps(v21, v21, 170), v17)),
                       v18),
                     v5->m_quad);
      hkDebugDisplay::displayLine(
        hkSingleton<hkDebugDisplay>::s_instance,
        &start,
        &end,
        color,
        0,
        (int)hkDebugDisplayProcess::m_tag);
      ++v4;
      ++v9;
    }
    while ( v4 < v6->m_size );
  }
}

// File Line: 255
// RVA: 0xC470D0
void __fastcall hkaiNavMeshDebugUtils::highlightNavMeshEdges(hkaiNavMesh *mesh, hkArrayBase<unsigned int> *edgesVisited, unsigned int highlightColor, hkVector4f *offset)
{
  hkaiNavMesh *v4; // rbx
  hkVector4f *v5; // rdi
  unsigned int v6; // esi
  hkArrayBase<unsigned int> *v7; // rbp
  hkaiNavMeshInstance mesha; // [rsp+20h] [rbp-1E8h]

  v4 = mesh;
  v5 = offset;
  v6 = highlightColor;
  v7 = edgesVisited;
  hkaiNavMeshInstance::hkaiNavMeshInstance(&mesha);
  hkaiNavMeshInstance::tempInit(&mesha, v4, 0);
  hkaiNavMeshDebugUtils::highlightNavMeshEdges(&mesha, v7, v6, v5);
  hkaiNavMeshInstance::~hkaiNavMeshInstance(&mesha);
}

// File Line: 264
// RVA: 0xC47310
void __fastcall hkaiNavMeshDebugUtils::highlightNavMeshEdgeMidpoints(hkaiNavMesh *mesh, int faceIndexStart, int faceIndexEnd, hkArrayBase<unsigned int> *edgesVisited, unsigned int highlightColor, float highlightRadius, float displayOffset)
{
  hkaiNavMesh *v7; // rbx
  hkArrayBase<unsigned int> *v8; // rdi
  int v9; // esi
  int v10; // ebp
  hkaiNavMeshInstance mesha; // [rsp+40h] [rbp-1E8h]

  v7 = mesh;
  v8 = edgesVisited;
  v9 = faceIndexEnd;
  v10 = faceIndexStart;
  hkaiNavMeshInstance::hkaiNavMeshInstance(&mesha);
  hkaiNavMeshInstance::tempInit(&mesha, v7, 0);
  hkaiNavMeshDebugUtils::highlightNavMeshEdgeMidpoints(
    &mesha,
    v10,
    v9,
    v8,
    highlightColor,
    highlightRadius,
    displayOffset);
  hkaiNavMeshInstance::~hkaiNavMeshInstance(&mesha);
}

// File Line: 271
// RVA: 0xC47450
void __fastcall hkaiNavMeshDebugUtils::highlightNavMeshEdgeMidpoints(hkaiNavMesh *mesh, int faceIndexStart, hkVector4f *startPoint, int faceIndexEnd, hkVector4f *endPoint, hkArrayBase<unsigned int> *edgesVisited, unsigned int highlightColor, float highlightRadius, float displayOffset)
{
  hkaiNavMesh *v9; // rbx
  int v10; // edi
  hkVector4f *v11; // rsi
  int v12; // ebp
  hkaiNavMeshInstance mesha; // [rsp+50h] [rbp-1E8h]

  v9 = mesh;
  v10 = faceIndexEnd;
  v11 = startPoint;
  v12 = faceIndexStart;
  hkaiNavMeshInstance::hkaiNavMeshInstance(&mesha);
  hkaiNavMeshInstance::tempInit(&mesha, v9, 0);
  hkaiNavMeshDebugUtils::highlightNavMeshEdgeMidpoints(
    &mesha,
    v12,
    v11,
    v10,
    endPoint,
    edgesVisited,
    highlightColor,
    highlightRadius,
    displayOffset);
  hkaiNavMeshInstance::~hkaiNavMeshInstance(&mesha);
}

// File Line: 278
// RVA: 0xC473B0
void __fastcall hkaiNavMeshDebugUtils::highlightNavMeshEdgeMidpoints(hkaiNavMeshInstance *mesh, __int64 faceIndexStart, int faceIndexEnd, hkArrayBase<unsigned int> *edgesVisited, unsigned int highlightColor, float highlightRadius, float displayOffset)
{
  unsigned int v7; // edi
  hkArrayBase<unsigned int> *v8; // rbx
  int v9; // esi
  hkaiNavMeshInstance *v10; // rbp
  hkVector4f *v11; // r9
  hkVector4f endPoint; // [rsp+50h] [rbp-28h]
  int faceIndex; // [rsp+60h] [rbp-18h]

  v7 = faceIndexEnd;
  v8 = edgesVisited;
  v9 = faceIndexStart;
  v10 = mesh;
  hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
    (hkaiNavMeshUtils *)mesh,
    (hkaiNavMeshInstance *)faceIndexStart,
    (__int64)&faceIndex,
    (hkVector4f *)edgesVisited);
  hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
    (hkaiNavMeshUtils *)v10,
    (hkaiNavMeshInstance *)v7,
    (__int64)&endPoint,
    v11);
  hkaiNavMeshDebugUtils::highlightNavMeshEdgeMidpoints(
    v10,
    v9,
    (hkVector4f *)&faceIndex,
    v7,
    &endPoint,
    v8,
    highlightColor,
    highlightRadius,
    displayOffset);
}

// File Line: 287
// RVA: 0xC47510
void __usercall hkaiNavMeshDebugUtils::highlightNavMeshEdgeMidpoints(hkaiNavMeshInstance *mesh@<rcx>, int faceIndexStart@<edx>, hkVector4f *startPoint@<r8>, __int64 faceIndexEnd@<r9>, __int64 a5@<r12>, __m128 a6@<xmm12>, hkVector4f *endPoint, hkArrayBase<unsigned int> *edgesVisited, unsigned int highlightColor, float highlightRadius, float displayOffset)
{
  signed int v11; // er14
  unsigned int v12; // er10
  signed int v13; // eax
  unsigned int v14; // er15
  hkaiNavMeshInstance *v15; // rbx
  signed __int64 v16; // rsi
  __m128 *v17; // r12
  __m128 v18; // xmm12
  hkVector4f *v19; // r9
  __m128 v20; // xmm11
  hkVector4f *v21; // r9
  hkVector4f *v22; // r9
  hkaiNavMeshInstance *v23; // r8
  __m128 v24; // xmm1
  __m128 v25; // xmm10
  __m128 v26; // xmm1
  __m128 v27; // xmm1
  __m128 v28; // xmm2
  __m128 v29; // xmm6
  __m128 v30; // xmm0
  __m128 v31; // xmm5
  __m128 v32; // xmm5
  __m128 v33; // xmm1
  __m128 v34; // xmm3
  __m128 v35; // xmm2
  __m128 v36; // xmm1
  __m128 v37; // xmm0
  __m128 v38; // xmm2
  __m128 v39; // xmm4
  __m128 v40; // xmm1
  __m128 v41; // xmm5
  __m128 v42; // xmm1
  __m128 v43; // xmm6
  __m128 v44; // xmm5
  __m128 v45; // xmm0
  __m128 v46; // xmm4
  __m128 v47; // xmm4
  __m128 v48; // xmm1
  __m128 v49; // xmm2
  __m128 v50; // xmm1
  __m128 v51; // xmm8
  __m128 v52; // xmm3
  __m128 v53; // xmm0
  __m128 v54; // xmm2
  __m128 v55; // xmm0
  __m128 v56; // xmm4
  __m128 v57; // xmm1
  int edgeIndex[4]; // [rsp+40h] [rbp-90h]
  hkVector4f start; // [rsp+50h] [rbp-80h]
  int faceIndex[4]; // [rsp+60h] [rbp-70h]
  hkVector4f a; // [rsp+70h] [rbp-60h]
  char v62; // [rsp+80h] [rbp-50h]
  char v63; // [rsp+90h] [rbp-40h]
  char v64; // [rsp+A0h] [rbp-30h]
  hkVector4f *v65; // [rsp+1A0h] [rbp+D0h]
  unsigned int v66; // [rsp+1A8h] [rbp+D8h]
  __m128 *vars0; // [rsp+1B0h] [rbp+E0h]
  _DWORD *retaddr; // [rsp+1B8h] [rbp+E8h]
  __int64 color; // [rsp+1C0h] [rbp+F0h]
  float v70; // [rsp+1C8h] [rbp+F8h]
  hkVector4f *v71[2]; // [rsp+1D0h] [rbp+100h]

  v71[0] = startPoint;
  v11 = -1;
  v12 = faceIndexEnd;
  v13 = retaddr[2];
  v14 = faceIndexStart;
  v15 = mesh;
  v16 = -1i64;
  if ( v13 > -1 )
  {
    color = a5;
    v17 = vars0;
    a6.m128_f32[0] = *(float *)&startPoint;
    v18 = _mm_shuffle_ps(a6, a6, 0);
    while ( v16 == -1 )
    {
      start.m_quad = startPoint->m_quad;
      hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
        (hkaiNavMeshUtils *)&v62,
        (hkSimdFloat32 *)v15,
        (hkaiNavMeshInstance *)v14,
        (__int64)faceIndex);
      if ( retaddr[2] )
      {
        hkaiNavMeshUtils::calcEdgeMidpoint<hkaiNavMeshInstance>(
          (hkaiNavMeshUtils *)v15,
          (hkaiNavMeshInstance *)**(unsigned int **)retaddr,
          (__int64)edgeIndex,
          v19);
LABEL_13:
        v20 = *(__m128 *)edgeIndex;
        goto LABEL_14;
      }
      v20 = *v17;
      *(__m128 *)edgeIndex = *v17;
LABEL_14:
      if ( v70 > 0.0 )
      {
        v25 = start.m_quad;
        v26 = (__m128)LODWORD(v71[0]);
        v26.m128_f32[0] = *(float *)v71 * 0.1;
        v27 = _mm_mul_ps(_mm_shuffle_ps(v26, v26, 0), *(__m128 *)faceIndex);
        v28 = _mm_add_ps(*(__m128 *)faceIndex, v27);
        v29 = _mm_add_ps(start.m_quad, v27);
        v30 = _mm_sub_ps(v29, v20);
        v31 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v30, v30, 201), v28), _mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), v30));
        v32 = _mm_shuffle_ps(v31, v31, 201);
        v33 = _mm_mul_ps(v32, v32);
        v34 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)),
                _mm_shuffle_ps(v33, v33, 170));
        v35 = _mm_rsqrt_ps(v34);
        v36 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v35, v34), v35));
        v37 = _mm_mul_ps(*(__m128 *)_xmm, v35);
        v38 = (__m128)LODWORD(v70);
        v38.m128_f32[0] = v70 * -1.2;
        v39 = _mm_andnot_ps(_mm_cmpleps(v34, (__m128)0i64), _mm_mul_ps(v36, v37));
        v40 = (__m128)LODWORD(v70);
        v40.m128_f32[0] = v70 * 1.2;
        v41 = _mm_mul_ps(v32, v39);
        v42 = _mm_mul_ps(_mm_shuffle_ps(v40, v40, 0), v41);
        *(__m128 *)faceIndex = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v38, v38, 0), v41), v20);
        a.m_quad = _mm_add_ps(v42, v20);
        start.m_quad = _mm_add_ps(v42, v29);
        hkDebugDisplay::displayTriangle(
          hkSingleton<hkDebugDisplay>::s_instance,
          &a,
          &start,
          &a,
          0x40000000u,
          0,
          (int)hkDebugDisplayProcess::m_tag);
        hkDebugDisplay::displayTriangle(
          hkSingleton<hkDebugDisplay>::s_instance,
          &a,
          (hkVector4f *)faceIndex,
          &a,
          0x40000000u,
          0,
          (int)hkDebugDisplayProcess::m_tag);
        v43 = _mm_mul_ps(v18, *(__m128 *)faceIndex);
        v44 = _mm_add_ps(v43, v25);
        *(__m128 *)edgeIndex = _mm_add_ps(v43, v20);
        v45 = _mm_sub_ps(v44, *(__m128 *)edgeIndex);
        v46 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v45, v45, 201), *(__m128 *)faceIndex),
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)faceIndex, *(__m128 *)faceIndex, 201), v45));
        v47 = _mm_shuffle_ps(v46, v46, 201);
        v48 = _mm_mul_ps(v47, v47);
        v49 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v48, v48, 85), _mm_shuffle_ps(v48, v48, 0)),
                _mm_shuffle_ps(v48, v48, 170));
        v50 = _mm_rsqrt_ps(v49);
        v51 = _mm_mul_ps(*(__m128 *)_xmm, v50);
        v52 = _mm_cmpleps(v49, (__m128)0i64);
        v53 = _mm_mul_ps(v50, v49);
        v54 = _mm_xor_ps((__m128)LODWORD(v70), *(__m128 *)_xmm);
        v55 = _mm_mul_ps(v53, v50);
        v50.m128_f32[0] = v70;
        v56 = _mm_mul_ps(v47, _mm_andnot_ps(v52, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v55), v51)));
        v57 = _mm_mul_ps(_mm_shuffle_ps(v50, v50, 0), v56);
        start.m_quad = _mm_add_ps(v44, v57);
        *(__m128 *)faceIndex = _mm_add_ps(*(__m128 *)edgeIndex, _mm_mul_ps(_mm_shuffle_ps(v54, v54, 0), v56));
        a.m_quad = _mm_add_ps(*(__m128 *)edgeIndex, v57);
        hkDebugDisplay::displayTriangle(
          hkSingleton<hkDebugDisplay>::s_instance,
          &a,
          &start,
          &a,
          color,
          0,
          (int)hkDebugDisplayProcess::m_tag);
        hkDebugDisplay::displayTriangle(
          hkSingleton<hkDebugDisplay>::s_instance,
          &a,
          (hkVector4f *)faceIndex,
          &a,
          color,
          0,
          (int)hkDebugDisplayProcess::m_tag);
      }
      else
      {
        v24 = _mm_mul_ps(v18, *(__m128 *)faceIndex);
        start.m_quad = _mm_add_ps(start.m_quad, v24);
        *(__m128 *)edgeIndex = _mm_add_ps(v20, v24);
        hkDebugDisplay::displayLine(
          hkSingleton<hkDebugDisplay>::s_instance,
          &start,
          (hkVector4f *)edgeIndex,
          color,
          0,
          (int)hkDebugDisplayProcess::m_tag);
      }
      v13 = retaddr[2];
      startPoint = v65;
      v12 = v66;
      ++v11;
      ++v16;
      if ( v11 >= v13 )
        return;
    }
    if ( v11 == v13 - 1 )
    {
      *(__m128 *)edgeIndex = *v17;
      hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
        (hkaiNavMeshUtils *)&v64,
        (hkSimdFloat32 *)v15,
        (hkaiNavMeshInstance *)v12,
        (__int64)faceIndex);
      hkaiNavMeshUtils::calcEdgeMidpoint<hkaiNavMeshInstance>(
        (hkaiNavMeshUtils *)v15,
        (hkaiNavMeshInstance *)*(unsigned int *)(*(_QWORD *)retaddr + 4i64 * (signed int)retaddr[2] - 4),
        (__int64)&start,
        v21);
    }
    else
    {
      hkaiNavMeshUtils::calcEdgeMidpoint<hkaiNavMeshInstance>(
        (hkaiNavMeshUtils *)v15,
        (hkaiNavMeshInstance *)*(unsigned int *)(*(_QWORD *)retaddr + 4 * v16),
        (__int64)&start,
        (hkVector4f *)faceIndexEnd);
      hkaiNavMeshUtils::calcEdgeMidpoint<hkaiNavMeshInstance>(
        (hkaiNavMeshUtils *)v15,
        (hkaiNavMeshInstance *)*(unsigned int *)(*(_QWORD *)retaddr + 4 * v16 + 4),
        (__int64)edgeIndex,
        v22);
      if ( v16 )
        v23 = (hkaiNavMeshInstance *)(hkaiNavMeshInstance_get_hkaiNavMesh::Edge__23(
                                        v15->m_originalEdges,
                                        v15->m_numOriginalEdges,
                                        &v15->m_instancedEdges,
                                        &v15->m_ownedEdges,
                                        &v15->m_edgeMap,
                                        *(_DWORD *)(*(_QWORD *)retaddr + 4 * v16 - 4))->m_oppositeFace & 0x3FFFFF);
      else
        v23 = (hkaiNavMeshInstance *)v14;
      hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
        (hkaiNavMeshUtils *)&v63,
        (hkSimdFloat32 *)v15,
        v23,
        (__int64)faceIndex);
    }
    goto LABEL_13;
  }
}

// File Line: 375
// RVA: 0xC47A60
void __fastcall hkaiNavMeshDebugUtils::drawPath(hkaiPath *path, float width, hkVector4f *up, unsigned int color, unsigned int lastSegmentColor, float offset)
{
  hkaiNavMeshDebugUtils::_drawPath(path, width, up, color, lastSegmentColor, 0i64, 0, offset);
}

// File Line: 380
// RVA: 0xC47AA0
void __usercall hkaiNavMeshDebugUtils::_drawPath(hkaiPath *path@<rcx>, float width@<xmm1>, hkVector4f *up@<r8>, unsigned int color@<r9d>, __m128 a5@<xmm9>, unsigned int lastSegmentColor, hkDebugDisplayHandler *displayHandler, int tag, float offset)
{
  signed __int64 v9; // rax
  signed int v10; // er15
  unsigned int v11; // edx
  signed __int64 v12; // rsi
  signed __int64 v13; // r13
  __m128 v14; // xmm7
  float v15; // xmm2_4
  hkDebugDisplayHandler *v16; // rbx
  int v17; // er14
  int v18; // eax
  __m128 v19; // xmm9
  __int64 v20; // r12
  bool v21; // zf
  hkaiPath::PathPoint *v22; // rax
  unsigned int v23; // edi
  __m128 v24; // xmm8
  __m128 v25; // xmm6
  __m128 v26; // xmm0
  __m128 v27; // xmm5
  __m128 v28; // xmm5
  __m128 v29; // xmm1
  __m128 v30; // xmm3
  __m128 v31; // xmm2
  __m128 v32; // xmm4
  __int64 v33; // ST38_8
  __int64 v34; // ST30_8
  __int64 v35; // ST28_8
  __int64 v36; // ST38_8
  __int64 v37; // ST30_8
  __int64 v38; // ST28_8
  __int64 id; // [rsp+28h] [rbp-D8h]
  __int64 v40; // [rsp+30h] [rbp-D0h]
  __int64 v41; // [rsp+38h] [rbp-C8h]
  unsigned int v42; // [rsp+40h] [rbp-C0h]
  hkVector4f c; // [rsp+50h] [rbp-B0h]
  hkVector4f a; // [rsp+60h] [rbp-A0h]
  hkVector4f v45; // [rsp+70h] [rbp-90h]
  hkVector4f v46; // [rsp+80h] [rbp-80h]
  char v47; // [rsp+90h] [rbp-70h]
  hkVector4f b; // [rsp+A0h] [rbp-60h]
  char v49; // [rsp+B0h] [rbp-50h]
  char v50; // [rsp+B4h] [rbp-4Ch]
  hkVector4f v51; // [rsp+C0h] [rbp-40h]
  hkVector4f v52; // [rsp+D0h] [rbp-30h]
  hkaiPath *v53; // [rsp+190h] [rbp+90h]
  int v54; // [rsp+198h] [rbp+98h]
  float v55; // [rsp+1A0h] [rbp+A0h]

  v53 = path;
  v9 = path->m_points.m_size;
  v10 = 1;
  v11 = color;
  v12 = 1i64;
  v13 = v9;
  v55 = FLOAT_0_050000001;
  v42 = color;
  v14 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(offset), (__m128)LODWORD(offset), 0), up->m_quad);
  v15 = fmaxf(width * 0.5, 0.050000001);
  if ( v9 > 1 )
  {
    v16 = displayHandler;
    v17 = tag;
    a5.m128_f32[0] = v15;
    v18 = v9 - 1;
    v19 = _mm_shuffle_ps(a5, a5, 0);
    v54 = v18;
    v20 = 0i64;
    do
    {
      v21 = v10 == v18;
      v22 = path->m_points.m_data;
      v23 = v11;
      if ( v21 )
        v23 = lastSegmentColor;
      v24 = v22[v20].m_position.m_quad;
      v25 = v22[v20 + 1].m_position.m_quad;
      v26 = _mm_sub_ps(v22[v20].m_position.m_quad, v25);
      v27 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v22[v20].m_normal.m_quad, v22[v20].m_normal.m_quad, 201), v26),
              _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v22[v20].m_normal.m_quad));
      v28 = _mm_shuffle_ps(v27, v27, 201);
      v29 = _mm_mul_ps(v28, v28);
      v30 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
              _mm_shuffle_ps(v29, v29, 170));
      v31 = _mm_rsqrt_ps(v30);
      v32 = _mm_mul_ps(
              _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmpleps(v30, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v30), v31)),
                    _mm_mul_ps(*(__m128 *)_xmm, v31))),
                v28),
              v19);
      c.m_quad = _mm_add_ps(_mm_add_ps(v32, v24), v14);
      b.m_quad = _mm_add_ps(_mm_add_ps(v32, v25), v14);
      a.m_quad = _mm_add_ps(_mm_sub_ps(v25, v32), v14);
      v46.m_quad = _mm_add_ps(_mm_sub_ps(v24, v32), v14);
      if ( v16 )
      {
        LODWORD(v41) = v17;
        LODWORD(v40) = 0;
        LODWORD(id) = v23;
        v16->vfptr->displayTriangle(v16, (hkResult *)&v55, &a, &b, &c, id, v40, v41);
        LODWORD(v33) = v17;
        LODWORD(v34) = 0;
        LODWORD(v35) = v23;
        v16->vfptr->displayTriangle(v16, (hkResult *)&v47, &c, &v46, &a, v35, v34, v33);
      }
      else
      {
        hkDebugDisplay::displayTriangle(
          hkSingleton<hkDebugDisplay>::s_instance,
          &a,
          &b,
          &c,
          v23,
          0,
          (int)hkDebugDisplayProcess::m_tag);
        hkDebugDisplay::displayTriangle(
          hkSingleton<hkDebugDisplay>::s_instance,
          &c,
          &v46,
          &a,
          v23,
          0,
          (int)hkDebugDisplayProcess::m_tag);
      }
      if ( v12 > 1 )
      {
        v45.m_quad = _mm_add_ps(v14, v24);
        if ( v16 )
        {
          LODWORD(v41) = v17;
          LODWORD(v40) = 0;
          LODWORD(id) = v23;
          v16->vfptr->displayTriangle(v16, (hkResult *)&v50, &c, &v51, &v45, id, v40, v41);
          LODWORD(v36) = v17;
          LODWORD(v37) = 0;
          LODWORD(v38) = v23;
          v16->vfptr->displayTriangle(v16, (hkResult *)&v49, &v52, &v46, &v45, v38, v37, v36);
        }
        else
        {
          hkDebugDisplay::displayTriangle(
            hkSingleton<hkDebugDisplay>::s_instance,
            &c,
            &v51,
            &v45,
            v23,
            0,
            (int)hkDebugDisplayProcess::m_tag);
          hkDebugDisplay::displayTriangle(
            hkSingleton<hkDebugDisplay>::s_instance,
            &v52,
            &v46,
            &v45,
            v23,
            0,
            (int)hkDebugDisplayProcess::m_tag);
        }
      }
      path = v53;
      v18 = v54;
      v11 = v42;
      ++v12;
      v51.m_quad = b.m_quad;
      v52.m_quad = a.m_quad;
      ++v10;
      ++v20;
    }
    while ( v12 < v13 );
  }
}

// File Line: 436
// RVA: 0xC47EB0
void __fastcall hkaiNavMeshDebugUtils::drawPathWithRadius(hkaiPathfindingUtil::FindPathInput *pathInput, hkaiPathfindingUtil::FindPathOutput *pathOutput, unsigned int color, unsigned int failureColor, float displayOffset)
{
  hkaiNavMeshDebugUtils::_drawPathWithRadius(pathInput, pathOutput, color, failureColor, 0i64, 0, displayOffset);
}

// File Line: 441
// RVA: 0xC47EE0
void __usercall hkaiNavMeshDebugUtils::_drawPathWithRadius(hkaiPathfindingUtil::FindPathInput *pathInput@<rcx>, hkaiPathfindingUtil::FindPathOutput *pathOutput@<rdx>, unsigned int color@<r8d>, unsigned int failureColor@<r9d>, hkDebugDisplayHandler *a5@<rdi>, __m128 *a6@<xmm9>, hkDebugDisplayHandler *displayHandler, int tag, float displayOffset)
{
  unsigned int v9; // er13
  int v10; // er9
  hkaiPathfindingUtil::FindPathOutput *v11; // r14
  int v12; // edx
  int v13; // er9
  unsigned int v14; // er12
  hkaiPathfindingUtil::FindPathInput *v15; // r15
  int v16; // edi
  __int64 v17; // rbx
  hkaiPath::PathPoint *v18; // rsi
  hkaiPath::PathPoint *v19; // rcx
  int v20; // eax
  unsigned int v21; // ecx
  __m128 v22; // xmm6
  hkVector4f *v23; // rdi
  int v24; // ebx
  hkaiPath::PathPoint *v25; // rcx
  hkVector4f v26; // xmm0
  float offset[4]; // [rsp+38h] [rbp-31h]
  hkaiPath path; // [rsp+48h] [rbp-21h]
  hkResult result; // [rsp+C8h] [rbp+5Fh]
  hkDebugDisplayHandler *v30; // [rsp+D8h] [rbp+6Fh]

  v30 = a5;
  v9 = failureColor;
  v10 = pathOutput->m_pathOut.m_size;
  v11 = pathOutput;
  v12 = 0;
  v13 = 2 * v10;
  v14 = color;
  v15 = pathInput;
  *(_DWORD *)&path.m_memSizeAndFlags = 0x1FFFF;
  path.vfptr = (hkBaseObjectVtbl *)&hkaiPath::`vftable;
  path.m_points.m_data = 0i64;
  path.m_points.m_size = 0;
  path.m_points.m_capacityAndFlags = 2147483648;
  path.m_referenceFrame.m_storage = 0;
  if ( v13 > 0 )
  {
    if ( v13 < 0 )
      v13 = 0;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &path.m_points,
      v13,
      48);
    v12 = path.m_points.m_size;
  }
  v16 = 0;
  if ( v11->m_pathOut.m_size > 0 )
  {
    v17 = 0i64;
    do
    {
      v18 = v11->m_pathOut.m_data;
      if ( v12 == (path.m_points.m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &path.m_points, 48);
        v12 = path.m_points.m_size;
      }
      v19 = &path.m_points.m_data[v12];
      if ( v19 )
      {
        v19->m_position = v18[v17].m_position;
        v19->m_normal = v18[v17].m_normal;
        *(_OWORD *)&v19->m_userEdgeData = *(_OWORD *)&v18[v17].m_userEdgeData;
        v12 = path.m_points.m_size;
      }
      ++v12;
      ++v16;
      ++v17;
      path.m_points.m_size = v12;
    }
    while ( v16 < v11->m_pathOut.m_size );
  }
  v20 = (unsigned __int8)v11->m_outputParameters.m_status.m_storage;
  v21 = v14;
  v22 = _mm_mul_ps(
          _mm_cvtepi32_ps(
            _mm_add_epi32(
              _mm_unpacklo_epi16((__m128i)0i64, _mm_loadl_epi64((const __m128i *)&v15->m_searchParameters)),
              _mm_loadu_si128((const __m128i *)hkPackedUnitVector_m_offset))),
          (__m128)xmmword_141A713A0);
  *(__m128 *)offset = v22;
  if ( (unsigned int)(v20 - 3) <= 1 && v15->m_goalPoints.m_size == 1 )
  {
    v23 = v15->m_goalPoints.m_data;
    v24 = *v15->m_goalFaceKeys.m_data >> 22;
    if ( v12 == (path.m_points.m_capacityAndFlags & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &path.m_points, 48);
      v12 = path.m_points.m_size;
    }
    v25 = &path.m_points.m_data[v12];
    path.m_points.m_size = v12 + 1;
    v26.m_quad = v23->m_quad;
    v25->m_normal.m_quad = v22;
    v25->m_sectionId = v24;
    v25->m_userEdgeData = 0;
    v25->m_flags.m_storage = 0;
    v25->m_position = (hkVector4f)v26.m_quad;
    v21 = v9;
  }
  hkaiNavMeshDebugUtils::_drawPath(
    &path,
    v15->m_agentInfo.m_diameter,
    (hkVector4f *)offset,
    v14,
    a6,
    v21,
    v30,
    (int)displayHandler,
    *(float *)&tag);
  path.m_points.m_size = 0;
  if ( path.m_points.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      path.m_points.m_data,
      48 * (path.m_points.m_capacityAndFlags & 0x3FFFFFFF));
}ainerHeapAllocator::s_alloc,
      path.m_points.m_data,
      48 * (path.m_points.m_capacityAndFlags & 0x3FFFFFFF));

// File Line: 466
// RVA: 0xC4B4A0
int perturbColor(...)
{
  __m128 v3; // xmm4
  int v4; // edx
  signed int v5; // eax
  int v6; // edx
  float v7; // xmm0_4
  signed int v8; // eax
  int v9; // edx
  __m128 v10; // ST20_16
  __m128 v11; // xmm3
  __m128 v12; // xmm0
  __m128 v13; // xmm0

  v3 = 0i64;
  v4 = 1664525 * seed + 1013904223;
  v5 = v4;
  v6 = 1664525 * v4 + 1013904223;
  v7 = (float)v5;
  v8 = v6;
  v9 = 1664525 * v6 + 1013904223;
  v10.m128_f32[0] = (float)((float)(v7 * 2.3283064e-10) * 2.0) - 1.0;
  v10.m128_f32[1] = (float)((float)((float)v8 * 2.3283064e-10) * 2.0) - 1.0;
  v10.m128_f32[2] = (float)((float)((float)v9 * 2.3283064e-10) * 2.0) - 1.0;
  v11 = 0i64;
  v3.m128_f32[0] = (float)BYTE2(color) * 0.0039215689;
  v11.m128_f32[0] = (float)BYTE1(color) * 0.0039215689;
  v10.m128_f32[3] = (float)((float)((float)v9 * 2.3283064e-10) * 2.0) - 1.0;
  v12 = 0i64;
  v12.m128_f32[0] = (float)(unsigned __int8)color * 0.0039215689;
  v13 = _mm_min_ps(
          query.m_quad,
          _mm_max_ps(
            (__m128)0i64,
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps((__m128)variance, (__m128)variance, 0), v10),
              _mm_unpacklo_ps(_mm_unpacklo_ps(v3, v12), _mm_unpacklo_ps(v11, (__m128)0i64)))));
  return hkColor::rgbFromFloats(
           v13.m128_f32[0],
           COERCE_CONST_FLOAT(_mm_shuffle_ps(v13, v13, 85)),
           COERCE_CONST_FLOAT(_mm_shuffle_ps(v13, v13, 170)),
           (float)(color >> 24) * 0.0039215689);
}

// File Line: 487
// RVA: 0xC4B610
__int64 __fastcall realToOrderedUint(const float *in)
{
  return *(_DWORD *)in ^ ((*(_DWORD *)in >> 31) | 0x80000000);
}

// File Line: 500
// RVA: 0xC46810
void __fastcall hkaiNavMeshDebugUtils::showNavMesh(hkDebugDisplayHandler *displayHandler, int tag, hkaiNavMeshDebugUtils::DebugInfo *settings, hkaiNavMesh *navMesh)
{
  hkDebugDisplayHandler *v4; // rbp
  hkaiNavMesh *v5; // rbx
  hkaiNavMeshDebugUtils::DebugInfo *v6; // rdi
  int v7; // esi
  int v8; // er9
  hkaiStreamingCollection::InstanceInfo *v9; // r8
  __int64 v10; // rdx
  hkaiDirectedGraphInstance **v11; // rax
  hkaiStreamingCollection array; // [rsp+30h] [rbp-228h]
  hkResult result; // [rsp+60h] [rbp-1F8h]
  hkaiNavMeshInstance v14; // [rsp+70h] [rbp-1E8h]

  v4 = displayHandler;
  v5 = navMesh;
  v6 = settings;
  v7 = tag;
  hkaiNavMeshInstance::hkaiNavMeshInstance(&v14);
  hkaiNavMeshInstance::tempInit(&v14, v5, 0);
  hkaiStreamingCollection::hkaiStreamingCollection(&array);
  array.m_isTemporary.m_bool = 1;
  if ( (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) < 1 )
  {
    v8 = 1;
    if ( 2 * (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) > 1 )
      v8 = 2 * (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array.m_instances,
      v8,
      48);
  }
  v9 = array.m_instances.m_data;
  v10 = 1 - array.m_instances.m_size;
  if ( 1 - array.m_instances.m_size > 0 )
  {
    v11 = &array.m_instances.m_data[array.m_instances.m_size].m_clusterGraphInstance;
    do
    {
      if ( v11 != (hkaiDirectedGraphInstance **)16 )
      {
        *(v11 - 2) = 0i64;
        *(v11 - 1) = 0i64;
        *v11 = 0i64;
        v11[1] = 0i64;
        v11[2] = 0i64;
        *((_DWORD *)v11 + 6) = -1;
      }
      v11 += 6;
      --v10;
    }
    while ( v10 );
    v9 = array.m_instances.m_data;
  }
  array.m_instances.m_size = 1;
  v9->m_instancePtr = &v14;
  array.m_instances.m_data->m_clusterGraphInstance = 0i64;
  array.m_instances.m_data->m_mediator = 0i64;
  hkaiNavMeshDebugUtils::showStreamingCollection(v4, v7, v6, &array);
  hkaiStreamingCollection::~hkaiStreamingCollection(&array);
  hkaiNavMeshInstance::~hkaiNavMeshInstance(&v14);
}

// File Line: 511
// RVA: 0xC46E70
void __fastcall hkaiNavMeshDebugUtils::showNavMesh(hkaiNavMeshDebugUtils::DebugInfo *settings, hkaiNavMesh *navMesh)
{
  hkaiNavMeshDebugUtils::DebugInfo *v2; // rdi
  hkaiNavMesh *v3; // rbx
  int v4; // er9
  hkaiStreamingCollection::InstanceInfo *v5; // r8
  __int64 v6; // rdx
  hkaiDirectedGraphInstance **v7; // rax
  hkaiStreamingCollection array; // [rsp+30h] [rbp-218h]
  hkaiNavMeshInstance v9; // [rsp+60h] [rbp-1E8h]
  hkResult result; // [rsp+260h] [rbp+18h]

  v2 = settings;
  v3 = navMesh;
  hkaiNavMeshInstance::hkaiNavMeshInstance(&v9);
  hkaiNavMeshInstance::tempInit(&v9, v3, 0);
  hkaiStreamingCollection::hkaiStreamingCollection(&array);
  array.m_isTemporary.m_bool = 1;
  if ( (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) < 1 )
  {
    v4 = 1;
    if ( 2 * (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) > 1 )
      v4 = 2 * (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array.m_instances,
      v4,
      48);
  }
  v5 = array.m_instances.m_data;
  v6 = 1 - array.m_instances.m_size;
  if ( 1 - array.m_instances.m_size > 0 )
  {
    v7 = &array.m_instances.m_data[array.m_instances.m_size].m_clusterGraphInstance;
    do
    {
      if ( v7 != (hkaiDirectedGraphInstance **)16 )
      {
        *(v7 - 2) = 0i64;
        *(v7 - 1) = 0i64;
        *v7 = 0i64;
        v7[1] = 0i64;
        v7[2] = 0i64;
        *((_DWORD *)v7 + 6) = -1;
      }
      v7 += 6;
      --v6;
    }
    while ( v6 );
    v5 = array.m_instances.m_data;
  }
  array.m_instances.m_size = 1;
  v5->m_instancePtr = &v9;
  array.m_instances.m_data->m_clusterGraphInstance = 0i64;
  array.m_instances.m_data->m_mediator = 0i64;
  hkaiNavMeshDebugUtils::showStreamingCollection(0i64, 0, v2, &array);
  hkaiStreamingCollection::~hkaiStreamingCollection(&array);
  hkaiNavMeshInstance::~hkaiNavMeshInstance(&v9);
}

// File Line: 522
// RVA: 0xC46FB0
void __fastcall hkaiNavMeshDebugUtils::showNavMesh(hkaiNavMeshDebugUtils::DebugInfo *settings, hkaiNavMeshInstance *nmi)
{
  hkaiNavMeshDebugUtils::DebugInfo *v2; // rdi
  hkaiNavMeshInstance *v3; // rbx
  int v4; // er9
  hkaiStreamingCollection::InstanceInfo *v5; // r8
  __int64 v6; // rdx
  hkaiDirectedGraphInstance **v7; // rax
  hkaiStreamingCollection array; // [rsp+30h] [rbp-38h]
  hkResult result; // [rsp+78h] [rbp+10h]

  v2 = settings;
  v3 = nmi;
  hkaiStreamingCollection::hkaiStreamingCollection(&array);
  array.m_isTemporary.m_bool = 1;
  if ( (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) < 1 )
  {
    v4 = 1;
    if ( 2 * (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) > 1 )
      v4 = 2 * (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array.m_instances,
      v4,
      48);
  }
  v5 = array.m_instances.m_data;
  v6 = 1 - array.m_instances.m_size;
  if ( 1 - array.m_instances.m_size > 0 )
  {
    v7 = &array.m_instances.m_data[array.m_instances.m_size].m_clusterGraphInstance;
    do
    {
      if ( v7 != (hkaiDirectedGraphInstance **)16 )
      {
        *(v7 - 2) = 0i64;
        *(v7 - 1) = 0i64;
        *v7 = 0i64;
        v7[1] = 0i64;
        v7[2] = 0i64;
        *((_DWORD *)v7 + 6) = -1;
      }
      v7 += 6;
      --v6;
    }
    while ( v6 );
    v5 = array.m_instances.m_data;
  }
  array.m_instances.m_size = 1;
  v5->m_instancePtr = v3;
  array.m_instances.m_data->m_clusterGraphInstance = 0i64;
  array.m_instances.m_data->m_mediator = 0i64;
  hkaiNavMeshDebugUtils::showStreamingCollection(0i64, 0, v2, &array);
  hkaiStreamingCollection::~hkaiStreamingCollection(&array);
}

// File Line: 530
// RVA: 0xC46960
void __fastcall hkaiNavMeshDebugUtils::showNavMesh(hkDebugDisplayHandler *displayHandler, int tag, hkaiNavMeshDebugUtils::DebugInfo *settings, hkaiNavMeshInstance *nmi)
{
  hkDebugDisplayHandler *v4; // rbp
  hkaiNavMeshInstance *v5; // rbx
  hkaiNavMeshDebugUtils::DebugInfo *v6; // rdi
  int v7; // esi
  int v8; // er9
  hkaiStreamingCollection::InstanceInfo *v9; // r8
  __int64 v10; // rdx
  hkaiDirectedGraphInstance **v11; // rax
  hkaiStreamingCollection array; // [rsp+30h] [rbp-38h]
  hkResult result; // [rsp+88h] [rbp+20h]

  v4 = displayHandler;
  v5 = nmi;
  v6 = settings;
  v7 = tag;
  hkaiStreamingCollection::hkaiStreamingCollection(&array);
  array.m_isTemporary.m_bool = 1;
  if ( (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) < 1 )
  {
    v8 = 1;
    if ( 2 * (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) > 1 )
      v8 = 2 * (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array.m_instances,
      v8,
      48);
  }
  v9 = array.m_instances.m_data;
  v10 = 1 - array.m_instances.m_size;
  if ( 1 - array.m_instances.m_size > 0 )
  {
    v11 = &array.m_instances.m_data[array.m_instances.m_size].m_clusterGraphInstance;
    do
    {
      if ( v11 != (hkaiDirectedGraphInstance **)16 )
      {
        *(v11 - 2) = 0i64;
        *(v11 - 1) = 0i64;
        *v11 = 0i64;
        v11[1] = 0i64;
        v11[2] = 0i64;
        *((_DWORD *)v11 + 6) = -1;
      }
      v11 += 6;
      --v10;
    }
    while ( v10 );
    v9 = array.m_instances.m_data;
  }
  array.m_instances.m_size = 1;
  v9->m_instancePtr = v5;
  array.m_instances.m_data->m_clusterGraphInstance = 0i64;
  array.m_instances.m_data->m_mediator = 0i64;
  hkaiNavMeshDebugUtils::showStreamingCollection(v4, v7, v6, &array);
  hkaiStreamingCollection::~hkaiStreamingCollection(&array);
}

// File Line: 538
// RVA: 0xC470B0
void __fastcall hkaiNavMeshDebugUtils::showStreamingCollection(hkaiNavMeshDebugUtils::DebugInfo *settings, hkaiStreamingCollection *collection)
{
  hkaiNavMeshDebugUtils::showStreamingCollection(0i64, 0, settings, collection);
}

// File Line: 543
// RVA: 0xC4B630
unsigned int __fastcall getLitColor(float r, float g, float b, float alpha, hkVector4f *v0, hkVector4f *v1, hkVector4f *v2, hkVector4f *lightDir)
{
  float v8; // xmm9_4
  float v9; // xmm8_4
  __m128 v10; // xmm6
  __m128 v11; // xmm5
  float v12; // xmm11_4
  __m128 v13; // xmm7
  __m128 v14; // xmm7
  __m128 v15; // xmm1
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm4

  v8 = g;
  v9 = b;
  v10 = _mm_sub_ps(v1->m_quad, v0->m_quad);
  v11 = _mm_sub_ps(v2->m_quad, v0->m_quad);
  v12 = alpha;
  v13 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v10), _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v11));
  v14 = _mm_shuffle_ps(v13, v13, 201);
  v15 = _mm_mul_ps(v14, v14);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v17 = _mm_rsqrt_ps(v16);
  v18 = _mm_mul_ps(
          _mm_mul_ps(
            _mm_andnot_ps(
              _mm_cmpleps(v16, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
                _mm_mul_ps(*(__m128 *)_xmm, v17))),
            v14),
          lightDir->m_quad);
  v15.m128_f32[0] = fmaxf(
                      0.0,
                      (float)(0.0
                            - (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 85))
                                            + COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 0)))
                                    + COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 170))))
                    + 0.75)
                  * 0.5714286;
  return hkColor::rgbFromFloats(v15.m128_f32[0] * r, v15.m128_f32[0] * v8, v15.m128_f32[0] * v9, v12);
}

// File Line: 562
// RVA: 0xC4B7A0
unsigned int __fastcall getLitColor_0(unsigned int color, hkVector4f *v0, hkVector4f *v1, hkVector4f *v2, hkVector4f *lightDir)
{
  return getLitColor(
           (float)BYTE2(color) * 0.0039215689,
           (float)BYTE1(color) * 0.0039215689,
           (float)(unsigned __int8)color * 0.0039215689,
           (float)(color >> 24) * 0.0039215689,
           v0,
           v1,
           v2,
           lightDir);
}

// File Line: 572
// RVA: 0xC4B820
void __fastcall formatUserData(hkStringBuf *label, const int *dataPtr, int N)
{
  int v3; // er15
  int v4; // esi
  const int *v5; // rbx
  __int64 v6; // rax
  __int64 v7; // rdi
  hkStringBuf *v8; // r14
  __int64 v9; // rbp
  int v10; // er15
  const char *v11; // r9

  if ( N > 0 )
  {
    v3 = N;
    v4 = 0;
    v5 = dataPtr;
    v6 = 0i64;
    v7 = N;
    v8 = label;
    while ( !dataPtr[v6] )
    {
      if ( ++v6 >= N )
        return;
    }
    if ( N == 1 )
    {
      if ( *dataPtr )
        hkStringBuf::printf(label, "[%d]");
    }
    else
    {
      hkStringBuf::operator=(label, "[");
      v9 = 0i64;
      v10 = v3 - 1;
      do
      {
        v11 = ", ";
        if ( v4 == v10 )
          v11 = "]";
        hkStringBuf::appendPrintf(v8, "%d%s", (unsigned int)v5[v9++], v11);
        ++v4;
      }
      while ( v9 < v7 );
    }
  }
}

// File Line: 613
// RVA: 0xC46A80
void __fastcall hkaiNavMeshDebugUtils::showStreamingCollection(hkDebugDisplayHandler *displayHandler, int tag, hkaiNavMeshDebugUtils::DebugInfo *settings, hkaiStreamingCollection *collection)
{
  hkaiStreamingCollection *v4; // r15
  hkaiNavMeshDebugUtils::DebugInfo *v5; // rsi
  bool v6; // al
  bool v7; // di
  bool v8; // al
  bool v9; // bl
  bool v10; // al
  __int64 v11; // r13
  int v12; // er14
  __int64 v13; // rbx
  hkaiNavMeshInstance *v14; // rbx
  _QWORD *v15; // r8
  _QWORD *v16; // rcx
  unsigned __int64 v17; // rax
  signed __int64 v18; // rcx
  hkArrayBase<int> *v19; // r12
  int v20; // edi
  int v21; // er9
  int v22; // edx
  int v23; // ecx
  int v24; // er15
  int v25; // edi
  char *v26; // rax
  int v27; // er8
  unsigned int v28; // eax
  unsigned int v29; // er14
  unsigned int faceColor; // ST28_4
  int v31; // er14
  _QWORD *v32; // rax
  _QWORD *v33; // rcx
  _QWORD *v34; // r8
  unsigned __int64 v35; // rax
  signed __int64 v36; // rcx
  bool v37; // [rsp+30h] [rbp-50h]
  bool v38; // [rsp+31h] [rbp-4Fh]
  bool v39; // [rsp+32h] [rbp-4Eh]
  char v40; // [rsp+33h] [rbp-4Dh]
  char v41; // [rsp+34h] [rbp-4Ch]
  int v42; // [rsp+38h] [rbp-48h]
  void *array; // [rsp+40h] [rbp-40h]
  int v44; // [rsp+48h] [rbp-38h]
  int v45; // [rsp+4Ch] [rbp-34h]
  hkArray<hkRadixSort::SortData32,hkContainerDebugAllocator> sortArray; // [rsp+50h] [rbp-30h]
  hkResult result; // [rsp+60h] [rbp-20h]
  __int64 v48; // [rsp+68h] [rbp-18h]
  hkDebugDisplayHandler *displayHandlera; // [rsp+B0h] [rbp+30h]
  int taga; // [rsp+B8h] [rbp+38h]
  hkaiStreamingCollection *collectiona; // [rsp+C8h] [rbp+48h]

  collectiona = collection;
  taga = tag;
  displayHandlera = displayHandler;
  v4 = collection;
  v5 = settings;
  v6 = hkaiNavMeshDebugUtils::DebugInfo::shouldDrawFaces(settings);
  v7 = v6;
  v37 = v6;
  v8 = hkaiNavMeshDebugUtils::DebugInfo::shouldDrawEdges(v5);
  v9 = v8;
  v38 = v8;
  v10 = hkaiNavMeshDebugUtils::DebugInfo::shouldDrawUserEdges(v5);
  v39 = v10;
  if ( v7 || v9 || v10 )
  {
    v11 = 0i64;
    v12 = 0;
    v42 = 0;
    if ( v4->m_instances.m_size > 0 )
    {
      v13 = 0i64;
      v48 = 0i64;
      do
      {
        if ( v12 >= v5->m_instanceEnabled.m_storage.m_numBits
          || (v5->m_instanceEnabled.m_storage.m_words.m_data[(signed __int64)v12 >> 5] >> (v12 & 0x1F)) & 1 )
        {
          v14 = *(hkaiNavMeshInstance **)((char *)&v4->m_instances.m_data->m_instancePtr + v13);
          if ( v14 )
          {
            v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
            v16 = (_QWORD *)v15[1];
            if ( (unsigned __int64)v16 < v15[3] )
            {
              *v16 = "TtshowStreamingCollection";
              v17 = __rdtsc();
              v18 = (signed __int64)(v16 + 2);
              *(_DWORD *)(v18 - 8) = v17;
              v15[1] = v18;
            }
            v19 = (hkArrayBase<int> *)&v5->m_regionMap->m_data;
            sortArray.m_data = 0i64;
            sortArray.m_size = 0;
            sortArray.m_capacityAndFlags = 2147483648;
            array = 0i64;
            v44 = 0;
            v45 = 2147483648;
            if ( !v19 || v19->m_size != v14->m_numOriginalFaces + v14->m_ownedFaces.m_size )
            {
              if ( v5->m_colorRegions.m_bool
                || v5->m_showSingleRegionIndex != -1
                || v5->m_highlightSingleRegionIndex != -1 )
              {
                v20 = v14->m_numOriginalFaces + v14->m_ownedFaces.m_size;
                if ( v20 <= 0 )
                {
                  result.m_enum = 0;
                }
                else
                {
                  v21 = v14->m_numOriginalFaces + v14->m_ownedFaces.m_size;
                  if ( v20 < 0 )
                    v21 = 0;
                  hkArrayUtil::_reserve(
                    &result,
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                    &array,
                    v21,
                    4);
                }
                v44 = v20;
                hkaiNavMeshUtils::computeRegions(v14, 0, (hkArrayBase<int> *)&array, 0i64);
              }
              v19 = (hkArrayBase<int> *)&array;
            }
            if ( v5->m_sortTransparentFaces.m_bool )
              hkaiNavMeshDebugUtils::_sortTransparentFaces(v14, v5, &sortArray);
            v22 = v14->m_ownedFaces.m_size;
            v23 = v14->m_numOriginalFaces;
            v24 = 0;
            if ( v23 + v22 > 0 )
            {
              do
              {
                if ( v5->m_sortTransparentFaces.m_bool )
                  v25 = *((_DWORD *)&sortArray.m_data[v22 + (signed __int64)v23 - v11] - 1);
                else
                  v25 = v24;
                if ( v14->m_faceFlags.m_size )
                {
                  v26 = &v41;
                  v41 = v14->m_faceFlags.m_data[v25].m_storage;
                }
                else
                {
                  v40 = 0;
                  v26 = &v40;
                }
                v27 = v5->m_showSingleRegionIndex;
                if ( (v27 == -1 || v19->m_data[v25] == v27) && (!(*v26 & 1) || v5->m_showHiddenFaces.m_bool) )
                {
                  if ( !v37 && !v38 )
                    goto LABEL_56;
                  v28 = hkaiNavMeshDebugUtils::_getUnlitFaceColor(v14, v5, v19, v25);
                  v29 = v28;
                  if ( v37 )
                    hkaiNavMeshDebugUtils::_showFace(displayHandlera, taga, v14, v5, v25, v28);
                  if ( v38 )
                  {
                    faceColor = v29;
                    v31 = taga;
                    hkaiNavMeshDebugUtils::_showEdgesForFace(displayHandlera, taga, v14, v5, v25, faceColor);
                  }
                  else
                  {
LABEL_56:
                    v31 = taga;
                  }
                  if ( v39 )
                    hkaiNavMeshDebugUtils::_showUserEdgesForFace(displayHandlera, v31, collectiona, v14, v5, v25);
                }
                v22 = v14->m_ownedFaces.m_size;
                v23 = v14->m_numOriginalFaces;
                ++v24;
                ++v11;
              }
              while ( v24 < v23 + v22 );
              v12 = v42;
            }
            v11 = 0i64;
            v44 = 0;
            if ( v45 >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                array,
                4 * v45);
            array = 0i64;
            v45 = 2147483648;
            sortArray.m_size = 0;
            if ( sortArray.m_capacityAndFlags >= 0 )
              hkContainerDebugAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerDebugAllocator::s_alloc,
                sortArray.m_data,
                8 * sortArray.m_capacityAndFlags);
            sortArray.m_data = 0i64;
            sortArray.m_capacityAndFlags = 2147483648;
            v32 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
            v4 = collectiona;
            v33 = (_QWORD *)v32[1];
            v34 = v32;
            if ( (unsigned __int64)v33 < v32[3] )
            {
              *v33 = "Et";
              v35 = __rdtsc();
              v36 = (signed __int64)(v33 + 2);
              *(_DWORD *)(v36 - 8) = v35;
              v34[1] = v36;
            }
          }
        }
        v48 += 48i64;
        ++v12;
        v13 = v48;
        v42 = v12;
      }
      while ( v12 < v4->m_instances.m_size );
    }
  }
}

// File Line: 698
// RVA: 0xC4B8F0
int cubicHermite(...)
{
  float v6; // xmm4_4
  __m128 v7; // xmm7
  __m128 v8; // xmm6
  __m128 v9; // xmm0
  __m128 v10; // xmm3
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  hkVector4f v13; // xmm3
  hkVector4f v14; // xmm2
  hkVector4f v15; // xmm1

  v6 = *(float *)&t;
  v7 = (__m128)t;
  v7.m128_f32[0] = *(float *)&t * *(float *)&t;
  v8 = v7;
  v9 = v7;
  v8.m128_f32[0] = v7.m128_f32[0] * v6;
  v10 = v8;
  v11 = v8;
  v12 = v8;
  v9.m128_f32[0] = (float)(v7.m128_f32[0] * v6) - v7.m128_f32[0];
  v10.m128_f32[0] = (float)((float)((float)(v7.m128_f32[0] * v6) * 2.0) - (float)(v7.m128_f32[0] * 3.0)) + 1.0;
  v12.m128_f32[0] = (float)((float)(v7.m128_f32[0] * v6) - (float)(v7.m128_f32[0] * 2.0)) + v6;
  v11.m128_f32[0] = (float)((float)(v7.m128_f32[0] * v6) * -2.0) + (float)(v7.m128_f32[0] * 3.0);
  v13.m_quad = _mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), p0->m_quad);
  *pOut = (hkVector4f)v13.m_quad;
  v14.m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), n0->m_quad), v13.m_quad);
  *pOut = (hkVector4f)v14.m_quad;
  v15.m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), p1->m_quad), v14.m_quad);
  *pOut = (hkVector4f)v15.m_quad;
  pOut->m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), n1->m_quad), v15.m_quad);
}

// File Line: 714
// RVA: 0xC4B9B0
void __fastcall getEdgeArcPoints(hkVector4f *start, hkVector4f *end, hkVector4f *inNormal, hkVector4f *outNormal, hkArray<hkVector4f,hkContainerHeapAllocator> *pointsOut)
{
  hkVector4f *v5; // rbp
  hkVector4f *v6; // rsi
  __m128 v7; // xmm1
  __m128 v8; // xmm1
  int v9; // eax
  __m128 v10; // xmm4
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __m128 v13; // xmm5
  float v14; // xmm6_4
  signed __int64 v15; // rdi
  __int64 v16; // r10
  int v17; // er10
  __int64 v18; // r10
  hkVector4f n1; // [rsp+30h] [rbp-58h]
  hkVector4f n0; // [rsp+40h] [rbp-48h]
  hkVector4f pOut; // [rsp+50h] [rbp-38h]

  v5 = end;
  v6 = start;
  v7 = _mm_sub_ps(start->m_quad, end->m_quad);
  v8 = _mm_mul_ps(v7, v7);
  v9 = pointsOut->m_capacityAndFlags & 0x3FFFFFFF;
  v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v11 = _mm_rsqrt_ps(v10);
  v12 = _mm_andnot_ps(
          _mm_cmpleps(v10, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v11), v11)),
              _mm_mul_ps(*(__m128 *)_xmm, v11)),
            v10));
  v13 = _mm_mul_ps(inNormal->m_quad, v12);
  n1.m_quad = _mm_mul_ps(
                _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), outNormal->m_quad),
                v12);
  n0.m_quad = v13;
  v14 = FLOAT_0_1;
  if ( pointsOut->m_size == v9 )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, pointsOut, 16);
  v15 = 10i64;
  pointsOut->m_data[pointsOut->m_size++] = (hkVector4f)v6->m_quad;
  v16 = (unsigned int)pointsOut->m_size;
  do
  {
    cubicHermite(v14, v6, v5, &n0, &n1, &pOut);
    if ( v17 == (pointsOut->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, pointsOut, 16);
    v14 = v14 + 0.1;
    pointsOut->m_data[pointsOut->m_size++] = (hkVector4f)pOut.m_quad;
    v18 = (unsigned int)pointsOut->m_size;
    --v15;
  }
  while ( v15 );
}

// File Line: 736
// RVA: 0xC48850
void __fastcall hkaiNavMeshDebugUtils::_showUserEdgeArc(bool curEnabled, bool oppEnabled, hkVector4f *curStart, hkVector4f *curEnd, hkVector4f *oppStart, hkVector4f *oppEnd, hkVector4f *curNormal, hkVector4f *oppNormal, unsigned int color, hkaiNavMeshDebugUtils::DebugInfo *settings, hkDebugDisplayHandler *displayHandler, int tag)
{
  hkDisplayGeometry *v12; // rbx
  hkVector4f *v13; // [rsp+20h] [rbp-48h]
  hkVector4f *v14; // [rsp+28h] [rbp-40h]
  hkArrayBase<hkDisplayGeometry *> geometries; // [rsp+40h] [rbp-28h]
  hkDisplayGeometry *v16; // [rsp+50h] [rbp-18h]

  v12 = hkaiNavMeshDebugUtils::makeUserEdgeArc(
          curEnabled,
          oppEnabled,
          curStart,
          curEnd,
          oppStart,
          oppEnd,
          curNormal,
          oppNormal);
  geometries.m_capacityAndFlags = -2147483647;
  geometries.m_size = 1;
  geometries.m_data = &v16;
  v16 = v12;
  if ( displayHandler )
  {
    LODWORD(v14) = tag;
    LODWORD(v13) = 0;
    displayHandler->vfptr->displayGeometry(
      displayHandler,
      (hkResult *)&displayHandler,
      &geometries,
      color & 0xFFFFFF | (color >> 1) & 0x7F000000,
      (int)v13,
      (int)v14);
  }
  else
  {
    hkDebugDisplay::displayGeometry(
      hkSingleton<hkDebugDisplay>::s_instance,
      &geometries,
      color & 0xFFFFFF | (color >> 1) & 0x7F000000,
      0,
      (int)hkDebugDisplayProcess::m_tag);
  }
  hkReferencedObject::removeReference((hkReferencedObject *)&v12->vfptr);
  geometries.m_size = 0;
  if ( geometries.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      geometries.m_data,
      8 * geometries.m_capacityAndFlags);
}

// File Line: 758
// RVA: 0xC48990
hkArray<hkVector4f,hkContainerHeapAllocator> *__fastcall hkaiNavMeshDebugUtils::makeUserEdgeArc(bool curEnabled, bool oppEnabled, hkVector4f *curStart, hkVector4f *curEnd, hkVector4f *oppStart, hkVector4f *oppEnd, hkVector4f *curNormal, hkVector4f *oppNormal)
{
  hkVector4f *v8; // r14
  hkVector4f *v9; // rsi
  _QWORD **v10; // rax
  hkDisplayWireframe *v11; // rax
  int v12; // er15
  __int64 v13; // r12
  hkArray<hkVector4f,hkContainerHeapAllocator> *v14; // rdi
  __int64 v15; // rsi
  hkArray<hkVector4f,hkContainerHeapAllocator> *v16; // rbx
  __m128 v17; // xmm6
  hkVector4f *v18; // rdi
  hkVector4f *v19; // rdi
  hkVector4f *v20; // rdi
  hkVector4f *v21; // rdi
  hkVector4f v22; // xmm0
  int v23; // eax
  hkVector4f *v24; // r14
  hkVector4f *v25; // r14
  hkVector4f *v26; // r14
  hkVector4f *v27; // r14
  __m128 v28; // xmm8
  __m128 v29; // xmm9
  __m128 v30; // xmm6
  __m128 v31; // xmm7
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // eax
  hkArray<hkVector4f,hkContainerHeapAllocator> *pointsOut; // [rsp+20h] [rbp-69h]
  __int64 v38; // [rsp+28h] [rbp-61h]
  hkArray<hkVector4f,hkContainerHeapAllocator> v39; // [rsp+30h] [rbp-59h]
  hkArray<hkVector4f,hkContainerHeapAllocator> v40; // [rsp+40h] [rbp-49h]
  char vars0; // [rsp+D0h] [rbp+47h]
  void *retaddr; // [rsp+D8h] [rbp+4Fh]
  hkVector4f *v43; // [rsp+F0h] [rbp+67h]
  hkVector4f *end; // [rsp+F8h] [rbp+6Fh]

  v8 = curStart;
  v9 = curEnd;
  v10 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = (hkDisplayWireframe *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v10[11] + 8i64))(v10[11], 128i64);
  v12 = 0;
  if ( v11 )
    hkDisplayWireframe::hkDisplayWireframe(v11);
  v40.m_data = 0i64;
  v40.m_size = 0;
  v40.m_capacityAndFlags = 2147483648;
  v39.m_data = 0i64;
  v39.m_size = 0;
  v39.m_capacityAndFlags = 2147483648;
  getEdgeArcPoints(v8, end, oppStart, oppEnd, &v40);
  getEdgeArcPoints(v9, v43, oppStart, oppEnd, &v39);
  v13 = v40.m_size;
  v14 = pointsOut;
  v15 = 0i64;
  v16 = pointsOut + 7;
  v38 = v40.m_size - 1;
  if ( v38 > 0 )
  {
    while ( v15 || !(_BYTE)retaddr )
    {
      if ( v12 == (_DWORD)v13 - 2 && vars0 )
      {
        v17 = _mm_add_ps(
                _mm_mul_ps(_mm_sub_ps(v39.m_data[v13 - 1].m_quad, v40.m_data[v13 - 1].m_quad), *(__m128 *)_xmm),
                v40.m_data[v13 - 1].m_quad);
        if ( pointsOut[7].m_size == (pointsOut[7].m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v16, 16);
        pointsOut[7].m_data[pointsOut[7].m_size++].m_quad = v17;
        v24 = v40.m_data;
        if ( pointsOut[7].m_size == (pointsOut[7].m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v16, 16);
        pointsOut[7].m_data[pointsOut[7].m_size++] = v24[v13 - 2];
        v25 = v40.m_data;
        if ( pointsOut[7].m_size == (pointsOut[7].m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v16, 16);
        pointsOut[7].m_data[pointsOut[7].m_size++] = v25[v13 - 2];
        v26 = v39.m_data;
        if ( pointsOut[7].m_size == (pointsOut[7].m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v16, 16);
        pointsOut[7].m_data[pointsOut[7].m_size++] = v26[v13 - 2];
        v27 = v39.m_data;
        if ( pointsOut[7].m_size == (pointsOut[7].m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v16, 16);
        v22.m_quad = (__m128)v27[v13 - 2];
        goto LABEL_17;
      }
      v28 = _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(v39.m_data[v15 + 1].m_quad, v40.m_data[v15 + 1].m_quad), (__m128)_xmm),
              v40.m_data[v15 + 1].m_quad);
      v29 = _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(v40.m_data[v15 + 1].m_quad, v39.m_data[v15 + 1].m_quad), (__m128)_xmm),
              v39.m_data[v15 + 1].m_quad);
      v30 = _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(v39.m_data[v15].m_quad, v40.m_data[v15].m_quad), (__m128)_xmm),
              v40.m_data[v15].m_quad);
      v31 = _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(v40.m_data[v15].m_quad, v39.m_data[v15].m_quad), (__m128)_xmm),
              v39.m_data[v15].m_quad);
      if ( pointsOut[7].m_size == (pointsOut[7].m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v16, 16);
      pointsOut[7].m_data[pointsOut[7].m_size].m_quad = v30;
      v32 = pointsOut[7].m_capacityAndFlags;
      if ( ++pointsOut[7].m_size == (v32 & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v16, 16);
      pointsOut[7].m_data[pointsOut[7].m_size].m_quad = v28;
      v33 = pointsOut[7].m_capacityAndFlags;
      if ( ++pointsOut[7].m_size == (v33 & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v16, 16);
      pointsOut[7].m_data[pointsOut[7].m_size].m_quad = v31;
      v34 = pointsOut[7].m_capacityAndFlags;
      if ( ++pointsOut[7].m_size == (v34 & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v16, 16);
      pointsOut[7].m_data[pointsOut[7].m_size++].m_quad = v29;
      if ( v15 <= 0 )
        goto LABEL_48;
      if ( pointsOut[7].m_size == (pointsOut[7].m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v16, 16);
      pointsOut[7].m_data[pointsOut[7].m_size].m_quad = v30;
      v35 = pointsOut[7].m_capacityAndFlags;
      if ( ++pointsOut[7].m_size == (v35 & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v16, 16);
      pointsOut[7].m_data[pointsOut[7].m_size].m_quad = v31;
LABEL_47:
      ++pointsOut[7].m_size;
LABEL_48:
      ++v15;
      ++v12;
      if ( v15 >= v38 )
      {
        v14 = pointsOut;
        goto LABEL_50;
      }
    }
    v17 = _mm_add_ps(
            _mm_mul_ps(_mm_sub_ps(v39.m_data->m_quad, v40.m_data->m_quad), *(__m128 *)_xmm),
            v40.m_data->m_quad);
    if ( pointsOut[7].m_size == (pointsOut[7].m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v16, 16);
    pointsOut[7].m_data[pointsOut[7].m_size++].m_quad = v17;
    v18 = v40.m_data;
    if ( pointsOut[7].m_size == (pointsOut[7].m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v16, 16);
    pointsOut[7].m_data[pointsOut[7].m_size++] = (hkVector4f)v18[1].m_quad;
    v19 = v40.m_data;
    if ( pointsOut[7].m_size == (pointsOut[7].m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v16, 16);
    pointsOut[7].m_data[pointsOut[7].m_size++] = (hkVector4f)v19[1].m_quad;
    v20 = v39.m_data;
    if ( pointsOut[7].m_size == (pointsOut[7].m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v16, 16);
    pointsOut[7].m_data[pointsOut[7].m_size++] = (hkVector4f)v20[1].m_quad;
    v21 = v39.m_data;
    if ( pointsOut[7].m_size == (pointsOut[7].m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v16, 16);
    v22.m_quad = (__m128)v21[1];
LABEL_17:
    pointsOut[7].m_data[pointsOut[7].m_size] = (hkVector4f)v22.m_quad;
    v23 = pointsOut[7].m_capacityAndFlags;
    if ( ++pointsOut[7].m_size == (v23 & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v16, 16);
    pointsOut[7].m_data[pointsOut[7].m_size].m_quad = v17;
    goto LABEL_47;
  }
LABEL_50:
  v39.m_size = 0;
  if ( v39.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v39.m_data,
      16 * v39.m_capacityAndFlags);
  v39.m_data = 0i64;
  v40.m_size = 0;
  v39.m_capacityAndFlags = 2147483648;
  if ( v40.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v40.m_data,
      16 * v40.m_capacityAndFlags);
  return v14;
}

// File Line: 821
// RVA: 0xC48350
void __usercall hkaiNavMeshDebugUtils::_showUserEdgePair(hkaiStreamingCollection *collection@<rcx>, hkaiNavMeshDebugUtils::DebugInfo *settings@<rdx>, unsigned int faceKey@<r8d>, unsigned int uedgeKey@<r9d>, hkDebugDisplayHandler *a5@<rbx>, hkDebugDisplayHandler *displayHandler, int tag)
{
  hkaiNavMeshDebugUtils::DebugInfo *v7; // r13
  hkaiStreamingCollection::InstanceInfo *v8; // rax
  unsigned int v9; // ebx
  hkaiNavMeshInstance *v10; // rdi
  int v11; // er14
  hkaiNavMesh::Edge *v12; // r15
  int v13; // esi
  __m128 v14; // xmm6
  bool v15; // zf
  char *v16; // rdx
  unsigned int v17; // er12
  unsigned int v18; // ecx
  signed int v19; // eax
  unsigned int color; // er14
  unsigned int v21; // ecx
  unsigned int v22; // eax
  unsigned int v23; // esi
  unsigned int v24; // eax
  hkaiNavMeshInstance *v25; // rsi
  hkaiNavMesh::Edge *v26; // r12
  BOOL v27; // esi
  BOOL v28; // er12
  hkArray<int,hkContainerHeapAllocator> *instanceMap; // [rsp+20h] [rbp-D0h]
  hkArray<int,hkContainerHeapAllocator> *instanceMapa; // [rsp+20h] [rbp-D0h]
  hkArray<int,hkContainerHeapAllocator> *instanceMapb; // [rsp+20h] [rbp-D0h]
  __int64 index; // [rsp+28h] [rbp-C8h]
  __int64 indexa; // [rsp+28h] [rbp-C8h]
  __int64 indexb; // [rsp+28h] [rbp-C8h]
  __int64 striding; // [rsp+30h] [rbp-C0h]
  hkVector4f pos; // [rsp+60h] [rbp-90h]
  hkVector4f edgeB; // [rsp+70h] [rbp-80h]
  hkVector4f edgeA; // [rsp+80h] [rbp-70h]
  hkaiNavMeshInstance *v39; // [rsp+90h] [rbp-60h]
  hkVector4f end; // [rsp+A0h] [rbp-50h]
  char v41; // [rsp+B0h] [rbp-40h]
  hkVector4f oppNormal; // [rsp+C0h] [rbp-30h]
  char v43; // [rsp+D0h] [rbp-20h]
  int faceIndex; // [rsp+E0h] [rbp-10h]
  hkStringBuf v45; // [rsp+F0h] [rbp+0h]
  __int64 vars0; // [rsp+1D0h] [rbp+E0h]
  void *retaddr; // [rsp+1D8h] [rbp+E8h]
  unsigned int v48; // [rsp+1E8h] [rbp+F8h]
  hkDebugDisplayHandler *v49; // [rsp+1F0h] [rbp+100h]
  unsigned int v50; // [rsp+1F8h] [rbp+108h]

  v50 = uedgeKey;
  v7 = settings;
  if ( settings->m_showUserEdges.m_bool )
  {
    v49 = a5;
    v8 = collection->m_instances.m_data;
    v9 = uedgeKey & 0x3FFFFF;
    edgeB.m_quad.m128_i32[0] = faceKey & 0x3FFFFF;
    v10 = v8[faceKey >> 22].m_instancePtr;
    v11 = v10->m_numOriginalEdges;
    v12 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__23(
            v10->m_originalEdges,
            v10->m_numOriginalEdges,
            &v10->m_instancedEdges,
            &v10->m_ownedEdges,
            &v10->m_edgeMap,
            uedgeKey & 0x3FFFFF);
    v13 = v10->m_edgeDataStriding ? *hkaiNavMeshInstance_getWithStriding_int__4(
                                       v10->m_originalEdgeData,
                                       v11,
                                       &v10->m_instancedEdgeData,
                                       &v10->m_ownedEdgeData,
                                       &v10->m_edgeMap,
                                       v9,
                                       v10->m_edgeDataStriding) : 0;
    if ( v12->m_oppositeEdge != -1 )
    {
      v14 = v7->m_displayOffset.m_quad;
      hkaiNavMeshInstance::getEdgePoints(v10, v9, &edgeA, &edgeB);
      v15 = v7->m_labelEdges.m_bool == 0;
      v16 = v45.m_string.m_storage;
      v45.m_string.m_data = v45.m_string.m_storage;
      v45.m_string.m_capacityAndFlags = -2147483520;
      v45.m_string.m_size = 1;
      v45.m_string.m_storage[0] = 0;
      edgeB.m_quad = _mm_add_ps(edgeB.m_quad, v14);
      edgeA.m_quad = _mm_add_ps(edgeA.m_quad, v14);
      pos.m_quad = _mm_add_ps(
                     _mm_mul_ps(_mm_sub_ps(edgeB.m_quad, edgeA.m_quad), (__m128)xmmword_141A711B0),
                     edgeA.m_quad);
      if ( !v15 )
      {
        hkStringBuf::printf(&v45, "%d ", v9);
        v16 = v45.m_string.m_data;
      }
      if ( v49 )
      {
        v17 = v50;
        LODWORD(striding) = v50;
        LODWORD(index) = 0;
        LODWORD(instanceMap) = v7->m_edgeLabelColor;
        v49->vfptr->display3dText(v49, (hkResult *)&retaddr, v16, &pos, (unsigned int)instanceMap, index, striding);
      }
      else
      {
        hkDebugDisplay::display3dText(
          hkSingleton<hkDebugDisplay>::s_instance,
          v16,
          &pos,
          v7->m_edgeLabelColor,
          0,
          (int)hkDebugDisplayProcess::m_tag);
        v17 = v50;
      }
      v45.m_string.m_size = 0;
      if ( v45.m_string.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          v45.m_string.m_data,
          v45.m_string.m_capacityAndFlags & 0x3FFFFFFF);
      v18 = v12->m_oppositeEdge;
      if ( v12->m_flags.m_storage & 0x40 )
        v19 = v18 >> 22;
      else
        v19 = v10->m_runtimeId;
      if ( v18 == -1 )
        v19 = -1;
      v39 = *(hkaiNavMeshInstance **)(*(_QWORD *)(vars0 + 32) + 48i64 * v19);
      LOBYTE(retaddr) = v39 != 0i64;
      if ( v7->m_colorUserEdgesByData.m_bool )
        color = hkColor::getPaletteColor(v13, 127);
      else
        color = v7->m_userEdgeColor;
      v21 = v12->m_oppositeEdge;
      if ( v12->m_flags.m_storage & 0x40 )
        v22 = v21 & 0xFFC00000;
      else
        v22 = v10->m_runtimeId << 22;
      v23 = v22 | v21 & 0x3FFFFF;
      if ( v21 == -1 )
        v23 = -1;
      if ( !(_BYTE)retaddr || (v24 = v48, v48 < v23) )
      {
        if ( v49 )
        {
          LODWORD(striding) = v17;
          LODWORD(indexa) = 0;
          LODWORD(instanceMapa) = color;
          v49->vfptr->displayLine(v49, (hkResult *)&v41, &edgeA, &edgeB, (unsigned int)instanceMapa, indexa, striding);
        }
        else
        {
          hkDebugDisplay::displayLine(
            hkSingleton<hkDebugDisplay>::s_instance,
            &edgeA,
            &edgeB,
            color,
            0,
            (int)hkDebugDisplayProcess::m_tag);
        }
        v24 = v48;
      }
      if ( (_BYTE)retaddr && v24 < v23 )
      {
        v25 = v39;
        v26 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__23(
                v39->m_originalEdges,
                v39->m_numOriginalEdges,
                &v39->m_instancedEdges,
                &v39->m_ownedEdges,
                &v39->m_edgeMap,
                v12->m_oppositeEdge & 0x3FFFFF);
        hkaiNavMeshInstance::getEdgePoints(v25, v26, &pos, &end);
        v15 = v12->m_oppositeEdge == -1;
        pos.m_quad = _mm_add_ps(pos.m_quad, v14);
        end.m_quad = _mm_add_ps(end.m_quad, v14);
        v27 = !v15 && !(v12->m_flags.m_storage & 0x20);
        v28 = v26->m_oppositeEdge != -1 && !(v26->m_flags.m_storage & 0x20);
        if ( v49 )
        {
          LODWORD(striding) = v50;
          LODWORD(indexb) = 0;
          LODWORD(instanceMapb) = color;
          v49->vfptr->displayLine(v49, (hkResult *)&retaddr, &pos, &end, (unsigned int)instanceMapb, indexb, striding);
        }
        else
        {
          hkDebugDisplay::displayLine(
            hkSingleton<hkDebugDisplay>::s_instance,
            &pos,
            &end,
            color,
            0,
            (int)hkDebugDisplayProcess::m_tag);
        }
        hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
          (hkaiNavMeshUtils *)&v43,
          (hkSimdFloat32 *)v10,
          (hkaiNavMeshInstance *)edgeB.m_quad.m128_u32[0],
          (__int64)&faceIndex);
        hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
          (hkaiNavMeshUtils *)&v43,
          (hkSimdFloat32 *)v39,
          (hkaiNavMeshInstance *)(v12->m_oppositeFace & 0x3FFFFF),
          (__int64)&oppNormal);
        if ( v27 || v28 )
          hkaiNavMeshDebugUtils::_showUserEdgeArc(
            v27 != 0,
            v28 != 0,
            &edgeA,
            &edgeB,
            &pos,
            &end,
            (hkVector4f *)&faceIndex,
            &oppNormal,
            color,
            v7,
            v49,
            v50);
      }
    }
  }
}            &oppNormal,
            color,
            v7,
            v49,
            v50);
      }
    }
  }
}

// File Line: 906
// RVA: 0xC48FE0
float __fastcall hkaiNavMeshDebugUtils::_calcNonplanarity(hkaiNavMeshInstance *nmi, int faceIdx)
{
  float v2; // xmm6_4
  float v3; // xmm7_4
  int index; // ebx
  hkaiNavMeshInstance *v5; // rdi
  int v6; // edx
  hkaiNavMesh::Face *v7; // rcx
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm2
  __m128 v11; // xmm12
  hkaiNavMesh::Face *v12; // rax
  hkaiNavMesh::Face *v13; // rsi
  __int16 v14; // r15
  int v15; // ebx
  int v16; // ebp
  int v17; // er13
  __m128 v18; // xmm8
  signed int v19; // er14
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v20; // r9
  __m128 v21; // xmm9
  __m128 v22; // xmm10
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v23; // r8
  __m128 v24; // xmm11
  __int64 v25; // rcx
  __m128 *v26; // rax
  __m128 v27; // xmm2
  float v28; // xmm1_4
  int faceIndex[4]; // [rsp+30h] [rbp-C8h]
  char v31; // [rsp+40h] [rbp-B8h]

  v2 = FLOAT_N3_40282e38;
  v3 = FLOAT_3_40282e38;
  index = faceIdx;
  v5 = nmi;
  hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
    (hkaiNavMeshUtils *)&v31,
    (hkSimdFloat32 *)nmi,
    (hkaiNavMeshInstance *)(unsigned int)faceIdx,
    (__int64)faceIndex);
  v6 = v5->m_numOriginalFaces;
  v7 = v5->m_originalFaces;
  v8 = _mm_mul_ps(*(__m128 *)faceIndex, *(__m128 *)faceIndex);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_rsqrt_ps(v9);
  v11 = _mm_mul_ps(
          *(__m128 *)faceIndex,
          _mm_andnot_ps(
            _mm_cmpleps(v9, (__m128)0i64),
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)), _mm_mul_ps(*(__m128 *)_xmm, v10))));
  *(__m128 *)faceIndex = v11;
  v12 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__21(
          v7,
          v6,
          &v5->m_instancedFaces,
          &v5->m_ownedFaces,
          &v5->m_faceMap,
          index);
  v13 = v12;
  v14 = v12->m_numUserEdges;
  if ( v14 <= 0 )
    v15 = v12->m_startEdgeIndex;
  else
    v15 = v12->m_startUserEdgeIndex;
  if ( v15 != -1 )
  {
    v16 = v12->m_startUserEdgeIndex;
    v17 = v5->m_numOriginalEdges;
    v18 = v5->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad;
    v19 = v5->m_numOriginalVertices;
    v20 = &v5->m_ownedEdges;
    v21 = v5->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad;
    v22 = v5->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad;
    v23 = &v5->m_instancedEdges;
    v24 = v5->m_referenceFrame.m_transform.m_translation.m_quad;
    while ( 1 )
    {
      v25 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__23(v5->m_originalEdges, v17, v23, v20, &v5->m_edgeMap, v15)->m_a;
      if ( (signed int)v25 >= v19 )
        v26 = &v5->m_ownedVertices.m_data[(signed int)v25 - v19].m_quad;
      else
        v26 = &v5->m_originalVertices[v25].m_quad;
      v27 = _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(*v26, *v26, 0), v21),
                    _mm_mul_ps(_mm_shuffle_ps(*v26, *v26, 85), v18)),
                  _mm_mul_ps(_mm_shuffle_ps(*v26, *v26, 170), v22)),
                v24),
              v11);
      v28 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v27, v27, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v27, v27, 0)))
          + COERCE_FLOAT(_mm_shuffle_ps(v27, v27, 170));
      v3 = fminf(v3, v28);
      v2 = fmaxf(v2, v28);
      if ( v15 >= v16 && v15 < v14 + v16 - 1 )
        goto LABEL_15;
      if ( v15 != v14 + v16 - 1 )
        break;
      v15 = v13->m_startEdgeIndex;
LABEL_16:
      if ( v15 == -1 )
        return v2 - v3;
    }
    if ( v15 < v13->m_startEdgeIndex || v15 >= v13->m_numEdges + v13->m_startEdgeIndex - 1 )
      return v2 - v3;
LABEL_15:
    ++v15;
    goto LABEL_16;
  }
  return v2 - v3;
}

// File Line: 931
// RVA: 0xC48140
void __fastcall hkaiNavMeshDebugUtils::reportMemoryUsed(hkaiNavMesh *mesh)
{
  int v1; // edx
  hkaiNavMesh *v2; // rbx
  int v3; // er15
  int v4; // er12
  int v5; // er13
  int v6; // esi
  int v7; // edi
  int v8; // er14
  int v9; // ebp
  int v10; // edi
  hkOstream *v11; // rax
  hkOstream *v12; // rax
  hkOstream *v13; // rax
  hkOstream *v14; // rax
  hkOstream *v15; // rax
  hkOstream *v16; // rax
  hkOstream *v17; // rax
  hkOstream *v18; // rax
  hkOstream *v19; // rax
  hkOstream *v20; // rax
  hkOstream *v21; // rax
  hkOstream *v22; // rax
  hkOstream *v23; // rax
  hkOstream *v24; // rax
  hkOstream *v25; // rax
  hkErrStream v26; // [rsp+20h] [rbp-248h]
  char buf; // [rsp+40h] [rbp-228h]

  v1 = mesh->m_edges.m_size;
  v2 = mesh;
  v3 = 16 * mesh->m_faces.m_size;
  v4 = 20 * v1;
  v5 = 16 * mesh->m_vertices.m_size;
  v6 = 4 * mesh->m_faces.m_size * mesh->m_faceDataStriding;
  v7 = 4 * v1 * mesh->m_edgeDataStriding;
  ((void (__fastcall *)(hkError *, signed __int64, const char *))hkSingleton<hkError>::s_instance->vfptr[4].__first_virtual_table_function__)(
    hkSingleton<hkError>::s_instance,
    1367214621i64,
    "hkaiNavMeshDebugUtils::reportMemoryUsed");
  hkErrStream::hkErrStream(&v26, &buf, 512);
  v8 = v2->m_vertices.m_size;
  v9 = v2->m_edges.m_size;
  LODWORD(v2) = v2->m_faces.m_size;
  v10 = v6 + v7;
  v11 = hkOstream::operator<<((hkOstream *)&v26.vfptr, "\nMemory:\n Faces ( ");
  v12 = hkOstream::operator<<(v11, (int)v2);
  v13 = hkOstream::operator<<(v12, " )\t:");
  v14 = hkOstream::operator<<(v13, v3);
  v15 = hkOstream::operator<<(v14, "\n Edges ( ");
  v16 = hkOstream::operator<<(v15, v9);
  v17 = hkOstream::operator<<(v16, " )\t:");
  v18 = hkOstream::operator<<(v17, v4);
  v19 = hkOstream::operator<<(v18, "\n Verts ( ");
  v20 = hkOstream::operator<<(v19, v8);
  v21 = hkOstream::operator<<(v20, " )\t:");
  v22 = hkOstream::operator<<(v21, v5);
  v23 = hkOstream::operator<<(v22, "\n UserData:");
  v24 = hkOstream::operator<<(v23, v10);
  v25 = hkOstream::operator<<(v24, "\n Total:");
  hkOstream::operator<<(v25, v3 + v4 + v10 + v5 + 176);
  hkError::messageReport(-1, &buf, "Debug\\hkaiNavMeshDebugUtils.cpp", 945);
  hkOstream::~hkOstream((hkOstream *)&v26.vfptr);
  ((void (*)(void))hkSingleton<hkError>::s_instance->vfptr[5].__vecDelDtor)();
}

// File Line: 950
// RVA: 0xC48300
unsigned __int64 __fastcall hkaiNavMeshDebugUtils::getMemoryUsed(hkaiNavMesh *mesh)
{
  return (unsigned int)(16 * mesh->m_faces.m_size)
       + (unsigned int)(16 * mesh->m_vertices.m_size)
       + (unsigned int)(4 * mesh->m_edges.m_size * mesh->m_edgeDataStriding)
       + (unsigned __int64)(unsigned int)(4 * mesh->m_faces.m_size * mesh->m_faceDataStriding)
       + (unsigned int)(20 * mesh->m_edges.m_size)
       + 176i64;
}

// File Line: 963
// RVA: 0xC492D0
void __fastcall hkaiNavMeshDebugUtils::_sortTransparentFaces(hkaiNavMeshInstance *nmi, hkaiNavMeshDebugUtils::DebugInfo *settings, hkArray<hkRadixSort::SortData32,hkContainerDebugAllocator> *sortArray, hkVector4f *a4)
{
  int v4; // eax
  int v5; // ebx
  hkArray<hkRadixSort::SortData32,hkContainerDebugAllocator> *v6; // rsi
  hkaiNavMeshDebugUtils::DebugInfo *v7; // r12
  hkaiNavMeshInstance *v8; // rdi
  int v9; // eax
  int v10; // er9
  int v11; // edx
  signed __int64 i; // rcx
  hkRadixSort::SortData32 *v13; // rax
  hkRadixSort::SortData32 *v14; // rbp
  int v15; // er14
  __int64 v16; // r15
  hkRadixSort::SortData32 *v17; // rdx
  __m128 v18; // xmm2
  int v19; // eax
  signed int v20; // edi
  int faceIndex[4]; // [rsp+30h] [rbp-38h]
  float v22; // [rsp+70h] [rbp+8h]

  v4 = sortArray->m_capacityAndFlags & 0x3FFFFFFF;
  v5 = (nmi->m_numOriginalFaces + nmi->m_ownedFaces.m_size + 3) & 0xFFFFFFFC;
  v6 = sortArray;
  v7 = settings;
  v8 = nmi;
  if ( v4 < v5 )
  {
    v9 = 2 * v4;
    v10 = (nmi->m_numOriginalFaces + nmi->m_ownedFaces.m_size + 3) & 0xFFFFFFFC;
    if ( v5 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(
      (hkResult *)&v22,
      (hkMemoryAllocator *)&hkContainerDebugAllocator::s_alloc.vfptr,
      sortArray,
      v10,
      8);
  }
  v6->m_size = v5;
  v11 = v8->m_ownedFaces.m_size + v8->m_numOriginalFaces;
  for ( i = v11; i < v5; ++v11 )
  {
    v13 = v6->m_data;
    *((_DWORD *)&v13[++i] - 1) = v11;
    v13[i - 1].m_key = 0x7FFFFFFF;
  }
  v14 = 0i64;
  v15 = 0;
  if ( v8->m_ownedFaces.m_size + v8->m_numOriginalFaces > 0 )
  {
    v16 = 0i64;
    do
    {
      hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
        (hkaiNavMeshUtils *)v8,
        (hkaiNavMeshInstance *)(unsigned int)v15,
        (__int64)faceIndex,
        a4);
      v17 = v6->m_data;
      ++v16;
      *(__m128 *)faceIndex = _mm_add_ps(*(__m128 *)faceIndex, v7->m_displayOffset.m_quad);
      *((_DWORD *)&v17[v16] - 1) = v15++;
      v18 = _mm_mul_ps(*(__m128 *)faceIndex, v7->m_sortDirection.m_quad);
      v22 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 0)))
          + COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 170));
      v17[v16 - 1].m_key = (LODWORD(v22) ^ ((SLODWORD(v22) >> 31) | 0x80000001)) >> 1;
    }
    while ( v15 < v8->m_ownedFaces.m_size + v8->m_numOriginalFaces );
  }
  v19 = v5;
  if ( v5 )
  {
    LODWORD(v22) = 8 * v5;
    v14 = (hkRadixSort::SortData32 *)hkContainerDebugAllocator::s_alloc.vfptr->bufAlloc(
                                       (hkMemoryAllocator *)&hkContainerDebugAllocator::s_alloc,
                                       (int *)&v22);
    v19 = SLODWORD(v22) / 8;
  }
  v20 = 2147483648;
  if ( v19 )
    v20 = v19;
  hkRadixSort::sort32(v6->m_data, v5, v14);
  if ( v20 >= 0 )
    hkContainerDebugAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerDebugAllocator::s_alloc,
      v14,
      8 * v20);
}

// File Line: 990
// RVA: 0xC494B0
void __fastcall hkaiNavMeshDebugUtils::_showFace(hkDebugDisplayHandler *displayHandler, int tag, hkaiNavMeshInstance *nmi, hkaiNavMeshDebugUtils::DebugInfo *settings, int faceIdx, unsigned int faceColor)
{
  int v6; // er15
  __int64 v7; // r14
  hkaiNavMeshInstance *v8; // rdi
  int v9; // er13
  hkDebugDisplayHandler *v10; // rsi
  hkaiNavMeshDebugUtils::DebugInfo *v11; // rbx
  hkaiNavMesh::Face *v12; // rax
  hkArray<int,hkContainerHeapAllocator> *v13; // r11
  int v14; // ecx
  int *v15; // r15
  int v16; // er12
  hkVector4f *v17; // r9
  bool v18; // zf
  __m128 v19; // xmm9
  unsigned int v20; // er9
  int v21; // er13
  __m128 v22; // xmm0
  const char *v23; // rdx
  int v24; // er8
  float v25; // xmm6_4
  hkVector4f *v26; // r9
  char v27; // r15
  __m128 v28; // xmm2
  __m128 v29; // xmm2
  __int64 v30; // r12
  __m128 v31; // xmm7
  __int64 v32; // rcx
  signed int v33; // eax
  hkVector4f *v34; // rax
  __m128 v35; // xmm1
  int v36; // eax
  unsigned int v37; // er15
  hkVector4f *v38; // r9
  int v39; // ST20_4
  float v40; // xmm0_4
  __m128 v41; // xmm1
  float v42; // xmm2_4
  hkAabb *instanceMap; // [rsp+20h] [rbp-A8h]
  __int64 index; // [rsp+28h] [rbp-A0h]
  __int64 indexa; // [rsp+28h] [rbp-A0h]
  __int64 striding; // [rsp+30h] [rbp-98h]
  hkVector4f *lightDir; // [rsp+38h] [rbp-90h]
  hkVector4f faceOffset; // [rsp+40h] [rbp-88h]
  int v49; // [rsp+50h] [rbp-78h]
  hkaiNavMesh::Face *v50; // [rsp+58h] [rbp-70h]
  hkVector4f end; // [rsp+60h] [rbp-68h]
  hkVector4f dir; // [rsp+70h] [rbp-58h]
  char v53; // [rsp+88h] [rbp-40h]
  char v54; // [rsp+8Ch] [rbp-3Ch]
  char v55; // [rsp+90h] [rbp-38h]
  hkSimdFloat32 extraRadius; // [rsp+98h] [rbp-30h]
  __m128 v57; // [rsp+A8h] [rbp-20h]
  hkStringBuf v58; // [rsp+B8h] [rbp-10h]
  hkStringBuf label; // [rsp+148h] [rbp+80h]
  int v60; // [rsp+280h] [rbp+1B8h]
  char v61; // [rsp+288h] [rbp+1C0h]
  char v62; // [rsp+290h] [rbp+1C8h]
  int v63; // [rsp+298h] [rbp+1D0h]
  unsigned int vars0; // [rsp+2A0h] [rbp+1D8h]

  v6 = nmi->m_numOriginalFaces;
  v7 = v63;
  v8 = nmi;
  v9 = tag;
  v10 = displayHandler;
  v11 = settings;
  v12 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__21(
          nmi->m_originalFaces,
          nmi->m_numOriginalFaces,
          &nmi->m_instancedFaces,
          &nmi->m_ownedFaces,
          &nmi->m_faceMap,
          v63);
  v14 = v8->m_faceDataStriding;
  v50 = v12;
  if ( v14 )
    v15 = hkaiNavMeshInstance_getWithStriding_int__4(
            v8->m_originalFaceData,
            v6,
            &v8->m_instancedFaceData,
            &v8->m_ownedFaceData,
            v13,
            v7,
            v14);
  else
    v15 = 0i64;
  if ( v8->m_faceFlags.m_size )
    v61 = v8->m_faceFlags.m_data[v7].m_storage;
  else
    v61 = 0;
  v16 = v61 & 1;
  hkaiNavMeshDebugUtils::_calcFaceOffset(v8, v11, v7, (hkVector4f *)((char *)&faceOffset + 8));
  v18 = v11->m_showNormals.m_bool == 0;
  v19 = *(__m128 *)((char *)&faceOffset + 8);
  dir.m_quad = 0i64;
  faceOffset.m_quad = 0i64;
  v62 = 0;
  v61 = 0;
  if ( !v18 )
  {
    hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
      (hkaiNavMeshUtils *)v8,
      (hkaiNavMeshInstance *)(unsigned int)v7,
      (__int64)&faceOffset,
      v17);
    v20 = v11->m_normalsColor;
    v61 = 1;
    faceOffset.m_quad = _mm_add_ps(faceOffset.m_quad, v19);
    if ( v10 )
      hkDebugDisplayHandler::displayArrow(v10, &faceOffset, &dir, v20, 0, v9);
    else
      hkDebugDisplay::displayArrow(
        hkSingleton<hkDebugDisplay>::s_instance,
        &faceOffset,
        &dir,
        v20,
        0,
        (int)hkDebugDisplayProcess::m_tag);
  }
  v21 = 1;
  v22 = _mm_cmpleps(v11->m_pruneLabelsAabb.m_max.m_quad, v11->m_pruneLabelsAabb.m_min.m_quad);
  if ( _mm_movemask_ps(v22) & 7
    || (*(hkVector4f *)((char *)&faceOffset + 8) = 0i64,
        hkaiNavMeshUtils::calcFaceAabb<hkaiNavMeshInstance>(
          (hkaiNavMeshUtils *)v8,
          (hkaiNavMeshInstance *)(unsigned int)v7,
          (__int64)&faceOffset.m_quad.m128_i64[1],
          &extraRadius,
          instanceMap),
        v22 = _mm_cmpleps(v11->m_pruneLabelsAabb.m_min.m_quad, v57),
        (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(extraRadius.m_real, v11->m_pruneLabelsAabb.m_max.m_quad), v22)) & 7) == 7) )
  {
    v18 = v11->m_labelFaces.m_bool == 0;
    v58.m_string.m_capacityAndFlags = -2147483520;
    v58.m_string.m_data = v58.m_string.m_storage;
    v58.m_string.m_size = 1;
    v58.m_string.m_storage[0] = 0;
    if ( !v18 )
    {
      v23 = "%d(%d)-H ";
      if ( !v16 )
        v23 = "%d(%d) ";
      hkStringBuf::printf(&v58, v23, (unsigned int)v7, (unsigned int)v50->m_numEdges);
    }
    if ( v11->m_showFaceData.m_bool )
    {
      if ( v15 )
      {
        v24 = v8->m_faceDataStriding;
        label.m_string.m_data = label.m_string.m_storage;
        label.m_string.m_capacityAndFlags = -2147483520;
        label.m_string.m_size = 1;
        label.m_string.m_storage[0] = 0;
        formatUserData(&label, v15, v24);
        hkStringBuf::operator+=(&v58, label.m_string.m_data);
        label.m_string.m_size = 0;
        if ( label.m_string.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            label.m_string.m_data,
            label.m_string.m_capacityAndFlags & 0x3FFFFFFF);
      }
    }
    if ( v58.m_string.m_size - 1 > 0 )
    {
      if ( !v61 )
      {
        hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
          (hkaiNavMeshUtils *)v8,
          (hkaiNavMeshInstance *)(unsigned int)v7,
          (__int64)&faceOffset,
          v17);
        v61 = 1;
        v22 = _mm_add_ps(faceOffset.m_quad, v19);
        faceOffset.m_quad = v22;
      }
      if ( v10 )
      {
        LODWORD(striding) = v60;
        LODWORD(index) = 0;
        LODWORD(instanceMap) = v11->m_faceLabelColor;
        v10->vfptr->display3dText(
          v10,
          (hkResult *)&v49,
          v58.m_string.m_data,
          &faceOffset,
          (unsigned int)instanceMap,
          index,
          striding);
      }
      else
      {
        hkDebugDisplay::display3dText(
          hkSingleton<hkDebugDisplay>::s_instance,
          v58.m_string.m_data,
          &faceOffset,
          v11->m_faceLabelColor,
          0,
          (int)hkDebugDisplayProcess::m_tag);
      }
    }
    v58.m_string.m_size = 0;
    if ( v58.m_string.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v58.m_string.m_data,
        v58.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  }
  v25 = FLOAT_N1_0;
  if ( v11->m_nonplanarFacesSettings.m_drawNonplanarity.m_bool )
  {
    hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
      (hkaiNavMeshUtils *)&faceOffset.m_quad.m128_u16[4],
      (hkSimdFloat32 *)v8,
      (hkaiNavMeshInstance *)(unsigned int)v7,
      (__int64)&dir);
    v27 = v61;
    v62 = 1;
    if ( !v61 )
    {
      hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
        (hkaiNavMeshUtils *)v8,
        (hkaiNavMeshInstance *)(unsigned int)v7,
        (__int64)&faceOffset,
        v26);
      v61 = 1;
      v27 = 1;
      v22 = _mm_add_ps(faceOffset.m_quad, v19);
      faceOffset.m_quad = v22;
    }
    v22.m128_f32[0] = hkaiNavMeshDebugUtils::_calcNonplanarity(v8, v7);
    v28 = v22;
    v25 = v22.m128_f32[0];
    v28.m128_f32[0] = v22.m128_f32[0] * v11->m_nonplanarFacesSettings.m_scaleMultiplier;
    end.m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v28, v28, 0), dir.m_quad), faceOffset.m_quad);
    if ( v10 )
    {
      LODWORD(striding) = v60;
      LODWORD(index) = 0;
      LODWORD(instanceMap) = hkColor::BLUE;
      v10->vfptr->displayLine(v10, (hkResult *)&v49, &faceOffset, &end, (unsigned int)instanceMap, index, striding);
    }
    else
    {
      hkDebugDisplay::displayLine(
        hkSingleton<hkDebugDisplay>::s_instance,
        &faceOffset,
        &end,
        hkColor::BLUE,
        0,
        (int)hkDebugDisplayProcess::m_tag);
    }
  }
  else
  {
    v27 = v61;
  }
  if ( v11->m_faceNormalSettings.m_drawFaceNormal.m_bool )
  {
    v29 = _mm_mul_ps(v11->m_faceNormalSettings.m_up.m_quad, dir.m_quad);
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 170))) < v11->m_faceNormalSettings.m_cosAngleThreshold )
    {
      if ( !v62 )
      {
        hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
          (hkaiNavMeshUtils *)&faceOffset.m_quad.m128_u16[4],
          (hkSimdFloat32 *)v8,
          (hkaiNavMeshInstance *)(unsigned int)v7,
          (__int64)&dir);
        v62 = 1;
      }
      if ( !v27 )
      {
        hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
          (hkaiNavMeshUtils *)v8,
          (hkaiNavMeshInstance *)(unsigned int)v7,
          (__int64)&faceOffset,
          v17);
        v61 = 1;
        faceOffset.m_quad = _mm_add_ps(faceOffset.m_quad, v19);
      }
      end.m_quad = _mm_add_ps(faceOffset.m_quad, dir.m_quad);
      if ( v10 )
      {
        LODWORD(striding) = v60;
        LODWORD(index) = 0;
        LODWORD(instanceMap) = hkColor::BLUE;
        v10->vfptr->displayLine(v10, (hkResult *)&v49, &faceOffset, &end, (unsigned int)instanceMap, index, striding);
      }
      else
      {
        hkDebugDisplay::displayLine(
          hkSingleton<hkDebugDisplay>::s_instance,
          &faceOffset,
          &end,
          hkColor::BLUE,
          0,
          (int)hkDebugDisplayProcess::m_tag);
      }
    }
  }
  if ( v11->m_showFaces.m_bool || v11->m_showHiddenFaces.m_bool && v16 )
  {
    v30 = (__int64)v50;
    v31 = _mm_add_ps(v11->m_faceOffset.m_quad, v19);
    v32 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__23(
            v8->m_originalEdges,
            v8->m_numOriginalEdges,
            &v8->m_instancedEdges,
            &v8->m_ownedEdges,
            &v8->m_edgeMap,
            v50->m_startEdgeIndex)->m_a;
    v33 = v8->m_numOriginalVertices;
    v34 = (signed int)v32 >= v33 ? &v8->m_ownedVertices.m_data[(signed int)v32 - v33] : &v8->m_originalVertices[v32];
    v35 = v34->m_quad;
    v36 = *(signed __int16 *)(v30 + 8) - 1;
    end.m_quad = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_shuffle_ps(v35, v35, 85),
                           v8->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad),
                         _mm_mul_ps(
                           _mm_shuffle_ps(v35, v35, 0),
                           v8->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad)),
                       _mm_mul_ps(
                         _mm_shuffle_ps(v35, v35, 170),
                         v8->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad)),
                     v8->m_referenceFrame.m_transform.m_translation.m_quad),
                   v31);
    if ( v36 > 1 )
    {
      do
      {
        v37 = vars0;
        hkaiNavMeshInstance::getEdgePoints(
          v8,
          v21 + *(_DWORD *)v30,
          (hkVector4f *)((char *)&end + 8),
          (hkVector4f *)((char *)&dir + 8));
        v18 = v11->m_showFanEdges.m_bool == 0;
        *(hkVector4f *)((char *)&end + 8) = (hkVector4f)_mm_add_ps(*(__m128 *)((char *)&end.m_quad + 8), v31);
        *(hkVector4f *)((char *)&dir + 8) = (hkVector4f)_mm_add_ps(*(__m128 *)((char *)&dir.m_quad + 8), v31);
        if ( !v18 && v21 != 1 )
        {
          if ( v10 )
          {
            v39 = v11->m_fanEdgeColor;
            ((void (__fastcall *)(hkDebugDisplayHandler *, char *, hkVector4f *, unsigned __int16 *))v10->vfptr->displayLine)(
              v10,
              &v53,
              &end,
              &end.m_quad.m128_u16[4]);
          }
          else
          {
            hkDebugDisplay::displayLine(
              hkSingleton<hkDebugDisplay>::s_instance,
              &end,
              (hkVector4f *)((char *)&end + 8),
              v11->m_fanEdgeColor,
              0,
              (int)hkDebugDisplayProcess::m_tag);
          }
        }
        if ( v11->m_nonplanarFacesSettings.m_highlightNonplanarFaces.m_bool )
        {
          if ( v25 == -1.0 )
            v25 = hkaiNavMeshDebugUtils::_calcNonplanarity(v8, v7);
          end.m_quad.m128_i32[0] = 0;
          v49 = 1065353216;
          *(float *)&v50 = v25 / v11->m_nonplanarFacesSettings.m_scaleMultiplier;
          v40 = 1.0 - fminf(fmaxf(*(float *)&v50, 0.0), 1.0);
          v37 = hkColor::rgbFromFloats(v40, v40, 1.0, 1.0);
        }
        else if ( v11->m_faceNormalSettings.m_highlightFaceNormals.m_bool )
        {
          v37 = hkColor::WHITE;
          if ( !v62 )
          {
            hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
              (hkaiNavMeshUtils *)&extraRadius,
              (hkSimdFloat32 *)v8,
              (hkaiNavMeshInstance *)(unsigned int)v7,
              (__int64)&dir);
            v62 = 1;
          }
          v41 = _mm_mul_ps(dir.m_quad, v11->m_faceNormalSettings.m_up.m_quad);
          v42 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v41, v41, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v41, v41, 0)))
              + COERCE_FLOAT(_mm_shuffle_ps(v41, v41, 170));
          if ( v42 < v11->m_faceNormalSettings.m_cosAngleThreshold )
            v37 = hkColor::BLUE;
          if ( v42 < v11->m_faceNormalSettings.m_cosAngleThreshold )
          {
            if ( !v61 )
            {
              hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
                (hkaiNavMeshUtils *)v8,
                (hkaiNavMeshInstance *)(unsigned int)v7,
                (__int64)&faceOffset,
                v38);
              v61 = 1;
              faceOffset.m_quad = _mm_add_ps(faceOffset.m_quad, v19);
            }
            *(hkVector4f *)((char *)&faceOffset + 8) = (hkVector4f)_mm_add_ps(
                                                                     _mm_mul_ps(
                                                                       _mm_shuffle_ps(
                                                                         (__m128)LODWORD(v11->m_faceNormalSettings.m_scaleMultiplier),
                                                                         (__m128)LODWORD(v11->m_faceNormalSettings.m_scaleMultiplier),
                                                                         0),
                                                                       v11->m_faceNormalSettings.m_up.m_quad),
                                                                     faceOffset.m_quad);
            if ( !v10 )
            {
              hkDebugDisplay::displayLine(
                hkSingleton<hkDebugDisplay>::s_instance,
                &faceOffset,
                (hkVector4f *)((char *)&faceOffset + 8),
                hkColor::BLUE,
                0,
                (int)hkDebugDisplayProcess::m_tag);
LABEL_75:
              hkDebugDisplay::displayTriangle(
                hkSingleton<hkDebugDisplay>::s_instance,
                &end,
                (hkVector4f *)((char *)&end + 8),
                (hkVector4f *)((char *)&dir + 8),
                v37,
                0,
                (int)hkDebugDisplayProcess::m_tag);
              v30 = (__int64)v50;
              goto LABEL_76;
            }
            ((void (__fastcall *)(hkDebugDisplayHandler *, char *, hkVector4f *, unsigned __int16 *))v10->vfptr->displayLine)(
              v10,
              &v54,
              &faceOffset,
              &faceOffset.m_quad.m128_u16[4]);
          }
          v30 = (__int64)v50;
        }
        else if ( v11->m_lightFaces.m_bool )
        {
          v37 = getLitColor(
                  (float)BYTE2(v37) * 0.0039215689,
                  (float)BYTE1(v37) * 0.0039215689,
                  (float)(unsigned __int8)v37 * 0.0039215689,
                  (float)(v37 >> 24) * 0.0039215689,
                  &end,
                  (hkVector4f *)((char *)&end + 8),
                  (hkVector4f *)((char *)&dir + 8),
                  &v11->m_lightDirection);
        }
        if ( !v10 )
          goto LABEL_75;
        LODWORD(lightDir) = v60;
        LODWORD(striding) = 0;
        LODWORD(indexa) = v37;
        v10->vfptr->displayTriangle(
          v10,
          (hkResult *)&v55,
          &end,
          (hkVector4f *)((char *)&end + 8),
          (hkVector4f *)((char *)&dir + 8),
          indexa,
          striding,
          (int)lightDir);
LABEL_76:
        ++v21;
      }
      while ( v21 < *(signed __int16 *)(v30 + 8) - 1 );
    }
  }
}

// File Line: 1137
// RVA: 0xC49EF0
void __fastcall hkaiNavMeshDebugUtils::_showEdgesForFace(hkDebugDisplayHandler *displayHandler, int tag, hkaiNavMeshInstance *nmi, hkaiNavMeshDebugUtils::DebugInfo *settings, int faceIdx, unsigned int faceColor)
{
  unsigned int v6; // er12
  hkaiNavMeshInstance *v7; // rdi
  int v8; // er13
  hkDebugDisplayHandler *v9; // r14
  hkaiNavMeshDebugUtils::DebugInfo *v10; // rbx
  hkaiNavMesh::Face *v11; // rsi
  int v12; // ecx
  hkArray<int,hkContainerHeapAllocator> *v13; // rdx
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v14; // r8
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v15; // r10
  __m128 v16; // xmm8
  int v17; // eax
  int v18; // esi
  hkVector4f *v19; // r9
  hkaiNavMesh::Edge *v20; // r15
  int v21; // eax
  __int64 v22; // rax
  signed int v23; // ecx
  __m128 *v24; // rax
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  __m128 v27; // xmm3
  __int64 v28; // rax
  __m128 v29; // xmm4
  __m128 v30; // xmm5
  __m128 v31; // xmm7
  __m128 *v32; // rax
  __m128 v33; // xmm6
  __m128 v34; // xmm0
  __m128 v35; // xmm1
  __m128 v36; // xmm2
  unsigned int v37; // esi
  unsigned int v38; // er8
  char v39; // dl
  bool v40; // r12
  hkaiNavMesh::Edge *v41; // rax
  bool v42; // al
  unsigned int v43; // edx
  __m128 v44; // xmm3
  __m128 v45; // xmm3
  __m128 v46; // xmm1
  __m128 v47; // xmm0
  unsigned int v48; // ecx
  unsigned int v49; // er9
  unsigned int v50; // er9
  float v51; // xmm2_4
  bool v52; // zf
  int v53; // er15
  int v54; // er8
  __m128 v55; // xmm1
  __m128 v56; // xmm1
  __m128 v57; // xmm4
  __m128 v58; // xmm1
  __m128 v59; // xmm0
  __int64 v60; // ST30_8
  __int64 v61; // ST28_8
  hkArray<int,hkContainerHeapAllocator> *v62; // ST20_8
  unsigned int v63; // er9
  unsigned int v64; // er9
  hkAabb *instanceMap; // [rsp+20h] [rbp-E0h]
  hkArray<int,hkContainerHeapAllocator> *instanceMapa; // [rsp+20h] [rbp-E0h]
  hkArray<int,hkContainerHeapAllocator> *instanceMapb; // [rsp+20h] [rbp-E0h]
  __int64 index; // [rsp+28h] [rbp-D8h]
  _QWORD striding[2]; // [rsp+30h] [rbp-D0h]
  char v70; // [rsp+40h] [rbp-C0h]
  int v71; // [rsp+44h] [rbp-BCh]
  int v72; // [rsp+48h] [rbp-B8h]
  hkVector4f start; // [rsp+50h] [rbp-B0h]
  BOOL v74; // [rsp+60h] [rbp-A0h]
  hkVector4f end; // [rsp+70h] [rbp-90h]
  int v76[4]; // [rsp+80h] [rbp-80h]
  int *dataPtr; // [rsp+90h] [rbp-70h]
  hkaiNavMesh::Face *v78; // [rsp+98h] [rbp-68h]
  hkVector4f faceNormal; // [rsp+A0h] [rbp-60h]
  int v80[4]; // [rsp+B0h] [rbp-50h]
  int faceIndex[4]; // [rsp+C0h] [rbp-40h]
  hkVector4f faceOffset; // [rsp+D0h] [rbp-30h]
  hkVector4f pos; // [rsp+E0h] [rbp-20h]
  char v84; // [rsp+F0h] [rbp-10h]
  char v85; // [rsp+F4h] [rbp-Ch]
  hkVector4f v86; // [rsp+100h] [rbp+0h]
  char v87; // [rsp+110h] [rbp+10h]
  char v88; // [rsp+114h] [rbp+14h]
  char v89; // [rsp+118h] [rbp+18h]
  char v90; // [rsp+11Ch] [rbp+1Ch]
  hkVector4f v91; // [rsp+120h] [rbp+20h]
  char buf; // [rsp+130h] [rbp+30h]
  hkVector4f v93; // [rsp+140h] [rbp+40h]
  hkVector4f v94; // [rsp+150h] [rbp+50h]
  hkVector4f v95; // [rsp+160h] [rbp+60h]
  hkVector4f edgeB; // [rsp+170h] [rbp+70h]
  hkVector4f edgeA; // [rsp+180h] [rbp+80h]
  hkSimdFloat32 extraRadius; // [rsp+190h] [rbp+90h]
  __m128 v99; // [rsp+1A0h] [rbp+A0h]
  hkStringBuf v100; // [rsp+1B0h] [rbp+B0h]
  hkStringBuf label; // [rsp+240h] [rbp+140h]
  char v102; // [rsp+2D0h] [rbp+1D0h]
  char v103; // [rsp+2E0h] [rbp+1E0h]
  char v104; // [rsp+3B0h] [rbp+2B0h]
  char v105; // [rsp+3B8h] [rbp+2B8h]

  v6 = faceIdx;
  v7 = nmi;
  v8 = tag;
  v9 = displayHandler;
  v10 = settings;
  v11 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__21(
          nmi->m_originalFaces,
          nmi->m_numOriginalFaces,
          &nmi->m_instancedFaces,
          &nmi->m_ownedFaces,
          &nmi->m_faceMap,
          faceIdx);
  v78 = v11;
  *(_OWORD *)v76 = 0i64;
  *(_OWORD *)v80 = 0i64;
  v104 = 0;
  v105 = 0;
  hkaiNavMeshDebugUtils::_calcFaceOffset(v7, v10, faceIdx, &faceOffset);
  v74 = 1;
  if ( (v10->m_labelVertices.m_bool || v10->m_labelEdges.m_bool || v10->m_showEdgeData.m_bool)
    && !(_mm_movemask_ps(_mm_cmpleps(v10->m_pruneLabelsAabb.m_max.m_quad, v10->m_pruneLabelsAabb.m_min.m_quad)) & 7) )
  {
    *(_OWORD *)faceIndex = 0i64;
    hkaiNavMeshUtils::calcFaceAabb<hkaiNavMeshInstance>(
      (hkaiNavMeshUtils *)v7,
      (hkaiNavMeshInstance *)(unsigned int)faceIdx,
      (__int64)faceIndex,
      &extraRadius,
      instanceMap);
    v74 = (_mm_movemask_ps(
             _mm_and_ps(
               _mm_cmpleps(extraRadius.m_real, v10->m_pruneLabelsAabb.m_max.m_quad),
               _mm_cmpleps(v10->m_pruneLabelsAabb.m_min.m_quad, v99))) & 7) == 7;
  }
  v12 = 0;
  v71 = 0;
  if ( v11->m_numEdges > 0 )
  {
    v13 = &v7->m_edgeMap;
    v14 = &v7->m_ownedEdges;
    v15 = &v7->m_instancedEdges;
    v16 = faceOffset.m_quad;
    do
    {
      v17 = v11->m_startEdgeIndex;
      v18 = v7->m_numOriginalEdges;
      faceNormal.m_quad = 0i64;
      v70 = 0;
      v72 = v12 + v17;
      v20 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__23(v7->m_originalEdges, v18, v15, v14, v13, v12 + v17);
      v21 = v7->m_edgeDataStriding;
      if ( v21 )
        dataPtr = hkaiNavMeshInstance_getWithStriding_int__4(
                    v7->m_originalEdgeData,
                    v18,
                    &v7->m_instancedEdgeData,
                    &v7->m_ownedEdgeData,
                    &v7->m_edgeMap,
                    v72,
                    v21);
      else
        dataPtr = 0i64;
      v22 = v20->m_a;
      v23 = v7->m_numOriginalVertices;
      if ( (signed int)v22 >= v23 )
        v24 = &v7->m_ownedVertices.m_data[(signed int)v22 - v23].m_quad;
      else
        v24 = &v7->m_originalVertices[v22].m_quad;
      v25 = *v24;
      v26 = v7->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad;
      v27 = v7->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad;
      v28 = v20->m_b;
      v29 = v7->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad;
      v30 = v7->m_referenceFrame.m_transform.m_translation.m_quad;
      v31 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), v27), _mm_mul_ps(_mm_shuffle_ps(v25, v25, 85), v26)),
                _mm_mul_ps(_mm_shuffle_ps(v25, v25, 170), v29)),
              v30);
      if ( (signed int)v28 >= v23 )
        v32 = &v7->m_ownedVertices.m_data[(signed int)v28 - v23].m_quad;
      else
        v32 = &v7->m_originalVertices[v28].m_quad;
      v33 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*v32, *v32, 0), v27),
                  _mm_mul_ps(_mm_shuffle_ps(*v32, *v32, 85), v26)),
                _mm_mul_ps(_mm_shuffle_ps(*v32, *v32, 170), v29)),
              v30);
      if ( v10->m_contractEdges.m_bool )
      {
        if ( !v105 )
        {
          hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
            (hkaiNavMeshUtils *)v7,
            (hkaiNavMeshInstance *)v6,
            (__int64)v80,
            v19);
          v105 = 1;
          *(__m128 *)v80 = _mm_add_ps(*(__m128 *)v80, v16);
        }
        v34 = _mm_shuffle_ps(
                (__m128)LODWORD(v10->m_edgeContractionRadius),
                (__m128)LODWORD(v10->m_edgeContractionRadius),
                0);
        v35 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)v80, v33), v34), v33);
        v36 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)v80, v31), v34), v31);
      }
      else
      {
        v36 = v31;
        v35 = v33;
      }
      v37 = v10->m_sharedEdgeColor;
      start.m_quad = _mm_add_ps(v36, v16);
      end.m_quad = _mm_add_ps(v35, v16);
      v38 = v20->m_oppositeEdge;
      if ( v38 == -1 )
      {
        v37 = v10->m_boundaryEdgeColor;
      }
      else if ( v20->m_flags.m_storage & 0x40 )
      {
        v37 = v10->m_externalEdgeColor;
      }
      v39 = v20->m_flags.m_storage;
      if ( v39 & 2 )
        v37 = ((((v37 ^ v10->m_faceColor) >> 1) & 0x7F7F7F) + (v10->m_faceColor & v37)) | 0xFF000000;
      v40 = v38 == -1 || v39 & 0x40;
      if ( v10->m_lightFaces.m_bool && !v40 )
        v37 = hkColor::rgbFromFloats(
                (float)((float)((float)BYTE2(faceColor) * 0.0039215689) + (float)((float)BYTE2(v37) * 0.0039215689))
              * 0.5,
                (float)((float)((float)BYTE1(faceColor) * 0.0039215689) + (float)((float)BYTE1(v37) * 0.0039215689))
              * 0.5,
                (float)((float)((float)(unsigned __int8)faceColor * 0.0039215689)
                      + (float)((float)(unsigned __int8)v37 * 0.0039215689))
              * 0.5,
                (float)(v37 >> 24) * 0.0039215689);
      if ( !v10->m_showEdges.m_bool )
        goto LABEL_50;
      if ( !v40 && faceIdx >= (signed int)(v20->m_oppositeFace & 0x3FFFFF) )
      {
        v42 = (v41 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__23(
                       v7->m_originalEdges,
                       v7->m_numOriginalEdges,
                       &v7->m_instancedEdges,
                       &v7->m_ownedEdges,
                       &v7->m_edgeMap,
                       v20->m_oppositeEdge & 0x3FFFFF),
               v20->m_a == v41->m_a)
           && v20->m_b == v41->m_b
           || v20->m_a == v41->m_b && v20->m_b == v41->m_a;
        if ( v42 )
          goto LABEL_50;
      }
      if ( v9 )
      {
        LODWORD(striding[0]) = v8;
        LODWORD(index) = 0;
        LODWORD(instanceMapa) = v37;
        v9->vfptr->displayLine(v9, (hkResult *)&v87, &start, &end, (unsigned int)instanceMapa, index, striding[0]);
      }
      else
      {
        hkDebugDisplay::displayLine(
          hkSingleton<hkDebugDisplay>::s_instance,
          &start,
          &end,
          v37,
          0,
          (int)hkDebugDisplayProcess::m_tag);
      }
      if ( v20->m_a == v20->m_b )
      {
        if ( v10->m_smallEdgeSettings.m_markDegenerateEdges.m_bool )
          goto LABEL_56;
      }
      else if ( v10->m_smallEdgeSettings.m_markSmallEdges.m_bool )
      {
        v44 = _mm_sub_ps(start.m_quad, end.m_quad);
        v45 = _mm_mul_ps(v44, v44);
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v45, v45, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v45, v45, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v45, v45, 170))) <= (float)(v10->m_smallEdgeSettings.m_smallEdgeTolerance
                                                                           * v10->m_smallEdgeSettings.m_smallEdgeTolerance) )
        {
LABEL_56:
          v46 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(end.m_quad, start.m_quad), (__m128)_xmm), start.m_quad);
          v47 = _mm_add_ps(v10->m_smallEdgeSettings.m_markerOffset.m_quad, v46);
          v93.m_quad = v46;
          v95.m_quad = v47;
          if ( v9 )
          {
            if ( v40 )
              v48 = v10->m_smallEdgeSettings.m_smallBoundaryEdgeColor;
            else
              v48 = v10->m_smallEdgeSettings.m_smallSharedEdgeColor;
            LODWORD(striding[0]) = v8;
            LODWORD(index) = 0;
            LODWORD(instanceMapa) = v48;
            v9->vfptr->displayLine(v9, (hkResult *)&v88, &v93, &v95, (unsigned int)instanceMapa, index, striding[0]);
          }
          else
          {
            if ( v40 )
              v49 = v10->m_smallEdgeSettings.m_smallBoundaryEdgeColor;
            else
              v49 = v10->m_smallEdgeSettings.m_smallSharedEdgeColor;
            hkDebugDisplay::displayLine(
              hkSingleton<hkDebugDisplay>::s_instance,
              &v93,
              &v95,
              v49,
              0,
              (int)hkDebugDisplayProcess::m_tag);
          }
          goto LABEL_50;
        }
      }
LABEL_50:
      if ( v10->m_showEdgeConnections.m_bool )
      {
        v43 = v20->m_oppositeEdge;
        if ( v43 != -1 )
        {
          v94.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(end.m_quad, start.m_quad), (__m128)_xmm), start.m_quad);
          hkaiNavMeshInstance::getEdgePoints(v7, v43 & 0x3FFFFF, &edgeA, &edgeB);
          v91.m_quad = _mm_add_ps(
                         _mm_add_ps(_mm_mul_ps(_mm_sub_ps(edgeA.m_quad, edgeB.m_quad), (__m128)_xmm), edgeB.m_quad),
                         v16);
          if ( v9 )
          {
            LODWORD(striding[0]) = v8;
            LODWORD(index) = 0;
            LODWORD(instanceMapa) = v10->m_edgeNormalColor;
            v9->vfptr->displayLine(v9, (hkResult *)&v89, &v94, &v91, (unsigned int)instanceMapa, index, striding[0]);
          }
          else
          {
            hkDebugDisplay::displayLine(
              hkSingleton<hkDebugDisplay>::s_instance,
              &v94,
              &v91,
              v10->m_edgeNormalColor,
              0,
              (int)hkDebugDisplayProcess::m_tag);
          }
        }
      }
      if ( v10->m_showVertices.m_bool )
      {
        v50 = v10->m_vertexLabelColor;
        v51 = v10->m_vertexDisplaySize;
        if ( v9 )
          hkDebugDisplayHandler::displayStar(v9, &start, v51, v50, 0, v8);
        else
          hkDebugDisplay::displayStar(
            hkSingleton<hkDebugDisplay>::s_instance,
            &start,
            v51,
            v50,
            0,
            (int)hkDebugDisplayProcess::m_tag);
      }
      if ( v74 )
      {
        v52 = v10->m_labelVertices.m_bool == 0;
        v100.m_string.m_capacityAndFlags = -2147483520;
        v100.m_string.m_data = v100.m_string.m_storage;
        v100.m_string.m_size = 1;
        v100.m_string.m_storage[0] = 0;
        if ( !v52 )
        {
          hkString::sprintf(&buf, "%d", (unsigned int)v20->m_a);
          if ( v9 )
          {
            LODWORD(striding[0]) = v8;
            LODWORD(index) = 0;
            LODWORD(instanceMapa) = v10->m_vertexLabelColor;
            v9->vfptr->display3dText(v9, (hkResult *)&v85, &buf, &start, (unsigned int)instanceMapa, index, striding[0]);
          }
          else
          {
            hkDebugDisplay::display3dText(
              hkSingleton<hkDebugDisplay>::s_instance,
              &buf,
              &start,
              v10->m_vertexLabelColor,
              0,
              (int)hkDebugDisplayProcess::m_tag);
          }
        }
        v53 = v71;
        if ( v10->m_labelEdges.m_bool )
          hkStringBuf::printf(&v100, "%d ", (unsigned int)(v71 + v78->m_startEdgeIndex));
        if ( v10->m_showEdgeData.m_bool )
        {
          if ( dataPtr )
          {
            v54 = v7->m_edgeDataStriding;
            label.m_string.m_data = label.m_string.m_storage;
            label.m_string.m_capacityAndFlags = -2147483520;
            label.m_string.m_size = 1;
            label.m_string.m_storage[0] = 0;
            formatUserData(&label, dataPtr, v54);
            hkStringBuf::operator+=(&v100, label.m_string.m_data);
            label.m_string.m_size = 0;
            if ( label.m_string.m_capacityAndFlags >= 0 )
              hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                label.m_string.m_data,
                label.m_string.m_capacityAndFlags & 0x3FFFFFFF);
          }
        }
        if ( v100.m_string.m_size - 1 > 0 )
        {
          v86.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(end.m_quad, start.m_quad), (__m128)_xmm), start.m_quad);
          if ( !v104 )
          {
            hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
              (hkaiNavMeshUtils *)&v103,
              (hkSimdFloat32 *)v7,
              (hkaiNavMeshInstance *)(unsigned int)faceIdx,
              (__int64)v76);
            v104 = 1;
          }
          hkaiNavMeshUtils::calcEdgePlane<hkaiNavMeshInstance>(
            (hkaiNavMeshUtils *)v7,
            (hkaiNavMeshInstance *)(unsigned int)faceIdx,
            v72,
            (__int64)v76,
            &faceNormal);
          v70 = 1;
          v55 = _mm_sub_ps(start.m_quad, end.m_quad);
          v56 = _mm_mul_ps(v55, v55);
          v57 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v56, v56, 85), _mm_shuffle_ps(v56, v56, 0)),
                  _mm_shuffle_ps(v56, v56, 170));
          v58 = _mm_rsqrt_ps(v57);
          v59 = _mm_mul_ps(*(__m128 *)_xmm, v58);
          v59.m128_f32[0] = COERCE_FLOAT(
                              _mm_andnot_ps(
                                _mm_cmpleps(v57, (__m128)0i64),
                                _mm_mul_ps(
                                  _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v58, v57), v58)), v59),
                                  v57)))
                          * -0.0099999998;
          pos.m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v59, v59, 0), faceNormal.m_quad), v86.m_quad);
          if ( v9 )
          {
            LODWORD(striding[0]) = v8;
            LODWORD(index) = 0;
            LODWORD(instanceMapb) = v10->m_edgeLabelColor;
            v9->vfptr->display3dText(
              v9,
              (hkResult *)&v90,
              v100.m_string.m_data,
              &pos,
              (unsigned int)instanceMapb,
              index,
              striding[0]);
            LODWORD(v60) = v8;
            LODWORD(v61) = 0;
            LODWORD(v62) = v10->m_edgeLabelColor;
            v9->vfptr->displayLine(v9, (hkResult *)&v84, &v86, &pos, (unsigned int)v62, v61, v60);
          }
          else
          {
            hkDebugDisplay::display3dText(
              hkSingleton<hkDebugDisplay>::s_instance,
              v100.m_string.m_data,
              &pos,
              v10->m_edgeLabelColor,
              0,
              (int)hkDebugDisplayProcess::m_tag);
            hkDebugDisplay::displayLine(
              hkSingleton<hkDebugDisplay>::s_instance,
              &v86,
              &pos,
              v10->m_edgeLabelColor,
              0,
              (int)hkDebugDisplayProcess::m_tag);
          }
        }
        v100.m_string.m_size = 0;
        if ( v100.m_string.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            v100.m_string.m_data,
            v100.m_string.m_capacityAndFlags & 0x3FFFFFFF);
      }
      else
      {
        v53 = v71;
      }
      if ( v10->m_showEdgeNormals.m_bool )
      {
        faceOffset.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(end.m_quad, start.m_quad), (__m128)_xmm), start.m_quad);
        if ( !v104 )
        {
          hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
            (hkaiNavMeshUtils *)&v102,
            (hkSimdFloat32 *)v7,
            (hkaiNavMeshInstance *)(unsigned int)faceIdx,
            (__int64)v76);
          v104 = 1;
        }
        if ( !v70 )
          hkaiNavMeshUtils::calcEdgePlane<hkaiNavMeshInstance>(
            (hkaiNavMeshUtils *)v7,
            (hkaiNavMeshInstance *)(unsigned int)faceIdx,
            v72,
            (__int64)v76,
            &faceNormal);
        v63 = v10->m_edgeNormalColor;
        if ( v9 )
          hkDebugDisplayHandler::displayArrow(v9, &faceOffset, &faceNormal, v63, 0, v8);
        else
          hkDebugDisplay::displayArrow(
            hkSingleton<hkDebugDisplay>::s_instance,
            &faceOffset,
            &faceNormal,
            v63,
            0,
            (int)hkDebugDisplayProcess::m_tag);
      }
      v6 = faceIdx;
      if ( v10->m_showVertexNormals.m_bool )
      {
        if ( !v104 )
        {
          hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
            (hkaiNavMeshUtils *)&extraRadius,
            (hkSimdFloat32 *)v7,
            (hkaiNavMeshInstance *)(unsigned int)faceIdx,
            (__int64)v76);
          v104 = 1;
        }
        hkaiNavMeshUtils::calcVertexPlane<hkaiNavMeshInstance>(
          (hkaiNavMeshUtils *)v7,
          (hkaiNavMeshInstance *)(unsigned int)faceIdx,
          v53,
          (__int64)v76,
          (hkVector4f *)faceIndex);
        v64 = v10->m_vertexNormalColor;
        if ( v9 )
          hkDebugDisplayHandler::displayArrow(v9, &start, (hkVector4f *)faceIndex, v64, 0, v8);
        else
          hkDebugDisplay::displayArrow(
            hkSingleton<hkDebugDisplay>::s_instance,
            &start,
            (hkVector4f *)faceIndex,
            v64,
            0,
            (int)hkDebugDisplayProcess::m_tag);
      }
      v11 = v78;
      v13 = &v7->m_edgeMap;
      v12 = v71 + 1;
      v14 = &v7->m_ownedEdges;
      v71 = v12;
      v15 = &v7->m_instancedEdges;
    }
    while ( v12 < v78->m_numEdges );
  }
}

// File Line: 1348
// RVA: 0xC4AB50
void __fastcall hkaiNavMeshDebugUtils::_showUserEdgesForFace(hkDebugDisplayHandler *displayHandler, int tag, hkaiStreamingCollection *collection, hkaiNavMeshInstance *nmi, hkaiNavMeshDebugUtils::DebugInfo *settings, int faceIdx)
{
  hkaiNavMeshInstance *v6; // rsi
  int v7; // er12
  hkDebugDisplayHandler *v8; // r13
  hkaiStreamingCollection *v9; // r15
  hkaiNavMesh::Face *v10; // rdi
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  signed __int64 v14; // rcx
  unsigned __int64 v15; // rbx
  _QWORD *v16; // rax
  _QWORD *v17; // rcx
  _QWORD *v18; // r8
  unsigned __int64 v19; // rax
  signed __int64 v20; // rcx

  v6 = nmi;
  v7 = tag;
  v8 = displayHandler;
  v9 = collection;
  v10 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__21(
          nmi->m_originalFaces,
          nmi->m_numOriginalFaces,
          &nmi->m_instancedFaces,
          &nmi->m_ownedFaces,
          &nmi->m_faceMap,
          faceIdx);
  if ( v10->m_numUserEdges )
  {
    v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v12 = (_QWORD *)v11[1];
    if ( (unsigned __int64)v12 < v11[3] )
    {
      *v12 = "TtuserEdges";
      v13 = __rdtsc();
      v14 = (signed __int64)(v12 + 2);
      *(_DWORD *)(v14 - 8) = v13;
      v11[1] = v14;
    }
    v15 = (unsigned int)v10->m_startUserEdgeIndex;
    if ( (signed int)v15 < (signed int)v15 + v10->m_numUserEdges )
    {
      do
      {
        hkaiNavMeshDebugUtils::_showUserEdgePair(
          v9,
          settings,
          faceIdx | (v6->m_runtimeId << 22),
          v15 | (v6->m_runtimeId << 22),
          (hkDebugDisplayHandler *)v15,
          v8,
          v7);
        v15 = (unsigned int)(v15 + 1);
      }
      while ( (signed int)v15 < v10->m_startUserEdgeIndex + v10->m_numUserEdges );
    }
    v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v17 = (_QWORD *)v16[1];
    v18 = v16;
    if ( (unsigned __int64)v17 < v16[3] )
    {
      *v17 = "Et";
      v19 = __rdtsc();
      v20 = (signed __int64)(v17 + 2);
      *(_DWORD *)(v20 - 8) = v19;
      v18[1] = v20;
    }
  }
}

// File Line: 1367
// RVA: 0xC4ACA0
void __fastcall hkaiNavMeshDebugUtils::_calcFaceOffset(hkaiNavMeshInstance *nmi, hkaiNavMeshDebugUtils::DebugInfo *settings, int faceIdx, hkVector4f *faceOffset)
{
  hkVector4f v4; // xmm1
  char v5; // [rsp+8h] [rbp+8h]

  if ( nmi->m_faceFlags.m_size )
    v5 = nmi->m_faceFlags.m_data[faceIdx].m_storage;
  else
    v5 = 0;
  v4.m_quad = (__m128)settings->m_displayOffset;
  *faceOffset = settings->m_displayOffset;
  if ( v5 & 1 )
  {
    if ( settings->m_showHiddenFaces.m_bool )
      faceOffset->m_quad = _mm_add_ps(settings->m_hiddenFaceOffset.m_quad, v4.m_quad);
  }
}

// File Line: 1381
// RVA: 0xC4ACF0
__int64 __fastcall hkaiNavMeshDebugUtils::_getUnlitFaceColor(hkaiNavMeshInstance *nmi, hkaiNavMeshDebugUtils::DebugInfo *settings, hkArrayBase<int> *regions, int faceIdx)
{
  __int64 index; // rdi
  hkaiNavMeshDebugUtils::DebugInfo *v5; // rbx
  hkArray<int,hkContainerHeapAllocator> *instanceMap; // rbp
  hkArrayBase<int> *v7; // r15
  hkaiNavMesh::Face *v8; // rax
  hkArray<int,hkContainerHeapAllocator> *v9; // r11
  int striding; // ecx
  int v11; // esi
  hkaiNavMesh::Face *v12; // r13
  int *v13; // r8
  int v14; // edx
  float v15; // xmm6_4
  unsigned int v16; // ecx
  unsigned __int64 v17; // r8
  int v18; // ecx
  float v19; // xmm0_4
  __int16 v20; // ax
  char v22; // [rsp+70h] [rbp+8h]

  index = faceIdx;
  v5 = settings;
  instanceMap = &nmi->m_faceMap;
  v7 = regions;
  v8 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__21(
         nmi->m_originalFaces,
         nmi->m_numOriginalFaces,
         &nmi->m_instancedFaces,
         &nmi->m_ownedFaces,
         &nmi->m_faceMap,
         faceIdx);
  striding = v9[4].m_size;
  v11 = 0;
  v12 = v8;
  if ( striding )
    v13 = hkaiNavMeshInstance_getWithStriding_int__4(
            v9[4].m_data,
            v9[1].m_size,
            v9 + 22,
            v9 + 24,
            instanceMap,
            index,
            striding);
  else
    v13 = 0i64;
  if ( v9[20].m_size )
    v22 = *((_BYTE *)v9[20].m_data + index);
  else
    v22 = 0;
  v14 = v5->m_highlightSingleRegionIndex;
  v15 = *(float *)&FLOAT_1_0;
  if ( v14 == -1 || v7->m_data[index] != v14 )
  {
    if ( v5->m_colorRegions.m_bool )
    {
      v17 = v7->m_data[index];
      v16 = regionColors[v17 - 12 * ((unsigned __int64)(v17 * (unsigned __int128)0xAAAAAAAAAAAAAAABui64 >> 64) >> 3)];
    }
    else
    {
      v18 = v5->m_numMaterialColors;
      if ( v18 <= 0 )
      {
        v16 = v5->m_faceColor;
      }
      else
      {
        if ( v13 )
          v11 = *v13;
        v16 = v5->m_materialColors[v11 % v18];
      }
    }
    if ( v5->m_allowFaceTransparency.m_bool )
    {
      v19 = v5->m_lightFaces.m_bool ? FLOAT_0_80000001 : FLOAT_0_25;
      v15 = (float)((float)(v16 >> 24) * 0.0039215689) * v19;
      if ( v22 & 1 )
        v15 = v15 * 0.25;
    }
    if ( v5->m_showClusters.m_bool )
    {
      v20 = v12->m_clusterIndex;
      if ( v20 >= 0 )
        v16 = perturbColor(v16, v20, 0.30000001);
    }
  }
  else
  {
    v16 = hkColor::rgbFromChars(255, 100, 0, 255);
    if ( v5->m_allowFaceTransparency.m_bool )
      v15 = FLOAT_0_627451;
  }
  return v16 & 0xFFFFFF | ((unsigned __int8)(signed int)(float)(v15 * 255.0) << 24);
}

// File Line: 1438
// RVA: 0xC4AF00
void __fastcall hkaiNavMeshDebugUtils::dumpMeshToZir(hkaiNavMesh *navMesh, hkVector4f *up, const char *filename)
{
  hkaiNavMesh *v3; // rbx
  const char *v4; // rdi
  hkVector4f *v5; // rsi
  hkaiNavMeshInstance navMeshInstance; // [rsp+20h] [rbp-1E8h]

  v3 = navMesh;
  v4 = filename;
  v5 = up;
  hkaiNavMeshInstance::hkaiNavMeshInstance(&navMeshInstance);
  hkaiNavMeshInstance::tempInit(&navMeshInstance, v3, 0);
  hkaiNavMeshDebugUtils::dumpMeshToZir(&navMeshInstance, v5, v4);
  hkaiNavMeshInstance::~hkaiNavMeshInstance(&navMeshInstance);
}

// File Line: 1445
// RVA: 0xC4AF70
void __fastcall hkaiNavMeshDebugUtils::dumpMeshToZir(hkaiNavMeshInstance *navMeshInstance, hkVector4f *up, const char *filename)
{
  const char *v3; // rbx
  hkaiNavMeshInstance *v4; // r13
  int v5; // ebx
  int v6; // er9
  int v7; // edi
  __int64 v8; // rsi
  __int64 v9; // r14
  int v10; // ecx
  __m128 *v11; // rax
  __m128 v12; // xmm1
  _DWORD *v13; // rbx
  int v14; // ebx
  __int64 v15; // rcx
  __int64 v16; // rax
  hkArray<int,hkContainerHeapAllocator> *v17; // rdx
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v18; // r8
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v19; // r10
  bool v20; // zf
  int v21; // er14
  hkResult *v22; // rax
  bool v23; // r12
  hkaiNavMesh::Face *v24; // rax
  hkaiNavMesh::Face *v25; // rsi
  int v26; // ebx
  hkaiNavMesh::Edge *v27; // rax
  char v28; // cl
  hkaiNavMesh::Edge *v29; // r8
  int v30; // eax
  int v31; // edi
  int v32; // er15
  int v33; // edx
  int v34; // ebx
  hkaiZirWriter::SegmentStyle segmentStyle; // [rsp+30h] [rbp-C0h]
  hkArrayBase<int> points; // [rsp+40h] [rbp-B0h]
  _DWORD *array; // [rsp+50h] [rbp-A0h]
  int v38; // [rsp+58h] [rbp-98h]
  int v39; // [rsp+5Ch] [rbp-94h]
  int v40; // [rsp+60h] [rbp-90h]
  const char *v41; // [rsp+68h] [rbp-88h]
  int v42; // [rsp+70h] [rbp-80h]
  __int64 v43; // [rsp+78h] [rbp-78h]
  int v44; // [rsp+80h] [rbp-70h]
  __int64 v45; // [rsp+88h] [rbp-68h]
  int v46; // [rsp+90h] [rbp-60h]
  __int64 v47; // [rsp+98h] [rbp-58h]
  hkaiZirWriter::NamePattern namePattern; // [rsp+A0h] [rbp-50h]
  hkaiZirWriter::NamePattern v49; // [rsp+B8h] [rbp-38h]
  hkaiZirWriter::Window window; // [rsp+D0h] [rbp-20h]
  hkaiZirWriter::PointStyle pointStyle; // [rsp+E0h] [rbp-10h]
  __int64 v52; // [rsp+F0h] [rbp+0h]
  hkAabb aabbOut; // [rsp+100h] [rbp+10h]
  hkaiZirWriter v54; // [rsp+120h] [rbp+30h]
  hkResult result; // [rsp+1A0h] [rbp+B0h]
  __int64 v56; // [rsp+1B8h] [rbp+C8h]

  v3 = filename;
  v4 = navMeshInstance;
  hkaiNavMeshInstance::getAabb(navMeshInstance, &aabbOut);
  *(_QWORD *)&window.m_minX = aabbOut.m_min.m_quad.m128_u64[0];
  *(_QWORD *)&window.m_maxX = aabbOut.m_max.m_quad.m128_u64[0];
  hkaiZirWriter::hkaiZirWriter(&v54, v3, &window);
  v5 = v4->m_numOriginalVertices + v4->m_ownedVertices.m_size;
  array = 0i64;
  v38 = 0;
  v39 = 2147483648;
  if ( v5 > 0 )
  {
    v6 = v5;
    if ( v5 < 0 )
      v6 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v6, 4);
  }
  v38 = v5;
  pointStyle.m_color = 0;
  *(_QWORD *)&pointStyle.m_shape = 1i64;
  pointStyle.m_hidden = 0;
  v7 = 0;
  v8 = 0i64;
  v9 = v5;
  if ( v5 > 0 )
  {
    do
    {
      v10 = v4->m_numOriginalVertices;
      if ( v7 >= v10 )
        v11 = &v4->m_ownedVertices.m_data[v7 - v10].m_quad;
      else
        v11 = &v4->m_originalVertices[v7].m_quad;
      v12 = *v11;
      v13 = array;
      namePattern.m_prefix = "v";
      namePattern.m_index = v7;
      namePattern.m_suffix = &customWorldMapCaption;
      ++v8;
      ++v7;
      v13[v8 - 1] = hkaiZirWriter::addPoint(
                      &v54,
                      v12.m128_f32[0],
                      COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 85)),
                      &pointStyle,
                      &namePattern,
                      "Vertex");
    }
    while ( v8 < v9 );
  }
  v14 = 0;
  v15 = 0i64;
  v16 = v4->m_numOriginalFaces + v4->m_ownedFaces.m_size;
  v45 = 2i64;
  LOWORD(v46) = 1;
  v43 = 4i64;
  LOWORD(v44) = 1;
  v41 = (const char *)3;
  LOWORD(v42) = 1;
  BYTE2(v42) = 0;
  points.m_data = 0i64;
  points.m_capacityAndFlags = 2147483648;
  v40 = 0;
  v47 = 0i64;
  v52 = v16;
  if ( v16 > 0 )
  {
    v17 = &v4->m_faceMap;
    v18 = &v4->m_ownedFaces;
    v19 = &v4->m_instancedFaces;
    while ( 1 )
    {
      v20 = v4->m_faceFlags.m_size == 0;
      v21 = 0;
      points.m_size = 0;
      if ( v20 )
      {
        LOBYTE(v56) = 0;
        v22 = (hkResult *)&v56;
      }
      else
      {
        v22 = &result;
        LOBYTE(result.m_enum) = v4->m_faceFlags.m_data[v15].m_storage;
      }
      v23 = v22->m_enum & 1;
      v24 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__21(
              v4->m_originalFaces,
              v4->m_numOriginalFaces,
              v19,
              v18,
              v17,
              v14);
      v25 = v24;
      v26 = v24->m_numUserEdges <= 0 ? v24->m_startEdgeIndex : v24->m_startUserEdgeIndex;
      if ( v26 != -1 )
        break;
LABEL_38:
      v34 = v40;
      namePattern.m_prefix = v41;
      namePattern.m_index = v42;
      v49.m_prefix = "f";
      v49.m_suffix = &customWorldMapCaption;
      BYTE2(namePattern.m_index) = v23;
      v49.m_index = v40;
      hkaiZirWriter::addPolygon(&v54, &points, (hkaiZirWriter::PolygonStyle *)&namePattern, &v49, "Polygon");
      v14 = v34 + 1;
      v17 = &v4->m_faceMap;
      v15 = v47 + 1;
      v40 = v14;
      v18 = &v4->m_ownedFaces;
      v47 = v15;
      v19 = &v4->m_instancedFaces;
      if ( v15 >= v52 )
        goto LABEL_39;
    }
    while ( 1 )
    {
      v27 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__23(
              v4->m_originalEdges,
              v4->m_numOriginalEdges,
              &v4->m_instancedEdges,
              &v4->m_ownedEdges,
              &v4->m_edgeMap,
              v26);
      *(_QWORD *)&segmentStyle.m_color = 0i64;
      *(_WORD *)&segmentStyle.m_arrow = 0;
      v28 = v27->m_flags.m_storage;
      v29 = v27;
      if ( v28 & 0x10 )
      {
        *(_QWORD *)&segmentStyle.m_color = v43;
        v30 = v44;
      }
      else if ( v27->m_oppositeEdge == -1 || v28 & 0x20 )
      {
        *(_QWORD *)&segmentStyle.m_color = v43;
        v30 = v42;
      }
      else
      {
        *(_QWORD *)&segmentStyle.m_color = v45;
        v30 = v46;
      }
      *(_DWORD *)&segmentStyle.m_arrow = v30;
      segmentStyle.m_hidden = v23;
      v31 = array[v29->m_a];
      v32 = array[v29->m_b];
      if ( !(v29->m_flags.m_storage & 0x10) )
      {
        if ( v21 == (points.m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &points, 4);
          v21 = points.m_size;
        }
        points.m_data[v21] = v31;
        ++points.m_size;
      }
      v49.m_prefix = "e";
      v49.m_suffix = &customWorldMapCaption;
      v49.m_index = v26;
      hkaiZirWriter::addSegment(&v54, v31, v32, &segmentStyle, &v49, 0i64);
      v33 = v25->m_startUserEdgeIndex;
      if ( v26 < v33 || v26 >= v25->m_numUserEdges + v33 - 1 )
      {
        if ( v26 == v25->m_numUserEdges + v33 - 1 )
        {
          v26 = v25->m_startEdgeIndex;
          goto LABEL_36;
        }
        if ( v26 < v25->m_startEdgeIndex || v26 >= v25->m_numEdges + v25->m_startEdgeIndex - 1 )
          goto LABEL_38;
      }
      ++v26;
LABEL_36:
      if ( v26 == -1 )
        goto LABEL_38;
      v21 = points.m_size;
    }
  }
LABEL_39:
  points.m_size = 0;
  if ( points.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      points.m_data,
      4 * points.m_capacityAndFlags);
  points.m_data = 0i64;
  points.m_capacityAndFlags = 2147483648;
  v38 = 0;
  if ( v39 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      4 * v39);
  array = 0i64;
  v39 = 2147483648;
  hkaiZirWriter::~hkaiZirWriter(&v54);
}

