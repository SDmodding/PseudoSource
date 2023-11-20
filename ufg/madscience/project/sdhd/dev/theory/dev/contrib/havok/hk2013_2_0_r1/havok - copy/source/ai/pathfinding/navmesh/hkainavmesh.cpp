// File Line: 29
// RVA: 0xBE37D0
void __fastcall hkaiNavMesh::hkaiNavMesh(hkaiNavMesh *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiNavMesh::`vftable';
}

// File Line: 34
// RVA: 0xBE3710
void __fastcall hkaiNavMesh::hkaiNavMesh(hkaiNavMesh *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiNavMesh::`vftable';
  this->m_faces.m_data = 0i64;
  this->m_faces.m_size = 0;
  this->m_faces.m_capacityAndFlags = 2147483648;
  this->m_edges.m_data = 0i64;
  this->m_edges.m_size = 0;
  this->m_edges.m_capacityAndFlags = 2147483648;
  this->m_vertices.m_data = 0i64;
  this->m_vertices.m_size = 0;
  this->m_vertices.m_capacityAndFlags = 2147483648;
  this->m_streamingSets.m_data = 0i64;
  this->m_streamingSets.m_size = 0;
  this->m_streamingSets.m_capacityAndFlags = 2147483648;
  this->m_faceData.m_data = 0i64;
  this->m_faceData.m_size = 0;
  this->m_faceData.m_capacityAndFlags = 2147483648;
  this->m_edgeData.m_data = 0i64;
  this->m_edgeData.m_size = 0;
  this->m_edgeData.m_capacityAndFlags = 2147483648;
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
  int v1; // er8
  hkaiNavMesh *v2; // rbx
  int v3; // er8
  int v4; // edi
  hkaiStreamingSet *v5; // rsi
  int v6; // er8
  int v7; // er8
  int v8; // eax
  int v9; // er8

  this->vfptr = (hkBaseObjectVtbl *)&hkaiNavMesh::`vftable';
  v1 = this->m_edgeData.m_capacityAndFlags;
  v2 = this;
  this->m_edgeData.m_size = 0;
  if ( v1 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_edgeData.m_data,
      4 * v1);
  v2->m_edgeData.m_data = 0i64;
  v2->m_edgeData.m_capacityAndFlags = 2147483648;
  v3 = v2->m_faceData.m_capacityAndFlags;
  v2->m_faceData.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_faceData.m_data,
      4 * v3);
  v2->m_faceData.m_data = 0i64;
  v2->m_faceData.m_capacityAndFlags = 2147483648;
  v4 = v2->m_streamingSets.m_size - 1;
  if ( v4 >= 0 )
  {
    v5 = &v2->m_streamingSets.m_data[v4];
    do
    {
      hkaiStreamingSet::~hkaiStreamingSet(v5);
      --v5;
      --v4;
    }
    while ( v4 >= 0 );
  }
  v6 = v2->m_streamingSets.m_capacityAndFlags;
  v2->m_streamingSets.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_streamingSets.m_data,
      56 * (v6 & 0x3FFFFFFF));
  v2->m_streamingSets.m_data = 0i64;
  v2->m_streamingSets.m_capacityAndFlags = 2147483648;
  v7 = v2->m_vertices.m_capacityAndFlags;
  v2->m_vertices.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_vertices.m_data,
      16 * v7);
  v2->m_vertices.m_data = 0i64;
  v2->m_vertices.m_capacityAndFlags = 2147483648;
  v8 = v2->m_edges.m_capacityAndFlags;
  v2->m_edges.m_size = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_edges.m_data,
      20 * (v8 & 0x3FFFFFFF));
  v2->m_edges.m_data = 0i64;
  v2->m_edges.m_capacityAndFlags = 2147483648;
  v9 = v2->m_faces.m_capacityAndFlags;
  v2->m_faces.m_size = 0;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_faces.m_data,
      16 * v9);
  v2->m_faces.m_data = 0i64;
  v2->m_faces.m_capacityAndFlags = 2147483648;
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 50
// RVA: 0xBE41F0
hkResult *__fastcall hkaiNavMesh::appendVertices(hkaiNavMesh *this, hkResult *result, hkVector4f *v, int numVerts)
{
  hkVector4f *v4; // rbp
  hkArrayBase<hkVector4f> *v5; // rsi
  int v6; // edi
  hkResult *v7; // rbx
  int v9; // [rsp+48h] [rbp+20h]

  v4 = v;
  v5 = (hkArrayBase<hkVector4f> *)&this->m_vertices.m_data;
  v6 = numVerts;
  v7 = result;
  hkaiArrayUtil::reserveSmall<hkVector4f,hkContainerHeapAllocator>(
    (hkaiArrayUtil *)&v9,
    (hkResult *)&this->m_vertices,
    (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(unsigned int)(numVerts + this->m_vertices.m_size),
    -1);
  if ( v9 )
  {
    v7->m_enum = 1;
  }
  else
  {
    hkArrayBase<hkVector4f>::_append(v5, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, v6);
    v7->m_enum = 0;
  }
  return v7;
}

// File Line: 60
// RVA: 0xBE4280
hkVector4f *__fastcall hkaiNavMesh::expandVerticesBy(hkaiNavMesh *this, int n)
{
  hkArray<hkVector4f,hkContainerHeapAllocator> *v2; // rbx
  int v3; // edi
  __int64 v5; // rcx
  int v6; // [rsp+38h] [rbp+10h]

  v2 = &this->m_vertices;
  v3 = n;
  hkaiArrayUtil::reserveSmall<hkVector4f,hkContainerHeapAllocator>(
    (hkaiArrayUtil *)&v6,
    (hkResult *)&this->m_vertices,
    (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(unsigned int)(n + this->m_vertices.m_size),
    -1);
  if ( v6 )
    return 0i64;
  v5 = v2->m_size;
  v2->m_size = v5 + v3;
  return &v2->m_data[v5];
}

// File Line: 69
// RVA: 0xBE42F0
hkaiNavMesh::Face *__fastcall hkaiNavMesh::expandFacesBy(hkaiNavMesh *this, int n, int estimatedMaxNumFaces)
{
  int v3; // er9
  int v4; // er15
  int v5; // er14
  hkaiNavMesh *v6; // rbp
  int v7; // ebx
  int v9; // eax
  int v10; // eax
  int v11; // er9
  int v12; // edx
  int *v13; // rdi
  __int64 v14; // rcx
  __int64 v15; // rcx
  hkResult result; // [rsp+30h] [rbp-38h]
  int v17; // [rsp+70h] [rbp+8h]
  int v18; // [rsp+88h] [rbp+20h]

  v3 = this->m_faceDataStriding;
  v4 = estimatedMaxNumFaces;
  v5 = n;
  v6 = this;
  if ( v3 )
  {
    v7 = this->m_faceData.m_size + n * v3;
    hkaiArrayUtil::reserveSmall<int,hkContainerHeapAllocator>(
      (hkaiArrayUtil *)&v17,
      (hkResult *)&this->m_faceData,
      (hkArray<unsigned int,hkContainerHeapAllocator> *)(unsigned int)v7,
      estimatedMaxNumFaces * v3);
    if ( v17 )
      return 0i64;
    v9 = v6->m_faceData.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v9 < v7 )
    {
      v10 = 2 * v9;
      v11 = v7;
      if ( v7 < v10 )
        v11 = v10;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v6->m_faceData,
        v11,
        4);
    }
    v12 = v7 - v6->m_faceData.m_size;
    v13 = &v6->m_faceData.m_data[v6->m_faceData.m_size];
    v14 = v12;
    if ( v12 > 0 )
    {
      while ( v14 )
      {
        *v13 = 0;
        ++v13;
        --v14;
      }
    }
    v6->m_faceData.m_size = v7;
  }
  hkaiArrayUtil::reserveSmall<hkVector4f,hkContainerHeapAllocator>(
    (hkaiArrayUtil *)&v18,
    (hkResult *)&v6->m_faces,
    (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(unsigned int)(v5 + v6->m_faces.m_size),
    v4);
  if ( v18 )
    return 0i64;
  v15 = v6->m_faces.m_size;
  v6->m_faces.m_size = v15 + v5;
  return &v6->m_faces.m_data[v15];
}

// File Line: 87
// RVA: 0xBE4550
hkaiNavMesh::Edge *__fastcall hkaiNavMesh::expandEdgesBy(hkaiNavMesh *this, int n, int estimatedMaxNumEdges)
{
  int v3; // er9
  int v4; // er15
  int v5; // er14
  hkaiNavMesh *v6; // rbp
  int v7; // ebx
  int v9; // eax
  int v10; // eax
  int v11; // er9
  int v12; // edx
  int *v13; // rdi
  __int64 v14; // rcx
  __int64 v15; // rcx
  int sizeElem; // [rsp+20h] [rbp-48h]
  hkResult result; // [rsp+30h] [rbp-38h]
  int v18; // [rsp+70h] [rbp+8h]
  int v19; // [rsp+88h] [rbp+20h]

  v3 = this->m_edgeDataStriding;
  v4 = estimatedMaxNumEdges;
  v5 = n;
  v6 = this;
  if ( v3 )
  {
    v7 = this->m_edgeData.m_size + n * v3;
    hkaiArrayUtil::reserveSmall<int,hkContainerHeapAllocator>(
      (hkaiArrayUtil *)&v18,
      (hkResult *)&this->m_edgeData,
      (hkArray<unsigned int,hkContainerHeapAllocator> *)(unsigned int)v7,
      estimatedMaxNumEdges * v3);
    if ( v18 )
      return 0i64;
    v9 = v6->m_edgeData.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v9 < v7 )
    {
      v10 = 2 * v9;
      v11 = v7;
      if ( v7 < v10 )
        v11 = v10;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v6->m_edgeData,
        v11,
        4);
    }
    v12 = v7 - v6->m_edgeData.m_size;
    v13 = &v6->m_edgeData.m_data[v6->m_edgeData.m_size];
    v14 = v12;
    if ( v12 > 0 )
    {
      while ( v14 )
      {
        *v13 = 0;
        ++v13;
        --v14;
      }
    }
    v6->m_edgeData.m_size = v7;
  }
  hkaiArrayUtil::reserveSmall<hkaiNavMesh::Edge,hkContainerHeapAllocator>(
    (hkaiArrayUtil *)&v19,
    (hkResult *)&v6->m_edges,
    (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(unsigned int)(v5 + v6->m_edges.m_size),
    v4,
    sizeElem);
  if ( v19 )
    return 0i64;
  v15 = v6->m_edges.m_size;
  v6->m_edges.m_size = v15 + v5;
  return &v6->m_edges.m_data[v15];
}

// File Line: 104
// RVA: 0xBE4400
hkResult *__fastcall hkaiNavMesh::appendEdges(hkaiNavMesh *this, hkResult *result, hkaiNavMesh::Edge *edges, int *edgeData, int n)
{
  int v5; // edi
  int *v6; // rbp
  hkaiNavMesh::Edge *v7; // r12
  hkResult *v8; // rbx
  hkaiNavMesh *v9; // r14
  int v10; // esi
  int v11; // er9
  int v12; // eax
  int v13; // eax
  int v14; // er9
  int v15; // edx
  int *v16; // rdi
  __int64 v17; // rcx
  int sizeElem; // [rsp+20h] [rbp-38h]
  int v20; // [rsp+60h] [rbp+8h]

  v5 = n;
  v6 = edgeData;
  v7 = edges;
  v8 = result;
  v9 = this;
  v10 = this->m_edgeData.m_size + n * this->m_edgeDataStriding;
  if ( this->m_edgeDataStriding
    && (hkaiArrayUtil::reserveSmall<int,hkContainerHeapAllocator>(
          (hkaiArrayUtil *)&n,
          (hkResult *)&this->m_edgeData,
          (hkArray<unsigned int,hkContainerHeapAllocator> *)(unsigned int)v10,
          -1),
        n) )
  {
    v8->m_enum = 1;
  }
  else
  {
    hkaiArrayUtil::reserveSmall<hkaiNavMesh::Edge,hkContainerHeapAllocator>(
      (hkaiArrayUtil *)&v20,
      (hkResult *)&v9->m_edges,
      (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(unsigned int)(v5 + v9->m_edges.m_size),
      -1,
      sizeElem);
    if ( v20 )
    {
      v8->m_enum = 1;
    }
    else
    {
      hkArrayBase<hkaiNavMesh::Edge>::_append(
        (hkArrayBase<hkaiNavMesh::Edge> *)&v9->m_edges.m_data,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        v7,
        v5);
      v11 = v9->m_edgeDataStriding;
      if ( v11 )
      {
        if ( v6 )
        {
          hkArrayBase<unsigned int>::_append(
            (hkArrayBase<unsigned int> *)&v9->m_edgeData,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            (const unsigned int *)v6,
            v5 * v11);
        }
        else
        {
          v12 = v9->m_edgeData.m_capacityAndFlags & 0x3FFFFFFF;
          if ( v12 < v10 )
          {
            v13 = 2 * v12;
            v14 = v10;
            if ( v10 < v13 )
              v14 = v13;
            hkArrayUtil::_reserve(
              (hkResult *)&n,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              &v9->m_edgeData,
              v14,
              4);
          }
          v15 = v10 - v9->m_edgeData.m_size;
          v16 = &v9->m_edgeData.m_data[v9->m_edgeData.m_size];
          v17 = v15;
          if ( v15 > 0 )
          {
            while ( v17 )
            {
              *v16 = 0;
              ++v16;
              --v17;
            }
          }
          v9->m_edgeData.m_size = v10;
        }
      }
      v8->m_enum = 0;
    }
  }
  return v8;
}

// File Line: 130
// RVA: 0xBE39B0
hkResult *__fastcall hkaiNavMesh::copy(hkaiNavMesh *this, hkResult *result, hkaiNavMesh *other)
{
  int v3; // er9
  hkaiNavMesh *v4; // rbx
  hkResult *v5; // r14
  hkaiNavMesh *v6; // rsi
  __int64 v7; // rax
  hkaiNavMesh::Face *v8; // rcx
  __int64 v9; // r8
  char *v10; // rdx
  int v11; // eax
  int v12; // er9
  int v13; // eax
  __int64 v14; // rax
  hkaiNavMesh::Edge *v15; // r9
  __int64 v16; // r8
  signed __int64 v17; // rcx
  char *v18; // rdx
  int v19; // eax
  int v20; // er9
  __int64 v21; // rax
  hkVector4f *v22; // rcx
  __int64 v23; // rdx
  char *v24; // r8
  hkVector4f v25; // xmm0
  int v26; // er9
  __int64 v27; // rax
  int *v28; // rcx
  __int64 v29; // rdx
  char *v30; // r8
  int v31; // eax
  int v32; // er9
  __int64 v33; // rax
  int *v34; // rcx
  __int64 v35; // rdx
  char *v36; // r8
  int v37; // eax
  int v38; // eax
  hkResult v40; // [rsp+30h] [rbp-10h]
  hkResult v41; // [rsp+34h] [rbp-Ch]
  int v42; // [rsp+38h] [rbp-8h]
  hkResult v43; // [rsp+3Ch] [rbp-4h]
  hkResult resulta; // [rsp+70h] [rbp+30h]
  hkResult v45; // [rsp+80h] [rbp+40h]
  hkResult v46; // [rsp+88h] [rbp+48h]

  v3 = other->m_faces.m_size;
  v4 = other;
  v5 = result;
  v6 = this;
  if ( (this->m_faces.m_capacityAndFlags & 0x3FFFFFFF) >= v3 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    hkArrayUtil::_reserve(
      &resulta,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_faces,
      v3,
      16);
    if ( resulta.m_enum )
      goto LABEL_12;
  }
  if ( (v6->m_faces.m_capacityAndFlags & 0x3FFFFFFF) < v4->m_faces.m_size )
  {
    if ( v6->m_faces.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v6->m_faces.m_data,
        16 * v6->m_faces.m_capacityAndFlags);
    v42 = 16 * v4->m_faces.m_size;
    v6->m_faces.m_data = (hkaiNavMesh::Face *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                &v42);
    v6->m_faces.m_capacityAndFlags = v42 / 16;
  }
  v7 = v4->m_faces.m_size;
  v8 = v6->m_faces.m_data;
  v6->m_faces.m_size = v7;
  v9 = v7;
  if ( (signed int)v7 > 0 )
  {
    v10 = (char *)((char *)v4->m_faces.m_data - (char *)v8);
    do
    {
      v11 = *(int *)((char *)&v8->m_startEdgeIndex + (_QWORD)v10);
      ++v8;
      v8[-1].m_startEdgeIndex = v11;
      v8[-1].m_startUserEdgeIndex = *(_DWORD *)((char *)v8 + (_QWORD)v10 - 12);
      *(_DWORD *)&v8[-1].m_numEdges = *(_DWORD *)((char *)v8 + (_QWORD)v10 - 8);
      *(_DWORD *)&v8[-1].m_clusterIndex = *(_DWORD *)((char *)v8 + (_QWORD)v10 - 4);
      --v9;
    }
    while ( v9 );
  }
LABEL_12:
  v12 = v4->m_edges.m_size;
  if ( (v6->m_edges.m_capacityAndFlags & 0x3FFFFFFF) >= v12 )
  {
    v45.m_enum = 0;
  }
  else
  {
    hkArrayUtil::_reserve(&v45, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v6->m_edges, v12, 20);
    if ( v45.m_enum )
      goto LABEL_23;
  }
  v13 = v6->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v13 < v4->m_edges.m_size )
  {
    if ( v6->m_edges.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v6->m_edges.m_data,
        20 * v13);
    v42 = 20 * v4->m_edges.m_size;
    v6->m_edges.m_data = (hkaiNavMesh::Edge *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                &v42);
    v6->m_edges.m_capacityAndFlags = v42 / 20;
  }
  v14 = v4->m_edges.m_size;
  v15 = v6->m_edges.m_data;
  v6->m_edges.m_size = v14;
  v16 = v14;
  if ( (signed int)v14 > 0 )
  {
    v17 = (signed __int64)&v15->m_b;
    v18 = (char *)((char *)v4->m_edges.m_data - (char *)v15);
    do
    {
      v19 = *(_DWORD *)&v18[v17 - 4];
      v17 += 20i64;
      *(_DWORD *)(v17 - 24) = v19;
      *(_DWORD *)(v17 - 20) = *(_DWORD *)&v18[v17 - 20];
      *(_DWORD *)(v17 - 16) = *(_DWORD *)&v18[v17 - 16];
      *(_DWORD *)(v17 - 12) = *(_DWORD *)&v18[v17 - 12];
      *(_BYTE *)(v17 - 8) = v18[v17 - 8];
      *(_BYTE *)(v17 - 7) = v18[v17 - 7];
      *(_WORD *)(v17 - 6) = *(_WORD *)&v18[v17 - 6];
      --v16;
    }
    while ( v16 );
  }
LABEL_23:
  v20 = v4->m_vertices.m_size;
  if ( (v6->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) >= v20 )
  {
    v46.m_enum = 0;
  }
  else
  {
    hkArrayUtil::_reserve(&v46, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v6->m_vertices, v20, 16);
    if ( v46.m_enum )
      goto LABEL_34;
  }
  if ( (v6->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) < v4->m_vertices.m_size )
  {
    if ( v6->m_vertices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v6->m_vertices.m_data,
        16 * v6->m_vertices.m_capacityAndFlags);
    v42 = 16 * v4->m_vertices.m_size;
    v6->m_vertices.m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                            &v42);
    v6->m_vertices.m_capacityAndFlags = v42 / 16;
  }
  v21 = v4->m_vertices.m_size;
  v22 = v6->m_vertices.m_data;
  v6->m_vertices.m_size = v21;
  v23 = v21;
  if ( (signed int)v21 > 0 )
  {
    v24 = (char *)((char *)v4->m_vertices.m_data - (char *)v22);
    do
    {
      v25.m_quad = *(__m128 *)((char *)v22 + (_QWORD)v24);
      ++v22;
      v22[-1] = (hkVector4f)v25.m_quad;
      --v23;
    }
    while ( v23 );
  }
LABEL_34:
  v26 = v4->m_faceData.m_size;
  if ( (v6->m_faceData.m_capacityAndFlags & 0x3FFFFFFF) >= v26 )
  {
    v40.m_enum = 0;
  }
  else
  {
    hkArrayUtil::_reserve(&v40, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v6->m_faceData, v26, 4);
    if ( v40.m_enum )
      goto LABEL_45;
  }
  if ( (v6->m_faceData.m_capacityAndFlags & 0x3FFFFFFF) < v4->m_faceData.m_size )
  {
    if ( v6->m_faceData.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v6->m_faceData.m_data,
        4 * v6->m_faceData.m_capacityAndFlags);
    v42 = 4 * v4->m_faceData.m_size;
    v6->m_faceData.m_data = (int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                     (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                     &v42);
    v6->m_faceData.m_capacityAndFlags = v42 / 4;
  }
  v27 = v4->m_faceData.m_size;
  v28 = v6->m_faceData.m_data;
  v6->m_faceData.m_size = v27;
  v29 = v27;
  if ( (signed int)v27 > 0 )
  {
    v30 = (char *)((char *)v4->m_faceData.m_data - (char *)v28);
    do
    {
      v31 = *(int *)((char *)v28 + (_QWORD)v30);
      ++v28;
      *(v28 - 1) = v31;
      --v29;
    }
    while ( v29 );
  }
LABEL_45:
  v32 = v4->m_edgeData.m_size;
  if ( (v6->m_edgeData.m_capacityAndFlags & 0x3FFFFFFF) >= v32 )
  {
    v41.m_enum = 0;
  }
  else
  {
    hkArrayUtil::_reserve(&v41, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v6->m_edgeData, v32, 4);
    if ( v41.m_enum )
      goto LABEL_56;
  }
  if ( (v6->m_edgeData.m_capacityAndFlags & 0x3FFFFFFF) < v4->m_edgeData.m_size )
  {
    if ( v6->m_edgeData.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v6->m_edgeData.m_data,
        4 * v6->m_edgeData.m_capacityAndFlags);
    v42 = 4 * v4->m_edgeData.m_size;
    v6->m_edgeData.m_data = (int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                     (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                     &v42);
    v6->m_edgeData.m_capacityAndFlags = v42 / 4;
  }
  v33 = v4->m_edgeData.m_size;
  v34 = v6->m_edgeData.m_data;
  v6->m_edgeData.m_size = v33;
  v35 = v33;
  if ( (signed int)v33 > 0 )
  {
    v36 = (char *)((char *)v4->m_edgeData.m_data - (char *)v34);
    do
    {
      v37 = *(int *)((char *)v34 + (_QWORD)v36);
      ++v34;
      *(v34 - 1) = v37;
      --v35;
    }
    while ( v35 );
  }
LABEL_56:
  hkaiStreamingSet::_copy(&v43, &v6->m_streamingSets, (hkArrayBase<hkaiStreamingSet> *)&v4->m_streamingSets.m_data);
  if ( resulta.m_enum || v45.m_enum || v46.m_enum || v43.m_enum || v40.m_enum || v41.m_enum )
  {
    v5->m_enum = 1;
  }
  else
  {
    v38 = v4->m_faceDataStriding;
    v5->m_enum = 0;
    v6->m_faceDataStriding = v38;
    v6->m_edgeDataStriding = v4->m_edgeDataStriding;
    v6->m_flags.m_storage = v4->m_flags.m_storage;
    v6->m_aabb.m_min = v4->m_aabb.m_min;
    v6->m_aabb.m_max = v4->m_aabb.m_max;
    v6->m_erosionRadius = v4->m_erosionRadius;
    v6->m_userData = v4->m_userData;
  }
  return v5;
}

// File Line: 157
// RVA: 0xBE3EE0
void __fastcall hkaiNavMesh::swap(hkaiNavMesh *this, hkaiNavMesh *other)
{
  hkaiNavMesh *v2; // rdi
  hkaiNavMesh *v3; // rbx
  int v4; // ecx
  int v5; // ecx
  char v6; // al
  hkVector4f v7; // xmm3
  hkVector4f v8; // xmm2
  float v9; // xmm0_4
  unsigned __int64 v10; // rcx

  v2 = other;
  v3 = this;
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&this->m_faces,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&other->m_faces);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v3->m_edges,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v2->m_edges);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v3->m_vertices,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v2->m_vertices);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v3->m_streamingSets,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v2->m_streamingSets);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v3->m_faceData,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v2->m_faceData);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v3->m_edgeData,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v2->m_edgeData);
  v4 = v3->m_faceDataStriding;
  v3->m_faceDataStriding = v2->m_faceDataStriding;
  v2->m_faceDataStriding = v4;
  v5 = v3->m_edgeDataStriding;
  v3->m_edgeDataStriding = v2->m_edgeDataStriding;
  v2->m_edgeDataStriding = v5;
  v6 = v3->m_flags.m_storage;
  v3->m_flags.m_storage = v2->m_flags.m_storage;
  v2->m_flags.m_storage = v6;
  v7.m_quad = (__m128)v3->m_aabb.m_min;
  v8.m_quad = (__m128)v3->m_aabb.m_max;
  v3->m_aabb.m_min = v2->m_aabb.m_min;
  v3->m_aabb.m_max = v2->m_aabb.m_max;
  v2->m_aabb.m_min = (hkVector4f)v7.m_quad;
  v2->m_aabb.m_max = (hkVector4f)v8.m_quad;
  v9 = v3->m_erosionRadius;
  v3->m_erosionRadius = v2->m_erosionRadius;
  v2->m_erosionRadius = v9;
  v10 = v3->m_userData;
  v3->m_userData = v2->m_userData;
  v2->m_userData = v10;
}

// File Line: 176
// RVA: 0xBE3FF0
void __fastcall hkaiNavMesh::clear(hkaiNavMesh *this)
{
  int v1; // er8
  hkaiNavMesh *v2; // rbx
  int v3; // eax
  int v4; // er8
  int v5; // edi
  hkaiStreamingSet *v6; // rsi
  int v7; // er8
  int v8; // er8
  int v9; // er8

  v1 = this->m_faces.m_capacityAndFlags;
  v2 = this;
  this->m_faces.m_size = 0;
  if ( v1 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_faces.m_data,
      16 * v1);
  v2->m_faces.m_data = 0i64;
  v2->m_faces.m_capacityAndFlags = 2147483648;
  v3 = v2->m_edges.m_capacityAndFlags;
  v2->m_edges.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_edges.m_data,
      20 * (v3 & 0x3FFFFFFF));
  v2->m_edges.m_data = 0i64;
  v2->m_edges.m_capacityAndFlags = 2147483648;
  v4 = v2->m_vertices.m_capacityAndFlags;
  v2->m_vertices.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_vertices.m_data,
      16 * v4);
  v2->m_vertices.m_data = 0i64;
  v2->m_vertices.m_capacityAndFlags = 2147483648;
  v5 = v2->m_streamingSets.m_size - 1;
  if ( v5 >= 0 )
  {
    v6 = &v2->m_streamingSets.m_data[v5];
    do
    {
      hkaiStreamingSet::~hkaiStreamingSet(v6);
      --v6;
      --v5;
    }
    while ( v5 >= 0 );
  }
  v7 = v2->m_streamingSets.m_capacityAndFlags;
  v2->m_streamingSets.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_streamingSets.m_data,
      56 * (v7 & 0x3FFFFFFF));
  v2->m_streamingSets.m_data = 0i64;
  v2->m_streamingSets.m_capacityAndFlags = 2147483648;
  v8 = v2->m_faceData.m_capacityAndFlags;
  v2->m_faceData.m_size = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_faceData.m_data,
      4 * v8);
  v2->m_faceData.m_data = 0i64;
  v2->m_faceData.m_capacityAndFlags = 2147483648;
  v9 = v2->m_edgeData.m_capacityAndFlags;
  v2->m_edgeData.m_size = 0;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_edgeData.m_data,
      4 * v9);
  v2->m_edgeData.m_data = 0i64;
  v2->m_edgeData.m_capacityAndFlags = 2147483648;
  v2->m_faceDataStriding = 1;
  v2->m_edgeDataStriding = 1;
  v2->m_aabb.m_min = (hkVector4f)xmmword_141A712A0;
  v2->m_aabb.m_max.m_quad = _mm_xor_ps(
                              (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                              v2->m_aabb.m_min.m_quad);
  v2->m_erosionRadius = 0.0;
  v2->m_userData = 0i64;
  v2->m_flags.m_storage = 0;
}

// File Line: 192
// RVA: 0xBE41E0
void __fastcall hkaiNavMesh::checkDeterminism(hkaiNavMesh *this)
{
  hkaiStreamingSet::checkDeterminism((hkArrayBase<hkaiStreamingSet> *)&this->m_streamingSets.m_data);
}

// File Line: 210
// RVA: 0xBE4890
hkResult *__fastcall hkaiNavMesh::setFaceDataStriding(hkaiNavMesh *this, hkResult *result, int newStride, int fillValue)
{
  int v4; // eax
  int v5; // er10
  hkArray<int,hkContainerHeapAllocator> *v6; // r8
  hkResult *v7; // rbx
  int v9; // [rsp+30h] [rbp-8h]

  v4 = this->m_faces.m_size;
  v5 = newStride;
  v6 = (hkArray<int,hkContainerHeapAllocator> *)(unsigned int)this->m_faceDataStriding;
  v7 = result;
  this->m_faceDataStriding = v5;
  hkaiUserDataUtils::restride<int>(
    (hkaiUserDataUtils *)result,
    (hkResult *)&this->m_faceData,
    v6,
    v5,
    v4,
    fillValue,
    v9);
  return v7;
}

// File Line: 217
// RVA: 0xBE48D0
hkResult *__fastcall hkaiNavMesh::setEdgeDataStriding(hkaiNavMesh *this, hkResult *result, int newStride, int fillValue)
{
  int v4; // eax
  int v5; // er10
  hkArray<int,hkContainerHeapAllocator> *v6; // r8
  hkResult *v7; // rbx
  int v9; // [rsp+30h] [rbp-8h]

  v4 = this->m_edges.m_size;
  v5 = newStride;
  v6 = (hkArray<int,hkContainerHeapAllocator> *)(unsigned int)this->m_edgeDataStriding;
  v7 = result;
  this->m_edgeDataStriding = v5;
  hkaiUserDataUtils::restride<int>(
    (hkaiUserDataUtils *)result,
    (hkResult *)&this->m_edgeData,
    v6,
    v5,
    v4,
    fillValue,
    v9);
  return v7;
}

// File Line: 224
// RVA: 0xBE4660
hkResult *__fastcall hkaiNavMesh::setFacesSize(hkaiNavMesh *this, hkResult *result, int newSize)
{
  int v3; // eax
  hkResult *v4; // rbx
  int v5; // eax

  v3 = this->m_faces.m_size;
  v4 = result;
  if ( newSize <= v3 )
  {
    v5 = this->m_faceDataStriding;
    this->m_faces.m_size = newSize;
    if ( v5 )
      this->m_faceData.m_size = newSize * v5;
    goto LABEL_4;
  }
  if ( hkaiNavMesh::expandFacesBy(this, newSize - v3, -1) )
  {
LABEL_4:
    v4->m_enum = 0;
    return v4;
  }
  v4->m_enum = 1;
  return v4;
}

// File Line: 246
// RVA: 0xBE46C0
hkResult *__fastcall hkaiNavMesh::setEdgesSize(hkaiNavMesh *this, hkResult *result, int newSize)
{
  int v3; // eax
  hkResult *v4; // rbx
  int v5; // eax

  v3 = this->m_edges.m_size;
  v4 = result;
  if ( newSize <= v3 )
  {
    v5 = this->m_edgeDataStriding;
    this->m_edges.m_size = newSize;
    if ( v5 )
      this->m_edgeData.m_size = newSize * v5;
    goto LABEL_4;
  }
  if ( hkaiNavMesh::expandEdgesBy(this, newSize - v3, -1) )
  {
LABEL_4:
    v4->m_enum = 0;
    return v4;
  }
  v4->m_enum = 1;
  return v4;
}

// File Line: 268
// RVA: 0xBE47E0
void __fastcall hkaiNavMesh::removeFaceAtAndCopy(hkaiNavMesh *this, int index)
{
  int v2; // er10
  hkaiNavMesh *v3; // r9
  hkaiNavMesh::Face *v4; // rdx
  int v5; // ecx
  __int64 v6; // rcx
  int v7; // eax
  __int64 v8; // r8
  int *v9; // rcx
  int v10; // eax
  int v11; // er10
  int *v12; // r8
  signed __int64 v13; // rax
  signed __int64 v14; // r8
  __int64 v15; // rdx
  int v16; // ecx

  --this->m_faces.m_size;
  v2 = index;
  v3 = this;
  v4 = &this->m_faces.m_data[index];
  v5 = 16 * (this->m_faces.m_size - v2);
  if ( v5 > 0 )
  {
    v6 = ((unsigned int)(v5 - 1) >> 2) + 1;
    do
    {
      v7 = v4[1].m_startEdgeIndex;
      v4 = (hkaiNavMesh::Face *)((char *)v4 + 4);
      *(_DWORD *)&v4[-1].m_clusterIndex = v7;
      --v6;
    }
    while ( v6 );
  }
  v8 = v3->m_faceDataStriding;
  if ( (_DWORD)v8 )
  {
    v3->m_faceData.m_size -= v8;
    v9 = v3->m_faceData.m_data;
    v10 = v2 * v8;
    v11 = 4 * (v3->m_faceData.m_size - v2 * v8);
    v12 = &v9[v10 + v8];
    v13 = (signed __int64)&v9[v10];
    if ( v11 > 0 )
    {
      v14 = (signed __int64)v12 - v13;
      v15 = ((unsigned int)(v11 - 1) >> 2) + 1;
      do
      {
        v16 = *(_DWORD *)(v14 + v13);
        v13 += 4i64;
        *(_DWORD *)(v13 - 4) = v16;
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
  int v2; // er11
  hkaiNavMesh *v3; // r9
  int v4; // er10
  hkaiNavMesh::Edge *v5; // rcx
  int v6; // er10
  __int64 v7; // rdx
  int v8; // eax
  __int64 v9; // r8
  int *v10; // rcx
  __int64 v11; // rdx
  int v12; // er10
  signed __int64 v13; // r8
  signed __int64 v14; // rax
  signed __int64 v15; // r8
  __int64 v16; // rdx
  int v17; // ecx

  --this->m_edges.m_size;
  v2 = index;
  v3 = this;
  v4 = 5 * (this->m_edges.m_size - index);
  v5 = &this->m_edges.m_data[index];
  v6 = 4 * v4;
  if ( v6 > 0 )
  {
    v7 = ((unsigned int)(v6 - 1) >> 2) + 1;
    do
    {
      v8 = v5[1].m_a;
      v5 = (hkaiNavMesh::Edge *)((char *)v5 + 4);
      *(_DWORD *)&v5[-1].m_flags.m_storage = v8;
      --v7;
    }
    while ( v7 );
  }
  v9 = v3->m_edgeDataStriding;
  if ( (_DWORD)v9 )
  {
    v3->m_edgeData.m_size -= v9;
    v10 = v3->m_edgeData.m_data;
    v11 = v2 * (signed int)v9;
    v12 = 4 * (v3->m_edgeData.m_size - v2 * v9);
    v13 = (signed __int64)&v10[v11 + v9];
    v14 = (signed __int64)&v10[v11];
    if ( v12 > 0 )
    {
      v15 = v13 - v14;
      v16 = ((unsigned int)(v12 - 1) >> 2) + 1;
      do
      {
        v17 = *(_DWORD *)(v15 + v14);
        v14 += 4i64;
        *(_DWORD *)(v14 - 4) = v17;
        --v16;
      }
      while ( v16 );
    }
  }
}

