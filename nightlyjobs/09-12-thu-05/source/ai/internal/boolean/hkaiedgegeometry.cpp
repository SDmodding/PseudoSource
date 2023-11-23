// File Line: 21
// RVA: 0xB9AD80
void __fastcall hkaiEdgeGeometry::hkaiEdgeGeometry(hkaiEdgeGeometry *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiEdgeGeometry::`vftable;
  this->m_edges.m_data = 0i64;
  this->m_edges.m_size = 0;
  this->m_edges.m_capacityAndFlags = 0x80000000;
  this->m_faces.m_capacityAndFlags = -2147483647;
  this->m_faces.m_data = &this->m_zeroFace;
  this->m_faces.m_size = 1;
  this->m_vertices.m_data = 0i64;
  this->m_vertices.m_size = 0;
  this->m_vertices.m_capacityAndFlags = 0x80000000;
  this->m_zeroFace.m_flags.m_storage = 0;
  this->m_zeroFace.m_data = 0;
}

// File Line: 26
// RVA: 0xB9A400
void __fastcall hkaiEdgeGeometry::clear(hkaiEdgeGeometry *this)
{
  hkArray<hkaiEdgeGeometry::Face,hkContainerHeapAllocator> *p_m_faces; // rbx
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  p_m_faces = &this->m_faces;
  this->m_edges.m_size = 0;
  this->m_vertices.m_size = 0;
  if ( (this->m_faces.m_capacityAndFlags & 0x3FFFFFFF) == 0 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, p_m_faces, 1, 12);
  p_m_faces->m_size = 1;
}

// File Line: 33
// RVA: 0xB9AC10
__int64 __fastcall hkaiEdgeGeometry::findEdgeIndex(hkaiEdgeGeometry *this, int startVertexIndex, int endVertexIndex)
{
  hkaiEdgeGeometry::Edge *m_data; // r10
  hkaiEdgeGeometry::Edge *v4; // rax
  hkaiEdgeGeometry::Edge *v5; // r9
  bool i; // zf

  m_data = this->m_edges.m_data;
  v4 = m_data;
  v5 = &m_data[this->m_edges.m_size];
  for ( i = m_data == v5; !i; i = v4 == v5 )
  {
    if ( v4->m_a == startVertexIndex && v4->m_b == endVertexIndex )
      return v4 - m_data;
    ++v4;
  }
  return 0xFFFFFFFFi64;
}

// File Line: 52
// RVA: 0xB99EE0
void __fastcall hkaiEdgeGeometry::calculateFaceNormal(
        hkaiEdgeGeometry *this,
        hkaiEdgeGeometry::Edge *const *start,
        hkaiEdgeGeometry::Edge *const *end,
        hkVector4f *normalOut)
{
  int *v5; // rax
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
  hkVector4f *m_data; // r8
  __m128 v21; // xmm5
  __m128 m_quad; // xmm3
  int *v23; // rcx
  __m128 v24; // xmm2
  __m128 v25; // xmm0
  __m128 v26; // xmm1
  __m128 v27; // xmm1
  __m128 v28; // xmm3
  __m128 v29; // xmm2
  __m128 v30; // xmm5
  __m128 v31; // xmm2
  __m128 v32; // xmm0

  v5 = (int *)*start;
  v6 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_9_9999994eN11), (__m128)LODWORD(FLOAT_9_9999994eN11), 0);
  if ( (unsigned int)(end - start) == 2 )
  {
    v7 = _mm_sub_ps(this->m_vertices.m_data[*v5].m_quad, this->m_vertices.m_data[v5[1]].m_quad);
    v8 = _mm_mul_ps(v7, v7);
    v9 = _mm_shuffle_ps(v7, _mm_unpackhi_ps(v7, (__m128)0i64), 196);
    v10 = _mm_shuffle_ps(v9, v9, 241);
    v11 = _mm_shuffle_ps(v9, v9, 206);
    v12 = _mm_mul_ps(v11, v11);
    v13 = _mm_mul_ps(v10, v10);
    v14 = _mm_cmplt_ps(
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
    v19 = _mm_cmplt_ps(
            v6,
            _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170)));
    normalOut->m_quad = _mm_or_ps(
                          _mm_and_ps(
                            _mm_mul_ps(
                              _mm_andnot_ps(
                                _mm_cmple_ps(v17, (__m128)0i64),
                                _mm_mul_ps(
                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                                  _mm_mul_ps(*(__m128 *)_xmm, v18))),
                              v15),
                            v19),
                          _mm_andnot_ps(v19, transform.m_quad));
  }
  else
  {
    m_data = this->m_vertices.m_data;
    v21 = 0i64;
    if ( start != end )
    {
      m_quad = m_data[*v5].m_quad;
      do
      {
        v23 = (int *)*start++;
        v24 = _mm_sub_ps(m_data[*v23].m_quad, m_quad);
        v25 = _mm_sub_ps(m_data[v23[1]].m_quad, m_quad);
        v26 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v24), _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v25));
        v21 = _mm_add_ps(v21, _mm_shuffle_ps(v26, v26, 201));
      }
      while ( start != end );
    }
    v27 = _mm_mul_ps(v21, v21);
    v28 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
            _mm_shuffle_ps(v27, v27, 170));
    v29 = _mm_rsqrt_ps(v28);
    v30 = _mm_mul_ps(
            v21,
            _mm_andnot_ps(
              _mm_cmple_ps(v28, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v29, v28), v29)),
                _mm_mul_ps(*(__m128 *)_xmm, v29))));
    v31 = _mm_mul_ps(v30, v30);
    v32 = _mm_cmplt_ps(
            v6,
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
              _mm_shuffle_ps(v31, v31, 170)));
    normalOut->m_quad = _mm_or_ps(_mm_andnot_ps(v32, transform.m_quad), _mm_and_ps(v32, v30));
  }
}

// File Line: 111
// RVA: 0xB9A260
void __fastcall hkaiEdgeGeometry::calculateFaceCentroid(
        hkaiEdgeGeometry *this,
        hkaiEdgeGeometry::Edge *const *start,
        hkaiEdgeGeometry::Edge *const *end,
        hkVector4f *centroidOut)
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
    v7 = *v5++;
  v4.m128_f32[0] = (float)(int)(end - start);
  v8 = _mm_shuffle_ps(v4, v4, 0);
  v9 = _mm_rcp_ps(v8);
  centroidOut->m_quad = _mm_mul_ps(i, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v9, v8)), v9));
}

// File Line: 125
// RVA: 0xB9A390
void __fastcall hkaiEdgeGeometry::calculateFaceAabb(
        hkaiEdgeGeometry *this,
        hkaiEdgeGeometry::Edge *const *start,
        hkaiEdgeGeometry::Edge *const *end,
        hkAabb *aabb)
{
  int *v4; // rax
  hkaiEdgeGeometry::Edge *const *v5; // rdx
  hkVector4f v7; // xmm0
  hkVector4f v8; // xmm1
  int *v9; // rax
  hkVector4f *v10; // rcx

  v4 = (int *)*start;
  v5 = start + 1;
  v7.m_quad = (__m128)this->m_vertices.m_data[*v4];
  aabb->m_min = (hkVector4f)v7.m_quad;
  aabb->m_max = (hkVector4f)v7.m_quad;
  if ( v5 < end )
  {
    v8.m_quad = v7.m_quad;
    do
    {
      v9 = (int *)*v5++;
      v10 = &this->m_vertices.m_data[*v9];
      aabb->m_min.m_quad = _mm_min_ps(aabb->m_min.m_quad, v10->m_quad);
      v8.m_quad = _mm_max_ps(v8.m_quad, v10->m_quad);
      aabb->m_max = (hkVector4f)v8.m_quad;
    }
    while ( v5 < end );
  }
}

// File Line: 139
// RVA: 0xB9A2C0
hkSimdFloat32 *__fastcall hkaiEdgeGeometry::calculateFaceArea(
        hkaiEdgeGeometry *this,
        hkSimdFloat32 *result,
        hkaiEdgeGeometry::Edge *const *start,
        hkaiEdgeGeometry::Edge *const *end)
{
  hkVector4f *m_data; // r10
  __m128 v5; // xmm3
  __m128 m_quad; // xmm4
  int *v7; // rcx
  __m128 v8; // xmm1
  __m128 v9; // xmm2
  __m128 v10; // xmm2
  __m128 v11; // xmm3
  hkSimdFloat32 *v12; // rax
  __m128 v13; // xmm4
  __m128 v14; // xmm1

  m_data = this->m_vertices.m_data;
  v5 = 0i64;
  if ( start != end )
  {
    m_quad = m_data[**(int **)start].m_quad;
    do
    {
      v7 = (int *)*start++;
      v8 = _mm_sub_ps(m_data[*v7].m_quad, m_quad);
      v9 = _mm_sub_ps(m_data[v7[1]].m_quad, m_quad);
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
                       _mm_cmple_ps(v13, (__m128)0i64),
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
void __fastcall hkaiEdgeGeometry::calculateFaceNormals(
        hkaiEdgeGeometry *this,
        hkaiFaceEdges *faceEdges,
        hkArray<hkVector4f,hkContainerHeapAllocator> *normals)
{
  int v4; // esi
  int v5; // eax
  int v8; // eax
  int v9; // r9d
  hkVector4f *m_data; // rax
  int v11; // edi
  __int64 v12; // rbx
  hkResult result; // [rsp+58h] [rbp+10h] BYREF

  v4 = faceEdges->m_faceStartEdges.m_size - 1;
  v5 = normals->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v5 < v4 )
  {
    v8 = 2 * v5;
    v9 = faceEdges->m_faceStartEdges.m_size - 1;
    if ( v4 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, normals, v9, 16);
  }
  m_data = normals->m_data;
  normals->m_size = v4;
  v11 = 1;
  v12 = 1i64;
  for ( *m_data = 0i64; v12 < v4; ++v11 )
  {
    hkaiEdgeGeometry::calculateFaceNormal(
      this,
      faceEdges->m_faceStartEdges.m_data[v12],
      faceEdges->m_faceStartEdges.m_data[v12 + 1],
      &normals->m_data[v11]);
    ++v12;
  }
}

// File Line: 185
// RVA: 0xB9A240
void __fastcall hkaiEdgeGeometry::calculateFaceNormal(
        hkaiEdgeGeometry *this,
        hkaiFaceEdges *faceEdges,
        int i,
        hkVector4f *normalOut)
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
  int m_size; // edi
  __int64 v5; // rax
  int v6; // edi
  hkaiEdgeGeometry::Face *v7; // r8
  __int64 v8; // rcx
  __int64 v9; // r11
  int v10; // eax
  hkaiEdgeGeometry::Edge *m_data; // r8
  hkArray<hkaiEdgeGeometry::Edge,hkContainerHeapAllocator> *p_m_edges; // rsi
  hkaiEdgeGeometry::Edge *v13; // rbx
  hkaiEdgeGeometry::Edge *v14; // rax
  hkaiEdgeGeometry::Edge *v15; // rdx
  unsigned int m_face; // ecx
  int v17; // eax
  __int64 v18; // rbx
  int v19; // eax
  int v20; // r9d
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  if ( faceIndexIn > 0 )
  {
    m_size = this->m_faces.m_size;
    this->m_faces.m_size = m_size - 1;
    v5 = this->m_faces.m_size;
    v6 = m_size - 1;
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
    m_data = this->m_edges.m_data;
    p_m_edges = &this->m_edges;
    v13 = &m_data[this->m_edges.m_size];
    v14 = v13 - 1;
    if ( &v13[-1] >= m_data )
    {
      v15 = v13 - 1;
      do
      {
        m_face = v14->m_face;
        if ( m_face == faceIndexIn )
        {
          if ( v14 != v15 )
          {
            v14->m_a = v15->m_a;
            v14->m_b = v15->m_b;
            v14->m_face = v15->m_face;
            v14->m_data = v15->m_data;
          }
          --v13;
          --v15;
        }
        else if ( m_face == v6 )
        {
          v14->m_face = faceIndexIn;
        }
        --v14;
      }
      while ( v14 >= m_data );
    }
    v17 = this->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
    v18 = v13 - m_data;
    if ( v17 < (int)v18 )
    {
      v19 = 2 * v17;
      v20 = v18;
      if ( (int)v18 < v19 )
        v20 = v19;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_edges, v20, 16);
    }
    p_m_edges->m_size = v18;
  }
}

// File Line: 241
// RVA: 0xB99B90
hkResult *__fastcall hkaiEdgeGeometry::concat(hkaiEdgeGeometry *this, hkResult *result, hkaiEdgeGeometry *geom)
{
  int v3; // r9d
  int m_size; // r14d
  int v5; // eax
  int v6; // r13d
  int v10; // eax
  __int64 v12; // r12
  int v13; // r15d
  int v14; // eax
  int v15; // r9d
  int v16; // eax
  int v17; // r9d
  int v18; // eax
  hkaiEdgeGeometry::Edge *v19; // r12
  int v20; // eax
  int v21; // r15d
  int v22; // r9d
  int v23; // eax
  int v24; // eax
  hkArray<hkaiEdgeGeometry::Face,hkContainerHeapAllocator> *p_m_faces; // rsi
  int v26; // r9d
  int v27; // eax
  int v28; // eax
  __int64 v29; // r15
  int v30; // ebp
  int v31; // eax
  int v32; // r9d
  int v33; // eax
  hkaiEdgeGeometry::Face *v34; // rdx
  __int64 v35; // r8
  __int64 v36; // rcx
  unsigned int m_data; // eax
  int v38; // eax
  hkVector4f *v39; // r10
  __int64 v40; // r11
  int *v41; // r9
  int v42; // edx
  int v43; // r8d
  int v44; // eax
  hkaiEdgeGeometry::Edge *v45; // r10
  hkaiEdgeGeometry::Edge *v46; // r9
  unsigned int *p_m_face; // r8
  unsigned int *v48; // rdx
  signed __int64 v49; // r10
  int v50; // ecx
  hkResult v51[2]; // [rsp+30h] [rbp-48h] BYREF
  hkResult v52; // [rsp+38h] [rbp-40h] BYREF
  hkResult resulta; // [rsp+80h] [rbp+8h] BYREF
  hkResult v54; // [rsp+90h] [rbp+18h] BYREF
  hkResult v55; // [rsp+98h] [rbp+20h] BYREF

  v3 = geom->m_edges.m_size + this->m_edges.m_size;
  m_size = this->m_vertices.m_size;
  v5 = this->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
  v6 = this->m_faces.m_size - 1;
  if ( v5 >= v3 )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    v10 = 2 * v5;
    if ( v3 < v10 )
      v3 = v10;
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &this->m_edges, v3, 16);
    if ( resulta.m_enum )
    {
      result->m_enum = HK_FAILURE;
      return result;
    }
  }
  v12 = this->m_edges.m_size;
  v13 = geom->m_edges.m_size;
  v14 = this->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
  v15 = v12 + v13;
  if ( v14 < (int)v12 + v13 )
  {
    v16 = 2 * v14;
    if ( v15 < v16 )
      v15 = v16;
    hkArrayUtil::_reserve(v51, &hkContainerHeapAllocator::s_alloc, &this->m_edges, v15, 16);
  }
  this->m_edges.m_size += v13;
  v17 = this->m_vertices.m_size + geom->m_vertices.m_size;
  v18 = this->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  v19 = &this->m_edges.m_data[v12];
  if ( v18 >= v17 )
  {
    v54.m_enum = HK_SUCCESS;
    goto LABEL_17;
  }
  v20 = 2 * v18;
  if ( v17 < v20 )
    v17 = v20;
  hkArrayUtil::_reserve(&v54, &hkContainerHeapAllocator::s_alloc, &this->m_vertices, v17, 16);
  if ( v54.m_enum == HK_SUCCESS )
  {
LABEL_17:
    v21 = geom->m_vertices.m_size;
    v22 = this->m_vertices.m_size + v21;
    v51[0] = (hkResult)this->m_vertices.m_size;
    v23 = this->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v23 < v22 )
    {
      v24 = 2 * v23;
      if ( v22 < v24 )
        v22 = v24;
      hkArrayUtil::_reserve(&v52, &hkContainerHeapAllocator::s_alloc, &this->m_vertices, v22, 16);
    }
    this->m_vertices.m_size += v21;
    p_m_faces = &this->m_faces;
    v26 = this->m_faces.m_size + geom->m_faces.m_size - 1;
    *(_QWORD *)&v51[0].m_enum = &this->m_vertices.m_data[v51[0].m_enum];
    v27 = this->m_faces.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v27 >= v26 )
    {
      v55.m_enum = HK_SUCCESS;
    }
    else
    {
      v28 = 2 * v27;
      if ( v26 < v28 )
        v26 = v28;
      hkArrayUtil::_reserve(&v55, &hkContainerHeapAllocator::s_alloc, &this->m_faces, v26, 12);
      if ( v55.m_enum )
      {
        result->m_enum = HK_FAILURE;
        return result;
      }
    }
    v29 = this->m_faces.m_size;
    v30 = geom->m_faces.m_size - 1;
    v31 = p_m_faces->m_capacityAndFlags & 0x3FFFFFFF;
    v32 = v29 + v30;
    if ( v31 < (int)v29 + v30 )
    {
      v33 = 2 * v31;
      if ( v32 < v33 )
        v32 = v33;
      hkArrayUtil::_reserve(&v52, &hkContainerHeapAllocator::s_alloc, p_m_faces, v32, 12);
    }
    p_m_faces->m_size += v30;
    v34 = geom->m_faces.m_data + 1;
    v35 = (__int64)&p_m_faces->m_data[v29];
    v36 = (unsigned int)(3 * (geom->m_faces.m_size - 1));
    if ( (int)v36 > 0 )
    {
      do
      {
        m_data = v34->m_data;
        v35 += 4i64;
        v34 = (hkaiEdgeGeometry::Face *)((char *)v34 + 4);
        *(_DWORD *)(v35 - 4) = m_data;
        --v36;
      }
      while ( v36 );
    }
    v38 = geom->m_vertices.m_size;
    v39 = geom->m_vertices.m_data;
    if ( v38 > 0 )
    {
      v40 = (unsigned int)v38;
      v41 = (int *)(*(_QWORD *)&v51[0].m_enum + 8i64);
      do
      {
        v42 = v39->m_quad.m128_i32[2];
        v43 = v39->m_quad.m128_i32[3];
        v44 = v39->m_quad.m128_i32[0];
        *(v41 - 1) = v39->m_quad.m128_i32[1];
        *v41 = v42;
        v41[1] = v43;
        *(v41 - 2) = v44;
        v41 += 4;
        ++v39;
        --v40;
      }
      while ( v40 );
    }
    v45 = geom->m_edges.m_data;
    v46 = &v45[geom->m_edges.m_size];
    if ( v45 != v46 )
    {
      p_m_face = &v45->m_face;
      v48 = &v19->m_face;
      v49 = (char *)v45 - (char *)v19;
      do
      {
        v50 = *(unsigned int *)((char *)v48 + v49 - 8);
        v48 += 4;
        p_m_face += 4;
        *(v48 - 6) = m_size + v50;
        *(v48 - 5) = m_size + *(p_m_face - 5);
        *(v48 - 4) = v6 + *(p_m_face - 4);
        *(v48 - 3) = *(p_m_face - 3);
      }
      while ( (hkaiEdgeGeometry::Edge *)((char *)v48 + v49 - 8) != v46 );
    }
    result->m_enum = HK_SUCCESS;
    return result;
  }
  result->m_enum = HK_FAILURE;
  return result;
}

// File Line: 287
// RVA: 0xB99520
hkResult *__fastcall hkaiEdgeGeometry::removeFaces(
        hkaiEdgeGeometry *this,
        hkResult *result,
        const unsigned int *faceIndices,
        int numRemoveFaces)
{
  __int64 v4; // r13
  hkResult *v8; // rax
  hkResultEnum m_size; // edi
  __int64 v10; // r14
  int v11; // ecx
  void *v12; // rdx
  int v13; // r8d
  int v14; // r9d
  hkResultEnum m_enum; // eax
  __int64 v16; // r8
  int v17; // ecx
  int v18; // r9d
  _DWORD *v19; // rdi
  __int64 v20; // rcx
  __int64 v21; // rdx
  __int64 v22; // rcx
  hkaiEdgeGeometry::Face *m_data; // r13
  __int64 v24; // rcx
  hkaiEdgeGeometry::Face *v25; // r9
  hkaiEdgeGeometry::Face *v26; // r8
  __int64 v27; // r11
  _DWORD *v28; // rdi
  __int64 v29; // rdx
  __int64 v30; // r12
  int v31; // eax
  int v32; // eax
  int v33; // r9d
  char *v34; // rdi
  __int64 v35; // rcx
  hkaiEdgeGeometry::Edge *v36; // rdx
  __int64 v37; // r14
  int v38; // edi
  hkaiEdgeGeometry::Edge *v39; // r14
  unsigned int *p_m_b; // r8
  unsigned int v41; // r11d
  __int64 v42; // rcx
  unsigned int v43; // r9d
  unsigned int *v44; // r10
  unsigned int v45; // eax
  __int64 v46; // rdx
  int v47; // eax
  int m_capacityAndFlags; // r8d
  int v49; // eax
  int v50; // eax
  int v51; // r9d
  __int64 v52; // rdx
  __int64 v53; // rdi
  __int64 v54; // rcx
  hkResult resulta; // [rsp+30h] [rbp-40h] BYREF
  hkResult v56; // [rsp+34h] [rbp-3Ch] BYREF
  hkResult v57; // [rsp+38h] [rbp-38h] BYREF
  char *v58; // [rsp+40h] [rbp-30h] BYREF
  int v59; // [rsp+48h] [rbp-28h]
  int v60; // [rsp+4Ch] [rbp-24h]
  _DWORD *array; // [rsp+50h] [rbp-20h] BYREF
  int v62; // [rsp+58h] [rbp-18h]
  int v63; // [rsp+5Ch] [rbp-14h]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> a; // [rsp+60h] [rbp-10h] BYREF
  hkResult v65; // [rsp+B8h] [rbp+48h] BYREF

  v4 = numRemoveFaces;
  if ( !numRemoveFaces )
  {
    v8 = result;
    result->m_enum = HK_SUCCESS;
    return v8;
  }
  if ( numRemoveFaces != 1 )
  {
    m_size = this->m_vertices.m_size;
    v10 = this->m_faces.m_size;
    v11 = 0x80000000;
    v56.m_enum = m_size;
    array = 0i64;
    v62 = 0;
    v63 = 0x80000000;
    v12 = 0i64;
    v58 = 0i64;
    v59 = 0;
    v13 = 0x80000000;
    v60 = 0x80000000;
    if ( (int)v10 <= 0 )
    {
      resulta.m_enum = HK_SUCCESS;
    }
    else
    {
      hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &array, v10, 4);
      v11 = v63;
      v13 = v60;
      v12 = v58;
    }
    if ( (v13 & 0x3FFFFFFF) >= m_size )
    {
      m_enum = HK_SUCCESS;
      v65.m_enum = HK_SUCCESS;
    }
    else
    {
      v14 = m_size;
      if ( m_size < 2 * (v13 & 0x3FFFFFFF) )
        v14 = 2 * (v13 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&v65, &hkContainerHeapAllocator::s_alloc, &v58, v14, 4);
      v11 = v63;
      v13 = v60;
      v12 = v58;
      m_enum = v65.m_enum;
    }
    if ( resulta.m_enum || m_enum )
    {
      v59 = 0;
      result->m_enum = HK_FAILURE;
      if ( v13 >= 0 )
      {
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v12, 4 * v13);
        v11 = v63;
      }
      v58 = 0i64;
      v60 = 0x80000000;
      v62 = 0;
      if ( v11 < 0 )
        return result;
      v16 = (unsigned int)(4 * v11);
      goto LABEL_73;
    }
    v17 = v11 & 0x3FFFFFFF;
    if ( v17 < (int)v10 )
    {
      v18 = v10;
      if ( (int)v10 < 2 * v17 )
        v18 = 2 * v17;
      hkArrayUtil::_reserve(&v57, &hkContainerHeapAllocator::s_alloc, &array, v18, 4);
    }
    v19 = &array[v62];
    v20 = (int)v10 - v62;
    if ( (int)v10 - v62 > 0 )
    {
      while ( v20 )
      {
        *v19++ = 0;
        --v20;
      }
    }
    v62 = v10;
    v21 = 0i64;
    if ( (int)v4 > 0 )
    {
      do
      {
        v22 = (int)faceIndices[v21++];
        array[v22] = 1;
      }
      while ( v21 < v4 );
    }
    m_data = this->m_faces.m_data;
    v24 = 1i64;
    v25 = m_data + 1;
    if ( v10 > 1 )
    {
      v26 = m_data + 1;
      v27 = 12i64;
      do
      {
        v28 = &array[v24];
        if ( *v28 )
        {
          *v28 = 0;
        }
        else
        {
          ++v25;
          v29 = v27 / 12;
          v27 += 12i64;
          *v28 = v29;
          v25[-1].m_data = v26->m_data;
          v25[-1].m_faceIndex = v26->m_faceIndex;
          *(_DWORD *)&v25[-1].m_flags.m_storage = *(_DWORD *)&v26->m_flags.m_storage;
        }
        ++v24;
        ++v26;
      }
      while ( v24 < v10 );
    }
    v30 = v56.m_enum;
    *array = 0;
    v31 = v60 & 0x3FFFFFFF;
    this->m_faces.m_size = v25 - m_data;
    if ( v31 < (int)v30 )
    {
      v32 = 2 * v31;
      v33 = v30;
      if ( (int)v30 < v32 )
        v33 = v32;
      hkArrayUtil::_reserve(&v57, &hkContainerHeapAllocator::s_alloc, &v58, v33, 4);
    }
    v34 = &v58[4 * v59];
    v35 = (int)v30 - v59;
    if ( (int)v30 - v59 > 0 )
    {
      while ( v35 )
      {
        *(_DWORD *)v34 = -1;
        v34 += 4;
        --v35;
      }
    }
    v36 = this->m_edges.m_data;
    v37 = this->m_edges.m_size;
    v59 = v30;
    v38 = 0;
    v39 = &v36[v37];
    if ( v36 != v39 )
    {
      p_m_b = &v36->m_b;
      do
      {
        v41 = array[p_m_b[1]];
        if ( v41 )
        {
          v42 = (int)*(p_m_b - 1);
          v43 = *(_DWORD *)&v58[4 * v42];
          if ( v43 == -1 )
          {
            v43 = v38++;
            *(_DWORD *)&v58[4 * v42] = v43;
          }
          v44 = (unsigned int *)&v58[4 * *p_m_b];
          v45 = *v44;
          if ( *v44 == -1 )
          {
            v45 = v38++;
            *v44 = v45;
          }
          v36->m_a = v43;
          v36->m_b = v45;
          v36->m_face = v41;
          ++v36;
          v36[-1].m_data = p_m_b[2];
        }
        p_m_b += 4;
      }
      while ( p_m_b - 1 != (unsigned int *)v39 );
    }
    v46 = (char *)v36 - (char *)this->m_edges.m_data;
    v47 = 0x80000000;
    a.m_data = 0i64;
    a.m_size = 0;
    a.m_capacityAndFlags = 0x80000000;
    this->m_edges.m_size = v46 >> 4;
    if ( v38 <= 0 )
    {
      v56.m_enum = HK_SUCCESS;
    }
    else
    {
      hkArrayUtil::_reserve(&v56, &hkContainerHeapAllocator::s_alloc, &a, v38, 16);
      if ( v56.m_enum )
      {
        m_capacityAndFlags = a.m_capacityAndFlags;
        result->m_enum = HK_FAILURE;
        a.m_size = 0;
        if ( m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            a.m_data,
            16 * m_capacityAndFlags);
        a.m_data = 0i64;
        a.m_capacityAndFlags = 0x80000000;
LABEL_69:
        v59 = 0;
        if ( v60 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v58, 4 * v60);
        v62 = 0;
        v60 = 0x80000000;
        v58 = 0i64;
        if ( v63 < 0 )
          return result;
        v16 = (unsigned int)(4 * v63);
LABEL_73:
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, v16);
        return result;
      }
      v47 = a.m_capacityAndFlags;
    }
    v49 = v47 & 0x3FFFFFFF;
    if ( v49 < v38 )
    {
      v50 = 2 * v49;
      v51 = v38;
      if ( v38 < v50 )
        v51 = v50;
      hkArrayUtil::_reserve(&v57, &hkContainerHeapAllocator::s_alloc, &a, v51, 16);
    }
    a.m_size = v38;
    v52 = 0i64;
    if ( (int)v30 > 0 )
    {
      v53 = 0i64;
      do
      {
        v54 = *(int *)&v58[4 * v52];
        if ( (_DWORD)v54 != -1 )
          a.m_data[v54] = (hkRelocationInfo::Import)this->m_vertices.m_data[v53];
        ++v52;
        ++v53;
      }
      while ( v52 < v30 );
    }
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&this->m_vertices,
      &a);
    a.m_size = 0;
    if ( a.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        a.m_data,
        16 * a.m_capacityAndFlags);
    result->m_enum = HK_SUCCESS;
    goto LABEL_69;
  }
  hkaiEdgeGeometry::removeFace(this, *faceIndices);
  result->m_enum = HK_SUCCESS;
  return result;
}>= 0 )
      hkContain

// File Line: 429
// RVA: 0xB99A50
void __fastcall hkaiEdgeGeometry::removeFacesEdges(
        hkaiEdgeGeometry *this,
        const unsigned int *faceIndices,
        int numRemoveFaces)
{
  __int64 v3; // rbx
  int m_size; // r8d
  __int64 v7; // r9
  __int64 v8; // rcx
  hkaiEdgeGeometry::Edge *m_data; // rax
  hkaiEdgeGeometry::Edge *v10; // r9
  hkaiEdgeGeometry::Edge *i; // r10
  __int64 v12; // r9
  int m_capacityAndFlags; // r8d
  hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > > v14; // [rsp+20h] [rbp-28h] BYREF

  if ( numRemoveFaces )
  {
    v3 = numRemoveFaces;
    m_size = this->m_faces.m_size;
    v14.m_storage.m_words.m_data = 0i64;
    v14.m_storage.m_words.m_size = 0;
    v14.m_storage.m_words.m_capacityAndFlags = 0x80000000;
    v14.m_storage.m_numBits = 0;
    hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::setSizeAndFill(
      &v14,
      0,
      m_size,
      0);
    v7 = 0i64;
    if ( (int)v3 > 0 )
    {
      do
      {
        v8 = (int)faceIndices[v7++];
        v14.m_storage.m_words.m_data[v8 >> 5] |= 1 << (v8 & 0x1F);
      }
      while ( v7 < v3 );
    }
    m_data = this->m_edges.m_data;
    v10 = m_data;
    for ( i = &m_data[this->m_edges.m_size]; m_data != i; ++m_data )
    {
      if ( ((v14.m_storage.m_words.m_data[(__int64)(int)m_data->m_face >> 5] >> (m_data->m_face & 0x1F)) & 1) == 0 )
      {
        ++v10;
        v10[-1].m_a = m_data->m_a;
        v10[-1].m_b = m_data->m_b;
        v10[-1].m_face = m_data->m_face;
        v10[-1].m_data = m_data->m_data;
      }
    }
    v12 = (char *)v10 - (char *)this->m_edges.m_data;
    m_capacityAndFlags = v14.m_storage.m_words.m_capacityAndFlags;
    v14.m_storage.m_words.m_size = 0;
    this->m_edges.m_size = v12 >> 4;
    if ( m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        v14.m_storage.m_words.m_data,
        4 * m_capacityAndFlags);
  }
}

// File Line: 459
// RVA: 0xB98F00
hkResult *__fastcall hkaiEdgeGeometry::set(hkaiEdgeGeometry *this, hkResult *result, hkaiEdgeGeometry *geom)
{
  int m_size; // r9d
  __int64 v7; // rax
  hkaiEdgeGeometry::Edge *m_data; // rcx
  __int64 v9; // rdx
  char *v10; // r8
  unsigned int v11; // eax
  int v12; // r9d
  int v13; // eax
  __int64 v14; // rax
  hkaiEdgeGeometry::Face *v15; // rcx
  __int64 v16; // rdx
  char *v17; // r8
  unsigned int v18; // eax
  int v19; // r9d
  __int64 v20; // rax
  hkVector4f *v21; // rcx
  __int64 v22; // rdx
  char *v23; // r8
  hkVector4f v24; // xmm0
  int v26[14]; // [rsp+30h] [rbp-38h] BYREF
  hkResult resulta; // [rsp+70h] [rbp+8h] BYREF
  hkResult v28; // [rsp+80h] [rbp+18h] BYREF
  hkResult v29; // [rsp+88h] [rbp+20h] BYREF

  m_size = geom->m_edges.m_size;
  if ( (this->m_edges.m_capacityAndFlags & 0x3FFFFFFF) >= m_size )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &this->m_edges, m_size, 16);
    if ( resulta.m_enum )
      goto LABEL_12;
  }
  if ( (this->m_edges.m_capacityAndFlags & 0x3FFFFFFF) < geom->m_edges.m_size )
  {
    if ( this->m_edges.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_edges.m_data,
        16 * this->m_edges.m_capacityAndFlags);
    v26[0] = 16 * geom->m_edges.m_size;
    this->m_edges.m_data = (hkaiEdgeGeometry::Edge *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                       &hkContainerHeapAllocator::s_alloc,
                                                       v26);
    this->m_edges.m_capacityAndFlags = v26[0] / 16;
  }
  v7 = geom->m_edges.m_size;
  m_data = this->m_edges.m_data;
  this->m_edges.m_size = v7;
  v9 = v7;
  if ( (int)v7 > 0 )
  {
    v10 = (char *)((char *)geom->m_edges.m_data - (char *)m_data);
    do
    {
      v11 = *(unsigned int *)((char *)&m_data->m_a + (_QWORD)v10);
      ++m_data;
      m_data[-1].m_a = v11;
      m_data[-1].m_b = *(_DWORD *)((char *)m_data + (_QWORD)v10 - 12);
      m_data[-1].m_face = *(_DWORD *)((char *)m_data + (_QWORD)v10 - 8);
      m_data[-1].m_data = *(_DWORD *)((char *)m_data + (_QWORD)v10 - 4);
      --v9;
    }
    while ( v9 );
  }
LABEL_12:
  v12 = geom->m_faces.m_size;
  if ( (this->m_faces.m_capacityAndFlags & 0x3FFFFFFF) >= v12 )
  {
    v28.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&v28, &hkContainerHeapAllocator::s_alloc, &this->m_faces, v12, 12);
    if ( v28.m_enum )
      goto LABEL_23;
  }
  v13 = this->m_faces.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v13 < geom->m_faces.m_size )
  {
    if ( this->m_faces.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_faces.m_data,
        12 * v13);
    v26[0] = 12 * geom->m_faces.m_size;
    this->m_faces.m_data = (hkaiEdgeGeometry::Face *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                       &hkContainerHeapAllocator::s_alloc,
                                                       v26);
    this->m_faces.m_capacityAndFlags = v26[0] / 12;
  }
  v14 = geom->m_faces.m_size;
  v15 = this->m_faces.m_data;
  this->m_faces.m_size = v14;
  v16 = v14;
  if ( (int)v14 > 0 )
  {
    v17 = (char *)((char *)geom->m_faces.m_data - (char *)v15);
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
  v19 = geom->m_vertices.m_size;
  if ( (this->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) >= v19 )
  {
    v29.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&v29, &hkContainerHeapAllocator::s_alloc, &this->m_vertices, v19, 16);
    if ( v29.m_enum )
      goto LABEL_34;
  }
  if ( (this->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) < geom->m_vertices.m_size )
  {
    if ( this->m_vertices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_vertices.m_data,
        16 * this->m_vertices.m_capacityAndFlags);
    v26[0] = 16 * geom->m_vertices.m_size;
    this->m_vertices.m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                              &hkContainerHeapAllocator::s_alloc,
                                              v26);
    this->m_vertices.m_capacityAndFlags = v26[0] / 16;
  }
  v20 = geom->m_vertices.m_size;
  v21 = this->m_vertices.m_data;
  this->m_vertices.m_size = v20;
  v22 = v20;
  if ( (int)v20 > 0 )
  {
    v23 = (char *)((char *)geom->m_vertices.m_data - (char *)v21);
    do
    {
      v24.m_quad = *(__m128 *)((char *)v21++ + (_QWORD)v23);
      v21[-1] = (hkVector4f)v24.m_quad;
      --v22;
    }
    while ( v22 );
  }
LABEL_34:
  if ( resulta.m_enum || v28.m_enum || v29.m_enum )
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
  else
  {
    result->m_enum = HK_SUCCESS;
    return result;
  }
}

// File Line: 471
// RVA: 0xB98BC0
hkResult *__fastcall hkaiEdgeGeometry::set(
        hkaiEdgeGeometry *this,
        hkResult *result,
        hkGeometry *geom,
        hkFlags<enum hkaiEdgeGeometry::FaceFlagBits,unsigned char> newFaceFlags,
        bool setFaceData)
{
  int m_size; // r9d
  __int64 v9; // rax
  hkVector4f *m_data; // rcx
  __int64 v11; // rdx
  char *v12; // rdi
  hkVector4f v13; // xmm0
  hkResult *v14; // rax
  int v15; // r9d
  int v16; // r9d
  int v17; // eax
  __int64 v18; // rbx
  int v19; // eax
  int v20; // r12d
  int v21; // eax
  int v22; // eax
  int v23; // r9d
  __int64 v24; // rax
  hkaiEdgeGeometry::Face *v25; // rsi
  __int64 v26; // rcx
  int v27; // eax
  hkaiEdgeGeometry::Face *v28; // rdi
  unsigned __int64 i; // rcx
  __int64 v30; // r12
  int v31; // esi
  int v32; // eax
  int v33; // eax
  int v34; // r9d
  hkaiEdgeGeometry::Edge *v35; // rax
  __int64 v36; // r9
  bool v37; // r10
  unsigned int v38; // edi
  __int64 v39; // r8
  hkGeometry::Triangle *v40; // rsi
  int m_b; // ecx
  int m_c; // ecx
  int m_a; // ecx
  hkaiEdgeGeometry::Face *v44; // rax
  hkResult v45; // [rsp+30h] [rbp-58h] BYREF
  hkResult v46; // [rsp+34h] [rbp-54h] BYREF
  int v47; // [rsp+40h] [rbp-48h]
  hkResult resulta; // [rsp+90h] [rbp+8h] BYREF
  hkResult v49; // [rsp+A0h] [rbp+18h] BYREF
  char m_storage; // [rsp+A8h] [rbp+20h]

  m_storage = newFaceFlags.m_storage;
  m_size = geom->m_vertices.m_size;
  if ( (this->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) >= m_size )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &this->m_vertices, m_size, 16);
    if ( resulta.m_enum )
    {
LABEL_13:
      v14 = result;
      result->m_enum = HK_FAILURE;
      return v14;
    }
  }
  if ( (this->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) < geom->m_vertices.m_size )
  {
    if ( this->m_vertices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_vertices.m_data,
        16 * this->m_vertices.m_capacityAndFlags);
    v49.m_enum = 16 * geom->m_vertices.m_size;
    this->m_vertices.m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                              &hkContainerHeapAllocator::s_alloc,
                                              &v49);
    this->m_vertices.m_capacityAndFlags = v49.m_enum / 16;
  }
  v9 = geom->m_vertices.m_size;
  m_data = this->m_vertices.m_data;
  this->m_vertices.m_size = v9;
  v11 = v9;
  if ( (int)v9 > 0 )
  {
    v12 = (char *)((char *)geom->m_vertices.m_data - (char *)m_data);
    do
    {
      v13.m_quad = *(__m128 *)((char *)m_data++ + (_QWORD)v12);
      m_data[-1] = (hkVector4f)v13.m_quad;
      --v11;
    }
    while ( v11 );
  }
  if ( resulta.m_enum )
    goto LABEL_13;
  v15 = geom->m_triangles.m_size;
  LOBYTE(v47) = m_storage;
  v16 = v15 + 1;
  v17 = this->m_faces.m_capacityAndFlags & 0x3FFFFFFF;
  v18 = 1i64;
  if ( v17 >= v16 )
  {
    v45.m_enum = HK_SUCCESS;
    goto LABEL_20;
  }
  v19 = 2 * v17;
  if ( v16 < v19 )
    v16 = v19;
  hkArrayUtil::_reserve(&v45, &hkContainerHeapAllocator::s_alloc, &this->m_faces, v16, 12);
  if ( v45.m_enum == HK_SUCCESS )
  {
LABEL_20:
    v20 = geom->m_triangles.m_size + 1;
    v21 = this->m_faces.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v21 < v20 )
    {
      v22 = 2 * v21;
      v23 = geom->m_triangles.m_size + 1;
      if ( v20 < v22 )
        v23 = v22;
      hkArrayUtil::_reserve(&v49, &hkContainerHeapAllocator::s_alloc, &this->m_faces, v23, 12);
    }
    v24 = this->m_faces.m_size;
    v25 = &this->m_faces.m_data[v24];
    v26 = v20 - (int)v24;
    if ( v20 - (int)v24 > 0 )
    {
      v27 = v47;
      v28 = v25 + 1;
      *(_QWORD *)&v25->m_data = 0i64;
      *(_DWORD *)&v25->m_flags.m_storage = v27;
      for ( i = (unsigned __int64)(12 * v26 - 12) >> 2; i; --i )
      {
        v28->m_data = v25->m_data;
        v25 = (hkaiEdgeGeometry::Face *)((char *)v25 + 4);
        v28 = (hkaiEdgeGeometry::Face *)((char *)v28 + 4);
      }
    }
    this->m_faces.m_size = v20;
    v30 = geom->m_triangles.m_size;
    v31 = 3 * v30;
    v32 = this->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v32 >= 3 * (int)v30 )
    {
      v46.m_enum = HK_SUCCESS;
    }
    else
    {
      v33 = 2 * v32;
      v34 = 3 * v30;
      if ( v31 < v33 )
        v34 = v33;
      hkArrayUtil::_reserve(&v46, &hkContainerHeapAllocator::s_alloc, &this->m_edges, v34, 16);
      if ( v46.m_enum )
      {
        result->m_enum = HK_FAILURE;
        return result;
      }
    }
    this->m_edges.m_size = v31;
    v35 = this->m_edges.m_data;
    v36 = v30;
    if ( (int)v30 > 0 )
    {
      v37 = setFaceData;
      v38 = 1;
      v39 = 0i64;
      do
      {
        v35 += 3;
        v40 = &geom->m_triangles.m_data[v39];
        v35[-3].m_a = v40->m_a;
        m_b = v40->m_b;
        v35[-3].m_face = v38;
        v35[-3].m_data = 0;
        v35[-3].m_b = m_b;
        v35[-2].m_a = v40->m_b;
        m_c = v40->m_c;
        v35[-2].m_face = v38;
        v35[-2].m_data = 0;
        v35[-2].m_b = m_c;
        v35[-1].m_a = v40->m_c;
        m_a = v40->m_a;
        v35[-1].m_face = v38;
        v35[-1].m_data = 0;
        v35[-1].m_b = m_a;
        if ( v37 )
        {
          this->m_faces.m_data[v18].m_faceIndex = v38;
          this->m_faces.m_data[v18].m_data = v40->m_material;
        }
        ++v38;
        ++v18;
        ++v39;
        --v36;
      }
      while ( v36 );
    }
    v44 = this->m_faces.m_data;
    result->m_enum = HK_SUCCESS;
    v44->m_flags.m_storage = 0;
    return result;
  }
  result->m_enum = HK_FAILURE;
  return result;
}

// File Line: 526
// RVA: 0xB9A460
void __fastcall hkaiEdgeGeometry::swap(hkaiEdgeGeometry *this, hkaiEdgeGeometry *geom)
{
  int m_capacityAndFlags; // eax
  int v5; // eax

  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&this->m_edges,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&geom->m_edges);
  if ( geom->m_faces.m_size == 1 )
  {
    m_capacityAndFlags = geom->m_faces.m_capacityAndFlags;
    geom->m_faces.m_size = 0;
    if ( m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        geom->m_faces.m_data,
        12 * (m_capacityAndFlags & 0x3FFFFFFF));
    geom->m_faces.m_data = 0i64;
    geom->m_faces.m_capacityAndFlags = 0x80000000;
  }
  if ( this->m_faces.m_size == 1 )
  {
    v5 = this->m_faces.m_capacityAndFlags;
    this->m_faces.m_size = 0;
    if ( v5 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_faces.m_data,
        12 * (v5 & 0x3FFFFFFF));
    this->m_faces.m_data = 0i64;
    this->m_faces.m_capacityAndFlags = 0x80000000;
  }
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&this->m_faces,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&geom->m_faces);
  if ( !this->m_faces.m_size )
  {
    this->m_faces.m_size = 1;
    this->m_faces.m_capacityAndFlags = -2147483647;
    this->m_faces.m_data = &this->m_zeroFace;
  }
  if ( !geom->m_faces.m_size )
  {
    geom->m_faces.m_size = 1;
    geom->m_faces.m_capacityAndFlags = -2147483647;
    geom->m_faces.m_data = &geom->m_zeroFace;
  }
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&this->m_vertices,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&geom->m_vertices);
}

// File Line: 564
// RVA: 0xB9A570
hkResult *__fastcall hkaiEdgeGeometry::checkConsistency(hkaiEdgeGeometry *this, hkResult *result)
{
  hkaiEdgeGeometryValidator checker; // [rsp+20h] [rbp-58h] BYREF

  checker.m_faceEdges.m_faceEdges.m_capacityAndFlags = 0x80000000;
  checker.m_faceEdges.m_faceStartEdges.m_capacityAndFlags = 0x80000000;
  checker.m_vertexIndexMap.m_capacityAndFlags = 0x80000000;
  checker.m_faceEdges.m_faceEdges.m_data = 0i64;
  checker.m_faceEdges.m_faceEdges.m_size = 0;
  checker.m_faceEdges.m_faceStartEdges.m_data = 0i64;
  checker.m_faceEdges.m_faceStartEdges.m_size = 0;
  checker.m_vertexIndexMap.m_data = 0i64;
  checker.m_vertexIndexMap.m_size = 0;
  checker.m_faceIndices.m_data = 0i64;
  checker.m_faceIndices.m_size = 0;
  checker.m_faceIndices.m_capacityAndFlags = 0x80000000;
  checker.m_indicesCount.m_data = 0i64;
  checker.m_indicesCount.m_size = 0;
  checker.m_indicesCount.m_capacityAndFlags = 0x80000000;
  hkaiEdgeGeometry::checkConsistency(this, result, &checker);
  hkaiEdgeGeometryValidator::~hkaiEdgeGeometryValidator(&checker);
  return result;
}

// File Line: 570
// RVA: 0xB9A600
hkResult *__fastcall hkaiEdgeGeometry::checkConsistency(
        hkaiEdgeGeometry *this,
        hkResult *result,
        hkaiEdgeGeometryValidator *checker)
{
  hkaiEdgeGeometry *v3; // r12
  hkResult *v5; // r14
  hkResult *v6; // rax
  int v7; // esi
  int m_size; // r9d
  hkArray<int,hkContainerHeapAllocator> *p_m_vertexIndexMap; // r15
  int v10; // eax
  int v11; // eax
  int v12; // ebx
  int v13; // eax
  int v14; // eax
  int v15; // r9d
  __int64 v16; // rdx
  int *v17; // rdi
  __int64 v18; // rcx
  hkArray<int,hkContainerHeapAllocator> *p_m_faceIndices; // rdi
  hkArray<int,hkContainerHeapAllocator> *p_m_indicesCount; // rbx
  __int64 v21; // rcx
  __int64 v22; // rax
  __int64 v23; // rax
  __int64 v24; // r14
  int **v25; // r12
  int v26; // esi
  int v27; // eax
  int v28; // eax
  int v29; // r9d
  int v30; // eax
  int v31; // eax
  int *v32; // rsi
  unsigned int v33; // eax
  __int64 v34; // rcx
  int v35; // r14d
  int v36; // r15d
  __int64 v37; // rcx
  int v38; // r14d
  int v39; // esi
  int v40; // edx
  int v41; // ecx
  int *m_data; // rax
  int v43; // r8d
  __int64 v44; // rdx
  int v45; // ebx
  int v46; // edi
  int v47; // eax
  _DWORD *v48; // r9
  int v49; // r8d
  int v50; // r9d
  __int64 v51; // r8
  void *v52; // rdx
  __int64 v53; // rcx
  _DWORD *v54; // rdi
  hkaiEdgeGeometry::Edge *v55; // rdi
  hkaiEdgeGeometry::Edge *v56; // r10
  __int64 m_face; // rcx
  int v58; // edi
  hkResult v59; // [rsp+30h] [rbp-29h] BYREF
  unsigned int v60; // [rsp+34h] [rbp-25h]
  __int64 v61; // [rsp+38h] [rbp-21h]
  hkArray<int,hkContainerHeapAllocator> *v62; // [rsp+40h] [rbp-19h]
  int **v63; // [rsp+48h] [rbp-11h]
  __int64 v64; // [rsp+50h] [rbp-9h]
  _DWORD *array; // [rsp+58h] [rbp-1h] BYREF
  int v66; // [rsp+60h] [rbp+7h]
  int v67; // [rsp+64h] [rbp+Bh]
  int v68; // [rsp+68h] [rbp+Fh]
  hkaiEdgeGeometry *v69; // [rsp+C0h] [rbp+67h] BYREF
  hkResult *v70; // [rsp+C8h] [rbp+6Fh]
  hkaiEdgeGeometryValidator *v71; // [rsp+D0h] [rbp+77h]
  hkResult resulta; // [rsp+D8h] [rbp+7Fh] BYREF

  v71 = checker;
  v70 = result;
  v69 = this;
  v3 = this;
  v5 = result;
  hkaiEdgeGeometryValidator::clear(checker);
  if ( v3->m_faces.m_size != 1 )
  {
    hkaiFaceEdges::setGeometry(&checker->m_faceEdges, &resulta, v3);
    if ( resulta.m_enum == HK_FAILURE )
    {
      v5->m_enum = HK_FAILURE;
      return v5;
    }
    v7 = checker->m_faceEdges.m_faceStartEdges.m_size - 1;
    v60 = v7;
    if ( v7 != v3->m_faces.m_size )
    {
      v5->m_enum = HK_FAILURE;
      return v5;
    }
    m_size = v3->m_vertices.m_size;
    p_m_vertexIndexMap = &checker->m_vertexIndexMap;
    v10 = checker->m_vertexIndexMap.m_capacityAndFlags & 0x3FFFFFFF;
    v62 = &checker->m_vertexIndexMap;
    if ( v10 < m_size )
    {
      v11 = 2 * v10;
      if ( m_size < v11 )
        m_size = v11;
      hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &checker->m_vertexIndexMap, m_size, 4);
      if ( resulta.m_enum )
      {
        v5->m_enum = HK_FAILURE;
        return v5;
      }
    }
    v12 = v3->m_vertices.m_size;
    v13 = checker->m_vertexIndexMap.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v13 < v12 )
    {
      v14 = 2 * v13;
      v15 = v3->m_vertices.m_size;
      if ( v12 < v14 )
        v15 = v14;
      hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &checker->m_vertexIndexMap, v15, 4);
    }
    v16 = checker->m_vertexIndexMap.m_size;
    v17 = &p_m_vertexIndexMap->m_data[v16];
    v18 = v12 - (int)v16;
    if ( v12 - (int)v16 > 0 )
    {
      while ( v18 )
      {
        *v17++ = -1;
        --v18;
      }
    }
    checker->m_vertexIndexMap.m_size = v12;
    p_m_faceIndices = &checker->m_faceIndices;
    p_m_indicesCount = &checker->m_indicesCount;
    v21 = 0i64;
    v64 = v7;
    v61 = 0i64;
    if ( v7 > 0 )
    {
      while ( 1 )
      {
        v22 = (__int64)v71;
        checker->m_faceIndices.m_size = 0;
        checker->m_indicesCount.m_size = 0;
        v23 = *(_QWORD *)(v22 + 16);
        v24 = *(_QWORD *)(v23 + 8 * v21 + 8);
        v25 = *(int ***)(v23 + 8 * v21);
        v63 = (int **)v24;
        v26 = 2 * ((v24 - (__int64)v25) >> 3);
        v27 = checker->m_faceIndices.m_capacityAndFlags & 0x3FFFFFFF;
        if ( v27 >= v26 )
        {
          resulta.m_enum = HK_SUCCESS;
        }
        else
        {
          v28 = 2 * v27;
          v29 = 2 * ((v24 - (__int64)v25) >> 3);
          if ( v26 < v28 )
            v29 = v28;
          hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, p_m_faceIndices, v29, 4);
          if ( resulta.m_enum )
            goto LABEL_26;
        }
        v30 = checker->m_indicesCount.m_capacityAndFlags & 0x3FFFFFFF;
        if ( v30 >= v26 )
        {
          v59.m_enum = HK_SUCCESS;
        }
        else
        {
          v31 = 2 * v30;
          if ( v26 < v31 )
            v26 = v31;
          hkArrayUtil::_reserve(&v59, &hkContainerHeapAllocator::s_alloc, p_m_indicesCount, v26, 4);
          if ( v59.m_enum )
            goto LABEL_26;
        }
        if ( v25 != (int **)v24 )
          break;
LABEL_50:
        v40 = checker->m_indicesCount.m_size;
        v41 = 0;
        if ( v40 > 0 )
        {
          m_data = p_m_indicesCount->m_data;
          while ( !*m_data )
          {
            ++v41;
            ++m_data;
            if ( v41 >= v40 )
              goto LABEL_54;
          }
LABEL_26:
          v6 = v70;
          v70->m_enum = HK_FAILURE;
          return v6;
        }
LABEL_54:
        v43 = 0;
        if ( checker->m_faceIndices.m_size > 0 )
        {
          v44 = 0i64;
          do
          {
            ++v43;
            p_m_vertexIndexMap->m_data[p_m_faceIndices->m_data[v44++]] = -1;
          }
          while ( v43 < checker->m_faceIndices.m_size );
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
        if ( !v33 || v33 >= v60 )
          goto LABEL_26;
        v34 = *v32;
        v35 = p_m_vertexIndexMap->m_data[v34];
        if ( v35 < 0 )
        {
          v35 = checker->m_faceIndices.m_size;
          p_m_vertexIndexMap->m_data[v34] = v35;
          v36 = *v32;
          if ( checker->m_faceIndices.m_size == (checker->m_faceIndices.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_m_faceIndices, 4);
          checker->m_faceIndices.m_data[checker->m_faceIndices.m_size++] = v36;
          if ( checker->m_indicesCount.m_size == (checker->m_indicesCount.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_m_indicesCount, 4);
          p_m_vertexIndexMap = v62;
          checker->m_indicesCount.m_data[checker->m_indicesCount.m_size++] = 0;
        }
        ++p_m_indicesCount->m_data[v35];
        v37 = v32[1];
        v38 = p_m_vertexIndexMap->m_data[v37];
        if ( v38 < 0 )
        {
          v38 = checker->m_faceIndices.m_size;
          p_m_vertexIndexMap->m_data[v37] = v38;
          v39 = v32[1];
          if ( checker->m_faceIndices.m_size == (checker->m_faceIndices.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_m_faceIndices, 4);
          checker->m_faceIndices.m_data[checker->m_faceIndices.m_size++] = v39;
          if ( checker->m_indicesCount.m_size == (checker->m_indicesCount.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_m_indicesCount, 4);
          checker->m_indicesCount.m_data[checker->m_indicesCount.m_size++] = 0;
        }
        ++v25;
        --p_m_indicesCount->m_data[v38];
        if ( v25 == v63 )
          goto LABEL_50;
      }
    }
LABEL_59:
    v45 = v3->m_faces.m_size;
    array = 0i64;
    v66 = 0;
    v67 = 0x80000000;
    v46 = (v45 + 31) >> 5;
    v47 = v46;
    if ( v46 )
    {
      LODWORD(v69) = 4 * v46;
      v48 = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &v69);
      v47 = (int)v69 / 4;
    }
    else
    {
      v48 = 0i64;
    }
    v49 = 0x80000000;
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
      hkArrayUtil::_reserve((hkResult *)&v69, &hkContainerHeapAllocator::s_alloc, &array, v50, 4);
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
          *v54++ = 0;
          --v53;
        }
        v49 = v67;
        v48 = array;
      }
      v55 = v3->m_edges.m_data;
      v56 = &v55[v3->m_edges.m_size];
      if ( v55 != v56 )
      {
        do
        {
          m_face = (int)v55->m_face;
          ++v55;
          v48[m_face >> 5] |= 1 << (m_face & 0x1F);
          v48 = array;
        }
        while ( v55 != v56 );
        v49 = v67;
      }
      v58 = 1;
      if ( v45 <= 1 )
      {
LABEL_83:
        v66 = 0;
        if ( v49 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v48, 4 * v49);
        v5->m_enum = HK_SUCCESS;
        return v5;
      }
      while ( ((v48[(__int64)v58 >> 5] >> (v58 & 0x1F)) & 1) != 0 )
      {
        if ( ++v58 >= v45 )
          goto LABEL_83;
      }
      v5->m_enum = HK_FAILURE;
      v66 = 0;
      if ( v49 < 0 )
        return v5;
      v52 = v48;
      v51 = (unsigned int)(4 * v49);
    }
    else
    {
      v5->m_enum = HK_FAILURE;
      v66 = 0;
      if ( v49 < 0 )
        return v5;
      v51 = (unsigned int)(4 * v49);
      v52 = 0i64;
    }
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v52, v51);
    return v5;
  }
  v6 = v5;
  if ( v3->m_edges.m_size )
    v5->m_enum = HK_FAILURE;
  else
    v5->m_enum = HK_SUCCESS;
  return v6;
}

// File Line: 725
// RVA: 0xB9AC50
void __fastcall hkaiEdgeGeometry::findLoopIndices(
        hkaiEdgeGeometry::Edge *const *start,
        hkaiEdgeGeometry::Edge *const *end,
        hkArray<int,hkContainerHeapAllocator> *indicesOut)
{
  hkaiEdgeGeometry::Edge *const *v6; // rdi
  unsigned __int64 v7; // rsi
  int i; // edi
  _BYTE v9[24]; // [rsp+20h] [rbp-18h] BYREF

  *(_DWORD *)&v9[12] = -1;
  v6 = start;
  indicesOut->m_size = 0;
  *(_QWORD *)v9 = 0i64;
  for ( *(_DWORD *)&v9[8] = 0; v6 != end; ++v6 )
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)v9,
      &hkContainerHeapAllocator::s_alloc,
      **(int **)v6,
      (int)(*v6)->m_b);
  v7 = **(int **)start;
  if ( indicesOut->m_size == (indicesOut->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, indicesOut, 4);
  indicesOut->m_data[indicesOut->m_size++] = v7;
  for ( i = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)v9,
              v7,
              0xFFFFFFFFFFFFFFFFui64);
        i != (_DWORD)v7;
        i = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)v9,
              i,
              0xFFFFFFFFFFFFFFFFui64) )
  {
    if ( indicesOut->m_size == (indicesOut->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, indicesOut, 4);
    indicesOut->m_data[indicesOut->m_size++] = i;
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)v9,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)v9);
}

// File Line: 753
// RVA: 0xB98790
void __fastcall hkaiEdgeGeometry::extractFace(
        hkaiEdgeGeometry *this,
        hkaiEdgeGeometry::Edge *const *start,
        hkaiEdgeGeometry::Edge *const *end,
        hkaiEdgeGeometry *geomOut)
{
  int m_size; // ebx
  __int64 v5; // r15
  hkaiEdgeGeometry *v6; // r12
  hkaiEdgeGeometry *v9; // r13
  __int64 v10; // r10
  int v11; // edi
  __int64 v12; // rcx
  _DWORD *v13; // rdi
  __int64 v14; // rdi
  __int64 v15; // rsi
  hkaiEdgeGeometry::Face *v16; // rdx
  hkaiEdgeGeometry::Edge *const *v17; // r13
  hkArray<hkaiEdgeGeometry::Edge,hkContainerHeapAllocator> *p_m_edges; // rdi
  __int64 v19; // r12
  hkaiEdgeGeometry::Edge *v20; // rbx
  __int64 v21; // rdx
  __int64 m_a; // rax
  int v23; // r14d
  int v24; // ecx
  unsigned int v25; // esi
  int v26; // ecx
  __int64 m_b; // rax
  int v28; // esi
  int v29; // ebx
  int v30; // ecx
  __int64 v31; // rcx
  int v32; // ecx
  int v33; // eax
  int v34; // edi
  int v35; // eax
  __int64 v36; // r9
  __int64 v37; // rdi
  __int64 v38; // r8
  __int64 v39; // rdx
  __int64 v40; // [rsp+30h] [rbp-28h] BYREF
  int v41; // [rsp+38h] [rbp-20h]
  int v42; // [rsp+3Ch] [rbp-1Ch]
  __int64 array; // [rsp+40h] [rbp-18h] BYREF
  int v44; // [rsp+48h] [rbp-10h]
  int v45; // [rsp+4Ch] [rbp-Ch]
  hkaiEdgeGeometry::Edge *const *v47; // [rsp+A8h] [rbp+50h] BYREF
  hkResult result; // [rsp+B0h] [rbp+58h] BYREF
  hkaiEdgeGeometry *v49; // [rsp+B8h] [rbp+60h]

  v49 = geomOut;
  v47 = start;
  m_size = this->m_vertices.m_size;
  v5 = 0i64;
  v6 = geomOut;
  v9 = this;
  v10 = 0i64;
  array = 0i64;
  v11 = 0;
  v44 = 0;
  v45 = 0x80000000;
  v40 = 0i64;
  v41 = 0;
  v42 = 0x80000000;
  if ( m_size > 0 )
  {
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array, m_size, 4);
    v11 = v44;
    v10 = array;
  }
  v12 = m_size - v11;
  if ( m_size - v11 > 0 )
  {
    v13 = (_DWORD *)(v10 + 4i64 * v11);
    while ( v12 )
    {
      *v13++ = -1;
      --v12;
    }
  }
  v44 = m_size;
  hkaiEdgeGeometry::clear(v6);
  if ( v6->m_faces.m_size == (v6->m_faces.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v6->m_faces, 12);
  v14 = v6->m_faces.m_size;
  v15 = end - start;
  v16 = &v6->m_faces.m_data[v14];
  v6->m_faces.m_size = v14 + 1;
  v16->m_data = 0;
  if ( (int)v15 > 0 )
  {
    v17 = v47;
    p_m_edges = &v6->m_edges;
    v19 = (int)v15;
    do
    {
      v20 = v17[v5];
      v21 = array;
      m_a = (int)v20->m_a;
      v23 = *(_DWORD *)(array + 4 * m_a);
      if ( v23 >= 0 )
      {
        v26 = v41;
      }
      else
      {
        v23 = v41;
        *(_DWORD *)(array + 4 * m_a) = v41;
        v24 = v41;
        v25 = v20->m_a;
        if ( v41 == (v42 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v40, 4);
          v24 = v41;
        }
        *(_DWORD *)(v40 + 4i64 * v24) = v25;
        v21 = array;
        v26 = ++v41;
      }
      m_b = (int)v20->m_b;
      v28 = *(_DWORD *)(v21 + 4 * m_b);
      if ( v28 < 0 )
      {
        *(_DWORD *)(v21 + 4 * m_b) = v26;
        v29 = v20->m_b;
        v28 = v26;
        v30 = v41;
        if ( v41 == (v42 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v40, 4);
          v30 = v41;
        }
        *(_DWORD *)(v40 + 4i64 * v30) = v29;
        ++v41;
      }
      if ( p_m_edges->m_size == (p_m_edges->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_m_edges, 16);
      ++v5;
      v31 = (__int64)&p_m_edges->m_data[p_m_edges->m_size++];
      *(_DWORD *)(v31 + 4) = v28;
      *(_DWORD *)v31 = v23;
      *(_QWORD *)(v31 + 8) = 1i64;
    }
    while ( v5 < v19 );
    v9 = this;
    v6 = v49;
  }
  v32 = v41;
  v33 = v6->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  v34 = v41;
  if ( v33 < v41 )
  {
    v35 = 2 * v33;
    if ( v41 < v35 )
      v32 = v35;
    hkArrayUtil::_reserve((hkResult *)&v47, &hkContainerHeapAllocator::s_alloc, &v6->m_vertices, v32, 16);
    v32 = v41;
  }
  v6->m_vertices.m_size = v34;
  v36 = 0i64;
  if ( v32 > 0 )
  {
    v37 = 0i64;
    v38 = 0i64;
    do
    {
      v36 = (unsigned int)(v36 + 1);
      v39 = *(int *)(v40 + v38);
      v38 += 4i64;
      v6->m_vertices.m_data[v37++] = v9->m_vertices.m_data[v39];
    }
    while ( (int)v36 < v41 );
  }
  v41 = 0;
  if ( v42 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, __int64, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      v40,
      (unsigned int)(4 * v42),
      v36);
  v40 = 0i64;
  v42 = 0x80000000;
  v44 = 0;
  if ( v45 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, __int64, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      array,
      (unsigned int)(4 * v45),
      v36);
}

// File Line: 803
// RVA: 0xB98AB0
void __fastcall hkaiEdgeGeometry::extractFace(hkaiEdgeGeometry *this, int faceIndexIn, hkaiEdgeGeometry *geomOut)
{
  hkaiEdgeGeometry::Edge *m_data; // rbx
  int v4; // eax
  char *v6; // rdx
  hkaiEdgeGeometry::Edge *v7; // rdi
  int v8; // r9d
  char *array; // [rsp+20h] [rbp-218h] BYREF
  int v12; // [rsp+28h] [rbp-210h]
  int i; // [rsp+2Ch] [rbp-20Ch]
  char v14[512]; // [rsp+30h] [rbp-208h] BYREF

  m_data = this->m_edges.m_data;
  v4 = 0;
  v6 = v14;
  v7 = &m_data[this->m_edges.m_size];
  v8 = -2147483584;
  array = v14;
  v12 = 0;
  for ( i = -2147483584; m_data != v7; ++m_data )
  {
    if ( m_data->m_face == faceIndexIn )
    {
      if ( v4 == (v8 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 8);
        v4 = v12;
        v6 = array;
      }
      *(_QWORD *)&v6[8 * v4] = m_data;
      v8 = i;
      v6 = array;
      v4 = ++v12;
    }
  }
  hkaiEdgeGeometry::extractFace(
    this,
    (hkaiEdgeGeometry::Edge *const *)v6,
    (hkaiEdgeGeometry::Edge *const *)&v6[8 * v4],
    geomOut);
  v12 = 0;
  if ( i >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * i);
}

// File Line: 824
// RVA: 0xB99230
hkResult *__fastcall hkaiEdgeGeometry::setForSingleTriangle(hkaiEdgeGeometry *this, hkResult *result)
{
  int v4; // r9d
  int v6; // r9d
  int v7; // r9d
  hkaiEdgeGeometry::Face *m_data; // rax
  hkResult resulta; // [rsp+50h] [rbp+8h] BYREF
  hkResult v10; // [rsp+60h] [rbp+18h] BYREF
  hkResult v11; // [rsp+68h] [rbp+20h] BYREF

  if ( (this->m_vertices.m_capacityAndFlags & 0x3FFFFFFFu) >= 3 )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    v4 = 3;
    if ( 2 * (this->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) > 3 )
      v4 = 2 * (this->m_vertices.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &this->m_vertices, v4, 16);
    if ( resulta.m_enum )
      goto LABEL_5;
  }
  this->m_vertices.m_size = 3;
  if ( (this->m_edges.m_capacityAndFlags & 0x3FFFFFFFu) >= 3 )
  {
    v10.m_enum = HK_SUCCESS;
  }
  else
  {
    v6 = 3;
    if ( 2 * (this->m_edges.m_capacityAndFlags & 0x3FFFFFFF) > 3 )
      v6 = 2 * (this->m_edges.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&v10, &hkContainerHeapAllocator::s_alloc, &this->m_edges, v6, 16);
    if ( v10.m_enum )
    {
      result->m_enum = HK_FAILURE;
      return result;
    }
  }
  this->m_edges.m_size = 3;
  this->m_edges.m_data->m_a = 2;
  this->m_edges.m_data->m_b = 0;
  this->m_edges.m_data->m_face = 1;
  this->m_edges.m_data->m_data = 0;
  this->m_edges.m_data[1].m_a = 0;
  this->m_edges.m_data[1].m_b = 1;
  this->m_edges.m_data[1].m_face = 1;
  this->m_edges.m_data[1].m_data = 0;
  this->m_edges.m_data[2].m_a = 1;
  this->m_edges.m_data[2].m_b = 2;
  this->m_edges.m_data[2].m_face = 1;
  this->m_edges.m_data[2].m_data = 0;
  if ( (this->m_faces.m_capacityAndFlags & 0x3FFFFFFFu) < 2 )
  {
    v7 = 2;
    if ( 2 * (this->m_faces.m_capacityAndFlags & 0x3FFFFFFF) > 2 )
      v7 = 2 * (this->m_faces.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&v11, &hkContainerHeapAllocator::s_alloc, &this->m_faces, v7, 12);
    if ( v11.m_enum )
    {
LABEL_5:
      result->m_enum = HK_FAILURE;
      return result;
    }
  }
  this->m_faces.m_size = 2;
  m_data = this->m_faces.m_data;
  result->m_enum = HK_SUCCESS;
  m_data->m_data = 0;
  this->m_faces.m_data->m_faceIndex = 0;
  this->m_faces.m_data->m_flags.m_storage = 0;
  this->m_faces.m_data[1].m_data = 0;
  this->m_faces.m_data[1].m_faceIndex = 0;
  this->m_faces.m_data[1].m_flags.m_storage = 1;
  return result;
}

