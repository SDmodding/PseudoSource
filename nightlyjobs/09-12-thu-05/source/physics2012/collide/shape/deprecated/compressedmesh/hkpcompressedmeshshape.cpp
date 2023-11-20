// File Line: 41
// RVA: 0xD0FED0
void __fastcall hkpCompressedMeshShape::hkpCompressedMeshShape(hkpCompressedMeshShape *this, int bitsPerIndex, float radius)
{
  int v3; // ebx
  hkpCompressedMeshShape *v4; // rdi

  v3 = bitsPerIndex;
  v4 = this;
  hkpShapeCollection::hkpShapeCollection(
    (hkpShapeCollection *)&this->vfptr,
    COMPRESSED_MESH,
    COLLECTION_COMPRESSED_MESH);
  v4->m_bitsPerIndex = v3;
  v4->m_radius = radius;
  v4->m_bitsPerWIndex = v3 + 1;
  v4->vfptr = (hkBaseObjectVtbl *)&hkpCompressedMeshShape::`vftable{for `hkpShape};
  v4->vfptr = (hkpShapeContainerVtbl *)&hkpCompressedMeshShape::`vftable{for `hkpShapeContainer};
  v4->m_wIndexMask = (1 << (v3 + 1)) - 1;
  v4->m_indexMask = (1 << v3) - 1;
  v4->m_materials.m_data = 0i64;
  v4->m_materials.m_size = 0;
  v4->m_materials.m_capacityAndFlags = 2147483648;
  v4->m_materials16.m_data = 0i64;
  v4->m_materials16.m_size = 0;
  v4->m_materials16.m_capacityAndFlags = 2147483648;
  v4->m_materials8.m_data = 0i64;
  v4->m_materials8.m_size = 0;
  v4->m_materials8.m_capacityAndFlags = 2147483648;
  v4->m_transforms.m_data = 0i64;
  v4->m_transforms.m_size = 0;
  v4->m_transforms.m_capacityAndFlags = 2147483648;
  v4->m_bigVertices.m_data = 0i64;
  v4->m_bigVertices.m_size = 0;
  v4->m_bigVertices.m_capacityAndFlags = 2147483648;
  v4->m_bigTriangles.m_data = 0i64;
  v4->m_bigTriangles.m_size = 0;
  v4->m_bigTriangles.m_capacityAndFlags = 2147483648;
  v4->m_chunks.m_data = 0i64;
  v4->m_chunks.m_size = 0;
  v4->m_chunks.m_capacityAndFlags = 2147483648;
  v4->m_convexPieces.m_data = 0i64;
  v4->m_convexPieces.m_size = 0;
  v4->m_convexPieces.m_capacityAndFlags = 2147483648;
  v4->m_defaultCollisionFilterInfo = 0;
  v4->m_meshMaterials = 0i64;
  *(_DWORD *)&v4->m_materialStriding = 4;
  v4->m_namedMaterials.m_data = 0i64;
  v4->m_namedMaterials.m_size = 0;
  v4->m_namedMaterials.m_capacityAndFlags = 2147483648;
  v4->m_weldingType.m_storage = 6;
}

// File Line: 57
// RVA: 0xD10020
void __fastcall hkpCompressedMeshShape::hkpCompressedMeshShape(hkpCompressedMeshShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpCompressedMeshShape *v2; // rbx
  bool v3; // zf
  int v4; // [rsp+38h] [rbp+10h]

  v4 = flag.m_finishing;
  v2 = this;
  hkpShapeCollection::hkpShapeCollection((hkpShapeCollection *)&this->vfptr, flag);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpCompressedMeshShape::`vftable{for `hkpShape};
  v2->vfptr = (hkpShapeContainerVtbl *)&hkpCompressedMeshShape::`vftable{for `hkpShapeContainer};
  if ( v4 )
  {
    v3 = v2->m_namedMaterials.m_size == 0;
    v2->m_type.m_storage = 15;
    v2->m_collectionType.m_storage = 6;
    if ( !v3 )
    {
      v2->m_meshMaterials = (hkpMeshMaterial *)&v2->m_namedMaterials.m_data->m_filterInfo;
      v2->m_materialStriding = 16;
    }
  }
}

// File Line: 71
// RVA: 0xD11160
__int64 __fastcall hkpCompressedMeshShape::Chunk::getNextIndex(hkpCompressedMeshShape::Chunk *this, int index, int *winding)
{
  int v3; // er9
  int v4; // edx
  int *v5; // rsi
  hkpCompressedMeshShape::Chunk *v6; // rbp
  int v8; // er9
  int v9; // ecx
  char v10; // r11
  unsigned __int16 *v11; // r8
  signed __int64 i; // r10
  int j; // er8

  v3 = index;
  v4 = 0;
  v5 = winding;
  *winding = 0;
  v6 = this;
  if ( v3 < 0 )
    return 0i64;
  v8 = v3 + 1;
  v9 = 0;
  v10 = 0;
  if ( v6->m_stripLengths.m_size )
  {
    v11 = v6->m_stripLengths.m_data;
    v9 = *v11;
    for ( i = 0i64; v8 >= v9; v9 += *v11 )
    {
      ++i;
      ++v4;
      ++v11;
      if ( i >= v6->m_stripLengths.m_size )
        break;
      v10 = v9;
    }
  }
  if ( v4 < v6->m_stripLengths.m_size )
  {
    if ( v8 < v9 - 2 )
      *v5 = ((_BYTE)v8 - v10) & 1;
    else
      v8 = v9;
  }
  else
  {
    for ( j = v8 - v9; j != 3 * (j / 3); ++v8 )
      ++j;
  }
  if ( v8 >= v6->m_indices.m_size )
    v8 = -1;
  return (unsigned int)v8;
}

// File Line: 140
// RVA: 0xD10090
__int64 __fastcall hkpCompressedMeshShape::getFirstKey(hkpCompressedMeshShape *this)
{
  return ((__int64 (__fastcall *)(hkpCompressedMeshShape *, signed __int64))this->vfptr[1].__first_virtual_table_function__)(
           this,
           0xFFFFFFFFi64);
}

// File Line: 145
// RVA: 0xD100A0
signed __int64 __fastcall hkpCompressedMeshShape::getNextKey(hkpCompressedMeshShape *this, unsigned int oldKey)
{
  hkpCompressedMeshShape *v2; // rdi
  int v3; // ebx
  unsigned int v4; // er14
  int v5; // ebx
  signed __int64 v6; // rsi
  char *v7; // r9
  hkQsTransformf *v8; // rax
  __int64 v9; // rcx
  __int64 v10; // rdx
  __int64 v11; // r8
  int v12; // er12
  int v13; // er14
  signed __int64 v14; // r15
  hkVector4f *v15; // rax
  signed __int64 v16; // rsi
  unsigned __int16 v17; // ax
  hkpCompressedMeshShape::Chunk *v18; // rcx
  signed __int64 result; // rax
  int v20; // eax
  unsigned int v21; // ebp
  hkVector4f *v22; // rax
  int v23; // ebx
  hkSimdFloat32 tolerance; // [rsp+20h] [rbp-248h]
  char v25; // [rsp+30h] [rbp-238h]
  int winding; // [rsp+278h] [rbp+10h]
  float v27; // [rsp+280h] [rbp+18h]

  v2 = this;
  if ( oldKey == -1 )
  {
    v3 = -1;
  }
  else
  {
    v4 = oldKey >> *(_DWORD *)((char *)&this->m_shapeInfoCodecType + 1);
    v3 = oldKey & HIDWORD(this->m_userData);
    if ( v4 )
      goto LABEL_9;
  }
  v5 = v3 + 1;
  if ( v5 >= this->m_transforms.m_size )
  {
LABEL_8:
    v4 = 1;
    v3 = -1;
LABEL_9:
    v12 = (1 << (32 - *((_BYTE *)&v2->m_shapeInfoCodecType + 1))) - 1;
    if ( v4 != v12 )
    {
      v13 = v4 - 1;
      if ( v13 < v2->m_bigVertices.m_size )
      {
        v14 = 6i64 * v13;
        do
        {
          v15 = v2->m_bigVertices.m_data;
          winding = 0;
          v16 = (signed __int64)&v15[v14];
          while ( 1 )
          {
            v17 = *(_WORD *)(v16 + 84);
            v18 = (hkpCompressedMeshShape::Chunk *)(v17 == -1 ? v16 : &v2->m_bigVertices.m_data[6 * v17]);
            v20 = hkpCompressedMeshShape::Chunk::getNextIndex(v18, v3, &winding);
            v3 = v20;
            if ( v20 == -1 )
              break;
            v21 = v20 & v2->m_userData | ((v13 + 1) << *(_DWORD *)((char *)&v2->m_shapeInfoCodecType + 1)) | ((winding & 1) << *(_DWORD *)&v2->m_type.m_storage);
            v22 = (hkVector4f *)((__int64 (__fastcall *)(hkpCompressedMeshShape *, _QWORD, char *))v2->vfptr[2].__first_virtual_table_function__)(
                                  v2,
                                  v21,
                                  &v25);
            v27 = hkDefaultTriangleDegeneracyTolerance;
            tolerance.m_real = _mm_shuffle_ps(
                                 (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                                 (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                                 0);
            if ( !hkcdTriangleUtil::isDegenerate(v22 + 3, v22 + 4, v22 + 5, &tolerance) )
              return v21;
          }
          ++v13;
          v3 = -1;
          v14 += 6i64;
        }
        while ( v13 < v2->m_bigVertices.m_size );
      }
    }
    v23 = v3 + 1;
    if ( v23 >= v2->m_bigTriangles.m_size )
      result = 0xFFFFFFFFi64;
    else
      result = v23 | (unsigned int)(v12 << *(_DWORD *)((char *)&v2->m_shapeInfoCodecType + 1));
    return result;
  }
  v6 = 8i64 * v5;
  while ( 1 )
  {
    v7 = v2->m_materials8.m_data;
    v8 = v2->m_transforms.m_data;
    v9 = v8->m_translation.m_quad.m128_u16[v6];
    v10 = v8->m_translation.m_quad.m128_u16[v6 + 1];
    v11 = v8->m_translation.m_quad.m128_u16[v6 + 2];
    winding = LODWORD(hkDefaultTriangleDegeneracyTolerance);
    tolerance.m_real = _mm_shuffle_ps(
                         (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                         (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                         0);
    if ( !hkcdTriangleUtil::isDegenerate(
            (hkVector4f *)&v7[16 * v9],
            (hkVector4f *)&v7[16 * v10],
            (hkVector4f *)&v7[16 * v11],
            &tolerance) )
      return (unsigned int)v5;
    ++v5;
    v6 += 8i64;
    if ( v5 >= v2->m_transforms.m_size )
      goto LABEL_8;
  }
}

// File Line: 244
// RVA: 0xD10CF0
void __fastcall hkpCompressedMeshShape::getChunkAabb(hkpCompressedMeshShape *this, hkpCompressedMeshShape::Chunk *chunk, hkAabb *bounds)
{
  unsigned __int16 v3; // ax
  hkAabb *v4; // rdi
  hkpCompressedMeshShape *v5; // rbx
  hkQsTransformf *v6; // rcx
  unsigned __int16 v7; // ax
  float v8; // xmm1_4
  hkpCompressedMeshShape::Chunk *v9; // rcx
  int v10; // er8
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  hkArray<hkVector4f,hkContainerHeapAllocator> vertices; // [rsp+20h] [rbp-48h]
  hkQsTransformf transform; // [rsp+30h] [rbp-38h]

  v3 = chunk->m_transformIndex;
  transform.m_translation = 0i64;
  v4 = bounds;
  v5 = this;
  transform.m_scale = (hkVector4f)query.m_quad;
  transform.m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
  if ( v3 != -1 )
  {
    v6 = &this->m_transforms.m_data[v3];
    transform.m_translation = v6->m_translation;
    transform.m_rotation = v6->m_rotation;
    transform.m_scale = v6->m_scale;
  }
  v7 = chunk->m_reference;
  v8 = v5->m_error;
  vertices.m_data = 0i64;
  vertices.m_size = 0;
  vertices.m_capacityAndFlags = 2147483648;
  if ( v7 == -1 )
    v9 = chunk;
  else
    v9 = &v5->m_chunks.m_data[v7];
  hkpCompressedMeshShape::Chunk::getVertices(v9, v8, &transform, &vertices);
  hkAabbUtil::calcAabb(vertices.m_data, vertices.m_size, v4);
  v10 = vertices.m_capacityAndFlags;
  vertices.m_size = 0;
  v11 = _mm_shuffle_ps((__m128)LODWORD(v5->m_radius), (__m128)LODWORD(v5->m_radius), 0);
  v12 = _mm_sub_ps(v4->m_min.m_quad, v11);
  v4->m_max.m_quad = _mm_add_ps(v4->m_max.m_quad, v11);
  v4->m_min.m_quad = v12;
  if ( v10 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      vertices.m_data,
      16 * v10);
}

// File Line: 268
// RVA: 0xD10E20
void __fastcall hkpCompressedMeshShape::getConvexPieceAabb(hkpCompressedMeshShape *this, hkpCompressedMeshShape::ConvexPiece *piece, hkAabb *bounds)
{
  unsigned __int16 v3; // ax
  hkAabb *v4; // rbx
  hkpCompressedMeshShape *v5; // r10
  hkQsTransformf *v6; // rcx
  unsigned __int16 v7; // ax
  float v8; // xmm1_4
  hkpCompressedMeshShape::ConvexPiece *v9; // rcx
  hkArray<hkVector4f,hkContainerHeapAllocator> vertices; // [rsp+20h] [rbp-48h]
  hkQsTransformf transform; // [rsp+30h] [rbp-38h]

  v3 = piece->m_transformIndex;
  transform.m_translation = 0i64;
  v4 = bounds;
  v5 = this;
  transform.m_scale = (hkVector4f)query.m_quad;
  transform.m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
  if ( v3 != -1 )
  {
    v6 = &this->m_transforms.m_data[v3];
    transform.m_translation = v6->m_translation;
    transform.m_rotation = v6->m_rotation;
    transform.m_scale = v6->m_scale;
  }
  v7 = piece->m_reference;
  v8 = v5->m_error;
  vertices.m_data = 0i64;
  vertices.m_size = 0;
  vertices.m_capacityAndFlags = 2147483648;
  if ( v7 == -1 )
    v9 = piece;
  else
    v9 = &v5->m_convexPieces.m_data[v7];
  hkpCompressedMeshShape::ConvexPiece::getVertices(v9, v8, &transform, &vertices);
  hkAabbUtil::calcAabb(vertices.m_data, vertices.m_size, v4);
  vertices.m_size = 0;
  if ( vertices.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      vertices.m_data,
      16 * vertices.m_capacityAndFlags);
}

// File Line: 292
// RVA: 0xD10CE0
signed __int64 __fastcall hkpCompressedMeshShape::calcSizeForSpu(hkpCompressedMeshShape *this, hkpShape::CalcSizeForSpuInput *input, int spuBufferSizeLeft)
{
  return 288i64;
}

// File Line: 307
// RVA: 0xD11070
void __fastcall hkpCompressedMeshShape::Chunk::getTriangle(hkpCompressedMeshShape::Chunk *this, int a, int b, int c, float error, hkVector4f *v1, hkVector4f *v2, hkVector4f *v3)
{
  __m128 v8; // xmm4

  v8 = _mm_shuffle_ps((__m128)LODWORD(error), (__m128)LODWORD(error), 0);
  v1->m_quad = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_unpacklo_ps(
                     _mm_unpacklo_ps(
                       (__m128)COERCE_UNSIGNED_INT((float)this->m_vertices.m_data[a]),
                       (__m128)COERCE_UNSIGNED_INT((float)this->m_vertices.m_data[a + 2])),
                     _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)this->m_vertices.m_data[a + 1]), (__m128)0i64)),
                   v8),
                 this->m_offset.m_quad);
  v2->m_quad = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_unpacklo_ps(
                     _mm_unpacklo_ps(
                       (__m128)COERCE_UNSIGNED_INT((float)this->m_vertices.m_data[b]),
                       (__m128)COERCE_UNSIGNED_INT((float)this->m_vertices.m_data[b + 2])),
                     _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)this->m_vertices.m_data[b + 1]), (__m128)0i64)),
                   v8),
                 this->m_offset.m_quad);
  v3->m_quad = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_unpacklo_ps(
                     _mm_unpacklo_ps(
                       (__m128)COERCE_UNSIGNED_INT((float)this->m_vertices.m_data[c]),
                       (__m128)COERCE_UNSIGNED_INT((float)this->m_vertices.m_data[c + 2])),
                     _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)this->m_vertices.m_data[c + 1]), (__m128)0i64)),
                   v8),
                 this->m_offset.m_quad);
}

// File Line: 320
// RVA: 0xD11260
__int64 __fastcall hkpCompressedMeshShape::Chunk::getNumTriangles(hkpCompressedMeshShape::Chunk *this)
{
  int v1; // er8
  int v2; // er9
  unsigned __int16 *v3; // r10
  signed __int64 v4; // rdx
  int v5; // eax

  v1 = 0;
  v2 = 0;
  if ( this->m_stripLengths.m_size > 0 )
  {
    v3 = this->m_stripLengths.m_data;
    v4 = 0i64;
    do
    {
      v5 = v3[v4++];
      v2 += v5;
      v1 = v3[v4 - 1] + v1 - 2;
    }
    while ( v4 < this->m_stripLengths.m_size );
  }
  return (unsigned int)(v1 + (this->m_indices.m_size - v2) / 3);
}

// File Line: 333
// RVA: 0xD10F30
signed __int64 __fastcall hkpCompressedMeshShape::isValidShapeKey(hkpCompressedMeshShape *this, unsigned int key)
{
  unsigned int v2; // eax
  signed int v3; // ebx
  int v4; // edi
  signed int v5; // ebx
  int v7; // eax
  hkpCompressedMeshShape::Chunk *v8; // rdx
  hkpCompressedMeshShape::Chunk *v9; // rcx
  unsigned __int16 v10; // ax
  int winding; // [rsp+38h] [rbp+10h]

  v2 = key >> this->m_bitsPerWIndex;
  v3 = key & this->m_wIndexMask;
  v4 = this->m_indexMask & v3;
  v5 = v3 >> this->m_bitsPerIndex;
  if ( v2 )
  {
    v7 = v2 - 1;
    if ( v7 >= this->m_chunks.m_size )
      return 2i64;
    v8 = this->m_chunks.m_data;
    v9 = &v8[v7];
    v10 = v9->m_reference;
    if ( v10 != -1 )
      v9 = &v8[v10];
    if ( hkpCompressedMeshShape::Chunk::getNextIndex(v9, v4 - 1, &winding) != v4 )
      return 3i64;
    if ( winding != v5 )
      return 4i64;
  }
  else if ( v5 )
  {
    return 1i64;
  }
  return 0i64;
}

// File Line: 379
// RVA: 0xD10930
void __fastcall hkpCompressedMeshShape::setWeldingInfo(hkpCompressedMeshShape *this, unsigned int key, __int16 weldingInfo)
{
  unsigned int v3; // er9
  int v4; // er9
  signed int v5; // er11
  hkpCompressedMeshShape::Chunk *v6; // rdx
  unsigned __int16 v7; // ax

  v3 = key >> this->m_bitsPerWIndex;
  if ( v3 )
  {
    v4 = v3 - 1;
    v5 = key & this->m_indexMask;
    v6 = this->m_chunks.m_data;
    v7 = v6[v4].m_reference;
    if ( v7 != -1 )
      v4 = v7;
    v6[v4].m_weldingInfo.m_data[v5] = weldingInfo;
  }
  else
  {
    this->m_bigTriangles.m_data[(signed int)key & (unsigned __int64)this->m_wIndexMask].m_weldingInfo = weldingInfo;
  }
}

// File Line: 400
// RVA: 0xD109B0
void __fastcall hkpCompressedMeshShape::initWeldingInfo(hkpCompressedMeshShape *this, hkpWeldingUtility::WeldingType weldingType)
{
  hkpCompressedMeshShape *v2; // r15
  int v3; // ebp
  __int64 v4; // r14
  hkpCompressedMeshShape::Chunk *v5; // rax
  int v6; // ebx
  hkpCompressedMeshShape::Chunk *v7; // rsi
  int v8; // eax
  int v9; // eax
  int v10; // er9
  int v11; // edx
  unsigned __int16 *v12; // rdi
  __int64 v13; // rcx
  hkResult result; // [rsp+68h] [rbp+10h]

  v2 = this;
  this->m_weldingType.m_storage = weldingType;
  if ( weldingType != 6 )
  {
    v3 = 0;
    if ( this->m_chunks.m_size > 0 )
    {
      v4 = 0i64;
      do
      {
        v5 = v2->m_chunks.m_data;
        v6 = v5[v4].m_indices.m_size;
        v7 = &v5[v4];
        v8 = v5[v4].m_weldingInfo.m_capacityAndFlags & 0x3FFFFFFF;
        if ( v8 >= v6 )
        {
          result.m_enum = 0;
        }
        else
        {
          v9 = 2 * v8;
          v10 = v6;
          if ( v6 < v9 )
            v10 = v9;
          hkArrayUtil::_reserve(
            &result,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &v7->m_weldingInfo,
            v10,
            2);
        }
        v11 = v6 - v7->m_weldingInfo.m_size;
        v12 = &v7->m_weldingInfo.m_data[v7->m_weldingInfo.m_size];
        v13 = v11;
        if ( v11 > 0 )
        {
          while ( v13 )
          {
            *v12 = 0;
            ++v12;
            --v13;
          }
        }
        ++v3;
        v7->m_weldingInfo.m_size = v6;
        ++v4;
      }
      while ( v3 < v2->m_chunks.m_size );
    }
  }
}

// File Line: 414
// RVA: 0xD10BB0
void __fastcall hkpCompressedMeshShape::setShapeKeyBitsPerIndex(hkpCompressedMeshShape *this, int bitsPerIndex)
{
  if ( bitsPerIndex != this->m_bitsPerWIndex )
  {
    this->m_bitsPerIndex = bitsPerIndex;
    this->m_bitsPerWIndex = bitsPerIndex + 1;
    this->m_wIndexMask = (1 << (bitsPerIndex + 1)) - 1;
    this->m_indexMask = (1 << bitsPerIndex) - 1;
  }
}

// File Line: 429
// RVA: 0xD11010
void __fastcall hkpCompressedMeshShape::Chunk::getTriangle(hkpCompressedMeshShape::Chunk *this, int index, float error, hkVector4f *v1, hkVector4f *v2, hkVector4f *v3)
{
  hkpCompressedMeshShape::Chunk::getTriangle(
    this,
    3 * this->m_indices.m_data[index],
    3 * this->m_indices.m_data[index + 1],
    3 * this->m_indices.m_data[index + 2],
    error,
    v1,
    v2,
    v3);
}

// File Line: 438
// RVA: 0xD112C0
void __fastcall hkpCompressedMeshShape::Chunk::getVertices(hkpCompressedMeshShape::Chunk *this, float quantization, hkQsTransformf *transform, hkArray<hkVector4f,hkContainerHeapAllocator> *vertices)
{
  hkArray<hkVector4f,hkContainerHeapAllocator> *v4; // rsi
  hkQsTransformf *v5; // r14
  hkpCompressedMeshShape::Chunk *v6; // rdi
  int v7; // eax
  int v8; // ebx
  int v9; // eax
  int v10; // er9
  __m128 v11; // xmm6
  int v12; // ebp
  __m128 v13; // xmm6
  signed __int64 v14; // rbx
  unsigned int v15; // edx
  hkVector4f b; // [rsp+30h] [rbp-38h]
  hkResult result; // [rsp+70h] [rbp+8h]
  float v18; // [rsp+78h] [rbp+10h]

  v18 = quantization;
  v4 = vertices;
  v5 = transform;
  v6 = this;
  v7 = vertices->m_capacityAndFlags & 0x3FFFFFFF;
  v8 = this->m_vertices.m_size / 3;
  if ( v7 < v8 )
  {
    v9 = 2 * v7;
    v10 = this->m_vertices.m_size / 3;
    if ( v8 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, v10, 16);
  }
  v11 = (__m128)LODWORD(v18);
  v12 = 0;
  v4->m_size = v8;
  v13 = _mm_shuffle_ps(v11, v11, 0);
  if ( v6->m_vertices.m_size > 0 )
  {
    v14 = 2i64;
    do
    {
      b.m_quad = _mm_add_ps(
                   _mm_mul_ps(
                     _mm_unpacklo_ps(
                       _mm_unpacklo_ps(
                         (__m128)COERCE_UNSIGNED_INT((float)v6->m_vertices.m_data[v14 - 2]),
                         (__m128)COERCE_UNSIGNED_INT((float)v6->m_vertices.m_data[v14])),
                       _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)v6->m_vertices.m_data[v14 - 1]), (__m128)0i64)),
                     v13),
                   v6->m_offset.m_quad);
      hkVector4f::setTransformedPos(&b, v5, &b);
      v14 += 3i64;
      v15 = (unsigned __int64)(1431655766i64 * v12) >> 32;
      v12 += 3;
      v4->m_data[(v15 >> 31) + v15] = (hkVector4f)b.m_quad;
    }
    while ( v12 < v6->m_vertices.m_size );
  }
}

// File Line: 454
// RVA: 0xD113F0
void __fastcall hkpCompressedMeshShape::ConvexPiece::getVertices(hkpCompressedMeshShape::ConvexPiece *this, float quantization, hkQsTransformf *transform, hkArray<hkVector4f,hkContainerHeapAllocator> *vertices)
{
  hkArray<hkVector4f,hkContainerHeapAllocator> *v4; // rsi
  hkQsTransformf *v5; // r14
  hkpCompressedMeshShape::ConvexPiece *v6; // rdi
  int v7; // eax
  int v8; // ebx
  int v9; // eax
  int v10; // er9
  __m128 v11; // xmm6
  int v12; // ebp
  __m128 v13; // xmm6
  signed __int64 v14; // rbx
  unsigned int v15; // edx
  hkVector4f b; // [rsp+30h] [rbp-38h]
  hkResult result; // [rsp+70h] [rbp+8h]
  float v18; // [rsp+78h] [rbp+10h]

  v18 = quantization;
  v4 = vertices;
  v5 = transform;
  v6 = this;
  v7 = vertices->m_capacityAndFlags & 0x3FFFFFFF;
  v8 = this->m_vertices.m_size / 3;
  if ( v7 < v8 )
  {
    v9 = 2 * v7;
    v10 = this->m_vertices.m_size / 3;
    if ( v8 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, v10, 16);
  }
  v11 = (__m128)LODWORD(v18);
  v12 = 0;
  v4->m_size = v8;
  v13 = _mm_shuffle_ps(v11, v11, 0);
  if ( v6->m_vertices.m_size > 0 )
  {
    v14 = 2i64;
    do
    {
      b.m_quad = _mm_add_ps(
                   _mm_mul_ps(
                     _mm_unpacklo_ps(
                       _mm_unpacklo_ps(
                         (__m128)COERCE_UNSIGNED_INT((float)v6->m_vertices.m_data[v14 - 2]),
                         (__m128)COERCE_UNSIGNED_INT((float)v6->m_vertices.m_data[v14])),
                       _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)v6->m_vertices.m_data[v14 - 1]), (__m128)0i64)),
                     v13),
                   v6->m_offset.m_quad);
      hkVector4f::setTransformedPos(&b, v5, &b);
      v14 += 3i64;
      v15 = (unsigned __int64)(1431655766i64 * v12) >> 32;
      v12 += 3;
      v4->m_data[(v15 >> 31) + v15] = (hkVector4f)b.m_quad;
    }
    while ( v12 < v6->m_vertices.m_size );
  }
}

// File Line: 495
// RVA: 0xD10BF0
void __fastcall hkpCompressedMeshShape::getAabb(hkpCompressedMeshShape *this, hkTransformf *localToWorld, float tolerance, hkAabb *out)
{
  hkVector4f v4; // xmm2
  __m128 v5; // xmm7
  __m128 v6; // xmm2
  __m128 v7; // xmm7
  __m128 v8; // xmm6
  __m128 v9; // xmm2
  float v10; // [rsp+40h] [rbp+18h]

  v10 = tolerance;
  v4.m_quad = (__m128)this->m_bounds.m_max;
  v5 = _mm_add_ps(this->m_bounds.m_min.m_quad, v4.m_quad);
  v6 = _mm_mul_ps(_mm_sub_ps(v4.m_quad, this->m_bounds.m_min.m_quad), (__m128)xmmword_141A711B0);
  v7 = _mm_mul_ps(v5, (__m128)xmmword_141A711B0);
  v8 = _mm_add_ps(
         _mm_add_ps(
           (__m128)_mm_srli_epi32(
                     _mm_slli_epi32(
                       (__m128i)_mm_mul_ps(_mm_shuffle_ps(v6, v6, 0), localToWorld->m_rotation.m_col0.m_quad),
                       1u),
                     1u),
           (__m128)_mm_srli_epi32(
                     _mm_slli_epi32(
                       (__m128i)_mm_mul_ps(_mm_shuffle_ps(v6, v6, 85), localToWorld->m_rotation.m_col1.m_quad),
                       1u),
                     1u)),
         _mm_add_ps(
           (__m128)_mm_srli_epi32(
                     _mm_slli_epi32(
                       (__m128i)_mm_mul_ps(_mm_shuffle_ps(v6, v6, 170), localToWorld->m_rotation.m_col2.m_quad),
                       1u),
                     1u),
           _mm_shuffle_ps((__m128)LODWORD(v10), (__m128)LODWORD(v10), 0)));
  v9 = _mm_add_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), localToWorld->m_rotation.m_col0.m_quad),
             _mm_mul_ps(_mm_shuffle_ps(v7, v7, 85), localToWorld->m_rotation.m_col1.m_quad)),
           _mm_mul_ps(_mm_shuffle_ps(v7, v7, 170), localToWorld->m_rotation.m_col2.m_quad)),
         localToWorld->m_translation.m_quad);
  out->m_max.m_quad = _mm_add_ps(v9, v8);
  out->m_min.m_quad = _mm_add_ps(
                        _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v8),
                        v9);
}

// File Line: 516
// RVA: 0x15CC950
_OWORD *dynamic_initializer_for__rotatedVerticesPool__()
{
  signed int v0; // ecx
  _OWORD *result; // rax

  v0 = 95;
  result = (_OWORD *)rotatedVerticesPool[0][0].m_vertices[2].m_quad.m128_f32;
  do
  {
    --v0;
    *(result - 2) = 0i64;
    *(result - 1) = 0i64;
    *result = 0i64;
    result += 3;
  }
  while ( v0 >= 0 );
  return result;
}

// File Line: 520
// RVA: 0xD102F0
hkpShape *__fastcall hkpCompressedMeshShape::getChildShape(hkpCompressedMeshShape *this, unsigned int key, char (*buffer)[512])
{
  hkpCompressedMeshShape *v3; // rsi
  unsigned int v4; // er9
  signed int v5; // er14
  int v6; // ebx
  char (*v7)[512]; // rdi
  signed int v8; // er15
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // r13
  hkpCompressedMeshShape::BigTriangle *v11; // r9
  unsigned __int16 v12; // ax
  hkVector4f *v13; // rcx
  unsigned __int16 v14; // ax
  signed __int64 v15; // rdi
  int v16; // eax
  __m128 v17; // xmm8
  __m128 v18; // xmm9
  hkFourTransposedPointsf *v19; // rcx
  __m128 v20; // xmm7
  unsigned int v21; // edx
  unsigned __int16 *v22; // rdi
  int v23; // edx
  int v24; // er13
  __m128 *v25; // rsi
  hkVector4f *v26; // r14
  signed __int64 v27; // r15
  __int64 v28; // r12
  bool v29; // zf
  __m128 v30; // xmm3
  __m128 v31; // xmm1
  int v32; // eax
  hkpShape *result; // rax
  float v34; // xmm0_4
  char v35; // bl
  char *v36; // rcx
  unsigned __int16 *v37; // rdx
  unsigned __int16 v38; // bx
  __m128 v39; // xmm0
  __m128 v40; // xmm1
  __m128 v41; // xmm2
  unsigned __int16 v42; // ax
  unsigned __int16 *v43; // rdx
  hkVector4f *v44; // r10
  int v45; // er14
  int v46; // er9
  signed __int64 v47; // rdx
  unsigned __int16 v48; // ax
  hkVector4f *v49; // rcx
  unsigned __int16 v50; // ax
  hkpCompressedMeshShape::Chunk *v51; // r11
  __m128 v52; // xmm1
  __m128 v53; // xmm0
  hkVector4f b; // [rsp+40h] [rbp-90h]
  hkVector4f v1; // [rsp+50h] [rbp-80h]
  hkVector4f v2; // [rsp+60h] [rbp-70h]
  hkQsTransformf a; // [rsp+70h] [rbp-60h]
  __m128 v58; // [rsp+A0h] [rbp-30h]
  __m128 v59; // [rsp+B0h] [rbp-20h]
  __m128 v60; // [rsp+C0h] [rbp-10h]
  int v61; // [rsp+150h] [rbp+80h]
  int v62; // [rsp+158h] [rbp+88h]
  hkVector4f *v63; // [rsp+168h] [rbp+98h]

  v3 = this;
  v4 = key >> *(_DWORD *)((char *)&this->m_shapeInfoCodecType + 1);
  v5 = key & this->m_userData;
  v6 = 0;
  v7 = buffer;
  v8 = (signed int)(key & this->m_userData) >> *(_DWORD *)&this->m_type.m_storage;
  if ( v4 == (1 << (32 - *((_BYTE *)&this->m_shapeInfoCodecType + 1))) - 1 )
  {
    a.m_translation = hkQsTransformf_identityStorage.m_translation;
    v1.m_quad = (__m128)hkQsTransformf_identityStorage.m_rotation;
    v2.m_quad = (__m128)hkQsTransformf_identityStorage.m_scale;
    if ( buffer )
    {
      hkpConvexVerticesShape::hkpConvexVerticesShape((hkpConvexVerticesShape *)buffer, *(float *)&this->vfptr);
      v10 = v9;
    }
    else
    {
      v10 = 0i64;
    }
    v11 = v3->m_bigTriangles.m_data;
    b.m_quad.m128_u64[0] = v10;
    v12 = v11[3 * v5 + 2].m_b;
    if ( v12 != -1 )
    {
      v13 = (hkVector4f *)&v3->m_materials16.m_data[24 * v12];
      a.m_translation = (hkVector4f)v13->m_quad;
      v1.m_quad = (__m128)v13[1];
      v2.m_quad = (__m128)v13[2];
    }
    v14 = v11[3 * v5 + 2].m_a;
    if ( v14 != -1 )
      v5 = v14;
    v15 = (signed __int64)&v11[3 * v5];
    v2.m_quad.m128_u64[0] = (unsigned __int64)&v11[3 * v5];
    v16 = (unsigned __int64)TlsGetValue(hkThreadNumber.m_slotID);
    v17 = (__m128)xmmword_141A712A0;
    v18 = _mm_shuffle_ps((__m128)LODWORD(v3->m_chunks.m_data), (__m128)LODWORD(v3->m_chunks.m_data), 0);
    v19 = rotatedVerticesPool[v16];
    v20 = _mm_xor_ps(
            (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
            (__m128)xmmword_141A712A0);
    v1.m_quad.m128_u64[0] = (unsigned __int64)rotatedVerticesPool[v16];
    v21 = (unsigned __int64)(1431655766i64 * *(signed int *)(v15 + 24)) >> 32;
    v22 = *(unsigned __int16 **)(v15 + 16);
    v23 = (v21 >> 31) + v21;
    v62 = v23;
    v61 = (v23 + 3) >> 2;
    a.m_translation.m_quad.m128_u64[0] = v61;
    if ( v61 > 0i64 )
    {
      v24 = v23 - 1;
      v63 = &v19->m_vertices[2];
      do
      {
        v25 = &a.m_scale.m_quad;
        v26 = &a.m_scale;
        v27 = 4i64;
        do
        {
          a.m_rotation.m_vec.m_quad = _mm_add_ps(
                                        _mm_mul_ps(
                                          _mm_unpacklo_ps(
                                            _mm_unpacklo_ps(
                                              (__m128)COERCE_UNSIGNED_INT((float)*v22),
                                              (__m128)COERCE_UNSIGNED_INT((float)v22[2])),
                                            _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)v22[1]), (__m128)0i64)),
                                          v18),
                                        *(__m128 *)v2.m_quad.m128_u64[0]);
          hkVector4f::setTransformedPos(v26, &a, &a.m_rotation.m_vec);
          v17 = _mm_min_ps(v17, *v25);
          v20 = _mm_max_ps(v20, *v25);
          if ( v6 < v24 )
          {
            ++v6;
            v22 += 3;
          }
          ++v26;
          ++v25;
          --v27;
        }
        while ( v27 );
        v28 = (__int64)&v63[3];
        v29 = a.m_translation.m_quad.m128_u64[0]-- == 1;
        v63 = (hkVector4f *)v28;
        v30 = _mm_shuffle_ps(a.m_scale.m_quad, v58, 68);
        v31 = _mm_shuffle_ps(v59, v60, 68);
        *(__m128 *)(v28 - 48) = _mm_shuffle_ps(
                                  _mm_shuffle_ps(a.m_scale.m_quad, v58, 238),
                                  _mm_shuffle_ps(v59, v60, 238),
                                  136);
        *(__m128 *)(v28 - 80) = _mm_shuffle_ps(v30, v31, 136);
        *(__m128 *)(v28 - 64) = _mm_shuffle_ps(v30, v31, 221);
      }
      while ( !v29 );
      v10 = b.m_quad.m128_u64[0];
      v19 = (hkFourTransposedPointsf *)v1.m_quad.m128_u64[0];
      v23 = v62;
    }
    v32 = v61;
    *(_QWORD *)(v10 + 80) = v19;
    *(_DWORD *)(v10 + 88) = v32;
    *(_DWORD *)(v10 + 92) = 8;
    *(_DWORD *)(v10 + 96) = v23;
    *(_BYTE *)(v10 + 100) = 1;
    result = (hkpShape *)v10;
    *(__m128 *)(v10 + 48) = _mm_mul_ps(_mm_sub_ps(v20, v17), (__m128)xmmword_141A711B0);
    *(__m128 *)(v10 + 64) = _mm_mul_ps(_mm_add_ps(v20, v17), (__m128)xmmword_141A711B0);
  }
  else
  {
    if ( buffer )
    {
      v34 = hkConvexShapeDefaultRadius;
      *(_DWORD *)&(*buffer)[8] = 0x1FFFF;
      *(_DWORD *)&(*buffer)[16] = 1026;
      *(float *)&(*buffer)[32] = v34;
      *(_QWORD *)&(*buffer)[24] = 0i64;
      *(_QWORD *)buffer = &hkpTriangleShape::`vftable;
      *(_DWORD *)&(*buffer)[40] = 393216;
      *(_OWORD *)&(*buffer)[96] = 0i64;
    }
    else
    {
      v7 = 0i64;
    }
    v35 = BYTE4(this->vfptr);
    *(_DWORD *)&(*v7)[32] = this->vfptr;
    (*v7)[42] = v35;
    if ( v4 )
    {
      v44 = this->m_bigVertices.m_data;
      v45 = HIDWORD(this->m_userData) & v5;
      v46 = v4 - 1;
      a.m_translation = 0i64;
      v1.m_quad = qi.m_vec.m_quad;
      v2.m_quad = query.m_quad;
      v47 = 6i64 * v46;
      v48 = v44[v47 + 5].m_quad.m128_u16[3];
      if ( v48 != -1 )
      {
        v49 = (hkVector4f *)&this->m_materials16.m_data[24 * v48];
        a.m_translation = (hkVector4f)v49->m_quad;
        v1.m_quad = (__m128)v49[1];
        v2.m_quad = (__m128)v49[2];
      }
      v50 = v44[v47 + 5].m_quad.m128_u16[2];
      if ( v50 != -1 )
        v46 = v50;
      v51 = (hkpCompressedMeshShape::Chunk *)&v44[6 * v46];
      if ( v35 != 6 )
        *(_WORD *)&(*v7)[40] = v51->m_weldingInfo.m_data[v45];
      hkpCompressedMeshShape::Chunk::getTriangle(
        v51,
        3 * v51->m_indices.m_data[v45],
        3 * v51->m_indices.m_data[v45 + 1],
        3 * v51->m_indices.m_data[v45 + 2],
        *(float *)&v3->m_chunks.m_data,
        &v1,
        &v2,
        &b);
      hkVector4f::setTransformedPos(&v1, &a, &v1);
      hkVector4f::setTransformedPos(&v2, &a, &v2);
      hkVector4f::setTransformedPos(&b, &a, &b);
      v52 = v2.m_quad;
      *(hkVector4f *)&(*v7)[16 * (2 * v8 + 3i64)] = (hkVector4f)v1.m_quad;
      v53 = b.m_quad;
      *(__m128 *)&(*v7)[64] = v52;
      *(__m128 *)&(*v7)[16 * (2 * (v8 ^ 1) + 3i64)] = v53;
    }
    else
    {
      v36 = this->m_materials8.m_data;
      v37 = (unsigned __int16 *)(&v3->m_transforms.m_data->m_translation.m_quad + v5);
      v38 = v37[6];
      v39 = *(__m128 *)&v36[16 * *v37];
      b.m_quad = *(__m128 *)&v36[16 * *v37];
      v40 = *(__m128 *)&v36[16 * v37[1]];
      v2.m_quad = *(__m128 *)&v36[16 * v37[1]];
      v41 = *(__m128 *)&v36[16 * v37[2]];
      v1.m_quad = *(__m128 *)&v36[16 * v37[2]];
      v42 = v37[7];
      if ( v42 != -1 )
      {
        v43 = v3->m_materials16.m_data;
        a.m_translation = *(hkVector4f *)&v43[24 * v42];
        v1.m_quad = *(__m128 *)&v43[24 * v42 + 8];
        v2.m_quad = *(__m128 *)&v43[24 * v42 + 16];
        hkVector4f::setTransformedPos(&b, &a, &b);
        hkVector4f::setTransformedPos(&v2, &a, &v2);
        hkVector4f::setTransformedPos(&v1, &a, &v1);
        v41 = v1.m_quad;
        v40 = v2.m_quad;
        v39 = b.m_quad;
      }
      *(_WORD *)&(*v7)[40] = v38;
      *(__m128 *)&(*v7)[48] = v39;
      *(__m128 *)&(*v7)[64] = v40;
      *(__m128 *)&(*v7)[80] = v41;
    }
    result = (hkpShape *)v7;
  }
  return result;
}

// File Line: 741
// RVA: 0xD10AB0
hkpMeshMaterial *__fastcall hkpCompressedMeshShape::getMaterial(hkpCompressedMeshShape *this, unsigned int key)
{
  hkpMeshMaterial *v2; // r11
  hkpCompressedMeshShape *v3; // r8
  int v4; // ecx
  unsigned int v5; // er10
  signed int v6; // er9
  unsigned int v7; // edx
  hkpCompressedMeshShape::Chunk *v8; // rdx
  signed __int64 v9; // rax
  unsigned __int16 v10; // cx

  v2 = this->m_meshMaterials;
  v3 = this;
  if ( v2 )
  {
    v4 = this->m_bitsPerWIndex;
    v5 = key >> v4;
    v6 = key & v3->m_indexMask;
    if ( !(key >> v4) )
    {
      v7 = v3->m_bigTriangles.m_data[v6].m_material;
      return (hkpMeshMaterial *)((char *)v2 + (signed int)(v7 * v3->m_materialStriding));
    }
    if ( v5 != (1 << (32 - v4)) - 1 )
    {
      v8 = v3->m_chunks.m_data;
      v9 = (signed __int64)&v8[v5 - 1];
      v10 = *(_WORD *)(v9 + 84);
      if ( v10 != -1 )
        v9 = (signed __int64)&v8[v10];
      v7 = *(_DWORD *)(v9 + 80);
      switch ( v3->m_materialType.m_storage )
      {
        case 1:
          return (hkpMeshMaterial *)((char *)v2 + (signed int)(v7 * v3->m_materialStriding));
        case 2:
          v7 = (unsigned __int8)v3->m_materials8.m_data[v7 + v6];
          return (hkpMeshMaterial *)((char *)v2 + (signed int)(v7 * v3->m_materialStriding));
        case 3:
          v7 = v3->m_materials16.m_data[v7 + v6];
          return (hkpMeshMaterial *)((char *)v2 + (signed int)(v7 * v3->m_materialStriding));
        case 4:
          v7 = v3->m_materials.m_data[v7 + v6];
          return (hkpMeshMaterial *)((char *)v2 + (signed int)(v7 * v3->m_materialStriding));
      }
    }
  }
  return 0i64;
}

// File Line: 800
// RVA: 0xD108F0
__int64 __fastcall hkpCompressedMeshShape::getCollisionFilterInfo(hkpCompressedMeshShape *this, unsigned int key)
{
  hkpCompressedMeshShape *v2; // rbx
  hkpMeshMaterial *v3; // rax
  __int64 result; // rax

  v2 = this;
  v3 = hkpCompressedMeshShape::getMaterial((hkpCompressedMeshShape *)((char *)this - 32), key);
  if ( v3 )
    result = v3->m_filterInfo;
  else
    result = v2->m_bounds.m_min.m_quad.m128_u32[0];
  return result;
}

