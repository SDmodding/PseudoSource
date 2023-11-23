// File Line: 215
// RVA: 0x1326470
void __fastcall hkpCompressedMeshShape::Chunk::Chunk(
        hkpCompressedMeshShape::Chunk *this,
        hkpCompressedMeshShape::Chunk *other)
{
  int v4; // r8d
  __int64 m_size; // rax
  unsigned __int16 *m_data; // rcx
  __int64 v7; // rdx
  char *v8; // r8
  unsigned __int16 v9; // ax
  int v10; // r8d
  __int64 v11; // rax
  unsigned __int16 *v12; // rcx
  __int64 v13; // rdx
  char *v14; // r8
  unsigned __int16 v15; // ax
  int v16; // r8d
  __int64 v17; // rax
  unsigned __int16 *v18; // rcx
  __int64 v19; // rdx
  char *v20; // r8
  unsigned __int16 v21; // ax
  int v22; // r8d
  __int64 v23; // rax
  unsigned __int16 *v24; // rcx
  __int64 v25; // rdx
  char *v26; // r8
  unsigned __int16 v27; // ax
  int v28; // [rsp+30h] [rbp+8h] BYREF

  this->m_vertices.m_capacityAndFlags = 0x80000000;
  this->m_vertices.m_data = 0i64;
  this->m_vertices.m_size = 0;
  this->m_indices.m_data = 0i64;
  this->m_indices.m_size = 0;
  this->m_indices.m_capacityAndFlags = 0x80000000;
  this->m_stripLengths.m_data = 0i64;
  this->m_stripLengths.m_size = 0;
  this->m_stripLengths.m_capacityAndFlags = 0x80000000;
  this->m_weldingInfo.m_data = 0i64;
  this->m_weldingInfo.m_size = 0;
  this->m_weldingInfo.m_capacityAndFlags = 0x80000000;
  this->m_offset = other->m_offset;
  v4 = this->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < other->m_vertices.m_size )
  {
    if ( this->m_vertices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_vertices.m_data,
        2 * v4);
    v28 = 2 * other->m_vertices.m_size;
    this->m_vertices.m_data = (unsigned __int16 *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                    &hkContainerHeapAllocator::s_alloc,
                                                    &v28);
    this->m_vertices.m_capacityAndFlags = v28 / 2;
  }
  m_size = other->m_vertices.m_size;
  m_data = this->m_vertices.m_data;
  this->m_vertices.m_size = m_size;
  v7 = m_size;
  if ( (int)m_size > 0 )
  {
    v8 = (char *)((char *)other->m_vertices.m_data - (char *)m_data);
    do
    {
      v9 = *(unsigned __int16 *)((char *)m_data++ + (_QWORD)v8);
      *(m_data - 1) = v9;
      --v7;
    }
    while ( v7 );
  }
  v10 = this->m_indices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 < other->m_indices.m_size )
  {
    if ( this->m_indices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_indices.m_data,
        2 * v10);
    v28 = 2 * other->m_indices.m_size;
    this->m_indices.m_data = (unsigned __int16 *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                   &hkContainerHeapAllocator::s_alloc,
                                                   &v28);
    this->m_indices.m_capacityAndFlags = v28 / 2;
  }
  v11 = other->m_indices.m_size;
  v12 = this->m_indices.m_data;
  this->m_indices.m_size = v11;
  v13 = v11;
  if ( (int)v11 > 0 )
  {
    v14 = (char *)((char *)other->m_indices.m_data - (char *)v12);
    do
    {
      v15 = *(unsigned __int16 *)((char *)v12++ + (_QWORD)v14);
      *(v12 - 1) = v15;
      --v13;
    }
    while ( v13 );
  }
  v16 = this->m_stripLengths.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v16 < other->m_stripLengths.m_size )
  {
    if ( this->m_stripLengths.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_stripLengths.m_data,
        2 * v16);
    v28 = 2 * other->m_stripLengths.m_size;
    this->m_stripLengths.m_data = (unsigned __int16 *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                        &hkContainerHeapAllocator::s_alloc,
                                                        &v28);
    this->m_stripLengths.m_capacityAndFlags = v28 / 2;
  }
  v17 = other->m_stripLengths.m_size;
  v18 = this->m_stripLengths.m_data;
  this->m_stripLengths.m_size = v17;
  v19 = v17;
  if ( (int)v17 > 0 )
  {
    v20 = (char *)((char *)other->m_stripLengths.m_data - (char *)v18);
    do
    {
      v21 = *(unsigned __int16 *)((char *)v18++ + (_QWORD)v20);
      *(v18 - 1) = v21;
      --v19;
    }
    while ( v19 );
  }
  v22 = this->m_weldingInfo.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v22 < other->m_weldingInfo.m_size )
  {
    if ( this->m_weldingInfo.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_weldingInfo.m_data,
        2 * v22);
    v28 = 2 * other->m_weldingInfo.m_size;
    this->m_weldingInfo.m_data = (unsigned __int16 *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                       &hkContainerHeapAllocator::s_alloc,
                                                       &v28);
    this->m_weldingInfo.m_capacityAndFlags = v28 / 2;
  }
  v23 = other->m_weldingInfo.m_size;
  v24 = this->m_weldingInfo.m_data;
  this->m_weldingInfo.m_size = v23;
  v25 = v23;
  if ( (int)v23 > 0 )
  {
    v26 = (char *)((char *)other->m_weldingInfo.m_data - (char *)v24);
    do
    {
      v27 = *(unsigned __int16 *)((char *)v24++ + (_QWORD)v26);
      *(v24 - 1) = v27;
      --v25;
    }
    while ( v25 );
  }
  this->m_materialInfo = other->m_materialInfo;
  this->m_reference = other->m_reference;
  this->m_transformIndex = other->m_transformIndex;
}

// File Line: 311
// RVA: 0x1326730
void __fastcall hkpCompressedMeshShape::ConvexPiece::ConvexPiece(
        hkpCompressedMeshShape::ConvexPiece *this,
        hkpCompressedMeshShape::ConvexPiece *other)
{
  int v4; // r8d
  __int64 m_size; // rcx
  unsigned __int16 *m_data; // rax
  __int64 v7; // rdx
  char *v8; // r8
  unsigned __int16 v9; // cx
  int v10; // [rsp+30h] [rbp+8h] BYREF

  this->m_vertices.m_capacityAndFlags = 0x80000000;
  this->m_vertices.m_data = 0i64;
  this->m_vertices.m_size = 0;
  this->m_offset = other->m_offset;
  v4 = this->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < other->m_vertices.m_size )
  {
    if ( this->m_vertices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_vertices.m_data,
        2 * v4);
    v10 = 2 * other->m_vertices.m_size;
    this->m_vertices.m_data = (unsigned __int16 *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                    &hkContainerHeapAllocator::s_alloc,
                                                    &v10);
    this->m_vertices.m_capacityAndFlags = v10 / 2;
  }
  m_size = other->m_vertices.m_size;
  m_data = this->m_vertices.m_data;
  this->m_vertices.m_size = m_size;
  v7 = m_size;
  if ( (int)m_size > 0 )
  {
    v8 = (char *)((char *)other->m_vertices.m_data - (char *)m_data);
    do
    {
      v9 = *(unsigned __int16 *)((char *)m_data++ + (_QWORD)v8);
      *(m_data - 1) = v9;
      --v7;
    }
    while ( v7 );
  }
  this->m_reference = other->m_reference;
  this->m_transformIndex = other->m_transformIndex;
}

