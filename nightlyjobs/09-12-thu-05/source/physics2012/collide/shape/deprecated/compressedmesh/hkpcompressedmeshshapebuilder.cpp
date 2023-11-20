// File Line: 23
// RVA: 0x1322470
void __fastcall hkpCompressedMeshShapeBuilder::createMeshShape(hkpCompressedMeshShapeBuilder *this, float quantizationError, hkpCompressedMeshShape::MaterialType materialType, int bitsPerIndex)
{
  hkpCompressedMeshShapeBuilder *v4; // rbx
  int v5; // edi
  char v6; // si
  _QWORD **v7; // rax
  hkpCompressedMeshShape *v8; // rax

  v4 = this;
  v5 = bitsPerIndex;
  v6 = materialType;
  v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (hkpCompressedMeshShape *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v7[11] + 8i64))(v7[11], 288i64);
  if ( v8 )
    hkpCompressedMeshShape::hkpCompressedMeshShape(v8, v5, hkConvexShapeDefaultRadius);
  v8->m_error = quantizationError;
  v8->m_materialType.m_storage = v6;
  v8->m_bounds.m_min = (hkVector4f)xmmword_141A712A0;
  v8->m_bounds.m_max.m_quad = _mm_xor_ps(
                                (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                v8->m_bounds.m_min.m_quad);
  v4->m_error = quantizationError;
  v4->m_shapeKeys.m_size = 0;
  v4->m_mesh = v8;
}

// File Line: 39
// RVA: 0x1323450
void __fastcall hkpCompressedMeshShapeBuilder::gatherStatistics(hkpCompressedMeshShapeBuilder *this, hkpCompressedMeshShape *meshShape)
{
  __int64 v2; // r11
  int v3; // ebx
  hkpCompressedMeshShape *v4; // rsi
  hkpCompressedMeshShapeBuilder *v5; // rbp
  signed int v6; // er9
  int v7; // edi
  int *v8; // r10
  int v9; // edx
  int v10; // ecx
  unsigned int v11; // eax
  signed int v12; // er8
  __int64 v13; // rdx
  int *v14; // rcx
  int v15; // eax
  float v16; // xmm1_4
  signed int v17; // ecx
  int v18; // edx
  int v19; // er9
  int v20; // ecx
  int v21; // eax
  int v22; // er9
  int v23; // ecx
  int v24; // edx
  int v25; // ecx
  int v26; // eax

  v2 = meshShape->m_chunks.m_size;
  v3 = 0;
  v4 = meshShape;
  v5 = this;
  v6 = 288;
  v7 = 0;
  if ( v2 > 0 )
  {
    v8 = &meshShape->m_chunks.m_data->m_vertices.m_size;
    do
    {
      v7 += v8[8];
      v9 = (unsigned __int64)(1431655766i64 * *v8) >> 32;
      v10 = v8[4] + v8[12];
      v11 = (unsigned __int64)(1431655766i64 * *v8) >> 32;
      v8 += 24;
      v3 += (v11 >> 31) + v9;
      v6 += 2 * (*(v8 - 24) + *(v8 - 16) + v10) + 96;
      --v2;
    }
    while ( v2 );
  }
  v5->m_statistics.m_chunksSize = v6;
  v12 = v6;
  if ( v4->m_convexPieces.m_size > 0 )
  {
    v13 = v4->m_convexPieces.m_size;
    v14 = &v4->m_convexPieces.m_data->m_vertices.m_size;
    do
    {
      v15 = *v14;
      v14 += 12;
      v6 += 2 * v15 + 48;
      --v13;
    }
    while ( v13 );
  }
  v16 = v5->m_error;
  v17 = v6;
  v5->m_statistics.m_convexPiecesSize = v6 - v12;
  v18 = v4->m_bigVertices.m_size;
  v19 = 16 * (v18 + v4->m_bigTriangles.m_size) + v6;
  v5->m_statistics.m_bigTrianglesSize = v19 - v17;
  v20 = v4->m_materials16.m_size + 2 * (v4->m_materials.m_size + 16 * v4->m_transforms.m_size);
  v21 = v4->m_materials8.m_size;
  v5->m_statistics.m_error = v16;
  v5->m_statistics.m_maxExtent = v16 * 65535.0;
  v5->m_statistics.m_maxIndex = 0xFFFF;
  v22 = v21 + 2 * v20 + v19;
  v23 = v5->m_statistics.m_numVertices;
  v24 = v18 - v23;
  v25 = v5->m_statistics.m_numTriangles + v23 + 3;
  v5->m_statistics.m_numExcessVertices = v3 + v24;
  v26 = v4->m_chunks.m_size;
  v5->m_statistics.m_numStrips = v7;
  v5->m_statistics.m_numChunks = v26;
  v5->m_statistics.m_size = v22;
  v5->m_statistics.m_compressRatio = (float)v22 / (float)(16 * v25);
}

// File Line: 92
// RVA: 0x1322530
void __fastcall hkpCompressedMeshShapeBuilder::addGeometry(hkpCompressedMeshShapeBuilder *this, hkGeometry *geometry, hkMatrix4f *transform, hkpCompressedMeshShape *meshShape)
{
  hkpCompressedMeshShapeBuilder *v4; // rbp
  hkGeometry *v5; // rcx
  hkpCompressedMeshShape *v6; // r13
  hkMatrix4f *v7; // rbx
  hkGeometry *v8; // r14
  __int64 v9; // rbx
  int i; // edi
  hkVector4f *v11; // r8
  hkpCompressedMeshShapeBuilder::MappingTree *v12; // rsi
  signed __int64 v13; // r15
  _QWORD **v14; // rax
  __int64 v15; // rax
  int v16; // edi
  int v17; // eax
  int v18; // eax
  int v19; // er9
  __int64 v20; // rcx
  __int64 v21; // rdx
  signed __int64 v22; // rax
  int v23; // edx
  __int64 v24; // rcx
  int v25; // er14
  int v26; // er9
  int v27; // eax
  int v28; // eax
  int v29; // edx
  signed __int64 v30; // rcx
  int v31; // edi
  hkpCompressedMeshShapeBuilder::MappingTree *v32; // rcx
  hkpCompressedMeshShapeBuilder::MappingTree *v33; // rcx
  int v34; // eax
  _QWORD **v35; // rax
  hkpCompressedMeshShapeBuilder::TriangleMapping *v36; // rax
  __int64 v37; // rcx
  hkQsTransformf a; // [rsp+30h] [rbp-58h]
  hkResult result; // [rsp+90h] [rbp+8h]

  this->m_mesh = meshShape;
  v4 = this;
  this->m_statistics.m_numVertices += geometry->m_vertices.m_size;
  v5 = &this->m_geometry;
  HIDWORD(v5[-3].m_vertices.m_data) += geometry->m_triangles.m_size;
  v6 = meshShape;
  v7 = transform;
  v8 = geometry;
  hkGeometry::operator=(v5, geometry);
  hkQsTransformf::set(&a, v7);
  v9 = 0i64;
  for ( i = 0; i < v4->m_geometry.m_vertices.m_size; ++i )
  {
    v11 = &v4->m_geometry.m_vertices.m_data[i];
    hkVector4f::setTransformedPos(v11, &a, v11);
  }
  v12 = 0i64;
  LODWORD(v13) = 0;
  if ( v4->m_createMapping )
  {
    v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v15 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v14[11] + 8i64))(v14[11], 32i64);
    v12 = (hkpCompressedMeshShapeBuilder::MappingTree *)v15;
    if ( v15 )
    {
      *(_QWORD *)v15 = 0i64;
      *(_DWORD *)(v15 + 8) = 0;
      *(_DWORD *)(v15 + 12) = 2147483648;
      *(_QWORD *)(v15 + 16) = 0i64;
      *(_QWORD *)(v15 + 24) = 0i64;
    }
    else
    {
      v12 = 0i64;
    }
    v16 = v8->m_triangles.m_size;
    v17 = v12->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v17 < v16 )
    {
      v18 = 2 * v17;
      v19 = v8->m_triangles.m_size;
      if ( v16 < v18 )
        v19 = v18;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v12, v19, 20);
    }
    v20 = v12->m_triangles.m_size;
    v21 = v16 - (signed int)v20;
    if ( v16 - (signed int)v20 > 0 )
    {
      v22 = (signed __int64)v12->m_triangles.m_data + 4 * (4 * v20 + 2 + v20);
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
    v12->m_triangles.m_size = v16;
    v23 = 0;
    if ( v16 > 0 )
    {
      v24 = 0i64;
      do
      {
        ++v24;
        v12->m_triangles.m_data[v24 - 1].m_originalIndex = v23++;
        *((_DWORD *)&v12->m_triangles.m_data[v24] - 2) = 0;
      }
      while ( v23 < v12->m_triangles.m_size );
    }
    v4->m_bigMapping.m_size = 0;
    v25 = v8->m_triangles.m_size;
    v13 = v4->m_shapeKeys.m_size;
    v26 = v25 + v4->m_shapeKeys.m_size;
    v27 = v4->m_shapeKeys.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v27 < v26 )
    {
      v28 = 2 * v27;
      if ( v26 < v28 )
        v26 = v28;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v4->m_shapeKeys,
        v26,
        4);
    }
    v4->m_shapeKeys.m_size += v25;
    v29 = v13;
    if ( (signed int)v13 < v4->m_shapeKeys.m_size )
    {
      v30 = v13;
      do
      {
        ++v29;
        ++v30;
        v4->m_shapeKeys.m_data[v30 - 1] = -1;
      }
      while ( v29 < v4->m_shapeKeys.m_size );
    }
  }
  if ( v4->m_preserveTjunctions )
    hkpCompressedMeshShapeBuilder::snapGeometry(v4, v12);
  else
    hkpCompressedMeshShapeBuilder::snapGeometry(&v4->m_geometry, v4->m_error);
  hkpCompressedMeshShapeBuilder::filterGeometry(v4, v12);
  if ( v4->m_geometry.m_triangles.m_size || v4->m_leftOver.m_triangles.m_size )
  {
    hkpCompressedMeshShapeBuilder::addChunk(v4, &v4->m_geometry, &v6->m_chunks, v12);
    v31 = hkpCompressedMeshShapeBuilder::addBigTriangles(v4, v6);
    if ( v4->m_createMapping )
    {
      hkpCompressedMeshShapeBuilder::MappingTree::getKeys(v12, &v4->m_shapeKeys, v13);
      if ( v12 )
      {
        v32 = v12->m_left;
        if ( v32 )
          hkpCompressedMeshShapeBuilder::MappingTree::`scalar deleting destructor'(v32, 1u);
        v33 = v12->m_right;
        if ( v33 )
          hkpCompressedMeshShapeBuilder::MappingTree::`scalar deleting destructor'(v33, 1u);
        v34 = v12->m_triangles.m_capacityAndFlags;
        v12->m_triangles.m_size = 0;
        if ( v34 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v12->m_triangles.m_data,
            20 * (v34 & 0x3FFFFFFF));
        v12->m_triangles.m_data = 0i64;
        v12->m_triangles.m_capacityAndFlags = 2147483648;
        v35 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, hkpCompressedMeshShapeBuilder::MappingTree *, signed __int64))(*v35[11] + 16i64))(
          v35[11],
          v12,
          32i64);
      }
      for ( ; v31 < v6->m_bigTriangles.m_size; ++v31 )
      {
        v36 = v4->m_bigMapping.m_data;
        ++v9;
        v37 = v36[v9 - 1].m_originalIndex;
        *((_DWORD *)&v36[v9] - 4) = v31;
        *((_DWORD *)&v36[v9] - 1) = v31;
        v4->m_shapeKeys.m_data[(signed int)v13 + v37] = v31;
      }
    }
  }
}

// File Line: 176
// RVA: 0x1322C50
__int64 __fastcall hkpCompressedMeshShapeBuilder::beginSubpart(hkpCompressedMeshShapeBuilder *this, hkpCompressedMeshShape *compressedMesh)
{
  int v2; // esi
  int v3; // ebp
  int v4; // er14
  int v5; // er15
  signed int *v6; // rbx
  hkpCompressedMeshShapeBuilder *v7; // rdi
  _DWORD *v8; // rdx

  v2 = compressedMesh->m_chunks.m_size;
  v3 = compressedMesh->m_bigTriangles.m_size;
  v4 = compressedMesh->m_convexPieces.m_size;
  v5 = this->m_shapeKeys.m_size;
  v6 = (signed int *)&this->subparts;
  v7 = this;
  if ( this->subparts.m_size == (this->subparts.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, 36);
  v8 = (_DWORD *)(*(_QWORD *)v6 + 36i64 * v6[2]);
  if ( v8 )
  {
    *v8 = 0;
    v8[1] = v2;
    v8[2] = 0;
    v8[3] = v3;
    v8[4] = 0;
    v8[5] = v4;
    v8[6] = 0;
    v8[7] = v5;
    v8[8] = 0;
  }
  ++v6[2];
  return (unsigned int)(v7->subparts.m_size - 1);
}

// File Line: 193
// RVA: 0x1322D20
void __fastcall hkpCompressedMeshShapeBuilder::endSubpart(hkpCompressedMeshShapeBuilder *this, hkpCompressedMeshShape *compressedMesh)
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
void __fastcall hkpCompressedMeshShapeBuilder::addInstance(hkpCompressedMeshShapeBuilder *this, int subpartID, hkMatrix4f *transform, hkpCompressedMeshShape *compressedMesh, hkArray<unsigned int,hkContainerHeapAllocator> *shapeKeyMap)
{
  __int64 v5; // rbx
  hkpCompressedMeshShape *v6; // rdi
  int v7; // er12
  hkpCompressedMeshShapeBuilder *v8; // r11
  hkQuaternionf *v9; // rcx
  signed __int64 v10; // rdx
  hkpCompressedMeshShapeBuilder::Subpart *v11; // r13
  signed __int64 v12; // rsi
  signed int v13; // eax
  hkArray<hkpCompressedMeshShape::Chunk,hkContainerHeapAllocator> *v14; // rbx
  signed __int64 v15; // r14
  int v16; // er15
  int v17; // eax
  hkpCompressedMeshShape::Chunk *v18; // rcx
  __m128 v19; // xmm1
  hkpCompressedMeshShapeBuilder::Subpart *v20; // rax
  signed __int64 v21; // r15
  int v22; // ecx
  __int64 v23; // rcx
  hkArray<hkpCompressedMeshShape::BigTriangle,hkContainerHeapAllocator> *v24; // rbx
  signed __int64 v25; // rsi
  hkpCompressedMeshShape::BigTriangle *v26; // rax
  int v27; // er14
  int v28; // edx
  unsigned int v29; // er8
  int v30; // er15
  int v31; // eax
  int v32; // eax
  float *v33; // rcx
  float v34; // eax
  hkVector4f *v35; // rcx
  unsigned __int16 *v36; // rdx
  __m128 v37; // xmm2
  __m128 v38; // xmm0
  __m128 v39; // xmm3
  unsigned __int16 v40; // ax
  hkQsTransformf *v41; // rdx
  __m128 v42; // xmm1
  __m128 v43; // xmm2
  bool v44; // zf
  __m128 v45; // xmm0
  __m128 v46; // xmm1
  hkArray<unsigned int,hkContainerHeapAllocator> *v47; // rsi
  __int64 v48; // rcx
  __int64 v49; // r14
  __int64 v50; // r15
  unsigned int v51; // ebx
  int v52; // er10
  int v53; // er9
  unsigned int v54; // er8
  hkpCompressedMeshShapeBuilder::Subpart *v55; // rax
  signed __int64 v56; // rcx
  signed __int64 v57; // r14
  hkArray<hkpCompressedMeshShape::ConvexPiece,hkContainerHeapAllocator> *v58; // rsi
  signed __int64 v59; // r15
  int v60; // er12
  signed __int64 v61; // rbx
  __int64 v62; // r8
  __m128 v63; // xmm1
  unsigned __int16 v64; // [rsp+20h] [rbp-E0h]
  int v65; // [rsp+24h] [rbp-DCh]
  unsigned int v66; // [rsp+28h] [rbp-D8h]
  signed __int64 v67; // [rsp+30h] [rbp-D0h]
  int v68; // [rsp+38h] [rbp-C8h]
  __int64 v69; // [rsp+40h] [rbp-C0h]
  hkAabb bounds; // [rsp+50h] [rbp-B0h]
  hkpCompressedMeshShapeBuilder::Subpart *v71; // [rsp+70h] [rbp-90h]
  hkVector4f v72; // [rsp+80h] [rbp-80h]
  hkVector4f v73; // [rsp+90h] [rbp-70h]
  hkpCompressedMeshShape::Chunk other; // [rsp+A0h] [rbp-60h]
  hkVector4f b; // [rsp+100h] [rbp+0h]
  hkQsTransformf v76; // [rsp+110h] [rbp+10h]
  hkpCompressedMeshShapeBuilder *v77; // [rsp+190h] [rbp+90h]
  int v78; // [rsp+198h] [rbp+98h]
  int v79; // [rsp+1A8h] [rbp+A8h]

  v77 = this;
  v5 = subpartID;
  v6 = compressedMesh;
  hkQsTransformf::set(&v76, transform);
  v7 = v6->m_transforms.m_size;
  v64 = v6->m_transforms.m_size;
  if ( v7 == (v6->m_transforms.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v6->m_transforms, 48);
  v8 = v77;
  v9 = (hkQuaternionf *)&v6->m_transforms.m_data[v6->m_transforms.m_size];
  *v9 = (hkQuaternionf)v76.m_translation;
  v9[1] = v76.m_rotation;
  v9[2] = (hkQuaternionf)v76.m_scale;
  ++v6->m_transforms.m_size;
  v10 = 36 * v5;
  v11 = &v77->subparts.m_data[v5];
  v68 = v6->m_chunks.m_size;
  v12 = v11->m_chunkOffset;
  v67 = 36 * v5;
  v13 = v12 + v11->m_numChunks;
  v71 = &v77->subparts.m_data[v5];
  v78 = v13;
  if ( (signed int)v12 < v13 )
  {
    v14 = &v6->m_chunks;
    v15 = v12;
    do
    {
      v16 = v12;
      if ( v11->m_numInstances )
      {
        v16 = v6->m_chunks.m_size;
        v17 = v6->m_chunks.m_capacityAndFlags & 0x3FFFFFFF;
        other.m_vertices.m_data = 0i64;
        other.m_vertices.m_size = 0;
        other.m_offset = 0i64;
        other.m_vertices.m_capacityAndFlags = 2147483648;
        other.m_indices.m_data = 0i64;
        other.m_indices.m_size = 0;
        other.m_indices.m_capacityAndFlags = 2147483648;
        other.m_stripLengths.m_data = 0i64;
        other.m_stripLengths.m_size = 0;
        other.m_stripLengths.m_capacityAndFlags = 2147483648;
        other.m_weldingInfo.m_data = 0i64;
        other.m_weldingInfo.m_size = 0;
        other.m_weldingInfo.m_capacityAndFlags = 2147483648;
        other.m_materialInfo = 0;
        other.m_reference = v12;
        other.m_transformIndex = v7;
        if ( v6->m_chunks.m_size == v17 )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v6->m_chunks, 96);
        v18 = &v14->m_data[v6->m_chunks.m_size];
        if ( v18 )
          hkpCompressedMeshShape::Chunk::Chunk(v18, &other);
        ++v6->m_chunks.m_size;
        ++v77->m_statistics.m_numChunkClones;
        hkpCompressedMeshShape::Chunk::~Chunk(&other);
      }
      else
      {
        v14->m_data[v15].m_transformIndex = v7;
      }
      hkpCompressedMeshShape::getChunkAabb(v6, &v14->m_data[v16], &bounds);
      LODWORD(v12) = v12 + 1;
      ++v15;
      v19 = _mm_max_ps(v6->m_bounds.m_max.m_quad, bounds.m_max.m_quad);
      v6->m_bounds.m_min.m_quad = _mm_min_ps(v6->m_bounds.m_min.m_quad, bounds.m_min.m_quad);
      v6->m_bounds.m_max.m_quad = v19;
    }
    while ( (signed int)v12 < v78 );
    v8 = v77;
    v10 = v67;
  }
  v20 = v8->subparts.m_data;
  v21 = *(int *)((char *)&v20->m_bigOffset + v10);
  v22 = *(int *)((char *)&v20->m_numBigTriangles + v10);
  v65 = v6->m_bigTriangles.m_size;
  v78 = v21;
  v23 = (signed int)v21 + v22;
  if ( v21 < v23 )
  {
    v24 = &v6->m_bigTriangles;
    v25 = v21;
    v69 = v23 - v21;
    do
    {
      v26 = v24->m_data;
      v27 = v21;
      if ( v11->m_numInstances )
      {
        v28 = *(_DWORD *)&v26[v25].m_c;
        v29 = v26[v25].m_material;
        v30 = *(_DWORD *)&v26[v25].m_a;
        v31 = *(_DWORD *)&v26[v25].m_weldingInfo;
        v27 = v6->m_bigTriangles.m_size;
        v79 = v28;
        bounds.m_min.m_quad.m128_i32[3] = v31;
        v66 = v29;
        v32 = v6->m_bigTriangles.m_capacityAndFlags & 0x3FFFFFFF;
        bounds.m_min.m_quad.m128_i16[7] = v7;
        if ( v6->m_bigTriangles.m_size == v32 )
        {
          hkArrayUtil::_reserveMore(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &v6->m_bigTriangles,
            16);
          v28 = v79;
          v29 = v66;
        }
        v33 = (float *)&v24->m_data[v6->m_bigTriangles.m_size].m_a;
        if ( v33 )
        {
          v34 = bounds.m_min.m_quad.m128_f32[3];
          *(_DWORD *)v33 = v30;
          *((_DWORD *)v33 + 1) = v28;
          *((_DWORD *)v33 + 2) = v29;
          v33[3] = v34;
        }
        ++v6->m_bigTriangles.m_size;
        LODWORD(v21) = v78;
      }
      else
      {
        v26[v25].m_transformIndex = v7;
      }
      v35 = v6->m_bigVertices.m_data;
      v36 = &v24->m_data[v27].m_a;
      v37 = v35[*v36].m_quad;
      b.m_quad = (__m128)v35[*v36];
      v38 = v35[v36[1]].m_quad;
      v73.m_quad = (__m128)v35[v36[1]];
      v39 = v35[v36[2]].m_quad;
      v72.m_quad = (__m128)v35[v36[2]];
      v40 = v36[7];
      if ( v40 != -1 )
      {
        v41 = v6->m_transforms.m_data;
        other.m_offset = v41[v40].m_translation;
        other.m_vertices = (hkArray<unsigned short,hkContainerHeapAllocator>)v41[v40].m_rotation;
        other.m_indices = (hkArray<unsigned short,hkContainerHeapAllocator>)v41[v40].m_scale;
        hkVector4f::setTransformedPos(&b, (hkQsTransformf *)&other, &b);
        hkVector4f::setTransformedPos(&v73, (hkQsTransformf *)&other, &v73);
        hkVector4f::setTransformedPos(&v72, (hkQsTransformf *)&other, &v72);
        v39 = v72.m_quad;
        v38 = v73.m_quad;
        v37 = b.m_quad;
      }
      v42 = v37;
      LODWORD(v21) = v21 + 1;
      v43 = _mm_max_ps(_mm_max_ps(v37, v38), v39);
      ++v25;
      v44 = v69-- == 1;
      v78 = v21;
      v45 = _mm_min_ps(v6->m_bounds.m_min.m_quad, _mm_min_ps(_mm_min_ps(v42, v38), v39));
      v46 = v6->m_bounds.m_max.m_quad;
      v6->m_bounds.m_min.m_quad = v45;
      v6->m_bounds.m_max.m_quad = _mm_max_ps(v46, v43);
    }
    while ( !v44 );
    v8 = v77;
  }
  if ( v8->m_createMapping )
  {
    v47 = shapeKeyMap;
    if ( shapeKeyMap )
    {
      v48 = v11->m_geomOffset;
      v49 = v11->m_geomOffset;
      v50 = (signed int)v48 + v11->m_numTriangles;
      if ( v48 < v50 )
      {
        do
        {
          v51 = v8->m_shapeKeys.m_data[v49];
          if ( v51 != -1 && v11->m_numInstances )
          {
            v52 = v6->m_bitsPerWIndex;
            v53 = v51 & v6->m_wIndexMask;
            v54 = v51 >> v6->m_bitsPerWIndex;
            if ( v54 )
            {
              if ( v54 != (1 << (32 - v52)) - 1 )
                v51 = v53 | ((v68 + v54 - v11->m_chunkOffset) << v52);
            }
            else
            {
              v51 = v65 + v53 - v11->m_bigOffset;
            }
          }
          if ( v47->m_size == (v47->m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v47, 4);
            v8 = v77;
          }
          ++v49;
          v47->m_data[v47->m_size++] = v51;
        }
        while ( v49 < v50 );
      }
    }
  }
  v55 = v8->subparts.m_data;
  v56 = v67;
  v57 = v55[(unsigned __int64)v67 / 0x24].m_convexOffset;
  v79 = v57 + v55[(unsigned __int64)v67 / 0x24].m_numConvexPieces;
  if ( (signed int)v57 < v79 )
  {
    v58 = &v6->m_convexPieces;
    v59 = v57;
    do
    {
      v60 = v57;
      if ( *(int *)((char *)&v8->subparts.m_data->m_numInstances + v56) )
      {
        v60 = v6->m_convexPieces.m_size;
        if ( v6->m_convexPieces.m_size == (v6->m_convexPieces.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &v6->m_convexPieces,
            48);
        v61 = (signed __int64)&v58->m_data[v6->m_convexPieces.m_size];
        if ( v61 )
        {
          *(_DWORD *)(v61 + 28) = 2147483648;
          *(_QWORD *)(v61 + 16) = 0i64;
          *(_DWORD *)(v61 + 24) = 0;
          *(_OWORD *)v61 = 0i64;
          v62 = *(_DWORD *)(v61 + 28) & 0x3FFFFFFF;
          if ( (*(_DWORD *)(v61 + 28) & 0x3FFFFFFF) < 0 )
          {
            if ( *(_DWORD *)(v61 + 28) >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                *(void **)(v61 + 16),
                2 * v62);
            v78 = 0;
            *(_QWORD *)(v61 + 16) = ((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, int *, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
                                      &hkContainerHeapAllocator::s_alloc,
                                      &v78,
                                      v62);
            *(_DWORD *)(v61 + 28) = v78 / 2;
          }
          *(_DWORD *)(v61 + 24) = 0;
          *(_WORD *)(v61 + 32) = v57;
          *(_WORD *)(v61 + 34) = v64;
        }
        ++v6->m_convexPieces.m_size;
      }
      else
      {
        v58->m_data[v59].m_transformIndex = v64;
      }
      hkpCompressedMeshShape::getConvexPieceAabb(v6, &v58->m_data[v60], &bounds);
      v8 = v77;
      v56 = v67;
      v63 = _mm_max_ps(v6->m_bounds.m_max.m_quad, bounds.m_max.m_quad);
      LODWORD(v57) = v57 + 1;
      ++v59;
      v6->m_bounds.m_min.m_quad = _mm_min_ps(v6->m_bounds.m_min.m_quad, bounds.m_min.m_quad);
      v6->m_bounds.m_max.m_quad = v63;
    }
    while ( (signed int)v57 < v79 );
    v11 = v71;
  }
  ++v11->m_numInstances;
}

// File Line: 344
// RVA: 0x13223A0
hkpCompressedMeshShape *__fastcall hkpCompressedMeshShapeBuilder::createMeshFromGeometry(hkGeometry *geometry, float quantizationError, hkpCompressedMeshShape::MaterialType materialType)
{
  hkGeometry *v3; // rdi
  hkpCompressedMeshShape::MaterialType v4; // ebx
  hkpCompressedMeshShape *v5; // rsi
  int v6; // ebx
  hkpCompressedMeshShapeBuilder v8; // [rsp+30h] [rbp-148h]

  v3 = geometry;
  v4 = materialType;
  hkpCompressedMeshShapeBuilder::hkpCompressedMeshShapeBuilder(&v8);
  v5 = hkpCompressedMeshShapeBuilder::createMeshShape(&v8, quantizationError, v4, 17);
  v6 = hkpCompressedMeshShapeBuilder::beginSubpart(&v8, v5);
  hkpCompressedMeshShapeBuilder::addGeometry(&v8, v3, (hkMatrix4f *)&transform, v5);
  hkpCompressedMeshShapeBuilder::endSubpart(&v8, v5);
  hkpCompressedMeshShapeBuilder::addInstance(&v8, v6, (hkMatrix4f *)&transform, v5, 0i64);
  hkpCompressedMeshShapeBuilder::~hkpCompressedMeshShapeBuilder(&v8);
  return v5;
}

// File Line: 358
// RVA: 0x13246B0
void __fastcall hkpCompressedMeshShapeBuilder::appendGeometry(hkpCompressedMeshShapeBuilder *this, hkGeometry *dest, hkGeometry *geom)
{
  signed __int64 v3; // rbx
  int v4; // esi
  hkGeometry *v5; // rbp
  hkGeometry *v6; // r14
  signed __int64 v7; // rax

  v3 = dest->m_triangles.m_size;
  v4 = dest->m_vertices.m_size;
  v5 = dest;
  v6 = geom;
  hkArrayBase<hkGeometry::Triangle>::_append(
    (hkArrayBase<hkGeometry::Triangle> *)&dest->m_triangles.m_data,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    geom->m_triangles.m_data,
    geom->m_triangles.m_size);
  if ( (signed int)v3 < v5->m_triangles.m_size )
  {
    v7 = v3;
    do
    {
      LODWORD(v3) = v3 + 1;
      ++v7;
      v5->m_triangles.m_data[v7 - 1].m_a += v4;
      *((_DWORD *)&v5->m_triangles.m_data[v7] - 3) += v4;
      *((_DWORD *)&v5->m_triangles.m_data[v7] - 2) += v4;
    }
    while ( (signed int)v3 < v5->m_triangles.m_size );
  }
  hkArrayBase<hkVector4f>::_append(
    (hkArrayBase<hkVector4f> *)&v5->m_vertices.m_data,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    v6->m_vertices.m_data,
    v6->m_vertices.m_size);
}

// File Line: 372
// RVA: 0x1325FB0
char __fastcall hasDifferentMaterials(hkGeometry *geometry)
{
  hkGeometry::Triangle *v1; // r9
  signed __int64 v2; // rdx
  signed __int64 v3; // rax
  int *v4; // rcx

  v1 = geometry->m_triangles.m_data;
  v2 = geometry->m_triangles.m_size;
  v3 = 1i64;
  if ( v2 <= 1 )
    return 0;
  v4 = &v1[1].m_material;
  while ( *v4 == v1->m_material )
  {
    ++v3;
    v4 += 4;
    if ( v3 >= v2 )
      return 0;
  }
  return 1;
}

// File Line: 386
// RVA: 0x1324900
void __fastcall hkpCompressedMeshShapeBuilder::addChunk(hkpCompressedMeshShapeBuilder *this, hkGeometry *geometry, hkArray<hkpCompressedMeshShape::Chunk,hkContainerHeapAllocator> *chunks, hkpCompressedMeshShapeBuilder::MappingTree *mapping)
{
  hkGeometry *v4; // rbx
  hkpCompressedMeshShapeBuilder *v5; // rsi
  hkpCompressedMeshShapeBuilder::MappingTree *v6; // rdi
  bool v7; // zf
  bool v8; // sf
  unsigned __int8 v9; // of
  hkVector4f v10; // xmm6
  __m128i v11; // xmm3
  __m128 v12; // xmm3
  __int64 v13; // rcx
  int v14; // ebx
  hkArray<hkpCompressedMeshShape::Chunk,hkContainerHeapAllocator> *v15; // rcx
  __int64 v16; // rax
  __int64 v17; // r11
  int v18; // er10
  int v19; // er9
  int v20; // er8
  hkpCompressedMeshShapeBuilder::MappingTree *v21; // r9
  hkpCompressedMeshShapeBuilder::MappingTree *v22; // r8
  hkpCompressedMeshShapeBuilder::MappingTree *v23; // rsi
  _QWORD **v24; // rax
  hkpCompressedMeshShapeBuilder::MappingTree *v25; // rsi
  _QWORD **v26; // rax
  __int64 half; // [rsp+28h] [rbp-C0h]
  char out2[52]; // [rsp+40h] [rbp-A8h]
  void *v29; // [rsp+78h] [rbp-70h]
  int v30; // [rsp+80h] [rbp-68h]
  int v31; // [rsp+84h] [rbp-64h]
  void *v32; // [rsp+88h] [rbp-60h]
  int v33; // [rsp+90h] [rbp-58h]
  int v34; // [rsp+94h] [rbp-54h]
  __int64 v35; // [rsp+98h] [rbp-50h]
  int v36; // [rsp+A0h] [rbp-48h]
  int v37; // [rsp+A4h] [rbp-44h]
  __int64 v38; // [rsp+A8h] [rbp-40h]
  int v39; // [rsp+B0h] [rbp-38h]
  int v40; // [rsp+B4h] [rbp-34h]
  int v41; // [rsp+B8h] [rbp-30h]
  int v42; // [rsp+BCh] [rbp-2Ch]
  float v43[4]; // [rsp+C8h] [rbp-20h]
  hkAabb aabbOut; // [rsp+D8h] [rbp-10h]
  hkGeometry *source; // [rsp+130h] [rbp+48h]
  hkArray<hkpCompressedMeshShape::Chunk,hkContainerHeapAllocator> *retaddr; // [rsp+138h] [rbp+50h]

  v4 = geometry;
  v5 = this;
  v6 = mapping;
  hkAabbUtil::calcAabb(geometry->m_vertices.m_data, geometry->m_vertices.m_size, (hkAabb *)((char *)&aabbOut + 24));
  v9 = __OFSUB__(v4->m_vertices.m_size, 255);
  v7 = v4->m_vertices.m_size == 255;
  v8 = v4->m_vertices.m_size - 255 < 0;
  v10.m_quad = (__m128)aabbOut.m_max;
  v11 = (__m128i)_mm_sub_ps(aabbOut.m_max.m_quad, aabbOut.m_min.m_quad);
  *(__m128i *)v43 = v11;
  v12 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v11, 1u), 1u);
  v13 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                               _mm_and_ps(
                                                                 _mm_cmpleps(
                                                                   _mm_max_ps(
                                                                     _mm_shuffle_ps(v12, v12, 170),
                                                                     _mm_max_ps(
                                                                       _mm_shuffle_ps(v12, v12, 85),
                                                                       _mm_shuffle_ps(v12, v12, 0))),
                                                                   v12),
                                                                 (__m128)xmmword_141C20A50))];
  *(_DWORD *)&out2[48] = v13;
  if ( (unsigned __int8)(v8 ^ v9) | v7 && (float)(v5->m_error * 65534.0) >= v43[v13] )
  {
    if ( v5->m_mesh->m_materialType.m_storage != 1 || !hasDifferentMaterials(v4) )
    {
      v14 = 0;
      *(_OWORD *)&out2[40] = 0i64;
      v29 = 0i64;
      v30 = 0;
      v31 = 2147483648;
      v32 = 0i64;
      v33 = 0;
      v34 = 2147483648;
      v35 = 0i64;
      v36 = 0;
      v37 = 2147483648;
      v38 = 0i64;
      v39 = 0;
      v40 = 2147483648;
      v42 = -1;
      v41 = 0;
      hkpCompressedMeshShapeBuilder::createChunk(
        v5,
        source,
        &aabbOut.m_min,
        (hkpCompressedMeshShape::Chunk *)&out2[40],
        v6);
      v15 = retaddr;
      if ( retaddr->m_size == (retaddr->m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, retaddr, 96);
        v15 = retaddr;
      }
      v16 = v15->m_size;
      if ( &v15->m_data[v16] )
      {
        hkpCompressedMeshShape::Chunk::Chunk(&v15->m_data[v16], (hkpCompressedMeshShape::Chunk *)&out2[40]);
        v15 = retaddr;
      }
      ++v15->m_size;
      if ( v6 && v6->m_triangles.m_size > 0 )
      {
        v17 = 0i64;
        do
        {
          ++v14;
          v18 = v6->m_triangles.m_data[v17].m_winding;
          v19 = v6->m_triangles.m_data[v17].m_triangleIndex;
          v20 = v15->m_size - 1;
          v6->m_triangles.m_data[v17].m_chunkIndex = v20;
          ++v17;
          v15 = retaddr;
          *((_DWORD *)&v6->m_triangles.m_data[v17] - 1) = v19 & v5->m_mesh->m_wIndexMask | ((v20 + 1) << v5->m_mesh->m_bitsPerWIndex) | ((v18 & 1) << v5->m_mesh->m_bitsPerIndex);
        }
        while ( v14 < v6->m_triangles.m_size );
      }
      hkpCompressedMeshShape::Chunk::~Chunk((hkpCompressedMeshShape::Chunk *)&out2[40]);
      return;
    }
    LODWORD(v13) = *(_DWORD *)&out2[48];
  }
  *(_QWORD *)&out2[40] = &hkGeometry::`vftable';
  *(_QWORD *)out2 = &hkGeometry::`vftable';
  *(__m128 *)v43 = _mm_mul_ps(_mm_add_ps(v10.m_quad, aabbOut.m_min.m_quad), (__m128)xmmword_141A711B0);
  *(float *)&half = v43[(signed int)v13];
  v29 = 0i64;
  v30 = 0;
  v31 = 2147483648;
  v32 = 0i64;
  v33 = 0;
  v34 = 2147483648;
  *(_DWORD *)&out2[8] = 0x1FFFF;
  *(_QWORD *)&out2[16] = 0i64;
  *(_DWORD *)&out2[24] = 0;
  *(_DWORD *)&out2[28] = 2147483648;
  *(_QWORD *)&out2[32] = 0i64;
  *(_DWORD *)&out2[40] = 0;
  *(_QWORD *)&out2[44] = 562947805937664i64;
  hkpCompressedMeshShapeBuilder::splitGeometry(v5, source, (hkGeometry *)&out2[40], (hkGeometry *)out2, v13, half, v6);
  if ( v33 )
  {
    if ( *(_DWORD *)&out2[40] )
    {
      if ( v6 )
      {
        hkpCompressedMeshShapeBuilder::addChunk(v5, (hkGeometry *)&out2[40], retaddr, v6->m_left);
        v21 = v6->m_right;
      }
      else
      {
        hkpCompressedMeshShapeBuilder::addChunk(v5, (hkGeometry *)&out2[40], retaddr, 0i64);
        v21 = 0i64;
      }
      hkpCompressedMeshShapeBuilder::addChunk(v5, (hkGeometry *)out2, retaddr, v21);
      goto LABEL_33;
    }
    hkpCompressedMeshShapeBuilder::appendGeometry(v5, &v5->m_leftOver, (hkGeometry *)&out2[40]);
    if ( v6 )
    {
      v22 = v6->m_left;
LABEL_26:
      hkArrayBase<hkpCompressedMeshShapeBuilder::TriangleMapping>::_append(
        (hkArrayBase<hkpCompressedMeshShapeBuilder::TriangleMapping> *)&v5->m_bigMapping.m_data,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        v22->m_triangles.m_data,
        v22->m_triangles.m_size);
LABEL_27:
      if ( v6 )
      {
        v23 = v6->m_left;
        if ( v23 )
        {
          hkpCompressedMeshShapeBuilder::MappingTree::~MappingTree(v6->m_left);
          v24 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          (*(void (__fastcall **)(_QWORD *, hkpCompressedMeshShapeBuilder::MappingTree *, signed __int64))(*v24[11] + 16i64))(
            v24[11],
            v23,
            32i64);
        }
        v25 = v6->m_right;
        v6->m_left = 0i64;
        if ( v25 )
        {
          hkpCompressedMeshShapeBuilder::MappingTree::~MappingTree(v25);
          v26 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          (*(void (__fastcall **)(_QWORD *, hkpCompressedMeshShapeBuilder::MappingTree *, signed __int64))(*v26[11] + 16i64))(
            v26[11],
            v25,
            32i64);
        }
        v6->m_right = 0i64;
      }
      goto LABEL_33;
    }
  }
  else
  {
    if ( !*(_DWORD *)&out2[40] )
      goto LABEL_27;
    hkpCompressedMeshShapeBuilder::appendGeometry(v5, &v5->m_leftOver, (hkGeometry *)out2);
    if ( v6 )
    {
      v22 = v6->m_right;
      goto LABEL_26;
    }
  }
LABEL_33:
  *(_DWORD *)&out2[40] = 0;
  if ( *(_DWORD *)&out2[44] >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)&out2[32],
      16 * *(_DWORD *)&out2[44]);
  *(_QWORD *)&out2[32] = 0i64;
  *(_DWORD *)&out2[44] = 2147483648;
  *(_DWORD *)&out2[24] = 0;
  if ( *(_DWORD *)&out2[28] >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)&out2[16],
      16 * *(_DWORD *)&out2[28]);
  *(_QWORD *)&out2[16] = 0i64;
  *(_DWORD *)&out2[28] = 2147483648;
  *(_QWORD *)out2 = &hkBaseObject::`vftable';
  v33 = 0;
  if ( v34 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v32,
      16 * v34);
  v32 = 0i64;
  v34 = 2147483648;
  v30 = 0;
  if ( v31 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v29,
      16 * v31);
}

// File Line: 475
// RVA: 0x1324640
void __fastcall hkpCompressedMeshShapeBuilder::snapToGrid(hkVector4f *v, float error)
{
  __m128 v2; // xmm4
  __m128 v3; // xmm1
  hkVector4f v4; // xmm3
  __m128 v5; // xmm0
  __m128 v6; // xmm2

  v2 = _mm_shuffle_ps((__m128)LODWORD(error), (__m128)LODWORD(error), 0);
  v3 = _mm_rcp_ps(v2);
  v4.m_quad = _mm_mul_ps(v->m_quad, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v3, v2)), v3));
  *v = (hkVector4f)v4.m_quad;
  v5 = _mm_add_ps(v4.m_quad, (__m128)xmmword_141A711B0);
  v6 = _mm_mul_ps(
         _mm_cvtepi32_ps(
           _mm_xor_si128(
             (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v5),
             _mm_cvttps_epi32(v5))),
         v2);
  v->m_quad = _mm_shuffle_ps(v6, _mm_unpackhi_ps(v6, v4.m_quad), 196);
}

// File Line: 524
// RVA: 0x1325EB0
void __fastcall hkpCompressedMeshShapeBuilder::addMaterial(hkpCompressedMeshShapeBuilder *this, hkpCompressedMeshShape::Chunk *chunk, const int material)
{
  hkpCompressedMeshShape *v3; // rbx
  int v4; // edi
  char v5; // al

  v3 = this->m_mesh;
  v4 = material;
  v5 = v3->m_materialType.m_storage;
  switch ( v5 )
  {
    case 4:
      if ( v3->m_materials.m_size == (v3->m_materials.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_materials, 4);
      v3->m_materials.m_data[v3->m_materials.m_size++] = v4;
      break;
    case 3:
      if ( v3->m_materials16.m_size == (v3->m_materials16.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_materials16, 2);
      v3->m_materials16.m_data[v3->m_materials16.m_size++] = v4;
      break;
    case 2:
      if ( v3->m_materials8.m_size == (v3->m_materials8.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_materials8, 1);
      v3->m_materials8.m_data[v3->m_materials8.m_size++] = v4;
      break;
    default:
      if ( chunk->m_materialInfo == -1 && v5 == 1 )
        chunk->m_materialInfo = material;
      break;
  }
}

// File Line: 546
// RVA: 0x1324760
void __fastcall hkpCompressedMeshShapeBuilder::quantizeVertices(float quantization, hkVector4f *offset, hkArray<hkVector4f,hkContainerHeapAllocator> *verticesIn, hkArray<unsigned short,hkContainerHeapAllocator> *verticesOut)
{
  __int64 v4; // rsi
  int v5; // edi
  int v6; // eax
  hkArray<unsigned short,hkContainerHeapAllocator> *v7; // rbx
  hkArray<hkVector4f,hkContainerHeapAllocator> *v8; // r14
  hkVector4f *v9; // rbp
  int v10; // eax
  int v11; // er9
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r9
  __m128 v15; // xmm2
  signed __int64 v16; // rdx
  float v17; // xmm0_4
  __m128 v18; // [rsp+30h] [rbp-28h]
  hkResult result; // [rsp+70h] [rbp+18h]

  v4 = verticesIn->m_size;
  v5 = 3 * v4;
  v6 = verticesOut->m_capacityAndFlags & 0x3FFFFFFF;
  v7 = verticesOut;
  v8 = verticesIn;
  v9 = offset;
  if ( v6 < 3 * (signed int)v4 )
  {
    v10 = 2 * v6;
    v11 = 3 * v4;
    if ( v5 < v10 )
      v11 = v10;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, v11, 2);
  }
  v7->m_size = v5;
  v12 = v4;
  if ( (signed int)v4 > 0 )
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
      v18 = _mm_mul_ps(_mm_sub_ps(v8->m_data[v14].m_quad, v9->m_quad), v15);
      do
      {
        v17 = v18.m128_f32[v16++];
        ++v13;
        v7->m_data[v13 - 1] = (signed int)(float)(v17 + 0.5);
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
void __fastcall hkpCompressedMeshShapeBuilder::createChunk(hkpCompressedMeshShapeBuilder *this, hkGeometry *geometry, hkVector4f *offset, hkpCompressedMeshShape::Chunk *chunk, hkpCompressedMeshShapeBuilder::MappingTree *mapping)
{
  hkpCompressedMeshShape *v5; // rax
  hkGeometry *v6; // rbx
  char v7; // r10
  __int64 v8; // r15
  _DWORD *v9; // r12
  int v10; // ecx
  int v11; // edx
  int v12; // ebx
  signed __int64 v13; // r8
  int v14; // eax
  __int64 v15; // rdx
  __int64 v16; // rax
  int v17; // er11
  unsigned __int64 v18; // r9
  __int64 v19; // r10
  __int64 v20; // rdx
  __int64 v21; // rcx
  signed __int64 v22; // r8
  __int64 v23; // rcx
  int v24; // edi
  int v25; // eax
  int v26; // eax
  int v27; // er9
  __int64 v28; // rcx
  int *v29; // rdx
  __int64 v30; // r8
  int v31; // eax
  char *v32; // rdx
  __int64 v33; // rcx
  __int64 v34; // r8
  int v35; // eax
  int v36; // ecx
  hkpCompressedMeshShape::Chunk *v37; // r11
  hkGeometry *v38; // rdi
  int v39; // ebx
  int v40; // eax
  int v41; // eax
  __int64 v42; // rdx
  int v43; // er10
  int v44; // er9
  int v45; // esi
  __int64 v46; // rbx
  __int64 v47; // r8
  int v48; // er13
  hkBaseObjectVtbl *v49; // rax
  int v50; // edi
  hkArray<unsigned short,hkContainerHeapAllocator> *v51; // rbx
  signed __int64 v52; // r14
  unsigned __int16 v53; // si
  signed __int64 v54; // rdx
  __int64 v55; // rax
  signed __int64 v56; // rcx
  int v57; // er8
  int v58; // ebx
  __int64 v59; // rax
  hkpCompressedMeshShape::Chunk *v60; // r9
  __int64 v61; // r15
  signed __int64 v62; // rsi
  __int64 v63; // r14
  __int16 v64; // r13
  signed __int64 v65; // rcx
  int v66; // er8
  int v67; // er9
  __int64 v68; // rdi
  int *v69; // rbx
  int v70; // er8
  hkArray<hkArray<int,hkContainerHeapAllocator>,hkContainerHeapAllocator> strips; // [rsp+30h] [rbp-C0h]
  int *array; // [rsp+40h] [rbp-B0h]
  int v73; // [rsp+48h] [rbp-A8h]
  int v74; // [rsp+4Ch] [rbp-A4h]
  hkArray<int,hkContainerHeapAllocator> map; // [rsp+50h] [rbp-A0h]
  int v76; // [rsp+60h] [rbp-90h]
  hkArray<int,hkContainerHeapAllocator> leftOvers; // [rsp+68h] [rbp-88h]
  hkgpIndexedMesh::StripConfig config; // [rsp+78h] [rbp-78h]
  hkgpIndexedMesh v79; // [rsp+90h] [rbp-60h]
  hkpCompressedMeshShapeBuilder *vars0; // [rsp+170h] [rbp+80h]
  _QWORD *retaddr; // [rsp+178h] [rbp+88h]
  int v82; // [rsp+180h] [rbp+90h]
  hkGeometry *chunka; // [rsp+188h] [rbp+98h]
  _DWORD *result; // [rsp+190h] [rbp+A0h]
  hkpCompressedMeshShape::Chunk *v85; // [rsp+198h] [rbp+A8h]

  v85 = chunk;
  chunka = geometry;
  chunk->m_offset = (hkVector4f)offset->m_quad;
  v5 = this->m_mesh;
  v6 = geometry;
  v7 = v5->m_materialType.m_storage;
  switch ( v7 )
  {
    case 2:
      chunk->m_materialInfo = v5->m_materials8.m_size;
      break;
    case 3:
      chunk->m_materialInfo = v5->m_materials16.m_size;
      break;
    case 4:
      chunk->m_materialInfo = v5->m_materials.m_size;
      break;
    default:
      chunk->m_materialInfo = -1;
      break;
  }
  hkpCompressedMeshShapeBuilder::quantizeVertices(this->m_error, offset, &geometry->m_vertices, &chunk->m_vertices);
  hkgpIndexedMesh::hkgpIndexedMesh(&v79);
  hkgpIndexedMesh::appendFromGeometry(&v79, v6);
  v8 = 0i64;
  strips.m_data = 0i64;
  strips.m_size = 0;
  strips.m_capacityAndFlags = 2147483648;
  leftOvers.m_data = 0i64;
  leftOvers.m_size = 0;
  leftOvers.m_capacityAndFlags = 2147483648;
  map.m_data = 0i64;
  map.m_size = 0;
  map.m_capacityAndFlags = 2147483648;
  config.m_minLength = 4;
  *(_QWORD *)&config.m_maxLength = 0xFFFFi64;
  hkgpIndexedMesh::generateStrips(&v79, &strips, &leftOvers, &map, &config);
  v9 = result;
  if ( result )
  {
    v10 = map.m_size;
    v11 = 0;
    array = 0i64;
    v73 = 0;
    v74 = 2147483648;
    v12 = map.m_size;
    if ( map.m_size > 0 )
    {
      if ( map.m_size < 0 )
        v10 = 0;
      hkArrayUtil::_reserve(
        (hkResult *)&result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &array,
        v10,
        20);
      v10 = map.m_size;
      v11 = v73;
    }
    v13 = 5i64 * v11;
    v14 = v12 - v11;
    v15 = v12 - v11;
    if ( v14 > 0 )
    {
      v16 = (__int64)&array[v13 + 2];
      do
      {
        if ( v16 != 8 )
        {
          *(_DWORD *)(v16 - 8) = -1;
          *(_QWORD *)(v16 - 4) = -1i64;
          *(_QWORD *)(v16 + 4) = -1i64;
        }
        v16 += 20i64;
        --v15;
      }
      while ( v15 );
      v10 = map.m_size;
    }
    v73 = v12;
    v17 = 0;
    if ( v10 > 0 )
    {
      v18 = 0i64;
      v19 = 0i64;
      do
      {
        v20 = (__int64)array;
        ++v17;
        v21 = map.m_data[v19];
        ++v19;
        v18 += 20i64;
        v22 = 5 * v21;
        v23 = *(_QWORD *)v9;
        array[v18 / 4 - 5] = *(_DWORD *)(*(_QWORD *)v9 + 4 * v22);
        *(_DWORD *)(v18 + v20 - 16) = *(_DWORD *)(v23 + 4 * v22 + 4);
        *(_DWORD *)(v18 + v20 - 12) = *(_DWORD *)(v23 + 4 * v22 + 8);
        *(_DWORD *)(v18 + v20 - 8) = *(_DWORD *)(v23 + 4 * v22 + 12);
        *(_DWORD *)(v18 + v20 - 4) = *(_DWORD *)(v23 + 4 * v22 + 16);
      }
      while ( v17 < map.m_size );
      v12 = v73;
    }
    v24 = v12;
    if ( v12 > v9[2] )
      v24 = v9[2];
    v25 = v9[3] & 0x3FFFFFFF;
    if ( v25 < v12 )
    {
      v26 = 2 * v25;
      v27 = v12;
      if ( v12 < v26 )
        v27 = v26;
      hkArrayUtil::_reserve(
        (hkResult *)&result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        v9,
        v27,
        20);
    }
    v28 = *(_QWORD *)v9;
    if ( v24 > 0 )
    {
      v29 = array;
      v30 = v24;
      do
      {
        v31 = *v29;
        v28 += 20i64;
        v29 += 5;
        *(_DWORD *)(v28 - 20) = v31;
        *(_DWORD *)(v28 - 16) = *(v29 - 4);
        *(_DWORD *)(v28 - 12) = *(v29 - 3);
        *(_DWORD *)(v28 - 8) = *(v29 - 2);
        *(_DWORD *)(v28 - 4) = *(v29 - 1);
        --v30;
      }
      while ( v30 );
    }
    v32 = (char *)(*(_QWORD *)v9 + 20i64 * v24);
    v33 = v12 - v24;
    if ( v12 - v24 > 0 )
    {
      v34 = (char *)&array[5 * v24] - v32;
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
    v9[2] = v12;
    v73 = 0;
    if ( v35 >= 0 )
      ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, int *, _QWORD, _QWORD))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerHeapAllocator::s_alloc,
        array,
        20 * (v35 & 0x3FFFFFFFu),
        v24);
  }
  v36 = strips.m_size;
  v37 = (hkpCompressedMeshShape::Chunk *)chunka;
  v38 = chunka + 1;
  v39 = strips.m_size;
  v40 = *(_DWORD *)(&chunka[1].m_referenceCount + 1) & 0x3FFFFFFF;
  if ( v40 < strips.m_size )
  {
    v41 = 2 * v40;
    if ( strips.m_size < v41 )
      v36 = v41;
    hkArrayUtil::_reserve(
      (hkResult *)&result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &chunka[1],
      v36,
      2);
    v36 = strips.m_size;
    v37 = (hkpCompressedMeshShape::Chunk *)chunka;
  }
  v42 = 0i64;
  *(_DWORD *)&chunka[1].m_memSizeAndFlags = v39;
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
      v49 = v38->vfptr;
      v50 = 0;
      *(_WORD *)((char *)&v49->__vecDelDtor + v46) = v48;
      if ( v48 > 0 )
      {
        v51 = &v37->m_indices;
        v52 = 20 * v42;
        do
        {
          v53 = *(_WORD *)(*(char **)((char *)&strips.m_data->m_data + v47) + v8);
          if ( v51->m_size == (v51->m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v51, 2);
            v42 = *(_QWORD *)&config.m_minLength;
            v44 = v82;
            v43 = (signed int)result;
            v37 = (hkpCompressedMeshShape::Chunk *)chunka;
          }
          v51->m_data[v51->m_size++] = v53;
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
          v43 = (signed int)result;
          v37 = (hkpCompressedMeshShape::Chunk *)chunka;
          ++v50;
          v8 += 4i64;
        }
        while ( v50 < v48 );
        v46 = (__int64)array;
        v45 = v76;
        v8 = 0i64;
      }
      v36 = strips.m_size;
      v37 = (hkpCompressedMeshShape::Chunk *)chunka;
      ++v45;
      v43 += v48;
      v46 += 2i64;
      v47 += 16i64;
      v38 = chunka + 1;
      v76 = v45;
      LODWORD(result) = v43;
      array = (int *)v46;
      *(_QWORD *)&leftOvers.m_size = v47;
    }
    while ( v45 < strips.m_size );
  }
  v58 = 0;
  v59 = v44;
  if ( leftOvers.m_size > 0 )
  {
    v60 = (hkpCompressedMeshShape::Chunk *)chunka;
    v61 = v59;
    v62 = 20 * v59;
    v63 = 0i64;
    do
    {
      v64 = leftOvers.m_data[v63];
      if ( chunka->m_triangles.m_size == (chunka->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &chunka->m_triangles,
          2);
        v43 = (signed int)result;
        v60 = (hkpCompressedMeshShape::Chunk *)chunka;
      }
      *((_WORD *)&chunka->m_triangles.m_data->m_a + chunka->m_triangles.m_size++) = v64;
      if ( v58 == 3 * (v58 / 3) )
      {
        if ( v9 )
          *(_DWORD *)(*(_QWORD *)v9 + v62 + 4) = v58 + v43;
        v62 += 20i64;
        v65 = 2i64 * map.m_data[v61];
        ++v61;
        v66 = *(_DWORD *)(retaddr[4] + 8 * v65 + 12);
      }
      else
      {
        v66 = -1;
      }
      hkpCompressedMeshShapeBuilder::addMaterial(vars0, v60, v66);
      v43 = (signed int)result;
      v60 = (hkpCompressedMeshShape::Chunk *)chunka;
      ++v58;
      ++v63;
    }
    while ( v58 < leftOvers.m_size );
    v36 = strips.m_size;
    LODWORD(v8) = 0;
  }
  v67 = chunka->m_triangles.m_size;
  if ( v67 < (chunka->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reduce(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &chunka->m_triangles,
      2,
      0i64,
      v67);
    v36 = strips.m_size;
  }
  map.m_size = v8;
  if ( map.m_capacityAndFlags >= 0 )
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      map.m_data,
      4 * map.m_capacityAndFlags);
    v36 = strips.m_size;
  }
  map.m_data = 0i64;
  map.m_capacityAndFlags = 2147483648;
  leftOvers.m_size = 0;
  if ( leftOvers.m_capacityAndFlags >= 0 )
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      leftOvers.m_data,
      4 * leftOvers.m_capacityAndFlags);
    v36 = strips.m_size;
  }
  leftOvers.m_data = 0i64;
  leftOvers.m_capacityAndFlags = 2147483648;
  v68 = v36 - 1;
  if ( v36 - 1 >= 0 )
  {
    v69 = &strips.m_data->m_capacityAndFlags + 4 * (v36 - 1);
    do
    {
      v70 = *v69;
      *(v69 - 1) = v8;
      if ( v70 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v69 - 3),
          4 * v70);
      *(_QWORD *)(v69 - 3) = 0i64;
      *v69 = 2147483648;
      v69 -= 4;
      --v68;
    }
    while ( v68 >= 0 );
  }
  strips.m_size = v8;
  if ( strips.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      strips.m_data,
      16 * strips.m_capacityAndFlags);
  strips.m_data = 0i64;
  strips.m_capacityAndFlags = 2147483648;
  hkgpIndexedMesh::~hkgpIndexedMesh(&v79);
}

// File Line: 678
// RVA: 0x13255B0
char __fastcall hkpCompressedMeshShapeBuilder::splitCriterion(hkpCompressedMeshShapeBuilder *this, hkVector4f *v1, hkVector4f *v2, hkVector4f *v3, float half, int dir)
{
  float v6; // xmm1_4
  float v7; // xmm3_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm3_4

  v6 = v1->m_quad.m128_f32[dir];
  v7 = v2->m_quad.m128_f32[dir];
  v8 = v1->m_quad.m128_f32[dir];
  if ( v7 < v8 )
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
      return -1;
    if ( v10 > this->m_statistics.m_maxOverlap )
      this->m_statistics.m_maxOverlap = v10;
  }
  return half > (float)((float)(v6 + v8) * 0.5);
}

// File Line: 711
// RVA: 0x1325FF0
void __fastcall addTriangle(int a, int b, int c, int material, hkVector4f *vertexA, hkVector4f *vertexB, hkVector4f *vertexC, hkGeometry *geom, hkArray<int,hkContainerHeapAllocator> *vertexIndex)
{
  __int64 v9; // r12
  int v10; // er13
  __int64 v11; // rbp
  __int64 v12; // rsi
  __int64 v13; // r15
  __int64 v14; // rsi
  int v15; // ebp
  int v16; // er14
  int v17; // esi
  hkGeometry::Triangle *v18; // rax

  v9 = a;
  v10 = material;
  v11 = c;
  v12 = b;
  if ( vertexIndex->m_data[v9] == -1 )
  {
    vertexIndex->m_data[v9] = geom->m_vertices.m_size;
    if ( geom->m_vertices.m_size == (geom->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &geom->m_vertices, 16);
    geom->m_vertices.m_data[geom->m_vertices.m_size++] = (hkVector4f)vertexA->m_quad;
  }
  v13 = v12;
  if ( vertexIndex->m_data[v12] == -1 )
  {
    vertexIndex->m_data[v13] = geom->m_vertices.m_size;
    if ( geom->m_vertices.m_size == (geom->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &geom->m_vertices, 16);
    geom->m_vertices.m_data[geom->m_vertices.m_size++] = (hkVector4f)vertexB->m_quad;
  }
  v14 = v11;
  if ( vertexIndex->m_data[v11] == -1 )
  {
    vertexIndex->m_data[v14] = geom->m_vertices.m_size;
    if ( geom->m_vertices.m_size == (geom->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &geom->m_vertices, 16);
    geom->m_vertices.m_data[geom->m_vertices.m_size++] = (hkVector4f)vertexC->m_quad;
  }
  v15 = vertexIndex->m_data[v9];
  v16 = vertexIndex->m_data[v13];
  v17 = vertexIndex->m_data[v14];
  if ( geom->m_triangles.m_size == (geom->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &geom->m_triangles, 16);
  v18 = &geom->m_triangles.m_data[geom->m_triangles.m_size];
  v18->m_a = v15;
  v18->m_b = v16;
  v18->m_c = v17;
  v18->m_material = v10;
  ++geom->m_triangles.m_size;
}

// File Line: 739
// RVA: 0x1323A80
void __fastcall hkpCompressedMeshShapeBuilder::splitGeometry(hkpCompressedMeshShapeBuilder *this, hkGeometry *source, hkGeometry *out1, hkGeometry *out2)
{
  hkGeometry *v4; // rsi
  hkpCompressedMeshShapeBuilder *v5; // rbp
  hkGeometry *v6; // rdi
  hkGeometry *v7; // rbx
  __m128 v8; // xmm3
  __int64 dir; // rdx
  __int64 half; // [rsp+28h] [rbp-50h]
  float v11[4]; // [rsp+40h] [rbp-38h]
  hkAabb aabbOut; // [rsp+50h] [rbp-28h]

  v4 = source;
  v5 = this;
  v6 = out1;
  v7 = out2;
  hkAabbUtil::calcAabb(source->m_vertices.m_data, source->m_vertices.m_size, &aabbOut);
  v8 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(aabbOut.m_max.m_quad, aabbOut.m_min.m_quad), 1u), 1u);
  *(__m128 *)v11 = _mm_mul_ps(_mm_add_ps(aabbOut.m_max.m_quad, aabbOut.m_min.m_quad), (__m128)xmmword_141A711B0);
  dir = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                               _mm_and_ps(
                                                                 _mm_cmpleps(
                                                                   _mm_max_ps(
                                                                     _mm_shuffle_ps(v8, v8, 170),
                                                                     _mm_max_ps(
                                                                       _mm_shuffle_ps(v8, v8, 85),
                                                                       _mm_shuffle_ps(v8, v8, 0))),
                                                                   v8),
                                                                 (__m128)xmmword_141C20A50))];
  *(float *)&half = v11[dir];
  hkpCompressedMeshShapeBuilder::splitGeometry(v5, v4, v6, v7, dir, half, 0i64);
}

// File Line: 759
// RVA: 0x13235E0
void __fastcall hkpCompressedMeshShapeBuilder::splitGeometry(hkpCompressedMeshShapeBuilder *this, hkGeometry *source, hkGeometry *out1, hkGeometry *out2, int dir, __int64 half, hkpCompressedMeshShapeBuilder::MappingTree *mapping)
{
  __int64 v7; // rbx
  hkGeometry *v8; // r14
  int v9; // er9
  int v10; // er9
  __int64 v11; // rcx
  __int64 *v12; // r15
  _DWORD *v13; // rdi
  _DWORD *v14; // rbx
  _QWORD **v15; // rax
  __int64 v16; // rax
  _QWORD **v17; // rax
  __int64 v18; // rax
  __int64 v19; // rsi
  __int64 v20; // r9
  hkGeometry::Triangle *v21; // rax
  __int64 v22; // rcx
  __int64 v23; // rdx
  __int64 v24; // r8
  hkVector4f *v25; // rax
  hkVector4f *v26; // r14
  hkVector4f *v27; // r12
  hkVector4f *vertexC; // r13
  int v29; // eax
  hkpCompressedMeshShapeBuilder::TriangleMapping *map; // rax
  __int64 v31; // r14
  _DWORD *v32; // rdx
  __int64 v33; // r14
  _DWORD *v34; // rdx
  int v35; // [rsp+48h] [rbp-51h]
  int c; // [rsp+4Ch] [rbp-4Dh]
  int b; // [rsp+50h] [rbp-49h]
  hkResult result; // [rsp+54h] [rbp-45h]
  __int64 v39; // [rsp+58h] [rbp-41h]
  hkArray<int,hkContainerHeapAllocator> vertexIndex; // [rsp+60h] [rbp-39h]
  _DWORD *array; // [rsp+70h] [rbp-29h]
  int v42; // [rsp+78h] [rbp-21h]
  int v43; // [rsp+7Ch] [rbp-1Dh]
  hkpCompressedMeshShapeBuilder *retaddr; // [rsp+E8h] [rbp+4Fh]
  hkpCompressedMeshShapeBuilder *v45; // [rsp+F0h] [rbp+57h]
  hkGeometry *geom; // [rsp+F8h] [rbp+5Fh]
  hkGeometry *v47; // [rsp+100h] [rbp+67h]
  hkGeometry *v48; // [rsp+108h] [rbp+6Fh]
  int halfa; // [rsp+118h] [rbp+7Fh]

  v48 = out2;
  v47 = out1;
  geom = source;
  v45 = this;
  v7 = source->m_vertices.m_size;
  v8 = source;
  v43 = 2147483648;
  array = 0i64;
  v42 = 0;
  vertexIndex.m_data = 0i64;
  vertexIndex.m_size = 0;
  vertexIndex.m_capacityAndFlags = 2147483648;
  if ( (signed int)v7 > 0 )
  {
    v9 = v7;
    if ( (signed int)v7 < 0 )
      v9 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v9, 4);
  }
  v42 = v7;
  if ( (vertexIndex.m_capacityAndFlags & 0x3FFFFFFF) < (signed int)v7 )
  {
    v10 = v7;
    if ( (signed int)v7 < 2 * (vertexIndex.m_capacityAndFlags & 0x3FFFFFFF) )
      v10 = 2 * (vertexIndex.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &vertexIndex, v10, 4);
  }
  vertexIndex.m_size = v7;
  v11 = 0i64;
  if ( (signed int)v7 > 0 )
  {
    do
    {
      array[++v11 - 1] = -1;
      vertexIndex.m_data[v11 - 1] = -1;
    }
    while ( v11 < v7 );
  }
  v12 = (__int64 *)half;
  v13 = 0i64;
  v14 = 0i64;
  if ( half )
  {
    v15 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v16 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v15[11] + 8i64))(v15[11], 32i64);
    v13 = (_DWORD *)v16;
    if ( v16 )
    {
      *(_QWORD *)v16 = 0i64;
      *(_DWORD *)(v16 + 8) = 0;
      *(_DWORD *)(v16 + 12) = 2147483648;
      *(_QWORD *)(v16 + 16) = 0i64;
      *(_QWORD *)(v16 + 24) = 0i64;
    }
    else
    {
      v13 = 0i64;
    }
    v17 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v18 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v17[11] + 8i64))(v17[11], 32i64);
    v14 = (_DWORD *)v18;
    if ( v18 )
    {
      *(_QWORD *)v18 = 0i64;
      *(_DWORD *)(v18 + 8) = 0;
      *(_DWORD *)(v18 + 12) = 2147483648;
      *(_QWORD *)(v18 + 16) = 0i64;
      *(_QWORD *)(v18 + 24) = 0i64;
    }
    else
    {
      v14 = 0i64;
    }
    *(_QWORD *)(half + 16) = v13;
    *(_QWORD *)(half + 24) = v14;
  }
  v35 = 0;
  if ( v8->m_triangles.m_size > 0 )
  {
    v19 = 0i64;
    v20 = 0i64;
    v39 = 0i64;
    do
    {
      v21 = v8->m_triangles.m_data;
      v22 = *(int *)((char *)&v21->m_a + v20);
      v23 = *(int *)((char *)&v21->m_b + v20);
      v24 = *(int *)((char *)&v21->m_c + v20);
      halfa = *(int *)((char *)&v21->m_material + v20);
      v25 = v8->m_vertices.m_data;
      result.m_enum = (signed int)v22;
      b = v23;
      c = v24;
      v26 = &v25[v22];
      v27 = &v25[v23];
      vertexC = &v25[v24];
      v29 = hkpCompressedMeshShapeBuilder::splitCriterion(retaddr, v26, &v25[v23], vertexC, *(float *)&dir, (int)v48);
      switch ( v29 )
      {
        case -1:
          map = 0i64;
          if ( v12 )
            map = (hkpCompressedMeshShapeBuilder::TriangleMapping *)(*v12 + 20i64 * v35);
          hkpCompressedMeshShapeBuilder::addLeftOverTriangle(retaddr, v26, v27, vertexC, halfa, map);
          break;
        case 1:
          addTriangle(
            result.m_enum,
            b,
            c,
            halfa,
            v26,
            v27,
            vertexC,
            geom,
            (hkArray<int,hkContainerHeapAllocator> *)&array);
          if ( v13 )
          {
            v31 = *v12;
            if ( v13[2] == (v13[3] & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v13, 20);
            v32 = (_DWORD *)(*(_QWORD *)v13 + 20i64 * (signed int)v13[2]);
            if ( v32 )
            {
              *v32 = *(_DWORD *)(v19 + v31);
              v32[1] = *(_DWORD *)(v19 + v31 + 4);
              v32[2] = *(_DWORD *)(v19 + v31 + 8);
              v32[3] = *(_DWORD *)(v19 + v31 + 12);
              v32[4] = *(_DWORD *)(v19 + v31 + 16);
            }
            ++v13[2];
          }
          break;
        case 0:
          addTriangle(result.m_enum, b, c, halfa, v26, v27, vertexC, v47, &vertexIndex);
          if ( v14 )
          {
            v33 = *v12;
            if ( v14[2] == (v14[3] & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v14, 20);
            v34 = (_DWORD *)(*(_QWORD *)v14 + 20i64 * (signed int)v14[2]);
            if ( v34 )
            {
              *v34 = *(_DWORD *)(v19 + v33);
              v34[1] = *(_DWORD *)(v19 + v33 + 4);
              v34[2] = *(_DWORD *)(v19 + v33 + 8);
              v34[3] = *(_DWORD *)(v19 + v33 + 12);
              v34[4] = *(_DWORD *)(v19 + v33 + 16);
            }
            ++v14[2];
          }
          break;
      }
      v8 = (hkGeometry *)v45;
      v20 = v39 + 16;
      v19 += 20i64;
      ++v35;
      v39 += 16i64;
    }
    while ( v35 < SLODWORD(v45->m_leftOver.m_vertices.m_data) );
  }
  if ( v12 )
    *((_DWORD *)v12 + 2) = 0;
  vertexIndex.m_size = 0;
  if ( vertexIndex.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      vertexIndex.m_data,
      4 * vertexIndex.m_capacityAndFlags);
  vertexIndex.m_data = 0i64;
  v42 = 0;
  vertexIndex.m_capacityAndFlags = 2147483648;
  if ( v43 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      4 * v43);
}

// File Line: 834
// RVA: 0x13261A0
__int64 __fastcall addVertex(hkGeometry *geometry, hkVector4f *vertex)
{
  __int64 v2; // r11
  unsigned int v3; // er10
  hkVector4f *v4; // rsi
  hkGeometry *v5; // rdi
  __int64 v6; // r8
  hkVector4f *v7; // r9
  __int64 result; // rax

  v2 = geometry->m_vertices.m_size;
  v3 = 0;
  v4 = vertex;
  v5 = geometry;
  v6 = 0i64;
  if ( v2 <= 0 )
  {
LABEL_5:
    if ( geometry->m_vertices.m_size == (geometry->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &geometry->m_vertices,
        16);
    v5->m_vertices.m_data[v5->m_vertices.m_size++] = (hkVector4f)v4->m_quad;
    result = (unsigned int)(v5->m_vertices.m_size - 1);
  }
  else
  {
    v7 = geometry->m_vertices.m_data;
    while ( _mm_movemask_ps(_mm_cmpeqps(v7->m_quad, vertex->m_quad)) != 15 )
    {
      ++v6;
      ++v3;
      ++v7;
      if ( v6 >= v2 )
        goto LABEL_5;
    }
    result = v3;
  }
  return result;
}

// File Line: 851
// RVA: 0x1325D90
void __fastcall hkpCompressedMeshShapeBuilder::addLeftOverTriangle(hkpCompressedMeshShapeBuilder *this, hkVector4f *v0, hkVector4f *v1, hkVector4f *v2, int material, hkpCompressedMeshShapeBuilder::TriangleMapping *map)
{
  hkpCompressedMeshShapeBuilder *v6; // rbp
  hkVector4f *v7; // rsi
  hkVector4f *v8; // rbx
  int v9; // er14
  int v10; // er15
  int v11; // edi
  hkGeometry::Triangle *v12; // rax
  hkpCompressedMeshShapeBuilder::TriangleMapping *v13; // rdx

  v6 = this;
  v7 = v2;
  v8 = v1;
  v9 = addVertex(&this->m_leftOver, v0);
  v10 = addVertex(&v6->m_leftOver, v8);
  v11 = addVertex(&v6->m_leftOver, v7);
  if ( v6->m_leftOver.m_triangles.m_size == (v6->m_leftOver.m_triangles.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v6->m_leftOver.m_triangles,
      16);
  v12 = &v6->m_leftOver.m_triangles.m_data[v6->m_leftOver.m_triangles.m_size];
  v12->m_a = v9;
  v12->m_b = v10;
  v12->m_c = v11;
  v12->m_material = material;
  ++v6->m_leftOver.m_triangles.m_size;
  if ( map )
  {
    if ( v6->m_bigMapping.m_size == (v6->m_bigMapping.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v6->m_bigMapping, 20);
    v13 = &v6->m_bigMapping.m_data[v6->m_bigMapping.m_size];
    if ( v13 )
    {
      v13->m_originalIndex = map->m_originalIndex;
      v13->m_triangleIndex = map->m_triangleIndex;
      v13->m_chunkIndex = map->m_chunkIndex;
      v13->m_winding = map->m_winding;
      v13->m_key = map->m_key;
    }
    ++v6->m_bigMapping.m_size;
  }
}

// File Line: 868
// RVA: 0x1323F50
void __fastcall hkpCompressedMeshShapeBuilder::chunkToGeometry(hkpCompressedMeshShape *compressedMesh, int id, hkGeometry *geometry)
{
  hkpCompressedMeshShape::Chunk *r9_1; // r9
  hkGeometry *v4; // r12
  hkpCompressedMeshShape *v5; // r8
  signed __int64 v6; // rdi
  unsigned __int16 v7; // ax
  hkQsTransformf *v8; // rcx
  unsigned __int16 v9; // ax
  int v10; // ebx
  hkpCompressedMeshShape::Chunk *v11; // r13
  int v12; // edi
  int v13; // eax
  __int64 v14; // rax
  _DWORD *v15; // r15
  unsigned int v16; // ecx
  __int64 v17; // rcx
  _DWORD *v18; // rdi
  hkVector4f *v19; // rbp
  hkVector4f *v20; // rbx
  signed __int64 v21; // r14
  signed __int64 v22; // rsi
  __int64 v23; // rcx
  unsigned __int16 *v24; // rdi
  signed __int64 v25; // rdx
  int v26; // esi
  int v27; // ebx
  int v28; // edi
  hkGeometry::Triangle *v29; // rax
  int v30; // eax
  signed int v31; // [rsp+34h] [rbp-B4h]
  int index; // [rsp+38h] [rbp-B0h]
  signed __int64 v33; // [rsp+40h] [rbp-A8h]
  hkQsTransformf a; // [rsp+50h] [rbp-98h]
  hkVector4f v1; // [rsp+80h] [rbp-68h]
  hkVector4f v2; // [rsp+90h] [rbp-58h]
  hkVector4f v3; // [rsp+A0h] [rbp-48h]
  hkpCompressedMeshShape *v38; // [rsp+F0h] [rbp+8h]
  int v39; // [rsp+F8h] [rbp+10h]
  int winding; // [rsp+108h] [rbp+20h]

  v38 = compressedMesh;
  r9_1 = compressedMesh->m_chunks.m_data;
  a.m_translation = 0i64;
  v4 = geometry;
  v5 = compressedMesh;
  v6 = id;
  a.m_scale = (hkVector4f)query.m_quad;
  a.m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
  v7 = r9_1[v6].m_transformIndex;
  if ( v7 != -1 )
  {
    v8 = &compressedMesh->m_transforms.m_data[v7];
    a.m_translation = v8->m_translation;
    a.m_rotation = v8->m_rotation;
    a.m_scale = v8->m_scale;
  }
  v9 = r9_1[v6].m_reference;
  if ( v9 != -1 )
    id = v9;
  v10 = 0;
  index = 0;
  v11 = &r9_1[id];
  v12 = v11->m_vertices.m_size / 3;
  v13 = v11->m_vertices.m_size / 3;
  if ( v12 )
  {
    v39 = 4 * v12;
    v14 = ((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, int *, hkpCompressedMeshShape *))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
            &hkContainerHeapAllocator::s_alloc,
            &v39,
            v5);
    v5 = v38;
    v15 = (_DWORD *)v14;
    v13 = v39 / 4;
  }
  else
  {
    v15 = 0i64;
  }
  v16 = 2147483648;
  if ( v13 )
    v16 = v13;
  v31 = v16;
  v17 = v12;
  if ( v12 > 0 )
  {
    v18 = v15;
    while ( v17 )
    {
      *v18 = -1;
      ++v18;
      --v17;
    }
  }
  winding = 0;
  do
  {
    hkpCompressedMeshShape::Chunk::getTriangle(v11, v10, v5->m_error, &v1, &v2, &v3);
    v19 = &v1;
    v33 = v10;
    v20 = &v1;
    v21 = 3i64;
    v22 = v33;
    do
    {
      v23 = v11->m_indices.m_data[v22];
      if ( v15[v23] == -1 )
      {
        v15[v23] = v4->m_vertices.m_size;
        hkVector4f::setTransformedPos(v20, &a, v20);
        if ( v4->m_vertices.m_size == (v4->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v4->m_vertices, 16);
        v4->m_vertices.m_data[v4->m_vertices.m_size++] = (hkVector4f)v19->m_quad;
      }
      ++v20;
      ++v22;
      ++v19;
      --v21;
    }
    while ( v21 );
    v24 = v11->m_indices.m_data;
    v25 = 2i64 * winding;
    v26 = v15[v24[v33 + 1]];
    v27 = v15[v24[v25 + v33]];
    v28 = v15[v24[v33 - v25 + 2]];
    if ( v4->m_triangles.m_size == (v4->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v4->m_triangles, 16);
    v29 = &v4->m_triangles.m_data[v4->m_triangles.m_size];
    v29->m_a = v27;
    v29->m_b = v26;
    v29->m_c = v28;
    v29->m_material = 0;
    ++v4->m_triangles.m_size;
    v30 = hkpCompressedMeshShape::Chunk::getNextIndex(v11, index, &winding);
    v5 = v38;
    v10 = v30;
    index = v30;
  }
  while ( v30 != -1 );
  if ( v31 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v15,
      4 * v31);
}hkContainerHeapAllocator::s_alloc.vfptr

// File Line: 913
// RVA: 0x1324260
void __fastcall hkpCompressedMeshShapeBuilder::convexPieceToGeometry(hkpCompressedMeshShape *compressedMesh, int index, hkGeometry *geometry)
{
  hkpCompressedMeshShape::ConvexPiece *v3; // r10
  hkGeometry *v4; // rbx
  hkpCompressedMeshShape *v5; // r11
  unsigned __int16 v6; // ax
  hkQsTransformf *v7; // rcx
  unsigned __int16 v8; // ax
  float v9; // xmm1_4
  hkArray<hkVector4f,hkContainerHeapAllocator> vertices; // [rsp+20h] [rbp-58h]
  hkStridedVertices stridedVertsIn; // [rsp+30h] [rbp-48h]
  hkQsTransformf transform; // [rsp+40h] [rbp-38h]

  v3 = compressedMesh->m_convexPieces.m_data;
  transform.m_translation = 0i64;
  v4 = geometry;
  v5 = compressedMesh;
  transform.m_scale = (hkVector4f)query.m_quad;
  transform.m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
  v6 = v3[index].m_transformIndex;
  if ( v6 != -1 )
  {
    v7 = &compressedMesh->m_transforms.m_data[v6];
    transform.m_translation = v7->m_translation;
    transform.m_rotation = v7->m_rotation;
    transform.m_scale = v7->m_scale;
  }
  v8 = v3[index].m_reference;
  if ( v8 != -1 )
    index = v8;
  v9 = v5->m_error;
  vertices.m_data = 0i64;
  vertices.m_size = 0;
  vertices.m_capacityAndFlags = 2147483648;
  hkpCompressedMeshShape::ConvexPiece::getVertices(&v3[index], v9, &transform, &vertices);
  stridedVertsIn.m_vertices = vertices.m_data->m_quad.m128_f32;
  stridedVertsIn.m_numVertices = vertices.m_size;
  stridedVertsIn.m_striding = 16;
  hkGeometryUtility::createConvexGeometry(&stridedVertsIn, v4);
  vertices.m_size = 0;
  if ( vertices.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      vertices.m_data,
      16 * vertices.m_capacityAndFlags);
}

// File Line: 933
// RVA: 0x1324390
void __fastcall hkpCompressedMeshShapeBuilder::bigTrianglesToGeometry(hkpCompressedMeshShape *compressedMesh, hkGeometry *geometryOut)
{
  int v2; // er12
  hkGeometry *v3; // rsi
  hkpCompressedMeshShape *v4; // rbp
  hkArray<hkVector4f,hkContainerHeapAllocator> *v5; // rbx
  hkArray<hkGeometry::Triangle,hkContainerHeapAllocator> *v6; // rdi
  __int64 v7; // r13
  hkVector4f *v8; // rcx
  unsigned __int16 *v9; // rdx
  unsigned __int16 v10; // ax
  hkQsTransformf *v11; // rdx
  int v12; // esi
  int v13; // er14
  int v14; // er15
  hkGeometry::Triangle *v15; // rax
  hkVector4f b; // [rsp+20h] [rbp-98h]
  hkVector4f v17; // [rsp+30h] [rbp-88h]
  hkVector4f v18; // [rsp+40h] [rbp-78h]
  hkQsTransformf a; // [rsp+50h] [rbp-68h]
  hkGeometry *v20; // [rsp+C8h] [rbp+10h]

  v20 = geometryOut;
  v2 = 0;
  v3 = geometryOut;
  v4 = compressedMesh;
  if ( compressedMesh->m_bigTriangles.m_size > 0 )
  {
    v5 = &geometryOut->m_vertices;
    v6 = &geometryOut->m_triangles;
    v7 = 0i64;
    do
    {
      v8 = v4->m_bigVertices.m_data;
      v9 = &v4->m_bigTriangles.m_data[v7].m_a;
      b.m_quad = (__m128)v8[*v9];
      v17.m_quad = (__m128)v8[v9[1]];
      v18.m_quad = (__m128)v8[v9[2]];
      v10 = v9[7];
      if ( v10 != -1 )
      {
        v11 = v4->m_transforms.m_data;
        a.m_translation = v11[v10].m_translation;
        a.m_rotation = v11[v10].m_rotation;
        a.m_scale = v11[v10].m_scale;
        hkVector4f::setTransformedPos(&b, &a, &b);
        hkVector4f::setTransformedPos(&v17, &a, &v17);
        hkVector4f::setTransformedPos(&v18, &a, &v18);
      }
      v12 = v3->m_vertices.m_size;
      if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 16);
      v5->m_data[v5->m_size++] = (hkVector4f)b.m_quad;
      if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 16);
      v5->m_data[v5->m_size++] = (hkVector4f)v17.m_quad;
      if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 16);
      v13 = v12 + 1;
      v14 = v12 + 2;
      v5->m_data[v5->m_size++] = (hkVector4f)v18.m_quad;
      if ( v6->m_size == (v6->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, 16);
      ++v2;
      ++v7;
      v15 = &v6->m_data[v6->m_size];
      v15->m_a = v12;
      v3 = v20;
      v15->m_b = v13;
      v15->m_c = v14;
      v15->m_material = 0;
      ++v6->m_size;
    }
    while ( v2 < v4->m_bigTriangles.m_size );
  }
}

// File Line: 956
// RVA: 0x1324870
void __fastcall hkpCompressedMeshShapeBuilder::MappingTree::getKeys(hkpCompressedMeshShapeBuilder::MappingTree *this, hkArray<unsigned int,hkContainerHeapAllocator> *keys, const int keysBase)
{
  __int64 v3; // rsi
  hkArray<unsigned int,hkContainerHeapAllocator> *v4; // rdi
  int v5; // er9
  __int64 v6; // r10
  __int64 v7; // r8
  unsigned int v8; // eax
  hkpCompressedMeshShapeBuilder::MappingTree **v9; // rbx

  v3 = keysBase;
  v4 = keys;
  while ( 1 )
  {
    v5 = 0;
    if ( this->m_triangles.m_size > 0 )
    {
      v6 = 0i64;
      do
      {
        ++v5;
        v7 = this->m_triangles.m_data[v6].m_originalIndex;
        v8 = this->m_triangles.m_data[v6].m_key;
        ++v6;
        v4->m_data[v3 + v7] = v8;
      }
      while ( v5 < this->m_triangles.m_size );
    }
    if ( !this->m_left )
      break;
    v9 = &this->m_right;
    if ( !this->m_right )
      break;
    hkpCompressedMeshShapeBuilder::MappingTree::getKeys(this->m_left, v4, v3);
    this = *v9;
  }
}

// File Line: 969
// RVA: 0x1325650
__int64 __fastcall hkpCompressedMeshShapeBuilder::addBigTriangles(hkpCompressedMeshShapeBuilder *this, hkpCompressedMeshShape *meshShape)
{
  hkpCompressedMeshShapeBuilder *v2; // rdi
  hkpCompressedMeshShape *v3; // rbx
  int v4; // esi
  unsigned int v5; // er15
  __int64 v6; // rbp
  signed int *v7; // rbx
  __int64 v8; // r14
  int v9; // er9
  int v10; // eax
  int v11; // eax
  __int64 v12; // rdx
  _DWORD *v13; // rcx
  int v14; // er9
  signed __int64 v15; // rdx
  __int64 v16; // r8
  hkGeometry::Triangle *v17; // rcx
  int v18; // ST30_4
  __int16 v19; // ax
  __int16 v20; // ax
  int v22; // [rsp+34h] [rbp-24h]
  hkResult result; // [rsp+60h] [rbp+8h]

  v2 = this;
  v3 = meshShape;
  hkGeometryUtils::weldVertices(&this->m_leftOver, 0.001);
  v4 = v3->m_bigVertices.m_size;
  hkArrayBase<hkVector4f>::_append(
    (hkArrayBase<hkVector4f> *)&v3->m_bigVertices.m_data,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    v2->m_leftOver.m_vertices.m_data,
    v2->m_leftOver.m_vertices.m_size);
  v5 = v3->m_bigTriangles.m_size;
  v6 = v2->m_leftOver.m_triangles.m_size;
  v7 = (signed int *)&v3->m_bigTriangles;
  v8 = v7[2];
  v9 = v8 + v6;
  v10 = v7[3] & 0x3FFFFFFF;
  if ( v10 < (signed int)v8 + (signed int)v6 )
  {
    v11 = 2 * v10;
    if ( v9 < v11 )
      v9 = v11;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, v9, 16);
  }
  v12 = v6;
  if ( (signed int)v6 > 0 )
  {
    v13 = (_DWORD *)(*(_QWORD *)v7 + 16i64 * v7[2] + 12);
    do
    {
      if ( v13 != (_DWORD *)12 )
      {
        *(v13 - 1) = 0;
        *v13 = -65536;
      }
      v13 += 4;
      --v12;
    }
    while ( v12 );
  }
  v7[2] += v6;
  v14 = 0;
  v15 = *(_QWORD *)v7 + 16 * v8;
  if ( v2->m_leftOver.m_triangles.m_size > 0 )
  {
    v16 = 0i64;
    do
    {
      v17 = v2->m_leftOver.m_triangles.m_data;
      ++v14;
      v15 += 16i64;
      LOWORD(v18) = LOWORD(v17[v16].m_a) + v4;
      v19 = v17[v16].m_b;
      ++v16;
      HIWORD(v18) = v4 + v19;
      v20 = *((_WORD *)&v17[v16] - 4);
      LODWORD(v17) = *((_DWORD *)&v17[v16] - 1);
      LOWORD(v22) = v4 + v20;
      *(_DWORD *)(v15 - 16) = v18;
      *(_DWORD *)(v15 - 12) = v22;
      *(_DWORD *)(v15 - 8) = (_DWORD)v17;
      *(_DWORD *)(v15 - 4) = -65536;
    }
    while ( v14 < v2->m_leftOver.m_triangles.m_size );
  }
  v2->m_statistics.m_numBigTriangles += v2->m_leftOver.m_triangles.m_size;
  v2->m_statistics.m_numBigVertices += v2->m_leftOver.m_vertices.m_size;
  v2->m_leftOver.m_vertices.m_size = 0;
  v2->m_leftOver.m_triangles.m_size = 0;
  return v5;
}

// File Line: 1004
// RVA: 0x13245F0
void __fastcall hkpCompressedMeshShapeBuilder::snapGeometry(hkGeometry *geometry, float quantizationError)
{
  int v2; // ebx
  hkGeometry *i; // rdi

  v2 = 0;
  for ( i = geometry; v2 < i->m_vertices.m_size; ++v2 )
    hkpCompressedMeshShapeBuilder::snapToGrid(&i->m_vertices.m_data[v2], quantizationError);
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
  hkErrStream v25; // [rsp+20h] [rbp-288h]
  char buf; // [rsp+40h] [rbp-268h]

  v3 = _mm_sub_ps(b->m_quad, v->m_quad);
  v4 = _mm_sub_ps(b->m_quad, a->m_quad);
  v5 = _mm_mul_ps(v3, v3);
  v6 = _mm_mul_ps(v4, v4);
  v7 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)), _mm_shuffle_ps(v6, v6, 170));
  v8 = _mm_rsqrt_ps(v7);
  v9 = _mm_andnot_ps(
         _mm_cmpleps(v7, (__m128)0i64),
         _mm_mul_ps(
           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v8, v7), v8)), _mm_mul_ps(*(__m128 *)_xmm, v8)),
           v7));
  v10 = _mm_sub_ps(v->m_quad, a->m_quad);
  v11 = _mm_mul_ps(v10, v10);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v13 = _mm_rsqrt_ps(v12);
  v14 = _mm_andnot_ps(
          _mm_cmpleps(v12, (__m128)0i64),
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
  LODWORD(v20) = (unsigned __int128)_mm_andnot_ps(
                                      _mm_cmpleps(v15, (__m128)0i64),
                                      _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, v18), v17), v15));
  v21 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v19, v9)), v19), v14);
  if ( v21.m128_f32[0] < 0.0 || v21.m128_f32[0] > 1.0 )
  {
    hkErrStream::hkErrStream(&v25, &buf, 512);
    v22 = hkOstream::operator<<((hkOstream *)&v25.vfptr, "ratio: ");
    v23 = hkOstream::operator<<(v22, v21.m128_f32[0], (int)v22);
    v24 = hkOstream::operator<<(v23, ", ");
    hkOstream::operator<<(
      v24,
      1.0 - (float)((float)((float)(2.0 - (float)(v19.m128_f32[0] * v9.m128_f32[0])) * v19.m128_f32[0]) * v20),
      (int)v24);
    hkError::messageReport(-1, &buf, "Shape\\Deprecated\\CompressedMesh\\hkpCompressedMeshShapeBuilder.cpp", 1037);
    hkOstream::~hkOstream((hkOstream *)&v25.vfptr);
  }
  else
  {
    v->m_quad = _mm_add_ps(_mm_mul_ps(v21, v4), a->m_quad);
  }
}

// File Line: 1042
// RVA: 0x1323B60
void __fastcall hkpCompressedMeshShapeBuilder::snapGeometry(hkpCompressedMeshShapeBuilder *this, hkpCompressedMeshShapeBuilder::MappingTree *mapping)
{
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v2; // r12
  hkpCompressedMeshShapeBuilder *v3; // rdi
  float v4; // xmm1_4
  hkGeometry *v5; // rcx
  int v6; // er15
  int v7; // edx
  __int64 v8; // rbx
  __int64 v9; // r14
  hkRelocationInfo::Import *v10; // rsi
  char *v11; // r8
  float v12; // xmm3_4
  hkArray<hkTjunctionDetector::ProximityInfo,hkContainerHeapAllocator> *v13; // rsi
  float triangleRemapOut; // ST20_4
  signed __int64 v15; // rax
  signed __int64 v16; // rbx
  hkTjunctionDetector::ProximityInfo *v17; // r13
  hkVector4f *v18; // rcx
  hkGeometry::Triangle *v19; // rax
  hkVector4f *v20; // rsi
  __int64 v21; // r14
  __int64 v22; // r15
  __int64 v23; // r12
  hkTjunctionDetector::ProximityInfoEnum v24; // eax
  __m128 *v25; // r14
  __m128 *v26; // r15
  __m128 *v27; // r12
  __m128 v28; // xmm1
  __m128 v29; // xmm0
  __m128 v30; // xmm6
  __m128 v31; // xmm6
  __m128 v32; // xmm1
  __m128 v33; // xmm3
  __m128 v34; // xmm2
  __m128 v35; // xmm6
  __m128 v36; // xmm2
  hkVector4f *v37; // r8
  hkVector4f *v38; // rdx
  char *array; // [rsp+30h] [rbp-40h]
  int v40; // [rsp+38h] [rbp-38h]
  int v41; // [rsp+3Ch] [rbp-34h]
  hkArray<int,hkContainerHeapAllocator> v42; // [rsp+40h] [rbp-30h]
  hkArray<int,hkContainerHeapAllocator> vertexRemapOut; // [rsp+50h] [rbp-20h]
  int v44; // [rsp+A0h] [rbp+30h]

  v2 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)mapping;
  v3 = this;
  if ( this->m_weldVertices )
  {
    v4 = this->m_weldTolerance;
    v5 = &this->m_geometry;
    if ( mapping )
    {
      vertexRemapOut.m_capacityAndFlags = 2147483648;
      v42.m_capacityAndFlags = 2147483648;
      vertexRemapOut.m_data = 0i64;
      vertexRemapOut.m_size = 0;
      v42.m_data = 0i64;
      v42.m_size = 0;
      array = 0i64;
      v40 = 0;
      v41 = 2147483648;
      hkGeometryUtils::weldVertices(v5, v4, 0, &vertexRemapOut);
      v6 = 0;
      if ( v42.m_size > 0 )
      {
        v7 = v40;
        v8 = 0i64;
        v9 = 0i64;
        do
        {
          if ( v42.m_data[v9] == -1 )
          {
            ++v3->m_statistics.m_numDegenerate;
          }
          else
          {
            v10 = v2->m_data;
            if ( v7 == (v41 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 20);
              v7 = v40;
            }
            v11 = &array[20 * v7];
            if ( v11 )
            {
              *(_DWORD *)v11 = *(int *)((char *)&v10->m_fromOffset + v8);
              *((_DWORD *)v11 + 1) = *(int *)((char *)&v10->m_fromOffset + v8 + 4);
              *((_DWORD *)v11 + 2) = *(_DWORD *)((char *)&v10->m_identifier + v8);
              *((_DWORD *)v11 + 3) = *(_DWORD *)((char *)&v10->m_identifier + v8 + 4);
              *((_DWORD *)v11 + 4) = *(int *)((char *)&v10[1].m_fromOffset + v8);
              v7 = v40;
            }
            v40 = ++v7;
          }
          ++v6;
          ++v9;
          v8 += 20i64;
        }
        while ( v6 < v42.m_size );
      }
      hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
        v2,
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&array);
      v40 = 0;
      if ( v41 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          array,
          20 * (v41 & 0x3FFFFFFF));
      array = 0i64;
      v41 = 2147483648;
      v42.m_size = 0;
      if ( v42.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v42.m_data,
          4 * v42.m_capacityAndFlags);
      v42.m_data = 0i64;
      v42.m_capacityAndFlags = 2147483648;
      vertexRemapOut.m_size = 0;
      if ( vertexRemapOut.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          vertexRemapOut.m_data,
          4 * vertexRemapOut.m_capacityAndFlags);
    }
    else
    {
      hkGeometryUtils::weldVertices(v5, v4);
    }
  }
  v12 = v3->m_TjunctionTolerance;
  v13 = &v3->m_Tjunctions;
  triangleRemapOut = v3->m_weldTolerance;
  v3->m_TjunctionsBase = v3->m_Tjunctions.m_size;
  hkTjunctionDetector::detect(&v3->m_geometry, &v3->m_Tjunctions, &v3->m_weldedVertices, v12, triangleRemapOut);
  hkpCompressedMeshShapeBuilder::snapGeometry(&v3->m_geometry, v3->m_error);
  v15 = v3->m_TjunctionsBase;
  v44 = v15;
  if ( (signed int)v15 < v3->m_Tjunctions.m_size )
  {
    v16 = v15;
    do
    {
      v17 = v13->m_data;
      v18 = v3->m_geometry.m_vertices.m_data;
      v19 = &v3->m_geometry.m_triangles.m_data[v13->m_data[v16].m_key];
      v20 = &v18[v13->m_data[v16].m_index];
      v21 = v19->m_a;
      v22 = v19->m_b;
      v23 = v19->m_c;
      v24 = v17[v16].m_type;
      v25 = &v18[v21].m_quad;
      v26 = &v18[v22].m_quad;
      v27 = &v18[v23].m_quad;
      switch ( v24 )
      {
        case 4:
          v28 = _mm_sub_ps(*v26, *v25);
          v29 = _mm_sub_ps(*v27, *v25);
          v30 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v29, v29, 201), v28),
                  _mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), v29));
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
                      _mm_mul_ps(*(__m128 *)_xmm, v34))));
          v36 = _mm_mul_ps(_mm_sub_ps(v20->m_quad, *v25), v35);
          v20->m_quad = _mm_sub_ps(
                          v20->m_quad,
                          _mm_mul_ps(
                            _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)),
                              _mm_shuffle_ps(v36, v36, 170)),
                            v35));
          break;
        case 1:
          v37 = (hkVector4f *)v26;
          v38 = (hkVector4f *)v25;
LABEL_30:
          projectOnEdge(v20, v38, v37);
          break;
        case 2:
          v37 = (hkVector4f *)v27;
          v38 = (hkVector4f *)v26;
          goto LABEL_30;
        case 3:
          v37 = (hkVector4f *)v25;
          v38 = (hkVector4f *)v27;
          goto LABEL_30;
      }
      ++v16;
      v17[v16 - 1].m_vertex = (hkVector4f)v20->m_quad;
      ++v44;
      v13 = &v3->m_Tjunctions;
      *((__m128 *)&v17[v16] - 3) = *v25;
      *((__m128 *)&v17[v16] - 2) = *v26;
      *((__m128 *)&v17[v16] - 1) = *v27;
    }
    while ( v44 < v3->m_Tjunctions.m_size );
  }
}

// File Line: 1133
// RVA: 0x13257E0
void __fastcall hkpCompressedMeshShapeBuilder::filterGeometry(hkpCompressedMeshShapeBuilder *this, hkpCompressedMeshShapeBuilder::MappingTree *mapping)
{
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v2; // rdi
  hkpCompressedMeshShapeBuilder *v3; // rbx
  int v4; // esi
  int v5; // er9
  int v6; // edx
  __int64 v7; // rcx
  signed __int64 v8; // rdx
  signed __int64 v9; // r8
  hkArray<hkGeometry::Triangle,hkContainerHeapAllocator> *v10; // r15
  hkGeometry::Triangle *v11; // rsi
  __int64 v12; // r14
  __int64 v13; // rdi
  hkGeometry::Triangle *v14; // rax
  hkVector4f *v15; // rcx
  __int64 v16; // rdx
  __int64 v17; // r15
  hkpCompressedMeshShapeBuilder::TriangleMapping *v18; // rdx
  __int64 v19; // rax
  hkVector4f *v20; // r12
  hkVector4f *v21; // r15
  hkVector4f *v22; // r13
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v23; // rdx
  hkpCompressedMeshShapeBuilder::TriangleMapping *v24; // r8
  __m128i v25; // xmm3
  __m128 v26; // xmm3
  hkGeometry::Triangle *v27; // rcx
  hkRelocationInfo::Import *v28; // r15
  int v29; // edx
  int *v30; // r8
  signed __int64 v31; // rsi
  int v32; // eax
  int v33; // eax
  int v34; // er9
  hkArray<hkVector4f,hkContainerHeapAllocator> *v35; // rsi
  int v36; // er10
  hkVector4f *v37; // rdi
  int v38; // er8
  __int64 v39; // rdx
  __int64 v40; // r9
  hkVector4f *v41; // rcx
  signed __int64 v42; // rdi
  int v43; // eax
  int v44; // eax
  int v45; // er9
  int v46; // er9
  __int64 v47; // r8
  hkGeometry::Triangle *v48; // rdx
  __int64 v49; // rcx
  hkpCompressedMeshShapeBuilder::TriangleMapping *map; // [rsp+28h] [rbp-49h]
  __int64 v51; // [rsp+30h] [rbp-41h]
  _DWORD *array; // [rsp+38h] [rbp-39h]
  int v53; // [rsp+40h] [rbp-31h]
  int v54; // [rsp+44h] [rbp-2Dh]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> a; // [rsp+48h] [rbp-29h]
  hkSimdFloat32 tolerance; // [rsp+58h] [rbp-19h]
  __m128i v57; // [rsp+68h] [rbp-9h]
  void *retaddr; // [rsp+D8h] [rbp+67h]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *result; // [rsp+E0h] [rbp+6Fh]
  hkpCompressedMeshShapeBuilder::MappingTree *v60; // [rsp+E8h] [rbp+77h]
  __int64 v61; // [rsp+F0h] [rbp+7Fh]

  v60 = mapping;
  v2 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)mapping;
  v3 = this;
  v54 = 2147483648;
  array = 0i64;
  v53 = 0;
  if ( this->m_preserveTjunctions )
  {
    v4 = this->m_geometry.m_vertices.m_size;
    if ( v4 > 0 )
    {
      v5 = this->m_geometry.m_vertices.m_size;
      if ( v4 < 0 )
        v5 = 0;
      hkArrayUtil::_reserve(
        (hkResult *)&retaddr,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &array,
        v5,
        4);
    }
    v53 = v4;
    v6 = 0;
    if ( v4 > 0 )
    {
      v7 = 0i64;
      do
      {
        ++v6;
        ++v7;
        array[v7 - 1] = 0;
      }
      while ( v6 < v53 );
    }
    v8 = v3->m_TjunctionsBase;
    if ( (signed int)v8 < v3->m_Tjunctions.m_size )
    {
      v9 = v8;
      do
      {
        LODWORD(v8) = v8 + 1;
        ++v9;
        array[*((signed int *)&v3->m_Tjunctions.m_data[v9] - 16)] = -1;
      }
      while ( (signed int)v8 < v3->m_Tjunctions.m_size );
    }
  }
  v10 = &v3->m_geometry.m_triangles;
  a.m_data = 0i64;
  a.m_size = 0;
  v11 = v3->m_geometry.m_triangles.m_data;
  a.m_capacityAndFlags = 2147483648;
  LODWORD(retaddr) = 0;
  if ( v3->m_geometry.m_triangles.m_size > 0 )
  {
    v12 = 0i64;
    v13 = 0i64;
    while ( 1 )
    {
      v14 = v10->m_data;
      v15 = v3->m_geometry.m_vertices.m_data;
      v16 = v10->m_data[v13].m_a;
      *(float *)&v60 = hkDefaultTriangleDegeneracyTolerance;
      v17 = v16;
      v61 = v16;
      v18 = (hkpCompressedMeshShapeBuilder::TriangleMapping *)v14[v13].m_b;
      tolerance.m_real = _mm_shuffle_ps(
                           (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                           (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                           0);
      v19 = v14[v13].m_c;
      map = v18;
      v20 = &v15[(_QWORD)v18];
      v21 = &v15[v17];
      v22 = &v15[v19];
      v51 = v19;
      if ( (unsigned int)hkcdTriangleUtil::isDegenerate(v21, &v15[(_QWORD)v18], &v15[v19], &tolerance) )
        break;
      v23 = result;
      if ( result )
        v24 = (hkpCompressedMeshShapeBuilder::TriangleMapping *)((char *)result->m_data + 20 * (signed int)retaddr);
      else
        v24 = 0i64;
      if ( v3->m_preserveTjunctions && (array[v61] == -1 || array[(_QWORD)map] == -1 || array[v51] == -1) )
      {
        hkpCompressedMeshShapeBuilder::addLeftOverTriangle(
          v3,
          v21,
          v20,
          v22,
          v3->m_geometry.m_triangles.m_data[v13].m_material,
          v24);
        goto LABEL_32;
      }
      v25 = (__m128i)_mm_sub_ps(
                       _mm_max_ps(
                         _mm_max_ps(
                           _mm_max_ps(
                             _mm_xor_ps(
                               (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                               (__m128)xmmword_141A712A0),
                             v21->m_quad),
                           v20->m_quad),
                         v22->m_quad),
                       _mm_min_ps(
                         _mm_min_ps(_mm_min_ps((__m128)xmmword_141A712A0, v21->m_quad), v20->m_quad),
                         v22->m_quad));
      v57 = v25;
      v26 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v25, 1u), 1u);
      if ( (float)(v3->m_error * 65534.0) < *(float *)&v57.m128i_i32[(unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(_mm_max_ps(_mm_shuffle_ps(v26, v26, 170), _mm_max_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0))), v26), (__m128)xmmword_141C20A50))]] )
      {
        hkpCompressedMeshShapeBuilder::addLeftOverTriangle(
          v3,
          v21,
          v20,
          v22,
          v3->m_geometry.m_triangles.m_data[v13].m_material,
          v24);
        goto LABEL_32;
      }
      v10 = &v3->m_geometry.m_triangles;
      ++v11;
      v27 = v3->m_geometry.m_triangles.m_data;
      v11[-1].m_a = v27[v13].m_a;
      v11[-1].m_b = v27[v13].m_b;
      v11[-1].m_c = v27[v13].m_c;
      v11[-1].m_material = v27[v13].m_material;
      if ( v23 )
      {
        v28 = v23->m_data;
        v29 = a.m_size;
        if ( a.m_size == (a.m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &a, 20);
          v29 = a.m_size;
        }
        v30 = &a.m_data->m_fromOffset + 5 * v29;
        if ( v30 )
        {
          *v30 = *(int *)((char *)&v28->m_fromOffset + v12);
          v30[1] = *(int *)((char *)&v28->m_fromOffset + v12 + 4);
          v30[2] = *(_DWORD *)((char *)&v28->m_identifier + v12);
          v30[3] = *(_DWORD *)((char *)&v28->m_identifier + v12 + 4);
          v30[4] = *(int *)((char *)&v28[1].m_fromOffset + v12);
          v29 = a.m_size;
        }
        a.m_size = v29 + 1;
        goto LABEL_32;
      }
LABEL_33:
      ++v13;
      v12 += 20i64;
      LODWORD(retaddr) = (_DWORD)retaddr + 1;
      if ( (signed int)retaddr >= v3->m_geometry.m_triangles.m_size )
      {
        v2 = result;
        goto LABEL_35;
      }
    }
    ++v3->m_statistics.m_numDegenerate;
LABEL_32:
    v10 = &v3->m_geometry.m_triangles;
    goto LABEL_33;
  }
LABEL_35:
  v31 = v11 - v10->m_data;
  v32 = v10->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v32 < (signed int)v31 )
  {
    v33 = 2 * v32;
    v34 = v31;
    if ( (signed int)v31 < v33 )
      v34 = v33;
    hkArrayUtil::_reserve(
      (hkResult *)&result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v10,
      v34,
      16);
  }
  v10->m_size = v31;
  if ( v2 )
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(v2, &a);
  if ( v3->m_preserveTjunctions )
  {
    v35 = &v3->m_geometry.m_vertices;
    v36 = 0;
    v37 = v3->m_geometry.m_vertices.m_data;
    v38 = 0;
    if ( v3->m_geometry.m_vertices.m_size > 0 )
    {
      v39 = 0i64;
      v40 = 0i64;
      do
      {
        if ( array[v39] != -1 )
        {
          v41 = v37;
          ++v37;
          *v41 = v35->m_data[v40];
          array[v39] = v36++;
        }
        ++v38;
        ++v40;
        ++v39;
      }
      while ( v38 < v3->m_geometry.m_vertices.m_size );
    }
    v42 = v37 - v35->m_data;
    v43 = v3->m_geometry.m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v43 < (signed int)v42 )
    {
      v44 = 2 * v43;
      v45 = v42;
      if ( (signed int)v42 < v44 )
        v45 = v44;
      hkArrayUtil::_reserve(
        (hkResult *)&result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v3->m_geometry.m_vertices,
        v45,
        16);
    }
    v3->m_geometry.m_vertices.m_size = v42;
    v46 = 0;
    if ( v3->m_geometry.m_triangles.m_size > 0 )
    {
      v47 = 0i64;
      do
      {
        v48 = v10->m_data;
        ++v46;
        v49 = v10->m_data[v47].m_a;
        ++v47;
        v48[v47 - 1].m_a = array[v49];
        *((_DWORD *)&v48[v47] - 3) = array[*((signed int *)&v48[v47] - 3)];
        *((_DWORD *)&v48[v47] - 2) = array[*((signed int *)&v48[v47] - 2)];
      }
      while ( v46 < v3->m_geometry.m_triangles.m_size );
    }
  }
  a.m_size = 0;
  if ( a.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      a.m_data,
      20 * (a.m_capacityAndFlags & 0x3FFFFFFF));
  a.m_data = 0i64;
  v53 = 0;
  a.m_capacityAndFlags = 2147483648;
  if ( v54 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      4 * v54);
}

// File Line: 1236
// RVA: 0x13228B0
char __fastcall hkpCompressedMeshShapeBuilder::addConvexPiece(hkpCompressedMeshShapeBuilder *this, hkArray<hkVector4f,hkContainerHeapAllocator> *vertices, hkpCompressedMeshShape *compressedMesh)
{
  hkArray<hkVector4f,hkContainerHeapAllocator> *v3; // rdi
  hkpCompressedMeshShapeBuilder *v4; // rbx
  hkpCompressedMeshShape *v5; // rsi
  hkStridedVertices v6; // xmm3
  __m128 v7; // xmm3
  int v9; // eax
  hkOstream *v10; // rax
  hkOstream *v11; // rax
  hkOstream *v12; // rax
  char v13; // bl
  __m128 v14; // xmm0
  float v15; // xmm1_4
  hkpCompressedMeshShape::ConvexPiece *v16; // rcx
  hkArray<hkVector4f,hkContainerHeapAllocator> positions; // [rsp+20h] [rbp-E0h]
  hkStridedVertices points; // [rsp+30h] [rbp-D0h]
  hkVector4f v; // [rsp+50h] [rbp-B0h]
  hkArray<unsigned short,hkContainerHeapAllocator> verticesOut; // [rsp+60h] [rbp-A0h]
  hkgpConvexHull::BuildConfig config; // [rsp+80h] [rbp-80h]
  hkAabb aabbOut; // [rsp+90h] [rbp-70h]
  hkgpConvexHull v23; // [rsp+B0h] [rbp-50h]
  char buf; // [rsp+E0h] [rbp-20h]

  v3 = vertices;
  v4 = this;
  v5 = compressedMesh;
  hkAabbUtil::calcAabb(vertices->m_data, vertices->m_size, &aabbOut);
  v6 = (hkStridedVertices)_mm_sub_ps(aabbOut.m_max.m_quad, aabbOut.m_min.m_quad);
  points = v6;
  v7 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v6, 1u), 1u);
  if ( (float)((float)(v4->m_error * 65535.0) - 1.0) <= *((float *)&points.m_vertices
                                                        + (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(_mm_max_ps(_mm_shuffle_ps(v7, v7, 170), _mm_max_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0))), v7), (__m128)xmmword_141C20A50))]) )
    return 0;
  hkgpConvexHull::BuildConfig::BuildConfig(&config);
  config.m_allowLowerDimensions.m_bool = 1;
  hkgpConvexHull::hkgpConvexHull(&v23);
  points.m_vertices = v3->m_data->m_quad.m128_f32;
  v9 = v3->m_size;
  points.m_striding = 16;
  points.m_numVertices = v9;
  hkgpConvexHull::build(&v23, &points, &config);
  positions.m_data = 0i64;
  positions.m_size = 0;
  positions.m_capacityAndFlags = 2147483648;
  hkgpConvexHull::fetchPositions(&v23, INTERNAL_VERTICES, &positions);
  if ( positions.m_size <= 32 )
  {
    v14 = aabbOut.m_min.m_quad;
    v15 = v4->m_error;
    v4->m_statistics.m_numVertices += positions.m_size;
    verticesOut.m_data = 0i64;
    verticesOut.m_size = 0;
    v.m_quad = v14;
    *(_QWORD *)&verticesOut.m_capacityAndFlags = -2147483648i64;
    hkpCompressedMeshShapeBuilder::snapToGrid(&v, v15);
    hkpCompressedMeshShapeBuilder::quantizeVertices(v4->m_error, &v, &positions, &verticesOut);
    if ( v5->m_convexPieces.m_size == (v5->m_convexPieces.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v5->m_convexPieces, 48);
    v16 = &v5->m_convexPieces.m_data[v5->m_convexPieces.m_size];
    if ( v16 )
      hkpCompressedMeshShape::ConvexPiece::ConvexPiece(v16, (hkpCompressedMeshShape::ConvexPiece *)&v);
    ++v5->m_convexPieces.m_size;
    verticesOut.m_size = 0;
    v13 = 1;
    if ( verticesOut.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        verticesOut.m_data,
        2 * (verticesOut.m_capacityAndFlags & 0x3FFFFFFF));
    verticesOut.m_data = 0i64;
    verticesOut.m_capacityAndFlags = 2147483648;
  }
  else
  {
    hkErrStream::hkErrStream((hkErrStream *)&points, &buf, 512);
    v10 = hkOstream::operator<<((hkOstream *)&points, "Number of convex hull vertices (");
    v11 = hkOstream::operator<<(v10, positions.m_size, (int)v10);
    v12 = hkOstream::operator<<(v11, ") too large, maximum allowed: ");
    hkOstream::operator<<(v12, 32, (int)v12);
    hkError::messageWarning(
      482939537,
      &buf,
      "Shape\\Deprecated\\CompressedMesh\\hkpCompressedMeshShapeBuilder.cpp",
      1257);
    hkOstream::~hkOstream((hkOstream *)&points);
    v13 = 0;
  }
  positions.m_size = 0;
  if ( positions.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      positions.m_data,
      16 * positions.m_capacityAndFlags);
  positions.m_data = 0i64;
  positions.m_capacityAndFlags = 2147483648;
  hkgpConvexHull::~hkgpConvexHull(&v23);
  return v13;
}

// File Line: 1275
// RVA: 0x1322B70
__int64 __fastcall hkpCompressedMeshShapeBuilder::addConvexPiece(hkpCompressedMeshShapeBuilder *this, hkGeometry *geometry, hkpCompressedMeshShape *compressedMesh)
{
  hkGeometry *v3; // rsi
  hkpCompressedMeshShapeBuilder *v4; // rdi
  unsigned __int8 v5; // bp
  signed __int64 v6; // rbx
  int v7; // er14
  int v8; // er9
  int v9; // eax
  int v10; // eax
  signed __int64 v11; // rcx
  hkResult result; // [rsp+58h] [rbp+10h]

  v3 = geometry;
  v4 = this;
  v5 = hkpCompressedMeshShapeBuilder::addConvexPiece(this, &geometry->m_vertices, compressedMesh);
  if ( !v5 || !v4->m_createMapping )
    return v5;
  v6 = v4->m_shapeKeys.m_size;
  v7 = v3->m_triangles.m_size;
  v8 = v7 + v4->m_shapeKeys.m_size;
  v9 = v4->m_shapeKeys.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v9 < v8 )
  {
    v10 = 2 * v9;
    if ( v8 < v10 )
      v8 = v10;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v4->m_shapeKeys,
      v8,
      4);
  }
  v4->m_shapeKeys.m_size += v7;
  if ( (signed int)v6 < v4->m_shapeKeys.m_size )
  {
    v11 = v6;
    do
    {
      LODWORD(v6) = v6 + 1;
      ++v11;
      v4->m_shapeKeys.m_data[v11 - 1] = -1;
    }
    while ( (signed int)v6 < v4->m_shapeKeys.m_size );
  }
  return v5;
}

