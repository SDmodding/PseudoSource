// File Line: 23
// RVA: 0xCA1EE0
void __fastcall hkGeometryUtils::Node::Triangle::Triangle(hkGeometryUtils::Node::Triangle *this, unsigned int a, unsigned int b, unsigned int c)
{
  unsigned int v4; // eax
  unsigned int v5; // edx
  unsigned int v6; // eax

  this->m_indices[0] = a;
  this->m_sortedIndices[0] = a;
  this->m_indices[1] = b;
  this->m_sortedIndices[1] = b;
  this->m_indices[2] = c;
  this->m_sortedIndices[2] = c;
  if ( b < a )
  {
    this->m_sortedIndices[1] = a;
    this->m_sortedIndices[0] = b;
  }
  v4 = this->m_sortedIndices[1];
  if ( c < v4 )
  {
    this->m_sortedIndices[2] = v4;
    this->m_sortedIndices[1] = c;
  }
  v5 = this->m_sortedIndices[1];
  v6 = this->m_sortedIndices[0];
  if ( v5 < v6 )
  {
    this->m_sortedIndices[1] = v6;
    this->m_sortedIndices[0] = v5;
  }
}

// File Line: 30
// RVA: 0xCA1B50
void __fastcall hkGeometryUtils::Node::Node(hkGeometryUtils::Node *this, unsigned int vertexIndex)
{
  this->m_vertexIndex = vertexIndex;
  this->m_edges.m_capacityAndFlags = 2147483648;
  this->m_edges.m_data = 0i64;
  this->m_edges.m_size = 0;
}

// File Line: 33
// RVA: 0xCA1B70
void __fastcall hkGeometryUtils::Node::Node(hkGeometryUtils::Node *this, hkGeometryUtils::Node *other)
{
  hkGeometryUtils::Node *v2; // r13
  __int64 v3; // rbp
  int v4; // ebx
  int v5; // er15
  int v6; // eax
  hkGeometryUtils::Node *v7; // r12
  int v8; // eax
  int v9; // er9
  int v10; // ebx
  __int64 v11; // rdi
  int *v12; // rbx
  int v13; // er8
  int v14; // eax
  hkGeometryUtils::Node::Edge *v15; // rbx
  signed __int64 v16; // rsi
  __int64 v17; // rdi
  hkGeometryUtils::Node::Edge *v18; // rbx
  signed __int64 v19; // rsi
  __int64 v20; // rdi
  hkResult result; // [rsp+60h] [rbp+8h]

  this->m_edges.m_capacityAndFlags = 2147483648;
  v2 = other;
  this->m_edges.m_data = 0i64;
  this->m_edges.m_size = 0;
  this->m_vertexIndex = other->m_vertexIndex;
  v3 = other->m_edges.m_size;
  v4 = this->m_edges.m_size;
  v5 = other->m_edges.m_size;
  if ( (signed int)v3 > v4 )
    v5 = this->m_edges.m_size;
  v6 = this->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
  v7 = this;
  if ( v6 < (signed int)v3 )
  {
    v8 = 2 * v6;
    v9 = v3;
    if ( (signed int)v3 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_edges,
      v9,
      56);
  }
  v10 = v4 - v3 - 1;
  v11 = v10;
  if ( v10 >= 0 )
  {
    v12 = &v7->m_edges.m_data[v3].m_triangleIndices.m_capacityAndFlags + 14 * v10;
    do
    {
      v13 = *v12;
      *(v12 - 1) = 0;
      if ( v13 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v12 - 3),
          4 * v13);
      *(_QWORD *)(v12 - 3) = 0i64;
      *v12 = 2147483648;
      v14 = *(v12 - 4);
      *(v12 - 5) = 0;
      if ( v14 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v12 - 7),
          24 * (v14 & 0x3FFFFFFF));
      *(_QWORD *)(v12 - 7) = 0i64;
      *(v12 - 4) = 2147483648;
      v12 -= 14;
      --v11;
    }
    while ( v11 >= 0 );
  }
  v15 = v7->m_edges.m_data;
  if ( v5 > 0 )
  {
    v16 = (char *)v2->m_edges.m_data - (char *)v15;
    v17 = (unsigned int)v5;
    do
    {
      hkGeometryUtils::Node::Edge::operator=(v15, (hkGeometryUtils::Node::Edge *)((char *)v15 + v16));
      ++v15;
      --v17;
    }
    while ( v17 );
  }
  v18 = &v7->m_edges.m_data[v5];
  if ( (signed int)v3 - v5 > 0 )
  {
    v19 = (char *)v2->m_edges.m_data - (char *)v7->m_edges.m_data;
    v20 = (unsigned int)(v3 - v5);
    do
    {
      if ( v18 )
        hkGeometryUtils::Node::Edge::Edge(v18, (hkGeometryUtils::Node::Edge *)((char *)v18 + v19));
      ++v18;
      --v20;
    }
    while ( v20 );
  }
  v7->m_edges.m_size = v3;
}

// File Line: 39
// RVA: 0xCA1D30
hkGeometryUtils::Node *__fastcall hkGeometryUtils::Node::operator=(hkGeometryUtils::Node *this, hkGeometryUtils::Node *other)
{
  hkGeometryUtils::Node *v2; // r13
  hkGeometryUtils::Node *v3; // r12
  __int64 v4; // rbp
  int v5; // ebx
  int v6; // er15
  int v7; // eax
  int v8; // eax
  int v9; // er9
  int v10; // ebx
  __int64 v11; // rdi
  int *v12; // rbx
  int v13; // er8
  int v14; // eax
  hkGeometryUtils::Node::Edge *v15; // rbx
  signed __int64 v16; // rsi
  __int64 v17; // rdi
  hkGeometryUtils::Node::Edge *v18; // rbx
  signed __int64 v19; // rsi
  __int64 v20; // rdi
  hkResult result; // [rsp+60h] [rbp+8h]

  v2 = other;
  v3 = this;
  this->m_vertexIndex = other->m_vertexIndex;
  v4 = other->m_edges.m_size;
  v5 = this->m_edges.m_size;
  v6 = other->m_edges.m_size;
  if ( (signed int)v4 > v5 )
    v6 = this->m_edges.m_size;
  v7 = this->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < (signed int)v4 )
  {
    v8 = 2 * v7;
    v9 = v4;
    if ( (signed int)v4 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_edges,
      v9,
      56);
  }
  v10 = v5 - v4 - 1;
  v11 = v10;
  if ( v10 >= 0 )
  {
    v12 = &v3->m_edges.m_data[v4].m_triangleIndices.m_capacityAndFlags + 14 * v10;
    do
    {
      v13 = *v12;
      *(v12 - 1) = 0;
      if ( v13 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v12 - 3),
          4 * v13);
      *(_QWORD *)(v12 - 3) = 0i64;
      *v12 = 2147483648;
      v14 = *(v12 - 4);
      *(v12 - 5) = 0;
      if ( v14 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v12 - 7),
          24 * (v14 & 0x3FFFFFFF));
      *(_QWORD *)(v12 - 7) = 0i64;
      *(v12 - 4) = 2147483648;
      v12 -= 14;
      --v11;
    }
    while ( v11 >= 0 );
  }
  v15 = v3->m_edges.m_data;
  if ( v6 > 0 )
  {
    v16 = (char *)v2->m_edges.m_data - (char *)v15;
    v17 = (unsigned int)v6;
    do
    {
      hkGeometryUtils::Node::Edge::operator=(v15, (hkGeometryUtils::Node::Edge *)((char *)v15 + v16));
      ++v15;
      --v17;
    }
    while ( v17 );
  }
  v18 = &v3->m_edges.m_data[v6];
  if ( (signed int)v4 - v6 > 0 )
  {
    v19 = (char *)v2->m_edges.m_data - (char *)v3->m_edges.m_data;
    v20 = (unsigned int)(v4 - v6);
    do
    {
      if ( v18 )
        hkGeometryUtils::Node::Edge::Edge(v18, (hkGeometryUtils::Node::Edge *)((char *)v18 + v19));
      ++v18;
      --v20;
    }
    while ( v20 );
  }
  v3->m_edges.m_size = v4;
  return v3;
}

// File Line: 54
// RVA: 0xCA1F30
void __fastcall hkGeometryUtils::Node::Edge::Edge(hkGeometryUtils::Node::Edge *this, unsigned int endpointIndex, hkGeometryUtils::Node::Triangle *triangle, unsigned int triangleIndex)
{
  unsigned int v4; // ebp
  hkGeometryUtils::Node::Triangle *v5; // r14
  hkGeometryUtils::Node::Edge *v6; // rsi
  hkGeometryUtils::Node::Triangle *v7; // rdx

  this->m_endpointIndex = endpointIndex;
  this->m_triangles.m_capacityAndFlags = 2147483648;
  this->m_triangles.m_data = 0i64;
  this->m_triangles.m_size = 0;
  this->m_triangleIndices.m_data = 0i64;
  this->m_triangleIndices.m_size = 0;
  this->m_triangleIndices.m_capacityAndFlags = 2147483648;
  *(_QWORD *)&this->m_numIncoming = 0i64;
  *(_WORD *)&this->m_nonManifold = 0;
  this->m_processed = 0;
  v4 = triangleIndex;
  v5 = triangle;
  v6 = this;
  if ( this->m_triangles.m_size == (this->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &this->m_triangles, 24);
  v7 = &v6->m_triangles.m_data[v6->m_triangles.m_size];
  if ( v7 )
  {
    v7->m_indices[0] = v5->m_indices[0];
    v7->m_indices[1] = v5->m_indices[1];
    v7->m_indices[2] = v5->m_indices[2];
    v7->m_sortedIndices[0] = v5->m_sortedIndices[0];
    v7->m_sortedIndices[1] = v5->m_sortedIndices[1];
    v7->m_sortedIndices[2] = v5->m_sortedIndices[2];
  }
  ++v6->m_triangles.m_size;
  if ( v6->m_triangleIndices.m_size == (v6->m_triangleIndices.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v6->m_triangleIndices, 4);
  v6->m_triangleIndices.m_data[v6->m_triangleIndices.m_size++] = v4;
}

// File Line: 60
// RVA: 0xCA2220
void __fastcall hkGeometryUtils::Node::Edge::Edge(hkGeometryUtils::Node::Edge *this, hkGeometryUtils::Node::Edge *other)
{
  hkGeometryUtils::Node::Edge *v2; // rdi
  int v3; // er14
  int v4; // ebp
  hkGeometryUtils::Node::Edge *v5; // rbx
  int v6; // eax
  int v7; // eax
  int v8; // er9
  hkGeometryUtils::Node::Triangle *v9; // rcx
  __int64 v10; // r9
  char *v11; // rdx
  __int64 v12; // r8
  unsigned int v13; // eax
  hkGeometryUtils::Node::Triangle *v14; // rax
  __int64 v15; // rdx
  signed __int64 v16; // r8
  __int64 v17; // r8
  __int64 v18; // rax
  unsigned int *v19; // rcx
  __int64 v20; // rdx
  char *v21; // r8
  unsigned int v22; // eax
  hkResult result; // [rsp+50h] [rbp+8h]

  this->m_triangles.m_capacityAndFlags = 2147483648;
  v2 = other;
  this->m_triangles.m_data = 0i64;
  this->m_triangles.m_size = 0;
  this->m_triangleIndices.m_data = 0i64;
  this->m_triangleIndices.m_size = 0;
  this->m_triangleIndices.m_capacityAndFlags = 2147483648;
  this->m_endpointIndex = other->m_endpointIndex;
  v3 = other->m_triangles.m_size;
  v4 = other->m_triangles.m_size;
  v5 = this;
  if ( v3 > this->m_triangles.m_size )
    v4 = this->m_triangles.m_size;
  v6 = this->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v6 < v3 )
  {
    v7 = 2 * v6;
    v8 = other->m_triangles.m_size;
    if ( v3 < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_triangles,
      v8,
      24);
  }
  v9 = v5->m_triangles.m_data;
  v10 = v4;
  if ( v4 > 0 )
  {
    v11 = (char *)((char *)v2->m_triangles.m_data - (char *)v9);
    v12 = v4;
    do
    {
      v13 = *(unsigned int *)((char *)v9->m_indices + (_QWORD)v11);
      ++v9;
      v9[-1].m_indices[0] = v13;
      v9[-1].m_indices[1] = *(unsigned int *)((char *)&v9->m_indices[-5] + (_QWORD)v11);
      v9[-1].m_indices[2] = *(unsigned int *)((char *)&v9->m_indices[-4] + (_QWORD)v11);
      v9[-1].m_sortedIndices[0] = *(unsigned int *)((char *)&v9->m_indices[-3] + (_QWORD)v11);
      v9[-1].m_sortedIndices[1] = *(unsigned int *)((char *)&v9->m_indices[-2] + (_QWORD)v11);
      v9[-1].m_sortedIndices[2] = *(unsigned int *)((char *)&v9->m_indices[-1] + (_QWORD)v11);
      --v12;
    }
    while ( v12 );
  }
  v14 = &v5->m_triangles.m_data[v4];
  v15 = v3 - v4;
  if ( v3 - v4 > 0 )
  {
    v16 = (char *)&v2->m_triangles.m_data[v4] - (char *)v14;
    do
    {
      if ( v14 )
      {
        v14->m_indices[0] = *(unsigned int *)((char *)v14->m_indices + v16);
        v14->m_indices[1] = *(unsigned int *)((char *)&v14->m_indices[1] + v16);
        v14->m_indices[2] = *(unsigned int *)((char *)&v14->m_indices[2] + v16);
        v14->m_sortedIndices[0] = *(unsigned int *)((char *)v14->m_sortedIndices + v16);
        v14->m_sortedIndices[1] = *(unsigned int *)((char *)&v14->m_sortedIndices[1] + v16);
        v14->m_sortedIndices[2] = *(unsigned int *)((char *)&v14->m_sortedIndices[2] + v16);
      }
      ++v14;
      --v15;
    }
    while ( v15 );
  }
  v5->m_triangles.m_size = v3;
  v17 = v5->m_triangleIndices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( (signed int)v17 < v2->m_triangleIndices.m_size )
  {
    if ( v5->m_triangleIndices.m_capacityAndFlags >= 0 )
      ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, unsigned int *, _QWORD, _QWORD))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerHeapAllocator::s_alloc,
        v5->m_triangleIndices.m_data,
        (unsigned int)(4 * v17),
        v4);
    result.m_enum = 4 * v2->m_triangleIndices.m_size;
    v5->m_triangleIndices.m_data = (unsigned int *)((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkResult *, __int64, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
                                                     &hkContainerHeapAllocator::s_alloc,
                                                     &result,
                                                     v17,
                                                     v10);
    v5->m_triangleIndices.m_capacityAndFlags = result.m_enum / 4;
  }
  v18 = v2->m_triangleIndices.m_size;
  v19 = v5->m_triangleIndices.m_data;
  v5->m_triangleIndices.m_size = v18;
  v20 = v18;
  if ( (signed int)v18 > 0 )
  {
    v21 = (char *)((char *)v2->m_triangleIndices.m_data - (char *)v19);
    do
    {
      v22 = *(unsigned int *)((char *)v19 + (_QWORD)v21);
      ++v19;
      *(v19 - 1) = v22;
      --v20;
    }
    while ( v20 );
  }
  v5->m_numIncoming = v2->m_numIncoming;
  v5->m_numOutgoing = v2->m_numOutgoing;
  v5->m_nonManifold = v2->m_nonManifold;
  v5->m_inconsistentWinding = v2->m_inconsistentWinding;
  v5->m_processed = v2->m_processed;
}

// File Line: 72
// RVA: 0xCA2040
hkGeometryUtils::Node::Edge *__fastcall hkGeometryUtils::Node::Edge::operator=(hkGeometryUtils::Node::Edge *this, hkGeometryUtils::Node::Edge *other)
{
  hkGeometryUtils::Node::Edge *v2; // rdi
  hkGeometryUtils::Node::Edge *v3; // rbx
  int v4; // esi
  int v5; // ebp
  int v6; // eax
  int v7; // eax
  int v8; // er9
  hkGeometryUtils::Node::Triangle *v9; // rcx
  __int64 v10; // r9
  char *v11; // rdx
  __int64 v12; // r8
  unsigned int v13; // eax
  hkGeometryUtils::Node::Triangle *v14; // rax
  __int64 v15; // rdx
  signed __int64 v16; // r8
  __int64 v17; // r8
  __int64 v18; // rax
  unsigned int *v19; // rcx
  __int64 v20; // rdx
  char *v21; // r8
  unsigned int v22; // eax
  hkResult result; // [rsp+50h] [rbp+8h]

  v2 = other;
  v3 = this;
  this->m_endpointIndex = other->m_endpointIndex;
  v4 = other->m_triangles.m_size;
  v5 = other->m_triangles.m_size;
  if ( v4 > this->m_triangles.m_size )
    v5 = this->m_triangles.m_size;
  v6 = this->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v6 < v4 )
  {
    v7 = 2 * v6;
    v8 = other->m_triangles.m_size;
    if ( v4 < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_triangles,
      v8,
      24);
  }
  v9 = v3->m_triangles.m_data;
  v10 = v5;
  if ( v5 > 0 )
  {
    v11 = (char *)((char *)v2->m_triangles.m_data - (char *)v9);
    v12 = v5;
    do
    {
      v13 = *(unsigned int *)((char *)v9->m_indices + (_QWORD)v11);
      ++v9;
      v9[-1].m_indices[0] = v13;
      v9[-1].m_indices[1] = *(unsigned int *)((char *)&v9->m_indices[-5] + (_QWORD)v11);
      v9[-1].m_indices[2] = *(unsigned int *)((char *)&v9->m_indices[-4] + (_QWORD)v11);
      v9[-1].m_sortedIndices[0] = *(unsigned int *)((char *)&v9->m_indices[-3] + (_QWORD)v11);
      v9[-1].m_sortedIndices[1] = *(unsigned int *)((char *)&v9->m_indices[-2] + (_QWORD)v11);
      v9[-1].m_sortedIndices[2] = *(unsigned int *)((char *)&v9->m_indices[-1] + (_QWORD)v11);
      --v12;
    }
    while ( v12 );
  }
  v14 = &v3->m_triangles.m_data[v5];
  v15 = v4 - v5;
  if ( v4 - v5 > 0 )
  {
    v16 = (char *)&v2->m_triangles.m_data[v5] - (char *)v14;
    do
    {
      if ( v14 )
      {
        v14->m_indices[0] = *(unsigned int *)((char *)v14->m_indices + v16);
        v14->m_indices[1] = *(unsigned int *)((char *)&v14->m_indices[1] + v16);
        v14->m_indices[2] = *(unsigned int *)((char *)&v14->m_indices[2] + v16);
        v14->m_sortedIndices[0] = *(unsigned int *)((char *)v14->m_sortedIndices + v16);
        v14->m_sortedIndices[1] = *(unsigned int *)((char *)&v14->m_sortedIndices[1] + v16);
        v14->m_sortedIndices[2] = *(unsigned int *)((char *)&v14->m_sortedIndices[2] + v16);
      }
      ++v14;
      --v15;
    }
    while ( v15 );
  }
  v3->m_triangles.m_size = v4;
  v17 = v3->m_triangleIndices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( (signed int)v17 < v2->m_triangleIndices.m_size )
  {
    if ( v3->m_triangleIndices.m_capacityAndFlags >= 0 )
      ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, unsigned int *, _QWORD, _QWORD))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerHeapAllocator::s_alloc,
        v3->m_triangleIndices.m_data,
        (unsigned int)(4 * v17),
        v5);
    result.m_enum = 4 * v2->m_triangleIndices.m_size;
    v3->m_triangleIndices.m_data = (unsigned int *)((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkResult *, __int64, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
                                                     &hkContainerHeapAllocator::s_alloc,
                                                     &result,
                                                     v17,
                                                     v10);
    v3->m_triangleIndices.m_capacityAndFlags = result.m_enum / 4;
  }
  v18 = v2->m_triangleIndices.m_size;
  v19 = v3->m_triangleIndices.m_data;
  v3->m_triangleIndices.m_size = v18;
  v20 = v18;
  if ( (signed int)v18 > 0 )
  {
    v21 = (char *)((char *)v2->m_triangleIndices.m_data - (char *)v19);
    do
    {
      v22 = *(unsigned int *)((char *)v19 + (_QWORD)v21);
      ++v19;
      *(v19 - 1) = v22;
      --v20;
    }
    while ( v20 );
  }
  v3->m_numIncoming = v2->m_numIncoming;
  v3->m_numOutgoing = v2->m_numOutgoing;
  v3->m_nonManifold = v2->m_nonManifold;
  v3->m_inconsistentWinding = v2->m_inconsistentWinding;
  v3->m_processed = v2->m_processed;
  return v3;
}

// File Line: 85
// RVA: 0xCA2440
char __fastcall hkGeometryUtils::Node::Edge::hasTriangleSameWinding(hkGeometryUtils::Node::Edge *this, hkGeometryUtils::Node::Triangle *triangle, int *triIndex)
{
  int v3; // er10
  __int64 v4; // r11
  __int64 v5; // r9
  hkGeometryUtils::Node::Triangle *v6; // rax
  char result; // al

  v3 = 0;
  *triIndex = -1;
  v4 = this->m_triangles.m_size;
  v5 = 0i64;
  if ( v4 <= 0 )
    return 0;
  v6 = this->m_triangles.m_data;
  while ( *(_QWORD *)triangle->m_indices != *(_QWORD *)v6->m_indices || triangle->m_indices[2] != v6->m_indices[2] )
  {
    ++v5;
    ++v3;
    ++v6;
    if ( v5 >= v4 )
      return 0;
  }
  result = 1;
  *triIndex = this->m_triangleIndices.m_data[v3];
  return result;
}

// File Line: 101
// RVA: 0xCA24C0
char __fastcall hkGeometryUtils::Node::Edge::hasTriangleIgnoreWinding(hkGeometryUtils::Node::Edge *this, hkGeometryUtils::Node::Triangle *triangle, int *triIndex)
{
  int v3; // er10
  __int64 v4; // r11
  __int64 v5; // r9
  unsigned int *v6; // rax
  char result; // al

  v3 = 0;
  *triIndex = -1;
  v4 = this->m_triangles.m_size;
  v5 = 0i64;
  if ( v4 <= 0 )
    return 0;
  v6 = &this->m_triangles.m_data->m_sortedIndices[1];
  while ( *(_QWORD *)triangle->m_sortedIndices != *(_QWORD *)(v6 - 1) || triangle->m_sortedIndices[2] != v6[1] )
  {
    ++v5;
    ++v3;
    v6 += 6;
    if ( v5 >= v4 )
      return 0;
  }
  result = 1;
  *triIndex = this->m_triangleIndices.m_data[v3];
  return result;
}

// File Line: 117
// RVA: 0xCA2730
hkGeometryUtils::Node::Edge *__fastcall hkGeometryUtils::Node::findEdge(hkGeometryUtils::Node *this, unsigned int endpointIndex)
{
  __int64 v2; // r10
  int v3; // er9
  __int64 v4; // r8
  hkGeometryUtils::Node::Edge *v5; // rax

  v2 = this->m_edges.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( v2 <= 0 )
    return 0i64;
  v5 = this->m_edges.m_data;
  while ( v5->m_endpointIndex != endpointIndex )
  {
    ++v4;
    ++v3;
    ++v5;
    if ( v4 >= v2 )
      return 0i64;
  }
  return &this->m_edges.m_data[v3];
}

// File Line: 126
// RVA: 0xCA2540
void __fastcall hkGeometryUtils::Node::addEdge(hkGeometryUtils::Node *this, unsigned int endpointIndex, hkGeometryUtils::Node::Triangle *triangle, unsigned int triangleIndex, bool incoming)
{
  unsigned int v5; // er14
  hkGeometryUtils::Node::Triangle *v6; // rsi
  unsigned int v7; // ebp
  hkGeometryUtils::Node *v8; // rdi
  hkGeometryUtils::Node::Edge *v9; // rax
  hkGeometryUtils::Node::Edge *v10; // rbx
  hkGeometryUtils::Node::Triangle *v11; // rdx
  hkGeometryUtils::Node::Edge *v12; // rcx
  int v13; // er8
  hkGeometryUtils::Node::Edge other; // [rsp+20h] [rbp-48h]

  v5 = triangleIndex;
  v6 = triangle;
  v7 = endpointIndex;
  v8 = this;
  v9 = hkGeometryUtils::Node::findEdge(this, endpointIndex);
  v10 = v9;
  if ( v9 )
  {
    if ( incoming )
      ++v9->m_numIncoming;
    else
      ++v9->m_numOutgoing;
    if ( v9->m_numIncoming > 1 || v9->m_numOutgoing > 1 )
      v9->m_inconsistentWinding = 1;
    if ( v9->m_triangleIndices.m_size == (v9->m_triangleIndices.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v9->m_triangleIndices,
        4);
    v10->m_triangleIndices.m_data[v10->m_triangleIndices.m_size++] = v5;
    if ( v10->m_triangles.m_size == (v10->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v10->m_triangles, 24);
    v11 = &v10->m_triangles.m_data[v10->m_triangles.m_size];
    if ( v11 )
    {
      v11->m_indices[0] = v6->m_indices[0];
      v11->m_indices[1] = v6->m_indices[1];
      v11->m_indices[2] = v6->m_indices[2];
      v11->m_sortedIndices[0] = v6->m_sortedIndices[0];
      v11->m_sortedIndices[1] = v6->m_sortedIndices[1];
      v11->m_sortedIndices[2] = v6->m_sortedIndices[2];
    }
    ++v10->m_triangles.m_size;
    if ( v10->m_triangleIndices.m_size > 2 )
      v10->m_nonManifold = 1;
  }
  else
  {
    hkGeometryUtils::Node::Edge::Edge(&other, v7, v6, v5);
    if ( incoming )
      ++other.m_numIncoming;
    else
      ++other.m_numOutgoing;
    if ( v8->m_edges.m_size == (v8->m_edges.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v8->m_edges, 56);
    v12 = &v8->m_edges.m_data[v8->m_edges.m_size];
    if ( v12 )
      hkGeometryUtils::Node::Edge::Edge(v12, &other);
    v13 = other.m_triangleIndices.m_capacityAndFlags;
    ++v8->m_edges.m_size;
    other.m_triangleIndices.m_size = 0;
    if ( v13 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        other.m_triangleIndices.m_data,
        4 * v13);
    other.m_triangleIndices.m_data = 0i64;
    other.m_triangleIndices.m_capacityAndFlags = 2147483648;
    other.m_triangles.m_size = 0;
    if ( other.m_triangles.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        other.m_triangles.m_data,
        24 * (other.m_triangles.m_capacityAndFlags & 0x3FFFFFFF));
  }
}

// File Line: 152
// RVA: 0xCA2770
char __fastcall hkGeometryUtils::Node::checkForNonManifoldGeometry(hkGeometryUtils::Node *this)
{
  __int64 v1; // r8
  __int64 v2; // rdx
  bool *v3; // rax

  v1 = this->m_edges.m_size;
  v2 = 0i64;
  if ( v1 <= 0 )
    return 1;
  v3 = &this->m_edges.m_data->m_nonManifold;
  while ( !*v3 )
  {
    ++v2;
    v3 += 56;
    if ( v2 >= v1 )
      return 1;
  }
  return 0;
}

// File Line: 162
// RVA: 0xCA27A0
void __fastcall hkGeometryUtils::Node::warnAboutInconsistentWinding(hkGeometryUtils::Node *this, int e)
{
  hkGeometryUtils::Node *v2; // rsi
  hkGeometryUtils::Node::Edge *v3; // rdi
  unsigned int *v4; // rbx
  hkOstream *v5; // rax
  hkOstream *v6; // rax
  hkOstream *v7; // rax
  hkOstream *v8; // rax
  hkOstream *v9; // rax
  hkOstream *v10; // rax
  hkOstream *v11; // rax
  hkOstream *v12; // rax
  hkErrStream v13; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v2 = this;
  v3 = &this->m_edges.m_data[e];
  if ( v3->m_inconsistentWinding )
  {
    if ( v3->m_triangles.m_size > 1 )
    {
      hkErrStream::hkErrStream(&v13, &buf, 512);
      v4 = v3->m_triangleIndices.m_data;
      v5 = hkOstream::operator<<((hkOstream *)&v13.vfptr, "Edge (");
      v6 = hkOstream::operator<<(v5, v3->m_endpointIndex, (int)v5);
      v7 = hkOstream::operator<<(v6, ",");
      v8 = hkOstream::operator<<(v7, v2->m_vertexIndex, (int)v7);
      v9 = hkOstream::operator<<(v8, ") has inconsistent winding in triangles ");
      v10 = hkOstream::operator<<(v9, *v4, (int)v9);
      v11 = hkOstream::operator<<(v10, "and");
      v12 = hkOstream::operator<<(v11, v4[1], (int)v11);
      hkOstream::operator<<(v12, ".");
      hkError::messageWarning(-1413866065, &buf, "Misc\\hkGeometryUtils.cpp", 166);
      hkOstream::~hkOstream((hkOstream *)&v13.vfptr);
    }
  }
}

// File Line: 185
// RVA: 0xC9D450
__int64 __fastcall hkGeometryUtils::weldVerticesVirtual(hkGeometryUtils::IVertices *vertices, hkArray<int,hkContainerHeapAllocator> *remap, float thr)
{
  hkArray<int,hkContainerHeapAllocator> *v3; // r15
  hkGeometryUtils::IVertices *v4; // r14
  float v5; // xmm6_4
  int v6; // eax
  unsigned int v7; // er13
  signed __int64 v8; // rsi
  weldVerticesVirtualNs::VertexRef *v9; // rbx
  unsigned int v10; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // er9
  int v14; // edi
  signed __int64 v15; // rbp
  signed __int64 v16; // r12
  int *v17; // rdi
  signed __int64 v18; // rbx
  signed __int64 v19; // r12
  __int64 v20; // rdx
  signed __int64 v21; // rsi
  float *v22; // rbx
  __int64 v23; // rdx
  __m128 v24; // xmm2
  __m128 v25; // xmm2
  weldVerticesVirtualNs::VertexRef *pArr; // [rsp+30h] [rbp-98h]
  __m128 v28; // [rsp+40h] [rbp-88h]
  __m128 v29; // [rsp+50h] [rbp-78h]
  int v30; // [rsp+D0h] [rbp+8h]
  int v31; // [rsp+D8h] [rbp+10h]
  float v32; // [rsp+E0h] [rbp+18h]
  hkResult result; // [rsp+E8h] [rbp+20h]

  v32 = thr;
  v3 = remap;
  v4 = vertices;
  LODWORD(v5) = (unsigned __int128)_mm_shuffle_ps((__m128)LODWORD(v32), (__m128)LODWORD(v32), 0);
  v6 = ((__int64 (*)(void))vertices->vfptr->getNumVertices)();
  v7 = 0;
  v8 = v6;
  if ( v6 )
  {
    v30 = 32 * v6;
    v9 = (weldVerticesVirtualNs::VertexRef *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                               (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                               &v30);
    v6 = v30 / 32;
  }
  else
  {
    v9 = 0i64;
  }
  v10 = 2147483648;
  pArr = v9;
  if ( v6 )
    v10 = v6;
  v11 = v3->m_capacityAndFlags & 0x3FFFFFFF;
  v31 = v10;
  if ( v11 < (signed int)v8 )
  {
    v12 = 2 * v11;
    v13 = v8;
    if ( (signed int)v8 < v12 )
      v13 = v12;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, v13, 4);
  }
  v3->m_size = v8;
  v14 = 0;
  v15 = v8;
  if ( (signed int)v8 > 0 )
  {
    v16 = v8;
    do
    {
      v4->vfptr->getVertex(v4, v14, (hkVector4f *)&v28);
      v9->m_index = v14++;
      ++v9;
      v9[-1].m_value.m_real = _mm_shuffle_ps(v28, v28, 0);
      --v16;
    }
    while ( v16 );
  }
  if ( (signed int)v8 > 1 )
    hkAlgorithm::quickSortRecursive<weldVerticesVirtualNs::VertexRef,hkAlgorithm::less<weldVerticesVirtualNs::VertexRef>>(
      pArr,
      0,
      v8 - 1,
      0);
  if ( (signed int)v8 > 0 )
  {
    v17 = &pArr->m_index;
    v18 = v8;
    v19 = 1i64;
    *(_QWORD *)&result.m_enum = v8;
    do
    {
      v20 = *v17;
      if ( (signed int)v20 >= 0 )
      {
        v3->m_data[v20] = v20;
        v4->vfptr->getVertex(v4, *v17, (hkVector4f *)&v28);
        v21 = v19;
        if ( v19 < v15 )
        {
          v22 = (float *)(v17 + 8);
          do
          {
            v23 = *(unsigned int *)v22;
            if ( (signed int)v23 >= 0 )
            {
              if ( (float)(*(v22 - 4) - *((float *)v17 - 4)) > v5 )
                break;
              v4->vfptr->getVertex(v4, v23, (hkVector4f *)&v29);
              v24 = _mm_sub_ps(v28, v29);
              v25 = _mm_mul_ps(v24, v24);
              if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v25, v25, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v25, v25, 0)))
                         + COERCE_FLOAT(_mm_shuffle_ps(v25, v25, 170))) <= (float)(v5 * v5)
                && v4->vfptr->isWeldingAllowed(v4, *(_DWORD *)v22, *v17) )
              {
                v3->m_data[*(signed int *)v22] = *v17;
                *v22 = -6.8056469e38/*NaN*/;
              }
            }
            ++v21;
            v22 += 8;
          }
          while ( v21 < v15 );
          v18 = *(_QWORD *)&result.m_enum;
        }
        *v17 = -1;
        ++v7;
      }
      v17 += 8;
      ++v19;
      *(_QWORD *)&result.m_enum = --v18;
    }
    while ( v18 );
  }
  if ( v31 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      pArr,
      32 * v31);
  return v7;
}locator::s_all

// File Line: 235
// RVA: 0xC9D720
void __fastcall hkGeometryUtils::weldVertices(hkGeometry *meshGeometry, float threshold)
{
  hkGeometry *v2; // rbx
  int v3; // ecx
  bool v4; // zf
  int v5; // ecx
  int v6; // edi
  hk1AxisSweep::AabbInt *v7; // r8
  int v8; // eax
  int v9; // ecx
  int v10; // ecx
  int v11; // edi
  hkRadixSort::SortData32 *v12; // r8
  int v13; // eax
  int v14; // ecx
  int v15; // ecx
  int v16; // edi
  hk1AxisSweep::AabbInt *v17; // r8
  int v18; // eax
  hkArrayBase<hk1AxisSweep::AabbInt> sortedAabbs; // [rsp+48h] [rbp-19h]
  hkArrayBase<hkRadixSort::SortData32> sortData; // [rsp+58h] [rbp-9h]
  hkArray<hkVector4f,hkContainerHeapAllocator> uniqueVerts; // [rsp+68h] [rbp+7h]
  hkArray<int,hkContainerHeapAllocator> triangleRemapOut; // [rsp+78h] [rbp+17h]
  hkArray<int,hkContainerHeapAllocator> vertexRemapOut; // [rsp+88h] [rbp+27h]
  hkArrayBase<hk1AxisSweep::AabbInt> sweepAabbs; // [rsp+98h] [rbp+37h]
  int retaddr; // [rsp+C8h] [rbp+67h]

  v2 = meshGeometry;
  v3 = meshGeometry->m_vertices.m_size;
  v4 = v3 == -4;
  v5 = v3 + 4;
  vertexRemapOut.m_capacityAndFlags = 2147483648;
  vertexRemapOut.m_data = 0i64;
  vertexRemapOut.m_size = 0;
  triangleRemapOut.m_data = 0i64;
  v6 = v5;
  triangleRemapOut.m_size = 0;
  triangleRemapOut.m_capacityAndFlags = 2147483648;
  uniqueVerts.m_data = 0i64;
  uniqueVerts.m_size = 0;
  uniqueVerts.m_capacityAndFlags = 2147483648;
  if ( v4 )
  {
    v7 = 0i64;
  }
  else
  {
    retaddr = 32 * v5;
    v7 = (hk1AxisSweep::AabbInt *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                    &retaddr);
    v5 = retaddr / 32;
  }
  v8 = 2147483648;
  sweepAabbs.m_size = v6;
  if ( v5 )
    v8 = v5;
  v9 = v2->m_vertices.m_size;
  sweepAabbs.m_data = v7;
  v4 = v9 == -4;
  v10 = v9 + 4;
  sweepAabbs.m_capacityAndFlags = v8;
  sortData.m_data = 0i64;
  sortData.m_size = 0;
  sortData.m_capacityAndFlags = 2147483648;
  v11 = v10;
  if ( v4 )
  {
    v12 = 0i64;
  }
  else
  {
    retaddr = 8 * v10;
    v12 = (hkRadixSort::SortData32 *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                       (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                       &retaddr);
    v10 = retaddr / 8;
  }
  v13 = 2147483648;
  sortData.m_size = v11;
  if ( v10 )
    v13 = v10;
  v14 = v2->m_vertices.m_size;
  sortData.m_data = v12;
  v4 = v14 == -4;
  v15 = v14 + 4;
  sortData.m_capacityAndFlags = v13;
  sortedAabbs.m_data = 0i64;
  sortedAabbs.m_size = 0;
  sortedAabbs.m_capacityAndFlags = 2147483648;
  v16 = v15;
  if ( v4 )
  {
    v17 = 0i64;
  }
  else
  {
    retaddr = 32 * v15;
    v17 = (hk1AxisSweep::AabbInt *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                     (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                     &retaddr);
    v15 = retaddr / 32;
  }
  v18 = 2147483648;
  sortedAabbs.m_data = v17;
  if ( v15 )
    v18 = v15;
  sortedAabbs.m_capacityAndFlags = v18;
  sortedAabbs.m_size = v16;
  hkGeometryUtils::_weldVertices(
    v2,
    threshold,
    0,
    &vertexRemapOut,
    &triangleRemapOut,
    &uniqueVerts,
    &sweepAabbs,
    &sortData,
    &sortedAabbs);
  sortedAabbs.m_size = 0;
  if ( sortedAabbs.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      sortedAabbs.m_data,
      32 * sortedAabbs.m_capacityAndFlags);
  sortedAabbs.m_data = 0i64;
  sortedAabbs.m_capacityAndFlags = 2147483648;
  sortData.m_size = 0;
  if ( sortData.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      sortData.m_data,
      8 * sortData.m_capacityAndFlags);
  sortData.m_data = 0i64;
  sortData.m_capacityAndFlags = 2147483648;
  if ( sweepAabbs.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      sweepAabbs.m_data,
      32 * sweepAabbs.m_capacityAndFlags);
  uniqueVerts.m_size = 0;
  if ( uniqueVerts.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      uniqueVerts.m_data,
      16 * uniqueVerts.m_capacityAndFlags);
  uniqueVerts.m_data = 0i64;
  uniqueVerts.m_capacityAndFlags = 2147483648;
  triangleRemapOut.m_size = 0;
  if ( triangleRemapOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      triangleRemapOut.m_data,
      4 * triangleRemapOut.m_capacityAndFlags);
  triangleRemapOut.m_data = 0i64;
  triangleRemapOut.m_capacityAndFlags = 2147483648;
  vertexRemapOut.m_size = 0;
  if ( vertexRemapOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      vertexRemapOut.m_data,
      4 * vertexRemapOut.m_capacityAndFlags);
}

// File Line: 246
// RVA: 0xC9DA10
void __fastcall hkGeometryUtils::weldVertices(hkGeometry *meshGeometry, float threshold, hkBool keepVertexOrder, hkArray<int,hkContainerHeapAllocator> *vertexRemapOut)
{
  int v4; // edx
  bool v5; // zf
  int v6; // edx
  hkArray<int,hkContainerHeapAllocator> *v7; // rsi
  hkGeometry *v8; // rbx
  int v9; // edi
  hk1AxisSweep::AabbInt *v10; // rcx
  int v11; // ecx
  int v12; // eax
  int v13; // ecx
  int v14; // edi
  hkRadixSort::SortData32 *v15; // r8
  int v16; // eax
  int v17; // ecx
  int v18; // ecx
  int v19; // edi
  hkArrayBase<hkRadixSort::SortData32> *sortData; // [rsp+38h] [rbp-11h]
  hkArrayBase<hk1AxisSweep::AabbInt> *sortedAabbs; // [rsp+40h] [rbp-9h]
  hkArrayBase<hkRadixSort::SortData32> v22; // [rsp+48h] [rbp-1h]
  hkArray<hkVector4f,hkContainerHeapAllocator> uniqueVerts; // [rsp+58h] [rbp+Fh]
  hkArrayBase<hk1AxisSweep::AabbInt> sweepAabbs; // [rsp+68h] [rbp+1Fh]
  int v25; // [rsp+A8h] [rbp+5Fh]
  void *retaddr; // [rsp+B8h] [rbp+6Fh]
  hkArray<int,hkContainerHeapAllocator> *v27; // [rsp+C8h] [rbp+7Fh]

  v4 = meshGeometry->m_vertices.m_size;
  v5 = v4 == -4;
  v6 = v4 + 4;
  v7 = vertexRemapOut;
  v8 = meshGeometry;
  uniqueVerts.m_data = 0i64;
  uniqueVerts.m_size = 0;
  v9 = v6;
  uniqueVerts.m_capacityAndFlags = 2147483648;
  if ( v5 )
  {
    v10 = 0i64;
  }
  else
  {
    v25 = 32 * v6;
    v10 = (hk1AxisSweep::AabbInt *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                     (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                     &v25);
    v6 = v25 / 32;
  }
  sweepAabbs.m_data = v10;
  v11 = v8->m_vertices.m_size;
  v12 = 2147483648;
  sweepAabbs.m_size = v9;
  v22.m_data = 0i64;
  if ( v6 )
    v12 = v6;
  v5 = v11 == -4;
  v13 = v11 + 4;
  v22.m_size = 0;
  v14 = v13;
  sweepAabbs.m_capacityAndFlags = v12;
  v22.m_capacityAndFlags = 2147483648;
  if ( v5 )
  {
    v15 = 0i64;
  }
  else
  {
    v25 = 8 * v13;
    v15 = (hkRadixSort::SortData32 *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                       (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                       &v25);
    v13 = v25 / 8;
  }
  v16 = 2147483648;
  v22.m_size = v14;
  if ( v13 )
    v16 = v13;
  v17 = v8->m_vertices.m_size;
  v22.m_data = v15;
  v5 = v17 == -4;
  v18 = v17 + 4;
  v22.m_capacityAndFlags = v16;
  sortData = 0i64;
  sortedAabbs = (hkArrayBase<hk1AxisSweep::AabbInt> *)0x8000000000000000i64;
  v19 = v18;
  if ( !v5 )
  {
    v25 = 32 * v18;
    hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc, &v25);
  }
  sortedAabbs = (hkArrayBase<hk1AxisSweep::AabbInt> *)&sortData;
  LODWORD(sortedAabbs) = v19;
  hkGeometryUtils::_weldVertices(v8, threshold, (hkBool)retaddr, v7, v27, &uniqueVerts, &sweepAabbs, &v22, sortedAabbs);
  LODWORD(sortedAabbs) = 0;
  if ( SHIDWORD(sortedAabbs) >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      sortData,
      32 * HIDWORD(sortedAabbs));
  sortData = 0i64;
  HIDWORD(sortedAabbs) = 2147483648;
  v22.m_size = 0;
  if ( v22.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v22.m_data,
      8 * v22.m_capacityAndFlags);
  v22.m_data = 0i64;
  v22.m_capacityAndFlags = 2147483648;
  if ( sweepAabbs.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      sweepAabbs.m_data,
      32 * sweepAabbs.m_capacityAndFlags);
  uniqueVerts.m_size = 0;
  if ( uniqueVerts.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      uniqueVerts.m_data,
      16 * uniqueVerts.m_capacityAndFlags);
}

// File Line: 258
// RVA: 0xCA28B0
void __fastcall `anonymous namespace'::hkWeldVertices(hkArray<hkVector4f,hkContainerHeapAllocator> *vertsIn, hkArray<hkVector4f,hkContainerHeapAllocator> *uniqueVerts, hkArray<int,hkContainerHeapAllocator> *remap, hkArrayBase<hk1AxisSweep::AabbInt> *vertAabbs, hkArrayBase<hkRadixSort::SortData32> *sortData, hkArrayBase<hk1AxisSweep::AabbInt> *tempAabbs, float tol)
{
  __int64 v7; // r13
  int v8; // eax
  hkArrayBase<hk1AxisSweep::AabbInt> *v9; // rbx
  hkArray<int,hkContainerHeapAllocator> *v10; // r12
  hkArray<hkVector4f,hkContainerHeapAllocator> *v11; // rsi
  __m128 v12; // xmm7
  int v13; // eax
  int v14; // er9
  __int64 v15; // rdi
  __int64 v16; // r15
  __m128 v17; // xmm6
  int v18; // ebp
  __int64 v19; // r14
  hkVector4f *v20; // rax
  hk1AxisSweep::AabbInt *v21; // rcx
  hkVector4f v22; // xmm0
  hkArrayBase<hk1AxisSweep::AabbInt> *v23; // r9
  hkArrayBase<hkRadixSort::SortData32> *v24; // r8
  hkVector4f v25; // xmm1
  signed __int64 v26; // rax
  float v27; // xmm7_4
  signed __int64 v28; // r13
  __int64 v29; // r9
  __int64 v30; // rbp
  hkArray<hkVector4f,hkContainerHeapAllocator> *v31; // r11
  __m128 *v32; // r14
  __int64 v33; // r8
  signed __int64 v34; // rax
  _DWORD *v35; // rdx
  __int64 v36; // rcx
  __m128 v37; // xmm2
  __m128 v38; // xmm2
  hkAabb aabbIn; // [rsp+30h] [rbp-78h]
  hkArray<hkVector4f,hkContainerHeapAllocator> *v40; // [rsp+B0h] [rbp+8h]
  hkArray<hkVector4f,hkContainerHeapAllocator> *v41; // [rsp+B8h] [rbp+10h]
  __int64 v42; // [rsp+C0h] [rbp+18h]

  v41 = uniqueVerts;
  v40 = vertsIn;
  v7 = vertsIn->m_size;
  v8 = remap->m_capacityAndFlags & 0x3FFFFFFF;
  v9 = vertAabbs;
  v10 = remap;
  v11 = uniqueVerts;
  v12 = _mm_shuffle_ps((__m128)LODWORD(tol), (__m128)LODWORD(tol), 0);
  if ( v8 < (signed int)v7 )
  {
    v13 = 2 * v8;
    v14 = v7;
    if ( (signed int)v7 < v13 )
      v14 = v13;
    hkArrayUtil::_reserve(
      (hkResult *)&v42,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      remap,
      v14,
      4);
  }
  v15 = 0i64;
  v10->m_size = v7;
  v16 = v7;
  v17 = _mm_mul_ps(v12, (__m128)xmmword_141A711B0);
  v18 = 0;
  v9->m_size = v7 + 4;
  if ( (signed int)v7 > 0 )
  {
    v19 = 0i64;
    do
    {
      v20 = v40->m_data;
      v21 = &v9->m_data[v18];
      aabbIn.m_min.m_quad = _mm_sub_ps(v40->m_data[v19].m_quad, v17);
      aabbIn.m_max.m_quad = _mm_add_ps(v20[v19].m_quad, v17);
      hk1AxisSweep::AabbInt::set(v21, &aabbIn, v18++);
      ++v19;
      --v16;
    }
    while ( v16 );
    v11 = v41;
    v16 = v7;
  }
  v22.m_quad = (__m128)aabbIn.m_max;
  v23 = tempAabbs;
  v24 = sortData;
  aabbIn.m_min.m_quad.m128_i32[0] = -1;
  v25.m_quad = (__m128)aabbIn.m_min;
  v26 = (signed __int64)&v9->m_data[v16];
  *(hkVector4f *)v26 = aabbIn.m_min;
  *(hkVector4f *)(v26 + 16) = (hkVector4f)v22.m_quad;
  *(hkVector4f *)(v26 + 32) = (hkVector4f)v25.m_quad;
  *(hkVector4f *)(v26 + 48) = (hkVector4f)v22.m_quad;
  *(hkVector4f *)(v26 + 64) = (hkVector4f)v25.m_quad;
  *(hkVector4f *)(v26 + 80) = (hkVector4f)v22.m_quad;
  *(hkVector4f *)(v26 + 96) = (hkVector4f)v25.m_quad;
  *(hkVector4f *)(v26 + 112) = (hkVector4f)v22.m_quad;
  hk1AxisSweep::sortAabbs(v9->m_data, v7, v24, v23);
  v27 = v12.m128_f32[0] * v12.m128_f32[0];
  if ( v16 > 0 )
  {
    v28 = 1i64;
    v29 = v16;
    v42 = v16;
    do
    {
      v30 = *(unsigned int *)v9->m_data[v15].m_expansionMin;
      if ( (_DWORD)v30 != -1 )
      {
        v31 = v40;
        v32 = &v40->m_data[(signed int)v30].m_quad;
        v10->m_data[(signed int)v30] = v11->m_size;
        if ( v11->m_size == (v11->m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v11, 16);
          v31 = v40;
          v29 = v42;
        }
        v33 = v28;
        v11->m_data[v11->m_size++].m_quad = *v32;
        if ( v28 < v16 )
        {
          v34 = v15 * 32 + 32;
          do
          {
            v35 = (unsigned int *)((char *)v9->m_data->m_min + v34);
            if ( *v35 > v9->m_data[v15].m_max[0] )
              break;
            v36 = (signed int)v35[3];
            if ( (_DWORD)v36 != -1 )
            {
              v37 = _mm_sub_ps(*v32, v31->m_data[v35[3]].m_quad);
              v38 = _mm_mul_ps(v37, v37);
              if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v38, v38, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v38, v38, 0)))
                         + COERCE_FLOAT(_mm_shuffle_ps(v38, v38, 170))) <= v27 )
              {
                v10->m_data[v36] = v10->m_data[v30];
                *(_DWORD *)&v9->m_data->m_expansionMin[v34] = -1;
              }
            }
            ++v33;
            v34 += 32i64;
          }
          while ( v33 < v16 );
          v29 = v42;
        }
      }
      ++v28;
      ++v15;
      v42 = --v29;
    }
    while ( v29 );
  }
}

// File Line: 327
// RVA: 0xCA2B60
bool __fastcall `anonymous namespace'::hkTriangle_isDegenerate(hkGeometry::Triangle *a)
{
  int v1; // edx
  int v2; // eax
  bool result; // al

  v1 = a->m_b;
  result = 1;
  if ( a->m_a != v1 )
  {
    v2 = a->m_c;
    if ( a->m_a != v2 && v1 != v2 )
      result = 0;
  }
  return result;
}

// File Line: 359
// RVA: 0xCA2B90
bool __fastcall sameTriangleConsideringWinding(hkGeometry::Triangle *triA, hkGeometry::Triangle *triB)
{
  int v2; // er10
  int v3; // er8
  int v4; // er9
  bool result; // al

  v2 = triA->m_a;
  v3 = triB->m_a;
  result = 1;
  if ( *(_QWORD *)&triA->m_a != *(_QWORD *)&triB->m_a || triA->m_c != triB->m_c )
  {
    v4 = triB->m_b;
    if ( (v2 != v4 || *(_QWORD *)&triA->m_b != __PAIR__(v3, triB->m_c))
      && (v2 != triB->m_c || *(_QWORD *)&triA->m_b != __PAIR__(v4, v3)) )
    {
      result = 0;
    }
  }
  return result;
}

// File Line: 381
// RVA: 0xCA2BE0
unsigned __int64 __fastcall hashTriangle(hkGeometry::Triangle *t1)
{
  return t1->m_c & 0x1FFFFF | ((t1->m_b & 0x1FFFFF | ((unsigned __int64)(t1->m_a & 0x1FFFFF) << 21)) << 21);
}

// File Line: 419
// RVA: 0xC9E9A0
hkResult *__fastcall hkGeometryUtils::removeDuplicateTrianglesFast(hkResult *result, hkGeometry *meshGeometry, hkArray<hkGeometry::Triangle,hkContainerHeapAllocator> *newTriangles)
{
  int v3; // ebp
  hkArray<hkGeometry::Triangle,hkContainerHeapAllocator> *v4; // r14
  hkGeometry *v5; // r13
  hkResult *v6; // rdi
  hkResult *v7; // rax
  int v8; // er12
  __int64 v9; // rbx
  int v10; // edi
  signed __int64 v11; // rsi
  hkGeometry::Triangle *v12; // rax
  int v13; // er8
  int v14; // er9
  int v15; // edx
  int v16; // eax
  unsigned __int64 v17; // rax
  int v18; // er15
  signed __int64 v19; // r11
  signed __int64 v20; // rdi
  __int64 v21; // r14
  int v22; // er10
  signed int v23; // esi
  int v24; // er8
  signed __int64 v25; // r9
  hkGeometry::Triangle *v26; // rax
  hkGeometry::Triangle *v27; // rdx
  int v28; // er11
  int v29; // ebx
  int v30; // er10
  signed __int64 v31; // rcx
  signed __int64 v32; // rdx
  __int64 v33; // rax
  int *v34; // rdi
  __int64 v35; // rsi
  hkGeometry::Triangle *v36; // rbx
  hkGeometry::Triangle *v37; // rcx
  __int64 v38; // rax
  hkGeometry::Triangle *v39; // rcx
  __int64 v40; // rdx
  char *v41; // r8
  int v42; // eax
  triInfo *v43; // [rsp+28h] [rbp-60h]
  hkGeometry::Triangle t1; // [rsp+30h] [rbp-58h]
  hkResult *v45; // [rsp+90h] [rbp+8h]
  int v46; // [rsp+98h] [rbp+10h]
  hkArray<hkGeometry::Triangle,hkContainerHeapAllocator> *v47; // [rsp+A0h] [rbp+18h]
  int v48; // [rsp+A8h] [rbp+20h]

  v47 = newTriangles;
  v45 = result;
  v3 = meshGeometry->m_triangles.m_size;
  v4 = newTriangles;
  v5 = meshGeometry;
  v6 = result;
  if ( v3 )
  {
    v48 = 16 * v3;
    v8 = 2147483648;
    v9 = (__int64)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                    (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                    &v48);
    v43 = (triInfo *)v9;
    if ( v48 / 16 )
      v8 = v48 / 16;
    if ( v9 )
    {
      v10 = 0;
      if ( v5->m_triangles.m_size > 0 )
      {
        v11 = -v9;
        do
        {
          v12 = v5->m_triangles.m_data;
          v13 = *(int *)((char *)&v12->m_a + v11 + v9);
          v14 = *(int *)((char *)&v12->m_b + v11 + v9);
          v15 = *(int *)((char *)&v12->m_c + v11 + v9);
          LODWORD(v12) = *(int *)((char *)&v12->m_material + v11 + v9);
          *(_QWORD *)&t1.m_a = __PAIR__(v14, v13);
          t1.m_material = (signed int)v12;
          t1.m_c = v15;
          if ( v13 > v14 )
          {
            v16 = v13;
            t1.m_a = v14;
            v13 = v14;
            v14 = v16;
            t1.m_b = v16;
          }
          if ( v13 > v15 )
          {
            t1.m_a = v15;
            v15 = v13;
            t1.m_c = v13;
          }
          if ( v14 > v15 )
          {
            t1.m_b = v15;
            t1.m_c = v14;
          }
          v17 = hashTriangle(&t1);
          *(_DWORD *)(v9 + 8) = v10++;
          *(_QWORD *)v9 = v17;
          v9 += 16i64;
        }
        while ( v10 < v5->m_triangles.m_size );
        v9 = (__int64)v43;
      }
      if ( v3 > 1 )
        hkAlgorithm::quickSortRecursive<triInfo,sortByKey>((triInfo *)v9, 0, v3 - 1, 0);
      v18 = v3 - 1;
      v19 = v3 - 1;
      *(_QWORD *)&t1.m_a = v3 - 1;
      if ( v19 >= 1 )
      {
        v20 = v9 + 16i64 * v18;
        do
        {
          v21 = *(_QWORD *)v20;
          v22 = v18 - 1;
          v23 = -1;
          v46 = v18 - 1;
          v24 = v18 - 1;
          if ( v18 >= 1 )
          {
            v25 = v20 - 16;
            do
            {
              if ( v21 != *(_QWORD *)v25 )
                break;
              v26 = &v5->m_triangles.m_data[*(signed int *)(v20 + 8)];
              v27 = &v5->m_triangles.m_data[*(signed int *)(v25 + 8)];
              v28 = v26->m_a;
              v29 = v27->m_a;
              if ( v26->m_a != v27->m_a || v26->m_b != v27->m_b || v26->m_c != v27->m_c )
              {
                v30 = v27->m_b;
                if ( (v28 != v30 || v26->m_b != v27->m_c || v26->m_c != v29)
                  && (v28 != v27->m_c || v26->m_b != v29 || v26->m_c != v30) )
                {
                  continue;
                }
              }
              v23 = v24;
              v25 -= 16i64;
              --v24;
            }
            while ( v24 >= 0 );
            v9 = (__int64)v43;
            if ( v23 != -1 && --v3 != v18 )
            {
              v31 = v20;
              v32 = 2i64;
              do
              {
                v33 = *(unsigned __int64 *)((char *)&v43[v3].m_key + v31 - v20);
                v31 += 8i64;
                *(_QWORD *)(v31 - 8) = v33;
                --v32;
              }
              while ( v32 );
            }
            v22 = v46;
            v19 = *(_QWORD *)&t1.m_a;
          }
          v20 -= 16i64;
          --v19;
          v18 = v22;
          *(_QWORD *)&t1.m_a = v19;
        }
        while ( v19 );
        v4 = v47;
      }
      if ( v3 > 1 )
        hkAlgorithm::quickSortRecursive<triInfo,sortByIndex>((triInfo *)v9, 0, v3 - 1, 0);
      v4->m_size = 0;
      if ( v3 > 0 )
      {
        v34 = (int *)(v9 + 8);
        v35 = (unsigned int)v3;
        do
        {
          v36 = &v5->m_triangles.m_data[*v34];
          if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 16);
          v34 += 4;
          v37 = &v4->m_data[v4->m_size];
          v37->m_a = v36->m_a;
          v37->m_b = v36->m_b;
          v37->m_c = v36->m_c;
          v37->m_material = v36->m_material;
          ++v4->m_size;
          --v35;
        }
        while ( v35 );
      }
      if ( (v5->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) < v4->m_size )
      {
        if ( v5->m_triangles.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v5->m_triangles.m_data,
            16 * v5->m_triangles.m_capacityAndFlags);
        v46 = 16 * v4->m_size;
        v5->m_triangles.m_data = (hkGeometry::Triangle *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                           (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                           &v46);
        v5->m_triangles.m_capacityAndFlags = v46 / 16;
      }
      v38 = v4->m_size;
      v39 = v5->m_triangles.m_data;
      v5->m_triangles.m_size = v38;
      v40 = v38;
      if ( (signed int)v38 > 0 )
      {
        v41 = (char *)((char *)v4->m_data - (char *)v39);
        do
        {
          v42 = *(int *)((char *)&v39->m_a + (_QWORD)v41);
          ++v39;
          v39[-1].m_a = v42;
          v39[-1].m_b = *(_DWORD *)((char *)v39 + (_QWORD)v41 - 12);
          v39[-1].m_c = *(_DWORD *)((char *)v39 + (_QWORD)v41 - 8);
          v39[-1].m_material = *(_DWORD *)((char *)v39 + (_QWORD)v41 - 4);
          --v40;
        }
        while ( v40 );
      }
      v45->m_enum = 0;
      if ( v8 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          v43,
          16 * v8);
      v7 = v45;
    }
    else
    {
      v6->m_enum = 1;
      if ( v8 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          0i64,
          16 * v8);
      v7 = v6;
    }
  }
  else
  {
    v7 = result;
    result->m_enum = 0;
  }
  return v7;
}

// File Line: 496
// RVA: 0xC9DC90
void __fastcall hkGeometryUtils::_weldVertices(hkGeometry *meshGeometry, float threshold, hkBool keepVertexOrder, hkArray<int,hkContainerHeapAllocator> *vertexRemapOut, hkArray<int,hkContainerHeapAllocator> *triangleRemapOut, hkArray<hkVector4f,hkContainerHeapAllocator> *uniqueVerts, hkArrayBase<hk1AxisSweep::AabbInt> *sweepAabbs, hkArrayBase<hkRadixSort::SortData32> *sortData, hkArrayBase<hk1AxisSweep::AabbInt> *sortedAabbs)
{
  int v9; // edi
  int v10; // er12
  int v11; // eax
  hkArray<int,hkContainerHeapAllocator> *v12; // r15
  hkGeometry *v13; // r13
  int v14; // eax
  int v15; // er9
  hkArray<hkVector4f,hkContainerHeapAllocator> *v16; // r14
  hkArrayBase<hk1AxisSweep::AabbInt> *v17; // r9
  hkArrayBase<hk1AxisSweep::AabbInt> *tempAabbs; // ST28_8
  signed __int64 v19; // rsi
  hkArray<hkVector4f,hkContainerHeapAllocator> *v20; // rdx
  hkArrayBase<hkRadixSort::SortData32> *sizeElem; // ST20_8
  signed __int64 v22; // rbx
  int v23; // er9
  int v24; // edi
  int v25; // er14
  int v26; // eax
  int v27; // er9
  __int64 v28; // rcx
  _DWORD *v29; // rdi
  int v30; // er13
  __int64 v31; // r14
  hkArray<hkVector4f,hkContainerHeapAllocator> *v32; // rbx
  __int64 v33; // rsi
  int v34; // er12
  int v35; // ecx
  __int128 *v36; // rsi
  void *v37; // rax
  _OWORD *v38; // rcx
  __int64 v39; // rdx
  __int128 *v40; // rax
  __int128 v41; // xmm0
  __int64 v42; // rsi
  __int64 v43; // rdi
  __int64 v44; // r8
  hkGeometry::Triangle *v45; // rdx
  hkArray<int,hkContainerHeapAllocator> *v46; // rdi
  int v47; // eax
  int v48; // eax
  int v49; // er9
  hkGeometry::Triangle *v50; // rdi
  hkArray<hkGeometry::Triangle,hkContainerHeapAllocator> *v51; // r12
  __int64 v52; // r15
  hkGeometry::Triangle *v53; // r13
  signed __int64 v54; // rsi
  hkGeometry::Triangle *v55; // r14
  signed __int64 v56; // rdi
  int v57; // eax
  int v58; // eax
  int v59; // er9
  __int64 v60; // rax
  char *v61; // rcx
  __int64 v62; // rdx
  signed __int64 v63; // rdi
  __int128 v64; // xmm0
  int v65; // [rsp+40h] [rbp-40h]
  signed __int64 v66; // [rsp+48h] [rbp-38h]
  __int128 *array; // [rsp+50h] [rbp-30h]
  int v68; // [rsp+58h] [rbp-28h]
  int v69; // [rsp+5Ch] [rbp-24h]
  _DWORD *v70; // [rsp+60h] [rbp-20h]
  int v71; // [rsp+68h] [rbp-18h]
  int v72; // [rsp+6Ch] [rbp-14h]
  hkGeometry *v73; // [rsp+C0h] [rbp+40h]
  char v74; // [rsp+D0h] [rbp+50h]
  hkResult result; // [rsp+D8h] [rbp+58h]

  v74 = keepVertexOrder.m_bool;
  v73 = meshGeometry;
  v9 = meshGeometry->m_vertices.m_size;
  v10 = meshGeometry->m_triangles.m_size;
  v11 = vertexRemapOut->m_capacityAndFlags & 0x3FFFFFFF;
  v12 = vertexRemapOut;
  v13 = meshGeometry;
  v65 = meshGeometry->m_triangles.m_size;
  if ( v11 < v9 )
  {
    v14 = 2 * v11;
    v15 = meshGeometry->m_vertices.m_size;
    if ( v9 < v14 )
      v15 = v14;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v12, v15, 4);
  }
  v16 = uniqueVerts;
  v17 = sweepAabbs;
  tempAabbs = sortedAabbs;
  v19 = (signed __int64)&v13->m_vertices;
  v20 = uniqueVerts;
  sizeElem = sortData;
  v12->m_size = v9;
  v66 = (signed __int64)&v13->m_vertices;
  `anonymous namespace'::hkWeldVertices(&v13->m_vertices, v20, v12, v17, sizeElem, tempAabbs, threshold);
  v22 = 0i64;
  if ( v74 )
  {
    v23 = v16->m_size;
    array = 0i64;
    v24 = 0;
    v68 = 0;
    v69 = 2147483648;
    if ( v23 > 0 )
    {
      if ( v23 < 0 )
        v23 = 0;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v23, 16);
      v24 = v68;
    }
    v25 = v16->m_size;
    v70 = 0i64;
    v26 = 0;
    v71 = 0;
    v72 = 2147483648;
    if ( v25 > 0 )
    {
      v27 = v25;
      if ( v25 < 0 )
        v27 = 0;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v70, v27, 4);
      v24 = v68;
      v26 = v71;
    }
    v28 = v25 - v26;
    if ( v25 - v26 > 0 )
    {
      v29 = &v70[v26];
      while ( v28 )
      {
        *v29 = -1;
        ++v29;
        --v28;
      }
      v24 = v68;
    }
    v71 = v25;
    v30 = 0;
    if ( v12->m_size > 0 )
    {
      v31 = 0i64;
      v32 = uniqueVerts;
      do
      {
        v33 = v12->m_data[v31];
        v34 = v70[v33];
        if ( v34 == -1 )
        {
          v70[v33] = v24;
          v35 = v68;
          v34 = v24;
          v36 = (__int128 *)&v32->m_data[v33];
          if ( v68 == (v69 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
            v35 = v68;
          }
          array[v35] = *v36;
          ++v68;
        }
        ++v30;
        ++v31;
        v12->m_data[v31 - 1] = v34;
        v24 = v68;
      }
      while ( v30 < v12->m_size );
      v19 = v66;
      v10 = v65;
      v22 = 0i64;
    }
    if ( (*(_DWORD *)(v19 + 12) & 0x3FFFFFFF) < v24 )
    {
      if ( *(_DWORD *)(v19 + 12) >= 0 )
      {
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)v19,
          16 * *(_DWORD *)(v19 + 12));
        v24 = v68;
      }
      result.m_enum = 16 * v24;
      v37 = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              (int *)&result);
      v24 = v68;
      *(_QWORD *)v19 = v37;
      *(_DWORD *)(v19 + 12) = result.m_enum / 16;
    }
    v38 = *(_OWORD **)v19;
    *(_DWORD *)(v19 + 8) = v24;
    v39 = v24;
    if ( v24 > 0 )
    {
      v40 = array;
      do
      {
        v41 = *v40;
        ++v38;
        ++v40;
        *(v38 - 1) = v41;
        --v39;
      }
      while ( v39 );
    }
    v71 = 0;
    if ( v72 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v70,
        4 * v72);
    v70 = 0i64;
    v72 = 2147483648;
    v68 = 0;
    if ( v69 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        16 * v69);
    v13 = v73;
  }
  else
  {
    if ( (v13->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) < v16->m_size )
    {
      if ( v13->m_vertices.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)v19,
          16 * v13->m_vertices.m_capacityAndFlags);
      LODWORD(v73) = 16 * v16->m_size;
      *(_QWORD *)v19 = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                         (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                         (int *)&v73);
      v13->m_vertices.m_capacityAndFlags = (signed int)v73 / 16;
    }
    v60 = v16->m_size;
    v61 = *(char **)v19;
    v13->m_vertices.m_size = v60;
    v62 = v60;
    if ( (signed int)v60 > 0 )
    {
      v63 = (char *)v16->m_data - v61;
      do
      {
        v64 = *(_OWORD *)&v61[v63];
        v61 += 16;
        *((_OWORD *)v61 - 1) = v64;
        --v62;
      }
      while ( v62 );
    }
  }
  v42 = v10;
  if ( v10 > 0 )
  {
    v43 = 0i64;
    v44 = v10;
    do
    {
      v45 = v13->m_triangles.m_data;
      ++v43;
      v45[v43 - 1].m_a = v12->m_data[v45[v43 - 1].m_a];
      *((_DWORD *)&v45[v43] - 3) = v12->m_data[*((signed int *)&v45[v43] - 3)];
      *((_DWORD *)&v45[v43] - 2) = v12->m_data[*((signed int *)&v45[v43] - 2)];
      --v44;
    }
    while ( v44 );
  }
  v46 = triangleRemapOut;
  v47 = triangleRemapOut->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v47 < v10 )
  {
    v48 = 2 * v47;
    v49 = v10;
    if ( v10 < v48 )
      v49 = v48;
    hkArrayUtil::_reserve(
      (hkResult *)&v73,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      triangleRemapOut,
      v49,
      4);
  }
  v46->m_size = v10;
  v50 = v13->m_triangles.m_data;
  v51 = &v13->m_triangles;
  if ( v42 > 0 )
  {
    v52 = 0i64;
    do
    {
      v53 = v51->m_data;
      LODWORD(v54) = -1;
      v55 = &v51->m_data[v52];
      if ( !`anonymous namespace'::hkTriangle_isDegenerate(&v51->m_data[v52]) )
      {
        v50->m_a = v55->m_a;
        v50->m_b = v55->m_b;
        v54 = v50 - v53;
        v50->m_c = v55->m_c;
        ++v50;
        v50[-1].m_material = v55->m_material;
      }
      ++v22;
      ++v52;
      triangleRemapOut->m_data[v22 - 1] = v54;
    }
    while ( v22 < v65 );
  }
  v56 = v50 - v51->m_data;
  v57 = v51->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v57 < (signed int)v56 )
  {
    v58 = 2 * v57;
    v59 = v56;
    if ( (signed int)v56 < v58 )
      v59 = v58;
    hkArrayUtil::_reserve((hkResult *)&v73, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v51, v59, 16);
  }
  v51->m_size = v56;
}

// File Line: 579
// RVA: 0xC9E180
void __usercall hkGeometryUtils::removeDuplicateTriangles(hkGeometry *meshGeometry@<rcx>, hkArray<int,hkContainerHeapAllocator> *triangleMapOut@<rdx>, bool ignoreWinding@<r8b>, __int64 a4@<rbx>)
{
  bool v4; // si
  hkArray<int,hkContainerHeapAllocator> *v5; // rbx
  hkGeometry *v6; // r14
  unsigned int v7; // edi
  int v8; // edx
  hkGeometryUtils::Node *v9; // rcx
  __int64 v10; // rcx
  unsigned int *v11; // rsi
  __int64 v12; // r12
  hkGeometryUtils::Node *v13; // rdi
  __int64 v14; // r15
  hkGeometryUtils::Node::Edge *v15; // rax
  __int64 v16; // r13
  hkGeometryUtils::Node::Edge *v17; // rsi
  hkGeometryUtils::Node::Edge *v18; // rdi
  unsigned int v19; // er13
  signed __int64 v20; // r15
  signed int v21; // er12
  __int64 v22; // rsi
  __int64 v23; // rdi
  __int64 v24; // rdi
  signed int v25; // ecx
  int *v26; // rdi
  int *v27; // rcx
  __int64 v28; // rcx
  unsigned int *v29; // rsi
  __int64 v30; // r12
  hkGeometryUtils::Node *v31; // rdi
  __int64 v32; // r15
  hkGeometryUtils::Node::Edge *v33; // rax
  __int64 v34; // r13
  hkGeometryUtils::Node::Edge *v35; // rsi
  hkGeometryUtils::Node::Edge *v36; // rdi
  unsigned int v37; // er13
  signed __int64 v38; // r15
  signed int v39; // er12
  __int64 v40; // rsi
  __int64 v41; // rdi
  __int64 v42; // rdi
  signed int v43; // ecx
  int *v44; // rdi
  int *v45; // rcx
  int v46; // edi
  int v47; // ebx
  hkOstream *v48; // rax
  hkOstream *v49; // rax
  hkOstream *v50; // rax
  hkOstream *v51; // rax
  __int64 v52; // rax
  hkGeometry::Triangle *v53; // rdx
  __int64 v54; // r8
  int *v55; // rcx
  int v56; // eax
  int v57; // ebx
  hkGeometryUtils::Node *v58; // rdi
  int *v59; // [rsp+30h] [rbp-C8h]
  unsigned int triangleIndex; // [rsp+38h] [rbp-C0h]
  int v61; // [rsp+3Ch] [rbp-BCh]
  hkGeometryUtils::Node *array; // [rsp+40h] [rbp-B8h]
  int v63; // [rsp+48h] [rbp-B0h]
  int v64; // [rsp+4Ch] [rbp-ACh]
  __int64 v65; // [rsp+50h] [rbp-A8h]
  unsigned int c; // [rsp+58h] [rbp-A0h]
  int v67; // [rsp+60h] [rbp-98h]
  int v68; // [rsp+64h] [rbp-94h]
  int v69; // [rsp+68h] [rbp-90h]
  hkGeometryUtils::Node other; // [rsp+70h] [rbp-88h]
  char buf; // [rsp+88h] [rbp-70h]
  void *retaddr; // [rsp+2C8h] [rbp+1D0h]
  __int64 i; // [rsp+2D8h] [rbp+1E0h]
  unsigned int v74; // [rsp+2E0h] [rbp+1E8h]

  i = a4;
  v4 = ignoreWinding;
  v5 = triangleMapOut;
  v6 = meshGeometry;
  v59 = 0i64;
  triangleIndex = 0;
  v61 = 2147483648;
  array = 0i64;
  v63 = 0;
  v64 = 2147483648;
  v7 = 0;
  if ( meshGeometry->m_vertices.m_size )
  {
    do
    {
      hkGeometryUtils::Node::Node(&other, v7);
      v8 = v63;
      if ( v63 == (v64 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 24);
        v8 = v63;
      }
      v9 = &array[v8];
      if ( v9 )
      {
        hkGeometryUtils::Node::Node(v9, &other);
        v8 = v63;
      }
      v63 = v8 + 1;
      hkGeometryUtils::Node::~Node(&other);
      ++v7;
    }
    while ( v7 < v6->m_vertices.m_size );
  }
  LODWORD(i) = 0;
  v74 = 0;
  if ( v4 )
  {
    if ( v6->m_triangles.m_size <= 0u )
      goto LABEL_49;
    v10 = 0i64;
    v65 = 0i64;
    do
    {
      v11 = (unsigned int *)((char *)v6->m_triangles.m_data + v10);
      hkGeometryUtils::Node::Triangle::Triangle((hkGeometryUtils::Node::Triangle *)&other, *v11, v11[1], v11[2]);
      v12 = (signed int)*v11;
      v13 = array;
      v14 = (signed int)v11[1];
      v15 = hkGeometryUtils::Node::findEdge(&array[v12], v11[1]);
      v16 = (signed int)v11[2];
      *(_QWORD *)&other.m_edges.m_size = v15;
      c = v16;
      v17 = hkGeometryUtils::Node::findEdge(&v13[v14], v16);
      v18 = hkGeometryUtils::Node::findEdge(&v13[v16], v12);
      if ( *(_QWORD *)&other.m_edges.m_size
        && hkGeometryUtils::Node::Edge::hasTriangleIgnoreWinding(
             *(hkGeometryUtils::Node::Edge **)&other.m_edges.m_size,
             (hkGeometryUtils::Node::Triangle *)&other,
             (int *)&retaddr)
        || v17
        && hkGeometryUtils::Node::Edge::hasTriangleIgnoreWinding(
             v17,
             (hkGeometryUtils::Node::Triangle *)&other,
             (int *)&retaddr)
        || v18
        && hkGeometryUtils::Node::Edge::hasTriangleIgnoreWinding(
             v18,
             (hkGeometryUtils::Node::Triangle *)&other,
             (int *)&retaddr) )
      {
        if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 4);
        v5->m_data[v5->m_size++] = (signed int)retaddr;
        LODWORD(i) = i + 1;
      }
      else
      {
        v69 = v16;
        v19 = triangleIndex;
        v67 = v12;
        v68 = v14;
        hkGeometryUtils::Node::Triangle::Triangle((hkGeometryUtils::Node::Triangle *)&other, v12, v14, c);
        v20 = 0i64;
        v21 = 1;
        do
        {
          v22 = *(&v67 + v20);
          v23 = *(&v67 + v21 % 3);
          hkGeometryUtils::Node::addEdge(
            &array[v22],
            *(&v67 + v21 % 3),
            (hkGeometryUtils::Node::Triangle *)&other,
            v19,
            0);
          hkGeometryUtils::Node::addEdge(&array[v23], v22, (hkGeometryUtils::Node::Triangle *)&other, v19, 1);
          ++v20;
          ++v21;
        }
        while ( v20 < 3 );
        if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 4);
        v24 = v65;
        v5->m_data[v5->m_size++] = v19;
        v25 = triangleIndex;
        v26 = (int *)((char *)&v6->m_triangles.m_data->m_a + v24);
        if ( triangleIndex == (v61 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v59, 16);
          v25 = triangleIndex;
        }
        v27 = &v59[4 * v25];
        *v27 = *v26;
        v27[1] = v26[1];
        v27[2] = v26[2];
        v27[3] = v26[3];
        ++triangleIndex;
      }
      v10 = v65 + 16;
      ++v74;
      v65 += 16i64;
    }
    while ( v74 < v6->m_triangles.m_size );
  }
  else
  {
    if ( v6->m_triangles.m_size <= 0u )
      goto LABEL_49;
    v28 = 0i64;
    v65 = 0i64;
    do
    {
      v29 = (unsigned int *)((char *)v6->m_triangles.m_data + v28);
      hkGeometryUtils::Node::Triangle::Triangle((hkGeometryUtils::Node::Triangle *)&other, *v29, v29[1], v29[2]);
      v30 = (signed int)*v29;
      v31 = array;
      v32 = (signed int)v29[1];
      v33 = hkGeometryUtils::Node::findEdge(&array[v30], v29[1]);
      v34 = (signed int)v29[2];
      *(_QWORD *)&other.m_edges.m_size = v33;
      c = v34;
      v35 = hkGeometryUtils::Node::findEdge(&v31[v32], v34);
      v36 = hkGeometryUtils::Node::findEdge(&v31[v34], v30);
      if ( *(_QWORD *)&other.m_edges.m_size
        && hkGeometryUtils::Node::Edge::hasTriangleSameWinding(
             *(hkGeometryUtils::Node::Edge **)&other.m_edges.m_size,
             (hkGeometryUtils::Node::Triangle *)&other,
             (int *)&retaddr)
        || v35
        && hkGeometryUtils::Node::Edge::hasTriangleSameWinding(
             v35,
             (hkGeometryUtils::Node::Triangle *)&other,
             (int *)&retaddr)
        || v36
        && hkGeometryUtils::Node::Edge::hasTriangleSameWinding(
             v36,
             (hkGeometryUtils::Node::Triangle *)&other,
             (int *)&retaddr) )
      {
        if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 4);
        v5->m_data[v5->m_size++] = (signed int)retaddr;
        LODWORD(i) = i + 1;
      }
      else
      {
        v69 = v34;
        v37 = triangleIndex;
        v67 = v30;
        v68 = v32;
        hkGeometryUtils::Node::Triangle::Triangle((hkGeometryUtils::Node::Triangle *)&other, v30, v32, c);
        v38 = 0i64;
        v39 = 1;
        do
        {
          v40 = *(&v67 + v38);
          v41 = *(&v67 + v39 % 3);
          hkGeometryUtils::Node::addEdge(
            &array[v40],
            *(&v67 + v39 % 3),
            (hkGeometryUtils::Node::Triangle *)&other,
            v37,
            0);
          hkGeometryUtils::Node::addEdge(&array[v41], v40, (hkGeometryUtils::Node::Triangle *)&other, v37, 1);
          ++v38;
          ++v39;
        }
        while ( v38 < 3 );
        if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 4);
        v42 = v65;
        v5->m_data[v5->m_size++] = v37;
        v43 = triangleIndex;
        v44 = (int *)((char *)&v6->m_triangles.m_data->m_a + v42);
        if ( triangleIndex == (v61 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v59, 16);
          v43 = triangleIndex;
        }
        v45 = &v59[4 * v43];
        *v45 = *v44;
        v45[1] = v44[1];
        v45[2] = v44[2];
        v45[3] = v44[3];
        ++triangleIndex;
      }
      v28 = v65 + 16;
      ++v74;
      v65 += 16i64;
    }
    while ( v74 < v6->m_triangles.m_size );
  }
  v46 = i;
  if ( (signed int)i > 0 )
  {
    hkErrStream::hkErrStream((hkErrStream *)&other, &buf, 512);
    v47 = v6->m_triangles.m_size;
    v48 = hkOstream::operator<<((hkOstream *)&other, "Removed ");
    v49 = hkOstream::operator<<(v48, v46, (int)v48);
    v50 = hkOstream::operator<<(v49, " duplicate triangles out of a total of ");
    v51 = hkOstream::operator<<(v50, v47, (int)v50);
    hkOstream::operator<<(v51, " triangles.");
    hkError::messageReport(-1, &buf, "Misc\\hkGeometryUtils.cpp", 679);
    hkOstream::~hkOstream((hkOstream *)&other);
  }
LABEL_49:
  if ( (v6->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) < (signed int)triangleIndex )
  {
    if ( v6->m_triangles.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v6->m_triangles.m_data,
        16 * v6->m_triangles.m_capacityAndFlags);
    LODWORD(i) = 16 * triangleIndex;
    v6->m_triangles.m_data = (hkGeometry::Triangle *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                       (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                       (int *)&i);
    v6->m_triangles.m_capacityAndFlags = (signed int)i / 16;
  }
  v52 = (signed int)triangleIndex;
  v53 = v6->m_triangles.m_data;
  v6->m_triangles.m_size = triangleIndex;
  v54 = v52;
  if ( (signed int)v52 > 0 )
  {
    v55 = v59;
    do
    {
      v56 = *v55;
      ++v53;
      v55 += 4;
      v53[-1].m_a = v56;
      v53[-1].m_b = *(v55 - 3);
      v53[-1].m_c = *(v55 - 2);
      v53[-1].m_material = *(v55 - 1);
      --v54;
    }
    while ( v54 );
  }
  v57 = v63 - 1;
  if ( v63 - 1 >= 0 )
  {
    v58 = &array[v57];
    do
    {
      hkGeometryUtils::Node::~Node(v58);
      --v58;
      --v57;
    }
    while ( v57 >= 0 );
  }
  v63 = 0;
  if ( v64 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      24 * (v64 & 0x3FFFFFFF));
  array = 0i64;
  triangleIndex = 0;
  v64 = 2147483648;
  if ( v61 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v59,
      16 * v61);
}

// File Line: 689
// RVA: 0xC9EFA0
void __fastcall hkGeometryUtils::createCapsuleGeometry(hkVector4f *start, hkVector4f *end, float radius, int heightSamples)
{
  __int64 v4; // rbx
  int v5; // er14
  unsigned int v6; // er9
  signed int v7; // er15
  int v8; // er8
  __m128 v9; // xmm9
  __m128 v10; // xmm14
  __m128 v11; // xmm15
  __m128 v12; // xmm12
  __m128 v13; // xmm4
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm5
  bool v17; // cf
  bool v18; // zf
  __m128 v19; // xmm5
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  __m128 v22; // xmm12
  __m128 v23; // xmm1
  __m128 v24; // xmm4
  __m128 v25; // xmm11
  __m128 v26; // xmm11
  __m128 v27; // xmm1
  __m128 v28; // xmm2
  __m128 v29; // xmm1
  __m128 v30; // xmm11
  __m128 v31; // xmm13
  __m128 v32; // xmm13
  __m128 v33; // xmm2
  __m128 v34; // xmm10
  int v35; // er13
  __m128 v36; // xmm15
  int v37; // eax
  __m128 v38; // xmm1
  __m128 v39; // xmm14
  __m128 v40; // xmm7
  __m128 v41; // xmm1
  __m128 v42; // xmm6
  __m128 v43; // xmm4
  __m128 v44; // xmm2
  int v45; // esi
  __m128 v46; // xmm2
  __m128 v47; // xmm1
  __m128 v48; // xmm0
  __m128 v49; // xmm2
  __m128 v50; // xmm2
  __m128 v51; // xmm5
  __m128 v52; // xmm1
  __m128 v53; // xmm5
  __m128 v54; // xmm3
  __m128 v55; // xmm6
  __m128 v56; // xmm0
  signed int v57; // edi
  __m128 v58; // xmm1
  __m128 v59; // xmm4
  __m128 v60; // xmm3
  __m128 v61; // xmm6
  __m128 v62; // xmm6
  __m128 v63; // xmm9
  __m128 v64; // xmm10
  __m128 v65; // xmm0
  int v66; // ecx
  __m128 v67; // xmm1
  __m128 v68; // xmm4
  __m128 v69; // xmm3
  __m128 v70; // xmm5
  __m128 v71; // xmm5
  __m128 v72; // xmm7
  __m128 v73; // xmm2
  int v74; // esi
  __m128 v75; // xmm2
  __m128 v76; // xmm1
  __m128 v77; // xmm4
  __m128 v78; // xmm14
  signed int v79; // edi
  __m128 v80; // xmm6
  __m128 v81; // xmm10
  __m128 v82; // xmm6
  __m128 v83; // xmm0
  int v84; // ecx
  __m128 v85; // xmm1
  __m128 v86; // xmm4
  __m128 v87; // xmm3
  __m128 v88; // xmm5
  __m128 v89; // xmm5
  __m128 v90; // xmm7
  signed int v91; // esi
  __m128 v92; // xmm14
  __m128 v93; // xmm1
  signed int v94; // edi
  __m128 v95; // xmm1
  __m128 v96; // xmm4
  __m128 v97; // xmm3
  __m128 v98; // xmm6
  __m128 v99; // xmm6
  __m128 v100; // xmm9
  __m128 v101; // xmm14
  __m128 v102; // xmm10
  __m128 v103; // xmm0
  int v104; // ecx
  __m128 v105; // xmm1
  __m128 v106; // xmm4
  __m128 v107; // xmm3
  __m128 v108; // xmm5
  __m128 v109; // xmm5
  __m128 v110; // xmm7
  __m128 v111; // xmm8
  __m128 v112; // xmm6
  int v113; // er8
  __m128 *v114; // rcx
  __int64 v115; // rdx
  __m128 v116; // xmm1
  int v117; // ecx
  signed int v118; // edi
  signed int v119; // er12
  signed int v120; // esi
  __int64 v121; // r15
  _DWORD *v122; // rax
  __int64 v123; // rax
  __int64 v124; // r13
  int v125; // esi
  int v126; // er14
  int v127; // er15
  int *v128; // rax
  int v129; // ecx
  int *v130; // rax
  __int64 v131; // r14
  int v132; // er15
  int v133; // esi
  int *v134; // rax
  __m128 *array; // [rsp+30h] [rbp-98h]
  int v136; // [rsp+38h] [rbp-90h]
  int v137; // [rsp+3Ch] [rbp-8Ch]
  __m256i a; // [rsp+40h] [rbp-88h]
  __m128 v139; // [rsp+60h] [rbp-68h]
  __m128 v140; // [rsp+70h] [rbp-58h]
  hkSimdFloat32 v141; // [rsp+88h] [rbp-40h]
  __m128 v142; // [rsp+98h] [rbp-30h]
  __m128 v143; // [rsp+A8h] [rbp-20h]
  hkVector4f axis; // [rsp+B8h] [rbp-10h]
  __m128 v145; // [rsp+C8h] [rbp+0h]
  __m128 v146; // [rsp+D8h] [rbp+10h]
  hkSimdFloat32 angle; // [rsp+E8h] [rbp+20h]
  __int64 v148; // [rsp+1D8h] [rbp+110h]
  unsigned int v149; // [rsp+1E8h] [rbp+120h]
  hkResult result; // [rsp+1F8h] [rbp+130h]
  __m128 *vars0; // [rsp+200h] [rbp+138h]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *retaddr; // [rsp+208h] [rbp+140h]

  v4 = (unsigned int)result.m_enum;
  v5 = heightSamples;
  v6 = 2147483648;
  v7 = (signed int)result.m_enum >> 1;
  array = 0i64;
  v8 = 0;
  v136 = 0;
  v137 = 2147483648;
  v9 = transform.m_quad;
  v10 = start->m_quad;
  v11 = end->m_quad;
  v143 = transform.m_quad;
  v12 = _mm_sub_ps(v11, v10);
  v13 = _mm_mul_ps(v12, v12);
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  v15 = _mm_rsqrt_ps(v14);
  v16 = _mm_andnot_ps(
          _mm_cmpleps(v14, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v15, v14), v15)),
              _mm_mul_ps(*(__m128 *)_xmm, v15)),
            v14));
  v145 = v16;
  v17 = v16.m128_f32[0] < 0.0;
  v18 = v16.m128_f32[0] == 0.0;
  v19 = stru_141A71280.m_quad;
  if ( v17
    || v18
    || (v20 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
                _mm_shuffle_ps(v13, v13, 170)),
        v21 = _mm_rsqrt_ps(v20),
        result.m_enum = LODWORD(FLOAT_0_99998999),
        v22 = _mm_mul_ps(
                v12,
                _mm_andnot_ps(
                  _mm_cmpleps(v20, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                    _mm_mul_ps(*(__m128 *)_xmm, v21)))),
        v23 = _mm_mul_ps(v22, stru_141A71280.m_quad),
        COERCE_FLOAT((unsigned int)(2
                                  * COERCE_SIGNED_INT(
                                      (float)(COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 85))
                                            + COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 0)))
                                    + COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 170)))) >> 1) >= COERCE_FLOAT(
                                                                                               _mm_shuffle_ps(
                                                                                                 (__m128)LODWORD(FLOAT_0_99998999),
                                                                                                 (__m128)LODWORD(FLOAT_0_99998999),
                                                                                                 0))) )
  {
    v22 = stru_141A71280.m_quad;
    v30 = direction.m_quad;
    v32 = transform.m_quad;
  }
  else
  {
    v24 = _mm_shuffle_ps(v22, v22, 201);
    v25 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(stru_141A71280.m_quad, stru_141A71280.m_quad, 201), v22),
            _mm_mul_ps(v24, stru_141A71280.m_quad));
    v26 = _mm_shuffle_ps(v25, v25, 201);
    v27 = _mm_mul_ps(v26, v26);
    v28 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
            _mm_shuffle_ps(v27, v27, 170));
    v29 = _mm_rsqrt_ps(v28);
    v30 = _mm_mul_ps(
            v26,
            _mm_andnot_ps(
              _mm_cmpleps(v28, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v29, v28), v29)),
                _mm_mul_ps(v29, *(__m128 *)_xmm))));
    v31 = _mm_sub_ps(_mm_mul_ps(v30, v24), _mm_mul_ps(_mm_shuffle_ps(v30, v30, 201), v22));
    v32 = _mm_shuffle_ps(v31, v31, 201);
  }
  v33 = (__m128)xmmword_141A711B0;
  v34 = v145;
  v35 = v5 + 2 * v7;
  v36 = _mm_mul_ps(_mm_add_ps(v11, v10), (__m128)xmmword_141A711B0);
  _mm_store_si128((__m128i *)&v139.m128_u16[4], (__m128i)stru_141A71280.m_quad);
  axis.m_quad = _mm_mul_ps(direction.m_quad, g_vectorfConstants[0]);
  v37 = v4 * (v35 - 1) + 2;
  v38 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)0i64, v34), (__m128)xmmword_141A711B0), stru_141A71280.m_quad);
  v39 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v38);
  v142 = v38;
  v141.m_real = _mm_sub_ps(v39, v38);
  if ( v37 > 0 )
  {
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v37, 16);
    v6 = v137;
    v8 = v136;
    v19 = stru_141A71280.m_quad;
    v33 = (__m128)xmmword_141A711B0;
  }
  v40 = _mm_shuffle_ps((__m128)v149, (__m128)v149, 0);
  *(__m128 *)&a.m256i_u64[2] = v40;
  v41 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v34, v33), v40), v19);
  v42 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v41, v41, 85), v30), _mm_mul_ps(_mm_shuffle_ps(v41, v41, 0), v32)),
            _mm_mul_ps(_mm_shuffle_ps(v41, v41, 170), v22)),
          v36);
  if ( v8 == (v6 & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
    v8 = v136;
  }
  v43 = (__m128)_xmm;
  v44 = 0i64;
  v44.m128_f32[0] = (float)v7;
  v45 = v7 - 1;
  v46 = _mm_shuffle_ps(v44, v44, 0);
  array[v8] = v42;
  ++v136;
  v47 = _mm_rcp_ps(v46);
  v48 = _mm_mul_ps(v47, v46);
  v49 = 0i64;
  v49.m128_f32[0] = (float)(signed int)v4;
  v50 = _mm_shuffle_ps(v49, v49, 0);
  v51 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v48), v47);
  v52 = _mm_rcp_ps(v50);
  v53 = _mm_mul_ps(v51, (__m128)xmmword_141A713C0);
  v146 = v53;
  v54 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v52, v50)), v52), (__m128)xmmword_141A713F0);
  v139 = v54;
  if ( v7 - 1 >= 0 )
  {
    v55 = _mm_shuffle_ps(transform.m_quad, transform.m_quad, 201);
    *(__m128 *)&a.m256i_u64[1] = v55;
    do
    {
      v56 = 0i64;
      v56.m128_f32[0] = (float)v45;
      angle.m_real = _mm_mul_ps(_mm_shuffle_ps(v56, v56, 0), v53);
      hkQuaternionf::setAxisAngle((hkQuaternionf *)&v140.m128_u16[4], &axis, &angle);
      v57 = 0;
      v58 = _mm_mul_ps(*(__m128 *)((char *)&v140 + 8), v9);
      v59 = _mm_shuffle_ps(*(__m128 *)((char *)&v140 + 8), *(__m128 *)((char *)&v140 + 8), 255);
      v60 = _mm_sub_ps(
              _mm_mul_ps(*(__m128 *)((char *)&v140 + 8), v55),
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)((char *)&v140 + 8), *(__m128 *)((char *)&v140 + 8), 201), v9));
      v61 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v58, v58, 85), _mm_shuffle_ps(v58, v58, 0)),
                    _mm_shuffle_ps(v58, v58, 170)),
                  *(__m128 *)((char *)&v140 + 8)),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v59, v59), (__m128)xmmword_141A711B0), v9)),
              _mm_mul_ps(_mm_shuffle_ps(v60, v60, 201), v59));
      v62 = _mm_add_ps(v61, v61);
      if ( (signed int)v4 > 0 )
      {
        v63 = v139;
        v64 = _mm_shuffle_ps(v62, v62, 201);
        do
        {
          v65 = 0i64;
          v65.m128_f32[0] = (float)v57;
          v140 = _mm_mul_ps(_mm_shuffle_ps(v65, v65, 0), v63);
          hkQuaternionf::setAxisAngle(
            (hkQuaternionf *)&a.m256i_u64[3],
            (hkVector4f *)&v139.m128_u16[4],
            (hkSimdFloat32 *)&v140);
          v66 = v136;
          v67 = _mm_mul_ps(*(__m128 *)&a.m256i_u64[3], v62);
          v68 = _mm_shuffle_ps(*(__m128 *)&a.m256i_u64[3], *(__m128 *)&a.m256i_u64[3], 255);
          v69 = _mm_sub_ps(
                  _mm_mul_ps(*(__m128 *)&a.m256i_u64[3], v64),
                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&a.m256i_u64[3], *(__m128 *)&a.m256i_u64[3], 201), v62));
          v70 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v67, v67, 85), _mm_shuffle_ps(v67, v67, 0)),
                        _mm_shuffle_ps(v67, v67, 170)),
                      *(__m128 *)&a.m256i_u64[3]),
                    _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v68, v68), (__m128)xmmword_141A711B0), v62)),
                  _mm_mul_ps(_mm_shuffle_ps(v69, v69, 201), v68));
          v71 = _mm_add_ps(_mm_mul_ps(_mm_add_ps(v70, v70), v40), v39);
          v72 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v71, v71, 85), v30),
                      _mm_mul_ps(_mm_shuffle_ps(v71, v71, 0), v32)),
                    _mm_mul_ps(_mm_shuffle_ps(v71, v71, 170), v22)),
                  v36);
          if ( v136 == (v137 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
            v66 = v136;
          }
          ++v57;
          array[v66] = v72;
          ++v136;
          v40 = *(__m128 *)&a.m256i_u64[2];
        }
        while ( v57 < (signed int)v4 );
        v9 = v143;
      }
      --v45;
      v55 = *(__m128 *)&a.m256i_u64[1];
      v53 = v146;
    }
    while ( v45 >= 0 );
    v54 = v139;
    v43 = (__m128)_xmm;
  }
  v73 = 0i64;
  v73.m128_f32[0] = (float)v5;
  v74 = v5 - 1;
  v75 = _mm_shuffle_ps(v73, v73, 0);
  v76 = _mm_rcp_ps(v75);
  v77 = _mm_mul_ps(_mm_sub_ps(v43, _mm_mul_ps(v76, v75)), v76);
  v140 = v77;
  if ( v5 - 1 > 0 )
  {
    v78 = v142;
    do
    {
      v79 = 0;
      if ( (signed int)v4 > 0 )
      {
        v80 = 0i64;
        v80.m128_f32[0] = (float)v74;
        v81 = _mm_shuffle_ps(v9, v9, 201);
        v82 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(v80, v80, 0), v77), v141.m_real), v78);
        do
        {
          v83 = 0i64;
          v83.m128_f32[0] = (float)v79;
          *(__m128 *)&a.m256i_u64[1] = _mm_mul_ps(_mm_shuffle_ps(v83, v83, 0), v54);
          hkQuaternionf::setAxisAngle(
            (hkQuaternionf *)&a.m256i_u64[3],
            (hkVector4f *)&v139.m128_u16[4],
            (hkSimdFloat32 *)&a.m256i_u64[1]);
          v84 = v136;
          v85 = _mm_mul_ps(*(__m128 *)&a.m256i_u64[3], v9);
          v86 = _mm_shuffle_ps(*(__m128 *)&a.m256i_u64[3], *(__m128 *)&a.m256i_u64[3], 255);
          v87 = _mm_sub_ps(
                  _mm_mul_ps(*(__m128 *)&a.m256i_u64[3], v81),
                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&a.m256i_u64[3], *(__m128 *)&a.m256i_u64[3], 201), v9));
          v88 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v85, v85, 85), _mm_shuffle_ps(v85, v85, 0)),
                        _mm_shuffle_ps(v85, v85, 170)),
                      *(__m128 *)&a.m256i_u64[3]),
                    _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v86, v86), (__m128)xmmword_141A711B0), v9)),
                  _mm_mul_ps(_mm_shuffle_ps(v87, v87, 201), v86));
          v89 = _mm_add_ps(_mm_mul_ps(_mm_add_ps(v88, v88), v40), v82);
          v90 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v89, v89, 85), v30),
                      _mm_mul_ps(_mm_shuffle_ps(v89, v89, 0), v32)),
                    _mm_mul_ps(_mm_shuffle_ps(v89, v89, 170), v22)),
                  v36);
          if ( v136 == (v137 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
            v84 = v136;
          }
          v54 = v139;
          ++v79;
          array[v84] = v90;
          ++v136;
          v40 = *(__m128 *)&a.m256i_u64[2];
        }
        while ( v79 < (signed int)v4 );
        v77 = v140;
      }
      v54 = v139;
      v40 = *(__m128 *)&a.m256i_u64[2];
      --v74;
    }
    while ( v74 > 0 );
  }
  v91 = 0;
  if ( v7 > 0 )
  {
    v92 = _mm_shuffle_ps(v9, v9, 201);
    *(__m128 *)((char *)&v140 + 8) = v92;
    do
    {
      v93 = 0i64;
      v93.m128_f32[0] = (float)v91;
      v141.m_real = _mm_mul_ps(_mm_sub_ps((__m128)0i64, _mm_shuffle_ps(v93, v93, 0)), v146);
      hkQuaternionf::setAxisAngle((hkQuaternionf *)&a.m256i_u64[1], &axis, &v141);
      v94 = 0;
      v95 = _mm_mul_ps(*(__m128 *)&a.m256i_u64[1], v9);
      v96 = _mm_shuffle_ps(*(__m128 *)&a.m256i_u64[1], *(__m128 *)&a.m256i_u64[1], 255);
      v97 = _mm_sub_ps(
              _mm_mul_ps(*(__m128 *)&a.m256i_u64[1], v92),
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&a.m256i_u64[1], *(__m128 *)&a.m256i_u64[1], 201), v9));
      v98 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v95, v95, 85), _mm_shuffle_ps(v95, v95, 0)),
                    _mm_shuffle_ps(v95, v95, 170)),
                  *(__m128 *)&a.m256i_u64[1]),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v96, v96), (__m128)xmmword_141A711B0), v9)),
              _mm_mul_ps(_mm_shuffle_ps(v97, v97, 201), v96));
      v99 = _mm_add_ps(v98, v98);
      if ( (signed int)v4 > 0 )
      {
        v100 = v139;
        v101 = *(__m128 *)&a.m256i_u64[2];
        v102 = _mm_shuffle_ps(v99, v99, 201);
        do
        {
          v103 = 0i64;
          v103.m128_f32[0] = (float)v94;
          *(__m128 *)&a.m256i_u64[3] = _mm_mul_ps(_mm_shuffle_ps(v103, v103, 0), v100);
          hkQuaternionf::setAxisAngle(
            (hkQuaternionf *)&v140,
            (hkVector4f *)&v139.m128_u16[4],
            (hkSimdFloat32 *)&a.m256i_u64[3]);
          v104 = v136;
          v105 = _mm_mul_ps(v140, v99);
          v106 = _mm_shuffle_ps(v140, v140, 255);
          v107 = _mm_sub_ps(_mm_mul_ps(v102, v140), _mm_mul_ps(_mm_shuffle_ps(v140, v140, 201), v99));
          v108 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v105, v105, 85), _mm_shuffle_ps(v105, v105, 0)),
                         _mm_shuffle_ps(v105, v105, 170)),
                       v140),
                     _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v106, v106), (__m128)xmmword_141A711B0), v99)),
                   _mm_mul_ps(_mm_shuffle_ps(v107, v107, 201), v106));
          v109 = _mm_add_ps(_mm_mul_ps(_mm_add_ps(v108, v108), v101), v142);
          v110 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v109, v109, 85), v30),
                       _mm_mul_ps(_mm_shuffle_ps(v109, v109, 0), v32)),
                     _mm_mul_ps(_mm_shuffle_ps(v109, v109, 170), v22)),
                   v36);
          if ( v136 == (v137 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
            v104 = v136;
          }
          ++v94;
          array[v104] = v110;
          ++v136;
        }
        while ( v94 < (signed int)v4 );
        v9 = v143;
        v92 = *(__m128 *)((char *)&v140 + 8);
      }
      ++v91;
    }
    while ( v91 < v7 );
  }
  v111 = _mm_mul_ps(
           _mm_sub_ps((__m128)0i64, _mm_add_ps(_mm_mul_ps(v145, (__m128)xmmword_141A711B0), *(__m128 *)&a.m256i_u64[2])),
           stru_141A71280.m_quad);
  v112 = _mm_add_ps(
           _mm_add_ps(
             _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v111, v111, 85), v30), _mm_mul_ps(_mm_shuffle_ps(v111, v111, 0), v32)),
             _mm_mul_ps(_mm_shuffle_ps(v111, v111, 170), v22)),
           v36);
  if ( v136 == (v137 & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
  v113 = 0;
  array[v136++] = v112;
  if ( v136 > 0 )
  {
    v114 = vars0;
    v115 = 0i64;
    do
    {
      ++v113;
      ++v115;
      v116 = array[v115 - 1];
      array[v115 - 1] = _mm_add_ps(
                          _mm_add_ps(
                            _mm_add_ps(
                              _mm_mul_ps(_mm_shuffle_ps(v116, v116, 85), v114[1]),
                              _mm_mul_ps(_mm_shuffle_ps(array[v115 - 1], v116, 0), *v114)),
                            _mm_mul_ps(_mm_shuffle_ps(v116, v116, 170), v114[2])),
                          v114[3]);
    }
    while ( v113 < v136 );
  }
  v117 = 0;
  v118 = 1;
  a.m256i_i64[0] = 0i64;
  a.m256i_i64[1] = 0x8000000000000000i64;
  v119 = 1;
  if ( (signed int)v4 > 0 )
  {
    v120 = 1;
    v121 = v4;
    do
    {
      if ( v117 == (a.m256i_i32[3] & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &a, 16);
        v117 = a.m256i_i32[2];
      }
      v122 = (_DWORD *)(a.m256i_i64[0] + 16i64 * v117);
      *v122 = 0;
      v122[1] = v120;
      v122[2] = v120 % (signed int)v4 + 1;
      v122[3] = -1;
      ++v120;
      v117 = a.m256i_i32[2]++ + 1;
      --v121;
    }
    while ( v121 );
  }
  v123 = (unsigned int)(v35 - 2);
  if ( v35 - 2 > 0 )
  {
    v148 = (unsigned int)(v35 - 2);
    do
    {
      if ( (signed int)v4 > 0 )
      {
        v124 = v4;
        do
        {
          v125 = v118 + v119 - 1;
          v126 = v118 % (signed int)v4 + v119;
          v127 = v126 + v4;
          if ( v117 == (a.m256i_i32[3] & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &a, 16);
            v117 = a.m256i_i32[2];
          }
          v128 = (int *)(a.m256i_i64[0] + 16i64 * v117);
          *v128 = v125;
          v128[1] = v125 + v4;
          v128[2] = v127;
          v128[3] = -1;
          v129 = a.m256i_i32[2] + 1;
          a.m256i_i32[2] = v129;
          if ( v129 == (a.m256i_i32[3] & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &a, 16);
            v129 = a.m256i_i32[2];
          }
          ++v118;
          v130 = (int *)(a.m256i_i64[0] + 16i64 * v129);
          *v130 = v126;
          v130[1] = v125;
          v130[2] = v127;
          v130[3] = -1;
          v117 = a.m256i_i32[2]++ + 1;
          --v124;
        }
        while ( v124 );
        v123 = v148;
        v118 = 1;
      }
      v119 += v4;
      v148 = --v123;
    }
    while ( v123 );
  }
  if ( (signed int)v4 > 0 )
  {
    v131 = v4;
    do
    {
      v132 = v118 + v119 - 1;
      v133 = v119 + v118 % (signed int)v4;
      if ( v117 == (a.m256i_i32[3] & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &a, 16);
        v117 = a.m256i_i32[2];
      }
      ++v118;
      v134 = (int *)(a.m256i_i64[0] + 16i64 * v117);
      *v134 = v133;
      v134[1] = v132;
      v134[2] = v119 + v4;
      v134[3] = -1;
      v117 = a.m256i_i32[2]++ + 1;
      --v131;
    }
    while ( v131 );
  }
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    retaddr + 1,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&array);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    retaddr + 2,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&a);
  a.m256i_i32[2] = 0;
  if ( a.m256i_i32[3] >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      (void *)a.m256i_i64[0],
      16 * a.m256i_i32[3]);
  a.m256i_i64[0] = 0i64;
  a.m256i_i32[3] = 2147483648;
  v136 = 0;
  if ( v137 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * v137);
}

// File Line: 922
// RVA: 0xC9FC90
void __fastcall hkGeometryUtils::createTaperedCapsuleGeometry(hkVector4f *start, hkVector4f *end, float startRadius, float endRadius)
{
  __int64 v4; // rbx
  __m128 v5; // xmm5
  hkVector4f *v6; // rsi
  unsigned int v7; // ecx
  signed int v8; // er15
  hkVector4f *v9; // rdi
  __m128 v10; // xmm1
  __m128 v11; // xmm15
  __m128 v12; // xmm4
  __m128 v13; // xmm11
  __m128 v14; // xmm7
  __m128 v15; // xmm15
  __m128 v16; // xmm1
  __m128 v17; // xmm11
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  __m128 v20; // xmm2
  __m128 v21; // xmm8
  __m128 v22; // xmm11
  __m128 v23; // xmm8
  __m128 v24; // xmm1
  __m128 v25; // xmm3
  __m128 v26; // xmm2
  __m128 v27; // xmm11
  __m128 v28; // xmm4
  __m128 v29; // xmm13
  __m128 v30; // xmm12
  __m128 v31; // xmm12
  __m128 v32; // xmm1
  __m128 v33; // xmm3
  __m128 v34; // xmm2
  __m128 v35; // xmm12
  __m128 v36; // xmm13
  __m128 v37; // xmm13
  __m128 v38; // xmm2
  signed int v39; // er14
  int v40; // er13
  __m128 v41; // xmm14
  int v42; // er9
  __m128 v43; // xmm1
  __m128 v44; // xmm6
  __m128 v45; // xmm1
  __m128 v46; // xmm3
  __m128 v47; // xmm1
  __m128 v48; // xmm3
  __m128 v49; // xmm2
  __m128 v50; // xmm1
  __m128 v51; // xmm9
  __m128 v52; // xmm7
  __m128 v53; // xmm6
  __m128 v54; // xmm2
  __m128 v55; // xmm5
  __m128 v56; // xmm4
  __m128 v57; // xmm3
  __m128 v58; // xmm2
  __m128 v59; // xmm3
  int v60; // esi
  __m128 v61; // xmm1
  __m128 v62; // xmm1
  __m128 v63; // xmm0
  __m128 v64; // xmm2
  __m128 v65; // xmm4
  __m128 v66; // xmm1
  __m128 v67; // xmm4
  __m128 v68; // xmm1
  __m128 v69; // xmm0
  __m128 v70; // xmm8
  __m128 v71; // xmm0
  __m128 v72; // xmm2
  __m128 v73; // xmm2
  signed int v74; // edi
  __m128 v75; // xmm1
  __m128 v76; // xmm5
  __m128 v77; // xmm4
  __m128 v78; // xmm7
  __m128 v79; // xmm7
  __m128 v80; // xmm9
  __m128 v81; // xmm0
  int v82; // ecx
  __m128 v83; // xmm1
  __m128 v84; // xmm4
  __m128 v85; // xmm3
  __m128 v86; // xmm5
  __m128 v87; // xmm5
  __m128 v88; // xmm6
  __m128 v89; // xmm6
  __m128 v90; // xmm1
  int v91; // esi
  __m128 v92; // xmm1
  __m128 v93; // xmm2
  __m128 v94; // xmm0
  __m128 v95; // xmm0
  __m128 v96; // xmm3
  signed int v97; // edi
  __m128 v98; // xmm7
  __m128 v99; // xmm7
  __m128 v100; // xmm15
  __m128 v101; // xmm9
  __m128 v102; // xmm0
  int v103; // ecx
  __m128 v104; // xmm1
  __m128 v105; // xmm5
  __m128 v106; // xmm4
  __m128 v107; // xmm0
  __m128 v108; // xmm6
  __m128 v109; // xmm1
  __m128 v110; // xmm6
  signed int v111; // esi
  __m128 v112; // xmm15
  __m128 v113; // xmm1
  __m128 v114; // xmm1
  signed int v115; // edi
  __m128 v116; // xmm1
  __m128 v117; // xmm5
  __m128 v118; // xmm4
  __m128 v119; // xmm7
  __m128 v120; // xmm7
  __m128 v121; // xmm9
  __m128 v122; // xmm0
  int v123; // ecx
  __m128 v124; // xmm1
  __m128 v125; // xmm4
  __m128 v126; // xmm3
  __m128 v127; // xmm5
  __m128 v128; // xmm5
  __m128 v129; // xmm6
  __m128 v130; // xmm10
  __m128 v131; // xmm6
  int v132; // er8
  __int64 v133; // rdx
  __m128 v134; // xmm1
  int v135; // ecx
  signed int v136; // edi
  signed int v137; // er12
  signed int v138; // esi
  __int64 v139; // r15
  _DWORD *v140; // rax
  __int64 v141; // rax
  __int64 v142; // r13
  int v143; // esi
  int v144; // er14
  int v145; // er15
  int *v146; // rax
  int v147; // ecx
  int *v148; // rax
  __int64 v149; // r14
  int v150; // er15
  int v151; // esi
  int *v152; // rax
  __m128 *array; // [rsp+30h] [rbp-98h]
  int v154; // [rsp+38h] [rbp-90h]
  int v155; // [rsp+3Ch] [rbp-8Ch]
  char a[24]; // [rsp+40h] [rbp-88h]
  char v157[24]; // [rsp+58h] [rbp-70h]
  __m128 v158; // [rsp+70h] [rbp-58h]
  hkSimdFloat32 v159; // [rsp+88h] [rbp-40h]
  hkQuaternionf v160; // [rsp+98h] [rbp-30h]
  __m128 v161; // [rsp+A8h] [rbp-20h]
  __m128 v162; // [rsp+B8h] [rbp-10h]
  hkSimdFloat32 v163; // [rsp+C8h] [rbp+0h]
  __m128 v164; // [rsp+D8h] [rbp+10h]
  hkRotationf v165; // [rsp+E8h] [rbp+20h]
  __int64 v166; // [rsp+1F8h] [rbp+130h]
  unsigned int v167; // [rsp+208h] [rbp+140h]
  unsigned int v168; // [rsp+210h] [rbp+148h]
  int v169; // [rsp+218h] [rbp+150h]
  hkResult result; // [rsp+220h] [rbp+158h]
  __m128 *retaddr; // [rsp+228h] [rbp+160h]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v172; // [rsp+230h] [rbp+168h]

  v4 = (unsigned int)result.m_enum;
  v5 = stru_141A71280.m_quad;
  v6 = start;
  v7 = 2147483648;
  v8 = (signed int)result.m_enum >> 1;
  v9 = end;
  v10 = _mm_shuffle_ps((__m128)v168, (__m128)v168, 0);
  array = 0i64;
  v154 = 0;
  v155 = 2147483648;
  v11 = _mm_shuffle_ps((__m128)v167, (__m128)v167, 0);
  v12 = _mm_cmpltps(v10, v11);
  v13 = _mm_andnot_ps(v12, end->m_quad);
  v14 = _mm_or_ps(_mm_and_ps(v10, v12), _mm_andnot_ps(v12, v11));
  v15 = _mm_or_ps(_mm_and_ps(v11, v12), _mm_andnot_ps(v12, v10));
  v16 = _mm_and_ps(v12, end->m_quad);
  *(__m128 *)&v157[8] = v14;
  v17 = _mm_sub_ps(_mm_or_ps(v13, _mm_and_ps(v12, v6->m_quad)), _mm_or_ps(v16, _mm_andnot_ps(v12, v6->m_quad)));
  v18 = _mm_mul_ps(v17, v17);
  v19 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)), _mm_shuffle_ps(v18, v18, 170));
  v20 = _mm_rsqrt_ps(v19);
  v21 = _mm_andnot_ps(
          _mm_cmpleps(v19, (__m128)0i64),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)), _mm_mul_ps(v20, *(__m128 *)_xmm)));
  v22 = _mm_mul_ps(v17, v21);
  v23 = _mm_add_ps(_mm_mul_ps(v21, v19), *(__m128 *)&epsilon);
  v162 = v23;
  if ( v23.m128_f32[0] <= (float)(0.00000011920929 + 0.00000011920929) )
    goto LABEL_69;
  v24 = _mm_mul_ps(v22, v22);
  v25 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)), _mm_shuffle_ps(v24, v24, 170));
  v26 = _mm_rsqrt_ps(v25);
  result.m_enum = LODWORD(FLOAT_0_99998999);
  v27 = _mm_mul_ps(
          v22,
          _mm_andnot_ps(
            _mm_cmpleps(v25, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v25), v26)),
              _mm_mul_ps(v26, *(__m128 *)_xmm))));
  v28 = _mm_mul_ps(stru_141A71280.m_quad, v27);
  if ( COERCE_FLOAT((unsigned int)(2
                                 * COERCE_SIGNED_INT(
                                     (float)(COERCE_FLOAT(_mm_shuffle_ps(v28, v28, 85))
                                           + COERCE_FLOAT(_mm_shuffle_ps(v28, v28, 0)))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v28, v28, 170)))) >> 1) < COERCE_FLOAT(
                                                                                             _mm_shuffle_ps(
                                                                                               (__m128)LODWORD(FLOAT_0_99998999),
                                                                                               (__m128)LODWORD(FLOAT_0_99998999),
                                                                                               0)) )
  {
    v29 = _mm_shuffle_ps(v27, v27, 201);
    v30 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(stru_141A71280.m_quad, stru_141A71280.m_quad, 201), v27),
            _mm_mul_ps(v29, stru_141A71280.m_quad));
    v31 = _mm_shuffle_ps(v30, v30, 201);
    v32 = _mm_mul_ps(v31, v31);
    v33 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
            _mm_shuffle_ps(v32, v32, 170));
    v34 = _mm_rsqrt_ps(v33);
    v35 = _mm_mul_ps(
            v31,
            _mm_andnot_ps(
              _mm_cmpleps(v33, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v34, v33), v34)),
                _mm_mul_ps(v34, *(__m128 *)_xmm))));
    v36 = _mm_sub_ps(_mm_mul_ps(v29, v35), _mm_mul_ps(_mm_shuffle_ps(v35, v35, 201), v27));
    v37 = _mm_shuffle_ps(v36, v36, 201);
    goto LABEL_7;
  }
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v28, v28, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v28, v28, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v28, v28, 170))) >= 0.0 )
  {
LABEL_69:
    v35 = direction.m_quad;
    v37 = transform.m_quad;
    v27 = stru_141A71280.m_quad;
  }
  else
  {
    *(_OWORD *)&v157[16] = xmmword_141A713B0;
    hkRotationf::setAxisAngle(&v165, &transform, (hkSimdFloat32 *)&v157[16]);
    v7 = v155;
    v37 = v165.m_col0.m_quad;
    v35 = v165.m_col1.m_quad;
    v27 = v165.m_col2.m_quad;
    v5 = stru_141A71280.m_quad;
  }
LABEL_7:
  v38 = (__m128)xmmword_141A711B0;
  v39 = v169;
  v40 = v169 + 2 * v8;
  v41 = _mm_mul_ps(_mm_add_ps(v9->m_quad, v6->m_quad), (__m128)xmmword_141A711B0);
  v158 = _mm_mul_ps(_mm_mul_ps(v23, (__m128)xmmword_141A711B0), v5);
  v42 = v4 * (v40 - 1) + 2;
  *(__m128 *)&v157[16] = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v158);
  if ( (signed int)(v7 & 0x3FFFFFFF) < v42 )
  {
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v42, 16);
    v7 = v155;
    v5 = stru_141A71280.m_quad;
    v38 = (__m128)xmmword_141A711B0;
  }
  v43 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v23, v38), v15), v5);
  v44 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v43, v43, 85), v35), _mm_mul_ps(_mm_shuffle_ps(v43, v43, 0), v37)),
            _mm_mul_ps(_mm_shuffle_ps(v43, v43, 170), v27)),
          v41);
  if ( v154 == (v7 & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
  v45 = _mm_rcp_ps(v23);
  array[v154++] = v44;
  v46 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v45, v23)), v45), _mm_sub_ps(v15, v14));
  v47 = _mm_cmpltps(v46, query.m_quad);
  v48 = _mm_max_ps(g_vectorfConstants[0], _mm_or_ps(_mm_andnot_ps(v47, query.m_quad), _mm_and_ps(v47, v46)));
  *(__m128 *)&a[8] = v48;
  v49 = _mm_sub_ps(query.m_quad, _mm_mul_ps(v48, v48));
  v50 = _mm_rsqrt_ps(v49);
  *(__m128 *)&a[16] = _mm_andnot_ps(
                        _mm_cmpleps(v49, (__m128)0i64),
                        _mm_mul_ps(
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v50, v49), v50)),
                            _mm_mul_ps(v50, *(__m128 *)_xmm)),
                          v49));
  v51 = _mm_min_ps(
          _mm_max_ps((__m128)v48.m128_u32[0], *(__m128 *)_xmm_bf800000bf800000bf800000bf800000),
          *(__m128 *)_xmm);
  v52 = _mm_andnot_ps(*(__m128 *)_xmm, v51);
  v53 = _mm_cmpltps(v52, *(__m128 *)_xmm);
  v54 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v52), *(__m128 *)_xmm);
  v55 = _mm_cmpltps(*(__m128 *)_xmm, v52);
  v56 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v54), v55), _mm_andnot_ps(v55, v52));
  v57 = _mm_or_ps(_mm_andnot_ps(v55, _mm_mul_ps(v52, v52)), _mm_and_ps(v55, v54));
  v58 = _mm_add_ps(
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v57, *(__m128 *)coeff4), *(__m128 *)coeff3), v57),
                        *(__m128 *)coeff2),
                      v57),
                    *(__m128 *)coeff1),
                  v57),
                *(__m128 *)coeff0),
              v57),
            v56),
          v56);
  v59 = (__m128)_xmm;
  v60 = v8 - 1;
  v61 = 0i64;
  v61.m128_f32[0] = (float)v8;
  result.m_enum = (*(unsigned __int128 *)&_mm_andnot_ps(
                                            v53,
                                            _mm_or_ps(
                                              _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v58, v58)), v55),
                                              _mm_andnot_ps(v55, v58))) | v53.m128_i32[0] & v52.m128_i32[0]) ^ v51.m128_i32[0] & _xmm[0];
  v62 = _mm_shuffle_ps(v61, v61, 0);
  v63 = _mm_rcp_ps(v62);
  v64 = _mm_shuffle_ps((__m128)(unsigned int)result.m_enum, (__m128)(unsigned int)result.m_enum, 0);
  v164 = v64;
  v65 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v62, v63));
  v66 = 0i64;
  v66.m128_f32[0] = (float)(signed int)v4;
  v67 = _mm_mul_ps(v65, v63);
  v161 = v67;
  v68 = _mm_shuffle_ps(v66, v66, 0);
  v69 = _mm_rcp_ps(v68);
  v70 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v68, v69)), v69), (__m128)xmmword_141A713F0);
  if ( v8 - 1 >= 0 )
  {
    v71 = _mm_sub_ps((__m128)0i64, v64);
    *(__m128 *)v157 = v71;
    do
    {
      v72 = 0i64;
      v72.m128_f32[0] = (float)v60;
      v73 = _mm_mul_ps(_mm_shuffle_ps(v72, v72, 0), v67);
      v163.m_real = _mm_sub_ps(
                      (__m128)0i64,
                      _mm_add_ps(
                        _mm_mul_ps(_mm_sub_ps(query.m_quad, v73), v71),
                        _mm_mul_ps((__m128)xmmword_141A713C0, v73)));
      hkQuaternionf::setAxisAngle((hkQuaternionf *)&v158.m128_u16[4], &direction, &v163);
      v74 = 0;
      v75 = _mm_mul_ps(*(__m128 *)((char *)&v158 + 8), transform.m_quad);
      v76 = _mm_shuffle_ps(*(__m128 *)((char *)&v158 + 8), *(__m128 *)((char *)&v158 + 8), 255);
      v77 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(transform.m_quad, transform.m_quad, 201), *(__m128 *)((char *)&v158 + 8)),
              _mm_mul_ps(
                _mm_shuffle_ps(*(__m128 *)((char *)&v158 + 8), *(__m128 *)((char *)&v158 + 8), 201),
                transform.m_quad));
      v78 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v75, v75, 85), _mm_shuffle_ps(v75, v75, 0)),
                    _mm_shuffle_ps(v75, v75, 170)),
                  *(__m128 *)((char *)&v158 + 8)),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v76, v76), (__m128)xmmword_141A711B0), transform.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v77, v77, 201), v76));
      v79 = _mm_add_ps(v78, v78);
      if ( (signed int)v4 > 0 )
      {
        v80 = _mm_shuffle_ps(v79, v79, 201);
        do
        {
          v81 = 0i64;
          v81.m128_f32[0] = (float)v74;
          v159.m_real = _mm_mul_ps(_mm_shuffle_ps(v81, v81, 0), v70);
          hkQuaternionf::setAxisAngle(&v160, &stru_141A71280, &v159);
          v82 = v154;
          v83 = _mm_mul_ps(v160.m_vec.m_quad, v79);
          v84 = _mm_shuffle_ps(v160.m_vec.m_quad, v160.m_vec.m_quad, 255);
          v85 = _mm_sub_ps(
                  _mm_mul_ps(v80, v160.m_vec.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v160.m_vec.m_quad, v160.m_vec.m_quad, 201), v79));
          v86 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v83, v83, 85), _mm_shuffle_ps(v83, v83, 0)),
                        _mm_shuffle_ps(v83, v83, 170)),
                      v160.m_vec.m_quad),
                    _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v84, v84), (__m128)xmmword_141A711B0), v79)),
                  _mm_mul_ps(_mm_shuffle_ps(v85, v85, 201), v84));
          v87 = _mm_add_ps(_mm_mul_ps(_mm_add_ps(v86, v86), v15), v158);
          v88 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v87, v87, 85), v35),
                      _mm_mul_ps(_mm_shuffle_ps(v87, v87, 0), v37)),
                    _mm_mul_ps(_mm_shuffle_ps(v87, v87, 170), v27)),
                  v41);
          if ( v154 == (v155 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
            v82 = v154;
          }
          ++v74;
          array[v82] = v88;
          ++v154;
        }
        while ( v74 < (signed int)v4 );
      }
      --v60;
      v71 = *(__m128 *)v157;
      v67 = v161;
    }
    while ( v60 >= 0 );
    v59 = (__m128)_xmm;
  }
  v89 = *(__m128 *)&v157[8];
  v90 = 0i64;
  v90.m128_f32[0] = (float)v39;
  v91 = v39 - 1;
  v92 = _mm_shuffle_ps(v90, v90, 0);
  v158 = _mm_mul_ps(_mm_sub_ps((__m128)0i64, *(__m128 *)&v157[8]), *(__m128 *)&a[8]);
  v93 = _mm_sub_ps(v162, _mm_mul_ps(v15, *(__m128 *)&a[8]));
  v94 = _mm_mul_ps(*(__m128 *)&v157[8], *(__m128 *)&a[16]);
  *(__m128 *)&a[16] = _mm_mul_ps(v15, *(__m128 *)&a[16]);
  v159.m_real = v93;
  v160.m_vec.m_quad = v94;
  v95 = _mm_rcp_ps(v92);
  v96 = _mm_mul_ps(_mm_sub_ps(v59, _mm_mul_ps(v92, v95)), v95);
  *(__m128 *)((char *)&v158 + 8) = v96;
  if ( v39 - 1 > 0 )
  {
    do
    {
      v97 = 0;
      if ( (signed int)v4 > 0 )
      {
        v98 = 0i64;
        v98.m128_f32[0] = (float)v91;
        v99 = _mm_mul_ps(_mm_shuffle_ps(v98, v98, 0), v96);
        v100 = _mm_mul_ps(v99, *(__m128 *)&a[16]);
        v101 = _mm_mul_ps(v99, v93);
        do
        {
          v102 = 0i64;
          v102.m128_f32[0] = (float)v97;
          *(__m128 *)&a[8] = _mm_mul_ps(_mm_shuffle_ps(v102, v102, 0), v70);
          hkQuaternionf::setAxisAngle((hkQuaternionf *)v157, &stru_141A71280, (hkSimdFloat32 *)&a[8]);
          v103 = v154;
          v104 = _mm_mul_ps(*(__m128 *)v157, transform.m_quad);
          v105 = _mm_shuffle_ps(*(__m128 *)v157, *(__m128 *)v157, 255);
          v106 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(transform.m_quad, transform.m_quad, 201), *(__m128 *)v157),
                   _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)v157, *(__m128 *)v157, 201), transform.m_quad));
          v107 = _mm_sub_ps(query.m_quad, v99);
          v108 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v104, v104, 85), _mm_shuffle_ps(v104, v104, 0)),
                         _mm_shuffle_ps(v104, v104, 170)),
                       *(__m128 *)v157),
                     _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v105, v105), (__m128)xmmword_141A711B0), transform.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(v106, v106, 201), v105));
          v109 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v107, v158), v101), stru_141A71280.m_quad),
                     *(__m128 *)&v157[16]),
                   _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v107, v160.m_vec.m_quad), v100), _mm_add_ps(v108, v108)));
          v110 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v109, v109, 85), v35),
                       _mm_mul_ps(_mm_shuffle_ps(v109, v109, 0), v37)),
                     _mm_mul_ps(_mm_shuffle_ps(v109, v109, 170), v27)),
                   v41);
          if ( v154 == (v155 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
            v103 = v154;
          }
          ++v97;
          array[v103] = v110;
          ++v154;
        }
        while ( v97 < (signed int)v4 );
        v93 = v159.m_real;
        v96 = *(__m128 *)((char *)&v158 + 8);
      }
      --v91;
    }
    while ( v91 > 0 );
    v89 = *(__m128 *)&v157[8];
  }
  v111 = 0;
  if ( v8 > 0 )
  {
    v112 = v161;
    do
    {
      v113 = 0i64;
      v113.m128_f32[0] = (float)v111;
      v114 = _mm_mul_ps(_mm_shuffle_ps(v113, v113, 0), v112);
      *(__m128 *)&a[16] = _mm_add_ps(
                            _mm_mul_ps(_mm_sub_ps(query.m_quad, v114), v164),
                            _mm_mul_ps(v114, (__m128)xmmword_141A713C0));
      hkQuaternionf::setAxisAngle((hkQuaternionf *)&a[8], &direction, (hkSimdFloat32 *)&a[16]);
      v115 = 0;
      v116 = _mm_mul_ps(*(__m128 *)&a[8], transform.m_quad);
      v117 = _mm_shuffle_ps(*(__m128 *)&a[8], *(__m128 *)&a[8], 255);
      v118 = _mm_sub_ps(
               _mm_mul_ps(_mm_shuffle_ps(transform.m_quad, transform.m_quad, 201), *(__m128 *)&a[8]),
               _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&a[8], *(__m128 *)&a[8], 201), transform.m_quad));
      v119 = _mm_add_ps(
               _mm_add_ps(
                 _mm_mul_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v116, v116, 85), _mm_shuffle_ps(v116, v116, 0)),
                     _mm_shuffle_ps(v116, v116, 170)),
                   *(__m128 *)&a[8]),
                 _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v117, v117), (__m128)xmmword_141A711B0), transform.m_quad)),
               _mm_mul_ps(_mm_shuffle_ps(v118, v118, 201), v117));
      v120 = _mm_add_ps(v119, v119);
      if ( (signed int)v4 > 0 )
      {
        v121 = _mm_shuffle_ps(v120, v120, 201);
        do
        {
          v122 = 0i64;
          v122.m128_f32[0] = (float)v115;
          *(__m128 *)v157 = _mm_mul_ps(_mm_shuffle_ps(v122, v122, 0), v70);
          hkQuaternionf::setAxisAngle((hkQuaternionf *)&v158, &stru_141A71280, (hkSimdFloat32 *)v157);
          v123 = v154;
          v124 = _mm_mul_ps(v158, v120);
          v125 = _mm_shuffle_ps(v158, v158, 255);
          v126 = _mm_sub_ps(_mm_mul_ps(v121, v158), _mm_mul_ps(_mm_shuffle_ps(v158, v158, 201), v120));
          v127 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v124, v124, 85), _mm_shuffle_ps(v124, v124, 0)),
                         _mm_shuffle_ps(v124, v124, 170)),
                       v158),
                     _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v125, v125), (__m128)xmmword_141A711B0), v120)),
                   _mm_mul_ps(_mm_shuffle_ps(v126, v126, 201), v125));
          v128 = _mm_add_ps(_mm_mul_ps(_mm_add_ps(v127, v127), v89), *(__m128 *)&v157[16]);
          v129 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v128, v128, 85), v35),
                       _mm_mul_ps(_mm_shuffle_ps(v128, v128, 0), v37)),
                     _mm_mul_ps(_mm_shuffle_ps(v128, v128, 170), v27)),
                   v41);
          if ( v154 == (v155 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
            v123 = v154;
          }
          ++v115;
          array[v123] = v129;
          ++v154;
          v89 = *(__m128 *)&v157[8];
        }
        while ( v115 < (signed int)v4 );
      }
      v89 = *(__m128 *)&v157[8];
      ++v111;
    }
    while ( v111 < v8 );
  }
  v130 = _mm_mul_ps(
           _mm_sub_ps((__m128)0i64, _mm_add_ps(_mm_mul_ps(v162, (__m128)xmmword_141A711B0), *(__m128 *)&v157[8])),
           stru_141A71280.m_quad);
  v131 = _mm_add_ps(
           _mm_add_ps(
             _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v130, v130, 85), v35), _mm_mul_ps(_mm_shuffle_ps(v130, v130, 0), v37)),
             _mm_mul_ps(_mm_shuffle_ps(v130, v130, 170), v27)),
           v41);
  if ( v154 == (v155 & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
  v132 = 0;
  array[v154++] = v131;
  if ( v154 > 0 )
  {
    v133 = 0i64;
    do
    {
      ++v132;
      ++v133;
      v134 = array[v133 - 1];
      array[v133 - 1] = _mm_add_ps(
                          _mm_add_ps(
                            _mm_add_ps(
                              _mm_mul_ps(_mm_shuffle_ps(v134, v134, 85), retaddr[1]),
                              _mm_mul_ps(_mm_shuffle_ps(array[v133 - 1], v134, 0), *retaddr)),
                            _mm_mul_ps(_mm_shuffle_ps(v134, v134, 170), retaddr[2])),
                          retaddr[3]);
    }
    while ( v132 < v154 );
  }
  v135 = 0;
  v136 = 1;
  *(_QWORD *)a = 0i64;
  *(_DWORD *)&a[12] = 2147483648;
  *(_DWORD *)&a[8] = 0;
  v137 = 1;
  if ( (signed int)v4 > 0 )
  {
    v138 = 1;
    v139 = v4;
    do
    {
      if ( v135 == (*(_DWORD *)&a[12] & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, a, 16);
        v135 = *(_DWORD *)&a[8];
      }
      v140 = (_DWORD *)(*(_QWORD *)a + 16i64 * v135);
      *v140 = 0;
      v140[1] = v138;
      v140[2] = v138 % (signed int)v4 + 1;
      v140[3] = -1;
      ++v138;
      v135 = (*(_DWORD *)&a[8])++ + 1;
      --v139;
    }
    while ( v139 );
  }
  v141 = (unsigned int)(v40 - 2);
  if ( v40 - 2 > 0 )
  {
    v166 = (unsigned int)(v40 - 2);
    do
    {
      if ( (signed int)v4 > 0 )
      {
        v142 = v4;
        do
        {
          v143 = v136 + v137 - 1;
          v144 = v136 % (signed int)v4 + v137;
          v145 = v144 + v4;
          if ( v135 == (*(_DWORD *)&a[12] & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, a, 16);
            v135 = *(_DWORD *)&a[8];
          }
          v146 = (int *)(*(_QWORD *)a + 16i64 * v135);
          *v146 = v143;
          v146[1] = v143 + v4;
          v146[2] = v145;
          v146[3] = -1;
          v147 = *(_DWORD *)&a[8] + 1;
          *(_DWORD *)&a[8] = v147;
          if ( v147 == (*(_DWORD *)&a[12] & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, a, 16);
            v147 = *(_DWORD *)&a[8];
          }
          ++v136;
          v148 = (int *)(*(_QWORD *)a + 16i64 * v147);
          *v148 = v144;
          v148[1] = v143;
          v148[2] = v145;
          v148[3] = -1;
          v135 = (*(_DWORD *)&a[8])++ + 1;
          --v142;
        }
        while ( v142 );
        v141 = v166;
        v136 = 1;
      }
      v137 += v4;
      v166 = --v141;
    }
    while ( v141 );
  }
  if ( (signed int)v4 > 0 )
  {
    v149 = v4;
    do
    {
      v150 = v136 + v137 - 1;
      v151 = v137 + v136 % (signed int)v4;
      if ( v135 == (*(_DWORD *)&a[12] & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, a, 16);
        v135 = *(_DWORD *)&a[8];
      }
      ++v136;
      v152 = (int *)(*(_QWORD *)a + 16i64 * v135);
      *v152 = v151;
      v152[1] = v150;
      v152[2] = v137 + v4;
      v152[3] = -1;
      v135 = (*(_DWORD *)&a[8])++ + 1;
      --v149;
    }
    while ( v149 );
  }
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    v172 + 1,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&array);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    v172 + 2,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)a);
  *(_DWORD *)&a[8] = 0;
  if ( *(_DWORD *)&a[12] >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)a,
      16 * *(_DWORD *)&a[12]);
  *(_QWORD *)a = 0i64;
  *(_DWORD *)&a[12] = 2147483648;
  v154 = 0;
  if ( v155 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * v155);
}

// File Line: 1174
// RVA: 0xCA0C00
void __fastcall hkGeometryUtils::createCylinderGeometry(hkVector4f *top, hkVector4f *bottom, float radius, int numSides)
{
  __int64 v4; // r13
  hkVector4f *v5; // r14
  float v6; // xmm6_4
  __m128 v7; // xmm7
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm2
  __m128 v11; // xmm5
  __m128 v12; // xmm0
  __m128 v13; // xmm4
  __m128 v14; // xmm4
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __int64 v18; // rdi
  _DWORD *v19; // rbx
  int v20; // er9
  int v21; // eax
  int v22; // eax
  __int64 v23; // rdi
  int v24; // eax
  int v25; // er9
  int v26; // eax
  __m128 v27; // xmm6
  int v28; // eax
  unsigned __int64 v29; // rcx
  __int64 v30; // r15
  __m128 v31; // xmm6
  __int64 v32; // rsi
  __int64 v33; // rdi
  int v34; // er9
  int v35; // eax
  int v36; // eax
  __int64 v37; // rdi
  int v38; // er9
  int v39; // eax
  int v40; // eax
  __m128 v41; // xmm5
  __m128 v42; // xmm6
  __m128 v43; // xmm3
  __m128 v44; // xmm4
  __m128 v45; // xmm6
  hkResultEnum v46; // eax
  signed int v47; // er15
  signed int v48; // edi
  signed int v49; // esi
  int v50; // er14
  int v51; // er12
  signed int *v52; // rbx
  unsigned __int64 v53; // rcx
  __int64 v54; // r13
  int v55; // er9
  int v56; // eax
  int v57; // eax
  signed int *v58; // rax
  __int64 v59; // r13
  int v60; // er9
  int v61; // eax
  int v62; // eax
  signed int *v63; // rax
  signed int v64; // er15
  int v65; // esi
  int v66; // esi
  signed int *v67; // rbx
  __int64 v68; // r13
  int v69; // edi
  __int64 v70; // r14
  int v71; // eax
  int v72; // er9
  int v73; // eax
  signed int *v74; // rax
  int v75; // eax
  int sizeElem[4]; // [rsp+20h] [rbp-79h]
  hkVector4f v77; // [rsp+30h] [rbp-69h]
  hkQuaternionf v78; // [rsp+40h] [rbp-59h]
  hkQuaternionf quat; // [rsp+50h] [rbp-49h]
  hkResult result; // [rsp+F0h] [rbp+57h]
  hkResult v81; // [rsp+F8h] [rbp+5Fh]
  unsigned int v82; // [rsp+100h] [rbp+67h]
  unsigned int v83; // [rsp+108h] [rbp+6Fh]
  unsigned int v84; // [rsp+110h] [rbp+77h]
  signed int *v85; // [rsp+118h] [rbp+7Fh]

  v4 = v84;
  v5 = bottom;
  v6 = (float)(signed int)v84;
  *(float *)&result.m_enum = 1.0 / v6;
  v7 = _mm_mul_ps(
         _mm_shuffle_ps((__m128)COERCE_UNSIGNED_INT(1.0 / v6), (__m128)COERCE_UNSIGNED_INT(1.0 / v6), 0),
         _mm_sub_ps(top->m_quad, bottom->m_quad));
  v8 = _mm_mul_ps(v7, v7);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_rsqrt_ps(v9);
  v11 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmpleps(v9, (__m128)0i64),
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)), _mm_mul_ps(*(__m128 *)_xmm, v10))),
          v7);
  result.m_enum = (hkResultEnum)LODWORD(v11.m128_f32[0]);
  v78.m_vec.m_quad = v11;
  if ( COERCE_FLOAT((unsigned int)(2 * v11.m128_i32[0]) >> 1) <= 0.5 )
  {
    result.m_enum = (unsigned int)*(_OWORD *)&_mm_shuffle_ps(v11, v11, 85);
    if ( COERCE_FLOAT((unsigned int)(2 * result.m_enum) >> 1) <= 0.5 )
      v12 = transform.m_quad;
    else
      v12 = stru_141A71280.m_quad;
  }
  else
  {
    v12 = direction.m_quad;
  }
  v13 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v11), _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v12));
  v14 = _mm_shuffle_ps(v13, v13, 201);
  v15 = _mm_mul_ps(v14, v14);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v17 = _mm_rsqrt_ps(v16);
  *(__m128 *)sizeElem = _mm_mul_ps(
                          _mm_mul_ps(
                            _mm_andnot_ps(
                              _mm_cmpleps(v16, (__m128)0i64),
                              _mm_mul_ps(
                                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
                                _mm_mul_ps(*(__m128 *)_xmm, v17))),
                            v14),
                          _mm_shuffle_ps((__m128)v82, (__m128)v82, 0));
  hkQuaternionf::setAxisAngle(&v78, &v78.m_vec, 6.2831855 / (float)numSides);
  hkQuaternionf::setAxisAngle(&quat, &v78.m_vec, 0.0);
  v18 = v85[6];
  v19 = v85 + 4;
  v20 = v18 + 1;
  v21 = v85[7] & 0x3FFFFFFF;
  if ( v21 < (signed int)v18 + 1 )
  {
    v22 = 2 * v21;
    sizeElem[0] = 16;
    if ( v20 < v22 )
      v20 = v22;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v85 + 4,
      v20,
      sizeElem[0]);
  }
  ++v19[2];
  *(hkVector4f *)(*(_QWORD *)v19 + 16 * v18) = (hkVector4f)v5->m_quad;
  v23 = (signed int)v19[2];
  v24 = v19[3];
  *(float *)&result.m_enum = v6;
  v25 = v23 + 1;
  v26 = v24 & 0x3FFFFFFF;
  v27 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v6), (__m128)LODWORD(v6), 0), v7), v5->m_quad);
  if ( v26 < (signed int)v23 + 1 )
  {
    v28 = 2 * v26;
    sizeElem[0] = 16;
    if ( v25 < v28 )
      v25 = v28;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v19, v25, sizeElem[0]);
  }
  ++v19[2];
  *(__m128 *)(*(_QWORD *)v19 + 16 * v23) = v27;
  v29 = v83;
  if ( (signed int)v83 > 0 )
  {
    v30 = v83;
    do
    {
      hkVector4f::setRotatedDir(&v77, &quat, (hkVector4f *)sizeElem);
      v31 = _mm_add_ps(v5->m_quad, v77.m_quad);
      if ( (signed int)v4 > 0 )
      {
        v32 = v4;
        do
        {
          v33 = (signed int)v19[2];
          v34 = v33 + 1;
          v35 = v19[3] & 0x3FFFFFFF;
          if ( v35 >= (signed int)v33 + 1 )
          {
            *(float *)&result.m_enum = 0.0;
          }
          else
          {
            v36 = 2 * v35;
            sizeElem[0] = 16;
            if ( v34 < v36 )
              v34 = v36;
            hkArrayUtil::_reserve(
              &result,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              v19,
              v34,
              sizeElem[0]);
          }
          ++v19[2];
          *(__m128 *)(*(_QWORD *)v19 + 16 * v33) = v31;
          v31 = _mm_add_ps(v31, v7);
          --v32;
        }
        while ( v32 );
      }
      v37 = (signed int)v19[2];
      v38 = v37 + 1;
      v39 = v19[3] & 0x3FFFFFFF;
      if ( v39 >= (signed int)v37 + 1 )
      {
        v81.m_enum = 0;
      }
      else
      {
        v40 = 2 * v39;
        sizeElem[0] = 16;
        if ( v38 < v40 )
          v38 = v40;
        hkArrayUtil::_reserve(
          &v81,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          v19,
          v38,
          sizeElem[0]);
      }
      ++v19[2];
      *(__m128 *)(*(_QWORD *)v19 + 16 * v37) = v31;
      v41 = _mm_shuffle_ps(v78.m_vec.m_quad, v78.m_vec.m_quad, 255);
      v42 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v78.m_vec.m_quad, v78.m_vec.m_quad, 201), quat.m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(quat.m_vec.m_quad, quat.m_vec.m_quad, 201), v78.m_vec.m_quad));
      v43 = _mm_mul_ps(v78.m_vec.m_quad, quat.m_vec.m_quad);
      v44 = _mm_shuffle_ps(quat.m_vec.m_quad, quat.m_vec.m_quad, 255);
      v45 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v42, v42, 201), _mm_mul_ps(v78.m_vec.m_quad, v44)),
              _mm_mul_ps(quat.m_vec.m_quad, v41));
      quat.m_vec.m_quad = _mm_shuffle_ps(
                            v45,
                            _mm_unpackhi_ps(
                              v45,
                              _mm_sub_ps(
                                _mm_mul_ps(v41, v44),
                                _mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)),
                                  _mm_shuffle_ps(v43, v43, 170)))),
                            196);
      --v30;
    }
    while ( v30 );
    v29 = v83;
  }
  v46 = v4 + 1;
  v47 = 2;
  result.m_enum = v4 + 1;
  v48 = v4 + 3;
  v49 = 3;
  v50 = v4 + 4;
  v51 = v29 * (v4 + 1) + 2;
  if ( (signed int)v29 > 0 )
  {
    quat.m_vec.m_quad.m128_u64[0] = v29;
    do
    {
      if ( (signed int)v4 > 0 )
      {
        v52 = v85;
        v53 = (unsigned int)v4;
        v78.m_vec.m_quad.m128_u64[0] = (unsigned int)v4;
        do
        {
          v54 = v52[10];
          v55 = v54 + 1;
          v56 = v52[11] & 0x3FFFFFFF;
          if ( v56 >= (signed int)v54 + 1 )
          {
            v81.m_enum = 0;
          }
          else
          {
            v57 = 2 * v56;
            sizeElem[0] = 16;
            if ( v55 < v57 )
              v55 = v57;
            hkArrayUtil::_reserve(
              &v81,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              v52 + 8,
              v55,
              sizeElem[0]);
            v53 = v78.m_vec.m_quad.m128_u64[0];
          }
          ++v52[10];
          v58 = (signed int *)(*((_QWORD *)v52 + 4) + 16 * v54);
          *v58 = v47;
          v58[1] = v48;
          v58[2] = v49;
          v58[3] = -1;
          v59 = v52[10];
          v60 = v59 + 1;
          v61 = v52[11] & 0x3FFFFFFF;
          if ( v61 >= (signed int)v59 + 1 )
          {
            v77.m_quad.m128_i32[0] = 0;
          }
          else
          {
            v62 = 2 * v61;
            sizeElem[0] = 16;
            if ( v60 < v62 )
              v60 = v62;
            hkArrayUtil::_reserve(
              (hkResult *)&v77,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              v52 + 8,
              v60,
              sizeElem[0]);
            v53 = v78.m_vec.m_quad.m128_u64[0];
          }
          ++v52[10];
          ++v47;
          v63 = (signed int *)(*((_QWORD *)v52 + 4) + 16 * v59);
          *v63 = v49;
          v63[1] = v48;
          v63[2] = v50;
          ++v48;
          ++v49;
          ++v50;
          --v53;
          v63[3] = -1;
          v78.m_vec.m_quad.m128_u64[0] = v53;
        }
        while ( v53 );
        LODWORD(v4) = v84;
        v29 = quat.m_vec.m_quad.m128_u64[0];
      }
      ++v50;
      ++v47;
      ++v48;
      ++v49;
      if ( v50 >= v51 )
      {
        v48 += 2 - v51;
        v50 += 2 - v51;
      }
      quat.m_vec.m_quad.m128_u64[0] = --v29;
    }
    while ( v29 );
    v46 = result.m_enum;
    LODWORD(v29) = v83;
  }
  v64 = 0;
  do
  {
    v65 = 0;
    if ( v64 )
      v65 = v4;
    v66 = v65 + 2;
    if ( (signed int)v29 > 0 )
    {
      v67 = v85;
      v68 = (unsigned int)v29;
      do
      {
        v69 = v66 + v46;
        if ( v66 + v46 >= v51 )
          v69 += 2 - v51;
        v70 = v67[10];
        v71 = v67[11] & 0x3FFFFFFF;
        v72 = v70 + 1;
        if ( v64 )
        {
          if ( v71 >= v72 )
          {
            v81.m_enum = 0;
          }
          else
          {
            v73 = 2 * v71;
            sizeElem[0] = 16;
            if ( v72 < v73 )
              v72 = v73;
            hkArrayUtil::_reserve(
              &v81,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              v67 + 8,
              v72,
              sizeElem[0]);
          }
          ++v67[10];
          v74 = (signed int *)(*((_QWORD *)v67 + 4) + 16 * v70);
          *v74 = v64;
          v74[1] = v66;
          v74[2] = v69;
        }
        else
        {
          if ( v71 >= v72 )
          {
            v77.m_quad.m128_i32[0] = 0;
          }
          else
          {
            v75 = 2 * v71;
            sizeElem[0] = 16;
            if ( v72 < v75 )
              v72 = v75;
            hkArrayUtil::_reserve(
              (hkResult *)&v77,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              v67 + 8,
              v72,
              sizeElem[0]);
          }
          ++v67[10];
          v74 = (signed int *)(*((_QWORD *)v67 + 4) + 16 * v70);
          *v74 = 0;
          v74[1] = v69;
          v74[2] = v66;
        }
        v74[3] = -1;
        v46 = result.m_enum;
        v66 = v69;
        --v68;
      }
      while ( v68 );
      LODWORD(v4) = v84;
      LODWORD(v29) = v83;
    }
    v46 = result.m_enum;
    ++v64;
  }
  while ( v64 < 2 );
});
          }
          ++v67[10];
          v74 = (signed int *)(*((_QWORD *)v67 + 4) + 16 * v70);
          *v74 = 0;
          v74[1] = v69;
          v74[2] = v66;
        }
        v74[3

// File Line: 1314
// RVA: 0xCA12C0
void __fastcall hkGeometryUtils::createPlaneGeometry(hkVector4f *normal, hkVector4f *perpToNormal, hkVector4f *center, hkVector4f *extents, hkGeometry *geometryOut)
{
  hkGeometry *v5; // rdi
  hkVector4f *v6; // rbp
  hkVector4f *v7; // rsi
  hkVector4f *v8; // r14
  hkVector4f *v9; // r15
  int v10; // eax
  int v11; // eax
  int v12; // er9
  int v13; // eax
  int v14; // eax
  int v15; // er9
  __m128 v16; // xmm3
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  hkGeometry::Triangle *v19; // rax
  hkGeometry::Triangle *v20; // rax
  hkGeometry::Triangle *v21; // rax
  hkGeometry::Triangle *v22; // rax

  v5 = geometryOut;
  v6 = extents;
  v7 = center;
  v8 = perpToNormal;
  v9 = normal;
  v10 = geometryOut->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 < 5 )
  {
    v11 = 2 * v10;
    v12 = 5;
    if ( v11 > 5 )
      v12 = v11;
    hkArrayUtil::_reserve(
      (hkResult *)&geometryOut,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &geometryOut->m_vertices,
      v12,
      16);
  }
  v5->m_vertices.m_size = 5;
  v13 = v5->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v13 < 4 )
  {
    v14 = 2 * v13;
    v15 = 4;
    if ( v14 > 4 )
      v15 = v14;
    hkArrayUtil::_reserve(
      (hkResult *)&geometryOut,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v5->m_triangles,
      v15,
      16);
  }
  v5->m_triangles.m_size = 4;
  v16 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v8->m_quad, v8->m_quad, 201), v9->m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v9->m_quad, v9->m_quad, 201), v8->m_quad));
  v17 = _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v6->m_quad);
  v18 = _mm_mul_ps(v6->m_quad, v8->m_quad);
  v5->m_vertices.m_data->m_quad = _mm_add_ps(v7->m_quad, v17);
  v5->m_vertices.m_data->m_quad = _mm_add_ps(v5->m_vertices.m_data->m_quad, v18);
  v5->m_vertices.m_data[1].m_quad = _mm_add_ps(v7->m_quad, v17);
  v5->m_vertices.m_data[1].m_quad = _mm_sub_ps(v5->m_vertices.m_data[1].m_quad, v18);
  v5->m_vertices.m_data[2].m_quad = _mm_sub_ps(v7->m_quad, v17);
  v5->m_vertices.m_data[2].m_quad = _mm_add_ps(v5->m_vertices.m_data[2].m_quad, v18);
  v5->m_vertices.m_data[3].m_quad = _mm_sub_ps(v7->m_quad, v17);
  v5->m_vertices.m_data[3].m_quad = _mm_sub_ps(v5->m_vertices.m_data[3].m_quad, v18);
  v5->m_vertices.m_data[4] = (hkVector4f)v7->m_quad;
  v19 = v5->m_triangles.m_data;
  v19->m_a = 2;
  v19->m_b = 4;
  v19->m_c = 3;
  v19->m_material = -1;
  v20 = v5->m_triangles.m_data;
  v20[1].m_a = 0;
  v20[1].m_b = 4;
  v20[1].m_c = 2;
  v20[1].m_material = -1;
  v21 = v5->m_triangles.m_data;
  v21[2].m_a = 1;
  *(_QWORD *)&v21[2].m_b = 4i64;
  v21[2].m_material = -1;
  v22 = v5->m_triangles.m_data;
  v22[3].m_a = 3;
  v22[3].m_b = 4;
  v22[3].m_c = 1;
  v22[3].m_material = -1;
}

// File Line: 1348
// RVA: 0xCA2C10
hkSimdFloat32 *__fastcall determinant3x3(hkSimdFloat32 *result, hkVector4f *col0, hkVector4f *col1, hkVector4f *col2)
{
  hkSimdFloat32 *v4; // rax
  __m128 v5; // xmm2
  __m128 v6; // xmm2

  v4 = result;
  v5 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(col2->m_quad, col2->m_quad, 201), col1->m_quad),
         _mm_mul_ps(_mm_shuffle_ps(col1->m_quad, col1->m_quad, 201), col2->m_quad));
  v6 = _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), col0->m_quad);
  result->m_real = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)),
                     _mm_shuffle_ps(v6, v6, 170));
  return v4;
}

// File Line: 1355
// RVA: 0xCA19B0
void __fastcall hkGeometryUtils::computeVolume(hkGeometry *geometry, hkSimdFloat32 *volume)
{
  int v2; // er10
  hkGeometry *v3; // r11
  __int64 v4; // rbx
  hkGeometry::Triangle *v5; // r8
  hkVector4f *v6; // r9
  __int64 v7; // rcx
  __int64 v8; // rax
  __m128 v9; // xmm2
  __m128 v10; // xmm2

  v2 = 0;
  v3 = geometry;
  *volume = 0i64;
  if ( geometry->m_triangles.m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      v5 = v3->m_triangles.m_data;
      v6 = v3->m_vertices.m_data;
      ++v2;
      v7 = v5[v4].m_c;
      v8 = v5[v4].m_b;
      ++v4;
      v9 = _mm_sub_ps(
             _mm_mul_ps(_mm_shuffle_ps(v6[v7].m_quad, v6[v7].m_quad, 201), v6[v8].m_quad),
             _mm_mul_ps(_mm_shuffle_ps(v6[v8].m_quad, v6[v8].m_quad, 201), v6[v7].m_quad));
      v10 = _mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v6[v5[v4 - 1].m_a].m_quad);
      volume->m_real = _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
                           _mm_shuffle_ps(v10, v10, 170)),
                         volume->m_real);
    }
    while ( v2 < v3->m_triangles.m_size );
  }
  volume->m_real = _mm_mul_ps(volume->m_real, (__m128)xmmword_141A711F0);
}

// File Line: 1374
// RVA: 0xCA1A70
void __fastcall hkGeometryUtils::computeAabb(hkGeometry *geomIn, hkAabb *aabbOut)
{
  hkVector4f v2; // xmm2
  hkVector4f *v3; // r8
  int v4; // eax
  __int64 v5; // rcx
  hkVector4f v6; // xmm1
  __m128 *v7; // rax

  v2.m_quad = (__m128)xmmword_141A712A0;
  v3 = geomIn->m_vertices.m_data;
  v4 = geomIn->m_vertices.m_size - 1;
  v5 = v4;
  v6.m_quad = _mm_xor_ps(
                (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                (__m128)xmmword_141A712A0);
  if ( v4 >= 0 )
  {
    v7 = &v3[v4].m_quad;
    do
    {
      --v5;
      v2.m_quad = _mm_min_ps(v2.m_quad, *v7);
      v6.m_quad = _mm_max_ps(v6.m_quad, *v7);
      --v7;
    }
    while ( v5 >= 0 );
  }
  aabbOut->m_max = (hkVector4f)v6.m_quad;
  aabbOut->m_min = (hkVector4f)v2.m_quad;
}

// File Line: 1387
// RVA: 0xCA1AD0
void __fastcall hkGeometryUtils::computeAabbFromTriangles(hkGeometry *geomIn, hkAabb *aabbOut)
{
  __int64 v2; // r9
  hkVector4f v3; // xmm4
  hkVector4f v4; // xmm3
  hkVector4f *v5; // r8
  hkGeometry::Triangle *v6; // rcx
  __int64 v7; // rax
  __m128 v8; // xmm0
  __m128 v9; // xmm1

  v2 = geomIn->m_triangles.m_size;
  v3.m_quad = (__m128)xmmword_141A712A0;
  v4.m_quad = _mm_xor_ps(
                (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                (__m128)xmmword_141A712A0);
  if ( v2 > 0 )
  {
    v5 = geomIn->m_vertices.m_data;
    v6 = geomIn->m_triangles.m_data;
    do
    {
      v7 = v6->m_a;
      ++v6;
      v8 = v5[v7].m_quad;
      v9 = v5[v6[-1].m_b].m_quad;
      v3.m_quad = _mm_min_ps(_mm_min_ps(_mm_min_ps(v3.m_quad, v8), v9), v5[v6[-1].m_c].m_quad);
      v4.m_quad = _mm_max_ps(_mm_max_ps(_mm_max_ps(v4.m_quad, v8), v9), v5[v6[-1].m_c].m_quad);
      --v2;
    }
    while ( v2 );
  }
  aabbOut->m_max = (hkVector4f)v4.m_quad;
  aabbOut->m_min = (hkVector4f)v3.m_quad;
}

// File Line: 1404
// RVA: 0xCA14B0
void __fastcall hkGeometryUtils::transformGeometry(hkMatrix4f *transform, hkGeometry *geometryInOut)
{
  int v2; // er8
  __int64 v3; // r9
  hkVector4f *v4; // rax
  __m128 v5; // xmm1

  v2 = 0;
  if ( geometryInOut->m_vertices.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      v4 = geometryInOut->m_vertices.m_data;
      ++v2;
      ++v3;
      v5 = v4[v3 - 1].m_quad;
      v4[v3 - 1].m_quad = _mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_mul_ps(_mm_shuffle_ps(v5, v5, 0), transform->m_col0.m_quad),
                                transform->m_col3.m_quad),
                              _mm_mul_ps(_mm_shuffle_ps(v4[v3 - 1].m_quad, v5, 85), transform->m_col1.m_quad)),
                            _mm_mul_ps(_mm_shuffle_ps(v5, v5, 170), transform->m_col2.m_quad));
    }
    while ( v2 < geometryInOut->m_vertices.m_size );
  }
}

// File Line: 1413
// RVA: 0xCA1510
void __fastcall hkGeometryUtils::appendGeometry(hkGeometry *input, hkGeometry *geomInOut)
{
  int v2; // edi
  hkGeometry *v3; // rsi
  hkGeometry *v4; // rbx
  int v5; // ebp
  __int64 v6; // r14
  int v7; // er9
  int v8; // eax
  int v9; // eax
  __int64 v10; // r8
  signed __int64 v11; // rcx
  signed __int64 v12; // rax
  _DWORD *v13; // rdx
  hkResult result; // [rsp+50h] [rbp+8h]

  v2 = geomInOut->m_vertices.m_size;
  v3 = input;
  v4 = geomInOut;
  hkArrayBase<hkVector4f>::_append(
    (hkArrayBase<hkVector4f> *)&geomInOut->m_vertices.m_data,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    input->m_vertices.m_data,
    input->m_vertices.m_size);
  v5 = v3->m_triangles.m_size;
  v6 = v4->m_triangles.m_size;
  v7 = v6 + v5;
  v8 = v4->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 >= (signed int)v6 + v5 )
  {
    result.m_enum = 0;
  }
  else
  {
    v9 = 2 * v8;
    if ( v7 < v9 )
      v7 = v9;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v4->m_triangles,
      v7,
      16);
  }
  v4->m_triangles.m_size += v5;
  v10 = v3->m_triangles.m_size;
  v11 = (signed __int64)&v4->m_triangles.m_data[v6];
  if ( v10 > 0 )
  {
    v12 = v11 + 8;
    do
    {
      v13 = (_DWORD *)((char *)v3->m_triangles.m_data + v12 - v11 - 8);
      v12 += 16i64;
      *(_DWORD *)(v12 - 24) = *v13;
      *(_DWORD *)(v12 - 20) = v13[1];
      *(_DWORD *)(v12 - 16) = v13[2];
      *(_DWORD *)(v12 - 12) = v13[3];
      *(_DWORD *)(v12 - 24) += v2;
      *(_DWORD *)(v12 - 20) += v2;
      *(_DWORD *)(v12 - 16) += v2;
      --v10;
    }
    while ( v10 );
  }
}

// File Line: 1430
// RVA: 0xC9EDF0
void __fastcall hkGeometryUtils::quantize(hkGeometry *mesh, int resolution)
{
  __m128 v2; // xmm6
  int v3; // er9
  __int64 v4; // rdx
  hkGeometry *v5; // r8
  __int64 v6; // rcx
  __m128 v7; // xmm2
  __m128 *v8; // rax
  int v9; // ecx
  __m128 v10; // xmm7
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm6
  __m128 v14; // xmm7
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm0
  __m128 v18; // xmm9
  __m128 v19; // xmm8
  __int64 v20; // rdx
  hkVector4f *v21; // rax
  __m128 v22; // xmm5
  __m128i v23; // xmm2
  __m128i v24; // xmm4
  __m128 v25; // xmm2
  __m128 v26; // xmm0

  v2 = (__m128)xmmword_141A712A0;
  v3 = resolution;
  v4 = mesh->m_vertices.m_size;
  v5 = mesh;
  v6 = v4;
  v7 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), (__m128)xmmword_141A712A0);
  if ( (signed int)v4 > 0 )
  {
    v8 = &v5->m_vertices.m_data->m_quad;
    do
    {
      v2 = _mm_min_ps(v2, *v8);
      v7 = _mm_max_ps(v7, *v8);
      ++v8;
      --v6;
    }
    while ( v6 );
  }
  v9 = 0;
  v10 = 0i64;
  v10.m128_f32[0] = (float)(v3 - 1);
  v11 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0099999998), (__m128)LODWORD(FLOAT_0_0099999998), 0);
  v12 = _mm_add_ps(v7, v11);
  v13 = _mm_sub_ps(v2, v11);
  v14 = _mm_shuffle_ps(v10, v10, 0);
  v15 = _mm_rcp_ps(v14);
  v16 = _mm_sub_ps(v12, v13);
  v17 = _mm_rcp_ps(v16);
  v18 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v14, v15)), v15), v16);
  v19 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v16, v17)), v17), v14);
  if ( (signed int)v4 > 0 )
  {
    v20 = 0i64;
    do
    {
      v21 = v5->m_vertices.m_data;
      ++v9;
      ++v20;
      v22 = _mm_mul_ps(_mm_sub_ps(v21[v20 - 1].m_quad, v13), v19);
      v23 = (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v22);
      v24 = _mm_or_si128(
              _mm_add_epi32(
                _mm_cvttps_epi32(
                  _mm_max_ps(
                    _mm_sub_ps(v22, _mm_and_ps((__m128)v23, *(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31)),
                    (__m128)0i64)),
                _mm_slli_epi32(v23, 0x1Fu)),
              (__m128i)_mm_cmpleps(
                         _mm_add_ps(
                           *(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31,
                           *(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31),
                         v22));
      v25 = _mm_add_ps(
              _mm_mul_ps(
                _mm_cvtepi32_ps(_mm_srli_epi32(v24, 0x10u)),
                (__m128)`hkIntVector::convertU32ToF32'::`2'::two16),
              _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v24, 0x10u), 0x10u)));
      v26 = _mm_cmpltps(v25, v14);
      v21[v20 - 1].m_quad = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v26, v14), _mm_and_ps(v25, v26))),
                                v18),
                              v13);
    }
    while ( v9 < v5->m_vertices.m_size );
  }
}

// File Line: 1475
// RVA: 0xCA1600
hkResult *__fastcall hkGeometryUtils::getGeometryInsideAabb(hkResult *result, hkGeometry *geometryIn, hkGeometry *geometryOut, hkAabb *aabb, hkGeometryUtils::GetGeometryInsideAabbMode mode)
{
  int v5; // er9
  hkGeometry *v6; // r13
  int v7; // eax
  hkGeometry *v8; // r15
  hkResult *v9; // rsi
  int v10; // er8
  int v11; // ebx
  int v12; // ecx
  int v13; // er9
  char *v14; // rdi
  __int64 v15; // rcx
  hkGeometryUtils::GetGeometryInsideAabbMode v16; // er12
  int v17; // edx
  int v18; // er14
  __int64 v19; // rcx
  signed int *v20; // r15
  hkVector4f *v21; // rcx
  signed __int64 v22; // rax
  __m128 v23; // xmm0
  signed __int64 v24; // rax
  signed __int64 v25; // rbx
  __m128 *v26; // rsi
  __int64 v27; // rcx
  hkGeometry::Triangle *v28; // rdx
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  hkResult resulta; // [rsp+30h] [rbp-41h]
  int v35; // [rsp+34h] [rbp-3Dh]
  hkResult v36; // [rsp+38h] [rbp-39h]
  __int64 v37; // [rsp+40h] [rbp-31h]
  char *array; // [rsp+48h] [rbp-29h]
  int v39; // [rsp+50h] [rbp-21h]
  int v40; // [rsp+54h] [rbp-1Dh]
  __m128 v41; // [rsp+60h] [rbp-11h]
  __m128 v42; // [rsp+70h] [rbp-1h]
  __m128 v43; // [rsp+80h] [rbp+Fh]
  hkResult *v44; // [rsp+D0h] [rbp+5Fh]
  hkGeometry *v45; // [rsp+D8h] [rbp+67h]
  hkAabb *v46; // [rsp+E8h] [rbp+77h]

  v46 = aabb;
  v45 = geometryIn;
  v44 = result;
  v5 = geometryIn->m_vertices.m_size;
  v6 = geometryOut;
  v7 = 0;
  v8 = geometryIn;
  v9 = result;
  array = 0i64;
  v40 = 2147483648;
  v39 = 0;
  if ( v5 <= 0 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    if ( v5 < 0 )
      v5 = 0;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v5, 4);
    if ( resulta.m_enum )
    {
      v10 = v40;
      v9->m_enum = 1;
      v39 = 0;
      if ( v10 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          array,
          4 * v10);
      return v9;
    }
    v7 = v39;
  }
  v11 = v8->m_vertices.m_size;
  v12 = v40 & 0x3FFFFFFF;
  if ( (v40 & 0x3FFFFFFF) < v11 )
  {
    v13 = v8->m_vertices.m_size;
    if ( v11 < 2 * v12 )
      v13 = 2 * v12;
    hkArrayUtil::_reserve(&v36, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v13, 4);
    v7 = v39;
  }
  v14 = &array[4 * v7];
  v15 = v11 - v7;
  if ( v11 - v7 > 0 )
  {
    while ( v15 )
    {
      *(_DWORD *)v14 = -1;
      v14 += 4;
      --v15;
    }
  }
  v16 = mode;
  v39 = v11;
  v17 = 0;
  v18 = 0;
  v36.m_enum = 0;
  if ( v8->m_triangles.m_size > 0 )
  {
    v19 = 0i64;
    v37 = 0i64;
    do
    {
      v20 = (int *)((char *)&v8->m_triangles.m_data->m_a + v19);
      v21 = v45->m_vertices.m_data;
      v22 = v20[1];
      v41 = v21[*v20].m_quad;
      v23 = v21[v22].m_quad;
      v24 = v20[2];
      v42 = v23;
      v43 = v21[v24].m_quad;
      if ( (_mm_movemask_ps(
              _mm_and_ps(
                _mm_cmpleps(v46->m_min.m_quad, _mm_max_ps(_mm_max_ps(v41, v23), v43)),
                _mm_cmpleps(_mm_min_ps(_mm_min_ps(v41, v23), v43), v46->m_max.m_quad))) & 7) == 7 )
      {
        v25 = 0i64;
        v26 = &v41;
        v35 = v17 + 1;
        do
        {
          v27 = v20[v25];
          if ( *(_DWORD *)&array[4 * v27] == -1 )
          {
            *(_DWORD *)&array[4 * v27] = v18++;
            if ( v16 == 1 )
            {
              if ( v6->m_vertices.m_size == (v6->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                  &v6->m_vertices,
                  16);
              v6->m_vertices.m_data[v6->m_vertices.m_size++].m_quad = *v26;
            }
          }
          ++v25;
          ++v26;
        }
        while ( v25 < 3 );
        if ( v16 == 1 )
        {
          if ( v6->m_triangles.m_size == (v6->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              &v6->m_triangles,
              16);
          v28 = &v6->m_triangles.m_data[v6->m_triangles.m_size++];
          v28->m_a = *(_DWORD *)&array[4 * *v20];
          v28->m_b = *(_DWORD *)&array[4 * v20[1]];
          v28->m_c = *(_DWORD *)&array[4 * v20[2]];
          v28->m_material = v20[3];
        }
        v17 = v35;
      }
      v8 = v45;
      v19 = v37 + 16;
      ++v36.m_enum;
      v37 += 16i64;
    }
    while ( v36.m_enum < v45->m_triangles.m_size );
    v9 = v44;
  }
  if ( v16 )
    goto LABEL_51;
  v29 = v6->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v29 >= v17 )
  {
    LODWORD(v45) = 0;
  }
  else
  {
    v30 = 2 * v29;
    if ( v17 < v30 )
      v17 = v30;
    hkArrayUtil::_reserve(
      (hkResult *)&v45,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v6->m_triangles,
      v17,
      16);
    if ( (_DWORD)v45 )
    {
      v9->m_enum = 1;
      goto LABEL_46;
    }
  }
  v31 = v6->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v31 >= v18 )
    goto LABEL_51;
  v32 = 2 * v31;
  if ( v18 < v32 )
    v18 = v32;
  hkArrayUtil::_reserve(&v36, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v6->m_vertices, v18, 16);
  if ( v36.m_enum == HK_SUCCESS )
LABEL_51:
    v9->m_enum = 0;
  else
    v9->m_enum = 1;
LABEL_46:
  v39 = 0;
  if ( v40 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      4 * v40);
  return v9;
}

