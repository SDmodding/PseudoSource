// File Line: 18
// RVA: 0x1318AF0
void hkcdWingedEdge::codeBegin(void)
{
  ;
}

// File Line: 25
// RVA: 0x1319140
signed __int64 __fastcall hkcdWingedEdge::findVisibleTriangles(hkcdWingedEdge *this, hkcdWingedEdge::Triangle *initialTriangle, hkVector4f *pointOfView, hkPadSpu<int> *chainLength, hkPadSpu<hkcdWingedEdge::Edge *> *edgeChain)
{
  hkPadSpu<int> *v5; // rbp
  hkcdWingedEdge::WingedEdgeStatus v6; // er9
  hkcdWingedEdge *v7; // rbx
  signed __int64 v8; // rdi
  hkcdWingedEdge::Edge **v9; // rsi
  hkcdWingedEdge::Edge *v10; // rcx
  hkcdWingedEdge::Triangle *v11; // rdx
  signed int v12; // eax
  __m128 v13; // xmm1
  float v14; // xmm2_4
  float v15; // xmm2_4
  __int64 v16; // rcx
  hkcdWingedEdge::Triangle *v18; // [rsp+58h] [rbp+10h]
  hkVector4f *v19; // [rsp+60h] [rbp+18h]

  v19 = pointOfView;
  v18 = initialTriangle;
  v5 = chainLength;
  v6 = 0;
  v7 = this;
  v8 = 0i64;
  v9 = &initialTriangle->m_edge[0].m_neighbour;
  while ( 1 )
  {
    v10 = *v9;
    v11 = (*v9)->m_triangle;
    v12 = v11->m_state;
    if ( !v12 )
    {
      v12 = 1;
      v13 = _mm_mul_ps(
              _mm_sub_ps(pointOfView->m_quad, v11->m_edge[0].m_vertex->m_position.m_quad),
              v11->m_normal.m_quad);
      v14 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 0)))
          + COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 170));
      if ( v14 <= v7->m_toleranceBorder.m_storage )
      {
        v15 = v14 + 0.0000001;
        if ( v15 > v7->m_toleranceBorder.m_storage )
          v7->m_toleranceBorder.m_storage = v15;
        v12 = 2;
      }
      else if ( v14 < v7->m_previousMinimumDistance.m_storage )
      {
        v7->m_previousMinimumDistance.m_storage = v14;
      }
      if ( v7->m_previousMinimumDistance.m_storage <= v7->m_toleranceBorder.m_storage )
        v12 = 4;
      v11->m_state = v12;
      if ( v12 == 1 )
      {
        v6 = hkcdWingedEdge::findVisibleTriangles(v7, v11, pointOfView, v5, edgeChain);
        if ( v6 == 2 )
          goto LABEL_20;
        pointOfView = v19;
        goto LABEL_17;
      }
      if ( v12 == 4 )
        break;
    }
    if ( v12 == 2 )
    {
      v10->m_vertex->m_referee.m_storage = v10;
      ++v5->m_storage;
      edgeChain->m_storage = v10;
    }
LABEL_17:
    ++v8;
    v9 += 4;
    if ( v8 >= 3 )
      goto LABEL_20;
  }
  v6 = 2;
LABEL_20:
  v18->m_distanceToOrigin = 3.40282e38;
  v16 = v7->m_numFreeTriangle.m_storage;
  if ( (signed int)v16 >= 100 )
    return 2i64;
  v7->m_freeTriangle[v16] = v18;
  ++v7->m_numFreeTriangle.m_storage;
  return (unsigned int)v6;
}

// File Line: 93
// RVA: 0x13192A0
void __fastcall hkcdWingedEdge::addTetrahedron(hkcdWingedEdge *this)
{
  hkcdWingedEdge::Triangle *v1; // rsi
  hkcdWingedEdge::Triangle *v2; // r11
  hkcdWingedEdge *v3; // rdi
  const int *v4; // r8
  hkcdWingedEdge::Triangle *v5; // r9
  unsigned __int64 v6; // rax
  __int64 v7; // rcx
  signed __int64 v8; // rdx
  __int64 v9; // rcx
  signed __int64 v10; // rdx
  signed __int64 v11; // rdx
  signed __int64 v12; // rcx
  __m128 v13; // xmm2
  signed int v14; // ebx

  v1 = this->m_triangles;
  v2 = &this->m_triangles[4];
  v3 = this;
  this->m_numTriangles.m_storage = 4;
  v4 = topologyData;
  v5 = this->m_triangles;
  if ( this->m_triangles != &this->m_triangles[4] )
  {
    do
    {
      v5->m_state = 0;
      v5->m_edge[0].m_next = &v5->m_edge[1];
      v5->m_edge[1].m_next = &v5->m_edge[2];
      v6 = (unsigned __int64)v5->m_edge;
      v5->m_edge[2].m_next = v5->m_edge;
      if ( v5->m_edge < (hkcdWingedEdge::Edge *)&v5->m_distanceToOrigin )
      {
        do
        {
          v7 = *v4;
          *(_QWORD *)(v6 + 24) = v5;
          v8 = (signed __int64)v3->m_vertex + v7;
          v9 = v4[2];
          v6 += 32i64;
          *(_QWORD *)(v6 - 32) = v8;
          v10 = v4[1] + 4368i64;
          v4 += 3;
          *(_QWORD *)(v6 - 16) = (char *)v3 + v9 + v10;
        }
        while ( v6 < (unsigned __int64)&v5->m_distanceToOrigin );
      }
      ++v5;
    }
    while ( v5 != v2 );
  }
  hkcdWingedEdge::Triangle::calculateTriangleData(&v3->m_triangles[3]);
  v11 = (signed __int64)v3->m_vertex;
  v12 = (signed __int64)&v3->m_vertex[1];
  v13 = _mm_mul_ps(
          _mm_sub_ps(v3->m_vertex[0].m_position.m_quad, v3->m_vertex[1].m_position.m_quad),
          v3->m_triangles[3].m_normal.m_quad);
  if ( !_mm_movemask_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
            _mm_shuffle_ps(v13, v13, 170))) )
  {
    v3->m_triangles[2].m_edge[0].m_vertex = (hkcdWingedEdge::Vertex *)v12;
    v3->m_triangles[1].m_edge[0].m_vertex = (hkcdWingedEdge::Vertex *)v12;
    v1->m_edge[0].m_vertex = (hkcdWingedEdge::Vertex *)v12;
    v3->m_triangles[3].m_edge[0].m_vertex = (hkcdWingedEdge::Vertex *)v11;
    v3->m_triangles[1].m_edge[1].m_vertex = (hkcdWingedEdge::Vertex *)v11;
    v1->m_edge[2].m_vertex = (hkcdWingedEdge::Vertex *)v11;
  }
  v14 = 3;
  do
  {
    hkcdWingedEdge::Triangle::calculateTriangleData(v1);
    ++v1;
    --v14;
  }
  while ( v14 >= 0 );
}

// File Line: 175
// RVA: 0x1318B10
void __fastcall hkcdWingedEdge::Triangle::calculateTriangleData(hkcdWingedEdge::Triangle *this)
{
  hkcdWingedEdge::Vertex *v1; // rdx
  hkVector4f v2; // xmm5
  __m128 v3; // xmm1
  __m128 v4; // xmm5
  __m128 v5; // xmm5
  __m128 v6; // xmm5
  __m128 v7; // xmm1
  __m128 v8; // xmm3
  __m128 v9; // xmm2
  hkVector4f v10; // xmm5
  __m128 v11; // xmm2

  v1 = this->m_edge[0].m_vertex;
  v2.m_quad = (__m128)this->m_edge[1].m_vertex->m_position;
  v3 = _mm_sub_ps(v1->m_position.m_quad, v2.m_quad);
  v4 = _mm_sub_ps(v2.m_quad, this->m_edge[2].m_vertex->m_position.m_quad);
  v5 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v4, v4, 201), v3), _mm_mul_ps(_mm_shuffle_ps(v3, v3, 201), v4));
  v6 = _mm_shuffle_ps(v5, v5, 201);
  v7 = _mm_mul_ps(v6, v6);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_rsqrt_ps(v8);
  v10.m_quad = _mm_mul_ps(
                 v6,
                 _mm_andnot_ps(
                   _mm_cmpleps(v8, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v9, v8), v9)),
                     _mm_mul_ps(*(__m128 *)_xmm, v9))));
  this->m_normal = (hkVector4f)v10.m_quad;
  v11 = _mm_mul_ps(v1->m_position.m_quad, v10.m_quad);
  this->m_distanceToOrigin = (float)(COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 85))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 0)))
                           + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 170));
}

// File Line: 211
// RVA: 0x1318B00
void hkcdWingedEdge::codeEnd(void)
{
  ;
}

// File Line: 273
// RVA: 0x1318BC0
__m128 *__fastcall hkcdWingedEdge::findTriangleNearestOrigin(hkcdWingedEdge *this, hkcdWingedEdge::Triangle *triangleOnNearestPlane)
{
  hkcdWingedEdge *v2; // r8
  int v3; // ecx
  hkcdWingedEdge::Triangle *v4; // rdi
  hkcdWingedEdge::Triangle::TriangleState *v5; // rax
  int v6; // eax
  hkPadSpu<hkcdWingedEdge::Edge *> *v7; // rcx
  __m128 *v8; // r11
  __m128 *v9; // rbx
  bool v10; // al
  signed int v11; // er8
  __int64 v12; // r10
  __m128 ***v13; // r9
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm4
  __m128 v17; // xmm3
  __m128 v18; // xmm3
  __m128 **v19; // rcx
  float v20; // xmm0_4
  __m128 *v21; // rdx

  v2 = this;
  v3 = 0;
  v4 = triangleOnNearestPlane;
  if ( v2->m_numTriangles.m_storage > 0 )
  {
    v5 = &v2->m_triangles[0].m_state;
    do
    {
      *v5 = 0;
      ++v3;
      v5 += 32;
    }
    while ( v3 < v2->m_numTriangles.m_storage );
  }
  v6 = 0;
  if ( v2->m_numVertices.m_storage > 0 )
  {
    v7 = &v2->m_vertex[0].m_referee;
    do
    {
      v7->m_storage = 0i64;
      ++v6;
      v7 += 8;
    }
    while ( v6 < v2->m_numVertices.m_storage );
  }
  v8 = &triangleOnNearestPlane->m_normal.m_quad;
  v9 = 0i64;
  v10 = 0;
  do
  {
    if ( v10 )
      break;
    v8[7].m128_i32[1] = 3;
    v11 = 0;
    v12 = 0i64;
    v13 = (__m128 ***)&v8[1].m128_u64[1];
    while ( 1 )
    {
      if ( &v8[2 * v11 + 1] != v9 )
      {
        v14 = *(__m128 *)*(v13 - 1);
        v15 = _mm_sub_ps(***v13, v14);
        v16 = _mm_mul_ps(v15, v15);
        v17 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(*v8, *v8, 201), v15), _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), *v8));
        v18 = _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v14);
        v15.m128_f32[0] = (float)(COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 0)))
                        + COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 170));
        if ( (float)(COERCE_FLOAT((unsigned int)(2 * v15.m128_i32[0]) >> 1) * v15.m128_f32[0]) < (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 170))) * COERCE_FLOAT(_mm_shuffle_ps((__m128)0xAEDBE6FE, (__m128)0xAEDBE6FE, 0))) )
        {
          v19 = v13[1];
          v20 = v4->m_distanceToOrigin;
          v21 = v19[3];
          if ( v20 <= 0.0 || (float)(v20 * 0.89999998) <= v21[7].m128_f32[0] )
            break;
        }
      }
      ++v11;
      ++v12;
      v13 += 4;
      if ( v11 >= 3 )
        goto LABEL_17;
    }
    v9 = (__m128 *)v8[2 * (v12 + 1)].m128_u64[0];
    v10 = v21[7].m128_i32[1] == 3;
    v8 = v19[3];
LABEL_17:
    ;
  }
  while ( v11 != 3 );
  return v8;
}

// File Line: 422
// RVA: 0x1318D70
void __fastcall hkcdWingedEdge::find2ClosestMultiTriangles(hkcdWingedEdge *we0, hkcdWingedEdge *we1, hkVector4f *directionOut, hkcdWingedEdge::Triangle **nearestTriangle0, hkcdWingedEdge::Triangle **nearestTriangle1)
{
  __m128 v5; // xmm6
  hkcdWingedEdge *v6; // rbx
  __m128 v7; // xmm10
  int v8; // eax
  __int64 v9; // r11
  __m128 v10; // xmm1
  __m128 v11; // xmm3
  hkcdWingedEdge::Triangle *v12; // rcx
  __m128 v13; // xmm9
  __m128 v14; // xmm15
  int v15; // eax
  __int64 v16; // rdx
  signed __int64 v17; // rax
  __m128 v18; // xmm3
  __m128 v19; // xmm7
  __m128 v20; // xmm1
  __m128 v21; // xmm4
  __m128 v22; // xmm8
  __m128 v23; // xmm2
  __m128 v24; // xmm1
  __m128 v25; // xmm3
  __m128 v26; // xmm2
  __m128 v27; // xmm1
  __m128 v28; // xmm5
  __m128 v29; // xmm7
  __m128 v30; // xmm6
  __m128 v31; // xmm1
  __m128 v32; // xmm1
  __m128 v33; // xmm7
  __m128 v34; // xmm2
  __m128 v35; // xmm1
  __m128 v36; // xmm7
  __m128 v37; // xmm2
  __m128 v38; // xmm1
  __m128 v39; // xmm0
  __m128 v40; // xmm6
  __m128 v41; // xmm5
  __m128 v42; // xmm2
  __m128 v43; // xmm1
  __m128 v44; // xmm1
  __m128 v45; // xmm6
  __m128 v46; // xmm0
  hkVector4f v47; // xmm0
  __m128 v48; // xmm6
  __m128 v49; // xmm1
  __m128 v50; // xmm3
  __m128 v51; // xmm2
  __m128 v52; // xmm7
  __m128 v53; // xmm0
  __m128 v54; // xmm3
  __m128 v55; // xmm1
  __m128 v56; // xmm7
  __m128 v57; // [rsp+0h] [rbp-D8h]
  __m128 v58; // [rsp+20h] [rbp-B8h]

  v5 = aabbOut.m_quad;
  v6 = we1;
  v7 = (__m128)xmmword_141A712A0;
  v8 = we0->m_numTriangles.m_storage - 1;
  v9 = v8;
  v10 = 0i64;
  v11 = 0i64;
  v58 = 0i64;
  v57 = 0i64;
  if ( v8 >= 0 )
  {
    v12 = (hkcdWingedEdge::Triangle *)((char *)we0 + 128 * (v8 + 34i64));
    while ( 1 )
    {
      v13 = _mm_shuffle_ps((__m128)LODWORD(v12->m_distanceToOrigin), (__m128)LODWORD(v12->m_distanceToOrigin), 0);
      v14 = _mm_mul_ps(v13, v13);
      if ( v14.m128_f32[0] <= v7.m128_f32[0] )
      {
        v15 = v6->m_numTriangles.m_storage - 1;
        v16 = v15;
        if ( v15 >= 1i64 )
          break;
      }
LABEL_23:
      --v12;
      if ( --v9 < 0 )
        goto LABEL_24;
    }
    v17 = (signed __int64)v6 + 128 * (v15 + 34i64);
    while ( 1 )
    {
      v18 = _mm_shuffle_ps((__m128)*(unsigned int *)(v17 + 112), (__m128)*(unsigned int *)(v17 + 112), 0);
      v19 = _mm_mul_ps(v18, v18);
      if ( v19.m128_f32[0] > v7.m128_f32[0] )
        goto LABEL_21;
      v20 = _mm_mul_ps(v12->m_normal.m_quad, *(__m128 *)v17);
      v21 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
              _mm_shuffle_ps(v20, v20, 170));
      if ( v21.m128_f32[0] < (float)(0.0 - 0.5) )
        goto LABEL_20;
      v22 = _mm_sub_ps(v13, _mm_mul_ps(v18, v21));
      v23 = _mm_sub_ps(v18, _mm_mul_ps(v13, v21));
      if ( v22.m128_f32[0] <= 0.00000011920929 )
        break;
      if ( v23.m128_f32[0] <= 0.00000011920929 )
      {
        v38 = _mm_cmpltps((__m128)0i64, v18);
        v39 = v38;
        v40 = _mm_and_ps(v38, aabbOut.m_quad);
        v41 = _mm_and_ps(v38, query.m_quad);
        v42 = v38;
        v43 = _mm_and_ps(v38, v14);
LABEL_16:
        v46 = _mm_andnot_ps(v39, (__m128)xmmword_141A711B0);
        v28 = _mm_or_ps(v41, v46);
        v30 = _mm_or_ps(v40, v46);
        v37 = _mm_or_ps(_mm_andnot_ps(v42, _mm_mul_ps(_mm_sub_ps((__m128)0i64, v21), v21)), v43);
        goto LABEL_17;
      }
      if ( v22.m128_f32[0] <= v23.m128_f32[0] )
      {
        v32 = _mm_rcp_ps(v23);
        v33 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v32, v23)), v32), v22);
        v34 = _mm_add_ps(_mm_mul_ps(v33, v21), query.m_quad);
        v35 = _mm_rcp_ps(v34);
        v30 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v35, v34)), v35);
        v28 = _mm_mul_ps(v33, v30);
        v31 = _mm_mul_ps(v30, v18);
        v29 = _mm_mul_ps(v33, v31);
      }
      else
      {
        v24 = _mm_rcp_ps(v22);
        v25 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v24, v22)), v24), v23);
        v26 = _mm_add_ps(_mm_mul_ps(v25, v21), query.m_quad);
        v27 = _mm_rcp_ps(v26);
        v28 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v27, v26)), v27);
        v29 = _mm_mul_ps(v28, v13);
        v30 = _mm_mul_ps(v28, v25);
        v31 = _mm_mul_ps(v29, v25);
      }
      v36 = _mm_add_ps(v29, _mm_mul_ps(v31, v21));
      v37 = _mm_add_ps(
              _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(query.m_quad, _mm_mul_ps(v21, v21)), v31), v31),
              _mm_mul_ps(v36, v36));
LABEL_17:
      if ( v37.m128_f32[0] >= v7.m128_f32[0] )
      {
        v5 = aabbOut.m_quad;
LABEL_20:
        v10 = v58;
LABEL_21:
        v11 = v57;
        goto LABEL_22;
      }
      v11 = v30;
      v57 = v30;
      v5 = aabbOut.m_quad;
      *nearestTriangle0 = v12;
      *nearestTriangle1 = (hkcdWingedEdge::Triangle *)v17;
      v10 = v28;
      v58 = v28;
      v7 = v37;
LABEL_22:
      v17 -= 128i64;
      if ( !--v16 )
        goto LABEL_23;
    }
    v44 = _mm_cmpltps(*(__m128 *)&epsilon, v13);
    v39 = v44;
    v42 = v44;
    v41 = _mm_and_ps(v44, v5);
    v45 = v44;
    v43 = _mm_and_ps(v44, v19);
    v40 = _mm_and_ps(v45, query.m_quad);
    goto LABEL_16;
  }
LABEL_24:
  v47.m_quad = _mm_mul_ps((*nearestTriangle0)->m_normal.m_quad, v10);
  *directionOut = (hkVector4f)v47.m_quad;
  v48 = _mm_add_ps(_mm_mul_ps((*nearestTriangle1)->m_normal.m_quad, v11), v47.m_quad);
  v49 = _mm_mul_ps(v48, v48);
  v50 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v49, v49, 85), _mm_shuffle_ps(v49, v49, 0)), _mm_shuffle_ps(v49, v49, 170));
  v51 = _mm_rsqrt_ps(v50);
  v52 = _mm_cmpleps(v50, (__m128)0i64);
  v53 = _mm_mul_ps(_mm_mul_ps(v51, v50), v51);
  v54 = _mm_max_ps(aabbOut.m_quad, v7);
  v55 = _mm_rsqrt_ps(v54);
  v56 = _mm_mul_ps(_mm_andnot_ps(v52, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v53), _mm_mul_ps(v51, *(__m128 *)_xmm))), v48);
  directionOut->m_quad = _mm_shuffle_ps(
                           v56,
                           _mm_unpackhi_ps(
                             v56,
                             _mm_andnot_ps(
                               _mm_cmpleps(v54, (__m128)0i64),
                               _mm_mul_ps(
                                 _mm_mul_ps(
                                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v54, v55), v55)),
                                   _mm_mul_ps(v55, *(__m128 *)_xmm)),
                                 v54))),
                           196);
}

