// File Line: 35
// RVA: 0xDC9C80
void __fastcall hkpConvexPenetrationUtil::findBestProjection(
        hkpConvexPenetrationUtil *this,
        hkVector4f *direction,
        hkVector4f *from,
        hkcdWingedEdge::Vertex *result,
        hkSimdFloat32 *bestDistanceOut)
{
  hkVector4f v9; // xmm4
  __m128 v10; // xmm1
  __m128 v11; // xmm3
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  hkcdVertex v14; // xmm0
  hkcdVertex v15; // xmm1
  hkcdWingedEdge::Edge *m_storage; // rax
  hkVector4f directiona; // [rsp+20h] [rbp-58h] BYREF
  hkcdWingedEdge::Vertex resulta; // [rsp+30h] [rbp-48h] BYREF

  directiona.m_quad = _mm_xor_ps(
                        (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                        direction->m_quad);
  hkpConvexPenetrationUtil::getPointForSimplex(this, direction, &resulta);
  hkpConvexPenetrationUtil::getPointForSimplex(this, &directiona, result);
  v9.m_quad = (__m128)resulta.m_position;
  v10 = _mm_mul_ps(_mm_sub_ps(resulta.m_position.m_quad, from->m_quad), direction->m_quad);
  v11 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)), _mm_shuffle_ps(v10, v10, 170));
  v12 = _mm_mul_ps(_mm_sub_ps(result->m_position.m_quad, from->m_quad), directiona.m_quad);
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  bestDistanceOut->m_real = _mm_max_ps(v11, v13);
  if ( v11.m128_f32[0] >= v13.m128_f32[0] )
  {
    v14.m_quad = (__m128)resulta.m_pointAinA;
    v15.m_quad = (__m128)resulta.m_pointBinX;
    m_storage = resulta.m_referee.m_storage;
    result->m_position = (hkVector4f)v9.m_quad;
    result->m_pointAinA = (hkcdVertex)v14.m_quad;
    result->m_pointBinX = (hkcdVertex)v15.m_quad;
    result->m_referee.m_storage = m_storage;
  }
}

// File Line: 265
// RVA: 0xDC8980
void hkpConvexPenetrationUtil::codeBegin(void)
{
  ;
}

// File Line: 269
// RVA: 0xDC9B90
void __fastcall hkpConvexPenetrationUtil::getPointForSimplex(
        hkpConvexPenetrationUtil *this,
        hkVector4f *direction,
        hkcdWingedEdge::Vertex *result)
{
  hkpConvexShape *m_storage; // rcx
  hkVector4f v7; // xmm3
  __m128 v8; // xmm1
  __m128 v9; // xmm2
  __m128 v10; // xmm5
  hkcdVertex v11; // xmm1
  __m128 v12; // [rsp+20h] [rbp-18h] BYREF

  ((void (__fastcall *)(hkpConvexShape *, hkVector4f *, hkcdVertex *))this->m_shapeA.m_storage->vfptr[4].__vecDelDtor)(
    this->m_shapeA.m_storage,
    direction,
    &result->m_pointAinA);
  m_storage = this->m_shapeB.m_storage;
  v7.m_quad = (__m128)this->m_aTb.m_rotation.m_col2;
  v8 = _mm_unpacklo_ps(this->m_aTb.m_rotation.m_col0.m_quad, this->m_aTb.m_rotation.m_col1.m_quad);
  v9 = _mm_movelh_ps(v8, v7.m_quad);
  v10 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), direction->m_quad);
  v12 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(_mm_movehl_ps(v9, v8), v7.m_quad, 212)),
            _mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), v9)),
          _mm_mul_ps(
            _mm_shuffle_ps(v10, v10, 170),
            _mm_shuffle_ps(
              _mm_unpackhi_ps(this->m_aTb.m_rotation.m_col0.m_quad, this->m_aTb.m_rotation.m_col1.m_quad),
              v7.m_quad,
              228)));
  ((void (__fastcall *)(hkpConvexShape *, __m128 *, hkcdVertex *))m_storage->vfptr[4].__vecDelDtor)(
    m_storage,
    &v12,
    &result->m_pointBinX);
  v11.m_quad = (__m128)result->m_pointBinX;
  result->m_position.m_quad = _mm_sub_ps(
                                result->m_pointAinA.m_quad,
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_mul_ps(
                                        _mm_shuffle_ps(v11.m_quad, v11.m_quad, 0),
                                        this->m_aTb.m_rotation.m_col0.m_quad),
                                      _mm_mul_ps(
                                        _mm_shuffle_ps(v11.m_quad, v11.m_quad, 85),
                                        this->m_aTb.m_rotation.m_col1.m_quad)),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(v11.m_quad, v11.m_quad, 170),
                                      this->m_aTb.m_rotation.m_col2.m_quad)),
                                  this->m_aTb.m_translation.m_quad));
}

// File Line: 283
// RVA: 0xDC9710
hkResult *__fastcall hkpConvexPenetrationUtil::tryToExpandPolytope(
        hkpConvexPenetrationUtil *this,
        hkResult *result,
        hkcdWingedEdge *we,
        hkcdWingedEdge::Triangle *nearestTriangle,
        hkcdWingedEdge::Vertex *newVertex,
        hkpGskStatus *failureReason)
{
  hkcdWingedEdge::Vertex *v7; // r8
  __m128 v9; // xmm6
  __m128 v10; // xmm0
  __m128 v11; // xmm5
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  hkpGskStatus *v14; // rax
  hkcdWingedEdge::Vertex *m_vertex; // rax
  __m128 m_quad; // xmm1
  __m128 v18; // xmm1
  hkcdWingedEdge::Triangle::TriangleState v19; // eax
  __m128 v20; // xmm1
  float v21; // xmm2_4
  float v22; // xmm2_4
  int m_storage; // r8d
  int v24; // edx
  __int64 v25; // r12
  hkpGskStatus *v26; // rax
  int v27; // eax
  int v28; // ecx
  int v29; // r11d
  __int64 v30; // r8
  __int64 *v31; // r9
  hkcdWingedEdge::Triangle **v32; // r10
  hkcdWingedEdge::Triangle *v33; // rax
  __int64 v34; // r9
  __int64 *v35; // r8
  __int64 v36; // rcx
  hkcdWingedEdge::Edge *v37; // rdx
  __int64 v38; // rbp
  hkcdWingedEdge::Edge *v39; // r15
  int v40; // r13d
  __int64 v41; // r11
  __int64 v42; // rsi
  __m128 *p_m_quad; // r8
  __m128 *v44; // rdx
  hkcdWingedEdge::Vertex *v45; // r9
  __m128 v46; // xmm1
  __m128 v47; // xmm0
  __m128 v48; // xmm4
  __m128 v49; // xmm4
  __m128 v50; // xmm3
  __m128 v51; // xmm1
  __m128 v52; // xmm2
  __m128 v53; // xmm4
  __m128 v54; // xmm5
  hkcdWingedEdge::Edge *m_next; // rax
  int v56; // eax
  hkcdWingedEdge::Triangle::TriangleState *p_m_state; // rcx
  int v58; // ecx
  hkPadSpu<hkcdWingedEdge::Edge *> *p_m_referee; // rax
  hkpGskStatus *v60; // rax
  hkpGskStatus *v61; // rax
  hkcdWingedEdge::Edge *v62; // [rsp+30h] [rbp-378h]
  __int64 v63[100]; // [rsp+40h] [rbp-368h] BYREF
  hkPadSpu<int> chainLength; // [rsp+3B0h] [rbp+8h] BYREF
  hkPadSpu<hkcdWingedEdge::Edge *> edgeChain; // [rsp+3C8h] [rbp+20h] BYREF

  v7 = newVertex;
  v9 = _mm_sub_ps(newVertex->m_position.m_quad, nearestTriangle->m_edge[0].m_vertex->m_position.m_quad);
  v10 = _mm_sub_ps(newVertex->m_position.m_quad, nearestTriangle->m_edge[1].m_vertex->m_position.m_quad);
  v11 = _mm_sub_ps(newVertex->m_position.m_quad, nearestTriangle->m_edge[2].m_vertex->m_position.m_quad);
  v12 = _mm_unpacklo_ps(v9, v10);
  v13 = _mm_movelh_ps(v12, v11);
  if ( (_mm_movemask_ps(
          _mm_cmplt_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps(_mm_movehl_ps(v13, v12), v11, 212),
                  _mm_shuffle_ps(nearestTriangle->m_normal.m_quad, nearestTriangle->m_normal.m_quad, 85)),
                _mm_mul_ps(_mm_shuffle_ps(nearestTriangle->m_normal.m_quad, nearestTriangle->m_normal.m_quad, 0), v13)),
              _mm_mul_ps(
                _mm_shuffle_ps(_mm_unpackhi_ps(v9, v10), v11, 228),
                _mm_shuffle_ps(nearestTriangle->m_normal.m_quad, nearestTriangle->m_normal.m_quad, 170))),
            this->m_epsTol.m_quad)) & 7) != 0 )
  {
    v14 = failureReason;
    result->m_enum = HK_FAILURE;
    *v14 = HK_GSK_OK;
    return result;
  }
  we->m_toleranceBorder.m_storage = 0.0000001;
  we->m_previousMinimumDistance.m_storage = 3.40282e38;
  m_vertex = nearestTriangle->m_edge[0].m_vertex;
  m_quad = v7->m_position.m_quad;
  edgeChain.m_storage = 0i64;
  chainLength.m_storage = 0;
  v18 = _mm_sub_ps(m_quad, m_vertex->m_position.m_quad);
  v19 = HKCD_VISIBLE;
  v20 = _mm_mul_ps(v18, nearestTriangle->m_normal.m_quad);
  v21 = (float)(_mm_shuffle_ps(v20, v20, 85).m128_f32[0] + _mm_shuffle_ps(v20, v20, 0).m128_f32[0])
      + _mm_shuffle_ps(v20, v20, 170).m128_f32[0];
  if ( v21 <= 0.0000001 )
  {
    v22 = v21 + 0.0000001;
    if ( v22 > 0.0000001 )
      we->m_toleranceBorder.m_storage = v22;
    v19 = HKCD_INVISIBLE;
  }
  else if ( v21 < 3.40282e38 )
  {
    we->m_previousMinimumDistance.m_storage = v21;
  }
  if ( we->m_previousMinimumDistance.m_storage <= we->m_toleranceBorder.m_storage )
    v19 = HKCD_UNKNOWN;
  nearestTriangle->m_state = v19;
  if ( v19 != HKCD_VISIBLE
    || hkcdWingedEdge::findVisibleTriangles(we, nearestTriangle, &v7->m_position, &chainLength, &edgeChain) )
  {
    v61 = failureReason;
    result->m_enum = HK_FAILURE;
    *v61 = HK_GSK_PD_UNSOLVABLE;
    return result;
  }
  m_storage = we->m_numFreeTriangle.m_storage;
  v24 = we->m_numTriangles.m_storage;
  v25 = chainLength.m_storage;
  if ( m_storage - v24 + 100 >= chainLength.m_storage )
  {
    v27 = m_storage - 1;
    v28 = chainLength.m_storage;
    v29 = 0;
    v30 = m_storage - 1;
    if ( chainLength.m_storage )
    {
      v31 = v63;
      v32 = &we->m_freeTriangle[v27];
      do
      {
        if ( v30 < 0 )
          break;
        v33 = *v32;
        --we->m_numFreeTriangle.m_storage;
        *v31++ = (__int64)v33;
        ++v29;
        --v30;
        --v32;
        --v28;
      }
      while ( v28 );
    }
    if ( v28 > 0 )
    {
      v34 = (unsigned int)v28;
      v35 = &v63[v29];
      do
      {
        v36 = v24++;
        *v35++ = (__int64)&we->m_triangles[v36];
        --v34;
      }
      while ( v34 );
      we->m_numTriangles.m_storage = v24;
    }
    v37 = edgeChain.m_storage;
    v38 = 0i64;
    v62 = edgeChain.m_storage;
    v39 = edgeChain.m_storage;
    if ( (int)v25 <= 0 )
    {
LABEL_32:
      v56 = 0;
      if ( we->m_numTriangles.m_storage > 0 )
      {
        p_m_state = &we->m_triangles[0].m_state;
        do
        {
          *p_m_state = HKCD_NOT_VISITED;
          ++v56;
          p_m_state += 32;
        }
        while ( v56 < we->m_numTriangles.m_storage );
      }
      v58 = 0;
      if ( we->m_numVertices.m_storage > 0 )
      {
        p_m_referee = &we->m_vertex[0].m_referee;
        do
        {
          p_m_referee->m_storage = 0i64;
          ++v58;
          p_m_referee += 8;
        }
        while ( v58 < we->m_numVertices.m_storage );
      }
      if ( v37 == v39 )
      {
        result->m_enum = HK_SUCCESS;
        return result;
      }
    }
    else
    {
      v40 = 1;
      while ( v39 )
      {
        v41 = v63[v38];
        v42 = v40 >= (int)v25 ? v63[0] : v63[v38 + 1];
        *(_QWORD *)(v41 + 40) = v41;
        *(_QWORD *)(v41 + 72) = v41;
        *(_QWORD *)(v41 + 104) = v41;
        *(_QWORD *)(v41 + 24) = v41 + 48;
        *(_QWORD *)(v41 + 56) = v41 + 80;
        *(_QWORD *)(v41 + 88) = v41 + 16;
        p_m_quad = &v39->m_vertex->m_position.m_quad;
        v44 = (__m128 *)v39->m_next->m_vertex;
        *(_QWORD *)(v41 + 48) = v39->m_vertex;
        v45 = newVertex;
        *(_QWORD *)(v41 + 80) = newVertex;
        *(_QWORD *)(v41 + 16) = v44;
        v39->m_neighbour = (hkcdWingedEdge::Edge *)(v41 + 16);
        *(_QWORD *)(v41 + 32) = v39;
        *(_QWORD *)(v42 + 64) = v41 + 80;
        *(_QWORD *)(v41 + 96) = v42 + 48;
        v46 = _mm_sub_ps(*v44, *p_m_quad);
        v47 = _mm_sub_ps(*p_m_quad, v45->m_position.m_quad);
        v48 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v47, v47, 201), v46), _mm_mul_ps(_mm_shuffle_ps(v46, v46, 201), v47));
        v49 = _mm_shuffle_ps(v48, v48, 201);
        v50 = _mm_mul_ps(v49, v49);
        if ( (float)((float)(_mm_shuffle_ps(v50, v50, 85).m128_f32[0] + _mm_shuffle_ps(v50, v50, 0).m128_f32[0])
                   + _mm_shuffle_ps(v50, v50, 170).m128_f32[0]) <= 0.0 )
          break;
        ++v38;
        ++v40;
        v51 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v50, v50, 85), _mm_shuffle_ps(v50, v50, 0)),
                _mm_shuffle_ps(v50, v50, 170));
        v52 = _mm_rsqrt_ps(v51);
        v53 = _mm_mul_ps(
                v49,
                _mm_andnot_ps(
                  _mm_cmple_ps(v51, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v52, v51), v52)),
                    _mm_mul_ps(*(__m128 *)_xmm, v52))));
        v54 = _mm_mul_ps(*v44, v53);
        *(float *)(v41 + 112) = (float)(_mm_shuffle_ps(v54, v54, 85).m128_f32[0]
                                      + _mm_shuffle_ps(v54, v54, 0).m128_f32[0])
                              + _mm_shuffle_ps(v54, v54, 170).m128_f32[0];
        *(__m128 *)v41 = v53;
        m_next = v39->m_next;
        v39 = m_next->m_vertex->m_referee.m_storage;
        m_next->m_vertex->m_referee.m_storage = 0i64;
        if ( v38 >= v25 )
        {
          v37 = v62;
          goto LABEL_32;
        }
      }
    }
    v60 = failureReason;
    result->m_enum = HK_FAILURE;
    *v60 = HK_GSK_PD_UNSOLVABLE;
  }
  else
  {
    v26 = failureReason;
    result->m_enum = HK_FAILURE;
    *v26 = HK_GSK_PD_OUT_OF_MEMORY;
  }
  return result;
}

// File Line: 341
// RVA: 0xDC9580
void __fastcall hkpConvexPenetrationUtil::convertResultToFeature(
        hkpConvexPenetrationUtil *this,
        hkcdWingedEdge *polytope,
        hkcdWingedEdge::Triangle *nearestTriangle,
        hkpGskOut *output)
{
  int i; // edi
  hkcdWingedEdge::Vertex *m_vertex; // rcx
  hkcdWingedEdge::Vertex *v10; // rcx
  hkcdWingedEdge::Vertex *v11; // rcx
  __m128 m_quad; // xmm1
  hkcdVertex *m_storage; // rax
  hkVector4f result; // [rsp+30h] [rbp-28h] BYREF

  for ( i = 0; i < 10; ++i )
  {
    *this->m_simplex.m_storage = nearestTriangle->m_edge[0].m_vertex->m_position;
    this->m_simplex.m_storage[1] = nearestTriangle->m_edge[1].m_vertex->m_position;
    this->m_simplex.m_storage[2] = nearestTriangle->m_edge[2].m_vertex->m_position;
    hkcdTriangleUtil::calcBarycentricCoordinates(
      &aabbOut,
      this->m_simplex.m_storage,
      this->m_simplex.m_storage + 1,
      this->m_simplex.m_storage + 2,
      &result);
    if ( (_mm_movemask_ps(_mm_cmplt_ps(result.m_quad, (__m128)0i64)) & 7) == 0 )
      break;
    nearestTriangle = hkcdWingedEdge::findTriangleNearestOrigin(polytope, nearestTriangle);
  }
  m_vertex = nearestTriangle->m_edge[0].m_vertex;
  *this->m_pointsAinA.m_storage = m_vertex->m_pointAinA;
  *this->m_pointsBinB.m_storage = m_vertex->m_pointBinX;
  v10 = nearestTriangle->m_edge[1].m_vertex;
  this->m_pointsAinA.m_storage[1] = v10->m_pointAinA;
  this->m_pointsBinB.m_storage[1] = v10->m_pointBinX;
  v11 = nearestTriangle->m_edge[2].m_vertex;
  this->m_pointsAinA.m_storage[2] = v11->m_pointAinA;
  this->m_pointsBinB.m_storage[2] = v11->m_pointBinX;
  m_quad = result.m_quad;
  m_storage = this->m_pointsAinA.m_storage;
  this->m_simplexSize.m_storage = 3;
  output->m_pointAinA.m_quad = _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), m_storage[1].m_quad),
                                   _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), m_storage->m_quad)),
                                 _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), m_storage[2].m_quad));
  LODWORD(output->m_distance.m_storage) = LODWORD(nearestTriangle->m_distanceToOrigin) ^ _xmm[0];
  output->m_normalInA.m_quad = _mm_xor_ps(
                                 (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                 nearestTriangle->m_normal.m_quad);
}

// File Line: 406
// RVA: 0xDC8CB0
hkResult *__fastcall hkpConvexPenetrationUtil::builtTetrahedron(
        hkpConvexPenetrationUtil *this,
        hkResult *result,
        hkpGskOut *output,
        hkpGskStatus *gjkStatus)
{
  int v5; // edi
  __m128 m_storage_low; // xmm11
  int m_storage; // ecx
  float v11; // xmm11_4
  int v12; // ecx
  int v13; // ecx
  int v14; // ecx
  hkVector4f v15; // xmm2
  __m128 v16; // xmm6
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  hkVector4f *v19; // rax
  __m128 v20; // xmm1
  __m128 v21; // xmm4
  hkVector4f *v22; // rsi
  __m128 v23; // xmm2
  __m128 v24; // xmm6
  __m128 v25; // xmm6
  hkVector4f *v26; // rax
  __m128 v27; // xmm3
  __m128 v28; // xmm3
  hkVector4f *v29; // r8
  __m128 v30; // xmm10
  __m128 v31; // xmm2
  __m128 v32; // xmm6
  __m128 v33; // xmm5
  __m128 v34; // xmm6
  __m128 v35; // xmm1
  __m128 v36; // xmm4
  __m128 v37; // xmm7
  __m128 v38; // xmm7
  __m128 v39; // xmm1
  __m128 v40; // xmm3
  __m128 v41; // xmm2
  __m128 v42; // xmm8
  __m128 v43; // xmm8
  __m128 v44; // xmm1
  __m128 v45; // xmm2
  __m128 v46; // xmm1
  hkVector4f *v47; // rax
  hkcdVertex v48; // xmm0
  hkVector4f *v49; // r8
  __m128 v50; // xmm0
  __m128 v51; // xmm1
  __m128 v52; // xmm0
  __m128 v53; // xmm4
  __m128 v54; // xmm4
  __m128 v55; // xmm3
  __m128 v56; // xmm1
  __m128 v57; // xmm2
  hkVector4f *v58; // rax
  __m128 v59; // xmm0
  __m128 v60; // xmm1
  __m128 v61; // xmm0
  __m128 v62; // xmm2
  __m128 v63; // xmm3
  __m128 v64; // xmm1
  __m128 v65; // xmm6
  __m128 v66; // xmm6
  __m128 v67; // xmm5
  __m128 v68; // xmm6
  __m128 v69; // xmm1
  __m128 v70; // xmm4
  __m128 v71; // xmm7
  __m128 v72; // xmm7
  __m128 v73; // xmm1
  __m128 v74; // xmm3
  __m128 v75; // xmm2
  __m128 v76; // xmm1
  __m128 v77; // xmm4
  __m128 v78; // xmm1
  __m128 v79; // xmm2
  __m128 v80; // xmm1
  __m128 v81; // xmm2
  __m128 v82; // xmm0
  hkVector4f v83; // xmm1
  __m128 v84; // xmm2
  __m128 m_quad; // xmm0
  hkVector4f v87; // [rsp+30h] [rbp-A8h] BYREF
  hkSimdFloat32 v88; // [rsp+40h] [rbp-98h] BYREF
  char resulta[72]; // [rsp+50h] [rbp-88h] BYREF
  hkVector4f direction; // [rsp+A8h] [rbp-30h] BYREF
  hkVector4f v91; // [rsp+B8h] [rbp-20h] BYREF
  hkVector4f v92; // [rsp+C8h] [rbp-10h] BYREF
  hkVector4f v93; // [rsp+D8h] [rbp+0h] BYREF
  hkSimdFloat32 v94; // [rsp+E8h] [rbp+10h] BYREF
  hkSimdFloat32 bestDistanceOut; // [rsp+F8h] [rbp+20h] BYREF

  v5 = -1;
  m_storage_low = (__m128)LODWORD(this->m_epsTolSqrd.m_storage);
  m_storage = this->m_simplexSize.m_storage;
  LODWORD(v11) = _mm_shuffle_ps(m_storage_low, m_storage_low, 0).m128_u32[0];
  if ( !m_storage )
    goto $DO_CASE0;
  v12 = m_storage - 1;
  if ( !v12 )
  {
    while ( 1 )
    {
$DO_CASE1:
      v22 = this->m_simplex.m_storage;
      v23 = _mm_mul_ps(v22->m_quad, v22->m_quad);
      if ( (float)((float)(_mm_shuffle_ps(v23, v23, 85).m128_f32[0] + _mm_shuffle_ps(v23, v23, 0).m128_f32[0])
                 + _mm_shuffle_ps(v23, v23, 170).m128_f32[0]) > v11 )
      {
        v5 = 1;
        hkpConvexPenetrationUtil::getPointForSimplex(this, this->m_simplex.m_storage, (hkcdWingedEdge::Vertex *)resulta);
        v24 = _mm_sub_ps(*(__m128 *)resulta, this->m_simplex.m_storage->m_quad);
        v25 = _mm_mul_ps(v24, v24);
        v93.m_quad = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v22->m_quad);
        hkpConvexPenetrationUtil::getPointForSimplex(this, &v93, (hkcdWingedEdge::Vertex *)&resulta[24]);
        v26 = this->m_simplex.m_storage;
        v27 = _mm_sub_ps(*(__m128 *)&resulta[24], v26->m_quad);
        v28 = _mm_mul_ps(v27, v27);
        if ( (float)((float)(_mm_shuffle_ps(v25, v25, 85).m128_f32[0] + _mm_shuffle_ps(v25, v25, 0).m128_f32[0])
                   + _mm_shuffle_ps(v25, v25, 170).m128_f32[0]) < (float)((float)(_mm_shuffle_ps(v28, v28, 85).m128_f32[0]
                                                                                + _mm_shuffle_ps(v28, v28, 0).m128_f32[0])
                                                                        + _mm_shuffle_ps(v28, v28, 170).m128_f32[0]) )
        {
          v26[1] = *(hkVector4f *)&resulta[24];
          this->m_pointsAinA.m_storage[1] = *(hkcdVertex *)&resulta[40];
          this->m_pointsBinB.m_storage[1] = *(hkcdVertex *)&resulta[56];
        }
        else
        {
          v26[1] = *(hkVector4f *)resulta;
          this->m_pointsAinA.m_storage[1] = *(hkcdVertex *)&resulta[16];
          this->m_pointsBinB.m_storage[1] = *(hkcdVertex *)&resulta[32];
        }
        goto LABEL_13;
      }
      if ( v5 >= 0 )
        goto LABEL_25;
      this->m_simplexSize.m_storage = 0;
$DO_CASE0:
      v15.m_quad = (__m128)this->m_aTb.m_translation;
      v16 = _mm_shuffle_ps(
              (__m128)LODWORD(this->m_epsTolSqrd.m_storage),
              (__m128)LODWORD(this->m_epsTolSqrd.m_storage),
              0);
      v17 = _mm_mul_ps(v15.m_quad, v15.m_quad);
      v18 = _mm_cmple_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
                _mm_shuffle_ps(v17, v17, 170)),
              v16);
      direction.m_quad = _mm_or_ps(
                           _mm_andnot_ps(
                             v18,
                             _mm_xor_ps(
                               (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                               v15.m_quad)),
                           _mm_and_ps(v18, ::direction.m_quad));
      hkpConvexPenetrationUtil::getPointForSimplex(this, &direction, (hkcdWingedEdge::Vertex *)resulta);
      *this->m_simplex.m_storage = *(hkVector4f *)resulta;
      *this->m_pointsAinA.m_storage = *(hkcdVertex *)&resulta[16];
      *this->m_pointsBinB.m_storage = *(hkcdVertex *)&resulta[32];
      v19 = this->m_simplex.m_storage;
      this->m_simplexSize.m_storage = 1;
      v20 = _mm_mul_ps(v19->m_quad, v19->m_quad);
      v21 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
              _mm_shuffle_ps(v20, v20, 170));
      if ( v21.m128_f32[0] <= v16.m128_f32[0] )
      {
        v80 = _mm_rsqrt_ps(v21);
        v81 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v80, v21), v80));
        v82 = _mm_mul_ps(*(__m128 *)_xmm, v80);
        v83.m_quad = *(__m128 *)&resulta[16];
        v84 = _mm_mul_ps(v81, v82);
        m_quad = direction.m_quad;
        LODWORD(output->m_distance.m_storage) = _mm_andnot_ps(_mm_cmple_ps(v21, (__m128)0i64), _mm_mul_ps(v84, v21)).m128_u32[0];
        output->m_normalInA.m_quad = m_quad;
        output->m_pointAinA = (hkVector4f)v83.m_quad;
        *gjkStatus = HK_GSK_OK;
        goto LABEL_35;
      }
      v5 = 0;
    }
  }
  v13 = v12 - 1;
  if ( !v13 )
    goto $DO_CASE2;
  v14 = v13 - 1;
  if ( !v14 )
    goto $DO_CASE3;
  if ( v14 == 1 )
  {
    while ( 2 )
    {
      v58 = this->m_simplex.m_storage;
      v59 = v58[1].m_quad;
      v60 = _mm_sub_ps(v58->m_quad, v59);
      v61 = _mm_sub_ps(v59, v58[2].m_quad);
      v62 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v61, v61, 201), v60), _mm_mul_ps(_mm_shuffle_ps(v60, v60, 201), v61));
      v87.m_quad = _mm_shuffle_ps(v62, v62, 201);
      v63 = _mm_mul_ps(v87.m_quad, v87.m_quad);
      v64 = _mm_mul_ps(_mm_sub_ps(v58[3].m_quad, v58->m_quad), v87.m_quad);
      v62.m128_f32[0] = (float)(_mm_shuffle_ps(v64, v64, 85).m128_f32[0] + _mm_shuffle_ps(v64, v64, 0).m128_f32[0])
                      + _mm_shuffle_ps(v64, v64, 170).m128_f32[0];
      if ( (float)(v62.m128_f32[0] * v62.m128_f32[0]) > (float)((float)((float)(_mm_shuffle_ps(v63, v63, 85).m128_f32[0]
                                                                              + _mm_shuffle_ps(v63, v63, 0).m128_f32[0])
                                                                      + _mm_shuffle_ps(v63, v63, 170).m128_f32[0])
                                                              * v11) )
      {
        *gjkStatus = HK_GSK_OK;
        result->m_enum = HK_SUCCESS;
        return result;
      }
      if ( v5 < 3 )
      {
        while ( 1 )
        {
          this->m_simplexSize.m_storage = 3;
$DO_CASE3:
          v49 = this->m_simplex.m_storage;
          v50 = v49[1].m_quad;
          v51 = _mm_sub_ps(v49->m_quad, v50);
          v52 = _mm_sub_ps(v50, v49[2].m_quad);
          v53 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v52, v52, 201), v51),
                  _mm_mul_ps(_mm_shuffle_ps(v51, v51, 201), v52));
          v54 = _mm_shuffle_ps(v53, v53, 201);
          v87.m_quad = v54;
          v55 = _mm_mul_ps(v54, v54);
          if ( (float)((float)(_mm_shuffle_ps(v55, v55, 85).m128_f32[0] + _mm_shuffle_ps(v55, v55, 0).m128_f32[0])
                     + _mm_shuffle_ps(v55, v55, 170).m128_f32[0]) != 0.0 )
            break;
          if ( v5 >= 2 )
          {
            output->m_distance.m_storage = 0.0;
            v65 = _mm_sub_ps(this->m_simplex.m_storage->m_quad, this->m_simplex.m_storage[1].m_quad);
            v66 = _mm_shuffle_ps(v65, _mm_unpackhi_ps(v65, (__m128)0i64), 196);
            v67 = _mm_shuffle_ps(v66, v66, 241);
            v68 = _mm_shuffle_ps(v66, v66, 206);
            v69 = _mm_mul_ps(v68, v68);
            v70 = _mm_mul_ps(v67, v67);
            v71 = _mm_cmplt_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v70, v70, 85), _mm_shuffle_ps(v70, v70, 0)),
                      _mm_shuffle_ps(v70, v70, 170)),
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v69, v69, 85), _mm_shuffle_ps(v69, v69, 0)),
                      _mm_shuffle_ps(v69, v69, 170)));
            v72 = _mm_xor_ps(
                    _mm_or_ps(_mm_and_ps(v71, v68), _mm_andnot_ps(v71, v67)),
                    (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
            v73 = _mm_mul_ps(v72, v72);
            v74 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v73, v73, 85), _mm_shuffle_ps(v73, v73, 0)),
                    _mm_shuffle_ps(v73, v73, 170));
            v75 = _mm_rsqrt_ps(v74);
            output->m_normalInA.m_quad = _mm_mul_ps(
                                           _mm_andnot_ps(
                                             _mm_cmple_ps(v74, (__m128)0i64),
                                             _mm_mul_ps(
                                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v75, v74), v75)),
                                               _mm_mul_ps(*(__m128 *)_xmm, v75))),
                                           v72);
            v76 = (__m128)_mm_srli_epi32(
                            _mm_slli_epi32(_mm_load_si128((const __m128i *)this->m_simplex.m_storage), 1u),
                            1u);
            v77 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v76, v76, 85), _mm_shuffle_ps(v76, v76, 0)),
                    _mm_shuffle_ps(v76, v76, 170));
            v78 = _mm_add_ps(_mm_add_ps(v77, v77), *(__m128 *)&epsilon);
            v79 = _mm_rcp_ps(v78);
            output->m_pointAinA.m_quad = _mm_add_ps(
                                           _mm_mul_ps(
                                             _mm_sub_ps(
                                               this->m_pointsAinA.m_storage[1].m_quad,
                                               this->m_pointsAinA.m_storage->m_quad),
                                             _mm_mul_ps(
                                               _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v79, v78)), v79),
                                               v77)),
                                           this->m_pointsAinA.m_storage->m_quad);
            *gjkStatus = HK_GSK_OK;
            goto LABEL_35;
          }
LABEL_13:
          this->m_simplexSize.m_storage = 2;
$DO_CASE2:
          v29 = this->m_simplex.m_storage;
          v30 = _mm_sub_ps(v29->m_quad, v29[1].m_quad);
          v31 = _mm_mul_ps(v30, v30);
          if ( (float)((float)(_mm_shuffle_ps(v31, v31, 85).m128_f32[0] + _mm_shuffle_ps(v31, v31, 0).m128_f32[0])
                     + _mm_shuffle_ps(v31, v31, 170).m128_f32[0]) <= v11 )
          {
            if ( v5 < 1 )
            {
              this->m_simplexSize.m_storage = 1;
              goto $DO_CASE1;
            }
            goto LABEL_25;
          }
          v5 = 2;
          v32 = _mm_shuffle_ps(v30, _mm_unpackhi_ps(v30, (__m128)0i64), 196);
          v33 = _mm_shuffle_ps(v32, v32, 241);
          v34 = _mm_shuffle_ps(v32, v32, 206);
          v35 = _mm_mul_ps(v34, v34);
          v36 = _mm_mul_ps(v33, v33);
          v37 = _mm_cmplt_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)),
                    _mm_shuffle_ps(v36, v36, 170)),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)),
                    _mm_shuffle_ps(v35, v35, 170)));
          v38 = _mm_xor_ps(
                  _mm_or_ps(_mm_and_ps(v37, v34), _mm_andnot_ps(v37, v33)),
                  (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
          v39 = _mm_mul_ps(v38, v38);
          v40 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)),
                  _mm_shuffle_ps(v39, v39, 170));
          v41 = _mm_rsqrt_ps(v40);
          v42 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v38, v38, 201), v30),
                  _mm_mul_ps(_mm_shuffle_ps(v30, v30, 201), v38));
          v43 = _mm_shuffle_ps(v42, v42, 201);
          v44 = _mm_mul_ps(v43, v43);
          v92.m_quad = _mm_mul_ps(
                         v38,
                         _mm_andnot_ps(
                           _mm_cmple_ps(v40, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v41, v40), v41)),
                             _mm_mul_ps(v41, *(__m128 *)_xmm))));
          v45 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v44, v44, 85), _mm_shuffle_ps(v44, v44, 0)),
                  _mm_shuffle_ps(v44, v44, 170));
          v46 = _mm_rsqrt_ps(v45);
          v91.m_quad = _mm_mul_ps(
                         v43,
                         _mm_andnot_ps(
                           _mm_cmple_ps(v45, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v46, v45), v46)),
                             _mm_mul_ps(v46, *(__m128 *)_xmm))));
          hkpConvexPenetrationUtil::findBestProjection(
            this,
            &v92,
            v29,
            (hkcdWingedEdge::Vertex *)&resulta[24],
            &bestDistanceOut);
          hkpConvexPenetrationUtil::findBestProjection(
            this,
            &v91,
            this->m_simplex.m_storage,
            (hkcdWingedEdge::Vertex *)resulta,
            &v94);
          v47 = this->m_simplex.m_storage;
          if ( bestDistanceOut.m_real.m128_f32[0] <= v94.m_real.m128_f32[0] )
          {
            v47[2] = *(hkVector4f *)resulta;
            this->m_pointsAinA.m_storage[2] = *(hkcdVertex *)&resulta[16];
            v48.m_quad = *(__m128 *)&resulta[32];
          }
          else
          {
            v47[2] = *(hkVector4f *)&resulta[24];
            this->m_pointsAinA.m_storage[2] = *(hkcdVertex *)&resulta[40];
            v48.m_quad = *(__m128 *)&resulta[56];
          }
          this->m_pointsBinB.m_storage[2] = (hkcdVertex)v48.m_quad;
        }
        v5 = 3;
        v56 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
                _mm_shuffle_ps(v55, v55, 170));
        v57 = _mm_rsqrt_ps(v56);
        v87.m_quad = _mm_mul_ps(
                       v54,
                       _mm_andnot_ps(
                         _mm_cmple_ps(v56, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v57, v56), v57)),
                           _mm_mul_ps(*(__m128 *)_xmm, v57))));
        hkpConvexPenetrationUtil::findBestProjection(this, &v87, v49, (hkcdWingedEdge::Vertex *)&resulta[24], &v88);
        if ( v88.m_real.m128_f32[0] >= _mm_shuffle_ps(this->m_epsTol.m_quad, this->m_epsTol.m_quad, 0).m128_f32[0] )
        {
          this->m_simplex.m_storage[3] = *(hkVector4f *)&resulta[24];
          this->m_pointsAinA.m_storage[3] = *(hkcdVertex *)&resulta[40];
          this->m_pointsBinB.m_storage[3] = *(hkcdVertex *)&resulta[56];
          this->m_simplexSize.m_storage = 4;
          continue;
        }
        output->m_normalInA = (hkVector4f)v87.m_quad;
        output->m_distance.m_storage = 0.0;
        hkcdTriangleUtil::calcBarycentricCoordinates(
          &aabbOut,
          this->m_simplex.m_storage,
          this->m_simplex.m_storage + 1,
          this->m_simplex.m_storage + 2,
          (hkVector4f *)&v88);
        output->m_pointAinA.m_quad = _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(
                                           _mm_shuffle_ps(v88.m_real, v88.m_real, 85),
                                           this->m_pointsAinA.m_storage[1].m_quad),
                                         _mm_mul_ps(
                                           _mm_shuffle_ps(v88.m_real, v88.m_real, 0),
                                           this->m_pointsAinA.m_storage->m_quad)),
                                       _mm_mul_ps(
                                         _mm_shuffle_ps(v88.m_real, v88.m_real, 170),
                                         this->m_pointsAinA.m_storage[2].m_quad));
        *gjkStatus = HK_GSK_OK;
        goto LABEL_35;
      }
      break;
    }
LABEL_25:
    *gjkStatus = HK_GSK_PD_UNSOLVABLE;
LABEL_35:
    result->m_enum = HK_FAILURE;
    return result;
  }
  *gjkStatus = HK_GSK_PD_UNSOLVABLE;
  result->m_enum = HK_FAILURE;
  return result;
}

// File Line: 581
// RVA: 0xDC9D70
float __fastcall rand01(int seed)
{
  return (float)((12345 - 1043968403 * seed) & 0x7FFFFFFF) * 4.6566129e-10;
}

// File Line: 590
// RVA: 0xDC9DA0
void __fastcall randomVector(int seed, hkSimdFloat32 *min, hkSimdFloat32 *max, hkVector4f *vecOut)
{
  unsigned int v4; // xmm0_4
  __m128 *v5; // r8
  __m128 *v6; // rdx
  __m128 *v7; // r9

  *(float *)&v4 = rand01(seed);
  *v7 = _mm_mul_ps(_mm_add_ps(_mm_shuffle_ps((__m128)v4, (__m128)v4, 0), *v6), _mm_sub_ps(*v5, *v6));
}

// File Line: 596
// RVA: 0xDC89A0
__int64 __fastcall hkpConvexPenetrationUtil::calculatePenetrationDepth(
        hkpConvexPenetrationUtil *this,
        hkpGskOut *output)
{
  hkpGskStatus v4; // ebx
  hkcdVertex *m_storage; // rcx
  hkcdVertex *v6; // rax
  hkVector4f *v7; // rdx
  hkVector4f v8; // xmm0
  hkVector4f v9; // xmm1
  hkVector4f v10; // xmm0
  hkVector4f v11; // xmm1
  int v12; // r9d
  float m_distanceToOrigin; // xmm0_4
  hkcdWingedEdge::Triangle *m_triangles; // rcx
  int v15; // edx
  hkcdWingedEdge::Triangle *v16; // rdi
  unsigned int v17; // eax
  unsigned __int64 v18; // r8
  hkcdWingedEdge::Vertex *newVertex; // rbx
  int v21; // ecx
  __m128 v22; // xmm6
  hkResult v23; // [rsp+38h] [rbp-C8h] BYREF
  hkcdWingedEdge we; // [rsp+40h] [rbp-C0h] BYREF
  hkpGskStatus gjkStatus; // [rsp+43A0h] [rbp+42A0h] BYREF
  hkResult result; // [rsp+43A8h] [rbp+42A8h] BYREF

  while ( 1 )
  {
    while ( 1 )
    {
      gjkStatus = HK_GSK_OK;
      hkpConvexPenetrationUtil::builtTetrahedron(this, &result, output, &gjkStatus);
      if ( result.m_enum == HK_FAILURE )
      {
        v4 = gjkStatus;
        if ( gjkStatus != HK_GSK_PD_UNSOLVABLE )
          return (unsigned int)v4;
      }
      else
      {
        m_storage = this->m_pointsBinB.m_storage;
        v6 = this->m_pointsAinA.m_storage;
        v7 = this->m_simplex.m_storage;
        we.m_numVertices.m_storage = 4;
        we.m_vertex[0].m_pointAinA = (hkcdVertex)v6->m_quad;
        we.m_vertex[0].m_pointBinX = (hkcdVertex)m_storage->m_quad;
        v8.m_quad = v7->m_quad;
        we.m_vertex[0].m_referee.m_storage = 0i64;
        we.m_vertex[0].m_position = (hkVector4f)v8.m_quad;
        we.m_vertex[1].m_pointAinA = (hkcdVertex)v6[1].m_quad;
        we.m_vertex[1].m_pointBinX = (hkcdVertex)m_storage[1].m_quad;
        v9.m_quad = (__m128)v7[1];
        we.m_vertex[1].m_referee.m_storage = 0i64;
        we.m_vertex[1].m_position = (hkVector4f)v9.m_quad;
        we.m_vertex[2].m_pointAinA = (hkcdVertex)v6[2].m_quad;
        we.m_vertex[2].m_pointBinX = (hkcdVertex)m_storage[2].m_quad;
        v10.m_quad = (__m128)v7[2];
        we.m_vertex[2].m_referee.m_storage = 0i64;
        we.m_vertex[2].m_position = (hkVector4f)v10.m_quad;
        we.m_vertex[3].m_pointAinA = (hkcdVertex)v6[3].m_quad;
        we.m_vertex[3].m_pointBinX = (hkcdVertex)m_storage[3].m_quad;
        v11.m_quad = (__m128)v7[3];
        we.m_vertex[3].m_referee.m_storage = 0i64;
        we.m_vertex[3].m_position = (hkVector4f)v11.m_quad;
        hkcdWingedEdge::addTetrahedron(&we);
        v12 = we.m_numVertices.m_storage;
        we.m_numFreeTriangle.m_storage = 0;
        while ( 1 )
        {
          m_distanceToOrigin = we.m_triangles[0].m_distanceToOrigin;
          m_triangles = we.m_triangles;
          v15 = we.m_numTriangles.m_storage - 2;
          v16 = we.m_triangles;
          if ( we.m_numTriangles.m_storage - 2 >= 0 )
          {
            v17 = v15 + 1;
            if ( v15 + 1 >= 4 )
            {
              v18 = (unsigned __int64)v17 >> 2;
              v15 -= 4 * (v17 >> 2);
              do
              {
                if ( m_triangles[1].m_distanceToOrigin < m_distanceToOrigin )
                {
                  m_distanceToOrigin = m_triangles[1].m_distanceToOrigin;
                  v16 = m_triangles + 1;
                }
                if ( m_triangles[2].m_distanceToOrigin < m_distanceToOrigin )
                {
                  m_distanceToOrigin = m_triangles[2].m_distanceToOrigin;
                  v16 = m_triangles + 2;
                }
                if ( m_triangles[3].m_distanceToOrigin < m_distanceToOrigin )
                {
                  m_distanceToOrigin = m_triangles[3].m_distanceToOrigin;
                  v16 = m_triangles + 3;
                }
                if ( m_triangles[4].m_distanceToOrigin < m_distanceToOrigin )
                {
                  m_distanceToOrigin = m_triangles[4].m_distanceToOrigin;
                  v16 = m_triangles + 4;
                }
                m_triangles += 4;
                --v18;
              }
              while ( v18 );
            }
            for ( ; v15 >= 0; --v15 )
            {
              ++m_triangles;
              if ( m_triangles->m_distanceToOrigin < m_distanceToOrigin )
              {
                m_distanceToOrigin = m_triangles->m_distanceToOrigin;
                v16 = m_triangles;
              }
            }
          }
          we.m_numVertices.m_storage = v12 + 1;
          newVertex = (hkcdWingedEdge::Vertex *)&we.m_freeTriangle[8 * (__int64)v12 - 440];
          newVertex->m_referee.m_storage = 0i64;
          hkpConvexPenetrationUtil::getPointForSimplex(this, &v16->m_normal, newVertex);
          hkpConvexPenetrationUtil::tryToExpandPolytope(this, &v23, &we, v16, newVertex, &gjkStatus);
          if ( v23.m_enum == HK_FAILURE )
            break;
          v12 = we.m_numVertices.m_storage;
          if ( we.m_numVertices.m_storage >= 55 )
          {
            v4 = HK_GSK_PD_OUT_OF_MEMORY;
LABEL_24:
            hkpConvexPenetrationUtil::convertResultToFeature(this, &we, v16, output);
            return (unsigned int)v4;
          }
        }
        v4 = gjkStatus;
        if ( gjkStatus != HK_GSK_PD_UNSOLVABLE )
          goto LABEL_24;
      }
      v21 = ++this->m_backupTries.m_storage;
      if ( v21 != 1 )
        break;
      this->m_simplexSize.m_storage = 1;
    }
    if ( v21 >= 20 )
      return (unsigned int)v4;
    this->m_simplexSize.m_storage = 0;
    v22 = _mm_shuffle_ps((__m128)0xB8D1B717, (__m128)0xB8D1B717, 0);
    gjkStatus = rand01(v21);
    this->m_aTb.m_translation.m_quad = _mm_add_ps(
                                         _mm_mul_ps(
                                           _mm_add_ps(
                                             _mm_shuffle_ps(
                                               (__m128)(unsigned int)gjkStatus,
                                               (__m128)(unsigned int)gjkStatus,
                                               0),
                                             v22),
                                           _mm_sub_ps(_mm_shuffle_ps((__m128)0x38D1B717u, (__m128)0x38D1B717u, 0), v22)),
                                         this->m_aTb.m_translation.m_quad);
  }
}

// File Line: 697
// RVA: 0xDC8990
void hkpConvexPenetrationUtil::codeEnd(void)
{
  ;
}

// File Line: 704
// RVA: 0xDC81E0
__int64 __fastcall hkCalculatePenetrationDepth(
        hkpConvexShape *shapeA,
        hkpConvexShape *shapeB,
        hkTransformf *btoa,
        float epsTol,
        hkcdVertex *pointsAinA,
        hkcdVertex *pointsBinB,
        hkVector4f *simplex,
        int simplexSize,
        hkpGskOut *output)
{
  _QWORD *Value; // r9
  _QWORD *v13; // rcx
  unsigned __int64 v14; // rax
  _QWORD *v15; // rcx
  hkVector4f v16; // xmm1
  __m128 m_quad; // xmm0
  hkVector4f v18; // xmm1
  hkpGskStatus v19; // ebx
  _QWORD *v20; // r8
  _QWORD *v21; // rcx
  unsigned __int64 v22; // rax
  _QWORD *v23; // rcx
  hkpConvexPenetrationUtil v25; // [rsp+30h] [rbp-B8h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v13 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v13 < Value[3] )
  {
    *v13 = "TtPenetration";
    v14 = __rdtsc();
    v15 = v13 + 2;
    *((_DWORD *)v15 - 2) = v14;
    Value[1] = v15;
  }
  v16.m_quad = (__m128)btoa->m_rotation.m_col1;
  v25.m_aTb.m_rotation.m_col0 = btoa->m_rotation.m_col0;
  m_quad = btoa->m_rotation.m_col2.m_quad;
  v25.m_aTb.m_rotation.m_col1 = (hkVector4f)v16.m_quad;
  v25.m_simplex.m_storage = simplex;
  v18.m_quad = (__m128)btoa->m_translation;
  v25.m_aTb.m_rotation.m_col2.m_quad = m_quad;
  m_quad.m128_f32[0] = epsTol;
  v25.m_shapeA.m_storage = shapeA;
  v25.m_epsTolSqrd.m_storage = epsTol * epsTol;
  v25.m_aTb.m_translation = (hkVector4f)v18.m_quad;
  v25.m_shapeB.m_storage = shapeB;
  v25.m_pointsAinA.m_storage = pointsAinA;
  v25.m_pointsBinB.m_storage = pointsBinB;
  v25.m_epsTol.m_quad = _mm_shuffle_ps(m_quad, m_quad, 0);
  v25.m_backupTries.m_storage = 0;
  v25.m_simplexSize.m_storage = simplexSize;
  v19 = hkpConvexPenetrationUtil::calculatePenetrationDepth(&v25, output);
  if ( v19 == HK_GSK_PD_UNSOLVABLE )
  {
    hkpCvxCvxDistByHeuristicSampling(shapeA, shapeB, btoa, pointsAinA, pointsBinB, output);
    v19 = HK_GSK_PD_HEURISTIC_SAMPLING;
  }
  v20 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v21 = (_QWORD *)v20[1];
  if ( (unsigned __int64)v21 < v20[3] )
  {
    *v21 = "Et";
    v22 = __rdtsc();
    v23 = v21 + 2;
    *((_DWORD *)v23 - 2) = v22;
    v20[1] = v23;
  }
  return (unsigned int)v19;
}

// File Line: 735
// RVA: 0xDC8380
hkResult *__fastcall hkCalcMultiPenetrationDepth(
        hkResult *result,
        hkTransformf *transformA,
        hkpConvexShape *shapeA,
        hkpConvexShape **shapeBs,
        int numShapeBs,
        hkTransformf *aTb,
        hkContactPoint **pointsOut)
{
  hkResult *v7; // rbx
  hkLifoAllocator *Value; // rax
  int v10; // ebp
  __int64 m_cur; // r13
  int v12; // edx
  void *v13; // rcx
  int v14; // r14d
  int v15; // r12d
  _QWORD *v16; // rdi
  signed __int64 v17; // r13
  _QWORD *v18; // rsi
  __int64 v19; // rax
  __int128 v20; // xmm0
  __int128 v21; // xmm1
  __int128 v22; // xmm0
  __int128 v23; // xmm1
  __int64 v24; // r14
  __int64 v25; // rbx
  char v26; // r12
  int v27; // r15d
  __int64 v28; // rbp
  __int64 v29; // rax
  hkVector4f **v30; // r14
  __int64 v31; // rcx
  hkcdWingedEdge::Vertex *v32; // rdi
  hkResult *v33; // rdi
  unsigned int v34; // ecx
  signed int v35; // ebx
  hkLifoAllocator *v36; // rax
  unsigned int m_slotID; // ecx
  signed int v38; // r14d
  hkLifoAllocator *v39; // rax
  int v40; // r8d
  __m128 v42; // xmm1
  __m128 v43; // xmm6
  __m128 v44; // xmm7
  __int64 v45; // rax
  __m128 v46; // xmm3
  unsigned int v47; // ecx
  int v48; // r8d
  hkResult resulta; // [rsp+30h] [rbp-B8h] BYREF
  hkpGskStatus gjkStatus[2]; // [rsp+38h] [rbp-B0h] BYREF
  __int64 v51[2]; // [rsp+40h] [rbp-A8h] BYREF
  hkVector4f directionOut; // [rsp+50h] [rbp-98h] BYREF
  hkpGskOut output; // [rsp+60h] [rbp-88h] BYREF

  v7 = result;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v10 = numShapeBs;
  m_cur = (__int64)Value->m_cur;
  v51[0] = m_cur;
  v12 = (17520 * numShapeBs + 127) & 0xFFFFFF80;
  v13 = (void *)(m_cur + v12);
  if ( v12 > Value->m_slabSize || v13 > Value->m_end )
  {
    m_cur = hkLifoAllocator::allocateFromNewSlab(Value, v12);
    v51[0] = m_cur;
  }
  else
  {
    Value->m_cur = v13;
  }
  v14 = numShapeBs;
  v15 = 0;
  if ( numShapeBs > 0 )
  {
    v16 = (_QWORD *)(m_cur + 344);
    v17 = (char *)pointsOut - (char *)shapeBs;
    do
    {
      v18 = v16 - 43;
      *(v16 - 1) = *shapeBs;
      *v16 = *(hkpConvexShape **)((char *)shapeBs + v17);
      v19 = (__int64)*shapeBs;
      *(hkTransformf *)(v16 - 43) = *aTb;
      *(_OWORD *)(v16 - 35) = *(_OWORD *)_xmm;
      *(v16 - 31) = v19;
      *((_DWORD *)v16 - 60) = 0;
      *(v16 - 29) = v16 - 25;
      *((_DWORD *)v16 - 52) = 0;
      *(v16 - 28) = v16 - 17;
      *(v16 - 32) = shapeA;
      *((_DWORD *)v16 - 66) = 841731190;
      *(v16 - 27) = v16 - 9;
      hkpConvexPenetrationUtil::builtTetrahedron((hkpConvexPenetrationUtil *)(v16 - 43), &resulta, &output, gjkStatus);
      if ( resulta.m_enum == HK_FAILURE )
      {
        --v10;
      }
      else
      {
        v16 += 2190;
        *((_DWORD *)v18 + 90) = 4;
        *((_OWORD *)v18 + 25) = *((_OWORD *)v18 + 9);
        *((_OWORD *)v18 + 26) = *((_OWORD *)v18 + 13);
        v20 = *((_OWORD *)v18 + 17);
        v18[54] = 0i64;
        *((_OWORD *)v18 + 24) = v20;
        *((_OWORD *)v18 + 29) = *((_OWORD *)v18 + 10);
        *((_OWORD *)v18 + 30) = *((_OWORD *)v18 + 14);
        v21 = *((_OWORD *)v18 + 18);
        v18[62] = 0i64;
        *((_OWORD *)v18 + 28) = v21;
        *((_OWORD *)v18 + 33) = *((_OWORD *)v18 + 11);
        *((_OWORD *)v18 + 34) = *((_OWORD *)v18 + 15);
        v22 = *((_OWORD *)v18 + 19);
        v18[70] = 0i64;
        *((_OWORD *)v18 + 32) = v22;
        *((_OWORD *)v18 + 37) = *((_OWORD *)v18 + 12);
        *((_OWORD *)v18 + 38) = *((_OWORD *)v18 + 16);
        v23 = *((_OWORD *)v18 + 20);
        v18[78] = 0i64;
        *((_OWORD *)v18 + 36) = v23;
        hkcdWingedEdge::addTetrahedron((hkcdWingedEdge *)(v18 + 44));
        *((_DWORD *)v18 + 91) = 0;
      }
      ++v15;
      ++shapeBs;
    }
    while ( v15 < v10 );
    m_cur = v51[0];
    v14 = numShapeBs;
    v7 = result;
  }
  if ( v10 <= 2 )
  {
    if ( v10 < 2 )
    {
      m_slotID = hkMemoryRouter::s_memoryRouter.m_slotID;
      v7->m_enum = HK_FAILURE;
      v38 = (17520 * v14 + 127) & 0xFFFFFF80;
      v39 = (hkLifoAllocator *)TlsGetValue(m_slotID);
      v40 = (v38 + 15) & 0xFFFFFFF0;
      if ( v38 > v39->m_slabSize || (void *)(m_cur + v40) != v39->m_cur || v39->m_firstNonLifoEnd == (void *)m_cur )
      {
        hkLifoAllocator::slowBlockFree(v39, (char *)m_cur, v40);
        return v7;
      }
      else
      {
        v39->m_cur = (void *)m_cur;
        return v7;
      }
    }
  }
  else
  {
    v10 = 2;
  }
  v24 = v10;
  v51[0] = 0i64;
  v25 = m_cur + 352;
  *(_QWORD *)gjkStatus = v10;
  do
  {
    hkcdWingedEdge::find2ClosestMultiTriangles(
      (hkcdWingedEdge *)v25,
      (hkcdWingedEdge *)(m_cur + 17872),
      &directionOut,
      (hkcdWingedEdge::Triangle **)(m_cur + 17504),
      (hkcdWingedEdge::Triangle **)(m_cur + 35024));
    v26 = 0;
    v27 = 0;
    v28 = 0i64;
    if ( v24 <= 0 )
      break;
    v29 = *(_QWORD *)gjkStatus;
    v30 = (hkVector4f **)(m_cur + 360);
    do
    {
      if ( *((_DWORD *)v51 + v28) != 2 )
      {
        v31 = *(int *)v30;
        if ( (int)v31 >= 55 )
        {
          v32 = (hkcdWingedEdge::Vertex *)&v30[8 * v31 + 3];
          *(_DWORD *)v30 = v31 + 1;
          v32->m_referee.m_storage = 0i64;
          hkpConvexPenetrationUtil::getPointForSimplex((hkpConvexPenetrationUtil *)(v30 - 45), v30[2143], v32);
          hkpConvexPenetrationUtil::tryToExpandPolytope(
            (hkpConvexPenetrationUtil *)(v30 - 45),
            &resulta,
            (hkcdWingedEdge *)(v30 - 1),
            (hkcdWingedEdge::Triangle *)v30[2143],
            v32,
            (hkpGskStatus *)v51 + v27);
          if ( resulta.m_enum == HK_FAILURE )
          {
            if ( *((_DWORD *)v51 + v28) == 3 )
            {
              v33 = result;
              v34 = hkMemoryRouter::s_memoryRouter.m_slotID;
              result->m_enum = HK_FAILURE;
              v35 = (17520 * numShapeBs + 127) & 0xFFFFFF80;
              v36 = (hkLifoAllocator *)TlsGetValue(v34);
              goto LABEL_35;
            }
          }
          else
          {
            v26 = 1;
          }
          v29 = *(_QWORD *)gjkStatus;
        }
      }
      ++v28;
      ++v27;
      v30 += 2190;
    }
    while ( v28 < v29 );
    v24 = *(_QWORD *)gjkStatus;
    v25 = m_cur + 352;
  }
  while ( v26 );
  v42 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), directionOut.m_quad);
  v43 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v42, v42, 85), transformA->m_rotation.m_col1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v42, v42, 0), transformA->m_rotation.m_col0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v42, v42, 170), transformA->m_rotation.m_col2.m_quad));
  v44 = _mm_sub_ps(
          _mm_sub_ps((__m128)0i64, _mm_shuffle_ps(directionOut.m_quad, directionOut.m_quad, 255)),
          _mm_shuffle_ps((__m128)LODWORD(shapeA->m_radius), (__m128)LODWORD(shapeA->m_radius), 0));
  if ( v24 > 0 )
  {
    do
    {
      hkpConvexPenetrationUtil::convertResultToFeature(
        (hkpConvexPenetrationUtil *)(v25 - 352),
        (hkcdWingedEdge *)v25,
        *(hkcdWingedEdge::Triangle **)(v25 + 17152),
        &output);
      v45 = *(_QWORD *)(v25 - 16);
      v25 += 17520i64;
      v46 = _mm_shuffle_ps((__m128)*(unsigned int *)(v45 + 32), (__m128)*(unsigned int *)(v45 + 32), 0);
      *(__m128 *)*(_QWORD *)(v25 - 17528) = _mm_add_ps(
                                              _mm_add_ps(
                                                _mm_add_ps(
                                                  _mm_mul_ps(
                                                    _mm_shuffle_ps(
                                                      output.m_pointAinA.m_quad,
                                                      output.m_pointAinA.m_quad,
                                                      85),
                                                    transformA->m_rotation.m_col1.m_quad),
                                                  _mm_mul_ps(
                                                    _mm_shuffle_ps(
                                                      output.m_pointAinA.m_quad,
                                                      output.m_pointAinA.m_quad,
                                                      0),
                                                    transformA->m_rotation.m_col0.m_quad)),
                                                _mm_mul_ps(
                                                  _mm_shuffle_ps(
                                                    output.m_pointAinA.m_quad,
                                                    output.m_pointAinA.m_quad,
                                                    170),
                                                  transformA->m_rotation.m_col2.m_quad)),
                                              transformA->m_translation.m_quad);
      *(__m128 *)(*(_QWORD *)(v25 - 17528) + 16i64) = _mm_shuffle_ps(
                                                        v43,
                                                        _mm_unpackhi_ps(v43, _mm_sub_ps(v44, v46)),
                                                        196);
      --v24;
    }
    while ( v24 );
  }
  v33 = result;
  v47 = hkMemoryRouter::s_memoryRouter.m_slotID;
  result->m_enum = HK_SUCCESS;
  v35 = (17520 * numShapeBs + 127) & 0xFFFFFF80;
  v36 = (hkLifoAllocator *)TlsGetValue(v47);
LABEL_35:
  v48 = (v35 + 15) & 0xFFFFFFF0;
  if ( v35 > v36->m_slabSize || (void *)(m_cur + v48) != v36->m_cur || v36->m_firstNonLifoEnd == (void *)m_cur )
    hkLifoAllocator::slowBlockFree(v36, (char *)m_cur, v48);
  else
    v36->m_cur = (void *)m_cur;
  return v33;
}

