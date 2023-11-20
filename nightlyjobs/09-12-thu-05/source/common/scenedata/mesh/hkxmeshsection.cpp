// File Line: 15
// RVA: 0xE37E60
void __fastcall hkxMeshSection::hkxMeshSection(hkxMeshSection *this, hkxMeshSection *other)
{
  int v2; // ebp
  hkArray<hkRefPtr<hkxIndexBuffer>,hkContainerHeapAllocator> *v3; // rdi
  hkArray<hkRefVariant,hkContainerHeapAllocator> *v4; // rbx
  hkxMeshSection *v5; // rsi
  hkxMeshSection *v6; // r12
  int v7; // er15
  __int64 v8; // r14
  hkRefPtr<hkxIndexBuffer> *v9; // r13
  hkRefPtr<hkxIndexBuffer> *v10; // r12
  hkReferencedObject *v11; // rcx
  __int64 v12; // rdi
  hkRefVariant *v13; // r15
  hkRefVariant *v14; // r14
  hkReferencedObject *v15; // rcx
  hkReferencedObject *v16; // rcx
  hkReferencedObject *v17; // rcx
  hkReferencedObject *v18; // rcx
  hkReferencedObject *v19; // rcx
  hkxMeshSection *v20; // [rsp+50h] [rbp+8h]

  v20 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v2 = 0;
  v3 = &this->m_indexBuffers;
  v4 = &this->m_userChannels;
  this->vfptr = (hkBaseObjectVtbl *)&hkxMeshSection::`vftable';
  this->m_vertexBuffer.m_pntr = 0i64;
  v3->m_data = 0i64;
  v3->m_size = 0;
  v3->m_capacityAndFlags = 2147483648;
  this->m_material.m_pntr = 0i64;
  v4->m_data = 0i64;
  v4->m_size = 0;
  v4->m_capacityAndFlags = 2147483648;
  this->m_vertexAnimations.m_data = 0i64;
  this->m_vertexAnimations.m_size = 0;
  this->m_vertexAnimations.m_capacityAndFlags = 2147483648;
  this->m_linearKeyFrameHints.m_data = 0i64;
  this->m_linearKeyFrameHints.m_size = 0;
  this->m_linearKeyFrameHints.m_capacityAndFlags = 2147483648;
  v5 = other;
  v6 = this;
  v7 = 0;
  if ( other->m_indexBuffers.m_size > 0 )
  {
    v8 = 0i64;
    do
    {
      v9 = v5->m_indexBuffers.m_data;
      if ( v3->m_size == (v3->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 8);
      v10 = &v3->m_data[v3->m_size];
      if ( v10 )
      {
        v11 = (hkReferencedObject *)&v9[v8].m_pntr->vfptr;
        if ( v11 )
          hkReferencedObject::addReference(v11);
        v10->m_pntr = (hkxIndexBuffer *)v9[v8];
      }
      ++v3->m_size;
      ++v7;
      ++v8;
    }
    while ( v7 < v5->m_indexBuffers.m_size );
    v6 = v20;
  }
  if ( v5->m_userChannels.m_size > 0 )
  {
    v12 = 0i64;
    do
    {
      v13 = v5->m_userChannels.m_data;
      if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 8);
      v14 = &v4->m_data[v4->m_size];
      if ( v14 )
      {
        v15 = v13[v12].m_pntr;
        if ( v15 )
          hkReferencedObject::addReference(v15);
        v14->m_pntr = (hkReferencedObject *)v13[v12];
      }
      ++v4->m_size;
      ++v2;
      ++v12;
    }
    while ( v2 < v5->m_userChannels.m_size );
  }
  v16 = (hkReferencedObject *)&v5->m_material.m_pntr->vfptr;
  if ( v16 )
    hkReferencedObject::addReference(v16);
  v17 = (hkReferencedObject *)&v6->m_material.m_pntr->vfptr;
  if ( v17 )
    hkReferencedObject::removeReference(v17);
  v6->m_material.m_pntr = v5->m_material.m_pntr;
  v18 = (hkReferencedObject *)&v5->m_vertexBuffer.m_pntr->vfptr;
  if ( v18 )
    hkReferencedObject::addReference(v18);
  v19 = (hkReferencedObject *)&v6->m_vertexBuffer.m_pntr->vfptr;
  if ( v19 )
    hkReferencedObject::removeReference(v19);
  v6->m_vertexBuffer.m_pntr = v5->m_vertexBuffer.m_pntr;
}

// File Line: 33
// RVA: 0xE38030
__int64 __fastcall hkxMeshSection::getNumTriangles(hkxMeshSection *this)
{
  unsigned int v1; // ebx
  hkxMeshSection *v2; // rbp
  int v3; // edi
  __int64 v4; // rsi
  int v5; // eax

  v1 = 0;
  v2 = this;
  v3 = 0;
  if ( this->m_indexBuffers.m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      v5 = hkxIndexBuffer::getNumTriangles(v2->m_indexBuffers.m_data[v4].m_pntr);
      ++v3;
      ++v4;
      v1 += v5;
    }
    while ( v3 < v2->m_indexBuffers.m_size );
  }
  return v1;
}

// File Line: 48
// RVA: 0xE38090
void __fastcall hkxMeshSection::getTriangleIndices(hkxMeshSection *this, unsigned int triIndex, unsigned int *indexAOut, unsigned int *indexBOut, unsigned int *indexCOut)
{
  unsigned int v5; // esi
  unsigned int *v6; // r12
  unsigned int *v7; // r13
  int v8; // ebx
  unsigned int v9; // er15
  hkxMeshSection *v10; // rbp
  __int64 v11; // rdi
  hkxIndexBuffer *v12; // r14
  unsigned int v13; // ecx

  v5 = 0;
  v6 = indexBOut;
  v7 = indexAOut;
  v8 = 0;
  v9 = triIndex;
  v10 = this;
  if ( this->m_indexBuffers.m_size > 0 )
  {
    v11 = 0i64;
    while ( 1 )
    {
      v12 = v10->m_indexBuffers.m_data[v11].m_pntr;
      v13 = hkxIndexBuffer::getNumTriangles(v12) + v5;
      if ( v9 < v13 )
        break;
      ++v8;
      ++v11;
      v5 = v13;
      if ( v8 >= v10->m_indexBuffers.m_size )
        return;
    }
    hkxIndexBuffer::getTriangleIndices(v12, v9 - v5, v7, v6, indexCOut);
  }
}

// File Line: 66
// RVA: 0xE38140
void __fastcall hkxMeshSection::collectVertexPositions(hkxMeshSection *this, hkArray<hkVector4f,hkContainerHeapAllocator> *verticesInOut)
{
  hkxVertexBuffer *v2; // r10
  hkArray<hkVector4f,hkContainerHeapAllocator> *v3; // rsi
  __int64 v4; // rdx
  hkxVertexDescription::ElementDecl *v5; // rdi
  int v6; // ecx
  int v7; // er9
  __int64 v8; // r8
  hkxVertexDescription::ElementDecl *v9; // r11
  hkEnum<enum hkxVertexDescription::DataUsage,unsigned short> *v10; // rax
  __int64 v11; // rbp
  char *v12; // rax
  signed __int64 v13; // r14
  __int64 v14; // r15
  int v15; // edi
  int v16; // ecx
  __m128 *v17; // rbx
  int v18; // ecx
  int v19; // er9
  __int64 v20; // rdx
  signed __int64 v21; // rcx
  hkVector4f v22; // xmm0
  hkResult result; // [rsp+50h] [rbp+8h]

  v2 = this->m_vertexBuffer.m_pntr;
  v3 = verticesInOut;
  if ( !v2 )
    return;
  v4 = v2->m_desc.m_decls.m_size;
  v5 = 0i64;
  v6 = 0;
  v7 = 0;
  v8 = 0i64;
  if ( v4 <= 0 )
    goto LABEL_10;
  v9 = v2->m_desc.m_decls.m_data;
  v10 = &v9->m_usage;
  while ( v10->m_storage != 1 )
  {
LABEL_7:
    ++v8;
    ++v7;
    v10 += 8;
    if ( v8 >= v4 )
      goto LABEL_10;
  }
  if ( v6 )
  {
    ++v6;
    goto LABEL_7;
  }
  v5 = &v9[v7];
LABEL_10:
  v11 = (signed int)v2->m_data.m_numVerts;
  if ( v5 && (signed int)v11 > 0 )
  {
    v12 = hkxVertexBuffer::getVertexDataPtr(v2, v5);
    v13 = v3->m_size;
    v14 = v5->m_byteStride;
    v15 = v13 + v11;
    v16 = v3->m_capacityAndFlags & 0x3FFFFFFF;
    v17 = (__m128 *)v12;
    if ( v16 < (signed int)v13 + (signed int)v11 )
    {
      v18 = 2 * v16;
      v19 = v13 + v11;
      if ( v15 < v18 )
        v19 = v18;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, v19, 16);
    }
    v3->m_size = v15;
    v20 = v11;
    if ( (signed int)v11 > 0 )
    {
      v21 = v13;
      do
      {
        v22.m_quad = *v17;
        v17 = (__m128 *)((char *)v17 + v14);
        ++v21;
        v3->m_data[v21 - 1] = (hkVector4f)v22.m_quad;
        --v20;
      }
      while ( v20 );
    }
  }
}

// File Line: 90
// RVA: 0xE38270
void __fastcall hkxMeshSection::appendGeometry(hkxMeshSection *this, hkGeometry *geometryInOut, int materialIndex)
{
  hkGeometry *v3; // r13
  hkxMeshSection *v4; // rbx
  int v5; // edi
  signed __int64 v6; // rcx
  __int64 v7; // rsi
  int v8; // eax
  int v9; // ecx
  bool v10; // r12
  signed __int64 v11; // rdx
  signed __int64 v12; // rbx
  unsigned __int16 *v13; // rax
  int v14; // er14
  int v15; // er15
  int v16; // edi
  int *v17; // rax
  signed __int64 v18; // rcx
  __int64 v19; // rax
  __int64 v20; // rax
  hkGeometry::Triangle *v21; // rax
  __int64 v22; // [rsp+20h] [rbp-268h]
  signed __int64 v23; // [rsp+28h] [rbp-260h]
  hkErrStream v24; // [rsp+30h] [rbp-258h]
  char buf; // [rsp+50h] [rbp-238h]
  hkxMeshSection *v26; // [rsp+290h] [rbp+8h]
  int v27; // [rsp+298h] [rbp+10h]
  int v28; // [rsp+2A8h] [rbp+20h]

  v26 = this;
  v3 = geometryInOut;
  v28 = materialIndex;
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
          v14 = *(unsigned __int16 *)(v19 + 2 * v12);
          v15 = *(unsigned __int16 *)(v19 + 2 * v12 + 2);
          v16 = *(unsigned __int16 *)(v19 + 2 * v12 + 4);
        }
        else
        {
          v20 = *(_QWORD *)(v7 + 40);
          v14 = *(_DWORD *)(v20 + 4 * v12);
          v15 = *(_DWORD *)(v20 + 4 * v12 + 4);
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
            v14 = *v13;
            v15 = v13[1];
            v16 = v13[2];
          }
          else
          {
            v17 = *(int **)(v7 + 40);
            v12 = 3i64;
            v14 = *v17;
            v15 = v17[1];
            v16 = v17[2];
          }
        }
        else
        {
          v18 = (signed __int64)&v3->m_triangles.m_data[v3->m_triangles.m_size - 1];
          v14 = *(_DWORD *)(v18 + 8);
          v15 = *(_DWORD *)(v18 + 4);
          if ( v10 )
            v16 = *(unsigned __int16 *)(*(_QWORD *)(v7 + 24) + 2 * ++v12 - 2);
          else
            v16 = *(_DWORD *)(*(_QWORD *)(v7 + 40) + 4 * ++v12 - 4);
        }
LABEL_19:
        if ( v3->m_triangles.m_size == (v3->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_triangles, 16);
          v11 = v23;
        }
        v21 = &v3->m_triangles.m_data[v3->m_triangles.m_size];
        v21->m_a = v14;
        v21->m_b = v15;
        v21->m_c = v16;
        v21->m_material = v28;
        ++v3->m_triangles.m_size;
        goto LABEL_22;
      }
      ++v12;
LABEL_22:
      if ( v12 >= v11 )
        goto LABEL_25;
    }
    hkErrStream::hkErrStream(&v24, &buf, 512);
    hkOstream::operator<<((hkOstream *)&v24.vfptr, "Unsupported index buffer type - Ignoring");
    hkError::messageWarning(-1413830525, &buf, "Mesh\\hkxMeshSection.cpp", 149);
    hkOstream::~hkOstream((hkOstream *)&v24.vfptr);
LABEL_25:
    v5 = v27;
LABEL_26:
    v4 = v26;
    ++v5;
    v6 = v22 + 8;
    v27 = v5;
    v22 += 8i64;
  }
  while ( v5 < v26->m_indexBuffers.m_size );
}

