// File Line: 215
// RVA: 0x1326470
void __fastcall hkpCompressedMeshShape::Chunk::Chunk(hkpCompressedMeshShape::Chunk *this, hkpCompressedMeshShape::Chunk *other)
{
  hkpCompressedMeshShape::Chunk *v2; // rdi
  hkpCompressedMeshShape::Chunk *v3; // rbx
  int v4; // er8
  __int64 v5; // rax
  unsigned __int16 *v6; // rcx
  __int64 v7; // rdx
  char *v8; // r8
  unsigned __int16 v9; // ax
  int v10; // er8
  __int64 v11; // rax
  unsigned __int16 *v12; // rcx
  __int64 v13; // rdx
  char *v14; // r8
  unsigned __int16 v15; // ax
  int v16; // er8
  __int64 v17; // rax
  unsigned __int16 *v18; // rcx
  __int64 v19; // rdx
  char *v20; // r8
  unsigned __int16 v21; // ax
  int v22; // er8
  __int64 v23; // rax
  unsigned __int16 *v24; // rcx
  __int64 v25; // rdx
  char *v26; // r8
  unsigned __int16 v27; // ax
  int v28; // [rsp+30h] [rbp+8h]

  this->m_vertices.m_capacityAndFlags = 2147483648;
  v2 = other;
  this->m_vertices.m_data = 0i64;
  this->m_vertices.m_size = 0;
  this->m_indices.m_data = 0i64;
  this->m_indices.m_size = 0;
  this->m_indices.m_capacityAndFlags = 2147483648;
  this->m_stripLengths.m_data = 0i64;
  this->m_stripLengths.m_size = 0;
  this->m_stripLengths.m_capacityAndFlags = 2147483648;
  this->m_weldingInfo.m_data = 0i64;
  this->m_weldingInfo.m_size = 0;
  this->m_weldingInfo.m_capacityAndFlags = 2147483648;
  v3 = this;
  this->m_offset = other->m_offset;
  v4 = this->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < other->m_vertices.m_size )
  {
    if ( this->m_vertices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        this->m_vertices.m_data,
        2 * v4);
    v28 = 2 * v2->m_vertices.m_size;
    v3->m_vertices.m_data = (unsigned __int16 *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                  &v28);
    v3->m_vertices.m_capacityAndFlags = v28 / 2;
  }
  v5 = v2->m_vertices.m_size;
  v6 = v3->m_vertices.m_data;
  v3->m_vertices.m_size = v5;
  v7 = v5;
  if ( (signed int)v5 > 0 )
  {
    v8 = (char *)((char *)v2->m_vertices.m_data - (char *)v6);
    do
    {
      v9 = *(unsigned __int16 *)((char *)v6 + (_QWORD)v8);
      ++v6;
      *(v6 - 1) = v9;
      --v7;
    }
    while ( v7 );
  }
  v10 = v3->m_indices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 < v2->m_indices.m_size )
  {
    if ( v3->m_indices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v3->m_indices.m_data,
        2 * v10);
    v28 = 2 * v2->m_indices.m_size;
    v3->m_indices.m_data = (unsigned __int16 *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                 (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                 &v28);
    v3->m_indices.m_capacityAndFlags = v28 / 2;
  }
  v11 = v2->m_indices.m_size;
  v12 = v3->m_indices.m_data;
  v3->m_indices.m_size = v11;
  v13 = v11;
  if ( (signed int)v11 > 0 )
  {
    v14 = (char *)((char *)v2->m_indices.m_data - (char *)v12);
    do
    {
      v15 = *(unsigned __int16 *)((char *)v12 + (_QWORD)v14);
      ++v12;
      *(v12 - 1) = v15;
      --v13;
    }
    while ( v13 );
  }
  v16 = v3->m_stripLengths.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v16 < v2->m_stripLengths.m_size )
  {
    if ( v3->m_stripLengths.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v3->m_stripLengths.m_data,
        2 * v16);
    v28 = 2 * v2->m_stripLengths.m_size;
    v3->m_stripLengths.m_data = (unsigned __int16 *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                      &v28);
    v3->m_stripLengths.m_capacityAndFlags = v28 / 2;
  }
  v17 = v2->m_stripLengths.m_size;
  v18 = v3->m_stripLengths.m_data;
  v3->m_stripLengths.m_size = v17;
  v19 = v17;
  if ( (signed int)v17 > 0 )
  {
    v20 = (char *)((char *)v2->m_stripLengths.m_data - (char *)v18);
    do
    {
      v21 = *(unsigned __int16 *)((char *)v18 + (_QWORD)v20);
      ++v18;
      *(v18 - 1) = v21;
      --v19;
    }
    while ( v19 );
  }
  v22 = v3->m_weldingInfo.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v22 < v2->m_weldingInfo.m_size )
  {
    if ( v3->m_weldingInfo.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v3->m_weldingInfo.m_data,
        2 * v22);
    v28 = 2 * v2->m_weldingInfo.m_size;
    v3->m_weldingInfo.m_data = (unsigned __int16 *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                     (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                     &v28);
    v3->m_weldingInfo.m_capacityAndFlags = v28 / 2;
  }
  v23 = v2->m_weldingInfo.m_size;
  v24 = v3->m_weldingInfo.m_data;
  v3->m_weldingInfo.m_size = v23;
  v25 = v23;
  if ( (signed int)v23 > 0 )
  {
    v26 = (char *)((char *)v2->m_weldingInfo.m_data - (char *)v24);
    do
    {
      v27 = *(unsigned __int16 *)((char *)v24 + (_QWORD)v26);
      ++v24;
      *(v24 - 1) = v27;
      --v25;
    }
    while ( v25 );
  }
  v3->m_materialInfo = v2->m_materialInfo;
  v3->m_reference = v2->m_reference;
  v3->m_transformIndex = v2->m_transformIndex;
}

// File Line: 311
// RVA: 0x1326730
void __fastcall hkpCompressedMeshShape::ConvexPiece::ConvexPiece(hkpCompressedMeshShape::ConvexPiece *this, hkpCompressedMeshShape::ConvexPiece *other)
{
  hkpCompressedMeshShape::ConvexPiece *v2; // rdi
  hkpCompressedMeshShape::ConvexPiece *v3; // rbx
  int v4; // er8
  __int64 v5; // rcx
  unsigned __int16 *v6; // rax
  __int64 v7; // rdx
  char *v8; // r8
  unsigned __int16 v9; // cx
  int v10; // [rsp+30h] [rbp+8h]

  this->m_vertices.m_capacityAndFlags = 2147483648;
  v2 = other;
  this->m_vertices.m_data = 0i64;
  this->m_vertices.m_size = 0;
  v3 = this;
  this->m_offset = other->m_offset;
  v4 = this->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < other->m_vertices.m_size )
  {
    if ( this->m_vertices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        this->m_vertices.m_data,
        2 * v4);
    v10 = 2 * v2->m_vertices.m_size;
    v3->m_vertices.m_data = (unsigned __int16 *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                  &v10);
    v3->m_vertices.m_capacityAndFlags = v10 / 2;
  }
  v5 = v2->m_vertices.m_size;
  v6 = v3->m_vertices.m_data;
  v3->m_vertices.m_size = v5;
  v7 = v5;
  if ( (signed int)v5 > 0 )
  {
    v8 = (char *)((char *)v2->m_vertices.m_data - (char *)v6);
    do
    {
      v9 = *(unsigned __int16 *)((char *)v6 + (_QWORD)v8);
      ++v6;
      *(v6 - 1) = v9;
      --v7;
    }
    while ( v7 );
  }
  v3->m_reference = v2->m_reference;
  v3->m_transformIndex = v2->m_transformIndex;
}

