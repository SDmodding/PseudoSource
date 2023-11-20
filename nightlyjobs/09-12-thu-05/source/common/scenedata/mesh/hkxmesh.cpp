// File Line: 14
// RVA: 0xE35060
void __fastcall hkxMesh::hkxMesh(hkxMesh *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkxMesh::`vftable';
}

// File Line: 18
// RVA: 0xE35080
void __fastcall hkxMesh::~hkxMesh(hkxMesh *this)
{
  hkxMesh *v1; // rdi
  hkRefPtr<hkxMesh::UserChannelInfo> *v2; // rsi
  int v3; // eax
  __int64 i; // rbx
  hkReferencedObject *v5; // rcx
  int v6; // er8
  hkRefPtr<hkxMeshSection> *v7; // rsi
  int v8; // eax
  __int64 j; // rbx
  hkReferencedObject *v10; // rcx
  int v11; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkxMesh::`vftable';
  v2 = this->m_userChannelInfos.m_data;
  v3 = this->m_userChannelInfos.m_size - 1;
  for ( i = v3; i >= 0; v2[i--].m_pntr = 0i64 )
  {
    v5 = (hkReferencedObject *)&v2[i].m_pntr->vfptr;
    if ( v5 )
      hkReferencedObject::removeReference(v5);
  }
  v6 = v1->m_userChannelInfos.m_capacityAndFlags;
  v1->m_userChannelInfos.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_userChannelInfos.m_data,
      8 * v6);
  v1->m_userChannelInfos.m_data = 0i64;
  v1->m_userChannelInfos.m_capacityAndFlags = 2147483648;
  v7 = v1->m_sections.m_data;
  v8 = v1->m_sections.m_size - 1;
  for ( j = v8; j >= 0; v7[j--].m_pntr = 0i64 )
  {
    v10 = (hkReferencedObject *)&v7[j].m_pntr->vfptr;
    if ( v10 )
      hkReferencedObject::removeReference(v10);
  }
  v11 = v1->m_sections.m_capacityAndFlags;
  v1->m_sections.m_size = 0;
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_sections.m_data,
      8 * v11);
  v1->m_sections.m_data = 0i64;
  v1->m_sections.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 23
// RVA: 0xE35190
void __fastcall hkxMesh::collectVertexPositions(hkxMesh *this, hkArray<hkVector4f,hkContainerHeapAllocator> *verticesInOut)
{
  int v2; // ebx
  hkArray<hkVector4f,hkContainerHeapAllocator> *v3; // rbp
  hkxMesh *v4; // rsi
  __int64 v5; // rdi

  v2 = 0;
  v3 = verticesInOut;
  v4 = this;
  if ( this->m_sections.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      hkxMeshSection::collectVertexPositions(v4->m_sections.m_data[v5].m_pntr, v3);
      ++v2;
      ++v5;
    }
    while ( v2 < v4->m_sections.m_size );
  }
}

// File Line: 32
// RVA: 0xE35200
void __fastcall hkxMesh::appendGeometry(hkxMesh *this, hkGeometry *geometryInOut, hkArray<hkxMaterial *,hkContainerHeapAllocator> *materialsInOut)
{
  int v3; // ebx
  hkArray<hkxMaterial *,hkContainerHeapAllocator> *v4; // rsi
  hkGeometry *v5; // r14
  hkxMesh *v6; // r13
  int v7; // er12
  __int64 v8; // r15
  int v9; // edi
  __int64 v10; // r8
  hkxMaterial *v11; // r14
  __int64 v12; // rcx
  hkxMaterial **v13; // rax
  hkRefPtr<hkxMeshSection> *v14; // rcx
  int v15; // edx
  __int64 v16; // rax
  hkGeometry geometryInOuta; // [rsp+30h] [rbp-30h]
  hkGeometry *v18; // [rsp+98h] [rbp+38h]

  v18 = geometryInOut;
  v3 = -1;
  v4 = materialsInOut;
  v5 = geometryInOut;
  v6 = this;
  v7 = 0;
  if ( this->m_sections.m_size > 0 )
  {
    v8 = 0i64;
    do
    {
      v9 = v5->m_vertices.m_size;
      if ( v4 )
      {
        v10 = v4->m_size;
        v3 = 0;
        v11 = v6->m_sections.m_data[v8].m_pntr->m_material.m_pntr;
        v12 = 0i64;
        if ( (signed int)v10 <= 0 )
          goto LABEL_10;
        v13 = v4->m_data;
        while ( *v13 != v11 )
        {
          ++v12;
          ++v3;
          ++v13;
          if ( v12 >= v10 )
            goto LABEL_10;
        }
        if ( v3 == -1 )
        {
LABEL_10:
          v3 = v10;
          if ( (_DWORD)v10 == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 8);
          v4->m_data[v4->m_size++] = v11;
        }
        v5 = v18;
      }
      v14 = v6->m_sections.m_data;
      *(_DWORD *)&geometryInOuta.m_memSizeAndFlags = 0x1FFFF;
      geometryInOuta.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable';
      geometryInOuta.m_vertices.m_data = 0i64;
      geometryInOuta.m_vertices.m_size = 0;
      geometryInOuta.m_vertices.m_capacityAndFlags = 2147483648;
      geometryInOuta.m_triangles.m_data = 0i64;
      geometryInOuta.m_triangles.m_size = 0;
      geometryInOuta.m_triangles.m_capacityAndFlags = 2147483648;
      hkxMeshSection::appendGeometry(v14[v8].m_pntr, &geometryInOuta, v3);
      v15 = 0;
      if ( geometryInOuta.m_triangles.m_size > 0 )
      {
        v16 = 0i64;
        do
        {
          ++v15;
          ++v16;
          geometryInOuta.m_triangles.m_data[v16 - 1].m_a += v9;
          *((_DWORD *)&geometryInOuta.m_triangles.m_data[v16] - 3) += v9;
          *((_DWORD *)&geometryInOuta.m_triangles.m_data[v16] - 2) += v9;
        }
        while ( v15 < geometryInOuta.m_triangles.m_size );
      }
      hkArrayBase<hkVector4f>::_insertAt(
        (hkArrayBase<hkVector4f> *)&v5->m_vertices.m_data,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        v9,
        geometryInOuta.m_vertices.m_data,
        geometryInOuta.m_vertices.m_size);
      hkArrayBase<hkGeometry::Triangle>::_insertAt(
        (hkArrayBase<hkGeometry::Triangle> *)&v5->m_triangles.m_data,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        v5->m_triangles.m_size,
        geometryInOuta.m_triangles.m_data,
        geometryInOuta.m_triangles.m_size);
      geometryInOuta.m_triangles.m_size = 0;
      if ( geometryInOuta.m_triangles.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          geometryInOuta.m_triangles.m_data,
          16 * geometryInOuta.m_triangles.m_capacityAndFlags);
      geometryInOuta.m_triangles.m_data = 0i64;
      geometryInOuta.m_triangles.m_capacityAndFlags = 2147483648;
      geometryInOuta.m_vertices.m_size = 0;
      if ( geometryInOuta.m_vertices.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          geometryInOuta.m_vertices.m_data,
          16 * geometryInOuta.m_vertices.m_capacityAndFlags);
      ++v7;
      ++v8;
    }
    while ( v7 < v6->m_sections.m_size );
  }
}

// File Line: 71
// RVA: 0xE35440
void __fastcall hkxMesh::removeUserChannel(hkxMesh *this, int userChannelIndex)
{
  int v2; // ebp
  hkxMesh *v3; // rsi
  hkRefPtr<hkxMesh::UserChannelInfo> *v4; // rbx
  hkReferencedObject *v5; // rcx
  signed __int64 v6; // r15
  __int64 v7; // rax
  int v8; // eax
  __int64 i; // rdi
  hkxMeshSection *v10; // rbx
  hkRefVariant *v11; // r14
  hkReferencedObject *v12; // rcx
  __int64 v13; // rax

  if ( userChannelIndex >= 0 )
  {
    v2 = userChannelIndex;
    v3 = this;
    if ( userChannelIndex < this->m_userChannelInfos.m_size )
    {
      v4 = this->m_userChannelInfos.m_data;
      v5 = (hkReferencedObject *)&v4[userChannelIndex].m_pntr->vfptr;
      v6 = userChannelIndex;
      if ( v5 )
        hkReferencedObject::removeReference(v5);
      v4[v6].m_pntr = 0i64;
      v7 = --v3->m_userChannelInfos.m_size;
      if ( (_DWORD)v7 != v2 )
        v3->m_userChannelInfos.m_data[v6].m_pntr = v3->m_userChannelInfos.m_data[v7].m_pntr;
      v8 = v3->m_sections.m_size - 1;
      for ( i = v8; i >= 0; --i )
      {
        v10 = v3->m_sections.m_data[i].m_pntr;
        v11 = v10->m_userChannels.m_data;
        v12 = v11[v6].m_pntr;
        if ( v12 )
          hkReferencedObject::removeReference(v12);
        v11[v6].m_pntr = 0i64;
        v13 = --v10->m_userChannels.m_size;
        if ( (_DWORD)v13 != v2 )
          v10->m_userChannels.m_data[v6].m_pntr = v10->m_userChannels.m_data[v13].m_pntr;
      }
    }
  }
}

