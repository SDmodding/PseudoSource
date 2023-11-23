// File Line: 15
// RVA: 0xE37E60
void __fastcall hkxMeshSection::hkxMeshSection(hkxMeshSection *this, hkxMeshSection *other)
{
  int v2; // ebp
  hkArray<hkRefPtr<hkxIndexBuffer>,hkContainerHeapAllocator> *p_m_indexBuffers; // rdi
  hkArray<hkRefVariant,hkContainerHeapAllocator> *p_m_userChannels; // rbx
  hkxMeshSection *v6; // r12
  int v7; // r15d
  __int64 v8; // r14
  hkRefPtr<hkxIndexBuffer> *m_data; // r13
  hkRefPtr<hkxIndexBuffer> *v10; // r12
  hkReferencedObject *m_pntr; // rcx
  __int64 v12; // rdi
  hkRefVariant *v13; // r15
  hkRefVariant *v14; // r14
  hkReferencedObject *v15; // rcx
  hkxMaterial *v16; // rcx
  hkReferencedObject *v17; // rcx
  hkxVertexBuffer *v18; // rcx
  hkReferencedObject *v19; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v2 = 0;
  p_m_indexBuffers = &this->m_indexBuffers;
  p_m_userChannels = &this->m_userChannels;
  this->vfptr = (hkBaseObjectVtbl *)&hkxMeshSection::`vftable;
  this->m_vertexBuffer.m_pntr = 0i64;
  this->m_indexBuffers.m_data = 0i64;
  this->m_indexBuffers.m_size = 0;
  this->m_indexBuffers.m_capacityAndFlags = 0x80000000;
  this->m_material.m_pntr = 0i64;
  this->m_userChannels.m_data = 0i64;
  this->m_userChannels.m_size = 0;
  this->m_userChannels.m_capacityAndFlags = 0x80000000;
  this->m_vertexAnimations.m_data = 0i64;
  this->m_vertexAnimations.m_size = 0;
  this->m_vertexAnimations.m_capacityAndFlags = 0x80000000;
  this->m_linearKeyFrameHints.m_data = 0i64;
  this->m_linearKeyFrameHints.m_size = 0;
  this->m_linearKeyFrameHints.m_capacityAndFlags = 0x80000000;
  v6 = this;
  v7 = 0;
  if ( other->m_indexBuffers.m_size > 0 )
  {
    v8 = 0i64;
    do
    {
      m_data = other->m_indexBuffers.m_data;
      if ( p_m_indexBuffers->m_size == (p_m_indexBuffers->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_indexBuffers->m_data, 8);
      v10 = &p_m_indexBuffers->m_data[p_m_indexBuffers->m_size];
      if ( v10 )
      {
        m_pntr = m_data[v8].m_pntr;
        if ( m_pntr )
          hkReferencedObject::addReference(m_pntr);
        v10->m_pntr = (hkxIndexBuffer *)m_data[v8];
      }
      ++p_m_indexBuffers->m_size;
      ++v7;
      ++v8;
    }
    while ( v7 < other->m_indexBuffers.m_size );
    v6 = this;
  }
  if ( other->m_userChannels.m_size > 0 )
  {
    v12 = 0i64;
    do
    {
      v13 = other->m_userChannels.m_data;
      if ( p_m_userChannels->m_size == (p_m_userChannels->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_userChannels->m_data, 8);
      v14 = &p_m_userChannels->m_data[p_m_userChannels->m_size];
      if ( v14 )
      {
        v15 = v13[v12].m_pntr;
        if ( v15 )
          hkReferencedObject::addReference(v15);
        v14->m_pntr = (hkReferencedObject *)v13[v12];
      }
      ++p_m_userChannels->m_size;
      ++v2;
      ++v12;
    }
    while ( v2 < other->m_userChannels.m_size );
  }
  v16 = other->m_material.m_pntr;
  if ( v16 )
    hkReferencedObject::addReference(v16);
  v17 = v6->m_material.m_pntr;
  if ( v17 )
    hkReferencedObject::removeReference(v17);
  v6->m_material.m_pntr = other->m_material.m_pntr;
  v18 = other->m_vertexBuffer.m_pntr;
  if ( v18 )
    hkReferencedObject::addReference(v18);
  v19 = v6->m_vertexBuffer.m_pntr;
  if ( v19 )
    hkReferencedObject::removeReference(v19);
  v6->m_vertexBuffer.m_pntr = other->m_vertexBuffer.m_pntr;
}

// File Line: 33
// RVA: 0xE38030
__int64 __fastcall hkxMeshSection::getNumTriangles(hkxMeshSection *this)
{
  unsigned int v1; // ebx
  int v3; // edi
  __int64 v4; // rsi
  int NumTriangles; // eax

  v1 = 0;
  v3 = 0;
  if ( this->m_indexBuffers.m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      NumTriangles = hkxIndexBuffer::getNumTriangles(this->m_indexBuffers.m_data[v4].m_pntr);
      ++v3;
      ++v4;
      v1 += NumTriangles;
    }
    while ( v3 < this->m_indexBuffers.m_size );
  }
  return v1;
}

// File Line: 48
// RVA: 0xE38090
void __fastcall hkxMeshSection::getTriangleIndices(
        hkxMeshSection *this,
        unsigned int triIndex,
        unsigned int *indexAOut,
        unsigned int *indexBOut,
        unsigned int *indexCOut)
{
  unsigned int v5; // esi
  int v8; // ebx
  __int64 i; // rdi
  hkxIndexBuffer *m_pntr; // r14
  unsigned int v13; // ecx

  v5 = 0;
  v8 = 0;
  if ( this->m_indexBuffers.m_size > 0 )
  {
    for ( i = 0i64; ; ++i )
    {
      m_pntr = this->m_indexBuffers.m_data[i].m_pntr;
      v13 = hkxIndexBuffer::getNumTriangles(m_pntr) + v5;
      if ( triIndex < v13 )
        break;
      ++v8;
      v5 = v13;
      if ( v8 >= this->m_indexBuffers.m_size )
        return;
    }
    hkxIndexBuffer::getTriangleIndices(m_pntr, triIndex - v5, indexAOut, indexBOut, indexCOut);
  }
}

// File Line: 66
// RVA: 0xE38140
void __fastcall hkxMeshSection::collectVertexPositions(
        hkxMeshSection *this,
        hkArray<hkVector4f,hkContainerHeapAllocator> *verticesInOut)
{
  hkxVertexBuffer *m_pntr; // r10
  __int64 m_size; // rdx
  hkxVertexDescription::ElementDecl *v5; // rdi
  int v6; // r9d
  __int64 v7; // r8
  hkxVertexDescription::ElementDecl *m_data; // r11
  hkEnum<enum hkxVertexDescription::DataUsage,unsigned short> *p_m_usage; // rax
  __int64 m_numVerts; // rbp
  char *VertexDataPtr; // rax
  __int64 v12; // r14
  __int64 m_byteStride; // r15
  int v14; // edi
  int v15; // ecx
  __m128 *v16; // rbx
  int v17; // ecx
  int v18; // r9d
  __int64 v19; // rdx
  __int64 v20; // rcx
  hkVector4f v21; // xmm0
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  m_pntr = this->m_vertexBuffer.m_pntr;
  if ( m_pntr )
  {
    m_size = m_pntr->m_desc.m_decls.m_size;
    v5 = 0i64;
    v6 = 0;
    v7 = 0i64;
    if ( m_size > 0 )
    {
      m_data = m_pntr->m_desc.m_decls.m_data;
      p_m_usage = &m_data->m_usage;
      while ( p_m_usage->m_storage != 1 )
      {
        ++v7;
        ++v6;
        p_m_usage += 8;
        if ( v7 >= m_size )
          goto LABEL_7;
      }
      v5 = &m_data[v6];
    }
LABEL_7:
    m_numVerts = (int)m_pntr->m_data.m_numVerts;
    if ( v5 && (int)m_numVerts > 0 )
    {
      VertexDataPtr = hkxVertexBuffer::getVertexDataPtr(m_pntr, v5);
      v12 = verticesInOut->m_size;
      m_byteStride = v5->m_byteStride;
      v14 = v12 + m_numVerts;
      v15 = verticesInOut->m_capacityAndFlags & 0x3FFFFFFF;
      v16 = (__m128 *)VertexDataPtr;
      if ( v15 < (int)v12 + (int)m_numVerts )
      {
        v17 = 2 * v15;
        v18 = v12 + m_numVerts;
        if ( v14 < v17 )
          v18 = v17;
        hkArrayUtil::_reserve(
          &result,
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&verticesInOut->m_data,
          v18,
          16);
      }
      verticesInOut->m_size = v14;
      v19 = m_numVerts;
      v20 = v12;
      do
      {
        v21.m_quad = *v16;
        v16 = (__m128 *)((char *)v16 + m_byteStride);
        verticesInOut->m_data[v20++] = (hkVector4f)v21.m_quad;
        --v19;
      }
      while ( v19 );
    }
  }
}

// File Line: 90
// RVA: 0xE38270
void __fastcall hkxMeshSection::appendGeometry(hkxMeshSection *this, hkGeometry *geometryInOut, int materialIndex)
{
  hkxMeshSection *v4; // rbx
  int v5; // edi
  __int64 v6; // rcx
  __int64 v7; // rsi
  int v8; // eax
  int v9; // ecx
  bool v10; // r12
  __int64 v11; // rdx
  __int64 v12; // rbx
  unsigned __int16 *v13; // rax
  int m_c; // r14d
  int m_b; // r15d
  int v16; // edi
  int *v17; // rax
  hkGeometry::Triangle *v18; // rcx
  __int64 v19; // rax
  __int64 v20; // rax
  hkGeometry::Triangle *v21; // rax
  __int64 v22; // [rsp+20h] [rbp-268h]
  __int64 v23; // [rsp+28h] [rbp-260h]
  hkErrStream v24; // [rsp+30h] [rbp-258h] BYREF
  char buf[512]; // [rsp+50h] [rbp-238h] BYREF
  int v27; // [rsp+298h] [rbp+10h]

  v4 = this;
  hkxMeshSection::collectVertexPositions(this, &geometryInOut->m_vertices);
  v5 = 0;
  v27 = 0;
  if ( v4->m_indexBuffers.m_size <= 0 )
    return;
  v6 = 0i64;
  v22 = 0i64;
  do
  {
    v7 = *(__int64 *)((char *)&v4->m_indexBuffers.m_data->m_pntr + v6);
    v8 = *(_DWORD *)(v7 + 32);
    v9 = v8 | *(_DWORD *)(v7 + 48);
    v10 = v8 > 0;
    v11 = v9;
    v12 = 0i64;
    v23 = v9;
    if ( v9 <= 0 )
      goto LABEL_26;
    while ( 1 )
    {
      if ( *(_BYTE *)(v7 + 16) == 1 )
      {
        if ( v10 )
        {
          v19 = *(_QWORD *)(v7 + 24);
          m_c = *(unsigned __int16 *)(v19 + 2 * v12);
          m_b = *(unsigned __int16 *)(v19 + 2 * v12 + 2);
          v16 = *(unsigned __int16 *)(v19 + 2 * v12 + 4);
        }
        else
        {
          v20 = *(_QWORD *)(v7 + 40);
          m_c = *(_DWORD *)(v20 + 4 * v12);
          m_b = *(_DWORD *)(v20 + 4 * v12 + 4);
          v16 = *(_DWORD *)(v20 + 4 * v12 + 8);
        }
        v12 += 3i64;
        goto LABEL_19;
      }
      if ( *(_BYTE *)(v7 + 16) != 2 )
        break;
      if ( v12 >= 2 )
      {
        if ( v12 == 2 )
        {
          if ( v10 )
          {
            v13 = *(unsigned __int16 **)(v7 + 24);
            v12 = 3i64;
            m_c = *v13;
            m_b = v13[1];
            v16 = v13[2];
          }
          else
          {
            v17 = *(int **)(v7 + 40);
            v12 = 3i64;
            m_c = *v17;
            m_b = v17[1];
            v16 = v17[2];
          }
        }
        else
        {
          v18 = &geometryInOut->m_triangles.m_data[geometryInOut->m_triangles.m_size - 1];
          m_c = v18->m_c;
          m_b = v18->m_b;
          ++v12;
          if ( v10 )
            v16 = *(unsigned __int16 *)(*(_QWORD *)(v7 + 24) + 2 * v12 - 2);
          else
            v16 = *(_DWORD *)(*(_QWORD *)(v7 + 40) + 4 * v12 - 4);
        }
LABEL_19:
        if ( geometryInOut->m_triangles.m_size == (geometryInOut->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&geometryInOut->m_triangles.m_data,
            16);
          v11 = v23;
        }
        v21 = &geometryInOut->m_triangles.m_data[geometryInOut->m_triangles.m_size];
        v21->m_a = m_c;
        v21->m_b = m_b;
        v21->m_c = v16;
        v21->m_material = materialIndex;
        ++geometryInOut->m_triangles.m_size;
        goto LABEL_22;
      }
      ++v12;
LABEL_22:
      if ( v12 >= v11 )
        goto LABEL_25;
    }
    hkErrStream::hkErrStream(&v24, buf, 512);
    hkOstream::operator<<(&v24, "Unsupported index buffer type - Ignoring");
    hkError::messageWarning(0xABBAA883, buf, "Mesh\\hkxMeshSection.cpp", 149);
    hkOstream::~hkOstream(&v24);
LABEL_25:
    v5 = v27;
LABEL_26:
    v4 = this;
    ++v5;
    v6 = v22 + 8;
    v27 = v5;
    v22 += 8i64;
  }
  while ( v5 < this->m_indexBuffers.m_size );
}

