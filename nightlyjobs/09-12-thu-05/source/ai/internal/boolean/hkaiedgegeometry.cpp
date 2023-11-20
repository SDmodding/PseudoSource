// File Line: 21
// RVA: 0xB9AD80
void __fastcall hkaiEdgeGeometry::hkaiEdgeGeometry(hkaiEdgeGeometry *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiEdgeGeometry::`vftable;
  this->m_edges.m_data = 0i64;
  this->m_edges.m_size = 0;
  this->m_edges.m_capacityAndFlags = 2147483648;
  this->m_faces.m_capacityAndFlags = -2147483647;
  this->m_faces.m_data = &this->m_zeroFace;
  this->m_faces.m_size = 1;
  this->m_vertices.m_data = 0i64;
  this->m_vertices.m_size = 0;
  this->m_vertices.m_capacityAndFlags = 2147483648;
  this->m_zeroFace.m_flags.m_storage = 0;
  this->m_zeroFace.m_data = 0;
}

// File Line: 26
// RVA: 0xB9A400
void __fastcall hkaiEdgeGeometry::clear(hkaiEdgeGeometry *this)
{
  hkArray<hkaiEdgeGeometry::Face,hkContainerHeapAllocator> *v1; // rbx
  int v2; // eax
  int v3; // eax
  int v4; // er9
  hkResult result; // [rsp+40h] [rbp+8h]

  v1 = &this->m_faces;
  this->m_edges.m_size = 0;
  this->m_vertices.m_size = 0;
  v2 = this->m_faces.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v2 < 1 )
  {
    v3 = 2 * v2;
    v4 = 1;
    if ( v3 > 1 )
      v4 = v3;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v1, v4, 12);
  }
  v1->m_size = 1;
}

// File Line: 33
// RVA: 0xB9AC10
signed __int64 __fastcall hkaiEdgeGeometry::findEdgeIndex(hkaiEdgeGeometry *this, int startVertexIndex, int endVertexIndex)
{
  hkaiEdgeGeometry::Edge *v3; // r10
  hkaiEdgeGeometry::Edge *v4; // rax
  signed __int64 v5; // r9
  bool i; // zf

  v3 = this->m_edges.m_data;
  v4 = v3;
  v5 = (signed __int64)&v3[this->m_edges.m_size];
  for ( i = v3 == (hkaiEdgeGeometry::Edge *)v5; !i; i = v4 == (hkaiEdgeGeometry::Edge *)v5 )
  {
    if ( v4->m_a == startVertexIndex && v4->m_b == endVertexIndex )
      return v4 - v3;
    ++v4;
  }
  return 0xFFFFFFFFi64;
}

// File Line: 52
// RVA: 0xB99EE0
void __fastcall hkaiEdgeGeometry::calculateFaceNormal(hkaiEdgeGeometry *this, hkaiEdgeGeometry::Edge *const *start, hkaiEdgeGeometry::Edge *const *end, hkVector4f *normalOut)
{
  hkaiEdgeGeometry::Edge *const *v4; // r10
  hkaiEdgeGeometry::Edge *v5; // rax
  __m128 v6; // xmm9
  __m128 v7; // xmm7
  __m128 v8; // xmm8
  __m128 v9; // xmm7
  __m128 v10; // xmm5
  __m128 v11; // xmm7
  __m128 v12; // xmm1
  __m128 v13; // xmm4
  __m128 v14; // xmm2
  __m128 v15; // xmm7
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  __m128 v18; // xmm1
  __m128 v19; // xmm9
  hkVector4f *v20; // r8
  __m128 v21; // xmm5
  __m128 v22; // xmm3
  hkaiEdgeGeometry::Edge *v23; // rcx
  __m128 v24; // xmm2
  __m128 v25; // xmm0
  __m128 v26; // xmm1
  __m128 v27; // xmm1
  __m128 v28; // xmm3
  __m128 v29; // xmm2
  __m128 v30; // xmm5
  __m128 v31; // xmm2
  __m128 v32; // xmm9

  v4 = end;
  v5 = *start;
  v6 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_9_9999994eN11), (__m128)LODWORD(FLOAT_9_9999994eN11), 0);
  if ( (unsigned int)(end - start) == 2 )
  {
    v7 = _mm_sub_ps(this->m_vertices.m_data[v5->m_a].m_quad, this->m_vertices.m_data[v5->m_b].m_quad);
    v8 = _mm_mul_ps(v7, v7);
    v9 = _mm_shuffle_ps(v7, _mm_unpackhi_ps(v7, (__m128)0i64), 196);
    v10 = _mm_shuffle_ps(v9, v9, 241);
    v11 = _mm_shuffle_ps(v9, v9, 206);
    v12 = _mm_mul_ps(v11, v11);
    v13 = _mm_mul_ps(v10, v10);
    v14 = _mm_cmpltps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
              _mm_shuffle_ps(v13, v13, 170)),
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
              _mm_shuffle_ps(v12, v12, 170)));
    v15 = _mm_xor_ps(
            _mm_or_ps(_mm_and_ps(v11, v14), _mm_andnot_ps(v14, v10)),
            (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
    v16 = _mm_mul_ps(v15, v15);
    v17 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
            _mm_shuffle_ps(v16, v16, 170));
    v18 = _mm_rsqrt_ps(v17);
    v19 = _mm_cmpltps(
            v6,
            _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170)));
    normalOut->m_quad = _mm_or_ps(
                          _mm_and_ps(
                            _mm_mul_ps(
                              _mm_andnot_ps(
                                _mm_cmpleps(v17, (__m128)0i64),
                                _mm_mul_ps(
                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                                  _mm_mul_ps(*(__m128 *)_xmm, v18))),
                              v15),
                            v19),
                          _mm_andnot_ps(v19, transform.m_quad));
  }
  else
  {
    v20 = this->m_vertices.m_data;
    v21 = 0i64;
    if ( start != v4 )
    {
      v22 = v20[v5->m_a].m_quad;
      do
      {
        v23 = *start;
        ++start;
        v24 = _mm_sub_ps(v20[v23->m_a].m_quad, v22);
        v25 = _mm_sub_ps(v20[v23->m_b].m_quad, v22);
        v26 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v24), _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v25));
        v21 = _mm_add_ps(v21, _mm_shuffle_ps(v26, v26, 201));
      }
      while ( start != v4 );
    }
    v27 = _mm_mul_ps(v21, v21);
    v28 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
            _mm_shuffle_ps(v27, v27, 170));
    v29 = _mm_rsqrt_ps(v28);
    v30 = _mm_mul_ps(
            v21,
            _mm_andnot_ps(
              _mm_cmpleps(v28, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v29, v28), v29)),
                _mm_mul_ps(*(__m128 *)_xmm, v29))));
    v31 = _mm_mul_ps(v30, v30);
    v32 = _mm_cmpltps(
            v6,
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
              _mm_shuffle_ps(v31, v31, 170)));
    normalOut->m_quad = _mm_or_ps(_mm_andnot_ps(v32, transform.m_quad), _mm_and_ps(v32, v30));
  }
}

// File Line: 111
// RVA: 0xB9A260
void __fastcall hkaiEdgeGeometry::calculateFaceCentroid(hkaiEdgeGeometry *this, hkaiEdgeGeometry::Edge *const *start, hkaiEdgeGeometry::Edge *const *end, hkVector4f *centroidOut)
{
  __m128 v4; // xmm1
  hkaiEdgeGeometry::Edge *const *v5; // r10
  __m128 i; // xmm3
  hkaiEdgeGeometry::Edge *v7; // rax
  __m128 v8; // xmm1
  __m128 v9; // xmm2

  v4 = 0i64;
  v5 = start;
  for ( i = 0i64; v5 != end; i = _mm_add_ps(i, this->m_vertices.m_data[v7->m_a].m_quad) )
  {
    v7 = *v5;
    ++v5;
  }
  v4.m128_f32[0] = (float)(signed int)(end - start);
  v8 = _mm_shuffle_ps(v4, v4, 0);
  v9 = _mm_rcp_ps(v8);
  centroidOut->m_quad = _mm_mul_ps(i, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v9, v8)), v9));
}

// File Line: 125
// RVA: 0xB9A390
void __fastcall hkaiEdgeGeometry::calculateFaceAabb(hkaiEdgeGeometry *this, hkaiEdgeGeometry::Edge *const *start, hkaiEdgeGeometry::Edge *const *end, hkAabb *aabb)
{
  hkaiEdgeGeometry::Edge *v4; // rax
  hkaiEdgeGeometry::Edge *const *v5; // rdx
  hkaiEdgeGeometry *v6; // r11
  hkVector4f v7; // xmm0
  hkVector4f v8; // xmm1
  hkaiEdgeGeometry::Edge *v9; // rax
  __m128 *v10; // rcx

  v4 = *start;
  v5 = start + 1;
  v6 = this;
  v7.m_quad = (__m128)this->m_vertices.m_data[v4->m_a];
  aabb->m_min = (hkVector4f)v7.m_quad;
  aabb->m_max = (hkVector4f)v7.m_quad;
  if ( v5 < end )
  {
    v8.m_quad = v7.m_quad;
    do
    {
      v9 = *v5;
      ++v5;
      v10 = &v6->m_vertices.m_data[v9->m_a].m_quad;
      aabb->m_min.m_quad = _mm_min_ps(aabb->m_min.m_quad, *v10);
      v8.m_quad = _mm_max_ps(v8.m_quad, *v10);
      aabb->m_max = (hkVector4f)v8.m_quad;
    }
    while ( v5 < end );
  }
}

// File Line: 139
// RVA: 0xB9A2C0
hkSimdFloat32 *__fastcall hkaiEdgeGeometry::calculateFaceArea(hkaiEdgeGeometry *this, hkSimdFloat32 *result, hkaiEdgeGeometry::Edge *const *start, hkaiEdgeGeometry::Edge *const *end)
{
  hkVector4f *v4; // r10
  __m128 v5; // xmm3
  __m128 v6; // xmm4
  hkaiEdgeGeometry::Edge *v7; // rcx
  __m128 v8; // xmm1
  __m128 v9; // xmm2
  __m128 v10; // xmm2
  __m128 v11; // xmm3
  hkSimdFloat32 *v12; // rax
  __m128 v13; // xmm4
  __m128 v14; // xmm1

  v4 = this->m_vertices.m_data;
  v5 = 0i64;
  if ( start != end )
  {
    v6 = v4[**(signed int **)start].m_quad;
    do
    {
      v7 = *start;
      ++start;
      v8 = _mm_sub_ps(v4[v7->m_a].m_quad, v6);
      v9 = _mm_sub_ps(v4[v7->m_b].m_quad, v6);
      v10 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v8), _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v9));
      v5 = _mm_add_ps(v5, _mm_shuffle_ps(v10, v10, 201));
    }
    while ( start != end );
  }
  v11 = _mm_mul_ps(v5, v5);
  v12 = result;
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v14 = _mm_rsqrt_ps(v13);
  result->m_real = _mm_mul_ps(
                     _mm_andnot_ps(
                       _mm_cmpleps(v13, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v14, v13), v14)),
                           _mm_mul_ps(*(__m128 *)_xmm, v14)),
                         v13)),
                     (__m128)xmmword_141A711B0);
  return v12;
}

// File Line: 168
// RVA: 0xB9A170
void __fastcall hkaiEdgeGeometry::calculateFaceNormals(hkaiEdgeGeometry *this, hkaiFaceEdges *faceEdges, hkArray<hkVector4f,hkContainerHeapAllocator> *normals)
{
  hkArray<hkVector4f,hkContainerHeapAllocator> *v3; // r14
  signed __int64 v4; // rsi
  int v5; // eax
  hkaiFaceEdges *v6; // rbp
  hkaiEdgeGeometry *v7; // r15
  int v8; // eax
  int v9; // er9
  _OWORD *v10; // rax
  signed int v11; // edi
  signed __int64 v12; // rbx
  hkResult result; // [rsp+58h] [rbp+10h]

  v3 = normals;
  LODWORD(v4) = faceEdges->m_faceStartEdges.m_size - 1;
  v5 = normals->m_capacityAndFlags & 0x3FFFFFFF;
  v6 = faceEdges;
  v7 = this;
  if ( v5 < (signed int)v4 )
  {
    v8 = 2 * v5;
    v9 = faceEdges->m_faceStartEdges.m_size - 1;
    if ( (signed int)v4 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, normals, v9, 16);
  }
  v10 = (_OWORD *)v3->m_data->m_quad.m128_f32;
  v3->m_size = v4;
  v11 = 1;
  v4 = (signed int)v4;
  v12 = 1i64;
  for ( *v10 = 0i64; v12 < v4; ++v11 )
  {
    hkaiEdgeGeometry::calculateFaceNormal(
      v7,
      v6->m_faceStartEdges.m_data[v12],
      v6->m_faceStartEdges.m_data[v12 + 1],
      &v3->m_data[v11]);
    ++v12;
  }
}

// File Line: 185
// RVA: 0xB9A240
void __fastcall hkaiEdgeGeometry::calculateFaceNormal(hkaiEdgeGeometry *this, hkaiFaceEdges *faceEdges, int i, hkVector4f *normalOut)
{
  hkaiEdgeGeometry::calculateFaceNormal(
    this,
    faceEdges->m_faceStartEdges.m_data[i],
    faceEdges->m_faceStartEdges.m_data[i + 1],
    normalOut);
}

// File Line: 195
// RVA: 0xB99400
void __fastcall hkaiEdgeGeometry::removeFace(hkaiEdgeGeometry *this, int faceIndexIn)
{
  int v2; // er9
  hkaiEdgeGeometry *v3; // r10
  int v4; // edi
  __int64 v5; // rax
  int v6; // edi
  hkaiEdgeGeometry::Face *v7; // r8
  signed __int64 v8; // rcx
  signed __int64 v9; // r11
  int v10; // eax
  unsigned __int64 v11; // r8
  signed __int64 v12; // rsi
  signed __int64 v13; // rbx
  _DWORD *v14; // rax
  _DWORD *v15; // rdx
  int v16; // ecx
  int v17; // eax
  signed __int64 v18; // rbx
  int v19; // eax
  int v20; // er9
  hkResult result; // [rsp+48h] [rbp+10h]

  v2 = faceIndexIn;
  v3 = this;
  if ( faceIndexIn > 0 )
  {
    v4 = this->m_faces.m_size--;
    v5 = this->m_faces.m_size;
    v6 = v4 - 1;
    if ( (_DWORD)v5 != faceIndexIn )
    {
      v7 = &this->m_faces.m_data[faceIndexIn];
      v8 = 3i64;
      v9 = 12 * v5 - 12i64 * faceIndexIn;
      do
      {
        v10 = *(unsigned int *)((char *)&v7->m_data + v9);
        v7 = (hkaiEdgeGeometry::Face *)((char *)v7 + 4);
        *(_DWORD *)&v7[-1].m_flags.m_storage = v10;
        --v8;
      }
      while ( v8 );
    }
    v11 = (unsigned __int64)v3->m_edges.m_data;
    v12 = (signed __int64)&v3->m_edges;
    v13 = v11 + 16i64 * v3->m_edges.m_size;
    v14 = (_DWORD *)(v13 - 16);
    if ( v13 - 16 >= v11 )
    {
      v15 = (_DWORD *)(v13 - 16);
      do
      {
        v16 = v14[2];
        if ( v16 == v2 )
        {
          if ( v14 != v15 )
          {
            *v14 = *v15;
            v14[1] = v15[1];
            v14[2] = v15[2];
            v14[3] = v15[3];
          }
          v13 -= 16i64;
          v15 -= 4;
        }
        else if ( v16 == v6 )
        {
          v14[2] = v2;
        }
        v14 -= 4;
      }
      while ( (unsigned __int64)v14 >= v11 );
    }
    v17 = v3->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
    v18 = (signed __int64)(v13 - v11) >> 4;
    if ( v17 < (signed int)v18 )
    {
      v19 = 2 * v17;
      v20 = v18;
      if ( (signed int)v18 < v19 )
        v20 = v19;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v3->m_edges,
        v20,
        16);
    }
    *(_DWORD *)(v12 + 8) = v18;
  }
}

// File Line: 241
// RVA: 0xB99B90
hkResult *__fastcall hkaiEdgeGeometry::concat(hkaiEdgeGeometry *this, hkResult *result, hkaiEdgeGeometry *geom)
{
  int v3; // er9
  int v4; // er14
  int v5; // eax
  int v6; // er13
  hkaiEdgeGeometry *v7; // rdi
  hkResult *v8; // rbx
  hkaiEdgeGeometry *v9; // rbp
  int v10; // eax
  __int64 v12; // r12
  int v13; // er15
  int v14; // eax
  int v15; // er9
  int v16; // eax
  int v17; // er9
  int v18; // eax
  signed __int64 v19; // r12
  int v20; // eax
  int v21; // er15
  int v22; // er9
  int v23; // eax
  int v24; // eax
  hkArray<hkaiEdgeGeometry::Face,hkContainerHeapAllocator> *v25; // rsi
  int v26; // er9
  int v27; // eax
  int v28; // eax
  __int64 v29; // r15
  int v30; // ebp
  int v31; // eax
  int v32; // er9
  int v33; // eax
  hkaiEdgeGeometry::Face *v34; // rdx
  signed __int64 v35; // r8
  __int64 v36; // rcx
  unsigned int v37; // eax
  int v38; // eax
  __m128 *v39; // r10
  __int64 v40; // r11
  _DWORD *v41; // r9
  int v42; // edx
  int v43; // er8
  int v44; // eax
  hkaiEdgeGeometry::Edge *v45; // r10
  signed __int64 v46; // r9
  signed __int64 v47; // r8
  signed __int64 v48; // rdx
  signed __int64 v49; // r10
  int v50; // ecx
  hkResult v51[2]; // [rsp+30h] [rbp-48h]
  hkResult v52; // [rsp+38h] [rbp-40h]
  hkResult resulta; // [rsp+80h] [rbp+8h]
  hkResult v54; // [rsp+90h] [rbp+18h]
  hkResult v55; // [rsp+98h] [rbp+20h]

  v3 = geom->m_edges.m_size + this->m_edges.m_size;
  v4 = this->m_vertices.m_size;
  v5 = this->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
  v6 = this->m_faces.m_size - 1;
  v7 = geom;
  v8 = result;
  v9 = this;
  if ( v5 >= v3 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    v10 = 2 * v5;
    if ( v3 < v10 )
      v3 = v10;
    hkArrayUtil::_reserve(
      &resulta,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_edges,
      v3,
      16);
    if ( resulta.m_enum )
    {
      v8->m_enum = 1;
      return v8;
    }
  }
  v12 = v9->m_edges.m_size;
  v13 = v7->m_edges.m_size;
  v14 = v9->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
  v15 = v12 + v13;
  if ( v14 < (signed int)v12 + v13 )
  {
    v16 = 2 * v14;
    if ( v15 < v16 )
      v15 = v16;
    hkArrayUtil::_reserve(v51, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v9->m_edges, v15, 16);
  }
  v9->m_edges.m_size += v13;
  v17 = v9->m_vertices.m_size + v7->m_vertices.m_size;
  v18 = v9->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  v19 = (signed __int64)&v9->m_edges.m_data[v12];
  if ( v18 >= v17 )
  {
    v54.m_enum = 0;
    goto LABEL_17;
  }
  v20 = 2 * v18;
  if ( v17 < v20 )
    v17 = v20;
  hkArrayUtil::_reserve(&v54, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v9->m_vertices, v17, 16);
  if ( v54.m_enum == HK_SUCCESS )
  {
LABEL_17:
    v21 = v7->m_vertices.m_size;
    v22 = v9->m_vertices.m_size + v21;
    v51[0] = (hkResult)v9->m_vertices.m_size;
    v23 = v9->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v23 < v22 )
    {
      v24 = 2 * v23;
      if ( v22 < v24 )
        v22 = v24;
      hkArrayUtil::_reserve(
        &v52,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v9->m_vertices,
        v22,
        16);
    }
    v9->m_vertices.m_size += v21;
    v25 = &v9->m_faces;
    v26 = v9->m_faces.m_size + v7->m_faces.m_size - 1;
    *(_QWORD *)&v51[0].m_enum = &v9->m_vertices.m_data[v51[0].m_enum];
    v27 = v9->m_faces.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v27 >= v26 )
    {
      v55.m_enum = 0;
    }
    else
    {
      v28 = 2 * v27;
      if ( v26 < v28 )
        v26 = v28;
      hkArrayUtil::_reserve(&v55, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v9->m_faces, v26, 12);
      if ( v55.m_enum )
      {
        v8->m_enum = 1;
        return v8;
      }
    }
    v29 = v9->m_faces.m_size;
    v30 = v7->m_faces.m_size - 1;
    v31 = v25->m_capacityAndFlags & 0x3FFFFFFF;
    v32 = v29 + v30;
    if ( v31 < (signed int)v29 + v30 )
    {
      v33 = 2 * v31;
      if ( v32 < v33 )
        v32 = v33;
      hkArrayUtil::_reserve(&v52, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v25, v32, 12);
    }
    v25->m_size += v30;
    v34 = v7->m_faces.m_data + 1;
    v35 = (signed __int64)&v25->m_data[v29];
    v36 = (unsigned int)(3 * (v7->m_faces.m_size - 1));
    if ( (signed int)v36 > 0 )
    {
      do
      {
        v37 = v34->m_data;
        v35 += 4i64;
        v34 = (hkaiEdgeGeometry::Face *)((char *)v34 + 4);
        *(_DWORD *)(v35 - 4) = v37;
        --v36;
      }
      while ( v36 );
    }
    v38 = v7->m_vertices.m_size;
    v39 = &v7->m_vertices.m_data->m_quad;
    if ( v38 > 0 )
    {
      v40 = (unsigned int)v38;
      v41 = (_DWORD *)(*(_QWORD *)&v51[0].m_enum + 8i64);
      do
      {
        v42 = v39->m128_u64[1];
        v43 = HIDWORD(v39->m128_u64[1]);
        v44 = v39->m128_u64[0];
        *(v41 - 1) = HIDWORD(v39->m128_u64[0]);
        *v41 = v42;
        v41[1] = v43;
        *(v41 - 2) = v44;
        v41 += 4;
        ++v39;
        --v40;
      }
      while ( v40 );
    }
    v45 = v7->m_edges.m_data;
    v46 = (signed __int64)&v45[v7->m_edges.m_size];
    if ( v45 != (hkaiEdgeGeometry::Edge *)v46 )
    {
      v47 = (signed __int64)&v45->m_face;
      v48 = v19 + 8;
      v49 = (signed __int64)v45 - v19;
      do
      {
        v50 = *(_DWORD *)(v49 + v48 - 8);
        v48 += 16i64;
        v47 += 16i64;
        *(_DWORD *)(v48 - 24) = v4 + v50;
        *(_DWORD *)(v48 - 20) = v4 + *(_DWORD *)(v47 - 20);
        *(_DWORD *)(v48 - 16) = v6 + *(_DWORD *)(v47 - 16);
        *(_DWORD *)(v48 - 12) = *(_DWORD *)(v47 - 12);
      }
      while ( v48 + v49 - 8 != v46 );
    }
    v8->m_enum = 0;
    return v8;
  }
  v8->m_enum = 1;
  return v8;
}

// File Line: 287
// RVA: 0xB99520
hkResult *__fastcall hkaiEdgeGeometry::removeFaces(hkaiEdgeGeometry *this, hkResult *result, const unsigned int *faceIndices, int numRemoveFaces)
{
  __int64 v4; // r13
  const unsigned int *v5; // r12
  hkResult *v6; // rsi
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v7; // r15
  hkResult *v8; // rax
  hkResultEnum v9; // edi
  signed __int64 v10; // r14
  signed int v11; // ecx
  void *v12; // rdx
  signed int v13; // er8
  int v14; // er9
  int v15; // er9
  hkResultEnum v16; // eax
  __int64 v17; // r8
  int v18; // ecx
  int v19; // er9
  _DWORD *v20; // rdi
  __int64 v21; // rcx
  __int64 v22; // rdx
  __int64 v23; // rcx
  hkRelocationInfo::Import *v24; // r13
  signed __int64 v25; // rcx
  signed __int64 v26; // r9
  _DWORD *v27; // r8
  signed __int64 v28; // r11
  _DWORD *v29; // rdi
  unsigned __int64 v30; // rdx
  __int64 v31; // r12
  int v32; // eax
  int v33; // eax
  int v34; // er9
  char *v35; // rdi
  __int64 v36; // rcx
  hkRelocationInfo::Import *v37; // rdx
  __int64 v38; // r14
  int v39; // edi
  signed __int64 v40; // r14
  signed int *v41; // r8
  int v42; // er11
  __int64 v43; // rcx
  int v44; // er9
  int *v45; // r10
  int v46; // eax
  signed __int64 v47; // rdx
  int v48; // eax
  int v49; // er9
  int v50; // er8
  int v51; // eax
  int v52; // eax
  int v53; // er9
  __int64 v54; // rdx
  __int64 v55; // rdi
  __int64 v56; // rcx
  hkResult resulta; // [rsp+30h] [rbp-40h]
  hkResult v58; // [rsp+34h] [rbp-3Ch]
  hkResult v59; // [rsp+38h] [rbp-38h]
  char *v60; // [rsp+40h] [rbp-30h]
  int v61; // [rsp+48h] [rbp-28h]
  int v62; // [rsp+4Ch] [rbp-24h]
  _DWORD *array; // [rsp+50h] [rbp-20h]
  int v64; // [rsp+58h] [rbp-18h]
  int v65; // [rsp+5Ch] [rbp-14h]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> a; // [rsp+60h] [rbp-10h]
  hkResult v67; // [rsp+B8h] [rbp+48h]

  v4 = numRemoveFaces;
  v5 = faceIndices;
  v6 = result;
  v7 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)this;
  if ( !numRemoveFaces )
  {
    v8 = result;
    result->m_enum = 0;
    return v8;
  }
  if ( numRemoveFaces != 1 )
  {
    v9 = this->m_vertices.m_size;
    v10 = this->m_faces.m_size;
    v11 = 2147483648;
    v58.m_enum = v9;
    array = 0i64;
    v64 = 0;
    v65 = 2147483648;
    v12 = 0i64;
    v60 = 0i64;
    v61 = 0;
    v13 = 2147483648;
    v62 = 2147483648;
    if ( (signed int)v10 <= 0 )
    {
      resulta.m_enum = 0;
    }
    else
    {
      v14 = v10;
      if ( (signed int)v10 < 0 )
        v14 = 0;
      hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v14, 4);
      v11 = v65;
      v13 = v62;
      v12 = v60;
    }
    if ( (v13 & 0x3FFFFFFF) >= v9 )
    {
      v16 = 0;
      v67.m_enum = 0;
    }
    else
    {
      v15 = v9;
      if ( v9 < 2 * (v13 & 0x3FFFFFFF) )
        v15 = 2 * (v13 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&v67, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v60, v15, 4);
      v11 = v65;
      v13 = v62;
      v12 = v60;
      v16 = v67.m_enum;
    }
    if ( resulta.m_enum || v16 )
    {
      v61 = 0;
      v6->m_enum = 1;
      if ( v13 >= 0 )
      {
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v12,
          4 * v13);
        v11 = v65;
      }
      v60 = 0i64;
      v62 = 2147483648;
      v64 = 0;
      if ( v11 < 0 )
        return v6;
      v17 = (unsigned int)(4 * v11);
      goto LABEL_77;
    }
    v18 = v11 & 0x3FFFFFFF;
    if ( v18 < (signed int)v10 )
    {
      v19 = v10;
      if ( (signed int)v10 < 2 * v18 )
        v19 = 2 * v18;
      hkArrayUtil::_reserve(&v59, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v19, 4);
    }
    v20 = &array[v64];
    v21 = (signed int)v10 - v64;
    if ( (signed int)v10 - v64 > 0 )
    {
      while ( v21 )
      {
        *v20 = 0;
        ++v20;
        --v21;
      }
    }
    v64 = v10;
    v22 = 0i64;
    if ( (signed int)v4 > 0 )
    {
      do
      {
        v23 = (signed int)v5[v22++];
        array[v23] = 1;
      }
      while ( v22 < v4 );
    }
    v24 = v7[2].m_data;
    v25 = 1i64;
    v26 = (signed __int64)&v24->m_identifier + 4;
    if ( v10 > 1 )
    {
      v27 = (_DWORD *)((char *)&v24->m_identifier + 4);
      v28 = 12i64;
      do
      {
        v29 = &array[v25];
        if ( array[v25] )
        {
          *v29 = 0;
        }
        else
        {
          v26 += 12i64;
          v30 = ((unsigned __int64)((unsigned __int128)(v28 * (signed __int128)3074457345618258603i64) >> 64) >> 63)
              + ((signed __int64)((unsigned __int128)(v28 * (signed __int128)3074457345618258603i64) >> 64) >> 1);
          v28 += 12i64;
          *v29 = v30;
          *(_DWORD *)(v26 - 12) = *v27;
          *(_DWORD *)(v26 - 8) = v27[1];
          *(_DWORD *)(v26 - 4) = v27[2];
        }
        ++v25;
        v27 += 3;
      }
      while ( v25 < v10 );
    }
    v31 = v58.m_enum;
    *array = 0;
    v32 = v62 & 0x3FFFFFFF;
    v7[2].m_size = ((unsigned __int64)((unsigned __int128)((v26 - (signed __int64)v24)
                                                         * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                 + ((signed __int64)((unsigned __int128)((v26 - (signed __int64)v24)
                                                       * (signed __int128)3074457345618258603i64) >> 64) >> 1);
    if ( v32 < (signed int)v31 )
    {
      v33 = 2 * v32;
      v34 = v31;
      if ( (signed int)v31 < v33 )
        v34 = v33;
      hkArrayUtil::_reserve(&v59, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v60, v34, 4);
    }
    v35 = &v60[4 * v61];
    v36 = (signed int)v31 - v61;
    if ( (signed int)v31 - v61 > 0 )
    {
      while ( v36 )
      {
        *(_DWORD *)v35 = -1;
        v35 += 4;
        --v36;
      }
    }
    v37 = v7[1].m_data;
    v38 = v7[1].m_size;
    v61 = v31;
    v39 = 0;
    v40 = (signed __int64)&v37[v38];
    if ( v37 != (hkRelocationInfo::Import *)v40 )
    {
      v41 = &v37->m_fromOffset + 1;
      do
      {
        v42 = array[v41[1]];
        if ( v42 )
        {
          v43 = *(v41 - 1);
          v44 = *(_DWORD *)&v60[4 * v43];
          if ( v44 == -1 )
          {
            v44 = v39++;
            *(_DWORD *)&v60[4 * v43] = v44;
          }
          v45 = (int *)&v60[4 * *v41];
          v46 = *v45;
          if ( *v45 == -1 )
          {
            v46 = v39++;
            *v45 = v46;
          }
          v37->m_fromOffset = v44;
          *(&v37->m_fromOffset + 1) = v46;
          LODWORD(v37->m_identifier) = v42;
          ++v37;
          HIDWORD(v37[-1].m_identifier) = v41[2];
        }
        v41 += 4;
      }
      while ( v41 - 1 != (signed int *)v40 );
    }
    v47 = (char *)v37 - (char *)v7[1].m_data;
    v48 = 2147483648;
    a.m_data = 0i64;
    a.m_size = 0;
    a.m_capacityAndFlags = 2147483648;
    v7[1].m_size = v47 >> 4;
    if ( v39 <= 0 )
    {
      v58.m_enum = 0;
    }
    else
    {
      v49 = v39;
      if ( v39 < 0 )
        v49 = 0;
      hkArrayUtil::_reserve(&v58, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &a, v49, 16);
      if ( v58.m_enum )
      {
        v50 = a.m_capacityAndFlags;
        v6->m_enum = 1;
        a.m_size = 0;
        if ( v50 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            a.m_data,
            16 * v50);
        a.m_data = 0i64;
        a.m_capacityAndFlags = 2147483648;
LABEL_73:
        v61 = 0;
        if ( v62 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v60,
            4 * v62);
        v64 = 0;
        v62 = 2147483648;
        v60 = 0i64;
        if ( v65 < 0 )
          return v6;
        v17 = (unsigned int)(4 * v65);
LABEL_77:
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          array,
          v17);
        return v6;
      }
      v48 = a.m_capacityAndFlags;
    }
    v51 = v48 & 0x3FFFFFFF;
    if ( v51 < v39 )
    {
      v52 = 2 * v51;
      v53 = v39;
      if ( v39 < v52 )
        v53 = v52;
      hkArrayUtil::_reserve(&v59, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &a, v53, 16);
    }
    a.m_size = v39;
    v54 = 0i64;
    if ( (signed int)v31 > 0 )
    {
      v55 = 0i64;
      do
      {
        v56 = *(signed int *)&v60[4 * v54];
        if ( (_DWORD)v56 != -1 )
          a.m_data[v56] = v7[3].m_data[v55];
        ++v54;
        ++v55;
      }
      while ( v54 < v31 );
    }
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(v7 + 3, &a);
    a.m_size = 0;
    if ( a.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        a.m_data,
        16 * a.m_capacityAndFlags);
    v6->m_enum = 0;
    goto LABEL_73;
  }
  hkaiEdgeGeometry::removeFace(this, *faceIndices);
  v6->m_enum = 0;
  return v6;
}

// File Line: 429
// RVA: 0xB99A50
void __fastcall hkaiEdgeGeometry::removeFacesEdges(hkaiEdgeGeometry *this, const unsigned int *faceIndices, int numRemoveFaces)
{
  __int64 v3; // rbx
  int v4; // er8
  hkaiEdgeGeometry *v5; // rdi
  const unsigned int *v6; // rsi
  __int64 v7; // r9
  __int64 v8; // rcx
  hkaiEdgeGeometry::Edge *v9; // rax
  hkaiEdgeGeometry::Edge *v10; // r9
  signed __int64 i; // r10
  signed __int64 v12; // r9
  int v13; // er8
  _DWORD *v14; // [rsp+20h] [rbp-28h]
  int v15; // [rsp+28h] [rbp-20h]
  int v16; // [rsp+2Ch] [rbp-1Ch]
  int v17; // [rsp+30h] [rbp-18h]

  if ( numRemoveFaces )
  {
    v3 = numRemoveFaces;
    v4 = this->m_faces.m_size;
    v5 = this;
    v6 = faceIndices;
    v14 = 0i64;
    v15 = 0;
    v16 = 2147483648;
    v17 = 0;
    hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::setSizeAndFill(
      (hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > > *)&v14,
      0,
      v4,
      0);
    v7 = 0i64;
    if ( (signed int)v3 > 0 )
    {
      do
      {
        v8 = (signed int)v6[v7++];
        v14[v8 >> 5] |= 1 << (v8 & 0x1F);
      }
      while ( v7 < v3 );
    }
    v9 = v5->m_edges.m_data;
    v10 = v9;
    for ( i = (signed __int64)&v9[v5->m_edges.m_size]; v9 != (hkaiEdgeGeometry::Edge *)i; ++v9 )
    {
      if ( !((v14[(signed __int64)(signed int)v9->m_face >> 5] >> (v9->m_face & 0x1F)) & 1) )
      {
        ++v10;
        v10[-1].m_a = v9->m_a;
        v10[-1].m_b = v9->m_b;
        v10[-1].m_face = v9->m_face;
        v10[-1].m_data = v9->m_data;
      }
    }
    v12 = (char *)v10 - (char *)v5->m_edges.m_data;
    v13 = v16;
    v15 = 0;
    v5->m_edges.m_size = v12 >> 4;
    if ( v13 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v14,
        4 * v13);
  }
}

// File Line: 459
// RVA: 0xB98F00
hkResult *__fastcall hkaiEdgeGeometry::set(hkaiEdgeGeometry *this, hkResult *result, hkaiEdgeGeometry *geom)
{
  int v3; // er9
  hkaiEdgeGeometry *v4; // rbx
  hkResult *v5; // rsi
  hkaiEdgeGeometry *v6; // rbp
  __int64 v7; // rax
  hkaiEdgeGeometry::Edge *v8; // rcx
  __int64 v9; // rdx
  char *v10; // r8
  unsigned int v11; // eax
  int v12; // er9
  int v13; // eax
  __int64 v14; // rax
  hkaiEdgeGeometry::Face *v15; // rcx
  __int64 v16; // rdx
  char *v17; // r8
  unsigned int v18; // eax
  int v19; // er9
  __int64 v20; // rax
  hkVector4f *v21; // rcx
  __int64 v22; // rdx
  char *v23; // r8
  hkVector4f v24; // xmm0
  hkResult *v25; // rax
  int v26; // [rsp+30h] [rbp-38h]
  hkResult resulta; // [rsp+70h] [rbp+8h]
  hkResult v28; // [rsp+80h] [rbp+18h]
  hkResult v29; // [rsp+88h] [rbp+20h]

  v3 = geom->m_edges.m_size;
  v4 = geom;
  v5 = result;
  v6 = this;
  if ( (this->m_edges.m_capacityAndFlags & 0x3FFFFFFF) >= v3 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    hkArrayUtil::_reserve(
      &resulta,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_edges,
      v3,
      16);
    if ( resulta.m_enum )
      goto LABEL_12;
  }
  if ( (v6->m_edges.m_capacityAndFlags & 0x3FFFFFFF) < v4->m_edges.m_size )
  {
    if ( v6->m_edges.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v6->m_edges.m_data,
        16 * v6->m_edges.m_capacityAndFlags);
    v26 = 16 * v4->m_edges.m_size;
    v6->m_edges.m_data = (hkaiEdgeGeometry::Edge *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                     (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                     &v26);
    v6->m_edges.m_capacityAndFlags = v26 / 16;
  }
  v7 = v4->m_edges.m_size;
  v8 = v6->m_edges.m_data;
  v6->m_edges.m_size = v7;
  v9 = v7;
  if ( (signed int)v7 > 0 )
  {
    v10 = (char *)((char *)v4->m_edges.m_data - (char *)v8);
    do
    {
      v11 = *(unsigned int *)((char *)&v8->m_a + (_QWORD)v10);
      ++v8;
      v8[-1].m_a = v11;
      v8[-1].m_b = *(_DWORD *)((char *)v8 + (_QWORD)v10 - 12);
      v8[-1].m_face = *(_DWORD *)((char *)v8 + (_QWORD)v10 - 8);
      v8[-1].m_data = *(_DWORD *)((char *)v8 + (_QWORD)v10 - 4);
      --v9;
    }
    while ( v9 );
  }
LABEL_12:
  v12 = v4->m_faces.m_size;
  if ( (v6->m_faces.m_capacityAndFlags & 0x3FFFFFFF) >= v12 )
  {
    v28.m_enum = 0;
  }
  else
  {
    hkArrayUtil::_reserve(&v28, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v6->m_faces, v12, 12);
    if ( v28.m_enum )
      goto LABEL_23;
  }
  v13 = v6->m_faces.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v13 < v4->m_faces.m_size )
  {
    if ( v6->m_faces.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v6->m_faces.m_data,
        12 * v13);
    v26 = 12 * v4->m_faces.m_size;
    v6->m_faces.m_data = (hkaiEdgeGeometry::Face *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                     (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                     &v26);
    v6->m_faces.m_capacityAndFlags = v26 / 12;
  }
  v14 = v4->m_faces.m_size;
  v15 = v6->m_faces.m_data;
  v6->m_faces.m_size = v14;
  v16 = v14;
  if ( (signed int)v14 > 0 )
  {
    v17 = (char *)((char *)v4->m_faces.m_data - (char *)v15);
    do
    {
      v18 = *(unsigned int *)((char *)&v15->m_data + (_QWORD)v17);
      ++v15;
      v15[-1].m_data = v18;
      v15[-1].m_faceIndex = *(_DWORD *)((char *)v15 + (_QWORD)v17 - 8);
      *(_DWORD *)&v15[-1].m_flags.m_storage = *(_DWORD *)((char *)v15 + (_QWORD)v17 - 4);
      --v16;
    }
    while ( v16 );
  }
LABEL_23:
  v19 = v4->m_vertices.m_size;
  if ( (v6->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) >= v19 )
  {
    v29.m_enum = 0;
  }
  else
  {
    hkArrayUtil::_reserve(&v29, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v6->m_vertices, v19, 16);
    if ( v29.m_enum )
      goto LABEL_34;
  }
  if ( (v6->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) < v4->m_vertices.m_size )
  {
    if ( v6->m_vertices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v6->m_vertices.m_data,
        16 * v6->m_vertices.m_capacityAndFlags);
    v26 = 16 * v4->m_vertices.m_size;
    v6->m_vertices.m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                            &v26);
    v6->m_vertices.m_capacityAndFlags = v26 / 16;
  }
  v20 = v4->m_vertices.m_size;
  v21 = v6->m_vertices.m_data;
  v6->m_vertices.m_size = v20;
  v22 = v20;
  if ( (signed int)v20 > 0 )
  {
    v23 = (char *)((char *)v4->m_vertices.m_data - (char *)v21);
    do
    {
      v24.m_quad = *(__m128 *)((char *)v21 + (_QWORD)v23);
      ++v21;
      v21[-1] = (hkVector4f)v24.m_quad;
      --v22;
    }
    while ( v22 );
  }
LABEL_34:
  if ( resulta.m_enum || v28.m_enum || v29.m_enum )
  {
    v5->m_enum = 1;
    v25 = v5;
  }
  else
  {
    v5->m_enum = 0;
    v25 = v5;
  }
  return v25;
}

// File Line: 471
// RVA: 0xB98BC0
hkResult *__fastcall hkaiEdgeGeometry::set(hkaiEdgeGeometry *this, hkResult *result, hkGeometry *geom, hkFlags<enum hkaiEdgeGeometry::FaceFlagBits,unsigned char> newFaceFlags, bool setFaceData)
{
  int v5; // er9
  hkGeometry *v6; // rbp
  hkResult *v7; // r15
  hkaiEdgeGeometry *v8; // r13
  __int64 v9; // rax
  hkVector4f *v10; // rcx
  __int64 v11; // rdx
  char *v12; // rdi
  hkVector4f v13; // xmm0
  hkResult *v14; // rax
  int v15; // er9
  int v16; // er9
  int v17; // eax
  signed __int64 v18; // rbx
  int v19; // eax
  int v20; // er12
  int v21; // eax
  int v22; // eax
  int v23; // er9
  __int64 v24; // rax
  signed __int64 v25; // rsi
  __int64 v26; // rcx
  int v27; // eax
  _DWORD *v28; // rdi
  unsigned __int64 i; // rcx
  __int64 v30; // r12
  int v31; // esi
  int v32; // eax
  int v33; // eax
  int v34; // er9
  hkaiEdgeGeometry::Edge *v35; // rax
  __int64 v36; // r9
  bool v37; // r10
  signed int v38; // edi
  __int64 v39; // r8
  hkGeometry::Triangle *v40; // rsi
  int v41; // ecx
  int v42; // ecx
  int v43; // ecx
  hkaiEdgeGeometry::Face *v44; // rax
  hkResult v45; // [rsp+30h] [rbp-58h]
  hkResult v46; // [rsp+34h] [rbp-54h]
  int v47; // [rsp+40h] [rbp-48h]
  hkResult resulta; // [rsp+90h] [rbp+8h]
  hkResult v49; // [rsp+A0h] [rbp+18h]
  char v50; // [rsp+A8h] [rbp+20h]

  v50 = newFaceFlags.m_storage;
  v5 = geom->m_vertices.m_size;
  v6 = geom;
  v7 = result;
  v8 = this;
  if ( (this->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) >= v5 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    hkArrayUtil::_reserve(
      &resulta,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_vertices,
      v5,
      16);
    if ( resulta.m_enum )
    {
LABEL_13:
      v14 = v7;
      v7->m_enum = 1;
      return v14;
    }
  }
  if ( (v8->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) < v6->m_vertices.m_size )
  {
    if ( v8->m_vertices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v8->m_vertices.m_data,
        16 * v8->m_vertices.m_capacityAndFlags);
    v49.m_enum = 16 * v6->m_vertices.m_size;
    v8->m_vertices.m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                            (int *)&v49);
    v8->m_vertices.m_capacityAndFlags = v49.m_enum / 16;
  }
  v9 = v6->m_vertices.m_size;
  v10 = v8->m_vertices.m_data;
  v8->m_vertices.m_size = v9;
  v11 = v9;
  if ( (signed int)v9 > 0 )
  {
    v12 = (char *)((char *)v6->m_vertices.m_data - (char *)v10);
    do
    {
      v13.m_quad = *(__m128 *)((char *)v10 + (_QWORD)v12);
      ++v10;
      v10[-1] = (hkVector4f)v13.m_quad;
      --v11;
    }
    while ( v11 );
  }
  if ( resulta.m_enum )
    goto LABEL_13;
  v15 = v6->m_triangles.m_size;
  LOBYTE(v47) = v50;
  v16 = v15 + 1;
  v17 = v8->m_faces.m_capacityAndFlags & 0x3FFFFFFF;
  v18 = 1i64;
  if ( v17 >= v16 )
  {
    v45.m_enum = 0;
    goto LABEL_20;
  }
  v19 = 2 * v17;
  if ( v16 < v19 )
    v16 = v19;
  hkArrayUtil::_reserve(&v45, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v8->m_faces, v16, 12);
  if ( v45.m_enum == HK_SUCCESS )
  {
LABEL_20:
    v20 = v6->m_triangles.m_size + 1;
    v21 = v8->m_faces.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v21 < v20 )
    {
      v22 = 2 * v21;
      v23 = v6->m_triangles.m_size + 1;
      if ( v20 < v22 )
        v23 = v22;
      hkArrayUtil::_reserve(&v49, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v8->m_faces, v23, 12);
    }
    v24 = v8->m_faces.m_size;
    v25 = (signed __int64)&v8->m_faces.m_data[v24];
    v26 = v20 - (signed int)v24;
    if ( v20 - (signed int)v24 > 0 )
    {
      v27 = v47;
      v28 = (_DWORD *)(v25 + 12);
      *(_QWORD *)v25 = 0i64;
      *(_DWORD *)(v25 + 8) = v27;
      for ( i = (unsigned __int64)(12 * v26 - 12) >> 2; i; --i )
      {
        *v28 = *(_DWORD *)v25;
        v25 += 4i64;
        ++v28;
      }
    }
    v8->m_faces.m_size = v20;
    v30 = v6->m_triangles.m_size;
    v31 = 3 * v30;
    v32 = v8->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v32 >= 3 * (signed int)v30 )
    {
      v46.m_enum = 0;
    }
    else
    {
      v33 = 2 * v32;
      v34 = 3 * v30;
      if ( v31 < v33 )
        v34 = v33;
      hkArrayUtil::_reserve(&v46, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v8->m_edges, v34, 16);
      if ( v46.m_enum )
      {
        v7->m_enum = 1;
        return v7;
      }
    }
    v8->m_edges.m_size = v31;
    v35 = v8->m_edges.m_data;
    v36 = v30;
    if ( (signed int)v30 > 0 )
    {
      v37 = setFaceData;
      v38 = 1;
      v39 = 0i64;
      do
      {
        v35 += 3;
        v40 = &v6->m_triangles.m_data[v39];
        v35[-3].m_a = v40->m_a;
        v41 = v40->m_b;
        v35[-3].m_face = v38;
        v35[-3].m_data = 0;
        v35[-3].m_b = v41;
        v35[-2].m_a = v40->m_b;
        v42 = v40->m_c;
        v35[-2].m_face = v38;
        v35[-2].m_data = 0;
        v35[-2].m_b = v42;
        v35[-1].m_a = v40->m_c;
        v43 = v40->m_a;
        v35[-1].m_face = v38;
        v35[-1].m_data = 0;
        v35[-1].m_b = v43;
        if ( v37 )
        {
          v8->m_faces.m_data[v18].m_faceIndex = v38;
          v8->m_faces.m_data[v18].m_data = v40->m_material;
        }
        ++v38;
        ++v18;
        ++v39;
        --v36;
      }
      while ( v36 );
    }
    v44 = v8->m_faces.m_data;
    v7->m_enum = 0;
    v44->m_flags.m_storage = 0;
    return v7;
  }
  v7->m_enum = 1;
  return v7;
}

// File Line: 526
// RVA: 0xB9A460
void __fastcall hkaiEdgeGeometry::swap(hkaiEdgeGeometry *this, hkaiEdgeGeometry *geom)
{
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v2; // rbx
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v3; // rdi
  int v4; // eax
  int v5; // eax

  v2 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)geom;
  v3 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)this;
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&this->m_edges,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&geom->m_edges);
  if ( v2[2].m_size == 1 )
  {
    v4 = v2[2].m_capacityAndFlags;
    v2[2].m_size = 0;
    if ( v4 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v2[2].m_data,
        12 * (v4 & 0x3FFFFFFF));
    v2[2].m_data = 0i64;
    v2[2].m_capacityAndFlags = 2147483648;
  }
  if ( v3[2].m_size == 1 )
  {
    v5 = v3[2].m_capacityAndFlags;
    v3[2].m_size = 0;
    if ( v5 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v3[2].m_data,
        12 * (v5 & 0x3FFFFFFF));
    v3[2].m_data = 0i64;
    v3[2].m_capacityAndFlags = 2147483648;
  }
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(v3 + 2, v2 + 2);
  if ( !v3[2].m_size )
  {
    v3[2].m_size = 1;
    v3[2].m_capacityAndFlags = -2147483647;
    v3[2].m_data = (hkRelocationInfo::Import *)&v3[4];
  }
  if ( !v2[2].m_size )
  {
    v2[2].m_size = 1;
    v2[2].m_capacityAndFlags = -2147483647;
    v2[2].m_data = (hkRelocationInfo::Import *)&v2[4];
  }
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(v3 + 3, v2 + 3);
}

// File Line: 564
// RVA: 0xB9A570
hkResult *__fastcall hkaiEdgeGeometry::checkConsistency(hkaiEdgeGeometry *this, hkResult *result)
{
  hkResult *v2; // rbx
  hkaiEdgeGeometryValidator checker; // [rsp+20h] [rbp-58h]

  v2 = result;
  checker.m_faceEdges.m_faceEdges.m_capacityAndFlags = 2147483648;
  checker.m_faceEdges.m_faceStartEdges.m_capacityAndFlags = 2147483648;
  checker.m_vertexIndexMap.m_capacityAndFlags = 2147483648;
  checker.m_faceEdges.m_faceEdges.m_data = 0i64;
  checker.m_faceEdges.m_faceEdges.m_size = 0;
  checker.m_faceEdges.m_faceStartEdges.m_data = 0i64;
  checker.m_faceEdges.m_faceStartEdges.m_size = 0;
  checker.m_vertexIndexMap.m_data = 0i64;
  checker.m_vertexIndexMap.m_size = 0;
  checker.m_faceIndices.m_data = 0i64;
  checker.m_faceIndices.m_size = 0;
  checker.m_faceIndices.m_capacityAndFlags = 2147483648;
  checker.m_indicesCount.m_data = 0i64;
  checker.m_indicesCount.m_size = 0;
  checker.m_indicesCount.m_capacityAndFlags = 2147483648;
  hkaiEdgeGeometry::checkConsistency(this, result, &checker);
  hkaiEdgeGeometryValidator::~hkaiEdgeGeometryValidator(&checker);
  return v2;
}

// File Line: 570
// RVA: 0xB9A600
hkResult *__fastcall hkaiEdgeGeometry::checkConsistency(hkaiEdgeGeometry *this, hkResult *result, hkaiEdgeGeometryValidator *checker)
{
  hkaiEdgeGeometry *v3; // r12
  hkaiEdgeGeometryValidator *v4; // r13
  hkResult *v5; // r14
  hkResult *v6; // rax
  int v7; // esi
  int v8; // er9
  hkArray<int,hkContainerHeapAllocator> *v9; // r15
  int v10; // eax
  int v11; // eax
  int v12; // ebx
  int v13; // eax
  int v14; // eax
  int v15; // er9
  __int64 v16; // rdx
  int *v17; // rdi
  __int64 v18; // rcx
  hkArray<int,hkContainerHeapAllocator> *v19; // rdi
  hkArray<int,hkContainerHeapAllocator> *v20; // rbx
  __int64 v21; // rcx
  __int64 v22; // rax
  __int64 v23; // rax
  __int64 v24; // r14
  signed int **v25; // r12
  int v26; // esi
  int v27; // eax
  int v28; // eax
  int v29; // er9
  int v30; // eax
  int v31; // eax
  int *v32; // rsi
  unsigned int v33; // eax
  __int64 v34; // rcx
  int v35; // er14
  int v36; // er15
  __int64 v37; // rcx
  int v38; // er14
  int v39; // esi
  int v40; // edx
  int v41; // ecx
  int *v42; // rax
  int v43; // er8
  __int64 v44; // rdx
  signed int v45; // ebx
  int v46; // edi
  int v47; // eax
  _DWORD *v48; // r9
  signed int v49; // er8
  int v50; // er9
  __int64 v51; // r8
  void *v52; // rdx
  __int64 v53; // rcx
  _DWORD *v54; // rdi
  hkaiEdgeGeometry::Edge *v55; // rdi
  signed __int64 v56; // r10
  __int64 v57; // rcx
  signed int v58; // edi
  hkResult v59; // [rsp+30h] [rbp-29h]
  unsigned int v60; // [rsp+34h] [rbp-25h]
  __int64 v61; // [rsp+38h] [rbp-21h]
  hkArray<int,hkContainerHeapAllocator> *v62; // [rsp+40h] [rbp-19h]
  signed int **v63; // [rsp+48h] [rbp-11h]
  __int64 v64; // [rsp+50h] [rbp-9h]
  _DWORD *array; // [rsp+58h] [rbp-1h]
  int v66; // [rsp+60h] [rbp+7h]
  int v67; // [rsp+64h] [rbp+Bh]
  int v68; // [rsp+68h] [rbp+Fh]
  hkaiEdgeGeometry *v69; // [rsp+C0h] [rbp+67h]
  hkResult *v70; // [rsp+C8h] [rbp+6Fh]
  hkaiEdgeGeometryValidator *v71; // [rsp+D0h] [rbp+77h]
  hkResult resulta; // [rsp+D8h] [rbp+7Fh]

  v71 = checker;
  v70 = result;
  v69 = this;
  v3 = this;
  v4 = checker;
  v5 = result;
  hkaiEdgeGeometryValidator::clear(checker);
  if ( v3->m_faces.m_size != 1 )
  {
    hkaiFaceEdges::setGeometry(&v4->m_faceEdges, &resulta, v3);
    if ( resulta.m_enum == 1 )
    {
      v5->m_enum = 1;
      return v5;
    }
    v7 = v4->m_faceEdges.m_faceStartEdges.m_size - 1;
    v60 = v7;
    if ( v7 != v3->m_faces.m_size )
    {
      v5->m_enum = 1;
      return v5;
    }
    v8 = v3->m_vertices.m_size;
    v9 = &v4->m_vertexIndexMap;
    v10 = v4->m_vertexIndexMap.m_capacityAndFlags & 0x3FFFFFFF;
    v62 = &v4->m_vertexIndexMap;
    if ( v10 < v8 )
    {
      v11 = 2 * v10;
      if ( v8 < v11 )
        v8 = v11;
      hkArrayUtil::_reserve(
        &resulta,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v4->m_vertexIndexMap,
        v8,
        4);
      if ( resulta.m_enum )
      {
        v5->m_enum = 1;
        return v5;
      }
    }
    v12 = v3->m_vertices.m_size;
    v13 = v4->m_vertexIndexMap.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v13 < v12 )
    {
      v14 = 2 * v13;
      v15 = v3->m_vertices.m_size;
      if ( v12 < v14 )
        v15 = v14;
      hkArrayUtil::_reserve(
        &resulta,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v4->m_vertexIndexMap,
        v15,
        4);
    }
    v16 = v4->m_vertexIndexMap.m_size;
    v17 = &v9->m_data[v16];
    v18 = v12 - (signed int)v16;
    if ( v12 - (signed int)v16 > 0 )
    {
      while ( v18 )
      {
        *v17 = -1;
        ++v17;
        --v18;
      }
    }
    v4->m_vertexIndexMap.m_size = v12;
    v19 = &v4->m_faceIndices;
    v20 = &v4->m_indicesCount;
    v21 = 0i64;
    v64 = v7;
    v61 = 0i64;
    if ( v7 > 0 )
    {
      while ( 1 )
      {
        v22 = (__int64)v71;
        v4->m_faceIndices.m_size = 0;
        v4->m_indicesCount.m_size = 0;
        v23 = *(_QWORD *)(v22 + 16);
        v24 = *(_QWORD *)(v23 + 8 * v21 + 8);
        v25 = *(signed int ***)(v23 + 8 * v21);
        v63 = (signed int **)v24;
        v26 = 2 * (unsigned __int64)((v24 - (signed __int64)v25) >> 3);
        v27 = v4->m_faceIndices.m_capacityAndFlags & 0x3FFFFFFF;
        if ( v27 >= v26 )
        {
          resulta.m_enum = 0;
        }
        else
        {
          v28 = 2 * v27;
          v29 = 2 * (unsigned __int64)((v24 - (signed __int64)v25) >> 3);
          if ( v26 < v28 )
            v29 = v28;
          hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v19, v29, 4);
          if ( resulta.m_enum )
            goto LABEL_26;
        }
        v30 = v4->m_indicesCount.m_capacityAndFlags & 0x3FFFFFFF;
        if ( v30 >= v26 )
        {
          v59.m_enum = 0;
        }
        else
        {
          v31 = 2 * v30;
          if ( v26 < v31 )
            v26 = v31;
          hkArrayUtil::_reserve(&v59, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v20, v26, 4);
          if ( v59.m_enum )
            goto LABEL_26;
        }
        if ( v25 != (signed int **)v24 )
          break;
LABEL_50:
        v40 = v4->m_indicesCount.m_size;
        v41 = 0;
        if ( v40 > 0 )
        {
          v42 = v20->m_data;
          while ( !*v42 )
          {
            ++v41;
            ++v42;
            if ( v41 >= v40 )
              goto LABEL_54;
          }
LABEL_26:
          v6 = v70;
          v70->m_enum = 1;
          return v6;
        }
LABEL_54:
        v43 = 0;
        if ( v4->m_faceIndices.m_size > 0 )
        {
          v44 = 0i64;
          do
          {
            ++v43;
            ++v44;
            v9->m_data[v19->m_data[v44 - 1]] = -1;
          }
          while ( v43 < v4->m_faceIndices.m_size );
        }
        v21 = v61 + 1;
        v61 = v21;
        if ( v21 >= v64 )
        {
          v5 = v70;
          v3 = v69;
          goto LABEL_59;
        }
      }
      while ( 1 )
      {
        v32 = *v25;
        v33 = (*v25)[2];
        if ( v33 < 1 || v33 >= v60 )
          goto LABEL_26;
        v34 = *v32;
        v35 = v9->m_data[v34];
        if ( v35 < 0 )
        {
          v35 = v4->m_faceIndices.m_size;
          v9->m_data[v34] = v35;
          v36 = *v32;
          if ( v4->m_faceIndices.m_size == (v4->m_faceIndices.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v19, 4);
          v4->m_faceIndices.m_data[v4->m_faceIndices.m_size++] = v36;
          if ( v4->m_indicesCount.m_size == (v4->m_indicesCount.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v20, 4);
          v9 = v62;
          v4->m_indicesCount.m_data[v4->m_indicesCount.m_size++] = 0;
        }
        ++v20->m_data[v35];
        v37 = v32[1];
        v38 = v9->m_data[v37];
        if ( v38 < 0 )
        {
          v38 = v4->m_faceIndices.m_size;
          v9->m_data[v37] = v38;
          v39 = v32[1];
          if ( v4->m_faceIndices.m_size == (v4->m_faceIndices.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v19, 4);
          v4->m_faceIndices.m_data[v4->m_faceIndices.m_size++] = v39;
          if ( v4->m_indicesCount.m_size == (v4->m_indicesCount.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v20, 4);
          v4->m_indicesCount.m_data[v4->m_indicesCount.m_size++] = 0;
        }
        ++v25;
        --v20->m_data[v38];
        if ( v25 == v63 )
          goto LABEL_50;
      }
    }
LABEL_59:
    v45 = v3->m_faces.m_size;
    array = 0i64;
    v66 = 0;
    v67 = 2147483648;
    v46 = (v45 + 31) >> 5;
    v47 = v46;
    if ( v46 )
    {
      LODWORD(v69) = 4 * v46;
      v48 = (_DWORD *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                        (int *)&v69);
      v47 = (signed int)v69 / 4;
    }
    else
    {
      v48 = 0i64;
    }
    v49 = 2147483648;
    array = v48;
    if ( v47 )
      v49 = v47;
    v66 = (v45 + 31) >> 5;
    v68 = v45;
    v67 = v49;
    if ( (v49 & 0x3FFFFFFF) < v46 )
    {
      v50 = (v45 + 31) >> 5;
      if ( v46 < 2 * (v49 & 0x3FFFFFFF) )
        v50 = 2 * (v49 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(
        (hkResult *)&v69,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &array,
        v50,
        4);
      v49 = v67;
      v48 = array;
    }
    v66 = (v45 + 31) >> 5;
    if ( v48 )
    {
      if ( v46 - 1 >= 0 )
      {
        v53 = (unsigned int)v46;
        v54 = v48;
        while ( v53 )
        {
          *v54 = 0;
          ++v54;
          --v53;
        }
        v49 = v67;
        v48 = array;
      }
      v55 = v3->m_edges.m_data;
      v56 = (signed __int64)&v55[v3->m_edges.m_size];
      if ( v55 != (hkaiEdgeGeometry::Edge *)v56 )
      {
        do
        {
          v57 = (signed int)v55->m_face;
          ++v55;
          v48[v57 >> 5] |= 1 << (v57 & 0x1F);
          v48 = array;
        }
        while ( v55 != (hkaiEdgeGeometry::Edge *)v56 );
        v49 = v67;
      }
      v58 = 1;
      if ( v45 <= 1 )
      {
LABEL_83:
        v66 = 0;
        if ( v49 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v48,
            4 * v49);
        v5->m_enum = 0;
        return v5;
      }
      while ( (v48[(signed __int64)v58 >> 5] >> (v58 & 0x1F)) & 1 )
      {
        if ( ++v58 >= v45 )
          goto LABEL_83;
      }
      v5->m_enum = 1;
      v66 = 0;
      if ( v49 < 0 )
        return v5;
      v52 = v48;
      v51 = (unsigned int)(4 * v49);
    }
    else
    {
      v5->m_enum = 1;
      v66 = 0;
      if ( v49 < 0 )
        return v5;
      v51 = (unsigned int)(4 * v49);
      v52 = 0i64;
    }
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc, v52, v51);
    return v5;
  }
  v6 = v5;
  if ( v3->m_edges.m_size )
    v5->m_enum = 1;
  else
    v5->m_enum = 0;
  return v6;
}

// File Line: 725
// RVA: 0xB9AC50
void __fastcall hkaiEdgeGeometry::findLoopIndices(hkaiEdgeGeometry::Edge *const *start, hkaiEdgeGeometry::Edge *const *end, hkArray<int,hkContainerHeapAllocator> *indicesOut)
{
  hkArray<int,hkContainerHeapAllocator> *v3; // rbx
  hkaiEdgeGeometry::Edge *const *v4; // rsi
  hkaiEdgeGeometry::Edge *const *v5; // r14
  hkaiEdgeGeometry::Edge *const *v6; // rdi
  unsigned __int64 v7; // rsi
  int i; // edi
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v9; // [rsp+20h] [rbp-18h]

  v3 = indicesOut;
  v4 = end;
  v5 = start;
  v9.m_hashMod = -1;
  v6 = start;
  indicesOut->m_size = 0;
  v9.m_elem = 0i64;
  for ( v9.m_numElems = 0; v6 != v4; ++v6 )
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      &v9,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      **(signed int **)v6,
      (signed int)(*v6)->m_b);
  v7 = **(signed int **)v5;
  if ( v3->m_size == (v3->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 4);
  v3->m_data[v3->m_size++] = v7;
  for ( i = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
              &v9,
              v7,
              0xFFFFFFFFFFFFFFFFui64);
        i != (_DWORD)v7;
        i = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
              &v9,
              i,
              0xFFFFFFFFFFFFFFFFui64) )
  {
    if ( v3->m_size == (v3->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 4);
    v3->m_data[v3->m_size++] = i;
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v9,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v9);
}

// File Line: 753
// RVA: 0xB98790
void __fastcall hkaiEdgeGeometry::extractFace(hkaiEdgeGeometry *this, hkaiEdgeGeometry::Edge *const *start, hkaiEdgeGeometry::Edge *const *end, hkaiEdgeGeometry *geomOut)
{
  int v4; // ebx
  __int64 v5; // r15
  hkaiEdgeGeometry *v6; // r12
  hkaiEdgeGeometry::Edge *const *v7; // rsi
  hkaiEdgeGeometry::Edge *const *v8; // r14
  hkaiEdgeGeometry *v9; // r13
  __int64 v10; // r10
  int v11; // edi
  int v12; // er9
  __int64 v13; // rcx
  _DWORD *v14; // rdi
  __int64 v15; // rdi
  signed __int64 v16; // rsi
  hkaiEdgeGeometry::Face *v17; // rdx
  hkaiEdgeGeometry::Edge *const *v18; // r13
  hkArray<hkaiEdgeGeometry::Edge,hkContainerHeapAllocator> *v19; // rdi
  __int64 v20; // r12
  hkaiEdgeGeometry::Edge *v21; // rbx
  __int64 v22; // rdx
  __int64 v23; // rax
  int v24; // er14
  int v25; // ecx
  unsigned int v26; // esi
  int v27; // ecx
  __int64 v28; // rax
  int v29; // esi
  signed int v30; // ebx
  int v31; // ecx
  signed __int64 v32; // rcx
  int v33; // ecx
  int v34; // eax
  int v35; // edi
  int v36; // eax
  __int64 v37; // r9
  __int64 v38; // rdi
  __int64 v39; // r8
  __int64 v40; // rdx
  __int64 v41; // [rsp+30h] [rbp-28h]
  int v42; // [rsp+38h] [rbp-20h]
  int v43; // [rsp+3Ch] [rbp-1Ch]
  __int64 array; // [rsp+40h] [rbp-18h]
  int v45; // [rsp+48h] [rbp-10h]
  int v46; // [rsp+4Ch] [rbp-Ch]
  hkaiEdgeGeometry *v47; // [rsp+A0h] [rbp+48h]
  hkaiEdgeGeometry::Edge *const *v48; // [rsp+A8h] [rbp+50h]
  hkResult result; // [rsp+B0h] [rbp+58h]
  hkaiEdgeGeometry *v50; // [rsp+B8h] [rbp+60h]

  v50 = geomOut;
  v48 = start;
  v47 = this;
  v4 = this->m_vertices.m_size;
  v5 = 0i64;
  v6 = geomOut;
  v7 = end;
  v8 = start;
  v9 = this;
  v10 = 0i64;
  array = 0i64;
  v11 = 0;
  v45 = 0;
  v46 = 2147483648;
  v41 = 0i64;
  v42 = 0;
  v43 = 2147483648;
  if ( v4 > 0 )
  {
    v12 = v4;
    if ( v4 < 0 )
      v12 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v12, 4);
    v11 = v45;
    v10 = array;
  }
  v13 = v4 - v11;
  if ( v4 - v11 > 0 )
  {
    v14 = (_DWORD *)(v10 + 4i64 * v11);
    while ( v13 )
    {
      *v14 = -1;
      ++v14;
      --v13;
    }
  }
  v45 = v4;
  hkaiEdgeGeometry::clear(v6);
  if ( v6->m_faces.m_size == (v6->m_faces.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v6->m_faces, 12);
  v15 = v6->m_faces.m_size;
  v16 = v7 - v8;
  v17 = &v6->m_faces.m_data[v15];
  v6->m_faces.m_size = v15 + 1;
  v17->m_data = 0;
  if ( (signed int)v16 > 0 )
  {
    v18 = v48;
    v19 = &v6->m_edges;
    v20 = (signed int)v16;
    do
    {
      v21 = v18[v5];
      v22 = array;
      v23 = (signed int)v21->m_a;
      v24 = *(_DWORD *)(array + 4 * v23);
      if ( v24 >= 0 )
      {
        v27 = v42;
      }
      else
      {
        v24 = v42;
        *(_DWORD *)(array + 4 * v23) = v42;
        v25 = v42;
        v26 = v21->m_a;
        if ( v42 == (v43 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v41, 4);
          v25 = v42;
        }
        *(_DWORD *)(v41 + 4i64 * v25) = v26;
        v22 = array;
        v27 = v42++ + 1;
      }
      v28 = (signed int)v21->m_b;
      v29 = *(_DWORD *)(v22 + 4 * v28);
      if ( v29 < 0 )
      {
        *(_DWORD *)(v22 + 4 * v28) = v27;
        v30 = v21->m_b;
        v29 = v27;
        v31 = v42;
        if ( v42 == (v43 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v41, 4);
          v31 = v42;
        }
        *(_DWORD *)(v41 + 4i64 * v31) = v30;
        ++v42;
      }
      if ( v19->m_size == (v19->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v19, 16);
      ++v5;
      v32 = (signed __int64)&v19->m_data[v19->m_size++];
      *(_DWORD *)(v32 + 4) = v29;
      *(_DWORD *)v32 = v24;
      *(_QWORD *)(v32 + 8) = 1i64;
    }
    while ( v5 < v20 );
    v9 = v47;
    v6 = v50;
  }
  v33 = v42;
  v34 = v6->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  v35 = v42;
  if ( v34 < v42 )
  {
    v36 = 2 * v34;
    if ( v42 < v36 )
      v33 = v36;
    hkArrayUtil::_reserve(
      (hkResult *)&v48,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v6->m_vertices,
      v33,
      16);
    v33 = v42;
  }
  v6->m_vertices.m_size = v35;
  v37 = 0i64;
  if ( v33 > 0 )
  {
    v38 = 0i64;
    v39 = 0i64;
    do
    {
      v37 = (unsigned int)(v37 + 1);
      v40 = *(signed int *)(v41 + v39);
      v39 += 4i64;
      ++v38;
      v6->m_vertices.m_data[v38 - 1] = v9->m_vertices.m_data[v40];
    }
    while ( (signed int)v37 < v42 );
  }
  v42 = 0;
  if ( v43 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, __int64, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      v41,
      (unsigned int)(4 * v43),
      v37);
  v41 = 0i64;
  v43 = 2147483648;
  v45 = 0;
  if ( v46 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, __int64, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      array,
      (unsigned int)(4 * v46),
      v37);
}

// File Line: 803
// RVA: 0xB98AB0
void __fastcall hkaiEdgeGeometry::extractFace(hkaiEdgeGeometry *this, int faceIndexIn, hkaiEdgeGeometry *geomOut)
{
  hkaiEdgeGeometry::Edge *v3; // rbx
  int v4; // eax
  int v5; // esi
  char *v6; // rdx
  signed __int64 v7; // rdi
  signed int v8; // er9
  hkaiEdgeGeometry *v9; // r14
  hkaiEdgeGeometry *v10; // rbp
  char *array; // [rsp+20h] [rbp-218h]
  int v12; // [rsp+28h] [rbp-210h]
  int i; // [rsp+2Ch] [rbp-20Ch]
  char v14; // [rsp+30h] [rbp-208h]

  v3 = this->m_edges.m_data;
  v4 = 0;
  v5 = faceIndexIn;
  v6 = &v14;
  v7 = (signed __int64)&v3[this->m_edges.m_size];
  v8 = -2147483584;
  v9 = geomOut;
  v10 = this;
  array = &v14;
  v12 = 0;
  for ( i = -2147483584; v3 != (hkaiEdgeGeometry::Edge *)v7; ++v3 )
  {
    if ( v3->m_face == v5 )
    {
      if ( v4 == (v8 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
        v4 = v12;
        v6 = array;
      }
      *(_QWORD *)&v6[8 * v4] = v3;
      v8 = i;
      v6 = array;
      v4 = v12++ + 1;
    }
  }
  hkaiEdgeGeometry::extractFace(
    v10,
    (hkaiEdgeGeometry::Edge *const *)v6,
    (hkaiEdgeGeometry::Edge *const *)&v6[8 * v4],
    v9);
  v12 = 0;
  if ( i >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      8 * i);
}

// File Line: 824
// RVA: 0xB99230
hkResult *__fastcall hkaiEdgeGeometry::setForSingleTriangle(hkaiEdgeGeometry *this, hkResult *result)
{
  hkResult *v2; // rbx
  int v3; // eax
  hkaiEdgeGeometry *v4; // rsi
  int v5; // eax
  int v6; // er9
  int v8; // eax
  int v9; // eax
  int v10; // er9
  int v11; // eax
  int v12; // eax
  int v13; // er9
  hkaiEdgeGeometry::Face *v14; // rax
  hkResult resulta; // [rsp+50h] [rbp+8h]
  hkResult v16; // [rsp+60h] [rbp+18h]
  hkResult v17; // [rsp+68h] [rbp+20h]

  v2 = result;
  v3 = this->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  v4 = this;
  if ( v3 >= 3 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    v5 = 2 * v3;
    v6 = 3;
    if ( v5 > 3 )
      v6 = v5;
    hkArrayUtil::_reserve(
      &resulta,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_vertices,
      v6,
      16);
    if ( resulta.m_enum )
      goto LABEL_5;
  }
  v4->m_vertices.m_size = 3;
  v8 = v4->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 >= 3 )
  {
    v16.m_enum = 0;
  }
  else
  {
    v9 = 2 * v8;
    v10 = 3;
    if ( v9 > 3 )
      v10 = v9;
    hkArrayUtil::_reserve(&v16, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v4->m_edges, v10, 16);
    if ( v16.m_enum )
    {
      v2->m_enum = 1;
      return v2;
    }
  }
  v4->m_edges.m_size = 3;
  v4->m_edges.m_data->m_a = 2;
  v4->m_edges.m_data->m_b = 0;
  v4->m_edges.m_data->m_face = 1;
  v4->m_edges.m_data->m_data = 0;
  v4->m_edges.m_data[1].m_a = 0;
  v4->m_edges.m_data[1].m_b = 1;
  v4->m_edges.m_data[1].m_face = 1;
  v4->m_edges.m_data[1].m_data = 0;
  v4->m_edges.m_data[2].m_a = 1;
  v4->m_edges.m_data[2].m_b = 2;
  v4->m_edges.m_data[2].m_face = 1;
  v4->m_edges.m_data[2].m_data = 0;
  v11 = v4->m_faces.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v11 < 2 )
  {
    v12 = 2 * v11;
    v13 = 2;
    if ( v12 > 2 )
      v13 = v12;
    hkArrayUtil::_reserve(&v17, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v4->m_faces, v13, 12);
    if ( v17.m_enum )
    {
LABEL_5:
      v2->m_enum = 1;
      return v2;
    }
  }
  v4->m_faces.m_size = 2;
  v14 = v4->m_faces.m_data;
  v2->m_enum = 0;
  v14->m_data = 0;
  v4->m_faces.m_data->m_faceIndex = 0;
  v4->m_faces.m_data->m_flags.m_storage = 0;
  v4->m_faces.m_data[1].m_data = 0;
  v4->m_faces.m_data[1].m_faceIndex = 0;
  v4->m_faces.m_data[1].m_flags.m_storage = 1;
  return v2;
}

