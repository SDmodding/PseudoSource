// File Line: 23
// RVA: 0x1322470
void __fastcall hkpCompressedMeshShapeBuilder::createMeshShape(
        hkpCompressedMeshShapeBuilder *this,
        float quantizationError,
        hkpCompressedMeshShape::MaterialType materialType,
        int bitsPerIndex)
{
  char v6; // si
  _QWORD **Value; // rax
  hkpCompressedMeshShape *v8; // rax

  v6 = materialType;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (hkpCompressedMeshShape *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 288i64);
  if ( v8 )
    hkpCompressedMeshShape::hkpCompressedMeshShape(v8, bitsPerIndex, hkConvexShapeDefaultRadius);
  v8->m_error = quantizationError;
  v8->m_materialType.m_storage = v6;
  v8->m_bounds.m_min = (hkVector4f)xmmword_141A712A0;
  v8->m_bounds.m_max.m_quad = _mm_xor_ps(
                                (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                v8->m_bounds.m_min.m_quad);
  this->m_error = quantizationError;
  this->m_shapeKeys.m_size = 0;
  this->m_mesh = v8;
}

// File Line: 39
// RVA: 0x1323450
void __fastcall hkpCompressedMeshShapeBuilder::gatherStatistics(
        hkpCompressedMeshShapeBuilder *this,
        hkpCompressedMeshShape *meshShape)
{
  __int64 m_size; // r11
  int v3; // ebx
  int v6; // r9d
  int v7; // edi
  int *p_m_size; // r10
  unsigned int v9; // edx
  int v10; // ecx
  int v11; // r8d
  __int64 v12; // rdx
  int *v13; // rcx
  int v14; // eax
  float m_error; // xmm1_4
  int v16; // ecx
  int v17; // edx
  int v18; // r9d
  int v19; // ecx
  int v20; // eax
  int v21; // r9d
  int m_numVertices; // ecx
  int v23; // edx
  int v24; // ecx
  int v25; // eax

  m_size = meshShape->m_chunks.m_size;
  v3 = 0;
  v6 = 288;
  v7 = 0;
  if ( m_size > 0 )
  {
    p_m_size = &meshShape->m_chunks.m_data->m_vertices.m_size;
    do
    {
      v7 += p_m_size[8];
      v9 = (unsigned __int64)(1431655766i64 * *p_m_size) >> 32;
      v10 = p_m_size[4] + p_m_size[12];
      p_m_size += 24;
      v3 += (v9 >> 31) + v9;
      v6 += 2 * (*(p_m_size - 24) + *(p_m_size - 16) + v10) + 96;
      --m_size;
    }
    while ( m_size );
  }
  this->m_statistics.m_chunksSize = v6;
  v11 = v6;
  if ( meshShape->m_convexPieces.m_size > 0 )
  {
    v12 = meshShape->m_convexPieces.m_size;
    v13 = &meshShape->m_convexPieces.m_data->m_vertices.m_size;
    do
    {
      v14 = *v13;
      v13 += 12;
      v6 += 2 * v14 + 48;
      --v12;
    }
    while ( v12 );
  }
  m_error = this->m_error;
  v16 = v6;
  this->m_statistics.m_convexPiecesSize = v6 - v11;
  v17 = meshShape->m_bigVertices.m_size;
  v18 = 16 * (v17 + meshShape->m_bigTriangles.m_size) + v6;
  this->m_statistics.m_bigTrianglesSize = v18 - v16;
  v19 = meshShape->m_materials16.m_size + 2 * (meshShape->m_materials.m_size + 16 * meshShape->m_transforms.m_size);
  v20 = meshShape->m_materials8.m_size;
  this->m_statistics.m_error = m_error;
  this->m_statistics.m_maxExtent = m_error * 65535.0;
  this->m_statistics.m_maxIndex = 0xFFFF;
  v21 = v20 + 2 * v19 + v18;
  m_numVertices = this->m_statistics.m_numVertices;
  v23 = v17 - m_numVertices;
  v24 = this->m_statistics.m_numTriangles + m_numVertices + 3;
  this->m_statistics.m_numExcessVertices = v3 + v23;
  v25 = meshShape->m_chunks.m_size;
  this->m_statistics.m_numStrips = v7;
  this->m_statistics.m_numChunks = v25;
  this->m_statistics.m_size = v21;
  this->m_statistics.m_compressRatio = (float)v21 / (float)(16 * v24);
}

// File Line: 92
// RVA: 0x1322530
void __fastcall hkpCompressedMeshShapeBuilder::addGeometry(
        hkpCompressedMeshShapeBuilder *this,
        hkGeometry *geometry,
        hkMatrix4f *transform,
        hkpCompressedMeshShape *meshShape)
{
  hkGeometry *p_m_geometry; // rcx
  __int64 v9; // rbx
  int i; // edi
  hkVector4f *v11; // r8
  hkpCompressedMeshShapeBuilder::MappingTree *v12; // rsi
  __int64 v13; // r15
  _QWORD **Value; // rax
  __int64 v15; // rax
  int m_size; // edi
  int v17; // eax
  int v18; // eax
  int v19; // r9d
  __int64 v20; // rcx
  __int64 v21; // rdx
  __int64 v22; // rax
  int v23; // edx
  __int64 v24; // rcx
  int v25; // r14d
  int v26; // r9d
  int v27; // eax
  int v28; // eax
  int v29; // edx
  __int64 v30; // rcx
  int v31; // edi
  hkpCompressedMeshShapeBuilder::MappingTree *m_left; // rcx
  hkpCompressedMeshShapeBuilder::MappingTree *m_right; // rcx
  int m_capacityAndFlags; // eax
  _QWORD **v35; // rax
  hkpCompressedMeshShapeBuilder::TriangleMapping *m_data; // rax
  __int64 m_originalIndex; // rcx
  hkQsTransformf a; // [rsp+30h] [rbp-58h] BYREF
  hkResult result; // [rsp+90h] [rbp+8h] BYREF

  this->m_mesh = meshShape;
  this->m_statistics.m_numVertices += geometry->m_vertices.m_size;
  p_m_geometry = &this->m_geometry;
  HIDWORD(p_m_geometry[-3].m_vertices.m_data) += geometry->m_triangles.m_size;
  hkGeometry::operator=(p_m_geometry, geometry);
  hkQsTransformf::set(&a, transform);
  v9 = 0i64;
  for ( i = 0; i < this->m_geometry.m_vertices.m_size; ++i )
  {
    v11 = &this->m_geometry.m_vertices.m_data[i];
    hkVector4f::setTransformedPos(v11, &a, v11);
  }
  v12 = 0i64;
  LODWORD(v13) = 0;
  if ( this->m_createMapping )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v15 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
    v12 = (hkpCompressedMeshShapeBuilder::MappingTree *)v15;
    if ( v15 )
    {
      *(_QWORD *)v15 = 0i64;
      *(_DWORD *)(v15 + 8) = 0;
      *(_DWORD *)(v15 + 12) = 0x80000000;
      *(_QWORD *)(v15 + 16) = 0i64;
      *(_QWORD *)(v15 + 24) = 0i64;
    }
    else
    {
      v12 = 0i64;
    }
    m_size = geometry->m_triangles.m_size;
    v17 = v12->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v17 < m_size )
    {
      v18 = 2 * v17;
      v19 = geometry->m_triangles.m_size;
      if ( m_size < v18 )
        v19 = v18;
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&v12->m_triangles.m_data,
        v19,
        20);
    }
    v20 = v12->m_triangles.m_size;
    v21 = m_size - (int)v20;
    if ( m_size - (int)v20 > 0 )
    {
      v22 = (__int64)(&v12->m_triangles.m_data->m_chunkIndex + 4 * v20 + v20);
      do
      {
        if ( v22 != 8 )
        {
          *(_DWORD *)(v22 - 8) = -1;
          *(_QWORD *)(v22 - 4) = -1i64;
          *(_QWORD *)(v22 + 4) = -1i64;
        }
        v22 += 20i64;
        --v21;
      }
      while ( v21 );
    }
    v12->m_triangles.m_size = m_size;
    v23 = 0;
    if ( m_size > 0 )
    {
      v24 = 0i64;
      do
      {
        v12->m_triangles.m_data[v24++].m_originalIndex = v23++;
        v12->m_triangles.m_data[v24 - 1].m_winding = 0;
      }
      while ( v23 < v12->m_triangles.m_size );
    }
    this->m_bigMapping.m_size = 0;
    v25 = geometry->m_triangles.m_size;
    v13 = this->m_shapeKeys.m_size;
    v26 = v25 + this->m_shapeKeys.m_size;
    v27 = this->m_shapeKeys.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v27 < v26 )
    {
      v28 = 2 * v27;
      if ( v26 < v28 )
        v26 = v28;
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&this->m_shapeKeys.m_data,
        v26,
        4);
    }
    this->m_shapeKeys.m_size += v25;
    v29 = v13;
    if ( (int)v13 < this->m_shapeKeys.m_size )
    {
      v30 = v13;
      do
      {
        ++v29;
        this->m_shapeKeys.m_data[v30++] = -1;
      }
      while ( v29 < this->m_shapeKeys.m_size );
    }
  }
  if ( this->m_preserveTjunctions )
    hkpCompressedMeshShapeBuilder::snapGeometry(this, v12);
  else
    hkpCompressedMeshShapeBuilder::snapGeometry(&this->m_geometry, this->m_error);
  hkpCompressedMeshShapeBuilder::filterGeometry(this, v12);
  if ( this->m_geometry.m_triangles.m_size || this->m_leftOver.m_triangles.m_size )
  {
    hkpCompressedMeshShapeBuilder::addChunk(this, &this->m_geometry, &meshShape->m_chunks, v12);
    v31 = hkpCompressedMeshShapeBuilder::addBigTriangles(this, meshShape);
    if ( this->m_createMapping )
    {
      hkpCompressedMeshShapeBuilder::MappingTree::getKeys(v12, &this->m_shapeKeys, v13);
      if ( v12 )
      {
        m_left = v12->m_left;
        if ( m_left )
          hkpCompressedMeshShapeBuilder::MappingTree::`scalar deleting destructor(m_left, 1u);
        m_right = v12->m_right;
        if ( m_right )
          hkpCompressedMeshShapeBuilder::MappingTree::`scalar deleting destructor(m_right, 1u);
        m_capacityAndFlags = v12->m_triangles.m_capacityAndFlags;
        v12->m_triangles.m_size = 0;
        if ( m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            v12->m_triangles.m_data,
            20 * (m_capacityAndFlags & 0x3FFFFFFF));
        v12->m_triangles.m_data = 0i64;
        v12->m_triangles.m_capacityAndFlags = 0x80000000;
        v35 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, hkpCompressedMeshShapeBuilder::MappingTree *, __int64))(*v35[11] + 16i64))(
          v35[11],
          v12,
          32i64);
      }
      for ( ; v31 < meshShape->m_bigTriangles.m_size; ++v31 )
      {
        m_data = this->m_bigMapping.m_data;
        m_originalIndex = m_data[v9++].m_originalIndex;
        m_data[v9 - 1].m_triangleIndex = v31;
        m_data[v9 - 1].m_key = v31;
        this->m_shapeKeys.m_data[(int)v13 + m_originalIndex] = v31;
      }
    }
  }
}

// File Line: 176
// RVA: 0x1322C50
__int64 __fastcall hkpCompressedMeshShapeBuilder::beginSubpart(
        hkpCompressedMeshShapeBuilder *this,
        hkpCompressedMeshShape *compressedMesh)
{
  int m_size; // esi
  int v3; // ebp
  int v4; // r14d
  int v5; // r15d
  hkArray<hkpCompressedMeshShapeBuilder::Subpart,hkContainerHeapAllocator> *p_subparts; // rbx
  hkpCompressedMeshShapeBuilder::Subpart *v8; // rdx

  m_size = compressedMesh->m_chunks.m_size;
  v3 = compressedMesh->m_bigTriangles.m_size;
  v4 = compressedMesh->m_convexPieces.m_size;
  v5 = this->m_shapeKeys.m_size;
  p_subparts = &this->subparts;
  if ( this->subparts.m_size == (this->subparts.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_subparts->m_data, 36);
  v8 = &p_subparts->m_data[p_subparts->m_size];
  if ( v8 )
  {
    v8->m_numInstances = 0;
    v8->m_chunkOffset = m_size;
    v8->m_numChunks = 0;
    v8->m_bigOffset = v3;
    v8->m_numBigTriangles = 0;
    v8->m_convexOffset = v4;
    v8->m_numConvexPieces = 0;
    v8->m_geomOffset = v5;
    v8->m_numTriangles = 0;
  }
  ++p_subparts->m_size;
  return (unsigned int)(this->subparts.m_size - 1);
}

// File Line: 193
// RVA: 0x1322D20
void __fastcall hkpCompressedMeshShapeBuilder::endSubpart(
        hkpCompressedMeshShapeBuilder *this,
        hkpCompressedMeshShape *compressedMesh)
{
  hkpCompressedMeshShapeBuilder::Subpart *v2; // r9

  v2 = &this->subparts.m_data[this->subparts.m_size - 1];
  v2->m_numChunks = compressedMesh->m_chunks.m_size - v2->m_chunkOffset;
  v2->m_numBigTriangles = compressedMesh->m_bigTriangles.m_size - v2->m_bigOffset;
  v2->m_numConvexPieces = compressedMesh->m_convexPieces.m_size - v2->m_convexOffset;
  if ( this->m_createMapping )
    v2->m_numTriangles = this->m_shapeKeys.m_size - v2->m_geomOffset;
}

// File Line: 206
// RVA: 0x1322D90
void __fastcall hkpCompressedMeshShapeBuilder::addInstance(
        hkpCompressedMeshShapeBuilder *this,
        int subpartID,
        hkMatrix4f *transform,
        hkpCompressedMeshShape *compressedMesh,
        hkArray<unsigned int,hkContainerHeapAllocator> *shapeKeyMap)
{
  __int64 v5; // rbx
  int m_size; // r12d
  hkpCompressedMeshShapeBuilder *v8; // r11
  __int64 v9; // rdx
  hkpCompressedMeshShapeBuilder::Subpart *v10; // r13
  __int64 m_chunkOffset; // rsi
  int v12; // eax
  hkArray<hkpCompressedMeshShape::Chunk,hkContainerHeapAllocator> *p_m_chunks; // rbx
  __int64 v14; // r14
  int v15; // r15d
  int v16; // eax
  hkpCompressedMeshShape::Chunk *v17; // rcx
  hkVector4f v18; // xmm1
  hkpCompressedMeshShapeBuilder::Subpart *m_data; // rax
  __int64 v20; // r15
  __int64 v21; // rcx
  hkArray<hkpCompressedMeshShape::BigTriangle,hkContainerHeapAllocator> *p_m_bigTriangles; // rbx
  __int64 v23; // rsi
  hkpCompressedMeshShape::BigTriangle *v24; // rax
  int v25; // r14d
  int v26; // edx
  unsigned int m_material; // r8d
  int v28; // r15d
  int v29; // eax
  hkpCompressedMeshShape::BigTriangle *v30; // rcx
  int v31; // eax
  hkVector4f *v32; // rcx
  unsigned __int16 *p_m_a; // rdx
  __m128 m_quad; // xmm2
  __m128 v35; // xmm0
  __m128 v36; // xmm3
  unsigned __int16 v37; // ax
  hkQsTransformf *v38; // rdx
  __m128 v39; // xmm1
  __m128 v40; // xmm2
  bool v41; // zf
  hkVector4f v42; // xmm0
  hkVector4f v43; // xmm1
  __int64 m_geomOffset; // rcx
  __int64 v45; // r14
  __int64 v46; // r15
  unsigned int v47; // ebx
  int m_bitsPerWIndex; // r10d
  int v49; // r9d
  unsigned int v50; // r8d
  hkpCompressedMeshShapeBuilder::Subpart *v51; // rax
  __int64 v52; // rcx
  __int64 m_convexOffset; // r14
  hkArray<hkpCompressedMeshShape::ConvexPiece,hkContainerHeapAllocator> *p_m_convexPieces; // rsi
  __int64 v55; // r15
  int v56; // r12d
  __int64 v57; // rbx
  hkVector4f v58; // xmm1
  unsigned __int16 v59; // [rsp+20h] [rbp-E0h]
  int v60; // [rsp+24h] [rbp-DCh]
  unsigned int v61; // [rsp+28h] [rbp-D8h]
  __int64 v62; // [rsp+30h] [rbp-D0h]
  int v63; // [rsp+38h] [rbp-C8h]
  __int64 v64; // [rsp+40h] [rbp-C0h]
  hkAabb bounds; // [rsp+50h] [rbp-B0h] BYREF
  hkpCompressedMeshShapeBuilder::Subpart *v66; // [rsp+70h] [rbp-90h]
  hkVector4f v67; // [rsp+80h] [rbp-80h] BYREF
  hkVector4f v68; // [rsp+90h] [rbp-70h] BYREF
  hkpCompressedMeshShape::Chunk other; // [rsp+A0h] [rbp-60h] BYREF
  hkVector4f b; // [rsp+100h] [rbp+0h] BYREF
  hkQsTransformf v71; // [rsp+110h] [rbp+10h] BYREF
  int v73; // [rsp+198h] [rbp+98h]
  int v74; // [rsp+198h] [rbp+98h]
  int v75; // [rsp+1A8h] [rbp+A8h]
  int v76; // [rsp+1A8h] [rbp+A8h]

  v5 = subpartID;
  hkQsTransformf::set(&v71, transform);
  m_size = compressedMesh->m_transforms.m_size;
  v59 = m_size;
  if ( m_size == (compressedMesh->m_transforms.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&compressedMesh->m_transforms.m_data,
      48);
  v8 = this;
  compressedMesh->m_transforms.m_data[compressedMesh->m_transforms.m_size++] = v71;
  v9 = 36 * v5;
  v10 = &this->subparts.m_data[v5];
  v63 = compressedMesh->m_chunks.m_size;
  m_chunkOffset = v10->m_chunkOffset;
  v62 = 36 * v5;
  v12 = m_chunkOffset + v10->m_numChunks;
  v66 = v10;
  v73 = v12;
  if ( (int)m_chunkOffset < v12 )
  {
    p_m_chunks = &compressedMesh->m_chunks;
    v14 = m_chunkOffset;
    do
    {
      v15 = m_chunkOffset;
      if ( v10->m_numInstances )
      {
        v15 = compressedMesh->m_chunks.m_size;
        v16 = compressedMesh->m_chunks.m_capacityAndFlags & 0x3FFFFFFF;
        memset(&other, 0, 28);
        other.m_vertices.m_capacityAndFlags = 0x80000000;
        other.m_indices.m_data = 0i64;
        other.m_indices.m_size = 0;
        other.m_indices.m_capacityAndFlags = 0x80000000;
        other.m_stripLengths.m_data = 0i64;
        other.m_stripLengths.m_size = 0;
        other.m_stripLengths.m_capacityAndFlags = 0x80000000;
        other.m_weldingInfo.m_data = 0i64;
        other.m_weldingInfo.m_size = 0;
        other.m_weldingInfo.m_capacityAndFlags = 0x80000000;
        other.m_materialInfo = 0;
        other.m_reference = m_chunkOffset;
        other.m_transformIndex = m_size;
        if ( compressedMesh->m_chunks.m_size == v16 )
          hkArrayUtil::_reserveMore(
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&compressedMesh->m_chunks.m_data,
            96);
        v17 = &p_m_chunks->m_data[compressedMesh->m_chunks.m_size];
        if ( v17 )
          hkpCompressedMeshShape::Chunk::Chunk(v17, &other);
        ++compressedMesh->m_chunks.m_size;
        ++this->m_statistics.m_numChunkClones;
        hkpCompressedMeshShape::Chunk::~Chunk(&other);
      }
      else
      {
        p_m_chunks->m_data[v14].m_transformIndex = m_size;
      }
      hkpCompressedMeshShape::getChunkAabb(compressedMesh, &p_m_chunks->m_data[v15], &bounds);
      LODWORD(m_chunkOffset) = m_chunkOffset + 1;
      ++v14;
      v18.m_quad = _mm_max_ps(compressedMesh->m_bounds.m_max.m_quad, bounds.m_max.m_quad);
      compressedMesh->m_bounds.m_min.m_quad = _mm_min_ps(compressedMesh->m_bounds.m_min.m_quad, bounds.m_min.m_quad);
      compressedMesh->m_bounds.m_max = (hkVector4f)v18.m_quad;
    }
    while ( (int)m_chunkOffset < v73 );
    v8 = this;
    v9 = v62;
  }
  m_data = v8->subparts.m_data;
  v20 = *(int *)((char *)&m_data->m_bigOffset + v9);
  v60 = compressedMesh->m_bigTriangles.m_size;
  v74 = v20;
  v21 = (int)v20 + *(int *)((char *)&m_data->m_numBigTriangles + v9);
  if ( v20 < v21 )
  {
    p_m_bigTriangles = &compressedMesh->m_bigTriangles;
    v23 = v20;
    v64 = v21 - v20;
    do
    {
      v24 = p_m_bigTriangles->m_data;
      v25 = v20;
      if ( v10->m_numInstances )
      {
        v26 = *(_DWORD *)&v24[v23].m_c;
        m_material = v24[v23].m_material;
        v28 = *(_DWORD *)&v24[v23].m_a;
        v25 = compressedMesh->m_bigTriangles.m_size;
        v75 = v26;
        bounds.m_min.m_quad.m128_i32[3] = *(_DWORD *)&v24[v23].m_weldingInfo;
        v61 = m_material;
        v29 = compressedMesh->m_bigTriangles.m_capacityAndFlags & 0x3FFFFFFF;
        bounds.m_min.m_quad.m128_i16[7] = m_size;
        if ( compressedMesh->m_bigTriangles.m_size == v29 )
        {
          hkArrayUtil::_reserveMore(
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&compressedMesh->m_bigTriangles.m_data,
            16);
          v26 = v75;
          m_material = v61;
        }
        v30 = &p_m_bigTriangles->m_data[compressedMesh->m_bigTriangles.m_size];
        if ( v30 )
        {
          v31 = bounds.m_min.m_quad.m128_i32[3];
          *(_DWORD *)&v30->m_a = v28;
          *(_DWORD *)&v30->m_c = v26;
          v30->m_material = m_material;
          *(_DWORD *)&v30->m_weldingInfo = v31;
        }
        ++compressedMesh->m_bigTriangles.m_size;
        LODWORD(v20) = v74;
      }
      else
      {
        v24[v23].m_transformIndex = m_size;
      }
      v32 = compressedMesh->m_bigVertices.m_data;
      p_m_a = &p_m_bigTriangles->m_data[v25].m_a;
      m_quad = v32[*p_m_a].m_quad;
      b.m_quad = m_quad;
      v35 = v32[p_m_a[1]].m_quad;
      v68.m_quad = v35;
      v36 = v32[p_m_a[2]].m_quad;
      v67.m_quad = v36;
      v37 = p_m_a[7];
      if ( v37 != 0xFFFF )
      {
        v38 = compressedMesh->m_transforms.m_data;
        other.m_offset = v38[v37].m_translation;
        other.m_vertices = (hkArray<unsigned short,hkContainerHeapAllocator>)v38[v37].m_rotation;
        other.m_indices = (hkArray<unsigned short,hkContainerHeapAllocator>)v38[v37].m_scale;
        hkVector4f::setTransformedPos(&b, (hkQsTransformf *)&other, &b);
        hkVector4f::setTransformedPos(&v68, (hkQsTransformf *)&other, &v68);
        hkVector4f::setTransformedPos(&v67, (hkQsTransformf *)&other, &v67);
        v36 = v67.m_quad;
        v35 = v68.m_quad;
        m_quad = b.m_quad;
      }
      v39 = m_quad;
      LODWORD(v20) = v20 + 1;
      v40 = _mm_max_ps(_mm_max_ps(m_quad, v35), v36);
      ++v23;
      v41 = v64-- == 1;
      v74 = v20;
      v42.m_quad = _mm_min_ps(compressedMesh->m_bounds.m_min.m_quad, _mm_min_ps(_mm_min_ps(v39, v35), v36));
      v43.m_quad = (__m128)compressedMesh->m_bounds.m_max;
      compressedMesh->m_bounds.m_min = (hkVector4f)v42.m_quad;
      compressedMesh->m_bounds.m_max.m_quad = _mm_max_ps(v43.m_quad, v40);
    }
    while ( !v41 );
    v8 = this;
  }
  if ( v8->m_createMapping )
  {
    if ( shapeKeyMap )
    {
      m_geomOffset = v10->m_geomOffset;
      v45 = m_geomOffset;
      v46 = (int)m_geomOffset + v10->m_numTriangles;
      if ( m_geomOffset < v46 )
      {
        do
        {
          v47 = v8->m_shapeKeys.m_data[v45];
          if ( v47 != -1 && v10->m_numInstances )
          {
            m_bitsPerWIndex = compressedMesh->m_bitsPerWIndex;
            v49 = v47 & compressedMesh->m_wIndexMask;
            v50 = v47 >> m_bitsPerWIndex;
            if ( v47 >> m_bitsPerWIndex )
            {
              if ( v50 != (1 << (32 - m_bitsPerWIndex)) - 1 )
                v47 = v49 | ((v63 + v50 - v10->m_chunkOffset) << m_bitsPerWIndex);
            }
            else
            {
              v47 = v60 + v49 - v10->m_bigOffset;
            }
          }
          if ( shapeKeyMap->m_size == (shapeKeyMap->m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&shapeKeyMap->m_data, 4);
            v8 = this;
          }
          ++v45;
          shapeKeyMap->m_data[shapeKeyMap->m_size++] = v47;
        }
        while ( v45 < v46 );
      }
    }
  }
  v51 = v8->subparts.m_data;
  v52 = v62;
  m_convexOffset = v51[(unsigned __int64)v62 / 0x24].m_convexOffset;
  v76 = m_convexOffset + v51[(unsigned __int64)v62 / 0x24].m_numConvexPieces;
  if ( (int)m_convexOffset < v76 )
  {
    p_m_convexPieces = &compressedMesh->m_convexPieces;
    v55 = m_convexOffset;
    do
    {
      v56 = m_convexOffset;
      if ( *(int *)((char *)&v8->subparts.m_data->m_numInstances + v52) )
      {
        v56 = compressedMesh->m_convexPieces.m_size;
        if ( v56 == (compressedMesh->m_convexPieces.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&compressedMesh->m_convexPieces.m_data,
            48);
        v57 = (__int64)&p_m_convexPieces->m_data[compressedMesh->m_convexPieces.m_size];
        if ( v57 )
        {
          *(_DWORD *)(v57 + 28) = 0x80000000;
          *(_QWORD *)(v57 + 16) = 0i64;
          *(_DWORD *)(v57 + 24) = 0;
          *(_OWORD *)v57 = 0i64;
          *(_DWORD *)(v57 + 24) = 0;
          *(_WORD *)(v57 + 32) = m_convexOffset;
          *(_WORD *)(v57 + 34) = v59;
        }
        ++compressedMesh->m_convexPieces.m_size;
      }
      else
      {
        p_m_convexPieces->m_data[v55].m_transformIndex = v59;
      }
      hkpCompressedMeshShape::getConvexPieceAabb(compressedMesh, &p_m_convexPieces->m_data[v56], &bounds);
      v8 = this;
      v52 = v62;
      v58.m_quad = _mm_max_ps(compressedMesh->m_bounds.m_max.m_quad, bounds.m_max.m_quad);
      LODWORD(m_convexOffset) = m_convexOffset + 1;
      ++v55;
      compressedMesh->m_bounds.m_min.m_quad = _mm_min_ps(compressedMesh->m_bounds.m_min.m_quad, bounds.m_min.m_quad);
      compressedMesh->m_bounds.m_max = (hkVector4f)v58.m_quad;
    }
    while ( (int)m_convexOffset < v76 );
    v10 = v66;
  }
  ++v10->m_numInstances;
}

// File Line: 344
// RVA: 0x13223A0
hkpCompressedMeshShape *__fastcall hkpCompressedMeshShapeBuilder::createMeshFromGeometry(
        hkGeometry *geometry,
        float quantizationError,
        hkpCompressedMeshShape::MaterialType materialType)
{
  hkpCompressedMeshShape *v5; // rsi
  int v6; // ebx
  hkpCompressedMeshShapeBuilder v8; // [rsp+30h] [rbp-148h] BYREF

  hkpCompressedMeshShapeBuilder::hkpCompressedMeshShapeBuilder(&v8);
  v5 = hkpCompressedMeshShapeBuilder::createMeshShape(&v8, quantizationError, materialType, 17);
  v6 = hkpCompressedMeshShapeBuilder::beginSubpart(&v8, v5);
  hkpCompressedMeshShapeBuilder::addGeometry(&v8, geometry, (hkMatrix4f *)&transform, v5);
  hkpCompressedMeshShapeBuilder::endSubpart(&v8, v5);
  hkpCompressedMeshShapeBuilder::addInstance(&v8, v6, (hkMatrix4f *)&transform, v5, 0i64);
  hkpCompressedMeshShapeBuilder::~hkpCompressedMeshShapeBuilder(&v8);
  return v5;
}

// File Line: 358
// RVA: 0x13246B0
void __fastcall hkpCompressedMeshShapeBuilder::appendGeometry(
        hkpCompressedMeshShapeBuilder *this,
        hkGeometry *dest,
        hkGeometry *geom)
{
  __int64 m_size; // rbx
  int v4; // esi
  __int64 v7; // rax

  m_size = dest->m_triangles.m_size;
  v4 = dest->m_vertices.m_size;
  hkArrayBase<hkGeometry::Triangle>::_append(
    &dest->m_triangles,
    &hkContainerHeapAllocator::s_alloc,
    geom->m_triangles.m_data,
    geom->m_triangles.m_size);
  if ( (int)m_size < dest->m_triangles.m_size )
  {
    v7 = m_size;
    do
    {
      LODWORD(m_size) = m_size + 1;
      dest->m_triangles.m_data[v7++].m_a += v4;
      dest->m_triangles.m_data[v7 - 1].m_b += v4;
      dest->m_triangles.m_data[v7 - 1].m_c += v4;
    }
    while ( (int)m_size < dest->m_triangles.m_size );
  }
  hkArrayBase<hkVector4f>::_append(
    &dest->m_vertices,
    &hkContainerHeapAllocator::s_alloc,
    geom->m_vertices.m_data,
    geom->m_vertices.m_size);
}

// File Line: 372
// RVA: 0x1325FB0
char __fastcall hasDifferentMaterials(hkGeometry *geometry)
{
  hkGeometry::Triangle *m_data; // r9
  __int64 m_size; // rdx
  __int64 v3; // rax
  int *i; // rcx

  m_data = geometry->m_triangles.m_data;
  m_size = geometry->m_triangles.m_size;
  v3 = 1i64;
  if ( m_size <= 1 )
    return 0;
  for ( i = &m_data[1].m_material; *i == m_data->m_material; i += 4 )
  {
    if ( ++v3 >= m_size )
      return 0;
  }
  return 1;
}

// File Line: 386
// RVA: 0x1324900
void __fastcall hkpCompressedMeshShapeBuilder::addChunk(
        hkpCompressedMeshShapeBuilder *this,
        hkGeometry *geometry,
        hkArray<hkpCompressedMeshShape::Chunk,hkContainerHeapAllocator> *chunks,
        hkpCompressedMeshShapeBuilder::MappingTree *mapping)
{
  bool v7; // cc
  hkVector4f v8; // xmm6
  __m128 v9; // xmm3
  __int64 v10; // rcx
  int v11; // ebx
  hkArray<hkpCompressedMeshShape::Chunk,hkContainerHeapAllocator> *v12; // rcx
  __int64 m_size; // rax
  __int64 v14; // r11
  int m_winding; // r10d
  int m_triangleIndex; // r9d
  int v17; // r8d
  hkpCompressedMeshShapeBuilder::MappingTree *m_right; // r9
  hkpCompressedMeshShapeBuilder::MappingTree *m_left; // r8
  hkpCompressedMeshShapeBuilder::MappingTree *v20; // rsi
  _QWORD **Value; // rax
  hkpCompressedMeshShapeBuilder::MappingTree *v22; // rsi
  _QWORD **v23; // rax
  __int64 *half; // [rsp+28h] [rbp-C0h]
  void **out2; // [rsp+40h] [rbp-A8h] BYREF
  int out2_8; // [rsp+48h] [rbp-A0h]
  void *out2_16; // [rsp+50h] [rbp-98h]
  int out2_24; // [rsp+58h] [rbp-90h]
  int out2_28; // [rsp+5Ch] [rbp-8Ch]
  void *out2_32; // [rsp+60h] [rbp-88h]
  hkpCompressedMeshShape::Chunk out2_40; // [rsp+68h] [rbp-80h] BYREF
  float v32[4]; // [rsp+C8h] [rbp-20h]
  hkAabb aabbOut; // [rsp+D8h] [rbp-10h] BYREF
  hkGeometry *source; // [rsp+130h] [rbp+48h]
  hkArray<hkpCompressedMeshShape::Chunk,hkContainerHeapAllocator> *retaddr; // [rsp+138h] [rbp+50h]

  hkAabbUtil::calcAabb(
    geometry->m_vertices.m_data,
    geometry->m_vertices.m_size,
    (hkAabb *)&aabbOut.m_max.m_quad.m128_u16[4]);
  v7 = geometry->m_vertices.m_size <= 255;
  v8.m_quad = (__m128)aabbOut.m_max;
  *(__m128 *)v32 = _mm_sub_ps(aabbOut.m_max.m_quad, aabbOut.m_min.m_quad);
  v9 = (__m128)_mm_srli_epi32(_mm_slli_epi32(*(__m128i *)v32, 1u), 1u);
  v10 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                               _mm_and_ps(
                                                                 _mm_cmple_ps(
                                                                   _mm_max_ps(
                                                                     _mm_shuffle_ps(v9, v9, 170),
                                                                     _mm_max_ps(
                                                                       _mm_shuffle_ps(v9, v9, 85),
                                                                       _mm_shuffle_ps(v9, v9, 0))),
                                                                   v9),
                                                                 (__m128)xmmword_141C20A50))];
  out2_40.m_offset.m_quad.m128_i32[2] = v10;
  if ( v7 && (float)(this->m_error * 65534.0) >= v32[v10] )
  {
    if ( this->m_mesh->m_materialType.m_storage != 1 || !hasDifferentMaterials(geometry) )
    {
      v11 = 0;
      memset(&out2_40, 0, 28);
      out2_40.m_vertices.m_capacityAndFlags = 0x80000000;
      out2_40.m_indices.m_data = 0i64;
      out2_40.m_indices.m_size = 0;
      out2_40.m_indices.m_capacityAndFlags = 0x80000000;
      out2_40.m_stripLengths.m_data = 0i64;
      out2_40.m_stripLengths.m_size = 0;
      out2_40.m_stripLengths.m_capacityAndFlags = 0x80000000;
      out2_40.m_weldingInfo.m_data = 0i64;
      out2_40.m_weldingInfo.m_size = 0;
      out2_40.m_weldingInfo.m_capacityAndFlags = 0x80000000;
      *(_DWORD *)&out2_40.m_reference = -1;
      out2_40.m_materialInfo = 0;
      hkpCompressedMeshShapeBuilder::createChunk(this, source, &aabbOut.m_min, &out2_40, mapping);
      v12 = retaddr;
      if ( retaddr->m_size == (retaddr->m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&retaddr->m_data, 96);
        v12 = retaddr;
      }
      m_size = v12->m_size;
      if ( &v12->m_data[m_size] )
      {
        hkpCompressedMeshShape::Chunk::Chunk(&v12->m_data[m_size], &out2_40);
        v12 = retaddr;
      }
      ++v12->m_size;
      if ( mapping && mapping->m_triangles.m_size > 0 )
      {
        v14 = 0i64;
        do
        {
          ++v11;
          m_winding = mapping->m_triangles.m_data[v14].m_winding;
          m_triangleIndex = mapping->m_triangles.m_data[v14].m_triangleIndex;
          v17 = v12->m_size - 1;
          mapping->m_triangles.m_data[v14++].m_chunkIndex = v17;
          v12 = retaddr;
          mapping->m_triangles.m_data[v14 - 1].m_key = m_triangleIndex & this->m_mesh->m_wIndexMask | ((v17 + 1) << this->m_mesh->m_bitsPerWIndex) | ((m_winding & 1) << this->m_mesh->m_bitsPerIndex);
        }
        while ( v11 < mapping->m_triangles.m_size );
      }
      hkpCompressedMeshShape::Chunk::~Chunk(&out2_40);
      return;
    }
    LODWORD(v10) = out2_40.m_offset.m_quad.m128_i32[2];
  }
  out2_40.m_offset.m_quad.m128_u64[0] = (unsigned __int64)&hkGeometry::`vftable;
  out2 = &hkGeometry::`vftable;
  *(__m128 *)v32 = _mm_mul_ps(_mm_add_ps(v8.m_quad, aabbOut.m_min.m_quad), (__m128)xmmword_141A711B0);
  *(float *)&half = v32[(int)v10];
  out2_40.m_vertices.m_data = 0i64;
  out2_40.m_vertices.m_size = 0;
  out2_40.m_vertices.m_capacityAndFlags = 0x80000000;
  out2_40.m_indices.m_data = 0i64;
  out2_40.m_indices.m_size = 0;
  out2_40.m_indices.m_capacityAndFlags = 0x80000000;
  out2_8 = 0x1FFFF;
  out2_16 = 0i64;
  out2_24 = 0;
  out2_28 = 0x80000000;
  out2_32 = 0i64;
  out2_40.m_offset.m_quad.m128_i32[0] = 0;
  *(unsigned __int64 *)((char *)out2_40.m_offset.m_quad.m128_u64 + 4) = 0x1FFFF80000000i64;
  hkpCompressedMeshShapeBuilder::splitGeometry(
    this,
    (hkpCompressedMeshShapeBuilder *)source,
    (hkGeometry *)&out2_40,
    (hkGeometry *)&out2,
    v10,
    half,
    mapping);
  if ( out2_40.m_indices.m_size )
  {
    if ( out2_40.m_offset.m_quad.m128_i32[0] )
    {
      if ( mapping )
      {
        hkpCompressedMeshShapeBuilder::addChunk(this, (hkGeometry *)&out2_40, retaddr, mapping->m_left);
        m_right = mapping->m_right;
      }
      else
      {
        hkpCompressedMeshShapeBuilder::addChunk(this, (hkGeometry *)&out2_40, retaddr, 0i64);
        m_right = 0i64;
      }
      hkpCompressedMeshShapeBuilder::addChunk(this, (hkGeometry *)&out2, retaddr, m_right);
      goto LABEL_33;
    }
    hkpCompressedMeshShapeBuilder::appendGeometry(this, &this->m_leftOver, (hkGeometry *)&out2_40);
    if ( mapping )
    {
      m_left = mapping->m_left;
LABEL_26:
      hkArrayBase<hkpCompressedMeshShapeBuilder::TriangleMapping>::_append(
        &this->m_bigMapping,
        &hkContainerHeapAllocator::s_alloc,
        m_left->m_triangles.m_data,
        m_left->m_triangles.m_size);
LABEL_27:
      if ( mapping )
      {
        v20 = mapping->m_left;
        if ( v20 )
        {
          hkpCompressedMeshShapeBuilder::MappingTree::~MappingTree(mapping->m_left);
          Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          (*(void (__fastcall **)(_QWORD *, hkpCompressedMeshShapeBuilder::MappingTree *, __int64))(*Value[11] + 16i64))(
            Value[11],
            v20,
            32i64);
        }
        v22 = mapping->m_right;
        mapping->m_left = 0i64;
        if ( v22 )
        {
          hkpCompressedMeshShapeBuilder::MappingTree::~MappingTree(v22);
          v23 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          (*(void (__fastcall **)(_QWORD *, hkpCompressedMeshShapeBuilder::MappingTree *, __int64))(*v23[11] + 16i64))(
            v23[11],
            v22,
            32i64);
        }
        mapping->m_right = 0i64;
      }
    }
  }
  else
  {
    if ( !out2_40.m_offset.m_quad.m128_i32[0] )
      goto LABEL_27;
    hkpCompressedMeshShapeBuilder::appendGeometry(this, &this->m_leftOver, (hkGeometry *)&out2);
    if ( mapping )
    {
      m_left = mapping->m_right;
      goto LABEL_26;
    }
  }
LABEL_33:
  out2_40.m_offset.m_quad.m128_i32[0] = 0;
  if ( out2_40.m_offset.m_quad.m128_i32[1] >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      out2_32,
      16 * out2_40.m_offset.m_quad.m128_i32[1]);
  out2_32 = 0i64;
  out2_40.m_offset.m_quad.m128_i32[1] = 0x80000000;
  out2_24 = 0;
  if ( out2_28 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, out2_16, 16 * out2_28);
  out2_16 = 0i64;
  out2_28 = 0x80000000;
  out2 = &hkBaseObject::`vftable;
  out2_40.m_indices.m_size = 0;
  if ( out2_40.m_indices.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      out2_40.m_indices.m_data,
      16 * out2_40.m_indices.m_capacityAndFlags);
  out2_40.m_indices.m_data = 0i64;
  out2_40.m_indices.m_capacityAndFlags = 0x80000000;
  out2_40.m_vertices.m_size = 0;
  if ( out2_40.m_vertices.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      out2_40.m_vertices.m_data,
      16 * out2_40.m_vertices.m_capacityAndFlags);
}

// File Line: 475
// RVA: 0x1324640
void __fastcall hkpCompressedMeshShapeBuilder::snapToGrid(hkVector4f *v, float error)
{
  __m128 v2; // xmm4
  __m128 v3; // xmm1
  __m128 v4; // xmm3
  __m128 v5; // xmm0
  __m128 v6; // xmm2

  v2 = _mm_shuffle_ps((__m128)LODWORD(error), (__m128)LODWORD(error), 0);
  v3 = _mm_rcp_ps(v2);
  v4 = _mm_mul_ps(v->m_quad, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v3, v2)), v3));
  *v = (hkVector4f)v4;
  v5 = _mm_add_ps(v4, (__m128)xmmword_141A711B0);
  v6 = _mm_mul_ps(
         _mm_cvtepi32_ps(
           _mm_xor_si128(
             (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v5),
             _mm_cvttps_epi32(v5))),
         v2);
  v->m_quad = _mm_shuffle_ps(v6, _mm_unpackhi_ps(v6, v4), 196);
}

// File Line: 524
// RVA: 0x1325EB0
void __fastcall hkpCompressedMeshShapeBuilder::addMaterial(
        hkpCompressedMeshShapeBuilder *this,
        hkpCompressedMeshShape::Chunk *chunk,
        unsigned int material)
{
  hkpCompressedMeshShape *m_mesh; // rbx
  char m_storage; // al

  m_mesh = this->m_mesh;
  m_storage = m_mesh->m_materialType.m_storage;
  switch ( m_storage )
  {
    case 4:
      if ( m_mesh->m_materials.m_size == (m_mesh->m_materials.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_mesh->m_materials.m_data, 4);
      m_mesh->m_materials.m_data[m_mesh->m_materials.m_size++] = material;
      break;
    case 3:
      if ( m_mesh->m_materials16.m_size == (m_mesh->m_materials16.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_mesh->m_materials16.m_data, 2);
      m_mesh->m_materials16.m_data[m_mesh->m_materials16.m_size++] = material;
      break;
    case 2:
      if ( m_mesh->m_materials8.m_size == (m_mesh->m_materials8.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_mesh->m_materials8.m_data, 1);
      m_mesh->m_materials8.m_data[m_mesh->m_materials8.m_size++] = material;
      break;
    default:
      if ( chunk->m_materialInfo == -1 && m_storage == 1 )
        chunk->m_materialInfo = material;
      break;
  }
}

// File Line: 546
// RVA: 0x1324760
void __fastcall hkpCompressedMeshShapeBuilder::quantizeVertices(
        float quantization,
        hkVector4f *offset,
        hkArray<hkVector4f,hkContainerHeapAllocator> *verticesIn,
        hkArray<unsigned short,hkContainerHeapAllocator> *verticesOut)
{
  __int64 m_size; // rsi
  int v5; // edi
  int v6; // eax
  int v10; // eax
  int v11; // r9d
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r9
  __m128 v15; // xmm2
  __int64 v16; // rdx
  float v17; // xmm0_4
  __m128 v18; // [rsp+30h] [rbp-28h]
  hkResult result; // [rsp+70h] [rbp+18h] BYREF

  m_size = verticesIn->m_size;
  v5 = 3 * m_size;
  v6 = verticesOut->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v6 < 3 * (int)m_size )
  {
    v10 = 2 * v6;
    v11 = 3 * m_size;
    if ( v5 < v10 )
      v11 = v10;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&verticesOut->m_data, v11, 2);
  }
  verticesOut->m_size = v5;
  v12 = m_size;
  if ( (int)m_size > 0 )
  {
    v13 = 0i64;
    v14 = 0i64;
    v15 = _mm_shuffle_ps(
            (__m128)COERCE_UNSIGNED_INT(1.0 / quantization),
            (__m128)COERCE_UNSIGNED_INT(1.0 / quantization),
            0);
    do
    {
      v16 = 0i64;
      v18 = _mm_mul_ps(_mm_sub_ps(verticesIn->m_data[v14].m_quad, offset->m_quad), v15);
      do
      {
        v17 = v18.m128_f32[v16++];
        verticesOut->m_data[v13++] = (int)(float)(v17 + 0.5);
      }
      while ( v16 < 3 );
      ++v14;
      --v12;
    }
    while ( v12 );
  }
}

// File Line: 566
// RVA: 0x1324DB0
void __fastcall hkpCompressedMeshShapeBuilder::createChunk(
        hkpCompressedMeshShapeBuilder *this,
        hkGeometry *geometry,
        hkVector4f *offset,
        hkpCompressedMeshShape::Chunk *chunk,
        hkpCompressedMeshShapeBuilder::MappingTree *mapping)
{
  hkpCompressedMeshShape *m_mesh; // rax
  char m_storage; // r10
  __int64 v8; // r15
  __int64 v9; // r12
  int m_size; // ecx
  int v11; // edx
  int v12; // ebx
  __int64 v13; // r8
  int v14; // eax
  __int64 v15; // rdx
  char *v16; // rax
  int v17; // r11d
  __int64 v18; // r9
  __int64 v19; // r10
  char *v20; // rdx
  __int64 v21; // rcx
  __int64 v22; // r8
  _DWORD *v23; // rcx
  int v24; // edi
  int v25; // eax
  int v26; // eax
  int v27; // r9d
  _DWORD *v28; // rcx
  int *v29; // rdx
  __int64 v30; // r8
  int v31; // eax
  char *v32; // rdx
  __int64 v33; // rcx
  signed __int64 v34; // r8
  int v35; // eax
  int v36; // ecx
  hkpCompressedMeshShape::Chunk *v37; // r11
  hkGeometry *v38; // rdi
  int v39; // ebx
  int v40; // eax
  int v41; // eax
  __int64 v42; // rdx
  int v43; // r10d
  int v44; // r9d
  int v45; // esi
  char *v46; // rbx
  __int64 v47; // r8
  int v48; // r13d
  hkBaseObjectVtbl *vfptr; // rax
  int v50; // edi
  hkArray<unsigned short,hkContainerHeapAllocator> *p_m_indices; // rbx
  __int64 v52; // r14
  unsigned __int16 v53; // si
  __int64 v54; // rdx
  __int64 v55; // rax
  __int64 v56; // rcx
  int v57; // r8d
  int v58; // ebx
  __int64 v59; // rax
  hkpCompressedMeshShape::Chunk *v60; // r9
  __int64 v61; // r15
  __int64 v62; // rsi
  __int64 v63; // r14
  __int16 v64; // r13
  __int64 v65; // rcx
  int v66; // r8d
  int v67; // r9d
  __int64 v68; // rdi
  int *v69; // rbx
  int v70; // r8d
  hkArray<hkArray<int,hkContainerHeapAllocator>,hkContainerHeapAllocator> strips; // [rsp+30h] [rbp-C0h] BYREF
  char *array; // [rsp+40h] [rbp-B0h] BYREF
  int v73; // [rsp+48h] [rbp-A8h]
  int v74; // [rsp+4Ch] [rbp-A4h]
  hkArray<int,hkContainerHeapAllocator> map; // [rsp+50h] [rbp-A0h] BYREF
  int v76; // [rsp+60h] [rbp-90h]
  hkArray<int,hkContainerHeapAllocator> leftOvers; // [rsp+68h] [rbp-88h] BYREF
  hkgpIndexedMesh::StripConfig config; // [rsp+78h] [rbp-78h] BYREF
  hkgpIndexedMesh v79; // [rsp+90h] [rbp-60h] BYREF
  hkpCompressedMeshShapeBuilder *vars0; // [rsp+170h] [rbp+80h]
  _QWORD *retaddr; // [rsp+178h] [rbp+88h]
  int v82; // [rsp+180h] [rbp+90h]
  __int64 result; // [rsp+190h] [rbp+A0h] BYREF
  hkpCompressedMeshShape::Chunk *v85; // [rsp+198h] [rbp+A8h]

  v85 = chunk;
  chunk->m_offset = (hkVector4f)offset->m_quad;
  m_mesh = this->m_mesh;
  m_storage = m_mesh->m_materialType.m_storage;
  switch ( m_storage )
  {
    case 2:
      chunk->m_materialInfo = m_mesh->m_materials8.m_size;
      break;
    case 3:
      chunk->m_materialInfo = m_mesh->m_materials16.m_size;
      break;
    case 4:
      chunk->m_materialInfo = m_mesh->m_materials.m_size;
      break;
    default:
      chunk->m_materialInfo = -1;
      break;
  }
  hkpCompressedMeshShapeBuilder::quantizeVertices(this->m_error, offset, &geometry->m_vertices, &chunk->m_vertices);
  hkgpIndexedMesh::hkgpIndexedMesh(&v79);
  hkgpIndexedMesh::appendFromGeometry(&v79, geometry);
  v8 = 0i64;
  strips.m_data = 0i64;
  strips.m_size = 0;
  strips.m_capacityAndFlags = 0x80000000;
  leftOvers.m_data = 0i64;
  leftOvers.m_size = 0;
  leftOvers.m_capacityAndFlags = 0x80000000;
  map.m_data = 0i64;
  map.m_size = 0;
  map.m_capacityAndFlags = 0x80000000;
  config.m_minLength = 4;
  *(_QWORD *)&config.m_maxLength = 0xFFFFi64;
  hkgpIndexedMesh::generateStrips(&v79, &strips, &leftOvers, &map, &config);
  v9 = result;
  if ( result )
  {
    m_size = map.m_size;
    v11 = 0;
    array = 0i64;
    v73 = 0;
    v74 = 0x80000000;
    v12 = map.m_size;
    if ( map.m_size > 0 )
    {
      hkArrayUtil::_reserve(
        (hkResult *)&result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&array,
        map.m_size,
        20);
      m_size = map.m_size;
      v11 = v73;
    }
    v13 = 5i64 * v11;
    v14 = v12 - v11;
    v15 = v12 - v11;
    if ( v14 > 0 )
    {
      v16 = &array[4 * v13 + 8];
      do
      {
        if ( v16 != (char *)8 )
        {
          *((_DWORD *)v16 - 2) = -1;
          *(_QWORD *)(v16 - 4) = -1i64;
          *(_QWORD *)(v16 + 4) = -1i64;
        }
        v16 += 20;
        --v15;
      }
      while ( v15 );
      m_size = map.m_size;
    }
    v73 = v12;
    v17 = 0;
    if ( m_size > 0 )
    {
      v18 = 0i64;
      v19 = 0i64;
      do
      {
        v20 = array;
        ++v17;
        v21 = map.m_data[v19++];
        v18 += 20i64;
        v22 = 5 * v21;
        v23 = *(_DWORD **)v9;
        *(_DWORD *)&array[v18 - 20] = *(_DWORD *)(*(_QWORD *)v9 + 4 * v22);
        *(_DWORD *)&v20[v18 - 16] = v23[v22 + 1];
        *(_DWORD *)&v20[v18 - 12] = v23[v22 + 2];
        *(_DWORD *)&v20[v18 - 8] = v23[v22 + 3];
        *(_DWORD *)&v20[v18 - 4] = v23[v22 + 4];
      }
      while ( v17 < map.m_size );
      v12 = v73;
    }
    v24 = v12;
    if ( v12 > *(_DWORD *)(v9 + 8) )
      v24 = *(_DWORD *)(v9 + 8);
    v25 = *(_DWORD *)(v9 + 12) & 0x3FFFFFFF;
    if ( v25 < v12 )
    {
      v26 = 2 * v25;
      v27 = v12;
      if ( v12 < v26 )
        v27 = v26;
      hkArrayUtil::_reserve((hkResult *)&result, &hkContainerHeapAllocator::s_alloc, (const void **)v9, v27, 20);
    }
    v28 = *(_DWORD **)v9;
    if ( v24 > 0 )
    {
      v29 = (int *)array;
      v30 = v24;
      do
      {
        v31 = *v29;
        v28 += 5;
        v29 += 5;
        *(v28 - 5) = v31;
        *(v28 - 4) = *(v29 - 4);
        *(v28 - 3) = *(v29 - 3);
        *(v28 - 2) = *(v29 - 2);
        *(v28 - 1) = *(v29 - 1);
        --v30;
      }
      while ( v30 );
    }
    v32 = (char *)(*(_QWORD *)v9 + 20i64 * v24);
    v33 = v12 - v24;
    if ( v12 - v24 > 0 )
    {
      v34 = &array[20 * v24] - v32;
      do
      {
        if ( v32 )
        {
          *(_DWORD *)v32 = *(_DWORD *)&v32[v34];
          *((_DWORD *)v32 + 1) = *(_DWORD *)&v32[v34 + 4];
          *((_DWORD *)v32 + 2) = *(_DWORD *)&v32[v34 + 8];
          *((_DWORD *)v32 + 3) = *(_DWORD *)&v32[v34 + 12];
          *((_DWORD *)v32 + 4) = *(_DWORD *)&v32[v34 + 16];
        }
        v32 += 20;
        --v33;
      }
      while ( v33 );
    }
    v35 = v74;
    *(_DWORD *)(v9 + 8) = v12;
    v73 = 0;
    if ( v35 >= 0 )
      ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, char *, _QWORD, _QWORD))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerHeapAllocator::s_alloc,
        array,
        20 * (v35 & 0x3FFFFFFFu),
        v24);
  }
  v36 = strips.m_size;
  v37 = (hkpCompressedMeshShape::Chunk *)geometry;
  v38 = geometry + 1;
  v39 = strips.m_size;
  v40 = *(_DWORD *)(&geometry[1].m_referenceCount + 1) & 0x3FFFFFFF;
  if ( v40 < strips.m_size )
  {
    v41 = 2 * v40;
    if ( strips.m_size < v41 )
      v36 = v41;
    hkArrayUtil::_reserve(
      (hkResult *)&result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&geometry[1].vfptr,
      v36,
      2);
    v36 = strips.m_size;
    v37 = (hkpCompressedMeshShape::Chunk *)geometry;
  }
  v42 = 0i64;
  *(_DWORD *)&geometry[1].m_memSizeAndFlags = v39;
  v43 = 0;
  LODWORD(result) = 0;
  *(_QWORD *)&config.m_minLength = 0i64;
  v44 = 0;
  v82 = 0;
  v45 = 0;
  v76 = 0;
  if ( v36 > 0 )
  {
    v46 = 0i64;
    v47 = 0i64;
    *(_QWORD *)&leftOvers.m_size = 0i64;
    array = 0i64;
    do
    {
      v48 = *(int *)((char *)&strips.m_data->m_size + v47);
      vfptr = v38->vfptr;
      v50 = 0;
      *(_WORD *)((char *)&vfptr->__vecDelDtor + (_QWORD)v46) = v48;
      if ( v48 > 0 )
      {
        p_m_indices = &v37->m_indices;
        v52 = 20 * v42;
        do
        {
          v53 = (*(int **)((char *)&strips.m_data->m_data + v47))[v8];
          if ( p_m_indices->m_size == (p_m_indices->m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_indices->m_data, 2);
            v42 = *(_QWORD *)&config.m_minLength;
            v44 = v82;
            v43 = result;
            v37 = (hkpCompressedMeshShape::Chunk *)geometry;
          }
          p_m_indices->m_data[p_m_indices->m_size++] = v53;
          if ( v50 >= v48 - 2 )
          {
            v57 = -1;
          }
          else
          {
            if ( v9 )
            {
              *(_DWORD *)(v52 + *(_QWORD *)v9 + 4) = v50 + v43;
              *(_DWORD *)(v52 + *(_QWORD *)v9 + 12) = v50 & 1;
            }
            v54 = v42 + 1;
            v82 = v44 + 1;
            v55 = retaddr[4];
            v56 = 2i64 * map.m_data[v54 - 1];
            *(_QWORD *)&config.m_minLength = v54;
            v57 = *(_DWORD *)(v55 + 8 * v56 + 12);
            v52 += 20i64;
          }
          hkpCompressedMeshShapeBuilder::addMaterial(vars0, v37, v57);
          v42 = *(_QWORD *)&config.m_minLength;
          v47 = *(_QWORD *)&leftOvers.m_size;
          v44 = v82;
          v43 = result;
          v37 = (hkpCompressedMeshShape::Chunk *)geometry;
          ++v50;
          ++v8;
        }
        while ( v50 < v48 );
        v46 = array;
        v45 = v76;
        v8 = 0i64;
      }
      v36 = strips.m_size;
      v37 = (hkpCompressedMeshShape::Chunk *)geometry;
      ++v45;
      v43 += v48;
      v46 += 2;
      v47 += 16i64;
      v38 = geometry + 1;
      v76 = v45;
      LODWORD(result) = v43;
      array = v46;
      *(_QWORD *)&leftOvers.m_size = v47;
    }
    while ( v45 < strips.m_size );
  }
  v58 = 0;
  v59 = v44;
  if ( leftOvers.m_size > 0 )
  {
    v60 = (hkpCompressedMeshShape::Chunk *)geometry;
    v61 = v59;
    v62 = 20 * v59;
    v63 = 0i64;
    do
    {
      v64 = leftOvers.m_data[v63];
      if ( geometry->m_triangles.m_size == (geometry->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&geometry->m_triangles.m_data, 2);
        v43 = result;
        v60 = (hkpCompressedMeshShape::Chunk *)geometry;
      }
      *((_WORD *)&geometry->m_triangles.m_data->m_a + geometry->m_triangles.m_size++) = v64;
      if ( v58 == 3 * (v58 / 3) )
      {
        if ( v9 )
          *(_DWORD *)(*(_QWORD *)v9 + v62 + 4) = v58 + v43;
        v62 += 20i64;
        v65 = 2i64 * map.m_data[v61++];
        v66 = *(_DWORD *)(retaddr[4] + 8 * v65 + 12);
      }
      else
      {
        v66 = -1;
      }
      hkpCompressedMeshShapeBuilder::addMaterial(vars0, v60, v66);
      v43 = result;
      v60 = (hkpCompressedMeshShape::Chunk *)geometry;
      ++v58;
      ++v63;
    }
    while ( v58 < leftOvers.m_size );
    v36 = strips.m_size;
  }
  v67 = geometry->m_triangles.m_size;
  if ( v67 < (geometry->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reduce(&hkContainerHeapAllocator::s_alloc, (const void **)&geometry->m_triangles.m_data, 2, 0i64, v67);
    v36 = strips.m_size;
  }
  map.m_size = 0;
  if ( map.m_capacityAndFlags >= 0 )
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      map.m_data,
      4 * map.m_capacityAndFlags);
    v36 = strips.m_size;
  }
  map.m_data = 0i64;
  map.m_capacityAndFlags = 0x80000000;
  leftOvers.m_size = 0;
  if ( leftOvers.m_capacityAndFlags >= 0 )
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      leftOvers.m_data,
      4 * leftOvers.m_capacityAndFlags);
    v36 = strips.m_size;
  }
  leftOvers.m_data = 0i64;
  leftOvers.m_capacityAndFlags = 0x80000000;
  v68 = v36 - 1;
  if ( v36 - 1 >= 0 )
  {
    v69 = &strips.m_data->m_capacityAndFlags + 4 * v36 - 4;
    do
    {
      v70 = *v69;
      *(v69 - 1) = 0;
      if ( v70 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v69 - 3),
          4 * v70);
      *(_QWORD *)(v69 - 3) = 0i64;
      *v69 = 0x80000000;
      v69 -= 4;
      --v68;
    }
    while ( v68 >= 0 );
  }
  strips.m_size = 0;
  if ( strips.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      strips.m_data,
      16 * strips.m_capacityAndFlags);
  strips.m_data = 0i64;
  strips.m_capacityAndFlags = 0x80000000;
  hkgpIndexedMesh::~hkgpIndexedMesh(&v79);
}

// File Line: 678
// RVA: 0x13255B0
__int64 __fastcall hkpCompressedMeshShapeBuilder::splitCriterion(
        hkpCompressedMeshShapeBuilder *this,
        hkVector4f *v1,
        hkVector4f *v2,
        hkVector4f *v3,
        float half,
        int dir)
{
  float v6; // xmm1_4
  float v7; // xmm3_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm3_4

  v6 = v1->m_quad.m128_f32[dir];
  v7 = v2->m_quad.m128_f32[dir];
  v8 = v6;
  if ( v7 < v6 )
    v8 = v2->m_quad.m128_f32[dir];
  v9 = v3->m_quad.m128_f32[dir];
  if ( v9 < v8 )
    v8 = v3->m_quad.m128_f32[dir];
  if ( v7 > v6 )
    v6 = v2->m_quad.m128_f32[dir];
  if ( v9 > v6 )
    v6 = v3->m_quad.m128_f32[dir];
  if ( v8 < half && v6 > half )
  {
    v10 = v6 - v8;
    if ( (float)(v6 - v8) > (float)((float)(this->m_error * 65535.0) * this->m_overlapRatio) )
      return 0xFFFFFFFFi64;
    if ( v10 > this->m_statistics.m_maxOverlap )
      this->m_statistics.m_maxOverlap = v10;
  }
  return half > (float)((float)(v6 + v8) * 0.5);
}

// File Line: 711
// RVA: 0x1325FF0
void __fastcall addTriangle(
        int a,
        int b,
        int c,
        int material,
        hkVector4f *vertexA,
        hkVector4f *vertexB,
        hkVector4f *vertexC,
        hkGeometry *geom,
        hkArray<int,hkContainerHeapAllocator> *vertexIndex)
{
  __int64 v9; // r12
  __int64 v11; // rbp
  __int64 v12; // rsi
  __int64 v13; // r15
  __int64 v14; // rsi
  int v15; // ebp
  int v16; // r14d
  int v17; // esi
  hkGeometry::Triangle *v18; // rax

  v9 = a;
  v11 = c;
  v12 = b;
  if ( vertexIndex->m_data[v9] == -1 )
  {
    vertexIndex->m_data[a] = geom->m_vertices.m_size;
    if ( geom->m_vertices.m_size == (geom->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&geom->m_vertices.m_data, 16);
    geom->m_vertices.m_data[geom->m_vertices.m_size++] = (hkVector4f)vertexA->m_quad;
  }
  v13 = v12;
  if ( vertexIndex->m_data[v12] == -1 )
  {
    vertexIndex->m_data[v12] = geom->m_vertices.m_size;
    if ( geom->m_vertices.m_size == (geom->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&geom->m_vertices.m_data, 16);
    geom->m_vertices.m_data[geom->m_vertices.m_size++] = (hkVector4f)vertexB->m_quad;
  }
  v14 = v11;
  if ( vertexIndex->m_data[v11] == -1 )
  {
    vertexIndex->m_data[v11] = geom->m_vertices.m_size;
    if ( geom->m_vertices.m_size == (geom->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&geom->m_vertices.m_data, 16);
    geom->m_vertices.m_data[geom->m_vertices.m_size++] = (hkVector4f)vertexC->m_quad;
  }
  v15 = vertexIndex->m_data[v9];
  v16 = vertexIndex->m_data[v13];
  v17 = vertexIndex->m_data[v14];
  if ( geom->m_triangles.m_size == (geom->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&geom->m_triangles.m_data, 16);
  v18 = &geom->m_triangles.m_data[geom->m_triangles.m_size];
  v18->m_a = v15;
  v18->m_b = v16;
  v18->m_c = v17;
  v18->m_material = material;
  ++geom->m_triangles.m_size;
}

// File Line: 739
// RVA: 0x1323A80
void __fastcall hkpCompressedMeshShapeBuilder::splitGeometry(
        hkpCompressedMeshShapeBuilder *this,
        hkpCompressedMeshShapeBuilder *source,
        hkGeometry *out1,
        hkGeometry *out2)
{
  __m128 v8; // xmm3
  __int64 dir; // rdx
  __int64 *half; // [rsp+28h] [rbp-50h]
  float v11[4]; // [rsp+40h] [rbp-38h]
  hkAabb aabbOut; // [rsp+50h] [rbp-28h] BYREF

  hkAabbUtil::calcAabb(*(hkVector4f **)&source->m_TjunctionTolerance, (int)source->m_leftOver.vfptr, &aabbOut);
  v8 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(aabbOut.m_max.m_quad, aabbOut.m_min.m_quad), 1u), 1u);
  *(__m128 *)v11 = _mm_mul_ps(_mm_add_ps(aabbOut.m_max.m_quad, aabbOut.m_min.m_quad), (__m128)xmmword_141A711B0);
  dir = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                               _mm_and_ps(
                                                                 _mm_cmple_ps(
                                                                   _mm_max_ps(
                                                                     _mm_shuffle_ps(v8, v8, 170),
                                                                     _mm_max_ps(
                                                                       _mm_shuffle_ps(v8, v8, 85),
                                                                       _mm_shuffle_ps(v8, v8, 0))),
                                                                   v8),
                                                                 (__m128)xmmword_141C20A50))];
  *(float *)&half = v11[dir];
  hkpCompressedMeshShapeBuilder::splitGeometry(this, source, out1, out2, dir, half, 0i64);
}

// File Line: 759
// RVA: 0x13235E0
void __fastcall hkpCompressedMeshShapeBuilder::splitGeometry(
        hkpCompressedMeshShapeBuilder *this,
        hkpCompressedMeshShapeBuilder *source,
        hkGeometry *out1,
        hkGeometry *out2,
        int dir,
        __int64 *half,
        hkpCompressedMeshShapeBuilder::MappingTree *mapping)
{
  __int64 vfptr_low; // rbx
  hkpCompressedMeshShapeBuilder *v8; // r14
  int v9; // r9d
  __int64 v10; // rcx
  __int64 v12; // rdi
  __int64 v13; // rbx
  _QWORD **Value; // rax
  __int64 v15; // rax
  _QWORD **v16; // rax
  __int64 v17; // rax
  __int64 v18; // rsi
  __int64 v19; // r9
  __int64 v20; // rax
  __int64 v21; // rcx
  __int64 v22; // rdx
  __int64 v23; // r8
  __int64 v24; // rax
  hkVector4f *v25; // r14
  hkVector4f *v26; // r12
  hkVector4f *vertexC; // r13
  int v28; // eax
  hkpCompressedMeshShapeBuilder::TriangleMapping *map; // rax
  __int64 v30; // r14
  _DWORD *v31; // rdx
  __int64 v32; // r14
  _DWORD *v33; // rdx
  int v34; // [rsp+48h] [rbp-51h]
  int c; // [rsp+4Ch] [rbp-4Dh]
  int b; // [rsp+50h] [rbp-49h]
  hkResult result; // [rsp+54h] [rbp-45h] BYREF
  __int64 v38; // [rsp+58h] [rbp-41h]
  hkArray<int,hkContainerHeapAllocator> vertexIndex; // [rsp+60h] [rbp-39h] BYREF
  hkArray<int,hkContainerHeapAllocator> array[2]; // [rsp+70h] [rbp-29h] BYREF
  hkpCompressedMeshShapeBuilder *retaddr; // [rsp+E8h] [rbp+4Fh]
  int v45; // [rsp+108h] [rbp+6Fh]
  int halfa; // [rsp+118h] [rbp+7Fh]

  v45 = (int)out2;
  vfptr_low = SLODWORD(source->m_leftOver.vfptr);
  v8 = source;
  array[0].m_capacityAndFlags = 0x80000000;
  array[0].m_data = 0i64;
  array[0].m_size = 0;
  vertexIndex.m_data = 0i64;
  vertexIndex.m_size = 0;
  vertexIndex.m_capacityAndFlags = 0x80000000;
  if ( (int)vfptr_low > 0 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array[0].m_data, vfptr_low, 4);
  array[0].m_size = vfptr_low;
  if ( (vertexIndex.m_capacityAndFlags & 0x3FFFFFFF) < (int)vfptr_low )
  {
    v9 = vfptr_low;
    if ( (int)vfptr_low < 2 * (vertexIndex.m_capacityAndFlags & 0x3FFFFFFF) )
      v9 = 2 * (vertexIndex.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&vertexIndex.m_data, v9, 4);
  }
  vertexIndex.m_size = vfptr_low;
  v10 = 0i64;
  if ( (int)vfptr_low > 0 )
  {
    do
    {
      array[0].m_data[v10++] = -1;
      vertexIndex.m_data[v10 - 1] = -1;
    }
    while ( v10 < vfptr_low );
  }
  v12 = 0i64;
  v13 = 0i64;
  if ( half )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v15 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
    v12 = v15;
    if ( v15 )
    {
      *(_QWORD *)v15 = 0i64;
      *(_DWORD *)(v15 + 8) = 0;
      *(_DWORD *)(v15 + 12) = 0x80000000;
      *(_QWORD *)(v15 + 16) = 0i64;
      *(_QWORD *)(v15 + 24) = 0i64;
    }
    else
    {
      v12 = 0i64;
    }
    v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v17 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v16[11] + 8i64))(v16[11], 32i64);
    v13 = v17;
    if ( v17 )
    {
      *(_QWORD *)v17 = 0i64;
      *(_DWORD *)(v17 + 8) = 0;
      *(_DWORD *)(v17 + 12) = 0x80000000;
      *(_QWORD *)(v17 + 16) = 0i64;
      *(_QWORD *)(v17 + 24) = 0i64;
    }
    else
    {
      v13 = 0i64;
    }
    half[2] = v12;
    half[3] = v13;
  }
  v34 = 0;
  if ( SLODWORD(v8->m_leftOver.m_vertices.m_data) > 0 )
  {
    v18 = 0i64;
    v19 = 0i64;
    v38 = 0i64;
    do
    {
      v20 = *(_QWORD *)&v8->m_leftOver.m_memSizeAndFlags;
      v21 = *(int *)(v19 + v20);
      v22 = *(int *)(v19 + v20 + 4);
      v23 = *(int *)(v19 + v20 + 8);
      halfa = *(_DWORD *)(v19 + v20 + 12);
      v24 = *(_QWORD *)&v8->m_TjunctionTolerance;
      result.m_enum = (int)v21;
      b = v22;
      c = v23;
      v25 = (hkVector4f *)(v24 + 16 * v21);
      v26 = (hkVector4f *)(v24 + 16 * v22);
      vertexC = (hkVector4f *)(v24 + 16 * v23);
      v28 = hkpCompressedMeshShapeBuilder::splitCriterion(retaddr, v25, v26, vertexC, *(float *)&dir, v45);
      switch ( v28 )
      {
        case -1:
          map = 0i64;
          if ( half )
            map = (hkpCompressedMeshShapeBuilder::TriangleMapping *)(*half + 20i64 * v34);
          hkpCompressedMeshShapeBuilder::addLeftOverTriangle(retaddr, v25, v26, vertexC, halfa, map);
          break;
        case 1:
          addTriangle(result.m_enum, b, c, halfa, v25, v26, vertexC, (hkGeometry *)source, array);
          if ( v12 )
          {
            v30 = *half;
            if ( *(_DWORD *)(v12 + 8) == (*(_DWORD *)(v12 + 12) & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)v12, 20);
            v31 = (_DWORD *)(*(_QWORD *)v12 + 20i64 * *(int *)(v12 + 8));
            if ( v31 )
            {
              *v31 = *(_DWORD *)(v18 + v30);
              v31[1] = *(_DWORD *)(v18 + v30 + 4);
              v31[2] = *(_DWORD *)(v18 + v30 + 8);
              v31[3] = *(_DWORD *)(v18 + v30 + 12);
              v31[4] = *(_DWORD *)(v18 + v30 + 16);
            }
            ++*(_DWORD *)(v12 + 8);
          }
          break;
        case 0:
          addTriangle(result.m_enum, b, c, halfa, v25, v26, vertexC, out1, &vertexIndex);
          if ( v13 )
          {
            v32 = *half;
            if ( *(_DWORD *)(v13 + 8) == (*(_DWORD *)(v13 + 12) & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)v13, 20);
            v33 = (_DWORD *)(*(_QWORD *)v13 + 20i64 * *(int *)(v13 + 8));
            if ( v33 )
            {
              *v33 = *(_DWORD *)(v18 + v32);
              v33[1] = *(_DWORD *)(v18 + v32 + 4);
              v33[2] = *(_DWORD *)(v18 + v32 + 8);
              v33[3] = *(_DWORD *)(v18 + v32 + 12);
              v33[4] = *(_DWORD *)(v18 + v32 + 16);
            }
            ++*(_DWORD *)(v13 + 8);
          }
          break;
      }
      v8 = this;
      v19 = v38 + 16;
      v18 += 20i64;
      ++v34;
      v38 += 16i64;
    }
    while ( v34 < SLODWORD(this->m_leftOver.m_vertices.m_data) );
  }
  if ( half )
    *((_DWORD *)half + 2) = 0;
  vertexIndex.m_size = 0;
  if ( vertexIndex.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      vertexIndex.m_data,
      4 * vertexIndex.m_capacityAndFlags);
  vertexIndex.m_data = 0i64;
  array[0].m_size = 0;
  vertexIndex.m_capacityAndFlags = 0x80000000;
  if ( array[0].m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array[0].m_data,
      4 * array[0].m_capacityAndFlags);
}

// File Line: 834
// RVA: 0x13261A0
__int64 __fastcall addVertex(hkGeometry *geometry, hkVector4f *vertex)
{
  __int64 m_size; // r11
  unsigned int v3; // r10d
  __int64 v6; // r8
  hkVector4f *m_data; // r9

  m_size = geometry->m_vertices.m_size;
  v3 = 0;
  v6 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_5:
    if ( geometry->m_vertices.m_size == (geometry->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&geometry->m_vertices.m_data, 16);
    geometry->m_vertices.m_data[geometry->m_vertices.m_size++] = (hkVector4f)vertex->m_quad;
    return (unsigned int)(geometry->m_vertices.m_size - 1);
  }
  else
  {
    m_data = geometry->m_vertices.m_data;
    while ( _mm_movemask_ps(_mm_cmpeq_ps(m_data->m_quad, vertex->m_quad)) != 15 )
    {
      ++v6;
      ++v3;
      ++m_data;
      if ( v6 >= m_size )
        goto LABEL_5;
    }
    return v3;
  }
}

// File Line: 851
// RVA: 0x1325D90
void __fastcall hkpCompressedMeshShapeBuilder::addLeftOverTriangle(
        hkpCompressedMeshShapeBuilder *this,
        hkVector4f *v0,
        hkVector4f *v1,
        hkVector4f *v2,
        int material,
        hkpCompressedMeshShapeBuilder::TriangleMapping *map)
{
  int v9; // r14d
  int v10; // r15d
  int v11; // edi
  hkGeometry::Triangle *v12; // rax
  hkpCompressedMeshShapeBuilder::TriangleMapping *v13; // rdx

  v9 = addVertex(&this->m_leftOver, v0);
  v10 = addVertex(&this->m_leftOver, v1);
  v11 = addVertex(&this->m_leftOver, v2);
  if ( this->m_leftOver.m_triangles.m_size == (this->m_leftOver.m_triangles.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_leftOver.m_triangles.m_data,
      16);
  v12 = &this->m_leftOver.m_triangles.m_data[this->m_leftOver.m_triangles.m_size];
  v12->m_a = v9;
  v12->m_b = v10;
  v12->m_c = v11;
  v12->m_material = material;
  ++this->m_leftOver.m_triangles.m_size;
  if ( map )
  {
    if ( this->m_bigMapping.m_size == (this->m_bigMapping.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_bigMapping.m_data, 20);
    v13 = &this->m_bigMapping.m_data[this->m_bigMapping.m_size];
    if ( v13 )
      *v13 = *map;
    ++this->m_bigMapping.m_size;
  }
}

// File Line: 868
// RVA: 0x1323F50
void __fastcall hkpCompressedMeshShapeBuilder::chunkToGeometry(
        hkpCompressedMeshShape *compressedMesh,
        int id,
        hkGeometry *geometry)
{
  hkpCompressedMeshShape::Chunk *m_data; // r9
  hkpCompressedMeshShape *v5; // r8
  __int64 v6; // rdi
  unsigned __int16 m_transformIndex; // ax
  unsigned __int16 m_reference; // ax
  int v9; // ebx
  hkpCompressedMeshShape::Chunk *v10; // r13
  int v11; // edi
  int v12; // eax
  __int64 v13; // rax
  _DWORD *v14; // r15
  unsigned int v15; // ecx
  __int64 v16; // rcx
  _DWORD *v17; // rdi
  hkVector4f *v18; // rbp
  hkVector4f *v19; // rbx
  __int64 v20; // r14
  __int64 v21; // rsi
  __int64 v22; // rcx
  unsigned __int16 *v23; // rdi
  __int64 v24; // rdx
  int v25; // esi
  int v26; // ebx
  int v27; // edi
  hkGeometry::Triangle *v28; // rax
  int NextIndex; // eax
  int v30; // [rsp+34h] [rbp-B4h]
  int index; // [rsp+38h] [rbp-B0h]
  __int64 v32; // [rsp+40h] [rbp-A8h]
  hkQsTransformf a; // [rsp+50h] [rbp-98h] BYREF
  hkVector4f v1; // [rsp+80h] [rbp-68h] BYREF
  hkVector4f v2; // [rsp+90h] [rbp-58h] BYREF
  hkVector4f v3; // [rsp+A0h] [rbp-48h] BYREF
  int v38; // [rsp+F8h] [rbp+10h] BYREF
  int winding; // [rsp+108h] [rbp+20h] BYREF

  m_data = compressedMesh->m_chunks.m_data;
  a.m_translation = 0i64;
  v5 = compressedMesh;
  v6 = id;
  a.m_scale = (hkVector4f)query.m_quad;
  a.m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
  m_transformIndex = m_data[v6].m_transformIndex;
  if ( m_transformIndex != 0xFFFF )
    a = compressedMesh->m_transforms.m_data[m_transformIndex];
  m_reference = m_data[v6].m_reference;
  if ( m_reference != 0xFFFF )
    id = m_reference;
  v9 = 0;
  index = 0;
  v10 = &m_data[id];
  v11 = v10->m_vertices.m_size / 3;
  v12 = v11;
  if ( v11 )
  {
    v38 = 4 * v11;
    v13 = ((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, int *, hkpCompressedMeshShape *))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
            &hkContainerHeapAllocator::s_alloc,
            &v38,
            compressedMesh);
    v5 = compressedMesh;
    v14 = (_DWORD *)v13;
    v12 = v38 / 4;
  }
  else
  {
    v14 = 0i64;
  }
  v15 = 0x80000000;
  if ( v12 )
    v15 = v12;
  v30 = v15;
  v16 = v11;
  if ( v11 > 0 )
  {
    v17 = v14;
    while ( v16 )
    {
      *v17++ = -1;
      --v16;
    }
  }
  winding = 0;
  do
  {
    hkpCompressedMeshShape::Chunk::getTriangle(v10, v9, v5->m_error, &v1, &v2, &v3);
    v18 = &v1;
    v32 = v9;
    v19 = &v1;
    v20 = 3i64;
    v21 = v32;
    do
    {
      v22 = v10->m_indices.m_data[v21];
      if ( v14[v22] == -1 )
      {
        v14[v22] = geometry->m_vertices.m_size;
        hkVector4f::setTransformedPos(v19, &a, v19);
        if ( geometry->m_vertices.m_size == (geometry->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&geometry->m_vertices.m_data, 16);
        geometry->m_vertices.m_data[geometry->m_vertices.m_size++] = (hkVector4f)v18->m_quad;
      }
      ++v19;
      ++v21;
      ++v18;
      --v20;
    }
    while ( v20 );
    v23 = v10->m_indices.m_data;
    v24 = 2i64 * winding;
    v25 = v14[v23[v32 + 1]];
    v26 = v14[v23[v24 + v32]];
    v27 = v14[v23[v32 - v24 + 2]];
    if ( geometry->m_triangles.m_size == (geometry->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&geometry->m_triangles.m_data, 16);
    v28 = &geometry->m_triangles.m_data[geometry->m_triangles.m_size];
    v28->m_a = v26;
    v28->m_b = v25;
    v28->m_c = v27;
    v28->m_material = 0;
    ++geometry->m_triangles.m_size;
    NextIndex = hkpCompressedMeshShape::Chunk::getNextIndex(v10, index, &winding);
    v5 = compressedMesh;
    v9 = NextIndex;
    index = NextIndex;
  }
  while ( NextIndex != -1 );
  if ( v30 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v14, 4 * v30);
}= -1 );
  if ( v30 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v14, 4 * 

// File Line: 913
// RVA: 0x1324260
void __fastcall hkpCompressedMeshShapeBuilder::convexPieceToGeometry(
        hkpCompressedMeshShape *compressedMesh,
        int index,
        hkGeometry *geometry)
{
  hkpCompressedMeshShape::ConvexPiece *m_data; // r10
  unsigned __int16 m_transformIndex; // ax
  unsigned __int16 m_reference; // ax
  float m_error; // xmm1_4
  hkArray<hkVector4f,hkContainerHeapAllocator> vertices; // [rsp+20h] [rbp-58h] BYREF
  hkStridedVertices stridedVertsIn; // [rsp+30h] [rbp-48h] BYREF
  hkQsTransformf transform; // [rsp+40h] [rbp-38h] BYREF

  m_data = compressedMesh->m_convexPieces.m_data;
  transform.m_translation = 0i64;
  transform.m_scale = (hkVector4f)query.m_quad;
  transform.m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
  m_transformIndex = m_data[index].m_transformIndex;
  if ( m_transformIndex != 0xFFFF )
    transform = compressedMesh->m_transforms.m_data[m_transformIndex];
  m_reference = m_data[index].m_reference;
  if ( m_reference != 0xFFFF )
    index = m_reference;
  m_error = compressedMesh->m_error;
  vertices.m_data = 0i64;
  vertices.m_size = 0;
  vertices.m_capacityAndFlags = 0x80000000;
  hkpCompressedMeshShape::ConvexPiece::getVertices(&m_data[index], m_error, &transform, &vertices);
  stridedVertsIn.m_vertices = vertices.m_data->m_quad.m128_f32;
  stridedVertsIn.m_numVertices = vertices.m_size;
  stridedVertsIn.m_striding = 16;
  hkGeometryUtility::createConvexGeometry(&stridedVertsIn, geometry);
  vertices.m_size = 0;
  if ( vertices.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      vertices.m_data,
      16 * vertices.m_capacityAndFlags);
}

// File Line: 933
// RVA: 0x1324390
void __fastcall hkpCompressedMeshShapeBuilder::bigTrianglesToGeometry(
        hkpCompressedMeshShape *compressedMesh,
        hkGeometry *geometryOut)
{
  int v2; // r12d
  hkGeometry *v3; // rsi
  hkArray<hkVector4f,hkContainerHeapAllocator> *p_m_vertices; // rbx
  hkArray<hkGeometry::Triangle,hkContainerHeapAllocator> *p_m_triangles; // rdi
  __int64 v7; // r13
  hkVector4f *m_data; // rcx
  hkpCompressedMeshShape::BigTriangle *v9; // rdx
  unsigned __int16 m_transformIndex; // ax
  int m_size; // esi
  int v12; // r14d
  int v13; // r15d
  hkGeometry::Triangle *v14; // rax
  hkVector4f b; // [rsp+20h] [rbp-98h] BYREF
  hkVector4f v16; // [rsp+30h] [rbp-88h] BYREF
  hkVector4f v17; // [rsp+40h] [rbp-78h] BYREF
  hkQsTransformf a; // [rsp+50h] [rbp-68h] BYREF

  v2 = 0;
  v3 = geometryOut;
  if ( compressedMesh->m_bigTriangles.m_size > 0 )
  {
    p_m_vertices = &geometryOut->m_vertices;
    p_m_triangles = &geometryOut->m_triangles;
    v7 = 0i64;
    do
    {
      m_data = compressedMesh->m_bigVertices.m_data;
      v9 = &compressedMesh->m_bigTriangles.m_data[v7];
      b.m_quad = (__m128)m_data[v9->m_a];
      v16.m_quad = (__m128)m_data[v9->m_b];
      v17.m_quad = (__m128)m_data[v9->m_c];
      m_transformIndex = v9->m_transformIndex;
      if ( m_transformIndex != 0xFFFF )
      {
        a = compressedMesh->m_transforms.m_data[m_transformIndex];
        hkVector4f::setTransformedPos(&b, &a, &b);
        hkVector4f::setTransformedPos(&v16, &a, &v16);
        hkVector4f::setTransformedPos(&v17, &a, &v17);
      }
      m_size = v3->m_vertices.m_size;
      if ( p_m_vertices->m_size == (p_m_vertices->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_vertices->m_data, 16);
      p_m_vertices->m_data[p_m_vertices->m_size++] = (hkVector4f)b.m_quad;
      if ( p_m_vertices->m_size == (p_m_vertices->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_vertices->m_data, 16);
      p_m_vertices->m_data[p_m_vertices->m_size++] = (hkVector4f)v16.m_quad;
      if ( p_m_vertices->m_size == (p_m_vertices->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_vertices->m_data, 16);
      v12 = m_size + 1;
      v13 = m_size + 2;
      p_m_vertices->m_data[p_m_vertices->m_size++] = (hkVector4f)v17.m_quad;
      if ( p_m_triangles->m_size == (p_m_triangles->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_triangles->m_data, 16);
      ++v2;
      ++v7;
      v14 = &p_m_triangles->m_data[p_m_triangles->m_size];
      v14->m_a = m_size;
      v3 = geometryOut;
      v14->m_b = v12;
      v14->m_c = v13;
      v14->m_material = 0;
      ++p_m_triangles->m_size;
    }
    while ( v2 < compressedMesh->m_bigTriangles.m_size );
  }
}

// File Line: 956
// RVA: 0x1324870
void __fastcall hkpCompressedMeshShapeBuilder::MappingTree::getKeys(
        hkpCompressedMeshShapeBuilder::MappingTree *this,
        hkArray<unsigned int,hkContainerHeapAllocator> *keys,
        const int keysBase)
{
  __int64 v3; // rsi
  int v5; // r9d
  __int64 v6; // r10
  __int64 m_originalIndex; // r8
  unsigned int m_key; // eax
  hkpCompressedMeshShapeBuilder::MappingTree **p_m_right; // rbx

  v3 = keysBase;
  while ( 1 )
  {
    v5 = 0;
    if ( this->m_triangles.m_size > 0 )
    {
      v6 = 0i64;
      do
      {
        ++v5;
        m_originalIndex = this->m_triangles.m_data[v6].m_originalIndex;
        m_key = this->m_triangles.m_data[v6++].m_key;
        keys->m_data[v3 + m_originalIndex] = m_key;
      }
      while ( v5 < this->m_triangles.m_size );
    }
    if ( !this->m_left )
      break;
    p_m_right = &this->m_right;
    if ( !this->m_right )
      break;
    hkpCompressedMeshShapeBuilder::MappingTree::getKeys(this->m_left, keys, v3);
    this = *p_m_right;
  }
}

// File Line: 969
// RVA: 0x1325650
__int64 __fastcall hkpCompressedMeshShapeBuilder::addBigTriangles(
        hkpCompressedMeshShapeBuilder *this,
        hkpCompressedMeshShape *meshShape)
{
  int m_size; // esi
  unsigned int v5; // r15d
  __int64 v6; // rbp
  hkArray<hkpCompressedMeshShape::BigTriangle,hkContainerHeapAllocator> *p_m_bigTriangles; // rbx
  __int64 v8; // r14
  int v9; // r9d
  int v10; // eax
  int v11; // eax
  __int64 v12; // rdx
  unsigned __int16 *p_m_weldingInfo; // rcx
  int v14; // r9d
  __int64 v15; // rdx
  __int64 v16; // r8
  hkGeometry::Triangle *m_data; // rcx
  __int16 m_b; // ax
  __int16 m_c; // ax
  int v21; // [rsp+30h] [rbp-28h]
  int v22; // [rsp+34h] [rbp-24h]
  hkResult result; // [rsp+60h] [rbp+8h] BYREF

  hkGeometryUtils::weldVertices(&this->m_leftOver, 0.001);
  m_size = meshShape->m_bigVertices.m_size;
  hkArrayBase<hkVector4f>::_append(
    &meshShape->m_bigVertices,
    &hkContainerHeapAllocator::s_alloc,
    this->m_leftOver.m_vertices.m_data,
    this->m_leftOver.m_vertices.m_size);
  v5 = meshShape->m_bigTriangles.m_size;
  v6 = this->m_leftOver.m_triangles.m_size;
  p_m_bigTriangles = &meshShape->m_bigTriangles;
  v8 = p_m_bigTriangles->m_size;
  v9 = v8 + v6;
  v10 = p_m_bigTriangles->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 < (int)v8 + (int)v6 )
  {
    v11 = 2 * v10;
    if ( v9 < v11 )
      v9 = v11;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&p_m_bigTriangles->m_data, v9, 16);
  }
  v12 = v6;
  if ( (int)v6 > 0 )
  {
    p_m_weldingInfo = &p_m_bigTriangles->m_data[p_m_bigTriangles->m_size].m_weldingInfo;
    do
    {
      if ( p_m_weldingInfo != (unsigned __int16 *)12 )
      {
        *((_DWORD *)p_m_weldingInfo - 1) = 0;
        *(_DWORD *)p_m_weldingInfo = -65536;
      }
      p_m_weldingInfo += 8;
      --v12;
    }
    while ( v12 );
  }
  p_m_bigTriangles->m_size += v6;
  v14 = 0;
  v15 = (__int64)&p_m_bigTriangles->m_data[v8];
  if ( this->m_leftOver.m_triangles.m_size > 0 )
  {
    v16 = 0i64;
    do
    {
      m_data = this->m_leftOver.m_triangles.m_data;
      ++v14;
      v15 += 16i64;
      LOWORD(v21) = LOWORD(m_data[v16].m_a) + m_size;
      m_b = m_data[v16++].m_b;
      HIWORD(v21) = m_size + m_b;
      m_c = m_data[v16 - 1].m_c;
      LODWORD(m_data) = m_data[v16 - 1].m_material;
      LOWORD(v22) = m_size + m_c;
      *(_DWORD *)(v15 - 16) = v21;
      *(_DWORD *)(v15 - 12) = v22;
      *(_DWORD *)(v15 - 8) = (_DWORD)m_data;
      *(_DWORD *)(v15 - 4) = -65536;
    }
    while ( v14 < this->m_leftOver.m_triangles.m_size );
  }
  this->m_statistics.m_numBigTriangles += this->m_leftOver.m_triangles.m_size;
  this->m_statistics.m_numBigVertices += this->m_leftOver.m_vertices.m_size;
  this->m_leftOver.m_vertices.m_size = 0;
  this->m_leftOver.m_triangles.m_size = 0;
  return v5;
}

// File Line: 1004
// RVA: 0x13245F0
void __fastcall hkpCompressedMeshShapeBuilder::snapGeometry(hkGeometry *geometry, float quantizationError)
{
  int i; // ebx

  for ( i = 0; i < geometry->m_vertices.m_size; ++i )
    hkpCompressedMeshShapeBuilder::snapToGrid(&geometry->m_vertices.m_data[i], quantizationError);
}

// File Line: 1012
// RVA: 0x1326260
void __fastcall projectOnEdge(hkVector4f *v, hkVector4f *a, hkVector4f *b)
{
  __m128 v3; // xmm8
  __m128 v4; // xmm11
  __m128 v5; // xmm8
  __m128 v6; // xmm1
  __m128 v7; // xmm3
  __m128 v8; // xmm2
  __m128 v9; // xmm9
  __m128 v10; // xmm1
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __m128 v13; // xmm1
  __m128 v14; // xmm5
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  __m128 v17; // xmm6
  __m128 v18; // xmm0
  __m128 v19; // xmm1
  float v20; // xmm3_4
  __m128 v21; // xmm6
  hkOstream *v22; // rax
  hkOstream *v23; // rax
  hkOstream *v24; // rax
  hkErrStream v25; // [rsp+20h] [rbp-288h] BYREF
  char buf[616]; // [rsp+40h] [rbp-268h] BYREF

  v3 = _mm_sub_ps(b->m_quad, v->m_quad);
  v4 = _mm_sub_ps(b->m_quad, a->m_quad);
  v5 = _mm_mul_ps(v3, v3);
  v6 = _mm_mul_ps(v4, v4);
  v7 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)), _mm_shuffle_ps(v6, v6, 170));
  v8 = _mm_rsqrt_ps(v7);
  v9 = _mm_andnot_ps(
         _mm_cmple_ps(v7, (__m128)0i64),
         _mm_mul_ps(
           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v8, v7), v8)), _mm_mul_ps(*(__m128 *)_xmm, v8)),
           v7));
  v10 = _mm_sub_ps(v->m_quad, a->m_quad);
  v11 = _mm_mul_ps(v10, v10);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v13 = _mm_rsqrt_ps(v12);
  v14 = _mm_andnot_ps(
          _mm_cmple_ps(v12, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v13, v12), v13)),
              _mm_mul_ps(*(__m128 *)_xmm, v13)),
            v12));
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)), _mm_shuffle_ps(v5, v5, 170));
  v16 = _mm_rsqrt_ps(v15);
  v17 = _mm_mul_ps(*(__m128 *)_xmm, v16);
  v18 = _mm_mul_ps(_mm_mul_ps(v16, v15), v16);
  v19 = _mm_rcp_ps(v9);
  LODWORD(v20) = _mm_andnot_ps(
                   _mm_cmple_ps(v15, (__m128)0i64),
                   _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, v18), v17), v15)).m128_u32[0];
  v21 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v19, v9)), v19), v14);
  if ( v21.m128_f32[0] < 0.0 || v21.m128_f32[0] > 1.0 )
  {
    hkErrStream::hkErrStream(&v25, buf, 512);
    v22 = hkOstream::operator<<(&v25, "ratio: ");
    v23 = hkOstream::operator<<(v22, v21.m128_f32[0]);
    v24 = hkOstream::operator<<(v23, ", ");
    hkOstream::operator<<(
      v24,
      1.0 - (float)((float)((float)(2.0 - (float)(v19.m128_f32[0] * v9.m128_f32[0])) * v19.m128_f32[0]) * v20));
    hkError::messageReport(
      0xFFFFFFFF,
      buf,
      "Shape\\Deprecated\\CompressedMesh\\hkpCompressedMeshShapeBuilder.cpp",
      1037);
    hkOstream::~hkOstream(&v25);
  }
  else
  {
    v->m_quad = _mm_add_ps(_mm_mul_ps(v21, v4), a->m_quad);
  }
}

// File Line: 1042
// RVA: 0x1323B60
void __fastcall hkpCompressedMeshShapeBuilder::snapGeometry(
        hkpCompressedMeshShapeBuilder *this,
        hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *mapping)
{
  float m_weldTolerance; // xmm1_4
  hkGeometry *p_m_geometry; // rcx
  float m_TjunctionTolerance; // xmm3_4
  hkArray<hkTjunctionDetector::ProximityInfo,hkContainerHeapAllocator> *p_m_Tjunctions; // rsi
  __int64 m_TjunctionsBase; // rax
  __int64 v9; // rbx
  hkTjunctionDetector::ProximityInfo *m_data; // r13
  hkVector4f *v11; // rcx
  hkGeometry::Triangle *v12; // rax
  hkVector4f *v13; // rsi
  __int64 m_a; // r14
  __int64 m_b; // r15
  __int64 m_c; // r12
  hkTjunctionDetector::ProximityInfoEnum m_type; // eax
  __m128 *p_m_quad; // r14
  __m128 *v19; // r15
  __m128 *v20; // r12
  __m128 v21; // xmm1
  __m128 v22; // xmm0
  __m128 v23; // xmm6
  __m128 v24; // xmm6
  __m128 v25; // xmm1
  __m128 v26; // xmm3
  __m128 v27; // xmm2
  __m128 v28; // xmm6
  __m128 v29; // xmm2
  hkVector4f *v30; // r8
  hkVector4f *v31; // rdx
  float triangleRemapOut; // [rsp+20h] [rbp-50h]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> array; // [rsp+30h] [rbp-40h] BYREF
  hkArray<int,hkContainerHeapAllocator> v34; // [rsp+40h] [rbp-30h]
  hkArray<int,hkContainerHeapAllocator> vertexRemapOut; // [rsp+50h] [rbp-20h] BYREF
  int v36; // [rsp+A0h] [rbp+30h]

  if ( this->m_weldVertices )
  {
    m_weldTolerance = this->m_weldTolerance;
    p_m_geometry = &this->m_geometry;
    if ( mapping )
    {
      vertexRemapOut.m_capacityAndFlags = 0x80000000;
      v34.m_capacityAndFlags = 0x80000000;
      vertexRemapOut.m_data = 0i64;
      vertexRemapOut.m_size = 0;
      v34.m_data = 0i64;
      v34.m_size = 0;
      array.m_data = 0i64;
      array.m_size = 0;
      array.m_capacityAndFlags = 0x80000000;
      hkGeometryUtils::weldVertices(p_m_geometry, m_weldTolerance, 0, &vertexRemapOut);
      hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(mapping, &array);
      array.m_size = 0;
      if ( array.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          array.m_data,
          20 * (array.m_capacityAndFlags & 0x3FFFFFFF));
      array.m_data = 0i64;
      array.m_capacityAndFlags = 0x80000000;
      v34.m_size = 0;
      if ( v34.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v34.m_data,
          4 * v34.m_capacityAndFlags);
      v34.m_data = 0i64;
      v34.m_capacityAndFlags = 0x80000000;
      vertexRemapOut.m_size = 0;
      if ( vertexRemapOut.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          vertexRemapOut.m_data,
          4 * vertexRemapOut.m_capacityAndFlags);
    }
    else
    {
      hkGeometryUtils::weldVertices(p_m_geometry, m_weldTolerance);
    }
  }
  m_TjunctionTolerance = this->m_TjunctionTolerance;
  p_m_Tjunctions = &this->m_Tjunctions;
  triangleRemapOut = this->m_weldTolerance;
  this->m_TjunctionsBase = this->m_Tjunctions.m_size;
  hkTjunctionDetector::detect(
    &this->m_geometry,
    &this->m_Tjunctions,
    &this->m_weldedVertices,
    m_TjunctionTolerance,
    triangleRemapOut);
  hkpCompressedMeshShapeBuilder::snapGeometry(&this->m_geometry, this->m_error);
  m_TjunctionsBase = this->m_TjunctionsBase;
  v36 = m_TjunctionsBase;
  if ( (int)m_TjunctionsBase < this->m_Tjunctions.m_size )
  {
    v9 = m_TjunctionsBase;
    do
    {
      m_data = p_m_Tjunctions->m_data;
      v11 = this->m_geometry.m_vertices.m_data;
      v12 = &this->m_geometry.m_triangles.m_data[p_m_Tjunctions->m_data[v9].m_key];
      v13 = &v11[p_m_Tjunctions->m_data[v9].m_index];
      m_a = v12->m_a;
      m_b = v12->m_b;
      m_c = v12->m_c;
      m_type = m_data[v9].m_type;
      p_m_quad = &v11[m_a].m_quad;
      v19 = &v11[m_b].m_quad;
      v20 = &v11[m_c].m_quad;
      switch ( m_type )
      {
        case NEAR_FACE:
          v21 = _mm_sub_ps(*v19, *p_m_quad);
          v22 = _mm_sub_ps(*v20, *p_m_quad);
          v23 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v21),
                  _mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v22));
          v24 = _mm_shuffle_ps(v23, v23, 201);
          v25 = _mm_mul_ps(v24, v24);
          v26 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
                  _mm_shuffle_ps(v25, v25, 170));
          v27 = _mm_rsqrt_ps(v26);
          v28 = _mm_mul_ps(
                  v24,
                  _mm_andnot_ps(
                    _mm_cmple_ps(v26, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27)),
                      _mm_mul_ps(*(__m128 *)_xmm, v27))));
          v29 = _mm_mul_ps(_mm_sub_ps(v13->m_quad, *p_m_quad), v28);
          v13->m_quad = _mm_sub_ps(
                          v13->m_quad,
                          _mm_mul_ps(
                            _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
                              _mm_shuffle_ps(v29, v29, 170)),
                            v28));
          break;
        case NEAR_EDGE0:
          v30 = (hkVector4f *)v19;
          v31 = (hkVector4f *)p_m_quad;
LABEL_20:
          projectOnEdge(v13, v31, v30);
          break;
        case NEAR_EDGE1:
          v30 = (hkVector4f *)v20;
          v31 = (hkVector4f *)v19;
          goto LABEL_20;
        case NEAR_EDGE2:
          v30 = (hkVector4f *)p_m_quad;
          v31 = (hkVector4f *)v20;
          goto LABEL_20;
      }
      m_data[v9++].m_vertex = (hkVector4f)v13->m_quad;
      ++v36;
      p_m_Tjunctions = &this->m_Tjunctions;
      m_data[v9 - 1].m_v0.m_quad = *p_m_quad;
      m_data[v9 - 1].m_v1.m_quad = *v19;
      m_data[v9 - 1].m_v2.m_quad = *v20;
    }
    while ( v36 < this->m_Tjunctions.m_size );
  }
}

// File Line: 1133
// RVA: 0x13257E0
void __fastcall hkpCompressedMeshShapeBuilder::filterGeometry(
        hkpCompressedMeshShapeBuilder *this,
        hkpCompressedMeshShapeBuilder::MappingTree *mapping)
{
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v2; // rdi
  int m_size; // esi
  int v5; // edx
  __int64 v6; // rcx
  __int64 m_TjunctionsBase; // rdx
  __int64 v8; // r8
  hkArray<hkGeometry::Triangle,hkContainerHeapAllocator> *p_m_triangles; // r15
  hkGeometry::Triangle *m_data; // rsi
  __int64 v11; // r14
  __int64 v12; // rdi
  hkGeometry::Triangle *v13; // rax
  hkVector4f *v14; // rcx
  __int64 m_a; // rdx
  __int64 v16; // r15
  hkpCompressedMeshShapeBuilder::TriangleMapping *m_b; // rdx
  __int64 m_c; // rax
  hkVector4f *v19; // r12
  hkVector4f *v20; // r15
  hkVector4f *v21; // r13
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v22; // rdx
  hkpCompressedMeshShapeBuilder::TriangleMapping *v23; // r8
  __m128 v24; // xmm3
  hkGeometry::Triangle *v25; // rcx
  hkRelocationInfo::Import *v26; // r15
  int v27; // edx
  int *v28; // r8
  __int64 v29; // rsi
  int v30; // eax
  int v31; // eax
  int v32; // r9d
  hkArray<hkVector4f,hkContainerHeapAllocator> *p_m_vertices; // rsi
  int v34; // r10d
  hkVector4f *v35; // rdi
  int v36; // r8d
  __int64 v37; // rdx
  __int64 v38; // r9
  hkVector4f *v39; // rcx
  __int64 v40; // rdi
  int v41; // eax
  int v42; // eax
  int v43; // r9d
  int v44; // r9d
  __int64 v45; // r8
  hkGeometry::Triangle *v46; // rdx
  __int64 v47; // rcx
  hkpCompressedMeshShapeBuilder::TriangleMapping *map; // [rsp+28h] [rbp-49h]
  __int64 v49; // [rsp+30h] [rbp-41h]
  _DWORD *array; // [rsp+38h] [rbp-39h] BYREF
  int v51; // [rsp+40h] [rbp-31h]
  int v52; // [rsp+44h] [rbp-2Dh]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> a; // [rsp+48h] [rbp-29h] BYREF
  hkSimdFloat32 tolerance; // [rsp+58h] [rbp-19h] BYREF
  __m128i v55; // [rsp+68h] [rbp-9h]
  void *retaddr; // [rsp+D8h] [rbp+67h] BYREF
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *result; // [rsp+E0h] [rbp+6Fh] BYREF
  hkpCompressedMeshShapeBuilder::MappingTree *v58; // [rsp+E8h] [rbp+77h]
  __int64 v59; // [rsp+F0h] [rbp+7Fh]

  v58 = mapping;
  v2 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)mapping;
  v52 = 0x80000000;
  array = 0i64;
  v51 = 0;
  if ( this->m_preserveTjunctions )
  {
    m_size = this->m_geometry.m_vertices.m_size;
    if ( m_size > 0 )
      hkArrayUtil::_reserve(
        (hkResult *)&retaddr,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&array,
        this->m_geometry.m_vertices.m_size,
        4);
    v51 = m_size;
    v5 = 0;
    if ( m_size > 0 )
    {
      v6 = 0i64;
      do
      {
        ++v5;
        array[v6++] = 0;
      }
      while ( v5 < v51 );
    }
    m_TjunctionsBase = this->m_TjunctionsBase;
    if ( (int)m_TjunctionsBase < this->m_Tjunctions.m_size )
    {
      v8 = m_TjunctionsBase;
      do
      {
        LODWORD(m_TjunctionsBase) = m_TjunctionsBase + 1;
        array[this->m_Tjunctions.m_data[v8++].m_index] = -1;
      }
      while ( (int)m_TjunctionsBase < this->m_Tjunctions.m_size );
    }
  }
  p_m_triangles = &this->m_geometry.m_triangles;
  a.m_data = 0i64;
  a.m_size = 0;
  m_data = this->m_geometry.m_triangles.m_data;
  a.m_capacityAndFlags = 0x80000000;
  LODWORD(retaddr) = 0;
  if ( this->m_geometry.m_triangles.m_size > 0 )
  {
    v11 = 0i64;
    v12 = 0i64;
    while ( 1 )
    {
      v13 = p_m_triangles->m_data;
      v14 = this->m_geometry.m_vertices.m_data;
      m_a = p_m_triangles->m_data[v12].m_a;
      *(float *)&v58 = hkDefaultTriangleDegeneracyTolerance;
      v16 = m_a;
      v59 = m_a;
      m_b = (hkpCompressedMeshShapeBuilder::TriangleMapping *)v13[v12].m_b;
      tolerance.m_real = _mm_shuffle_ps(
                           (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                           (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                           0);
      m_c = v13[v12].m_c;
      map = m_b;
      v19 = &v14[(_QWORD)m_b];
      v20 = &v14[v16];
      v21 = &v14[m_c];
      v49 = m_c;
      if ( hkcdTriangleUtil::isDegenerate(v20, v19, v21, &tolerance) )
        break;
      v22 = result;
      if ( result )
        v23 = (hkpCompressedMeshShapeBuilder::TriangleMapping *)((char *)result->m_data + 20 * (int)retaddr);
      else
        v23 = 0i64;
      if ( this->m_preserveTjunctions && (array[v59] == -1 || array[(_QWORD)map] == -1 || array[v49] == -1)
        || (v55 = (__m128i)_mm_sub_ps(
                             _mm_max_ps(
                               _mm_max_ps(
                                 _mm_max_ps(
                                   _mm_xor_ps(
                                     (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                     (__m128)xmmword_141A712A0),
                                   v20->m_quad),
                                 v19->m_quad),
                               v21->m_quad),
                             _mm_min_ps(
                               _mm_min_ps(_mm_min_ps((__m128)xmmword_141A712A0, v20->m_quad), v19->m_quad),
                               v21->m_quad)),
            v24 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v55, 1u), 1u),
            (float)(this->m_error * 65534.0) < *(float *)&v55.m128i_i32[(unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(_mm_max_ps(_mm_shuffle_ps(v24, v24, 170), _mm_max_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0))), v24), (__m128)xmmword_141C20A50))]]) )
      {
        hkpCompressedMeshShapeBuilder::addLeftOverTriangle(
          this,
          v20,
          v19,
          v21,
          this->m_geometry.m_triangles.m_data[v12].m_material,
          v23);
        goto LABEL_30;
      }
      p_m_triangles = &this->m_geometry.m_triangles;
      ++m_data;
      v25 = this->m_geometry.m_triangles.m_data;
      m_data[-1].m_a = v25[v12].m_a;
      m_data[-1].m_b = v25[v12].m_b;
      m_data[-1].m_c = v25[v12].m_c;
      m_data[-1].m_material = v25[v12].m_material;
      if ( v22 )
      {
        v26 = v22->m_data;
        v27 = a.m_size;
        if ( a.m_size == (a.m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&a.m_data, 20);
          v27 = a.m_size;
        }
        v28 = &a.m_data->m_fromOffset + 5 * v27;
        if ( v28 )
        {
          *v28 = *(int *)((char *)&v26->m_fromOffset + v11);
          v28[1] = *(int *)((char *)&v26->m_fromOffset + v11 + 4);
          v28[2] = *(_DWORD *)((char *)&v26->m_identifier + v11);
          v28[3] = *(_DWORD *)((char *)&v26->m_identifier + v11 + 4);
          v28[4] = *(int *)((char *)&v26[1].m_fromOffset + v11);
          v27 = a.m_size;
        }
        a.m_size = v27 + 1;
        goto LABEL_30;
      }
LABEL_31:
      ++v12;
      v11 += 20i64;
      LODWORD(retaddr) = (_DWORD)retaddr + 1;
      if ( (int)retaddr >= this->m_geometry.m_triangles.m_size )
      {
        v2 = result;
        goto LABEL_33;
      }
    }
    ++this->m_statistics.m_numDegenerate;
LABEL_30:
    p_m_triangles = &this->m_geometry.m_triangles;
    goto LABEL_31;
  }
LABEL_33:
  v29 = m_data - p_m_triangles->m_data;
  v30 = p_m_triangles->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v30 < (int)v29 )
  {
    v31 = 2 * v30;
    v32 = v29;
    if ( (int)v29 < v31 )
      v32 = v31;
    hkArrayUtil::_reserve(
      (hkResult *)&result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&p_m_triangles->m_data,
      v32,
      16);
  }
  p_m_triangles->m_size = v29;
  if ( v2 )
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(v2, &a);
  if ( this->m_preserveTjunctions )
  {
    p_m_vertices = &this->m_geometry.m_vertices;
    v34 = 0;
    v35 = this->m_geometry.m_vertices.m_data;
    v36 = 0;
    if ( this->m_geometry.m_vertices.m_size > 0 )
    {
      v37 = 0i64;
      v38 = 0i64;
      do
      {
        if ( array[v37] != -1 )
        {
          v39 = v35++;
          *v39 = p_m_vertices->m_data[v38];
          array[v37] = v34++;
        }
        ++v36;
        ++v38;
        ++v37;
      }
      while ( v36 < this->m_geometry.m_vertices.m_size );
    }
    v40 = v35 - p_m_vertices->m_data;
    v41 = this->m_geometry.m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v41 < (int)v40 )
    {
      v42 = 2 * v41;
      v43 = v40;
      if ( (int)v40 < v42 )
        v43 = v42;
      hkArrayUtil::_reserve(
        (hkResult *)&result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&this->m_geometry.m_vertices.m_data,
        v43,
        16);
    }
    this->m_geometry.m_vertices.m_size = v40;
    v44 = 0;
    if ( this->m_geometry.m_triangles.m_size > 0 )
    {
      v45 = 0i64;
      do
      {
        v46 = p_m_triangles->m_data;
        ++v44;
        v47 = p_m_triangles->m_data[v45++].m_a;
        v46[v45 - 1].m_a = array[v47];
        v46[v45 - 1].m_b = array[v46[v45 - 1].m_b];
        v46[v45 - 1].m_c = array[v46[v45 - 1].m_c];
      }
      while ( v44 < this->m_geometry.m_triangles.m_size );
    }
  }
  a.m_size = 0;
  if ( a.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      a.m_data,
      20 * (a.m_capacityAndFlags & 0x3FFFFFFF));
  a.m_data = 0i64;
  v51 = 0;
  a.m_capacityAndFlags = 0x80000000;
  if ( v52 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 4 * v52);
}

// File Line: 1236
// RVA: 0x13228B0
char __fastcall hkpCompressedMeshShapeBuilder::addConvexPiece(
        hkpCompressedMeshShapeBuilder *this,
        hkArray<hkVector4f,hkContainerHeapAllocator> *vertices,
        hkpCompressedMeshShape *compressedMesh)
{
  __m128 v6; // xmm3
  int m_size; // eax
  hkOstream *v9; // rax
  hkOstream *v10; // rax
  hkOstream *v11; // rax
  char v12; // bl
  hkVector4f v13; // xmm0
  float m_error; // xmm1_4
  hkpCompressedMeshShape::ConvexPiece *v15; // rcx
  hkArray<hkVector4f,hkContainerHeapAllocator> positions; // [rsp+20h] [rbp-E0h] BYREF
  hkErrStream points; // [rsp+30h] [rbp-D0h] BYREF
  hkpCompressedMeshShape::ConvexPiece v; // [rsp+50h] [rbp-B0h] BYREF
  hkgpConvexHull::BuildConfig config; // [rsp+80h] [rbp-80h] BYREF
  hkAabb aabbOut; // [rsp+90h] [rbp-70h] BYREF
  hkgpConvexHull v21; // [rsp+B0h] [rbp-50h] BYREF
  char buf[512]; // [rsp+E0h] [rbp-20h] BYREF

  hkAabbUtil::calcAabb(vertices->m_data, vertices->m_size, &aabbOut);
  points.hkReferencedObject = (hkReferencedObject)_mm_sub_ps(aabbOut.m_max.m_quad, aabbOut.m_min.m_quad);
  v6 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)points.hkReferencedObject, 1u), 1u);
  if ( (float)((float)(this->m_error * 65535.0) - 1.0) <= *((float *)&points.vfptr
                                                          + (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(_mm_max_ps(_mm_shuffle_ps(v6, v6, 170), _mm_max_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0))), v6), (__m128)xmmword_141C20A50))]) )
    return 0;
  hkgpConvexHull::BuildConfig::BuildConfig(&config);
  config.m_allowLowerDimensions.m_bool = 1;
  hkgpConvexHull::hkgpConvexHull(&v21);
  points.vfptr = (hkBaseObjectVtbl *)vertices->m_data;
  m_size = vertices->m_size;
  *(_DWORD *)(&points.m_referenceCount + 1) = 16;
  *(_DWORD *)&points.m_memSizeAndFlags = m_size;
  hkgpConvexHull::build(&v21, (hkStridedVertices *)&points, &config);
  positions.m_data = 0i64;
  positions.m_size = 0;
  positions.m_capacityAndFlags = 0x80000000;
  hkgpConvexHull::fetchPositions(&v21, INTERNAL_VERTICES, &positions);
  if ( positions.m_size <= 32 )
  {
    v13.m_quad = (__m128)aabbOut.m_min;
    m_error = this->m_error;
    this->m_statistics.m_numVertices += positions.m_size;
    v.m_vertices.m_data = 0i64;
    v.m_vertices.m_size = 0;
    v.m_offset = (hkVector4f)v13.m_quad;
    *(_QWORD *)&v.m_vertices.m_capacityAndFlags = 0xFFFFFFFF80000000ui64;
    hkpCompressedMeshShapeBuilder::snapToGrid(&v.m_offset, m_error);
    hkpCompressedMeshShapeBuilder::quantizeVertices(this->m_error, &v.m_offset, &positions, &v.m_vertices);
    if ( compressedMesh->m_convexPieces.m_size == (compressedMesh->m_convexPieces.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&compressedMesh->m_convexPieces.m_data,
        48);
    v15 = &compressedMesh->m_convexPieces.m_data[compressedMesh->m_convexPieces.m_size];
    if ( v15 )
      hkpCompressedMeshShape::ConvexPiece::ConvexPiece(v15, &v);
    ++compressedMesh->m_convexPieces.m_size;
    v.m_vertices.m_size = 0;
    v12 = 1;
    if ( v.m_vertices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        v.m_vertices.m_data,
        2 * (v.m_vertices.m_capacityAndFlags & 0x3FFFFFFF));
    v.m_vertices.m_data = 0i64;
    v.m_vertices.m_capacityAndFlags = 0x80000000;
  }
  else
  {
    hkErrStream::hkErrStream(&points, buf, 512);
    v9 = hkOstream::operator<<(&points, "Number of convex hull vertices (");
    v10 = hkOstream::operator<<(v9, positions.m_size);
    v11 = hkOstream::operator<<(v10, ") too large, maximum allowed: ");
    hkOstream::operator<<(v11, 0x20u);
    hkError::messageWarning(
      0x1CC91291u,
      buf,
      "Shape\\Deprecated\\CompressedMesh\\hkpCompressedMeshShapeBuilder.cpp",
      1257);
    hkOstream::~hkOstream(&points);
    v12 = 0;
  }
  positions.m_size = 0;
  if ( positions.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      positions.m_data,
      16 * positions.m_capacityAndFlags);
  positions.m_data = 0i64;
  positions.m_capacityAndFlags = 0x80000000;
  hkgpConvexHull::~hkgpConvexHull(&v21);
  return v12;
}

// File Line: 1275
// RVA: 0x1322B70
__int64 __fastcall hkpCompressedMeshShapeBuilder::addConvexPiece(
        hkpCompressedMeshShapeBuilder *this,
        hkGeometry *geometry,
        hkpCompressedMeshShape *compressedMesh)
{
  unsigned __int8 v5; // bp
  __int64 m_size; // rbx
  int v7; // r14d
  int v8; // r9d
  int v9; // eax
  int v10; // eax
  __int64 v11; // rcx
  hkResult result; // [rsp+58h] [rbp+10h] BYREF

  v5 = hkpCompressedMeshShapeBuilder::addConvexPiece(this, &geometry->m_vertices, compressedMesh);
  if ( !v5 || !this->m_createMapping )
    return v5;
  m_size = this->m_shapeKeys.m_size;
  v7 = geometry->m_triangles.m_size;
  v8 = v7 + this->m_shapeKeys.m_size;
  v9 = this->m_shapeKeys.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v9 < v8 )
  {
    v10 = 2 * v9;
    if ( v8 < v10 )
      v8 = v10;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_shapeKeys.m_data, v8, 4);
  }
  this->m_shapeKeys.m_size += v7;
  if ( (int)m_size < this->m_shapeKeys.m_size )
  {
    v11 = m_size;
    do
    {
      LODWORD(m_size) = m_size + 1;
      this->m_shapeKeys.m_data[v11++] = -1;
    }
    while ( (int)m_size < this->m_shapeKeys.m_size );
  }
  return v5;
}

