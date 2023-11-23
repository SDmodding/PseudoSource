// File Line: 76
// RVA: 0xC464D0
void __fastcall hkaiNavMeshDebugUtils::SmallEdgeSettings::SmallEdgeSettings(
        hkaiNavMeshDebugUtils::SmallEdgeSettings *this)
{
  *(_WORD *)&this->m_markSmallEdges.m_bool = 0;
  this->m_smallBoundaryEdgeColor = hkColor::YELLOW;
  this->m_smallEdgeTolerance = 0.02;
  this->m_markerOffset.m_quad = _xmm;
  this->m_smallSharedEdgeColor = hkColor::ORANGE;
}

// File Line: 84
// RVA: 0xC46510
void __fastcall hkaiNavMeshDebugUtils::NonplanarFacesSettings::NonplanarFacesSettings(
        hkaiNavMeshDebugUtils::NonplanarFacesSettings *this)
{
  *(_WORD *)&this->m_highlightNonplanarFaces.m_bool = 0;
  this->m_scaleMultiplier = 1.0;
}

// File Line: 93
// RVA: 0xC46530
void __fastcall hkaiNavMeshDebugUtils::FaceNormalSettings::FaceNormalSettings(
        hkaiNavMeshDebugUtils::FaceNormalSettings *this)
{
  *(_WORD *)&this->m_highlightFaceNormals.m_bool = 0;
  this->m_up.m_quad = _xmm;
  *(_QWORD *)&this->m_scaleMultiplier = 1120403456i64;
}

// File Line: 142
// RVA: 0xC46560
void __fastcall hkaiNavMeshDebugUtils::DebugInfo::DebugInfo(hkaiNavMeshDebugUtils::DebugInfo *this)
{
  hkaiNavMeshDebugUtils::SmallEdgeSettings *p_m_smallEdgeSettings; // rcx
  __m128 v3; // xmm1
  __m128 v4; // xmm3
  __m128 v5; // xmm2

  *(_DWORD *)&this->m_allowFaceTransparency.m_bool = 65793;
  *(_QWORD *)&this->m_showUserEdges.m_bool = 1i64;
  *(_WORD *)&this->m_showEdgeConnections.m_bool = 0;
  p_m_smallEdgeSettings = &this->m_smallEdgeSettings;
  p_m_smallEdgeSettings[-7].m_markerOffset.m_quad.m128_u64[0] = 0i64;
  p_m_smallEdgeSettings[-7].m_markerOffset.m_quad.m128_i32[2] = 0;
  *(_QWORD *)&p_m_smallEdgeSettings[-6].m_markSmallEdges.m_bool = 0i64;
  p_m_smallEdgeSettings[-6].m_smallSharedEdgeColor = 0;
  LOBYTE(p_m_smallEdgeSettings[-6].m_smallEdgeTolerance) = 0;
  p_m_smallEdgeSettings[-6].m_markerOffset.m_quad.m128_i32[0] = hkColor::ORANGE;
  p_m_smallEdgeSettings[-6].m_markerOffset.m_quad.m128_i32[1] = hkColor::RED;
  p_m_smallEdgeSettings[-6].m_markerOffset.m_quad.m128_i32[2] = hkColor::BLUE;
  p_m_smallEdgeSettings[-6].m_markerOffset.m_quad.m128_i32[3] = hkColor::CYAN;
  *(_DWORD *)&p_m_smallEdgeSettings[-5].m_markSmallEdges.m_bool = hkColor::CYAN;
  p_m_smallEdgeSettings[-5].m_smallBoundaryEdgeColor = hkColor::LIGHTBLUE;
  p_m_smallEdgeSettings[-5].m_smallSharedEdgeColor = hkColor::BLACK;
  LODWORD(p_m_smallEdgeSettings[-5].m_smallEdgeTolerance) = hkColor::BLACK;
  p_m_smallEdgeSettings[-5].m_markerOffset.m_quad.m128_i32[0] = hkColor::PURPLE;
  p_m_smallEdgeSettings[-5].m_markerOffset.m_quad.m128_i32[1] = hkColor::BLUE;
  p_m_smallEdgeSettings[-5].m_markerOffset.m_quad.m128_i32[2] = hkColor::PURPLE;
  p_m_smallEdgeSettings[-5].m_markerOffset.m_quad.m128_i32[3] = hkColor::BLUE;
  p_m_smallEdgeSettings[-4].m_markSmallEdges.m_bool = 0;
  p_m_smallEdgeSettings[-4].m_smallBoundaryEdgeColor = 0;
  p_m_smallEdgeSettings[-4].m_smallSharedEdgeColor = 1028443341;
  *(_QWORD *)&p_m_smallEdgeSettings[-4].m_smallEdgeTolerance = -1i64;
  p_m_smallEdgeSettings[-4].m_markerOffset.m_quad.m128_i8[4] = 0;
  p_m_smallEdgeSettings[-3].m_markerOffset.m_quad.m128_i8[0] = 0;
  hkaiNavMeshDebugUtils::SmallEdgeSettings::SmallEdgeSettings(p_m_smallEdgeSettings);
  hkaiNavMeshDebugUtils::NonplanarFacesSettings::NonplanarFacesSettings(&this->m_nonplanarFacesSettings);
  hkaiNavMeshDebugUtils::FaceNormalSettings::FaceNormalSettings(&this->m_faceNormalSettings);
  hkaiGraphDebugUtils::DebugInfo::DebugInfo(&this->m_clusterGraphSettings);
  this->m_instanceEnabled.m_storage.m_words.m_data = 0i64;
  this->m_instanceEnabled.m_storage.m_words.m_size = 0;
  this->m_instanceEnabled.m_storage.m_words.m_capacityAndFlags = 0x80000000;
  this->m_instanceEnabled.m_storage.m_numBits = 0;
  this->m_displayOffset = (hkVector4f)_xmm;
  this->m_hiddenFaceOffset = 0i64;
  this->m_sortDirection = 0i64;
  this->m_lightDirection.m_quad = g_vectorfConstants[0];
  v3 = _mm_mul_ps(g_vectorfConstants[0], g_vectorfConstants[0]);
  v4 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v3, v3, 85), _mm_shuffle_ps(v3, v3, 0)), _mm_shuffle_ps(v3, v3, 170));
  v5 = _mm_rsqrt_ps(v4);
  this->m_faceOffset = 0i64;
  this->m_lightDirection.m_quad = _mm_mul_ps(
                                    _mm_andnot_ps(
                                      _mm_cmple_ps(v4, (__m128)0i64),
                                      _mm_mul_ps(
                                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v5, v4), v5)),
                                        _mm_mul_ps(*(__m128 *)_xmm, v5))),
                                    g_vectorfConstants[0]);
  this->m_pruneLabelsAabb.m_min = (hkVector4f)xmmword_141A712A0;
  this->m_pruneLabelsAabb.m_max.m_quad = _mm_xor_ps(
                                           (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                           this->m_pruneLabelsAabb.m_min.m_quad);
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
      || this->m_labelVertices.m_bool
      || this->m_labelEdges.m_bool
      || this->m_showEdgeData.m_bool
      || this->m_showEdgeNormals.m_bool
      || this->m_showVertexNormals.m_bool;
}

// File Line: 177
// RVA: 0xC46800
_BOOL8 __fastcall hkaiNavMeshDebugUtils::DebugInfo::shouldDrawUserEdges(hkaiNavMeshDebugUtils::DebugInfo *this)
{
  return this->m_showUserEdges.m_bool != 0;
}

// File Line: 241
// RVA: 0xC47150
void __fastcall hkaiNavMeshDebugUtils::highlightNavMeshEdges(
        hkaiNavMeshInstance *mesh,
        hkArrayBase<unsigned int> *edgesVisited,
        unsigned int highlightColor,
        hkVector4f *offset)
{
  int v4; // r12d
  hkArray<int,hkContainerHeapAllocator> *instanceMap; // rbp
  __int64 v9; // rsi
  hkaiNavMesh::Edge *v10; // rax
  int m_numOriginalVertices; // edx
  __int64 m_a; // rcx
  hkVector4f *v13; // rcx
  hkVector4f v14; // xmm4
  hkVector4f v15; // xmm5
  __int64 m_b; // rax
  hkVector4f v17; // xmm6
  hkVector4f v18; // xmm7
  __m128 v19; // xmm2
  hkVector4f *v20; // rax
  __m128 m_quad; // xmm1
  hkVector4f end; // [rsp+30h] [rbp-68h] BYREF
  hkVector4f start; // [rsp+40h] [rbp-58h] BYREF

  v4 = 0;
  if ( edgesVisited->m_size > 0 )
  {
    instanceMap = &mesh->m_edgeMap;
    v9 = 0i64;
    do
    {
      v10 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__23(
              mesh->m_originalEdges,
              mesh->m_numOriginalEdges,
              &mesh->m_instancedEdges,
              &mesh->m_ownedEdges,
              instanceMap,
              edgesVisited->m_data[v9]);
      m_numOriginalVertices = mesh->m_numOriginalVertices;
      m_a = v10->m_a;
      if ( (int)m_a >= m_numOriginalVertices )
        v13 = &mesh->m_ownedVertices.m_data[(int)m_a - m_numOriginalVertices];
      else
        v13 = &mesh->m_originalVertices[m_a];
      v14.m_quad = (__m128)mesh->m_referenceFrame.m_transform.m_rotation.m_col1;
      v15.m_quad = (__m128)mesh->m_referenceFrame.m_transform.m_rotation.m_col0;
      m_b = v10->m_b;
      v17.m_quad = (__m128)mesh->m_referenceFrame.m_transform.m_rotation.m_col2;
      v18.m_quad = (__m128)mesh->m_referenceFrame.m_transform.m_translation;
      v19 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v13->m_quad, v13->m_quad, 0), v15.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v13->m_quad, v13->m_quad, 85), v14.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v13->m_quad, v13->m_quad, 170), v17.m_quad)),
              v18.m_quad);
      if ( (int)m_b >= m_numOriginalVertices )
        v20 = &mesh->m_ownedVertices.m_data[(int)m_b - m_numOriginalVertices];
      else
        v20 = &mesh->m_originalVertices[m_b];
      m_quad = v20->m_quad;
      start.m_quad = _mm_add_ps(offset->m_quad, v19);
      end.m_quad = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), v15.m_quad),
                           _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), v14.m_quad)),
                         _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), v17.m_quad)),
                       v18.m_quad),
                     offset->m_quad);
      hkDebugDisplay::displayLine(
        hkSingleton<hkDebugDisplay>::s_instance,
        &start,
        &end,
        highlightColor,
        0,
        (int)hkDebugDisplayProcess::m_tag);
      ++v4;
      ++v9;
    }
    while ( v4 < edgesVisited->m_size );
  }
}

// File Line: 255
// RVA: 0xC470D0
void __fastcall hkaiNavMeshDebugUtils::highlightNavMeshEdges(
        hkaiNavMesh *mesh,
        hkArrayBase<unsigned int> *edgesVisited,
        unsigned int highlightColor,
        hkVector4f *offset)
{
  hkaiNavMeshInstance mesha; // [rsp+20h] [rbp-1E8h] BYREF

  hkaiNavMeshInstance::hkaiNavMeshInstance(&mesha);
  hkaiNavMeshInstance::tempInit(&mesha, mesh, 0);
  hkaiNavMeshDebugUtils::highlightNavMeshEdges(&mesha, edgesVisited, highlightColor, offset);
  hkaiNavMeshInstance::~hkaiNavMeshInstance(&mesha);
}

// File Line: 264
// RVA: 0xC47310
void __fastcall hkaiNavMeshDebugUtils::highlightNavMeshEdgeMidpoints(
        hkaiNavMesh *mesh,
        int faceIndexStart,
        int faceIndexEnd,
        hkArrayBase<unsigned int> *edgesVisited,
        unsigned int highlightColor,
        float highlightRadius,
        float displayOffset)
{
  hkaiNavMeshInstance mesha; // [rsp+40h] [rbp-1E8h] BYREF

  hkaiNavMeshInstance::hkaiNavMeshInstance(&mesha);
  hkaiNavMeshInstance::tempInit(&mesha, mesh, 0);
  hkaiNavMeshDebugUtils::highlightNavMeshEdgeMidpoints(
    &mesha,
    faceIndexStart,
    faceIndexEnd,
    edgesVisited,
    highlightColor,
    highlightRadius,
    displayOffset);
  hkaiNavMeshInstance::~hkaiNavMeshInstance(&mesha);
}

// File Line: 271
// RVA: 0xC47450
void __fastcall hkaiNavMeshDebugUtils::highlightNavMeshEdgeMidpoints(
        hkaiNavMesh *mesh,
        int faceIndexStart,
        hkVector4f *startPoint,
        int faceIndexEnd,
        hkVector4f *endPoint,
        hkArrayBase<unsigned int> *edgesVisited,
        unsigned int highlightColor,
        float highlightRadius,
        float displayOffset)
{
  hkaiNavMeshInstance mesha; // [rsp+50h] [rbp-1E8h] BYREF

  hkaiNavMeshInstance::hkaiNavMeshInstance(&mesha);
  hkaiNavMeshInstance::tempInit(&mesha, mesh, 0);
  hkaiNavMeshDebugUtils::highlightNavMeshEdgeMidpoints(
    &mesha,
    faceIndexStart,
    startPoint,
    faceIndexEnd,
    endPoint,
    edgesVisited,
    highlightColor,
    highlightRadius,
    displayOffset);
  hkaiNavMeshInstance::~hkaiNavMeshInstance(&mesha);
}

// File Line: 278
// RVA: 0xC473B0
void __fastcall hkaiNavMeshDebugUtils::highlightNavMeshEdgeMidpoints(
        hkaiNavMeshUtils *mesh,
        hkaiNavMeshInstance *faceIndexStart,
        unsigned int faceIndexEnd,
        hkVector4f *edgesVisited,
        unsigned int highlightColor,
        float highlightRadius,
        float displayOffset)
{
  int v9; // esi
  hkVector4f *v11; // r9
  hkVector4f endPoint; // [rsp+50h] [rbp-28h] BYREF
  __m128 faceIndex; // [rsp+60h] [rbp-18h] BYREF

  v9 = (int)faceIndexStart;
  hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(mesh, faceIndexStart, &faceIndex, edgesVisited);
  hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
    mesh,
    (hkaiNavMeshInstance *)faceIndexEnd,
    &endPoint.m_quad,
    v11);
  hkaiNavMeshDebugUtils::highlightNavMeshEdgeMidpoints(
    (hkaiNavMeshInstance *)mesh,
    v9,
    (hkVector4f *)&faceIndex,
    faceIndexEnd,
    &endPoint,
    (hkArrayBase<unsigned int> *)edgesVisited,
    highlightColor,
    highlightRadius,
    displayOffset);
}

// File Line: 287
// RVA: 0xC47510
void __fastcall hkaiNavMeshDebugUtils::highlightNavMeshEdgeMidpoints(
        hkSimdFloat32 *mesh,
        unsigned int faceIndexStart,
        hkVector4f *startPoint,
        hkVector4f *faceIndexEnd,
        hkVector4f *endPoint,
        hkArrayBase<unsigned int> *edgesVisited,
        unsigned int highlightColor,
        float highlightRadius,
        float displayOffset)
{
  unsigned int v9; // r12d
  __m128 v10; // xmm12
  int v11; // r14d
  unsigned int v12; // r10d
  int v13; // eax
  __int64 v16; // rsi
  __m128 *v17; // r12
  __m128 v18; // xmm12
  hkVector4f *v19; // r9
  __m128 v20; // xmm11
  hkVector4f *v21; // r9
  hkVector4f *v22; // r9
  hkaiNavMeshInstance *v23; // r8
  __m128 v24; // xmm1
  __m128 m_quad; // xmm10
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
  __m128 v42; // xmm0
  __m128 v43; // xmm5
  __m128 v44; // xmm6
  __m128 v45; // xmm5
  __m128 v46; // xmm0
  __m128 v47; // xmm4
  __m128 v48; // xmm4
  __m128 v49; // xmm1
  __m128 v50; // xmm2
  __m128 v51; // xmm1
  __m128 v52; // xmm8
  __m128 v53; // xmm3
  __m128 v54; // xmm0
  __m128 v55; // xmm2
  __m128 v56; // xmm0
  __m128 v57; // xmm4
  __m128 v58; // xmm1
  int edgeIndex[4]; // [rsp+40h] [rbp-90h] BYREF
  hkVector4f start; // [rsp+50h] [rbp-80h] BYREF
  int faceIndex[4]; // [rsp+60h] [rbp-70h] BYREF
  hkVector4f a; // [rsp+70h] [rbp-60h] BYREF
  hkaiNavMeshUtils v63; // [rsp+80h] [rbp-50h] BYREF
  hkaiNavMeshUtils v64; // [rsp+90h] [rbp-40h] BYREF
  hkaiNavMeshUtils v65; // [rsp+A0h] [rbp-30h] BYREF
  __m128 v66; // [rsp+110h] [rbp+40h]
  hkVector4f *v67; // [rsp+1A0h] [rbp+D0h]
  unsigned int v68; // [rsp+1A8h] [rbp+D8h]
  __m128 *vars0; // [rsp+1B0h] [rbp+E0h]
  _DWORD *retaddr; // [rsp+1B8h] [rbp+E8h]
  unsigned int color; // [rsp+1C0h] [rbp+F0h]
  float v72; // [rsp+1C8h] [rbp+F8h]
  float v73; // [rsp+1D0h] [rbp+100h]

  v73 = *(float *)&startPoint;
  v11 = -1;
  v12 = (unsigned int)faceIndexEnd;
  v13 = retaddr[2];
  v16 = -1i64;
  if ( v13 > -1 )
  {
    color = v9;
    v17 = vars0;
    v66 = v10;
    v10.m128_f32[0] = *(float *)&startPoint;
    v18 = _mm_shuffle_ps(v10, v10, 0);
    while ( v16 == -1 )
    {
      start.m_quad = startPoint->m_quad;
      hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
        &v63,
        mesh,
        (hkaiNavMeshInstance *)faceIndexStart,
        (__m128 *)faceIndex);
      if ( retaddr[2] )
      {
        hkaiNavMeshUtils::calcEdgeMidpoint<hkaiNavMeshInstance>(
          (hkaiNavMeshUtils *)mesh,
          (hkaiNavMeshInstance *)**(unsigned int **)retaddr,
          (__m128 *)edgeIndex,
          v19);
LABEL_13:
        v20 = *(__m128 *)edgeIndex;
        goto LABEL_14;
      }
      v20 = *v17;
      *(__m128 *)edgeIndex = *v17;
LABEL_14:
      if ( v72 > 0.0 )
      {
        m_quad = start.m_quad;
        v26 = (__m128)LODWORD(v73);
        v26.m128_f32[0] = v73 * 0.1;
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
        v38 = (__m128)LODWORD(v72);
        v38.m128_f32[0] = v72 * -1.2;
        v39 = _mm_andnot_ps(_mm_cmple_ps(v34, (__m128)0i64), _mm_mul_ps(v36, v37));
        v40 = (__m128)LODWORD(v72);
        v40.m128_f32[0] = v72 * 1.2;
        v41 = _mm_mul_ps(v32, v39);
        *(__m128 *)faceIndex = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v38, v38, 0), v41), v20);
        v42 = _mm_mul_ps(_mm_shuffle_ps(v40, v40, 0), v41);
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
        v44 = _mm_add_ps(v43, v20);
        v45 = _mm_add_ps(v43, m_quad);
        *(__m128 *)edgeIndex = v44;
        v46 = _mm_sub_ps(v45, v44);
        v47 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v46, v46, 201), *(__m128 *)faceIndex),
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)faceIndex, *(__m128 *)faceIndex, 201), v46));
        v48 = _mm_shuffle_ps(v47, v47, 201);
        v49 = _mm_mul_ps(v48, v48);
        v50 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v49, v49, 85), _mm_shuffle_ps(v49, v49, 0)),
                _mm_shuffle_ps(v49, v49, 170));
        v51 = _mm_rsqrt_ps(v50);
        v52 = _mm_mul_ps(*(__m128 *)_xmm, v51);
        v53 = _mm_cmple_ps(v50, (__m128)0i64);
        v54 = _mm_mul_ps(v51, v50);
        v55 = _mm_xor_ps((__m128)LODWORD(v72), *(__m128 *)_xmm);
        v56 = _mm_mul_ps(v54, v51);
        v51.m128_f32[0] = v72;
        v57 = _mm_mul_ps(v48, _mm_andnot_ps(v53, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v56), v52)));
        v58 = _mm_mul_ps(_mm_shuffle_ps(v51, v51, 0), v57);
        start.m_quad = _mm_add_ps(v45, v58);
        *(__m128 *)faceIndex = _mm_add_ps(v44, _mm_mul_ps(_mm_shuffle_ps(v55, v55, 0), v57));
        a.m_quad = _mm_add_ps(v44, v58);
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
      startPoint = v67;
      v12 = v68;
      ++v11;
      ++v16;
      if ( v11 >= v13 )
        return;
    }
    if ( v11 == v13 - 1 )
    {
      *(__m128 *)edgeIndex = *v17;
      hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(&v65, mesh, (hkaiNavMeshInstance *)v12, (__m128 *)faceIndex);
      hkaiNavMeshUtils::calcEdgeMidpoint<hkaiNavMeshInstance>(
        (hkaiNavMeshUtils *)mesh,
        (hkaiNavMeshInstance *)*(unsigned int *)(*(_QWORD *)retaddr + 4i64 * (int)retaddr[2] - 4),
        &start.m_quad,
        v21);
    }
    else
    {
      hkaiNavMeshUtils::calcEdgeMidpoint<hkaiNavMeshInstance>(
        (hkaiNavMeshUtils *)mesh,
        (hkaiNavMeshInstance *)*(unsigned int *)(*(_QWORD *)retaddr + 4 * v16),
        &start.m_quad,
        faceIndexEnd);
      hkaiNavMeshUtils::calcEdgeMidpoint<hkaiNavMeshInstance>(
        (hkaiNavMeshUtils *)mesh,
        (hkaiNavMeshInstance *)*(unsigned int *)(*(_QWORD *)retaddr + 4 * v16 + 4),
        (__m128 *)edgeIndex,
        v22);
      if ( v16 )
        v23 = (hkaiNavMeshInstance *)(hkaiNavMeshInstance_get_hkaiNavMesh::Edge__23(
                                        (hkaiNavMesh::Edge *)mesh[2].m_real.m128_u64[0],
                                        mesh[2].m_real.m128_i32[2],
                                        (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&mesh[16],
                                        (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&mesh[18],
                                        (hkArray<int,hkContainerHeapAllocator> *)&mesh[13],
                                        *(_DWORD *)(*(_QWORD *)retaddr + 4 * v16 - 4))->m_oppositeFace & 0x3FFFFF);
      else
        v23 = (hkaiNavMeshInstance *)faceIndexStart;
      hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(&v64, mesh, v23, (__m128 *)faceIndex);
    }
    goto LABEL_13;
  }
}

// File Line: 375
// RVA: 0xC47A60
void __fastcall hkaiNavMeshDebugUtils::drawPath(
        hkaiPath *path,
        float width,
        hkVector4f *up,
        unsigned int color,
        unsigned int lastSegmentColor,
        float offset)
{
  hkaiNavMeshDebugUtils::_drawPath(path, width, up, color, lastSegmentColor, 0i64, 0, offset);
}

// File Line: 380
// RVA: 0xC47AA0
void __fastcall hkaiNavMeshDebugUtils::_drawPath(
        hkaiPath *path,
        float width,
        hkVector4f *up,
        unsigned int color,
        unsigned int lastSegmentColor,
        hkDebugDisplayHandler *displayHandler,
        int tag,
        float offset)
{
  __m128 v8; // xmm9
  __int64 m_size; // rax
  int v10; // r15d
  unsigned int v11; // edx
  __int64 v12; // rsi
  __int64 v13; // r13
  __m128 v14; // xmm7
  float v15; // xmm2_4
  hkDebugDisplayHandler *v16; // rbx
  int v17; // r14d
  int v18; // eax
  __m128 v19; // xmm9
  __int64 v20; // r12
  bool v21; // zf
  hkaiPath::PathPoint *m_data; // rax
  unsigned int v23; // edi
  __m128 m_quad; // xmm8
  __m128 v25; // xmm6
  __m128 v26; // xmm0
  __m128 v27; // xmm5
  __m128 v28; // xmm5
  __m128 v29; // xmm1
  __m128 v30; // xmm3
  __m128 v31; // xmm2
  __m128 v32; // xmm4
  hkVector4f c; // [rsp+50h] [rbp-B0h] BYREF
  hkVector4f a; // [rsp+60h] [rbp-A0h] BYREF
  hkVector4f v36; // [rsp+70h] [rbp-90h] BYREF
  hkVector4f v37; // [rsp+80h] [rbp-80h] BYREF
  char v38; // [rsp+90h] [rbp-70h] BYREF
  hkVector4f b; // [rsp+A0h] [rbp-60h] BYREF
  hkResult v40; // [rsp+B0h] [rbp-50h] BYREF
  char v41; // [rsp+B4h] [rbp-4Ch] BYREF
  hkVector4f v42; // [rsp+C0h] [rbp-40h] BYREF
  hkVector4f v43; // [rsp+D0h] [rbp-30h] BYREF
  __m128 v44; // [rsp+110h] [rbp+10h]
  hkaiPath *v45; // [rsp+190h] [rbp+90h]
  int v46; // [rsp+198h] [rbp+98h]
  float v47; // [rsp+1A0h] [rbp+A0h] BYREF

  v45 = path;
  m_size = path->m_points.m_size;
  v10 = 1;
  v11 = color;
  v12 = 1i64;
  v13 = m_size;
  v47 = FLOAT_0_050000001;
  v14 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(offset), (__m128)LODWORD(offset), 0), up->m_quad);
  v15 = fmaxf(width * 0.5, 0.050000001);
  if ( m_size > 1 )
  {
    v16 = displayHandler;
    v17 = tag;
    v44 = v8;
    v8.m128_f32[0] = v15;
    v18 = m_size - 1;
    v19 = _mm_shuffle_ps(v8, v8, 0);
    v46 = v18;
    v20 = 0i64;
    do
    {
      v21 = v10 == v18;
      m_data = path->m_points.m_data;
      v23 = v11;
      if ( v21 )
        v23 = lastSegmentColor;
      m_quad = m_data[v20].m_position.m_quad;
      v25 = m_data[v20 + 1].m_position.m_quad;
      v26 = _mm_sub_ps(m_quad, v25);
      v27 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(m_data[v20].m_normal.m_quad, m_data[v20].m_normal.m_quad, 201), v26),
              _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), m_data[v20].m_normal.m_quad));
      v28 = _mm_shuffle_ps(v27, v27, 201);
      v29 = _mm_mul_ps(v28, v28);
      v30 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
              _mm_shuffle_ps(v29, v29, 170));
      v31 = _mm_rsqrt_ps(v30);
      v32 = _mm_mul_ps(
              _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmple_ps(v30, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v30), v31)),
                    _mm_mul_ps(*(__m128 *)_xmm, v31))),
                v28),
              v19);
      c.m_quad = _mm_add_ps(_mm_add_ps(v32, m_quad), v14);
      b.m_quad = _mm_add_ps(_mm_add_ps(v32, v25), v14);
      a.m_quad = _mm_add_ps(_mm_sub_ps(v25, v32), v14);
      v37.m_quad = _mm_add_ps(_mm_sub_ps(m_quad, v32), v14);
      if ( v16 )
      {
        v16->vfptr->displayTriangle(v16, (hkResult *)&v47, &a, &b, &c, v23, 0, v17);
        v16->vfptr->displayTriangle(v16, (hkResult *)&v38, &c, &v37, &a, v23, 0, v17);
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
          &v37,
          &a,
          v23,
          0,
          (int)hkDebugDisplayProcess::m_tag);
      }
      if ( v12 > 1 )
      {
        v36.m_quad = _mm_add_ps(v14, m_quad);
        if ( v16 )
        {
          v16->vfptr->displayTriangle(v16, (hkResult *)&v41, &c, &v42, &v36, v23, 0, v17);
          v16->vfptr->displayTriangle(v16, &v40, &v43, &v37, &v36, v23, 0, v17);
        }
        else
        {
          hkDebugDisplay::displayTriangle(
            hkSingleton<hkDebugDisplay>::s_instance,
            &c,
            &v42,
            &v36,
            v23,
            0,
            (int)hkDebugDisplayProcess::m_tag);
          hkDebugDisplay::displayTriangle(
            hkSingleton<hkDebugDisplay>::s_instance,
            &v43,
            &v37,
            &v36,
            v23,
            0,
            (int)hkDebugDisplayProcess::m_tag);
        }
      }
      path = v45;
      v18 = v46;
      v11 = color;
      ++v12;
      v42.m_quad = b.m_quad;
      v43.m_quad = a.m_quad;
      ++v10;
      ++v20;
    }
    while ( v12 < v13 );
  }
}

// File Line: 436
// RVA: 0xC47EB0
void __fastcall hkaiNavMeshDebugUtils::drawPathWithRadius(
        hkaiPathfindingUtil::FindPathInput *pathInput,
        hkaiPathfindingUtil::FindPathOutput *pathOutput,
        unsigned int color,
        unsigned int failureColor,
        float displayOffset)
{
  hkaiNavMeshDebugUtils::_drawPathWithRadius(pathInput, pathOutput, color, failureColor, 0i64, 0, displayOffset);
}

// File Line: 441
// RVA: 0xC47EE0
void __fastcall hkaiNavMeshDebugUtils::_drawPathWithRadius(
        hkaiPathfindingUtil::FindPathInput *pathInput,
        hkaiPathfindingUtil::FindPathOutput *pathOutput,
        unsigned int color,
        unsigned int failureColor,
        hkDebugDisplayHandler *displayHandler,
        int tag,
        float displayOffset)
{
  hkDebugDisplayHandler *v7; // rdi
  int m_size; // r9d
  int v11; // edx
  int v12; // r9d
  int v15; // edi
  __int64 v16; // rbx
  hkaiPath::PathPoint *m_data; // rsi
  hkaiPath::PathPoint *v18; // rcx
  int m_storage; // eax
  unsigned int v20; // ecx
  __m128 v21; // xmm6
  hkVector4f *v22; // rdi
  unsigned int v23; // ebx
  hkaiPath::PathPoint *v24; // rcx
  __m128 m_quad; // xmm0
  float offset[4]; // [rsp+38h] [rbp-31h] BYREF
  hkaiPath path; // [rsp+48h] [rbp-21h] BYREF
  hkResult result; // [rsp+C8h] [rbp+5Fh] BYREF
  hkDebugDisplayHandler *v29; // [rsp+D8h] [rbp+6Fh]

  v29 = v7;
  m_size = pathOutput->m_pathOut.m_size;
  v11 = 0;
  v12 = 2 * m_size;
  *(_DWORD *)&path.m_memSizeAndFlags = 0x1FFFF;
  path.vfptr = (hkBaseObjectVtbl *)&hkaiPath::`vftable;
  path.m_points.m_data = 0i64;
  path.m_points.m_size = 0;
  path.m_points.m_capacityAndFlags = 0x80000000;
  path.m_referenceFrame.m_storage = 0;
  if ( v12 > 0 )
  {
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &path.m_points, v12, 48);
    v11 = path.m_points.m_size;
  }
  v15 = 0;
  if ( pathOutput->m_pathOut.m_size > 0 )
  {
    v16 = 0i64;
    do
    {
      m_data = pathOutput->m_pathOut.m_data;
      if ( v11 == (path.m_points.m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &path.m_points, 48);
        v11 = path.m_points.m_size;
      }
      v18 = &path.m_points.m_data[v11];
      if ( v18 )
      {
        v18->m_position = m_data[v16].m_position;
        v18->m_normal = m_data[v16].m_normal;
        *(_OWORD *)&v18->m_userEdgeData = *(_OWORD *)&m_data[v16].m_userEdgeData;
        v11 = path.m_points.m_size;
      }
      ++v11;
      ++v15;
      ++v16;
      path.m_points.m_size = v11;
    }
    while ( v15 < pathOutput->m_pathOut.m_size );
  }
  m_storage = (unsigned __int8)pathOutput->m_outputParameters.m_status.m_storage;
  v20 = color;
  v21 = _mm_mul_ps(
          _mm_cvtepi32_ps(
            _mm_add_epi32(
              _mm_unpacklo_epi16((__m128i)0i64, _mm_loadl_epi64((const __m128i *)&pathInput->m_searchParameters)),
              _mm_loadu_si128((const __m128i *)hkPackedUnitVector_m_offset))),
          (__m128)xmmword_141A713A0);
  *(__m128 *)offset = v21;
  if ( (unsigned int)(m_storage - 3) <= 1 && pathInput->m_goalPoints.m_size == 1 )
  {
    v22 = pathInput->m_goalPoints.m_data;
    v23 = *pathInput->m_goalFaceKeys.m_data >> 22;
    if ( v11 == (path.m_points.m_capacityAndFlags & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &path.m_points, 48);
      v11 = path.m_points.m_size;
    }
    v24 = &path.m_points.m_data[v11];
    path.m_points.m_size = v11 + 1;
    m_quad = v22->m_quad;
    v24->m_normal.m_quad = v21;
    v24->m_sectionId = v23;
    v24->m_userEdgeData = 0;
    v24->m_flags.m_storage = 0;
    v24->m_position.m_quad = m_quad;
    v20 = failureColor;
  }
  hkaiNavMeshDebugUtils::_drawPath(
    &path,
    pathInput->m_agentInfo.m_diameter,
    (hkVector4f *)offset,
    color,
    v20,
    v29,
    (int)displayHandler,
    *(float *)&tag);
  path.m_points.m_size = 0;
  if ( path.m_points.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      path.m_points.m_data,
      48 * (path.m_points.m_capacityAndFlags & 0x3FFFFFFF));
}

// File Line: 466
// RVA: 0xC4B4A0
// local variable allocation has failed, the output may be wrong!
unsigned int __fastcall perturbColor(unsigned int color, int seed, double variance)
{
  __m128 v3; // xmm4
  int v4; // eax
  float v5; // xmm0_4
  int v6; // eax
  float v7; // xmm0_4
  int v8; // eax
  __m128 v9; // xmm3
  __m128 v10; // xmm0
  __m128 v11; // xmm0
  __m128 v13; // [rsp+20h] [rbp-38h]

  v3 = 0i64;
  v4 = 1664525 * seed + 1013904223;
  v5 = (float)v4;
  v6 = 1664525 * v4 + 1013904223;
  v13.m128_f32[0] = (float)((float)(v5 * 2.3283064e-10) * 2.0) - 1.0;
  v7 = (float)v6;
  v8 = 1664525 * v6 + 1013904223;
  v13.m128_f32[1] = (float)((float)(v7 * 2.3283064e-10) * 2.0) - 1.0;
  v13.m128_f32[2] = (float)((float)((float)v8 * 2.3283064e-10) * 2.0) - 1.0;
  v9 = 0i64;
  v3.m128_f32[0] = (float)BYTE2(color) * 0.0039215689;
  v9.m128_f32[0] = (float)BYTE1(color) * 0.0039215689;
  v13.m128_f32[3] = (float)((float)((float)(1664525 * v8 + 1013904223) * 2.3283064e-10) * 2.0) - 1.0;
  v10 = 0i64;
  v10.m128_f32[0] = (float)(unsigned __int8)color * 0.0039215689;
  v11 = _mm_min_ps(
          query.m_quad,
          _mm_max_ps(
            (__m128)0i64,
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&variance, *(__m128 *)&variance, 0), v13),
              _mm_unpacklo_ps(_mm_unpacklo_ps(v3, v10), _mm_unpacklo_ps(v9, (__m128)0i64)))));
  return hkColor::rgbFromFloats(
           v11.m128_f32[0],
           _mm_shuffle_ps(v11, v11, 85).m128_f32[0],
           _mm_shuffle_ps(v11, v11, 170).m128_f32[0],
           (float)HIBYTE(color) * 0.0039215689);
}

// File Line: 487
// RVA: 0xC4B610
__int64 __fastcall realToOrderedUint(const float *in)
{
  return *(_DWORD *)in ^ ((*(int *)in >> 31) | 0x80000000);
}

// File Line: 500
// RVA: 0xC46810
void __fastcall hkaiNavMeshDebugUtils::showNavMesh(
        hkDebugDisplayHandler *displayHandler,
        int tag,
        hkaiNavMeshDebugUtils::DebugInfo *settings,
        hkaiNavMesh *navMesh)
{
  hkaiStreamingCollection::InstanceInfo *m_data; // r8
  __int64 v9; // rdx
  hkaiDirectedGraphInstance **p_m_clusterGraphInstance; // rax
  hkaiStreamingCollection array; // [rsp+30h] [rbp-228h] BYREF
  hkResult result; // [rsp+60h] [rbp-1F8h] BYREF
  hkaiNavMeshInstance v13; // [rsp+70h] [rbp-1E8h] BYREF

  hkaiNavMeshInstance::hkaiNavMeshInstance(&v13);
  hkaiNavMeshInstance::tempInit(&v13, navMesh, 0);
  hkaiStreamingCollection::hkaiStreamingCollection(&array);
  array.m_isTemporary.m_bool = 1;
  if ( (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) == 0 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array.m_instances, 1, 48);
  m_data = array.m_instances.m_data;
  v9 = 1 - array.m_instances.m_size;
  if ( 1 - array.m_instances.m_size > 0 )
  {
    p_m_clusterGraphInstance = &array.m_instances.m_data[array.m_instances.m_size].m_clusterGraphInstance;
    do
    {
      if ( p_m_clusterGraphInstance != (hkaiDirectedGraphInstance **)16 )
      {
        *(p_m_clusterGraphInstance - 2) = 0i64;
        *(p_m_clusterGraphInstance - 1) = 0i64;
        *p_m_clusterGraphInstance = 0i64;
        p_m_clusterGraphInstance[1] = 0i64;
        p_m_clusterGraphInstance[2] = 0i64;
        *((_DWORD *)p_m_clusterGraphInstance + 6) = -1;
      }
      p_m_clusterGraphInstance += 6;
      --v9;
    }
    while ( v9 );
    m_data = array.m_instances.m_data;
  }
  array.m_instances.m_size = 1;
  m_data->m_instancePtr = &v13;
  array.m_instances.m_data->m_clusterGraphInstance = 0i64;
  array.m_instances.m_data->m_mediator = 0i64;
  hkaiNavMeshDebugUtils::showStreamingCollection(displayHandler, tag, settings, &array);
  hkaiStreamingCollection::~hkaiStreamingCollection(&array);
  hkaiNavMeshInstance::~hkaiNavMeshInstance(&v13);
}

// File Line: 511
// RVA: 0xC46E70
void __fastcall hkaiNavMeshDebugUtils::showNavMesh(hkaiNavMeshDebugUtils::DebugInfo *settings, hkaiNavMesh *navMesh)
{
  hkaiStreamingCollection::InstanceInfo *m_data; // r8
  __int64 v5; // rdx
  hkaiDirectedGraphInstance **p_m_clusterGraphInstance; // rax
  hkaiStreamingCollection array; // [rsp+30h] [rbp-218h] BYREF
  hkaiNavMeshInstance v8; // [rsp+60h] [rbp-1E8h] BYREF
  hkResult result; // [rsp+260h] [rbp+18h] BYREF

  hkaiNavMeshInstance::hkaiNavMeshInstance(&v8);
  hkaiNavMeshInstance::tempInit(&v8, navMesh, 0);
  hkaiStreamingCollection::hkaiStreamingCollection(&array);
  array.m_isTemporary.m_bool = 1;
  if ( (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) == 0 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array.m_instances, 1, 48);
  m_data = array.m_instances.m_data;
  v5 = 1 - array.m_instances.m_size;
  if ( 1 - array.m_instances.m_size > 0 )
  {
    p_m_clusterGraphInstance = &array.m_instances.m_data[array.m_instances.m_size].m_clusterGraphInstance;
    do
    {
      if ( p_m_clusterGraphInstance != (hkaiDirectedGraphInstance **)16 )
      {
        *(p_m_clusterGraphInstance - 2) = 0i64;
        *(p_m_clusterGraphInstance - 1) = 0i64;
        *p_m_clusterGraphInstance = 0i64;
        p_m_clusterGraphInstance[1] = 0i64;
        p_m_clusterGraphInstance[2] = 0i64;
        *((_DWORD *)p_m_clusterGraphInstance + 6) = -1;
      }
      p_m_clusterGraphInstance += 6;
      --v5;
    }
    while ( v5 );
    m_data = array.m_instances.m_data;
  }
  array.m_instances.m_size = 1;
  m_data->m_instancePtr = &v8;
  array.m_instances.m_data->m_clusterGraphInstance = 0i64;
  array.m_instances.m_data->m_mediator = 0i64;
  hkaiNavMeshDebugUtils::showStreamingCollection(0i64, 0, settings, &array);
  hkaiStreamingCollection::~hkaiStreamingCollection(&array);
  hkaiNavMeshInstance::~hkaiNavMeshInstance(&v8);
}

// File Line: 522
// RVA: 0xC46FB0
void __fastcall hkaiNavMeshDebugUtils::showNavMesh(
        hkaiNavMeshDebugUtils::DebugInfo *settings,
        hkaiNavMeshInstance *nmi)
{
  hkaiStreamingCollection::InstanceInfo *m_data; // r8
  __int64 v5; // rdx
  hkaiDirectedGraphInstance **p_m_clusterGraphInstance; // rax
  hkaiStreamingCollection array; // [rsp+30h] [rbp-38h] BYREF
  hkResult result; // [rsp+78h] [rbp+10h] BYREF

  hkaiStreamingCollection::hkaiStreamingCollection(&array);
  array.m_isTemporary.m_bool = 1;
  if ( (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) == 0 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array.m_instances, 1, 48);
  m_data = array.m_instances.m_data;
  v5 = 1 - array.m_instances.m_size;
  if ( 1 - array.m_instances.m_size > 0 )
  {
    p_m_clusterGraphInstance = &array.m_instances.m_data[array.m_instances.m_size].m_clusterGraphInstance;
    do
    {
      if ( p_m_clusterGraphInstance != (hkaiDirectedGraphInstance **)16 )
      {
        *(p_m_clusterGraphInstance - 2) = 0i64;
        *(p_m_clusterGraphInstance - 1) = 0i64;
        *p_m_clusterGraphInstance = 0i64;
        p_m_clusterGraphInstance[1] = 0i64;
        p_m_clusterGraphInstance[2] = 0i64;
        *((_DWORD *)p_m_clusterGraphInstance + 6) = -1;
      }
      p_m_clusterGraphInstance += 6;
      --v5;
    }
    while ( v5 );
    m_data = array.m_instances.m_data;
  }
  array.m_instances.m_size = 1;
  m_data->m_instancePtr = nmi;
  array.m_instances.m_data->m_clusterGraphInstance = 0i64;
  array.m_instances.m_data->m_mediator = 0i64;
  hkaiNavMeshDebugUtils::showStreamingCollection(0i64, 0, settings, &array);
  hkaiStreamingCollection::~hkaiStreamingCollection(&array);
}

// File Line: 530
// RVA: 0xC46960
void __fastcall hkaiNavMeshDebugUtils::showNavMesh(
        hkDebugDisplayHandler *displayHandler,
        int tag,
        hkaiNavMeshDebugUtils::DebugInfo *settings,
        hkaiNavMeshInstance *nmi)
{
  hkaiStreamingCollection::InstanceInfo *m_data; // r8
  __int64 v9; // rdx
  hkaiDirectedGraphInstance **p_m_clusterGraphInstance; // rax
  hkaiStreamingCollection array; // [rsp+30h] [rbp-38h] BYREF
  hkResult result; // [rsp+88h] [rbp+20h] BYREF

  hkaiStreamingCollection::hkaiStreamingCollection(&array);
  array.m_isTemporary.m_bool = 1;
  if ( (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) == 0 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array.m_instances, 1, 48);
  m_data = array.m_instances.m_data;
  v9 = 1 - array.m_instances.m_size;
  if ( 1 - array.m_instances.m_size > 0 )
  {
    p_m_clusterGraphInstance = &array.m_instances.m_data[array.m_instances.m_size].m_clusterGraphInstance;
    do
    {
      if ( p_m_clusterGraphInstance != (hkaiDirectedGraphInstance **)16 )
      {
        *(p_m_clusterGraphInstance - 2) = 0i64;
        *(p_m_clusterGraphInstance - 1) = 0i64;
        *p_m_clusterGraphInstance = 0i64;
        p_m_clusterGraphInstance[1] = 0i64;
        p_m_clusterGraphInstance[2] = 0i64;
        *((_DWORD *)p_m_clusterGraphInstance + 6) = -1;
      }
      p_m_clusterGraphInstance += 6;
      --v9;
    }
    while ( v9 );
    m_data = array.m_instances.m_data;
  }
  array.m_instances.m_size = 1;
  m_data->m_instancePtr = nmi;
  array.m_instances.m_data->m_clusterGraphInstance = 0i64;
  array.m_instances.m_data->m_mediator = 0i64;
  hkaiNavMeshDebugUtils::showStreamingCollection(displayHandler, tag, settings, &array);
  hkaiStreamingCollection::~hkaiStreamingCollection(&array);
}

// File Line: 538
// RVA: 0xC470B0
void __fastcall hkaiNavMeshDebugUtils::showStreamingCollection(
        hkaiNavMeshDebugUtils::DebugInfo *settings,
        hkaiStreamingCollection *collection)
{
  hkaiNavMeshDebugUtils::showStreamingCollection(0i64, 0, settings, collection);
}

// File Line: 543
// RVA: 0xC4B630
unsigned int __fastcall getLitColor(
        float r,
        float g,
        float b,
        float alpha,
        hkVector4f *v0,
        hkVector4f *v1,
        hkVector4f *v2,
        hkVector4f *lightDir)
{
  __m128 v10; // xmm6
  __m128 v11; // xmm5
  __m128 v13; // xmm7
  __m128 v14; // xmm7
  __m128 v15; // xmm1
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm4

  v10 = _mm_sub_ps(v1->m_quad, v0->m_quad);
  v11 = _mm_sub_ps(v2->m_quad, v0->m_quad);
  v13 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v10), _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v11));
  v14 = _mm_shuffle_ps(v13, v13, 201);
  v15 = _mm_mul_ps(v14, v14);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v17 = _mm_rsqrt_ps(v16);
  v18 = _mm_mul_ps(
          _mm_mul_ps(
            _mm_andnot_ps(
              _mm_cmple_ps(v16, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
                _mm_mul_ps(*(__m128 *)_xmm, v17))),
            v14),
          lightDir->m_quad);
  v15.m128_f32[0] = fmaxf(
                      0.0,
                      (float)(0.0
                            - (float)((float)(_mm_shuffle_ps(v18, v18, 85).m128_f32[0]
                                            + _mm_shuffle_ps(v18, v18, 0).m128_f32[0])
                                    + _mm_shuffle_ps(v18, v18, 170).m128_f32[0]))
                    + 0.75)
                  * 0.5714286;
  return hkColor::rgbFromFloats(v15.m128_f32[0] * r, v15.m128_f32[0] * g, v15.m128_f32[0] * b, alpha);
}

// File Line: 562
// RVA: 0xC4B7A0
unsigned int __fastcall getLitColor_0(
        unsigned int color,
        hkVector4f *v0,
        hkVector4f *v1,
        hkVector4f *v2,
        hkVector4f *lightDir)
{
  return getLitColor(
           (float)BYTE2(color) * 0.0039215689,
           (float)BYTE1(color) * 0.0039215689,
           (float)(unsigned __int8)color * 0.0039215689,
           (float)HIBYTE(color) * 0.0039215689,
           v0,
           v1,
           v2,
           lightDir);
}

// File Line: 572
// RVA: 0xC4B820
void __fastcall formatUserData(hkStringBuf *label, const int *dataPtr, int N)
{
  int v4; // esi
  __int64 v6; // rax
  __int64 v7; // rdi
  __int64 v9; // r8
  __int64 v10; // rbp
  int v11; // r15d
  const char *v12; // r9

  if ( N > 0 )
  {
    v4 = 0;
    v6 = 0i64;
    v7 = N;
    while ( !dataPtr[v6] )
    {
      if ( ++v6 >= N )
        return;
    }
    if ( N == 1 )
    {
      v9 = *(unsigned int *)dataPtr;
      if ( (_DWORD)v9 )
        hkStringBuf::printf(label, "[%d]", v9);
    }
    else
    {
      hkStringBuf::operator=(label, "[");
      v10 = 0i64;
      v11 = N - 1;
      do
      {
        v12 = ", ";
        if ( v4 == v11 )
          v12 = "]";
        hkStringBuf::appendPrintf(label, "%d%s", (unsigned int)dataPtr[v10++], v12);
        ++v4;
      }
      while ( v10 < v7 );
    }
  }
}

// File Line: 613
// RVA: 0xC46A80
void __fastcall hkaiNavMeshDebugUtils::showStreamingCollection(
        hkDebugDisplayHandler *displayHandler,
        int tag,
        hkaiNavMeshDebugUtils::DebugInfo *settings,
        hkaiStreamingCollection *collection)
{
  hkaiStreamingCollection *v4; // r15
  bool shouldDrawEdges; // bl
  bool shouldDrawUserEdges; // al
  __int64 v8; // r13
  int v9; // r14d
  __int64 v10; // rbx
  hkaiNavMeshInstance *v11; // rbx
  _QWORD *Value; // r8
  _QWORD *v13; // rcx
  unsigned __int64 v14; // rax
  _QWORD *v15; // rcx
  hkArray<int,hkContainerHeapAllocator> *m_regionMap; // r12
  int v17; // edi
  int m_size; // edx
  int m_numOriginalFaces; // ecx
  int v20; // r15d
  int m_userData; // edi
  char *v22; // rax
  int m_showSingleRegionIndex; // r8d
  unsigned int UnlitFaceColor; // eax
  unsigned int v25; // r14d
  int v26; // r14d
  _QWORD *v27; // rax
  _QWORD *v28; // rcx
  _QWORD *v29; // r8
  unsigned __int64 v30; // rax
  _QWORD *v31; // rcx
  unsigned int faceColor; // [rsp+28h] [rbp-58h]
  bool shouldDrawFaces; // [rsp+30h] [rbp-50h]
  bool v34; // [rsp+31h] [rbp-4Fh]
  bool v35; // [rsp+32h] [rbp-4Eh]
  char v36; // [rsp+33h] [rbp-4Dh] BYREF
  char m_storage; // [rsp+34h] [rbp-4Ch] BYREF
  int v38; // [rsp+38h] [rbp-48h]
  hkArrayBase<int> array; // [rsp+40h] [rbp-40h] BYREF
  hkArray<hkRadixSort::SortData32,hkContainerDebugAllocator> sortArray; // [rsp+50h] [rbp-30h] BYREF
  hkResult result; // [rsp+60h] [rbp-20h] BYREF
  __int64 v42; // [rsp+68h] [rbp-18h]

  v4 = collection;
  shouldDrawFaces = hkaiNavMeshDebugUtils::DebugInfo::shouldDrawFaces(settings);
  shouldDrawEdges = hkaiNavMeshDebugUtils::DebugInfo::shouldDrawEdges(settings);
  v34 = shouldDrawEdges;
  shouldDrawUserEdges = hkaiNavMeshDebugUtils::DebugInfo::shouldDrawUserEdges(settings);
  v35 = shouldDrawUserEdges;
  if ( __PAIR16__(shouldDrawEdges, shouldDrawFaces) || shouldDrawUserEdges )
  {
    v8 = 0i64;
    v9 = 0;
    v38 = 0;
    if ( v4->m_instances.m_size > 0 )
    {
      v10 = 0i64;
      v42 = 0i64;
      do
      {
        if ( v9 >= settings->m_instanceEnabled.m_storage.m_numBits
          || ((settings->m_instanceEnabled.m_storage.m_words.m_data[(__int64)v9 >> 5] >> (v9 & 0x1F)) & 1) != 0 )
        {
          v11 = *(hkaiNavMeshInstance **)((char *)&v4->m_instances.m_data->m_instancePtr + v10);
          if ( v11 )
          {
            Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
            v13 = (_QWORD *)Value[1];
            if ( (unsigned __int64)v13 < Value[3] )
            {
              *v13 = "TtshowStreamingCollection";
              v14 = __rdtsc();
              v15 = v13 + 2;
              *((_DWORD *)v15 - 2) = v14;
              Value[1] = v15;
            }
            m_regionMap = settings->m_regionMap;
            sortArray.m_data = 0i64;
            sortArray.m_size = 0;
            sortArray.m_capacityAndFlags = 0x80000000;
            array.m_data = 0i64;
            array.m_size = 0;
            array.m_capacityAndFlags = 0x80000000;
            if ( !m_regionMap || m_regionMap->m_size != v11->m_numOriginalFaces + v11->m_ownedFaces.m_size )
            {
              if ( settings->m_colorRegions.m_bool
                || settings->m_showSingleRegionIndex != -1
                || settings->m_highlightSingleRegionIndex != -1 )
              {
                v17 = v11->m_numOriginalFaces + v11->m_ownedFaces.m_size;
                if ( v17 <= 0 )
                  result.m_enum = HK_SUCCESS;
                else
                  hkArrayUtil::_reserve(
                    &result,
                    &hkContainerHeapAllocator::s_alloc,
                    &array,
                    v11->m_numOriginalFaces + v11->m_ownedFaces.m_size,
                    4);
                array.m_size = v17;
                hkaiNavMeshUtils::computeRegions(v11, 0, &array, 0i64);
              }
              m_regionMap = (hkArray<int,hkContainerHeapAllocator> *)&array;
            }
            if ( settings->m_sortTransparentFaces.m_bool )
              hkaiNavMeshDebugUtils::_sortTransparentFaces(v11, settings, &sortArray);
            m_size = v11->m_ownedFaces.m_size;
            m_numOriginalFaces = v11->m_numOriginalFaces;
            v20 = 0;
            if ( m_numOriginalFaces + m_size > 0 )
            {
              do
              {
                if ( settings->m_sortTransparentFaces.m_bool )
                  m_userData = sortArray.m_data[m_size + (__int64)m_numOriginalFaces - v8 - 1].m_userData;
                else
                  m_userData = v20;
                if ( v11->m_faceFlags.m_size )
                {
                  v22 = &m_storage;
                  m_storage = v11->m_faceFlags.m_data[m_userData].m_storage;
                }
                else
                {
                  v36 = 0;
                  v22 = &v36;
                }
                m_showSingleRegionIndex = settings->m_showSingleRegionIndex;
                if ( (m_showSingleRegionIndex == -1 || m_regionMap->m_data[m_userData] == m_showSingleRegionIndex)
                  && ((*v22 & 1) == 0 || settings->m_showHiddenFaces.m_bool) )
                {
                  if ( !shouldDrawFaces && !v34 )
                    goto LABEL_39;
                  UnlitFaceColor = hkaiNavMeshDebugUtils::_getUnlitFaceColor(v11, settings, m_regionMap, m_userData);
                  v25 = UnlitFaceColor;
                  if ( shouldDrawFaces )
                    hkaiNavMeshDebugUtils::_showFace(displayHandler, tag, v11, settings, m_userData, UnlitFaceColor);
                  if ( v34 )
                  {
                    faceColor = v25;
                    v26 = tag;
                    hkaiNavMeshDebugUtils::_showEdgesForFace(displayHandler, tag, v11, settings, m_userData, faceColor);
                  }
                  else
                  {
LABEL_39:
                    v26 = tag;
                  }
                  if ( v35 )
                    hkaiNavMeshDebugUtils::_showUserEdgesForFace(
                      displayHandler,
                      v26,
                      collection,
                      v11,
                      settings,
                      m_userData);
                }
                m_size = v11->m_ownedFaces.m_size;
                m_numOriginalFaces = v11->m_numOriginalFaces;
                ++v20;
                ++v8;
              }
              while ( v20 < m_numOriginalFaces + m_size );
              v9 = v38;
            }
            v8 = 0i64;
            array.m_size = 0;
            if ( array.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                array.m_data,
                4 * array.m_capacityAndFlags);
            array.m_data = 0i64;
            array.m_capacityAndFlags = 0x80000000;
            sortArray.m_size = 0;
            if ( sortArray.m_capacityAndFlags >= 0 )
              hkContainerDebugAllocator::s_alloc.vfptr->bufFree(
                &hkContainerDebugAllocator::s_alloc,
                sortArray.m_data,
                8 * sortArray.m_capacityAndFlags);
            sortArray.m_data = 0i64;
            sortArray.m_capacityAndFlags = 0x80000000;
            v27 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
            v4 = collection;
            v28 = (_QWORD *)v27[1];
            v29 = v27;
            if ( (unsigned __int64)v28 < v27[3] )
            {
              *v28 = "Et";
              v30 = __rdtsc();
              v31 = v28 + 2;
              *((_DWORD *)v31 - 2) = v30;
              v29[1] = v31;
            }
          }
        }
        v42 += 48i64;
        ++v9;
        v10 = v42;
        v38 = v9;
      }
      while ( v9 < v4->m_instances.m_size );
    }
  }
}

// File Line: 698
// RVA: 0xC4B8F0
// local variable allocation has failed, the output may be wrong!
void __fastcall cubicHermite(
        double t,
        hkVector4f *p0,
        hkVector4f *p1,
        hkVector4f *n0,
        hkVector4f *n1,
        hkVector4f *pOut)
{
  float v6; // xmm4_4
  __m128 v7; // xmm7
  __m128 v8; // xmm6
  __m128 v9; // xmm0
  __m128 v10; // xmm3
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  __m128 v15; // xmm1

  v6 = *(float *)&t;
  v7 = *(__m128 *)&t;
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
  v13 = _mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), p0->m_quad);
  *pOut = (hkVector4f)v13;
  v14 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), n0->m_quad), v13);
  *pOut = (hkVector4f)v14;
  v15 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), p1->m_quad), v14);
  *pOut = (hkVector4f)v15;
  pOut->m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), n1->m_quad), v15);
}

// File Line: 714
// RVA: 0xC4B9B0
void __fastcall getEdgeArcPoints(
        hkVector4f *start,
        hkVector4f *end,
        hkVector4f *inNormal,
        hkVector4f *outNormal,
        hkArray<hkVector4f,hkContainerHeapAllocator> *pointsOut)
{
  __m128 v7; // xmm1
  __m128 v8; // xmm1
  int v9; // eax
  __m128 v10; // xmm4
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __m128 v13; // xmm5
  double v14; // xmm6_8
  __int64 v15; // rdi
  int v16; // r10d
  hkVector4f n1; // [rsp+30h] [rbp-58h] BYREF
  hkVector4f n0; // [rsp+40h] [rbp-48h] BYREF
  hkVector4f pOut; // [rsp+50h] [rbp-38h] BYREF

  v7 = _mm_sub_ps(start->m_quad, end->m_quad);
  v8 = _mm_mul_ps(v7, v7);
  v9 = pointsOut->m_capacityAndFlags & 0x3FFFFFFF;
  v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v11 = _mm_rsqrt_ps(v10);
  v12 = _mm_andnot_ps(
          _mm_cmple_ps(v10, (__m128)0i64),
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
  *(_QWORD *)&v14 = LODWORD(FLOAT_0_1);
  if ( pointsOut->m_size == v9 )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, pointsOut, 16);
  v15 = 10i64;
  pointsOut->m_data[pointsOut->m_size++] = (hkVector4f)start->m_quad;
  do
  {
    cubicHermite(v14, start, end, &n0, &n1, &pOut);
    if ( v16 == (pointsOut->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, pointsOut, 16);
    *(float *)&v14 = *(float *)&v14 + 0.1;
    pointsOut->m_data[pointsOut->m_size++] = (hkVector4f)pOut.m_quad;
    --v15;
  }
  while ( v15 );
}

// File Line: 736
// RVA: 0xC48850
void __fastcall hkaiNavMeshDebugUtils::_showUserEdgeArc(
        bool curEnabled,
        bool oppEnabled,
        hkVector4f *curStart,
        hkVector4f *curEnd,
        hkVector4f *oppStart,
        hkVector4f *oppEnd,
        hkVector4f *curNormal,
        hkVector4f *oppNormal,
        unsigned int color,
        hkaiNavMeshDebugUtils::DebugInfo *settings,
        hkDebugDisplayHandler *displayHandler,
        int tag)
{
  hkDisplayGeometry *UserEdgeArc; // rbx
  hkArrayBase<hkDisplayGeometry *> geometries; // [rsp+40h] [rbp-28h] BYREF
  hkDisplayGeometry *v14; // [rsp+50h] [rbp-18h] BYREF

  UserEdgeArc = hkaiNavMeshDebugUtils::makeUserEdgeArc(
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
  geometries.m_data = &v14;
  v14 = UserEdgeArc;
  if ( displayHandler )
    displayHandler->vfptr->displayGeometry(
      displayHandler,
      (hkResult *)&displayHandler,
      &geometries,
      color & 0xFFFFFF | (color >> 1) & 0x7F000000,
      0,
      tag);
  else
    hkDebugDisplay::displayGeometry(
      hkSingleton<hkDebugDisplay>::s_instance,
      &geometries,
      color & 0xFFFFFF | (color >> 1) & 0x7F000000,
      0,
      (int)hkDebugDisplayProcess::m_tag);
  hkReferencedObject::removeReference(UserEdgeArc);
  geometries.m_size = 0;
  if ( geometries.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      geometries.m_data,
      8 * geometries.m_capacityAndFlags);
}

// File Line: 758
// RVA: 0xC48990
hkArray<hkVector4f,hkContainerHeapAllocator> *__fastcall hkaiNavMeshDebugUtils::makeUserEdgeArc(
        bool curEnabled,
        bool oppEnabled,
        hkVector4f *curStart,
        hkVector4f *curEnd,
        hkVector4f *oppStart,
        hkVector4f *oppEnd,
        hkVector4f *curNormal,
        hkVector4f *oppNormal)
{
  hkVector4f *v8; // rbx
  _QWORD **Value; // rax
  hkDisplayWireframe *v12; // rax
  int v13; // r15d
  __int64 m_size; // r12
  hkArray<hkVector4f,hkContainerHeapAllocator> *v15; // rdi
  __int64 v16; // rsi
  hkArray<hkVector4f,hkContainerHeapAllocator> *v17; // rbx
  __m128 v18; // xmm6
  hkVector4f *v19; // rdi
  hkVector4f *v20; // rdi
  hkVector4f *v21; // rdi
  hkVector4f *v22; // rdi
  hkVector4f v23; // xmm0
  int v24; // eax
  hkVector4f *m_data; // r14
  hkVector4f *v26; // r14
  hkVector4f *v27; // r14
  hkVector4f *v28; // r14
  __m128 v29; // xmm8
  __m128 v30; // xmm9
  __m128 v31; // xmm6
  __m128 v32; // xmm7
  int m_capacityAndFlags; // eax
  int v34; // eax
  int v35; // eax
  int v36; // eax
  hkArray<hkVector4f,hkContainerHeapAllocator> *pointsOut; // [rsp+20h] [rbp-69h]
  __int64 v39; // [rsp+28h] [rbp-61h]
  hkArray<hkVector4f,hkContainerHeapAllocator> v40; // [rsp+30h] [rbp-59h] BYREF
  hkArray<hkVector4f,hkContainerHeapAllocator> v41; // [rsp+40h] [rbp-49h] BYREF
  char vars0; // [rsp+D0h] [rbp+47h]
  void *retaddr; // [rsp+D8h] [rbp+4Fh]
  hkVector4f *end; // [rsp+F8h] [rbp+6Fh]

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (hkDisplayWireframe *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 128i64);
  v13 = 0;
  if ( v12 )
    hkDisplayWireframe::hkDisplayWireframe(v12);
  v41.m_data = 0i64;
  v41.m_size = 0;
  v41.m_capacityAndFlags = 0x80000000;
  v40.m_data = 0i64;
  v40.m_size = 0;
  v40.m_capacityAndFlags = 0x80000000;
  getEdgeArcPoints(curStart, end, oppStart, oppEnd, &v41);
  getEdgeArcPoints(curEnd, v8, oppStart, oppEnd, &v40);
  m_size = v41.m_size;
  v15 = pointsOut;
  v16 = 0i64;
  v17 = pointsOut + 7;
  v39 = v41.m_size - 1;
  if ( v39 > 0 )
  {
    while ( v16 || !(_BYTE)retaddr )
    {
      if ( v13 == (_DWORD)m_size - 2 && vars0 )
      {
        v18 = _mm_add_ps(
                _mm_mul_ps(_mm_sub_ps(v40.m_data[m_size - 1].m_quad, v41.m_data[m_size - 1].m_quad), *(__m128 *)_xmm),
                v41.m_data[m_size - 1].m_quad);
        if ( pointsOut[7].m_size == (pointsOut[7].m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v17, 16);
        pointsOut[7].m_data[pointsOut[7].m_size++].m_quad = v18;
        m_data = v41.m_data;
        if ( pointsOut[7].m_size == (pointsOut[7].m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v17, 16);
        pointsOut[7].m_data[pointsOut[7].m_size++] = m_data[m_size - 2];
        v26 = v41.m_data;
        if ( pointsOut[7].m_size == (pointsOut[7].m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v17, 16);
        pointsOut[7].m_data[pointsOut[7].m_size++] = v26[m_size - 2];
        v27 = v40.m_data;
        if ( pointsOut[7].m_size == (pointsOut[7].m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v17, 16);
        pointsOut[7].m_data[pointsOut[7].m_size++] = v27[m_size - 2];
        v28 = v40.m_data;
        if ( pointsOut[7].m_size == (pointsOut[7].m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v17, 16);
        v23.m_quad = (__m128)v28[m_size - 2];
        goto LABEL_17;
      }
      v29 = _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(v40.m_data[v16 + 1].m_quad, v41.m_data[v16 + 1].m_quad), (__m128)_xmm),
              v41.m_data[v16 + 1].m_quad);
      v30 = _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(v41.m_data[v16 + 1].m_quad, v40.m_data[v16 + 1].m_quad), (__m128)_xmm),
              v40.m_data[v16 + 1].m_quad);
      v31 = _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(v40.m_data[v16].m_quad, v41.m_data[v16].m_quad), (__m128)_xmm),
              v41.m_data[v16].m_quad);
      v32 = _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(v41.m_data[v16].m_quad, v40.m_data[v16].m_quad), (__m128)_xmm),
              v40.m_data[v16].m_quad);
      if ( pointsOut[7].m_size == (pointsOut[7].m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v17, 16);
      pointsOut[7].m_data[pointsOut[7].m_size].m_quad = v31;
      m_capacityAndFlags = pointsOut[7].m_capacityAndFlags;
      if ( ++pointsOut[7].m_size == (m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v17, 16);
      pointsOut[7].m_data[pointsOut[7].m_size].m_quad = v29;
      v34 = pointsOut[7].m_capacityAndFlags;
      if ( ++pointsOut[7].m_size == (v34 & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v17, 16);
      pointsOut[7].m_data[pointsOut[7].m_size].m_quad = v32;
      v35 = pointsOut[7].m_capacityAndFlags;
      if ( ++pointsOut[7].m_size == (v35 & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v17, 16);
      pointsOut[7].m_data[pointsOut[7].m_size++].m_quad = v30;
      if ( v16 <= 0 )
        goto LABEL_48;
      if ( pointsOut[7].m_size == (pointsOut[7].m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v17, 16);
      pointsOut[7].m_data[pointsOut[7].m_size].m_quad = v31;
      v36 = pointsOut[7].m_capacityAndFlags;
      if ( ++pointsOut[7].m_size == (v36 & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v17, 16);
      pointsOut[7].m_data[pointsOut[7].m_size].m_quad = v32;
LABEL_47:
      ++pointsOut[7].m_size;
LABEL_48:
      ++v16;
      ++v13;
      if ( v16 >= v39 )
      {
        v15 = pointsOut;
        goto LABEL_50;
      }
    }
    v18 = _mm_add_ps(
            _mm_mul_ps(_mm_sub_ps(v40.m_data->m_quad, v41.m_data->m_quad), *(__m128 *)_xmm),
            v41.m_data->m_quad);
    if ( pointsOut[7].m_size == (pointsOut[7].m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v17, 16);
    pointsOut[7].m_data[pointsOut[7].m_size++].m_quad = v18;
    v19 = v41.m_data;
    if ( pointsOut[7].m_size == (pointsOut[7].m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v17, 16);
    pointsOut[7].m_data[pointsOut[7].m_size++] = (hkVector4f)v19[1].m_quad;
    v20 = v41.m_data;
    if ( pointsOut[7].m_size == (pointsOut[7].m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v17, 16);
    pointsOut[7].m_data[pointsOut[7].m_size++] = (hkVector4f)v20[1].m_quad;
    v21 = v40.m_data;
    if ( pointsOut[7].m_size == (pointsOut[7].m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v17, 16);
    pointsOut[7].m_data[pointsOut[7].m_size++] = (hkVector4f)v21[1].m_quad;
    v22 = v40.m_data;
    if ( pointsOut[7].m_size == (pointsOut[7].m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v17, 16);
    v23.m_quad = (__m128)v22[1];
LABEL_17:
    pointsOut[7].m_data[pointsOut[7].m_size] = (hkVector4f)v23.m_quad;
    v24 = pointsOut[7].m_capacityAndFlags;
    if ( ++pointsOut[7].m_size == (v24 & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v17, 16);
    pointsOut[7].m_data[pointsOut[7].m_size].m_quad = v18;
    goto LABEL_47;
  }
LABEL_50:
  v40.m_size = 0;
  if ( v40.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v40.m_data,
      16 * v40.m_capacityAndFlags);
  v40.m_data = 0i64;
  v41.m_size = 0;
  v40.m_capacityAndFlags = 0x80000000;
  if ( v41.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v41.m_data,
      16 * v41.m_capacityAndFlags);
  return v15;
}

// File Line: 821
// RVA: 0xC48350
void __fastcall hkaiNavMeshDebugUtils::_showUserEdgePair(
        hkaiStreamingCollection *collection,
        hkaiNavMeshDebugUtils::DebugInfo *settings,
        unsigned int faceKey,
        int uedgeKey,
        hkDebugDisplayHandler *displayHandler,
        int tag)
{
  hkDebugDisplayHandler *v6; // rbx
  hkaiStreamingCollection::InstanceInfo *m_data; // rax
  unsigned int index; // ebx
  hkaiNavMeshInstance *m_instancePtr; // rdi
  int m_numOriginalEdges; // r14d
  hkaiNavMesh::Edge *v12; // r15
  int v13; // esi
  hkVector4f v14; // xmm6
  bool v15; // zf
  char *m_storage; // rdx
  int v17; // r12d
  unsigned int m_oppositeEdge; // ecx
  int m_runtimeId; // eax
  unsigned int color; // r14d
  unsigned int v21; // ecx
  unsigned int v22; // eax
  unsigned int v23; // esi
  unsigned int v24; // eax
  hkaiNavMeshInstance *v25; // rsi
  hkaiNavMesh::Edge *v26; // r12
  BOOL v27; // esi
  BOOL v28; // r12d
  hkVector4f pos; // [rsp+60h] [rbp-90h] BYREF
  hkVector4f edgeB; // [rsp+70h] [rbp-80h] BYREF
  hkVector4f edgeA; // [rsp+80h] [rbp-70h] BYREF
  hkaiNavMeshInstance *v32; // [rsp+90h] [rbp-60h]
  hkVector4f end; // [rsp+A0h] [rbp-50h] BYREF
  char v34; // [rsp+B0h] [rbp-40h] BYREF
  hkVector4f oppNormal; // [rsp+C0h] [rbp-30h] BYREF
  hkaiNavMeshUtils v36[16]; // [rsp+D0h] [rbp-20h] BYREF
  __m128 faceIndex; // [rsp+E0h] [rbp-10h] BYREF
  hkStringBuf v38; // [rsp+F0h] [rbp+0h] BYREF
  __int64 vars0; // [rsp+1D0h] [rbp+E0h]
  void *retaddr; // [rsp+1D8h] [rbp+E8h] BYREF
  unsigned int v41; // [rsp+1E8h] [rbp+F8h]
  hkDebugDisplayHandler *v42; // [rsp+1F0h] [rbp+100h]

  if ( settings->m_showUserEdges.m_bool )
  {
    v42 = v6;
    m_data = collection->m_instances.m_data;
    index = uedgeKey & 0x3FFFFF;
    edgeB.m_quad.m128_i32[0] = faceKey & 0x3FFFFF;
    m_instancePtr = m_data[faceKey >> 22].m_instancePtr;
    m_numOriginalEdges = m_instancePtr->m_numOriginalEdges;
    v12 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__23(
            m_instancePtr->m_originalEdges,
            m_numOriginalEdges,
            &m_instancePtr->m_instancedEdges,
            &m_instancePtr->m_ownedEdges,
            &m_instancePtr->m_edgeMap,
            uedgeKey & 0x3FFFFF);
    v13 = m_instancePtr->m_edgeDataStriding
        ? *hkaiNavMeshInstance_getWithStriding_int__4(
             m_instancePtr->m_originalEdgeData,
             m_numOriginalEdges,
             &m_instancePtr->m_instancedEdgeData,
             &m_instancePtr->m_ownedEdgeData,
             &m_instancePtr->m_edgeMap,
             index,
             m_instancePtr->m_edgeDataStriding)
        : 0;
    if ( v12->m_oppositeEdge != -1 )
    {
      v14.m_quad = (__m128)settings->m_displayOffset;
      hkaiNavMeshInstance::getEdgePoints(m_instancePtr, index, &edgeA, &edgeB);
      v15 = settings->m_labelEdges.m_bool == 0;
      m_storage = v38.m_string.m_storage;
      v38.m_string.m_data = v38.m_string.m_storage;
      v38.m_string.m_capacityAndFlags = -2147483520;
      v38.m_string.m_size = 1;
      v38.m_string.m_storage[0] = 0;
      edgeB.m_quad = _mm_add_ps(edgeB.m_quad, v14.m_quad);
      edgeA.m_quad = _mm_add_ps(edgeA.m_quad, v14.m_quad);
      pos.m_quad = _mm_add_ps(
                     _mm_mul_ps(_mm_sub_ps(edgeB.m_quad, edgeA.m_quad), (__m128)xmmword_141A711B0),
                     edgeA.m_quad);
      if ( !v15 )
      {
        hkStringBuf::printf(&v38, "%d ", index);
        m_storage = v38.m_string.m_data;
      }
      if ( v42 )
      {
        v17 = uedgeKey;
        v42->vfptr->display3dText(v42, (hkResult *)&retaddr, m_storage, &pos, settings->m_edgeLabelColor, 0, uedgeKey);
      }
      else
      {
        hkDebugDisplay::display3dText(
          hkSingleton<hkDebugDisplay>::s_instance,
          m_storage,
          &pos,
          settings->m_edgeLabelColor,
          0,
          (int)hkDebugDisplayProcess::m_tag);
        v17 = uedgeKey;
      }
      v38.m_string.m_size = 0;
      if ( v38.m_string.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          v38.m_string.m_data,
          v38.m_string.m_capacityAndFlags & 0x3FFFFFFF);
      m_oppositeEdge = v12->m_oppositeEdge;
      if ( (v12->m_flags.m_storage & 0x40) != 0 )
        m_runtimeId = m_oppositeEdge >> 22;
      else
        m_runtimeId = m_instancePtr->m_runtimeId;
      if ( m_oppositeEdge == -1 )
        m_runtimeId = -1;
      v32 = *(hkaiNavMeshInstance **)(*(_QWORD *)(vars0 + 32) + 48i64 * m_runtimeId);
      LOBYTE(retaddr) = v32 != 0i64;
      if ( settings->m_colorUserEdgesByData.m_bool )
        color = hkColor::getPaletteColor(v13, 127);
      else
        color = settings->m_userEdgeColor;
      v21 = v12->m_oppositeEdge;
      if ( (v12->m_flags.m_storage & 0x40) != 0 )
        v22 = v21 & 0xFFC00000;
      else
        v22 = m_instancePtr->m_runtimeId << 22;
      v23 = v22 | v21 & 0x3FFFFF;
      if ( v21 == -1 )
        v23 = -1;
      if ( !(_BYTE)retaddr || (v24 = v41, v41 < v23) )
      {
        if ( v42 )
          v42->vfptr->displayLine(v42, (hkResult *)&v34, &edgeA, &edgeB, color, 0, v17);
        else
          hkDebugDisplay::displayLine(
            hkSingleton<hkDebugDisplay>::s_instance,
            &edgeA,
            &edgeB,
            color,
            0,
            (int)hkDebugDisplayProcess::m_tag);
        v24 = v41;
      }
      if ( (_BYTE)retaddr && v24 < v23 )
      {
        v25 = v32;
        v26 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__23(
                v32->m_originalEdges,
                v32->m_numOriginalEdges,
                &v32->m_instancedEdges,
                &v32->m_ownedEdges,
                &v32->m_edgeMap,
                v12->m_oppositeEdge & 0x3FFFFF);
        hkaiNavMeshInstance::getEdgePoints(v25, v26, &pos, &end);
        v15 = v12->m_oppositeEdge == -1;
        pos.m_quad = _mm_add_ps(pos.m_quad, v14.m_quad);
        end.m_quad = _mm_add_ps(end.m_quad, v14.m_quad);
        v27 = !v15 && (v12->m_flags.m_storage & 0x20) == 0;
        v28 = v26->m_oppositeEdge != -1 && (v26->m_flags.m_storage & 0x20) == 0;
        if ( v42 )
          v42->vfptr->displayLine(v42, (hkResult *)&retaddr, &pos, &end, color, 0, uedgeKey);
        else
          hkDebugDisplay::displayLine(
            hkSingleton<hkDebugDisplay>::s_instance,
            &pos,
            &end,
            color,
            0,
            (int)hkDebugDisplayProcess::m_tag);
        hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
          v36,
          (hkSimdFloat32 *)m_instancePtr,
          (hkaiNavMeshInstance *)edgeB.m_quad.m128_u32[0],
          &faceIndex);
        hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
          v36,
          (hkSimdFloat32 *)v32,
          (hkaiNavMeshInstance *)(v12->m_oppositeFace & 0x3FFFFF),
          &oppNormal.m_quad);
        if ( v27 || v28 )
          hkaiNavMeshDebugUtils::_showUserEdgeArc(
            v27,
            v28,
            &edgeA,
            &edgeB,
            &pos,
            &end,
            (hkVector4f *)&faceIndex,
            &oppNormal,
            color,
            settings,
            v42,
            uedgeKey);
      }
    }
  }
}

// File Line: 906
// RVA: 0xC48FE0
float __fastcall hkaiNavMeshDebugUtils::_calcNonplanarity(hkSimdFloat32 *nmi, unsigned int faceIdx)
{
  float v2; // xmm6_4
  float v3; // xmm7_4
  int v6; // edx
  hkaiNavMesh::Face *v7; // rcx
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm2
  __m128 v11; // xmm12
  hkaiNavMesh::Face *v12; // rax
  hkaiNavMesh::Face *v13; // rsi
  __int16 m_numUserEdges; // r15
  int m_startEdgeIndex; // ebx
  int m_startUserEdgeIndex; // ebp
  int v17; // r13d
  hkVector4f v18; // xmm8
  int v19; // r14d
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v20; // r9
  hkVector4f v21; // xmm9
  hkVector4f v22; // xmm10
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v23; // r8
  hkVector4f v24; // xmm11
  __int64 m_a; // rcx
  hkVector4f *v26; // rax
  __m128 v27; // xmm2
  float v28; // xmm1_4
  int faceIndex[4]; // [rsp+30h] [rbp-C8h] BYREF
  hkaiNavMeshUtils v31; // [rsp+40h] [rbp-B8h] BYREF

  v2 = FLOAT_N3_40282e38;
  v3 = FLOAT_3_40282e38;
  hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(&v31, nmi, (hkaiNavMeshInstance *)faceIdx, (__m128 *)faceIndex);
  v6 = nmi[1].m_real.m128_i32[2];
  v7 = (hkaiNavMesh::Face *)nmi[1].m_real.m128_u64[0];
  v8 = _mm_mul_ps(*(__m128 *)faceIndex, *(__m128 *)faceIndex);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_rsqrt_ps(v9);
  v11 = _mm_mul_ps(
          *(__m128 *)faceIndex,
          _mm_andnot_ps(
            _mm_cmple_ps(v9, (__m128)0i64),
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)), _mm_mul_ps(*(__m128 *)_xmm, v10))));
  *(__m128 *)faceIndex = v11;
  v12 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__21(
          v7,
          v6,
          (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&nmi[15],
          (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&nmi[17],
          (hkArray<int,hkContainerHeapAllocator> *)&nmi[14],
          faceIdx);
  v13 = v12;
  m_numUserEdges = v12->m_numUserEdges;
  if ( m_numUserEdges <= 0 )
    m_startEdgeIndex = v12->m_startEdgeIndex;
  else
    m_startEdgeIndex = v12->m_startUserEdgeIndex;
  if ( m_startEdgeIndex != -1 )
  {
    m_startUserEdgeIndex = v12->m_startUserEdgeIndex;
    v17 = nmi[2].m_real.m128_i32[2];
    v18.m_quad = (__m128)nmi[8];
    v19 = nmi[3].m_real.m128_i32[2];
    v20 = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&nmi[18];
    v21.m_quad = (__m128)nmi[7];
    v22.m_quad = (__m128)nmi[9];
    v23 = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&nmi[16];
    v24.m_quad = (__m128)nmi[10];
    while ( 1 )
    {
      m_a = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__23(
              (hkaiNavMesh::Edge *)nmi[2].m_real.m128_u64[0],
              v17,
              v23,
              v20,
              (hkArray<int,hkContainerHeapAllocator> *)&nmi[13],
              m_startEdgeIndex)->m_a;
      if ( (int)m_a >= v19 )
        v26 = (hkVector4f *)(nmi[19].m_real.m128_u64[0] + 16i64 * ((int)m_a - v19));
      else
        v26 = (hkVector4f *)(nmi[3].m_real.m128_u64[0] + 16 * m_a);
      v27 = _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v26->m_quad, v26->m_quad, 0), v21.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v26->m_quad, v26->m_quad, 85), v18.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v26->m_quad, v26->m_quad, 170), v22.m_quad)),
                v24.m_quad),
              v11);
      v28 = (float)(_mm_shuffle_ps(v27, v27, 85).m128_f32[0] + _mm_shuffle_ps(v27, v27, 0).m128_f32[0])
          + _mm_shuffle_ps(v27, v27, 170).m128_f32[0];
      v3 = fminf(v3, v28);
      v2 = fmaxf(v2, v28);
      if ( m_startEdgeIndex >= m_startUserEdgeIndex && m_startEdgeIndex < m_numUserEdges + m_startUserEdgeIndex - 1 )
        goto LABEL_15;
      if ( m_startEdgeIndex != m_numUserEdges + m_startUserEdgeIndex - 1 )
        break;
      m_startEdgeIndex = v13->m_startEdgeIndex;
LABEL_16:
      if ( m_startEdgeIndex == -1 )
        return v2 - v3;
    }
    if ( m_startEdgeIndex < v13->m_startEdgeIndex || m_startEdgeIndex >= v13->m_numEdges + v13->m_startEdgeIndex - 1 )
      return v2 - v3;
LABEL_15:
    ++m_startEdgeIndex;
    goto LABEL_16;
  }
  return v2 - v3;
}

// File Line: 931
// RVA: 0xC48140
void __fastcall hkaiNavMeshDebugUtils::reportMemoryUsed(hkaiNavMesh *mesh)
{
  int m_size; // edx
  hkaiNavMesh *v2; // rbx
  int v3; // r15d
  int v4; // r12d
  int v5; // r13d
  int v6; // esi
  int v7; // edi
  int v8; // r14d
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
  hkErrStream v26; // [rsp+20h] [rbp-248h] BYREF
  char buf[512]; // [rsp+40h] [rbp-228h] BYREF

  m_size = mesh->m_edges.m_size;
  v2 = mesh;
  v3 = 16 * mesh->m_faces.m_size;
  v4 = 20 * m_size;
  v5 = 16 * mesh->m_vertices.m_size;
  v6 = 4 * mesh->m_faces.m_size * mesh->m_faceDataStriding;
  v7 = 4 * m_size * mesh->m_edgeDataStriding;
  ((void (__fastcall *)(hkError *, __int64, const char *))hkSingleton<hkError>::s_instance->vfptr[4].__first_virtual_table_function__)(
    hkSingleton<hkError>::s_instance,
    1367214621i64,
    "hkaiNavMeshDebugUtils::reportMemoryUsed");
  hkErrStream::hkErrStream(&v26, buf, 512);
  v8 = v2->m_vertices.m_size;
  v9 = v2->m_edges.m_size;
  LODWORD(v2) = v2->m_faces.m_size;
  v10 = v6 + v7;
  v11 = hkOstream::operator<<(&v26, "\nMemory:\n Faces ( ");
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
  hkError::messageReport(-1, buf, "Debug\\hkaiNavMeshDebugUtils.cpp", 945);
  hkOstream::~hkOstream(&v26);
  ((void (__fastcall *)(hkError *))hkSingleton<hkError>::s_instance->vfptr[5].__vecDelDtor)(hkSingleton<hkError>::s_instance);
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
void __fastcall hkaiNavMeshDebugUtils::_sortTransparentFaces(
        hkaiNavMeshUtils *nmi,
        hkaiNavMeshDebugUtils::DebugInfo *settings,
        hkArray<hkRadixSort::SortData32,hkContainerDebugAllocator> *sortArray,
        hkVector4f *a4)
{
  int v4; // eax
  int v5; // ebx
  int v9; // eax
  int v10; // r9d
  int v11; // edx
  __int64 v12; // rcx
  hkRadixSort::SortData32 *m_data; // rax
  hkRadixSort::SortData32 *v14; // rbp
  int v15; // r14d
  __int64 v16; // r15
  hkRadixSort::SortData32 *v17; // rdx
  __m128 v18; // xmm2
  __int32 v19; // eax
  int v20; // edi
  int faceIndex[4]; // [rsp+30h] [rbp-38h] BYREF
  hkResult v22; // [rsp+70h] [rbp+8h] BYREF

  v4 = sortArray->m_capacityAndFlags & 0x3FFFFFFF;
  v5 = (*(_DWORD *)&nmi[24] + *(_DWORD *)&nmi[280] + 3) & 0xFFFFFFFC;
  if ( v4 < v5 )
  {
    v9 = 2 * v4;
    v10 = (*(_DWORD *)&nmi[24] + *(_DWORD *)&nmi[280] + 3) & 0xFFFFFFFC;
    if ( v5 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&v22, &hkContainerDebugAllocator::s_alloc, sortArray, v10, 8);
  }
  sortArray->m_size = v5;
  v11 = *(_DWORD *)&nmi[280] + *(_DWORD *)&nmi[24];
  v12 = v11;
  if ( v11 < (__int64)v5 )
  {
    do
    {
      m_data = sortArray->m_data;
      m_data[v12++].m_userData = v11;
      m_data[v12 - 1].m_key = 0x7FFFFFFF;
      ++v11;
    }
    while ( v12 < v5 );
  }
  v14 = 0i64;
  v15 = 0;
  if ( *(_DWORD *)&nmi[280] + *(_DWORD *)&nmi[24] > 0 )
  {
    v16 = 0i64;
    do
    {
      hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
        nmi,
        (hkaiNavMeshInstance *)(unsigned int)v15,
        (__m128 *)faceIndex,
        a4);
      v17 = sortArray->m_data;
      ++v16;
      *(__m128 *)faceIndex = _mm_add_ps(*(__m128 *)faceIndex, settings->m_displayOffset.m_quad);
      v17[v16 - 1].m_userData = v15++;
      v18 = _mm_mul_ps(*(__m128 *)faceIndex, settings->m_sortDirection.m_quad);
      *(float *)&v22.m_enum = (float)(_mm_shuffle_ps(v18, v18, 85).m128_f32[0] + _mm_shuffle_ps(v18, v18, 0).m128_f32[0])
                            + _mm_shuffle_ps(v18, v18, 170).m128_f32[0];
      v17[v16 - 1].m_key = (v22.m_enum ^ ((v22.m_enum >> 31) | 0x80000001)) >> 1;
    }
    while ( v15 < *(_DWORD *)&nmi[280] + *(_DWORD *)&nmi[24] );
  }
  v19 = v5;
  if ( v5 )
  {
    v22.m_enum = 8 * v5;
    v14 = (hkRadixSort::SortData32 *)hkContainerDebugAllocator::s_alloc.vfptr->bufAlloc(
                                       &hkContainerDebugAllocator::s_alloc,
                                       &v22);
    v19 = v22.m_enum / 8;
  }
  v20 = 0x80000000;
  if ( v19 )
    v20 = v19;
  hkRadixSort::sort32(sortArray->m_data, v5, v14);
  if ( v20 >= 0 )
    hkContainerDebugAllocator::s_alloc.vfptr->bufFree(&hkContainerDebugAllocator::s_alloc, v14, 8 * v20);
}

// File Line: 990
// RVA: 0xC494B0
void __fastcall hkaiNavMeshDebugUtils::_showFace(
        hkDebugDisplayHandler *displayHandler,
        int tag,
        hkaiNavMeshInstance *nmi,
        hkaiNavMeshDebugUtils::DebugInfo *settings,
        int faceIdx,
        unsigned int faceColor)
{
  int m_numOriginalFaces; // r15d
  unsigned int v7; // r14d
  hkaiNavMesh::Face *v12; // rax
  hkArray<int,hkContainerHeapAllocator> *v13; // r11
  int striding; // ecx
  int *v15; // r15
  int v16; // r12d
  hkVector4f *v17; // r9
  bool v18; // zf
  __m128 v19; // xmm9
  unsigned int m_normalsColor; // r9d
  int v21; // r13d
  __m128 v22; // xmm0
  const char *v23; // rdx
  int m_faceDataStriding; // r8d
  float v25; // xmm6_4
  hkVector4f *v26; // r9
  char v27; // r15
  __m128 v28; // xmm2
  __m128 v29; // xmm2
  __int64 v30; // r12
  __m128 v31; // xmm7
  __int64 m_a; // rcx
  int m_numOriginalVertices; // eax
  hkVector4f *v34; // rax
  __m128 m_quad; // xmm1
  int v36; // eax
  unsigned int LitColor; // r15d
  hkVector4f *v38; // r9
  float v39; // xmm0_4
  __m128 v40; // xmm1
  float v41; // xmm2_4
  hkAabb *instanceMap; // [rsp+20h] [rbp-A8h]
  _BYTE faceOffset[24]; // [rsp+40h] [rbp-88h] BYREF
  hkaiNavMesh::Face *v44; // [rsp+58h] [rbp-70h]
  _BYTE end[40]; // [rsp+60h] [rbp-68h] BYREF
  char v46[4]; // [rsp+88h] [rbp-40h] BYREF
  char v47[4]; // [rsp+8Ch] [rbp-3Ch] BYREF
  char v48[8]; // [rsp+90h] [rbp-38h] BYREF
  hkSimdFloat32 extraRadius; // [rsp+98h] [rbp-30h] BYREF
  __m128 v50; // [rsp+A8h] [rbp-20h]
  hkStringBuf v51; // [rsp+B8h] [rbp-10h] BYREF
  hkStringBuf label; // [rsp+148h] [rbp+80h] BYREF
  int v53; // [rsp+280h] [rbp+1B8h]
  char m_storage; // [rsp+288h] [rbp+1C0h]
  char v55; // [rsp+290h] [rbp+1C8h]
  unsigned int index; // [rsp+298h] [rbp+1D0h]
  unsigned int vars0; // [rsp+2A0h] [rbp+1D8h]

  m_numOriginalFaces = nmi->m_numOriginalFaces;
  v7 = index;
  v12 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__21(
          nmi->m_originalFaces,
          m_numOriginalFaces,
          &nmi->m_instancedFaces,
          &nmi->m_ownedFaces,
          &nmi->m_faceMap,
          index);
  striding = nmi->m_faceDataStriding;
  v44 = v12;
  if ( striding )
    v15 = hkaiNavMeshInstance_getWithStriding_int__4(
            nmi->m_originalFaceData,
            m_numOriginalFaces,
            &nmi->m_instancedFaceData,
            &nmi->m_ownedFaceData,
            v13,
            index,
            striding);
  else
    v15 = 0i64;
  if ( nmi->m_faceFlags.m_size )
    m_storage = nmi->m_faceFlags.m_data[index].m_storage;
  else
    m_storage = 0;
  v16 = m_storage & 1;
  hkaiNavMeshDebugUtils::_calcFaceOffset(nmi, settings, index, (hkVector4f *)&faceOffset[8]);
  v18 = settings->m_showNormals.m_bool == 0;
  v19 = *(__m128 *)&faceOffset[8];
  *(_OWORD *)&end[16] = 0i64;
  *(_OWORD *)faceOffset = 0i64;
  v55 = 0;
  m_storage = 0;
  if ( !v18 )
  {
    hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
      (hkaiNavMeshUtils *)nmi,
      (hkaiNavMeshInstance *)v7,
      (__m128 *)faceOffset,
      v17);
    m_normalsColor = settings->m_normalsColor;
    m_storage = 1;
    *(__m128 *)faceOffset = _mm_add_ps(*(__m128 *)faceOffset, v19);
    if ( displayHandler )
      hkDebugDisplayHandler::displayArrow(
        displayHandler,
        (hkVector4f *)faceOffset,
        (hkVector4f *)&end[16],
        m_normalsColor,
        0,
        tag);
    else
      hkDebugDisplay::displayArrow(
        hkSingleton<hkDebugDisplay>::s_instance,
        (hkVector4f *)faceOffset,
        (hkVector4f *)&end[16],
        m_normalsColor,
        0,
        (int)hkDebugDisplayProcess::m_tag);
  }
  v21 = 1;
  v22 = _mm_cmple_ps(settings->m_pruneLabelsAabb.m_max.m_quad, settings->m_pruneLabelsAabb.m_min.m_quad);
  if ( (_mm_movemask_ps(v22) & 7) != 0
    || (*(_OWORD *)&faceOffset[8] = 0i64,
        hkaiNavMeshUtils::calcFaceAabb<hkaiNavMeshInstance>(
          (hkaiNavMeshUtils *)nmi,
          (hkaiNavMeshInstance *)v7,
          (__m128 *)&faceOffset[8],
          &extraRadius,
          instanceMap),
        v22 = _mm_cmple_ps(settings->m_pruneLabelsAabb.m_min.m_quad, v50),
        (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(extraRadius.m_real, settings->m_pruneLabelsAabb.m_max.m_quad), v22)) & 7) == 7) )
  {
    v18 = settings->m_labelFaces.m_bool == 0;
    v51.m_string.m_capacityAndFlags = -2147483520;
    v51.m_string.m_data = v51.m_string.m_storage;
    v51.m_string.m_size = 1;
    v51.m_string.m_storage[0] = 0;
    if ( !v18 )
    {
      v23 = "%d(%d)-H ";
      if ( !v16 )
        v23 = "%d(%d) ";
      hkStringBuf::printf(&v51, v23, v7, (unsigned int)v44->m_numEdges);
    }
    if ( settings->m_showFaceData.m_bool )
    {
      if ( v15 )
      {
        m_faceDataStriding = nmi->m_faceDataStriding;
        label.m_string.m_data = label.m_string.m_storage;
        label.m_string.m_capacityAndFlags = -2147483520;
        label.m_string.m_size = 1;
        label.m_string.m_storage[0] = 0;
        formatUserData(&label, v15, m_faceDataStriding);
        hkStringBuf::operator+=(&v51, label.m_string.m_data);
        label.m_string.m_size = 0;
        if ( label.m_string.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            label.m_string.m_data,
            label.m_string.m_capacityAndFlags & 0x3FFFFFFF);
      }
    }
    if ( v51.m_string.m_size - 1 > 0 )
    {
      if ( !m_storage )
      {
        hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
          (hkaiNavMeshUtils *)nmi,
          (hkaiNavMeshInstance *)v7,
          (__m128 *)faceOffset,
          v17);
        m_storage = 1;
        v22 = _mm_add_ps(*(__m128 *)faceOffset, v19);
        *(__m128 *)faceOffset = v22;
      }
      if ( displayHandler )
        displayHandler->vfptr->display3dText(
          displayHandler,
          (hkResult *)&faceOffset[16],
          v51.m_string.m_data,
          (hkVector4f *)faceOffset,
          settings->m_faceLabelColor,
          0,
          v53);
      else
        hkDebugDisplay::display3dText(
          hkSingleton<hkDebugDisplay>::s_instance,
          v51.m_string.m_data,
          (hkVector4f *)faceOffset,
          settings->m_faceLabelColor,
          0,
          (int)hkDebugDisplayProcess::m_tag);
    }
    v51.m_string.m_size = 0;
    if ( v51.m_string.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        v51.m_string.m_data,
        v51.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  }
  v25 = FLOAT_N1_0;
  if ( settings->m_nonplanarFacesSettings.m_drawNonplanarity.m_bool )
  {
    hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
      (hkaiNavMeshUtils *)&faceOffset[8],
      (hkSimdFloat32 *)nmi,
      (hkaiNavMeshInstance *)v7,
      (__m128 *)&end[16]);
    v27 = m_storage;
    v55 = 1;
    if ( !m_storage )
    {
      hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
        (hkaiNavMeshUtils *)nmi,
        (hkaiNavMeshInstance *)v7,
        (__m128 *)faceOffset,
        v26);
      m_storage = 1;
      v27 = 1;
      v22 = _mm_add_ps(*(__m128 *)faceOffset, v19);
      *(__m128 *)faceOffset = v22;
    }
    v22.m128_f32[0] = hkaiNavMeshDebugUtils::_calcNonplanarity((hkSimdFloat32 *)nmi, v7);
    v28 = v22;
    v25 = v22.m128_f32[0];
    v28.m128_f32[0] = v22.m128_f32[0] * settings->m_nonplanarFacesSettings.m_scaleMultiplier;
    *(__m128 *)end = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v28, v28, 0), *(__m128 *)&end[16]), *(__m128 *)faceOffset);
    if ( displayHandler )
      displayHandler->vfptr->displayLine(
        displayHandler,
        (hkResult *)&faceOffset[16],
        (hkVector4f *)faceOffset,
        (hkVector4f *)end,
        hkColor::BLUE,
        0,
        v53);
    else
      hkDebugDisplay::displayLine(
        hkSingleton<hkDebugDisplay>::s_instance,
        (hkVector4f *)faceOffset,
        (hkVector4f *)end,
        hkColor::BLUE,
        0,
        (int)hkDebugDisplayProcess::m_tag);
  }
  else
  {
    v27 = m_storage;
  }
  if ( settings->m_faceNormalSettings.m_drawFaceNormal.m_bool )
  {
    v29 = _mm_mul_ps(settings->m_faceNormalSettings.m_up.m_quad, *(__m128 *)&end[16]);
    if ( (float)((float)(_mm_shuffle_ps(v29, v29, 85).m128_f32[0] + _mm_shuffle_ps(v29, v29, 0).m128_f32[0])
               + _mm_shuffle_ps(v29, v29, 170).m128_f32[0]) < settings->m_faceNormalSettings.m_cosAngleThreshold )
    {
      if ( !v55 )
      {
        hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
          (hkaiNavMeshUtils *)&faceOffset[8],
          (hkSimdFloat32 *)nmi,
          (hkaiNavMeshInstance *)v7,
          (__m128 *)&end[16]);
        v55 = 1;
      }
      if ( !v27 )
      {
        hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
          (hkaiNavMeshUtils *)nmi,
          (hkaiNavMeshInstance *)v7,
          (__m128 *)faceOffset,
          v17);
        m_storage = 1;
        *(__m128 *)faceOffset = _mm_add_ps(*(__m128 *)faceOffset, v19);
      }
      *(__m128 *)end = _mm_add_ps(*(__m128 *)faceOffset, *(__m128 *)&end[16]);
      if ( displayHandler )
        displayHandler->vfptr->displayLine(
          displayHandler,
          (hkResult *)&faceOffset[16],
          (hkVector4f *)faceOffset,
          (hkVector4f *)end,
          hkColor::BLUE,
          0,
          v53);
      else
        hkDebugDisplay::displayLine(
          hkSingleton<hkDebugDisplay>::s_instance,
          (hkVector4f *)faceOffset,
          (hkVector4f *)end,
          hkColor::BLUE,
          0,
          (int)hkDebugDisplayProcess::m_tag);
    }
  }
  if ( settings->m_showFaces.m_bool || settings->m_showHiddenFaces.m_bool && v16 )
  {
    v30 = (__int64)v44;
    v31 = _mm_add_ps(settings->m_faceOffset.m_quad, v19);
    m_a = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__23(
            nmi->m_originalEdges,
            nmi->m_numOriginalEdges,
            &nmi->m_instancedEdges,
            &nmi->m_ownedEdges,
            &nmi->m_edgeMap,
            v44->m_startEdgeIndex)->m_a;
    m_numOriginalVertices = nmi->m_numOriginalVertices;
    v34 = (int)m_a >= m_numOriginalVertices
        ? &nmi->m_ownedVertices.m_data[(int)m_a - m_numOriginalVertices]
        : &nmi->m_originalVertices[m_a];
    m_quad = v34->m_quad;
    v36 = *(__int16 *)(v30 + 8) - 1;
    *(__m128 *)end = _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(
                               _mm_shuffle_ps(m_quad, m_quad, 85),
                               nmi->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad),
                             _mm_mul_ps(
                               _mm_shuffle_ps(m_quad, m_quad, 0),
                               nmi->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad)),
                           _mm_mul_ps(
                             _mm_shuffle_ps(m_quad, m_quad, 170),
                             nmi->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad)),
                         nmi->m_referenceFrame.m_transform.m_translation.m_quad),
                       v31);
    if ( v36 > 1 )
    {
      do
      {
        LitColor = vars0;
        hkaiNavMeshInstance::getEdgePoints(nmi, v21 + *(_DWORD *)v30, (hkVector4f *)&end[8], (hkVector4f *)&end[24]);
        v18 = settings->m_showFanEdges.m_bool == 0;
        *(__m128 *)&end[8] = _mm_add_ps(*(__m128 *)&end[8], v31);
        *(__m128 *)&end[24] = _mm_add_ps(*(__m128 *)&end[24], v31);
        if ( !v18 && v21 != 1 )
        {
          if ( displayHandler )
            displayHandler->vfptr->displayLine(
              displayHandler,
              (hkResult *)v46,
              (hkVector4f *)end,
              (hkVector4f *)&end[8],
              settings->m_fanEdgeColor,
              0,
              v53);
          else
            hkDebugDisplay::displayLine(
              hkSingleton<hkDebugDisplay>::s_instance,
              (hkVector4f *)end,
              (hkVector4f *)&end[8],
              settings->m_fanEdgeColor,
              0,
              (int)hkDebugDisplayProcess::m_tag);
        }
        if ( settings->m_nonplanarFacesSettings.m_highlightNonplanarFaces.m_bool )
        {
          if ( v25 == -1.0 )
            v25 = hkaiNavMeshDebugUtils::_calcNonplanarity((hkSimdFloat32 *)nmi, v7);
          *(_DWORD *)end = 0;
          *(_DWORD *)&faceOffset[16] = 1065353216;
          *(float *)&v44 = v25 / settings->m_nonplanarFacesSettings.m_scaleMultiplier;
          v39 = 1.0 - fminf(fmaxf(*(float *)&v44, 0.0), 1.0);
          LitColor = hkColor::rgbFromFloats(v39, v39, 1.0, 1.0);
        }
        else if ( settings->m_faceNormalSettings.m_highlightFaceNormals.m_bool )
        {
          LitColor = hkColor::WHITE;
          if ( !v55 )
          {
            hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
              (hkaiNavMeshUtils *)&extraRadius,
              (hkSimdFloat32 *)nmi,
              (hkaiNavMeshInstance *)v7,
              (__m128 *)&end[16]);
            v55 = 1;
          }
          v40 = _mm_mul_ps(*(__m128 *)&end[16], settings->m_faceNormalSettings.m_up.m_quad);
          v41 = (float)(_mm_shuffle_ps(v40, v40, 85).m128_f32[0] + _mm_shuffle_ps(v40, v40, 0).m128_f32[0])
              + _mm_shuffle_ps(v40, v40, 170).m128_f32[0];
          if ( v41 < settings->m_faceNormalSettings.m_cosAngleThreshold )
            LitColor = hkColor::BLUE;
          if ( v41 < settings->m_faceNormalSettings.m_cosAngleThreshold )
          {
            if ( !m_storage )
            {
              hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
                (hkaiNavMeshUtils *)nmi,
                (hkaiNavMeshInstance *)v7,
                (__m128 *)faceOffset,
                v38);
              m_storage = 1;
              *(__m128 *)faceOffset = _mm_add_ps(*(__m128 *)faceOffset, v19);
            }
            *(__m128 *)&faceOffset[8] = _mm_add_ps(
                                          _mm_mul_ps(
                                            _mm_shuffle_ps(
                                              (__m128)LODWORD(settings->m_faceNormalSettings.m_scaleMultiplier),
                                              (__m128)LODWORD(settings->m_faceNormalSettings.m_scaleMultiplier),
                                              0),
                                            settings->m_faceNormalSettings.m_up.m_quad),
                                          *(__m128 *)faceOffset);
            if ( !displayHandler )
            {
              hkDebugDisplay::displayLine(
                hkSingleton<hkDebugDisplay>::s_instance,
                (hkVector4f *)faceOffset,
                (hkVector4f *)&faceOffset[8],
                hkColor::BLUE,
                0,
                (int)hkDebugDisplayProcess::m_tag);
LABEL_75:
              hkDebugDisplay::displayTriangle(
                hkSingleton<hkDebugDisplay>::s_instance,
                (hkVector4f *)end,
                (hkVector4f *)&end[8],
                (hkVector4f *)&end[24],
                LitColor,
                0,
                (int)hkDebugDisplayProcess::m_tag);
              v30 = (__int64)v44;
              goto LABEL_76;
            }
            displayHandler->vfptr->displayLine(
              displayHandler,
              (hkResult *)v47,
              (hkVector4f *)faceOffset,
              (hkVector4f *)&faceOffset[8],
              hkColor::BLUE,
              0,
              v53);
          }
          v30 = (__int64)v44;
        }
        else if ( settings->m_lightFaces.m_bool )
        {
          LitColor = getLitColor(
                       (float)BYTE2(LitColor) * 0.0039215689,
                       (float)BYTE1(LitColor) * 0.0039215689,
                       (float)(unsigned __int8)LitColor * 0.0039215689,
                       (float)HIBYTE(LitColor) * 0.0039215689,
                       (hkVector4f *)end,
                       (hkVector4f *)&end[8],
                       (hkVector4f *)&end[24],
                       &settings->m_lightDirection);
        }
        if ( !displayHandler )
          goto LABEL_75;
        displayHandler->vfptr->displayTriangle(
          displayHandler,
          (hkResult *)v48,
          (hkVector4f *)end,
          (hkVector4f *)&end[8],
          (hkVector4f *)&end[24],
          LitColor,
          0,
          v53);
LABEL_76:
        ++v21;
      }
      while ( v21 < *(__int16 *)(v30 + 8) - 1 );
    }
  }
}

// File Line: 1137
// RVA: 0xC49EF0
void __fastcall hkaiNavMeshDebugUtils::_showEdgesForFace(
        hkDebugDisplayHandler *displayHandler,
        int tag,
        hkaiNavMeshInstance *nmi,
        hkaiNavMeshDebugUtils::DebugInfo *settings,
        unsigned int faceIdx,
        unsigned int faceColor)
{
  unsigned int v6; // r12d
  hkaiNavMesh::Face *v11; // rsi
  int v12; // ecx
  hkArray<int,hkContainerHeapAllocator> *p_m_edgeMap; // rdx
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_ownedEdges; // r8
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_instancedEdges; // r10
  __m128 m_quad; // xmm8
  int m_startEdgeIndex; // eax
  int m_numOriginalEdges; // esi
  hkVector4f *v19; // r9
  hkaiNavMesh::Edge *v20; // r15
  int striding; // eax
  __int64 m_a; // rax
  int m_numOriginalVertices; // ecx
  hkVector4f *v24; // rax
  __m128 v25; // xmm1
  hkVector4f v26; // xmm2
  hkVector4f v27; // xmm3
  __int64 m_b; // rax
  hkVector4f v29; // xmm4
  hkVector4f v30; // xmm5
  __m128 v31; // xmm7
  hkVector4f *v32; // rax
  __m128 v33; // xmm6
  __m128 v34; // xmm0
  __m128 v35; // xmm1
  __m128 v36; // xmm2
  unsigned int m_sharedEdgeColor; // esi
  unsigned int m_oppositeEdge; // r8d
  char m_storage; // dl
  bool v40; // r12
  hkaiNavMesh::Edge *v41; // rax
  unsigned int v43; // edx
  __m128 v44; // xmm3
  __m128 v45; // xmm3
  __m128 v46; // xmm1
  __m128 v47; // xmm0
  unsigned int m_smallBoundaryEdgeColor; // ecx
  unsigned int m_smallSharedEdgeColor; // r9d
  unsigned int m_vertexLabelColor; // r9d
  float m_vertexDisplaySize; // xmm2_4
  bool v52; // zf
  int v53; // r15d
  int m_edgeDataStriding; // r8d
  __m128 v55; // xmm1
  __m128 v56; // xmm1
  __m128 v57; // xmm4
  __m128 v58; // xmm1
  __m128 v59; // xmm0
  unsigned int m_edgeNormalColor; // r9d
  unsigned int m_vertexNormalColor; // r9d
  hkAabb *instanceMap; // [rsp+20h] [rbp-E0h]
  char v63; // [rsp+40h] [rbp-C0h]
  int v64; // [rsp+44h] [rbp-BCh]
  int index; // [rsp+48h] [rbp-B8h]
  hkVector4f start; // [rsp+50h] [rbp-B0h] BYREF
  BOOL v67; // [rsp+60h] [rbp-A0h]
  hkVector4f end; // [rsp+70h] [rbp-90h] BYREF
  int v69[4]; // [rsp+80h] [rbp-80h] BYREF
  int *dataPtr; // [rsp+90h] [rbp-70h]
  hkaiNavMesh::Face *v71; // [rsp+98h] [rbp-68h]
  hkVector4f faceNormal; // [rsp+A0h] [rbp-60h] BYREF
  int v73[4]; // [rsp+B0h] [rbp-50h] BYREF
  int faceIndex[4]; // [rsp+C0h] [rbp-40h] BYREF
  hkVector4f faceOffset; // [rsp+D0h] [rbp-30h] BYREF
  hkVector4f pos; // [rsp+E0h] [rbp-20h] BYREF
  char v77[4]; // [rsp+F0h] [rbp-10h] BYREF
  char v78[12]; // [rsp+F4h] [rbp-Ch] BYREF
  hkVector4f v79; // [rsp+100h] [rbp+0h] BYREF
  char v80[4]; // [rsp+110h] [rbp+10h] BYREF
  char v81[4]; // [rsp+114h] [rbp+14h] BYREF
  char v82[4]; // [rsp+118h] [rbp+18h] BYREF
  char v83[4]; // [rsp+11Ch] [rbp+1Ch] BYREF
  hkVector4f v84; // [rsp+120h] [rbp+20h] BYREF
  char buf[16]; // [rsp+130h] [rbp+30h] BYREF
  hkVector4f v86; // [rsp+140h] [rbp+40h] BYREF
  hkVector4f v87; // [rsp+150h] [rbp+50h] BYREF
  hkVector4f v88; // [rsp+160h] [rbp+60h] BYREF
  hkVector4f edgeB; // [rsp+170h] [rbp+70h] BYREF
  hkVector4f edgeA; // [rsp+180h] [rbp+80h] BYREF
  hkSimdFloat32 extraRadius; // [rsp+190h] [rbp+90h] BYREF
  __m128 v92; // [rsp+1A0h] [rbp+A0h]
  hkStringBuf v93; // [rsp+1B0h] [rbp+B0h] BYREF
  hkStringBuf label; // [rsp+240h] [rbp+140h] BYREF
  hkaiNavMeshUtils v95; // [rsp+2D0h] [rbp+1D0h] BYREF
  hkaiNavMeshUtils v96; // [rsp+2E0h] [rbp+1E0h] BYREF
  char v97; // [rsp+3B0h] [rbp+2B0h]
  char v98; // [rsp+3B8h] [rbp+2B8h]

  v6 = faceIdx;
  v11 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__21(
          nmi->m_originalFaces,
          nmi->m_numOriginalFaces,
          &nmi->m_instancedFaces,
          &nmi->m_ownedFaces,
          &nmi->m_faceMap,
          faceIdx);
  v71 = v11;
  *(_OWORD *)v69 = 0i64;
  *(_OWORD *)v73 = 0i64;
  v97 = 0;
  v98 = 0;
  hkaiNavMeshDebugUtils::_calcFaceOffset(nmi, settings, faceIdx, &faceOffset);
  v67 = 1;
  if ( (*(_WORD *)&settings->m_labelVertices.m_bool || settings->m_showEdgeData.m_bool)
    && (_mm_movemask_ps(_mm_cmple_ps(settings->m_pruneLabelsAabb.m_max.m_quad, settings->m_pruneLabelsAabb.m_min.m_quad)) & 7) == 0 )
  {
    *(_OWORD *)faceIndex = 0i64;
    hkaiNavMeshUtils::calcFaceAabb<hkaiNavMeshInstance>(
      (hkaiNavMeshUtils *)nmi,
      (hkaiNavMeshInstance *)faceIdx,
      (__m128 *)faceIndex,
      &extraRadius,
      instanceMap);
    v67 = (_mm_movemask_ps(
             _mm_and_ps(
               _mm_cmple_ps(extraRadius.m_real, settings->m_pruneLabelsAabb.m_max.m_quad),
               _mm_cmple_ps(settings->m_pruneLabelsAabb.m_min.m_quad, v92))) & 7) == 7;
  }
  v12 = 0;
  v64 = 0;
  if ( v11->m_numEdges > 0 )
  {
    p_m_edgeMap = &nmi->m_edgeMap;
    p_m_ownedEdges = &nmi->m_ownedEdges;
    p_m_instancedEdges = &nmi->m_instancedEdges;
    m_quad = faceOffset.m_quad;
    do
    {
      m_startEdgeIndex = v11->m_startEdgeIndex;
      m_numOriginalEdges = nmi->m_numOriginalEdges;
      faceNormal.m_quad = 0i64;
      v63 = 0;
      index = v12 + m_startEdgeIndex;
      v20 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__23(
              nmi->m_originalEdges,
              m_numOriginalEdges,
              p_m_instancedEdges,
              p_m_ownedEdges,
              p_m_edgeMap,
              v12 + m_startEdgeIndex);
      striding = nmi->m_edgeDataStriding;
      if ( striding )
        dataPtr = hkaiNavMeshInstance_getWithStriding_int__4(
                    nmi->m_originalEdgeData,
                    m_numOriginalEdges,
                    &nmi->m_instancedEdgeData,
                    &nmi->m_ownedEdgeData,
                    &nmi->m_edgeMap,
                    index,
                    striding);
      else
        dataPtr = 0i64;
      m_a = v20->m_a;
      m_numOriginalVertices = nmi->m_numOriginalVertices;
      if ( (int)m_a >= m_numOriginalVertices )
        v24 = &nmi->m_ownedVertices.m_data[(int)m_a - m_numOriginalVertices];
      else
        v24 = &nmi->m_originalVertices[m_a];
      v25 = v24->m_quad;
      v26.m_quad = (__m128)nmi->m_referenceFrame.m_transform.m_rotation.m_col1;
      v27.m_quad = (__m128)nmi->m_referenceFrame.m_transform.m_rotation.m_col0;
      m_b = v20->m_b;
      v29.m_quad = (__m128)nmi->m_referenceFrame.m_transform.m_rotation.m_col2;
      v30.m_quad = (__m128)nmi->m_referenceFrame.m_transform.m_translation;
      v31 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), v27.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v25, v25, 85), v26.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v25, v25, 170), v29.m_quad)),
              v30.m_quad);
      if ( (int)m_b >= m_numOriginalVertices )
        v32 = &nmi->m_ownedVertices.m_data[(int)m_b - m_numOriginalVertices];
      else
        v32 = &nmi->m_originalVertices[m_b];
      v33 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v32->m_quad, v32->m_quad, 0), v27.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v32->m_quad, v32->m_quad, 85), v26.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v32->m_quad, v32->m_quad, 170), v29.m_quad)),
              v30.m_quad);
      if ( settings->m_contractEdges.m_bool )
      {
        if ( !v98 )
        {
          hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
            (hkaiNavMeshUtils *)nmi,
            (hkaiNavMeshInstance *)v6,
            (__m128 *)v73,
            v19);
          v98 = 1;
          *(__m128 *)v73 = _mm_add_ps(*(__m128 *)v73, m_quad);
        }
        v34 = _mm_shuffle_ps(
                (__m128)LODWORD(settings->m_edgeContractionRadius),
                (__m128)LODWORD(settings->m_edgeContractionRadius),
                0);
        v35 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)v73, v33), v34), v33);
        v36 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)v73, v31), v34), v31);
      }
      else
      {
        v36 = v31;
        v35 = v33;
      }
      m_sharedEdgeColor = settings->m_sharedEdgeColor;
      start.m_quad = _mm_add_ps(v36, m_quad);
      end.m_quad = _mm_add_ps(v35, m_quad);
      m_oppositeEdge = v20->m_oppositeEdge;
      if ( m_oppositeEdge == -1 )
      {
        m_sharedEdgeColor = settings->m_boundaryEdgeColor;
      }
      else if ( (v20->m_flags.m_storage & 0x40) != 0 )
      {
        m_sharedEdgeColor = settings->m_externalEdgeColor;
      }
      m_storage = v20->m_flags.m_storage;
      if ( (m_storage & 2) != 0 )
        m_sharedEdgeColor = ((((m_sharedEdgeColor ^ settings->m_faceColor) >> 1) & 0x7F7F7F)
                           + (settings->m_faceColor & m_sharedEdgeColor)) | 0xFF000000;
      v40 = m_oppositeEdge == -1 || (m_storage & 0x40) != 0;
      if ( settings->m_lightFaces.m_bool && !v40 )
        m_sharedEdgeColor = hkColor::rgbFromFloats(
                              (float)((float)((float)BYTE2(faceColor) * 0.0039215689)
                                    + (float)((float)BYTE2(m_sharedEdgeColor) * 0.0039215689))
                            * 0.5,
                              (float)((float)((float)BYTE1(faceColor) * 0.0039215689)
                                    + (float)((float)BYTE1(m_sharedEdgeColor) * 0.0039215689))
                            * 0.5,
                              (float)((float)((float)(unsigned __int8)faceColor * 0.0039215689)
                                    + (float)((float)(unsigned __int8)m_sharedEdgeColor * 0.0039215689))
                            * 0.5,
                              (float)HIBYTE(m_sharedEdgeColor) * 0.0039215689);
      if ( !settings->m_showEdges.m_bool )
        goto LABEL_49;
      if ( !v40 && (int)faceIdx >= (signed int)(v20->m_oppositeFace & 0x3FFFFF) )
      {
        v41 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__23(
                nmi->m_originalEdges,
                nmi->m_numOriginalEdges,
                &nmi->m_instancedEdges,
                &nmi->m_ownedEdges,
                &nmi->m_edgeMap,
                v20->m_oppositeEdge & 0x3FFFFF);
        if ( v20->m_a == v41->m_a && v20->m_b == v41->m_b )
          goto LABEL_49;
        if ( v20->m_a == v41->m_b && v20->m_b == v41->m_a )
          goto LABEL_49;
      }
      if ( displayHandler )
        displayHandler->vfptr->displayLine(displayHandler, (hkResult *)v80, &start, &end, m_sharedEdgeColor, 0, tag);
      else
        hkDebugDisplay::displayLine(
          hkSingleton<hkDebugDisplay>::s_instance,
          &start,
          &end,
          m_sharedEdgeColor,
          0,
          (int)hkDebugDisplayProcess::m_tag);
      if ( v20->m_a == v20->m_b )
      {
        if ( settings->m_smallEdgeSettings.m_markDegenerateEdges.m_bool )
          goto LABEL_55;
      }
      else if ( settings->m_smallEdgeSettings.m_markSmallEdges.m_bool )
      {
        v44 = _mm_sub_ps(start.m_quad, end.m_quad);
        v45 = _mm_mul_ps(v44, v44);
        if ( (float)((float)(_mm_shuffle_ps(v45, v45, 85).m128_f32[0] + _mm_shuffle_ps(v45, v45, 0).m128_f32[0])
                   + _mm_shuffle_ps(v45, v45, 170).m128_f32[0]) <= (float)(settings->m_smallEdgeSettings.m_smallEdgeTolerance
                                                                         * settings->m_smallEdgeSettings.m_smallEdgeTolerance) )
        {
LABEL_55:
          v46 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(end.m_quad, start.m_quad), (__m128)_xmm), start.m_quad);
          v47 = _mm_add_ps(settings->m_smallEdgeSettings.m_markerOffset.m_quad, v46);
          v86.m_quad = v46;
          v88.m_quad = v47;
          if ( displayHandler )
          {
            if ( v40 )
              m_smallBoundaryEdgeColor = settings->m_smallEdgeSettings.m_smallBoundaryEdgeColor;
            else
              m_smallBoundaryEdgeColor = settings->m_smallEdgeSettings.m_smallSharedEdgeColor;
            displayHandler->vfptr->displayLine(
              displayHandler,
              (hkResult *)v81,
              &v86,
              &v88,
              m_smallBoundaryEdgeColor,
              0,
              tag);
          }
          else
          {
            if ( v40 )
              m_smallSharedEdgeColor = settings->m_smallEdgeSettings.m_smallBoundaryEdgeColor;
            else
              m_smallSharedEdgeColor = settings->m_smallEdgeSettings.m_smallSharedEdgeColor;
            hkDebugDisplay::displayLine(
              hkSingleton<hkDebugDisplay>::s_instance,
              &v86,
              &v88,
              m_smallSharedEdgeColor,
              0,
              (int)hkDebugDisplayProcess::m_tag);
          }
        }
      }
LABEL_49:
      if ( settings->m_showEdgeConnections.m_bool )
      {
        v43 = v20->m_oppositeEdge;
        if ( v43 != -1 )
        {
          v87.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(end.m_quad, start.m_quad), (__m128)_xmm), start.m_quad);
          hkaiNavMeshInstance::getEdgePoints(nmi, v43 & 0x3FFFFF, &edgeA, &edgeB);
          v84.m_quad = _mm_add_ps(
                         _mm_add_ps(_mm_mul_ps(_mm_sub_ps(edgeA.m_quad, edgeB.m_quad), (__m128)_xmm), edgeB.m_quad),
                         m_quad);
          if ( displayHandler )
            displayHandler->vfptr->displayLine(
              displayHandler,
              (hkResult *)v82,
              &v87,
              &v84,
              settings->m_edgeNormalColor,
              0,
              tag);
          else
            hkDebugDisplay::displayLine(
              hkSingleton<hkDebugDisplay>::s_instance,
              &v87,
              &v84,
              settings->m_edgeNormalColor,
              0,
              (int)hkDebugDisplayProcess::m_tag);
        }
      }
      if ( settings->m_showVertices.m_bool )
      {
        m_vertexLabelColor = settings->m_vertexLabelColor;
        m_vertexDisplaySize = settings->m_vertexDisplaySize;
        if ( displayHandler )
          hkDebugDisplayHandler::displayStar(displayHandler, &start, m_vertexDisplaySize, m_vertexLabelColor, 0, tag);
        else
          hkDebugDisplay::displayStar(
            hkSingleton<hkDebugDisplay>::s_instance,
            &start,
            m_vertexDisplaySize,
            m_vertexLabelColor,
            0,
            (int)hkDebugDisplayProcess::m_tag);
      }
      if ( v67 )
      {
        v52 = settings->m_labelVertices.m_bool == 0;
        v93.m_string.m_capacityAndFlags = -2147483520;
        v93.m_string.m_data = v93.m_string.m_storage;
        v93.m_string.m_size = 1;
        v93.m_string.m_storage[0] = 0;
        if ( !v52 )
        {
          hkString::sprintf(buf, "%d", (unsigned int)v20->m_a);
          if ( displayHandler )
            displayHandler->vfptr->display3dText(
              displayHandler,
              (hkResult *)v78,
              buf,
              &start,
              settings->m_vertexLabelColor,
              0,
              tag);
          else
            hkDebugDisplay::display3dText(
              hkSingleton<hkDebugDisplay>::s_instance,
              buf,
              &start,
              settings->m_vertexLabelColor,
              0,
              (int)hkDebugDisplayProcess::m_tag);
        }
        v53 = v64;
        if ( settings->m_labelEdges.m_bool )
          hkStringBuf::printf(&v93, "%d ", (unsigned int)(v64 + v71->m_startEdgeIndex));
        if ( settings->m_showEdgeData.m_bool )
        {
          if ( dataPtr )
          {
            m_edgeDataStriding = nmi->m_edgeDataStriding;
            label.m_string.m_data = label.m_string.m_storage;
            label.m_string.m_capacityAndFlags = -2147483520;
            label.m_string.m_size = 1;
            label.m_string.m_storage[0] = 0;
            formatUserData(&label, dataPtr, m_edgeDataStriding);
            hkStringBuf::operator+=(&v93, label.m_string.m_data);
            label.m_string.m_size = 0;
            if ( label.m_string.m_capacityAndFlags >= 0 )
              hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                &hkContainerTempAllocator::s_alloc,
                label.m_string.m_data,
                label.m_string.m_capacityAndFlags & 0x3FFFFFFF);
          }
        }
        if ( v93.m_string.m_size - 1 > 0 )
        {
          v79.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(end.m_quad, start.m_quad), (__m128)_xmm), start.m_quad);
          if ( !v97 )
          {
            hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
              &v96,
              (hkSimdFloat32 *)nmi,
              (hkaiNavMeshInstance *)faceIdx,
              (__m128 *)v69);
            v97 = 1;
          }
          hkaiNavMeshUtils::calcEdgePlane<hkaiNavMeshInstance>(
            (hkaiNavMeshUtils *)nmi,
            (hkaiNavMeshInstance *)faceIdx,
            index,
            (__m128 *)v69,
            &faceNormal);
          v63 = 1;
          v55 = _mm_sub_ps(start.m_quad, end.m_quad);
          v56 = _mm_mul_ps(v55, v55);
          v57 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v56, v56, 85), _mm_shuffle_ps(v56, v56, 0)),
                  _mm_shuffle_ps(v56, v56, 170));
          v58 = _mm_rsqrt_ps(v57);
          v59 = _mm_mul_ps(*(__m128 *)_xmm, v58);
          v59.m128_f32[0] = _mm_andnot_ps(
                              _mm_cmple_ps(v57, (__m128)0i64),
                              _mm_mul_ps(
                                _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v58, v57), v58)), v59),
                                v57)).m128_f32[0]
                          * -0.0099999998;
          pos.m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v59, v59, 0), faceNormal.m_quad), v79.m_quad);
          if ( displayHandler )
          {
            displayHandler->vfptr->display3dText(
              displayHandler,
              (hkResult *)v83,
              v93.m_string.m_data,
              &pos,
              settings->m_edgeLabelColor,
              0,
              tag);
            displayHandler->vfptr->displayLine(
              displayHandler,
              (hkResult *)v77,
              &v79,
              &pos,
              settings->m_edgeLabelColor,
              0,
              tag);
          }
          else
          {
            hkDebugDisplay::display3dText(
              hkSingleton<hkDebugDisplay>::s_instance,
              v93.m_string.m_data,
              &pos,
              settings->m_edgeLabelColor,
              0,
              (int)hkDebugDisplayProcess::m_tag);
            hkDebugDisplay::displayLine(
              hkSingleton<hkDebugDisplay>::s_instance,
              &v79,
              &pos,
              settings->m_edgeLabelColor,
              0,
              (int)hkDebugDisplayProcess::m_tag);
          }
        }
        v93.m_string.m_size = 0;
        if ( v93.m_string.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            v93.m_string.m_data,
            v93.m_string.m_capacityAndFlags & 0x3FFFFFFF);
      }
      else
      {
        v53 = v64;
      }
      if ( settings->m_showEdgeNormals.m_bool )
      {
        faceOffset.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(end.m_quad, start.m_quad), (__m128)_xmm), start.m_quad);
        if ( !v97 )
        {
          hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
            &v95,
            (hkSimdFloat32 *)nmi,
            (hkaiNavMeshInstance *)faceIdx,
            (__m128 *)v69);
          v97 = 1;
        }
        if ( !v63 )
          hkaiNavMeshUtils::calcEdgePlane<hkaiNavMeshInstance>(
            (hkaiNavMeshUtils *)nmi,
            (hkaiNavMeshInstance *)faceIdx,
            index,
            (__m128 *)v69,
            &faceNormal);
        m_edgeNormalColor = settings->m_edgeNormalColor;
        if ( displayHandler )
          hkDebugDisplayHandler::displayArrow(displayHandler, &faceOffset, &faceNormal, m_edgeNormalColor, 0, tag);
        else
          hkDebugDisplay::displayArrow(
            hkSingleton<hkDebugDisplay>::s_instance,
            &faceOffset,
            &faceNormal,
            m_edgeNormalColor,
            0,
            (int)hkDebugDisplayProcess::m_tag);
      }
      v6 = faceIdx;
      if ( settings->m_showVertexNormals.m_bool )
      {
        if ( !v97 )
        {
          hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
            (hkaiNavMeshUtils *)&extraRadius,
            (hkSimdFloat32 *)nmi,
            (hkaiNavMeshInstance *)faceIdx,
            (__m128 *)v69);
          v97 = 1;
        }
        hkaiNavMeshUtils::calcVertexPlane<hkaiNavMeshInstance>(
          (hkaiNavMeshUtils *)nmi,
          (hkaiNavMeshInstance *)faceIdx,
          v53,
          (__m128 *)v69,
          (hkVector4f *)faceIndex);
        m_vertexNormalColor = settings->m_vertexNormalColor;
        if ( displayHandler )
          hkDebugDisplayHandler::displayArrow(
            displayHandler,
            &start,
            (hkVector4f *)faceIndex,
            m_vertexNormalColor,
            0,
            tag);
        else
          hkDebugDisplay::displayArrow(
            hkSingleton<hkDebugDisplay>::s_instance,
            &start,
            (hkVector4f *)faceIndex,
            m_vertexNormalColor,
            0,
            (int)hkDebugDisplayProcess::m_tag);
      }
      v11 = v71;
      p_m_edgeMap = &nmi->m_edgeMap;
      v12 = v64 + 1;
      p_m_ownedEdges = &nmi->m_ownedEdges;
      v64 = v12;
      p_m_instancedEdges = &nmi->m_instancedEdges;
    }
    while ( v12 < v71->m_numEdges );
  }
}

// File Line: 1348
// RVA: 0xC4AB50
void __fastcall hkaiNavMeshDebugUtils::_showUserEdgesForFace(
        hkDebugDisplayHandler *displayHandler,
        int tag,
        hkaiStreamingCollection *collection,
        hkaiNavMeshInstance *nmi,
        hkaiNavMeshDebugUtils::DebugInfo *settings,
        int faceIdx)
{
  hkaiNavMesh::Face *v10; // rdi
  _QWORD *Value; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  int m_startUserEdgeIndex; // ebx
  _QWORD *v16; // rax
  _QWORD *v17; // rcx
  _QWORD *v18; // r8
  unsigned __int64 v19; // rax
  _QWORD *v20; // rcx

  v10 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__21(
          nmi->m_originalFaces,
          nmi->m_numOriginalFaces,
          &nmi->m_instancedFaces,
          &nmi->m_ownedFaces,
          &nmi->m_faceMap,
          faceIdx);
  if ( v10->m_numUserEdges )
  {
    Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v12 = (_QWORD *)Value[1];
    if ( (unsigned __int64)v12 < Value[3] )
    {
      *v12 = "TtuserEdges";
      v13 = __rdtsc();
      v14 = v12 + 2;
      *((_DWORD *)v14 - 2) = v13;
      Value[1] = v14;
    }
    m_startUserEdgeIndex = v10->m_startUserEdgeIndex;
    if ( m_startUserEdgeIndex < m_startUserEdgeIndex + v10->m_numUserEdges )
    {
      do
        hkaiNavMeshDebugUtils::_showUserEdgePair(
          collection,
          settings,
          faceIdx | (nmi->m_runtimeId << 22),
          m_startUserEdgeIndex++ | (nmi->m_runtimeId << 22),
          displayHandler,
          tag);
      while ( m_startUserEdgeIndex < v10->m_startUserEdgeIndex + v10->m_numUserEdges );
    }
    v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v17 = (_QWORD *)v16[1];
    v18 = v16;
    if ( (unsigned __int64)v17 < v16[3] )
    {
      *v17 = "Et";
      v19 = __rdtsc();
      v20 = v17 + 2;
      *((_DWORD *)v20 - 2) = v19;
      v18[1] = v20;
    }
  }
}

// File Line: 1367
// RVA: 0xC4ACA0
void __fastcall hkaiNavMeshDebugUtils::_calcFaceOffset(
        hkaiNavMeshInstance *nmi,
        hkaiNavMeshDebugUtils::DebugInfo *settings,
        int faceIdx,
        hkVector4f *faceOffset)
{
  hkVector4f v4; // xmm1
  char m_storage; // [rsp+8h] [rbp+8h]

  if ( nmi->m_faceFlags.m_size )
    m_storage = nmi->m_faceFlags.m_data[faceIdx].m_storage;
  else
    m_storage = 0;
  v4.m_quad = (__m128)settings->m_displayOffset;
  *faceOffset = settings->m_displayOffset;
  if ( (m_storage & 1) != 0 )
  {
    if ( settings->m_showHiddenFaces.m_bool )
      faceOffset->m_quad = _mm_add_ps(settings->m_hiddenFaceOffset.m_quad, v4.m_quad);
  }
}

// File Line: 1381
// RVA: 0xC4ACF0
__int64 __fastcall hkaiNavMeshDebugUtils::_getUnlitFaceColor(
        hkaiNavMeshInstance *nmi,
        hkaiNavMeshDebugUtils::DebugInfo *settings,
        hkArrayBase<int> *regions,
        int faceIdx)
{
  __int64 index; // rdi
  hkArray<int,hkContainerHeapAllocator> *instanceMap; // rbp
  hkaiNavMesh::Face *v8; // rax
  hkArray<int,hkContainerHeapAllocator> *v9; // r11
  int striding; // ecx
  int v11; // esi
  hkaiNavMesh::Face *v12; // r13
  int *v13; // r8
  int m_highlightSingleRegionIndex; // edx
  float v15; // xmm6_4
  unsigned int m_faceColor; // ecx
  int m_numMaterialColors; // ecx
  float v18; // xmm0_4
  __int16 m_clusterIndex; // ax
  char v21; // [rsp+70h] [rbp+8h]

  index = faceIdx;
  instanceMap = &nmi->m_faceMap;
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
    v21 = *((_BYTE *)v9[20].m_data + index);
  else
    v21 = 0;
  m_highlightSingleRegionIndex = settings->m_highlightSingleRegionIndex;
  v15 = *(float *)&FLOAT_1_0;
  if ( m_highlightSingleRegionIndex == -1 || regions->m_data[index] != m_highlightSingleRegionIndex )
  {
    if ( settings->m_colorRegions.m_bool )
    {
      m_faceColor = regionColors[regions->m_data[index] % 0xCui64];
    }
    else
    {
      m_numMaterialColors = settings->m_numMaterialColors;
      if ( m_numMaterialColors <= 0 )
      {
        m_faceColor = settings->m_faceColor;
      }
      else
      {
        if ( v13 )
          v11 = *v13;
        m_faceColor = settings->m_materialColors[v11 % m_numMaterialColors];
      }
    }
    if ( settings->m_allowFaceTransparency.m_bool )
    {
      v18 = settings->m_lightFaces.m_bool ? FLOAT_0_80000001 : FLOAT_0_25;
      v15 = (float)((float)HIBYTE(m_faceColor) * 0.0039215689) * v18;
      if ( (v21 & 1) != 0 )
        v15 = v15 * 0.25;
    }
    if ( settings->m_showClusters.m_bool )
    {
      m_clusterIndex = v12->m_clusterIndex;
      if ( m_clusterIndex >= 0 )
        m_faceColor = perturbColor(m_faceColor, m_clusterIndex, 0.30000001);
    }
  }
  else
  {
    m_faceColor = hkColor::rgbFromChars(255, 100, 0, 255);
    if ( settings->m_allowFaceTransparency.m_bool )
      v15 = FLOAT_0_627451;
  }
  return m_faceColor & 0xFFFFFF | ((unsigned __int8)(int)(float)(v15 * 255.0) << 24);
}

// File Line: 1438
// RVA: 0xC4AF00
void __fastcall hkaiNavMeshDebugUtils::dumpMeshToZir(hkaiNavMesh *navMesh, hkVector4f *up, const char *filename)
{
  hkaiNavMeshInstance navMeshInstance; // [rsp+20h] [rbp-1E8h] BYREF

  hkaiNavMeshInstance::hkaiNavMeshInstance(&navMeshInstance);
  hkaiNavMeshInstance::tempInit(&navMeshInstance, navMesh, 0);
  hkaiNavMeshDebugUtils::dumpMeshToZir(&navMeshInstance, up, filename);
  hkaiNavMeshInstance::~hkaiNavMeshInstance(&navMeshInstance);
}

// File Line: 1445
// RVA: 0xC4AF70
void __fastcall hkaiNavMeshDebugUtils::dumpMeshToZir(
        hkaiNavMeshInstance *navMeshInstance,
        hkVector4f *up,
        const char *filename)
{
  int v5; // ebx
  int v6; // edi
  __int64 v7; // rsi
  __int64 i; // r14
  int m_numOriginalVertices; // ecx
  hkVector4f *v10; // rax
  __m128 m_quad; // xmm1
  _DWORD *v12; // rbx
  int v13; // ebx
  __int64 v14; // rcx
  __int64 v15; // rax
  hkArray<int,hkContainerHeapAllocator> *p_m_faceMap; // rdx
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *p_m_ownedFaces; // r8
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *p_m_instancedFaces; // r10
  bool v19; // zf
  int m_size; // r14d
  hkResult *p_result; // rax
  bool v22; // r12
  hkaiNavMesh::Face *v23; // rax
  hkaiNavMesh::Face *v24; // rsi
  int m_startEdgeIndex; // ebx
  hkaiNavMesh::Edge *v26; // rax
  char m_storage; // cl
  hkaiNavMesh::Edge *v28; // r8
  int v29; // eax
  int v30; // edi
  int v31; // r15d
  int m_startUserEdgeIndex; // edx
  int v33; // ebx
  hkaiZirWriter::SegmentStyle segmentStyle; // [rsp+30h] [rbp-C0h] BYREF
  hkArrayBase<int> points; // [rsp+40h] [rbp-B0h] BYREF
  _DWORD *array; // [rsp+50h] [rbp-A0h] BYREF
  int v37; // [rsp+58h] [rbp-98h]
  int v38; // [rsp+5Ch] [rbp-94h]
  int v39; // [rsp+60h] [rbp-90h]
  __int64 v40; // [rsp+68h] [rbp-88h]
  int v41; // [rsp+70h] [rbp-80h]
  __int64 v42; // [rsp+78h] [rbp-78h]
  int v43; // [rsp+80h] [rbp-70h]
  __int64 v44; // [rsp+88h] [rbp-68h]
  int v45; // [rsp+90h] [rbp-60h]
  __int64 v46; // [rsp+98h] [rbp-58h]
  hkaiZirWriter::NamePattern namePattern; // [rsp+A0h] [rbp-50h] BYREF
  hkaiZirWriter::NamePattern v48; // [rsp+B8h] [rbp-38h] BYREF
  hkaiZirWriter::Window window; // [rsp+D0h] [rbp-20h] BYREF
  hkaiZirWriter::PointStyle pointStyle; // [rsp+E0h] [rbp-10h] BYREF
  __int64 v51; // [rsp+F0h] [rbp+0h]
  hkAabb aabbOut; // [rsp+100h] [rbp+10h] BYREF
  hkaiZirWriter v53; // [rsp+120h] [rbp+30h] BYREF
  hkResult result; // [rsp+1A0h] [rbp+B0h] BYREF
  __int64 v55; // [rsp+1B8h] [rbp+C8h] BYREF

  hkaiNavMeshInstance::getAabb(navMeshInstance, &aabbOut);
  *(_QWORD *)&window.m_minX = aabbOut.m_min.m_quad.m128_u64[0];
  *(_QWORD *)&window.m_maxX = aabbOut.m_max.m_quad.m128_u64[0];
  hkaiZirWriter::hkaiZirWriter(&v53, filename, &window);
  v5 = navMeshInstance->m_numOriginalVertices + navMeshInstance->m_ownedVertices.m_size;
  array = 0i64;
  v37 = 0;
  v38 = 0x80000000;
  if ( v5 > 0 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array, v5, 4);
  v37 = v5;
  pointStyle.m_color = 0;
  *(_QWORD *)&pointStyle.m_shape = 1i64;
  pointStyle.m_hidden = 0;
  v6 = 0;
  v7 = 0i64;
  for ( i = v5;
        v7 < i;
        v12[v7 - 1] = hkaiZirWriter::addPoint(
                        &v53,
                        m_quad.m128_f32[0],
                        _mm_shuffle_ps(m_quad, m_quad, 85).m128_f32[0],
                        &pointStyle,
                        &namePattern,
                        "Vertex") )
  {
    m_numOriginalVertices = navMeshInstance->m_numOriginalVertices;
    if ( v6 >= m_numOriginalVertices )
      v10 = &navMeshInstance->m_ownedVertices.m_data[v6 - m_numOriginalVertices];
    else
      v10 = &navMeshInstance->m_originalVertices[v6];
    m_quad = v10->m_quad;
    v12 = array;
    namePattern.m_prefix = "v";
    namePattern.m_index = v6;
    namePattern.m_suffix = &customCaption;
    ++v7;
    ++v6;
  }
  v13 = 0;
  v14 = 0i64;
  v15 = navMeshInstance->m_numOriginalFaces + navMeshInstance->m_ownedFaces.m_size;
  v44 = 2i64;
  LOWORD(v45) = 1;
  v42 = 4i64;
  LOWORD(v43) = 1;
  v40 = 3i64;
  LOWORD(v41) = 1;
  BYTE2(v41) = 0;
  points.m_data = 0i64;
  points.m_capacityAndFlags = 0x80000000;
  v39 = 0;
  v46 = 0i64;
  v51 = v15;
  if ( v15 > 0 )
  {
    p_m_faceMap = &navMeshInstance->m_faceMap;
    p_m_ownedFaces = &navMeshInstance->m_ownedFaces;
    p_m_instancedFaces = &navMeshInstance->m_instancedFaces;
    while ( 1 )
    {
      v19 = navMeshInstance->m_faceFlags.m_size == 0;
      m_size = 0;
      points.m_size = 0;
      if ( v19 )
      {
        LOBYTE(v55) = 0;
        p_result = (hkResult *)&v55;
      }
      else
      {
        p_result = &result;
        LOBYTE(result.m_enum) = navMeshInstance->m_faceFlags.m_data[v14].m_storage;
      }
      v22 = p_result->m_enum & 1;
      v23 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__21(
              navMeshInstance->m_originalFaces,
              navMeshInstance->m_numOriginalFaces,
              p_m_instancedFaces,
              p_m_ownedFaces,
              p_m_faceMap,
              v13);
      v24 = v23;
      m_startEdgeIndex = v23->m_numUserEdges <= 0 ? v23->m_startEdgeIndex : v23->m_startUserEdgeIndex;
      if ( m_startEdgeIndex != -1 )
        break;
LABEL_36:
      v33 = v39;
      namePattern.m_prefix = (const char *)v40;
      namePattern.m_index = v41;
      v48.m_prefix = "f";
      v48.m_suffix = &customCaption;
      BYTE2(namePattern.m_index) = v22;
      v48.m_index = v39;
      hkaiZirWriter::addPolygon(&v53, &points, (hkaiZirWriter::PolygonStyle *)&namePattern, &v48, "Polygon");
      v13 = v33 + 1;
      p_m_faceMap = &navMeshInstance->m_faceMap;
      v14 = v46 + 1;
      v39 = v13;
      p_m_ownedFaces = &navMeshInstance->m_ownedFaces;
      v46 = v14;
      p_m_instancedFaces = &navMeshInstance->m_instancedFaces;
      if ( v14 >= v51 )
        goto LABEL_37;
    }
    while ( 1 )
    {
      v26 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__23(
              navMeshInstance->m_originalEdges,
              navMeshInstance->m_numOriginalEdges,
              &navMeshInstance->m_instancedEdges,
              &navMeshInstance->m_ownedEdges,
              &navMeshInstance->m_edgeMap,
              m_startEdgeIndex);
      *(_QWORD *)&segmentStyle.m_color = 0i64;
      *(_WORD *)&segmentStyle.m_arrow = 0;
      m_storage = v26->m_flags.m_storage;
      v28 = v26;
      if ( (m_storage & 0x10) != 0 )
      {
        *(_QWORD *)&segmentStyle.m_color = v42;
        v29 = v43;
      }
      else if ( v26->m_oppositeEdge == -1 || (m_storage & 0x20) != 0 )
      {
        *(_QWORD *)&segmentStyle.m_color = v42;
        v29 = v41;
      }
      else
      {
        *(_QWORD *)&segmentStyle.m_color = v44;
        v29 = v45;
      }
      *(_DWORD *)&segmentStyle.m_arrow = v29;
      segmentStyle.m_hidden = v22;
      v30 = array[v28->m_a];
      v31 = array[v28->m_b];
      if ( (v28->m_flags.m_storage & 0x10) == 0 )
      {
        if ( m_size == (points.m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &points, 4);
          m_size = points.m_size;
        }
        points.m_data[m_size] = v30;
        ++points.m_size;
      }
      v48.m_prefix = "e";
      v48.m_suffix = &customCaption;
      v48.m_index = m_startEdgeIndex;
      hkaiZirWriter::addSegment(&v53, v30, v31, &segmentStyle, &v48, 0i64);
      m_startUserEdgeIndex = v24->m_startUserEdgeIndex;
      if ( m_startEdgeIndex < m_startUserEdgeIndex || m_startEdgeIndex >= v24->m_numUserEdges + m_startUserEdgeIndex - 1 )
      {
        if ( m_startEdgeIndex == v24->m_numUserEdges + m_startUserEdgeIndex - 1 )
        {
          m_startEdgeIndex = v24->m_startEdgeIndex;
          goto LABEL_34;
        }
        if ( m_startEdgeIndex < v24->m_startEdgeIndex || m_startEdgeIndex >= v24->m_numEdges + v24->m_startEdgeIndex - 1 )
          goto LABEL_36;
      }
      ++m_startEdgeIndex;
LABEL_34:
      if ( m_startEdgeIndex == -1 )
        goto LABEL_36;
      m_size = points.m_size;
    }
  }
LABEL_37:
  points.m_size = 0;
  if ( points.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      points.m_data,
      4 * points.m_capacityAndFlags);
  points.m_data = 0i64;
  points.m_capacityAndFlags = 0x80000000;
  v37 = 0;
  if ( v38 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 4 * v38);
  array = 0i64;
  v38 = 0x80000000;
  hkaiZirWriter::~hkaiZirWriter(&v53);
}AndFlags = 0x80000000;
  v37 = 0;
  if ( v38 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAll

