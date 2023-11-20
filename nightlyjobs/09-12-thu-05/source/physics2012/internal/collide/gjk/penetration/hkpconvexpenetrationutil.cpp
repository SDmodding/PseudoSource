// File Line: 35
// RVA: 0xDC9C80
void __fastcall hkpConvexPenetrationUtil::findBestProjection(hkpConvexPenetrationUtil *this, hkVector4f *direction, hkVector4f *from, hkcdWingedEdge::Vertex *result, hkSimdFloat32 *bestDistanceOut)
{
  hkVector4f *v5; // rdi
  hkcdWingedEdge::Vertex *v6; // rbp
  hkVector4f *v7; // rsi
  hkpConvexPenetrationUtil *v8; // rbx
  hkVector4f v9; // xmm4
  __m128 v10; // xmm1
  __m128 v11; // xmm3
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  hkcdVertex v14; // xmm0
  hkcdVertex v15; // xmm1
  hkcdWingedEdge::Edge *v16; // rax
  hkVector4f directiona; // [rsp+20h] [rbp-58h]
  hkcdWingedEdge::Vertex resulta; // [rsp+30h] [rbp-48h]

  v5 = from;
  v6 = result;
  v7 = direction;
  v8 = this;
  directiona.m_quad = _mm_xor_ps(
                        (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                        direction->m_quad);
  hkpConvexPenetrationUtil::getPointForSimplex(this, direction, &resulta);
  hkpConvexPenetrationUtil::getPointForSimplex(v8, &directiona, v6);
  v9.m_quad = (__m128)resulta.m_position;
  v10 = _mm_mul_ps(_mm_sub_ps(resulta.m_position.m_quad, v5->m_quad), v7->m_quad);
  v11 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)), _mm_shuffle_ps(v10, v10, 170));
  v12 = _mm_mul_ps(_mm_sub_ps(v6->m_position.m_quad, v5->m_quad), directiona.m_quad);
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  bestDistanceOut->m_real = _mm_max_ps(v11, v13);
  if ( v11.m128_f32[0] >= v13.m128_f32[0] )
  {
    v14.m_quad = (__m128)resulta.m_pointAinA;
    v15.m_quad = (__m128)resulta.m_pointBinX;
    v16 = resulta.m_referee.m_storage;
    v6->m_position = (hkVector4f)v9.m_quad;
    v6->m_pointAinA = (hkcdVertex)v14.m_quad;
    v6->m_pointBinX = (hkcdVertex)v15.m_quad;
    v6->m_referee.m_storage = v16;
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
void __fastcall hkpConvexPenetrationUtil::getPointForSimplex(hkpConvexPenetrationUtil *this, hkVector4f *direction, hkcdWingedEdge::Vertex *result)
{
  hkpConvexPenetrationUtil *v3; // rsi
  hkcdWingedEdge::Vertex *v4; // rbp
  hkVector4f *v5; // rbx
  hkpConvexShape *v6; // rcx
  __m128 v7; // xmm3
  __m128 v8; // xmm1
  __m128 v9; // xmm2
  __m128 v10; // xmm5
  __m128 v11; // xmm1
  __m128 v12; // [rsp+20h] [rbp-18h]

  v3 = this;
  v4 = result;
  v5 = direction;
  ((void (__fastcall *)(hkpConvexShape *, hkVector4f *, hkcdVertex *))this->m_shapeA.m_storage->vfptr[4].__vecDelDtor)(
    this->m_shapeA.m_storage,
    direction,
    &result->m_pointAinA);
  v6 = v3->m_shapeB.m_storage;
  v7 = v3->m_aTb.m_rotation.m_col2.m_quad;
  v8 = _mm_unpacklo_ps(v3->m_aTb.m_rotation.m_col0.m_quad, v3->m_aTb.m_rotation.m_col1.m_quad);
  v9 = _mm_movelh_ps(v8, v7);
  v10 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v5->m_quad);
  v12 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(_mm_movehl_ps(v9, v8), v7, 212)),
            _mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), v9)),
          _mm_mul_ps(
            _mm_shuffle_ps(v10, v10, 170),
            _mm_shuffle_ps(
              _mm_unpackhi_ps(v3->m_aTb.m_rotation.m_col0.m_quad, v3->m_aTb.m_rotation.m_col1.m_quad),
              v7,
              228)));
  ((void (__fastcall *)(hkpConvexShape *, __m128 *, hkcdVertex *))v6->vfptr[4].__vecDelDtor)(v6, &v12, &v4->m_pointBinX);
  v11 = v4->m_pointBinX.m_quad;
  v4->m_position.m_quad = _mm_sub_ps(
                            v4->m_pointAinA.m_quad,
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), v3->m_aTb.m_rotation.m_col0.m_quad),
                                  _mm_mul_ps(
                                    _mm_shuffle_ps(v4->m_pointBinX.m_quad, v11, 85),
                                    v3->m_aTb.m_rotation.m_col1.m_quad)),
                                _mm_mul_ps(_mm_shuffle_ps(v11, v11, 170), v3->m_aTb.m_rotation.m_col2.m_quad)),
                              v3->m_aTb.m_translation.m_quad));
}

// File Line: 283
// RVA: 0xDC9710
hkResult *__fastcall hkpConvexPenetrationUtil::tryToExpandPolytope(hkpConvexPenetrationUtil *this, hkResult *result, hkcdWingedEdge *we, hkcdWingedEdge::Triangle *nearestTriangle, hkcdWingedEdge::Vertex *newVertex, hkpGskStatus *failureReason)
{
  hkcdWingedEdge *v6; // rbx
  hkcdWingedEdge::Vertex *v7; // r8
  hkResult *v8; // r14
  __m128 v9; // xmm6
  __m128 v10; // xmm0
  __m128 v11; // xmm5
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  hkpGskStatus *v14; // rax
  hkcdWingedEdge::Vertex *v16; // rax
  __m128 v17; // xmm1
  __m128 v18; // xmm1
  hkcdWingedEdge::Triangle::TriangleState v19; // eax
  __m128 v20; // xmm1
  float v21; // xmm2_4
  float v22; // xmm2_4
  int v23; // er8
  int v24; // edx
  __int64 v25; // r12
  hkpGskStatus *v26; // rax
  int v27; // eax
  int v28; // ecx
  int v29; // er11
  __int64 v30; // r8
  __int64 *v31; // r9
  hkcdWingedEdge::Triangle **v32; // r10
  __int64 v33; // rax
  __int64 v34; // r9
  __int64 *v35; // r8
  __int64 v36; // rcx
  hkcdWingedEdge::Edge *v37; // rdx
  __int64 v38; // rbp
  hkcdWingedEdge::Edge *v39; // r15
  signed int v40; // er13
  __int64 v41; // r11
  __int64 v42; // rsi
  __m128 *v43; // r8
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
  hkcdWingedEdge::Edge *v55; // rax
  int v56; // eax
  hkcdWingedEdge::Triangle::TriangleState *v57; // rcx
  int v58; // ecx
  hkPadSpu<hkcdWingedEdge::Edge *> *v59; // rax
  hkpGskStatus *v60; // rax
  hkpGskStatus *v61; // rax
  hkcdWingedEdge::Edge *v62; // [rsp+30h] [rbp-378h]
  __int64 v63; // [rsp+40h] [rbp-368h]
  __int64 v64[99]; // [rsp+48h] [rbp-360h]
  hkPadSpu<int> chainLength; // [rsp+3B0h] [rbp+8h]
  hkPadSpu<hkcdWingedEdge::Edge *> edgeChain; // [rsp+3C8h] [rbp+20h]

  v6 = we;
  v7 = newVertex;
  v8 = result;
  v9 = _mm_sub_ps(newVertex->m_position.m_quad, nearestTriangle->m_edge[0].m_vertex->m_position.m_quad);
  v10 = _mm_sub_ps(newVertex->m_position.m_quad, nearestTriangle->m_edge[1].m_vertex->m_position.m_quad);
  v11 = _mm_sub_ps(newVertex->m_position.m_quad, nearestTriangle->m_edge[2].m_vertex->m_position.m_quad);
  v12 = _mm_unpacklo_ps(v9, v10);
  v13 = _mm_movelh_ps(v12, v11);
  if ( _mm_movemask_ps(
         _mm_cmpltps(
           _mm_add_ps(
             _mm_add_ps(
               _mm_mul_ps(
                 _mm_shuffle_ps(_mm_movehl_ps(v13, v12), v11, 212),
                 _mm_shuffle_ps(nearestTriangle->m_normal.m_quad, nearestTriangle->m_normal.m_quad, 85)),
               _mm_mul_ps(_mm_shuffle_ps(nearestTriangle->m_normal.m_quad, nearestTriangle->m_normal.m_quad, 0), v13)),
             _mm_mul_ps(
               _mm_shuffle_ps(_mm_unpackhi_ps(v9, v10), v11, 228),
               _mm_shuffle_ps(nearestTriangle->m_normal.m_quad, nearestTriangle->m_normal.m_quad, 170))),
           this->m_epsTol.m_quad)) & 7 )
  {
    v14 = failureReason;
    result->m_enum = 1;
    *v14 = 0;
    return result;
  }
  v6->m_toleranceBorder.m_storage = 0.0000001;
  v6->m_previousMinimumDistance.m_storage = 3.40282e38;
  v16 = nearestTriangle->m_edge[0].m_vertex;
  v17 = v7->m_position.m_quad;
  edgeChain.m_storage = 0i64;
  chainLength.m_storage = 0;
  v18 = _mm_sub_ps(v17, v16->m_position.m_quad);
  v19 = 1;
  v20 = _mm_mul_ps(v18, nearestTriangle->m_normal.m_quad);
  v21 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 0)))
      + COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 170));
  if ( v21 <= 0.0000001 )
  {
    v22 = v21 + 0.0000001;
    if ( v22 > 0.0000001 )
      v6->m_toleranceBorder.m_storage = v22;
    v19 = 2;
  }
  else if ( v21 < 3.40282e38 )
  {
    v6->m_previousMinimumDistance.m_storage = v21;
  }
  if ( v6->m_previousMinimumDistance.m_storage <= v6->m_toleranceBorder.m_storage )
    v19 = 4;
  nearestTriangle->m_state = v19;
  if ( v19 != 1 || hkcdWingedEdge::findVisibleTriangles(v6, nearestTriangle, &v7->m_position, &chainLength, &edgeChain) )
  {
    v61 = failureReason;
    v8->m_enum = 1;
    *v61 = 3;
    return v8;
  }
  v23 = v6->m_numFreeTriangle.m_storage;
  v24 = v6->m_numTriangles.m_storage;
  v25 = chainLength.m_storage;
  if ( v23 - v24 + 100 >= chainLength.m_storage )
  {
    v27 = v23 - 1;
    v28 = chainLength.m_storage;
    v29 = 0;
    v30 = v23 - 1;
    if ( chainLength.m_storage )
    {
      v31 = &v63;
      v32 = &v6->m_freeTriangle[v27];
      do
      {
        if ( v30 < 0 )
          break;
        v33 = (__int64)*v32;
        --v6->m_numFreeTriangle.m_storage;
        ++v31;
        *(v31 - 1) = v33;
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
      v35 = &v63 + v29;
      do
      {
        v36 = v24++;
        ++v35;
        *(v35 - 1) = (__int64)v6 + 128 * (v36 + 34);
        --v34;
      }
      while ( v34 );
      v6->m_numTriangles.m_storage = v24;
    }
    v37 = edgeChain.m_storage;
    v38 = 0i64;
    v62 = edgeChain.m_storage;
    v39 = edgeChain.m_storage;
    if ( (signed int)v25 <= 0 )
    {
LABEL_32:
      v56 = 0;
      if ( v6->m_numTriangles.m_storage > 0 )
      {
        v57 = &v6->m_triangles[0].m_state;
        do
        {
          *v57 = 0;
          ++v56;
          v57 += 32;
        }
        while ( v56 < v6->m_numTriangles.m_storage );
      }
      v58 = 0;
      if ( v6->m_numVertices.m_storage > 0 )
      {
        v59 = &v6->m_vertex[0].m_referee;
        do
        {
          v59->m_storage = 0i64;
          ++v58;
          v59 += 8;
        }
        while ( v58 < v6->m_numVertices.m_storage );
      }
      if ( v37 == v39 )
      {
        v8->m_enum = 0;
        return v8;
      }
    }
    else
    {
      v40 = 1;
      while ( v39 )
      {
        v41 = *(&v63 + v38);
        v42 = v40 >= (signed int)v25 ? v63 : v64[v38];
        *(_QWORD *)(v41 + 40) = v41;
        *(_QWORD *)(v41 + 72) = v41;
        *(_QWORD *)(v41 + 104) = v41;
        *(_QWORD *)(v41 + 24) = v41 + 48;
        *(_QWORD *)(v41 + 56) = v41 + 80;
        *(_QWORD *)(v41 + 88) = v41 + 16;
        v43 = &v39->m_vertex->m_position.m_quad;
        v44 = (__m128 *)v39->m_next->m_vertex;
        *(_QWORD *)(v41 + 48) = v39->m_vertex;
        v45 = newVertex;
        *(_QWORD *)(v41 + 80) = newVertex;
        *(_QWORD *)(v41 + 16) = v44;
        v39->m_neighbour = (hkcdWingedEdge::Edge *)(v41 + 16);
        *(_QWORD *)(v41 + 32) = v39;
        *(_QWORD *)(v42 + 64) = v41 + 80;
        *(_QWORD *)(v41 + 96) = v42 + 48;
        v46 = _mm_sub_ps(*v44, *v43);
        v47 = _mm_sub_ps(*v43, v45->m_position.m_quad);
        v48 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v47, v47, 201), v46), _mm_mul_ps(_mm_shuffle_ps(v46, v46, 201), v47));
        v49 = _mm_shuffle_ps(v48, v48, 201);
        v50 = _mm_mul_ps(v49, v49);
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v50, v50, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v50, v50, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v50, v50, 170))) <= 0.0 )
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
                  _mm_cmpleps(v51, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v52, v51), v52)),
                    _mm_mul_ps(*(__m128 *)_xmm, v52))));
        v54 = _mm_mul_ps(*v44, v53);
        *(float *)(v41 + 112) = (float)(COERCE_FLOAT(_mm_shuffle_ps(v54, v54, 85))
                                      + COERCE_FLOAT(_mm_shuffle_ps(v54, v54, 0)))
                              + COERCE_FLOAT(_mm_shuffle_ps(v54, v54, 170));
        *(__m128 *)v41 = v53;
        v55 = v39->m_next;
        v39 = v55->m_vertex->m_referee.m_storage;
        v55->m_vertex->m_referee.m_storage = 0i64;
        if ( v38 >= v25 )
        {
          v37 = v62;
          goto LABEL_32;
        }
      }
    }
    v60 = failureReason;
    v8->m_enum = 1;
    *v60 = 3;
  }
  else
  {
    v26 = failureReason;
    v8->m_enum = 1;
    *v26 = 2;
  }
  return v8;
}

// File Line: 341
// RVA: 0xDC9580
void __fastcall hkpConvexPenetrationUtil::convertResultToFeature(hkpConvexPenetrationUtil *this, hkcdWingedEdge *polytope, hkcdWingedEdge::Triangle *nearestTriangle, hkpGskOut *output)
{
  __m128 *v4; // r14
  hkcdWingedEdge::Triangle *v5; // rbx
  hkcdWingedEdge *v6; // rbp
  hkpConvexPenetrationUtil *v7; // rsi
  signed int v8; // edi
  hkcdWingedEdge::Vertex *v9; // rcx
  hkcdWingedEdge::Vertex *v10; // rcx
  hkcdWingedEdge::Vertex *v11; // rcx
  __m128 v12; // xmm1
  __m128 *v13; // rax
  hkVector4f result; // [rsp+30h] [rbp-28h]

  v4 = &output->m_normalInA.m_quad;
  v5 = nearestTriangle;
  v6 = polytope;
  v7 = this;
  v8 = 0;
  do
  {
    *v7->m_simplex.m_storage = v5->m_edge[0].m_vertex->m_position;
    v7->m_simplex.m_storage[1] = v5->m_edge[1].m_vertex->m_position;
    v7->m_simplex.m_storage[2] = v5->m_edge[2].m_vertex->m_position;
    hkcdTriangleUtil::calcBarycentricCoordinates(
      &aabbOut,
      v7->m_simplex.m_storage,
      v7->m_simplex.m_storage + 1,
      v7->m_simplex.m_storage + 2,
      &result);
    if ( !(_mm_movemask_ps(_mm_cmpltps(result.m_quad, (__m128)0i64)) & 7) )
      break;
    ++v8;
    v5 = hkcdWingedEdge::findTriangleNearestOrigin(v6, v5);
  }
  while ( v8 < 10 );
  v9 = v5->m_edge[0].m_vertex;
  *v7->m_pointsAinA.m_storage = v9->m_pointAinA;
  *v7->m_pointsBinB.m_storage = v9->m_pointBinX;
  v10 = v5->m_edge[1].m_vertex;
  v7->m_pointsAinA.m_storage[1] = v10->m_pointAinA;
  v7->m_pointsBinB.m_storage[1] = v10->m_pointBinX;
  v11 = v5->m_edge[2].m_vertex;
  v7->m_pointsAinA.m_storage[2] = v11->m_pointAinA;
  v7->m_pointsBinB.m_storage[2] = v11->m_pointBinX;
  v12 = result.m_quad;
  v13 = &v7->m_pointsAinA.m_storage->m_quad;
  v7->m_simplexSize.m_storage = 3;
  v4[1] = _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v12, v12, 85), v13[1]), _mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), *v13)),
            _mm_mul_ps(_mm_shuffle_ps(v12, v12, 170), v13[2]));
  v4[2].m128_i32[0] = LODWORD(v5->m_distanceToOrigin) ^ _xmm[0];
  *v4 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v5->m_normal.m_quad);
}

// File Line: 406
// RVA: 0xDC8CB0
hkResult *__fastcall hkpConvexPenetrationUtil::builtTetrahedron(hkpConvexPenetrationUtil *this, hkResult *result, hkpGskOut *output, hkpGskStatus *gjkStatus)
{
  hkpConvexPenetrationUtil *v4; // rbx
  signed int v5; // edi
  hkpGskStatus *v6; // r15
  hkpGskOut *v7; // r13
  hkResult *v8; // r14
  __m128 v9; // xmm11
  int v10; // ecx
  float v11; // xmm11_4
  int v12; // ecx
  int v13; // ecx
  int v14; // ecx
  __m128 v15; // xmm2
  __m128 v16; // xmm6
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 *v19; // rax
  __m128 v20; // xmm1
  __m128 v21; // xmm4
  __m128 *v22; // rsi
  __m128 v23; // xmm2
  __m128 v24; // xmm6
  __m128 v25; // xmm6
  hkcdVertex *v26; // rax
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
  __m128 v37; // xmm2
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
  __m128 v71; // xmm2
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
  hkcdVertex v83; // xmm1
  __m128 v84; // xmm2
  __m128 v85; // xmm0
  hkVector4f v87; // [rsp+30h] [rbp-A8h]
  hkSimdFloat32 v88; // [rsp+40h] [rbp-98h]
  hkcdWingedEdge::Vertex resulta; // [rsp+50h] [rbp-88h]
  hkVector4f direction; // [rsp+A8h] [rbp-30h]
  hkVector4f v91; // [rsp+B8h] [rbp-20h]
  hkVector4f v92; // [rsp+C8h] [rbp-10h]
  hkVector4f v93; // [rsp+D8h] [rbp+0h]
  hkSimdFloat32 v94; // [rsp+E8h] [rbp+10h]
  hkSimdFloat32 bestDistanceOut; // [rsp+F8h] [rbp+20h]

  v4 = this;
  v5 = -1;
  v6 = gjkStatus;
  v7 = output;
  v8 = result;
  v9 = (__m128)LODWORD(this->m_epsTolSqrd.m_storage);
  v10 = this->m_simplexSize.m_storage;
  LODWORD(v11) = (unsigned __int128)_mm_shuffle_ps(v9, v9, 0);
  if ( !v10 )
    goto $DO_CASE0;
  v12 = v10 - 1;
  if ( !v12 )
  {
    while ( 1 )
    {
$DO_CASE1:
      v22 = &v4->m_simplex.m_storage->m_quad;
      v23 = _mm_mul_ps(*v22, *v22);
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 170))) > v11 )
      {
        v5 = 1;
        hkpConvexPenetrationUtil::getPointForSimplex(v4, v4->m_simplex.m_storage, &resulta);
        v24 = _mm_sub_ps(resulta.m_position.m_quad, v4->m_simplex.m_storage->m_quad);
        v25 = _mm_mul_ps(v24, v24);
        v93.m_quad = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), *v22);
        hkpConvexPenetrationUtil::getPointForSimplex(v4, &v93, (hkcdWingedEdge::Vertex *)((char *)&resulta + 24));
        v26 = (hkcdVertex *)v4->m_simplex.m_storage;
        v27 = _mm_sub_ps(*(__m128 *)((char *)&resulta.m_pointAinA.m_quad + 8), v26->m_quad);
        v28 = _mm_mul_ps(v27, v27);
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v25, v25, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v25, v25, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v25, v25, 170))) < (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v28, v28, 85))
                                                                                  + COERCE_FLOAT(_mm_shuffle_ps(v28, v28, 0)))
                                                                          + COERCE_FLOAT(_mm_shuffle_ps(v28, v28, 170))) )
        {
          v26[1] = *(hkcdVertex *)((char *)&resulta.m_pointAinA + 8);
          v4->m_pointsAinA.m_storage[1] = *(hkcdVertex *)((char *)&resulta.m_pointBinX + 8);
          v4->m_pointsBinB.m_storage[1] = *(hkcdVertex *)(&resulta.m_referee + 1);
        }
        else
        {
          v26[1] = (hkcdVertex)resulta.m_position;
          v4->m_pointsAinA.m_storage[1] = resulta.m_pointAinA;
          v4->m_pointsBinB.m_storage[1] = resulta.m_pointBinX;
        }
        goto LABEL_13;
      }
      if ( v5 >= 0 )
        goto LABEL_25;
      v4->m_simplexSize.m_storage = 0;
$DO_CASE0:
      v15 = v4->m_aTb.m_translation.m_quad;
      v16 = _mm_shuffle_ps((__m128)LODWORD(v4->m_epsTolSqrd.m_storage), (__m128)LODWORD(v4->m_epsTolSqrd.m_storage), 0);
      v17 = _mm_mul_ps(v15, v15);
      v18 = _mm_cmpleps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
                _mm_shuffle_ps(v17, v17, 170)),
              v16);
      direction.m_quad = _mm_or_ps(
                           _mm_andnot_ps(
                             v18,
                             _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v15)),
                           _mm_and_ps(v18, ::direction.m_quad));
      hkpConvexPenetrationUtil::getPointForSimplex(v4, &direction, &resulta);
      *v4->m_simplex.m_storage = resulta.m_position;
      *v4->m_pointsAinA.m_storage = resulta.m_pointAinA;
      *v4->m_pointsBinB.m_storage = resulta.m_pointBinX;
      v19 = &v4->m_simplex.m_storage->m_quad;
      v4->m_simplexSize.m_storage = 1;
      v20 = _mm_mul_ps(*v19, *v19);
      v21 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
              _mm_shuffle_ps(v20, v20, 170));
      if ( v21.m128_f32[0] <= v16.m128_f32[0] )
      {
        v80 = _mm_rsqrt_ps(v21);
        v81 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v80, v21), v80));
        v82 = _mm_mul_ps(*(__m128 *)_xmm, v80);
        v83.m_quad = (__m128)resulta.m_pointAinA;
        v84 = _mm_mul_ps(v81, v82);
        v85 = direction.m_quad;
        LODWORD(v7->m_distance.m_storage) = (unsigned __int128)_mm_andnot_ps(
                                                                 _mm_cmpleps(v21, (__m128)0i64),
                                                                 _mm_mul_ps(v84, v21));
        v7->m_normalInA.m_quad = v85;
        v7->m_pointAinA = (hkVector4f)v83.m_quad;
        *v6 = 0;
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
      v58 = v4->m_simplex.m_storage;
      v59 = v58[1].m_quad;
      v60 = _mm_sub_ps(v58->m_quad, v59);
      v61 = _mm_sub_ps(v59, v58[2].m_quad);
      v62 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v61, v61, 201), v60), _mm_mul_ps(_mm_shuffle_ps(v60, v60, 201), v61));
      v87.m_quad = _mm_shuffle_ps(v62, v62, 201);
      v63 = _mm_mul_ps(v87.m_quad, v87.m_quad);
      v64 = _mm_mul_ps(_mm_sub_ps(v58[3].m_quad, v58->m_quad), v87.m_quad);
      v62.m128_f32[0] = (float)(COERCE_FLOAT(_mm_shuffle_ps(v64, v64, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v64, v64, 0)))
                      + COERCE_FLOAT(_mm_shuffle_ps(v64, v64, 170));
      if ( (float)(v62.m128_f32[0] * v62.m128_f32[0]) > (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v63, v63, 85))
                                                                              + COERCE_FLOAT(_mm_shuffle_ps(v63, v63, 0)))
                                                                      + COERCE_FLOAT(_mm_shuffle_ps(v63, v63, 170)))
                                                              * v11) )
      {
        *v6 = 0;
        v8->m_enum = 0;
        return v8;
      }
      if ( v5 < 3 )
      {
        while ( 1 )
        {
          v4->m_simplexSize.m_storage = 3;
$DO_CASE3:
          v49 = v4->m_simplex.m_storage;
          v50 = v49[1].m_quad;
          v51 = _mm_sub_ps(v49->m_quad, v50);
          v52 = _mm_sub_ps(v50, v49[2].m_quad);
          v53 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v52, v52, 201), v51),
                  _mm_mul_ps(_mm_shuffle_ps(v51, v51, 201), v52));
          v54 = _mm_shuffle_ps(v53, v53, 201);
          v87.m_quad = v54;
          v55 = _mm_mul_ps(v54, v54);
          if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v55, v55, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v55, v55, 0)))
                     + COERCE_FLOAT(_mm_shuffle_ps(v55, v55, 170))) != 0.0 )
            break;
          if ( v5 >= 2 )
          {
            v7->m_distance.m_storage = 0.0;
            v65 = _mm_sub_ps(v4->m_simplex.m_storage->m_quad, v4->m_simplex.m_storage[1].m_quad);
            v66 = _mm_shuffle_ps(v65, _mm_unpackhi_ps(v65, (__m128)0i64), 196);
            v67 = _mm_shuffle_ps(v66, v66, 241);
            v68 = _mm_shuffle_ps(v66, v66, 206);
            v69 = _mm_mul_ps(v68, v68);
            v70 = _mm_mul_ps(v67, v67);
            v71 = _mm_cmpltps(
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
            v7->m_normalInA.m_quad = _mm_mul_ps(
                                       _mm_andnot_ps(
                                         _mm_cmpleps(v74, (__m128)0i64),
                                         _mm_mul_ps(
                                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v75, v74), v75)),
                                           _mm_mul_ps(*(__m128 *)_xmm, v75))),
                                       v72);
            v76 = (__m128)_mm_srli_epi32(
                            _mm_slli_epi32(_mm_load_si128((const __m128i *)v4->m_simplex.m_storage), 1u),
                            1u);
            v77 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v76, v76, 85), _mm_shuffle_ps(v76, v76, 0)),
                    _mm_shuffle_ps(v76, v76, 170));
            v78 = _mm_add_ps(_mm_add_ps(v77, v77), *(__m128 *)&epsilon);
            v79 = _mm_rcp_ps(v78);
            v7->m_pointAinA.m_quad = _mm_add_ps(
                                       _mm_mul_ps(
                                         _mm_sub_ps(
                                           v4->m_pointsAinA.m_storage[1].m_quad,
                                           v4->m_pointsAinA.m_storage->m_quad),
                                         _mm_mul_ps(
                                           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v79, v78)), v79),
                                           v77)),
                                       v4->m_pointsAinA.m_storage->m_quad);
            *v6 = 0;
            goto LABEL_35;
          }
LABEL_13:
          v4->m_simplexSize.m_storage = 2;
$DO_CASE2:
          v29 = v4->m_simplex.m_storage;
          v30 = _mm_sub_ps(v29->m_quad, v29[1].m_quad);
          v31 = _mm_mul_ps(v30, v30);
          if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v31, v31, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v31, v31, 0)))
                     + COERCE_FLOAT(_mm_shuffle_ps(v31, v31, 170))) <= v11 )
          {
            if ( v5 < 1 )
            {
              v4->m_simplexSize.m_storage = 1;
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
          v37 = _mm_cmpltps(
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
                           _mm_cmpleps(v40, (__m128)0i64),
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
                           _mm_cmpleps(v45, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v46, v45), v46)),
                             _mm_mul_ps(v46, *(__m128 *)_xmm))));
          hkpConvexPenetrationUtil::findBestProjection(
            v4,
            &v92,
            v29,
            (hkcdWingedEdge::Vertex *)((char *)&resulta + 24),
            &bestDistanceOut);
          hkpConvexPenetrationUtil::findBestProjection(v4, &v91, v4->m_simplex.m_storage, &resulta, &v94);
          v47 = v4->m_simplex.m_storage;
          if ( bestDistanceOut.m_real.m128_f32[0] <= v94.m_real.m128_f32[0] )
          {
            v47[2] = resulta.m_position;
            v4->m_pointsAinA.m_storage[2] = resulta.m_pointAinA;
            v48.m_quad = (__m128)resulta.m_pointBinX;
          }
          else
          {
            v47[2] = *(hkVector4f *)((char *)&resulta.m_pointAinA.0 + 8);
            v4->m_pointsAinA.m_storage[2] = *(hkcdVertex *)((char *)&resulta.m_pointBinX + 8);
            v48.m_quad = *(__m128 *)(&resulta.m_referee + 1);
          }
          v4->m_pointsBinB.m_storage[2] = (hkcdVertex)v48.m_quad;
        }
        v5 = 3;
        v56 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
                _mm_shuffle_ps(v55, v55, 170));
        v57 = _mm_rsqrt_ps(v56);
        v87.m_quad = _mm_mul_ps(
                       v54,
                       _mm_andnot_ps(
                         _mm_cmpleps(v56, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v57, v56), v57)),
                           _mm_mul_ps(*(__m128 *)_xmm, v57))));
        hkpConvexPenetrationUtil::findBestProjection(
          v4,
          &v87,
          v49,
          (hkcdWingedEdge::Vertex *)((char *)&resulta + 24),
          &v88);
        if ( v88.m_real.m128_f32[0] >= COERCE_FLOAT(_mm_shuffle_ps(v4->m_epsTol.m_quad, v4->m_epsTol.m_quad, 0)) )
        {
          v4->m_simplex.m_storage[3] = *(hkVector4f *)((char *)&resulta.m_pointAinA + 8);
          v4->m_pointsAinA.m_storage[3] = *(hkcdVertex *)((char *)&resulta.m_pointBinX + 8);
          v4->m_pointsBinB.m_storage[3] = *(hkcdVertex *)(&resulta.m_referee + 1);
          v4->m_simplexSize.m_storage = 4;
          continue;
        }
        v7->m_normalInA = (hkVector4f)v87.m_quad;
        v7->m_distance.m_storage = 0.0;
        hkcdTriangleUtil::calcBarycentricCoordinates(
          &aabbOut,
          v4->m_simplex.m_storage,
          v4->m_simplex.m_storage + 1,
          v4->m_simplex.m_storage + 2,
          (hkVector4f *)&v88);
        v7->m_pointAinA.m_quad = _mm_add_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(
                                       _mm_shuffle_ps(v88.m_real, v88.m_real, 85),
                                       v4->m_pointsAinA.m_storage[1].m_quad),
                                     _mm_mul_ps(
                                       _mm_shuffle_ps(v88.m_real, v88.m_real, 0),
                                       v4->m_pointsAinA.m_storage->m_quad)),
                                   _mm_mul_ps(
                                     _mm_shuffle_ps(v88.m_real, v88.m_real, 170),
                                     v4->m_pointsAinA.m_storage[2].m_quad));
        *v6 = 0;
        goto LABEL_35;
      }
      break;
    }
LABEL_25:
    *v6 = 3;
LABEL_35:
    v8->m_enum = 1;
    return v8;
  }
  *gjkStatus = 3;
  result->m_enum = 1;
  return v8;
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
__int64 __fastcall hkpConvexPenetrationUtil::calculatePenetrationDepth(hkpConvexPenetrationUtil *this, hkpGskOut *output)
{
  hkpGskOut *v2; // r14
  hkpConvexPenetrationUtil *i; // rsi
  hkpGskStatus v4; // ebx
  hkcdVertex *v5; // rcx
  hkcdVertex *v6; // rax
  hkVector4f *v7; // rdx
  hkVector4f v8; // xmm0
  hkVector4f v9; // xmm1
  hkVector4f v10; // xmm0
  hkVector4f v11; // xmm1
  int v12; // er9
  float v13; // xmm0_4
  float *v14; // rcx
  int v15; // edx
  hkcdWingedEdge::Triangle *v16; // rdi
  unsigned int v17; // eax
  unsigned __int64 v18; // r8
  hkcdWingedEdge::Vertex *newVertex; // rbx
  int v21; // ecx
  __m128 v22; // xmm6
  hkResult v23; // [rsp+38h] [rbp-C8h]
  hkcdWingedEdge we; // [rsp+40h] [rbp-C0h]
  hkpGskStatus gjkStatus; // [rsp+43A0h] [rbp+42A0h]
  hkResult result; // [rsp+43A8h] [rbp+42A8h]

  v2 = output;
  for ( i = this;
        ;
        i->m_aTb.m_translation.m_quad = _mm_add_ps(
                                          _mm_mul_ps(
                                            _mm_add_ps(
                                              _mm_shuffle_ps(
                                                (__m128)(unsigned int)gjkStatus,
                                                (__m128)(unsigned int)gjkStatus,
                                                0),
                                              v22),
                                            _mm_sub_ps(_mm_shuffle_ps((__m128)0x38D1B717u, (__m128)0x38D1B717u, 0), v22)),
                                          i->m_aTb.m_translation.m_quad) )
  {
    while ( 1 )
    {
      gjkStatus = 0;
      hkpConvexPenetrationUtil::builtTetrahedron(i, &result, v2, &gjkStatus);
      if ( result.m_enum == 1 )
      {
        v4 = gjkStatus;
        if ( gjkStatus != 3 )
          return (unsigned int)v4;
      }
      else
      {
        v5 = i->m_pointsBinB.m_storage;
        v6 = i->m_pointsAinA.m_storage;
        v7 = i->m_simplex.m_storage;
        we.m_numVertices.m_storage = 4;
        we.m_vertex[0].m_pointAinA = (hkcdVertex)v6->m_quad;
        we.m_vertex[0].m_pointBinX = (hkcdVertex)v5->m_quad;
        v8.m_quad = v7->m_quad;
        we.m_vertex[0].m_referee.m_storage = 0i64;
        we.m_vertex[0].m_position = (hkVector4f)v8.m_quad;
        we.m_vertex[1].m_pointAinA = (hkcdVertex)v6[1].m_quad;
        we.m_vertex[1].m_pointBinX = (hkcdVertex)v5[1].m_quad;
        v9.m_quad = (__m128)v7[1];
        we.m_vertex[1].m_referee.m_storage = 0i64;
        we.m_vertex[1].m_position = (hkVector4f)v9.m_quad;
        we.m_vertex[2].m_pointAinA = (hkcdVertex)v6[2].m_quad;
        we.m_vertex[2].m_pointBinX = (hkcdVertex)v5[2].m_quad;
        v10.m_quad = (__m128)v7[2];
        we.m_vertex[2].m_referee.m_storage = 0i64;
        we.m_vertex[2].m_position = (hkVector4f)v10.m_quad;
        we.m_vertex[3].m_pointAinA = (hkcdVertex)v6[3].m_quad;
        we.m_vertex[3].m_pointBinX = (hkcdVertex)v5[3].m_quad;
        v11.m_quad = (__m128)v7[3];
        we.m_vertex[3].m_referee.m_storage = 0i64;
        we.m_vertex[3].m_position = (hkVector4f)v11.m_quad;
        hkcdWingedEdge::addTetrahedron(&we);
        v12 = we.m_numVertices.m_storage;
        we.m_numFreeTriangle.m_storage = 0;
        while ( 1 )
        {
          v13 = we.m_triangles[0].m_distanceToOrigin;
          v14 = (float *)we.m_triangles;
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
                if ( v14[60] < v13 )
                {
                  v13 = v14[60];
                  v16 = (hkcdWingedEdge::Triangle *)(v14 + 32);
                }
                if ( v14[92] < v13 )
                {
                  v13 = v14[92];
                  v16 = (hkcdWingedEdge::Triangle *)(v14 + 64);
                }
                if ( v14[124] < v13 )
                {
                  v13 = v14[124];
                  v16 = (hkcdWingedEdge::Triangle *)(v14 + 96);
                }
                if ( v14[156] < v13 )
                {
                  v13 = v14[156];
                  v16 = (hkcdWingedEdge::Triangle *)(v14 + 128);
                }
                v14 += 128;
                --v18;
              }
              while ( v18 );
            }
            for ( ; v15 >= 0; --v15 )
            {
              v14 += 32;
              if ( v14[28] < v13 )
              {
                v13 = v14[28];
                v16 = (hkcdWingedEdge::Triangle *)v14;
              }
            }
          }
          we.m_numVertices.m_storage = v12 + 1;
          newVertex = &we.m_vertex[(signed __int64)v12];
          newVertex->m_referee.m_storage = 0i64;
          hkpConvexPenetrationUtil::getPointForSimplex(i, &v16->m_normal, newVertex);
          hkpConvexPenetrationUtil::tryToExpandPolytope(i, &v23, &we, v16, newVertex, &gjkStatus);
          if ( v23.m_enum == 1 )
            break;
          v12 = we.m_numVertices.m_storage;
          if ( we.m_numVertices.m_storage >= 55 )
          {
            v4 = 2;
LABEL_25:
            hkpConvexPenetrationUtil::convertResultToFeature(i, &we, v16, v2);
            return (unsigned int)v4;
          }
        }
        v4 = gjkStatus;
        if ( gjkStatus != 3 )
          goto LABEL_25;
      }
      v21 = ++i->m_backupTries.m_storage;
      if ( v21 != 1 )
        break;
      i->m_simplexSize.m_storage = 1;
    }
    if ( v21 >= 20 )
      break;
    i->m_simplexSize.m_storage = 0;
    v22 = _mm_shuffle_ps((__m128)0xB8D1B717, (__m128)0xB8D1B717, 0);
    gjkStatus = rand01(v21);
  }
  return (unsigned int)v4;
}

// File Line: 697
// RVA: 0xDC8990
void hkpConvexPenetrationUtil::codeEnd(void)
{
  ;
}

// File Line: 704
// RVA: 0xDC81E0
__int64 __fastcall hkCalculatePenetrationDepth(hkpConvexShape *shapeA, hkpConvexShape *shapeB, hkTransformf *btoa, float epsTol, hkcdVertex *pointsAinA, hkcdVertex *pointsBinB, hkVector4f *simplex, int simplexSize, hkpGskOut *output)
{
  hkpConvexShape *v9; // rbp
  hkTransformf *v10; // rdi
  hkpConvexShape *v11; // rsi
  _QWORD *v12; // r9
  _QWORD *v13; // rcx
  unsigned __int64 v14; // rax
  signed __int64 v15; // rcx
  hkVector4f v16; // xmm1
  hkVector4f v17; // xmm0
  hkVector4f v18; // xmm1
  hkpGskStatus v19; // ebx
  _QWORD *v20; // r8
  _QWORD *v21; // rcx
  unsigned __int64 v22; // rax
  signed __int64 v23; // rcx
  hkpConvexPenetrationUtil v25; // [rsp+30h] [rbp-B8h]

  v9 = shapeA;
  v10 = btoa;
  v11 = shapeB;
  v12 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v13 = (_QWORD *)v12[1];
  if ( (unsigned __int64)v13 < v12[3] )
  {
    *v13 = "TtPenetration";
    v14 = __rdtsc();
    v15 = (signed __int64)(v13 + 2);
    *(_DWORD *)(v15 - 8) = v14;
    v12[1] = v15;
  }
  v16.m_quad = (__m128)v10->m_rotation.m_col1;
  v25.m_aTb.m_rotation.m_col0 = v10->m_rotation.m_col0;
  v17.m_quad = (__m128)v10->m_rotation.m_col2;
  v25.m_aTb.m_rotation.m_col1 = (hkVector4f)v16.m_quad;
  v25.m_simplex.m_storage = simplex;
  v18.m_quad = (__m128)v10->m_translation;
  v25.m_aTb.m_rotation.m_col2 = (hkVector4f)v17.m_quad;
  v17.m_quad.m128_f32[0] = epsTol;
  v25.m_shapeA.m_storage = v9;
  v25.m_epsTolSqrd.m_storage = epsTol * epsTol;
  v25.m_aTb.m_translation = (hkVector4f)v18.m_quad;
  v25.m_shapeB.m_storage = v11;
  v25.m_pointsAinA.m_storage = pointsAinA;
  v25.m_pointsBinB.m_storage = pointsBinB;
  v25.m_epsTol.m_quad = _mm_shuffle_ps(v17.m_quad, v17.m_quad, 0);
  v25.m_backupTries.m_storage = 0;
  v25.m_simplexSize.m_storage = simplexSize;
  v19 = hkpConvexPenetrationUtil::calculatePenetrationDepth(&v25, output);
  if ( v19 == 3 )
  {
    hkpCvxCvxDistByHeuristicSampling(v9, v11, v10, pointsAinA, pointsBinB, output);
    v19 = 1;
  }
  v20 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v21 = (_QWORD *)v20[1];
  if ( (unsigned __int64)v21 < v20[3] )
  {
    *v21 = "Et";
    v22 = __rdtsc();
    v23 = (signed __int64)(v21 + 2);
    *(_DWORD *)(v23 - 8) = v22;
    v20[1] = v23;
  }
  return (unsigned int)v19;
}

// File Line: 735
// RVA: 0xDC8380
hkResult *__fastcall hkCalcMultiPenetrationDepth(hkResult *result, hkTransformf *transformA, hkpConvexShape *shapeA, hkpConvexShape **shapeBs, int numShapeBs, hkTransformf *aTb, hkContactPoint **pointsOut)
{
  hkResult *v7; // rbx
  hkpConvexShape **v8; // r15
  hkLifoAllocator *v9; // rax
  int v10; // ebp
  char *v11; // r13
  int v12; // edx
  char *v13; // rcx
  int v14; // er14
  int v15; // er12
  _QWORD *v16; // rdi
  char *v17; // r13
  signed __int64 v18; // rsi
  hkpConvexShape *v19; // rax
  signed __int64 v20; // rbx
  __int128 v21; // xmm0
  __int128 v22; // xmm1
  __int128 v23; // xmm0
  __int128 v24; // xmm1
  __int64 v25; // r14
  signed __int64 v26; // rbx
  char v27; // r12
  int v28; // er15
  __int64 v29; // rbp
  __int64 v30; // rax
  hkVector4f **v31; // r14
  __int64 v32; // rcx
  hkcdWingedEdge::Vertex *v33; // rdi
  hkResult *v34; // rdi
  unsigned int v35; // ecx
  signed int v36; // ebx
  hkLifoAllocator *v37; // rax
  unsigned int v38; // ecx
  signed int v39; // er14
  hkLifoAllocator *v40; // rax
  int v41; // er8
  hkResult *v42; // rax
  __m128 v43; // xmm1
  __m128 v44; // xmm6
  __m128 v45; // xmm7
  __int64 v46; // rax
  __m128 v47; // xmm3
  unsigned int v48; // ecx
  int v49; // er8
  hkResult resulta; // [rsp+30h] [rbp-B8h]
  hkpGskStatus gjkStatus[2]; // [rsp+38h] [rbp-B0h]
  char *v52; // [rsp+40h] [rbp-A8h]
  hkVector4f directionOut; // [rsp+50h] [rbp-98h]
  hkpGskOut output; // [rsp+60h] [rbp-88h]
  hkResult *v55; // [rsp+F0h] [rbp+8h]
  hkTransformf *v56; // [rsp+F8h] [rbp+10h]
  hkpConvexShape *v57; // [rsp+100h] [rbp+18h]

  v57 = shapeA;
  v56 = transformA;
  v55 = result;
  v7 = result;
  v8 = shapeBs;
  v9 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v10 = numShapeBs;
  v11 = (char *)v9->m_cur;
  v52 = v11;
  v12 = (17520 * numShapeBs + 127) & 0xFFFFFF80;
  v13 = &v11[v12];
  if ( v12 > v9->m_slabSize || v13 > v9->m_end )
  {
    v11 = (char *)hkLifoAllocator::allocateFromNewSlab(v9, v12);
    v52 = v11;
  }
  else
  {
    v9->m_cur = v13;
  }
  v14 = numShapeBs;
  v15 = 0;
  if ( numShapeBs > 0 )
  {
    v16 = v11 + 344;
    v17 = (char *)((char *)pointsOut - (char *)v8);
    do
    {
      v18 = (signed __int64)(v16 - 43);
      *(v16 - 1) = *v8;
      *v16 = *(_QWORD *)&v17[(_QWORD)v8];
      v19 = *v8;
      *(hkVector4f *)(v16 - 43) = aTb->m_rotation.m_col0;
      *(hkVector4f *)(v16 - 41) = aTb->m_rotation.m_col1;
      *(hkVector4f *)(v16 - 39) = aTb->m_rotation.m_col2;
      *(hkVector4f *)(v16 - 37) = aTb->m_translation;
      *(_OWORD *)(v16 - 35) = *(_OWORD *)_xmm;
      *(v16 - 31) = v19;
      *((_DWORD *)v16 - 60) = 0;
      *(v16 - 29) = v16 - 25;
      *((_DWORD *)v16 - 52) = 0;
      *(v16 - 28) = v16 - 17;
      *(v16 - 32) = v57;
      *((_DWORD *)v16 - 66) = 841731190;
      *(v16 - 27) = v16 - 9;
      hkpConvexPenetrationUtil::builtTetrahedron((hkpConvexPenetrationUtil *)(v16 - 43), &resulta, &output, gjkStatus);
      if ( resulta.m_enum == 1 )
      {
        --v10;
      }
      else
      {
        v20 = v18 + 352;
        v16 += 2190;
        *(_DWORD *)(v20 + 8) = 4;
        *(_OWORD *)(v20 + 48) = *(_OWORD *)(v18 + 144);
        *(_OWORD *)(v20 + 64) = *(_OWORD *)(v18 + 208);
        v21 = *(_OWORD *)(v18 + 272);
        *(_QWORD *)(v20 + 80) = 0i64;
        *(_OWORD *)(v20 + 32) = v21;
        *(_OWORD *)(v20 + 112) = *(_OWORD *)(v18 + 160);
        *(_OWORD *)(v20 + 128) = *(_OWORD *)(v18 + 224);
        v22 = *(_OWORD *)(v18 + 288);
        *(_QWORD *)(v20 + 144) = 0i64;
        *(_OWORD *)(v20 + 96) = v22;
        *(_OWORD *)(v20 + 176) = *(_OWORD *)(v18 + 176);
        *(_OWORD *)(v20 + 192) = *(_OWORD *)(v18 + 240);
        v23 = *(_OWORD *)(v18 + 304);
        *(_QWORD *)(v20 + 208) = 0i64;
        *(_OWORD *)(v20 + 160) = v23;
        *(_OWORD *)(v20 + 240) = *(_OWORD *)(v18 + 192);
        *(_OWORD *)(v20 + 256) = *(_OWORD *)(v18 + 256);
        v24 = *(_OWORD *)(v18 + 320);
        *(_QWORD *)(v20 + 272) = 0i64;
        *(_OWORD *)(v20 + 224) = v24;
        hkcdWingedEdge::addTetrahedron((hkcdWingedEdge *)(v18 + 352));
        *(_DWORD *)(v18 + 364) = 0;
      }
      ++v15;
      ++v8;
    }
    while ( v15 < v10 );
    v11 = v52;
    v14 = numShapeBs;
    v7 = v55;
  }
  if ( v10 <= 2 )
  {
    if ( v10 < 2 )
    {
      v38 = hkMemoryRouter::s_memoryRouter.m_slotID;
      v7->m_enum = 1;
      v39 = (17520 * v14 + 127) & 0xFFFFFF80;
      v40 = (hkLifoAllocator *)TlsGetValue(v38);
      v41 = (v39 + 15) & 0xFFFFFFF0;
      if ( v39 > v40->m_slabSize || &v11[v41] != v40->m_cur || v40->m_firstNonLifoEnd == v11 )
      {
        hkLifoAllocator::slowBlockFree(v40, v11, v41);
        v42 = v7;
      }
      else
      {
        v40->m_cur = v11;
        v42 = v7;
      }
      return v42;
    }
  }
  else
  {
    v10 = 2;
  }
  v25 = v10;
  v52 = 0i64;
  v26 = (signed __int64)(v11 + 352);
  *(_QWORD *)gjkStatus = v10;
  do
  {
    hkcdWingedEdge::find2ClosestMultiTriangles(
      (hkcdWingedEdge *)v26,
      (hkcdWingedEdge *)(v11 + 17872),
      &directionOut,
      (hkcdWingedEdge::Triangle **)v11 + 2188,
      (hkcdWingedEdge::Triangle **)v11 + 4378);
    v27 = 0;
    v28 = 0;
    v29 = 0i64;
    if ( v25 <= 0 )
      break;
    v30 = *(_QWORD *)gjkStatus;
    v31 = (hkVector4f **)(v11 + 360);
    do
    {
      if ( *((_DWORD *)&v52 + v29) != 2 )
      {
        v32 = *(signed int *)v31;
        if ( (signed int)v32 >= 55 )
        {
          v33 = (hkcdWingedEdge::Vertex *)&v31[8 * v32 + 3];
          *(_DWORD *)v31 = v32 + 1;
          v33->m_referee.m_storage = 0i64;
          hkpConvexPenetrationUtil::getPointForSimplex((hkpConvexPenetrationUtil *)(v31 - 45), v31[2143], v33);
          hkpConvexPenetrationUtil::tryToExpandPolytope(
            (hkpConvexPenetrationUtil *)(v31 - 45),
            &resulta,
            (hkcdWingedEdge *)(v31 - 1),
            (hkcdWingedEdge::Triangle *)v31[2143],
            v33,
            (hkpGskStatus *)&v52 + v28);
          if ( resulta.m_enum == 1 )
          {
            if ( *((_DWORD *)&v52 + v29) == 3 )
            {
              v34 = v55;
              v35 = hkMemoryRouter::s_memoryRouter.m_slotID;
              v55->m_enum = 1;
              v36 = (17520 * numShapeBs + 127) & 0xFFFFFF80;
              v37 = (hkLifoAllocator *)TlsGetValue(v35);
              goto LABEL_35;
            }
          }
          else
          {
            v27 = 1;
          }
          v30 = *(_QWORD *)gjkStatus;
        }
      }
      ++v29;
      ++v28;
      v31 += 2190;
    }
    while ( v29 < v30 );
    v25 = *(_QWORD *)gjkStatus;
    v26 = (signed __int64)(v11 + 352);
  }
  while ( v27 );
  v43 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), directionOut.m_quad);
  v44 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v43, v43, 85), v56->m_rotation.m_col1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v43, v43, 0), v56->m_rotation.m_col0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v43, v43, 170), v56->m_rotation.m_col2.m_quad));
  v45 = _mm_sub_ps(
          _mm_sub_ps((__m128)0i64, _mm_shuffle_ps(directionOut.m_quad, directionOut.m_quad, 255)),
          _mm_shuffle_ps((__m128)LODWORD(v57->m_radius), (__m128)LODWORD(v57->m_radius), 0));
  if ( v25 > 0 )
  {
    do
    {
      hkpConvexPenetrationUtil::convertResultToFeature(
        (hkpConvexPenetrationUtil *)(v26 - 352),
        (hkcdWingedEdge *)v26,
        *(hkcdWingedEdge::Triangle **)(v26 + 17152),
        &output);
      v46 = *(_QWORD *)(v26 - 16);
      v26 += 17520i64;
      v47 = _mm_shuffle_ps((__m128)*(unsigned int *)(v46 + 32), (__m128)*(unsigned int *)(v46 + 32), 0);
      *(__m128 *)*(_QWORD *)(v26 - 17528) = _mm_add_ps(
                                              _mm_add_ps(
                                                _mm_add_ps(
                                                  _mm_mul_ps(
                                                    _mm_shuffle_ps(
                                                      output.m_pointAinA.m_quad,
                                                      output.m_pointAinA.m_quad,
                                                      85),
                                                    v56->m_rotation.m_col1.m_quad),
                                                  _mm_mul_ps(
                                                    _mm_shuffle_ps(
                                                      output.m_pointAinA.m_quad,
                                                      output.m_pointAinA.m_quad,
                                                      0),
                                                    v56->m_rotation.m_col0.m_quad)),
                                                _mm_mul_ps(
                                                  _mm_shuffle_ps(
                                                    output.m_pointAinA.m_quad,
                                                    output.m_pointAinA.m_quad,
                                                    170),
                                                  v56->m_rotation.m_col2.m_quad)),
                                              v56->m_translation.m_quad);
      *(__m128 *)(*(_QWORD *)(v26 - 17528) + 16i64) = _mm_shuffle_ps(
                                                        v44,
                                                        _mm_unpackhi_ps(v44, _mm_sub_ps(v45, v47)),
                                                        196);
      --v25;
    }
    while ( v25 );
  }
  v34 = v55;
  v48 = hkMemoryRouter::s_memoryRouter.m_slotID;
  v55->m_enum = 0;
  v36 = (17520 * numShapeBs + 127) & 0xFFFFFF80;
  v37 = (hkLifoAllocator *)TlsGetValue(v48);
LABEL_35:
  v49 = (v36 + 15) & 0xFFFFFFF0;
  if ( v36 > v37->m_slabSize || &v11[v49] != v37->m_cur || v37->m_firstNonLifoEnd == v11 )
    hkLifoAllocator::slowBlockFree(v37, v11, v49);
  else
    v37->m_cur = v11;
  return v34;
}

