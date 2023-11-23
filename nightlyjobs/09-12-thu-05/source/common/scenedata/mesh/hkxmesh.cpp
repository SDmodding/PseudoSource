// File Line: 14
// RVA: 0xE35060
void __fastcall hkxMesh::hkxMesh(hkxMesh *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkxMesh::`vftable;
}

// File Line: 18
// RVA: 0xE35080
void __fastcall hkxMesh::~hkxMesh(hkxMesh *this)
{
  hkRefPtr<hkxMesh::UserChannelInfo> *m_data; // rsi
  int v3; // eax
  __int64 i; // rbx
  hkReferencedObject *m_pntr; // rcx
  int m_capacityAndFlags; // r8d
  hkRefPtr<hkxMeshSection> *v7; // rsi
  int v8; // eax
  __int64 j; // rbx
  hkReferencedObject *v10; // rcx
  int v11; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkxMesh::`vftable;
  m_data = this->m_userChannelInfos.m_data;
  v3 = this->m_userChannelInfos.m_size - 1;
  for ( i = v3; i >= 0; m_data[i--].m_pntr = 0i64 )
  {
    m_pntr = m_data[i].m_pntr;
    if ( m_pntr )
      hkReferencedObject::removeReference(m_pntr);
  }
  m_capacityAndFlags = this->m_userChannelInfos.m_capacityAndFlags;
  this->m_userChannelInfos.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_userChannelInfos.m_data,
      8 * m_capacityAndFlags);
  this->m_userChannelInfos.m_data = 0i64;
  this->m_userChannelInfos.m_capacityAndFlags = 0x80000000;
  v7 = this->m_sections.m_data;
  v8 = this->m_sections.m_size - 1;
  for ( j = v8; j >= 0; v7[j--].m_pntr = 0i64 )
  {
    v10 = v7[j].m_pntr;
    if ( v10 )
      hkReferencedObject::removeReference(v10);
  }
  v11 = this->m_sections.m_capacityAndFlags;
  this->m_sections.m_size = 0;
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_sections.m_data,
      8 * v11);
  this->m_sections.m_data = 0i64;
  this->m_sections.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 23
// RVA: 0xE35190
void __fastcall hkxMesh::collectVertexPositions(
        hkxMesh *this,
        hkArray<hkVector4f,hkContainerHeapAllocator> *verticesInOut)
{
  int v2; // ebx
  __int64 v5; // rdi

  v2 = 0;
  if ( this->m_sections.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      hkxMeshSection::collectVertexPositions(this->m_sections.m_data[v5].m_pntr, verticesInOut);
      ++v2;
      ++v5;
    }
    while ( v2 < this->m_sections.m_size );
  }
}

// File Line: 32
// RVA: 0xE35200
void __fastcall hkxMesh::appendGeometry(
        hkxMesh *this,
        hkGeometry *geometryInOut,
        hkArray<hkxMaterial *,hkContainerHeapAllocator> *materialsInOut)
{
  int v3; // ebx
  hkGeometry *v5; // r14
  int v7; // r12d
  __int64 v8; // r15
  int m_size; // edi
  __int64 v10; // r8
  hkxMaterial *m_pntr; // r14
  __int64 v12; // rcx
  hkxMaterial **m_data; // rax
  hkRefPtr<hkxMeshSection> *v14; // rcx
  int v15; // edx
  __int64 v16; // rax
  hkGeometry geometryInOuta; // [rsp+30h] [rbp-30h] BYREF

  v3 = -1;
  v5 = geometryInOut;
  v7 = 0;
  if ( this->m_sections.m_size > 0 )
  {
    v8 = 0i64;
    do
    {
      m_size = v5->m_vertices.m_size;
      if ( materialsInOut )
      {
        v10 = materialsInOut->m_size;
        v3 = 0;
        m_pntr = this->m_sections.m_data[v8].m_pntr->m_material.m_pntr;
        v12 = 0i64;
        if ( (int)v10 <= 0 )
          goto LABEL_10;
        m_data = materialsInOut->m_data;
        while ( *m_data != m_pntr )
        {
          ++v12;
          ++v3;
          ++m_data;
          if ( v12 >= v10 )
            goto LABEL_10;
        }
        if ( v3 == -1 )
        {
LABEL_10:
          v3 = materialsInOut->m_size;
          if ( (_DWORD)v10 == (materialsInOut->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&materialsInOut->m_data, 8);
          materialsInOut->m_data[materialsInOut->m_size++] = m_pntr;
        }
        v5 = geometryInOut;
      }
      v14 = this->m_sections.m_data;
      *(_DWORD *)&geometryInOuta.m_memSizeAndFlags = 0x1FFFF;
      geometryInOuta.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable;
      geometryInOuta.m_vertices.m_data = 0i64;
      geometryInOuta.m_vertices.m_size = 0;
      geometryInOuta.m_vertices.m_capacityAndFlags = 0x80000000;
      geometryInOuta.m_triangles.m_data = 0i64;
      geometryInOuta.m_triangles.m_size = 0;
      geometryInOuta.m_triangles.m_capacityAndFlags = 0x80000000;
      hkxMeshSection::appendGeometry(v14[v8].m_pntr, &geometryInOuta, v3);
      v15 = 0;
      if ( geometryInOuta.m_triangles.m_size > 0 )
      {
        v16 = 0i64;
        do
        {
          ++v15;
          geometryInOuta.m_triangles.m_data[v16++].m_a += m_size;
          geometryInOuta.m_triangles.m_data[v16 - 1].m_b += m_size;
          geometryInOuta.m_triangles.m_data[v16 - 1].m_c += m_size;
        }
        while ( v15 < geometryInOuta.m_triangles.m_size );
      }
      hkArrayBase<hkVector4f>::_insertAt(
        &v5->m_vertices,
        &hkContainerHeapAllocator::s_alloc,
        m_size,
        geometryInOuta.m_vertices.m_data,
        geometryInOuta.m_vertices.m_size);
      hkArrayBase<hkGeometry::Triangle>::_insertAt(
        &v5->m_triangles,
        &hkContainerHeapAllocator::s_alloc,
        v5->m_triangles.m_size,
        geometryInOuta.m_triangles.m_data,
        geometryInOuta.m_triangles.m_size);
      geometryInOuta.m_triangles.m_size = 0;
      if ( geometryInOuta.m_triangles.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          geometryInOuta.m_triangles.m_data,
          16 * geometryInOuta.m_triangles.m_capacityAndFlags);
      geometryInOuta.m_triangles.m_data = 0i64;
      geometryInOuta.m_triangles.m_capacityAndFlags = 0x80000000;
      geometryInOuta.m_vertices.m_size = 0;
      if ( geometryInOuta.m_vertices.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          geometryInOuta.m_vertices.m_data,
          16 * geometryInOuta.m_vertices.m_capacityAndFlags);
      ++v7;
      ++v8;
    }
    while ( v7 < this->m_sections.m_size );
  }
}

// File Line: 71
// RVA: 0xE35440
void __fastcall hkxMesh::removeUserChannel(hkxMesh *this, int userChannelIndex)
{
  __int64 v2; // rbp
  hkRefPtr<hkxMesh::UserChannelInfo> *m_data; // rbx
  hkReferencedObject *m_pntr; // rcx
  __int64 v6; // rax
  int v7; // eax
  __int64 i; // rdi
  hkxMeshSection *v9; // rbx
  hkRefVariant *v10; // r14
  hkReferencedObject *v11; // rcx
  __int64 v12; // rax

  if ( userChannelIndex >= 0 )
  {
    v2 = userChannelIndex;
    if ( userChannelIndex < this->m_userChannelInfos.m_size )
    {
      m_data = this->m_userChannelInfos.m_data;
      m_pntr = m_data[userChannelIndex].m_pntr;
      if ( m_pntr )
        hkReferencedObject::removeReference(m_pntr);
      m_data[v2].m_pntr = 0i64;
      v6 = --this->m_userChannelInfos.m_size;
      if ( (_DWORD)v6 != (_DWORD)v2 )
        this->m_userChannelInfos.m_data[v2].m_pntr = this->m_userChannelInfos.m_data[v6].m_pntr;
      v7 = this->m_sections.m_size - 1;
      for ( i = v7; i >= 0; --i )
      {
        v9 = this->m_sections.m_data[i].m_pntr;
        v10 = v9->m_userChannels.m_data;
        v11 = v10[v2].m_pntr;
        if ( v11 )
          hkReferencedObject::removeReference(v11);
        v10[v2].m_pntr = 0i64;
        v12 = --v9->m_userChannels.m_size;
        if ( (_DWORD)v12 != (_DWORD)v2 )
          v9->m_userChannels.m_data[v2].m_pntr = v9->m_userChannels.m_data[v12].m_pntr;
      }
    }
  }
}

