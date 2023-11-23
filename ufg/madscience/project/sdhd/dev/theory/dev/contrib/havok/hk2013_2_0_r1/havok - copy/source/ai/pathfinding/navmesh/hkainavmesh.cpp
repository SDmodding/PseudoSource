// File Line: 29
// RVA: 0xBE37D0
void __fastcall hkaiNavMesh::hkaiNavMesh(hkaiNavMesh *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiNavMesh::`vftable;
}

// File Line: 34
// RVA: 0xBE3710
void __fastcall hkaiNavMesh::hkaiNavMesh(hkaiNavMesh *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiNavMesh::`vftable;
  this->m_faces.m_data = 0i64;
  this->m_faces.m_size = 0;
  this->m_faces.m_capacityAndFlags = 0x80000000;
  this->m_edges.m_data = 0i64;
  this->m_edges.m_size = 0;
  this->m_edges.m_capacityAndFlags = 0x80000000;
  this->m_vertices.m_data = 0i64;
  this->m_vertices.m_size = 0;
  this->m_vertices.m_capacityAndFlags = 0x80000000;
  this->m_streamingSets.m_data = 0i64;
  this->m_streamingSets.m_size = 0;
  this->m_streamingSets.m_capacityAndFlags = 0x80000000;
  this->m_faceData.m_data = 0i64;
  this->m_faceData.m_size = 0;
  this->m_faceData.m_capacityAndFlags = 0x80000000;
  this->m_edgeData.m_data = 0i64;
  this->m_edgeData.m_size = 0;
  this->m_edgeData.m_capacityAndFlags = 0x80000000;
  this->m_aabb.m_min = (hkVector4f)xmmword_141A712A0;
  this->m_aabb.m_max.m_quad = _mm_xor_ps(
                                (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                this->m_aabb.m_min.m_quad);
  this->m_erosionRadius = 0.0;
  this->m_userData = 0i64;
  this->m_flags.m_storage = 0;
  this->m_faceDataStriding = 1;
  this->m_edgeDataStriding = 1;
}

// File Line: 46
// RVA: 0xBE37F0
void __fastcall hkaiNavMesh::~hkaiNavMesh(hkaiNavMesh *this)
{
  int m_capacityAndFlags; // r8d
  int v3; // r8d
  int v4; // edi
  hkaiStreamingSet *v5; // rsi
  int v6; // r8d
  int v7; // r8d
  int v8; // eax
  int v9; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkaiNavMesh::`vftable;
  m_capacityAndFlags = this->m_edgeData.m_capacityAndFlags;
  this->m_edgeData.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_edgeData.m_data,
      4 * m_capacityAndFlags);
  this->m_edgeData.m_data = 0i64;
  this->m_edgeData.m_capacityAndFlags = 0x80000000;
  v3 = this->m_faceData.m_capacityAndFlags;
  this->m_faceData.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_faceData.m_data,
      4 * v3);
  this->m_faceData.m_data = 0i64;
  this->m_faceData.m_capacityAndFlags = 0x80000000;
  v4 = this->m_streamingSets.m_size - 1;
  if ( v4 >= 0 )
  {
    v5 = &this->m_streamingSets.m_data[v4];
    do
    {
      hkaiStreamingSet::~hkaiStreamingSet(v5--);
      --v4;
    }
    while ( v4 >= 0 );
  }
  v6 = this->m_streamingSets.m_capacityAndFlags;
  this->m_streamingSets.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_streamingSets.m_data,
      56 * (v6 & 0x3FFFFFFF));
  this->m_streamingSets.m_data = 0i64;
  this->m_streamingSets.m_capacityAndFlags = 0x80000000;
  v7 = this->m_vertices.m_capacityAndFlags;
  this->m_vertices.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_vertices.m_data,
      16 * v7);
  this->m_vertices.m_data = 0i64;
  this->m_vertices.m_capacityAndFlags = 0x80000000;
  v8 = this->m_edges.m_capacityAndFlags;
  this->m_edges.m_size = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_edges.m_data,
      20 * (v8 & 0x3FFFFFFF));
  this->m_edges.m_data = 0i64;
  this->m_edges.m_capacityAndFlags = 0x80000000;
  v9 = this->m_faces.m_capacityAndFlags;
  this->m_faces.m_size = 0;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, this->m_faces.m_data, 16 * v9);
  this->m_faces.m_data = 0i64;
  this->m_faces.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 50
// RVA: 0xBE41F0
hkResult *__fastcall hkaiNavMesh::appendVertices(hkaiNavMesh *this, hkResult *result, hkVector4f *v, int numVerts)
{
  hkArray<hkVector4f,hkContainerHeapAllocator> *p_m_vertices; // rsi
  int v9; // [rsp+48h] [rbp+20h] BYREF

  p_m_vertices = &this->m_vertices;
  hkaiArrayUtil::reserveSmall<hkVector4f,hkContainerHeapAllocator>(
    (hkaiArrayUtil *)&v9,
    (hkResult *)&this->m_vertices,
    (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(unsigned int)(numVerts + this->m_vertices.m_size),
    -1);
  if ( v9 )
  {
    result->m_enum = HK_FAILURE;
  }
  else
  {
    hkArrayBase<hkVector4f>::_append(p_m_vertices, &hkContainerHeapAllocator::s_alloc, v, numVerts);
    result->m_enum = HK_SUCCESS;
  }
  return result;
}

// File Line: 60
// RVA: 0xBE4280
hkVector4f *__fastcall hkaiNavMesh::expandVerticesBy(hkaiNavMesh *this, int n)
{
  hkArray<hkVector4f,hkContainerHeapAllocator> *p_m_vertices; // rbx
  __int64 m_size; // rcx
  int v6; // [rsp+38h] [rbp+10h] BYREF

  p_m_vertices = &this->m_vertices;
  hkaiArrayUtil::reserveSmall<hkVector4f,hkContainerHeapAllocator>(
    (hkaiArrayUtil *)&v6,
    (hkResult *)&this->m_vertices,
    (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(unsigned int)(n + this->m_vertices.m_size),
    -1);
  if ( v6 )
    return 0i64;
  m_size = p_m_vertices->m_size;
  p_m_vertices->m_size = m_size + n;
  return &p_m_vertices->m_data[m_size];
}

// File Line: 69
// RVA: 0xBE42F0
hkaiNavMesh::Face *__fastcall hkaiNavMesh::expandFacesBy(hkaiNavMesh *this, int n, int estimatedMaxNumFaces)
{
  int m_faceDataStriding; // r9d
  int v7; // ebx
  int v9; // eax
  int v10; // eax
  int v11; // r9d
  int v12; // edx
  int *v13; // rdi
  __int64 v14; // rcx
  __int64 m_size; // rcx
  hkResult result; // [rsp+30h] [rbp-38h] BYREF
  int v17; // [rsp+70h] [rbp+8h] BYREF
  int v18; // [rsp+88h] [rbp+20h] BYREF

  m_faceDataStriding = this->m_faceDataStriding;
  if ( m_faceDataStriding )
  {
    v7 = this->m_faceData.m_size + n * m_faceDataStriding;
    hkaiArrayUtil::reserveSmall<int,hkContainerHeapAllocator>(
      (hkaiArrayUtil *)&v17,
      (hkResult *)&this->m_faceData,
      (hkArray<unsigned int,hkContainerHeapAllocator> *)(unsigned int)v7,
      estimatedMaxNumFaces * m_faceDataStriding);
    if ( v17 )
      return 0i64;
    v9 = this->m_faceData.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v9 < v7 )
    {
      v10 = 2 * v9;
      v11 = v7;
      if ( v7 < v10 )
        v11 = v10;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_faceData, v11, 4);
    }
    v12 = v7 - this->m_faceData.m_size;
    v13 = &this->m_faceData.m_data[this->m_faceData.m_size];
    v14 = v12;
    if ( v12 > 0 )
    {
      while ( v14 )
      {
        *v13++ = 0;
        --v14;
      }
    }
    this->m_faceData.m_size = v7;
  }
  hkaiArrayUtil::reserveSmall<hkVector4f,hkContainerHeapAllocator>(
    (hkaiArrayUtil *)&v18,
    (hkResult *)&this->m_faces,
    (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(unsigned int)(n + this->m_faces.m_size),
    estimatedMaxNumFaces);
  if ( v18 )
    return 0i64;
  m_size = this->m_faces.m_size;
  this->m_faces.m_size = m_size + n;
  return &this->m_faces.m_data[m_size];
}

// File Line: 87
// RVA: 0xBE4550
hkaiNavMesh::Edge *__fastcall hkaiNavMesh::expandEdgesBy(hkaiNavMesh *this, int n, int estimatedMaxNumEdges)
{
  int m_edgeDataStriding; // r9d
  int v7; // ebx
  int v9; // eax
  int v10; // eax
  int v11; // r9d
  int v12; // edx
  int *v13; // rdi
  __int64 v14; // rcx
  __int64 m_size; // rcx
  int sizeElem; // [rsp+20h] [rbp-48h]
  hkResult result; // [rsp+30h] [rbp-38h] BYREF
  int v18; // [rsp+70h] [rbp+8h] BYREF
  int v19; // [rsp+88h] [rbp+20h] BYREF

  m_edgeDataStriding = this->m_edgeDataStriding;
  if ( m_edgeDataStriding )
  {
    v7 = this->m_edgeData.m_size + n * m_edgeDataStriding;
    hkaiArrayUtil::reserveSmall<int,hkContainerHeapAllocator>(
      (hkaiArrayUtil *)&v18,
      (hkResult *)&this->m_edgeData,
      (hkArray<unsigned int,hkContainerHeapAllocator> *)(unsigned int)v7,
      estimatedMaxNumEdges * m_edgeDataStriding);
    if ( v18 )
      return 0i64;
    v9 = this->m_edgeData.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v9 < v7 )
    {
      v10 = 2 * v9;
      v11 = v7;
      if ( v7 < v10 )
        v11 = v10;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_edgeData, v11, 4);
    }
    v12 = v7 - this->m_edgeData.m_size;
    v13 = &this->m_edgeData.m_data[this->m_edgeData.m_size];
    v14 = v12;
    if ( v12 > 0 )
    {
      while ( v14 )
      {
        *v13++ = 0;
        --v14;
      }
    }
    this->m_edgeData.m_size = v7;
  }
  hkaiArrayUtil::reserveSmall<hkaiNavMesh::Edge,hkContainerHeapAllocator>(
    (hkaiArrayUtil *)&v19,
    (hkResult *)&this->m_edges,
    (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(unsigned int)(n + this->m_edges.m_size),
    estimatedMaxNumEdges,
    sizeElem);
  if ( v19 )
    return 0i64;
  m_size = this->m_edges.m_size;
  this->m_edges.m_size = m_size + n;
  return &this->m_edges.m_data[m_size];
}

// File Line: 104
// RVA: 0xBE4400
hkResult *__fastcall hkaiNavMesh::appendEdges(
        hkaiNavMesh *this,
        hkResult *result,
        hkaiNavMesh::Edge *edges,
        const unsigned int *edgeData,
        int n)
{
  int v5; // edi
  int v10; // esi
  int m_edgeDataStriding; // r9d
  int v12; // eax
  int v13; // eax
  int v14; // r9d
  int v15; // edx
  int *v16; // rdi
  __int64 v17; // rcx
  int sizeElem; // [rsp+20h] [rbp-38h]
  int v20; // [rsp+60h] [rbp+8h] BYREF

  v5 = n;
  v10 = this->m_edgeData.m_size + n * this->m_edgeDataStriding;
  if ( this->m_edgeDataStriding
    && (hkaiArrayUtil::reserveSmall<int,hkContainerHeapAllocator>(
          (hkaiArrayUtil *)&n,
          (hkResult *)&this->m_edgeData,
          (hkArray<unsigned int,hkContainerHeapAllocator> *)(unsigned int)v10,
          -1),
        n) )
  {
    result->m_enum = HK_FAILURE;
  }
  else
  {
    hkaiArrayUtil::reserveSmall<hkaiNavMesh::Edge,hkContainerHeapAllocator>(
      (hkaiArrayUtil *)&v20,
      (hkResult *)&this->m_edges,
      (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(unsigned int)(v5 + this->m_edges.m_size),
      -1,
      sizeElem);
    if ( v20 )
    {
      result->m_enum = HK_FAILURE;
    }
    else
    {
      hkArrayBase<hkaiNavMesh::Edge>::_append(&this->m_edges, &hkContainerHeapAllocator::s_alloc, edges, v5);
      m_edgeDataStriding = this->m_edgeDataStriding;
      if ( m_edgeDataStriding )
      {
        if ( edgeData )
        {
          hkArrayBase<unsigned int>::_append(
            (hkArrayBase<unsigned int> *)&this->m_edgeData,
            &hkContainerHeapAllocator::s_alloc,
            edgeData,
            v5 * m_edgeDataStriding);
        }
        else
        {
          v12 = this->m_edgeData.m_capacityAndFlags & 0x3FFFFFFF;
          if ( v12 < v10 )
          {
            v13 = 2 * v12;
            v14 = v10;
            if ( v10 < v13 )
              v14 = v13;
            hkArrayUtil::_reserve((hkResult *)&n, &hkContainerHeapAllocator::s_alloc, &this->m_edgeData, v14, 4);
          }
          v15 = v10 - this->m_edgeData.m_size;
          v16 = &this->m_edgeData.m_data[this->m_edgeData.m_size];
          v17 = v15;
          if ( v15 > 0 )
          {
            while ( v17 )
            {
              *v16++ = 0;
              --v17;
            }
          }
          this->m_edgeData.m_size = v10;
        }
      }
      result->m_enum = HK_SUCCESS;
    }
  }
  return result;
}

// File Line: 130
// RVA: 0xBE39B0
hkResult *__fastcall hkaiNavMesh::copy(hkaiNavMesh *this, hkResult *result, hkaiNavMesh *other)
{
  int m_size; // r9d
  __int64 v7; // rax
  hkaiNavMesh::Face *m_data; // rcx
  __int64 v9; // r8
  char *v10; // rdx
  int v11; // eax
  int v12; // r9d
  int v13; // eax
  __int64 v14; // rax
  hkaiNavMesh::Edge *v15; // r9
  __int64 v16; // r8
  int *p_m_b; // rcx
  char *v18; // rdx
  int v19; // eax
  int v20; // r9d
  __int64 v21; // rax
  hkVector4f *v22; // rcx
  __int64 v23; // rdx
  char *v24; // r8
  hkVector4f v25; // xmm0
  int v26; // r9d
  __int64 v27; // rax
  int *v28; // rcx
  __int64 v29; // rdx
  char *v30; // r8
  int v31; // eax
  int v32; // r9d
  __int64 v33; // rax
  int *v34; // rcx
  __int64 v35; // rdx
  char *v36; // r8
  int v37; // eax
  int m_faceDataStriding; // eax
  hkResult v40; // [rsp+30h] [rbp-10h] BYREF
  hkResult v41; // [rsp+34h] [rbp-Ch] BYREF
  int v42; // [rsp+38h] [rbp-8h] BYREF
  hkResult v43; // [rsp+3Ch] [rbp-4h] BYREF
  hkResult resulta; // [rsp+70h] [rbp+30h] BYREF
  hkResult v45; // [rsp+80h] [rbp+40h] BYREF
  hkResult v46; // [rsp+88h] [rbp+48h] BYREF

  m_size = other->m_faces.m_size;
  if ( (this->m_faces.m_capacityAndFlags & 0x3FFFFFFF) >= m_size )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &this->m_faces, m_size, 16);
    if ( resulta.m_enum )
      goto LABEL_12;
  }
  if ( (this->m_faces.m_capacityAndFlags & 0x3FFFFFFF) < other->m_faces.m_size )
  {
    if ( this->m_faces.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_faces.m_data,
        16 * this->m_faces.m_capacityAndFlags);
    v42 = 16 * other->m_faces.m_size;
    this->m_faces.m_data = (hkaiNavMesh::Face *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                  &hkContainerHeapAllocator::s_alloc,
                                                  &v42);
    this->m_faces.m_capacityAndFlags = v42 / 16;
  }
  v7 = other->m_faces.m_size;
  m_data = this->m_faces.m_data;
  this->m_faces.m_size = v7;
  v9 = v7;
  if ( (int)v7 > 0 )
  {
    v10 = (char *)((char *)other->m_faces.m_data - (char *)m_data);
    do
    {
      v11 = *(int *)((char *)&m_data->m_startEdgeIndex + (_QWORD)v10);
      ++m_data;
      m_data[-1].m_startEdgeIndex = v11;
      m_data[-1].m_startUserEdgeIndex = *(_DWORD *)((char *)m_data + (_QWORD)v10 - 12);
      *(_DWORD *)&m_data[-1].m_numEdges = *(_DWORD *)((char *)m_data + (_QWORD)v10 - 8);
      *(_DWORD *)&m_data[-1].m_clusterIndex = *(_DWORD *)((char *)m_data + (_QWORD)v10 - 4);
      --v9;
    }
    while ( v9 );
  }
LABEL_12:
  v12 = other->m_edges.m_size;
  if ( (this->m_edges.m_capacityAndFlags & 0x3FFFFFFF) >= v12 )
  {
    v45.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&v45, &hkContainerHeapAllocator::s_alloc, &this->m_edges, v12, 20);
    if ( v45.m_enum )
      goto LABEL_23;
  }
  v13 = this->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v13 < other->m_edges.m_size )
  {
    if ( this->m_edges.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_edges.m_data,
        20 * v13);
    v42 = 20 * other->m_edges.m_size;
    this->m_edges.m_data = (hkaiNavMesh::Edge *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                  &hkContainerHeapAllocator::s_alloc,
                                                  &v42);
    this->m_edges.m_capacityAndFlags = v42 / 20;
  }
  v14 = other->m_edges.m_size;
  v15 = this->m_edges.m_data;
  this->m_edges.m_size = v14;
  v16 = v14;
  if ( (int)v14 > 0 )
  {
    p_m_b = &v15->m_b;
    v18 = (char *)((char *)other->m_edges.m_data - (char *)v15);
    do
    {
      v19 = *(int *)((char *)p_m_b + (_QWORD)v18 - 4);
      p_m_b += 5;
      *(p_m_b - 6) = v19;
      *(p_m_b - 5) = *(int *)((char *)p_m_b + (_QWORD)v18 - 20);
      *(p_m_b - 4) = *(int *)((char *)p_m_b + (_QWORD)v18 - 16);
      *(p_m_b - 3) = *(int *)((char *)p_m_b + (_QWORD)v18 - 12);
      *((_BYTE *)p_m_b - 8) = *((_BYTE *)p_m_b + (_QWORD)v18 - 8);
      *((_BYTE *)p_m_b - 7) = *((_BYTE *)p_m_b + (_QWORD)v18 - 7);
      *((_WORD *)p_m_b - 3) = *(_WORD *)((char *)p_m_b + (_QWORD)v18 - 6);
      --v16;
    }
    while ( v16 );
  }
LABEL_23:
  v20 = other->m_vertices.m_size;
  if ( (this->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) >= v20 )
  {
    v46.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&v46, &hkContainerHeapAllocator::s_alloc, &this->m_vertices, v20, 16);
    if ( v46.m_enum )
      goto LABEL_34;
  }
  if ( (this->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) < other->m_vertices.m_size )
  {
    if ( this->m_vertices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_vertices.m_data,
        16 * this->m_vertices.m_capacityAndFlags);
    v42 = 16 * other->m_vertices.m_size;
    this->m_vertices.m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                              &hkContainerHeapAllocator::s_alloc,
                                              &v42);
    this->m_vertices.m_capacityAndFlags = v42 / 16;
  }
  v21 = other->m_vertices.m_size;
  v22 = this->m_vertices.m_data;
  this->m_vertices.m_size = v21;
  v23 = v21;
  if ( (int)v21 > 0 )
  {
    v24 = (char *)((char *)other->m_vertices.m_data - (char *)v22);
    do
    {
      v25.m_quad = *(__m128 *)((char *)v22++ + (_QWORD)v24);
      v22[-1] = (hkVector4f)v25.m_quad;
      --v23;
    }
    while ( v23 );
  }
LABEL_34:
  v26 = other->m_faceData.m_size;
  if ( (this->m_faceData.m_capacityAndFlags & 0x3FFFFFFF) >= v26 )
  {
    v40.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&v40, &hkContainerHeapAllocator::s_alloc, &this->m_faceData, v26, 4);
    if ( v40.m_enum )
      goto LABEL_45;
  }
  if ( (this->m_faceData.m_capacityAndFlags & 0x3FFFFFFF) < other->m_faceData.m_size )
  {
    if ( this->m_faceData.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_faceData.m_data,
        4 * this->m_faceData.m_capacityAndFlags);
    v42 = 4 * other->m_faceData.m_size;
    this->m_faceData.m_data = (int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                       &hkContainerHeapAllocator::s_alloc,
                                       &v42);
    this->m_faceData.m_capacityAndFlags = v42 / 4;
  }
  v27 = other->m_faceData.m_size;
  v28 = this->m_faceData.m_data;
  this->m_faceData.m_size = v27;
  v29 = v27;
  if ( (int)v27 > 0 )
  {
    v30 = (char *)((char *)other->m_faceData.m_data - (char *)v28);
    do
    {
      v31 = *(int *)((char *)v28++ + (_QWORD)v30);
      *(v28 - 1) = v31;
      --v29;
    }
    while ( v29 );
  }
LABEL_45:
  v32 = other->m_edgeData.m_size;
  if ( (this->m_edgeData.m_capacityAndFlags & 0x3FFFFFFF) >= v32 )
  {
    v41.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&v41, &hkContainerHeapAllocator::s_alloc, &this->m_edgeData, v32, 4);
    if ( v41.m_enum )
      goto LABEL_56;
  }
  if ( (this->m_edgeData.m_capacityAndFlags & 0x3FFFFFFF) < other->m_edgeData.m_size )
  {
    if ( this->m_edgeData.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_edgeData.m_data,
        4 * this->m_edgeData.m_capacityAndFlags);
    v42 = 4 * other->m_edgeData.m_size;
    this->m_edgeData.m_data = (int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                       &hkContainerHeapAllocator::s_alloc,
                                       &v42);
    this->m_edgeData.m_capacityAndFlags = v42 / 4;
  }
  v33 = other->m_edgeData.m_size;
  v34 = this->m_edgeData.m_data;
  this->m_edgeData.m_size = v33;
  v35 = v33;
  if ( (int)v33 > 0 )
  {
    v36 = (char *)((char *)other->m_edgeData.m_data - (char *)v34);
    do
    {
      v37 = *(int *)((char *)v34++ + (_QWORD)v36);
      *(v34 - 1) = v37;
      --v35;
    }
    while ( v35 );
  }
LABEL_56:
  hkaiStreamingSet::_copy(&v43, &this->m_streamingSets, &other->m_streamingSets);
  if ( resulta.m_enum || v45.m_enum || v46.m_enum || v43.m_enum || v40.m_enum || v41.m_enum )
  {
    result->m_enum = HK_FAILURE;
  }
  else
  {
    m_faceDataStriding = other->m_faceDataStriding;
    result->m_enum = HK_SUCCESS;
    this->m_faceDataStriding = m_faceDataStriding;
    this->m_edgeDataStriding = other->m_edgeDataStriding;
    this->m_flags.m_storage = other->m_flags.m_storage;
    this->m_aabb.m_min = other->m_aabb.m_min;
    this->m_aabb.m_max = other->m_aabb.m_max;
    this->m_erosionRadius = other->m_erosionRadius;
    this->m_userData = other->m_userData;
  }
  return result;
}

// File Line: 157
// RVA: 0xBE3EE0
void __fastcall hkaiNavMesh::swap(hkaiNavMesh *this, hkaiNavMesh *other)
{
  int m_faceDataStriding; // ecx
  int m_edgeDataStriding; // ecx
  char m_storage; // al
  hkVector4f v7; // xmm3
  hkVector4f v8; // xmm2
  float m_erosionRadius; // xmm0_4
  unsigned __int64 m_userData; // rcx

  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&this->m_faces,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&other->m_faces);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&this->m_edges,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&other->m_edges);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&this->m_vertices,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&other->m_vertices);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&this->m_streamingSets,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&other->m_streamingSets);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&this->m_faceData,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&other->m_faceData);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&this->m_edgeData,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&other->m_edgeData);
  m_faceDataStriding = this->m_faceDataStriding;
  this->m_faceDataStriding = other->m_faceDataStriding;
  other->m_faceDataStriding = m_faceDataStriding;
  m_edgeDataStriding = this->m_edgeDataStriding;
  this->m_edgeDataStriding = other->m_edgeDataStriding;
  other->m_edgeDataStriding = m_edgeDataStriding;
  m_storage = this->m_flags.m_storage;
  this->m_flags.m_storage = other->m_flags.m_storage;
  other->m_flags.m_storage = m_storage;
  v7.m_quad = (__m128)this->m_aabb.m_min;
  v8.m_quad = (__m128)this->m_aabb.m_max;
  this->m_aabb = other->m_aabb;
  other->m_aabb.m_min = (hkVector4f)v7.m_quad;
  other->m_aabb.m_max = (hkVector4f)v8.m_quad;
  m_erosionRadius = this->m_erosionRadius;
  this->m_erosionRadius = other->m_erosionRadius;
  other->m_erosionRadius = m_erosionRadius;
  m_userData = this->m_userData;
  this->m_userData = other->m_userData;
  other->m_userData = m_userData;
}

// File Line: 176
// RVA: 0xBE3FF0
void __fastcall hkaiNavMesh::clear(hkaiNavMesh *this)
{
  int m_capacityAndFlags; // r8d
  int v3; // eax
  int v4; // r8d
  int v5; // edi
  hkaiStreamingSet *v6; // rsi
  int v7; // r8d
  int v8; // r8d
  int v9; // r8d

  m_capacityAndFlags = this->m_faces.m_capacityAndFlags;
  this->m_faces.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_faces.m_data,
      16 * m_capacityAndFlags);
  this->m_faces.m_data = 0i64;
  this->m_faces.m_capacityAndFlags = 0x80000000;
  v3 = this->m_edges.m_capacityAndFlags;
  this->m_edges.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_edges.m_data,
      20 * (v3 & 0x3FFFFFFF));
  this->m_edges.m_data = 0i64;
  this->m_edges.m_capacityAndFlags = 0x80000000;
  v4 = this->m_vertices.m_capacityAndFlags;
  this->m_vertices.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_vertices.m_data,
      16 * v4);
  this->m_vertices.m_data = 0i64;
  this->m_vertices.m_capacityAndFlags = 0x80000000;
  v5 = this->m_streamingSets.m_size - 1;
  if ( v5 >= 0 )
  {
    v6 = &this->m_streamingSets.m_data[v5];
    do
    {
      hkaiStreamingSet::~hkaiStreamingSet(v6--);
      --v5;
    }
    while ( v5 >= 0 );
  }
  v7 = this->m_streamingSets.m_capacityAndFlags;
  this->m_streamingSets.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_streamingSets.m_data,
      56 * (v7 & 0x3FFFFFFF));
  this->m_streamingSets.m_data = 0i64;
  this->m_streamingSets.m_capacityAndFlags = 0x80000000;
  v8 = this->m_faceData.m_capacityAndFlags;
  this->m_faceData.m_size = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_faceData.m_data,
      4 * v8);
  this->m_faceData.m_data = 0i64;
  this->m_faceData.m_capacityAndFlags = 0x80000000;
  v9 = this->m_edgeData.m_capacityAndFlags;
  this->m_edgeData.m_size = 0;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_edgeData.m_data,
      4 * v9);
  this->m_edgeData.m_data = 0i64;
  this->m_edgeData.m_capacityAndFlags = 0x80000000;
  this->m_faceDataStriding = 1;
  this->m_edgeDataStriding = 1;
  this->m_aabb.m_min = (hkVector4f)xmmword_141A712A0;
  this->m_aabb.m_max.m_quad = _mm_xor_ps(
                                (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                this->m_aabb.m_min.m_quad);
  this->m_erosionRadius = 0.0;
  this->m_userData = 0i64;
  this->m_flags.m_storage = 0;
}

// File Line: 192
// RVA: 0xBE41E0
void __fastcall hkaiNavMesh::checkDeterminism(hkaiNavMesh *this)
{
  hkaiStreamingSet::checkDeterminism(&this->m_streamingSets);
}

// File Line: 210
// RVA: 0xBE4890
hkaiUserDataUtils *__fastcall hkaiNavMesh::setFaceDataStriding(
        hkaiNavMesh *this,
        hkaiUserDataUtils *result,
        int newStride,
        int fillValue)
{
  int m_size; // eax
  hkArray<int,hkContainerHeapAllocator> *m_faceDataStriding; // r8
  int v9; // [rsp+30h] [rbp-8h]

  m_size = this->m_faces.m_size;
  m_faceDataStriding = (hkArray<int,hkContainerHeapAllocator> *)(unsigned int)this->m_faceDataStriding;
  this->m_faceDataStriding = newStride;
  hkaiUserDataUtils::restride<int>(
    result,
    (hkResult *)&this->m_faceData,
    m_faceDataStriding,
    newStride,
    m_size,
    fillValue,
    v9);
  return result;
}

// File Line: 217
// RVA: 0xBE48D0
hkaiUserDataUtils *__fastcall hkaiNavMesh::setEdgeDataStriding(
        hkaiNavMesh *this,
        hkaiUserDataUtils *result,
        int newStride,
        int fillValue)
{
  int m_size; // eax
  hkArray<int,hkContainerHeapAllocator> *m_edgeDataStriding; // r8
  int v9; // [rsp+30h] [rbp-8h]

  m_size = this->m_edges.m_size;
  m_edgeDataStriding = (hkArray<int,hkContainerHeapAllocator> *)(unsigned int)this->m_edgeDataStriding;
  this->m_edgeDataStriding = newStride;
  hkaiUserDataUtils::restride<int>(
    result,
    (hkResult *)&this->m_edgeData,
    m_edgeDataStriding,
    newStride,
    m_size,
    fillValue,
    v9);
  return result;
}

// File Line: 224
// RVA: 0xBE4660
hkResult *__fastcall hkaiNavMesh::setFacesSize(hkaiNavMesh *this, hkResult *result, int newSize)
{
  int m_size; // eax
  int m_faceDataStriding; // eax

  m_size = this->m_faces.m_size;
  if ( newSize <= m_size )
  {
    m_faceDataStriding = this->m_faceDataStriding;
    this->m_faces.m_size = newSize;
    if ( m_faceDataStriding )
      this->m_faceData.m_size = newSize * m_faceDataStriding;
    goto LABEL_4;
  }
  if ( hkaiNavMesh::expandFacesBy(this, newSize - m_size, -1) )
  {
LABEL_4:
    result->m_enum = HK_SUCCESS;
    return result;
  }
  result->m_enum = HK_FAILURE;
  return result;
}

// File Line: 246
// RVA: 0xBE46C0
hkResult *__fastcall hkaiNavMesh::setEdgesSize(hkaiNavMesh *this, hkResult *result, int newSize)
{
  int m_size; // eax
  int m_edgeDataStriding; // eax

  m_size = this->m_edges.m_size;
  if ( newSize <= m_size )
  {
    m_edgeDataStriding = this->m_edgeDataStriding;
    this->m_edges.m_size = newSize;
    if ( m_edgeDataStriding )
      this->m_edgeData.m_size = newSize * m_edgeDataStriding;
    goto LABEL_4;
  }
  if ( hkaiNavMesh::expandEdgesBy(this, newSize - m_size, -1) )
  {
LABEL_4:
    result->m_enum = HK_SUCCESS;
    return result;
  }
  result->m_enum = HK_FAILURE;
  return result;
}

// File Line: 268
// RVA: 0xBE47E0
void __fastcall hkaiNavMesh::removeFaceAtAndCopy(hkaiNavMesh *this, int index)
{
  hkaiNavMesh::Face *v4; // rdx
  int v5; // ecx
  __int64 v6; // rcx
  int m_startEdgeIndex; // eax
  __int64 m_faceDataStriding; // r8
  int *m_data; // rcx
  __int64 v10; // rdx
  int v11; // r10d
  int *v12; // r8
  int *v13; // rax
  signed __int64 v14; // r8
  __int64 v15; // rdx
  int v16; // ecx

  --this->m_faces.m_size;
  v4 = &this->m_faces.m_data[index];
  v5 = 16 * (this->m_faces.m_size - index);
  if ( v5 > 0 )
  {
    v6 = ((unsigned int)(v5 - 1) >> 2) + 1;
    do
    {
      m_startEdgeIndex = v4[1].m_startEdgeIndex;
      v4 = (hkaiNavMesh::Face *)((char *)v4 + 4);
      *(_DWORD *)&v4[-1].m_clusterIndex = m_startEdgeIndex;
      --v6;
    }
    while ( v6 );
  }
  m_faceDataStriding = this->m_faceDataStriding;
  if ( (_DWORD)m_faceDataStriding )
  {
    this->m_faceData.m_size -= m_faceDataStriding;
    m_data = this->m_faceData.m_data;
    v10 = index * (int)m_faceDataStriding;
    v11 = 4 * (this->m_faceData.m_size - index * m_faceDataStriding);
    v12 = &m_data[v10 + m_faceDataStriding];
    v13 = &m_data[v10];
    if ( v11 > 0 )
    {
      v14 = (char *)v12 - (char *)v13;
      v15 = ((unsigned int)(v11 - 1) >> 2) + 1;
      do
      {
        v16 = *(int *)((char *)v13++ + v14);
        *(v13 - 1) = v16;
        --v15;
      }
      while ( v15 );
    }
  }
}

// File Line: 277
// RVA: 0xBE4720
void __fastcall hkaiNavMesh::removeEdgeAtAndCopy(hkaiNavMesh *this, int index)
{
  int v4; // r10d
  hkaiNavMesh::Edge *v5; // rcx
  int v6; // r10d
  __int64 v7; // rdx
  int m_a; // eax
  __int64 m_edgeDataStriding; // r8
  int *m_data; // rcx
  __int64 v11; // rdx
  int v12; // r10d
  int *v13; // r8
  int *v14; // rax
  signed __int64 v15; // r8
  __int64 v16; // rdx
  int v17; // ecx

  v4 = 5 * (--this->m_edges.m_size - index);
  v5 = &this->m_edges.m_data[index];
  v6 = 4 * v4;
  if ( v6 > 0 )
  {
    v7 = ((unsigned int)(v6 - 1) >> 2) + 1;
    do
    {
      m_a = v5[1].m_a;
      v5 = (hkaiNavMesh::Edge *)((char *)v5 + 4);
      *(_DWORD *)&v5[-1].m_flags.m_storage = m_a;
      --v7;
    }
    while ( v7 );
  }
  m_edgeDataStriding = this->m_edgeDataStriding;
  if ( (_DWORD)m_edgeDataStriding )
  {
    this->m_edgeData.m_size -= m_edgeDataStriding;
    m_data = this->m_edgeData.m_data;
    v11 = index * (int)m_edgeDataStriding;
    v12 = 4 * (this->m_edgeData.m_size - index * m_edgeDataStriding);
    v13 = &m_data[v11 + m_edgeDataStriding];
    v14 = &m_data[v11];
    if ( v12 > 0 )
    {
      v15 = (char *)v13 - (char *)v14;
      v16 = ((unsigned int)(v12 - 1) >> 2) + 1;
      do
      {
        v17 = *(int *)((char *)v14++ + v15);
        *(v14 - 1) = v17;
        --v16;
      }
      while ( v16 );
    }
  }
}

