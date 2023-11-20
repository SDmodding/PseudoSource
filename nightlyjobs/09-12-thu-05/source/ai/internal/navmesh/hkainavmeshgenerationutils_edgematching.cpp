// File Line: 46
// RVA: 0xB902E0
hkSimdFloat32 *__fastcall findFurthestVertexOfFaceBehindLine_hkaiNavMesh_1_(hkSimdFloat32 *result, hkaiNavMesh *mesh, int faceIdx, hkVector4f *edgePlaneProjected, hkVector4f *furthestPointOut)
{
  hkVector4f v5; // xmm5
  hkVector4f *v6; // r11
  hkaiNavMesh::Face *v7; // rax
  __int64 v8; // r8
  __int64 v9; // r9
  hkVector4f *v10; // r8
  __m128 v11; // xmm6
  hkaiNavMesh::Edge *v12; // rdx
  signed __int64 v13; // rax
  __m128 v14; // xmm1
  __m128 v15; // xmm1
  __m128 v16; // xmm0
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  hkSimdFloat32 v19; // xmm1
  __m128 v20; // xmm0
  __m128 v21; // xmm3

  v5.m_quad = 0i64;
  v6 = edgePlaneProjected;
  v7 = &mesh->m_faces.m_data[faceIdx];
  v8 = v7->m_numEdges;
  result->m_real = _mm_sub_ps((__m128)0i64, (__m128)xmmword_141A712A0);
  v9 = v8;
  if ( (signed int)v8 > 0 )
  {
    v10 = mesh->m_vertices.m_data;
    v11 = v6->m_quad;
    v12 = &mesh->m_edges.m_data[v7->m_startEdgeIndex];
    do
    {
      v13 = v12->m_a;
      ++v12;
      v14 = _mm_mul_ps(v11, v10[v13].m_quad);
      v15 = _mm_shuffle_ps(v14, _mm_unpackhi_ps(v14, v11), 196);
      v16 = _mm_add_ps(_mm_shuffle_ps(v15, v15, 78), v15);
      v17 = _mm_add_ps(_mm_shuffle_ps(v16, v16, 177), v16);
      v18 = _mm_cmpltps(result->m_real, v17);
      v19.m_real = _mm_or_ps(_mm_andnot_ps(v18, result->m_real), _mm_and_ps(v18, v17));
      v20 = v18;
      v21 = _mm_and_ps(v18, v10[v13].m_quad);
      *result = (hkSimdFloat32)v19.m_real;
      v5.m_quad = _mm_or_ps(_mm_andnot_ps(v20, v5.m_quad), v21);
      --v9;
    }
    while ( v9 );
  }
  *furthestPointOut = (hkVector4f)v5.m_quad;
  return result;
}

// File Line: 82
// RVA: 0xB8BDB0
hkaiNavMeshGenerationConnectivityResult::ConnectivityResultEnum __fastcall hkaiNavMeshGenerationUtils::calculateConnectivity(hkaiNavMeshEdgeMatchingParameters *input, hkVector4f *up, hkSimdFloat32 *characterHeight, hkaiNavMesh *mesh, hkaiEdgeGeometryRaycaster *raycaster, int edgeAIdx, int edgeBIdx, int faceAIdx, int faceBIdx, hkaiNavMeshGenerationUtils::EdgePair *edgePair)
{
  hkaiEdgeGeometryRaycaster *v11; // [rsp+30h] [rbp-38h]
  hkaiNavMeshGenerationUtils::EdgePair *v12; // [rsp+58h] [rbp-10h]

  LODWORD(v11) = edgeAIdx;
  return hkaiNavMeshGenerationUtils::_calculateConnectivity<hkaiNavMesh,0>(
           (hkaiNavMeshGenerationUtils *)input,
           (hkaiNavMeshEdgeMatchingParameters *)up,
           (hkVector4f *)characterHeight,
           (hkSimdFloat32 *)mesh,
           mesh,
           (hkaiNavMesh *)raycaster,
           v11,
           edgeBIdx,
           faceAIdx,
           faceBIdx,
           (int)edgePair,
           v12);
}

// File Line: 87
// RVA: 0xB8BE10
hkaiNavMeshGenerationConnectivityResult::ConnectivityResultEnum __fastcall hkaiNavMeshGenerationUtils::calculateWallClimbingConnectivity(hkaiNavMeshEdgeMatchingParameters *input, hkSimdFloat32 *characterHeight, hkaiNavMesh *mesh, hkaiEdgeGeometryRaycaster *raycaster, int edgeAIdx, int edgeBIdx, int faceAIdx, int faceBIdx, hkaiNavMeshGenerationUtils::EdgePair *edgePair)
{
  hkaiEdgeGeometryRaycaster *raycastera; // [rsp+30h] [rbp-48h]
  hkaiNavMeshGenerationUtils::EdgePair *v11; // [rsp+58h] [rbp-20h]
  __int128 v12; // [rsp+60h] [rbp-18h]

  _mm_store_si128((__m128i *)&v12, (__m128i)aabbOut.m_quad);
  LODWORD(raycastera) = edgeAIdx;
  return hkaiNavMeshGenerationUtils::_calculateConnectivity<hkaiNavMesh,1>(
           (hkaiNavMeshGenerationUtils *)input,
           (hkaiNavMeshEdgeMatchingParameters *)&v12,
           (hkVector4f *)characterHeight,
           (hkSimdFloat32 *)mesh,
           mesh,
           (hkaiNavMesh *)raycaster,
           raycastera,
           edgeBIdx,
           faceAIdx,
           faceBIdx,
           (int)edgePair,
           v11);
}

// File Line: 93
// RVA: 0xB8BE80
hkaiNavMeshGenerationConnectivityResult::ConnectivityResultEnum __fastcall hkaiNavMeshGenerationUtils::calculateConnectivity(hkaiNavMeshEdgeMatchingParameters *input, hkVector4f *up, hkaiNavMeshInstance *meshInstanceA, hkaiNavMeshInstance *meshInstanceB, int edgeAIdx, int edgeBIdx, int faceAIdx, int faceBIdx, hkaiNavMeshGenerationUtils::EdgePair *edgePair)
{
  hkaiNavMeshInstance *meshA; // rdi
  hkSimdFloat32 *v10; // rsi
  char v11; // r10
  char v12; // r11
  char v13; // r14
  char v14; // r12
  bool v15; // al
  bool v16; // r15
  hkaiNavMeshGenerationConnectivityResult::ConnectivityResultEnum result; // eax
  float v18; // xmm8_4
  float v19; // xmm9_4
  float v20; // xmm10_4
  float v21; // xmm11_4
  float v22; // xmm12_4
  float v23; // xmm13_4
  float v24; // xmm14_4
  int v25; // xmm15_4
  int v26; // xmm0_4
  float v27; // xmm2_4
  float v28; // xmm6_4
  float v29; // xmm7_4
  float v30; // xmm4_4
  float v31; // xmm3_4
  float v32; // xmm5_4
  int v33; // xmm1_4
  int v34; // xmm0_4
  float v35; // xmm1_4
  int v36; // xmm0_4
  hkaiEdgeGeometryRaycaster *raycaster; // [rsp+30h] [rbp-D0h]
  hkaiNavMeshGenerationUtils::EdgePair *v38; // [rsp+58h] [rbp-A8h]
  int v39; // [rsp+60h] [rbp-A0h]
  int v40; // [rsp+64h] [rbp-9Ch]
  hkVector4f upa; // [rsp+70h] [rbp-90h]
  int v42; // [rsp+80h] [rbp-80h]
  int v43; // [rsp+84h] [rbp-7Ch]
  int v44; // [rsp+88h] [rbp-78h]
  int v45; // [rsp+8Ch] [rbp-74h]
  hkaiNavMeshEdgeMatchingParameters *v46; // [rsp+190h] [rbp+90h]
  int v47; // [rsp+1A0h] [rbp+A0h]
  int v48; // [rsp+1A8h] [rbp+A8h]

  v46 = input;
  meshA = meshInstanceB;
  v10 = (hkSimdFloat32 *)meshInstanceA;
  v11 = meshInstanceB->m_originalMesh.m_pntr->m_flags.m_storage & 1;
  v12 = meshInstanceA->m_originalMesh.m_pntr->m_flags.m_storage & 1;
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
               (hkaiNavMeshGenerationUtils *)input,
               (hkaiNavMeshEdgeMatchingParameters *)up,
               &upa,
               (hkSimdFloat32 *)meshInstanceA,
               meshInstanceB,
               0i64,
               raycaster,
               edgeBIdx,
               faceAIdx,
               faceBIdx,
               (int)edgePair,
               v38);
    if ( v13 || result != -1 )
      return result;
    input = v46;
  }
  v18 = edgePair->m_distanceSquared;
  v19 = edgePair->m_edgeAlignment;
  v20 = edgePair->m_overlap;
  v21 = edgePair->m_tStartA;
  v22 = edgePair->m_tEndA;
  v23 = edgePair->m_tStartB;
  v24 = edgePair->m_tEndB;
  v25 = edgePair->m_edgeAIdx;
  v47 = edgePair->m_edgeBIdx;
  v48 = edgePair->m_faceAIdx;
  v39 = edgePair->m_faceBIdx;
  v40 = *(_DWORD *)&edgePair->m_isValid;
  if ( !v16
    || (LODWORD(raycaster) = edgeAIdx,
        result = hkaiNavMeshGenerationUtils::_calculateConnectivity<hkaiNavMeshInstance,1>(
                   (hkaiNavMeshGenerationUtils *)input,
                   (hkaiNavMeshEdgeMatchingParameters *)&aabbOut,
                   &upa,
                   v10,
                   meshA,
                   0i64,
                   raycaster,
                   edgeBIdx,
                   faceAIdx,
                   faceBIdx,
                   (int)edgePair,
                   v38),
        !v14)
    && result == -1 )
  {
    v26 = edgePair->m_edgeAIdx;
    v27 = edgePair->m_distanceSquared;
    result = -1;
    v28 = edgePair->m_tStartB;
    v29 = edgePair->m_tEndB;
    v30 = edgePair->m_overlap;
    v31 = edgePair->m_tStartA;
    v32 = edgePair->m_tEndA;
    v43 = edgePair->m_edgeBIdx;
    v33 = edgePair->m_faceBIdx;
    v42 = v26;
    v34 = edgePair->m_faceAIdx;
    v45 = v33;
    v35 = edgePair->m_edgeAlignment;
    v44 = v34;
    v36 = *(_DWORD *)&edgePair->m_isValid;
    edgePair->m_edgeAIdx = v25;
    edgePair->m_edgeBIdx = v47;
    edgePair->m_faceAIdx = v48;
    edgePair->m_faceBIdx = v39;
    *(_DWORD *)&edgePair->m_isValid = v40;
    edgePair->m_edgeAlignment = (float)(v35 + v19) * 0.5;
    edgePair->m_distanceSquared = (float)(v27 + v18) * 0.5;
    edgePair->m_tStartA = fmaxf(v21, v31);
    edgePair->m_overlap = (float)(v30 + v20) * 0.5;
    edgePair->m_tEndA = fminf(v22, v32);
    edgePair->m_tStartB = fmaxf(v23, v28);
    edgePair->m_tEndB = fminf(v24, v29);
  }
  return result;
}

// File Line: 199
// RVA: 0xB8EBE0
void __fastcall `anonymous namespace::SegmentPair::SegmentPair(SegmentPair *this, hkVector4f *SA, hkVector4f *EA, hkVector4f *SB, hkVector4f *EB)
{
  hkSimdFloat32 tEB; // [rsp+30h] [rbp-48h]
  hkSimdFloat32 tSB; // [rsp+40h] [rbp-38h]
  hkSimdFloat32 tEA; // [rsp+50h] [rbp-28h]
  hkSimdFloat32 tSA; // [rsp+60h] [rbp-18h]

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
void __fastcall `anonymous namespace::SegmentPair::updateT(SegmentPair *this, hkSimdFloat32 *tSA, hkSimdFloat32 *tEA, hkSimdFloat32 *tSB, hkSimdFloat32 *tEB)
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
void __fastcall `anonymous namespace::SegmentPair::updateProjection(SegmentPair *this, hkVector4f *up, __int64 a3, hkVector4f *a4)
{
  SegmentPair *v4; // rbx
  hkVector4f *v5; // rdi
  hkVector4f *v6; // r9
  hkVector4f *v7; // r9
  hkVector4f *v8; // r9

  v4 = this;
  v5 = up;
  `anonymous namespace::SegmentPair::projectPoint((SegmentPair *)((char *)this + 64), up, &this->m_pSAProjected, a4);
  `anonymous namespace::SegmentPair::projectPoint((SegmentPair *)((char *)v4 + 80), v5, &v4->m_pEAProjected, v6);
  `anonymous namespace::SegmentPair::projectPoint((SegmentPair *)((char *)v4 + 96), v5, &v4->m_pSBProjected, v7);
  `anonymous namespace::SegmentPair::projectPoint((SegmentPair *)((char *)v4 + 112), v5, &v4->m_pEBProjected, v8);
}

// File Line: 225
// RVA: 0xB8F240
void __fastcall `anonymous namespace::SegmentPair::projectPoint(SegmentPair *this, hkVector4f *p, hkVector4f *up, hkVector4f *projOut)
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
hkSimdFloat32 *__fastcall `anonymous namespace::SegmentPair::clippedDistanceSquared(SegmentPair *this, hkSimdFloat32 *result, hkVector4f *closestAminusClosestB)
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
  __m128 v28; // xmm0
  __m128 v29; // xmm3
  __m128 v30; // xmm0
  __m128 v31; // xmm2
  __m128 v32; // xmm11
  __m128 v33; // xmm1
  hkVector4f v34; // xmm5
  __m128 v35; // xmm5

  v3 = _mm_sub_ps(this->m_pEA.m_quad, this->m_pSA.m_quad);
  v4.m_quad = (__m128)this->m_pSB;
  v5 = _mm_sub_ps(this->m_pEB.m_quad, v4.m_quad);
  v6 = _mm_mul_ps(v3, v5);
  v7 = _mm_sub_ps(this->m_pSB.m_quad, this->m_pSA.m_quad);
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
  v25 = _mm_cmpleps(v17, *(__m128 *)&epsilon);
  v26 = _mm_mul_ps(v24, v22);
  v27 = _mm_sub_ps(_mm_mul_ps(v16, v11), _mm_mul_ps(v12, v8));
  v28 = _mm_cmpltps(v27, v17);
  v29 = _mm_sub_ps(
          _mm_mul_ps(
            _mm_or_ps(
              _mm_andnot_ps(
                v25,
                _mm_mul_ps(_mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v28, v17), _mm_and_ps(v28, v27))), v19)),
              _mm_and_ps(v25, query.m_quad)),
            _mm_mul_ps(v8, v21)),
          _mm_mul_ps(v12, v21));
  v30 = _mm_cmpltps(v29, query.m_quad);
  v31 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v30, query.m_quad), _mm_and_ps(v29, v30)));
  v32 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v8, v26), v31), _mm_mul_ps(v11, v26));
  v33 = _mm_cmpltps(v32, query.m_quad);
  v34.m_quad = _mm_sub_ps(
                 _mm_add_ps(
                   _mm_mul_ps(
                     _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v33, query.m_quad), _mm_and_ps(v33, v32))),
                     v3),
                   this->m_pSA.m_quad),
                 _mm_add_ps(_mm_mul_ps(v31, v5), v4.m_quad));
  *closestAminusClosestB = (hkVector4f)v34.m_quad;
  v35 = _mm_mul_ps(v34.m_quad, v34.m_quad);
  result->m_real = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)),
                     _mm_shuffle_ps(v35, v35, 170));
  return v23;
}

// File Line: 277
// RVA: 0xB8EFC0
hkSimdFloat32 *__fastcall `anonymous namespace::SegmentPair::projectedDistanceSquared(SegmentPair *this, hkSimdFloat32 *result)
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
  __m128 v27; // xmm0
  __m128 v28; // xmm3
  __m128 v29; // xmm0
  __m128 v30; // xmm2
  __m128 v31; // xmm11
  __m128 v32; // xmm1
  __m128 v33; // xmm5
  __m128 v34; // xmm5

  v2 = _mm_sub_ps(this->m_pEAProjected.m_quad, this->m_pSAProjected.m_quad);
  v3.m_quad = (__m128)this->m_pSBProjected;
  v4 = _mm_sub_ps(this->m_pEBProjected.m_quad, v3.m_quad);
  v5 = _mm_mul_ps(v2, v4);
  v6 = _mm_sub_ps(this->m_pSBProjected.m_quad, this->m_pSAProjected.m_quad);
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
  v24 = _mm_cmpleps(v16, *(__m128 *)&epsilon);
  v25 = _mm_mul_ps(v23, v21);
  v26 = _mm_sub_ps(_mm_mul_ps(v15, v10), _mm_mul_ps(v11, v7));
  v27 = _mm_cmpltps(v26, v16);
  v28 = _mm_sub_ps(
          _mm_mul_ps(
            _mm_or_ps(
              _mm_andnot_ps(
                v24,
                _mm_mul_ps(_mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v27, v16), _mm_and_ps(v27, v26))), v18)),
              _mm_and_ps(v24, query.m_quad)),
            _mm_mul_ps(v7, v20)),
          _mm_mul_ps(v11, v20));
  v29 = _mm_cmpltps(v28, query.m_quad);
  v30 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v29, query.m_quad), _mm_and_ps(v28, v29)));
  v31 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v7, v25), v30), _mm_mul_ps(v10, v25));
  v32 = _mm_cmpltps(v31, query.m_quad);
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
signed __int64 __fastcall checkProjections(SegmentPair *segPair, hkaiNavMeshEdgeMatchingParameters *input, hkVector4f *up, hkVector4f *dirA, hkVector4f *dirB, hkSimdFloat32 *minA, hkSimdFloat32 *maxA, hkSimdFloat32 *minB, hkSimdFloat32 *maxB, float *intervalOverlapReal)
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
  __m128 v22; // xmm0
  __m128 v23; // xmm5
  __m128 v24; // xmm2
  float v25; // xmm1_4
  __m128 v26; // xmm4
  __m128 v27; // xmm3
  float v28; // xmm2_4
  float v29; // xmm3_4
  signed __int64 result; // rax

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
            _mm_cmpleps(v14, (__m128)0i64),
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
  v22 = minB->m_real;
  if ( COERCE_FLOAT(*minB) > v21.m_real.m128_f32[0] )
  {
    *minB = (hkSimdFloat32)v21.m_real;
    *maxB = (hkSimdFloat32)v22;
  }
  v23 = minB->m_real;
  v24 = maxA->m_real;
  LODWORD(v25) = (unsigned __int128)_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_000001), (__m128)LODWORD(FLOAT_0_000001), 0);
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
  if ( v28 >= input->m_minEdgeOverlap
    || (LODWORD(v29) = (unsigned __int128)_mm_shuffle_ps(
                                            (__m128)LODWORD(FLOAT_0_0000099999997),
                                            (__m128)LODWORD(FLOAT_0_0000099999997),
                                            0),
        COERCE_FLOAT((unsigned int)(2
                                  * COERCE_SIGNED_INT(v28 - (float)(maxA->m_real.m128_f32[0] - minA->m_real.m128_f32[0]))) >> 1) < v29)
    || COERCE_FLOAT((unsigned int)(2
                                 * COERCE_SIGNED_INT(v28 - (float)(maxB->m_real.m128_f32[0] - minB->m_real.m128_f32[0]))) >> 1) < v29 )
  {
    result = 0xFFFFFFFFi64;
  }
  else
  {
    result = 4i64;
  }
  return result;
} )
  {
    result = 0xFFFFFFFFi64;
  }
  else
  {
    result = 4i64;
  }
  return res

// File Line: 365
// RVA: 0xB8F4F0
signed __int64 __fastcall clipToMaxDistance(SegmentPair *segPair, hkaiNavMeshEdgeMatchingParameters *input, hkVector4f *up, ClipType clipType)
{
  hkVector4f *v4; // rsi
  hkaiNavMeshEdgeMatchingParameters *v5; // rdi
  SegmentPair *v6; // rbx
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
  __m128 v36; // xmm2
  __m128 v37; // xmm0
  __m128 v38; // xmm2
  __m128 v39; // xmm0
  hkSimdFloat32 v40; // xmm1
  __m128 v41; // xmm2
  __m128 v42; // xmm5
  __m128 v43; // xmm1
  __m128 v44; // xmm3
  __m128 v45; // xmm2
  __m128 v46; // xmm4
  __m128 v47; // xmm5
  __m128 v48; // xmm1
  __m128 v49; // xmm2
  __m128 v50; // xmm1
  unsigned int v51; // eax
  unsigned int v52; // ecx
  hkSimdFloat32 tEB; // [rsp+50h] [rbp-B8h]
  hkSimdFloat32 tSB; // [rsp+60h] [rbp-A8h]
  hkSimdFloat32 tEA; // [rsp+70h] [rbp-98h]
  hkSimdFloat32 tSA; // [rsp+80h] [rbp-88h]
  hkSimdFloat32 maxA; // [rsp+90h] [rbp-78h]
  hkSimdFloat32 minA; // [rsp+A0h] [rbp-68h]
  float intervalOverlapReal; // [rsp+128h] [rbp+20h]

  v4 = up;
  v5 = input;
  v6 = segPair;
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
    v9 = _mm_andnot_ps(_mm_cmpleps(v15, (__m128)0i64), _mm_mul_ps(v18, v15));
    v20 = _mm_rsqrt_ps(v19);
    v11 = _mm_andnot_ps(
            _mm_cmpleps(v19, (__m128)0i64),
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
    v32 = _mm_cmpltps(v25, query.m_quad);
    v33 = _mm_or_ps(_mm_and_ps(v25, v32), _mm_andnot_ps(v32, query.m_quad));
    v34 = _mm_cmpltps(v24, query.m_quad);
    v30 = _mm_max_ps((__m128)0i64, v33);
    v31 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v24, v34), _mm_andnot_ps(v34, query.m_quad)));
  }
  else
  {
    v26 = _mm_cmpltps(v24, query.m_quad);
    v27 = _mm_and_ps(v24, v26);
    v28 = _mm_andnot_ps(v26, query.m_quad);
    v29 = _mm_cmpltps(v25, query.m_quad);
    v30 = _mm_max_ps((__m128)0i64, _mm_or_ps(v28, v27));
    v31 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v25, v29), _mm_andnot_ps(v29, query.m_quad)));
  }
  v35.m_real = (__m128)segPair->m_tStartA;
  v36 = _mm_sub_ps(segPair->m_tEndA.m_real, v35.m_real);
  v37 = v36;
  v38 = _mm_add_ps(_mm_mul_ps(v36, v31), v35.m_real);
  v39 = _mm_add_ps(_mm_mul_ps(v37, v30), v35.m_real);
  v40.m_real = (__m128)segPair->m_tEndB;
  tEA.m_real = v38;
  v41 = _mm_sub_ps(segPair->m_tStartB.m_real, v40.m_real);
  tSA.m_real = v39;
  tEB.m_real = _mm_add_ps(_mm_mul_ps(v41, v30), v40.m_real);
  tSB.m_real = _mm_add_ps(_mm_mul_ps(v41, v31), v40.m_real);
  `anonymous namespace::SegmentPair::updateT(segPair, &tSA, &tEA, &tSB, &tEB);
  if ( `anonymous namespace::SegmentPair::areIntervalsDisjoint(v6) )
    return 5i64;
  v42 = _mm_sub_ps(v6->m_endA.m_quad, v6->m_startA.m_quad);
  v43 = _mm_mul_ps(v42, v42);
  v44 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)), _mm_shuffle_ps(v43, v43, 170));
  v45 = _mm_rsqrt_ps(v44);
  v46 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmpleps(v44, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v45, v44), v45)),
              _mm_mul_ps(v45, *(__m128 *)_xmm))),
          v42);
  v47 = _mm_sub_ps(v6->m_endB.m_quad, v6->m_startB.m_quad);
  tEA.m_real = v46;
  v48 = _mm_mul_ps(v47, v47);
  v49 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v48, v48, 85), _mm_shuffle_ps(v48, v48, 0)), _mm_shuffle_ps(v48, v48, 170));
  v50 = _mm_rsqrt_ps(v49);
  tSA.m_real = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmpleps(v49, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v50, v49), v50)),
                     _mm_mul_ps(v50, *(__m128 *)_xmm))),
                 v47);
  v51 = checkProjections(
          v6,
          v5,
          v4,
          (hkVector4f *)&tEA,
          (hkVector4f *)&tSA,
          &minA,
          &maxA,
          &tEB,
          &tSB,
          &intervalOverlapReal);
  v52 = -1;
  if ( v51 != -1 )
    v52 = v51;
  return v52;
}

// File Line: 465
// RVA: 0xB91260
__int64 __usercall hkaiNavMeshGenerationUtils::_calculateConnectivity<hkaiNavMesh,0>@<rax>(hkaiNavMeshGenerationUtils *this@<rcx>, hkaiNavMeshEdgeMatchingParameters *input@<rdx>, hkVector4f *up@<r8>, hkSimdFloat32 *characterHeight@<r9>, unsigned int a5@<edi>, hkaiNavMesh *meshA, hkaiNavMesh *meshB, hkaiEdgeGeometryRaycaster *raycaster, int edgeAIdx, int edgeBIdx, int faceAIdx, int faceBIdx, hkaiNavMeshGenerationUtils::EdgePair *edgePairOut)
{
  hkaiNavMesh *v13; // r12
  int v14; // er14
  hkaiNavMesh *v15; // r13
  unsigned __int64 v16; // r9
  hkaiNavMeshGenerationUtils *v17; // rbx
  hkVector4f *v18; // rcx
  __m128 v19; // xmm12
  hkVector4f *v20; // rsi
  hkaiNavMesh::Edge *v21; // rdx
  __int64 v22; // rax
  __m128 v23; // xmm0
  hkVector4f *v24; // rcx
  signed __int64 v25; // rax
  __m128 v26; // xmm0
  __int64 v27; // rax
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
  __int64 v52; // rax
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
  float v89; // xmm1_4
  float v90; // xmm1_4
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
  __m128 v147; // xmm1
  hkVector4f *v148; // r9
  __m128 v149; // xmm10
  __m128 v150; // xmm8
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
  hkVector4f *v204; // ST20_8
  hkVector4f *EB; // [rsp+20h] [rbp-A8h]
  hkVector4f EA; // [rsp+48h] [rbp-80h]
  hkVector4f furthestPointOut; // [rsp+58h] [rbp-70h]
  hkVector4f SA; // [rsp+68h] [rbp-60h]
  hkSimdFloat32 result; // [rsp+78h] [rbp-50h]
  hkSimdFloat32 v210; // [rsp+88h] [rbp-40h]
  hkVector4f dirB; // [rsp+98h] [rbp-30h]
  hkVector4f dirA; // [rsp+A8h] [rbp-20h]
  SegmentPair segPair; // [rsp+B8h] [rbp-10h]
  hkVector4f normalB; // [rsp+1B8h] [rbp+F0h]
  int faceIndex; // [rsp+1C8h] [rbp+100h]
  bool v216; // [rsp+2B8h] [rbp+1F0h]
  hkSimdFloat32 *characterHeighta; // [rsp+2C8h] [rbp+200h]
  hkaiNavMesh *mesh; // [rsp+2D8h] [rbp+210h]
  hkaiEdgeGeometryRaycaster *vars0; // [rsp+2E0h] [rbp+218h]
  void *retaddr; // [rsp+2E8h] [rbp+220h]
  int v221; // [rsp+2F0h] [rbp+228h]
  hkVector4f *faceIdx; // [rsp+300h] [rbp+238h]
  hkaiNavMeshGenerationUtils::EdgePair *edgePair; // [rsp+308h] [rbp+240h]

  faceIdx = up;
  v13 = mesh;
  v14 = (signed int)retaddr;
  v216 = vars0 == 0i64;
  v15 = (hkaiNavMesh *)characterHeight;
  v16 = characterHeight[2].m_real.m128_u64[0];
  v17 = this;
  v18 = v15->m_vertices.m_data;
  v19 = *(__m128 *)&input->m_maxStepHeight;
  v20 = (hkVector4f *)input;
  v21 = mesh->m_edges.m_data;
  v22 = *(signed int *)(v16 + 20i64 * (signed int)retaddr + 4);
  v210.m_real = (__m128)v18[*(signed int *)(v16 + 20i64 * (signed int)retaddr)];
  SA.m_quad = v210.m_real;
  v23 = v18[v22].m_quad;
  v24 = mesh->m_vertices.m_data;
  v25 = v21[v221].m_a;
  EA.m_quad = v23;
  v26 = v24[v25].m_quad;
  v27 = v21[v221].m_b;
  result.m_real = v26;
  *(hkVector4f *)((char *)&SA + 8) = (hkVector4f)v26;
  furthestPointOut.m_quad = (__m128)v24[v27];
  `anonymous namespace::SegmentPair::SegmentPair(
    &segPair,
    &SA,
    &EA,
    (hkVector4f *)((char *)&SA + 8),
    &furthestPointOut);
  v28 = _mm_sub_ps(segPair.m_endA.m_quad, segPair.m_startA.m_quad);
  v29 = _mm_mul_ps(v28, v28);
  v30 = _mm_sub_ps(segPair.m_endB.m_quad, segPair.m_startB.m_quad);
  v31 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)), _mm_shuffle_ps(v29, v29, 170));
  v32 = _mm_rsqrt_ps(v31);
  v33 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmpleps(v31, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v32, v31), v32)),
              _mm_mul_ps(v32, *(__m128 *)_xmm))),
          v28);
  v34 = _mm_mul_ps(v30, v30);
  dirA.m_quad = v33;
  v35 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)), _mm_shuffle_ps(v34, v34, 170));
  v36 = _mm_rsqrt_ps(v35);
  v37 = _mm_andnot_ps(
          _mm_cmpleps(v35, (__m128)0i64),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v36, v35), v36)), _mm_mul_ps(v36, *(__m128 *)_xmm)));
  v38 = _mm_mul_ps(v28, v19);
  v39 = _mm_mul_ps(v37, v30);
  dirB.m_quad = v39;
  v40 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)), _mm_shuffle_ps(v38, v38, 170));
  v41 = _mm_mul_ps(v30, v19);
  v42 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps((__m128)0i64, v40), v19), v28);
  v43 = _mm_mul_ps(v42, v42);
  v44 = _mm_add_ps(
          _mm_mul_ps(
            _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)),
                _mm_shuffle_ps(v41, v41, 170))),
            v19),
          v30);
  v45 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)), _mm_shuffle_ps(v43, v43, 170));
  v46 = _mm_rsqrt_ps(v45);
  v47 = _mm_mul_ps(v44, v44);
  v48 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmpleps(v45, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v46, v45), v46)),
              _mm_mul_ps(v46, *(__m128 *)_xmm))),
          v42);
  v49 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v47, v47, 85), _mm_shuffle_ps(v47, v47, 0)), _mm_shuffle_ps(v47, v47, 170));
  v50 = _mm_rsqrt_ps(v49);
  v51 = _mm_mul_ps(
          _mm_mul_ps(
            _mm_andnot_ps(
              _mm_cmpleps(v49, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v50, v49), v50)),
                _mm_mul_ps(v50, *(__m128 *)_xmm))),
            v44),
          v48);
  *(float *)&retaddr = 0.0
                     - (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v51, v51, 85))
                                     + COERCE_FLOAT(_mm_shuffle_ps(v51, v51, 0)))
                             + COERCE_FLOAT(_mm_shuffle_ps(v51, v51, 170)));
  if ( *(float *)&retaddr < *(float *)&v17[16] )
    return 0i64;
  v53 = _mm_sub_ps(v33, v39);
  v54 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v53), _mm_mul_ps(_mm_shuffle_ps(v53, v53, 201), v19));
  v55 = _mm_shuffle_ps(v54, v54, 201);
  v56 = _mm_mul_ps(v55, v55);
  v57 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v56, v56, 85), _mm_shuffle_ps(v56, v56, 0)), _mm_shuffle_ps(v56, v56, 170));
  v58 = _mm_rsqrt_ps(v57);
  v59 = _mm_mul_ps(
          v55,
          _mm_andnot_ps(
            _mm_cmpleps(v57, (__m128)0i64),
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
            _mm_cmpleps(v66, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v67, v66), v67)),
              _mm_mul_ps(v67, *(__m128 *)_xmm))));
  v70 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v68, v68, 85), _mm_shuffle_ps(v68, v68, 0)), _mm_shuffle_ps(v68, v68, 170));
  v71 = _mm_rsqrt_ps(v70);
  v72 = _mm_mul_ps(
          _mm_mul_ps(
            _mm_andnot_ps(
              _mm_cmpleps(v70, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v71, v70), v71)),
                _mm_mul_ps(v71, *(__m128 *)_xmm))),
            v65),
          v69);
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(
                      (float)(COERCE_FLOAT(_mm_shuffle_ps(v72, v72, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v72, v72, 0)))
                    + COERCE_FLOAT(_mm_shuffle_ps(v72, v72, 170))) ^ _xmm[0]) < *(float *)&v17[20] )
    return 1i64;
  v52 = checkProjections(
          &segPair,
          (hkaiNavMeshEdgeMatchingParameters *)v17,
          v20,
          &dirA,
          &dirB,
          (hkSimdFloat32 *)&furthestPointOut,
          (hkSimdFloat32 *)&SA,
          (hkSimdFloat32 *)&EA,
          (hkSimdFloat32 *)&SA.m_quad.m128_u16[4],
          (float *)&retaddr);
  if ( (_DWORD)v52 != -1 )
    return v52;
  v73 = furthestPointOut.m_quad;
  v74 = EA.m_quad;
  edgePair->m_edgeAIdx = v14;
  edgePair->m_edgeBIdx = v221;
  v75 = SA.m_quad;
  v76 = *(__m128 *)((char *)&SA + 8);
  LODWORD(edgePair->m_overlap) = (_DWORD)retaddr;
  LODWORD(edgePair->m_edgeAlignment) = (_DWORD)retaddr;
  edgePair->m_distanceSquared = -1.0;
  edgePair->m_isValid = 1;
  v77 = _mm_sub_ps(v73, v74);
  edgePair->m_faceAIdx = a5;
  edgePair->m_faceBIdx = (signed int)faceIdx;
  v78 = _mm_div_ps(query.m_quad, _mm_sub_ps(v75, v73));
  v79 = _mm_div_ps(query.m_quad, _mm_sub_ps(v76, v74));
  *(float *)&retaddr = FLOAT_0_001;
  LODWORD(v80) = (unsigned __int128)_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0);
  if ( COERCE_FLOAT((unsigned int)(2 * v77.m128_i32[0]) >> 1) >= v80 )
  {
    if ( v73.m128_f32[0] > v74.m128_f32[0] )
    {
      *(hkVector4f *)((char *)&SA + 8) = 0i64;
      v81 = _mm_mul_ps(v79, v77);
      goto LABEL_12;
    }
    *(hkVector4f *)((char *)&SA + 8) = (hkVector4f)_mm_mul_ps(_mm_sub_ps(v74, v73), v78);
  }
  else
  {
    *(hkVector4f *)((char *)&SA + 8) = 0i64;
  }
  v81 = 0i64;
LABEL_12:
  if ( COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT(v75.m128_f32[0] - v76.m128_f32[0])) >> 1) < v80 )
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
  SA.m_quad = _mm_sub_ps(query.m_quad, v81);
  `anonymous namespace::SegmentPair::updateT(
    &segPair,
    (hkSimdFloat32 *)&SA.m_quad.m128_u16[4],
    (hkSimdFloat32 *)&EA,
    (hkSimdFloat32 *)&furthestPointOut,
    (hkSimdFloat32 *)&SA);
  if ( `anonymous namespace::SegmentPair::areIntervalsDisjoint(&segPair) )
    return 5i64;
  `anonymous namespace::SegmentPair::clippedDistanceSquared(&segPair, (hkSimdFloat32 *)&furthestPointOut, &SA);
  v85 = _mm_mul_ps(SA.m_quad, v20->m_quad);
  if ( COERCE_FLOAT((unsigned int)(2
                                 * COERCE_SIGNED_INT(
                                     (float)(COERCE_FLOAT(_mm_shuffle_ps(v85, v85, 85))
                                           + COERCE_FLOAT(_mm_shuffle_ps(v85, v85, 0)))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v85, v85, 170)))) >> 1) > COERCE_FLOAT(
                                                                                             _mm_shuffle_ps(
                                                                                               (__m128)*(_DWORD *)v17,
                                                                                               (__m128)*(_DWORD *)v17,
                                                                                               0)) )
    return 6i64;
  if ( v216 || (v52 = clipToMaxDistance(&segPair, (hkaiNavMeshEdgeMatchingParameters *)v17, v20, 0), (_DWORD)v52 == -1) )
  {
    `anonymous namespace::SegmentPair::updateProjection(&segPair, v20, v83, v84);
    v86 = (__m128)COERCE_UNSIGNED_INT(*(float *)&v17[4] * *(float *)&v17[4]);
    `anonymous namespace::SegmentPair::projectedDistanceSquared(&segPair, (hkSimdFloat32 *)&SA);
    if ( SA.m_quad.m128_f32[0] > COERCE_FLOAT(_mm_shuffle_ps(v86, v86, 0)) )
      return 2i64;
    if ( v216
      || (v52 = clipToMaxDistance(&segPair, (hkaiNavMeshEdgeMatchingParameters *)v17, v20, CLIP_MAX_SEPARATION),
          (_DWORD)v52 == -1) )
    {
      v89 = segPair.m_tEndA.m_real.m128_f32[0];
      edgePair->m_tStartA = segPair.m_tStartA.m_real.m128_f32[0];
      edgePair->m_tEndA = v89;
      v90 = segPair.m_tEndB.m_real.m128_f32[0];
      edgePair->m_tStartB = segPair.m_tStartB.m_real.m128_f32[0];
      edgePair->m_tEndB = v90;
      `anonymous namespace::SegmentPair::updateProjection(&segPair, v20, v87, v88);
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
      v98 = _mm_cmpltps(v97, query.m_quad);
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
      v100.m128_i32[0] = (unsigned __int128)_mm_andnot_ps(
                                              _mm_cmpleps(v101, (__m128)0i64),
                                              _mm_mul_ps(
                                                _mm_mul_ps(
                                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v101, v102), v102)),
                                                  _mm_mul_ps(v102, *(__m128 *)_xmm)),
                                                v101));
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
      v110 = _mm_cmpltps(v109, query.m_quad);
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
               _mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), dirA.m_quad),
               _mm_mul_ps(_mm_shuffle_ps(dirA.m_quad, dirA.m_quad, 201), v19));
      v112.m128_i32[0] = (unsigned __int128)_mm_andnot_ps(
                                              _mm_cmpleps(v113, (__m128)0i64),
                                              _mm_mul_ps(
                                                _mm_mul_ps(
                                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v113, v114), v114)),
                                                  _mm_mul_ps(v114, *(__m128 *)_xmm)),
                                                v113));
      v116 = _mm_shuffle_ps(v115, v115, 201);
      v117 = _mm_sub_ps(
               _mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), dirB.m_quad),
               _mm_mul_ps(_mm_shuffle_ps(dirB.m_quad, dirB.m_quad, 201), v19));
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
                 _mm_cmpleps(v120, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v121, v120), v121)),
                   _mm_mul_ps(v121, *(__m128 *)_xmm))));
      v123 = _mm_mul_ps(v122, v210.m_real);
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
      *(hkVector4f *)((char *)&SA + 8) = (hkVector4f)v124;
      v126 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v125, v125, 85), _mm_shuffle_ps(v125, v125, 0)),
               _mm_shuffle_ps(v125, v125, 170));
      v127 = _mm_rsqrt_ps(v126);
      v128 = _mm_cmpleps(v126, (__m128)0i64);
      v129 = _mm_mul_ps(_mm_mul_ps(v127, v126), v127);
      v126.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(
                                              (__m128)*(unsigned int *)&v17[8],
                                              (__m128)*(unsigned int *)&v17[8],
                                              0);
      v130 = _mm_mul_ps(
               v119,
               _mm_andnot_ps(v128, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v129), _mm_mul_ps(v127, *(__m128 *)_xmm))));
      v131 = _mm_mul_ps(v130, result.m_real);
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
      if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v135, v135, 177)) + v135.m128_f32[0]) < (float)(0.0 - v126.m128_f32[0])
        || (float)(COERCE_FLOAT(_mm_shuffle_ps(v138, v138, 177)) + v138.m128_f32[0]) < v145
        || (float)(COERCE_FLOAT(_mm_shuffle_ps(v141, v141, 177)) + v141.m128_f32[0]) < v145
        || (float)(COERCE_FLOAT(_mm_shuffle_ps(v144, v144, 177)) + v144.m128_f32[0]) < v145 )
      {
        v52 = 7i64;
      }
      else
      {
        LODWORD(v146) = (unsigned __int128)_mm_shuffle_ps(
                                             (__m128)*(unsigned int *)&v17[12],
                                             (__m128)*(unsigned int *)&v17[12],
                                             0);
        findFurthestVertexOfFaceBehindLine_hkaiNavMesh_0_(&result, v13, (int)faceIdx, (hkVector4f *)((char *)&SA + 8));
        if ( result.m_real.m128_f32[0] < v146 )
          return 8i64;
        findFurthestVertexOfFaceBehindLine_hkaiNavMesh_0_(&result, v15, a5, &EA);
        if ( result.m_real.m128_f32[0] < v146 )
          return 8i64;
        if ( !vars0 && v146 <= 0.0 )
          return 0xFFFFFFFFi64;
        v147 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
        EA.m_quad = _mm_xor_ps(v147, v132);
        *(hkVector4f *)((char *)&SA + 8) = (hkVector4f)_mm_xor_ps(v147, v124);
        findFurthestVertexOfFaceBehindLine_hkaiNavMesh_1_(
          &result,
          v15,
          a5,
          (hkVector4f *)((char *)&SA + 8),
          &furthestPointOut);
        findFurthestVertexOfFaceBehindLine_hkaiNavMesh_1_(
          &v210,
          v13,
          (int)faceIdx,
          &EA,
          (hkVector4f *)((char *)&SA + 8));
        v149 = result.m_real;
        if ( result.m_real.m128_f32[0] > 0.0 )
        {
          v150 = v210.m_real;
          if ( v210.m_real.m128_f32[0] > 0.0 )
          {
            if ( v17[52] )
            {
              `anonymous namespace::SegmentPair::projectPoint(
                (SegmentPair *)&furthestPointOut,
                v20,
                &furthestPointOut,
                v148);
              `anonymous namespace::SegmentPair::projectPoint(
                (SegmentPair *)&SA.m_quad.m128_u16[4],
                v20,
                (hkVector4f *)((char *)&SA + 8),
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
              v167 = _mm_cmpleps(v165, (__m128)0i64);
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
                       _mm_andnot_ps(_mm_cmpleps(v169, (__m128)0i64), _mm_mul_ps(_mm_mul_ps(v172, v173), v169)),
                       _mm_andnot_ps(
                         _mm_cmpleps(v176, (__m128)0i64),
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
              v181 = _mm_sub_ps(segPair.m_pSBProjected.m_quad, *(__m128 *)((char *)&SA.m_quad + 8));
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
              v188 = _mm_add_ps(_mm_sub_ps(v181, v186), *(__m128 *)((char *)&SA.m_quad + 8));
              v189 = _mm_shuffle_ps(v188, _mm_unpackhi_ps(v188, v185), 196);
              v190 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v187, v187, 85), _mm_shuffle_ps(v187, v187, 0)),
                       _mm_shuffle_ps(v187, v187, 170));
              v191 = _mm_sub_ps(segPair.m_pSBProjected.m_quad, v189);
              v192 = _mm_rsqrt_ps(v190);
              v193 = _mm_mul_ps(v191, v191);
              v194 = _mm_andnot_ps(
                       _mm_cmpleps(v190, (__m128)0i64),
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
                       _mm_cmpleps(v195, (__m128)0i64),
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
                         _mm_cmpleps(v200, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v200, v201), v201)),
                             _mm_mul_ps(v201, *(__m128 *)_xmm)),
                           v200)));
              v203 = _mm_rcp_ps(v202);
              v150 = _mm_min_ps(
                       v150,
                       _mm_div_ps(
                         _mm_mul_ps(_mm_mul_ps(v194, (__m128)xmmword_141A711B0), v150),
                         _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v202, v203)), v203)));
            }
            else
            {
              EA.m_quad = result.m_real;
            }
            furthestPointOut.m_quad = v150;
            if ( vars0 )
            {
              hkaiNavMeshUtils::calcFaceNormal<hkaiNavMesh>(
                (hkaiNavMeshUtils *)&result,
                (hkSimdFloat32 *)v15,
                (hkaiNavMesh *)a5,
                (unsigned __int64)&faceIndex,
                EB);
              hkaiNavMeshUtils::calcFaceNormal<hkaiNavMesh>(
                (hkaiNavMeshUtils *)&result,
                (hkSimdFloat32 *)v13,
                (hkaiNavMesh *)(unsigned int)faceIdx,
                (unsigned __int64)&normalB,
                v204);
              furthestPointOut.m_quad.m128_u64[1] = (unsigned __int64)edgePair;
              return hkaiNavMeshGenerationUtils::checkEdgeRaycasts(
                       (hkaiNavMeshEdgeMatchingParameters *)v17,
                       v20,
                       characterHeighta,
                       vars0,
                       &segPair.m_pSA,
                       &segPair.m_pSB,
                       &segPair.m_pEA,
                       &segPair.m_pEB,
                       (hkVector4f *)&faceIndex,
                       &normalB,
                       (hkSimdFloat32 *)&EA,
                       (hkSimdFloat32 *)&furthestPointOut);
            }
            return 0xFFFFFFFFi64;
          }
        }
        v52 = 9i64;
      }
    }
  }
  return v52;
}

// File Line: 875
// RVA: 0xB8C270
__int64 __fastcall hkaiNavMeshGenerationUtils::checkEdgeRaycasts(hkaiNavMeshEdgeMatchingParameters *input, hkVector4f *up, hkSimdFloat32 *characterHeight, hkaiEdgeGeometryRaycaster *raycaster, hkVector4f *pSA, hkVector4f *pSB, hkVector4f *pEA, hkVector4f *pEB, hkVector4f *normalA, hkVector4f *normalB, hkSimdFloat32 *midpointClearanceA, hkSimdFloat32 *midpointClearanceB)
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
  __m128 v28; // xmm9
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
  signed __int64 v44; // rax
  __int64 v45; // rcx
  __m128 v46; // xmm5
  __m128 v47; // xmm6
  __m128 v48; // xmm7
  int v49; // eax
  unsigned int v50; // ecx
  hkVector4f extrusion; // [rsp+20h] [rbp-1B8h]
  hkVector4f ends; // [rsp+30h] [rbp-1A8h]
  __int128 v54; // [rsp+40h] [rbp-198h]
  __int128 v55[7]; // [rsp+50h] [rbp-188h]
  hkVector4f starts; // [rsp+C0h] [rbp-118h]
  __int128 v57; // [rsp+D0h] [rbp-108h]
  __int128 v58[15]; // [rsp+E0h] [rbp-F8h]

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
                _mm_cmpleps(v18, (__m128)0i64),
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
            _mm_cmpleps(v25, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v25), v26)),
              _mm_mul_ps(v26, *(__m128 *)_xmm))),
          v22);
  v28 = up->m_quad;
  v29 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(_mm_sub_ps(pEB->m_quad, pSB->m_quad), (__m128)xmmword_141A711B0), pSB->m_quad),
          _mm_mul_ps(
            _mm_sub_ps((__m128)0i64, _mm_min_ps(_mm_mul_ps(midpointClearanceB->m_real, (__m128)xmmword_141A711B0), v12)),
            v27));
  v30 = _mm_mul_ps(v20, up->m_quad);
  v31 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)), _mm_shuffle_ps(v30, v30, 170));
  v32 = _mm_mul_ps(v29, up->m_quad);
  v33 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)), _mm_shuffle_ps(v32, v32, 170));
  v34 = _mm_cmpltps(v33, v31);
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
    *(__int128 *)((char *)&v57 + v44 * 16) = (__int128)v46;
    *(__int128 *)((char *)&v54 + v44 * 16) = (__int128)v47;
    v58[v44] = (__int128)v47;
    v47 = _mm_add_ps(v47, v48);
    *(__m128 *)((char *)&ends + v45) = v46;
    v55[v44] = (__int128)v41;
    *(hkVector4f *)((char *)&starts + v45) = (hkVector4f)v42.m_quad;
    v44 += 3i64;
    v45 += 48i64;
    v46 = _mm_add_ps(v46, v48);
  }
  while ( v44 < 9 );
  extrusion.m_quad = _mm_mul_ps(_mm_sub_ps((__m128)0i64, characterHeight->m_real), v28);
  v49 = hkaiEdgeGeometryRaycaster::castSmallRayBundleExtruded(raycaster, &starts, &ends, &extrusion);
  v50 = -1;
  if ( v49 )
    v50 = 11;
  return v50;
}

// File Line: 1002
// RVA: 0xB8C5D0
signed __int64 __fastcall hkaiNavMeshGenerationUtils::checkEdgeRaycastsWallClimbing(hkaiNavMeshEdgeMatchingParameters *input, hkVector4f *up_unused, hkSimdFloat32 *characterHeight, hkaiEdgeGeometryRaycaster *raycaster, hkVector4f *pSA, hkVector4f *pSB, hkVector4f *pEA, hkVector4f *pEB, hkVector4f *_normalA, hkVector4f *_normalB, hkVector4f *dirA, hkVector4f *dirB)
{
  hkaiNavMeshEdgeMatchingParameters *v12; // rbx
  hkaiEdgeGeometryRaycaster *v13; // rdi
  hkSimdFloat32 *v14; // rsi
  __m128 v15; // xmm9
  __m128 v16; // xmm11
  __m128 v17; // xmm13
  __m128 v18; // xmm1
  hkVector4f *v19; // rax
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
  __m128 v59; // xmm6
  __m128 v60; // xmm2
  __m128 v61; // xmm5
  __m128 v62; // xmm4
  __m128 v63; // xmm3
  __m128 v64; // xmm2
  float v65; // xmm2_4
  __m128 v66; // xmm13
  __m128 v67; // xmm6
  __m128 v68; // xmm5
  __m128 v69; // xmm4
  __m128 v70; // xmm9
  __m128 v71; // xmm7
  __m128 v72; // xmm3
  __m128 v73; // xmm2
  __m128 v74; // xmm1
  float v75; // xmm8_4
  __m128 v76; // xmm1
  __m128 v77; // xmm3
  __m128 v78; // xmm2
  __m128 v79; // xmm4
  __m128 v80; // xmm1
  __m128 v81; // xmm3
  __m128 v82; // xmm2
  __m128 v83; // xmm4
  __m128 v84; // xmm4
  __m128 v85; // xmm5
  __m128 v86; // xmm1
  __m128 v87; // xmm6
  __m128 v88; // xmm2
  __m128 v89; // xmm1
  __m128 v90; // xmm11
  __m128 v91; // xmm0
  __m128 v92; // xmm1
  __m128 v93; // xmm5
  __m128 v94; // xmm6
  int v95; // ebx
  __m128 v96; // xmm3
  hkQuaternionf quat; // [rsp+20h] [rbp-E0h]
  hkVector4f end; // [rsp+30h] [rbp-D0h]
  hkVector4f direction; // [rsp+40h] [rbp-C0h]
  hkVector4f v101; // [rsp+50h] [rbp-B0h]
  hkQuaternionf v102; // [rsp+60h] [rbp-A0h]
  hkVector4f v103; // [rsp+70h] [rbp-90h]
  hkVector4f start; // [rsp+80h] [rbp-80h]
  hkVector4f v105; // [rsp+90h] [rbp-70h]
  hkVector4f v106; // [rsp+A0h] [rbp-60h]
  hkVector4f v107; // [rsp+B0h] [rbp-50h]
  hkVector4f v108; // [rsp+C0h] [rbp-40h]
  hkVector4f v109; // [rsp+D0h] [rbp-30h]
  unsigned int _normalAa; // [rsp+1D0h] [rbp+D0h]

  v12 = input;
  v13 = raycaster;
  v14 = characterHeight;
  v15 = (__m128)_xmm;
  v16 = *(__m128 *)_xmm;
  v17 = _normalB->m_quad;
  v18 = pEA->m_quad;
  v19 = _normalA;
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
  v107.m_quad = v17;
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
                _mm_cmpleps(v29, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v30, v29), v30)),
                  _mm_mul_ps(*(__m128 *)_xmm, v30))),
              v27),
            v31),
          v24);
  v33 = quat.m_vec.m_quad;
  v34 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v17), _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v23));
  v35 = _mm_shuffle_ps(v34, v34, 201);
  v36 = _mm_mul_ps(v35, v35);
  v37 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)), _mm_shuffle_ps(v36, v36, 170));
  v38 = _mm_rsqrt_ps(v37);
  quat.m_vec.m_quad = _mm_shuffle_ps(
                        (__m128)LODWORD(v12->m_minAngleBetweenFaces),
                        (__m128)LODWORD(v12->m_minAngleBetweenFaces),
                        0);
  v39 = _mm_add_ps(
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_andnot_ps(
                _mm_cmpleps(v37, (__m128)0i64),
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
              _mm_cmpleps(v43, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v44, v43), v44)),
                _mm_mul_ps(*(__m128 *)_xmm, v44))));
    v46 = _mm_mul_ps(v41, v41);
    v47 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v46, v46, 85), _mm_shuffle_ps(v46, v46, 0)),
            _mm_shuffle_ps(v46, v46, 170));
    v48 = _mm_rsqrt_ps(v47);
    v49 = _mm_add_ps(v17, v20);
    v50 = _mm_mul_ps(
            v41,
            _mm_andnot_ps(
              _mm_cmpleps(v47, (__m128)0i64),
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
                        (float)(COERCE_FLOAT(_mm_shuffle_ps(v54, v54, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v54, v54, 0)))
                      + COERCE_FLOAT(_mm_shuffle_ps(v54, v54, 170))),
              *(__m128 *)_xmm_bf800000bf800000bf800000bf800000),
            *(__m128 *)_xmm);
    v57 = _mm_mul_ps(
            _mm_mul_ps(
              _mm_andnot_ps(
                _mm_cmpleps(v52, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v55, v52), v55)),
                  _mm_mul_ps(v55, *(__m128 *)_xmm))),
              v49),
            _mm_add_ps(v53, v45));
    v58 = _mm_andnot_ps(*(__m128 *)_xmm, v56);
    v59 = _mm_cmpltps(v58, *(__m128 *)_xmm);
    v60 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v58), *(__m128 *)_xmm);
    v61 = _mm_cmpltps(*(__m128 *)_xmm, v58);
    v62 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v60), v61), _mm_andnot_ps(v61, v58));
    v63 = _mm_or_ps(_mm_andnot_ps(v61, _mm_mul_ps(v58, v58)), _mm_and_ps(v61, v60));
    v64 = _mm_add_ps(
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v63, *(__m128 *)coeff4), *(__m128 *)coeff3), v63),
                          *(__m128 *)coeff2),
                        v63),
                      *(__m128 *)coeff1),
                    v63),
                  *(__m128 *)coeff0),
                v63),
              v62),
            v62);
    *(float *)&_normalAa = 1.5707964
                         - COERCE_FLOAT((*(unsigned __int128 *)&_mm_andnot_ps(
                                                                  v59,
                                                                  _mm_or_ps(
                                                                    _mm_and_ps(
                                                                      _mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v64, v64)),
                                                                      v61),
                                                                    _mm_andnot_ps(v61, v64))) | v59.m128_i32[0] & v58.m128_i32[0]) ^ v56.m128_i32[0] & _xmm[0]);
    LODWORD(v65) = (unsigned __int128)_mm_shuffle_ps((__m128)_normalAa, (__m128)_normalAa, 0);
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v57, v57, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v57, v57, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v57, v57, 170))) < 0.0 )
      v65 = 6.2831855 - v65;
    if ( v65 >= 1.5707964 || v65 <= quat.m_vec.m_quad.m128_f32[0] )
    {
      v16 = *(__m128 *)_xmm;
      v20 = end.m_quad;
      v15 = (__m128)_xmm;
    }
    else
    {
      v66 = _mm_mul_ps(v17, v19->m_quad);
      v67 = _mm_min_ps(
              _mm_max_ps(
                (__m128)COERCE_UNSIGNED_INT(
                          (float)(COERCE_FLOAT(_mm_shuffle_ps(v66, v66, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v66, v66, 0)))
                        + COERCE_FLOAT(_mm_shuffle_ps(v66, v66, 170))),
                *(__m128 *)_xmm_bf800000bf800000bf800000bf800000),
              *(__m128 *)_xmm);
      v68 = _mm_andnot_ps(*(__m128 *)_xmm, v67);
      v69 = _mm_cmpltps(v68, *(__m128 *)_xmm);
      v70 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v68), *(__m128 *)_xmm);
      v71 = _mm_cmpltps(*(__m128 *)_xmm, v68);
      v72 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v70), v71), _mm_andnot_ps(v71, v68));
      v73 = _mm_or_ps(_mm_andnot_ps(v71, _mm_mul_ps(v68, v68)), _mm_and_ps(v71, v70));
      v74 = _mm_add_ps(
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v73, *(__m128 *)coeff4), *(__m128 *)coeff3), v73),
                            *(__m128 *)coeff2),
                          v73),
                        *(__m128 *)coeff1),
                      v73),
                    *(__m128 *)coeff0),
                  v73),
                v72),
              v72);
      LODWORD(v75) = COERCE_UNSIGNED_INT(
                       (float)(1.5707964
                             - COERCE_FLOAT((*(unsigned __int128 *)&_mm_andnot_ps(
                                                                      v69,
                                                                      _mm_or_ps(
                                                                        _mm_and_ps(
                                                                          _mm_sub_ps(
                                                                            *(__m128 *)_xmm,
                                                                            _mm_add_ps(v74, v74)),
                                                                          v71),
                                                                        _mm_andnot_ps(v71, v74))) | v69.m128_i32[0] & v68.m128_i32[0]) ^ v67.m128_i32[0] & _xmm[0]))
                     - 1.5533431) ^ _xmm[0];
      hkQuaternionf::setAxisAngle(&quat, dirA, v75);
      hkQuaternionf::setAxisAngle(&v102, dirB, v75);
      hkVector4f::setRotatedDir(&v109, &quat, &direction);
      v76 = _mm_mul_ps(v109.m_quad, v109.m_quad);
      v15 = (__m128)_xmm;
      v16 = *(__m128 *)_xmm;
      v77 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v76, v76, 85), _mm_shuffle_ps(v76, v76, 0)),
              _mm_shuffle_ps(v76, v76, 170));
      v78 = _mm_rsqrt_ps(v77);
      v79 = _mm_cmpltps(v77, (__m128)xmmword_141A712D0);
      direction.m_quad = _mm_or_ps(
                           _mm_andnot_ps(
                             v79,
                             _mm_mul_ps(
                               _mm_mul_ps(
                                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v78, v77), v78)),
                                 _mm_mul_ps(v78, *(__m128 *)_xmm)),
                               v109.m_quad)),
                           _mm_and_ps(v79, transform.m_quad));
      hkVector4f::setRotatedDir(&v101, &v102, &v107);
      v20 = direction.m_quad;
      v80 = _mm_mul_ps(v101.m_quad, v101.m_quad);
      v81 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v80, v80, 85), _mm_shuffle_ps(v80, v80, 0)),
              _mm_shuffle_ps(v80, v80, 170));
      v82 = _mm_rsqrt_ps(v81);
      v83 = _mm_cmpltps(v81, (__m128)xmmword_141A712D0);
      v17 = _mm_or_ps(
              _mm_andnot_ps(
                v83,
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v82, v81), v82)),
                    _mm_mul_ps(v82, *(__m128 *)_xmm)),
                  v101.m_quad)),
              _mm_and_ps(v83, transform.m_quad));
      v107.m_quad = v17;
    }
  }
  v84 = v14->m_real;
  v85 = _mm_add_ps(v17, v20);
  v86 = _mm_mul_ps(v85, v85);
  v87 = _mm_add_ps(
          _mm_mul_ps(
            _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_44999999), (__m128)LODWORD(FLOAT_0_44999999), 0),
            _mm_sub_ps(v39, v32)),
          v32);
  end.m_quad = _mm_add_ps(_mm_mul_ps(v14->m_real, v20), v32);
  v88 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v86, v86, 85), _mm_shuffle_ps(v86, v86, 0)), _mm_shuffle_ps(v86, v86, 170));
  v89 = _mm_rsqrt_ps(v88);
  v90 = _mm_mul_ps(v16, v89);
  v91 = _mm_mul_ps(_mm_mul_ps(v89, v88), v89);
  v92 = _mm_shuffle_ps((__m128)LODWORD(v12->m_maxStepHeight), (__m128)LODWORD(v12->m_maxStepHeight), 0);
  v93 = _mm_mul_ps(v85, _mm_andnot_ps(_mm_cmpleps(v88, (__m128)0i64), _mm_mul_ps(_mm_sub_ps(v15, v91), v90)));
  v105.m_quad = _mm_add_ps(_mm_mul_ps(v84, v17), v39);
  v108.m_quad = _mm_add_ps(_mm_mul_ps(v84, v93), v87);
  start.m_quad = _mm_add_ps(_mm_mul_ps(v92, v20), v32);
  v106.m_quad = _mm_add_ps(_mm_mul_ps(v92, v17), v39);
  v103.m_quad = _mm_add_ps(v87, _mm_mul_ps(v92, v93));
  if ( !(unsigned int)hkaiEdgeGeometryRaycaster::castRay(v13, &start, &end)
    && !(unsigned int)hkaiEdgeGeometryRaycaster::castRay(v13, &v103, &v108)
    && !(unsigned int)hkaiEdgeGeometryRaycaster::castRay(v13, &v106, &v105) )
  {
    v94 = (__m128)xmmword_141A711B0;
    v95 = 0;
    while ( 1 )
    {
      v96 = _mm_mul_ps(v94, (__m128)xmmword_141A711C0);
      v101.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(end.m_quad, start.m_quad), v96), start.m_quad);
      quat.m_vec.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v108.m_quad, v103.m_quad), v96), v103.m_quad);
      v102.m_vec.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v105.m_quad, v106.m_quad), v96), v106.m_quad);
      if ( (unsigned int)hkaiEdgeGeometryRaycaster::castRay(v13, &v101, &quat.m_vec)
        || (unsigned int)hkaiEdgeGeometryRaycaster::castRay(v13, &quat.m_vec, &v102.m_vec) )
      {
        break;
      }
      v94 = _mm_add_ps(v94, query.m_quad);
      if ( ++v95 >= 3 )
        return 0xFFFFFFFFi64;
    }
  }
  return 11i64;
}   if ( ++v95 >= 3 )
        return 0xFFFFFFFFi64;
    }
  }
  return 11i64;
}

// File Line: 1227
// RVA: 0xB8F920
__int64 __fastcall getNumBoundaryEdges(hkaiNavMesh *mesh)
{
  __int64 v1; // r11
  unsigned int v2; // er8
  hkaiNavMesh *v3; // rbx
  hkaiNavMesh::Face *v4; // r9
  __int64 v5; // rcx
  int v6; // ST04_4
  int v7; // ST0C_4
  __int64 v8; // rdx
  __int64 v9; // rdx
  int *v10; // rcx

  v1 = mesh->m_faces.m_size;
  v2 = 0;
  v3 = mesh;
  if ( v1 > 0 )
  {
    v4 = mesh->m_faces.m_data;
    do
    {
      v5 = v4->m_startEdgeIndex;
      v6 = v4->m_startUserEdgeIndex;
      v7 = *(_DWORD *)&v4->m_clusterIndex;
      v8 = (signed int)v5 + (signed __int16)*(_DWORD *)&v4->m_numEdges;
      if ( v5 < v8 )
      {
        v9 = v8 - v5;
        v10 = &v3->m_edges.m_data->m_a + v5 + 4 * (v5 + 1);
        do
        {
          if ( *(v10 - 2) == -1 || *(_BYTE *)v10 & 0x20 )
            ++v2;
          v10 += 5;
          --v9;
        }
        while ( v9 );
      }
      ++v4;
      --v1;
    }
    while ( v1 );
  }
  return v2;
}

// File Line: 1252
// RVA: 0xB8DCA0
hkResult *__fastcall hkaiNavMeshGenerationUtils::_findConnectableEdges(hkResult *result, hkaiNavMeshGenerationSettings *input, hkaiNavMesh *mesh, hkaiEdgeGeometryRaycaster *raycaster, hkArray<hkaiNavMeshGenerationUtils::EdgePair,hkContainerHeapAllocator> *edgePairs, int iterationNum, hkaiNavMeshGenerationProgressCallback *cb, hkaiNavMeshGenerationProgressCallbackContext *cbCtx)
{
  hkArray<hkaiNavMeshGenerationUtils::EdgePair,hkContainerHeapAllocator> *v8; // r14
  hkResult *v9; // rdi
  hkaiNavMesh *v10; // rsi
  int v11; // eax
  int v12; // ebx
  hk1AxisSweep::AabbInt *v13; // r15
  int v14; // er13
  int v15; // er9
  hkResultEnum v16; // er8
  __int64 v17; // r9
  hk1AxisSweep::AabbInt *v18; // rdx
  hkaiNavMesh::Face *v19; // rcx
  signed __int64 v20; // rdi
  int v21; // er13
  signed int v23; // er12
  hkResultEnum v24; // er14
  signed __int64 v25; // rbx
  hkaiNavMesh::Edge *v26; // rdx
  hkVector4f *v27; // rcx
  __m128 v28; // xmm3
  __m128 v29; // xmm2
  hkaiNavMeshEdgeMatchingParameters *v30; // rax
  __m128 v31; // xmm0
  int v32; // xmm1_4
  __m128 v33; // xmm3
  __m128 v34; // xmm3
  __m128 v35; // xmm3
  int v36; // er8
  hkVector4f v37; // xmm0
  hkVector4f v38; // xmm1
  int v39; // er8
  signed __int64 v40; // rax
  int v41; // er9
  int v42; // eax
  int v43; // ecx
  int v44; // er9
  hkaiNavMeshGenerationSettings *v45; // r10
  hk1AxisSweep::AabbInt *v46; // rdx
  int v47; // edi
  unsigned int v48; // edi
  int v49; // ebx
  signed __int64 v50; // rcx
  hkRadixSort::SortData32 *v51; // r13
  hkaiNavMeshGenerationProgressCallback *v52; // r12
  __int64 v53; // r15
  hkRadixSort::SortData32 *v54; // r8
  hk1AxisSweep::AabbInt *v55; // r9
  unsigned int v56; // eax
  __int64 v57; // r11
  __int64 faceBIdx; // rbx
  __int64 v59; // rdi
  hkVector4f *v60; // rdx
  hkaiNavMesh::Edge *v61; // r8
  __int128 v62; // xmm0
  __int64 v63; // rdx
  int v64; // er8
  int v65; // er9
  hkaiNavMeshEdgeMatchingParameters *v66; // rax
  hkaiNavMeshGenerationConnectivityResult::ConnectivityResultEnum v67; // eax
  int v68; // er9
  int v69; // eax
  int v70; // eax
  hkResult *v71; // rbx
  int v72; // er8
  int v73; // er8
  hkVector4f *v74; // rcx
  __int64 sizeElem; // [rsp+20h] [rbp-E0h]
  __int64 edgeBIdx; // [rsp+28h] [rbp-D8h]
  __int64 faceAIdx; // [rsp+30h] [rbp-D0h]
  bool v78; // [rsp+50h] [rbp-B0h]
  hkResult v79; // [rsp+54h] [rbp-ACh]
  hkArrayBase<hkRadixSort::SortData32> sortArray; // [rsp+58h] [rbp-A8h]
  hkResult resulta; // [rsp+68h] [rbp-98h]
  hk1AxisSweep::AabbInt *array; // [rsp+70h] [rbp-90h]
  int v83; // [rsp+78h] [rbp-88h]
  int v84; // [rsp+7Ch] [rbp-84h]
  hkArrayBase<hk1AxisSweep::AabbInt> sortedAabbs; // [rsp+80h] [rbp-80h]
  int v86; // [rsp+90h] [rbp-70h]
  int v87; // [rsp+94h] [rbp-6Ch]
  __int64 v88; // [rsp+98h] [rbp-68h]
  __int64 v89; // [rsp+A0h] [rbp-60h]
  hkAabb aabbIn; // [rsp+B0h] [rbp-50h]
  int v91; // [rsp+D0h] [rbp-30h]
  int v92; // [rsp+D4h] [rbp-2Ch]
  int v93; // [rsp+D8h] [rbp-28h]
  int v94; // [rsp+DCh] [rbp-24h]
  hkSimdFloat32 characterHeight; // [rsp+E0h] [rbp-20h]
  hkArrayBase<hkVector4f> points; // [rsp+F0h] [rbp-10h]
  __m128 v97; // [rsp+100h] [rbp+0h]
  __m128 v98; // [rsp+110h] [rbp+10h]
  hkVector4f v99; // [rsp+120h] [rbp+20h]
  __int128 v100; // [rsp+130h] [rbp+30h]
  hkResult *v101; // [rsp+180h] [rbp+80h]
  hkaiNavMeshGenerationSettings *v102; // [rsp+188h] [rbp+88h]
  hkaiEdgeGeometryRaycaster *raycastera; // [rsp+198h] [rbp+98h]

  raycastera = raycaster;
  v102 = input;
  v101 = result;
  v8 = edgePairs;
  v9 = result;
  v78 = input->m_wallClimbingSettings.m_enableWallClimbing.m_bool != 0;
  edgePairs->m_size = 0;
  v10 = mesh;
  v11 = getNumBoundaryEdges(mesh);
  v12 = v11 + 4;
  v13 = 0i64;
  array = 0i64;
  v14 = v11;
  v86 = v11;
  v83 = 0;
  v84 = 2147483648;
  v87 = v11 + 4;
  if ( v11 + 4 > 0 )
  {
    v15 = v11 + 4;
    if ( v12 < 0 )
      v15 = 0;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v15, 32);
    if ( resulta.m_enum )
    {
      v9->m_enum = 1;
LABEL_11:
      v83 = 0;
      if ( v84 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          array,
          32 * v84);
      return v9;
    }
    v13 = array;
  }
  v83 = v12;
  v16 = 0;
  v79.m_enum = 0;
  v17 = 0i64;
  v88 = 0i64;
  if ( v10->m_faces.m_size > 0 )
  {
    v18 = 0i64;
    sortedAabbs.m_data = 0i64;
    do
    {
      v19 = v10->m_faces.m_data;
      v20 = *(int *)((char *)&v19->m_startEdgeIndex + (_QWORD)v18);
      HIDWORD(sortArray.m_data) = *(int *)((char *)&v19->m_startUserEdgeIndex + (_QWORD)v18);
      sortArray.m_size = *(_DWORD *)((char *)&v19->m_numEdges + (_QWORD)v18);
      sortArray.m_capacityAndFlags = *(_DWORD *)((char *)&v19->m_clusterIndex + (_QWORD)v18);
      if ( v10->m_faceDataStriding )
        v21 = v10->m_faceData.m_data[v17 * v10->m_faceDataStriding];
      else
        v21 = 0;
      v23 = v20 + SLOWORD(sortArray.m_size);
      if ( (signed int)v20 < v23 )
      {
        v24 = v79.m_enum;
        v25 = v20;
        do
        {
          v26 = v10->m_edges.m_data;
          if ( v26[v25].m_oppositeEdge == -1 || v26[v25].m_flags.m_storage & 0x20 )
          {
            v27 = v10->m_vertices.m_data;
            v28 = v27[v26[v25].m_a].m_quad;
            v29 = v27[v26[v25].m_b].m_quad;
            points.m_size = 2;
            points.m_capacityAndFlags = -2147483646;
            v97 = v28;
            v98 = v29;
            points.m_data = (hkVector4f *)&v97;
            aabbIn.m_min.m_quad = _mm_min_ps(v28, v29);
            aabbIn.m_max.m_quad = _mm_max_ps(v28, v29);
            v30 = hkaiNavMeshGenerationSettings::getEdgeMatchingParameters(v102, &points, v21, v21);
            v31 = (__m128)LODWORD(v30->m_maxSeparation);
            if ( v78 )
            {
              v32 = LODWORD(v30->m_maxStepHeight);
              resulta.m_enum = LODWORD(v30->m_maxSeparation);
              LODWORD(v89) = v32;
              v28.m128_f32[0] = fmaxf(*(float *)&v32, v31.m128_f32[0]);
              v33 = _mm_shuffle_ps(v28, v28, 0);
            }
            else
            {
              characterHeight.m_real = _mm_shuffle_ps(v31, v31, 0);
              v34 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&v102->m_up), 1u), 1u);
              characterHeight.m_real.m128_i32[(unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(_mm_max_ps(_mm_shuffle_ps(v34, v34, 170), _mm_max_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0))), v34), (__m128)xmmword_141A4DA50))]] = LODWORD(v30->m_maxStepHeight);
              v33 = characterHeight.m_real;
            }
            v35 = _mm_mul_ps(v33, (__m128)xmmword_141A711B0);
            aabbIn.m_min.m_quad = _mm_sub_ps(aabbIn.m_min.m_quad, v35);
            aabbIn.m_max.m_quad = _mm_add_ps(aabbIn.m_max.m_quad, v35);
            hk1AxisSweep::AabbInt::set(v13, &aabbIn, v20);
            v36 = points.m_capacityAndFlags;
            *(_DWORD *)v13->m_expansionMax = v24;
            ++v13;
            points.m_size = 0;
            if ( v36 >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                points.m_data,
                16 * v36);
          }
          LODWORD(v20) = v20 + 1;
          ++v25;
        }
        while ( (signed int)v20 < v23 );
        v18 = sortedAabbs.m_data;
        v17 = v88;
        v16 = v24;
      }
      ++v16;
      ++v17;
      v18 = (hk1AxisSweep::AabbInt *)((char *)v18 + 16);
      v79.m_enum = v16;
      v88 = v17;
      sortedAabbs.m_data = v18;
    }
    while ( v16 < v10->m_faces.m_size );
    v13 = array;
    v8 = edgePairs;
    v12 = v87;
    v9 = v101;
    v14 = v86;
  }
  v37.m_quad = (__m128)aabbIn.m_max;
  aabbIn.m_min.m_quad.m128_i32[0] = -1;
  v38.m_quad = (__m128)aabbIn.m_min;
  v39 = 2147483648;
  v40 = (signed __int64)&v13[v14];
  sortedAabbs.m_data = 0i64;
  sortedAabbs.m_size = 0;
  sortedAabbs.m_capacityAndFlags = 2147483648;
  sortArray.m_data = 0i64;
  sortArray.m_size = 0;
  *(hkVector4f *)v40 = aabbIn.m_min;
  *(hkVector4f *)(v40 + 16) = (hkVector4f)v37.m_quad;
  *(hkVector4f *)(v40 + 32) = (hkVector4f)v38.m_quad;
  *(hkVector4f *)(v40 + 48) = (hkVector4f)v37.m_quad;
  *(hkVector4f *)(v40 + 64) = (hkVector4f)v38.m_quad;
  *(hkVector4f *)(v40 + 80) = (hkVector4f)v37.m_quad;
  sortArray.m_capacityAndFlags = 2147483648;
  *(hkVector4f *)(v40 + 96) = (hkVector4f)v38.m_quad;
  *(hkVector4f *)(v40 + 112) = (hkVector4f)v37.m_quad;
  if ( v12 <= 0 )
  {
    v42 = 0;
    LODWORD(edgePairs) = 0;
LABEL_34:
    sortedAabbs.m_size = v12;
    goto LABEL_35;
  }
  v41 = v12;
  if ( v12 < 0 )
    v41 = 0;
  hkArrayUtil::_reserve(
    (hkResult *)&edgePairs,
    (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
    &sortedAabbs,
    v41,
    32);
  v42 = (signed int)edgePairs;
  v39 = sortArray.m_capacityAndFlags;
  if ( !(_DWORD)edgePairs )
    goto LABEL_34;
LABEL_35:
  v43 = v39 & 0x3FFFFFFF;
  if ( (v39 & 0x3FFFFFFF) >= v12 )
  {
    v79.m_enum = 0;
  }
  else
  {
    v44 = v12;
    if ( v12 < 2 * v43 )
      v44 = 2 * v43;
    hkArrayUtil::_reserve(&v79, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &sortArray, v44, 8);
    v39 = sortArray.m_capacityAndFlags;
    if ( v79.m_enum )
      goto LABEL_40;
    v42 = (signed int)edgePairs;
  }
  sortArray.m_size = v12;
  if ( v42 )
  {
LABEL_40:
    sortArray.m_size = 0;
    v9->m_enum = 1;
    if ( v39 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        sortArray.m_data,
        8 * v39);
    sortArray.m_data = 0i64;
    sortArray.m_capacityAndFlags = 2147483648;
    sortedAabbs.m_size = 0;
    if ( sortedAabbs.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        sortedAabbs.m_data,
        32 * sortedAabbs.m_capacityAndFlags);
    sortedAabbs.m_data = 0i64;
    sortedAabbs.m_capacityAndFlags = 2147483648;
    goto LABEL_11;
  }
  hk1AxisSweep::sortAabbs(array, v14, &sortArray, &sortedAabbs);
  sortArray.m_size = 0;
  if ( sortArray.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      sortArray.m_data,
      8 * sortArray.m_capacityAndFlags);
  sortArray.m_data = 0i64;
  sortArray.m_capacityAndFlags = 2147483648;
  sortedAabbs.m_size = 0;
  if ( sortedAabbs.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      sortedAabbs.m_data,
      32 * sortedAabbs.m_capacityAndFlags);
  v45 = v102;
  v46 = array;
  v47 = v102->m_edgeConnectionIterations + 1;
  characterHeight.m_real = _mm_shuffle_ps(
                             (__m128)LODWORD(v102->m_characterHeight),
                             (__m128)LODWORD(v102->m_characterHeight),
                             0);
  v48 = v14 * v47;
  v87 = v48;
  if ( v14 )
  {
    v49 = 0;
    v50 = 1i64;
    v51 = 0i64;
    v52 = cb;
    resulta.m_enum = 0;
    v89 = 1i64;
    while ( 1 )
    {
      v53 = *(signed int *)&v46->m_expansionMax[(_QWORD)v51];
      v54 = v51 + 4;
      LODWORD(edgePairs) = *(_DWORD *)&v46->m_expansionMin[(_QWORD)v51];
      v55 = (hk1AxisSweep::AabbInt *)(signed int)edgePairs;
      sortedAabbs.m_data = (hk1AxisSweep::AabbInt *)(signed int)edgePairs;
      v56 = *(unsigned int *)((char *)v46->m_max + (_QWORD)v51);
      v88 = v50;
      sortArray.m_data = v51 + 4;
      v57 = v53;
      if ( *(unsigned int *)((char *)v46->m_min + (_QWORD)(v51 + 4)) <= v56 )
      {
        while ( 1 )
        {
          faceBIdx = *(signed int *)((char *)&v54[3].m_userData + (_QWORD)v46);
          v59 = *(signed int *)((char *)&v54[1].m_userData + (_QWORD)v46);
          if ( (_DWORD)v53 != (_DWORD)faceBIdx
            && (((*(unsigned int *)((char *)&v54[2].m_userData + (_QWORD)v46)
                - *(unsigned int *)((char *)&v46->m_min[1] + (_QWORD)v51)) | (*(unsigned int *)((char *)&v54[3].m_key
                                                                                              + (_QWORD)v46)
                                                                            - *(unsigned int *)((char *)&v46->m_min[2]
                                                                                              + (_QWORD)v51)) | (*(unsigned int *)((char *)&v46->m_max[1] + (_QWORD)v51) - *(unsigned int *)((char *)&v54->m_userData + (_QWORD)v46)) | (*(unsigned int *)((char *)&v46->m_max[2] + (_QWORD)v51) - *(unsigned int *)((char *)&v54[1].m_key + (_QWORD)v46))) & 0x80000000) == 0 )
          {
            v60 = v10->m_vertices.m_data;
            v61 = v10->m_edges.m_data;
            points.m_size = 4;
            points.m_capacityAndFlags = -2147483644;
            points.m_data = (hkVector4f *)&v97;
            v97 = v60[v61[(_QWORD)v55].m_a].m_quad;
            v98 = v60[v61[(_QWORD)v55].m_b].m_quad;
            v99.m_quad = (__m128)v60[v61[v59].m_a];
            v62 = (__int128)v60[v61[v59].m_b];
            v63 = v10->m_faceDataStriding;
            v100 = v62;
            if ( (_DWORD)v63 )
              v64 = v10->m_faceData.m_data[v57 * v63];
            else
              v64 = 0;
            if ( (_DWORD)v63 )
              v65 = v10->m_faceData.m_data[v63 * faceBIdx];
            else
              v65 = 0;
            v66 = hkaiNavMeshGenerationSettings::getEdgeMatchingParameters(v45, &points, v64, v65);
            if ( v78 )
              v67 = hkaiNavMeshGenerationUtils::calculateWallClimbingConnectivity(
                      v66,
                      &characterHeight,
                      v10,
                      raycastera,
                      (int)edgePairs,
                      v59,
                      v53,
                      faceBIdx,
                      (hkaiNavMeshGenerationUtils::EdgePair *)&aabbIn);
            else
              v67 = hkaiNavMeshGenerationUtils::calculateConnectivity(
                      v66,
                      &v102->m_up,
                      &characterHeight,
                      v10,
                      raycastera,
                      (int)edgePairs,
                      v59,
                      v53,
                      faceBIdx,
                      (hkaiNavMeshGenerationUtils::EdgePair *)&aabbIn);
            if ( v67 == -1 )
            {
              v68 = v8->m_size + 1;
              v69 = v8->m_capacityAndFlags & 0x3FFFFFFF;
              if ( v69 >= v68 )
              {
                v79.m_enum = 0;
              }
              else
              {
                v70 = 2 * v69;
                if ( v68 < v70 )
                  v68 = v70;
                hkArrayUtil::_reserve(&v79, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v8, v68, 48);
                if ( v79.m_enum )
                {
                  v71 = v101;
                  v72 = points.m_capacityAndFlags;
                  v101->m_enum = 1;
                  points.m_size = 0;
                  if ( v72 >= 0 )
                    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                      points.m_data,
                      16 * v72);
                  v73 = v84;
                  points.m_data = 0i64;
                  points.m_capacityAndFlags = 2147483648;
                  v83 = 0;
                  if ( v84 >= 0 )
                  {
                    v46 = array;
                    goto LABEL_91;
                  }
                  return v71;
                }
              }
              if ( v8->m_size == (v8->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v8, 48);
              v74 = (hkVector4f *)&v8->m_data[v8->m_size];
              *v74 = aabbIn.m_min;
              v74[1] = aabbIn.m_max;
              v74[2].m_quad.m128_i32[0] = v91;
              v74[2].m_quad.m128_i32[1] = v92;
              v74[2].m_quad.m128_i32[2] = v93;
              v74[2].m_quad.m128_i32[3] = v94;
              ++v8->m_size;
            }
            else if ( v52 )
            {
              LODWORD(faceAIdx) = v67;
              LODWORD(edgeBIdx) = v59;
              LODWORD(sizeElem) = faceBIdx;
              v52->vfptr->edgeRejectedCallback(
                v52,
                v10,
                v53,
                (int)edgePairs,
                sizeElem,
                edgeBIdx,
                (hkaiNavMeshGenerationConnectivityResult::ConnectivityResultEnum)faceAIdx);
            }
            points.m_size = 0;
            if ( points.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                points.m_data,
                16 * points.m_capacityAndFlags);
            v55 = sortedAabbs.m_data;
            v45 = v102;
            v46 = array;
            v57 = v53;
          }
          v54 = (hkRadixSort::SortData32 *)(32 * ++v88);
          if ( v46[v88].m_min[0] > *(unsigned int *)((char *)&sortArray.m_data[-2].m_key + (unsigned __int64)v46) )
          {
            v54 = sortArray.m_data;
            v49 = resulta.m_enum;
            v50 = v89;
            v48 = v87;
            break;
          }
        }
      }
      ++v49;
      ++v50;
      v51 = v54;
      resulta.m_enum = v49;
      v89 = v50;
      if ( v52 && cbCtx )
      {
        v52->vfptr->stepMiddleCallback(v52, END|BEGIN|0x4, v49 + iterationNum * v86, v48, cbCtx);
        v46 = array;
        v50 = v89;
      }
      if ( v49 >= v86 - 1 )
        break;
      v45 = v102;
    }
  }
  v71 = v101;
  v73 = v84;
  v83 = 0;
  v101->m_enum = 0;
  if ( v73 >= 0 )
LABEL_91:
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v46,
      32 * v73);
  return v71;
}

// File Line: 1506
// RVA: 0xB8D660
hkResult *__fastcall hkaiNavMeshGenerationUtils::_findExactEdges(hkResult *result, hkaiNavMeshGenerationSettings *input, hkaiNavMesh *mesh, hkaiEdgeGeometryRaycaster *raycaster, hkArray<hkaiNavMeshGenerationUtils::EdgePair,hkContainerHeapAllocator> *edgePairs, hkaiNavMeshGenerationProgressCallback *cb, hkaiNavMeshGenerationProgressCallbackContext *cbCtx)
{
  hkaiNavMesh *v7; // r15
  hkaiNavMeshGenerationSettings *v8; // rdi
  int v9; // er9
  signed int v10; // er8
  hkResult *v11; // rbx
  int v12; // er10
  int v13; // er12
  __int64 v14; // r13
  hkaiNavMesh::Face *v15; // r14
  signed __int64 v16; // rbx
  signed __int64 v17; // rdi
  hkaiNavMesh::Edge *v18; // rsi
  __int64 v19; // r9
  int v20; // er8
  int v21; // edx
  int v22; // eax
  __m128 v23; // xmm0
  int v24; // er11
  int v25; // edi
  signed __int64 v26; // rsi
  int v27; // er11
  int v28; // ebx
  signed __int64 v29; // r9
  signed __int64 v30; // rdx
  unsigned __int64 *v31; // rcx
  signed __int64 v32; // rdx
  signed __int64 v33; // rax
  int v34; // ebx
  hkaiNavMesh::Edge *v35; // rdx
  hkVector4f *v36; // r8
  signed __int64 v37; // r9
  __int64 v38; // r10
  __int64 faceBIdx; // r12
  __int64 v40; // r13
  __int64 v41; // r14
  __int64 v42; // rax
  __int64 v43; // rdx
  int v44; // er8
  int v45; // er9
  hkaiNavMeshEdgeMatchingParameters *v46; // rax
  hkaiNavMeshGenerationConnectivityResult::ConnectivityResultEnum v47; // eax
  int v48; // er9
  int v49; // eax
  int v50; // eax
  int v51; // er8
  hkaiNavMeshGenerationUtils::EdgePair *v52; // rcx
  int v53; // edi
  signed __int64 v54; // rsi
  __int64 sizeElem; // [rsp+20h] [rbp-E0h]
  __int64 edgeBIdx; // [rsp+28h] [rbp-D8h]
  __int64 faceAIdx; // [rsp+30h] [rbp-D0h]
  EdgeKey *array; // [rsp+50h] [rbp-B0h]
  int v60; // [rsp+58h] [rbp-A8h]
  int v61; // [rsp+5Ch] [rbp-A4h]
  hkResult resulta; // [rsp+60h] [rbp-A0h]
  int v63; // [rsp+64h] [rbp-9Ch]
  int v64; // [rsp+68h] [rbp-98h]
  __int64 v65; // [rsp+70h] [rbp-90h]
  hkaiNavMeshGenerationUtils::EdgePair edgePair; // [rsp+78h] [rbp-88h]
  hkArrayBase<hkVector4f> points; // [rsp+B0h] [rbp-50h]
  hkVector4f v68; // [rsp+C0h] [rbp-40h]
  hkVector4f v69; // [rsp+D0h] [rbp-30h]
  hkVector4f v70; // [rsp+E0h] [rbp-20h]
  hkVector4f v71; // [rsp+F0h] [rbp-10h]
  hkSimdFloat32 characterHeight; // [rsp+100h] [rbp+0h]
  hkResult *v73; // [rsp+160h] [rbp+60h]
  hkaiNavMeshGenerationSettings *v74; // [rsp+168h] [rbp+68h]
  bool v75; // [rsp+170h] [rbp+70h]
  hkaiEdgeGeometryRaycaster *raycastera; // [rsp+178h] [rbp+78h]

  raycastera = raycaster;
  v74 = input;
  v73 = result;
  v7 = mesh;
  v75 = input->m_wallClimbingSettings.m_enableWallClimbing.m_bool != 0;
  v8 = input;
  edgePairs->m_size = 0;
  v9 = mesh->m_edges.m_size;
  v10 = 2147483648;
  v11 = result;
  array = 0i64;
  v12 = 0;
  v60 = 0;
  v61 = 2147483648;
  if ( v9 > 0 )
  {
    if ( v9 < 0 )
      v9 = 0;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v9, 16);
    v10 = v61;
    if ( resulta.m_enum )
    {
      v11->m_enum = 1;
      v60 = 0;
      if ( v10 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          array,
          16 * v10);
      return v11;
    }
    v12 = v60;
  }
  v13 = 0;
  if ( v7->m_faces.m_size > 0 )
  {
    v14 = 0i64;
    do
    {
      v15 = &v7->m_faces.m_data[v14];
      v16 = v15->m_startEdgeIndex;
      if ( (signed int)v16 < (signed int)v16 + v15->m_numEdges )
      {
        v17 = v16;
        do
        {
          v18 = v7->m_edges.m_data;
          if ( v18[v17].m_oppositeEdge == -1 )
          {
            if ( v12 == (v10 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 16);
              v12 = v60;
            }
            v60 = v12 + 1;
            v19 = (__int64)&array[v12];
            *(_DWORD *)v19 = v16;
            *(_DWORD *)(v19 + 4) = v13;
            v20 = v18[v17].m_b;
            v21 = v18[v17].m_a;
            v22 = v20;
            if ( v21 < v20 )
              v22 = v18[v17].m_a;
            if ( v21 > v20 )
              v20 = v18[v17].m_a;
            *(_QWORD *)(v19 + 8) = v20 | (unsigned __int64)((signed __int64)v22 << 32);
            v10 = v61;
            v12 = v60;
          }
          LODWORD(v16) = v16 + 1;
          ++v17;
        }
        while ( (signed int)v16 < v15->m_startEdgeIndex + v15->m_numEdges );
      }
      ++v13;
      ++v14;
    }
    while ( v13 < v7->m_faces.m_size );
    v11 = v73;
    v8 = v74;
  }
  if ( !v12 )
  {
LABEL_65:
    v60 = 0;
    v11->m_enum = 0;
    goto LABEL_66;
  }
  if ( v12 > 1 )
  {
    hkAlgorithm::quickSortRecursive<EdgeKey,hkAlgorithm::less<EdgeKey>>(array, 0, v12 - 1, 0);
    v10 = v61;
    v12 = v60;
  }
  v23 = (__m128)LODWORD(v8->m_characterHeight);
  v24 = v8->m_edgeConnectionIterations + 1;
  v25 = 0;
  v26 = 0i64;
  characterHeight.m_real = _mm_shuffle_ps(v23, v23, 0);
  v27 = v12 * v24;
  v63 = v27;
  if ( v12 - 1 <= 0 )
  {
LABEL_64:
    v11 = v73;
    goto LABEL_65;
  }
  while ( 1 )
  {
    v28 = v25 + 1;
    v29 = v26 + 1;
    v30 = v26 + 1;
    if ( v25 + 1 < v12 )
    {
      v31 = &array[v29].m_key;
      do
      {
        if ( array[v26].m_key != *v31 )
          break;
        ++v28;
        ++v30;
        v31 += 2;
      }
      while ( v28 < v12 );
    }
    v32 = v30 - v26;
    v33 = v32 - 1;
    v34 = v28 - v25 - 1;
    v65 = v32 - 1;
    if ( v32 == 2 )
      break;
LABEL_58:
    v53 = v34 + v25;
    v54 = v33 + v26;
    if ( cb && cbCtx )
    {
      cb->vfptr->stepMiddleCallback(cb, END|BEGIN|0x4, v53, v27, cbCtx);
      v12 = v60;
    }
    v25 = v53 + 1;
    v26 = v54 + 1;
    if ( v25 >= v12 - 1 )
    {
      v10 = v61;
      goto LABEL_64;
    }
    v27 = v63;
  }
  v35 = v7->m_edges.m_data;
  v36 = v7->m_vertices.m_data;
  v37 = v29;
  v38 = array[v37].m_edgeId;
  faceBIdx = array[v37].m_faceId;
  v40 = array[v26].m_edgeId;
  v41 = array[v26].m_faceId;
  points.m_size = 4;
  points.m_capacityAndFlags = -2147483644;
  points.m_data = &v68;
  v64 = v38;
  v68.m_quad = (__m128)v36[v35[v40].m_a];
  v69.m_quad = (__m128)v36[v35[v40].m_b];
  v70.m_quad = (__m128)v36[v35[v38].m_a];
  v42 = v35[v38].m_b;
  v43 = v7->m_faceDataStriding;
  v71.m_quad = (__m128)v36[v42];
  if ( (_DWORD)v43 )
    v44 = v7->m_faceData.m_data[v41 * v43];
  else
    v44 = 0;
  if ( (_DWORD)v43 )
    v45 = v7->m_faceData.m_data[faceBIdx * v43];
  else
    v45 = 0;
  v46 = hkaiNavMeshGenerationSettings::getEdgeMatchingParameters(v74, &points, v44, v45);
  if ( v75 )
    v47 = hkaiNavMeshGenerationUtils::calculateWallClimbingConnectivity(
            v46,
            &characterHeight,
            v7,
            raycastera,
            v40,
            v64,
            v41,
            faceBIdx,
            &edgePair);
  else
    v47 = hkaiNavMeshGenerationUtils::calculateConnectivity(
            v46,
            &v74->m_up,
            &characterHeight,
            v7,
            raycastera,
            v40,
            v64,
            v41,
            faceBIdx,
            &edgePair);
  if ( v47 != -1 )
  {
    if ( cb )
    {
      LODWORD(faceAIdx) = v47;
      LODWORD(edgeBIdx) = v64;
      LODWORD(sizeElem) = faceBIdx;
      cb->vfptr->edgeRejectedCallback(
        cb,
        v7,
        v41,
        v40,
        sizeElem,
        edgeBIdx,
        (hkaiNavMeshGenerationConnectivityResult::ConnectivityResultEnum)faceAIdx);
    }
    goto LABEL_55;
  }
  v48 = edgePairs->m_size + 1;
  v49 = edgePairs->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v49 >= v48 )
  {
    resulta.m_enum = 0;
LABEL_50:
    if ( edgePairs->m_size == (edgePairs->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, edgePairs, 48);
    v52 = &edgePairs->m_data[edgePairs->m_size];
    v52->m_edgeAIdx = edgePair.m_edgeAIdx;
    v52->m_edgeBIdx = edgePair.m_edgeBIdx;
    v52->m_faceAIdx = edgePair.m_faceAIdx;
    v52->m_faceBIdx = edgePair.m_faceBIdx;
    v52->m_distanceSquared = edgePair.m_distanceSquared;
    v52->m_edgeAlignment = edgePair.m_edgeAlignment;
    v52->m_overlap = edgePair.m_overlap;
    *(_DWORD *)&v52->m_isValid = *(_DWORD *)&edgePair.m_isValid;
    v52->m_tStartA = edgePair.m_tStartA;
    v52->m_tEndA = edgePair.m_tEndA;
    v52->m_tStartB = edgePair.m_tStartB;
    v52->m_tEndB = edgePair.m_tEndB;
    ++edgePairs->m_size;
LABEL_55:
    points.m_size = 0;
    if ( points.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        points.m_data,
        16 * points.m_capacityAndFlags);
    v27 = v63;
    v33 = v65;
    v12 = v60;
    goto LABEL_58;
  }
  v50 = 2 * v49;
  if ( v48 < v50 )
    v48 = v50;
  hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, edgePairs, v48, 48);
  if ( resulta.m_enum == HK_SUCCESS )
    goto LABEL_50;
  v11 = v73;
  v51 = points.m_capacityAndFlags;
  v73->m_enum = 1;
  points.m_size = 0;
  if ( v51 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      points.m_data,
      16 * v51);
  v10 = v61;
  points.m_data = 0i64;
  points.m_capacityAndFlags = 2147483648;
  v60 = 0;
LABEL_66:
  if ( v10 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      16 * v10);
  return v11;
}

// File Line: 1658
// RVA: 0xB8BCF0
_BOOL8 __fastcall hkaiNavMeshGenerationUtils::EdgePair::operator<(hkaiNavMeshGenerationUtils::EdgePair *this, hkaiNavMeshGenerationUtils::EdgePair *other)
{
  float v2; // xmm2_4

  v2 = other->m_distanceSquared;
  if ( COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT(this->m_distanceSquared - v2)) >> 1) > 0.0000099999997 )
    return this->m_distanceSquared > v2;
  if ( COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT(this->m_edgeAlignment - other->m_edgeAlignment)) >> 1) > 0.0000099999997 )
    return other->m_edgeAlignment > this->m_edgeAlignment;
  return this->m_overlap < other->m_overlap;
}

// File Line: 1667
// RVA: 0xB95170
hkResult *__fastcall NavMeshFreeList::addFreeSpace(NavMeshFreeList *this, hkResult *result, int idx, __int64 num)
{
  __int64 v4; // r15
  int v5; // er12
  hkResult *v6; // rsi
  NavMeshFreeList *v7; // r14
  int v8; // ebp
  int v9; // eax
  int v10; // eax
  int v11; // er9
  int v12; // eax
  __int64 v13; // rdi
  int *v14; // rbx
  int v15; // er8
  signed __int64 v16; // rax
  int v17; // ecx
  signed __int64 v18; // rdx
  __int64 v19; // rax
  hkArray<int,hkContainerHeapAllocator> *v20; // rdx
  hkArray<int,hkContainerHeapAllocator> *v21; // r8
  int v22; // er9
  int v23; // eax
  int v24; // eax
  hkArray<int,hkContainerHeapAllocator> *v25; // rdx
  signed __int64 v26; // rdx
  hkResult resulta; // [rsp+78h] [rbp+20h]

  v4 = (signed int)num;
  v5 = idx;
  v6 = result;
  v7 = this;
  if ( this->m_freeSpace.m_size > (signed int)num )
    goto LABEL_17;
  v8 = num + 1;
  hkaiArrayUtil::reserveForNonPodType<hkArray<int,hkContainerHeapAllocator>,hkContainerHeapAllocator>(
    (hkaiArrayUtil *)&resulta,
    (hkResult *)this,
    (hkArray<hkArray<int,hkContainerHeapAllocator>,hkContainerHeapAllocator> *)(unsigned int)(num + 1),
    num);
  if ( resulta.m_enum == HK_SUCCESS )
  {
    v9 = v7->m_freeSpace.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v9 < v8 )
    {
      v10 = 2 * v9;
      v11 = v8;
      if ( v8 < v10 )
        v11 = v10;
      hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, v11, 16);
    }
    v12 = v7->m_freeSpace.m_size - v8 - 1;
    v13 = v12;
    if ( v12 >= 0 )
    {
      v14 = &v7->m_freeSpace.m_data[v8].m_capacityAndFlags + 4 * v12;
      do
      {
        v15 = *v14;
        *(v14 - 1) = 0;
        if ( v15 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            *(void **)(v14 - 3),
            4 * v15);
        *(_QWORD *)(v14 - 3) = 0i64;
        *v14 = 2147483648;
        v14 -= 4;
        --v13;
      }
      while ( v13 >= 0 );
    }
    v16 = v7->m_freeSpace.m_size;
    v17 = v8 - v16;
    v18 = v16;
    v19 = v8 - (signed int)v16;
    v20 = &v7->m_freeSpace.m_data[v18];
    if ( v17 > 0 )
    {
      do
      {
        if ( v20 )
        {
          v20->m_data = 0i64;
          v20->m_size = 0;
          v20->m_capacityAndFlags = 2147483648;
        }
        ++v20;
        --v19;
      }
      while ( v19 );
    }
    v7->m_freeSpace.m_size = v8;
LABEL_17:
    v21 = &v7->m_freeSpace.m_data[v4];
    v22 = v21->m_size + 1;
    v23 = v21->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v23 >= v22 )
    {
      resulta.m_enum = 0;
    }
    else
    {
      v24 = 2 * v23;
      if ( v22 < v24 )
        v22 = v24;
      hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v21, v22, 4);
      if ( resulta.m_enum )
        goto LABEL_21;
    }
    v25 = v7->m_freeSpace.m_data;
    v6->m_enum = 0;
    v26 = (signed __int64)&v25[v4];
    *(_DWORD *)(*(_QWORD *)v26 + 4i64 * (signed int)(*(_DWORD *)(v26 + 8))++) = v5;
    return v6;
  }
LABEL_21:
  v6->m_enum = 1;
  return v6;
}

// File Line: 1701
// RVA: 0xB8F9D0
hkResult *__fastcall _splitEdges(hkResult *result, hkaiNavMesh *mesh, int faceIdx, hkaiNavMeshGenerationUtils::EdgeSplit *splits, NavMeshFreeList *freeList, int *numSplitsOut)
{
  hkaiNavMesh::Face *v6; // rax
  hkResult *v7; // rsi
  __int32 v8; // er13
  hkaiNavMeshGenerationUtils::EdgeSplit *v9; // r14
  hkaiNavMesh *v10; // r15
  __m128i v11; // xmm8
  hkResultEnum v12; // eax
  __int16 v13; // di
  int v14; // ebx
  int v15; // er9
  int v16; // eax
  int v17; // eax
  int v18; // er9
  int v19; // er12
  hkaiNavMesh::Edge *v20; // rdx
  _DWORD *v21; // rcx
  int v22; // eax
  __int64 v23; // rdi
  int v24; // eax
  unsigned int v25; // eax
  int v26; // edx
  int v27; // er9
  int v28; // er8
  int v29; // eax
  int v30; // eax
  int v31; // er9
  char *v32; // rdi
  __int64 v33; // rcx
  hkaiNavMeshGenerationUtils::EdgeSplit *v34; // rdi
  int v35; // er14
  __int64 v36; // rdx
  float v37; // xmm0_4
  hkaiNavMesh::Edge *v38; // r9
  int v39; // eax
  signed __int64 v40; // r8
  float *v41; // rcx
  float v42; // xmm1_4
  hkVector4f *v43; // rcx
  int v44; // er12
  signed __int64 v45; // rax
  __m128 v46; // xmm1
  int v47; // er13
  int v48; // er9
  signed __int64 v49; // rbx
  _DWORD *v50; // rdx
  int v51; // eax
  signed __int64 v52; // rax
  hkVector4f *v53; // rdx
  __m128 v54; // xmm2
  int v55; // er12
  signed __int64 v56; // rcx
  signed __int64 v57; // rax
  int v58; // er13
  int v59; // er9
  signed __int64 v60; // rbx
  _DWORD *v61; // rdx
  int v62; // eax
  int v63; // er8
  __int64 v64; // r10
  unsigned __int64 v65; // rdx
  __int64 v66; // rdi
  unsigned int v67; // er8
  _DWORD **v68; // rdx
  int v69; // ecx
  _DWORD *v70; // rax
  __int64 v71; // rax
  NavMeshFreeList *v72; // r14
  hkArray<int,hkContainerHeapAllocator> *v73; // r8
  __int64 v74; // rbx
  hkaiNavMesh::Edge *v75; // r9
  int *v76; // rcx
  hkaiNavMesh::Edge *v77; // rdx
  __int64 v78; // r8
  int v79; // eax
  _DWORD **v80; // rcx
  _DWORD *v81; // rax
  hkResultEnum v82; // edi
  unsigned int *v83; // r8
  signed __int64 v84; // rax
  signed __int64 v85; // rdx
  hkaiNavMesh::Face *v86; // rdx
  __int64 v87; // rcx
  hkResultEnum v88; // eax
  int v89; // er9
  int v90; // er8
  int v91; // er8
  char *v93; // [rsp+30h] [rbp-98h]
  int v94; // [rsp+38h] [rbp-90h]
  int v95; // [rsp+3Ch] [rbp-8Ch]
  void *array; // [rsp+40h] [rbp-88h]
  hkResult v97[4]; // [rsp+48h] [rbp-80h]
  hkaiNavMesh::Edge t; // [rsp+58h] [rbp-70h]
  hkResult v99; // [rsp+70h] [rbp-58h]
  int num; // [rsp+74h] [rbp-54h]
  hkResult v101; // [rsp+78h] [rbp-50h]
  int v102; // [rsp+7Ch] [rbp-4Ch]
  int v103; // [rsp+80h] [rbp-48h]
  unsigned __int64 v104; // [rsp+88h] [rbp-40h]
  __int64 v105; // [rsp+90h] [rbp-38h]
  hkVector4f v; // [rsp+98h] [rbp-30h]
  hkVector4f v107; // [rsp+A8h] [rbp-20h]
  hkResult resulta; // [rsp+130h] [rbp+68h]
  hkResult v109; // [rsp+138h] [rbp+70h]
  __int64 v110; // [rsp+140h] [rbp+78h]
  NavMeshFreeList *v111; // [rsp+148h] [rbp+80h]
  _DWORD *vars0; // [rsp+150h] [rbp+88h]

  v6 = mesh->m_faces.m_data;
  v7 = result;
  v8 = faceIdx;
  v9 = splits;
  v10 = mesh;
  v104 = 16i64 * faceIdx;
  v11 = (__m128i)v6[v104 / 0x10];
  v12 = 2147483648;
  array = 0i64;
  v13 = _mm_extract_epi16(v11, 4);
  v97[0].m_enum = 0;
  v97[1].m_enum = 2147483648;
  v14 = v13;
  num = v13;
  v15 = 2 * v13;
  if ( 2 * v13 <= 0 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    if ( v15 < 0 )
      v15 = 0;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v15, 20);
    v12 = v97[1].m_enum;
    if ( resulta.m_enum )
    {
      v7->m_enum = 1;
      v97[0].m_enum = 0;
LABEL_6:
      if ( (signed int)v12 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          array,
          20 * (v12 & 0x3FFFFFFF));
      return v7;
    }
  }
  v16 = v12 & 0x3FFFFFFF;
  if ( v16 < v13 )
  {
    v17 = 2 * v16;
    v18 = v13;
    if ( v13 < v17 )
      v18 = v17;
    hkArrayUtil::_reserve(&v97[2], (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v18, 20);
  }
  v19 = _mm_cvtsi128_si32(v11);
  v97[0].m_enum = v13;
  t.m_oppositeEdge = v19;
  v20 = &v10->m_edges.m_data[v19];
  v21 = array;
  v22 = 5 * v13;
  if ( v22 > 0 )
  {
    v23 = (unsigned int)v22;
    do
    {
      v24 = v20->m_a;
      ++v21;
      v20 = (hkaiNavMesh::Edge *)((char *)v20 + 4);
      *(v21 - 1) = v24;
      --v23;
    }
    while ( v23 );
  }
  v25 = 2147483648;
  v26 = 0;
  v93 = 0i64;
  v95 = 2147483648;
  v94 = 0;
  if ( v14 <= 0 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    v27 = v14;
    if ( v14 < 0 )
      v27 = 0;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v93, v27, 4);
    if ( resulta.m_enum )
    {
      v28 = v95;
      v7->m_enum = 1;
      v94 = 0;
      if ( v28 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          v93,
          4 * v28);
      v12 = v97[1].m_enum;
      v93 = 0i64;
      v95 = 2147483648;
      v97[0].m_enum = 0;
      goto LABEL_6;
    }
    v25 = v95;
    v26 = v94;
  }
  v29 = v25 & 0x3FFFFFFF;
  if ( v29 < v14 )
  {
    v30 = 2 * v29;
    v31 = v14;
    if ( v14 < v30 )
      v31 = v30;
    hkArrayUtil::_reserve(&v97[2], (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v93, v31, 4);
    v26 = v94;
  }
  v32 = &v93[4 * v26];
  v33 = v14 - v26;
  if ( v14 - v26 > 0 )
  {
    while ( v33 )
    {
      *(_DWORD *)v32 = 0;
      v32 += 4;
      --v33;
    }
  }
  v34 = v9;
  v35 = 0;
  v94 = v14;
  while ( 1 )
  {
    v36 = v34->m_edgeIdx;
    v37 = v34->m_tS;
    v38 = v10->m_edges.m_data;
    v39 = v36 + v19;
    *(_QWORD *)&v97[0].m_enum = v10->m_edges.m_data;
    v40 = 5i64 * ((signed int)v36 + v19);
    v41 = (float *)v93;
    v105 = 5i64 * ((signed int)v36 + v19);
    v42 = *(float *)&v93[4 * v36];
    if ( (float)(v37 - v42) < 0.000001 )
      v34->m_tS = v42;
    if ( v41[v36] < v34->m_tS )
    {
      v43 = v10->m_vertices.m_data;
      v44 = v10->m_vertices.m_size;
      v45 = v38[v39].m_a;
      v46 = _mm_shuffle_ps((__m128)LODWORD(v34->m_tS), (__m128)LODWORD(v34->m_tS), 0);
      _mm_store_si128((__m128i *)&v, (__m128i)v43[*(&v38->m_a + v40)].m_quad);
      v.m_quad = _mm_add_ps(
                   _mm_mul_ps(_mm_sub_ps(v43[*(&v38->m_b + v40)].m_quad, v43[v45].m_quad), v46),
                   v43[v45].m_quad);
      hkaiNavMesh::appendVertices(v10, &v101, &v, 1);
      if ( v101.m_enum )
        goto LABEL_55;
      v47 = v35 + v34->m_edgeIdx;
      v48 = v97[0].m_enum + 1;
      v49 = 5i64 * v47;
      t.m_a = *((_DWORD *)array + 5 * v47);
      t.m_b = *((_DWORD *)array + 5 * v47 + 1);
      t.m_oppositeEdge = *((_DWORD *)array + 5 * v47 + 2);
      t.m_oppositeFace = *((_DWORD *)array + 5 * v47 + 3);
      *(_DWORD *)&t.m_flags.m_storage = *((_DWORD *)array + 5 * v47 + 4);
      if ( (v97[1].m_enum & 0x3FFFFFFF) >= v97[0].m_enum + 1 )
      {
        resulta.m_enum = 0;
      }
      else
      {
        if ( v48 < 2 * (v97[1].m_enum & 0x3FFFFFFF) )
          v48 = 2 * (v97[1].m_enum & 0x3FFFFFFF);
        hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v48, 20);
        if ( resulta.m_enum )
          goto LABEL_68;
      }
      hkArrayBase<hkaiNavMesh::Edge>::_insertAt(
        (hkArrayBase<hkaiNavMesh::Edge> *)&array,
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
        v47,
        &t);
      v50 = array;
      v40 = v105;
      v38 = *(hkaiNavMesh::Edge **)&v97[0].m_enum;
      v51 = v47 + 1;
      v8 = v109.m_enum;
      ++v35;
      v52 = 5i64 * v51;
      *((_DWORD *)array + v52) = v44;
      *(_QWORD *)&v50[v52 + 2] = -1i64;
      v50[v49 + 1] = v44;
    }
    *(float *)&v93[4 * v34->m_edgeIdx] = v34->m_tE;
    *v34->m_sharedPairEdgeIdx = v35 + v34->m_edgeIdx;
    if ( v34->m_tE < 1.0 )
    {
      v53 = v10->m_vertices.m_data;
      v54 = _mm_shuffle_ps((__m128)LODWORD(v34->m_tE), (__m128)LODWORD(v34->m_tE), 0);
      v55 = v10->m_vertices.m_size;
      v56 = *(&v38->m_b + v40);
      v57 = *(&v38->m_a + v40);
      _mm_store_si128((__m128i *)&v107, (__m128i)v53[*(&v38->m_b + v40)].m_quad);
      v107.m_quad = _mm_add_ps(_mm_mul_ps(v54, _mm_sub_ps(v53[v56].m_quad, v53[v57].m_quad)), v53[v57].m_quad);
      hkaiNavMesh::appendVertices(v10, &v97[2], &v107, 1);
      if ( v97[2].m_enum )
      {
LABEL_55:
        v63 = v95;
        v7->m_enum = 1;
        v94 = 0;
        if ( v63 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            v93,
            4 * v63);
        v93 = 0i64;
        v97[0].m_enum = 0;
        goto LABEL_89;
      }
      v58 = v35 + v34->m_edgeIdx;
      v59 = v97[0].m_enum + 1;
      v60 = 5i64 * v58;
      v99.m_enum = *((_DWORD *)array + 5 * v58);
      num = *((_DWORD *)array + 5 * v58 + 1);
      v101.m_enum = *((_DWORD *)array + 5 * v58 + 2);
      v102 = *((_DWORD *)array + 5 * v58 + 3);
      v103 = *((_DWORD *)array + 5 * v58 + 4);
      if ( (v97[1].m_enum & 0x3FFFFFFF) >= v97[0].m_enum + 1 )
      {
        v99.m_enum = 0;
      }
      else
      {
        if ( v59 < 2 * (v97[1].m_enum & 0x3FFFFFFF) )
          v59 = 2 * (v97[1].m_enum & 0x3FFFFFFF);
        hkArrayUtil::_reserve(&v99, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v59, 20);
        if ( v99.m_enum )
          goto LABEL_68;
      }
      hkArrayBase<hkaiNavMesh::Edge>::_insertAt(
        (hkArrayBase<hkaiNavMesh::Edge> *)&array,
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
        v58,
        (hkaiNavMesh::Edge *)&v99);
      v61 = array;
      v62 = v58 + 1;
      v8 = v109.m_enum;
      *((_DWORD *)array + v60 + 1) = v55;
      *(_QWORD *)&v61[v60 + 2] = -1i64;
      ++v35;
      v61[5 * v62] = v55;
    }
    ++v34;
    if ( v34->m_faceIdx != v8 )
      break;
    v19 = t.m_oppositeEdge;
  }
  v64 = v110;
  v65 = ((unsigned __int64)((unsigned __int128)(((signed __int64)v34 - v110) * (signed __int128)3074457345618258603i64) >> 64) >> 63)
      + ((signed __int64)((unsigned __int128)(((signed __int64)v34 - v110) * (signed __int128)3074457345618258603i64) >> 64) >> 2);
  *vars0 = v65;
  v66 = (signed int)v65;
  if ( !v35 )
  {
    if ( (signed int)v65 > 0 )
    {
      v67 = t.m_oppositeEdge;
      v68 = (_DWORD **)(v64 + 8);
      do
      {
        v69 = *((_DWORD *)v68 - 1);
        v70 = *v68;
        v68 += 3;
        *v70 = v67 + v69;
        --v66;
      }
      while ( v66 );
    }
    v7->m_enum = 0;
    goto LABEL_69;
  }
  v71 = SLOWORD(v97[0].m_enum);
  v72 = v111;
  _mm_store_si128((__m128i *)v97, v11);
  LOWORD(v97[2].m_enum) = v71;
  if ( v72->m_freeSpace.m_size > (signed int)v71
    && (v73 = v72->m_freeSpace.m_data, v72->m_freeSpace.m_data[v71].m_size)
    && (v74 = v73[v71].m_data[v73[v71].m_size - 1], --v73[v71].m_size, (_DWORD)v74 != -1) )
  {
    v75 = &v10->m_edges.m_data[v74];
  }
  else
  {
    LODWORD(v74) = v10->m_edges.m_size;
    v75 = hkaiNavMesh::expandEdgesBy(v10, v97[0].m_enum, -1);
    if ( !v75 )
    {
LABEL_68:
      v7->m_enum = 1;
LABEL_69:
      v94 = 0;
      if ( v95 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          v93,
          4 * v95);
      v93 = 0i64;
      v97[0].m_enum = 0;
      goto LABEL_89;
    }
    v64 = v110;
  }
  v76 = (int *)array;
  v77 = v75;
  v78 = (unsigned int)(5 * v97[0].m_enum);
  if ( (signed int)v78 > 0 )
  {
    do
    {
      v79 = *v76;
      v77 = (hkaiNavMesh::Edge *)((char *)v77 + 4);
      ++v76;
      *(_DWORD *)&v77[-1].m_flags.m_storage = v79;
      --v78;
    }
    while ( v78 );
  }
  if ( v66 > 0 )
  {
    v80 = (_DWORD **)(v64 + 8);
    do
    {
      v81 = *v80;
      v80 += 3;
      *v81 += v74;
      --v66;
    }
    while ( v66 );
  }
  v82 = 0;
  if ( v97[0].m_enum > 0 )
  {
    v83 = &v75->m_oppositeEdge;
    do
    {
      v84 = (signed int)*v83;
      if ( (_DWORD)v84 != -1 )
      {
        v85 = v84;
        v10->m_edges.m_data[v85].m_oppositeEdge = v82 + v74;
        v10->m_edges.m_data[v85].m_oppositeFace = v8;
      }
      ++v82;
      v83 += 5;
    }
    while ( v82 < v97[0].m_enum );
  }
  v86 = v10->m_faces.m_data;
  v87 = v104;
  v88 = v97[1].m_enum;
  v89 = num;
  v90 = t.m_oppositeEdge;
  v86[v104 / 0x10].m_startEdgeIndex = v74;
  *(int *)((char *)&v86->m_startUserEdgeIndex + v87) = v88;
  *(hkResult *)((char *)&v86->m_numEdges + v87) = v97[2];
  *(hkResult *)((char *)&v86->m_clusterIndex + v87) = v97[3];
  NavMeshFreeList::addFreeSpace(v72, &v109, v90, v89);
  v91 = v95;
  v94 = 0;
  if ( v109.m_enum )
    v7->m_enum = 1;
  else
    v7->m_enum = 0;
  if ( v91 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v93,
      4 * v91);
  v97[0].m_enum = 0;
  v93 = 0i64;
LABEL_89:
  v95 = 2147483648;
  if ( v97[1].m_enum >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      20 * (v97[1].m_enum & 0x3FFFFFFF));
  return v7;
}

// File Line: 1878
// RVA: 0xB90200
_BOOL8 __fastcall _splitOrder(hkaiNavMeshGenerationUtils::EdgeSplit *a, hkaiNavMeshGenerationUtils::EdgeSplit *b)
{
  int v2; // er8
  int v3; // er9
  int v4; // eax
  _BOOL8 result; // rax

  v2 = a->m_faceIdx;
  v3 = b->m_faceIdx;
  result = 1;
  if ( a->m_faceIdx >= b->m_faceIdx )
  {
    if ( v2 != v3 || (v4 = b->m_edgeIdx, a->m_edgeIdx >= v4) && (v2 != v3 || a->m_edgeIdx != v4 || b->m_tS <= a->m_tS) )
      result = 0;
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
hkResult *__fastcall hkaiNavMeshGenerationUtils::_resolveConflictingEdgePairs(hkResult *result, hkArrayBase<hkaiNavMeshGenerationUtils::EdgePair> *edgePairs)
{
  int v2; // er12
  signed int v3; // er8
  hkArrayBase<hkaiNavMeshGenerationUtils::EdgePair> *v4; // rsi
  int v5; // er9
  EdgeAndPair *v6; // rdx
  hkResult *v7; // rdi
  int v8; // er9
  signed int v9; // er10
  int v10; // er9
  hkResultEnum v11; // eax
  hkResult *v12; // rax
  int v13; // ecx
  int v14; // eax
  int v15; // ebx
  int v16; // er9
  int v17; // er8
  int v18; // er15
  __int64 v19; // r14
  int v20; // ecx
  hkaiNavMeshGenerationUtils::EdgePair *v21; // rdi
  __int64 v22; // rbx
  int v23; // ecx
  __int64 v24; // rbx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v25; // r9
  int v26; // edx
  signed __int64 v27; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v28; // rax
  int v29; // ebx
  int v30; // ecx
  EdgeAndPair *v31; // rdx
  __int64 v32; // r8
  int v33; // edx
  signed __int64 v34; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v35; // rax
  int v36; // ecx
  EdgeAndPair *v37; // rdx
  char *v38; // r13
  __int64 v39; // r14
  __int64 v40; // r15
  int v41; // eax
  int v42; // edi
  signed __int64 v43; // rsi
  __int64 v44; // rax
  float v45; // xmm6_4
  float v46; // xmm5_4
  int i; // eax
  _QWORD *v48; // rbx
  signed __int64 v49; // r11
  __int64 v50; // rcx
  float *v51; // r9
  float *v52; // r8
  float v53; // xmm2_4
  float v54; // xmm4_4
  float v55; // xmm3_4
  signed int v56; // edx
  signed int v57; // eax
  signed int v58; // er10
  signed int v59; // edx
  signed int v60; // eax
  int v61; // er8
  void *ptr; // [rsp+38h] [rbp-61h]
  int v63; // [rsp+40h] [rbp-59h]
  int v64; // [rsp+44h] [rbp-55h]
  char *array; // [rsp+48h] [rbp-51h]
  int v66; // [rsp+50h] [rbp-49h]
  int v67; // [rsp+54h] [rbp-45h]
  EdgeAndPair *pArr; // [rsp+58h] [rbp-41h]
  int v69; // [rsp+60h] [rbp-39h]
  int v70; // [rsp+64h] [rbp-35h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v71; // [rsp+68h] [rbp-31h]
  hkResult *v72; // [rsp+100h] [rbp+67h]
  hkResult v73; // [rsp+108h] [rbp+6Fh]
  hkResult resulta; // [rsp+110h] [rbp+77h]
  hkResult v75; // [rsp+118h] [rbp+7Fh]

  v72 = result;
  v2 = 0;
  v3 = 2147483648;
  v4 = edgePairs;
  v5 = edgePairs->m_size;
  v6 = 0i64;
  v7 = result;
  v8 = 2 * v5;
  array = 0i64;
  v66 = 0;
  v67 = 2147483648;
  pArr = 0i64;
  v69 = 0;
  v9 = 2147483648;
  v70 = 2147483648;
  if ( v8 <= 0 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    if ( v8 < 0 )
      v8 = 0;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v8, 16);
    v3 = v67;
    v9 = v70;
    v6 = pArr;
  }
  v10 = 2 * v4->m_size;
  if ( (v9 & 0x3FFFFFFF) >= v10 )
  {
    v11 = 0;
    v73.m_enum = 0;
  }
  else
  {
    if ( v10 < 2 * (v9 & 0x3FFFFFFF) )
      v10 = 2 * (v9 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&v73, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &pArr, v10, 8);
    v3 = v67;
    v9 = v70;
    v6 = pArr;
    v11 = v73.m_enum;
  }
  if ( resulta.m_enum || v11 )
  {
    v69 = 0;
    v7->m_enum = 1;
    if ( v9 >= 0 )
    {
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v6,
        8 * v9);
      v3 = v67;
    }
    pArr = 0i64;
    v70 = 2147483648;
    v66 = 0;
    if ( v3 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        array,
        16 * v3);
    v12 = v7;
  }
  else
  {
    v13 = v4->m_size;
    ptr = 0i64;
    v63 = 0;
    v64 = 2147483648;
    v14 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getSizeInBytesFor(2 * v13);
    v15 = v14;
    if ( v14 <= 0 )
    {
      v75.m_enum = 0;
    }
    else
    {
      v16 = v14;
      if ( v14 < 0 )
        v16 = 0;
      hkArrayUtil::_reserve(&v75, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &ptr, v16, 1);
      if ( v75.m_enum )
      {
        v17 = v64;
        v7->m_enum = 1;
        v63 = 0;
        if ( v17 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            ptr,
            v17 & 0x3FFFFFFF);
        ptr = 0i64;
        v64 = 2147483648;
        v69 = 0;
        if ( v70 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            pArr,
            8 * v70);
        pArr = 0i64;
        v70 = 2147483648;
        v66 = 0;
        if ( v67 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            array,
            16 * v67);
        return v7;
      }
    }
    v63 = v15;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>(
      &v71,
      ptr,
      v15);
    v18 = 0;
    if ( v4->m_size > 0 )
    {
      v19 = 0i64;
      do
      {
        v20 = v66;
        v21 = &v4->m_data[v19];
        if ( v66 == (v67 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 16);
          v20 = v66;
        }
        v66 = v20 + 1;
        v22 = (__int64)&array[16 * v20];
        *(_QWORD *)v22 = v21;
        *(_DWORD *)(v22 + 8) = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                 &v71,
                                 v21->m_edgeAIdx,
                                 0xFFFFFFFFFFFFFFFFui64);
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          &v71,
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
          v21->m_edgeAIdx,
          v66 - 1);
        v23 = v66;
        if ( v66 == (v67 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 16);
          v23 = v66;
        }
        v66 = v23 + 1;
        v24 = (__int64)&array[16 * v23];
        *(_QWORD *)v24 = v21;
        *(_DWORD *)(v24 + 8) = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                 &v71,
                                 v21->m_edgeBIdx,
                                 0xFFFFFFFFFFFFFFFFui64);
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          &v71,
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
          v21->m_edgeBIdx,
          v66 - 1);
        ++v18;
        ++v19;
      }
      while ( v18 < v4->m_size );
    }
    v25 = v71.m_elem;
    v26 = 0;
    v27 = 0i64;
    if ( v71.m_hashMod >= 0 )
    {
      v28 = v71.m_elem;
      do
      {
        if ( v28->key != -1i64 )
          break;
        ++v27;
        ++v26;
        ++v28;
      }
      while ( v27 <= v71.m_hashMod );
    }
    v29 = v26;
    if ( v26 <= v71.m_hashMod )
    {
      do
      {
        v30 = v69;
        if ( v69 == (v70 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &pArr, 8);
          v30 = v69;
          v25 = v71.m_elem;
        }
        v31 = pArr;
        v32 = v30;
        v69 = v30 + 1;
        pArr[v32].m_edgeIndex = v25[v29].key;
        v31[v32].m_pairListIndex = v71.m_elem[v29].val;
        v25 = v71.m_elem;
        v33 = v29 + 1;
        v34 = v29 + 1;
        if ( v34 <= v71.m_hashMod )
        {
          v35 = &v71.m_elem[v33];
          do
          {
            if ( v35->key != -1i64 )
              break;
            ++v34;
            ++v33;
            ++v35;
          }
          while ( v34 <= v71.m_hashMod );
        }
        v29 = v33;
      }
      while ( v33 <= v71.m_hashMod );
    }
    if ( v69 > 1 )
      hkAlgorithm::quickSortRecursive<EdgeAndPair,hkAlgorithm::less<EdgeAndPair>>(pArr, 0, v69 - 1, 0);
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      &v71,
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr);
    _((AMD_HD3D *)&v71);
    v63 = 0;
    if ( v64 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        ptr,
        v64 & 0x3FFFFFFF);
    v36 = v69;
    v37 = pArr;
    v38 = (char *)2;
    v39 = 0i64;
    ptr = (void *)2;
    do
    {
      if ( v36 > 0 )
      {
        v40 = 0i64;
        do
        {
          v41 = v37[v40].m_pairListIndex;
          v42 = v37[v40].m_edgeIndex;
          if ( v41 != -1 )
          {
            do
            {
              v43 = 2i64 * v41;
              v44 = *(_QWORD *)&array[16 * v41];
              if ( *(_BYTE *)(v44 + 28) )
              {
                v45 = *(_DWORD *)v44 == v42 ? *(float *)(v44 + 32) : *(float *)(v44 + 40);
                v46 = *(_DWORD *)v44 == v42 ? *(float *)(v44 + 36) : *(float *)(v44 + 44);
                for ( i = *(_DWORD *)&array[8 * v43 + 8]; i != -1; i = *(_DWORD *)&array[8 * v49 + 8] )
                {
                  v48 = array;
                  v49 = 2i64 * i;
                  v50 = *(_QWORD *)&array[16 * i];
                  if ( *(_BYTE *)(v50 + 28) )
                  {
                    v51 = (float *)(v50 + 32);
                    if ( *(_DWORD *)v50 == v42 )
                    {
                      v52 = (float *)(v50 + 36);
                    }
                    else
                    {
                      v51 = (float *)(v50 + 40);
                      v52 = (float *)(v50 + 44);
                    }
                    v53 = *v51;
                    v54 = *v52;
                    v75.m_enum = LODWORD(v46);
                    v55 = fminf(v46, v54) - fmaxf(v45, v53);
                    if ( v39 == 1 )
                    {
                      if ( v55 > 0.0 )
                        *(_BYTE *)(v50 + 28) = 0;
                    }
                    else
                    {
                      if ( v45 > v53 || (v56 = 1, v46 < v53) )
                        v56 = 0;
                      if ( v45 > v54 || (v57 = 1, v46 < v54) )
                        v57 = 0;
                      if ( v56 && v57 )
                      {
                        v58 = 1;
                      }
                      else
                      {
                        v58 = 0;
                        if ( v55 > 0.0 && v55 < 0.0099999998 )
                        {
                          if ( v56 )
                          {
                            if ( !v57 )
                              *v51 = v46;
                          }
                          else if ( v57 )
                          {
                            *v52 = v45;
                          }
                        }
                      }
                      if ( *v51 > v45 || (v59 = 1, v45 > *v52) )
                        v59 = 0;
                      if ( *v51 > v46 || (v60 = 1, v46 > *v52) )
                        v60 = 0;
                      if ( v59 && v60 )
                        *(_BYTE *)(v50 + 28) = 0;
                      if ( v58 )
                        *(_BYTE *)(v48[v49] + 28i64) = 0;
                    }
                  }
                }
              }
              v41 = *(_DWORD *)&array[8 * v43 + 8];
            }
            while ( v41 != -1 );
            v36 = v69;
            v37 = pArr;
          }
          ++v2;
          ++v40;
        }
        while ( v2 < v36 );
        v38 = (char *)ptr;
      }
      ++v39;
      --v38;
      v2 = 0;
      ptr = v38;
    }
    while ( v38 );
    v61 = v70;
    v72->m_enum = 0;
    v69 = 0;
    if ( v61 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v37,
        8 * v61);
    pArr = 0i64;
    v70 = 2147483648;
    v66 = 0;
    if ( v67 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        array,
        16 * v67);
    v12 = v72;
  }
  return v12;
}

// File Line: 2132
// RVA: 0xB94120
hkaiNavMeshGenerationUtils *__fastcall hkaiNavMeshGenerationUtils::_gatherAndSortSplits<hkaiNavMesh>(hkaiNavMeshGenerationUtils *this, hkResult *result, hkaiNavMesh *meshA, hkaiNavMesh *meshB, hkArrayBase<hkaiNavMeshGenerationUtils::EdgePair> *edgePairs)
{
  hkArrayBase<hkaiNavMeshGenerationUtils::EdgePair> *v5; // rbx
  hkaiNavMesh *v6; // r15
  int v7; // er9
  hkaiNavMeshGenerationUtils *v8; // r13
  int v9; // eax
  int v10; // eax
  int v12; // esi
  __int64 v13; // r14
  hkBaseObjectVtbl *v14; // rdi
  int v15; // ecx
  float v16; // xmm0_4
  float v17; // xmm1_4
  int v18; // eax
  hkaiNavMeshGenerationUtils::EdgePair *v19; // rcx
  signed __int64 v20; // rdx
  __int64 v21; // rax
  float v22; // xmm1_4
  hkaiNavMeshGenerationUtils::EdgePair *v23; // rcx
  signed __int64 v24; // rdx
  __int64 v25; // rax
  signed int v26; // er8
  __int64 v27; // rax
  hkaiNavMeshGenerationUtils::EdgePair *v28; // rcx
  signed __int64 v29; // rdx
  hkaiNavMeshGenerationUtils::EdgeSplit v30; // [rsp+30h] [rbp-38h]
  hkaiNavMeshGenerationUtils *v31; // [rsp+90h] [rbp+28h]
  hkResult *v32; // [rsp+98h] [rbp+30h]
  hkaiNavMesh *v33; // [rsp+A0h] [rbp+38h]

  v33 = meshA;
  v32 = result;
  v31 = this;
  v5 = edgePairs;
  v6 = meshB;
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
    hkArrayUtil::_reserve(
      (hkResult *)&edgePairs,
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
      edgePairs,
      v7,
      24);
    if ( (_DWORD)edgePairs )
    {
      *(_DWORD *)v8 = 1;
      return v8;
    }
  }
  v12 = 0;
  if ( *(_DWORD *)&v6->m_memSizeAndFlags > 0 )
  {
    v13 = 0i64;
    do
    {
      v14 = &v6->vfptr[v13];
      if ( BYTE4(v14[1].__first_virtual_table_function__) )
      {
        v15 = (int)v14->__vecDelDtor;
        v16 = *(float *)&v14[2].__vecDelDtor;
        v17 = *((float *)&v14[2].__vecDelDtor + 1);
        v30.m_faceIdx = (int)v14->__first_virtual_table_function__;
        v30.m_tS = v16;
        v30.m_tE = v17;
        v18 = v5->m_capacityAndFlags & 0x3FFFFFFF;
        v30.m_edgeIdx = (v15 & 0x3FFFFF) - *(_DWORD *)(*(_QWORD *)&v32[4].m_enum + 16i64 * (v30.m_faceIdx & 0x3FFFFF));
        if ( v5->m_size == v18 )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v5, 24);
        v19 = v5->m_data;
        v20 = 3i64 * v5->m_size;
        *((_QWORD *)&v19->m_edgeAIdx + v20) = *(_QWORD *)&v30.m_faceIdx;
        v21 = *(_QWORD *)&v30.m_tS;
        *((_QWORD *)&v19->m_faceAIdx + v20) = v14;
        *((_QWORD *)&v19->m_distanceSquared + v20) = v21;
        ++v5->m_size;
        LODWORD(v21) = HIDWORD(v14->__first_virtual_table_function__);
        v22 = *((float *)&v14[2].__first_virtual_table_function__ + 1);
        v30.m_tS = *(float *)&v14[2].__first_virtual_table_function__;
        v30.m_tE = v22;
        LODWORD(v19) = HIDWORD(v14->__vecDelDtor);
        v30.m_faceIdx = v21;
        LODWORD(v19) = ((unsigned int)v19 & 0x3FFFFF) - v33->m_faces.m_data[v21 & 0x3FFFFF].m_startEdgeIndex;
        LODWORD(v21) = v5->m_capacityAndFlags & 0x3FFFFFFF;
        v30.m_edgeIdx = (signed int)v19;
        if ( v5->m_size == (_DWORD)v21 )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v5, 24);
        v23 = v5->m_data;
        v24 = 3i64 * v5->m_size;
        *((_QWORD *)&v23->m_edgeAIdx + v24) = *(_QWORD *)&v30.m_faceIdx;
        v25 = *(_QWORD *)&v30.m_tS;
        *((_QWORD *)&v23->m_faceAIdx + v24) = (char *)v14 + 4;
        *((_QWORD *)&v23->m_distanceSquared + v24) = v25;
        ++v5->m_size;
      }
      ++v12;
      v13 += 3i64;
    }
    while ( v12 < *(_DWORD *)&v6->m_memSizeAndFlags );
    v8 = v31;
  }
  v26 = v5->m_size;
  if ( v26 > 1 )
    hkAlgorithm::quickSortRecursive<hkaiNavMeshGenerationUtils::EdgeSplit,hkAlgorithm::less<hkaiNavMeshGenerationUtils::EdgeSplit>>(
      (hkaiNavMeshGenerationUtils::EdgeSplit *)v5->m_data,
      0,
      v26 - 1,
      0);
  hkaiNavMeshGenerationUtils::EdgeSplit::setAsTerminiator(&v30);
  if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v5, 24);
  v27 = v5->m_size;
  v28 = v5->m_data;
  *(_DWORD *)v8 = 0;
  v29 = 3 * v27;
  *((_QWORD *)&v28->m_edgeAIdx + v29) = *(_QWORD *)&v30.m_faceIdx;
  *((_QWORD *)&v28->m_faceAIdx + v29) = v30.m_sharedPairEdgeIdx;
  *((_QWORD *)&v28->m_distanceSquared + v29) = *(_QWORD *)&v30.m_tS;
  return v8;
}

// File Line: 2183
// RVA: 0xB8E680
hkResult *__fastcall hkaiNavMeshGenerationUtils::_connectEdges(hkResult *result, hkaiNavMeshGenerationSettings *input, hkaiNavMesh *mesh, hkaiEdgeGeometryRaycaster *raycaster, int iterationNumber, hkaiNavMeshGenerationProgressCallback *cb, hkaiNavMeshGenerationProgressCallbackContext *cbCtx)
{
  hkResult *v7; // rdi
  hkaiNavMesh *v8; // rsi
  hkaiNavMeshGenerationSettings *v9; // rbx
  bool v10; // r14
  hkResult *v11; // rax
  int v12; // ebx
  int v13; // ecx
  int v14; // er9
  __int64 v15; // r10
  hkaiNavMeshGenerationUtils::EdgePair *v16; // r8
  hkaiNavMeshGenerationProgressCallback *v18; // [rsp+28h] [rbp-58h]
  hkResult resulta; // [rsp+40h] [rbp-40h]
  hkResult v20; // [rsp+44h] [rbp-3Ch]
  hkArray<hkaiNavMeshGenerationUtils::EdgePair,hkContainerHeapAllocator> edgePairs; // [rsp+48h] [rbp-38h]
  hkArrayBase<hkaiNavMeshGenerationUtils::EdgePair> v22; // [rsp+58h] [rbp-28h]
  NavMeshFreeList freeList; // [rsp+68h] [rbp-18h]

  v7 = result;
  v8 = mesh;
  v9 = input;
  v10 = iterationNumber == 0;
  edgePairs.m_capacityAndFlags = 2147483648;
  edgePairs.m_data = 0i64;
  edgePairs.m_size = 0;
  if ( iterationNumber )
    v11 = hkaiNavMeshGenerationUtils::_findConnectableEdges(
            (hkResult *)&iterationNumber,
            input,
            mesh,
            raycaster,
            &edgePairs,
            iterationNumber,
            cb,
            cbCtx);
  else
    v11 = hkaiNavMeshGenerationUtils::_findExactEdges(
            (hkResult *)&iterationNumber,
            input,
            mesh,
            raycaster,
            &edgePairs,
            cb,
            cbCtx);
  if ( v11->m_enum )
  {
    v7->m_enum = 1;
    goto LABEL_33;
  }
  if ( !edgePairs.m_size )
  {
    v7->m_enum = 0;
    goto LABEL_33;
  }
  if ( v9->m_edgeMatchingMetric.m_storage == 1 )
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
    hkaiNavMeshGenerationUtils::_resolveConflictingEdgePairs(
      (hkResult *)&iterationNumber,
      (hkArrayBase<hkaiNavMeshGenerationUtils::EdgePair> *)&edgePairs.m_data);
    if ( iterationNumber )
    {
      v7->m_enum = 1;
      goto LABEL_33;
    }
  }
  v22.m_data = 0i64;
  v22.m_size = 0;
  v22.m_capacityAndFlags = 2147483648;
  hkaiNavMeshGenerationUtils::_gatherAndSortSplits<hkaiNavMesh>(
    (hkaiNavMeshGenerationUtils *)&iterationNumber,
    (hkResult *)v8,
    v8,
    (hkaiNavMesh *)&edgePairs,
    &v22,
    (hkArray<hkaiNavMeshGenerationUtils::EdgeSplit,hkContainerTempAllocator> *)v18);
  if ( !iterationNumber )
  {
    v12 = 0;
    freeList.m_freeSpace.m_data = 0i64;
    freeList.m_freeSpace.m_size = 0;
    freeList.m_freeSpace.m_capacityAndFlags = 2147483648;
    if ( v22.m_size <= 0 )
    {
LABEL_21:
      v13 = edgePairs.m_size;
      v14 = 0;
      if ( edgePairs.m_size > 0 )
      {
        v15 = 0i64;
        do
        {
          v16 = &edgePairs.m_data[v15];
          if ( edgePairs.m_data[v15].m_isValid )
          {
            v8->m_edges.m_data[v16->m_edgeAIdx].m_oppositeEdge = v16->m_edgeBIdx;
            v8->m_edges.m_data[v16->m_edgeBIdx].m_oppositeEdge = v16->m_edgeAIdx;
            v8->m_edges.m_data[v16->m_edgeAIdx].m_oppositeFace = v16->m_faceBIdx;
            v8->m_edges.m_data[v16->m_edgeBIdx].m_oppositeFace = v16->m_faceAIdx;
            v13 = edgePairs.m_size;
          }
          ++v14;
          ++v15;
        }
        while ( v14 < v13 );
      }
      hkaiNavMeshUtils::compactEdges(&v20, v8, 0, 0);
      if ( v20.m_enum == HK_SUCCESS )
      {
        v7->m_enum = 0;
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
          v8,
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
    v7->m_enum = 1;
LABEL_29:
    hkArray<hkArray<unsigned int,hkContainerHeapAllocator>,hkContainerHeapAllocator>::~hkArray<hkArray<unsigned int,hkContainerHeapAllocator>,hkContainerHeapAllocator>(&freeList);
    goto LABEL_30;
  }
  v7->m_enum = 1;
LABEL_30:
  v22.m_size = 0;
  if ( v22.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v22.m_data,
      24 * (v22.m_capacityAndFlags & 0x3FFFFFFF));
  v22.m_capacityAndFlags = 2147483648;
  v22.m_data = 0i64;
LABEL_33:
  edgePairs.m_size = 0;
  if ( edgePairs.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      edgePairs.m_data,
      48 * (edgePairs.m_capacityAndFlags & 0x3FFFFFFF));
  return v7;
}

