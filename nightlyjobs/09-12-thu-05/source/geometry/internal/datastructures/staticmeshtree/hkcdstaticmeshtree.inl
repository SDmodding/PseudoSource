// File Line: 660
// RVA: 0xDF2650
void __fastcall hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::clear(hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *this)
{
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *v1; // rbx
  int v2; // eax
  hkcdStaticMeshTreeBase::Section *v3; // rcx
  int v4; // eax
  __int64 v5; // rsi
  int *v6; // rdi
  int v7; // er8
  int v8; // eax
  int v9; // er8
  int v10; // er8
  int v11; // er8
  int v12; // er8
  int v13; // er8

  v1 = this;
  this->m_nodes.m_size = 0;
  this->m_domain.m_min = (hkVector4f)xmmword_141A712A0;
  this->m_domain.m_max.m_quad = _mm_xor_ps(
                                  (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                  this->m_domain.m_min.m_quad);
  v2 = this->m_sections.m_size;
  v3 = this->m_sections.m_data;
  v4 = v2 - 1;
  v5 = v4;
  if ( v4 >= 0 )
  {
    v6 = &v3->m_nodes.m_capacityAndFlags + 24 * v4;
    do
    {
      v7 = *v6;
      *(v6 - 1) = 0;
      if ( v7 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v6 - 3),
          4 * v7);
      *(_QWORD *)(v6 - 3) = 0i64;
      *v6 = 2147483648;
      v6 -= 24;
      --v5;
    }
    while ( v5 >= 0 );
  }
  v8 = v1->m_sections.m_capacityAndFlags;
  v1->m_sections.m_size = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_sections.m_data,
      96 * (v8 & 0x3FFFFFFF));
  v1->m_sections.m_data = 0i64;
  v1->m_sections.m_capacityAndFlags = 2147483648;
  v9 = v1->m_primitives.m_capacityAndFlags;
  v1->m_primitives.m_size = 0;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_primitives.m_data,
      4 * v9);
  v1->m_primitives.m_data = 0i64;
  v1->m_primitives.m_capacityAndFlags = 2147483648;
  v10 = v1->m_packedVertices.m_capacityAndFlags;
  v1->m_packedVertices.m_size = 0;
  if ( v10 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_packedVertices.m_data,
      4 * v10);
  v1->m_packedVertices.m_data = 0i64;
  v1->m_packedVertices.m_capacityAndFlags = 2147483648;
  v11 = v1->m_sharedVertices.m_capacityAndFlags;
  v1->m_sharedVertices.m_size = 0;
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_sharedVertices.m_data,
      8 * v11);
  v1->m_sharedVertices.m_data = 0i64;
  v1->m_sharedVertices.m_capacityAndFlags = 2147483648;
  v12 = v1->m_sharedVerticesIndex.m_capacityAndFlags;
  v1->m_sharedVerticesIndex.m_size = 0;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_sharedVerticesIndex.m_data,
      2 * (v12 & 0x3FFFFFFF));
  v1->m_sharedVerticesIndex.m_data = 0i64;
  v1->m_sharedVerticesIndex.m_capacityAndFlags = 2147483648;
  v13 = v1->m_primitiveDataRuns.m_capacityAndFlags;
  v1->m_primitiveDataRuns.m_size = 0;
  if ( v13 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_primitiveDataRuns.m_data,
      8 * v13);
  v1->m_primitiveDataRuns.m_capacityAndFlags = 2147483648;
  v1->m_primitiveDataRuns.m_data = 0i64;
}

// File Line: 673
// RVA: 0xDF3B50
__int64 __fastcall hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::getMemoryFootPrint(hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *this, hkcdStaticMeshTreeBase::MemoryStatistics *stats)
{
  hkcdStaticMeshTreeBase::MemoryStatistics *v2; // r10
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *v3; // r9
  int v4; // eax
  __int64 v5; // r8
  int v6; // ecx
  int v7; // edx
  int v8; // ecx
  int v9; // edx
  int v10; // er8
  int v11; // ecx
  int v12; // eax
  __int64 result; // rax

  v2 = stats;
  v3 = this;
  v4 = 0;
  stats->m_collisionSize = 5 * this->m_nodes.m_size;
  if ( this->m_sections.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      ++v4;
      ++v5;
      stats->m_collisionSize += 4 * *((_DWORD *)&this->m_sections.m_data[v5] - 22);
    }
    while ( v4 < this->m_sections.m_size );
  }
  stats->m_geometrySize = 160;
  v6 = 96 * this->m_sections.m_size + 160;
  stats->m_geometrySize = v6;
  v7 = v6 + 4 * v3->m_primitives.m_size;
  v2->m_geometrySize = v7;
  v8 = v7 + 4 * v3->m_packedVertices.m_size;
  v2->m_geometrySize = v8;
  v9 = v8 + 8 * v3->m_sharedVertices.m_size;
  v2->m_geometrySize = v9;
  v10 = v9 + 2 * v3->m_sharedVerticesIndex.m_size;
  v2->m_geometrySize = v10;
  v11 = 8 * v3->m_primitiveDataRuns.m_size;
  v12 = v11 + v2->m_collisionSize;
  v2->m_dataSize = v11;
  result = (unsigned int)(v10 + v12);
  v2->m_totalSize = result;
  return result;
}

// File Line: 713
// RVA: 0xDF3C00
signed __int64 __fastcall hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::getNextKey(hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *this, unsigned int primitiveKey)
{
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *v2; // rbx
  __int64 v3; // r8
  unsigned int v4; // er10
  int v5; // er9
  unsigned int v6; // edi
  __int64 v7; // rcx
  hkcdStaticMeshTreeBase::Primitive *v8; // rax
  int v9; // edx
  hkcdStaticMeshTreeBase::Primitive *v10; // r11
  int v11; // eax
  int v12; // ecx
  signed int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // er10

  v2 = this;
  v3 = primitiveKey >> 8;
  v4 = primitiveKey & 1;
  v5 = (unsigned __int8)primitiveKey >> 1;
  v6 = this->m_sections.m_data[v3].m_primitives.m_data;
  v7 = v5 + (this->m_sections.m_data[v3].m_primitives.m_data >> 8);
  v8 = v2->m_primitives.m_data;
  v9 = (unsigned __int8)v8[v7].m_indices[1];
  v10 = &v8[v7];
  v11 = (unsigned __int8)v8[v7].m_indices[3];
  v12 = (unsigned __int8)v10->m_indices[2];
  if ( v11 == v12 )
  {
    v13 = 1;
    if ( v12 == v9 )
      v13 = 3;
  }
  else if ( v10->m_indices[0] != -34 || v9 != 173 || v12 != 222 || v11 != 173 )
  {
    v13 = 2;
  }
  else
  {
    v13 = 0;
  }
  v14 = hkcdStaticMeshTreeBase::Primitive::g_typeToNumTriangles[v13];
  v15 = v4;
  v16 = v4 + 1;
  if ( v15 >= v14 - 1 )
  {
    ++v5;
    v16 = 0;
    if ( v5 >= (unsigned __int8)v6 )
    {
      LODWORD(v3) = v3 + 1;
      v5 = 0;
      if ( (signed int)v3 >= v2->m_sections.m_size )
        return 0xFFFFFFFFi64;
    }
  }
  if ( (signed int)v3 < 0 )
    return 0xFFFFFFFFi64;
  return v16 | 2 * ((unsigned int)v5 | ((_DWORD)v3 << 7));
}

// File Line: 753
// RVA: 0xDF41E0
void __fastcall hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::getTriangleVertices(hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *this, unsigned int primitiveKey, hkVector4f *verticesOut)
{
  hkVector4f v3; // xmm3
  __m128 v4; // xmm6
  signed int v5; // esi
  __int64 v6; // r11
  int v7; // er10
  hkVector4f *v8; // rbx
  __int64 v9; // rax
  hkVector4f v10; // xmm13
  __m128 v11; // xmm5
  __m128 v12; // xmm3
  hkcdStaticMeshTreeBase::Section *v13; // r8
  unsigned int *v14; // rbp
  unsigned __int64 *v15; // r14
  unsigned __int16 *v16; // rdx
  hkcdStaticMeshTreeBase::Primitive *v17; // rcx
  signed __int64 v18; // r8
  __m128i v19; // xmm7
  __m128i v20; // xmm8
  __m128i v21; // xmm9
  unsigned __int8 *v22; // rdx
  __m128i v23; // xmm10
  __m128i v24; // xmm11
  __m128i v25; // xmm12
  __int64 v26; // rax
  __m128i v27; // xmm2
  __m128 v28; // xmm4
  __int64 v29; // rax
  __m128i v30; // xmm2
  __int64 v31; // rax
  __m128i v32; // xmm2
  __int64 v33; // rax
  __m128i v34; // xmm2
  __m128 v35; // [rsp+10h] [rbp-148h]
  __m128 v36; // [rsp+20h] [rbp-138h]
  __m128 v37; // [rsp+30h] [rbp-128h]
  __int128 v38; // [rsp+90h] [rbp-C8h]
  __m128i v39; // [rsp+A0h] [rbp-B8h]

  v3.m_quad = (__m128)this->m_domain.m_max;
  v4 = 0i64;
  v5 = primitiveKey & 1;
  LODWORD(v6) = 0;
  v7 = (unsigned __int8)primitiveKey >> 1;
  v8 = verticesOut;
  v9 = primitiveKey >> 8;
  v10.m_quad = (__m128)this->m_domain.m_min;
  v11 = 0i64;
  _mm_store_si128((__m128i *)&v38, (__m128i)0i64);
  _mm_store_si128(&v39, (__m128i)0i64);
  v12 = _mm_mul_ps(
          _mm_sub_ps(v3.m_quad, v10.m_quad),
          (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::setupParameters'::`2'::invBitScalesBuffer);
  if ( (_DWORD)v9 == -1 )
  {
    v18 = v39.m128i_i64[1];
    v15 = (unsigned __int64 *)v39.m128i_i64[0];
    v14 = (unsigned int *)*((_QWORD *)&v38 + 1);
    v17 = (hkcdStaticMeshTreeBase::Primitive *)v38;
  }
  else
  {
    v13 = &this->m_sections.m_data[v9];
    v4 = *(__m128 *)v13->m_codecParms;
    v14 = &this->m_packedVertices.m_data[v13->m_firstPackedVertex];
    v6 = (unsigned __int8)v13->m_sharedVertices.m_data;
    v11 = (__m128)_mm_srli_si128(
                    _mm_slli_si128(
                      (__m128i)_mm_movelh_ps(
                                 (__m128)*(unsigned __int64 *)&v13->m_codecParms[3],
                                 (__m128)LODWORD(v13->m_codecParms[5])),
                      4),
                    4);
    v15 = &this->m_sharedVertices.m_data[(unsigned __int8)v13->m_page << 16];
    v16 = &this->m_sharedVerticesIndex.m_data[(unsigned __int64)v13->m_sharedVertices.m_data >> 8];
    v17 = &this->m_primitives.m_data[(unsigned __int64)v13->m_primitives.m_data >> 8];
    v18 = (signed __int64)&v16[-v6];
  }
  v19 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskZ);
  v20 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskY);
  v21 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskX);
  v22 = (unsigned __int8 *)&v17[v7];
  v23 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskZ);
  v24 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskY);
  v25 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskX);
  v26 = *v22;
  if ( (signed int)v26 < (signed int)v6 )
  {
    v28 = _mm_add_ps(
            _mm_mul_ps(
              _mm_cvtepi32_ps(
                _mm_or_si128(
                  _mm_or_si128(
                    _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32((__m128i)v14[v26], 0x16u), 0), v19),
                    _mm_and_si128((__m128i)v14[v26], v21)),
                  _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32((__m128i)v14[v26], 0xBu), 0), v20))),
              v11),
            v4);
  }
  else
  {
    v27 = _mm_loadl_epi64((const __m128i *)&v15[*(unsigned __int16 *)(v18 + 2i64 * *v22)]);
    v28 = _mm_add_ps(
            _mm_mul_ps(
              _mm_cvtepi32_ps(
                _mm_or_si128(
                  _mm_or_si128(
                    _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v27, 0xAu), 85), v23),
                    _mm_and_si128(v27, v25)),
                  _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v27, 2), 5u), v24))),
              v12),
            v10.m_quad);
  }
  v29 = v22[1];
  if ( (signed int)v29 < (signed int)v6 )
  {
    v35 = _mm_add_ps(
            _mm_mul_ps(
              _mm_cvtepi32_ps(
                _mm_or_si128(
                  _mm_or_si128(
                    _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32((__m128i)v14[v29], 0x16u), 0), v19),
                    _mm_and_si128((__m128i)v14[v29], v21)),
                  _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32((__m128i)v14[v29], 0xBu), 0), v20))),
              v11),
            v4);
  }
  else
  {
    v30 = _mm_loadl_epi64((const __m128i *)&v15[*(unsigned __int16 *)(v18 + 2i64 * v22[1])]);
    v35 = _mm_add_ps(
            _mm_mul_ps(
              _mm_cvtepi32_ps(
                _mm_or_si128(
                  _mm_or_si128(
                    _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v30, 0xAu), 85), v23),
                    _mm_and_si128(v30, v25)),
                  _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v30, 2), 5u), v24))),
              v12),
            v10.m_quad);
  }
  v31 = v22[2];
  if ( (signed int)v31 < (signed int)v6 )
  {
    v36 = _mm_add_ps(
            _mm_mul_ps(
              _mm_cvtepi32_ps(
                _mm_or_si128(
                  _mm_or_si128(
                    _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32((__m128i)v14[v31], 0x16u), 0), v19),
                    _mm_and_si128((__m128i)v14[v31], v21)),
                  _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32((__m128i)v14[v31], 0xBu), 0), v20))),
              v11),
            v4);
  }
  else
  {
    v32 = _mm_loadl_epi64((const __m128i *)&v15[*(unsigned __int16 *)(v18 + 2i64 * v22[2])]);
    v36 = _mm_add_ps(
            _mm_mul_ps(
              _mm_cvtepi32_ps(
                _mm_or_si128(
                  _mm_or_si128(
                    _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v32, 0xAu), 85), v23),
                    _mm_and_si128(v32, v25)),
                  _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v32, 2), 5u), v24))),
              v12),
            v10.m_quad);
  }
  v33 = v22[3];
  if ( (signed int)v33 < (signed int)v6 )
  {
    v37 = _mm_add_ps(
            _mm_mul_ps(
              _mm_cvtepi32_ps(
                _mm_or_si128(
                  _mm_or_si128(
                    _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32((__m128i)v14[v33], 0x16u), 0), v19),
                    _mm_and_si128((__m128i)v14[v33], v21)),
                  _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32((__m128i)v14[v33], 0xBu), 0), v20))),
              v11),
            v4);
  }
  else
  {
    v34 = _mm_loadl_epi64((const __m128i *)&v15[*(unsigned __int16 *)(v18 + 2i64 * v22[3])]);
    v37 = _mm_add_ps(
            _mm_mul_ps(
              _mm_cvtepi32_ps(
                _mm_or_si128(
                  _mm_or_si128(
                    _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v34, 0xAu), 85), v23),
                    _mm_and_si128(v34, v25)),
                  _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v34, 2), 5u), v24))),
              v12),
            v10.m_quad);
  }
  *v8 = (hkVector4f)v28;
  v8[1] = *((hkVector4f *)&v35 + v5);
  v8[2] = *((hkVector4f *)&v36 + v5);
}
  *v8 = (hkVector4f)v28;
  v8[1] = *((hkVector4f *)&v35 + v5);
  v8[2] = *((hkVector4f *)&v36 + v5);
}

// File Line: 772
// RVA: 0xDF3DE0
__int64 __fastcall hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::getQuadVertices(hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *this, unsigned int primitiveKey, hkVector4f *verticesOut)
{
  hkVector4f v3; // xmm6
  int v4; // er10
  __m128 v5; // xmm4
  __int64 v6; // rax
  hkVector4f *v7; // rdi
  __m128 v8; // xmm3
  __m128 v9; // xmm5
  int v10; // er11
  __int64 v11; // rbx
  hkcdStaticMeshTreeBase::Section *v12; // r8
  unsigned int *v13; // rbp
  unsigned __int64 *v14; // r14
  unsigned __int16 *v15; // rdx
  hkcdStaticMeshTreeBase::Primitive *v16; // rcx
  signed __int64 v17; // r8
  unsigned __int8 *v18; // rdx
  __int64 v19; // rax
  __m128i v20; // xmm2
  __int64 v21; // rax
  __m128i v22; // xmm2
  __int64 v23; // rax
  __m128i v24; // xmm2
  __int64 v25; // rax
  __m128i v26; // xmm2
  __int128 v28; // [rsp+50h] [rbp-58h]
  __m128i v29; // [rsp+60h] [rbp-48h]

  v3.m_quad = (__m128)this->m_domain.m_min;
  v4 = 0;
  v5 = 0i64;
  v6 = primitiveKey >> 8;
  v7 = verticesOut;
  v8 = _mm_mul_ps(
         _mm_sub_ps(this->m_domain.m_max.m_quad, v3.m_quad),
         (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::setupParameters'::`2'::invBitScalesBuffer);
  v9 = 0i64;
  _mm_store_si128((__m128i *)&v28, (__m128i)0i64);
  v10 = (unsigned __int8)primitiveKey >> 1;
  LODWORD(v11) = 0;
  _mm_store_si128(&v29, (__m128i)0i64);
  if ( (_DWORD)v6 == -1 )
  {
    v17 = v29.m128i_i64[1];
    v14 = (unsigned __int64 *)v29.m128i_i64[0];
    v13 = (unsigned int *)*((_QWORD *)&v28 + 1);
    v16 = (hkcdStaticMeshTreeBase::Primitive *)v28;
  }
  else
  {
    v12 = &this->m_sections.m_data[v6];
    v5 = *(__m128 *)v12->m_codecParms;
    v13 = &this->m_packedVertices.m_data[v12->m_firstPackedVertex];
    v11 = (unsigned __int8)v12->m_sharedVertices.m_data;
    v9 = (__m128)_mm_srli_si128(
                   _mm_slli_si128(
                     (__m128i)_mm_movelh_ps(
                                (__m128)*(unsigned __int64 *)&v12->m_codecParms[3],
                                (__m128)LODWORD(v12->m_codecParms[5])),
                     4),
                   4);
    v14 = &this->m_sharedVertices.m_data[(unsigned __int8)v12->m_page << 16];
    v15 = &this->m_sharedVerticesIndex.m_data[(unsigned __int64)v12->m_sharedVertices.m_data >> 8];
    v16 = &this->m_primitives.m_data[(unsigned __int64)v12->m_primitives.m_data >> 8];
    v17 = (signed __int64)&v15[-v11];
  }
  v18 = (unsigned __int8 *)&v16[v10];
  v19 = (unsigned __int8)v16[v10].m_indices[0];
  if ( (signed int)v19 < (signed int)v11 )
  {
    v7->m_quad = _mm_add_ps(
                   _mm_mul_ps(
                     _mm_cvtepi32_ps(
                       _mm_or_si128(
                         _mm_or_si128(
                           _mm_and_si128(
                             _mm_shuffle_epi32(_mm_srli_epi32((__m128i)v13[v19], 0x16u), 0),
                             (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskZ),
                           _mm_and_si128(
                             (__m128i)v13[v19],
                             (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskX)),
                         _mm_and_si128(
                           _mm_shuffle_epi32(_mm_srli_epi32((__m128i)v13[v19], 0xBu), 0),
                           (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskY))),
                     v9),
                   v5);
  }
  else
  {
    v20 = _mm_loadl_epi64((const __m128i *)&v14[*(unsigned __int16 *)(v17 + 2i64
                                                                          * (unsigned __int8)v16[v10].m_indices[0])]);
    v7->m_quad = _mm_add_ps(
                   _mm_mul_ps(
                     _mm_cvtepi32_ps(
                       _mm_or_si128(
                         _mm_or_si128(
                           _mm_and_si128(
                             _mm_shuffle_epi32(_mm_srli_epi32(v20, 0xAu), 85),
                             (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskZ),
                           _mm_and_si128(
                             v20,
                             (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskX)),
                         _mm_and_si128(
                           _mm_srli_epi32(_mm_slli_si128(v20, 2), 5u),
                           (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskY))),
                     v8),
                   v3.m_quad);
  }
  v21 = v18[1];
  if ( (signed int)v21 < (signed int)v11 )
  {
    v7[1].m_quad = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_cvtepi32_ps(
                         _mm_or_si128(
                           _mm_or_si128(
                             _mm_and_si128(
                               _mm_shuffle_epi32(_mm_srli_epi32((__m128i)v13[v21], 0x16u), 0),
                               (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskZ),
                             _mm_and_si128(
                               (__m128i)v13[v21],
                               (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskX)),
                           _mm_and_si128(
                             _mm_shuffle_epi32(_mm_srli_epi32((__m128i)v13[v21], 0xBu), 0),
                             (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskY))),
                       v9),
                     v5);
  }
  else
  {
    v22 = _mm_loadl_epi64((const __m128i *)&v14[*(unsigned __int16 *)(v17 + 2i64 * v18[1])]);
    v7[1].m_quad = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_cvtepi32_ps(
                         _mm_or_si128(
                           _mm_or_si128(
                             _mm_and_si128(
                               _mm_shuffle_epi32(_mm_srli_epi32(v22, 0xAu), 85),
                               (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskZ),
                             _mm_and_si128(
                               v22,
                               (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskX)),
                           _mm_and_si128(
                             _mm_srli_epi32(_mm_slli_si128(v22, 2), 5u),
                             (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskY))),
                       v8),
                     v3.m_quad);
  }
  v23 = v18[2];
  if ( (signed int)v23 < (signed int)v11 )
  {
    v7[2].m_quad = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_cvtepi32_ps(
                         _mm_or_si128(
                           _mm_or_si128(
                             _mm_and_si128(
                               _mm_shuffle_epi32(_mm_srli_epi32((__m128i)v13[v23], 0x16u), 0),
                               (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskZ),
                             _mm_and_si128(
                               (__m128i)v13[v23],
                               (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskX)),
                           _mm_and_si128(
                             _mm_shuffle_epi32(_mm_srli_epi32((__m128i)v13[v23], 0xBu), 0),
                             (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskY))),
                       v9),
                     v5);
  }
  else
  {
    v24 = _mm_loadl_epi64((const __m128i *)&v14[*(unsigned __int16 *)(v17 + 2i64 * v18[2])]);
    v7[2].m_quad = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_cvtepi32_ps(
                         _mm_or_si128(
                           _mm_or_si128(
                             _mm_and_si128(
                               _mm_shuffle_epi32(_mm_srli_epi32(v24, 0xAu), 85),
                               (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskZ),
                             _mm_and_si128(
                               v24,
                               (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskX)),
                           _mm_and_si128(
                             _mm_srli_epi32(_mm_slli_si128(v24, 2), 5u),
                             (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskY))),
                       v8),
                     v3.m_quad);
  }
  v25 = v18[3];
  if ( (signed int)v25 < (signed int)v11 )
  {
    v7[3].m_quad = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_cvtepi32_ps(
                         _mm_or_si128(
                           _mm_or_si128(
                             _mm_and_si128(
                               _mm_shuffle_epi32(_mm_srli_epi32((__m128i)v13[v25], 0x16u), 0),
                               (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskZ),
                             _mm_and_si128(
                               (__m128i)v13[v25],
                               (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskX)),
                           _mm_and_si128(
                             _mm_shuffle_epi32(_mm_srli_epi32((__m128i)v13[v25], 0xBu), 0),
                             (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskY))),
                       v9),
                     v5);
  }
  else
  {
    v26 = _mm_loadl_epi64((const __m128i *)&v14[*(unsigned __int16 *)(v17 + 2i64 * v18[3])]);
    v7[3].m_quad = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_cvtepi32_ps(
                         _mm_or_si128(
                           _mm_or_si128(
                             _mm_and_si128(
                               _mm_shuffle_epi32(_mm_srli_epi32(v26, 0xAu), 85),
                               (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskZ),
                             _mm_and_si128(
                               v26,
                               (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskX)),
                           _mm_and_si128(
                             _mm_srli_epi32(_mm_slli_si128(v26, 2), 5u),
                             (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskY))),
                       v8),
                     v3.m_quad);
  }
  LOBYTE(v4) = v18[2] != v18[3];
  return (unsigned int)(v4 + 1);
}

// File Line: 788
// RVA: 0xE09E30
__int64 __fastcall hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::getPrimitiveData(hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *this, unsigned int primitiveKey)
{
  __int64 v2; // rax
  int v3; // er11
  hkcdStaticMeshTreeBase::Section *v4; // rdx
  hkpBvCompressedMeshShapeTreeDataRun *v5; // rbx
  int v6; // er8
  int v7; // edx
  int i; // ecx
  int v9; // ecx
  int v10; // er9
  int v11; // er9
  unsigned __int8 *v12; // rdx
  int v13; // er8

  v2 = primitiveKey >> 8;
  v3 = (unsigned __int8)primitiveKey >> 1;
  v4 = 0i64;
  v5 = 0i64;
  if ( (_DWORD)v2 != -1 )
  {
    v4 = &this->m_sections.m_data[v2];
    v5 = &this->m_primitiveDataRuns.m_data[(unsigned __int64)v4->m_dataRuns.m_data >> 8];
  }
  v6 = 0;
  v7 = LOBYTE(v4->m_dataRuns.m_data) - 1;
  for ( i = v7 + 1; i > 4; i = v7 - v6 + 1 )
  {
    v9 = (v7 + v6) >> 1;
    v10 = v3 - (unsigned __int8)v5[v9].m_index;
    if ( v10 < 0 )
    {
      v7 = (v7 + v6) >> 1;
    }
    else
    {
      if ( v10 < (unsigned __int8)v5[v9].m_count )
        return v5[v9].m_value;
      v6 = v9 + 1;
    }
  }
  v11 = 0;
  v12 = (unsigned __int8 *)&v5[v6];
  if ( i <= 0 )
    return (unsigned int)MEMORY[0];
  while ( 1 )
  {
    v13 = v3 - v12[4];
    if ( v13 >= 0 && v13 < v12[5] )
      break;
    ++v11;
    v12 += 8;
    if ( v11 >= i )
      return (unsigned int)MEMORY[0];
  }
  return *(unsigned int *)v12;
}

// File Line: 1250
// RVA: 0xE069A0
void __fastcall hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverter::appendCustomPrimitiveToGeometry(hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverter *this, hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Decoder *decoder, int primitiveIndex, hkGeometry *geometry)
{
  int v4; // ebp
  signed __int64 v5; // rbx
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Decoder *v6; // rsi
  hkcdStaticMeshTreeBase::Primitive *v7; // rcx
  int *v8; // rdi
  hkGeometry *v9; // r15
  int v10; // edx
  int v11; // edx
  hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *v12; // rcx
  hkcdStaticMeshTreeBase::Section *v13; // r10
  signed int v14; // er9
  __int64 v15; // rdx
  __int64 v16; // r8
  char *v17; // rcx
  const unsigned __int16 *v18; // rcx
  __int64 v19; // rdx
  int v20; // er14
  unsigned __int16 v21; // r10
  unsigned int v22; // er9
  int v23; // er9
  int v24; // ebx
  hkOstream *v25; // rax
  hkOstream *v26; // rax
  hkVector4f v27; // xmm5
  int v28; // er9
  signed __int64 v29; // r11
  __m128 v30; // xmm4
  hkVector4f *v31; // r10
  unsigned int v32; // ecx
  __m128i v33; // xmm0
  __m128i v34; // xmm2
  __m128i v35; // xmm3
  int v36; // ecx
  int v37; // eax
  unsigned int v38; // eax
  hkVector4f *v39; // r10
  signed __int64 v40; // r8
  unsigned int v41; // ecx
  unsigned int v42; // eax
  hkVector4f v43; // xmm4
  int v44; // edx
  signed __int64 v45; // r10
  __m128i v46; // xmm5
  __m128i v47; // xmm6
  __m128i v48; // xmm7
  __m128 v49; // xmm3
  hkVector4f *v50; // r9
  __m128i v51; // xmm1
  int v52; // eax
  __m128i v53; // xmm1
  hkVector4f *v54; // r9
  signed __int64 v55; // r8
  int v56; // eax
  unsigned int v57; // ecx
  __m128i v58; // xmm1
  __m128i v59; // xmm3
  __m128i v60; // xmm4
  __m128i v61; // xmm5
  signed __int64 v62; // r10
  int v63; // ecx
  __m128 v64; // xmm6
  __m128 v65; // xmm7
  hkVector4f *v66; // rdx
  const __m128i *v67; // r9
  unsigned int v68; // eax
  __int64 v69; // r11
  __m128i v70; // xmm2
  __m128i v71; // xmm2
  __m128 v72; // xmm6
  __m128 v73; // xmm7
  hkVector4f *v74; // rdx
  signed __int64 v75; // r8
  __int64 v76; // rax
  __m128i v77; // xmm2
  hkpBvCompressedMeshShapeTreeDataRun *v78; // r11
  int v79; // edx
  int v80; // er9
  int i; // eax
  int v82; // ecx
  int v83; // er8
  __int64 v84; // rcx
  int v85; // er9
  signed __int64 v86; // rdx
  int v87; // er8
  hkAabb aabb; // [rsp+20h] [rbp-1258h]
  char buf; // [rsp+40h] [rbp-1238h]
  hkVector4f vertices[256]; // [rsp+240h] [rbp-1038h]

  v4 = primitiveIndex;
  v5 = primitiveIndex;
  v6 = decoder;
  v7 = &decoder->m_primitives[primitiveIndex];
  v8 = 0i64;
  v9 = geometry;
  v10 = (unsigned __int8)v7->m_indices[2];
  if ( (unsigned __int8)v7->m_indices[3] != v10 || v10 != (unsigned __int8)v7->m_indices[1] )
  {
    v13 = v6->m_section;
    v14 = 0;
    v15 = 0i64;
    v16 = v13->m_nodes.m_size;
    if ( v16 <= 0 )
    {
LABEL_9:
      v14 = -1;
    }
    else
    {
      v17 = &v13->m_nodes.m_data->m_data;
      while ( *v17 & 1 || v4 != (unsigned int)(unsigned __int8)*v17 >> 1 )
      {
        ++v15;
        ++v14;
        v17 += 4;
        if ( v15 >= v16 )
          goto LABEL_9;
      }
    }
    v11 = v14;
    v12 = (hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *)&v6->m_section->m_nodes;
  }
  else
  {
    v11 = (unsigned __int8)v7->m_indices[1];
    v12 = (hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *)&v6->m_section->m_nodes;
  }
  hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4>::getNodeAabb(v12, v11, &aabb);
  v18 = v6->m_sharedVerticesIndex;
  v19 = (unsigned __int8)v6->m_primitives[v5].m_indices[0];
  v20 = 256;
  v21 = v18[v19 + 1];
  if ( (signed int)((unsigned int)v18[v19] >> 8) < 256 )
    v20 = (unsigned int)v18[v19] >> 8;
  v22 = ((unsigned int)v18[v19] >> 4) & 3;
  if ( v22 )
  {
    v23 = v22 - 1;
    if ( v23 )
    {
      if ( v23 == 1 )
      {
        v27.m_quad = (__m128)aabb.m_min;
        v28 = 0;
        v29 = (signed __int64)&v6->m_sharedVertices[v21];
        v30 = _mm_mul_ps(
                _mm_sub_ps(aabb.m_max.m_quad, aabb.m_min.m_quad),
                (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned short,5,5>::setupParameters'::`2'::invBitScalesBuffer);
        if ( v20 - 1 > 0 )
        {
          v31 = vertices;
          do
          {
            v31 += 2;
            v32 = *(unsigned __int16 *)(v29 + 2i64 * (signed int)((v28 & 0xFFFFFFFC) - (v28 & 3) + 3));
            v33 = _mm_cvtsi32_si128(v32 >> 10);
            v34 = _mm_cvtsi32_si128((v32 >> 5) & 0x1F);
            v35 = _mm_cvtsi32_si128(*(_WORD *)(v29 + 2i64 * (signed int)((v28 & 0xFFFFFFFC) - (v28 & 3) + 3)) & 0x1F);
            v36 = v28 + 1;
            v37 = (v28 + 1) & 3;
            v28 += 2;
            v31[-2].m_quad = _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_cvtepi32_ps(
                                   _mm_unpacklo_epi32(
                                     _mm_unpacklo_epi32(v35, v33),
                                     _mm_unpacklo_epi32(v34, _mm_cvtsi32_si128(0)))),
                                 v30),
                               v27.m_quad);
            v38 = *(unsigned __int16 *)(v29 + 2i64 * (signed int)((v36 & 0xFFFFFFFC) - v37 + 3));
            v31[-1].m_quad = _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_cvtepi32_ps(
                                   _mm_unpacklo_epi32(
                                     _mm_unpacklo_epi32(_mm_cvtsi32_si128(v38 & 0x1F), _mm_cvtsi32_si128(v38 >> 10)),
                                     _mm_unpacklo_epi32(_mm_cvtsi32_si128((v38 >> 5) & 0x1F), _mm_cvtsi32_si128(0)))),
                                 v30),
                               v27.m_quad);
          }
          while ( v28 < v20 - 1 );
        }
        if ( v28 < (signed __int64)v20 )
        {
          v39 = &vertices[v28];
          v40 = v20 - (signed __int64)v28;
          do
          {
            ++v39;
            v41 = (v28 & 0xFFFFFFFC) - (v28 & 3);
            ++v28;
            v42 = *(unsigned __int16 *)(v29 + 2i64 * (signed int)(v41 + 3));
            v39[-1].m_quad = _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_cvtepi32_ps(
                                   _mm_unpacklo_epi32(
                                     _mm_unpacklo_epi32(
                                       _mm_cvtsi32_si128(*(_WORD *)(v29 + 2i64 * (signed int)(v41 + 3)) & 0x1F),
                                       _mm_cvtsi32_si128(v42 >> 10)),
                                     _mm_unpacklo_epi32(_mm_cvtsi32_si128((v42 >> 5) & 0x1F), _mm_cvtsi32_si128(0)))),
                                 v30),
                               v27.m_quad);
            --v40;
          }
          while ( v40 );
        }
      }
      else
      {
        hkErrStream::hkErrStream((hkErrStream *)&aabb, &buf, 512);
        v24 = ((unsigned int)v6->m_sharedVerticesIndex[(unsigned __int8)v6->m_primitives[v5].m_indices[0]] >> 4) & 3;
        v25 = hkOstream::operator<<((hkOstream *)&aabb, "Compression method #");
        v26 = hkOstream::operator<<(v25, v24, (int)v25);
        hkOstream::operator<<(v26, " not implemented");
        if ( (unsigned int)hkError::messageError(
                             -1875965459,
                             &buf,
                             "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Geometry/Internal/DataStructures/StaticMeshTree/hkcd"
                             "StaticMeshTree.inl",
                             499) )
          __debugbreak();
        hkOstream::~hkOstream((hkOstream *)&aabb);
      }
    }
    else
    {
      v43.m_quad = (__m128)aabb.m_min;
      v44 = 0;
      v45 = (signed __int64)&v6->m_sharedVertices[v21];
      v46 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskZ);
      v47 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskY);
      v48 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskX);
      v49 = _mm_mul_ps(
              _mm_sub_ps(aabb.m_max.m_quad, aabb.m_min.m_quad),
              (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::setupParameters'::`2'::invBitScalesBuffer);
      if ( v20 - 1 > 0 )
      {
        v50 = vertices;
        do
        {
          v50 += 2;
          v51 = (__m128i)*(unsigned int *)(v45 + 4i64 * (signed int)((v44 & 0xFFFFFFFE) - (v44 & 1) + 1));
          v52 = v44 + 1;
          v44 += 2;
          v50[-2].m_quad = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_cvtepi32_ps(
                                 _mm_or_si128(
                                   _mm_or_si128(
                                     _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v51, 0x16u), 0), v46),
                                     _mm_and_si128(v51, v48)),
                                   _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v51, 0xBu), 0), v47))),
                               v49),
                             v43.m_quad);
          v53 = (__m128i)*(unsigned int *)(v45 + 4i64 * (signed int)((v52 & 0xFFFFFFFE) - (v52 & 1) + 1));
          v50[-1].m_quad = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_cvtepi32_ps(
                                 _mm_or_si128(
                                   _mm_or_si128(
                                     _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v53, 0x16u), 0), v46),
                                     _mm_and_si128(v53, v48)),
                                   _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v53, 0xBu), 0), v47))),
                               v49),
                             v43.m_quad);
        }
        while ( v44 < v20 - 1 );
      }
      if ( v44 < (signed __int64)v20 )
      {
        v54 = &vertices[v44];
        v55 = v20 - (signed __int64)v44;
        do
        {
          ++v54;
          v56 = v44 & 1;
          v57 = v44++ & 0xFFFFFFFE;
          v58 = (__m128i)*(unsigned int *)(v45 + 4i64 * (signed int)(v57 - v56 + 1));
          v54[-1].m_quad = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_cvtepi32_ps(
                                 _mm_or_si128(
                                   _mm_or_si128(
                                     _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v58, 0x16u), 0), v46),
                                     _mm_and_si128(v58, v48)),
                                   _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v58, 0xBu), 0), v47))),
                               v49),
                             v43.m_quad);
          --v55;
        }
        while ( v55 );
      }
    }
  }
  else
  {
    v59 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskZ);
    v60 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskY);
    v61 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskX);
    v62 = (signed __int64)&v6->m_sharedVertices[v21];
    v63 = 0;
    if ( v20 - 1 > 0 )
    {
      v64 = v6->m_sharedParms.m_scale.m_quad;
      v65 = v6->m_sharedParms.m_origin.m_quad;
      v66 = vertices;
      v67 = (const __m128i *)v62;
      v68 = ((unsigned int)(v20 - 2) >> 1) + 1;
      v69 = v68;
      v63 = 2 * v68;
      do
      {
        v70 = _mm_loadl_epi64(v67);
        v66 += 2;
        ++v67;
        v66[-2].m_quad = _mm_add_ps(
                           _mm_mul_ps(
                             _mm_cvtepi32_ps(
                               _mm_or_si128(
                                 _mm_or_si128(
                                   _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v70, 0xAu), 85), v59),
                                   _mm_and_si128(v70, v61)),
                                 _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v70, 2), 5u), v60))),
                             v64),
                           v65);
        v71 = _mm_loadl_epi64((const __m128i *)((char *)v67 - 8));
        v66[-1].m_quad = _mm_add_ps(
                           _mm_mul_ps(
                             _mm_cvtepi32_ps(
                               _mm_or_si128(
                                 _mm_or_si128(
                                   _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v71, 0xAu), 85), v59),
                                   _mm_and_si128(v71, v61)),
                                 _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v71, 2), 5u), v60))),
                             v64),
                           v65);
        --v69;
      }
      while ( v69 );
    }
    if ( v63 < (signed __int64)v20 )
    {
      v72 = v6->m_sharedParms.m_scale.m_quad;
      v73 = v6->m_sharedParms.m_origin.m_quad;
      v74 = &vertices[v63];
      v75 = v20 - (signed __int64)v63;
      do
      {
        v76 = v63;
        ++v74;
        ++v63;
        v77 = _mm_loadl_epi64((const __m128i *)(v62 + 8 * v76));
        v74[-1].m_quad = _mm_add_ps(
                           _mm_mul_ps(
                             _mm_cvtepi32_ps(
                               _mm_or_si128(
                                 _mm_or_si128(
                                   _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v77, 0xAu), 85), v59),
                                   _mm_and_si128(v77, v61)),
                                 _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v77, 2), 5u), v60))),
                             v72),
                           v73);
        --v75;
      }
      while ( v75 );
    }
  }
  v78 = v6->m_primitiveDataRuns;
  v79 = LOBYTE(v6->m_section->m_dataRuns.m_data) - 1;
  v80 = 0;
  for ( i = LOBYTE(v6->m_section->m_dataRuns.m_data); i > 4; i = v79 - v80 + 1 )
  {
    v82 = (v80 + v79) >> 1;
    v83 = v4 - (unsigned __int8)v78[v82].m_index;
    if ( v83 < 0 )
    {
      v79 = (v80 + v79) >> 1;
    }
    else
    {
      if ( v83 < (unsigned __int8)v78[v82].m_count )
      {
        v8 = (int *)&v78[v82];
        goto LABEL_52;
      }
      v80 = v82 + 1;
    }
  }
  v84 = v80;
  v85 = 0;
  v86 = (signed __int64)&v78[v84];
  if ( i > 0 )
  {
    while ( 1 )
    {
      v87 = v4 - *(unsigned __int8 *)(v86 + 4);
      if ( v87 >= 0 && v87 < *(unsigned __int8 *)(v86 + 5) )
        break;
      ++v85;
      v86 += 8i64;
      if ( v85 >= i )
        goto LABEL_52;
    }
    v8 = (int *)v86;
  }
LABEL_52:
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverter::appendVerticesAsConvexHull(
    vertices,
    v20,
    *v8,
    v9);
}

// File Line: 1261
// RVA: 0xE09400
void __fastcall hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverter::appendVerticesAsConvexHull(hkVector4f *vertices, int numVertices, int material, hkGeometry *geometry)
{
  hkVector4f *v4; // rdi
  hkGeometry *v5; // rsi
  int v6; // er14
  int v7; // ebx
  hkgpConvexHull::BuildConfig *v8; // rax
  hkResult result; // [rsp+30h] [rbp-19h]
  hkgpConvexHull::BuildConfig v10; // [rsp+34h] [rbp-15h]
  hkgpConvexHull v11; // [rsp+48h] [rbp-1h]
  hkGeometry geometrya; // [rsp+70h] [rbp+27h]

  v4 = vertices;
  v5 = geometry;
  v6 = material;
  v7 = numVertices;
  hkgpConvexHull::hkgpConvexHull(&v11);
  hkgpConvexHull::BuildConfig::BuildConfig(&v10);
  if ( hkgpConvexHull::build(&v11, v4, v7, v8) >= 2 )
  {
    geometrya.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable';
    *(_DWORD *)&geometrya.m_memSizeAndFlags = 0x1FFFF;
    geometrya.m_vertices.m_data = 0i64;
    geometrya.m_vertices.m_size = 0;
    geometrya.m_vertices.m_capacityAndFlags = 2147483648;
    geometrya.m_triangles.m_data = 0i64;
    geometrya.m_triangles.m_size = 0;
    geometrya.m_triangles.m_capacityAndFlags = 2147483648;
    hkgpConvexHull::generateGeometry(&v11, 0, &geometrya, v6, 1);
    hkGeometry::appendGeometry(v5, &result, &geometrya, 0i64);
    geometrya.m_triangles.m_size = 0;
    if ( geometrya.m_triangles.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        geometrya.m_triangles.m_data,
        16 * geometrya.m_triangles.m_capacityAndFlags);
    geometrya.m_triangles.m_data = 0i64;
    geometrya.m_triangles.m_capacityAndFlags = 2147483648;
    geometrya.m_vertices.m_size = 0;
    if ( geometrya.m_vertices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        geometrya.m_vertices.m_data,
        16 * geometrya.m_vertices.m_capacityAndFlags);
  }
  hkgpConvexHull::~hkgpConvexHull(&v11);
}

// File Line: 1287
// RVA: 0xE09540
void __usercall hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::convertToGeometry(hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *this@<rcx>, int sectionIndex@<edx>, hkGeometry *geometry@<r8>, hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverter *gc@<r9>, hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverter *a5@<rbx>, int append, bool weld, hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::TriangleMaterial tm)
{
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverter *v8; // rsi
  hkGeometry *v9; // r13
  __int64 v10; // rdi
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *v11; // rbx
  __m128 v12; // xmm4
  signed __int64 v13; // r8
  unsigned __int64 v14; // r11
  signed int v15; // er14
  __m128 v16; // xmm5
  __m128 v17; // xmm3
  __m128 v18; // xmm6
  __m128 v19; // xmm3
  signed __int64 v20; // rdx
  int v21; // er12
  __int64 v22; // r15
  __m128i v23; // xmm7
  __m128i v24; // xmm8
  __m128i v25; // xmm9
  __m128i v26; // xmm10
  __m128i v27; // xmm11
  __m128i v28; // xmm12
  int v29; // edx
  int v30; // eax
  int v31; // ecx
  int *v32; // rdi
  int v33; // er9
  int v34; // er8
  int i; // ecx
  int v36; // ecx
  int v37; // edx
  __int64 v38; // rax
  int v39; // er9
  signed __int64 v40; // rdx
  int v41; // er8
  __int64 v42; // rax
  int v43; // er13
  __int64 v44; // r9
  __m128i v45; // xmm2
  __int64 v46; // rcx
  __int64 v47; // rax
  __m128i v48; // xmm2
  __int64 v49; // r8
  __m128i v50; // xmm2
  __int64 v51; // rdx
  __m128i v52; // xmm2
  int v53; // er14
  char v54; // si
  int v55; // er15
  int v56; // edi
  int v57; // er12
  int v58; // ebx
  int v59; // esi
  __m128 *v60; // rcx
  __int64 v61; // [rsp+20h] [rbp-D0h]
  __m128 v62; // [rsp+30h] [rbp-C0h]
  __m128 v63; // [rsp+40h] [rbp-B0h]
  __m128 v64; // [rsp+50h] [rbp-A0h]
  __m128 v65; // [rsp+60h] [rbp-90h]
  __int128 v66; // [rsp+70h] [rbp-80h]
  __int128 v67; // [rsp+80h] [rbp-70h]
  unsigned __int64 v68; // [rsp+90h] [rbp-60h]
  int v69; // [rsp+98h] [rbp-58h]
  __int64 v70; // [rsp+9Ch] [rbp-54h]
  __int64 v71; // [rsp+B0h] [rbp-40h]
  hkVector4f a; // [rsp+C0h] [rbp-30h]
  __m128 v73; // [rsp+D0h] [rbp-20h]
  __m128 v74; // [rsp+E0h] [rbp-10h]
  __m128 v75; // [rsp+F0h] [rbp+0h]
  hkErrStream v76; // [rsp+100h] [rbp+10h]
  char buf; // [rsp+120h] [rbp+30h]
  __int64 vars0; // [rsp+3D0h] [rbp+2E0h]
  hkArrayBase<hkVector4f> *v79; // [rsp+3E0h] [rbp+2F0h]
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverter *v80; // [rsp+3E8h] [rbp+2F8h]
  int v81; // [rsp+3F0h] [rbp+300h]
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverter *v82; // [rsp+3F8h] [rbp+308h]

  v82 = gc;
  v80 = a5;
  v8 = gc;
  v9 = geometry;
  v10 = sectionIndex;
  v11 = this;
  if ( !(_BYTE)geometry )
    hkGeometry::clear(geometry);
  v12 = 0i64;
  v13 = 0i64;
  v66 = (unsigned __int64)v11;
  v70 = -1i64;
  v14 = 0i64;
  v62 = 0i64;
  v63 = 0i64;
  v64 = 0i64;
  v68 = 0i64;
  v15 = 0;
  vars0 = 0i64;
  v65 = 0i64;
  _mm_store_si128((__m128i *)&v66, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v67, (__m128i)0i64);
  v69 = 0;
  v16 = 0i64;
  v17 = _mm_sub_ps(v11->m_domain.m_max.m_quad, v11->m_domain.m_min.m_quad);
  v63 = v17;
  v18 = v11->m_domain.m_min.m_quad;
  v19 = _mm_mul_ps(
          v17,
          (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::setupParameters'::`2'::invBitScalesBuffer);
  v62 = v11->m_domain.m_min.m_quad;
  v63 = v19;
  if ( (_DWORD)v10 != -1 )
  {
    v13 = (signed __int64)&v11->m_sections.m_data[v10];
    HIDWORD(v70) = v10;
    LODWORD(v70) = v10;
    *((_QWORD *)&v66 + 1) = v13;
    v20 = (signed __int64)&v11->m_packedVertices.m_data[*(unsigned int *)(v13 + 72)];
    vars0 = v13;
    *((_QWORD *)&v66 + 1) = v20;
    *(_QWORD *)&v67 = &v11->m_sharedVertices.m_data[*(unsigned __int8 *)(v13 + 92) << 16];
    *((_QWORD *)&v67 + 1) = &v11->m_sharedVerticesIndex.m_data[(unsigned __int64)*(unsigned int *)(v13 + 76) >> 8];
    v14 = (unsigned __int64)&v11->m_primitiveDataRuns.m_data[(unsigned __int64)*(unsigned int *)(v13 + 84) >> 8];
    v68 = (unsigned __int64)&v11->m_primitiveDataRuns.m_data[(unsigned __int64)*(unsigned int *)(v13 + 84) >> 8];
    v15 = *(unsigned __int8 *)(v13 + 76);
    v69 = *(unsigned __int8 *)(v13 + 76);
    *(_QWORD *)&v66 = &v11->m_primitives.m_data[(unsigned __int64)*(unsigned int *)(v13 + 80) >> 8];
    v12 = *(__m128 *)(v13 + 48);
    v64 = *(__m128 *)(v13 + 48);
    v16 = (__m128)_mm_srli_si128(
                    _mm_slli_si128(
                      (__m128i)_mm_movelh_ps(
                                 (__m128)*(unsigned __int64 *)(v13 + 60),
                                 (__m128)*(unsigned int *)(v13 + 68)),
                      4),
                    4);
    v65 = v16;
    *((_QWORD *)&v67 + 1) -= 2i64 * *(unsigned __int8 *)(v13 + 76);
  }
  v21 = 0;
  v22 = 0i64;
  v81 = 0;
  v61 = 0i64;
  v71 = *(unsigned __int8 *)(v13 + 80);
  if ( v71 > 0 )
  {
    v23 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskZ);
    v24 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskY);
    v25 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskX);
    v26 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskZ);
    v27 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskY);
    v28 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskX);
    do
    {
      v29 = *(unsigned __int8 *)(v66 + 4 * v22 + 3);
      v30 = *(unsigned __int8 *)(v66 + 4 * v22 + 2);
      v31 = *(unsigned __int8 *)(v66 + 4 * v22 + 1);
      if ( v29 == v30 )
      {
        if ( v30 == v31 )
        {
          if ( v8->vfptr->isKeyConvertionAllowed(v8, ((_DWORD)v70 << 8) | 2 * v21) )
            v8->vfptr->appendCustomPrimitiveToGeometry(
              v8,
              (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Decoder *)&v62,
              v21,
              v9);
          goto LABEL_11;
        }
      }
      else if ( *(_BYTE *)(v66 + 4 * v22) == -34 && v31 == 173 && v30 == 222 && v29 == 173 )
      {
        goto LABEL_60;
      }
      v32 = 0i64;
      v33 = 0;
      v34 = *(unsigned __int8 *)(v13 + 84) - 1;
      for ( i = v34 + 1; i > 4; i = v34 - v33 + 1 )
      {
        v36 = (v34 + v33) >> 1;
        v37 = v21 - *(unsigned __int8 *)(v14 + 8i64 * v36 + 4);
        if ( v37 < 0 )
        {
          v34 = (v34 + v33) >> 1;
        }
        else
        {
          if ( v37 < *(unsigned __int8 *)(v14 + 8i64 * v36 + 5) )
          {
            v32 = (int *)(v14 + 8i64 * v36);
            goto LABEL_29;
          }
          v33 = v36 + 1;
        }
      }
      v38 = v33;
      v39 = 0;
      v40 = v14 + 8 * v38;
      if ( i > 0 )
      {
        while ( 1 )
        {
          v41 = v21 - *(unsigned __int8 *)(v40 + 4);
          if ( v41 >= 0 && v41 < *(unsigned __int8 *)(v40 + 5) )
            break;
          ++v39;
          v40 += 8i64;
          if ( v39 >= i )
            goto LABEL_29;
        }
        v32 = (int *)v40;
      }
LABEL_29:
      v42 = *(unsigned __int8 *)(v66 + 4 * v22);
      v43 = *v32;
      v44 = v67;
      if ( (signed int)v42 < v15 )
      {
        v46 = *((_QWORD *)&v66 + 1);
        a.m_quad = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_cvtepi32_ps(
                         _mm_or_si128(
                           _mm_or_si128(
                             _mm_and_si128(
                               _mm_shuffle_epi32(
                                 _mm_srli_epi32((__m128i)*(unsigned int *)(*((_QWORD *)&v66 + 1) + 4 * v42), 0x16u),
                                 0),
                               v23),
                             _mm_and_si128((__m128i)*(unsigned int *)(*((_QWORD *)&v66 + 1) + 4 * v42), v25)),
                           _mm_and_si128(
                             _mm_shuffle_epi32(
                               _mm_srli_epi32((__m128i)*(unsigned int *)(*((_QWORD *)&v66 + 1) + 4 * v42), 0xBu),
                               0),
                             v24))),
                       v16),
                     v12);
      }
      else
      {
        v45 = _mm_loadl_epi64((const __m128i *)(v67
                                              + 8i64
                                              * *(unsigned __int16 *)(*((_QWORD *)&v67 + 1)
                                                                    + 2i64 * *(unsigned __int8 *)(v66 + 4 * v22))));
        v46 = *((_QWORD *)&v66 + 1);
        a.m_quad = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_cvtepi32_ps(
                         _mm_or_si128(
                           _mm_or_si128(
                             _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v45, 0xAu), 85), v26),
                             _mm_and_si128(v45, v28)),
                           _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v45, 2), 5u), v27))),
                       v19),
                     v18);
      }
      v47 = *(unsigned __int8 *)(v66 + 4 * v22 + 1);
      if ( (signed int)v47 < v15 )
      {
        v73 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(
                    _mm_or_si128(
                      _mm_or_si128(
                        _mm_and_si128(
                          _mm_shuffle_epi32(_mm_srli_epi32((__m128i)*(unsigned int *)(v46 + 4 * v47), 0x16u), 0),
                          v23),
                        _mm_and_si128((__m128i)*(unsigned int *)(v46 + 4 * v47), v25)),
                      _mm_and_si128(
                        _mm_shuffle_epi32(_mm_srli_epi32((__m128i)*(unsigned int *)(v46 + 4 * v47), 0xBu), 0),
                        v24))),
                  v16),
                v12);
      }
      else
      {
        v48 = _mm_loadl_epi64((const __m128i *)(v67
                                              + 8i64
                                              * *(unsigned __int16 *)(*((_QWORD *)&v67 + 1)
                                                                    + 2i64 * *(unsigned __int8 *)(v66 + 4 * v22 + 1))));
        v46 = *((_QWORD *)&v66 + 1);
        v73 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(
                    _mm_or_si128(
                      _mm_or_si128(
                        _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v48, 0xAu), 85), v26),
                        _mm_and_si128(v48, v28)),
                      _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v48, 2), 5u), v27))),
                  v19),
                v18);
      }
      v49 = *(unsigned __int8 *)(v66 + 4 * v22 + 2);
      if ( (signed int)v49 < v15 )
      {
        v74 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(
                    _mm_or_si128(
                      _mm_or_si128(
                        _mm_and_si128(
                          _mm_shuffle_epi32(_mm_srli_epi32((__m128i)*(unsigned int *)(v46 + 4 * v49), 0x16u), 0),
                          v23),
                        _mm_and_si128((__m128i)*(unsigned int *)(v46 + 4 * v49), v25)),
                      _mm_and_si128(
                        _mm_shuffle_epi32(_mm_srli_epi32((__m128i)*(unsigned int *)(v46 + 4 * v49), 0xBu), 0),
                        v24))),
                  v16),
                v12);
      }
      else
      {
        v50 = _mm_loadl_epi64((const __m128i *)(v67
                                              + 8i64
                                              * *(unsigned __int16 *)(*((_QWORD *)&v67 + 1)
                                                                    + 2i64 * *(unsigned __int8 *)(v66 + 4 * v22 + 2))));
        v46 = *((_QWORD *)&v66 + 1);
        v74 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(
                    _mm_or_si128(
                      _mm_or_si128(
                        _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v50, 0xAu), 85), v26),
                        _mm_and_si128(v50, v28)),
                      _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v50, 2), 5u), v27))),
                  v19),
                v18);
      }
      v51 = *(unsigned __int8 *)(v66 + 4 * v22 + 3);
      if ( (signed int)v51 < v15 )
      {
        v75 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(
                    _mm_or_si128(
                      _mm_or_si128(
                        _mm_and_si128(
                          _mm_shuffle_epi32(_mm_srli_epi32((__m128i)*(unsigned int *)(v46 + 4 * v51), 0x16u), 0),
                          v23),
                        _mm_and_si128((__m128i)*(unsigned int *)(v46 + 4 * v51), v25)),
                      _mm_and_si128(
                        _mm_shuffle_epi32(_mm_srli_epi32((__m128i)*(unsigned int *)(v46 + 4 * v51), 0xBu), 0),
                        v24))),
                  v16),
                v12);
      }
      else
      {
        v52 = _mm_loadl_epi64((const __m128i *)(v67
                                              + 8i64
                                              * *(unsigned __int16 *)(*((_QWORD *)&v67 + 1)
                                                                    + 2i64 * *(unsigned __int8 *)(v66 + 4 * v22 + 3))));
        v75 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(
                    _mm_or_si128(
                      _mm_or_si128(
                        _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v52, 0xAu), 85), v26),
                        _mm_and_si128(v52, v28)),
                      _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v52, 2), 5u), v27))),
                  v19),
                v18);
      }
      v53 = v79[1].m_size;
      v54 = 0;
      v55 = ((_BYTE)v49 != (_BYTE)v51) + 1;
      v56 = 0;
      if ( v55 <= 0 )
      {
        v13 = vars0;
        v9 = (hkGeometry *)v79;
        goto LABEL_59;
      }
      v57 = 2 * v21;
      do
      {
        v58 = v56 | v57 | ((_DWORD)v70 << 8);
        if ( ((unsigned __int8 (__fastcall *)(hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverter *, _QWORD, __int64, __int64))v80->vfptr->isKeyConvertionAllowed)(
               v80,
               v56 | (unsigned int)v57 | ((_DWORD)v70 << 8),
               v49,
               v44) )
        {
          v59 = 0;
          if ( append )
          {
            if ( append == 1 )
            {
              v59 = v58;
            }
            else
            {
              hkErrStream::hkErrStream(&v76, &buf, 512);
              hkOstream::operator<<((hkOstream *)&v76.vfptr, "Triangle material type not supported.");
              if ( (unsigned int)hkError::messageError(
                                   -560922122,
                                   &buf,
                                   "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Geometry/Internal/DataStructures/StaticMeshTre"
                                   "e/hkcdStaticMeshTree.inl",
                                   1317) )
                __debugbreak();
              hkOstream::~hkOstream((hkOstream *)&v76.vfptr);
            }
          }
          else
          {
            v59 = v43;
          }
          if ( v79[2].m_size == (v79[2].m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v79[2], 16);
          v60 = &v79[2].m_data[v79[2].m_size++].m_quad;
          HIDWORD(v60->m128_u64[1]) = v59;
          LODWORD(v60->m128_u64[0]) = v53;
          v54 = 1;
          HIDWORD(v60->m128_u64[0]) = v56 + v53 + 1;
          LODWORD(v60->m128_u64[1]) = v56 + v53 + 2;
        }
        ++v56;
      }
      while ( v56 < v55 );
      v9 = (hkGeometry *)v79;
      if ( v54 )
      {
        hkArrayBase<hkVector4f>::_append(
          v79 + 1,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &a,
          v55 + 2);
        v13 = *((_QWORD *)&v66 + 1);
        v14 = v68;
        v16 = v65;
        v12 = v64;
        v19 = v63;
        v21 = v81;
        vars0 = *((_QWORD *)&v66 + 1);
        v18 = v62;
        v26 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskZ);
        v27 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskY);
        v28 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskX);
        v23 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskZ);
        v24 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskY);
        v25 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskX);
LABEL_59:
        v22 = v61;
        goto LABEL_60;
      }
      v21 = v81;
      v22 = v61;
LABEL_11:
      v13 = *((_QWORD *)&v66 + 1);
      v14 = v68;
      v16 = v65;
      v12 = v64;
      v19 = v63;
      v18 = v62;
      vars0 = *((_QWORD *)&v66 + 1);
      v26 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskZ);
      v27 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskY);
      v28 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode'::`2'::maskX);
      v23 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskZ);
      v24 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskY);
      v25 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode'::`2'::maskX);
LABEL_60:
      v8 = v80;
      v15 = v69;
      ++v22;
      ++v21;
      v61 = v22;
      v81 = v21;
    }
    while ( v22 < v71 );
  }
  if ( (_BYTE)v82 )
    hkGeometryUtils::weldVertices(v9, 0.0);
}

