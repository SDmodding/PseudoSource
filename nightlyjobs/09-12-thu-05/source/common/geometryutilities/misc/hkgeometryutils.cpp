// File Line: 23
// RVA: 0xCA1EE0
void __fastcall hkGeometryUtils::Node::Triangle::Triangle(
        hkGeometryUtils::Node::Triangle *this,
        unsigned int a,
        unsigned int b,
        unsigned int c)
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
  this->m_edges.m_capacityAndFlags = 0x80000000;
  this->m_edges.m_data = 0i64;
  this->m_edges.m_size = 0;
}

// File Line: 33
// RVA: 0xCA1B70
void __fastcall hkGeometryUtils::Node::Node(hkGeometryUtils::Node *this, hkGeometryUtils::Node *other)
{
  __int64 m_size; // rbp
  int v4; // ebx
  int v5; // r15d
  int v6; // eax
  int v8; // eax
  int v9; // r9d
  int v10; // ebx
  __int64 v11; // rdi
  int *v12; // rbx
  int v13; // r8d
  int v14; // eax
  hkGeometryUtils::Node::Edge *m_data; // rbx
  char *v16; // rsi
  __int64 v17; // rdi
  hkGeometryUtils::Node::Edge *v18; // rbx
  signed __int64 v19; // rsi
  __int64 v20; // rdi
  hkResult result; // [rsp+60h] [rbp+8h] BYREF

  this->m_edges.m_capacityAndFlags = 0x80000000;
  this->m_edges.m_data = 0i64;
  this->m_edges.m_size = 0;
  this->m_vertexIndex = other->m_vertexIndex;
  m_size = other->m_edges.m_size;
  v4 = this->m_edges.m_size;
  v5 = other->m_edges.m_size;
  if ( (int)m_size > v4 )
    v5 = this->m_edges.m_size;
  v6 = this->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v6 < (int)m_size )
  {
    v8 = 2 * v6;
    v9 = other->m_edges.m_size;
    if ( (int)m_size < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_edges.m_data, v9, 56);
  }
  v10 = v4 - m_size - 1;
  v11 = v10;
  if ( v10 >= 0 )
  {
    v12 = &this->m_edges.m_data[m_size].m_triangleIndices.m_capacityAndFlags + 14 * v10;
    do
    {
      v13 = *v12;
      *(v12 - 1) = 0;
      if ( v13 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v12 - 3),
          4 * v13);
      *(_QWORD *)(v12 - 3) = 0i64;
      *v12 = 0x80000000;
      v14 = *(v12 - 4);
      *(v12 - 5) = 0;
      if ( v14 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v12 - 7),
          24 * (v14 & 0x3FFFFFFF));
      *(_QWORD *)(v12 - 7) = 0i64;
      *(v12 - 4) = 0x80000000;
      v12 -= 14;
      --v11;
    }
    while ( v11 >= 0 );
  }
  m_data = this->m_edges.m_data;
  if ( v5 > 0 )
  {
    v16 = (char *)((char *)other->m_edges.m_data - (char *)m_data);
    v17 = (unsigned int)v5;
    do
    {
      hkGeometryUtils::Node::Edge::operator=(m_data, (hkGeometryUtils::Node::Edge *)((char *)m_data + (_QWORD)v16));
      ++m_data;
      --v17;
    }
    while ( v17 );
  }
  v18 = &this->m_edges.m_data[v5];
  if ( (int)m_size - v5 > 0 )
  {
    v19 = (char *)other->m_edges.m_data - (char *)this->m_edges.m_data;
    v20 = (unsigned int)(m_size - v5);
    do
    {
      if ( v18 )
        hkGeometryUtils::Node::Edge::Edge(v18, (hkGeometryUtils::Node::Edge *)((char *)v18 + v19));
      ++v18;
      --v20;
    }
    while ( v20 );
  }
  this->m_edges.m_size = m_size;
}

// File Line: 39
// RVA: 0xCA1D30
hkGeometryUtils::Node *__fastcall hkGeometryUtils::Node::operator=(
        hkGeometryUtils::Node *this,
        hkGeometryUtils::Node *other)
{
  __int64 m_size; // rbp
  int v5; // ebx
  int v6; // r15d
  int v7; // eax
  int v8; // eax
  int v9; // r9d
  int v10; // ebx
  __int64 v11; // rdi
  int *v12; // rbx
  int v13; // r8d
  int v14; // eax
  hkGeometryUtils::Node::Edge *m_data; // rbx
  char *v16; // rsi
  __int64 v17; // rdi
  hkGeometryUtils::Node::Edge *v18; // rbx
  signed __int64 v19; // rsi
  __int64 v20; // rdi
  hkResult result; // [rsp+60h] [rbp+8h] BYREF

  this->m_vertexIndex = other->m_vertexIndex;
  m_size = other->m_edges.m_size;
  v5 = this->m_edges.m_size;
  v6 = other->m_edges.m_size;
  if ( (int)m_size > v5 )
    v6 = this->m_edges.m_size;
  v7 = this->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < (int)m_size )
  {
    v8 = 2 * v7;
    v9 = other->m_edges.m_size;
    if ( (int)m_size < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_edges.m_data, v9, 56);
  }
  v10 = v5 - m_size - 1;
  v11 = v10;
  if ( v10 >= 0 )
  {
    v12 = &this->m_edges.m_data[m_size].m_triangleIndices.m_capacityAndFlags + 14 * v10;
    do
    {
      v13 = *v12;
      *(v12 - 1) = 0;
      if ( v13 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v12 - 3),
          4 * v13);
      *(_QWORD *)(v12 - 3) = 0i64;
      *v12 = 0x80000000;
      v14 = *(v12 - 4);
      *(v12 - 5) = 0;
      if ( v14 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v12 - 7),
          24 * (v14 & 0x3FFFFFFF));
      *(_QWORD *)(v12 - 7) = 0i64;
      *(v12 - 4) = 0x80000000;
      v12 -= 14;
      --v11;
    }
    while ( v11 >= 0 );
  }
  m_data = this->m_edges.m_data;
  if ( v6 > 0 )
  {
    v16 = (char *)((char *)other->m_edges.m_data - (char *)m_data);
    v17 = (unsigned int)v6;
    do
    {
      hkGeometryUtils::Node::Edge::operator=(m_data, (hkGeometryUtils::Node::Edge *)((char *)m_data + (_QWORD)v16));
      ++m_data;
      --v17;
    }
    while ( v17 );
  }
  v18 = &this->m_edges.m_data[v6];
  if ( (int)m_size - v6 > 0 )
  {
    v19 = (char *)other->m_edges.m_data - (char *)this->m_edges.m_data;
    v20 = (unsigned int)(m_size - v6);
    do
    {
      if ( v18 )
        hkGeometryUtils::Node::Edge::Edge(v18, (hkGeometryUtils::Node::Edge *)((char *)v18 + v19));
      ++v18;
      --v20;
    }
    while ( v20 );
  }
  this->m_edges.m_size = m_size;
  return this;
}

// File Line: 54
// RVA: 0xCA1F30
void __fastcall hkGeometryUtils::Node::Edge::Edge(
        hkGeometryUtils::Node::Edge *this,
        unsigned int endpointIndex,
        hkGeometryUtils::Node::Triangle *triangle,
        unsigned int triangleIndex)
{
  hkGeometryUtils::Node::Triangle *v7; // rdx

  this->m_endpointIndex = endpointIndex;
  this->m_triangles.m_capacityAndFlags = 0x80000000;
  this->m_triangles.m_data = 0i64;
  this->m_triangles.m_size = 0;
  this->m_triangleIndices.m_data = 0i64;
  this->m_triangleIndices.m_size = 0;
  this->m_triangleIndices.m_capacityAndFlags = 0x80000000;
  *(_QWORD *)&this->m_numIncoming = 0i64;
  *(_WORD *)&this->m_nonManifold = 0;
  this->m_processed = 0;
  if ( this->m_triangles.m_size == (this->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_triangles.m_data, 24);
  v7 = &this->m_triangles.m_data[this->m_triangles.m_size];
  if ( v7 )
  {
    v7->m_indices[0] = triangle->m_indices[0];
    v7->m_indices[1] = triangle->m_indices[1];
    v7->m_indices[2] = triangle->m_indices[2];
    v7->m_sortedIndices[0] = triangle->m_sortedIndices[0];
    v7->m_sortedIndices[1] = triangle->m_sortedIndices[1];
    v7->m_sortedIndices[2] = triangle->m_sortedIndices[2];
  }
  ++this->m_triangles.m_size;
  if ( this->m_triangleIndices.m_size == (this->m_triangleIndices.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_triangleIndices.m_data, 4);
  this->m_triangleIndices.m_data[this->m_triangleIndices.m_size++] = triangleIndex;
}

// File Line: 60
// RVA: 0xCA2220
void __fastcall hkGeometryUtils::Node::Edge::Edge(
        hkGeometryUtils::Node::Edge *this,
        hkGeometryUtils::Node::Edge *other)
{
  int m_size; // r14d
  int v4; // ebp
  int v6; // eax
  int v7; // eax
  int v8; // r9d
  hkGeometryUtils::Node::Triangle *m_data; // rcx
  __int64 v10; // r9
  char *v11; // rdx
  __int64 v12; // r8
  unsigned int v13; // eax
  hkGeometryUtils::Node::Triangle *v14; // rax
  __int64 v15; // rdx
  char *v16; // r8
  __int64 v17; // r8
  __int64 v18; // rax
  unsigned int *v19; // rcx
  __int64 v20; // rdx
  char *v21; // r8
  unsigned int v22; // eax
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  this->m_triangles.m_capacityAndFlags = 0x80000000;
  this->m_triangles.m_data = 0i64;
  this->m_triangles.m_size = 0;
  this->m_triangleIndices.m_data = 0i64;
  this->m_triangleIndices.m_size = 0;
  this->m_triangleIndices.m_capacityAndFlags = 0x80000000;
  this->m_endpointIndex = other->m_endpointIndex;
  m_size = other->m_triangles.m_size;
  v4 = m_size;
  if ( m_size > this->m_triangles.m_size )
    v4 = this->m_triangles.m_size;
  v6 = this->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v6 < m_size )
  {
    v7 = 2 * v6;
    v8 = other->m_triangles.m_size;
    if ( m_size < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_triangles.m_data, v8, 24);
  }
  m_data = this->m_triangles.m_data;
  v10 = v4;
  if ( v4 > 0 )
  {
    v11 = (char *)((char *)other->m_triangles.m_data - (char *)m_data);
    v12 = v4;
    do
    {
      v13 = *(unsigned int *)((char *)m_data->m_indices + (_QWORD)v11);
      ++m_data;
      m_data[-1].m_indices[0] = v13;
      m_data[-1].m_indices[1] = *(unsigned int *)((char *)&m_data->m_indices[-5] + (_QWORD)v11);
      m_data[-1].m_indices[2] = *(unsigned int *)((char *)&m_data->m_indices[-4] + (_QWORD)v11);
      m_data[-1].m_sortedIndices[0] = *(unsigned int *)((char *)&m_data->m_indices[-3] + (_QWORD)v11);
      m_data[-1].m_sortedIndices[1] = *(unsigned int *)((char *)&m_data->m_indices[-2] + (_QWORD)v11);
      m_data[-1].m_sortedIndices[2] = *(unsigned int *)((char *)&m_data->m_indices[-1] + (_QWORD)v11);
      --v12;
    }
    while ( v12 );
  }
  v14 = &this->m_triangles.m_data[v4];
  v15 = m_size - v4;
  if ( m_size - v4 > 0 )
  {
    v16 = (char *)((char *)&other->m_triangles.m_data[v4] - (char *)v14);
    do
    {
      if ( v14 )
      {
        v14->m_indices[0] = *(unsigned int *)((char *)v14->m_indices + (_QWORD)v16);
        v14->m_indices[1] = *(unsigned int *)((char *)&v14->m_indices[1] + (_QWORD)v16);
        v14->m_indices[2] = *(unsigned int *)((char *)&v14->m_indices[2] + (_QWORD)v16);
        v14->m_sortedIndices[0] = *(unsigned int *)((char *)v14->m_sortedIndices + (_QWORD)v16);
        v14->m_sortedIndices[1] = *(unsigned int *)((char *)&v14->m_sortedIndices[1] + (_QWORD)v16);
        v14->m_sortedIndices[2] = *(unsigned int *)((char *)&v14->m_sortedIndices[2] + (_QWORD)v16);
      }
      ++v14;
      --v15;
    }
    while ( v15 );
  }
  this->m_triangles.m_size = m_size;
  v17 = this->m_triangleIndices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( (int)v17 < other->m_triangleIndices.m_size )
  {
    if ( this->m_triangleIndices.m_capacityAndFlags >= 0 )
      ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, unsigned int *, _QWORD, _QWORD))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerHeapAllocator::s_alloc,
        this->m_triangleIndices.m_data,
        (unsigned int)(4 * this->m_triangleIndices.m_capacityAndFlags),
        v4);
    result.m_enum = 4 * other->m_triangleIndices.m_size;
    this->m_triangleIndices.m_data = (unsigned int *)((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkResult *, __int64, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
                                                       &hkContainerHeapAllocator::s_alloc,
                                                       &result,
                                                       v17,
                                                       v10);
    this->m_triangleIndices.m_capacityAndFlags = result.m_enum / 4;
  }
  v18 = other->m_triangleIndices.m_size;
  v19 = this->m_triangleIndices.m_data;
  this->m_triangleIndices.m_size = v18;
  v20 = v18;
  if ( (int)v18 > 0 )
  {
    v21 = (char *)((char *)other->m_triangleIndices.m_data - (char *)v19);
    do
    {
      v22 = *(unsigned int *)((char *)v19++ + (_QWORD)v21);
      *(v19 - 1) = v22;
      --v20;
    }
    while ( v20 );
  }
  this->m_numIncoming = other->m_numIncoming;
  this->m_numOutgoing = other->m_numOutgoing;
  this->m_nonManifold = other->m_nonManifold;
  this->m_inconsistentWinding = other->m_inconsistentWinding;
  this->m_processed = other->m_processed;
}

// File Line: 72
// RVA: 0xCA2040
hkGeometryUtils::Node::Edge *__fastcall hkGeometryUtils::Node::Edge::operator=(
        hkGeometryUtils::Node::Edge *this,
        hkGeometryUtils::Node::Edge *other)
{
  int m_size; // esi
  int v5; // ebp
  int v6; // eax
  int v7; // eax
  int v8; // r9d
  hkGeometryUtils::Node::Triangle *m_data; // rcx
  __int64 v10; // r9
  char *v11; // rdx
  __int64 v12; // r8
  unsigned int v13; // eax
  hkGeometryUtils::Node::Triangle *v14; // rax
  __int64 v15; // rdx
  char *v16; // r8
  __int64 v17; // r8
  __int64 v18; // rax
  unsigned int *v19; // rcx
  __int64 v20; // rdx
  char *v21; // r8
  unsigned int v22; // eax
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  this->m_endpointIndex = other->m_endpointIndex;
  m_size = other->m_triangles.m_size;
  v5 = m_size;
  if ( m_size > this->m_triangles.m_size )
    v5 = this->m_triangles.m_size;
  v6 = this->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v6 < m_size )
  {
    v7 = 2 * v6;
    v8 = other->m_triangles.m_size;
    if ( m_size < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_triangles.m_data, v8, 24);
  }
  m_data = this->m_triangles.m_data;
  v10 = v5;
  if ( v5 > 0 )
  {
    v11 = (char *)((char *)other->m_triangles.m_data - (char *)m_data);
    v12 = v5;
    do
    {
      v13 = *(unsigned int *)((char *)m_data->m_indices + (_QWORD)v11);
      ++m_data;
      m_data[-1].m_indices[0] = v13;
      m_data[-1].m_indices[1] = *(unsigned int *)((char *)&m_data->m_indices[-5] + (_QWORD)v11);
      m_data[-1].m_indices[2] = *(unsigned int *)((char *)&m_data->m_indices[-4] + (_QWORD)v11);
      m_data[-1].m_sortedIndices[0] = *(unsigned int *)((char *)&m_data->m_indices[-3] + (_QWORD)v11);
      m_data[-1].m_sortedIndices[1] = *(unsigned int *)((char *)&m_data->m_indices[-2] + (_QWORD)v11);
      m_data[-1].m_sortedIndices[2] = *(unsigned int *)((char *)&m_data->m_indices[-1] + (_QWORD)v11);
      --v12;
    }
    while ( v12 );
  }
  v14 = &this->m_triangles.m_data[v5];
  v15 = m_size - v5;
  if ( m_size - v5 > 0 )
  {
    v16 = (char *)((char *)&other->m_triangles.m_data[v5] - (char *)v14);
    do
    {
      if ( v14 )
      {
        v14->m_indices[0] = *(unsigned int *)((char *)v14->m_indices + (_QWORD)v16);
        v14->m_indices[1] = *(unsigned int *)((char *)&v14->m_indices[1] + (_QWORD)v16);
        v14->m_indices[2] = *(unsigned int *)((char *)&v14->m_indices[2] + (_QWORD)v16);
        v14->m_sortedIndices[0] = *(unsigned int *)((char *)v14->m_sortedIndices + (_QWORD)v16);
        v14->m_sortedIndices[1] = *(unsigned int *)((char *)&v14->m_sortedIndices[1] + (_QWORD)v16);
        v14->m_sortedIndices[2] = *(unsigned int *)((char *)&v14->m_sortedIndices[2] + (_QWORD)v16);
      }
      ++v14;
      --v15;
    }
    while ( v15 );
  }
  this->m_triangles.m_size = m_size;
  v17 = this->m_triangleIndices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( (int)v17 < other->m_triangleIndices.m_size )
  {
    if ( this->m_triangleIndices.m_capacityAndFlags >= 0 )
      ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, unsigned int *, _QWORD, _QWORD))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerHeapAllocator::s_alloc,
        this->m_triangleIndices.m_data,
        (unsigned int)(4 * this->m_triangleIndices.m_capacityAndFlags),
        v5);
    result.m_enum = 4 * other->m_triangleIndices.m_size;
    this->m_triangleIndices.m_data = (unsigned int *)((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkResult *, __int64, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
                                                       &hkContainerHeapAllocator::s_alloc,
                                                       &result,
                                                       v17,
                                                       v10);
    this->m_triangleIndices.m_capacityAndFlags = result.m_enum / 4;
  }
  v18 = other->m_triangleIndices.m_size;
  v19 = this->m_triangleIndices.m_data;
  this->m_triangleIndices.m_size = v18;
  v20 = v18;
  if ( (int)v18 > 0 )
  {
    v21 = (char *)((char *)other->m_triangleIndices.m_data - (char *)v19);
    do
    {
      v22 = *(unsigned int *)((char *)v19++ + (_QWORD)v21);
      *(v19 - 1) = v22;
      --v20;
    }
    while ( v20 );
  }
  this->m_numIncoming = other->m_numIncoming;
  this->m_numOutgoing = other->m_numOutgoing;
  this->m_nonManifold = other->m_nonManifold;
  this->m_inconsistentWinding = other->m_inconsistentWinding;
  this->m_processed = other->m_processed;
  return this;
}

// File Line: 85
// RVA: 0xCA2440
bool __fastcall hkGeometryUtils::Node::Edge::hasTriangleSameWinding(
        hkGeometryUtils::Node::Edge *this,
        hkGeometryUtils::Node::Triangle *triangle,
        int *triIndex)
{
  int v3; // r10d
  __int64 m_size; // r11
  __int64 v5; // r9
  hkGeometryUtils::Node::Triangle *i; // rax
  bool result; // al

  v3 = 0;
  *triIndex = -1;
  m_size = this->m_triangles.m_size;
  v5 = 0i64;
  if ( m_size <= 0 )
    return 0;
  for ( i = this->m_triangles.m_data;
        triangle->m_indices[0] != i->m_indices[0]
     || triangle->m_indices[1] != i->m_indices[1]
     || triangle->m_indices[2] != i->m_indices[2];
        ++i )
  {
    ++v5;
    ++v3;
    if ( v5 >= m_size )
      return 0;
  }
  result = 1;
  *triIndex = this->m_triangleIndices.m_data[v3];
  return result;
}

// File Line: 101
// RVA: 0xCA24C0
bool __fastcall hkGeometryUtils::Node::Edge::hasTriangleIgnoreWinding(
        hkGeometryUtils::Node::Edge *this,
        hkGeometryUtils::Node::Triangle *triangle,
        int *triIndex)
{
  int v3; // r10d
  __int64 m_size; // r11
  __int64 v5; // r9
  unsigned int *i; // rax
  bool result; // al

  v3 = 0;
  *triIndex = -1;
  m_size = this->m_triangles.m_size;
  v5 = 0i64;
  if ( m_size <= 0 )
    return 0;
  for ( i = &this->m_triangles.m_data->m_sortedIndices[1];
        triangle->m_sortedIndices[0] != *(i - 1)
     || triangle->m_sortedIndices[1] != *i
     || triangle->m_sortedIndices[2] != i[1];
        i += 6 )
  {
    ++v5;
    ++v3;
    if ( v5 >= m_size )
      return 0;
  }
  result = 1;
  *triIndex = this->m_triangleIndices.m_data[v3];
  return result;
}

// File Line: 117
// RVA: 0xCA2730
hkGeometryUtils::Node::Edge *__fastcall hkGeometryUtils::Node::findEdge(
        hkGeometryUtils::Node *this,
        unsigned int endpointIndex)
{
  __int64 m_size; // r10
  int v3; // r9d
  __int64 v4; // r8
  hkGeometryUtils::Node::Edge *i; // rax

  m_size = this->m_edges.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( m_size <= 0 )
    return 0i64;
  for ( i = this->m_edges.m_data; i->m_endpointIndex != endpointIndex; ++i )
  {
    ++v4;
    ++v3;
    if ( v4 >= m_size )
      return 0i64;
  }
  return &this->m_edges.m_data[v3];
}

// File Line: 126
// RVA: 0xCA2540
void __fastcall hkGeometryUtils::Node::addEdge(
        hkGeometryUtils::Node *this,
        unsigned int endpointIndex,
        hkGeometryUtils::Node::Triangle *triangle,
        unsigned int triangleIndex,
        bool incoming)
{
  hkGeometryUtils::Node::Edge *Edge; // rax
  hkGeometryUtils::Node::Edge *v10; // rbx
  hkGeometryUtils::Node::Triangle *v11; // rdx
  hkGeometryUtils::Node::Edge *v12; // rcx
  int m_capacityAndFlags; // r8d
  hkGeometryUtils::Node::Edge other; // [rsp+20h] [rbp-48h] BYREF

  Edge = hkGeometryUtils::Node::findEdge(this, endpointIndex);
  v10 = Edge;
  if ( Edge )
  {
    if ( incoming )
      ++Edge->m_numIncoming;
    else
      ++Edge->m_numOutgoing;
    if ( Edge->m_numIncoming > 1 || Edge->m_numOutgoing > 1 )
      Edge->m_inconsistentWinding = 1;
    if ( Edge->m_triangleIndices.m_size == (Edge->m_triangleIndices.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&Edge->m_triangleIndices.m_data, 4);
    v10->m_triangleIndices.m_data[v10->m_triangleIndices.m_size++] = triangleIndex;
    if ( v10->m_triangles.m_size == (v10->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v10->m_triangles.m_data, 24);
    v11 = &v10->m_triangles.m_data[v10->m_triangles.m_size];
    if ( v11 )
    {
      v11->m_indices[0] = triangle->m_indices[0];
      v11->m_indices[1] = triangle->m_indices[1];
      v11->m_indices[2] = triangle->m_indices[2];
      v11->m_sortedIndices[0] = triangle->m_sortedIndices[0];
      v11->m_sortedIndices[1] = triangle->m_sortedIndices[1];
      v11->m_sortedIndices[2] = triangle->m_sortedIndices[2];
    }
    ++v10->m_triangles.m_size;
    if ( v10->m_triangleIndices.m_size > 2 )
      v10->m_nonManifold = 1;
  }
  else
  {
    hkGeometryUtils::Node::Edge::Edge(&other, endpointIndex, triangle, triangleIndex);
    if ( incoming )
      ++other.m_numIncoming;
    else
      ++other.m_numOutgoing;
    if ( this->m_edges.m_size == (this->m_edges.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_edges.m_data, 56);
    v12 = &this->m_edges.m_data[this->m_edges.m_size];
    if ( v12 )
      hkGeometryUtils::Node::Edge::Edge(v12, &other);
    m_capacityAndFlags = other.m_triangleIndices.m_capacityAndFlags;
    ++this->m_edges.m_size;
    other.m_triangleIndices.m_size = 0;
    if ( m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        other.m_triangleIndices.m_data,
        4 * m_capacityAndFlags);
    other.m_triangleIndices.m_data = 0i64;
    other.m_triangleIndices.m_capacityAndFlags = 0x80000000;
    other.m_triangles.m_size = 0;
    if ( other.m_triangles.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        other.m_triangles.m_data,
        24 * (other.m_triangles.m_capacityAndFlags & 0x3FFFFFFF));
  }
}

// File Line: 152
// RVA: 0xCA2770
char __fastcall hkGeometryUtils::Node::checkForNonManifoldGeometry(hkGeometryUtils::Node *this)
{
  __int64 m_size; // r8
  __int64 v2; // rdx
  bool *i; // rax

  m_size = this->m_edges.m_size;
  v2 = 0i64;
  if ( m_size <= 0 )
    return 1;
  for ( i = &this->m_edges.m_data->m_nonManifold; !*i; i += 56 )
  {
    if ( ++v2 >= m_size )
      return 1;
  }
  return 0;
}

// File Line: 162
// RVA: 0xCA27A0
void __fastcall hkGeometryUtils::Node::warnAboutInconsistentWinding(hkGeometryUtils::Node *this, int e)
{
  hkGeometryUtils::Node::Edge *v3; // rdi
  unsigned int *m_data; // rbx
  hkOstream *v5; // rax
  hkOstream *v6; // rax
  hkOstream *v7; // rax
  hkOstream *v8; // rax
  hkOstream *v9; // rax
  hkOstream *v10; // rax
  hkOstream *v11; // rax
  hkOstream *v12; // rax
  hkErrStream v13; // [rsp+20h] [rbp-228h] BYREF
  char buf[520]; // [rsp+40h] [rbp-208h] BYREF

  v3 = &this->m_edges.m_data[e];
  if ( v3->m_inconsistentWinding && v3->m_triangles.m_size > 1 )
  {
    hkErrStream::hkErrStream(&v13, buf, 512);
    m_data = v3->m_triangleIndices.m_data;
    v5 = hkOstream::operator<<(&v13, "Edge (");
    v6 = hkOstream::operator<<(v5, v3->m_endpointIndex);
    v7 = hkOstream::operator<<(v6, ",");
    v8 = hkOstream::operator<<(v7, this->m_vertexIndex);
    v9 = hkOstream::operator<<(v8, ") has inconsistent winding in triangles ");
    v10 = hkOstream::operator<<(v9, *m_data);
    v11 = hkOstream::operator<<(v10, "and");
    v12 = hkOstream::operator<<(v11, m_data[1]);
    hkOstream::operator<<(v12, ".");
    hkError::messageWarning(0xABBA1DAF, buf, "Misc\\hkGeometryUtils.cpp", 166);
    hkOstream::~hkOstream(&v13);
  }
}

// File Line: 185
// RVA: 0xC9D450
__int64 __fastcall hkGeometryUtils::weldVerticesVirtual(
        hkGeometryUtils::IVertices *vertices,
        hkArray<int,hkContainerHeapAllocator> *remap,
        float thr)
{
  float v5; // xmm6_4
  int v6; // eax
  unsigned int v7; // r13d
  __int64 v8; // rsi
  weldVerticesVirtualNs::VertexRef *v9; // rbx
  unsigned int v10; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // r9d
  int v14; // edi
  __int64 v15; // rbp
  __int64 v16; // r12
  int *p_m_index; // rdi
  __int64 v18; // rbx
  __int64 v19; // r12
  __int64 v20; // rdx
  __int64 v21; // rsi
  int *v22; // rbx
  __int64 v23; // rdx
  __m128 v24; // xmm2
  __m128 v25; // xmm2
  weldVerticesVirtualNs::VertexRef *pArr; // [rsp+30h] [rbp-98h]
  __m128 v28; // [rsp+40h] [rbp-88h] BYREF
  __m128 v29; // [rsp+50h] [rbp-78h] BYREF
  int v30; // [rsp+D0h] [rbp+8h] BYREF
  int v31; // [rsp+D8h] [rbp+10h]
  unsigned int v32; // [rsp+E0h] [rbp+18h]
  __int64 result; // [rsp+E8h] [rbp+20h] BYREF

  v32 = LODWORD(thr);
  LODWORD(v5) = _mm_shuffle_ps((__m128)v32, (__m128)v32, 0).m128_u32[0];
  v6 = vertices->vfptr->getNumVertices(vertices);
  v7 = 0;
  v8 = v6;
  if ( v6 )
  {
    v30 = 32 * v6;
    v9 = (weldVerticesVirtualNs::VertexRef *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                               &hkContainerHeapAllocator::s_alloc,
                                               &v30);
    v6 = v30 / 32;
  }
  else
  {
    v9 = 0i64;
  }
  v10 = 0x80000000;
  pArr = v9;
  if ( v6 )
    v10 = v6;
  v11 = remap->m_capacityAndFlags & 0x3FFFFFFF;
  v31 = v10;
  if ( v11 < (int)v8 )
  {
    v12 = 2 * v11;
    v13 = v8;
    if ( (int)v8 < v12 )
      v13 = v12;
    hkArrayUtil::_reserve(
      (hkResult *)&result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&remap->m_data,
      v13,
      4);
  }
  remap->m_size = v8;
  v14 = 0;
  v15 = v8;
  if ( (int)v8 > 0 )
  {
    v16 = v8;
    do
    {
      vertices->vfptr->getVertex(vertices, v14, (hkVector4f *)&v28);
      v9->m_index = v14++;
      ++v9;
      v9[-1].m_value.m_real = _mm_shuffle_ps(v28, v28, 0);
      --v16;
    }
    while ( v16 );
  }
  if ( (int)v8 > 1 )
    hkAlgorithm::quickSortRecursive<weldVerticesVirtualNs::VertexRef,hkAlgorithm::less<weldVerticesVirtualNs::VertexRef>>(
      pArr,
      0,
      v8 - 1,
      0);
  if ( (int)v8 > 0 )
  {
    p_m_index = &pArr->m_index;
    v18 = v8;
    v19 = 1i64;
    result = v8;
    do
    {
      v20 = *p_m_index;
      if ( (int)v20 >= 0 )
      {
        remap->m_data[v20] = v20;
        vertices->vfptr->getVertex(vertices, *p_m_index, (hkVector4f *)&v28);
        v21 = v19;
        if ( v19 < v15 )
        {
          v22 = p_m_index + 8;
          do
          {
            v23 = (unsigned int)*v22;
            if ( (int)v23 >= 0 )
            {
              if ( (float)(*((float *)v22 - 4) - *((float *)p_m_index - 4)) > v5 )
                break;
              vertices->vfptr->getVertex(vertices, v23, (hkVector4f *)&v29);
              v24 = _mm_sub_ps(v28, v29);
              v25 = _mm_mul_ps(v24, v24);
              if ( (float)((float)(_mm_shuffle_ps(v25, v25, 85).m128_f32[0] + _mm_shuffle_ps(v25, v25, 0).m128_f32[0])
                         + _mm_shuffle_ps(v25, v25, 170).m128_f32[0]) <= (float)(v5 * v5)
                && vertices->vfptr->isWeldingAllowed(vertices, *v22, *p_m_index) )
              {
                remap->m_data[*v22] = *p_m_index;
                *v22 = -1;
              }
            }
            ++v21;
            v22 += 8;
          }
          while ( v21 < v15 );
          v18 = result;
        }
        *p_m_index = -1;
        ++v7;
      }
      p_m_index += 8;
      ++v19;
      result = --v18;
    }
    while ( v18 );
  }
  if ( v31 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, pArr, 32 * v31);
  return v7;
}

// File Line: 235
// RVA: 0xC9D720
void __fastcall hkGeometryUtils::weldVertices(hkGeometry *meshGeometry, float threshold)
{
  int m_size; // ecx
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
  hkArrayBase<hk1AxisSweep::AabbInt> sortedAabbs; // [rsp+48h] [rbp-19h] BYREF
  hkArrayBase<hkRadixSort::SortData32> sortData; // [rsp+58h] [rbp-9h] BYREF
  hkArray<hkVector4f,hkContainerHeapAllocator> uniqueVerts; // [rsp+68h] [rbp+7h] BYREF
  hkArray<int,hkContainerHeapAllocator> triangleRemapOut; // [rsp+78h] [rbp+17h] BYREF
  hkArray<int,hkContainerHeapAllocator> vertexRemapOut; // [rsp+88h] [rbp+27h] BYREF
  hkArrayBase<hk1AxisSweep::AabbInt> sweepAabbs; // [rsp+98h] [rbp+37h] BYREF
  void *retaddr; // [rsp+C8h] [rbp+67h] BYREF

  m_size = meshGeometry->m_vertices.m_size;
  v4 = m_size == -4;
  v5 = m_size + 4;
  vertexRemapOut.m_capacityAndFlags = 0x80000000;
  vertexRemapOut.m_data = 0i64;
  vertexRemapOut.m_size = 0;
  triangleRemapOut.m_data = 0i64;
  v6 = v5;
  triangleRemapOut.m_size = 0;
  triangleRemapOut.m_capacityAndFlags = 0x80000000;
  uniqueVerts.m_data = 0i64;
  uniqueVerts.m_size = 0;
  uniqueVerts.m_capacityAndFlags = 0x80000000;
  if ( v4 )
  {
    v7 = 0i64;
  }
  else
  {
    LODWORD(retaddr) = 32 * v5;
    v7 = (hk1AxisSweep::AabbInt *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                    &hkContainerHeapAllocator::s_alloc,
                                    &retaddr);
    v5 = (int)retaddr / 32;
  }
  v8 = 0x80000000;
  sweepAabbs.m_size = v6;
  if ( v5 )
    v8 = v5;
  v9 = meshGeometry->m_vertices.m_size;
  sweepAabbs.m_data = v7;
  v4 = v9 == -4;
  v10 = v9 + 4;
  sweepAabbs.m_capacityAndFlags = v8;
  sortData.m_data = 0i64;
  sortData.m_size = 0;
  sortData.m_capacityAndFlags = 0x80000000;
  v11 = v10;
  if ( v4 )
  {
    v12 = 0i64;
  }
  else
  {
    LODWORD(retaddr) = 8 * v10;
    v12 = (hkRadixSort::SortData32 *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                       &hkContainerHeapAllocator::s_alloc,
                                       &retaddr);
    v10 = (int)retaddr / 8;
  }
  v13 = 0x80000000;
  sortData.m_size = v11;
  if ( v10 )
    v13 = v10;
  v14 = meshGeometry->m_vertices.m_size;
  sortData.m_data = v12;
  v4 = v14 == -4;
  v15 = v14 + 4;
  sortData.m_capacityAndFlags = v13;
  sortedAabbs.m_data = 0i64;
  sortedAabbs.m_size = 0;
  sortedAabbs.m_capacityAndFlags = 0x80000000;
  v16 = v15;
  if ( v4 )
  {
    v17 = 0i64;
  }
  else
  {
    LODWORD(retaddr) = 32 * v15;
    v17 = (hk1AxisSweep::AabbInt *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                     &hkContainerHeapAllocator::s_alloc,
                                     &retaddr);
    v15 = (int)retaddr / 32;
  }
  v18 = 0x80000000;
  sortedAabbs.m_data = v17;
  if ( v15 )
    v18 = v15;
  sortedAabbs.m_capacityAndFlags = v18;
  sortedAabbs.m_size = v16;
  hkGeometryUtils::_weldVertices(
    meshGeometry,
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
      &hkContainerHeapAllocator::s_alloc,
      sortedAabbs.m_data,
      32 * sortedAabbs.m_capacityAndFlags);
  sortedAabbs.m_data = 0i64;
  sortedAabbs.m_capacityAndFlags = 0x80000000;
  sortData.m_size = 0;
  if ( sortData.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      sortData.m_data,
      8 * sortData.m_capacityAndFlags);
  sortData.m_data = 0i64;
  sortData.m_capacityAndFlags = 0x80000000;
  if ( sweepAabbs.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      sweepAabbs.m_data,
      32 * sweepAabbs.m_capacityAndFlags);
  uniqueVerts.m_size = 0;
  if ( uniqueVerts.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      uniqueVerts.m_data,
      16 * uniqueVerts.m_capacityAndFlags);
  uniqueVerts.m_data = 0i64;
  uniqueVerts.m_capacityAndFlags = 0x80000000;
  triangleRemapOut.m_size = 0;
  if ( triangleRemapOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      triangleRemapOut.m_data,
      4 * triangleRemapOut.m_capacityAndFlags);
  triangleRemapOut.m_data = 0i64;
  triangleRemapOut.m_capacityAndFlags = 0x80000000;
  vertexRemapOut.m_size = 0;
  if ( vertexRemapOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      vertexRemapOut.m_data,
      4 * vertexRemapOut.m_capacityAndFlags);
}

// File Line: 246
// RVA: 0xC9DA10
void __fastcall hkGeometryUtils::weldVertices(
        hkGeometry *meshGeometry,
        float threshold,
        hkBool keepVertexOrder,
        hkArray<int,hkContainerHeapAllocator> *vertexRemapOut)
{
  int m_size; // edx
  bool v5; // zf
  int v6; // edx
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
  hkArrayBase<hkRadixSort::SortData32> *sortData; // [rsp+38h] [rbp-11h] BYREF
  hkArrayBase<hk1AxisSweep::AabbInt> *sortedAabbs; // [rsp+40h] [rbp-9h]
  hkArrayBase<hkRadixSort::SortData32> v22; // [rsp+48h] [rbp-1h] BYREF
  hkArray<hkVector4f,hkContainerHeapAllocator> uniqueVerts; // [rsp+58h] [rbp+Fh] BYREF
  hkArrayBase<hk1AxisSweep::AabbInt> sweepAabbs; // [rsp+68h] [rbp+1Fh] BYREF
  int v25; // [rsp+A8h] [rbp+5Fh] BYREF
  void *retaddr; // [rsp+B8h] [rbp+6Fh]
  hkArray<int,hkContainerHeapAllocator> *v27; // [rsp+C8h] [rbp+7Fh]

  m_size = meshGeometry->m_vertices.m_size;
  v5 = m_size == -4;
  v6 = m_size + 4;
  uniqueVerts.m_data = 0i64;
  uniqueVerts.m_size = 0;
  v9 = v6;
  uniqueVerts.m_capacityAndFlags = 0x80000000;
  if ( v5 )
  {
    v10 = 0i64;
  }
  else
  {
    v25 = 32 * v6;
    v10 = (hk1AxisSweep::AabbInt *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                     &hkContainerHeapAllocator::s_alloc,
                                     &v25);
    v6 = v25 / 32;
  }
  sweepAabbs.m_data = v10;
  v11 = meshGeometry->m_vertices.m_size;
  v12 = 0x80000000;
  sweepAabbs.m_size = v9;
  v22.m_data = 0i64;
  if ( v6 )
    v12 = v6;
  v5 = v11 == -4;
  v13 = v11 + 4;
  v22.m_size = 0;
  v14 = v13;
  sweepAabbs.m_capacityAndFlags = v12;
  v22.m_capacityAndFlags = 0x80000000;
  if ( v5 )
  {
    v15 = 0i64;
  }
  else
  {
    v25 = 8 * v13;
    v15 = (hkRadixSort::SortData32 *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                       &hkContainerHeapAllocator::s_alloc,
                                       &v25);
    v13 = v25 / 8;
  }
  v16 = 0x80000000;
  v22.m_size = v14;
  if ( v13 )
    v16 = v13;
  v17 = meshGeometry->m_vertices.m_size;
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
    hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &v25);
  }
  hkGeometryUtils::_weldVertices(
    meshGeometry,
    threshold,
    (hkBool)retaddr,
    vertexRemapOut,
    v27,
    &uniqueVerts,
    &sweepAabbs,
    &v22,
    (hkArrayBase<hk1AxisSweep::AabbInt> *)__PAIR64__((_DWORD)&sortData, v19));
  LODWORD(sortedAabbs) = 0;
  if ( SHIDWORD(sortedAabbs) >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      sortData,
      32 * HIDWORD(sortedAabbs));
  sortData = 0i64;
  HIDWORD(sortedAabbs) = 0x80000000;
  v22.m_size = 0;
  if ( v22.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v22.m_data,
      8 * v22.m_capacityAndFlags);
  v22.m_data = 0i64;
  v22.m_capacityAndFlags = 0x80000000;
  if ( sweepAabbs.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      sweepAabbs.m_data,
      32 * sweepAabbs.m_capacityAndFlags);
  uniqueVerts.m_size = 0;
  if ( uniqueVerts.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      uniqueVerts.m_data,
      16 * uniqueVerts.m_capacityAndFlags);
}

// File Line: 258
// RVA: 0xCA28B0
void __fastcall `anonymous namespace::hkWeldVertices(
        hkArray<hkVector4f,hkContainerHeapAllocator> *vertsIn,
        hkArray<hkVector4f,hkContainerHeapAllocator> *uniqueVerts,
        hkArray<int,hkContainerHeapAllocator> *remap,
        hkArrayBase<hk1AxisSweep::AabbInt> *vertAabbs,
        hkArrayBase<hkRadixSort::SortData32> *sortData,
        hkArrayBase<hk1AxisSweep::AabbInt> *tempAabbs,
        float tol)
{
  __int64 m_size; // r13
  int v8; // eax
  hkArray<hkVector4f,hkContainerHeapAllocator> *v11; // rsi
  __m128 v12; // xmm7
  int v13; // eax
  int v14; // r9d
  __int64 v15; // rdi
  __int64 v16; // r15
  __m128 v17; // xmm6
  unsigned int v18; // ebp
  __int64 v19; // r14
  hkVector4f *m_data; // rax
  hk1AxisSweep::AabbInt *v21; // rcx
  hkVector4f v22; // xmm0
  hkArrayBase<hk1AxisSweep::AabbInt> *v23; // r9
  hkArrayBase<hkRadixSort::SortData32> *v24; // r8
  hkVector4f v25; // xmm1
  hk1AxisSweep::AabbInt *v26; // rax
  float v27; // xmm7_4
  __int64 v28; // r13
  __int64 v29; // r9
  __int64 v30; // rbp
  hkArray<hkVector4f,hkContainerHeapAllocator> *v31; // r11
  hkVector4f *v32; // r14
  __int64 v33; // r8
  __int64 v34; // rax
  _DWORD *v35; // rdx
  __int64 v36; // rcx
  __m128 v37; // xmm2
  __m128 v38; // xmm2
  hkAabb aabbIn; // [rsp+30h] [rbp-78h] BYREF
  __int64 v42; // [rsp+C0h] [rbp+18h] BYREF

  m_size = vertsIn->m_size;
  v8 = remap->m_capacityAndFlags & 0x3FFFFFFF;
  v11 = uniqueVerts;
  v12 = _mm_shuffle_ps((__m128)LODWORD(tol), (__m128)LODWORD(tol), 0);
  if ( v8 < (int)m_size )
  {
    v13 = 2 * v8;
    v14 = vertsIn->m_size;
    if ( (int)m_size < v13 )
      v14 = v13;
    hkArrayUtil::_reserve((hkResult *)&v42, &hkContainerHeapAllocator::s_alloc, (const void **)&remap->m_data, v14, 4);
  }
  v15 = 0i64;
  remap->m_size = m_size;
  v16 = m_size;
  v17 = _mm_mul_ps(v12, (__m128)xmmword_141A711B0);
  v18 = 0;
  vertAabbs->m_size = m_size + 4;
  if ( (int)m_size > 0 )
  {
    v19 = 0i64;
    do
    {
      m_data = vertsIn->m_data;
      v21 = &vertAabbs->m_data[v18];
      aabbIn.m_min.m_quad = _mm_sub_ps(vertsIn->m_data[v19].m_quad, v17);
      aabbIn.m_max.m_quad = _mm_add_ps(m_data[v19].m_quad, v17);
      hk1AxisSweep::AabbInt::set(v21, (const __m128i *)&aabbIn, v18++);
      ++v19;
      --v16;
    }
    while ( v16 );
    v11 = uniqueVerts;
    v16 = m_size;
  }
  v22.m_quad = (__m128)aabbIn.m_max;
  v23 = tempAabbs;
  v24 = sortData;
  aabbIn.m_min.m_quad.m128_i32[0] = -1;
  v25.m_quad = (__m128)aabbIn.m_min;
  v26 = &vertAabbs->m_data[v16];
  *(hkVector4f *)v26->m_min = aabbIn.m_min;
  *(hkVector4f *)v26->m_max = (hkVector4f)v22.m_quad;
  *(hkVector4f *)v26[1].m_min = (hkVector4f)v25.m_quad;
  *(hkVector4f *)v26[1].m_max = (hkVector4f)v22.m_quad;
  *(hkVector4f *)v26[2].m_min = (hkVector4f)v25.m_quad;
  *(hkVector4f *)v26[2].m_max = (hkVector4f)v22.m_quad;
  *(hkVector4f *)v26[3].m_min = (hkVector4f)v25.m_quad;
  *(hkVector4f *)v26[3].m_max = (hkVector4f)v22.m_quad;
  hk1AxisSweep::sortAabbs(vertAabbs->m_data, m_size, v24, v23);
  v27 = v12.m128_f32[0] * v12.m128_f32[0];
  if ( v16 > 0 )
  {
    v28 = 1i64;
    v29 = v16;
    v42 = v16;
    do
    {
      v30 = *(unsigned int *)vertAabbs->m_data[v15].m_expansionMin;
      if ( (_DWORD)v30 != -1 )
      {
        v31 = vertsIn;
        v32 = &vertsIn->m_data[(int)v30];
        remap->m_data[(int)v30] = v11->m_size;
        if ( v11->m_size == (v11->m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v11->m_data, 16);
          v31 = vertsIn;
          v29 = v42;
        }
        v33 = v28;
        v11->m_data[v11->m_size++] = (hkVector4f)v32->m_quad;
        if ( v28 < v16 )
        {
          v34 = v15 * 32 + 32;
          do
          {
            v35 = (unsigned int *)((char *)vertAabbs->m_data->m_min + v34);
            if ( *v35 > vertAabbs->m_data[v15].m_max[0] )
              break;
            v36 = (int)v35[3];
            if ( (_DWORD)v36 != -1 )
            {
              v37 = _mm_sub_ps(v32->m_quad, v31->m_data[v35[3]].m_quad);
              v38 = _mm_mul_ps(v37, v37);
              if ( (float)((float)(_mm_shuffle_ps(v38, v38, 85).m128_f32[0] + _mm_shuffle_ps(v38, v38, 0).m128_f32[0])
                         + _mm_shuffle_ps(v38, v38, 170).m128_f32[0]) <= v27 )
              {
                remap->m_data[v36] = remap->m_data[v30];
                *(_DWORD *)&vertAabbs->m_data->m_expansionMin[v34] = -1;
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
bool __fastcall `anonymous namespace::hkTriangle_isDegenerate(hkGeometry::Triangle *a)
{
  int m_b; // edx
  int m_c; // eax
  bool result; // al

  m_b = a->m_b;
  result = 1;
  if ( a->m_a != m_b )
  {
    m_c = a->m_c;
    if ( a->m_a != m_c && m_b != m_c )
      return 0;
  }
  return result;
}

// File Line: 359
// RVA: 0xCA2B90
bool __fastcall sameTriangleConsideringWinding(hkGeometry::Triangle *triA, hkGeometry::Triangle *triB)
{
  int m_a; // r10d
  int v3; // r8d
  int m_b; // r9d
  bool result; // al

  m_a = triA->m_a;
  v3 = triB->m_a;
  result = 1;
  if ( triA->m_a != triB->m_a || triA->m_b != triB->m_b || triA->m_c != triB->m_c )
  {
    m_b = triB->m_b;
    if ( (m_a != m_b || *(_QWORD *)&triA->m_b != __PAIR64__(v3, triB->m_c))
      && (m_a != triB->m_c || triA->m_b != v3 || triA->m_c != m_b) )
    {
      return 0;
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
hkResult *__fastcall hkGeometryUtils::removeDuplicateTrianglesFast(
        hkResult *result,
        hkGeometry *meshGeometry,
        hkArray<hkGeometry::Triangle,hkContainerHeapAllocator> *newTriangles)
{
  int m_size; // ebp
  hkArray<hkGeometry::Triangle,hkContainerHeapAllocator> *v4; // r14
  hkResult *v7; // rax
  int v8; // r12d
  triInfo *v9; // rbx
  int v10; // edi
  __int64 v11; // rsi
  hkGeometry::Triangle *m_data; // rax
  int v13; // r8d
  int v14; // r9d
  int v15; // edx
  int v16; // eax
  unsigned __int64 v17; // rax
  int v18; // r15d
  __int64 v19; // r11
  triInfo *v20; // rdi
  unsigned __int64 m_key; // r14
  int v22; // r10d
  int v23; // esi
  int v24; // r8d
  triInfo *v25; // r9
  hkGeometry::Triangle *v26; // rax
  hkGeometry::Triangle *v27; // rdx
  int m_a; // r11d
  int v29; // ebx
  int m_b; // r10d
  triInfo *v31; // rcx
  __int64 v32; // rdx
  __int64 v33; // rax
  int *p_m_index; // rdi
  __int64 v35; // rsi
  hkGeometry::Triangle *v36; // rbx
  hkGeometry::Triangle *v37; // rcx
  __int64 v38; // rax
  hkGeometry::Triangle *v39; // rcx
  __int64 v40; // rdx
  signed __int64 v41; // r8
  int v42; // eax
  triInfo *v43; // [rsp+28h] [rbp-60h]
  hkGeometry::Triangle t1; // [rsp+30h] [rbp-58h] BYREF
  int v46; // [rsp+98h] [rbp+10h] BYREF
  hkArray<hkGeometry::Triangle,hkContainerHeapAllocator> *v47; // [rsp+A0h] [rbp+18h]
  int v48; // [rsp+A8h] [rbp+20h] BYREF

  v47 = newTriangles;
  m_size = meshGeometry->m_triangles.m_size;
  v4 = newTriangles;
  if ( m_size )
  {
    v48 = 16 * m_size;
    v8 = 0x80000000;
    v9 = (triInfo *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(&hkContainerTempAllocator::s_alloc, &v48);
    v43 = v9;
    if ( v48 / 16 )
      v8 = v48 / 16;
    if ( v9 )
    {
      v10 = 0;
      if ( meshGeometry->m_triangles.m_size > 0 )
      {
        v11 = -(__int64)v9;
        do
        {
          m_data = meshGeometry->m_triangles.m_data;
          v13 = *(int *)((char *)&m_data->m_a + (_QWORD)v9 + v11);
          v14 = *(int *)((char *)&m_data->m_b + (_QWORD)v9 + v11);
          v15 = *(int *)((char *)&m_data->m_c + (_QWORD)v9 + v11);
          LODWORD(m_data) = *(int *)((char *)&m_data->m_material + (_QWORD)v9 + v11);
          *(_QWORD *)&t1.m_a = __PAIR64__(v14, v13);
          t1.m_material = (int)m_data;
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
          v9->m_index = v10++;
          v9->m_key = v17;
          ++v9;
        }
        while ( v10 < meshGeometry->m_triangles.m_size );
        v9 = v43;
      }
      if ( m_size > 1 )
        hkAlgorithm::quickSortRecursive<triInfo,sortByKey>(v9, 0, m_size - 1, 0);
      v18 = m_size - 1;
      v19 = m_size - 1;
      *(_QWORD *)&t1.m_a = v19;
      if ( v19 >= 1 )
      {
        v20 = &v9[v18];
        do
        {
          m_key = v20->m_key;
          v22 = v18 - 1;
          v23 = -1;
          v46 = v18 - 1;
          v24 = v18 - 1;
          if ( v18 >= 1 )
          {
            v25 = v20 - 1;
            do
            {
              if ( m_key != v25->m_key )
                break;
              v26 = &meshGeometry->m_triangles.m_data[v20->m_index];
              v27 = &meshGeometry->m_triangles.m_data[v25->m_index];
              m_a = v26->m_a;
              v29 = v27->m_a;
              if ( v26->m_a != v27->m_a || v26->m_b != v27->m_b || v26->m_c != v27->m_c )
              {
                m_b = v27->m_b;
                if ( (m_a != m_b || v26->m_b != v27->m_c || v26->m_c != v29)
                  && (m_a != v27->m_c || v26->m_b != v29 || v26->m_c != m_b) )
                {
                  continue;
                }
              }
              v23 = v24;
              --v25;
              --v24;
            }
            while ( v24 >= 0 );
            v9 = v43;
            if ( v23 != -1 && --m_size != v18 )
            {
              v31 = v20;
              v32 = 2i64;
              do
              {
                v33 = *(unsigned __int64 *)((char *)&v31->m_key + (char *)&v43[m_size] - (char *)v20);
                v31 = (triInfo *)((char *)v31 + 8);
                *(_QWORD *)&v31[-1].m_index = v33;
                --v32;
              }
              while ( v32 );
            }
            v22 = v46;
            v19 = *(_QWORD *)&t1.m_a;
          }
          --v20;
          --v19;
          v18 = v22;
          *(_QWORD *)&t1.m_a = v19;
        }
        while ( v19 );
        v4 = v47;
      }
      if ( m_size > 1 )
        hkAlgorithm::quickSortRecursive<triInfo,sortByIndex>(v9, 0, m_size - 1, 0);
      v4->m_size = 0;
      if ( m_size > 0 )
      {
        p_m_index = &v9->m_index;
        v35 = (unsigned int)m_size;
        do
        {
          v36 = &meshGeometry->m_triangles.m_data[*p_m_index];
          if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v4->m_data, 16);
          p_m_index += 4;
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
      if ( (meshGeometry->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) < v4->m_size )
      {
        if ( meshGeometry->m_triangles.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            meshGeometry->m_triangles.m_data,
            16 * meshGeometry->m_triangles.m_capacityAndFlags);
        v46 = 16 * v4->m_size;
        meshGeometry->m_triangles.m_data = (hkGeometry::Triangle *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                                     &hkContainerHeapAllocator::s_alloc,
                                                                     &v46);
        meshGeometry->m_triangles.m_capacityAndFlags = v46 / 16;
      }
      v38 = v4->m_size;
      v39 = meshGeometry->m_triangles.m_data;
      meshGeometry->m_triangles.m_size = v38;
      v40 = v38;
      if ( (int)v38 > 0 )
      {
        v41 = (char *)v4->m_data - (char *)v39;
        do
        {
          v42 = *(int *)((char *)&v39->m_a + v41);
          ++v39;
          v39[-1].m_a = v42;
          v39[-1].m_b = *(_DWORD *)((char *)v39 + v41 - 12);
          v39[-1].m_c = *(_DWORD *)((char *)v39 + v41 - 8);
          v39[-1].m_material = *(_DWORD *)((char *)v39 + v41 - 4);
          --v40;
        }
        while ( v40 );
      }
      result->m_enum = HK_SUCCESS;
      if ( v8 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v43, 16 * v8);
      return result;
    }
    else
    {
      result->m_enum = HK_FAILURE;
      if ( v8 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, 0i64, 16 * v8);
      return result;
    }
  }
  else
  {
    v7 = result;
    result->m_enum = HK_SUCCESS;
  }
  return v7;
}

// File Line: 496
// RVA: 0xC9DC90
void __fastcall hkGeometryUtils::_weldVertices(
        hkGeometry *meshGeometry,
        float threshold,
        hkBool keepVertexOrder,
        hkArray<int,hkContainerHeapAllocator> *vertexRemapOut,
        hkArray<int,hkContainerHeapAllocator> *triangleRemapOut,
        hkArray<hkVector4f,hkContainerHeapAllocator> *uniqueVerts,
        hkArrayBase<hk1AxisSweep::AabbInt> *sweepAabbs,
        hkArrayBase<hkRadixSort::SortData32> *sortData,
        hkArrayBase<hk1AxisSweep::AabbInt> *sortedAabbs)
{
  int m_size; // edi
  int v10; // r12d
  int v11; // eax
  hkGeometry *v13; // r13
  int v14; // eax
  int v15; // r9d
  hkArray<hkVector4f,hkContainerHeapAllocator> *v16; // r14
  hkArrayBase<hk1AxisSweep::AabbInt> *v17; // r9
  hkArray<hkVector4f,hkContainerHeapAllocator> *p_m_vertices; // rsi
  hkArray<hkVector4f,hkContainerHeapAllocator> *v19; // rdx
  __int64 v20; // rbx
  int v21; // r9d
  int v22; // edi
  int v23; // r14d
  int v24; // eax
  __int64 v25; // rcx
  _DWORD *v26; // rdi
  int v27; // r13d
  __int64 v28; // r14
  hkArray<hkVector4f,hkContainerHeapAllocator> *v29; // rbx
  __int64 v30; // rsi
  int v31; // r12d
  int v32; // ecx
  __int128 *v33; // rsi
  hkVector4f *v34; // rax
  _OWORD *m128_f32; // rcx
  __int64 v36; // rdx
  __int128 *v37; // rax
  __int128 v38; // xmm0
  __int64 v39; // rsi
  __int64 v40; // rdi
  __int64 v41; // r8
  hkGeometry::Triangle *v42; // rdx
  hkArray<int,hkContainerHeapAllocator> *v43; // rdi
  int v44; // eax
  int v45; // eax
  int v46; // r9d
  hkGeometry::Triangle *v47; // rdi
  hkArray<hkGeometry::Triangle,hkContainerHeapAllocator> *p_m_triangles; // r12
  __int64 v49; // r15
  hkGeometry::Triangle *v50; // r13
  __int64 v51; // rsi
  hkGeometry::Triangle *v52; // r14
  __int64 v53; // rdi
  int v54; // eax
  int v55; // eax
  int v56; // r9d
  __int64 v57; // rax
  char *m_data; // rcx
  __int64 v59; // rdx
  signed __int64 v60; // rdi
  __int128 v61; // xmm0
  hkArrayBase<hkRadixSort::SortData32> *sizeElem; // [rsp+20h] [rbp-60h]
  hkArrayBase<hk1AxisSweep::AabbInt> *tempAabbs; // [rsp+28h] [rbp-58h]
  int v64; // [rsp+40h] [rbp-40h]
  hkArray<hkVector4f,hkContainerHeapAllocator> *v65; // [rsp+48h] [rbp-38h]
  __int128 *array; // [rsp+50h] [rbp-30h] BYREF
  int v67; // [rsp+58h] [rbp-28h]
  int v68; // [rsp+5Ch] [rbp-24h]
  _DWORD *v69; // [rsp+60h] [rbp-20h] BYREF
  int v70; // [rsp+68h] [rbp-18h]
  int v71; // [rsp+6Ch] [rbp-14h]
  hkGeometry *v72; // [rsp+C0h] [rbp+40h] BYREF
  char m_bool; // [rsp+D0h] [rbp+50h]
  hkResult result; // [rsp+D8h] [rbp+58h] BYREF

  m_bool = keepVertexOrder.m_bool;
  v72 = meshGeometry;
  m_size = meshGeometry->m_vertices.m_size;
  v10 = meshGeometry->m_triangles.m_size;
  v11 = vertexRemapOut->m_capacityAndFlags & 0x3FFFFFFF;
  v13 = meshGeometry;
  v64 = v10;
  if ( v11 < m_size )
  {
    v14 = 2 * v11;
    v15 = meshGeometry->m_vertices.m_size;
    if ( m_size < v14 )
      v15 = v14;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&vertexRemapOut->m_data, v15, 4);
  }
  v16 = uniqueVerts;
  v17 = sweepAabbs;
  tempAabbs = sortedAabbs;
  p_m_vertices = &v13->m_vertices;
  v19 = uniqueVerts;
  sizeElem = sortData;
  vertexRemapOut->m_size = m_size;
  v65 = &v13->m_vertices;
  `anonymous namespace::hkWeldVertices(&v13->m_vertices, v19, vertexRemapOut, v17, sizeElem, tempAabbs, threshold);
  v20 = 0i64;
  if ( m_bool )
  {
    v21 = v16->m_size;
    array = 0i64;
    v22 = 0;
    v67 = 0;
    v68 = 0x80000000;
    if ( v21 > 0 )
    {
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v21, 16);
      v22 = v67;
    }
    v23 = v16->m_size;
    v69 = 0i64;
    v24 = 0;
    v70 = 0;
    v71 = 0x80000000;
    if ( v23 > 0 )
    {
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v69, v23, 4);
      v22 = v67;
      v24 = v70;
    }
    v25 = v23 - v24;
    if ( v23 - v24 > 0 )
    {
      v26 = &v69[v24];
      while ( v25 )
      {
        *v26++ = -1;
        --v25;
      }
      v22 = v67;
    }
    v70 = v23;
    v27 = 0;
    if ( vertexRemapOut->m_size > 0 )
    {
      v28 = 0i64;
      v29 = uniqueVerts;
      do
      {
        v30 = vertexRemapOut->m_data[v28];
        v31 = v69[v30];
        if ( v31 == -1 )
        {
          v69[v30] = v22;
          v32 = v67;
          v31 = v22;
          v33 = (__int128 *)&v29->m_data[v30];
          if ( v67 == (v68 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
            v32 = v67;
          }
          array[v32] = *v33;
          ++v67;
        }
        ++v27;
        vertexRemapOut->m_data[v28++] = v31;
        v22 = v67;
      }
      while ( v27 < vertexRemapOut->m_size );
      p_m_vertices = v65;
      v10 = v64;
      v20 = 0i64;
    }
    if ( (p_m_vertices->m_capacityAndFlags & 0x3FFFFFFF) < v22 )
    {
      if ( p_m_vertices->m_capacityAndFlags >= 0 )
      {
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          p_m_vertices->m_data,
          16 * p_m_vertices->m_capacityAndFlags);
        v22 = v67;
      }
      result.m_enum = 16 * v22;
      v34 = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &result);
      v22 = v67;
      p_m_vertices->m_data = v34;
      p_m_vertices->m_capacityAndFlags = result.m_enum / 16;
    }
    m128_f32 = (_OWORD *)p_m_vertices->m_data->m_quad.m128_f32;
    p_m_vertices->m_size = v22;
    v36 = v22;
    if ( v22 > 0 )
    {
      v37 = array;
      do
      {
        v38 = *v37;
        ++m128_f32;
        ++v37;
        *(m128_f32 - 1) = v38;
        --v36;
      }
      while ( v36 );
    }
    v70 = 0;
    if ( v71 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v69, 4 * v71);
    v69 = 0i64;
    v71 = 0x80000000;
    v67 = 0;
    if ( v68 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v68);
    v13 = v72;
  }
  else
  {
    if ( (v13->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) < v16->m_size )
    {
      if ( v13->m_vertices.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          p_m_vertices->m_data,
          16 * v13->m_vertices.m_capacityAndFlags);
      LODWORD(v72) = 16 * v16->m_size;
      p_m_vertices->m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                             &hkContainerHeapAllocator::s_alloc,
                                             &v72);
      v13->m_vertices.m_capacityAndFlags = (int)v72 / 16;
    }
    v57 = v16->m_size;
    m_data = (char *)p_m_vertices->m_data;
    v13->m_vertices.m_size = v57;
    v59 = v57;
    if ( (int)v57 > 0 )
    {
      v60 = (char *)v16->m_data - m_data;
      do
      {
        v61 = *(_OWORD *)&m_data[v60];
        m_data += 16;
        *((_OWORD *)m_data - 1) = v61;
        --v59;
      }
      while ( v59 );
    }
  }
  v39 = v10;
  if ( v10 > 0 )
  {
    v40 = 0i64;
    v41 = v10;
    do
    {
      v42 = v13->m_triangles.m_data;
      ++v40;
      v42[v40 - 1].m_a = vertexRemapOut->m_data[v42[v40 - 1].m_a];
      v42[v40 - 1].m_b = vertexRemapOut->m_data[v42[v40 - 1].m_b];
      v42[v40 - 1].m_c = vertexRemapOut->m_data[v42[v40 - 1].m_c];
      --v41;
    }
    while ( v41 );
  }
  v43 = triangleRemapOut;
  v44 = triangleRemapOut->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v44 < v10 )
  {
    v45 = 2 * v44;
    v46 = v10;
    if ( v10 < v45 )
      v46 = v45;
    hkArrayUtil::_reserve(
      (hkResult *)&v72,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&triangleRemapOut->m_data,
      v46,
      4);
  }
  v43->m_size = v10;
  v47 = v13->m_triangles.m_data;
  p_m_triangles = &v13->m_triangles;
  if ( v39 > 0 )
  {
    v49 = 0i64;
    do
    {
      v50 = p_m_triangles->m_data;
      LODWORD(v51) = -1;
      v52 = &p_m_triangles->m_data[v49];
      if ( !`anonymous namespace::hkTriangle_isDegenerate(v52) )
      {
        v47->m_a = v52->m_a;
        v47->m_b = v52->m_b;
        v51 = v47 - v50;
        v47->m_c = v52->m_c;
        ++v47;
        v47[-1].m_material = v52->m_material;
      }
      ++v20;
      ++v49;
      triangleRemapOut->m_data[v20 - 1] = v51;
    }
    while ( v20 < v64 );
  }
  v53 = v47 - p_m_triangles->m_data;
  v54 = p_m_triangles->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v54 < (int)v53 )
  {
    v55 = 2 * v54;
    v56 = v53;
    if ( (int)v53 < v55 )
      v56 = v55;
    hkArrayUtil::_reserve(
      (hkResult *)&v72,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&p_m_triangles->m_data,
      v56,
      16);
  }
  p_m_triangles->m_size = v53;
}

// File Line: 579
// RVA: 0xC9E180
void __fastcall hkGeometryUtils::removeDuplicateTriangles(
        hkGeometry *meshGeometry,
        hkArray<int,hkContainerHeapAllocator> *triangleMapOut,
        bool ignoreWinding)
{
  __int64 v3; // rbx
  unsigned int j; // edi
  int v8; // edx
  hkGeometryUtils::Node *v9; // rcx
  __int64 v10; // rcx
  unsigned int *v11; // rsi
  __int64 v12; // r12
  hkGeometryUtils::Node *v13; // rdi
  __int64 v14; // r15
  hkGeometryUtils::Node::Edge *Edge; // rax
  __int64 v16; // r13
  hkGeometryUtils::Node::Edge *v17; // rsi
  hkGeometryUtils::Node::Edge *v18; // rdi
  int v19; // r13d
  __int64 v20; // r15
  int v21; // r12d
  __int64 v22; // rsi
  __int64 v23; // rdi
  __int64 v24; // rdi
  unsigned int v25; // ecx
  _DWORD *v26; // rdi
  char *v27; // rcx
  __int64 v28; // rcx
  unsigned int *v29; // rsi
  __int64 v30; // r12
  hkGeometryUtils::Node *v31; // rdi
  __int64 v32; // r15
  hkGeometryUtils::Node::Edge *v33; // rax
  __int64 v34; // r13
  hkGeometryUtils::Node::Edge *v35; // rsi
  hkGeometryUtils::Node::Edge *v36; // rdi
  int v37; // r13d
  __int64 v38; // r15
  int v39; // r12d
  __int64 v40; // rsi
  __int64 v41; // rdi
  __int64 v42; // rdi
  unsigned int v43; // ecx
  _DWORD *v44; // rdi
  char *v45; // rcx
  unsigned int v46; // edi
  int m_size; // ebx
  hkOstream *v48; // rax
  hkOstream *v49; // rax
  hkOstream *v50; // rax
  hkOstream *v51; // rax
  __int64 v52; // rax
  hkGeometry::Triangle *m_data; // rdx
  __int64 v54; // r8
  int *v55; // rcx
  int v56; // eax
  int v57; // ebx
  hkGeometryUtils::Node *v58; // rdi
  int *v59; // [rsp+30h] [rbp-C8h] BYREF
  unsigned int triangleIndex; // [rsp+38h] [rbp-C0h]
  int v61; // [rsp+3Ch] [rbp-BCh]
  hkGeometryUtils::Node *array; // [rsp+40h] [rbp-B8h] BYREF
  int v63; // [rsp+48h] [rbp-B0h]
  int v64; // [rsp+4Ch] [rbp-ACh]
  __int64 v65; // [rsp+50h] [rbp-A8h]
  unsigned int c; // [rsp+58h] [rbp-A0h]
  int v67; // [rsp+60h] [rbp-98h]
  int v68; // [rsp+64h] [rbp-94h]
  int v69; // [rsp+68h] [rbp-90h]
  hkGeometryUtils::Node other; // [rsp+70h] [rbp-88h] BYREF
  char buf[520]; // [rsp+88h] [rbp-70h] BYREF
  void *retaddr; // [rsp+2C8h] [rbp+1D0h] BYREF
  __int64 i; // [rsp+2D8h] [rbp+1E0h] BYREF
  unsigned int v74; // [rsp+2E0h] [rbp+1E8h]

  i = v3;
  v59 = 0i64;
  triangleIndex = 0;
  v61 = 0x80000000;
  array = 0i64;
  v63 = 0;
  v64 = 0x80000000;
  for ( j = 0; j < meshGeometry->m_vertices.m_size; ++j )
  {
    hkGeometryUtils::Node::Node(&other, j);
    v8 = v63;
    if ( v63 == (v64 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&array, 24);
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
  }
  LODWORD(i) = 0;
  v74 = 0;
  if ( ignoreWinding )
  {
    if ( !meshGeometry->m_triangles.m_size )
      goto LABEL_49;
    v10 = 0i64;
    v65 = 0i64;
    do
    {
      v11 = (unsigned int *)((char *)meshGeometry->m_triangles.m_data + v10);
      hkGeometryUtils::Node::Triangle::Triangle((hkGeometryUtils::Node::Triangle *)&other, *v11, v11[1], v11[2]);
      v12 = (int)*v11;
      v13 = array;
      v14 = (int)v11[1];
      Edge = hkGeometryUtils::Node::findEdge(&array[v12], v11[1]);
      v16 = (int)v11[2];
      *(_QWORD *)&other.m_edges.m_size = Edge;
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
        if ( triangleMapOut->m_size == (triangleMapOut->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&triangleMapOut->m_data, 4);
        triangleMapOut->m_data[triangleMapOut->m_size++] = (int)retaddr;
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
        if ( triangleMapOut->m_size == (triangleMapOut->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&triangleMapOut->m_data, 4);
        v24 = v65;
        triangleMapOut->m_data[triangleMapOut->m_size++] = v19;
        v25 = triangleIndex;
        v26 = (int *)((char *)&meshGeometry->m_triangles.m_data->m_a + v24);
        if ( triangleIndex == (v61 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v59, 16);
          v25 = triangleIndex;
        }
        v27 = (char *)&v59[4 * v25];
        *(_DWORD *)v27 = *v26;
        *((_DWORD *)v27 + 1) = v26[1];
        *((_DWORD *)v27 + 2) = v26[2];
        *((_DWORD *)v27 + 3) = v26[3];
        ++triangleIndex;
      }
      v10 = v65 + 16;
      ++v74;
      v65 += 16i64;
    }
    while ( v74 < meshGeometry->m_triangles.m_size );
  }
  else
  {
    if ( !meshGeometry->m_triangles.m_size )
      goto LABEL_49;
    v28 = 0i64;
    v65 = 0i64;
    do
    {
      v29 = (unsigned int *)((char *)meshGeometry->m_triangles.m_data + v28);
      hkGeometryUtils::Node::Triangle::Triangle((hkGeometryUtils::Node::Triangle *)&other, *v29, v29[1], v29[2]);
      v30 = (int)*v29;
      v31 = array;
      v32 = (int)v29[1];
      v33 = hkGeometryUtils::Node::findEdge(&array[v30], v29[1]);
      v34 = (int)v29[2];
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
        if ( triangleMapOut->m_size == (triangleMapOut->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&triangleMapOut->m_data, 4);
        triangleMapOut->m_data[triangleMapOut->m_size++] = (int)retaddr;
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
        if ( triangleMapOut->m_size == (triangleMapOut->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&triangleMapOut->m_data, 4);
        v42 = v65;
        triangleMapOut->m_data[triangleMapOut->m_size++] = v37;
        v43 = triangleIndex;
        v44 = (int *)((char *)&meshGeometry->m_triangles.m_data->m_a + v42);
        if ( triangleIndex == (v61 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v59, 16);
          v43 = triangleIndex;
        }
        v45 = (char *)&v59[4 * v43];
        *(_DWORD *)v45 = *v44;
        *((_DWORD *)v45 + 1) = v44[1];
        *((_DWORD *)v45 + 2) = v44[2];
        *((_DWORD *)v45 + 3) = v44[3];
        ++triangleIndex;
      }
      v28 = v65 + 16;
      ++v74;
      v65 += 16i64;
    }
    while ( v74 < meshGeometry->m_triangles.m_size );
  }
  v46 = i;
  if ( (int)i > 0 )
  {
    hkErrStream::hkErrStream((hkErrStream *)&other, buf, 512);
    m_size = meshGeometry->m_triangles.m_size;
    v48 = hkOstream::operator<<((hkOstream *)&other, "Removed ");
    v49 = hkOstream::operator<<(v48, v46);
    v50 = hkOstream::operator<<(v49, " duplicate triangles out of a total of ");
    v51 = hkOstream::operator<<(v50, m_size);
    hkOstream::operator<<(v51, " triangles.");
    hkError::messageReport(0xFFFFFFFF, buf, "Misc\\hkGeometryUtils.cpp", 679);
    hkOstream::~hkOstream((hkOstream *)&other);
  }
LABEL_49:
  if ( (meshGeometry->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) < (int)triangleIndex )
  {
    if ( meshGeometry->m_triangles.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        meshGeometry->m_triangles.m_data,
        16 * meshGeometry->m_triangles.m_capacityAndFlags);
    LODWORD(i) = 16 * triangleIndex;
    meshGeometry->m_triangles.m_data = (hkGeometry::Triangle *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                                 &hkContainerHeapAllocator::s_alloc,
                                                                 &i);
    meshGeometry->m_triangles.m_capacityAndFlags = (int)i / 16;
  }
  v52 = (int)triangleIndex;
  m_data = meshGeometry->m_triangles.m_data;
  meshGeometry->m_triangles.m_size = triangleIndex;
  v54 = v52;
  if ( (int)v52 > 0 )
  {
    v55 = v59;
    do
    {
      v56 = *v55;
      ++m_data;
      v55 += 4;
      m_data[-1].m_a = v56;
      m_data[-1].m_b = *(v55 - 3);
      m_data[-1].m_c = *(v55 - 2);
      m_data[-1].m_material = *(v55 - 1);
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
      hkGeometryUtils::Node::~Node(v58--);
      --v57;
    }
    while ( v57 >= 0 );
  }
  v63 = 0;
  if ( v64 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 24 * (v64 & 0x3FFFFFFF));
  array = 0i64;
  triangleIndex = 0;
  v64 = 0x80000000;
  if ( v61 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v59, 16 * v61);
}

// File Line: 689
// RVA: 0xC9EFA0
void __fastcall hkGeometryUtils::createCapsuleGeometry(
        hkVector4f *start,
        hkVector4f *end,
        float radius,
        int heightSamples)
{
  __int64 m_enum; // rbx
  int m_capacityAndFlags; // r9d
  hkResultEnum v7; // r15d
  int m_size; // r8d
  __m128 m_quad; // xmm9
  __m128 v10; // xmm14
  __m128 v11; // xmm15
  __m128 v12; // xmm12
  __m128 v13; // xmm4
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm5
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  __m128 v19; // xmm12
  __m128 v20; // xmm1
  __m128 v21; // xmm4
  __m128 v22; // xmm11
  __m128 v23; // xmm11
  __m128 v24; // xmm1
  __m128 v25; // xmm2
  __m128 v26; // xmm1
  __m128 v27; // xmm11
  __m128 v28; // xmm13
  __m128 v29; // xmm13
  __m128 v30; // xmm2
  __m128 v31; // xmm10
  int v32; // r13d
  __m128 v33; // xmm15
  int v34; // eax
  __m128 v35; // xmm1
  __m128 v36; // xmm14
  __m128 v37; // xmm7
  __m128 v38; // xmm1
  __m128 v39; // xmm6
  __m128 v40; // xmm4
  __m128 v41; // xmm2
  int v42; // esi
  __m128 v43; // xmm2
  __m128 v44; // xmm1
  __m128 v45; // xmm0
  __m128 v46; // xmm2
  __m128 v47; // xmm2
  __m128 v48; // xmm5
  __m128 v49; // xmm1
  __m128 v50; // xmm5
  __m128 v51; // xmm3
  __m128 v52; // xmm6
  __m128 v53; // xmm0
  int v54; // edi
  __m128 v55; // xmm1
  __m128 v56; // xmm4
  __m128 v57; // xmm3
  __m128 v58; // xmm6
  __m128 v59; // xmm6
  __m128 v60; // xmm9
  __m128 v61; // xmm10
  __m128 v62; // xmm0
  int v63; // ecx
  __m128 v64; // xmm1
  __m128 v65; // xmm4
  __m128 v66; // xmm3
  __m128 v67; // xmm5
  __m128 v68; // xmm5
  __m128 v69; // xmm7
  __m128 v70; // xmm2
  int v71; // esi
  __m128 v72; // xmm2
  __m128 v73; // xmm1
  __m128 v74; // xmm4
  __m128 v75; // xmm14
  int v76; // edi
  __m128 v77; // xmm6
  __m128 v78; // xmm10
  __m128 v79; // xmm6
  __m128 v80; // xmm0
  int v81; // ecx
  __m128 v82; // xmm1
  __m128 v83; // xmm4
  __m128 v84; // xmm3
  __m128 v85; // xmm5
  __m128 v86; // xmm5
  __m128 v87; // xmm7
  int v88; // esi
  __m128 v89; // xmm14
  __m128 v90; // xmm1
  int v91; // edi
  __m128 v92; // xmm1
  __m128 v93; // xmm4
  __m128 v94; // xmm3
  __m128 v95; // xmm6
  __m128 v96; // xmm6
  __m128 v97; // xmm9
  __m128 v98; // xmm14
  __m128 v99; // xmm10
  __m128 v100; // xmm0
  int v101; // ecx
  __m128 v102; // xmm1
  __m128 v103; // xmm4
  __m128 v104; // xmm3
  __m128 v105; // xmm5
  __m128 v106; // xmm5
  __m128 v107; // xmm7
  __m128 v108; // xmm8
  __m128 v109; // xmm6
  int v110; // r8d
  __m128 *v111; // rcx
  __int64 v112; // rdx
  __m128 v113; // xmm1
  int v114; // ecx
  int v115; // edi
  int v116; // r12d
  int v117; // esi
  __int64 v118; // r15
  char *v119; // rax
  __int64 v120; // rax
  __int64 v121; // r13
  int v122; // esi
  int v123; // r14d
  int v124; // r15d
  char *v125; // rax
  int v126; // ecx
  char *v127; // rax
  __int64 v128; // r14
  int v129; // r15d
  int v130; // esi
  char *v131; // rax
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> array; // [rsp+30h] [rbp-98h] BYREF
  char *a; // [rsp+40h] [rbp-88h] BYREF
  _BYTE a_8[64]; // [rsp+48h] [rbp-80h] BYREF
  hkSimdFloat32 v135; // [rsp+88h] [rbp-40h] BYREF
  __m128 v136; // [rsp+98h] [rbp-30h]
  __m128 v137; // [rsp+A8h] [rbp-20h]
  hkVector4f axis; // [rsp+B8h] [rbp-10h] BYREF
  __m128 v139; // [rsp+C8h] [rbp+0h]
  __m128 v140; // [rsp+D8h] [rbp+10h]
  hkSimdFloat32 angle; // [rsp+E8h] [rbp+20h] BYREF
  __int64 v142; // [rsp+1D8h] [rbp+110h]
  unsigned int v143; // [rsp+1E8h] [rbp+120h]
  hkResult result; // [rsp+1F8h] [rbp+130h] BYREF
  __m128 *vars0; // [rsp+200h] [rbp+138h]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *retaddr; // [rsp+208h] [rbp+140h]

  m_enum = (unsigned int)result.m_enum;
  m_capacityAndFlags = 0x80000000;
  v7 = result.m_enum >> 1;
  array.m_data = 0i64;
  m_size = 0;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  m_quad = transform.m_quad;
  v10 = start->m_quad;
  v11 = end->m_quad;
  v137 = transform.m_quad;
  v12 = _mm_sub_ps(v11, v10);
  v13 = _mm_mul_ps(v12, v12);
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  v15 = _mm_rsqrt_ps(v14);
  v139 = _mm_andnot_ps(
           _mm_cmple_ps(v14, (__m128)0i64),
           _mm_mul_ps(
             _mm_mul_ps(
               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v15, v14), v15)),
               _mm_mul_ps(*(__m128 *)_xmm, v15)),
             v14));
  v16 = stru_141A71280.m_quad;
  if ( v139.m128_f32[0] <= 0.0
    || (v17 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
                _mm_shuffle_ps(v13, v13, 170)),
        v18 = _mm_rsqrt_ps(v17),
        result.m_enum = LODWORD(FLOAT_0_99998999),
        v19 = _mm_mul_ps(
                v12,
                _mm_andnot_ps(
                  _mm_cmple_ps(v17, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                    _mm_mul_ps(*(__m128 *)_xmm, v18)))),
        v20 = _mm_mul_ps(v19, stru_141A71280.m_quad),
        COERCE_FLOAT((unsigned int)(2
                                  * COERCE_INT(
                                      (float)(_mm_shuffle_ps(v20, v20, 85).m128_f32[0]
                                            + _mm_shuffle_ps(v20, v20, 0).m128_f32[0])
                                    + _mm_shuffle_ps(v20, v20, 170).m128_f32[0])) >> 1) >= _mm_shuffle_ps(
                                                                                             (__m128)LODWORD(FLOAT_0_99998999),
                                                                                             (__m128)LODWORD(FLOAT_0_99998999),
                                                                                             0).m128_f32[0]) )
  {
    v19 = stru_141A71280.m_quad;
    v27 = direction.m_quad;
    v29 = transform.m_quad;
  }
  else
  {
    v21 = _mm_shuffle_ps(v19, v19, 201);
    v22 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(stru_141A71280.m_quad, stru_141A71280.m_quad, 201), v19),
            _mm_mul_ps(v21, stru_141A71280.m_quad));
    v23 = _mm_shuffle_ps(v22, v22, 201);
    v24 = _mm_mul_ps(v23, v23);
    v25 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
            _mm_shuffle_ps(v24, v24, 170));
    v26 = _mm_rsqrt_ps(v25);
    v27 = _mm_mul_ps(
            v23,
            _mm_andnot_ps(
              _mm_cmple_ps(v25, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v25), v26)),
                _mm_mul_ps(v26, *(__m128 *)_xmm))));
    v28 = _mm_sub_ps(_mm_mul_ps(v27, v21), _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v19));
    v29 = _mm_shuffle_ps(v28, v28, 201);
  }
  v30 = (__m128)xmmword_141A711B0;
  v31 = v139;
  v32 = heightSamples + 2 * v7;
  v33 = _mm_mul_ps(_mm_add_ps(v11, v10), (__m128)xmmword_141A711B0);
  *(hkVector4f *)&a_8[32] = (hkVector4f)stru_141A71280.m_quad;
  axis.m_quad = _mm_mul_ps(direction.m_quad, g_vectorfConstants[0]);
  v34 = m_enum * (v32 - 1) + 2;
  v35 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)0i64, v139), (__m128)xmmword_141A711B0), stru_141A71280.m_quad);
  v36 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v35);
  v136 = v35;
  v135.m_real = _mm_sub_ps(v36, v35);
  if ( v34 > 0 )
  {
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, v34, 16);
    m_capacityAndFlags = array.m_capacityAndFlags;
    m_size = array.m_size;
    v16 = stru_141A71280.m_quad;
    v30 = (__m128)xmmword_141A711B0;
  }
  v37 = _mm_shuffle_ps((__m128)v143, (__m128)v143, 0);
  *(__m128 *)&a_8[8] = v37;
  v38 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v31, v30), v37), v16);
  v39 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v38, v38, 85), v27), _mm_mul_ps(_mm_shuffle_ps(v38, v38, 0), v29)),
            _mm_mul_ps(_mm_shuffle_ps(v38, v38, 170), v19)),
          v33);
  if ( m_size == (m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, 16);
    m_size = array.m_size;
  }
  v40 = (__m128)_xmm;
  v41 = 0i64;
  v41.m128_f32[0] = (float)v7;
  v42 = v7 - 1;
  v43 = _mm_shuffle_ps(v41, v41, 0);
  array.m_data[m_size] = (hkRelocationInfo::Import)v39;
  ++array.m_size;
  v44 = _mm_rcp_ps(v43);
  v45 = _mm_mul_ps(v44, v43);
  v46 = 0i64;
  v46.m128_f32[0] = (float)(int)m_enum;
  v47 = _mm_shuffle_ps(v46, v46, 0);
  v48 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v45), v44);
  v49 = _mm_rcp_ps(v47);
  v50 = _mm_mul_ps(v48, (__m128)xmmword_141A713C0);
  v140 = v50;
  v51 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v49, v47)), v49), (__m128)xmmword_141A713F0);
  *(__m128 *)&a_8[24] = v51;
  if ( v7 - 1 >= 0 )
  {
    v52 = _mm_shuffle_ps(transform.m_quad, transform.m_quad, 201);
    *(__m128 *)a_8 = v52;
    do
    {
      v53 = 0i64;
      v53.m128_f32[0] = (float)v42;
      angle.m_real = _mm_mul_ps(_mm_shuffle_ps(v53, v53, 0), v50);
      hkQuaternionf::setAxisAngle((hkQuaternionf *)&a_8[48], &axis, &angle);
      v54 = 0;
      v55 = _mm_mul_ps(*(__m128 *)&a_8[48], m_quad);
      v56 = _mm_shuffle_ps(*(__m128 *)&a_8[48], *(__m128 *)&a_8[48], 255);
      v57 = _mm_sub_ps(
              _mm_mul_ps(*(__m128 *)&a_8[48], v52),
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&a_8[48], *(__m128 *)&a_8[48], 201), m_quad));
      v58 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
                    _mm_shuffle_ps(v55, v55, 170)),
                  *(__m128 *)&a_8[48]),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v56, v56), (__m128)xmmword_141A711B0), m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v57, v57, 201), v56));
      v59 = _mm_add_ps(v58, v58);
      if ( (int)m_enum > 0 )
      {
        v60 = *(__m128 *)&a_8[24];
        v61 = _mm_shuffle_ps(v59, v59, 201);
        do
        {
          v62 = 0i64;
          v62.m128_f32[0] = (float)v54;
          *(__m128 *)&a_8[40] = _mm_mul_ps(_mm_shuffle_ps(v62, v62, 0), v60);
          hkQuaternionf::setAxisAngle((hkQuaternionf *)&a_8[16], (hkVector4f *)&a_8[32], (hkSimdFloat32 *)&a_8[40]);
          v63 = array.m_size;
          v64 = _mm_mul_ps(*(__m128 *)&a_8[16], v59);
          v65 = _mm_shuffle_ps(*(__m128 *)&a_8[16], *(__m128 *)&a_8[16], 255);
          v66 = _mm_sub_ps(
                  _mm_mul_ps(*(__m128 *)&a_8[16], v61),
                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&a_8[16], *(__m128 *)&a_8[16], 201), v59));
          v67 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v64, v64, 85), _mm_shuffle_ps(v64, v64, 0)),
                        _mm_shuffle_ps(v64, v64, 170)),
                      *(__m128 *)&a_8[16]),
                    _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v65, v65), (__m128)xmmword_141A711B0), v59)),
                  _mm_mul_ps(_mm_shuffle_ps(v66, v66, 201), v65));
          v68 = _mm_add_ps(_mm_mul_ps(_mm_add_ps(v67, v67), v37), v36);
          v69 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v68, v68, 85), v27),
                      _mm_mul_ps(_mm_shuffle_ps(v68, v68, 0), v29)),
                    _mm_mul_ps(_mm_shuffle_ps(v68, v68, 170), v19)),
                  v33);
          if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, 16);
            v63 = array.m_size;
          }
          ++v54;
          array.m_data[v63] = (hkRelocationInfo::Import)v69;
          ++array.m_size;
          v37 = *(__m128 *)&a_8[8];
        }
        while ( v54 < (int)m_enum );
        m_quad = v137;
      }
      --v42;
      v52 = *(__m128 *)a_8;
      v50 = v140;
    }
    while ( v42 >= 0 );
    v51 = *(__m128 *)&a_8[24];
    v40 = (__m128)_xmm;
  }
  v70 = 0i64;
  v70.m128_f32[0] = (float)heightSamples;
  v71 = heightSamples - 1;
  v72 = _mm_shuffle_ps(v70, v70, 0);
  v73 = _mm_rcp_ps(v72);
  v74 = _mm_mul_ps(_mm_sub_ps(v40, _mm_mul_ps(v73, v72)), v73);
  *(__m128 *)&a_8[40] = v74;
  if ( heightSamples - 1 > 0 )
  {
    v75 = v136;
    do
    {
      v76 = 0;
      if ( (int)m_enum > 0 )
      {
        v77 = 0i64;
        v77.m128_f32[0] = (float)v71;
        v78 = _mm_shuffle_ps(m_quad, m_quad, 201);
        v79 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(v77, v77, 0), v74), v135.m_real), v75);
        do
        {
          v80 = 0i64;
          v80.m128_f32[0] = (float)v76;
          *(__m128 *)a_8 = _mm_mul_ps(_mm_shuffle_ps(v80, v80, 0), v51);
          hkQuaternionf::setAxisAngle((hkQuaternionf *)&a_8[16], (hkVector4f *)&a_8[32], (hkSimdFloat32 *)a_8);
          v81 = array.m_size;
          v82 = _mm_mul_ps(*(__m128 *)&a_8[16], m_quad);
          v83 = _mm_shuffle_ps(*(__m128 *)&a_8[16], *(__m128 *)&a_8[16], 255);
          v84 = _mm_sub_ps(
                  _mm_mul_ps(*(__m128 *)&a_8[16], v78),
                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&a_8[16], *(__m128 *)&a_8[16], 201), m_quad));
          v85 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v82, v82, 85), _mm_shuffle_ps(v82, v82, 0)),
                        _mm_shuffle_ps(v82, v82, 170)),
                      *(__m128 *)&a_8[16]),
                    _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v83, v83), (__m128)xmmword_141A711B0), m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v84, v84, 201), v83));
          v86 = _mm_add_ps(_mm_mul_ps(_mm_add_ps(v85, v85), v37), v79);
          v87 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v86, v86, 85), v27),
                      _mm_mul_ps(_mm_shuffle_ps(v86, v86, 0), v29)),
                    _mm_mul_ps(_mm_shuffle_ps(v86, v86, 170), v19)),
                  v33);
          if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, 16);
            v81 = array.m_size;
          }
          v51 = *(__m128 *)&a_8[24];
          ++v76;
          array.m_data[v81] = (hkRelocationInfo::Import)v87;
          ++array.m_size;
          v37 = *(__m128 *)&a_8[8];
        }
        while ( v76 < (int)m_enum );
        v74 = *(__m128 *)&a_8[40];
      }
      v51 = *(__m128 *)&a_8[24];
      v37 = *(__m128 *)&a_8[8];
      --v71;
    }
    while ( v71 > 0 );
  }
  v88 = 0;
  if ( v7 > HK_SUCCESS )
  {
    v89 = _mm_shuffle_ps(m_quad, m_quad, 201);
    *(__m128 *)&a_8[48] = v89;
    do
    {
      v90 = 0i64;
      v90.m128_f32[0] = (float)v88;
      v135.m_real = _mm_mul_ps(_mm_sub_ps((__m128)0i64, _mm_shuffle_ps(v90, v90, 0)), v140);
      hkQuaternionf::setAxisAngle((hkQuaternionf *)a_8, &axis, &v135);
      v91 = 0;
      v92 = _mm_mul_ps(*(__m128 *)a_8, m_quad);
      v93 = _mm_shuffle_ps(*(__m128 *)a_8, *(__m128 *)a_8, 255);
      v94 = _mm_sub_ps(
              _mm_mul_ps(*(__m128 *)a_8, v89),
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)a_8, *(__m128 *)a_8, 201), m_quad));
      v95 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v92, v92, 85), _mm_shuffle_ps(v92, v92, 0)),
                    _mm_shuffle_ps(v92, v92, 170)),
                  *(__m128 *)a_8),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v93, v93), (__m128)xmmword_141A711B0), m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v94, v94, 201), v93));
      v96 = _mm_add_ps(v95, v95);
      if ( (int)m_enum > 0 )
      {
        v97 = *(__m128 *)&a_8[24];
        v98 = *(__m128 *)&a_8[8];
        v99 = _mm_shuffle_ps(v96, v96, 201);
        do
        {
          v100 = 0i64;
          v100.m128_f32[0] = (float)v91;
          *(__m128 *)&a_8[16] = _mm_mul_ps(_mm_shuffle_ps(v100, v100, 0), v97);
          hkQuaternionf::setAxisAngle((hkQuaternionf *)&a_8[40], (hkVector4f *)&a_8[32], (hkSimdFloat32 *)&a_8[16]);
          v101 = array.m_size;
          v102 = _mm_mul_ps(*(__m128 *)&a_8[40], v96);
          v103 = _mm_shuffle_ps(*(__m128 *)&a_8[40], *(__m128 *)&a_8[40], 255);
          v104 = _mm_sub_ps(
                   _mm_mul_ps(v99, *(__m128 *)&a_8[40]),
                   _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&a_8[40], *(__m128 *)&a_8[40], 201), v96));
          v105 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v102, v102, 85), _mm_shuffle_ps(v102, v102, 0)),
                         _mm_shuffle_ps(v102, v102, 170)),
                       *(__m128 *)&a_8[40]),
                     _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v103, v103), (__m128)xmmword_141A711B0), v96)),
                   _mm_mul_ps(_mm_shuffle_ps(v104, v104, 201), v103));
          v106 = _mm_add_ps(_mm_mul_ps(_mm_add_ps(v105, v105), v98), v136);
          v107 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v106, v106, 85), v27),
                       _mm_mul_ps(_mm_shuffle_ps(v106, v106, 0), v29)),
                     _mm_mul_ps(_mm_shuffle_ps(v106, v106, 170), v19)),
                   v33);
          if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, 16);
            v101 = array.m_size;
          }
          ++v91;
          array.m_data[v101] = (hkRelocationInfo::Import)v107;
          ++array.m_size;
        }
        while ( v91 < (int)m_enum );
        m_quad = v137;
        v89 = *(__m128 *)&a_8[48];
      }
      ++v88;
    }
    while ( v88 < v7 );
  }
  v108 = _mm_mul_ps(
           _mm_sub_ps((__m128)0i64, _mm_add_ps(_mm_mul_ps(v139, (__m128)xmmword_141A711B0), *(__m128 *)&a_8[8])),
           stru_141A71280.m_quad);
  v109 = _mm_add_ps(
           _mm_add_ps(
             _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v108, v108, 85), v27), _mm_mul_ps(_mm_shuffle_ps(v108, v108, 0), v29)),
             _mm_mul_ps(_mm_shuffle_ps(v108, v108, 170), v19)),
           v33);
  if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, 16);
  v110 = 0;
  array.m_data[array.m_size++] = (hkRelocationInfo::Import)v109;
  if ( array.m_size > 0 )
  {
    v111 = vars0;
    v112 = 0i64;
    do
    {
      ++v110;
      v113 = (__m128)array.m_data[v112++];
      array.m_data[v112 - 1] = (hkRelocationInfo::Import)_mm_add_ps(
                                                           _mm_add_ps(
                                                             _mm_add_ps(
                                                               _mm_mul_ps(_mm_shuffle_ps(v113, v113, 85), v111[1]),
                                                               _mm_mul_ps(_mm_shuffle_ps(v113, v113, 0), *v111)),
                                                             _mm_mul_ps(_mm_shuffle_ps(v113, v113, 170), v111[2])),
                                                           v111[3]);
    }
    while ( v110 < array.m_size );
  }
  v114 = 0;
  v115 = 1;
  a = 0i64;
  *(_DWORD *)&a_8[4] = 0x80000000;
  *(_DWORD *)a_8 = 0;
  v116 = 1;
  if ( (int)m_enum > 0 )
  {
    v117 = 1;
    v118 = m_enum;
    do
    {
      if ( v114 == (*(_DWORD *)&a_8[4] & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&a, 16);
        v114 = *(_DWORD *)a_8;
      }
      v119 = &a[16 * v114];
      *(_DWORD *)v119 = 0;
      *((_DWORD *)v119 + 1) = v117;
      *((_DWORD *)v119 + 2) = v117 % (int)m_enum + 1;
      *((_DWORD *)v119 + 3) = -1;
      ++v117;
      v114 = ++*(_DWORD *)a_8;
      --v118;
    }
    while ( v118 );
  }
  v120 = (unsigned int)(v32 - 2);
  if ( v32 - 2 > 0 )
  {
    v142 = (unsigned int)(v32 - 2);
    do
    {
      if ( (int)m_enum > 0 )
      {
        v121 = m_enum;
        do
        {
          v122 = v115 + v116 - 1;
          v123 = v115 % (int)m_enum + v116;
          v124 = v123 + m_enum;
          if ( v114 == (*(_DWORD *)&a_8[4] & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&a, 16);
            v114 = *(_DWORD *)a_8;
          }
          v125 = &a[16 * v114];
          *(_DWORD *)v125 = v122;
          *((_DWORD *)v125 + 1) = v122 + m_enum;
          *((_DWORD *)v125 + 2) = v124;
          *((_DWORD *)v125 + 3) = -1;
          v126 = *(_DWORD *)a_8 + 1;
          *(_DWORD *)a_8 = v126;
          if ( v126 == (*(_DWORD *)&a_8[4] & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&a, 16);
            v126 = *(_DWORD *)a_8;
          }
          ++v115;
          v127 = &a[16 * v126];
          *(_DWORD *)v127 = v123;
          *((_DWORD *)v127 + 1) = v122;
          *((_DWORD *)v127 + 2) = v124;
          *((_DWORD *)v127 + 3) = -1;
          v114 = ++*(_DWORD *)a_8;
          --v121;
        }
        while ( v121 );
        v120 = v142;
        v115 = 1;
      }
      v116 += m_enum;
      v142 = --v120;
    }
    while ( v120 );
  }
  if ( (int)m_enum > 0 )
  {
    v128 = m_enum;
    do
    {
      v129 = v115 + v116 - 1;
      v130 = v116 + v115 % (int)m_enum;
      if ( v114 == (*(_DWORD *)&a_8[4] & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&a, 16);
        v114 = *(_DWORD *)a_8;
      }
      ++v115;
      v131 = &a[16 * v114];
      *(_DWORD *)v131 = v130;
      *((_DWORD *)v131 + 1) = v129;
      *((_DWORD *)v131 + 2) = v116 + m_enum;
      *((_DWORD *)v131 + 3) = -1;
      v114 = ++*(_DWORD *)a_8;
      --v128;
    }
    while ( v128 );
  }
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(retaddr + 1, &array);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    retaddr + 2,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&a);
  *(_DWORD *)a_8 = 0;
  if ( *(int *)&a_8[4] >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, a, 16 * *(_DWORD *)&a_8[4]);
  a = 0i64;
  *(_DWORD *)&a_8[4] = 0x80000000;
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array.m_data,
      16 * array.m_capacityAndFlags);
}

// File Line: 922
// RVA: 0xC9FC90
void __fastcall hkGeometryUtils::createTaperedCapsuleGeometry(
        hkVector4f *start,
        hkVector4f *end,
        float startRadius,
        float endRadius)
{
  __int64 m_enum; // rbx
  __m128 m_quad; // xmm5
  int m_capacityAndFlags; // ecx
  hkResultEnum v8; // r15d
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
  int v39; // r14d
  int v40; // r13d
  __m128 v41; // xmm14
  __m128 v42; // xmm1
  int v43; // r9d
  __m128 v44; // xmm1
  __m128 v45; // xmm6
  __m128 v46; // xmm1
  __m128 v47; // xmm3
  __m128 v48; // xmm0
  __m128 v49; // xmm3
  __m128 v50; // xmm2
  __m128 v51; // xmm1
  __m128 v52; // xmm9
  __m128 v53; // xmm7
  __m128 v54; // xmm2
  __m128 v55; // xmm5
  __m128 v56; // xmm4
  __m128 v57; // xmm3
  __m128 v58; // xmm2
  __m128 v59; // xmm3
  __m128 v60; // xmm0
  int v61; // esi
  __m128 v62; // xmm1
  __m128 v63; // xmm1
  __m128 v64; // xmm0
  __m128 v65; // xmm2
  __m128 v66; // xmm4
  __m128 v67; // xmm1
  __m128 v68; // xmm4
  __m128 v69; // xmm1
  __m128 v70; // xmm0
  __m128 v71; // xmm8
  __m128 v72; // xmm0
  __m128 v73; // xmm2
  __m128 v74; // xmm2
  int v75; // edi
  __m128 v76; // xmm1
  __m128 v77; // xmm5
  __m128 v78; // xmm4
  __m128 v79; // xmm7
  __m128 v80; // xmm7
  __m128 v81; // xmm9
  __m128 v82; // xmm0
  int m_size; // ecx
  __m128 v84; // xmm1
  __m128 v85; // xmm4
  __m128 v86; // xmm3
  __m128 v87; // xmm5
  __m128 v88; // xmm5
  __m128 v89; // xmm6
  __m128 v90; // xmm6
  __m128 v91; // xmm1
  int v92; // esi
  __m128 v93; // xmm1
  __m128 m_real; // xmm2
  __m128 v95; // xmm0
  __m128 v96; // xmm0
  __m128 v97; // xmm3
  int v98; // edi
  __m128 v99; // xmm7
  __m128 v100; // xmm7
  __m128 v101; // xmm15
  __m128 v102; // xmm9
  __m128 v103; // xmm0
  int v104; // ecx
  __m128 v105; // xmm1
  __m128 v106; // xmm5
  __m128 v107; // xmm4
  __m128 v108; // xmm6
  __m128 v109; // xmm1
  __m128 v110; // xmm1
  __m128 v111; // xmm6
  int v112; // esi
  __m128 v113; // xmm15
  __m128 v114; // xmm1
  __m128 v115; // xmm1
  int v116; // edi
  __m128 v117; // xmm1
  __m128 v118; // xmm5
  __m128 v119; // xmm4
  __m128 v120; // xmm7
  __m128 v121; // xmm7
  __m128 v122; // xmm9
  __m128 v123; // xmm0
  int v124; // ecx
  __m128 v125; // xmm1
  __m128 v126; // xmm4
  __m128 v127; // xmm3
  __m128 v128; // xmm5
  __m128 v129; // xmm5
  __m128 v130; // xmm6
  __m128 v131; // xmm10
  __m128 v132; // xmm6
  int v133; // r8d
  __int64 v134; // rdx
  __m128 v135; // xmm1
  int v136; // ecx
  int v137; // edi
  int v138; // r12d
  int v139; // esi
  __int64 v140; // r15
  char *v141; // rax
  __int64 v142; // rax
  __int64 v143; // r13
  int v144; // esi
  int v145; // r14d
  int v146; // r15d
  char *v147; // rax
  int v148; // ecx
  char *v149; // rax
  __int64 v150; // r14
  int v151; // r15d
  int v152; // esi
  char *v153; // rax
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> array; // [rsp+30h] [rbp-98h] BYREF
  char *a; // [rsp+40h] [rbp-88h] BYREF
  _BYTE a_8[64]; // [rsp+48h] [rbp-80h] BYREF
  hkSimdFloat32 v157; // [rsp+88h] [rbp-40h] BYREF
  hkQuaternionf v158; // [rsp+98h] [rbp-30h] BYREF
  __m128 v159; // [rsp+A8h] [rbp-20h]
  __m128 v160; // [rsp+B8h] [rbp-10h]
  hkSimdFloat32 v161; // [rsp+C8h] [rbp+0h] BYREF
  __m128 v162; // [rsp+D8h] [rbp+10h]
  hkRotationf v163; // [rsp+E8h] [rbp+20h] BYREF
  __int64 v164; // [rsp+1F8h] [rbp+130h]
  unsigned int v165; // [rsp+208h] [rbp+140h]
  unsigned int v166; // [rsp+210h] [rbp+148h]
  int v167; // [rsp+218h] [rbp+150h]
  hkResult result; // [rsp+220h] [rbp+158h] BYREF
  __m128 *retaddr; // [rsp+228h] [rbp+160h]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v170; // [rsp+230h] [rbp+168h]

  m_enum = (unsigned int)result.m_enum;
  m_quad = stru_141A71280.m_quad;
  m_capacityAndFlags = 0x80000000;
  v8 = result.m_enum >> 1;
  v10 = _mm_shuffle_ps((__m128)v166, (__m128)v166, 0);
  array.m_data = 0i64;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  v11 = _mm_shuffle_ps((__m128)v165, (__m128)v165, 0);
  v12 = _mm_cmplt_ps(v10, v11);
  v13 = _mm_andnot_ps(v12, end->m_quad);
  v14 = _mm_or_ps(_mm_and_ps(v10, v12), _mm_andnot_ps(v12, v11));
  v15 = _mm_or_ps(_mm_and_ps(v11, v12), _mm_andnot_ps(v12, v10));
  v16 = _mm_and_ps(v12, end->m_quad);
  *(__m128 *)&a_8[24] = v14;
  v17 = _mm_sub_ps(_mm_or_ps(v13, _mm_and_ps(v12, start->m_quad)), _mm_or_ps(v16, _mm_andnot_ps(v12, start->m_quad)));
  v18 = _mm_mul_ps(v17, v17);
  v19 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)), _mm_shuffle_ps(v18, v18, 170));
  v20 = _mm_rsqrt_ps(v19);
  v21 = _mm_andnot_ps(
          _mm_cmple_ps(v19, (__m128)0i64),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)), _mm_mul_ps(v20, *(__m128 *)_xmm)));
  v22 = _mm_mul_ps(v17, v21);
  v23 = _mm_add_ps(_mm_mul_ps(v21, v19), *(__m128 *)&epsilon);
  v160 = v23;
  if ( v23.m128_f32[0] <= (float)(0.00000011920929 + 0.00000011920929) )
    goto LABEL_6;
  v24 = _mm_mul_ps(v22, v22);
  v25 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)), _mm_shuffle_ps(v24, v24, 170));
  v26 = _mm_rsqrt_ps(v25);
  result.m_enum = LODWORD(FLOAT_0_99998999);
  v27 = _mm_mul_ps(
          v22,
          _mm_andnot_ps(
            _mm_cmple_ps(v25, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v25), v26)),
              _mm_mul_ps(v26, *(__m128 *)_xmm))));
  v28 = _mm_mul_ps(stru_141A71280.m_quad, v27);
  if ( COERCE_FLOAT((unsigned int)(2
                                 * COERCE_INT(
                                     (float)(_mm_shuffle_ps(v28, v28, 85).m128_f32[0]
                                           + _mm_shuffle_ps(v28, v28, 0).m128_f32[0])
                                   + _mm_shuffle_ps(v28, v28, 170).m128_f32[0])) >> 1) < _mm_shuffle_ps(
                                                                                           (__m128)LODWORD(FLOAT_0_99998999),
                                                                                           (__m128)LODWORD(FLOAT_0_99998999),
                                                                                           0).m128_f32[0] )
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
              _mm_cmple_ps(v33, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v34, v33), v34)),
                _mm_mul_ps(v34, *(__m128 *)_xmm))));
    v36 = _mm_sub_ps(_mm_mul_ps(v29, v35), _mm_mul_ps(_mm_shuffle_ps(v35, v35, 201), v27));
    v37 = _mm_shuffle_ps(v36, v36, 201);
    goto LABEL_7;
  }
  if ( (float)((float)(_mm_shuffle_ps(v28, v28, 85).m128_f32[0] + _mm_shuffle_ps(v28, v28, 0).m128_f32[0])
             + _mm_shuffle_ps(v28, v28, 170).m128_f32[0]) >= 0.0 )
  {
LABEL_6:
    v35 = direction.m_quad;
    v37 = transform.m_quad;
    v27 = stru_141A71280.m_quad;
  }
  else
  {
    *(_OWORD *)&a_8[32] = xmmword_141A713B0;
    hkRotationf::setAxisAngle(&v163, &transform, (hkSimdFloat32 *)&a_8[32]);
    m_capacityAndFlags = array.m_capacityAndFlags;
    v37 = v163.m_col0.m_quad;
    v35 = v163.m_col1.m_quad;
    v27 = v163.m_col2.m_quad;
    m_quad = stru_141A71280.m_quad;
  }
LABEL_7:
  v38 = (__m128)xmmword_141A711B0;
  v39 = v167;
  v40 = v167 + 2 * v8;
  v41 = _mm_mul_ps(_mm_add_ps(end->m_quad, start->m_quad), (__m128)xmmword_141A711B0);
  v42 = _mm_mul_ps(_mm_mul_ps(v23, (__m128)xmmword_141A711B0), m_quad);
  *(_QWORD *)&a_8[48] = v42.m128_u64[1];
  v43 = m_enum * (v40 - 1) + 2;
  *(__m128 *)&a_8[32] = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v42);
  if ( (m_capacityAndFlags & 0x3FFFFFFF) < v43 )
  {
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, v43, 16);
    m_capacityAndFlags = array.m_capacityAndFlags;
    m_quad = stru_141A71280.m_quad;
    v38 = (__m128)xmmword_141A711B0;
  }
  v44 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v23, v38), v15), m_quad);
  v45 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v44, v44, 85), v35), _mm_mul_ps(_mm_shuffle_ps(v44, v44, 0), v37)),
            _mm_mul_ps(_mm_shuffle_ps(v44, v44, 170), v27)),
          v41);
  if ( array.m_size == (m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, 16);
  v46 = _mm_rcp_ps(v23);
  array.m_data[array.m_size++] = (hkRelocationInfo::Import)v45;
  v47 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v46, v23)), v46), _mm_sub_ps(v15, v14));
  v48 = _mm_cmplt_ps(v47, query.m_quad);
  v49 = _mm_max_ps(g_vectorfConstants[0], _mm_or_ps(_mm_andnot_ps(v48, query.m_quad), _mm_and_ps(v48, v47)));
  *(_QWORD *)a_8 = v49.m128_u64[0];
  v50 = _mm_sub_ps(query.m_quad, _mm_mul_ps(v49, v49));
  v51 = _mm_rsqrt_ps(v50);
  *(__m128 *)&a_8[8] = _mm_andnot_ps(
                         _mm_cmple_ps(v50, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v51, v50), v51)),
                             _mm_mul_ps(v51, *(__m128 *)_xmm)),
                           v50));
  v52 = _mm_min_ps(
          _mm_max_ps((__m128)v49.m128_u32[0], *(__m128 *)_xmm_bf800000bf800000bf800000bf800000),
          *(__m128 *)_xmm);
  v53 = _mm_andnot_ps(*(__m128 *)_xmm, v52);
  v54 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v53), *(__m128 *)_xmm);
  v55 = _mm_cmplt_ps(*(__m128 *)_xmm, v53);
  v56 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v54), v55), _mm_andnot_ps(v55, v53));
  v57 = _mm_or_ps(_mm_andnot_ps(v55, _mm_mul_ps(v53, v53)), _mm_and_ps(v55, v54));
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
  v60 = _mm_cmplt_ps(v53, *(__m128 *)_xmm);
  v61 = v8 - 1;
  v62 = 0i64;
  v62.m128_f32[0] = (float)v8;
  result.m_enum = (_mm_andnot_ps(
                     v60,
                     _mm_or_ps(
                       _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v58, v58)), v55),
                       _mm_andnot_ps(v55, v58))).m128_u32[0] | v60.m128_i32[0] & v53.m128_i32[0]) ^ v52.m128_i32[0] & _xmm[0];
  v63 = _mm_shuffle_ps(v62, v62, 0);
  v64 = _mm_rcp_ps(v63);
  v65 = _mm_shuffle_ps((__m128)(unsigned int)result.m_enum, (__m128)(unsigned int)result.m_enum, 0);
  v162 = v65;
  v66 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v63, v64));
  v67 = 0i64;
  v67.m128_f32[0] = (float)(int)m_enum;
  v68 = _mm_mul_ps(v66, v64);
  v159 = v68;
  v69 = _mm_shuffle_ps(v67, v67, 0);
  v70 = _mm_rcp_ps(v69);
  v71 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v69, v70)), v70), (__m128)xmmword_141A713F0);
  if ( v8 - 1 >= 0 )
  {
    v72 = _mm_sub_ps((__m128)0i64, v65);
    *(__m128 *)&a_8[16] = v72;
    do
    {
      v73 = 0i64;
      v73.m128_f32[0] = (float)v61;
      v74 = _mm_mul_ps(_mm_shuffle_ps(v73, v73, 0), v68);
      v161.m_real = _mm_sub_ps(
                      (__m128)0i64,
                      _mm_add_ps(
                        _mm_mul_ps(_mm_sub_ps(query.m_quad, v74), v72),
                        _mm_mul_ps((__m128)xmmword_141A713C0, v74)));
      hkQuaternionf::setAxisAngle((hkQuaternionf *)&a_8[48], &direction, &v161);
      v75 = 0;
      v76 = _mm_mul_ps(*(__m128 *)&a_8[48], transform.m_quad);
      v77 = _mm_shuffle_ps(*(__m128 *)&a_8[48], *(__m128 *)&a_8[48], 255);
      v78 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(transform.m_quad, transform.m_quad, 201), *(__m128 *)&a_8[48]),
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&a_8[48], *(__m128 *)&a_8[48], 201), transform.m_quad));
      v79 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v76, v76, 85), _mm_shuffle_ps(v76, v76, 0)),
                    _mm_shuffle_ps(v76, v76, 170)),
                  *(__m128 *)&a_8[48]),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v77, v77), (__m128)xmmword_141A711B0), transform.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v78, v78, 201), v77));
      v80 = _mm_add_ps(v79, v79);
      if ( (int)m_enum > 0 )
      {
        v81 = _mm_shuffle_ps(v80, v80, 201);
        do
        {
          v82 = 0i64;
          v82.m128_f32[0] = (float)v75;
          v157.m_real = _mm_mul_ps(_mm_shuffle_ps(v82, v82, 0), v71);
          hkQuaternionf::setAxisAngle(&v158, &stru_141A71280, &v157);
          m_size = array.m_size;
          v84 = _mm_mul_ps(v158.m_vec.m_quad, v80);
          v85 = _mm_shuffle_ps(v158.m_vec.m_quad, v158.m_vec.m_quad, 255);
          v86 = _mm_sub_ps(
                  _mm_mul_ps(v81, v158.m_vec.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v158.m_vec.m_quad, v158.m_vec.m_quad, 201), v80));
          v87 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v84, v84, 85), _mm_shuffle_ps(v84, v84, 0)),
                        _mm_shuffle_ps(v84, v84, 170)),
                      v158.m_vec.m_quad),
                    _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v85, v85), (__m128)xmmword_141A711B0), v80)),
                  _mm_mul_ps(_mm_shuffle_ps(v86, v86, 201), v85));
          v88 = _mm_add_ps(_mm_mul_ps(_mm_add_ps(v87, v87), v15), *(__m128 *)&a_8[40]);
          v89 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v88, v88, 85), v35),
                      _mm_mul_ps(_mm_shuffle_ps(v88, v88, 0), v37)),
                    _mm_mul_ps(_mm_shuffle_ps(v88, v88, 170), v27)),
                  v41);
          if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, 16);
            m_size = array.m_size;
          }
          ++v75;
          array.m_data[m_size] = (hkRelocationInfo::Import)v89;
          ++array.m_size;
        }
        while ( v75 < (int)m_enum );
      }
      --v61;
      v72 = *(__m128 *)&a_8[16];
      v68 = v159;
    }
    while ( v61 >= 0 );
    v59 = (__m128)_xmm;
  }
  v90 = *(__m128 *)&a_8[24];
  v91 = 0i64;
  v91.m128_f32[0] = (float)v39;
  v92 = v39 - 1;
  v93 = _mm_shuffle_ps(v91, v91, 0);
  *(_QWORD *)&a_8[40] = _mm_mul_ps(_mm_sub_ps((__m128)0i64, *(__m128 *)&a_8[24]), *(__m128 *)a_8).m128_u64[0];
  m_real = _mm_sub_ps(v160, _mm_mul_ps(v15, *(__m128 *)a_8));
  v95 = _mm_mul_ps(*(__m128 *)&a_8[24], *(__m128 *)&a_8[8]);
  *(__m128 *)&a_8[8] = _mm_mul_ps(v15, *(__m128 *)&a_8[8]);
  v157.m_real = m_real;
  v158.m_vec.m_quad = v95;
  v96 = _mm_rcp_ps(v93);
  v97 = _mm_mul_ps(_mm_sub_ps(v59, _mm_mul_ps(v93, v96)), v96);
  *(__m128 *)&a_8[48] = v97;
  if ( v39 - 1 > 0 )
  {
    do
    {
      v98 = 0;
      if ( (int)m_enum > 0 )
      {
        v99 = 0i64;
        v99.m128_f32[0] = (float)v92;
        v100 = _mm_mul_ps(_mm_shuffle_ps(v99, v99, 0), v97);
        v101 = _mm_mul_ps(v100, *(__m128 *)&a_8[8]);
        v102 = _mm_mul_ps(v100, m_real);
        do
        {
          v103 = 0i64;
          v103.m128_f32[0] = (float)v98;
          *(__m128 *)a_8 = _mm_mul_ps(_mm_shuffle_ps(v103, v103, 0), v71);
          hkQuaternionf::setAxisAngle((hkQuaternionf *)&a_8[16], &stru_141A71280, (hkSimdFloat32 *)a_8);
          v104 = array.m_size;
          v105 = _mm_mul_ps(*(__m128 *)&a_8[16], transform.m_quad);
          v106 = _mm_shuffle_ps(*(__m128 *)&a_8[16], *(__m128 *)&a_8[16], 255);
          v107 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(transform.m_quad, transform.m_quad, 201), *(__m128 *)&a_8[16]),
                   _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&a_8[16], *(__m128 *)&a_8[16], 201), transform.m_quad));
          v108 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v105, v105, 85), _mm_shuffle_ps(v105, v105, 0)),
                         _mm_shuffle_ps(v105, v105, 170)),
                       *(__m128 *)&a_8[16]),
                     _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v106, v106), (__m128)xmmword_141A711B0), transform.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(v107, v107, 201), v106));
          v109 = _mm_sub_ps(query.m_quad, v100);
          v110 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v109, *(__m128 *)&a_8[40]), v102), stru_141A71280.m_quad),
                     *(__m128 *)&a_8[32]),
                   _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v109, v158.m_vec.m_quad), v101), _mm_add_ps(v108, v108)));
          v111 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v110, v110, 85), v35),
                       _mm_mul_ps(_mm_shuffle_ps(v110, v110, 0), v37)),
                     _mm_mul_ps(_mm_shuffle_ps(v110, v110, 170), v27)),
                   v41);
          if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, 16);
            v104 = array.m_size;
          }
          ++v98;
          array.m_data[v104] = (hkRelocationInfo::Import)v111;
          ++array.m_size;
        }
        while ( v98 < (int)m_enum );
        m_real = v157.m_real;
        v97 = *(__m128 *)&a_8[48];
      }
      --v92;
    }
    while ( v92 > 0 );
    v90 = *(__m128 *)&a_8[24];
  }
  v112 = 0;
  if ( v8 > HK_SUCCESS )
  {
    v113 = v159;
    do
    {
      v114 = 0i64;
      v114.m128_f32[0] = (float)v112;
      v115 = _mm_mul_ps(_mm_shuffle_ps(v114, v114, 0), v113);
      *(__m128 *)&a_8[8] = _mm_add_ps(
                             _mm_mul_ps(_mm_sub_ps(query.m_quad, v115), v162),
                             _mm_mul_ps(v115, (__m128)xmmword_141A713C0));
      hkQuaternionf::setAxisAngle((hkQuaternionf *)a_8, &direction, (hkSimdFloat32 *)&a_8[8]);
      v116 = 0;
      v117 = _mm_mul_ps(*(__m128 *)a_8, transform.m_quad);
      v118 = _mm_shuffle_ps(*(__m128 *)a_8, *(__m128 *)a_8, 255);
      v119 = _mm_sub_ps(
               _mm_mul_ps(_mm_shuffle_ps(transform.m_quad, transform.m_quad, 201), *(__m128 *)a_8),
               _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)a_8, *(__m128 *)a_8, 201), transform.m_quad));
      v120 = _mm_add_ps(
               _mm_add_ps(
                 _mm_mul_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v117, v117, 85), _mm_shuffle_ps(v117, v117, 0)),
                     _mm_shuffle_ps(v117, v117, 170)),
                   *(__m128 *)a_8),
                 _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v118, v118), (__m128)xmmword_141A711B0), transform.m_quad)),
               _mm_mul_ps(_mm_shuffle_ps(v119, v119, 201), v118));
      v121 = _mm_add_ps(v120, v120);
      if ( (int)m_enum > 0 )
      {
        v122 = _mm_shuffle_ps(v121, v121, 201);
        do
        {
          v123 = 0i64;
          v123.m128_f32[0] = (float)v116;
          *(__m128 *)&a_8[16] = _mm_mul_ps(_mm_shuffle_ps(v123, v123, 0), v71);
          hkQuaternionf::setAxisAngle((hkQuaternionf *)&a_8[40], &stru_141A71280, (hkSimdFloat32 *)&a_8[16]);
          v124 = array.m_size;
          v125 = _mm_mul_ps(*(__m128 *)&a_8[40], v121);
          v126 = _mm_shuffle_ps(*(__m128 *)&a_8[40], *(__m128 *)&a_8[40], 255);
          v127 = _mm_sub_ps(
                   _mm_mul_ps(v122, *(__m128 *)&a_8[40]),
                   _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&a_8[40], *(__m128 *)&a_8[40], 201), v121));
          v128 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v125, v125, 85), _mm_shuffle_ps(v125, v125, 0)),
                         _mm_shuffle_ps(v125, v125, 170)),
                       *(__m128 *)&a_8[40]),
                     _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v126, v126), (__m128)xmmword_141A711B0), v121)),
                   _mm_mul_ps(_mm_shuffle_ps(v127, v127, 201), v126));
          v129 = _mm_add_ps(_mm_mul_ps(_mm_add_ps(v128, v128), v90), *(__m128 *)&a_8[32]);
          v130 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v129, v129, 85), v35),
                       _mm_mul_ps(_mm_shuffle_ps(v129, v129, 0), v37)),
                     _mm_mul_ps(_mm_shuffle_ps(v129, v129, 170), v27)),
                   v41);
          if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, 16);
            v124 = array.m_size;
          }
          ++v116;
          array.m_data[v124] = (hkRelocationInfo::Import)v130;
          ++array.m_size;
          v90 = *(__m128 *)&a_8[24];
        }
        while ( v116 < (int)m_enum );
      }
      v90 = *(__m128 *)&a_8[24];
      ++v112;
    }
    while ( v112 < v8 );
  }
  v131 = _mm_mul_ps(
           _mm_sub_ps((__m128)0i64, _mm_add_ps(_mm_mul_ps(v160, (__m128)xmmword_141A711B0), *(__m128 *)&a_8[24])),
           stru_141A71280.m_quad);
  v132 = _mm_add_ps(
           _mm_add_ps(
             _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v131, v131, 85), v35), _mm_mul_ps(_mm_shuffle_ps(v131, v131, 0), v37)),
             _mm_mul_ps(_mm_shuffle_ps(v131, v131, 170), v27)),
           v41);
  if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, 16);
  v133 = 0;
  array.m_data[array.m_size++] = (hkRelocationInfo::Import)v132;
  if ( array.m_size > 0 )
  {
    v134 = 0i64;
    do
    {
      ++v133;
      v135 = (__m128)array.m_data[v134++];
      array.m_data[v134 - 1] = (hkRelocationInfo::Import)_mm_add_ps(
                                                           _mm_add_ps(
                                                             _mm_add_ps(
                                                               _mm_mul_ps(_mm_shuffle_ps(v135, v135, 85), retaddr[1]),
                                                               _mm_mul_ps(_mm_shuffle_ps(v135, v135, 0), *retaddr)),
                                                             _mm_mul_ps(_mm_shuffle_ps(v135, v135, 170), retaddr[2])),
                                                           retaddr[3]);
    }
    while ( v133 < array.m_size );
  }
  v136 = 0;
  v137 = 1;
  a = 0i64;
  *(_DWORD *)&a_8[4] = 0x80000000;
  *(_DWORD *)a_8 = 0;
  v138 = 1;
  if ( (int)m_enum > 0 )
  {
    v139 = 1;
    v140 = m_enum;
    do
    {
      if ( v136 == (*(_DWORD *)&a_8[4] & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&a, 16);
        v136 = *(_DWORD *)a_8;
      }
      v141 = &a[16 * v136];
      *(_DWORD *)v141 = 0;
      *((_DWORD *)v141 + 1) = v139;
      *((_DWORD *)v141 + 2) = v139 % (int)m_enum + 1;
      *((_DWORD *)v141 + 3) = -1;
      ++v139;
      v136 = ++*(_DWORD *)a_8;
      --v140;
    }
    while ( v140 );
  }
  v142 = (unsigned int)(v40 - 2);
  if ( v40 - 2 > 0 )
  {
    v164 = (unsigned int)(v40 - 2);
    do
    {
      if ( (int)m_enum > 0 )
      {
        v143 = m_enum;
        do
        {
          v144 = v137 + v138 - 1;
          v145 = v137 % (int)m_enum + v138;
          v146 = v145 + m_enum;
          if ( v136 == (*(_DWORD *)&a_8[4] & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&a, 16);
            v136 = *(_DWORD *)a_8;
          }
          v147 = &a[16 * v136];
          *(_DWORD *)v147 = v144;
          *((_DWORD *)v147 + 1) = v144 + m_enum;
          *((_DWORD *)v147 + 2) = v146;
          *((_DWORD *)v147 + 3) = -1;
          v148 = *(_DWORD *)a_8 + 1;
          *(_DWORD *)a_8 = v148;
          if ( v148 == (*(_DWORD *)&a_8[4] & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&a, 16);
            v148 = *(_DWORD *)a_8;
          }
          ++v137;
          v149 = &a[16 * v148];
          *(_DWORD *)v149 = v145;
          *((_DWORD *)v149 + 1) = v144;
          *((_DWORD *)v149 + 2) = v146;
          *((_DWORD *)v149 + 3) = -1;
          v136 = ++*(_DWORD *)a_8;
          --v143;
        }
        while ( v143 );
        v142 = v164;
        v137 = 1;
      }
      v138 += m_enum;
      v164 = --v142;
    }
    while ( v142 );
  }
  if ( (int)m_enum > 0 )
  {
    v150 = m_enum;
    do
    {
      v151 = v137 + v138 - 1;
      v152 = v138 + v137 % (int)m_enum;
      if ( v136 == (*(_DWORD *)&a_8[4] & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&a, 16);
        v136 = *(_DWORD *)a_8;
      }
      ++v137;
      v153 = &a[16 * v136];
      *(_DWORD *)v153 = v152;
      *((_DWORD *)v153 + 1) = v151;
      *((_DWORD *)v153 + 2) = v138 + m_enum;
      *((_DWORD *)v153 + 3) = -1;
      v136 = ++*(_DWORD *)a_8;
      --v150;
    }
    while ( v150 );
  }
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(v170 + 1, &array);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    v170 + 2,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&a);
  *(_DWORD *)a_8 = 0;
  if ( *(int *)&a_8[4] >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, a, 16 * *(_DWORD *)&a_8[4]);
  a = 0i64;
  *(_DWORD *)&a_8[4] = 0x80000000;
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array.m_data,
      16 * array.m_capacityAndFlags);
}fptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array.m_data,
      16 * array.m_capacityAndFlags);
}

// File Line: 1174
// RVA: 0xCA0C00
void __fastcall hkGeometryUtils::createCylinderGeometry(
        hkVector4f *top,
        hkVector4f *bottom,
        float radius,
        int numSides)
{
  __int64 v4; // r13
  float v6; // xmm6_4
  __m128 v7; // xmm7
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm2
  __m128 v11; // xmm5
  __m128 m_quad; // xmm0
  __m128 v13; // xmm4
  __m128 v14; // xmm4
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __int64 v18; // rdi
  __int64 v19; // rbx
  int v20; // r9d
  int v21; // eax
  int v22; // eax
  __int64 v23; // rdi
  int v24; // eax
  int v25; // r9d
  int v26; // eax
  __m128 v27; // xmm6
  int v28; // eax
  unsigned __int64 v29; // rcx
  __int64 v30; // r15
  __m128 v31; // xmm6
  __int64 v32; // rsi
  __int64 v33; // rdi
  int v34; // r9d
  int v35; // eax
  int v36; // eax
  __int64 v37; // rdi
  int v38; // r9d
  int v39; // eax
  int v40; // eax
  __m128 v41; // xmm5
  __m128 v42; // xmm6
  __m128 v43; // xmm3
  __m128 v44; // xmm4
  __m128 v45; // xmm6
  hkResultEnum m_enum; // eax
  int v47; // r15d
  int v48; // edi
  int v49; // esi
  int v50; // r14d
  int v51; // r12d
  __int64 v52; // rbx
  unsigned __int64 v53; // rcx
  __int64 v54; // r13
  int v55; // r9d
  int v56; // eax
  int v57; // eax
  int *v58; // rax
  __int64 v59; // r13
  int v60; // r9d
  int v61; // eax
  int v62; // eax
  int *v63; // rax
  int i; // r15d
  int v65; // esi
  int v66; // esi
  __int64 v67; // rbx
  __int64 v68; // r13
  int v69; // edi
  __int64 v70; // r14
  int v71; // eax
  int v72; // r9d
  int v73; // eax
  int *v74; // rax
  int v75; // eax
  int sizeElem[4]; // [rsp+20h] [rbp-79h] BYREF
  hkVector4f v77; // [rsp+30h] [rbp-69h] BYREF
  hkQuaternionf v78; // [rsp+40h] [rbp-59h] BYREF
  hkQuaternionf quat; // [rsp+50h] [rbp-49h] BYREF
  hkResult result; // [rsp+F0h] [rbp+57h] BYREF
  hkResult v81; // [rsp+F8h] [rbp+5Fh] BYREF
  unsigned int v82; // [rsp+100h] [rbp+67h]
  unsigned int v83; // [rsp+108h] [rbp+6Fh]
  unsigned int v84; // [rsp+110h] [rbp+77h]
  __int64 v85; // [rsp+118h] [rbp+7Fh]

  v4 = v84;
  v6 = (float)(int)v84;
  *(float *)&result.m_enum = 1.0 / v6;
  v7 = _mm_mul_ps(
         _mm_shuffle_ps((__m128)COERCE_UNSIGNED_INT(1.0 / v6), (__m128)COERCE_UNSIGNED_INT(1.0 / v6), 0),
         _mm_sub_ps(top->m_quad, bottom->m_quad));
  v8 = _mm_mul_ps(v7, v7);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_rsqrt_ps(v9);
  v11 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmple_ps(v9, (__m128)0i64),
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)), _mm_mul_ps(*(__m128 *)_xmm, v10))),
          v7);
  result.m_enum = (hkResultEnum)LODWORD(v11.m128_f32[0]);
  v78.m_vec.m_quad = v11;
  if ( COERCE_FLOAT((unsigned int)(2 * v11.m128_i32[0]) >> 1) <= 0.5 )
  {
    result.m_enum = _mm_shuffle_ps(v11, v11, 85).m128_u32[0];
    if ( COERCE_FLOAT((unsigned int)(2 * result.m_enum) >> 1) <= 0.5 )
      m_quad = transform.m_quad;
    else
      m_quad = stru_141A71280.m_quad;
  }
  else
  {
    m_quad = direction.m_quad;
  }
  v13 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v11),
          _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), m_quad));
  v14 = _mm_shuffle_ps(v13, v13, 201);
  v15 = _mm_mul_ps(v14, v14);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v17 = _mm_rsqrt_ps(v16);
  *(__m128 *)sizeElem = _mm_mul_ps(
                          _mm_mul_ps(
                            _mm_andnot_ps(
                              _mm_cmple_ps(v16, (__m128)0i64),
                              _mm_mul_ps(
                                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
                                _mm_mul_ps(*(__m128 *)_xmm, v17))),
                            v14),
                          _mm_shuffle_ps((__m128)v82, (__m128)v82, 0));
  hkQuaternionf::setAxisAngle(&v78, &v78.m_vec, 6.2831855 / (float)numSides);
  hkQuaternionf::setAxisAngle(&quat, &v78.m_vec, 0.0);
  v18 = *(int *)(v85 + 24);
  v19 = v85 + 16;
  v20 = v18 + 1;
  v21 = *(_DWORD *)(v85 + 28) & 0x3FFFFFFF;
  if ( v21 < (int)v18 + 1 )
  {
    v22 = 2 * v21;
    sizeElem[0] = 16;
    if ( v20 < v22 )
      v20 = v22;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)(v85 + 16), v20, sizeElem[0]);
  }
  ++*(_DWORD *)(v19 + 8);
  *(hkVector4f *)(*(_QWORD *)v19 + 16 * v18) = (hkVector4f)bottom->m_quad;
  v23 = *(int *)(v19 + 8);
  v24 = *(_DWORD *)(v19 + 12);
  *(float *)&result.m_enum = v6;
  v25 = v23 + 1;
  v26 = v24 & 0x3FFFFFFF;
  v27 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v6), (__m128)LODWORD(v6), 0), v7), bottom->m_quad);
  if ( v26 < (int)v23 + 1 )
  {
    v28 = 2 * v26;
    sizeElem[0] = 16;
    if ( v25 < v28 )
      v25 = v28;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)v19, v25, sizeElem[0]);
  }
  ++*(_DWORD *)(v19 + 8);
  *(__m128 *)(*(_QWORD *)v19 + 16 * v23) = v27;
  v29 = v83;
  if ( (int)v83 > 0 )
  {
    v30 = v83;
    do
    {
      hkVector4f::setRotatedDir(&v77, &quat, (hkVector4f *)sizeElem);
      v31 = _mm_add_ps(bottom->m_quad, v77.m_quad);
      if ( (int)v4 > 0 )
      {
        v32 = v4;
        do
        {
          v33 = *(int *)(v19 + 8);
          v34 = v33 + 1;
          v35 = *(_DWORD *)(v19 + 12) & 0x3FFFFFFF;
          if ( v35 >= (int)v33 + 1 )
          {
            *(float *)&result.m_enum = 0.0;
          }
          else
          {
            v36 = 2 * v35;
            sizeElem[0] = 16;
            if ( v34 < v36 )
              v34 = v36;
            hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)v19, v34, sizeElem[0]);
          }
          ++*(_DWORD *)(v19 + 8);
          *(__m128 *)(*(_QWORD *)v19 + 16 * v33) = v31;
          v31 = _mm_add_ps(v31, v7);
          --v32;
        }
        while ( v32 );
      }
      v37 = *(int *)(v19 + 8);
      v38 = v37 + 1;
      v39 = *(_DWORD *)(v19 + 12) & 0x3FFFFFFF;
      if ( v39 >= (int)v37 + 1 )
      {
        v81.m_enum = HK_SUCCESS;
      }
      else
      {
        v40 = 2 * v39;
        sizeElem[0] = 16;
        if ( v38 < v40 )
          v38 = v40;
        hkArrayUtil::_reserve(&v81, &hkContainerHeapAllocator::s_alloc, (const void **)v19, v38, sizeElem[0]);
      }
      ++*(_DWORD *)(v19 + 8);
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
  m_enum = v4 + 1;
  v47 = 2;
  result.m_enum = v4 + 1;
  v48 = v4 + 3;
  v49 = 3;
  v50 = v4 + 4;
  v51 = v29 * (v4 + 1) + 2;
  if ( (int)v29 > 0 )
  {
    quat.m_vec.m_quad.m128_u64[0] = v29;
    do
    {
      if ( (int)v4 > 0 )
      {
        v52 = v85;
        v53 = (unsigned int)v4;
        v78.m_vec.m_quad.m128_u64[0] = (unsigned int)v4;
        do
        {
          v54 = *(int *)(v52 + 40);
          v55 = v54 + 1;
          v56 = *(_DWORD *)(v52 + 44) & 0x3FFFFFFF;
          if ( v56 >= (int)v54 + 1 )
          {
            v81.m_enum = HK_SUCCESS;
          }
          else
          {
            v57 = 2 * v56;
            sizeElem[0] = 16;
            if ( v55 < v57 )
              v55 = v57;
            hkArrayUtil::_reserve(&v81, &hkContainerHeapAllocator::s_alloc, (const void **)(v52 + 32), v55, sizeElem[0]);
            v53 = v78.m_vec.m_quad.m128_u64[0];
          }
          ++*(_DWORD *)(v52 + 40);
          v58 = (int *)(*(_QWORD *)(v52 + 32) + 16 * v54);
          *v58 = v47;
          v58[1] = v48;
          v58[2] = v49;
          v58[3] = -1;
          v59 = *(int *)(v52 + 40);
          v60 = v59 + 1;
          v61 = *(_DWORD *)(v52 + 44) & 0x3FFFFFFF;
          if ( v61 >= (int)v59 + 1 )
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
              &hkContainerHeapAllocator::s_alloc,
              (const void **)(v52 + 32),
              v60,
              sizeElem[0]);
            v53 = v78.m_vec.m_quad.m128_u64[0];
          }
          ++*(_DWORD *)(v52 + 40);
          ++v47;
          v63 = (int *)(*(_QWORD *)(v52 + 32) + 16 * v59);
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
    m_enum = result.m_enum;
    LODWORD(v29) = v83;
  }
  for ( i = 0; i < 2; ++i )
  {
    v65 = 0;
    if ( i )
      v65 = v4;
    v66 = v65 + 2;
    if ( (int)v29 > 0 )
    {
      v67 = v85;
      v68 = (unsigned int)v29;
      do
      {
        v69 = v66 + m_enum;
        if ( v66 + m_enum >= v51 )
          v69 += 2 - v51;
        v70 = *(int *)(v67 + 40);
        v71 = *(_DWORD *)(v67 + 44) & 0x3FFFFFFF;
        v72 = v70 + 1;
        if ( i )
        {
          if ( v71 >= v72 )
          {
            v81.m_enum = HK_SUCCESS;
          }
          else
          {
            v73 = 2 * v71;
            sizeElem[0] = 16;
            if ( v72 < v73 )
              v72 = v73;
            hkArrayUtil::_reserve(&v81, &hkContainerHeapAllocator::s_alloc, (const void **)(v67 + 32), v72, sizeElem[0]);
          }
          ++*(_DWORD *)(v67 + 40);
          v74 = (int *)(*(_QWORD *)(v67 + 32) + 16 * v70);
          *v74 = i;
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
              &hkContainerHeapAllocator::s_alloc,
              (const void **)(v67 + 32),
              v72,
              sizeElem[0]);
          }
          ++*(_DWORD *)(v67 + 40);
          v74 = (int *)(*(_QWORD *)(v67 + 32) + 16 * v70);
          *v74 = 0;
          v74[1] = v69;
          v74[2] = v66;
        }
        v74[3] = -1;
        m_enum = result.m_enum;
        v66 = v69;
        --v68;
      }
      while ( v68 );
      LODWORD(v4) = v84;
      LODWORD(v29) = v83;
    }
    m_enum = result.m_enum;
  }
}          }
          ++*(_DWORD *)(v67 + 40);
          v74 = (int *)(*(_QWORD *)(v67 + 32) + 16 * v70);
          *v74 = 0;
          v74[1] = v69;
          v74[2] = v66;
        }
        v74[3] = -1;
        m_enum = result.m_enum;
        v66 = v69;
        --v68;
      }
      while ( v68 );
      LODWORD(v4) = v84;
      LODWORD(v29) = v83;
    }
    m_enum = result.m_en

// File Line: 1314
// RVA: 0xCA12C0
void __fastcall hkGeometryUtils::createPlaneGeometry(
        hkVector4f *normal,
        hkVector4f *perpToNormal,
        hkVector4f *center,
        hkVector4f *extents,
        hkGeometry *geometryOut)
{
  hkGeometry *v5; // rdi
  int v10; // r9d
  int v11; // r9d
  __m128 v12; // xmm3
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  hkGeometry::Triangle *m_data; // rax
  hkGeometry::Triangle *v16; // rax
  hkGeometry::Triangle *v17; // rax
  hkGeometry::Triangle *v18; // rax

  v5 = geometryOut;
  if ( (geometryOut->m_vertices.m_capacityAndFlags & 0x3FFFFFFFu) < 5 )
  {
    v10 = 5;
    if ( 2 * (geometryOut->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) > 5 )
      v10 = 2 * (geometryOut->m_vertices.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      (hkResult *)&geometryOut,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&geometryOut->m_vertices.m_data,
      v10,
      16);
  }
  v5->m_vertices.m_size = 5;
  if ( (v5->m_triangles.m_capacityAndFlags & 0x3FFFFFFFu) < 4 )
  {
    v11 = 4;
    if ( 2 * (v5->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) > 4 )
      v11 = 2 * (v5->m_triangles.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      (hkResult *)&geometryOut,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&v5->m_triangles.m_data,
      v11,
      16);
  }
  v5->m_triangles.m_size = 4;
  v12 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(perpToNormal->m_quad, perpToNormal->m_quad, 201), normal->m_quad),
          _mm_mul_ps(_mm_shuffle_ps(normal->m_quad, normal->m_quad, 201), perpToNormal->m_quad));
  v13 = _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), extents->m_quad);
  v14 = _mm_mul_ps(extents->m_quad, perpToNormal->m_quad);
  v5->m_vertices.m_data->m_quad = _mm_add_ps(center->m_quad, v13);
  v5->m_vertices.m_data->m_quad = _mm_add_ps(v5->m_vertices.m_data->m_quad, v14);
  v5->m_vertices.m_data[1].m_quad = _mm_add_ps(center->m_quad, v13);
  v5->m_vertices.m_data[1].m_quad = _mm_sub_ps(v5->m_vertices.m_data[1].m_quad, v14);
  v5->m_vertices.m_data[2].m_quad = _mm_sub_ps(center->m_quad, v13);
  v5->m_vertices.m_data[2].m_quad = _mm_add_ps(v5->m_vertices.m_data[2].m_quad, v14);
  v5->m_vertices.m_data[3].m_quad = _mm_sub_ps(center->m_quad, v13);
  v5->m_vertices.m_data[3].m_quad = _mm_sub_ps(v5->m_vertices.m_data[3].m_quad, v14);
  v5->m_vertices.m_data[4] = (hkVector4f)center->m_quad;
  m_data = v5->m_triangles.m_data;
  m_data->m_a = 2;
  m_data->m_b = 4;
  m_data->m_c = 3;
  m_data->m_material = -1;
  v16 = v5->m_triangles.m_data;
  v16[1].m_a = 0;
  v16[1].m_b = 4;
  v16[1].m_c = 2;
  v16[1].m_material = -1;
  v17 = v5->m_triangles.m_data;
  v17[2].m_a = 1;
  *(_QWORD *)&v17[2].m_b = 4i64;
  v17[2].m_material = -1;
  v18 = v5->m_triangles.m_data;
  v18[3].m_a = 3;
  v18[3].m_b = 4;
  v18[3].m_c = 1;
  v18[3].m_material = -1;
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
  int v2; // r10d
  __int64 v4; // rbx
  hkGeometry::Triangle *m_data; // r8
  hkVector4f *v6; // r9
  __int64 m_c; // rcx
  __int64 m_b; // rax
  __m128 v9; // xmm2
  __m128 v10; // xmm2

  v2 = 0;
  *volume = 0i64;
  if ( geometry->m_triangles.m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      m_data = geometry->m_triangles.m_data;
      v6 = geometry->m_vertices.m_data;
      ++v2;
      m_c = m_data[v4].m_c;
      m_b = m_data[v4++].m_b;
      v9 = _mm_sub_ps(
             _mm_mul_ps(_mm_shuffle_ps(v6[m_c].m_quad, v6[m_c].m_quad, 201), v6[m_b].m_quad),
             _mm_mul_ps(_mm_shuffle_ps(v6[m_b].m_quad, v6[m_b].m_quad, 201), v6[m_c].m_quad));
      v10 = _mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v6[m_data[v4 - 1].m_a].m_quad);
      volume->m_real = _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
                           _mm_shuffle_ps(v10, v10, 170)),
                         volume->m_real);
    }
    while ( v2 < geometry->m_triangles.m_size );
  }
  volume->m_real = _mm_mul_ps(volume->m_real, (__m128)xmmword_141A711F0);
}

// File Line: 1374
// RVA: 0xCA1A70
void __fastcall hkGeometryUtils::computeAabb(hkGeometry *geomIn, hkAabb *aabbOut)
{
  hkVector4f v2; // xmm2
  hkVector4f *m_data; // r8
  int v4; // eax
  __int64 v5; // rcx
  hkVector4f v6; // xmm1
  __m128 *p_m_quad; // rax

  v2.m_quad = (__m128)xmmword_141A712A0;
  m_data = geomIn->m_vertices.m_data;
  v4 = geomIn->m_vertices.m_size - 1;
  v5 = v4;
  v6.m_quad = _mm_xor_ps(
                (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                (__m128)xmmword_141A712A0);
  if ( v4 >= 0 )
  {
    p_m_quad = &m_data[v4].m_quad;
    do
    {
      --v5;
      v2.m_quad = _mm_min_ps(v2.m_quad, *p_m_quad);
      v6.m_quad = _mm_max_ps(v6.m_quad, *p_m_quad--);
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
  __int64 m_size; // r9
  hkVector4f v3; // xmm4
  hkVector4f v4; // xmm3
  hkVector4f *m_data; // r8
  hkGeometry::Triangle *v6; // rcx
  __int64 m_a; // rax
  __m128 m_quad; // xmm0
  __m128 v9; // xmm1

  m_size = geomIn->m_triangles.m_size;
  v3.m_quad = (__m128)xmmword_141A712A0;
  v4.m_quad = _mm_xor_ps(
                (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                (__m128)xmmword_141A712A0);
  if ( m_size > 0 )
  {
    m_data = geomIn->m_vertices.m_data;
    v6 = geomIn->m_triangles.m_data;
    do
    {
      m_a = v6->m_a;
      ++v6;
      m_quad = m_data[m_a].m_quad;
      v9 = m_data[v6[-1].m_b].m_quad;
      v3.m_quad = _mm_min_ps(_mm_min_ps(_mm_min_ps(v3.m_quad, m_quad), v9), m_data[v6[-1].m_c].m_quad);
      v4.m_quad = _mm_max_ps(_mm_max_ps(_mm_max_ps(v4.m_quad, m_quad), v9), m_data[v6[-1].m_c].m_quad);
      --m_size;
    }
    while ( m_size );
  }
  aabbOut->m_max = (hkVector4f)v4.m_quad;
  aabbOut->m_min = (hkVector4f)v3.m_quad;
}

// File Line: 1404
// RVA: 0xCA14B0
void __fastcall hkGeometryUtils::transformGeometry(hkMatrix4f *transform, hkGeometry *geometryInOut)
{
  int v2; // r8d
  __int64 v3; // r9
  hkVector4f *m_data; // rax
  __m128 m_quad; // xmm1

  v2 = 0;
  if ( geometryInOut->m_vertices.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      m_data = geometryInOut->m_vertices.m_data;
      ++v2;
      m_quad = m_data[v3++].m_quad;
      m_data[v3 - 1].m_quad = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), transform->m_col0.m_quad),
                                    transform->m_col3.m_quad),
                                  _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), transform->m_col1.m_quad)),
                                _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), transform->m_col2.m_quad));
    }
    while ( v2 < geometryInOut->m_vertices.m_size );
  }
}

// File Line: 1413
// RVA: 0xCA1510
void __fastcall hkGeometryUtils::appendGeometry(hkGeometry *input, hkGeometry *geomInOut)
{
  int m_size; // edi
  int v5; // ebp
  __int64 v6; // r14
  int v7; // r9d
  int v8; // eax
  int v9; // eax
  __int64 v10; // r8
  hkGeometry::Triangle *v11; // rcx
  int *p_m_c; // rax
  hkGeometry::Triangle *v13; // rdx
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  m_size = geomInOut->m_vertices.m_size;
  hkArrayBase<hkVector4f>::_append(
    &geomInOut->m_vertices,
    &hkContainerHeapAllocator::s_alloc,
    input->m_vertices.m_data,
    input->m_vertices.m_size);
  v5 = input->m_triangles.m_size;
  v6 = geomInOut->m_triangles.m_size;
  v7 = v6 + v5;
  v8 = geomInOut->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 >= (int)v6 + v5 )
  {
    result.m_enum = HK_SUCCESS;
  }
  else
  {
    v9 = 2 * v8;
    if ( v7 < v9 )
      v7 = v9;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&geomInOut->m_triangles.m_data,
      v7,
      16);
  }
  geomInOut->m_triangles.m_size += v5;
  v10 = input->m_triangles.m_size;
  v11 = &geomInOut->m_triangles.m_data[v6];
  if ( v10 > 0 )
  {
    p_m_c = &v11->m_c;
    do
    {
      v13 = (hkGeometry::Triangle *)((char *)p_m_c + (unsigned __int64)input->m_triangles.m_data - 8 - (_QWORD)v11);
      p_m_c += 4;
      *(p_m_c - 6) = v13->m_a;
      *(p_m_c - 5) = v13->m_b;
      *(p_m_c - 4) = v13->m_c;
      *(p_m_c - 3) = v13->m_material;
      *(p_m_c - 6) += m_size;
      *(p_m_c - 5) += m_size;
      *(p_m_c - 4) += m_size;
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
  __int64 m_size; // rdx
  __int64 v6; // rcx
  __m128 v7; // xmm2
  hkVector4f *m_data; // rax
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
  __m128i v23; // xmm0
  __m128i v24; // xmm0
  __m128 v25; // xmm2
  __m128 v26; // xmm0

  v2 = (__m128)xmmword_141A712A0;
  m_size = mesh->m_vertices.m_size;
  v6 = m_size;
  v7 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), (__m128)xmmword_141A712A0);
  if ( (int)m_size > 0 )
  {
    m_data = mesh->m_vertices.m_data;
    do
    {
      v2 = _mm_min_ps(v2, m_data->m_quad);
      v7 = _mm_max_ps(v7, m_data->m_quad);
      ++m_data;
      --v6;
    }
    while ( v6 );
  }
  v9 = 0;
  v10 = 0i64;
  v10.m128_f32[0] = (float)(resolution - 1);
  v11 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0099999998), (__m128)LODWORD(FLOAT_0_0099999998), 0);
  v12 = _mm_add_ps(v7, v11);
  v13 = _mm_sub_ps(v2, v11);
  v14 = _mm_shuffle_ps(v10, v10, 0);
  v15 = _mm_rcp_ps(v14);
  v16 = _mm_sub_ps(v12, v13);
  v17 = _mm_rcp_ps(v16);
  v18 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v14, v15)), v15), v16);
  v19 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v16, v17)), v17), v14);
  if ( (int)m_size > 0 )
  {
    v20 = 0i64;
    do
    {
      v21 = mesh->m_vertices.m_data;
      ++v9;
      v22 = _mm_mul_ps(_mm_sub_ps(v21[v20++].m_quad, v13), v19);
      v23 = (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v22);
      v24 = _mm_or_si128(
              _mm_add_epi32(
                _mm_cvttps_epi32(
                  _mm_max_ps(
                    _mm_sub_ps(v22, _mm_and_ps((__m128)v23, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                    (__m128)0i64)),
                _mm_slli_epi32(v23, 0x1Fu)),
              (__m128i)_mm_cmple_ps(
                         _mm_add_ps(
                           *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                           *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31),
                         v22));
      v25 = _mm_add_ps(
              _mm_mul_ps(
                _mm_cvtepi32_ps(_mm_srli_epi32(v24, 0x10u)),
                (__m128)`hkIntVector::convertU32ToF32::`2::two16),
              _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v24, 0x10u), 0x10u)));
      v26 = _mm_cmplt_ps(v25, v14);
      v21[v20 - 1].m_quad = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v26, v14), _mm_and_ps(v25, v26))),
                                v18),
                              v13);
    }
    while ( v9 < mesh->m_vertices.m_size );
  }
}

// File Line: 1475
// RVA: 0xCA1600
hkResult *__fastcall hkGeometryUtils::getGeometryInsideAabb(
        hkResult *result,
        hkGeometry *geometryIn,
        hkGeometry *geometryOut,
        hkAabb *aabb,
        hkGeometryUtils::GetGeometryInsideAabbMode mode)
{
  int m_size; // r9d
  int v7; // eax
  hkGeometry *v8; // r15
  hkResult *v9; // rsi
  int v10; // r8d
  int v11; // ebx
  int v12; // ecx
  int v13; // r9d
  _DWORD *v14; // rdi
  __int64 v15; // rcx
  hkGeometryUtils::GetGeometryInsideAabbMode v16; // r12d
  int v17; // edx
  int v18; // r14d
  __int64 v19; // rcx
  int *v20; // r15
  hkVector4f *m_data; // rcx
  __int64 v22; // rax
  __m128 m_quad; // xmm0
  __int64 v24; // rax
  __int64 v25; // rbx
  hkVector4f *v26; // rsi
  __int64 v27; // rcx
  hkGeometry::Triangle *v28; // rdx
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  hkResult resulta; // [rsp+30h] [rbp-41h] BYREF
  int v35; // [rsp+34h] [rbp-3Dh]
  hkResult v36; // [rsp+38h] [rbp-39h] BYREF
  __int64 v37; // [rsp+40h] [rbp-31h]
  _DWORD *array; // [rsp+48h] [rbp-29h] BYREF
  int v39; // [rsp+50h] [rbp-21h]
  int v40; // [rsp+54h] [rbp-1Dh]
  __m128 v41[2]; // [rsp+60h] [rbp-11h] BYREF
  __m128 v42; // [rsp+80h] [rbp+Fh]
  hkGeometry *v44; // [rsp+D8h] [rbp+67h] BYREF
  hkAabb *v45; // [rsp+E8h] [rbp+77h]

  v45 = aabb;
  v44 = geometryIn;
  m_size = geometryIn->m_vertices.m_size;
  v7 = 0;
  v8 = geometryIn;
  v9 = result;
  array = 0i64;
  v40 = 0x80000000;
  v39 = 0;
  if ( m_size <= 0 )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, (const void **)&array, m_size, 4);
    if ( resulta.m_enum )
    {
      v10 = v40;
      v9->m_enum = HK_FAILURE;
      v39 = 0;
      if ( v10 >= 0 )
        goto LABEL_45;
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
    hkArrayUtil::_reserve(&v36, &hkContainerTempAllocator::s_alloc, (const void **)&array, v13, 4);
    v7 = v39;
  }
  v14 = &array[v7];
  v15 = v11 - v7;
  if ( v11 - v7 > 0 )
  {
    while ( v15 )
    {
      *v14++ = -1;
      --v15;
    }
  }
  v16 = mode;
  v39 = v11;
  v17 = 0;
  v18 = 0;
  v36.m_enum = HK_SUCCESS;
  if ( v8->m_triangles.m_size > 0 )
  {
    v19 = 0i64;
    v37 = 0i64;
    do
    {
      v20 = (int *)((char *)&v8->m_triangles.m_data->m_a + v19);
      m_data = v44->m_vertices.m_data;
      v22 = v20[1];
      v41[0] = m_data[*v20].m_quad;
      m_quad = m_data[v22].m_quad;
      v24 = v20[2];
      v41[1] = m_quad;
      v42 = m_data[v24].m_quad;
      if ( (_mm_movemask_ps(
              _mm_and_ps(
                _mm_cmple_ps(v45->m_min.m_quad, _mm_max_ps(_mm_max_ps(v41[0], m_quad), v42)),
                _mm_cmple_ps(_mm_min_ps(_mm_min_ps(v41[0], m_quad), v42), v45->m_max.m_quad))) & 7) == 7 )
      {
        v25 = 0i64;
        v26 = (hkVector4f *)v41;
        v35 = v17 + 1;
        do
        {
          v27 = v20[v25];
          if ( array[v27] == -1 )
          {
            array[v27] = v18++;
            if ( v16 == MODE_COPY_DATA )
            {
              if ( geometryOut->m_vertices.m_size == (geometryOut->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(
                  &hkContainerHeapAllocator::s_alloc,
                  (const void **)&geometryOut->m_vertices.m_data,
                  16);
              geometryOut->m_vertices.m_data[geometryOut->m_vertices.m_size++] = (hkVector4f)v26->m_quad;
            }
          }
          ++v25;
          ++v26;
        }
        while ( v25 < 3 );
        if ( v16 == MODE_COPY_DATA )
        {
          if ( geometryOut->m_triangles.m_size == (geometryOut->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(
              &hkContainerHeapAllocator::s_alloc,
              (const void **)&geometryOut->m_triangles.m_data,
              16);
          v28 = &geometryOut->m_triangles.m_data[geometryOut->m_triangles.m_size++];
          v28->m_a = array[*v20];
          v28->m_b = array[v20[1]];
          v28->m_c = array[v20[2]];
          v28->m_material = v20[3];
        }
        v17 = v35;
      }
      v8 = v44;
      v19 = v37 + 16;
      ++v36.m_enum;
      v37 += 16i64;
    }
    while ( v36.m_enum < v44->m_triangles.m_size );
    v9 = result;
  }
  if ( v16 )
    goto LABEL_43;
  v29 = geometryOut->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v29 >= v17 )
  {
    LODWORD(v44) = 0;
  }
  else
  {
    v30 = 2 * v29;
    if ( v17 < v30 )
      v17 = v30;
    hkArrayUtil::_reserve(
      (hkResult *)&v44,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&geometryOut->m_triangles.m_data,
      v17,
      16);
    if ( (_DWORD)v44 )
    {
      v9->m_enum = HK_FAILURE;
      goto LABEL_44;
    }
  }
  v31 = geometryOut->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v31 >= v18 )
    goto LABEL_43;
  v32 = 2 * v31;
  if ( v18 < v32 )
    v18 = v32;
  hkArrayUtil::_reserve(
    &v36,
    &hkContainerHeapAllocator::s_alloc,
    (const void **)&geometryOut->m_vertices.m_data,
    v18,
    16);
  if ( v36.m_enum == HK_SUCCESS )
LABEL_43:
    v9->m_enum = HK_SUCCESS;
  else
    v9->m_enum = HK_FAILURE;
LABEL_44:
  v10 = v40;
  v39 = 0;
  if ( v40 >= 0 )
LABEL_45:
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v10);
  return v9;
}

