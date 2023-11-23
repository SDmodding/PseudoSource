// File Line: 18
// RVA: 0x1318AF0
void hkcdWingedEdge::codeBegin(void)
{
  ;
}

// File Line: 25
// RVA: 0x1319140
__int64 __fastcall hkcdWingedEdge::findVisibleTriangles(
        hkcdWingedEdge *this,
        hkcdWingedEdge::Triangle *initialTriangle,
        hkVector4f *pointOfView,
        hkPadSpu<int> *chainLength,
        hkPadSpu<hkcdWingedEdge::Edge *> *edgeChain)
{
  hkcdWingedEdge::WingedEdgeStatus VisibleTriangles; // r9d
  __int64 v8; // rdi
  hkcdWingedEdge::Edge **p_m_neighbour; // rsi
  hkcdWingedEdge::Edge *v10; // rcx
  hkcdWingedEdge::Triangle *m_triangle; // rdx
  int m_state; // eax
  __m128 v13; // xmm1
  float v14; // xmm2_4
  float v15; // xmm2_4
  __int64 m_storage; // rcx
  hkVector4f *v19; // [rsp+60h] [rbp+18h]

  v19 = pointOfView;
  VisibleTriangles = HKCD_WINGED_EDGE_OK;
  v8 = 0i64;
  p_m_neighbour = &initialTriangle->m_edge[0].m_neighbour;
  while ( 1 )
  {
    v10 = *p_m_neighbour;
    m_triangle = (*p_m_neighbour)->m_triangle;
    m_state = m_triangle->m_state;
    if ( !m_state )
    {
      m_state = 1;
      v13 = _mm_mul_ps(
              _mm_sub_ps(pointOfView->m_quad, m_triangle->m_edge[0].m_vertex->m_position.m_quad),
              m_triangle->m_normal.m_quad);
      v14 = (float)(_mm_shuffle_ps(v13, v13, 85).m128_f32[0] + _mm_shuffle_ps(v13, v13, 0).m128_f32[0])
          + _mm_shuffle_ps(v13, v13, 170).m128_f32[0];
      if ( v14 <= this->m_toleranceBorder.m_storage )
      {
        v15 = v14 + 0.0000001;
        if ( v15 > this->m_toleranceBorder.m_storage )
          this->m_toleranceBorder.m_storage = v15;
        m_state = 2;
      }
      else if ( v14 < this->m_previousMinimumDistance.m_storage )
      {
        this->m_previousMinimumDistance.m_storage = v14;
      }
      if ( this->m_previousMinimumDistance.m_storage <= this->m_toleranceBorder.m_storage )
        m_state = 4;
      m_triangle->m_state = m_state;
      if ( m_state == 1 )
      {
        VisibleTriangles = hkcdWingedEdge::findVisibleTriangles(this, m_triangle, pointOfView, chainLength, edgeChain);
        if ( VisibleTriangles == HKCD_WINGED_EDGE_FAIL )
          goto LABEL_20;
        pointOfView = v19;
        goto LABEL_17;
      }
      if ( m_state == 4 )
        break;
    }
    if ( m_state == 2 )
    {
      v10->m_vertex->m_referee.m_storage = v10;
      ++chainLength->m_storage;
      edgeChain->m_storage = v10;
    }
LABEL_17:
    ++v8;
    p_m_neighbour += 4;
    if ( v8 >= 3 )
      goto LABEL_20;
  }
  VisibleTriangles = HKCD_WINGED_EDGE_FAIL;
LABEL_20:
  initialTriangle->m_distanceToOrigin = 3.40282e38;
  m_storage = this->m_numFreeTriangle.m_storage;
  if ( (int)m_storage >= 100 )
    return 2i64;
  this->m_freeTriangle[m_storage] = initialTriangle;
  ++this->m_numFreeTriangle.m_storage;
  return (unsigned int)VisibleTriangles;
}

// File Line: 93
// RVA: 0x13192A0
void __fastcall hkcdWingedEdge::addTetrahedron(hkcdWingedEdge *this)
{
  hkcdWingedEdge::Triangle *m_triangles; // rsi
  hkcdWingedEdge::Triangle *v2; // r11
  const int *v4; // r8
  hkcdWingedEdge::Triangle *i; // r9
  unsigned __int64 m_edge; // rax
  __int64 v7; // rcx
  char *v8; // rdx
  __int64 v9; // rcx
  __int64 v10; // rdx
  hkcdWingedEdge::Vertex *m_vertex; // rdx
  hkcdWingedEdge::Vertex *v12; // rcx
  __m128 v13; // xmm2
  int j; // ebx

  m_triangles = this->m_triangles;
  v2 = &this->m_triangles[4];
  this->m_numTriangles.m_storage = 4;
  v4 = topologyData;
  for ( i = this->m_triangles; i != v2; ++i )
  {
    i->m_state = HKCD_NOT_VISITED;
    i->m_edge[0].m_next = &i->m_edge[1];
    i->m_edge[1].m_next = &i->m_edge[2];
    m_edge = (unsigned __int64)i->m_edge;
    i->m_edge[2].m_next = i->m_edge;
    if ( i->m_edge < (hkcdWingedEdge::Edge *)&i->m_distanceToOrigin )
    {
      do
      {
        v7 = *v4;
        *(_QWORD *)(m_edge + 24) = i;
        v8 = (char *)this->m_vertex + v7;
        v9 = v4[2];
        m_edge += 32i64;
        *(_QWORD *)(m_edge - 32) = v8;
        v10 = v4[1] + 4368i64;
        v4 += 3;
        *(_QWORD *)(m_edge - 16) = (char *)this + v9 + v10;
      }
      while ( m_edge < (unsigned __int64)&i->m_distanceToOrigin );
    }
  }
  hkcdWingedEdge::Triangle::calculateTriangleData(&this->m_triangles[3]);
  m_vertex = this->m_vertex;
  v12 = &this->m_vertex[1];
  v13 = _mm_mul_ps(
          _mm_sub_ps(this->m_vertex[0].m_position.m_quad, this->m_vertex[1].m_position.m_quad),
          this->m_triangles[3].m_normal.m_quad);
  if ( !_mm_movemask_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
            _mm_shuffle_ps(v13, v13, 170))) )
  {
    this->m_triangles[2].m_edge[0].m_vertex = v12;
    this->m_triangles[1].m_edge[0].m_vertex = v12;
    m_triangles->m_edge[0].m_vertex = v12;
    this->m_triangles[3].m_edge[0].m_vertex = m_vertex;
    this->m_triangles[1].m_edge[1].m_vertex = m_vertex;
    m_triangles->m_edge[2].m_vertex = m_vertex;
  }
  for ( j = 3; j >= 0; --j )
    hkcdWingedEdge::Triangle::calculateTriangleData(m_triangles++);
}

// File Line: 175
// RVA: 0x1318B10
void __fastcall hkcdWingedEdge::Triangle::calculateTriangleData(hkcdWingedEdge::Triangle *this)
{
  hkcdWingedEdge::Vertex *m_vertex; // rdx
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

  m_vertex = this->m_edge[0].m_vertex;
  v2.m_quad = (__m128)this->m_edge[1].m_vertex->m_position;
  v3 = _mm_sub_ps(m_vertex->m_position.m_quad, v2.m_quad);
  v4 = _mm_sub_ps(v2.m_quad, this->m_edge[2].m_vertex->m_position.m_quad);
  v5 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v4, v4, 201), v3), _mm_mul_ps(_mm_shuffle_ps(v3, v3, 201), v4));
  v6 = _mm_shuffle_ps(v5, v5, 201);
  v7 = _mm_mul_ps(v6, v6);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_rsqrt_ps(v8);
  v10.m_quad = _mm_mul_ps(
                 v6,
                 _mm_andnot_ps(
                   _mm_cmple_ps(v8, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v9, v8), v9)),
                     _mm_mul_ps(*(__m128 *)_xmm, v9))));
  this->m_normal = (hkVector4f)v10.m_quad;
  v11 = _mm_mul_ps(m_vertex->m_position.m_quad, v10.m_quad);
  this->m_distanceToOrigin = (float)(_mm_shuffle_ps(v11, v11, 85).m128_f32[0] + _mm_shuffle_ps(v11, v11, 0).m128_f32[0])
                           + _mm_shuffle_ps(v11, v11, 170).m128_f32[0];
}

// File Line: 211
// RVA: 0x1318B00
void hkcdWingedEdge::codeEnd(void)
{
  ;
}

// File Line: 273
// RVA: 0x1318BC0
hkcdWingedEdge::Triangle *__fastcall hkcdWingedEdge::findTriangleNearestOrigin(
        hkcdWingedEdge *this,
        hkcdWingedEdge::Triangle *triangleOnNearestPlane)
{
  int v3; // ecx
  hkcdWingedEdge::Triangle::TriangleState *p_m_state; // rax
  int v6; // eax
  hkPadSpu<hkcdWingedEdge::Edge *> *p_m_referee; // rcx
  __m128 *p_m_quad; // r11
  __m128 *v9; // rbx
  bool v10; // al
  int v11; // r8d
  __int64 v12; // r10
  __m128 ***v13; // r9
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm4
  __m128 v17; // xmm3
  __m128 v18; // xmm3
  __m128 **v19; // rcx
  float m_distanceToOrigin; // xmm0_4
  __m128 *v21; // rdx

  v3 = 0;
  if ( this->m_numTriangles.m_storage > 0 )
  {
    p_m_state = &this->m_triangles[0].m_state;
    do
    {
      *p_m_state = HKCD_NOT_VISITED;
      ++v3;
      p_m_state += 32;
    }
    while ( v3 < this->m_numTriangles.m_storage );
  }
  v6 = 0;
  if ( this->m_numVertices.m_storage > 0 )
  {
    p_m_referee = &this->m_vertex[0].m_referee;
    do
    {
      p_m_referee->m_storage = 0i64;
      ++v6;
      p_m_referee += 8;
    }
    while ( v6 < this->m_numVertices.m_storage );
  }
  p_m_quad = &triangleOnNearestPlane->m_normal.m_quad;
  v9 = 0i64;
  v10 = 0;
  do
  {
    if ( v10 )
      break;
    p_m_quad[7].m128_i32[1] = 3;
    v11 = 0;
    v12 = 0i64;
    v13 = (__m128 ***)&p_m_quad[1].m128_u64[1];
    while ( 1 )
    {
      if ( &p_m_quad[2 * v11 + 1] != v9 )
      {
        v14 = *(__m128 *)*(v13 - 1);
        v15 = _mm_sub_ps(***v13, v14);
        v16 = _mm_mul_ps(v15, v15);
        v17 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(*p_m_quad, *p_m_quad, 201), v15),
                _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), *p_m_quad));
        v18 = _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v14);
        v15.m128_f32[0] = (float)(_mm_shuffle_ps(v18, v18, 85).m128_f32[0] + _mm_shuffle_ps(v18, v18, 0).m128_f32[0])
                        + _mm_shuffle_ps(v18, v18, 170).m128_f32[0];
        if ( (float)(COERCE_FLOAT((unsigned int)(2 * v15.m128_i32[0]) >> 1) * v15.m128_f32[0]) < (float)((float)((float)(_mm_shuffle_ps(v16, v16, 85).m128_f32[0] + _mm_shuffle_ps(v16, v16, 0).m128_f32[0]) + _mm_shuffle_ps(v16, v16, 170).m128_f32[0]) * _mm_shuffle_ps((__m128)0xAEDBE6FE, (__m128)0xAEDBE6FE, 0).m128_f32[0]) )
        {
          v19 = v13[1];
          m_distanceToOrigin = triangleOnNearestPlane->m_distanceToOrigin;
          v21 = v19[3];
          if ( m_distanceToOrigin <= 0.0 || (float)(m_distanceToOrigin * 0.89999998) <= v21[7].m128_f32[0] )
            break;
        }
      }
      ++v11;
      ++v12;
      v13 += 4;
      if ( v11 >= 3 )
        goto LABEL_17;
    }
    v9 = (__m128 *)p_m_quad[2 * v12 + 2].m128_u64[0];
    v10 = v21[7].m128_i32[1] == 3;
    p_m_quad = v19[3];
LABEL_17:
    ;
  }
  while ( v11 != 3 );
  return (hkcdWingedEdge::Triangle *)p_m_quad;
}

// File Line: 422
// RVA: 0x1318D70
void __fastcall hkcdWingedEdge::find2ClosestMultiTriangles(
        hkcdWingedEdge *we0,
        hkcdWingedEdge *we1,
        hkVector4f *directionOut,
        hkcdWingedEdge::Triangle **nearestTriangle0,
        hkcdWingedEdge::Triangle **nearestTriangle1)
{
  __m128 m_quad; // xmm6
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
  hkcdWingedEdge::Triangle *v17; // rax
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
  __m128 v38; // xmm0
  __m128 v39; // xmm6
  __m128 v40; // xmm5
  __m128 v41; // xmm2
  __m128 v42; // xmm1
  __m128 v43; // xmm0
  __m128 v44; // xmm0
  __m128 v45; // xmm6
  __m128 v46; // xmm1
  __m128 v47; // xmm3
  __m128 v48; // xmm2
  __m128 v49; // xmm7
  __m128 v50; // xmm0
  __m128 v51; // xmm3
  __m128 v52; // xmm1
  __m128 v53; // xmm7
  __m128 v54; // [rsp+0h] [rbp-D8h]
  __m128 v55; // [rsp+20h] [rbp-B8h]

  m_quad = aabbOut.m_quad;
  v7 = (__m128)xmmword_141A712A0;
  v8 = we0->m_numTriangles.m_storage - 1;
  v9 = v8;
  v10 = 0i64;
  v11 = 0i64;
  v55 = 0i64;
  v54 = 0i64;
  if ( v8 >= 0 )
  {
    v12 = &we0->m_triangles[v8];
    while ( 1 )
    {
      v13 = _mm_shuffle_ps((__m128)LODWORD(v12->m_distanceToOrigin), (__m128)LODWORD(v12->m_distanceToOrigin), 0);
      v14 = _mm_mul_ps(v13, v13);
      if ( v14.m128_f32[0] <= v7.m128_f32[0] )
      {
        v15 = we1->m_numTriangles.m_storage - 1;
        v16 = v15;
        if ( v15 >= 1i64 )
          break;
      }
LABEL_23:
      --v12;
      if ( --v9 < 0 )
        goto LABEL_24;
    }
    v17 = &we1->m_triangles[v15];
    while ( 1 )
    {
      v18 = _mm_shuffle_ps((__m128)LODWORD(v17->m_distanceToOrigin), (__m128)LODWORD(v17->m_distanceToOrigin), 0);
      v19 = _mm_mul_ps(v18, v18);
      if ( v19.m128_f32[0] > v7.m128_f32[0] )
        goto LABEL_21;
      v20 = _mm_mul_ps(v12->m_normal.m_quad, v17->m_normal.m_quad);
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
        v38 = _mm_cmplt_ps((__m128)0i64, v18);
        v39 = _mm_and_ps(v38, aabbOut.m_quad);
        v40 = _mm_and_ps(v38, query.m_quad);
        v41 = v38;
        v42 = _mm_and_ps(v38, v14);
LABEL_16:
        v43 = _mm_andnot_ps(v38, (__m128)xmmword_141A711B0);
        v28 = _mm_or_ps(v40, v43);
        v30 = _mm_or_ps(v39, v43);
        v37 = _mm_or_ps(_mm_andnot_ps(v41, _mm_mul_ps(_mm_sub_ps((__m128)0i64, v21), v21)), v42);
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
        m_quad = aabbOut.m_quad;
LABEL_20:
        v10 = v55;
LABEL_21:
        v11 = v54;
        goto LABEL_22;
      }
      v11 = v30;
      v54 = v30;
      m_quad = aabbOut.m_quad;
      *nearestTriangle0 = v12;
      *nearestTriangle1 = v17;
      v10 = v28;
      v55 = v28;
      v7 = v37;
LABEL_22:
      --v17;
      if ( !--v16 )
        goto LABEL_23;
    }
    v38 = _mm_cmplt_ps(*(__m128 *)&epsilon, v13);
    v41 = v38;
    v40 = _mm_and_ps(v38, m_quad);
    v42 = _mm_and_ps(v38, v19);
    v39 = _mm_and_ps(v38, query.m_quad);
    goto LABEL_16;
  }
LABEL_24:
  v44 = _mm_mul_ps((*nearestTriangle0)->m_normal.m_quad, v10);
  *directionOut = (hkVector4f)v44;
  v45 = _mm_add_ps(_mm_mul_ps((*nearestTriangle1)->m_normal.m_quad, v11), v44);
  v46 = _mm_mul_ps(v45, v45);
  v47 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v46, v46, 85), _mm_shuffle_ps(v46, v46, 0)), _mm_shuffle_ps(v46, v46, 170));
  v48 = _mm_rsqrt_ps(v47);
  v49 = _mm_cmple_ps(v47, (__m128)0i64);
  v50 = _mm_mul_ps(_mm_mul_ps(v48, v47), v48);
  v51 = _mm_max_ps(aabbOut.m_quad, v7);
  v52 = _mm_rsqrt_ps(v51);
  v53 = _mm_mul_ps(_mm_andnot_ps(v49, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v50), _mm_mul_ps(v48, *(__m128 *)_xmm))), v45);
  directionOut->m_quad = _mm_shuffle_ps(
                           v53,
                           _mm_unpackhi_ps(
                             v53,
                             _mm_andnot_ps(
                               _mm_cmple_ps(v51, (__m128)0i64),
                               _mm_mul_ps(
                                 _mm_mul_ps(
                                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v51, v52), v52)),
                                   _mm_mul_ps(v52, *(__m128 *)_xmm)),
                                 v51))),
                           196);
}

