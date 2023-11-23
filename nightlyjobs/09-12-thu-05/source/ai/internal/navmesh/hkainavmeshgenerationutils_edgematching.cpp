// File Line: 46
// RVA: 0xB902E0
hkSimdFloat32 *__fastcall findFurthestVertexOfFaceBehindLine_hkaiNavMesh_1_(
        hkSimdFloat32 *result,
        hkaiNavMesh *mesh,
        int faceIdx,
        hkVector4f *edgePlaneProjected,
        hkVector4f *furthestPointOut)
{
  __m128 v5; // xmm5
  hkaiNavMesh::Face *v7; // rax
  __int64 m_numEdges; // r8
  __int64 v9; // r9
  hkVector4f *m_data; // r8
  __m128 m_quad; // xmm6
  hkaiNavMesh::Edge *v12; // rdx
  __int64 m_a; // rax
  __m128 v14; // xmm1
  __m128 v15; // xmm1
  __m128 v16; // xmm0
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  hkSimdFloat32 v19; // xmm1
  __m128 v20; // xmm0
  __m128 v21; // xmm3

  v5 = 0i64;
  v7 = &mesh->m_faces.m_data[faceIdx];
  m_numEdges = v7->m_numEdges;
  result->m_real = _mm_sub_ps((__m128)0i64, (__m128)xmmword_141A712A0);
  v9 = m_numEdges;
  if ( (int)m_numEdges > 0 )
  {
    m_data = mesh->m_vertices.m_data;
    m_quad = edgePlaneProjected->m_quad;
    v12 = &mesh->m_edges.m_data[v7->m_startEdgeIndex];
    do
    {
      m_a = v12->m_a;
      ++v12;
      v14 = _mm_mul_ps(m_quad, m_data[m_a].m_quad);
      v15 = _mm_shuffle_ps(v14, _mm_unpackhi_ps(v14, m_quad), 196);
      v16 = _mm_add_ps(_mm_shuffle_ps(v15, v15, 78), v15);
      v17 = _mm_add_ps(_mm_shuffle_ps(v16, v16, 177), v16);
      v18 = _mm_cmplt_ps(result->m_real, v17);
      v19.m_real = _mm_or_ps(_mm_andnot_ps(v18, result->m_real), _mm_and_ps(v18, v17));
      v20 = v18;
      v21 = _mm_and_ps(v18, m_data[m_a].m_quad);
      *result = (hkSimdFloat32)v19.m_real;
      v5 = _mm_or_ps(_mm_andnot_ps(v20, v5), v21);
      --v9;
    }
    while ( v9 );
  }
  *furthestPointOut = (hkVector4f)v5;
  return result;
}

// File Line: 82
// RVA: 0xB8BDB0
hkaiNavMeshGenerationConnectivityResult::ConnectivityResultEnum __fastcall hkaiNavMeshGenerationUtils::calculateConnectivity(
        hkaiNavMeshGenerationUtils *input,
        hkaiNavMeshEdgeMatchingParameters *up,
        hkVector4f *characterHeight,
        hkSimdFloat32 *mesh,
        hkaiNavMesh *raycaster,
        int edgeAIdx,
        int edgeBIdx,
        int faceAIdx,
        int faceBIdx,
        hkaiNavMeshGenerationUtils::EdgePair *edgePair)
{
  hkaiEdgeGeometryRaycaster *v11; // [rsp+30h] [rbp-38h]
  hkaiNavMeshGenerationUtils::EdgePair *v12; // [rsp+58h] [rbp-10h]

  LODWORD(v11) = edgeAIdx;
  return hkaiNavMeshGenerationUtils::_calculateConnectivity<hkaiNavMesh,0>(
           input,
           up,
           characterHeight,
           mesh,
           (hkaiNavMesh *)mesh,
           raycaster,
           v11,
           edgeBIdx,
           faceAIdx,
           faceBIdx,
           (int)edgePair,
           v12);
}

// File Line: 87
// RVA: 0xB8BE10
hkaiNavMeshGenerationConnectivityResult::ConnectivityResultEnum __fastcall hkaiNavMeshGenerationUtils::calculateWallClimbingConnectivity(
        hkaiNavMeshGenerationUtils *input,
        hkVector4f *characterHeight,
        hkSimdFloat32 *mesh,
        hkaiNavMesh *raycaster,
        int edgeAIdx,
        int edgeBIdx,
        int faceAIdx,
        int faceBIdx,
        hkaiNavMeshGenerationUtils::EdgePair *edgePair)
{
  hkaiEdgeGeometryRaycaster *raycastera; // [rsp+30h] [rbp-48h]
  hkaiNavMeshGenerationUtils::EdgePair *v11; // [rsp+58h] [rbp-20h]
  _BYTE v12[24]; // [rsp+60h] [rbp-18h] BYREF

  *(hkVector4f *)v12 = (hkVector4f)aabbOut.m_quad;
  LODWORD(raycastera) = edgeAIdx;
  return hkaiNavMeshGenerationUtils::_calculateConnectivity<hkaiNavMesh,1>(
           input,
           (hkaiNavMeshEdgeMatchingParameters *)v12,
           characterHeight,
           mesh,
           (hkaiNavMesh *)mesh,
           raycaster,
           raycastera,
           edgeBIdx,
           faceAIdx,
           faceBIdx,
           (int)edgePair,
           v11);
}

// File Line: 93
// RVA: 0xB8BE80
hkaiNavMeshGenerationConnectivityResult::ConnectivityResultEnum __fastcall hkaiNavMeshGenerationUtils::calculateConnectivity(
        hkaiNavMeshGenerationUtils *input,
        hkaiNavMeshEdgeMatchingParameters *up,
        hkSimdFloat32 *meshInstanceA,
        hkaiNavMeshInstance *meshInstanceB,
        int edgeAIdx,
        int edgeBIdx,
        int faceAIdx,
        int faceBIdx,
        hkaiNavMeshGenerationUtils::EdgePair *edgePair)
{
  char v11; // r10
  char v12; // r11
  char v13; // r14
  char v14; // r12
  bool v15; // al
  bool v16; // r15
  hkaiNavMeshGenerationConnectivityResult::ConnectivityResultEnum result; // eax
  float m_distanceSquared; // xmm8_4
  float m_edgeAlignment; // xmm9_4
  float m_overlap; // xmm10_4
  float m_tStartA; // xmm11_4
  float m_tEndA; // xmm12_4
  float m_tStartB; // xmm13_4
  float m_tEndB; // xmm14_4
  int m_edgeAIdx; // xmm15_4
  int v26; // xmm0_4
  float v27; // xmm2_4
  float v28; // xmm6_4
  float v29; // xmm7_4
  float v30; // xmm4_4
  float v31; // xmm3_4
  float v32; // xmm5_4
  int v33; // xmm1_4
  float v34; // xmm1_4
  hkaiEdgeGeometryRaycaster *raycaster; // [rsp+30h] [rbp-D0h]
  hkaiNavMeshGenerationUtils::EdgePair *v36; // [rsp+58h] [rbp-A8h]
  int m_faceBIdx; // [rsp+60h] [rbp-A0h]
  int v38; // [rsp+64h] [rbp-9Ch]
  hkVector4f upa; // [rsp+70h] [rbp-90h] BYREF
  int v40; // [rsp+80h] [rbp-80h]
  int v41; // [rsp+84h] [rbp-7Ch]
  int v42; // [rsp+8Ch] [rbp-74h]
  hkaiNavMeshEdgeMatchingParameters *v43; // [rsp+190h] [rbp+90h]
  int m_edgeBIdx; // [rsp+1A0h] [rbp+A0h]
  int m_faceAIdx; // [rsp+1A8h] [rbp+A8h]

  v43 = (hkaiNavMeshEdgeMatchingParameters *)input;
  v11 = meshInstanceB->m_originalMesh.m_pntr->m_flags.m_storage & 1;
  v12 = *(_BYTE *)(meshInstanceA[6].m_real.m128_u64[0] + 120) & 1;
  if ( v12 || v11 )
  {
    v13 = 0;
    if ( v12 && v11 )
    {
      v14 = 1;
      goto LABEL_5;
    }
  }
  else
  {
    v13 = 1;
  }
  v14 = 0;
LABEL_5:
  v15 = !v12 || !v11;
  v16 = v12 || v11;
  upa.m_quad = aabbOut.m_quad;
  if ( v15 )
  {
    LODWORD(raycaster) = edgeAIdx;
    result = hkaiNavMeshGenerationUtils::_calculateConnectivity<hkaiNavMeshInstance,0>(
               input,
               up,
               &upa,
               meshInstanceA,
               meshInstanceB,
               0i64,
               raycaster,
               edgeBIdx,
               faceAIdx,
               faceBIdx,
               (int)edgePair,
               v36);
    if ( v13 || result != CONNECT_SUCCESS )
      return result;
    input = (hkaiNavMeshGenerationUtils *)v43;
  }
  m_distanceSquared = edgePair->m_distanceSquared;
  m_edgeAlignment = edgePair->m_edgeAlignment;
  m_overlap = edgePair->m_overlap;
  m_tStartA = edgePair->m_tStartA;
  m_tEndA = edgePair->m_tEndA;
  m_tStartB = edgePair->m_tStartB;
  m_tEndB = edgePair->m_tEndB;
  m_edgeAIdx = edgePair->m_edgeAIdx;
  m_edgeBIdx = edgePair->m_edgeBIdx;
  m_faceAIdx = edgePair->m_faceAIdx;
  m_faceBIdx = edgePair->m_faceBIdx;
  v38 = *(_DWORD *)&edgePair->m_isValid;
  if ( !v16
    || (LODWORD(raycaster) = edgeAIdx,
        result = hkaiNavMeshGenerationUtils::_calculateConnectivity<hkaiNavMeshInstance,1>(
                   input,
                   (hkaiNavMeshEdgeMatchingParameters *)&aabbOut,
                   &upa,
                   meshInstanceA,
                   meshInstanceB,
                   0i64,
                   raycaster,
                   edgeBIdx,
                   faceAIdx,
                   faceBIdx,
                   (int)edgePair,
                   v36),
        !v14)
    && result == CONNECT_SUCCESS )
  {
    v26 = edgePair->m_edgeAIdx;
    v27 = edgePair->m_distanceSquared;
    result = CONNECT_SUCCESS;
    v28 = edgePair->m_tStartB;
    v29 = edgePair->m_tEndB;
    v30 = edgePair->m_overlap;
    v31 = edgePair->m_tStartA;
    v32 = edgePair->m_tEndA;
    v41 = edgePair->m_edgeBIdx;
    v33 = edgePair->m_faceBIdx;
    v40 = v26;
    v42 = v33;
    v34 = edgePair->m_edgeAlignment;
    edgePair->m_edgeAIdx = m_edgeAIdx;
    edgePair->m_edgeBIdx = m_edgeBIdx;
    edgePair->m_faceAIdx = m_faceAIdx;
    edgePair->m_faceBIdx = m_faceBIdx;
    *(_DWORD *)&edgePair->m_isValid = v38;
    edgePair->m_edgeAlignment = (float)(v34 + m_edgeAlignment) * 0.5;
    edgePair->m_distanceSquared = (float)(v27 + m_distanceSquared) * 0.5;
    edgePair->m_tStartA = fmaxf(m_tStartA, v31);
    edgePair->m_overlap = (float)(v30 + m_overlap) * 0.5;
    edgePair->m_tEndA = fminf(m_tEndA, v32);
    edgePair->m_tStartB = fmaxf(m_tStartB, v28);
    edgePair->m_tEndB = fminf(m_tEndB, v29);
  }
  return result;
}

// File Line: 199
// RVA: 0xB8EBE0
void __fastcall `anonymous namespace::SegmentPair::SegmentPair(
        SegmentPair *this,
        hkVector4f *SA,
        hkVector4f *EA,
        hkVector4f *SB,
        hkVector4f *EB)
{
  hkSimdFloat32 tEB; // [rsp+30h] [rbp-48h] BYREF
  hkSimdFloat32 tSB; // [rsp+40h] [rbp-38h] BYREF
  hkSimdFloat32 tEA; // [rsp+50h] [rbp-28h] BYREF
  hkSimdFloat32 tSA; // [rsp+60h] [rbp-18h] BYREF

  this->m_startA = (hkVector4f)SA->m_quad;
  this->m_endA = (hkVector4f)EA->m_quad;
  this->m_startB = (hkVector4f)SB->m_quad;
  this->m_endB = (hkVector4f)EB->m_quad;
  tEB.m_real = query.m_quad;
  tSB.m_real = aabbOut.m_quad;
  tEA.m_real = query.m_quad;
  tSA.m_real = aabbOut.m_quad;
  `anonymous namespace::SegmentPair::updateT(this, &tSA, &tEA, &tSB, &tEB);
}

// File Line: 204
// RVA: 0xB8EC60
void __fastcall `anonymous namespace::SegmentPair::updateT(
        SegmentPair *this,
        hkSimdFloat32 *tSA,
        hkSimdFloat32 *tEA,
        hkSimdFloat32 *tSB,
        hkSimdFloat32 *tEB)
{
  hkVector4f v5; // xmm2
  hkVector4f v6; // xmm3

  v5.m_quad = (__m128)this->m_endA;
  v6.m_quad = (__m128)this->m_endB;
  this->m_tStartA = (hkSimdFloat32)tSA->m_real;
  this->m_tEndA = (hkSimdFloat32)tEA->m_real;
  this->m_tStartB = (hkSimdFloat32)tSB->m_real;
  this->m_tEndB = (hkSimdFloat32)tEB->m_real;
  this->m_pSA.m_quad = _mm_add_ps(
                         _mm_mul_ps(_mm_sub_ps(v5.m_quad, this->m_startA.m_quad), tSA->m_real),
                         this->m_startA.m_quad);
  this->m_pEA.m_quad = _mm_add_ps(
                         _mm_mul_ps(_mm_sub_ps(v5.m_quad, this->m_startA.m_quad), tEA->m_real),
                         this->m_startA.m_quad);
  this->m_pSB.m_quad = _mm_add_ps(
                         _mm_mul_ps(_mm_sub_ps(v6.m_quad, this->m_startB.m_quad), tSB->m_real),
                         this->m_startB.m_quad);
  this->m_pEB.m_quad = _mm_add_ps(
                         _mm_mul_ps(_mm_sub_ps(v6.m_quad, this->m_startB.m_quad), tEB->m_real),
                         this->m_startB.m_quad);
}

// File Line: 217
// RVA: 0xB8ECE0
void __fastcall `anonymous namespace::SegmentPair::updateProjection(
        SegmentPair *this,
        hkVector4f *up,
        __int64 a3,
        hkVector4f *a4)
{
  hkVector4f *v6; // r9
  hkVector4f *v7; // r9
  hkVector4f *v8; // r9

  `anonymous namespace::SegmentPair::projectPoint((SegmentPair *)&this->m_pSA, up, &this->m_pSAProjected, a4);
  `anonymous namespace::SegmentPair::projectPoint((SegmentPair *)&this->m_pEA, up, &this->m_pEAProjected, v6);
  `anonymous namespace::SegmentPair::projectPoint((SegmentPair *)&this->m_pSB, up, &this->m_pSBProjected, v7);
  `anonymous namespace::SegmentPair::projectPoint((SegmentPair *)&this->m_pEB, up, &this->m_pEBProjected, v8);
}

// File Line: 225
// RVA: 0xB8F240
void __fastcall `anonymous namespace::SegmentPair::projectPoint(
        SegmentPair *this,
        hkVector4f *p,
        hkVector4f *up,
        hkVector4f *projOut)
{
  __m128 v4; // xmm1

  *up = this->m_startA;
  v4 = _mm_mul_ps(this->m_startA.m_quad, p->m_quad);
  up->m_quad = _mm_sub_ps(
                 up->m_quad,
                 _mm_mul_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v4, v4, 85), _mm_shuffle_ps(v4, v4, 0)),
                     _mm_shuffle_ps(v4, v4, 170)),
                   p->m_quad));
}

// File Line: 256
// RVA: 0xB8F280
bool __fastcall `anonymous namespace::SegmentPair::areIntervalsDisjoint(SegmentPair *this)
{
  return COERCE_FLOAT(*(_OWORD *)&this->m_tEndA) <= this->m_tStartA.m_real.m128_f32[0]
      || COERCE_FLOAT(*(_OWORD *)&this->m_tEndB) <= this->m_tStartB.m_real.m128_f32[0];
}

// File Line: 265
// RVA: 0xB8ED50
hkSimdFloat32 *__fastcall `anonymous namespace::SegmentPair::clippedDistanceSquared(
        SegmentPair *this,
        hkSimdFloat32 *result,
        hkVector4f *closestAminusClosestB)
{
  __m128 v3; // xmm13
  hkVector4f v4; // xmm14
  __m128 v5; // xmm12
  __m128 v6; // xmm1
  __m128 v7; // xmm2
  __m128 v8; // xmm11
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  __m128 v11; // xmm10
  __m128 v12; // xmm9
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm7
  __m128 v17; // xmm6
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  __m128 v20; // xmm1
  __m128 v21; // xmm5
  __m128 v22; // xmm1
  hkSimdFloat32 *v23; // rax
  __m128 v24; // xmm8
  __m128 v25; // xmm2
  __m128 v26; // xmm8
  __m128 v27; // xmm7
  __m128 v28; // xmm1
  __m128 v29; // xmm3
  __m128 v30; // xmm0
  __m128 v31; // xmm2
  __m128 v32; // xmm11
  __m128 v33; // xmm0
  __m128 v34; // xmm5
  __m128 v35; // xmm5

  v3 = _mm_sub_ps(this->m_pEA.m_quad, this->m_pSA.m_quad);
  v4.m_quad = (__m128)this->m_pSB;
  v5 = _mm_sub_ps(this->m_pEB.m_quad, v4.m_quad);
  v6 = _mm_mul_ps(v3, v5);
  v7 = _mm_sub_ps(v4.m_quad, this->m_pSA.m_quad);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)), _mm_shuffle_ps(v6, v6, 170));
  v9 = _mm_mul_ps(v3, v7);
  v10 = _mm_mul_ps(v7, v5);
  v11 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)), _mm_shuffle_ps(v10, v10, 170));
  v13 = _mm_mul_ps(v3, v3);
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  v15 = _mm_mul_ps(v5, v5);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v17 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v16, v14), _mm_mul_ps(v8, v8)), *(__m128 *)&epsilon);
  v18 = _mm_rcp_ps(v17);
  v19 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v18, v17)), v18);
  v20 = _mm_rcp_ps(v16);
  v21 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v20, v16)), v20);
  v22 = _mm_rcp_ps(v14);
  v23 = result;
  v24 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v22, v14));
  v25 = _mm_cmple_ps(v17, *(__m128 *)&epsilon);
  v26 = _mm_mul_ps(v24, v22);
  v27 = _mm_sub_ps(_mm_mul_ps(v16, v11), _mm_mul_ps(v12, v8));
  v28 = _mm_cmplt_ps(v27, v17);
  v29 = _mm_sub_ps(
          _mm_mul_ps(
            _mm_or_ps(
              _mm_andnot_ps(
                v25,
                _mm_mul_ps(_mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v28, v17), _mm_and_ps(v28, v27))), v19)),
              _mm_and_ps(v25, query.m_quad)),
            _mm_mul_ps(v8, v21)),
          _mm_mul_ps(v12, v21));
  v30 = _mm_cmplt_ps(v29, query.m_quad);
  v31 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v30, query.m_quad), _mm_and_ps(v29, v30)));
  v32 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v8, v26), v31), _mm_mul_ps(v11, v26));
  v33 = _mm_cmplt_ps(v32, query.m_quad);
  v34 = _mm_sub_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v33, query.m_quad), _mm_and_ps(v33, v32))), v3),
            this->m_pSA.m_quad),
          _mm_add_ps(_mm_mul_ps(v31, v5), v4.m_quad));
  *closestAminusClosestB = (hkVector4f)v34;
  v35 = _mm_mul_ps(v34, v34);
  result->m_real = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)),
                     _mm_shuffle_ps(v35, v35, 170));
  return v23;
}

// File Line: 277
// RVA: 0xB8EFC0
hkSimdFloat32 *__fastcall `anonymous namespace::SegmentPair::projectedDistanceSquared(
        SegmentPair *this,
        hkSimdFloat32 *result)
{
  __m128 v2; // xmm13
  hkVector4f v3; // xmm14
  __m128 v4; // xmm12
  __m128 v5; // xmm1
  __m128 v6; // xmm2
  __m128 v7; // xmm11
  __m128 v8; // xmm1
  __m128 v9; // xmm2
  __m128 v10; // xmm10
  __m128 v11; // xmm9
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm7
  __m128 v16; // xmm6
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm1
  __m128 v20; // xmm5
  __m128 v21; // xmm1
  hkSimdFloat32 *v22; // rax
  __m128 v23; // xmm8
  __m128 v24; // xmm2
  __m128 v25; // xmm8
  __m128 v26; // xmm7
  __m128 v27; // xmm1
  __m128 v28; // xmm3
  __m128 v29; // xmm0
  __m128 v30; // xmm2
  __m128 v31; // xmm11
  __m128 v32; // xmm0
  __m128 v33; // xmm5
  __m128 v34; // xmm5

  v2 = _mm_sub_ps(this->m_pEAProjected.m_quad, this->m_pSAProjected.m_quad);
  v3.m_quad = (__m128)this->m_pSBProjected;
  v4 = _mm_sub_ps(this->m_pEBProjected.m_quad, v3.m_quad);
  v5 = _mm_mul_ps(v2, v4);
  v6 = _mm_sub_ps(v3.m_quad, this->m_pSAProjected.m_quad);
  v7 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)), _mm_shuffle_ps(v5, v5, 170));
  v8 = _mm_mul_ps(v2, v6);
  v9 = _mm_mul_ps(v6, v4);
  v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v11 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
  v12 = _mm_mul_ps(v2, v2);
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  v14 = _mm_mul_ps(v4, v4);
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)), _mm_shuffle_ps(v14, v14, 170));
  v16 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v15, v13), _mm_mul_ps(v7, v7)), *(__m128 *)&epsilon);
  v17 = _mm_rcp_ps(v16);
  v18 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v17, v16)), v17);
  v19 = _mm_rcp_ps(v15);
  v20 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v19, v15)), v19);
  v21 = _mm_rcp_ps(v13);
  v22 = result;
  v23 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v21, v13));
  v24 = _mm_cmple_ps(v16, *(__m128 *)&epsilon);
  v25 = _mm_mul_ps(v23, v21);
  v26 = _mm_sub_ps(_mm_mul_ps(v15, v10), _mm_mul_ps(v11, v7));
  v27 = _mm_cmplt_ps(v26, v16);
  v28 = _mm_sub_ps(
          _mm_mul_ps(
            _mm_or_ps(
              _mm_andnot_ps(
                v24,
                _mm_mul_ps(_mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v27, v16), _mm_and_ps(v27, v26))), v18)),
              _mm_and_ps(v24, query.m_quad)),
            _mm_mul_ps(v7, v20)),
          _mm_mul_ps(v11, v20));
  v29 = _mm_cmplt_ps(v28, query.m_quad);
  v30 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v29, query.m_quad), _mm_and_ps(v28, v29)));
  v31 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v7, v25), v30), _mm_mul_ps(v10, v25));
  v32 = _mm_cmplt_ps(v31, query.m_quad);
  v33 = _mm_sub_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v32, query.m_quad), _mm_and_ps(v32, v31))), v2),
            this->m_pSAProjected.m_quad),
          _mm_add_ps(_mm_mul_ps(v30, v4), v3.m_quad));
  v34 = _mm_mul_ps(v33, v33);
  result->m_real = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
                     _mm_shuffle_ps(v34, v34, 170));
  return v22;
}

// File Line: 293
// RVA: 0xB8F2B0
__int64 __fastcall checkProjections(
        SegmentPair *segPair,
        hkaiNavMeshEdgeMatchingParameters *input,
        hkVector4f *up,
        hkVector4f *dirA,
        hkVector4f *dirB,
        hkSimdFloat32 *minA,
        hkSimdFloat32 *maxA,
        hkSimdFloat32 *minB,
        hkSimdFloat32 *maxB,
        float *intervalOverlapReal)
{
  __m128 v10; // xmm6
  __m128 v11; // xmm2
  __m128 v12; // xmm6
  __m128 v13; // xmm1
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm6
  __m128 v17; // xmm2
  __m128 v18; // xmm2
  __m128 v19; // xmm2
  __m128 v20; // xmm2
  hkSimdFloat32 v21; // xmm1
  __m128 m_real; // xmm0
  __m128 v23; // xmm5
  __m128 v24; // xmm2
  float v25; // xmm1_4
  __m128 v26; // xmm4
  __m128 v27; // xmm3
  float v28; // xmm2_4
  float v29; // xmm3_4

  v10 = _mm_mul_ps(_mm_sub_ps(dirA->m_quad, dirB->m_quad), (__m128)xmmword_141A711B0);
  v11 = _mm_mul_ps(up->m_quad, v10);
  v12 = _mm_add_ps(
          v10,
          _mm_mul_ps(
            _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
                _mm_shuffle_ps(v11, v11, 170))),
            up->m_quad));
  v13 = _mm_mul_ps(v12, v12);
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  v15 = _mm_rsqrt_ps(v14);
  v16 = _mm_mul_ps(
          v12,
          _mm_andnot_ps(
            _mm_cmple_ps(v14, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v15, v14), v15)),
              _mm_mul_ps(*(__m128 *)_xmm, v15))));
  v17 = _mm_mul_ps(segPair->m_pSA.m_quad, v16);
  minA->m_real = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
                   _mm_shuffle_ps(v17, v17, 170));
  v18 = _mm_mul_ps(segPair->m_pEA.m_quad, v16);
  maxA->m_real = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
                   _mm_shuffle_ps(v18, v18, 170));
  v19 = _mm_mul_ps(segPair->m_pSB.m_quad, v16);
  minB->m_real = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
                   _mm_shuffle_ps(v19, v19, 170));
  v20 = _mm_mul_ps(segPair->m_pEB.m_quad, v16);
  v21.m_real = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                 _mm_shuffle_ps(v20, v20, 170));
  *maxB = (hkSimdFloat32)v21.m_real;
  m_real = minB->m_real;
  if ( COERCE_FLOAT(*minB) > v21.m_real.m128_f32[0] )
  {
    *minB = (hkSimdFloat32)v21.m_real;
    *maxB = (hkSimdFloat32)m_real;
  }
  v23 = minB->m_real;
  v24 = maxA->m_real;
  LODWORD(v25) = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_000001), (__m128)LODWORD(FLOAT_0_000001), 0).m128_u32[0];
  if ( COERCE_FLOAT(*minB) > COERCE_FLOAT(*maxA) )
    return 3i64;
  v26 = maxB->m_real;
  v27 = minA->m_real;
  if ( COERCE_FLOAT(*maxB) < COERCE_FLOAT(*minA)
    || (float)(v24.m128_f32[0] - v27.m128_f32[0]) < v25
    || (float)(v26.m128_f32[0] - v23.m128_f32[0]) < v25 )
  {
    return 3i64;
  }
  v28 = fmin(v24.m128_f32[0], v26.m128_f32[0]) - fmax(v27.m128_f32[0], v23.m128_f32[0]);
  *intervalOverlapReal = v28;
  if ( v28 >= input->m_minEdgeOverlap )
    return 0xFFFFFFFFi64;
  v29 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0000099999997), (__m128)LODWORD(FLOAT_0_0000099999997), 0).m128_f32[0];
  if ( COERCE_FLOAT((unsigned int)(2 * COERCE_INT(v28 - (float)(maxA->m_real.m128_f32[0] - minA->m_real.m128_f32[0]))) >> 1) < v29
    || COERCE_FLOAT((unsigned int)(2 * COERCE_INT(v28 - (float)(maxB->m_real.m128_f32[0] - minB->m_real.m128_f32[0]))) >> 1) < v29 )
  {
    return 0xFFFFFFFFi64;
  }
  else
  {
    return 4i64;
  }
}

// File Line: 365
// RVA: 0xB8F4F0
__int64 __fastcall clipToMaxDistance(
        SegmentPair *segPair,
        hkaiNavMeshEdgeMatchingParameters *input,
        hkVector4f *up,
        ClipType clipType)
{
  __m128 v7; // xmm9
  __m128 v8; // xmm1
  __m128 v9; // xmm8
  __m128 v10; // xmm1
  __m128 v11; // xmm7
  __m128 v12; // xmm1
  __m128 v13; // xmm1
  __m128 v14; // xmm7
  __m128 v15; // xmm3
  __m128 v16; // xmm7
  __m128 v17; // xmm2
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __m128 v22; // xmm5
  __m128 v23; // xmm2
  __m128 v24; // xmm4
  __m128 v25; // xmm3
  __m128 v26; // xmm0
  __m128 v27; // xmm4
  __m128 v28; // xmm1
  __m128 v29; // xmm0
  __m128 v30; // xmm5
  __m128 v31; // xmm6
  __m128 v32; // xmm0
  __m128 v33; // xmm3
  __m128 v34; // xmm0
  hkSimdFloat32 v35; // xmm1
  __m128 v36; // xmm0
  __m128 v37; // xmm2
  __m128 v38; // xmm0
  hkSimdFloat32 v39; // xmm1
  __m128 v40; // xmm2
  __m128 v41; // xmm5
  __m128 v42; // xmm1
  __m128 v43; // xmm3
  __m128 v44; // xmm2
  __m128 v45; // xmm4
  __m128 v46; // xmm5
  __m128 v47; // xmm1
  __m128 v48; // xmm2
  __m128 v49; // xmm1
  unsigned int v50; // eax
  unsigned int v51; // ecx
  hkSimdFloat32 tEB; // [rsp+50h] [rbp-B8h] BYREF
  hkSimdFloat32 tSB; // [rsp+60h] [rbp-A8h] BYREF
  hkSimdFloat32 tEA; // [rsp+70h] [rbp-98h] BYREF
  hkSimdFloat32 tSA; // [rsp+80h] [rbp-88h] BYREF
  hkSimdFloat32 maxA; // [rsp+90h] [rbp-78h] BYREF
  hkSimdFloat32 minA; // [rsp+A0h] [rbp-68h] BYREF
  float intervalOverlapReal; // [rsp+128h] [rbp+20h] BYREF

  if ( clipType )
  {
    v12 = _mm_sub_ps(segPair->m_pSAProjected.m_quad, segPair->m_pEBProjected.m_quad);
    v7 = _mm_shuffle_ps((__m128)LODWORD(input->m_maxSeparation), (__m128)LODWORD(input->m_maxSeparation), 0);
    v13 = _mm_mul_ps(v12, v12);
    v14 = _mm_sub_ps(segPair->m_pSBProjected.m_quad, segPair->m_pEAProjected.m_quad);
    v15 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
            _mm_shuffle_ps(v13, v13, 170));
    v16 = _mm_mul_ps(v14, v14);
    v17 = _mm_rsqrt_ps(v15);
    v18 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v15, v17), v17)), _mm_mul_ps(*(__m128 *)_xmm, v17));
    v19 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
            _mm_shuffle_ps(v16, v16, 170));
    v9 = _mm_andnot_ps(_mm_cmple_ps(v15, (__m128)0i64), _mm_mul_ps(v18, v15));
    v20 = _mm_rsqrt_ps(v19);
    v11 = _mm_andnot_ps(
            _mm_cmple_ps(v19, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v20), v20)),
                _mm_mul_ps(*(__m128 *)_xmm, v20)),
              v19));
  }
  else
  {
    v7 = _mm_shuffle_ps((__m128)LODWORD(input->m_maxStepHeight), (__m128)LODWORD(input->m_maxStepHeight), 0);
    v8 = _mm_mul_ps(_mm_sub_ps(segPair->m_pEB.m_quad, segPair->m_pSA.m_quad), up->m_quad);
    v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
    v10 = _mm_mul_ps(_mm_sub_ps(segPair->m_pSB.m_quad, segPair->m_pEA.m_quad), up->m_quad);
    v11 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
            _mm_shuffle_ps(v10, v10, 170));
  }
  if ( COERCE_FLOAT((unsigned int)(2 * v9.m128_i32[0]) >> 1) < v7.m128_f32[0]
    && COERCE_FLOAT((unsigned int)(2 * v11.m128_i32[0]) >> 1) < v7.m128_f32[0] )
  {
    return 0xFFFFFFFFi64;
  }
  v22 = _mm_sub_ps(v11, v9);
  if ( COERCE_FLOAT((unsigned int)(2 * v22.m128_i32[0]) >> 1) < input->m_edgeParallelTolerance )
    return 0xFFFFFFFFi64;
  v23 = _mm_rcp_ps(v22);
  v24 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v22, v23)), v23), _mm_sub_ps(v7, v9));
  v25 = _mm_mul_ps(
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v22, v23)), v23),
          _mm_sub_ps(_mm_sub_ps((__m128)0i64, v7), v9));
  if ( v11.m128_f32[0] >= v9.m128_f32[0] )
  {
    v32 = _mm_cmplt_ps(v25, query.m_quad);
    v33 = _mm_or_ps(_mm_and_ps(v25, v32), _mm_andnot_ps(v32, query.m_quad));
    v34 = _mm_cmplt_ps(v24, query.m_quad);
    v30 = _mm_max_ps((__m128)0i64, v33);
    v31 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v24, v34), _mm_andnot_ps(v34, query.m_quad)));
  }
  else
  {
    v26 = _mm_cmplt_ps(v24, query.m_quad);
    v27 = _mm_and_ps(v24, v26);
    v28 = _mm_andnot_ps(v26, query.m_quad);
    v29 = _mm_cmplt_ps(v25, query.m_quad);
    v30 = _mm_max_ps((__m128)0i64, _mm_or_ps(v28, v27));
    v31 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v25, v29), _mm_andnot_ps(v29, query.m_quad)));
  }
  v35.m_real = (__m128)segPair->m_tStartA;
  v36 = _mm_sub_ps(segPair->m_tEndA.m_real, v35.m_real);
  v37 = _mm_add_ps(_mm_mul_ps(v36, v31), v35.m_real);
  v38 = _mm_add_ps(_mm_mul_ps(v36, v30), v35.m_real);
  v39.m_real = (__m128)segPair->m_tEndB;
  tEA.m_real = v37;
  v40 = _mm_sub_ps(segPair->m_tStartB.m_real, v39.m_real);
  tSA.m_real = v38;
  tEB.m_real = _mm_add_ps(_mm_mul_ps(v40, v30), v39.m_real);
  tSB.m_real = _mm_add_ps(_mm_mul_ps(v40, v31), v39.m_real);
  `anonymous namespace::SegmentPair::updateT(segPair, &tSA, &tEA, &tSB, &tEB);
  if ( `anonymous namespace::SegmentPair::areIntervalsDisjoint(segPair) )
    return 5i64;
  v41 = _mm_sub_ps(segPair->m_endA.m_quad, segPair->m_startA.m_quad);
  v42 = _mm_mul_ps(v41, v41);
  v43 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v42, v42, 85), _mm_shuffle_ps(v42, v42, 0)), _mm_shuffle_ps(v42, v42, 170));
  v44 = _mm_rsqrt_ps(v43);
  v45 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmple_ps(v43, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v44, v43), v44)),
              _mm_mul_ps(v44, *(__m128 *)_xmm))),
          v41);
  v46 = _mm_sub_ps(segPair->m_endB.m_quad, segPair->m_startB.m_quad);
  tEA.m_real = v45;
  v47 = _mm_mul_ps(v46, v46);
  v48 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v47, v47, 85), _mm_shuffle_ps(v47, v47, 0)), _mm_shuffle_ps(v47, v47, 170));
  v49 = _mm_rsqrt_ps(v48);
  tSA.m_real = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmple_ps(v48, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v49, v48), v49)),
                     _mm_mul_ps(v49, *(__m128 *)_xmm))),
                 v46);
  v50 = checkProjections(
          segPair,
          input,
          up,
          (hkVector4f *)&tEA,
          (hkVector4f *)&tSA,
          &minA,
          &maxA,
          &tEB,
          &tSB,
          &intervalOverlapReal);
  v51 = -1;
  if ( v50 != -1 )
    return v50;
  return v51;
}

// File Line: 465
// RVA: 0xB91260
__int64 __fastcall hkaiNavMeshGenerationUtils::_calculateConnectivity<hkaiNavMesh,0>(
        hkaiNavMeshGenerationUtils *this,
        hkVector4f *input,
        hkVector4f *up,
        hkaiNavMesh *characterHeight,
        hkaiNavMesh *meshA,
        hkaiNavMesh *meshB,
        hkaiEdgeGeometryRaycaster *raycaster,
        int edgeAIdx,
        int edgeBIdx,
        int faceAIdx,
        int faceBIdx,
        hkaiNavMeshGenerationUtils::EdgePair *edgePairOut)
{
  unsigned int v12; // edi
  hkaiNavMesh *v13; // r12
  int v14; // r14d
  unsigned __int64 m_data; // r9
  unsigned __int64 v18; // rcx
  __m128 m_quad; // xmm12
  hkaiNavMesh::Edge *v21; // rdx
  __int64 v22; // rax
  __m128 v23; // xmm0
  hkVector4f *v24; // rcx
  __int64 m_a; // rax
  hkVector4f v26; // xmm0
  __int64 m_b; // rax
  __m128 v28; // xmm5
  __m128 v29; // xmm1
  __m128 v30; // xmm7
  __m128 v31; // xmm3
  __m128 v32; // xmm2
  __m128 v33; // xmm8
  __m128 v34; // xmm1
  __m128 v35; // xmm3
  __m128 v36; // xmm2
  __m128 v37; // xmm10
  __m128 v38; // xmm2
  __m128 v39; // xmm10
  __m128 v40; // xmm1
  __m128 v41; // xmm2
  __m128 v42; // xmm4
  __m128 v43; // xmm1
  __m128 v44; // xmm6
  __m128 v45; // xmm3
  __m128 v46; // xmm2
  __m128 v47; // xmm1
  __m128 v48; // xmm5
  __m128 v49; // xmm3
  __m128 v50; // xmm2
  __m128 v51; // xmm4
  __int64 result; // rax
  __m128 v53; // xmm0
  __m128 v54; // xmm6
  __m128 v55; // xmm6
  __m128 v56; // xmm1
  __m128 v57; // xmm3
  __m128 v58; // xmm2
  __m128 v59; // xmm6
  __m128 v60; // xmm2
  __m128 v61; // xmm1
  __m128 v62; // xmm2
  __m128 v63; // xmm7
  __m128 v64; // xmm1
  __m128 v65; // xmm5
  __m128 v66; // xmm3
  __m128 v67; // xmm2
  __m128 v68; // xmm1
  __m128 v69; // xmm7
  __m128 v70; // xmm3
  __m128 v71; // xmm2
  __m128 v72; // xmm4
  __m128 v73; // xmm5
  __m128 v74; // xmm6
  __m128 v75; // xmm1
  __m128 v76; // xmm3
  __m128 v77; // xmm14
  __m128 v78; // xmm10
  __m128 v79; // xmm8
  float v80; // xmm7_4
  __m128 v81; // xmm4
  __m128 v82; // xmm1
  __int64 v83; // r8
  hkVector4f *v84; // r9
  __m128 v85; // xmm1
  __m128 v86; // xmm6
  __int64 v87; // r8
  hkVector4f *v88; // r9
  int v89; // xmm1_4
  int v90; // xmm1_4
  __m128 v91; // xmm15
  __m128 v92; // xmm5
  __m128 v93; // xmm1
  __m128 v94; // xmm4
  __m128 v95; // xmm1
  __m128 v96; // xmm0
  __m128 v97; // xmm2
  __m128 v98; // xmm0
  __m128 v99; // xmm5
  __m128 v100; // xmm5
  __m128 v101; // xmm3
  __m128 v102; // xmm2
  __m128 v103; // xmm14
  __m128 v104; // xmm4
  __m128 v105; // xmm1
  __m128 v106; // xmm3
  __m128 v107; // xmm1
  __m128 v108; // xmm0
  __m128 v109; // xmm1
  __m128 v110; // xmm0
  __m128 v111; // xmm4
  __m128 v112; // xmm4
  __m128 v113; // xmm3
  __m128 v114; // xmm2
  __m128 v115; // xmm7
  __m128 v116; // xmm7
  __m128 v117; // xmm12
  __m128 v118; // xmm1
  __m128 v119; // xmm12
  __m128 v120; // xmm3
  __m128 v121; // xmm2
  __m128 v122; // xmm7
  __m128 v123; // xmm2
  __m128 v124; // xmm7
  __m128 v125; // xmm1
  __m128 v126; // xmm3
  __m128 v127; // xmm2
  __m128 v128; // xmm4
  __m128 v129; // xmm0
  __m128 v130; // xmm12
  __m128 v131; // xmm2
  __m128 v132; // xmm12
  __m128 v133; // xmm1
  __m128 v134; // xmm1
  __m128 v135; // xmm2
  __m128 v136; // xmm1
  __m128 v137; // xmm1
  __m128 v138; // xmm4
  __m128 v139; // xmm1
  __m128 v140; // xmm1
  __m128 v141; // xmm5
  __m128 v142; // xmm1
  __m128 v143; // xmm1
  __m128 v144; // xmm6
  float v145; // xmm1_4
  float v146; // xmm6_4
  __m128 v147; // xmm0
  hkVector4f *v148; // r9
  __m128 v149; // xmm10
  __m128 m_real; // xmm8
  hkVector4f *v151; // r9
  __m128 v152; // xmm1
  __m128 v153; // xmm7
  __m128 v154; // xmm2
  __m128 v155; // xmm1
  __m128 v156; // xmm3
  __m128 v157; // xmm1
  __m128 v158; // xmm2
  __m128 v159; // xmm0
  __m128 v160; // xmm14
  __m128 v161; // xmm7
  __m128 v162; // xmm7
  __m128 v163; // xmm5
  __m128 v164; // xmm5
  __m128 v165; // xmm3
  __m128 v166; // xmm1
  __m128 v167; // xmm6
  __m128 v168; // xmm2
  __m128 v169; // xmm3
  __m128 v170; // xmm1
  __m128 v171; // xmm6
  __m128 v172; // xmm2
  __m128 v173; // xmm0
  __m128 v174; // xmm1
  __m128 v175; // xmm1
  __m128 v176; // xmm4
  __m128 v177; // xmm1
  __m128 v178; // xmm5
  __m128 v179; // xmm0
  __m128 v180; // xmm1
  __m128 v181; // xmm6
  __m128 v182; // xmm3
  __m128 v183; // xmm1
  __m128 v184; // xmm0
  __m128 v185; // xmm1
  __m128 v186; // xmm0
  __m128 v187; // xmm15
  __m128 v188; // xmm6
  __m128 v189; // xmm6
  __m128 v190; // xmm3
  __m128 v191; // xmm10
  __m128 v192; // xmm2
  __m128 v193; // xmm10
  __m128 v194; // xmm5
  __m128 v195; // xmm3
  __m128 v196; // xmm2
  __m128 v197; // xmm4
  __m128 v198; // xmm1
  __m128 v199; // xmm1
  __m128 v200; // xmm3
  __m128 v201; // xmm1
  __m128 v202; // xmm4
  __m128 v203; // xmm0
  hkVector4f *EB; // [rsp+20h] [rbp-A8h]
  hkVector4f *EBa; // [rsp+20h] [rbp-A8h]
  hkVector4f EA; // [rsp+48h] [rbp-80h] BYREF
  hkVector4f furthestPointOut; // [rsp+58h] [rbp-70h] BYREF
  __m256i SA; // [rsp+68h] [rbp-60h] BYREF
  hkSimdFloat32 v209; // [rsp+88h] [rbp-40h] BYREF
  hkVector4f dirB; // [rsp+98h] [rbp-30h] BYREF
  hkVector4f dirA; // [rsp+A8h] [rbp-20h] BYREF
  SegmentPair segPair; // [rsp+B8h] [rbp-10h] BYREF
  hkVector4f normalB; // [rsp+1B8h] [rbp+F0h] BYREF
  hkVector4f faceIndex[4]; // [rsp+1C8h] [rbp+100h] BYREF
  bool v215; // [rsp+2B8h] [rbp+1F0h]
  hkSimdFloat32 *characterHeighta; // [rsp+2C8h] [rbp+200h]
  hkaiNavMesh *mesh; // [rsp+2D8h] [rbp+210h]
  hkaiEdgeGeometryRaycaster *vars0; // [rsp+2E0h] [rbp+218h]
  void *retaddr; // [rsp+2E8h] [rbp+220h] BYREF
  int v220; // [rsp+2F0h] [rbp+228h]
  unsigned int faceIdx; // [rsp+300h] [rbp+238h]
  hkaiNavMeshGenerationUtils::EdgePair *edgePair; // [rsp+308h] [rbp+240h]

  faceIdx = (unsigned int)up;
  v13 = mesh;
  v14 = (int)retaddr;
  v215 = vars0 == 0i64;
  m_data = (unsigned __int64)characterHeight->m_edges.m_data;
  v18 = (unsigned __int64)characterHeight->m_vertices.m_data;
  m_quad = input->m_quad;
  v21 = mesh->m_edges.m_data;
  v22 = *(int *)(m_data + 20i64 * (int)retaddr + 4);
  v209.m_real = *(__m128 *)(v18 + 16i64 * *(int *)(m_data + 20i64 * (int)retaddr));
  *(hkSimdFloat32 *)SA.m256i_i8 = (hkSimdFloat32)v209.m_real;
  v23 = *(__m128 *)(v18 + 16 * v22);
  v24 = mesh->m_vertices.m_data;
  m_a = v21[v220].m_a;
  EA.m_quad = v23;
  v26.m_quad = (__m128)v24[m_a];
  m_b = v21[v220].m_b;
  SA.m256i_i64[3] = v26.m_quad.m128_i64[1];
  *(hkVector4f *)&SA.m256i_u64[1] = (hkVector4f)v26.m_quad;
  furthestPointOut.m_quad = (__m128)v24[m_b];
  `anonymous namespace::SegmentPair::SegmentPair(
    &segPair,
    (hkVector4f *)&SA,
    &EA,
    (hkVector4f *)&SA.m256i_u64[1],
    &furthestPointOut);
  v28 = _mm_sub_ps(segPair.m_endA.m_quad, segPair.m_startA.m_quad);
  v29 = _mm_mul_ps(v28, v28);
  v30 = _mm_sub_ps(segPair.m_endB.m_quad, segPair.m_startB.m_quad);
  v31 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)), _mm_shuffle_ps(v29, v29, 170));
  v32 = _mm_rsqrt_ps(v31);
  v33 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmple_ps(v31, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v32, v31), v32)),
              _mm_mul_ps(v32, *(__m128 *)_xmm))),
          v28);
  v34 = _mm_mul_ps(v30, v30);
  dirA.m_quad = v33;
  v35 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)), _mm_shuffle_ps(v34, v34, 170));
  v36 = _mm_rsqrt_ps(v35);
  v37 = _mm_andnot_ps(
          _mm_cmple_ps(v35, (__m128)0i64),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v36, v35), v36)), _mm_mul_ps(v36, *(__m128 *)_xmm)));
  v38 = _mm_mul_ps(v28, m_quad);
  v39 = _mm_mul_ps(v37, v30);
  dirB.m_quad = v39;
  v40 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)), _mm_shuffle_ps(v38, v38, 170));
  v41 = _mm_mul_ps(v30, m_quad);
  v42 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps((__m128)0i64, v40), m_quad), v28);
  v43 = _mm_mul_ps(v42, v42);
  v44 = _mm_add_ps(
          _mm_mul_ps(
            _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)),
                _mm_shuffle_ps(v41, v41, 170))),
            m_quad),
          v30);
  v45 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)), _mm_shuffle_ps(v43, v43, 170));
  v46 = _mm_rsqrt_ps(v45);
  v47 = _mm_mul_ps(v44, v44);
  v48 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmple_ps(v45, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v46, v45), v46)),
              _mm_mul_ps(v46, *(__m128 *)_xmm))),
          v42);
  v49 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v47, v47, 85), _mm_shuffle_ps(v47, v47, 0)), _mm_shuffle_ps(v47, v47, 170));
  v50 = _mm_rsqrt_ps(v49);
  v51 = _mm_mul_ps(
          _mm_mul_ps(
            _mm_andnot_ps(
              _mm_cmple_ps(v49, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v50, v49), v50)),
                _mm_mul_ps(v50, *(__m128 *)_xmm))),
            v44),
          v48);
  *(float *)&retaddr = 0.0
                     - (float)((float)(_mm_shuffle_ps(v51, v51, 85).m128_f32[0] + _mm_shuffle_ps(v51, v51, 0).m128_f32[0])
                             + _mm_shuffle_ps(v51, v51, 170).m128_f32[0]);
  if ( *(float *)&retaddr < *(float *)&this[16] )
    return 0i64;
  v53 = _mm_sub_ps(v33, v39);
  v54 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v53),
          _mm_mul_ps(_mm_shuffle_ps(v53, v53, 201), m_quad));
  v55 = _mm_shuffle_ps(v54, v54, 201);
  v56 = _mm_mul_ps(v55, v55);
  v57 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v56, v56, 85), _mm_shuffle_ps(v56, v56, 0)), _mm_shuffle_ps(v56, v56, 170));
  v58 = _mm_rsqrt_ps(v57);
  v59 = _mm_mul_ps(
          v55,
          _mm_andnot_ps(
            _mm_cmple_ps(v57, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v58, v57), v58)),
              _mm_mul_ps(v58, *(__m128 *)_xmm))));
  v60 = _mm_mul_ps(v59, v33);
  v61 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v60, v60, 85), _mm_shuffle_ps(v60, v60, 0)), _mm_shuffle_ps(v60, v60, 170));
  v62 = _mm_mul_ps(v59, v39);
  v63 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps((__m128)0i64, v61), v59), v33);
  v64 = _mm_mul_ps(v63, v63);
  v65 = _mm_add_ps(
          _mm_mul_ps(
            _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v62, v62, 85), _mm_shuffle_ps(v62, v62, 0)),
                _mm_shuffle_ps(v62, v62, 170))),
            v59),
          v39);
  v66 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v64, v64, 85), _mm_shuffle_ps(v64, v64, 0)), _mm_shuffle_ps(v64, v64, 170));
  v67 = _mm_rsqrt_ps(v66);
  v68 = _mm_mul_ps(v65, v65);
  v69 = _mm_mul_ps(
          v63,
          _mm_andnot_ps(
            _mm_cmple_ps(v66, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v67, v66), v67)),
              _mm_mul_ps(v67, *(__m128 *)_xmm))));
  v70 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v68, v68, 85), _mm_shuffle_ps(v68, v68, 0)), _mm_shuffle_ps(v68, v68, 170));
  v71 = _mm_rsqrt_ps(v70);
  v72 = _mm_mul_ps(
          _mm_mul_ps(
            _mm_andnot_ps(
              _mm_cmple_ps(v70, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v71, v70), v71)),
                _mm_mul_ps(v71, *(__m128 *)_xmm))),
            v65),
          v69);
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(
                      (float)(_mm_shuffle_ps(v72, v72, 85).m128_f32[0] + _mm_shuffle_ps(v72, v72, 0).m128_f32[0])
                    + _mm_shuffle_ps(v72, v72, 170).m128_f32[0]) ^ _xmm[0]) < *(float *)&this[20] )
    return 1i64;
  result = checkProjections(
             &segPair,
             (hkaiNavMeshEdgeMatchingParameters *)this,
             input,
             &dirA,
             &dirB,
             (hkSimdFloat32 *)&furthestPointOut,
             (hkSimdFloat32 *)&SA,
             (hkSimdFloat32 *)&EA,
             (hkSimdFloat32 *)&SA.m256i_u64[1],
             (float *)&retaddr);
  if ( (_DWORD)result != -1 )
    return result;
  v73 = furthestPointOut.m_quad;
  v74 = EA.m_quad;
  edgePair->m_edgeAIdx = v14;
  edgePair->m_edgeBIdx = v220;
  v75 = *(__m128 *)SA.m256i_i8;
  v76 = *(__m128 *)&SA.m256i_u64[1];
  LODWORD(edgePair->m_overlap) = (_DWORD)retaddr;
  LODWORD(edgePair->m_edgeAlignment) = (_DWORD)retaddr;
  edgePair->m_distanceSquared = -1.0;
  edgePair->m_isValid = 1;
  v77 = _mm_sub_ps(v73, v74);
  edgePair->m_faceAIdx = v12;
  edgePair->m_faceBIdx = faceIdx;
  v78 = _mm_div_ps(query.m_quad, _mm_sub_ps(v75, v73));
  v79 = _mm_div_ps(query.m_quad, _mm_sub_ps(v76, v74));
  *(float *)&retaddr = FLOAT_0_001;
  v80 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0).m128_f32[0];
  if ( COERCE_FLOAT((unsigned int)(2 * v77.m128_i32[0]) >> 1) >= v80 )
  {
    if ( v73.m128_f32[0] > v74.m128_f32[0] )
    {
      *(_OWORD *)&SA.m256i_u64[1] = 0i64;
      v81 = _mm_mul_ps(v79, v77);
      goto LABEL_12;
    }
    *(__m128 *)&SA.m256i_u64[1] = _mm_mul_ps(_mm_sub_ps(v74, v73), v78);
  }
  else
  {
    *(_OWORD *)&SA.m256i_u64[1] = 0i64;
  }
  v81 = 0i64;
LABEL_12:
  if ( COERCE_FLOAT((unsigned int)(2 * COERCE_INT(v75.m128_f32[0] - v76.m128_f32[0])) >> 1) < v80 )
  {
    v82 = query.m_quad;
LABEL_17:
    EA.m_quad = query.m_quad;
    goto LABEL_18;
  }
  if ( v75.m128_f32[0] <= v76.m128_f32[0] )
  {
    v82 = _mm_mul_ps(_mm_sub_ps(v75, v74), v79);
    goto LABEL_17;
  }
  v82 = query.m_quad;
  EA.m_quad = _mm_mul_ps(_mm_sub_ps(v76, v73), v78);
LABEL_18:
  furthestPointOut.m_quad = _mm_sub_ps(query.m_quad, v82);
  *(__m128 *)SA.m256i_i8 = _mm_sub_ps(query.m_quad, v81);
  `anonymous namespace::SegmentPair::updateT(
    &segPair,
    (hkSimdFloat32 *)&SA.m256i_u64[1],
    (hkSimdFloat32 *)&EA,
    (hkSimdFloat32 *)&furthestPointOut,
    (hkSimdFloat32 *)&SA);
  if ( `anonymous namespace::SegmentPair::areIntervalsDisjoint(&segPair) )
    return 5i64;
  `anonymous namespace::SegmentPair::clippedDistanceSquared(
    &segPair,
    (hkSimdFloat32 *)&furthestPointOut,
    (hkVector4f *)&SA);
  v85 = _mm_mul_ps(*(__m128 *)SA.m256i_i8, input->m_quad);
  if ( COERCE_FLOAT((unsigned int)(2
                                 * COERCE_INT(
                                     (float)(_mm_shuffle_ps(v85, v85, 85).m128_f32[0]
                                           + _mm_shuffle_ps(v85, v85, 0).m128_f32[0])
                                   + _mm_shuffle_ps(v85, v85, 170).m128_f32[0])) >> 1) > _mm_shuffle_ps(
                                                                                           (__m128)*(_DWORD *)this,
                                                                                           (__m128)*(_DWORD *)this,
                                                                                           0).m128_f32[0] )
    return 6i64;
  if ( v215
    || (result = clipToMaxDistance(&segPair, (hkaiNavMeshEdgeMatchingParameters *)this, input, CLIP_MAX_HEIGHT),
        (_DWORD)result == -1) )
  {
    `anonymous namespace::SegmentPair::updateProjection(&segPair, input, v83, v84);
    v86 = (__m128)COERCE_UNSIGNED_INT(*(float *)&this[4] * *(float *)&this[4]);
    `anonymous namespace::SegmentPair::projectedDistanceSquared(&segPair, (hkSimdFloat32 *)&SA);
    if ( *(float *)SA.m256i_i32 > _mm_shuffle_ps(v86, v86, 0).m128_f32[0] )
      return 2i64;
    if ( v215
      || (result = clipToMaxDistance(&segPair, (hkaiNavMeshEdgeMatchingParameters *)this, input, CLIP_MAX_SEPARATION),
          (_DWORD)result == -1) )
    {
      v89 = segPair.m_tEndA.m_real.m128_i32[0];
      LODWORD(edgePair->m_tStartA) = segPair.m_tStartA.m_real.m128_i32[0];
      LODWORD(edgePair->m_tEndA) = v89;
      v90 = segPair.m_tEndB.m_real.m128_i32[0];
      LODWORD(edgePair->m_tStartB) = segPair.m_tStartB.m_real.m128_i32[0];
      LODWORD(edgePair->m_tEndB) = v90;
      `anonymous namespace::SegmentPair::updateProjection(&segPair, input, v87, v88);
      v91 = _mm_sub_ps(segPair.m_pSBProjected.m_quad, segPair.m_pEBProjected.m_quad);
      v92 = _mm_sub_ps(
              segPair.m_pSBProjected.m_quad,
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_sub_ps(segPair.m_pEAProjected.m_quad, segPair.m_pSAProjected.m_quad),
                  (__m128)xmmword_141A711B0),
                segPair.m_pSAProjected.m_quad));
      v93 = _mm_mul_ps(v91, v91);
      v94 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v93, v93, 85), _mm_shuffle_ps(v93, v93, 0)),
              _mm_shuffle_ps(v93, v93, 170));
      v95 = _mm_mul_ps(v92, v91);
      v96 = _mm_rcp_ps(v94);
      v97 = _mm_mul_ps(
              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v94, v96)), v96),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v95, v95, 85), _mm_shuffle_ps(v95, v95, 0)),
                _mm_shuffle_ps(v95, v95, 170)));
      v98 = _mm_cmplt_ps(v97, query.m_quad);
      v99 = _mm_sub_ps(
              v92,
              _mm_mul_ps(
                _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v98, query.m_quad), _mm_and_ps(v97, v98))),
                v91));
      v100 = _mm_mul_ps(v99, v99);
      v101 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v100, v100, 85), _mm_shuffle_ps(v100, v100, 0)),
               _mm_shuffle_ps(v100, v100, 170));
      v102 = _mm_rsqrt_ps(v101);
      v100.m128_f32[0] = _mm_andnot_ps(
                           _mm_cmple_ps(v101, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_mul_ps(
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v101, v102), v102)),
                               _mm_mul_ps(v102, *(__m128 *)_xmm)),
                             v101)).m128_f32[0];
      v103 = _mm_sub_ps(segPair.m_pSAProjected.m_quad, segPair.m_pEAProjected.m_quad);
      v104 = _mm_sub_ps(
               segPair.m_pSAProjected.m_quad,
               _mm_add_ps(
                 _mm_mul_ps(
                   _mm_sub_ps(segPair.m_pEBProjected.m_quad, segPair.m_pSBProjected.m_quad),
                   (__m128)xmmword_141A711B0),
                 segPair.m_pSBProjected.m_quad));
      v105 = _mm_mul_ps(v103, v103);
      v106 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v105, v105, 85), _mm_shuffle_ps(v105, v105, 0)),
               _mm_shuffle_ps(v105, v105, 170));
      v107 = _mm_mul_ps(v104, v103);
      v108 = _mm_rcp_ps(v106);
      v109 = _mm_mul_ps(
               _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v106, v108)), v108),
               _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v107, v107, 85), _mm_shuffle_ps(v107, v107, 0)),
                 _mm_shuffle_ps(v107, v107, 170)));
      v110 = _mm_cmplt_ps(v109, query.m_quad);
      v111 = _mm_sub_ps(
               v104,
               _mm_mul_ps(
                 _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v109, v110), _mm_andnot_ps(v110, query.m_quad))),
                 v103));
      v112 = _mm_mul_ps(v111, v111);
      v113 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v112, v112, 85), _mm_shuffle_ps(v112, v112, 0)),
               _mm_shuffle_ps(v112, v112, 170));
      v114 = _mm_rsqrt_ps(v113);
      v115 = _mm_sub_ps(
               _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), dirA.m_quad),
               _mm_mul_ps(_mm_shuffle_ps(dirA.m_quad, dirA.m_quad, 201), m_quad));
      v112.m128_f32[0] = _mm_andnot_ps(
                           _mm_cmple_ps(v113, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_mul_ps(
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v113, v114), v114)),
                               _mm_mul_ps(v114, *(__m128 *)_xmm)),
                             v113)).m128_f32[0];
      v116 = _mm_shuffle_ps(v115, v115, 201);
      v117 = _mm_sub_ps(
               _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), dirB.m_quad),
               _mm_mul_ps(_mm_shuffle_ps(dirB.m_quad, dirB.m_quad, 201), m_quad));
      edgePair->m_distanceSquared = (float)((float)(v112.m128_f32[0] + v100.m128_f32[0]) * 0.5)
                                  * (float)((float)(v112.m128_f32[0] + v100.m128_f32[0]) * 0.5);
      v118 = _mm_mul_ps(v116, v116);
      v119 = _mm_shuffle_ps(v117, v117, 201);
      v120 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v118, v118, 85), _mm_shuffle_ps(v118, v118, 0)),
               _mm_shuffle_ps(v118, v118, 170));
      v121 = _mm_rsqrt_ps(v120);
      v122 = _mm_mul_ps(
               v116,
               _mm_andnot_ps(
                 _mm_cmple_ps(v120, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v121, v120), v121)),
                   _mm_mul_ps(v121, *(__m128 *)_xmm))));
      v123 = _mm_mul_ps(v122, v209.m_real);
      v124 = _mm_shuffle_ps(
               v122,
               _mm_unpackhi_ps(
                 v122,
                 _mm_sub_ps(
                   (__m128)0i64,
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v123, v123, 85), _mm_shuffle_ps(v123, v123, 0)),
                     _mm_shuffle_ps(v123, v123, 170)))),
               196);
      v125 = _mm_mul_ps(v119, v119);
      *(__m128 *)&SA.m256i_u64[1] = v124;
      v126 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v125, v125, 85), _mm_shuffle_ps(v125, v125, 0)),
               _mm_shuffle_ps(v125, v125, 170));
      v127 = _mm_rsqrt_ps(v126);
      v128 = _mm_cmple_ps(v126, (__m128)0i64);
      v129 = _mm_mul_ps(_mm_mul_ps(v127, v126), v127);
      v126.m128_f32[0] = _mm_shuffle_ps((__m128)*(_DWORD *)&this[8], (__m128)*(_DWORD *)&this[8], 0).m128_f32[0];
      v130 = _mm_mul_ps(
               v119,
               _mm_andnot_ps(v128, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v129), _mm_mul_ps(v127, *(__m128 *)_xmm))));
      v131 = _mm_mul_ps(v130, *(__m128 *)&SA.m256i_u64[2]);
      v132 = _mm_shuffle_ps(
               v130,
               _mm_unpackhi_ps(
                 v130,
                 _mm_sub_ps(
                   (__m128)0i64,
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v131, v131, 85), _mm_shuffle_ps(v131, v131, 0)),
                     _mm_shuffle_ps(v131, v131, 170)))),
               196);
      v133 = _mm_mul_ps(segPair.m_pSB.m_quad, v124);
      EA.m_quad = v132;
      v134 = _mm_shuffle_ps(v133, _mm_unpackhi_ps(v133, v124), 196);
      v135 = _mm_add_ps(_mm_shuffle_ps(v134, v134, 78), v134);
      v136 = _mm_mul_ps(segPair.m_pEB.m_quad, v124);
      v137 = _mm_shuffle_ps(v136, _mm_unpackhi_ps(v136, v124), 196);
      v138 = _mm_add_ps(_mm_shuffle_ps(v137, v137, 78), v137);
      v139 = _mm_mul_ps(segPair.m_pSA.m_quad, v132);
      v140 = _mm_shuffle_ps(v139, _mm_unpackhi_ps(v139, v132), 196);
      v141 = _mm_add_ps(_mm_shuffle_ps(v140, v140, 78), v140);
      v142 = _mm_mul_ps(segPair.m_pEA.m_quad, v132);
      v143 = _mm_shuffle_ps(v142, _mm_unpackhi_ps(v142, v132), 196);
      v144 = _mm_add_ps(_mm_shuffle_ps(v143, v143, 78), v143);
      v145 = 0.0 - v126.m128_f32[0];
      if ( (float)(_mm_shuffle_ps(v135, v135, 177).m128_f32[0] + v135.m128_f32[0]) < (float)(0.0 - v126.m128_f32[0])
        || (float)(_mm_shuffle_ps(v138, v138, 177).m128_f32[0] + v138.m128_f32[0]) < v145
        || (float)(_mm_shuffle_ps(v141, v141, 177).m128_f32[0] + v141.m128_f32[0]) < v145
        || (float)(_mm_shuffle_ps(v144, v144, 177).m128_f32[0] + v144.m128_f32[0]) < v145 )
      {
        return 7i64;
      }
      else
      {
        v146 = _mm_shuffle_ps((__m128)*(_DWORD *)&this[12], (__m128)*(_DWORD *)&this[12], 0).m128_f32[0];
        findFurthestVertexOfFaceBehindLine_hkaiNavMesh_0_(
          (hkSimdFloat32 *)&SA.m256i_u64[2],
          v13,
          faceIdx,
          (hkVector4f *)&SA.m256i_u64[1]);
        if ( *(float *)&SA.m256i_i32[4] < v146 )
          return 8i64;
        findFurthestVertexOfFaceBehindLine_hkaiNavMesh_0_((hkSimdFloat32 *)&SA.m256i_u64[2], characterHeight, v12, &EA);
        if ( *(float *)&SA.m256i_i32[4] < v146 )
          return 8i64;
        if ( !vars0 && v146 <= 0.0 )
          return 0xFFFFFFFFi64;
        v147 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
        EA.m_quad = _mm_xor_ps(v147, v132);
        *(__m128 *)&SA.m256i_u64[1] = _mm_xor_ps(v147, v124);
        findFurthestVertexOfFaceBehindLine_hkaiNavMesh_1_(
          (hkSimdFloat32 *)&SA.m256i_u64[2],
          characterHeight,
          v12,
          (hkVector4f *)&SA.m256i_u64[1],
          &furthestPointOut);
        findFurthestVertexOfFaceBehindLine_hkaiNavMesh_1_(&v209, v13, faceIdx, &EA, (hkVector4f *)&SA.m256i_u64[1]);
        v149 = *(__m128 *)&SA.m256i_u64[2];
        if ( *(float *)&SA.m256i_i32[4] > 0.0 )
        {
          m_real = v209.m_real;
          if ( v209.m_real.m128_f32[0] > 0.0 )
          {
            if ( this[52] )
            {
              `anonymous namespace::SegmentPair::projectPoint(
                (SegmentPair *)&furthestPointOut,
                input,
                &furthestPointOut,
                v148);
              `anonymous namespace::SegmentPair::projectPoint(
                (SegmentPair *)&SA.m256i_u64[1],
                input,
                (hkVector4f *)&SA.m256i_u64[1],
                v151);
              v152 = _mm_mul_ps(v103, v103);
              v153 = _mm_sub_ps(segPair.m_pSAProjected.m_quad, furthestPointOut.m_quad);
              v154 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v152, v152, 85), _mm_shuffle_ps(v152, v152, 0)),
                       _mm_shuffle_ps(v152, v152, 170));
              v155 = _mm_mul_ps(v153, v103);
              v156 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v155, v155, 85), _mm_shuffle_ps(v155, v155, 0)),
                       _mm_shuffle_ps(v155, v155, 170));
              v157 = _mm_rcp_ps(v154);
              v158 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v157, v154)), v157), v156);
              v159 = _mm_mul_ps(v158, v103);
              v160 = _mm_mul_ps(v103, v103);
              v161 = _mm_add_ps(_mm_sub_ps(v153, v159), furthestPointOut.m_quad);
              v162 = _mm_shuffle_ps(v161, _mm_unpackhi_ps(v161, v158), 196);
              v163 = _mm_sub_ps(segPair.m_pSAProjected.m_quad, v162);
              v164 = _mm_mul_ps(v163, v163);
              v165 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v160, v160, 85), _mm_shuffle_ps(v160, v160, 0)),
                       _mm_shuffle_ps(v160, v160, 170));
              v166 = _mm_rsqrt_ps(v165);
              v167 = _mm_cmple_ps(v165, (__m128)0i64);
              v168 = _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v165, v166), v166)),
                         _mm_mul_ps(*(__m128 *)_xmm, v166)),
                       v165);
              v169 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v164, v164, 85), _mm_shuffle_ps(v164, v164, 0)),
                       _mm_shuffle_ps(v164, v164, 170));
              v170 = _mm_rsqrt_ps(v169);
              v171 = _mm_mul_ps(_mm_andnot_ps(v167, v168), (__m128)xmmword_141A711B0);
              v172 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v169, v170), v170));
              v173 = _mm_mul_ps(*(__m128 *)_xmm, v170);
              v174 = _mm_sub_ps(segPair.m_pEAProjected.m_quad, v162);
              v175 = _mm_mul_ps(v174, v174);
              v176 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v175, v175, 85), _mm_shuffle_ps(v175, v175, 0)),
                       _mm_shuffle_ps(v175, v175, 170));
              v177 = _mm_rsqrt_ps(v176);
              v178 = _mm_max_ps(
                       _mm_andnot_ps(_mm_cmple_ps(v169, (__m128)0i64), _mm_mul_ps(_mm_mul_ps(v172, v173), v169)),
                       _mm_andnot_ps(
                         _mm_cmple_ps(v176, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v176, v177), v177)),
                             _mm_mul_ps(*(__m128 *)_xmm, v177)),
                           v176)));
              v179 = _mm_rcp_ps(v178);
              v180 = _mm_mul_ps(v91, v91);
              EA.m_quad = _mm_min_ps(
                            v149,
                            _mm_div_ps(
                              _mm_mul_ps(v171, v149),
                              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v178, v179)), v179)));
              v181 = _mm_sub_ps(segPair.m_pSBProjected.m_quad, *(__m128 *)&SA.m256i_u64[1]);
              v182 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v180, v180, 85), _mm_shuffle_ps(v180, v180, 0)),
                       _mm_shuffle_ps(v180, v180, 170));
              v183 = _mm_mul_ps(v181, v91);
              v184 = _mm_rcp_ps(v182);
              v185 = _mm_mul_ps(
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v182, v184)), v184),
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v183, v183, 85), _mm_shuffle_ps(v183, v183, 0)),
                         _mm_shuffle_ps(v183, v183, 170)));
              v186 = _mm_mul_ps(v185, v91);
              v187 = _mm_mul_ps(v91, v91);
              v188 = _mm_add_ps(_mm_sub_ps(v181, v186), *(__m128 *)&SA.m256i_u64[1]);
              v189 = _mm_shuffle_ps(v188, _mm_unpackhi_ps(v188, v185), 196);
              v190 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v187, v187, 85), _mm_shuffle_ps(v187, v187, 0)),
                       _mm_shuffle_ps(v187, v187, 170));
              v191 = _mm_sub_ps(segPair.m_pSBProjected.m_quad, v189);
              v192 = _mm_rsqrt_ps(v190);
              v193 = _mm_mul_ps(v191, v191);
              v194 = _mm_andnot_ps(
                       _mm_cmple_ps(v190, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v190, v192), v192)),
                           _mm_mul_ps(v192, *(__m128 *)_xmm)),
                         v190));
              v195 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v193, v193, 85), _mm_shuffle_ps(v193, v193, 0)),
                       _mm_shuffle_ps(v193, v193, 170));
              v196 = _mm_rsqrt_ps(v195);
              v197 = _mm_andnot_ps(
                       _mm_cmple_ps(v195, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v195, v196), v196)),
                           _mm_mul_ps(v196, *(__m128 *)_xmm)),
                         v195));
              v198 = _mm_sub_ps(segPair.m_pEBProjected.m_quad, v189);
              v199 = _mm_mul_ps(v198, v198);
              v200 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v199, v199, 85), _mm_shuffle_ps(v199, v199, 0)),
                       _mm_shuffle_ps(v199, v199, 170));
              v201 = _mm_rsqrt_ps(v200);
              v202 = _mm_max_ps(
                       v197,
                       _mm_andnot_ps(
                         _mm_cmple_ps(v200, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v200, v201), v201)),
                             _mm_mul_ps(v201, *(__m128 *)_xmm)),
                           v200)));
              v203 = _mm_rcp_ps(v202);
              m_real = _mm_min_ps(
                         m_real,
                         _mm_div_ps(
                           _mm_mul_ps(_mm_mul_ps(v194, (__m128)xmmword_141A711B0), m_real),
                           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v202, v203)), v203)));
            }
            else
            {
              EA.m_quad = *(__m128 *)&SA.m256i_u64[2];
            }
            furthestPointOut.m_quad = m_real;
            if ( vars0 )
            {
              hkaiNavMeshUtils::calcFaceNormal<hkaiNavMesh>(
                (hkaiNavMeshUtils *)&SA.m256i_u64[2],
                (hkSimdFloat32 *)characterHeight,
                (hkaiNavMesh *)v12,
                (int)faceIndex,
                EB);
              hkaiNavMeshUtils::calcFaceNormal<hkaiNavMesh>(
                (hkaiNavMeshUtils *)&SA.m256i_u64[2],
                (hkSimdFloat32 *)v13,
                (hkaiNavMesh *)faceIdx,
                (int)&normalB,
                EBa);
              furthestPointOut.m_quad.m128_u64[1] = (unsigned __int64)edgePair;
              return hkaiNavMeshGenerationUtils::checkEdgeRaycasts(
                       (hkaiNavMeshEdgeMatchingParameters *)this,
                       input,
                       characterHeighta,
                       vars0,
                       &segPair.m_pSA,
                       &segPair.m_pSB,
                       &segPair.m_pEA,
                       &segPair.m_pEB,
                       faceIndex,
                       &normalB,
                       (hkSimdFloat32 *)&EA,
                       (hkSimdFloat32 *)&furthestPointOut);
            }
            return 0xFFFFFFFFi64;
          }
        }
        return 9i64;
      }
    }
  }
  return result;
}

// File Line: 875
// RVA: 0xB8C270
__int64 __fastcall hkaiNavMeshGenerationUtils::checkEdgeRaycasts(
        hkaiNavMeshEdgeMatchingParameters *input,
        hkVector4f *up,
        hkSimdFloat32 *characterHeight,
        hkaiEdgeGeometryRaycaster *raycaster,
        hkVector4f *pSA,
        hkVector4f *pSB,
        hkVector4f *pEA,
        hkVector4f *pEB,
        hkVector4f *normalA,
        hkVector4f *normalB,
        hkSimdFloat32 *midpointClearanceA,
        hkSimdFloat32 *midpointClearanceB)
{
  __m128 v12; // xmm8
  __m128 v13; // xmm6
  __m128 v14; // xmm6
  __m128 v15; // xmm9
  __m128 v16; // xmm6
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  __m128 v20; // xmm11
  __m128 v21; // xmm9
  __m128 v22; // xmm9
  __m128 v23; // xmm1
  __m128 v24; // xmm5
  __m128 v25; // xmm2
  __m128 v26; // xmm1
  __m128 v27; // xmm3
  __m128 m_quad; // xmm9
  __m128 v29; // xmm10
  __m128 v30; // xmm1
  __m128 v31; // xmm4
  __m128 v32; // xmm1
  __m128 v33; // xmm3
  __m128 v34; // xmm2
  __m128 v35; // xmm8
  __m128 v36; // xmm6
  __m128 v37; // xmm7
  __m128 v38; // xmm1
  __m128 v39; // xmm0
  __m128 v40; // xmm5
  __m128 v41; // xmm2
  hkVector4f v42; // xmm8
  __m128 v43; // xmm0
  __int64 v44; // rax
  __int64 v45; // rcx
  __m128 v46; // xmm5
  __m128 v47; // xmm6
  __m128 v48; // xmm7
  int v49; // eax
  unsigned int v50; // ecx
  hkVector4f extrusion; // [rsp+20h] [rbp-1B8h] BYREF
  hkVector4f ends; // [rsp+30h] [rbp-1A8h] BYREF
  __int128 v54[8]; // [rsp+40h] [rbp-198h]
  hkVector4f starts; // [rsp+C0h] [rbp-118h] BYREF
  __int128 v56[16]; // [rsp+D0h] [rbp-108h]

  v12 = _mm_shuffle_ps(
          (__m128)LODWORD(input->m_edgeTraversibilityHorizontalEpsilon),
          (__m128)LODWORD(input->m_edgeTraversibilityHorizontalEpsilon),
          0);
  v13 = _mm_sub_ps(pSA->m_quad, pEA->m_quad);
  v14 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), normalA->m_quad),
          _mm_mul_ps(_mm_shuffle_ps(normalA->m_quad, normalA->m_quad, 201), v13));
  v15 = _mm_sub_ps(pSB->m_quad, pEB->m_quad);
  v16 = _mm_shuffle_ps(v14, v14, 201);
  v17 = _mm_mul_ps(v16, v16);
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v19 = _mm_rsqrt_ps(v18);
  v20 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(_mm_sub_ps(pEA->m_quad, pSA->m_quad), (__m128)xmmword_141A711B0), pSA->m_quad),
          _mm_mul_ps(
            _mm_sub_ps((__m128)0i64, _mm_min_ps(_mm_mul_ps(midpointClearanceA->m_real, (__m128)xmmword_141A711B0), v12)),
            _mm_mul_ps(
              _mm_andnot_ps(
                _mm_cmple_ps(v18, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                  _mm_mul_ps(v19, *(__m128 *)_xmm))),
              v16)));
  v21 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), normalB->m_quad),
          _mm_mul_ps(_mm_shuffle_ps(normalB->m_quad, normalB->m_quad, 201), v15));
  v22 = _mm_shuffle_ps(v21, v21, 201);
  v23 = _mm_mul_ps(v22, v22);
  v24 = _mm_shuffle_ps((__m128)LODWORD(input->m_maxStepHeight), (__m128)LODWORD(input->m_maxStepHeight), 0);
  v25 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)), _mm_shuffle_ps(v23, v23, 170));
  v26 = _mm_rsqrt_ps(v25);
  v27 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmple_ps(v25, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v25), v26)),
              _mm_mul_ps(v26, *(__m128 *)_xmm))),
          v22);
  m_quad = up->m_quad;
  v29 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(_mm_sub_ps(pEB->m_quad, pSB->m_quad), (__m128)xmmword_141A711B0), pSB->m_quad),
          _mm_mul_ps(
            _mm_sub_ps((__m128)0i64, _mm_min_ps(_mm_mul_ps(midpointClearanceB->m_real, (__m128)xmmword_141A711B0), v12)),
            v27));
  v30 = _mm_mul_ps(v20, up->m_quad);
  v31 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)), _mm_shuffle_ps(v30, v30, 170));
  v32 = _mm_mul_ps(v29, up->m_quad);
  v33 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)), _mm_shuffle_ps(v32, v32, 170));
  v34 = _mm_cmplt_ps(v33, v31);
  v35 = _mm_or_ps(_mm_andnot_ps(v34, v20), _mm_and_ps(v29, v34));
  v36 = _mm_or_ps(_mm_andnot_ps(v34, v29), _mm_and_ps(v20, v34));
  v37 = _mm_or_ps(
          _mm_andnot_ps(v34, _mm_sub_ps(v24, _mm_sub_ps(v33, v31))),
          _mm_and_ps(_mm_sub_ps(v24, _mm_sub_ps(v31, v33)), v34));
  v38 = _mm_shuffle_ps(
          (__m128)LODWORD(input->m_edgeTraversibilityVerticalEpsilon),
          (__m128)LODWORD(input->m_edgeTraversibilityVerticalEpsilon),
          0);
  v39 = _mm_mul_ps(_mm_mul_ps(v38, (__m128)xmmword_141A711B0), up->m_quad);
  v40 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v24, v37), up->m_quad), v35);
  v41 = _mm_add_ps(v36, v39);
  v42.m_quad = _mm_add_ps(v35, v39);
  v43 = _mm_mul_ps(v38, up->m_quad);
  v44 = 0i64;
  v45 = 0i64;
  v46 = _mm_add_ps(v40, v43);
  v47 = _mm_add_ps(v36, v43);
  v48 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(v37, v38), (__m128)xmmword_141A711B0), up->m_quad);
  do
  {
    v56[v44] = (__int128)v46;
    v54[v44] = (__int128)v47;
    v56[v44 + 1] = (__int128)v47;
    v47 = _mm_add_ps(v47, v48);
    *(__m128 *)((char *)&ends + v45) = v46;
    v54[v44 + 1] = (__int128)v41;
    *(hkVector4f *)((char *)&starts + v45) = (hkVector4f)v42.m_quad;
    v44 += 3i64;
    v45 += 48i64;
    v46 = _mm_add_ps(v46, v48);
  }
  while ( v44 < 9 );
  extrusion.m_quad = _mm_mul_ps(_mm_sub_ps((__m128)0i64, characterHeight->m_real), m_quad);
  v49 = hkaiEdgeGeometryRaycaster::castSmallRayBundleExtruded(raycaster, &starts, &ends, &extrusion);
  v50 = -1;
  if ( v49 )
    return 11;
  return v50;
}

// File Line: 1002
// RVA: 0xB8C5D0
__int64 __fastcall hkaiNavMeshGenerationUtils::checkEdgeRaycastsWallClimbing(
        hkaiNavMeshEdgeMatchingParameters *input,
        hkVector4f *up_unused,
        hkSimdFloat32 *characterHeight,
        hkaiEdgeGeometryRaycaster *raycaster,
        hkVector4f *pSA,
        hkVector4f *pSB,
        hkVector4f *pEA,
        hkVector4f *pEB,
        hkVector4f *_normalA,
        hkVector4f *_normalB,
        hkVector4f *dirA,
        hkVector4f *dirB)
{
  __m128 v15; // xmm9
  __m128 v16; // xmm11
  __m128 m_quad; // xmm13
  __m128 v18; // xmm1
  __m128 v20; // xmm10
  __m128 v21; // xmm2
  __m128 v22; // xmm12
  __m128 v23; // xmm8
  __m128 v24; // xmm12
  __m128 v25; // xmm2
  __m128 v26; // xmm4
  __m128 v27; // xmm4
  __m128 v28; // xmm1
  __m128 v29; // xmm3
  __m128 v30; // xmm2
  __m128 v31; // xmm6
  __m128 v32; // xmm14
  __m128 v33; // xmm7
  __m128 v34; // xmm8
  __m128 v35; // xmm8
  __m128 v36; // xmm1
  __m128 v37; // xmm3
  __m128 v38; // xmm2
  __m128 v39; // xmm15
  __m128 v40; // xmm6
  __m128 v41; // xmm5
  __m128 v42; // xmm1
  __m128 v43; // xmm3
  __m128 v44; // xmm2
  __m128 v45; // xmm6
  __m128 v46; // xmm1
  __m128 v47; // xmm3
  __m128 v48; // xmm2
  __m128 v49; // xmm11
  __m128 v50; // xmm5
  __m128 v51; // xmm1
  __m128 v52; // xmm2
  __m128 v53; // xmm12
  __m128 v54; // xmm5
  __m128 v55; // xmm1
  __m128 v56; // xmm8
  __m128 v57; // xmm10
  __m128 v58; // xmm7
  __m128 v59; // xmm2
  __m128 v60; // xmm5
  __m128 v61; // xmm4
  __m128 v62; // xmm3
  __m128 v63; // xmm2
  __m128 v64; // xmm1
  __m128 v65; // xmm5
  __m128 v66; // xmm2
  float v67; // xmm2_4
  __m128 v68; // xmm13
  __m128 v69; // xmm6
  __m128 v70; // xmm5
  __m128 v71; // xmm9
  __m128 v72; // xmm7
  __m128 v73; // xmm3
  __m128 v74; // xmm2
  __m128 v75; // xmm1
  __m128 v76; // xmm0
  float v77; // xmm8_4
  __m128 v78; // xmm1
  __m128 v79; // xmm3
  __m128 v80; // xmm2
  __m128 v81; // xmm0
  __m128 v82; // xmm1
  __m128 v83; // xmm3
  __m128 v84; // xmm2
  __m128 v85; // xmm13
  __m128 m_real; // xmm4
  __m128 v87; // xmm5
  __m128 v88; // xmm1
  __m128 v89; // xmm6
  __m128 v90; // xmm2
  __m128 v91; // xmm1
  __m128 v92; // xmm11
  __m128 v93; // xmm0
  __m128 v94; // xmm1
  __m128 v95; // xmm5
  __m128 v96; // xmm6
  int v97; // ebx
  __m128 v98; // xmm3
  hkQuaternionf quat; // [rsp+20h] [rbp-E0h] BYREF
  hkVector4f end; // [rsp+30h] [rbp-D0h] BYREF
  hkVector4f direction; // [rsp+40h] [rbp-C0h] BYREF
  hkVector4f v103; // [rsp+50h] [rbp-B0h] BYREF
  hkQuaternionf v104; // [rsp+60h] [rbp-A0h] BYREF
  hkVector4f v105; // [rsp+70h] [rbp-90h] BYREF
  hkVector4f start; // [rsp+80h] [rbp-80h] BYREF
  hkVector4f v107; // [rsp+90h] [rbp-70h] BYREF
  hkVector4f v108; // [rsp+A0h] [rbp-60h] BYREF
  hkVector4f v109; // [rsp+B0h] [rbp-50h] BYREF
  hkVector4f v110; // [rsp+C0h] [rbp-40h] BYREF
  hkVector4f v111; // [rsp+D0h] [rbp-30h] BYREF
  unsigned int _normalAa; // [rsp+1D0h] [rbp+D0h]

  v15 = (__m128)_xmm;
  v16 = *(__m128 *)_xmm;
  m_quad = _normalB->m_quad;
  v18 = pEA->m_quad;
  v20 = _normalA->m_quad;
  v21 = pSA->m_quad;
  v22 = _mm_sub_ps(pEA->m_quad, pSA->m_quad);
  v23 = _mm_sub_ps(pSB->m_quad, pEB->m_quad);
  quat.m_vec.m_quad = _mm_add_ps(
                        _mm_mul_ps(_mm_sub_ps(pEB->m_quad, pSB->m_quad), (__m128)xmmword_141A711B0),
                        pSB->m_quad);
  end.m_quad = v20;
  direction.m_quad = v20;
  v24 = _mm_add_ps(_mm_mul_ps(v22, (__m128)xmmword_141A711B0), v21);
  v25 = _mm_sub_ps(v21, v18);
  v109.m_quad = m_quad;
  v26 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v20), _mm_mul_ps(_mm_shuffle_ps(v20, v20, 201), v25));
  v27 = _mm_shuffle_ps(v26, v26, 201);
  v28 = _mm_mul_ps(v27, v27);
  v29 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)), _mm_shuffle_ps(v28, v28, 170));
  v30 = _mm_rsqrt_ps(v29);
  v31 = _mm_sub_ps((__m128)0i64, _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0));
  v32 = _mm_add_ps(
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_andnot_ps(
                _mm_cmple_ps(v29, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v30, v29), v30)),
                  _mm_mul_ps(*(__m128 *)_xmm, v30))),
              v27),
            v31),
          v24);
  v33 = quat.m_vec.m_quad;
  v34 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), m_quad),
          _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v23));
  v35 = _mm_shuffle_ps(v34, v34, 201);
  v36 = _mm_mul_ps(v35, v35);
  v37 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)), _mm_shuffle_ps(v36, v36, 170));
  v38 = _mm_rsqrt_ps(v37);
  quat.m_vec.m_quad = _mm_shuffle_ps(
                        (__m128)LODWORD(input->m_minAngleBetweenFaces),
                        (__m128)LODWORD(input->m_minAngleBetweenFaces),
                        0);
  v39 = _mm_add_ps(
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_andnot_ps(
                _mm_cmple_ps(v37, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v38, v37), v38)),
                  _mm_mul_ps(*(__m128 *)_xmm, v38))),
              v35),
            v31),
          v33);
  if ( quat.m_vec.m_quad.m128_f32[0] < 1.5707964 )
  {
    v40 = _mm_sub_ps(v32, v24);
    v41 = _mm_sub_ps(v39, v33);
    v42 = _mm_mul_ps(v40, v40);
    v43 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v42, v42, 85), _mm_shuffle_ps(v42, v42, 0)),
            _mm_shuffle_ps(v42, v42, 170));
    v44 = _mm_rsqrt_ps(v43);
    v45 = _mm_mul_ps(
            v40,
            _mm_andnot_ps(
              _mm_cmple_ps(v43, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v44, v43), v44)),
                _mm_mul_ps(*(__m128 *)_xmm, v44))));
    v46 = _mm_mul_ps(v41, v41);
    v47 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v46, v46, 85), _mm_shuffle_ps(v46, v46, 0)),
            _mm_shuffle_ps(v46, v46, 170));
    v48 = _mm_rsqrt_ps(v47);
    v49 = _mm_add_ps(m_quad, v20);
    v50 = _mm_mul_ps(
            v41,
            _mm_andnot_ps(
              _mm_cmple_ps(v47, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v48, v47), v48)),
                _mm_mul_ps(v48, *(__m128 *)_xmm))));
    v51 = _mm_mul_ps(v49, v49);
    v52 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v51, v51, 85), _mm_shuffle_ps(v51, v51, 0)),
            _mm_shuffle_ps(v51, v51, 170));
    v53 = _mm_mul_ps(_mm_sub_ps(v50, v45), (__m128)xmmword_141A711B0);
    v54 = _mm_mul_ps(v50, v45);
    v55 = _mm_rsqrt_ps(v52);
    v56 = _mm_min_ps(
            _mm_max_ps(
              (__m128)COERCE_UNSIGNED_INT(
                        (float)(_mm_shuffle_ps(v54, v54, 85).m128_f32[0] + _mm_shuffle_ps(v54, v54, 0).m128_f32[0])
                      + _mm_shuffle_ps(v54, v54, 170).m128_f32[0]),
              *(__m128 *)_xmm_bf800000bf800000bf800000bf800000),
            *(__m128 *)_xmm);
    v57 = _mm_mul_ps(
            _mm_mul_ps(
              _mm_andnot_ps(
                _mm_cmple_ps(v52, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v55, v52), v55)),
                  _mm_mul_ps(v55, *(__m128 *)_xmm))),
              v49),
            _mm_add_ps(v53, v45));
    v58 = _mm_andnot_ps(*(__m128 *)_xmm, v56);
    v59 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v58), *(__m128 *)_xmm);
    v60 = _mm_cmplt_ps(*(__m128 *)_xmm, v58);
    v61 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v59), v60), _mm_andnot_ps(v60, v58));
    v62 = _mm_or_ps(_mm_andnot_ps(v60, _mm_mul_ps(v58, v58)), _mm_and_ps(v60, v59));
    v63 = _mm_add_ps(
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v62, *(__m128 *)coeff4), *(__m128 *)coeff3), v62),
                          *(__m128 *)coeff2),
                        v62),
                      *(__m128 *)coeff1),
                    v62),
                  *(__m128 *)coeff0),
                v62),
              v61),
            v61);
    v64 = _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v63, v63)), v60);
    v65 = _mm_andnot_ps(v60, v63);
    v66 = _mm_cmplt_ps(v58, *(__m128 *)_xmm);
    *(float *)&_normalAa = 1.5707964
                         - COERCE_FLOAT((_mm_andnot_ps(v66, _mm_or_ps(v64, v65)).m128_u32[0] | v66.m128_i32[0] & v58.m128_i32[0]) ^ v56.m128_i32[0] & _xmm[0]);
    LODWORD(v67) = _mm_shuffle_ps((__m128)_normalAa, (__m128)_normalAa, 0).m128_u32[0];
    if ( (float)((float)(_mm_shuffle_ps(v57, v57, 85).m128_f32[0] + _mm_shuffle_ps(v57, v57, 0).m128_f32[0])
               + _mm_shuffle_ps(v57, v57, 170).m128_f32[0]) < 0.0 )
      v67 = 6.2831855 - v67;
    if ( v67 >= 1.5707964 || v67 <= quat.m_vec.m_quad.m128_f32[0] )
    {
      v16 = *(__m128 *)_xmm;
      v20 = end.m_quad;
      v15 = (__m128)_xmm;
    }
    else
    {
      v68 = _mm_mul_ps(m_quad, _normalA->m_quad);
      v69 = _mm_min_ps(
              _mm_max_ps(
                (__m128)COERCE_UNSIGNED_INT(
                          (float)(_mm_shuffle_ps(v68, v68, 85).m128_f32[0] + _mm_shuffle_ps(v68, v68, 0).m128_f32[0])
                        + _mm_shuffle_ps(v68, v68, 170).m128_f32[0]),
                *(__m128 *)_xmm_bf800000bf800000bf800000bf800000),
              *(__m128 *)_xmm);
      v70 = _mm_andnot_ps(*(__m128 *)_xmm, v69);
      v71 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v70), *(__m128 *)_xmm);
      v72 = _mm_cmplt_ps(*(__m128 *)_xmm, v70);
      v73 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v71), v72), _mm_andnot_ps(v72, v70));
      v74 = _mm_or_ps(_mm_andnot_ps(v72, _mm_mul_ps(v70, v70)), _mm_and_ps(v72, v71));
      v75 = _mm_add_ps(
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v74, *(__m128 *)coeff4), *(__m128 *)coeff3), v74),
                            *(__m128 *)coeff2),
                          v74),
                        *(__m128 *)coeff1),
                      v74),
                    *(__m128 *)coeff0),
                  v74),
                v73),
              v73);
      v76 = _mm_cmplt_ps(v70, *(__m128 *)_xmm);
      LODWORD(v77) = COERCE_UNSIGNED_INT(
                       (float)(1.5707964
                             - COERCE_FLOAT((_mm_andnot_ps(
                                               v76,
                                               _mm_or_ps(
                                                 _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v75, v75)), v72),
                                                 _mm_andnot_ps(v72, v75))).m128_u32[0] | v76.m128_i32[0] & v70.m128_i32[0]) ^ v69.m128_i32[0] & _xmm[0]))
                     - 1.5533431) ^ _xmm[0];
      hkQuaternionf::setAxisAngle(&quat, dirA, v77);
      hkQuaternionf::setAxisAngle(&v104, dirB, v77);
      hkVector4f::setRotatedDir(&v111, &quat, &direction);
      v78 = _mm_mul_ps(v111.m_quad, v111.m_quad);
      v15 = (__m128)_xmm;
      v16 = *(__m128 *)_xmm;
      v79 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v78, v78, 85), _mm_shuffle_ps(v78, v78, 0)),
              _mm_shuffle_ps(v78, v78, 170));
      v80 = _mm_rsqrt_ps(v79);
      v81 = _mm_cmplt_ps(v79, (__m128)xmmword_141A712D0);
      direction.m_quad = _mm_or_ps(
                           _mm_andnot_ps(
                             v81,
                             _mm_mul_ps(
                               _mm_mul_ps(
                                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v80, v79), v80)),
                                 _mm_mul_ps(v80, *(__m128 *)_xmm)),
                               v111.m_quad)),
                           _mm_and_ps(v81, transform.m_quad));
      hkVector4f::setRotatedDir(&v103, &v104, &v109);
      v20 = direction.m_quad;
      v82 = _mm_mul_ps(v103.m_quad, v103.m_quad);
      v83 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v82, v82, 85), _mm_shuffle_ps(v82, v82, 0)),
              _mm_shuffle_ps(v82, v82, 170));
      v84 = _mm_rsqrt_ps(v83);
      v85 = _mm_cmplt_ps(v83, (__m128)xmmword_141A712D0);
      m_quad = _mm_or_ps(
                 _mm_andnot_ps(
                   v85,
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v84, v83), v84)),
                       _mm_mul_ps(v84, *(__m128 *)_xmm)),
                     v103.m_quad)),
                 _mm_and_ps(v85, transform.m_quad));
      v109.m_quad = m_quad;
    }
  }
  m_real = characterHeight->m_real;
  v87 = _mm_add_ps(m_quad, v20);
  v88 = _mm_mul_ps(v87, v87);
  v89 = _mm_add_ps(
          _mm_mul_ps(
            _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_44999999), (__m128)LODWORD(FLOAT_0_44999999), 0),
            _mm_sub_ps(v39, v32)),
          v32);
  end.m_quad = _mm_add_ps(_mm_mul_ps(characterHeight->m_real, v20), v32);
  v90 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v88, v88, 85), _mm_shuffle_ps(v88, v88, 0)), _mm_shuffle_ps(v88, v88, 170));
  v91 = _mm_rsqrt_ps(v90);
  v92 = _mm_mul_ps(v16, v91);
  v93 = _mm_mul_ps(_mm_mul_ps(v91, v90), v91);
  v94 = _mm_shuffle_ps((__m128)LODWORD(input->m_maxStepHeight), (__m128)LODWORD(input->m_maxStepHeight), 0);
  v95 = _mm_mul_ps(v87, _mm_andnot_ps(_mm_cmple_ps(v90, (__m128)0i64), _mm_mul_ps(_mm_sub_ps(v15, v93), v92)));
  v107.m_quad = _mm_add_ps(_mm_mul_ps(m_real, m_quad), v39);
  v110.m_quad = _mm_add_ps(_mm_mul_ps(m_real, v95), v89);
  start.m_quad = _mm_add_ps(_mm_mul_ps(v94, v20), v32);
  v108.m_quad = _mm_add_ps(_mm_mul_ps(v94, m_quad), v39);
  v105.m_quad = _mm_add_ps(v89, _mm_mul_ps(v94, v95));
  if ( !(unsigned int)hkaiEdgeGeometryRaycaster::castRay(raycaster, &start, &end)
    && !(unsigned int)hkaiEdgeGeometryRaycaster::castRay(raycaster, &v105, &v110)
    && !(unsigned int)hkaiEdgeGeometryRaycaster::castRay(raycaster, &v108, &v107) )
  {
    v96 = (__m128)xmmword_141A711B0;
    v97 = 0;
    while ( 1 )
    {
      v98 = _mm_mul_ps(v96, (__m128)xmmword_141A711C0);
      v103.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(end.m_quad, start.m_quad), v98), start.m_quad);
      quat.m_vec.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v110.m_quad, v105.m_quad), v98), v105.m_quad);
      v104.m_vec.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v107.m_quad, v108.m_quad), v98), v108.m_quad);
      if ( (unsigned int)hkaiEdgeGeometryRaycaster::castRay(raycaster, &v103, &quat.m_vec)
        || (unsigned int)hkaiEdgeGeometryRaycaster::castRay(raycaster, &quat.m_vec, &v104.m_vec) )
      {
        break;
      }
      v96 = _mm_add_ps(v96, query.m_quad);
      if ( ++v97 >= 3 )
        return 0xFFFFFFFFi64;
    }
  }
  return 11i64;
}

// File Line: 1227
// RVA: 0xB8F920
__int64 __fastcall getNumBoundaryEdges(hkaiNavMesh *mesh)
{
  __int64 m_size; // r11
  unsigned int v2; // r8d
  hkaiNavMesh::Face *m_data; // r9
  __int64 m_startEdgeIndex; // rcx
  __int64 v6; // rdx
  __int64 v7; // rdx
  hkFlags<enum hkaiNavMesh::EdgeFlagBits,unsigned char> *v8; // rcx

  m_size = mesh->m_faces.m_size;
  v2 = 0;
  if ( m_size > 0 )
  {
    m_data = mesh->m_faces.m_data;
    do
    {
      m_startEdgeIndex = m_data->m_startEdgeIndex;
      v6 = (int)m_startEdgeIndex + (__int16)*(_DWORD *)&m_data->m_numEdges;
      if ( m_startEdgeIndex < v6 )
      {
        v7 = v6 - m_startEdgeIndex;
        v8 = &mesh->m_edges.m_data->m_flags + 16 * m_startEdgeIndex + 4 * m_startEdgeIndex;
        do
        {
          if ( *(_DWORD *)&v8[-8].m_storage == -1 || (v8->m_storage & 0x20) != 0 )
            ++v2;
          v8 += 20;
          --v7;
        }
        while ( v7 );
      }
      ++m_data;
      --m_size;
    }
    while ( m_size );
  }
  return v2;
}

// File Line: 1252
// RVA: 0xB8DCA0
hkResult *__fastcall hkaiNavMeshGenerationUtils::_findConnectableEdges(
        hkResult *result,
        hkaiNavMeshGenerationSettings *input,
        hkaiNavMesh *mesh,
        hkaiNavMesh *raycaster,
        hkArray<hkaiNavMeshGenerationUtils::EdgePair,hkContainerHeapAllocator> *edgePairs,
        int iterationNum,
        hkaiNavMeshGenerationProgressCallback *cb,
        hkaiNavMeshGenerationProgressCallbackContext *cbCtx)
{
  hkArray<hkaiNavMeshGenerationUtils::EdgePair,hkContainerHeapAllocator> *v8; // r14
  hkResult *v9; // rdi
  int NumBoundaryEdges; // eax
  int v12; // ebx
  hk1AxisSweep::AabbInt *v13; // r15
  int v14; // r13d
  int v15; // r8d
  __int64 v16; // r9
  hk1AxisSweep::AabbInt *v17; // rdx
  hkaiNavMesh::Face *m_data; // rcx
  __int64 v19; // rdi
  int v20; // r13d
  int v22; // r12d
  hkResultEnum m_enum; // r14d
  __int64 v24; // rbx
  hkaiNavMesh::Edge *v25; // rdx
  hkVector4f *v26; // rcx
  __m128 m_quad; // xmm3
  __m128 v28; // xmm2
  hkaiNavMeshEdgeMatchingParameters *EdgeMatchingParameters; // rax
  __m128 m_maxSeparation_low; // xmm0
  int m_maxStepHeight_low; // xmm1_4
  __m128 m_real; // xmm3
  __m128 v33; // xmm3
  __m128 v34; // xmm3
  int m_capacityAndFlags; // r8d
  __int128 v36; // xmm0
  __int128 v37; // xmm1
  int v38; // r8d
  hk1AxisSweep::AabbInt *v39; // rax
  int v40; // eax
  int v41; // ecx
  int v42; // r9d
  hkaiNavMeshGenerationSettings *v43; // r10
  hk1AxisSweep::AabbInt *v44; // rdx
  int v45; // edi
  unsigned int v46; // edi
  hkResultEnum v47; // ebx
  __int64 v48; // rcx
  hkRadixSort::SortData32 *v49; // r13
  hkaiNavMeshGenerationProgressCallback *v50; // r12
  __int64 faceAIdx; // r15
  hkRadixSort::SortData32 *v52; // r8
  hk1AxisSweep::AabbInt *v53; // r9
  unsigned int v54; // eax
  __int64 v55; // r11
  __int64 faceBIdx; // rbx
  __int64 edgeBIdx; // rdi
  hkVector4f *v58; // rdx
  hkaiNavMesh::Edge *v59; // r8
  __int128 v60; // xmm0
  __int64 m_faceDataStriding; // rdx
  int v62; // r8d
  int v63; // r9d
  hkaiNavMeshGenerationUtils *v64; // rax
  hkaiNavMeshGenerationConnectivityResult::ConnectivityResultEnum v65; // eax
  int v66; // r9d
  int v67; // eax
  int v68; // eax
  hkResult *v69; // rbx
  int v70; // r8d
  int v71; // r8d
  bool v72; // [rsp+50h] [rbp-B0h]
  hkResult v73; // [rsp+54h] [rbp-ACh] BYREF
  hkArrayBase<hkRadixSort::SortData32> sortArray; // [rsp+58h] [rbp-A8h] BYREF
  hkResult resulta; // [rsp+68h] [rbp-98h] BYREF
  hk1AxisSweep::AabbInt *array; // [rsp+70h] [rbp-90h] BYREF
  int v77; // [rsp+78h] [rbp-88h]
  int v78; // [rsp+7Ch] [rbp-84h]
  hkArrayBase<hk1AxisSweep::AabbInt> sortedAabbs; // [rsp+80h] [rbp-80h] BYREF
  int v80; // [rsp+90h] [rbp-70h]
  int v81; // [rsp+94h] [rbp-6Ch]
  __int64 v82; // [rsp+98h] [rbp-68h]
  __int64 v83; // [rsp+A0h] [rbp-60h]
  hkaiNavMeshGenerationUtils::EdgePair aabbIn; // [rsp+B0h] [rbp-50h] BYREF
  hkSimdFloat32 characterHeight; // [rsp+E0h] [rbp-20h] BYREF
  hkArrayBase<hkVector4f> points; // [rsp+F0h] [rbp-10h] BYREF
  __m128 v87; // [rsp+100h] [rbp+0h] BYREF
  __m128 v88; // [rsp+110h] [rbp+10h]
  hkVector4f v89; // [rsp+120h] [rbp+20h]
  __int128 v90; // [rsp+130h] [rbp+30h]

  v8 = edgePairs;
  v9 = result;
  v72 = input->m_wallClimbingSettings.m_enableWallClimbing.m_bool != 0;
  edgePairs->m_size = 0;
  NumBoundaryEdges = getNumBoundaryEdges(mesh);
  v12 = NumBoundaryEdges + 4;
  v13 = 0i64;
  array = 0i64;
  v14 = NumBoundaryEdges;
  v80 = NumBoundaryEdges;
  v77 = 0;
  v78 = 0x80000000;
  v81 = NumBoundaryEdges + 4;
  if ( NumBoundaryEdges + 4 > 0 )
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &array, NumBoundaryEdges + 4, 32);
    if ( resulta.m_enum )
    {
      v9->m_enum = HK_FAILURE;
LABEL_9:
      v77 = 0;
      if ( v78 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 32 * v78);
      return v9;
    }
    v13 = array;
  }
  v77 = v12;
  v15 = 0;
  v73.m_enum = HK_SUCCESS;
  v16 = 0i64;
  v82 = 0i64;
  if ( mesh->m_faces.m_size > 0 )
  {
    v17 = 0i64;
    sortedAabbs.m_data = 0i64;
    do
    {
      m_data = mesh->m_faces.m_data;
      v19 = *(int *)((char *)&m_data->m_startEdgeIndex + (_QWORD)v17);
      HIDWORD(sortArray.m_data) = *(int *)((char *)&m_data->m_startUserEdgeIndex + (_QWORD)v17);
      sortArray.m_size = *(_DWORD *)((char *)&m_data->m_numEdges + (_QWORD)v17);
      sortArray.m_capacityAndFlags = *(_DWORD *)((char *)&m_data->m_clusterIndex + (_QWORD)v17);
      if ( mesh->m_faceDataStriding )
        v20 = mesh->m_faceData.m_data[v16 * mesh->m_faceDataStriding];
      else
        v20 = 0;
      v22 = v19 + SLOWORD(sortArray.m_size);
      if ( (int)v19 < v22 )
      {
        m_enum = v73.m_enum;
        v24 = v19;
        do
        {
          v25 = mesh->m_edges.m_data;
          if ( v25[v24].m_oppositeEdge == -1 || (v25[v24].m_flags.m_storage & 0x20) != 0 )
          {
            v26 = mesh->m_vertices.m_data;
            m_quad = v26[v25[v24].m_a].m_quad;
            v28 = v26[v25[v24].m_b].m_quad;
            points.m_size = 2;
            points.m_capacityAndFlags = -2147483646;
            v87 = m_quad;
            v88 = v28;
            points.m_data = (hkVector4f *)&v87;
            *(__m128 *)&aabbIn.m_edgeAIdx = _mm_min_ps(m_quad, v28);
            *(__m128 *)&aabbIn.m_distanceSquared = _mm_max_ps(m_quad, v28);
            EdgeMatchingParameters = hkaiNavMeshGenerationSettings::getEdgeMatchingParameters(input, &points, v20, v20);
            m_maxSeparation_low = (__m128)LODWORD(EdgeMatchingParameters->m_maxSeparation);
            if ( v72 )
            {
              m_maxStepHeight_low = LODWORD(EdgeMatchingParameters->m_maxStepHeight);
              resulta.m_enum = LODWORD(EdgeMatchingParameters->m_maxSeparation);
              LODWORD(v83) = m_maxStepHeight_low;
              m_quad.m128_f32[0] = fmaxf(*(float *)&m_maxStepHeight_low, m_maxSeparation_low.m128_f32[0]);
              m_real = _mm_shuffle_ps(m_quad, m_quad, 0);
            }
            else
            {
              characterHeight.m_real = _mm_shuffle_ps(m_maxSeparation_low, m_maxSeparation_low, 0);
              v33 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&input->m_up), 1u), 1u);
              characterHeight.m_real.m128_i32[(unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(_mm_max_ps(_mm_shuffle_ps(v33, v33, 170), _mm_max_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0))), v33), (__m128)xmmword_141A4DA50))]] = LODWORD(EdgeMatchingParameters->m_maxStepHeight);
              m_real = characterHeight.m_real;
            }
            v34 = _mm_mul_ps(m_real, (__m128)xmmword_141A711B0);
            *(__m128 *)&aabbIn.m_edgeAIdx = _mm_sub_ps(*(__m128 *)&aabbIn.m_edgeAIdx, v34);
            *(__m128 *)&aabbIn.m_distanceSquared = _mm_add_ps(*(__m128 *)&aabbIn.m_distanceSquared, v34);
            hk1AxisSweep::AabbInt::set(v13, (hkAabb *)&aabbIn, v19);
            m_capacityAndFlags = points.m_capacityAndFlags;
            *(_DWORD *)v13->m_expansionMax = m_enum;
            ++v13;
            points.m_size = 0;
            if ( m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                points.m_data,
                16 * m_capacityAndFlags);
          }
          LODWORD(v19) = v19 + 1;
          ++v24;
        }
        while ( (int)v19 < v22 );
        v17 = sortedAabbs.m_data;
        v16 = v82;
        v15 = m_enum;
      }
      ++v15;
      ++v16;
      v17 = (hk1AxisSweep::AabbInt *)((char *)v17 + 16);
      v73.m_enum = v15;
      v82 = v16;
      sortedAabbs.m_data = v17;
    }
    while ( v15 < mesh->m_faces.m_size );
    v13 = array;
    v8 = edgePairs;
    v12 = v81;
    v9 = result;
    v14 = v80;
  }
  v36 = *(_OWORD *)&aabbIn.m_distanceSquared;
  aabbIn.m_edgeAIdx = -1;
  v37 = *(_OWORD *)&aabbIn.m_edgeAIdx;
  v38 = 0x80000000;
  v39 = &v13[v14];
  sortedAabbs.m_data = 0i64;
  sortedAabbs.m_size = 0;
  sortedAabbs.m_capacityAndFlags = 0x80000000;
  sortArray.m_data = 0i64;
  sortArray.m_size = 0;
  *(_OWORD *)v39->m_min = *(_OWORD *)&aabbIn.m_edgeAIdx;
  *(_OWORD *)v39->m_max = v36;
  *(_OWORD *)v39[1].m_min = v37;
  *(_OWORD *)v39[1].m_max = v36;
  *(_OWORD *)v39[2].m_min = v37;
  *(_OWORD *)v39[2].m_max = v36;
  sortArray.m_capacityAndFlags = 0x80000000;
  *(_OWORD *)v39[3].m_min = v37;
  *(_OWORD *)v39[3].m_max = v36;
  if ( v12 <= 0 )
  {
    v40 = 0;
    LODWORD(edgePairs) = 0;
    goto LABEL_30;
  }
  hkArrayUtil::_reserve((hkResult *)&edgePairs, &hkContainerTempAllocator::s_alloc, &sortedAabbs, v12, 32);
  v40 = (int)edgePairs;
  v38 = sortArray.m_capacityAndFlags;
  if ( !(_DWORD)edgePairs )
LABEL_30:
    sortedAabbs.m_size = v12;
  v41 = v38 & 0x3FFFFFFF;
  if ( (v38 & 0x3FFFFFFF) >= v12 )
  {
    v73.m_enum = HK_SUCCESS;
  }
  else
  {
    v42 = v12;
    if ( v12 < 2 * v41 )
      v42 = 2 * v41;
    hkArrayUtil::_reserve(&v73, &hkContainerTempAllocator::s_alloc, &sortArray, v42, 8);
    v38 = sortArray.m_capacityAndFlags;
    if ( v73.m_enum )
      goto LABEL_36;
    v40 = (int)edgePairs;
  }
  sortArray.m_size = v12;
  if ( v40 )
  {
LABEL_36:
    sortArray.m_size = 0;
    v9->m_enum = HK_FAILURE;
    if ( v38 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, sortArray.m_data, 8 * v38);
    sortArray.m_data = 0i64;
    sortArray.m_capacityAndFlags = 0x80000000;
    sortedAabbs.m_size = 0;
    if ( sortedAabbs.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        sortedAabbs.m_data,
        32 * sortedAabbs.m_capacityAndFlags);
    sortedAabbs.m_data = 0i64;
    sortedAabbs.m_capacityAndFlags = 0x80000000;
    goto LABEL_9;
  }
  hk1AxisSweep::sortAabbs(array, v14, &sortArray, &sortedAabbs);
  sortArray.m_size = 0;
  if ( sortArray.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      sortArray.m_data,
      8 * sortArray.m_capacityAndFlags);
  sortArray.m_data = 0i64;
  sortArray.m_capacityAndFlags = 0x80000000;
  sortedAabbs.m_size = 0;
  if ( sortedAabbs.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      sortedAabbs.m_data,
      32 * sortedAabbs.m_capacityAndFlags);
  v43 = input;
  v44 = array;
  v45 = input->m_edgeConnectionIterations + 1;
  characterHeight.m_real = _mm_shuffle_ps(
                             (__m128)LODWORD(input->m_characterHeight),
                             (__m128)LODWORD(input->m_characterHeight),
                             0);
  v46 = v14 * v45;
  v81 = v46;
  if ( v14 )
  {
    v47 = HK_SUCCESS;
    v48 = 1i64;
    v49 = 0i64;
    v50 = cb;
    resulta.m_enum = HK_SUCCESS;
    v83 = 1i64;
    while ( 1 )
    {
      faceAIdx = *(int *)&v44->m_expansionMax[(_QWORD)v49];
      v52 = v49 + 4;
      LODWORD(edgePairs) = *(_DWORD *)&v44->m_expansionMin[(_QWORD)v49];
      v53 = (hk1AxisSweep::AabbInt *)(int)edgePairs;
      sortedAabbs.m_data = (hk1AxisSweep::AabbInt *)(int)edgePairs;
      v54 = *(unsigned int *)((char *)v44->m_max + (_QWORD)v49);
      v82 = v48;
      sortArray.m_data = v49 + 4;
      v55 = faceAIdx;
      if ( *(unsigned int *)((char *)v44->m_min + (_QWORD)(v49 + 4)) <= v54 )
      {
        while ( 1 )
        {
          faceBIdx = *(int *)((char *)&v52[3].m_userData + (_QWORD)v44);
          edgeBIdx = *(int *)((char *)&v52[1].m_userData + (_QWORD)v44);
          if ( (_DWORD)faceAIdx != (_DWORD)faceBIdx
            && (((*(unsigned int *)((char *)&v52[2].m_userData + (_QWORD)v44)
                - *(unsigned int *)((char *)&v44->m_min[1] + (_QWORD)v49)) | (*(_DWORD *)((char *)&v52[3].0 + (_QWORD)v44)
                                                                            - *(unsigned int *)((char *)&v44->m_min[2]
                                                                                              + (_QWORD)v49)) | (*(unsigned int *)((char *)&v44->m_max[1] + (_QWORD)v49) - *(unsigned int *)((char *)&v52->m_userData + (_QWORD)v44)) | (*(unsigned int *)((char *)&v44->m_max[2] + (_QWORD)v49) - *(_DWORD *)((char *)&v52[1].0 + (_QWORD)v44))) & 0x80000000) == 0 )
          {
            v58 = mesh->m_vertices.m_data;
            v59 = mesh->m_edges.m_data;
            points.m_size = 4;
            points.m_capacityAndFlags = -2147483644;
            points.m_data = (hkVector4f *)&v87;
            v87 = v58[v59[(_QWORD)v53].m_a].m_quad;
            v88 = v58[v59[(_QWORD)v53].m_b].m_quad;
            v89.m_quad = (__m128)v58[v59[edgeBIdx].m_a];
            v60 = (__int128)v58[v59[edgeBIdx].m_b];
            m_faceDataStriding = mesh->m_faceDataStriding;
            v90 = v60;
            if ( (_DWORD)m_faceDataStriding )
              v62 = mesh->m_faceData.m_data[v55 * m_faceDataStriding];
            else
              v62 = 0;
            if ( (_DWORD)m_faceDataStriding )
              v63 = mesh->m_faceData.m_data[m_faceDataStriding * faceBIdx];
            else
              v63 = 0;
            v64 = (hkaiNavMeshGenerationUtils *)hkaiNavMeshGenerationSettings::getEdgeMatchingParameters(
                                                  v43,
                                                  &points,
                                                  v62,
                                                  v63);
            if ( v72 )
              v65 = hkaiNavMeshGenerationUtils::calculateWallClimbingConnectivity(
                      v64,
                      (hkVector4f *)&characterHeight,
                      (hkSimdFloat32 *)mesh,
                      raycaster,
                      (int)edgePairs,
                      edgeBIdx,
                      faceAIdx,
                      faceBIdx,
                      &aabbIn);
            else
              v65 = hkaiNavMeshGenerationUtils::calculateConnectivity(
                      v64,
                      (hkaiNavMeshEdgeMatchingParameters *)&input->m_up,
                      (hkVector4f *)&characterHeight,
                      (hkSimdFloat32 *)mesh,
                      raycaster,
                      (int)edgePairs,
                      edgeBIdx,
                      faceAIdx,
                      faceBIdx,
                      &aabbIn);
            if ( v65 == CONNECT_SUCCESS )
            {
              v66 = v8->m_size + 1;
              v67 = v8->m_capacityAndFlags & 0x3FFFFFFF;
              if ( v67 >= v66 )
              {
                v73.m_enum = HK_SUCCESS;
              }
              else
              {
                v68 = 2 * v67;
                if ( v66 < v68 )
                  v66 = v68;
                hkArrayUtil::_reserve(&v73, &hkContainerHeapAllocator::s_alloc, v8, v66, 48);
                if ( v73.m_enum )
                {
                  v69 = result;
                  v70 = points.m_capacityAndFlags;
                  result->m_enum = HK_FAILURE;
                  points.m_size = 0;
                  if ( v70 >= 0 )
                    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                      &hkContainerHeapAllocator::s_alloc,
                      points.m_data,
                      16 * v70);
                  v71 = v78;
                  points.m_data = 0i64;
                  points.m_capacityAndFlags = 0x80000000;
                  v77 = 0;
                  if ( v78 >= 0 )
                  {
                    v44 = array;
                    goto LABEL_87;
                  }
                  return v69;
                }
              }
              if ( v8->m_size == (v8->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v8, 48);
              v8->m_data[v8->m_size++] = aabbIn;
            }
            else if ( v50 )
            {
              v50->vfptr->edgeRejectedCallback(v50, mesh, faceAIdx, (int)edgePairs, faceBIdx, edgeBIdx, v65);
            }
            points.m_size = 0;
            if ( points.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                points.m_data,
                16 * points.m_capacityAndFlags);
            v53 = sortedAabbs.m_data;
            v43 = input;
            v44 = array;
            v55 = faceAIdx;
          }
          ++v82;
          v52 = (hkRadixSort::SortData32 *)(32 * v82);
          if ( v44[v82].m_min[0] > *(_DWORD *)((char *)&sortArray.m_data[-2].0 + (unsigned __int64)v44) )
          {
            v52 = sortArray.m_data;
            v47 = resulta.m_enum;
            v48 = v83;
            v46 = v81;
            break;
          }
        }
      }
      ++v47;
      ++v48;
      v49 = v52;
      resulta.m_enum = v47;
      v83 = v48;
      if ( v50 && cbCtx )
      {
        v50->vfptr->stepMiddleCallback(v50, END|BEGIN|0x4, v47 + iterationNum * v80, v46, cbCtx);
        v44 = array;
        v48 = v83;
      }
      if ( v47 >= v80 - 1 )
        break;
      v43 = input;
    }
  }
  v69 = result;
  v71 = v78;
  v77 = 0;
  result->m_enum = HK_SUCCESS;
  if ( v71 >= 0 )
LABEL_87:
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v44, 32 * v71);
  return v69;
}

// File Line: 1506
// RVA: 0xB8D660
hkResult *__fastcall hkaiNavMeshGenerationUtils::_findExactEdges(
        hkResult *result,
        hkaiNavMeshGenerationSettings *input,
        hkSimdFloat32 *mesh,
        hkaiNavMesh *raycaster,
        hkArray<hkaiNavMeshGenerationUtils::EdgePair,hkContainerHeapAllocator> *edgePairs,
        hkaiNavMeshGenerationProgressCallback *cb,
        hkaiNavMeshGenerationProgressCallbackContext *cbCtx)
{
  hkaiNavMeshGenerationSettings *v8; // rdi
  int v9; // r9d
  int v10; // r8d
  hkResult *v11; // rbx
  int v12; // r10d
  int v13; // r12d
  __int64 v14; // r13
  hkaiNavMesh::Face *v15; // r14
  __int64 m_startEdgeIndex; // rbx
  __int64 v17; // rdi
  hkaiNavMesh::Edge *v18; // rsi
  EdgeKey *v19; // r9
  int m_b; // r8d
  int m_a; // edx
  int v22; // eax
  __m128 m_characterHeight_low; // xmm0
  int v24; // r11d
  int v25; // edi
  __int64 v26; // rsi
  int v27; // r11d
  int v28; // ebx
  __int64 v29; // r9
  __int64 v30; // rdx
  unsigned __int64 *p_m_key; // rcx
  __int64 v32; // rdx
  __int64 v33; // rax
  int v34; // ebx
  hkaiNavMesh::Edge *v35; // rdx
  hkVector4f *v36; // r8
  __int64 v37; // r9
  __int64 m_edgeId; // r10
  __int64 faceBIdx; // r12
  __int64 v40; // r13
  __int64 faceAIdx; // r14
  __int64 v42; // rax
  __int64 v43; // rdx
  int v44; // r8d
  int v45; // r9d
  hkaiNavMeshGenerationUtils *EdgeMatchingParameters; // rax
  hkaiNavMeshGenerationConnectivityResult::ConnectivityResultEnum v47; // eax
  int v48; // r9d
  int v49; // eax
  int v50; // eax
  int m_capacityAndFlags; // r8d
  int v52; // edi
  __int64 v53; // rsi
  EdgeKey *array; // [rsp+50h] [rbp-B0h] BYREF
  int v56; // [rsp+58h] [rbp-A8h]
  int v57; // [rsp+5Ch] [rbp-A4h]
  hkResult resulta; // [rsp+60h] [rbp-A0h] BYREF
  int v59; // [rsp+64h] [rbp-9Ch]
  int edgeBIdx; // [rsp+68h] [rbp-98h]
  __int64 v61; // [rsp+70h] [rbp-90h]
  hkaiNavMeshGenerationUtils::EdgePair edgePair; // [rsp+78h] [rbp-88h] BYREF
  hkArrayBase<hkVector4f> points; // [rsp+B0h] [rbp-50h] BYREF
  __int128 v64[4]; // [rsp+C0h] [rbp-40h] BYREF
  hkSimdFloat32 characterHeight; // [rsp+100h] [rbp+0h] BYREF
  bool v68; // [rsp+170h] [rbp+70h]

  v68 = input->m_wallClimbingSettings.m_enableWallClimbing.m_bool != 0;
  v8 = input;
  edgePairs->m_size = 0;
  v9 = mesh[2].m_real.m128_i32[2];
  v10 = 0x80000000;
  v11 = result;
  array = 0i64;
  v12 = 0;
  v56 = 0;
  v57 = 0x80000000;
  if ( v9 > 0 )
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &array, v9, 16);
    v10 = v57;
    if ( resulta.m_enum )
    {
      v11->m_enum = HK_FAILURE;
      v56 = 0;
      if ( v10 >= 0 )
        goto LABEL_65;
      return v11;
    }
    v12 = v56;
  }
  v13 = 0;
  if ( mesh[1].m_real.m128_i32[2] > 0 )
  {
    v14 = 0i64;
    do
    {
      v15 = (hkaiNavMesh::Face *)(v14 + mesh[1].m_real.m128_u64[0]);
      m_startEdgeIndex = v15->m_startEdgeIndex;
      if ( (int)m_startEdgeIndex < (int)m_startEdgeIndex + v15->m_numEdges )
      {
        v17 = m_startEdgeIndex;
        do
        {
          v18 = (hkaiNavMesh::Edge *)mesh[2].m_real.m128_u64[0];
          if ( v18[v17].m_oppositeEdge == -1 )
          {
            if ( v12 == (v10 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &array, 16);
              v12 = v56;
            }
            v56 = v12 + 1;
            v19 = &array[v12];
            v19->m_edgeId = m_startEdgeIndex;
            v19->m_faceId = v13;
            m_b = v18[v17].m_b;
            m_a = v18[v17].m_a;
            v22 = m_b;
            if ( m_a < m_b )
              v22 = v18[v17].m_a;
            if ( m_a > m_b )
              m_b = v18[v17].m_a;
            v19->m_key = m_b | (unsigned __int64)((__int64)v22 << 32);
            v10 = v57;
            v12 = v56;
          }
          LODWORD(m_startEdgeIndex) = m_startEdgeIndex + 1;
          ++v17;
        }
        while ( (int)m_startEdgeIndex < v15->m_startEdgeIndex + v15->m_numEdges );
      }
      ++v13;
      v14 += 16i64;
    }
    while ( v13 < mesh[1].m_real.m128_i32[2] );
    v11 = result;
    v8 = input;
  }
  if ( !v12 )
  {
LABEL_63:
    v56 = 0;
    v11->m_enum = HK_SUCCESS;
    goto LABEL_64;
  }
  if ( v12 > 1 )
  {
    hkAlgorithm::quickSortRecursive<EdgeKey,hkAlgorithm::less<EdgeKey>>(array, 0, v12 - 1, 0);
    v10 = v57;
    v12 = v56;
  }
  m_characterHeight_low = (__m128)LODWORD(v8->m_characterHeight);
  v24 = v8->m_edgeConnectionIterations + 1;
  v25 = 0;
  v26 = 0i64;
  characterHeight.m_real = _mm_shuffle_ps(m_characterHeight_low, m_characterHeight_low, 0);
  v27 = v12 * v24;
  v59 = v27;
  if ( v12 - 1 <= 0 )
  {
LABEL_62:
    v11 = result;
    goto LABEL_63;
  }
  while ( 1 )
  {
    v28 = v25 + 1;
    v29 = v26 + 1;
    v30 = v26 + 1;
    if ( v25 + 1 < v12 )
    {
      p_m_key = &array[v29].m_key;
      do
      {
        if ( array[v26].m_key != *p_m_key )
          break;
        ++v28;
        ++v30;
        p_m_key += 2;
      }
      while ( v28 < v12 );
    }
    v32 = v30 - v26;
    v33 = v32 - 1;
    v34 = v28 - v25 - 1;
    v61 = v32 - 1;
    if ( v32 == 2 )
      break;
LABEL_56:
    v52 = v34 + v25;
    v53 = v33 + v26;
    if ( cb && cbCtx )
    {
      cb->vfptr->stepMiddleCallback(cb, END|BEGIN|0x4, v52, v27, cbCtx);
      v12 = v56;
    }
    v25 = v52 + 1;
    v26 = v53 + 1;
    if ( v25 >= v12 - 1 )
    {
      v10 = v57;
      goto LABEL_62;
    }
    v27 = v59;
  }
  v35 = (hkaiNavMesh::Edge *)mesh[2].m_real.m128_u64[0];
  v36 = (hkVector4f *)mesh[3].m_real.m128_u64[0];
  v37 = v29;
  m_edgeId = array[v37].m_edgeId;
  faceBIdx = array[v37].m_faceId;
  v40 = array[v26].m_edgeId;
  faceAIdx = array[v26].m_faceId;
  points.m_size = 4;
  points.m_capacityAndFlags = -2147483644;
  points.m_data = (hkVector4f *)v64;
  edgeBIdx = m_edgeId;
  v64[0] = (__int128)v36[v35[v40].m_a];
  v64[1] = (__int128)v36[v35[v40].m_b];
  v64[2] = (__int128)v36[v35[m_edgeId].m_a];
  v42 = v35[m_edgeId].m_b;
  v43 = mesh[7].m_real.m128_i32[0];
  v64[3] = (__int128)v36[v42];
  if ( (_DWORD)v43 )
    v44 = *(_DWORD *)(mesh[5].m_real.m128_u64[0] + 4 * faceAIdx * v43);
  else
    v44 = 0;
  if ( (_DWORD)v43 )
    v45 = *(_DWORD *)(mesh[5].m_real.m128_u64[0] + 4 * faceBIdx * v43);
  else
    v45 = 0;
  EdgeMatchingParameters = (hkaiNavMeshGenerationUtils *)hkaiNavMeshGenerationSettings::getEdgeMatchingParameters(
                                                           input,
                                                           &points,
                                                           v44,
                                                           v45);
  if ( v68 )
    v47 = hkaiNavMeshGenerationUtils::calculateWallClimbingConnectivity(
            EdgeMatchingParameters,
            (hkVector4f *)&characterHeight,
            mesh,
            raycaster,
            v40,
            edgeBIdx,
            faceAIdx,
            faceBIdx,
            &edgePair);
  else
    v47 = hkaiNavMeshGenerationUtils::calculateConnectivity(
            EdgeMatchingParameters,
            (hkaiNavMeshEdgeMatchingParameters *)&input->m_up,
            (hkVector4f *)&characterHeight,
            mesh,
            raycaster,
            v40,
            edgeBIdx,
            faceAIdx,
            faceBIdx,
            &edgePair);
  if ( v47 != CONNECT_SUCCESS )
  {
    if ( cb )
      cb->vfptr->edgeRejectedCallback(cb, (hkaiNavMesh *)mesh, faceAIdx, v40, faceBIdx, edgeBIdx, v47);
    goto LABEL_53;
  }
  v48 = edgePairs->m_size + 1;
  v49 = edgePairs->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v49 >= v48 )
  {
    resulta.m_enum = HK_SUCCESS;
LABEL_48:
    if ( edgePairs->m_size == (edgePairs->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, edgePairs, 48);
    edgePairs->m_data[edgePairs->m_size++] = edgePair;
LABEL_53:
    points.m_size = 0;
    if ( points.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        points.m_data,
        16 * points.m_capacityAndFlags);
    v27 = v59;
    v33 = v61;
    v12 = v56;
    goto LABEL_56;
  }
  v50 = 2 * v49;
  if ( v48 < v50 )
    v48 = v50;
  hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, edgePairs, v48, 48);
  if ( resulta.m_enum == HK_SUCCESS )
    goto LABEL_48;
  v11 = result;
  m_capacityAndFlags = points.m_capacityAndFlags;
  result->m_enum = HK_FAILURE;
  points.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      points.m_data,
      16 * m_capacityAndFlags);
  v10 = v57;
  points.m_data = 0i64;
  points.m_capacityAndFlags = 0x80000000;
  v56 = 0;
LABEL_64:
  if ( v10 >= 0 )
LABEL_65:
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 16 * v10);
  return v11;
}

// File Line: 1658
// RVA: 0xB8BCF0
_BOOL8 __fastcall hkaiNavMeshGenerationUtils::EdgePair::operator<(
        hkaiNavMeshGenerationUtils::EdgePair *this,
        hkaiNavMeshGenerationUtils::EdgePair *other)
{
  float m_distanceSquared; // xmm2_4

  m_distanceSquared = other->m_distanceSquared;
  if ( COERCE_FLOAT((unsigned int)(2 * COERCE_INT(this->m_distanceSquared - m_distanceSquared)) >> 1) > 0.0000099999997 )
    return this->m_distanceSquared > m_distanceSquared;
  if ( COERCE_FLOAT((unsigned int)(2 * COERCE_INT(this->m_edgeAlignment - other->m_edgeAlignment)) >> 1) > 0.0000099999997 )
    return other->m_edgeAlignment > this->m_edgeAlignment;
  return this->m_overlap < other->m_overlap;
}

// File Line: 1667
// RVA: 0xB95170
hkResult *__fastcall NavMeshFreeList::addFreeSpace(NavMeshFreeList *this, hkResult *result, int idx, __int64 num)
{
  __int64 v4; // r15
  int v8; // ebp
  int v9; // eax
  int v10; // eax
  int v11; // r9d
  int v12; // eax
  __int64 v13; // rdi
  int *v14; // rbx
  int v15; // r8d
  __int64 m_size; // rdx
  int v17; // ecx
  __int64 v18; // rax
  hkArray<int,hkContainerHeapAllocator> *v19; // rdx
  hkArray<int,hkContainerHeapAllocator> *v20; // r8
  int v21; // r9d
  int v22; // eax
  int v23; // eax
  hkArray<int,hkContainerHeapAllocator> *m_data; // rdx
  hkArray<int,hkContainerHeapAllocator> *v25; // rdx
  hkResult resulta; // [rsp+78h] [rbp+20h] BYREF

  v4 = (int)num;
  if ( this->m_freeSpace.m_size > (int)num )
    goto LABEL_17;
  v8 = num + 1;
  hkaiArrayUtil::reserveForNonPodType<hkArray<int,hkContainerHeapAllocator>,hkContainerHeapAllocator>(
    (hkaiArrayUtil *)&resulta,
    (hkResult *)this,
    (hkArray<hkArray<int,hkContainerHeapAllocator>,hkContainerHeapAllocator> *)(unsigned int)(num + 1),
    num);
  if ( resulta.m_enum == HK_SUCCESS )
  {
    v9 = this->m_freeSpace.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v9 < v8 )
    {
      v10 = 2 * v9;
      v11 = v8;
      if ( v8 < v10 )
        v11 = v10;
      hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, this, v11, 16);
    }
    v12 = this->m_freeSpace.m_size - v8 - 1;
    v13 = v12;
    if ( v12 >= 0 )
    {
      v14 = &this->m_freeSpace.m_data[v8].m_capacityAndFlags + 4 * v12;
      do
      {
        v15 = *v14;
        *(v14 - 1) = 0;
        if ( v15 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            *(void **)(v14 - 3),
            4 * v15);
        *(_QWORD *)(v14 - 3) = 0i64;
        *v14 = 0x80000000;
        v14 -= 4;
        --v13;
      }
      while ( v13 >= 0 );
    }
    m_size = this->m_freeSpace.m_size;
    v17 = v8 - m_size;
    v18 = v8 - (int)m_size;
    v19 = &this->m_freeSpace.m_data[m_size];
    if ( v17 > 0 )
    {
      do
      {
        if ( v19 )
        {
          v19->m_data = 0i64;
          v19->m_size = 0;
          v19->m_capacityAndFlags = 0x80000000;
        }
        ++v19;
        --v18;
      }
      while ( v18 );
    }
    this->m_freeSpace.m_size = v8;
LABEL_17:
    v20 = &this->m_freeSpace.m_data[v4];
    v21 = v20->m_size + 1;
    v22 = v20->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v22 >= v21 )
    {
      resulta.m_enum = HK_SUCCESS;
    }
    else
    {
      v23 = 2 * v22;
      if ( v21 < v23 )
        v21 = v23;
      hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, v20, v21, 4);
      if ( resulta.m_enum )
        goto LABEL_21;
    }
    m_data = this->m_freeSpace.m_data;
    result->m_enum = HK_SUCCESS;
    v25 = &m_data[v4];
    v25->m_data[v25->m_size++] = idx;
    return result;
  }
LABEL_21:
  result->m_enum = HK_FAILURE;
  return result;
}

// File Line: 1701
// RVA: 0xB8F9D0
hkResult *__fastcall _splitEdges(
        hkResult *result,
        hkaiNavMesh *mesh,
        unsigned int faceIdx,
        hkaiNavMeshGenerationUtils::EdgeSplit *splits,
        NavMeshFreeList *freeList,
        int *numSplitsOut)
{
  hkaiNavMesh::Face *m_data; // rax
  unsigned int v8; // r13d
  __m128i v11; // xmm8
  hkResultEnum m_enum; // eax
  __int16 epi16; // di
  int v14; // ebx
  int v15; // r9d
  int v16; // eax
  int v17; // eax
  int v18; // r9d
  int m_oppositeEdge; // r12d
  hkaiNavMesh::Edge *v20; // rdx
  _DWORD *v21; // rcx
  int v22; // eax
  __int64 v23; // rdi
  int m_a; // eax
  unsigned int v25; // eax
  int v26; // edx
  int v27; // r8d
  int v28; // eax
  int v29; // eax
  int v30; // r9d
  char *v31; // rdi
  __int64 v32; // rcx
  hkaiNavMeshGenerationUtils::EdgeSplit *v33; // rdi
  int v34; // r14d
  __int64 m_edgeIdx; // rdx
  float m_tS; // xmm0_4
  hkaiNavMesh::Edge *v37; // r9
  int v38; // eax
  __int64 v39; // r8
  float *v40; // rcx
  float v41; // xmm1_4
  hkVector4f *v42; // rcx
  int m_size; // r12d
  __int64 v44; // rax
  __m128 v45; // xmm1
  int v46; // r13d
  int v47; // r9d
  __int64 v48; // rbx
  _DWORD *v49; // rdx
  int v50; // eax
  __int64 v51; // rax
  hkVector4f *v52; // rdx
  __m128 v53; // xmm2
  int v54; // r12d
  __int64 v55; // rcx
  __int64 v56; // rax
  int v57; // r13d
  int v58; // r9d
  __int64 v59; // rbx
  _DWORD *v60; // rdx
  int v61; // eax
  int v62; // r8d
  __int64 v63; // r10
  __int64 v64; // rdx
  __int64 v65; // rdi
  unsigned int v66; // r8d
  _DWORD **v67; // rdx
  int v68; // ecx
  _DWORD *v69; // rax
  __int64 m_enum_low; // rax
  NavMeshFreeList *v71; // r14
  hkArray<int,hkContainerHeapAllocator> *v72; // r8
  __int64 v73; // rbx
  hkaiNavMesh::Edge *v74; // r9
  int *v75; // rcx
  hkaiNavMesh::Edge *v76; // rdx
  __int64 v77; // r8
  int v78; // eax
  _DWORD **v79; // rcx
  _DWORD *v80; // rax
  hkResultEnum v81; // edi
  unsigned int *p_m_oppositeEdge; // r8
  __int64 v83; // rax
  __int64 v84; // rdx
  hkaiNavMesh::Face *v85; // rdx
  __int64 v86; // rcx
  hkResultEnum v87; // eax
  int m_b; // r9d
  int v89; // r8d
  int v90; // r8d
  float *v92; // [rsp+30h] [rbp-98h] BYREF
  int v93; // [rsp+38h] [rbp-90h]
  int v94; // [rsp+3Ch] [rbp-8Ch]
  _DWORD *array; // [rsp+40h] [rbp-88h] BYREF
  hkResult v96[4]; // [rsp+48h] [rbp-80h] BYREF
  hkaiNavMesh::Edge t; // [rsp+58h] [rbp-70h] BYREF
  hkaiNavMesh::Edge v98; // [rsp+70h] [rbp-58h] BYREF
  unsigned __int64 v99; // [rsp+88h] [rbp-40h]
  __int64 v100; // [rsp+90h] [rbp-38h]
  hkVector4f v; // [rsp+98h] [rbp-30h] BYREF
  hkVector4f v102; // [rsp+A8h] [rbp-20h] BYREF
  hkResult resulta; // [rsp+130h] [rbp+68h] BYREF
  hkResult v104; // [rsp+138h] [rbp+70h] BYREF
  __int64 v105; // [rsp+140h] [rbp+78h]
  NavMeshFreeList *v106; // [rsp+148h] [rbp+80h]
  _DWORD *vars0; // [rsp+150h] [rbp+88h]

  m_data = mesh->m_faces.m_data;
  v8 = faceIdx;
  v99 = 16i64 * (int)faceIdx;
  v11 = (__m128i)m_data[v99 / 0x10];
  m_enum = 0x80000000;
  array = 0i64;
  epi16 = _mm_extract_epi16(v11, 4);
  v96[0].m_enum = HK_SUCCESS;
  v96[1].m_enum = 0x80000000;
  v14 = epi16;
  v98.m_b = epi16;
  v15 = 2 * epi16;
  if ( v15 <= 0 )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    if ( (epi16 & 0x40000000) != 0 )
      v15 = 0;
    hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &array, v15, 20);
    m_enum = v96[1].m_enum;
    if ( resulta.m_enum )
    {
      result->m_enum = HK_FAILURE;
      v96[0].m_enum = HK_SUCCESS;
      goto LABEL_6;
    }
  }
  v16 = m_enum & 0x3FFFFFFF;
  if ( v16 < epi16 )
  {
    v17 = 2 * v16;
    v18 = epi16;
    if ( epi16 < v17 )
      v18 = v17;
    hkArrayUtil::_reserve(&v96[2], &hkContainerTempAllocator::s_alloc, &array, v18, 20);
  }
  m_oppositeEdge = _mm_cvtsi128_si32(v11);
  v96[0].m_enum = epi16;
  t.m_oppositeEdge = m_oppositeEdge;
  v20 = &mesh->m_edges.m_data[m_oppositeEdge];
  v21 = array;
  v22 = 5 * epi16;
  if ( v22 > 0 )
  {
    v23 = (unsigned int)v22;
    do
    {
      m_a = v20->m_a;
      ++v21;
      v20 = (hkaiNavMesh::Edge *)((char *)v20 + 4);
      *(v21 - 1) = m_a;
      --v23;
    }
    while ( v23 );
  }
  v25 = 0x80000000;
  v26 = 0;
  v92 = 0i64;
  v94 = 0x80000000;
  v93 = 0;
  if ( v14 <= 0 )
  {
    resulta.m_enum = HK_SUCCESS;
    goto LABEL_23;
  }
  hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &v92, v14, 4);
  if ( resulta.m_enum == HK_SUCCESS )
  {
    v25 = v94;
    v26 = v93;
LABEL_23:
    v28 = v25 & 0x3FFFFFFF;
    if ( v28 < v14 )
    {
      v29 = 2 * v28;
      v30 = v14;
      if ( v14 < v29 )
        v30 = v29;
      hkArrayUtil::_reserve(&v96[2], &hkContainerTempAllocator::s_alloc, &v92, v30, 4);
      v26 = v93;
    }
    v31 = (char *)&v92[v26];
    v32 = v14 - v26;
    if ( v14 - v26 > 0 )
    {
      while ( v32 )
      {
        *(_DWORD *)v31 = 0;
        v31 += 4;
        --v32;
      }
    }
    v33 = splits;
    v34 = 0;
    v93 = v14;
    while ( 1 )
    {
      m_edgeIdx = v33->m_edgeIdx;
      m_tS = v33->m_tS;
      v37 = mesh->m_edges.m_data;
      v38 = m_edgeIdx + m_oppositeEdge;
      *(_QWORD *)&v96[0].m_enum = v37;
      v39 = 5i64 * ((int)m_edgeIdx + m_oppositeEdge);
      v40 = v92;
      v100 = v39;
      v41 = v92[m_edgeIdx];
      if ( (float)(m_tS - v41) < 0.000001 )
        v33->m_tS = v41;
      if ( v40[m_edgeIdx] < v33->m_tS )
      {
        v42 = mesh->m_vertices.m_data;
        m_size = mesh->m_vertices.m_size;
        v44 = v37[v38].m_a;
        v45 = _mm_shuffle_ps((__m128)LODWORD(v33->m_tS), (__m128)LODWORD(v33->m_tS), 0);
        v.m_quad = (__m128)v42[*(&v37->m_a + v39)];
        v.m_quad = _mm_add_ps(
                     _mm_mul_ps(_mm_sub_ps(v42[*(&v37->m_b + v39)].m_quad, v42[v44].m_quad), v45),
                     v42[v44].m_quad);
        hkaiNavMesh::appendVertices(mesh, (hkResult *)&v98.m_oppositeEdge, &v, 1);
        if ( v98.m_oppositeEdge )
          goto LABEL_53;
        v46 = v34 + v33->m_edgeIdx;
        v47 = v96[0].m_enum + 1;
        v48 = 5i64 * v46;
        t = *(hkaiNavMesh::Edge *)&array[5 * v46];
        if ( (v96[1].m_enum & 0x3FFFFFFF) >= v96[0].m_enum + 1 )
        {
          resulta.m_enum = HK_SUCCESS;
        }
        else
        {
          if ( v47 < 2 * (v96[1].m_enum & 0x3FFFFFFF) )
            v47 = 2 * (v96[1].m_enum & 0x3FFFFFFF);
          hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &array, v47, 20);
          if ( resulta.m_enum )
            goto LABEL_66;
        }
        hkArrayBase<hkaiNavMesh::Edge>::_insertAt(
          (hkArrayBase<hkaiNavMesh::Edge> *)&array,
          &hkContainerTempAllocator::s_alloc,
          v46,
          &t);
        v49 = array;
        v39 = v100;
        v37 = *(hkaiNavMesh::Edge **)&v96[0].m_enum;
        v50 = v46 + 1;
        v8 = v104.m_enum;
        ++v34;
        v51 = 5i64 * v50;
        array[v51] = m_size;
        *(_QWORD *)&v49[v51 + 2] = -1i64;
        v49[v48 + 1] = m_size;
      }
      v92[v33->m_edgeIdx] = v33->m_tE;
      *v33->m_sharedPairEdgeIdx = v34 + v33->m_edgeIdx;
      if ( v33->m_tE < 1.0 )
      {
        v52 = mesh->m_vertices.m_data;
        v53 = _mm_shuffle_ps((__m128)LODWORD(v33->m_tE), (__m128)LODWORD(v33->m_tE), 0);
        v54 = mesh->m_vertices.m_size;
        v55 = *(&v37->m_b + v39);
        v56 = *(&v37->m_a + v39);
        v102.m_quad = (__m128)v52[*(&v37->m_b + v39)];
        v102.m_quad = _mm_add_ps(_mm_mul_ps(v53, _mm_sub_ps(v52[v55].m_quad, v52[v56].m_quad)), v52[v56].m_quad);
        hkaiNavMesh::appendVertices(mesh, &v96[2], &v102, 1);
        if ( v96[2].m_enum )
        {
LABEL_53:
          v62 = v94;
          result->m_enum = HK_FAILURE;
          v93 = 0;
          if ( v62 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v92, 4 * v62);
          v92 = 0i64;
          v96[0].m_enum = HK_SUCCESS;
          goto LABEL_87;
        }
        v57 = v34 + v33->m_edgeIdx;
        v58 = v96[0].m_enum + 1;
        v59 = 5i64 * v57;
        v98 = *(hkaiNavMesh::Edge *)&array[5 * v57];
        if ( (v96[1].m_enum & 0x3FFFFFFF) >= v96[0].m_enum + 1 )
        {
          v98.m_a = 0;
        }
        else
        {
          if ( v58 < 2 * (v96[1].m_enum & 0x3FFFFFFF) )
            v58 = 2 * (v96[1].m_enum & 0x3FFFFFFF);
          hkArrayUtil::_reserve((hkResult *)&v98, &hkContainerTempAllocator::s_alloc, &array, v58, 20);
          if ( v98.m_a )
            goto LABEL_66;
        }
        hkArrayBase<hkaiNavMesh::Edge>::_insertAt(
          (hkArrayBase<hkaiNavMesh::Edge> *)&array,
          &hkContainerTempAllocator::s_alloc,
          v57,
          &v98);
        v60 = array;
        v61 = v57 + 1;
        v8 = v104.m_enum;
        array[v59 + 1] = v54;
        *(_QWORD *)&v60[v59 + 2] = -1i64;
        ++v34;
        v60[5 * v61] = v54;
      }
      ++v33;
      if ( v33->m_faceIdx != v8 )
        break;
      m_oppositeEdge = t.m_oppositeEdge;
    }
    v63 = v105;
    v64 = ((__int64)v33 - v105) / 24;
    *vars0 = v64;
    v65 = (int)v64;
    if ( !v34 )
    {
      if ( (int)v64 > 0 )
      {
        v66 = t.m_oppositeEdge;
        v67 = (_DWORD **)(v63 + 8);
        do
        {
          v68 = *((_DWORD *)v67 - 1);
          v69 = *v67;
          v67 += 3;
          *v69 = v66 + v68;
          --v65;
        }
        while ( v65 );
      }
      result->m_enum = HK_SUCCESS;
      goto LABEL_67;
    }
    m_enum_low = SLOWORD(v96[0].m_enum);
    v71 = v106;
    *(__m128i *)&v96[0].m_enum = v11;
    LOWORD(v96[2].m_enum) = m_enum_low;
    if ( v106->m_freeSpace.m_size <= (int)m_enum_low
      || (v72 = v106->m_freeSpace.m_data, !v106->m_freeSpace.m_data[m_enum_low].m_size)
      || (v73 = v72[m_enum_low].m_data[v72[m_enum_low].m_size - 1], --v72[m_enum_low].m_size, (_DWORD)v73 == -1) )
    {
      LODWORD(v73) = mesh->m_edges.m_size;
      v74 = hkaiNavMesh::expandEdgesBy(mesh, v96[0].m_enum, -1);
      if ( !v74 )
      {
LABEL_66:
        result->m_enum = HK_FAILURE;
LABEL_67:
        v93 = 0;
        if ( v94 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v92, 4 * v94);
        v92 = 0i64;
        v96[0].m_enum = HK_SUCCESS;
        goto LABEL_87;
      }
      v63 = v105;
    }
    else
    {
      v74 = &mesh->m_edges.m_data[v73];
    }
    v75 = array;
    v76 = v74;
    v77 = (unsigned int)(5 * v96[0].m_enum);
    if ( (int)v77 > 0 )
    {
      do
      {
        v78 = *v75;
        v76 = (hkaiNavMesh::Edge *)((char *)v76 + 4);
        ++v75;
        *(_DWORD *)&v76[-1].m_flags.m_storage = v78;
        --v77;
      }
      while ( v77 );
    }
    if ( v65 > 0 )
    {
      v79 = (_DWORD **)(v63 + 8);
      do
      {
        v80 = *v79;
        v79 += 3;
        *v80 += v73;
        --v65;
      }
      while ( v65 );
    }
    v81 = HK_SUCCESS;
    if ( v96[0].m_enum > HK_SUCCESS )
    {
      p_m_oppositeEdge = &v74->m_oppositeEdge;
      do
      {
        v83 = (int)*p_m_oppositeEdge;
        if ( (_DWORD)v83 != -1 )
        {
          v84 = v83;
          mesh->m_edges.m_data[v84].m_oppositeEdge = v81 + v73;
          mesh->m_edges.m_data[v84].m_oppositeFace = v8;
        }
        ++v81;
        p_m_oppositeEdge += 5;
      }
      while ( v81 < v96[0].m_enum );
    }
    v85 = mesh->m_faces.m_data;
    v86 = v99;
    v87 = v96[1].m_enum;
    m_b = v98.m_b;
    v89 = t.m_oppositeEdge;
    v85[v99 / 0x10].m_startEdgeIndex = v73;
    *(int *)((char *)&v85->m_startUserEdgeIndex + v86) = v87;
    *(hkResult *)((char *)&v85->m_numEdges + v86) = v96[2];
    *(hkResult *)((char *)&v85->m_clusterIndex + v86) = v96[3];
    NavMeshFreeList::addFreeSpace(v71, &v104, v89, m_b);
    v90 = v94;
    v93 = 0;
    if ( v104.m_enum )
      result->m_enum = HK_FAILURE;
    else
      result->m_enum = HK_SUCCESS;
    if ( v90 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v92, 4 * v90);
    v96[0].m_enum = HK_SUCCESS;
    v92 = 0i64;
LABEL_87:
    m_enum = v96[1].m_enum;
    v94 = 0x80000000;
    if ( v96[1].m_enum >= HK_SUCCESS )
      goto LABEL_88;
    return result;
  }
  v27 = v94;
  result->m_enum = HK_FAILURE;
  v93 = 0;
  if ( v27 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v92, 4 * v27);
  m_enum = v96[1].m_enum;
  v92 = 0i64;
  v94 = 0x80000000;
  v96[0].m_enum = HK_SUCCESS;
LABEL_6:
  if ( m_enum >= HK_SUCCESS )
LABEL_88:
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      array,
      20 * (m_enum & 0x3FFFFFFF));
  return result;
}

// File Line: 1878
// RVA: 0xB90200
_BOOL8 __fastcall _splitOrder(hkaiNavMeshGenerationUtils::EdgeSplit *a, hkaiNavMeshGenerationUtils::EdgeSplit *b)
{
  int m_faceIdx; // r8d
  int v3; // r9d
  int m_edgeIdx; // eax
  _BOOL8 result; // rax

  m_faceIdx = a->m_faceIdx;
  v3 = b->m_faceIdx;
  result = 1;
  if ( a->m_faceIdx >= b->m_faceIdx )
  {
    if ( m_faceIdx != v3 )
      return 0;
    m_edgeIdx = b->m_edgeIdx;
    if ( a->m_edgeIdx >= m_edgeIdx && (m_faceIdx != v3 || a->m_edgeIdx != m_edgeIdx || b->m_tS <= a->m_tS) )
      return 0;
  }
  return result;
}

// File Line: 1890
// RVA: 0xB8BD80
void __fastcall hkaiNavMeshGenerationUtils::EdgeSplit::setAsTerminiator(hkaiNavMeshGenerationUtils::EdgeSplit *this)
{
  *(_QWORD *)&this->m_faceIdx = -1i64;
  this->m_sharedPairEdgeIdx = 0i64;
  this->m_tS = -1.0;
  this->m_tE = -1.0;
}

// File Line: 1935
// RVA: 0xB8CED0
hkResult *__fastcall hkaiNavMeshGenerationUtils::_resolveConflictingEdgePairs(
        hkResult *result,
        hkArrayBase<hkaiNavMeshGenerationUtils::EdgePair> *edgePairs)
{
  int v2; // r12d
  int v3; // r8d
  int m_size; // r9d
  EdgeAndPair *v6; // rdx
  int v8; // r9d
  int v9; // r10d
  int v10; // r9d
  hkResultEnum m_enum; // eax
  int v13; // ecx
  int SizeInBytesFor; // eax
  int v15; // ebx
  int v16; // r8d
  int v17; // r15d
  __int64 v18; // r14
  int v19; // ecx
  hkaiNavMeshGenerationUtils::EdgePair *v20; // rdi
  char *v21; // rbx
  int v22; // ecx
  char *v23; // rbx
  __int64 v24; // r9
  int v25; // edx
  __int64 v26; // rcx
  _QWORD *v27; // rax
  int v28; // ebx
  int v29; // ecx
  EdgeAndPair *v30; // rdx
  int v31; // edx
  __int64 v32; // rcx
  _QWORD *v33; // rax
  int v34; // ecx
  EdgeAndPair *v35; // rdx
  __int64 v36; // r13
  __int64 v37; // r14
  __int64 v38; // r15
  int m_pairListIndex; // eax
  int m_edgeIndex; // edi
  __int64 v41; // rsi
  __int64 v42; // rax
  float v43; // xmm6_4
  float v44; // xmm5_4
  int i; // eax
  _QWORD *v46; // rbx
  __int64 v47; // r11
  __int64 v48; // rcx
  float *v49; // r9
  float *v50; // r8
  float v51; // xmm2_4
  float v52; // xmm4_4
  float v53; // xmm3_4
  int v54; // edx
  int v55; // eax
  int v56; // r10d
  int v57; // edx
  int v58; // eax
  int v59; // r8d
  void *ptr; // [rsp+38h] [rbp-61h] BYREF
  int v61; // [rsp+40h] [rbp-59h]
  int v62; // [rsp+44h] [rbp-55h]
  char *array; // [rsp+48h] [rbp-51h] BYREF
  int v64; // [rsp+50h] [rbp-49h]
  int v65; // [rsp+54h] [rbp-45h]
  EdgeAndPair *pArr; // [rsp+58h] [rbp-41h] BYREF
  int v67; // [rsp+60h] [rbp-39h]
  int v68; // [rsp+64h] [rbp-35h]
  AMD_HD3D v69; // [rsp+68h] [rbp-31h] BYREF
  hkResult v71; // [rsp+108h] [rbp+6Fh] BYREF
  hkResult resulta; // [rsp+110h] [rbp+77h] BYREF
  hkResult v73; // [rsp+118h] [rbp+7Fh] BYREF

  v2 = 0;
  v3 = 0x80000000;
  m_size = edgePairs->m_size;
  v6 = 0i64;
  v8 = 2 * m_size;
  array = 0i64;
  v64 = 0;
  v65 = 0x80000000;
  pArr = 0i64;
  v67 = 0;
  v9 = 0x80000000;
  v68 = 0x80000000;
  if ( v8 <= 0 )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &array, v8, 16);
    v3 = v65;
    v9 = v68;
    v6 = pArr;
  }
  v10 = 2 * edgePairs->m_size;
  if ( (v9 & 0x3FFFFFFF) >= v10 )
  {
    m_enum = HK_SUCCESS;
    v71.m_enum = HK_SUCCESS;
  }
  else
  {
    if ( v10 < 2 * (v9 & 0x3FFFFFFF) )
      v10 = 2 * (v9 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&v71, &hkContainerTempAllocator::s_alloc, &pArr, v10, 8);
    v3 = v65;
    v9 = v68;
    v6 = pArr;
    m_enum = v71.m_enum;
  }
  if ( resulta.m_enum || m_enum )
  {
    v67 = 0;
    result->m_enum = HK_FAILURE;
    if ( v9 >= 0 )
    {
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v6, 8 * v9);
      v3 = v65;
    }
    pArr = 0i64;
    v68 = 0x80000000;
    v64 = 0;
    if ( v3 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 16 * v3);
    return result;
  }
  else
  {
    v13 = edgePairs->m_size;
    ptr = 0i64;
    v61 = 0;
    v62 = 0x80000000;
    SizeInBytesFor = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getSizeInBytesFor(2 * v13);
    v15 = SizeInBytesFor;
    if ( SizeInBytesFor <= 0 )
    {
      v73.m_enum = HK_SUCCESS;
    }
    else
    {
      hkArrayUtil::_reserve(&v73, &hkContainerTempAllocator::s_alloc, &ptr, SizeInBytesFor, 1);
      if ( v73.m_enum )
      {
        v16 = v62;
        result->m_enum = HK_FAILURE;
        v61 = 0;
        if ( v16 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, ptr, v16 & 0x3FFFFFFF);
        ptr = 0i64;
        v62 = 0x80000000;
        v67 = 0;
        if ( v68 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, pArr, 8 * v68);
        pArr = 0i64;
        v68 = 0x80000000;
        v64 = 0;
        if ( v65 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 16 * v65);
        return result;
      }
    }
    v61 = v15;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v69,
      ptr,
      v15);
    v17 = 0;
    if ( edgePairs->m_size > 0 )
    {
      v18 = 0i64;
      do
      {
        v19 = v64;
        v20 = &edgePairs->m_data[v18];
        if ( v64 == (v65 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &array, 16);
          v19 = v64;
        }
        v64 = v19 + 1;
        v21 = &array[16 * v19];
        *(_QWORD *)v21 = v20;
        *((_DWORD *)v21 + 2) = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                 (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v69,
                                 v20->m_edgeAIdx,
                                 0xFFFFFFFFFFFFFFFFui64);
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v69,
          &hkContainerTempAllocator::s_alloc,
          v20->m_edgeAIdx,
          v64 - 1);
        v22 = v64;
        if ( v64 == (v65 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &array, 16);
          v22 = v64;
        }
        v64 = v22 + 1;
        v23 = &array[16 * v22];
        *(_QWORD *)v23 = v20;
        *((_DWORD *)v23 + 2) = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                 (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v69,
                                 v20->m_edgeBIdx,
                                 0xFFFFFFFFFFFFFFFFui64);
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v69,
          &hkContainerTempAllocator::s_alloc,
          v20->m_edgeBIdx,
          v64 - 1);
        ++v17;
        ++v18;
      }
      while ( v17 < edgePairs->m_size );
    }
    v24 = *(_QWORD *)&v69.mEnableStereo;
    v25 = 0;
    v26 = 0i64;
    if ( (v69.mHeight & 0x80000000) == 0 )
    {
      v27 = *(_QWORD **)&v69.mEnableStereo;
      do
      {
        if ( *v27 != -1i64 )
          break;
        ++v26;
        ++v25;
        v27 += 2;
      }
      while ( v26 <= (int)v69.mHeight );
    }
    v28 = v25;
    if ( v25 <= (int)v69.mHeight )
    {
      do
      {
        v29 = v67;
        if ( v67 == (v68 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &pArr, 8);
          v29 = v67;
          v24 = *(_QWORD *)&v69.mEnableStereo;
        }
        v30 = pArr;
        v67 = v29 + 1;
        pArr[v29].m_edgeIndex = *(_DWORD *)(v24 + 16i64 * v28);
        v30[v29].m_pairListIndex = *(_DWORD *)(*(_QWORD *)&v69.mEnableStereo + 16i64 * v28 + 8);
        v24 = *(_QWORD *)&v69.mEnableStereo;
        v31 = v28 + 1;
        v32 = v28 + 1;
        if ( v32 <= (int)v69.mHeight )
        {
          v33 = (_QWORD *)(*(_QWORD *)&v69.mEnableStereo + 16i64 * v31);
          do
          {
            if ( *v33 != -1i64 )
              break;
            ++v32;
            ++v31;
            v33 += 2;
          }
          while ( v32 <= (int)v69.mHeight );
        }
        v28 = v31;
      }
      while ( v31 <= (int)v69.mHeight );
    }
    if ( v67 > 1 )
      hkAlgorithm::quickSortRecursive<EdgeAndPair,hkAlgorithm::less<EdgeAndPair>>(pArr, 0, v67 - 1, 0);
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v69,
      &hkContainerTempAllocator::s_alloc);
    _(&v69);
    v61 = 0;
    if ( v62 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, ptr, v62 & 0x3FFFFFFF);
    v34 = v67;
    v35 = pArr;
    v36 = 2i64;
    v37 = 0i64;
    ptr = (void *)2;
    do
    {
      if ( v34 > 0 )
      {
        v38 = 0i64;
        do
        {
          m_pairListIndex = v35[v38].m_pairListIndex;
          m_edgeIndex = v35[v38].m_edgeIndex;
          if ( m_pairListIndex != -1 )
          {
            do
            {
              v41 = 2i64 * m_pairListIndex;
              v42 = *(_QWORD *)&array[16 * m_pairListIndex];
              if ( *(_BYTE *)(v42 + 28) )
              {
                v43 = *(_DWORD *)v42 == m_edgeIndex ? *(float *)(v42 + 32) : *(float *)(v42 + 40);
                v44 = *(_DWORD *)v42 == m_edgeIndex ? *(float *)(v42 + 36) : *(float *)(v42 + 44);
                for ( i = *(_DWORD *)&array[8 * v41 + 8]; i != -1; i = *(_DWORD *)&array[8 * v47 + 8] )
                {
                  v46 = array;
                  v47 = 2i64 * i;
                  v48 = *(_QWORD *)&array[16 * i];
                  if ( *(_BYTE *)(v48 + 28) )
                  {
                    v49 = (float *)(v48 + 32);
                    if ( *(_DWORD *)v48 == m_edgeIndex )
                    {
                      v50 = (float *)(v48 + 36);
                    }
                    else
                    {
                      v49 = (float *)(v48 + 40);
                      v50 = (float *)(v48 + 44);
                    }
                    v51 = *v49;
                    v52 = *v50;
                    v73.m_enum = LODWORD(v44);
                    v53 = fminf(v44, v52) - fmaxf(v43, v51);
                    if ( v37 == 1 )
                    {
                      if ( v53 > 0.0 )
                        *(_BYTE *)(v48 + 28) = 0;
                    }
                    else
                    {
                      if ( v43 > v51 || (v54 = 1, v44 < v51) )
                        v54 = 0;
                      if ( v43 > v52 || (v55 = 1, v44 < v52) )
                        v55 = 0;
                      if ( v54 && v55 )
                      {
                        v56 = 1;
                      }
                      else
                      {
                        v56 = 0;
                        if ( v53 > 0.0 && v53 < 0.0099999998 )
                        {
                          if ( v54 )
                          {
                            if ( !v55 )
                              *v49 = v44;
                          }
                          else if ( v55 )
                          {
                            *v50 = v43;
                          }
                        }
                      }
                      if ( *v49 > v43 || (v57 = 1, v43 > *v50) )
                        v57 = 0;
                      if ( *v49 > v44 || (v58 = 1, v44 > *v50) )
                        v58 = 0;
                      if ( v57 && v58 )
                        *(_BYTE *)(v48 + 28) = 0;
                      if ( v56 )
                        *(_BYTE *)(v46[v47] + 28i64) = 0;
                    }
                  }
                }
              }
              m_pairListIndex = *(_DWORD *)&array[8 * v41 + 8];
            }
            while ( m_pairListIndex != -1 );
            v34 = v67;
            v35 = pArr;
          }
          ++v2;
          ++v38;
        }
        while ( v2 < v34 );
        v36 = (__int64)ptr;
      }
      ++v37;
      --v36;
      v2 = 0;
      ptr = (void *)v36;
    }
    while ( v36 );
    v59 = v68;
    result->m_enum = HK_SUCCESS;
    v67 = 0;
    if ( v59 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v35, 8 * v59);
    pArr = 0i64;
    v68 = 0x80000000;
    v64 = 0;
    if ( v65 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 16 * v65);
    return result;
  }
} v68;
    result->m_enum = HK_SUCCESS;

// File Line: 2132
// RVA: 0xB94120
hkaiNavMeshGenerationUtils *__fastcall hkaiNavMeshGenerationUtils::_gatherAndSortSplits<hkaiNavMesh>(
        hkaiNavMeshGenerationUtils *this,
        hkResult *result,
        hkaiNavMesh *meshA,
        hkaiNavMesh *meshB,
        hkArrayBase<hkaiNavMeshGenerationUtils::EdgePair> *edgePairs)
{
  hkArrayBase<hkaiNavMeshGenerationUtils::EdgePair> *v5; // rbx
  int v7; // r9d
  hkaiNavMeshGenerationUtils *v8; // r13
  int v9; // eax
  int v10; // eax
  int v12; // esi
  __int64 v13; // r14
  hkBaseObjectVtbl *v14; // rdi
  int vecDelDtor; // ecx
  float v16; // xmm0_4
  float v17; // xmm1_4
  int v18; // eax
  hkaiNavMeshGenerationUtils::EdgePair *m_data; // rcx
  __int64 v20; // rdx
  __int64 v21; // rax
  float v22; // xmm1_4
  hkaiNavMeshGenerationUtils::EdgePair *v23; // rcx
  __int64 v24; // rdx
  __int64 v25; // rax
  int m_size; // r8d
  __int64 v27; // rax
  hkaiNavMeshGenerationUtils::EdgePair *v28; // rcx
  hkaiNavMeshGenerationUtils::EdgeSplit v29; // [rsp+30h] [rbp-38h] BYREF

  v5 = edgePairs;
  v7 = 2 * *(_DWORD *)&meshB->m_memSizeAndFlags + 1;
  v8 = this;
  v9 = edgePairs->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v9 >= v7 )
  {
    LODWORD(edgePairs) = 0;
  }
  else
  {
    v10 = 2 * v9;
    if ( v7 < v10 )
      v7 = v10;
    hkArrayUtil::_reserve((hkResult *)&edgePairs, &hkContainerTempAllocator::s_alloc, edgePairs, v7, 24);
    if ( (_DWORD)edgePairs )
    {
      *(_DWORD *)v8 = 1;
      return v8;
    }
  }
  v12 = 0;
  if ( *(int *)&meshB->m_memSizeAndFlags > 0 )
  {
    v13 = 0i64;
    do
    {
      v14 = &meshB->vfptr[v13];
      if ( BYTE4(v14[1].__first_virtual_table_function__) )
      {
        vecDelDtor = (int)v14->__vecDelDtor;
        v16 = *(float *)&v14[2].__vecDelDtor;
        v17 = *((float *)&v14[2].__vecDelDtor + 1);
        v29.m_faceIdx = (int)v14->__first_virtual_table_function__;
        v29.m_tS = v16;
        v29.m_tE = v17;
        v18 = v5->m_capacityAndFlags & 0x3FFFFFFF;
        v29.m_edgeIdx = (vecDelDtor & 0x3FFFFF)
                      - *(_DWORD *)(*(_QWORD *)&result[4].m_enum + 16i64 * (v29.m_faceIdx & 0x3FFFFF));
        if ( v5->m_size == v18 )
          hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, v5, 24);
        m_data = v5->m_data;
        v20 = 3i64 * v5->m_size;
        *((_QWORD *)&m_data->m_edgeAIdx + v20) = *(_QWORD *)&v29.m_faceIdx;
        v21 = *(_QWORD *)&v29.m_tS;
        *((_QWORD *)&m_data->m_faceAIdx + v20) = v14;
        *((_QWORD *)&m_data->m_distanceSquared + v20) = v21;
        ++v5->m_size;
        LODWORD(v21) = HIDWORD(v14->__first_virtual_table_function__);
        v22 = *((float *)&v14[2].__first_virtual_table_function__ + 1);
        v29.m_tS = *(float *)&v14[2].__first_virtual_table_function__;
        v29.m_tE = v22;
        LODWORD(m_data) = HIDWORD(v14->__vecDelDtor);
        v29.m_faceIdx = v21;
        LODWORD(m_data) = ((unsigned int)m_data & 0x3FFFFF) - meshA->m_faces.m_data[v21 & 0x3FFFFF].m_startEdgeIndex;
        LODWORD(v21) = v5->m_capacityAndFlags & 0x3FFFFFFF;
        v29.m_edgeIdx = (int)m_data;
        if ( v5->m_size == (_DWORD)v21 )
          hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, v5, 24);
        v23 = v5->m_data;
        v24 = 3i64 * v5->m_size;
        *((_QWORD *)&v23->m_edgeAIdx + v24) = *(_QWORD *)&v29.m_faceIdx;
        v25 = *(_QWORD *)&v29.m_tS;
        *((_QWORD *)&v23->m_faceAIdx + v24) = (char *)&v14->__vecDelDtor + 4;
        *((_QWORD *)&v23->m_distanceSquared + v24) = v25;
        ++v5->m_size;
      }
      ++v12;
      v13 += 3i64;
    }
    while ( v12 < *(_DWORD *)&meshB->m_memSizeAndFlags );
    v8 = this;
  }
  m_size = v5->m_size;
  if ( m_size > 1 )
    hkAlgorithm::quickSortRecursive<hkaiNavMeshGenerationUtils::EdgeSplit,hkAlgorithm::less<hkaiNavMeshGenerationUtils::EdgeSplit>>(
      (hkaiNavMeshGenerationUtils::EdgeSplit *)v5->m_data,
      0,
      m_size - 1,
      0);
  hkaiNavMeshGenerationUtils::EdgeSplit::setAsTerminiator(&v29);
  if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, v5, 24);
  v27 = v5->m_size;
  v28 = v5->m_data;
  *(_DWORD *)v8 = 0;
  *((hkaiNavMeshGenerationUtils::EdgeSplit *)&v28->m_edgeAIdx + v27) = v29;
  return v8;
}

// File Line: 2183
// RVA: 0xB8E680
hkResult *__fastcall hkaiNavMeshGenerationUtils::_connectEdges(
        hkResult *result,
        hkaiNavMeshGenerationSettings *input,
        hkaiNavMesh *mesh,
        hkaiNavMesh *raycaster,
        int iterationNumber,
        hkaiNavMeshGenerationProgressCallback *cb,
        hkaiNavMeshGenerationProgressCallbackContext *cbCtx)
{
  bool v10; // r14
  hkResult *ConnectableEdges; // rax
  int v12; // ebx
  int m_size; // ecx
  int v14; // r9d
  __int64 v15; // r10
  hkaiNavMeshGenerationUtils::EdgePair *v16; // r8
  hkaiNavMeshGenerationProgressCallback *v18; // [rsp+28h] [rbp-58h]
  hkResult resulta; // [rsp+40h] [rbp-40h] BYREF
  hkResult v20; // [rsp+44h] [rbp-3Ch] BYREF
  hkArray<hkaiNavMeshGenerationUtils::EdgePair,hkContainerHeapAllocator> edgePairs; // [rsp+48h] [rbp-38h] BYREF
  hkArrayBase<hkaiNavMeshGenerationUtils::EdgePair> v22; // [rsp+58h] [rbp-28h] BYREF
  NavMeshFreeList freeList; // [rsp+68h] [rbp-18h] BYREF

  v10 = iterationNumber == 0;
  edgePairs.m_capacityAndFlags = 0x80000000;
  edgePairs.m_data = 0i64;
  edgePairs.m_size = 0;
  if ( iterationNumber )
    ConnectableEdges = hkaiNavMeshGenerationUtils::_findConnectableEdges(
                         (hkResult *)&iterationNumber,
                         input,
                         mesh,
                         raycaster,
                         &edgePairs,
                         iterationNumber,
                         cb,
                         cbCtx);
  else
    ConnectableEdges = hkaiNavMeshGenerationUtils::_findExactEdges(
                         (hkResult *)&iterationNumber,
                         input,
                         (hkSimdFloat32 *)mesh,
                         raycaster,
                         &edgePairs,
                         cb,
                         cbCtx);
  if ( ConnectableEdges->m_enum )
  {
    result->m_enum = HK_FAILURE;
    goto LABEL_33;
  }
  if ( !edgePairs.m_size )
  {
    result->m_enum = HK_SUCCESS;
    goto LABEL_33;
  }
  if ( input->m_edgeMatchingMetric.m_storage == 1 )
  {
    if ( edgePairs.m_size > 1 )
      hkAlgorithm::quickSortRecursive<hkaiNavMeshGenerationUtils::EdgePair,_sortEdgePairAscendingByOverlap>(
        edgePairs.m_data,
        0,
        edgePairs.m_size - 1,
        0);
  }
  else if ( edgePairs.m_size > 1 )
  {
    hkAlgorithm::quickSortRecursive<hkaiNavMeshGenerationUtils::EdgePair,_sortEdgePairDescendingByDistance>(
      edgePairs.m_data,
      0,
      edgePairs.m_size - 1,
      0);
  }
  if ( !v10 )
  {
    hkaiNavMeshGenerationUtils::_resolveConflictingEdgePairs((hkResult *)&iterationNumber, &edgePairs);
    if ( iterationNumber )
    {
      result->m_enum = HK_FAILURE;
      goto LABEL_33;
    }
  }
  v22.m_data = 0i64;
  v22.m_size = 0;
  v22.m_capacityAndFlags = 0x80000000;
  hkaiNavMeshGenerationUtils::_gatherAndSortSplits<hkaiNavMesh>(
    (hkaiNavMeshGenerationUtils *)&iterationNumber,
    (hkResult *)mesh,
    mesh,
    (hkaiNavMesh *)&edgePairs,
    &v22,
    (hkArray<hkaiNavMeshGenerationUtils::EdgeSplit,hkContainerTempAllocator> *)v18);
  if ( !iterationNumber )
  {
    v12 = 0;
    freeList.m_freeSpace.m_data = 0i64;
    freeList.m_freeSpace.m_size = 0;
    freeList.m_freeSpace.m_capacityAndFlags = 0x80000000;
    if ( v22.m_size <= 0 )
    {
LABEL_21:
      m_size = edgePairs.m_size;
      v14 = 0;
      if ( edgePairs.m_size > 0 )
      {
        v15 = 0i64;
        do
        {
          v16 = &edgePairs.m_data[v15];
          if ( edgePairs.m_data[v15].m_isValid )
          {
            mesh->m_edges.m_data[v16->m_edgeAIdx].m_oppositeEdge = v16->m_edgeBIdx;
            mesh->m_edges.m_data[v16->m_edgeBIdx].m_oppositeEdge = v16->m_edgeAIdx;
            mesh->m_edges.m_data[v16->m_edgeAIdx].m_oppositeFace = v16->m_faceBIdx;
            mesh->m_edges.m_data[v16->m_edgeBIdx].m_oppositeFace = v16->m_faceAIdx;
            m_size = edgePairs.m_size;
          }
          ++v14;
          ++v15;
        }
        while ( v14 < m_size );
      }
      hkaiNavMeshUtils::compactEdges(&v20, mesh, 0, 0);
      if ( v20.m_enum == HK_SUCCESS )
      {
        result->m_enum = HK_SUCCESS;
        goto LABEL_29;
      }
    }
    else
    {
      while ( 1 )
      {
        iterationNumber = 0;
        _splitEdges(
          &resulta,
          mesh,
          *(&v22.m_data->m_edgeAIdx + 6 * v12),
          (hkaiNavMeshGenerationUtils::EdgeSplit *)v22.m_data + v12,
          &freeList,
          &iterationNumber);
        if ( resulta.m_enum )
          break;
        v12 += iterationNumber;
        if ( v12 >= v22.m_size )
          goto LABEL_21;
      }
    }
    result->m_enum = HK_FAILURE;
LABEL_29:
    hkArray<hkArray<unsigned int,hkContainerHeapAllocator>,hkContainerHeapAllocator>::~hkArray<hkArray<unsigned int,hkContainerHeapAllocator>,hkContainerHeapAllocator>(&freeList);
    goto LABEL_30;
  }
  result->m_enum = HK_FAILURE;
LABEL_30:
  v22.m_size = 0;
  if ( v22.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      v22.m_data,
      24 * (v22.m_capacityAndFlags & 0x3FFFFFFF));
  v22.m_capacityAndFlags = 0x80000000;
  v22.m_data = 0i64;
LABEL_33:
  edgePairs.m_size = 0;
  if ( edgePairs.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      edgePairs.m_data,
      48 * (edgePairs.m_capacityAndFlags & 0x3FFFFFFF));
  return result;
}

