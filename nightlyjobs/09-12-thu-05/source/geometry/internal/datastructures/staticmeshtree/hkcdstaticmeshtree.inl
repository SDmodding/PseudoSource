// File Line: 660
// RVA: 0xDF2650
void __fastcall hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::clear(
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *this)
{
  int m_size; // eax
  hkcdStaticMeshTreeBase::Section *m_data; // rcx
  int v4; // eax
  __int64 v5; // rsi
  int *v6; // rdi
  int v7; // r8d
  int m_capacityAndFlags; // eax
  int v9; // r8d
  int v10; // r8d
  int v11; // r8d
  int v12; // r8d
  int v13; // r8d

  this->m_nodes.m_size = 0;
  this->m_domain.m_min = (hkVector4f)xmmword_141A712A0;
  this->m_domain.m_max.m_quad = _mm_xor_ps(
                                  (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                  this->m_domain.m_min.m_quad);
  m_size = this->m_sections.m_size;
  m_data = this->m_sections.m_data;
  v4 = m_size - 1;
  v5 = v4;
  if ( v4 >= 0 )
  {
    v6 = &m_data->m_nodes.m_capacityAndFlags + 24 * v4;
    do
    {
      v7 = *v6;
      *(v6 - 1) = 0;
      if ( v7 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, *(void **)(v6 - 3), 4 * v7);
      *(_QWORD *)(v6 - 3) = 0i64;
      *v6 = 0x80000000;
      v6 -= 24;
      --v5;
    }
    while ( v5 >= 0 );
  }
  m_capacityAndFlags = this->m_sections.m_capacityAndFlags;
  this->m_sections.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_sections.m_data,
      96 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_sections.m_data = 0i64;
  this->m_sections.m_capacityAndFlags = 0x80000000;
  v9 = this->m_primitives.m_capacityAndFlags;
  this->m_primitives.m_size = 0;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_primitives.m_data,
      4 * v9);
  this->m_primitives.m_data = 0i64;
  this->m_primitives.m_capacityAndFlags = 0x80000000;
  v10 = this->m_packedVertices.m_capacityAndFlags;
  this->m_packedVertices.m_size = 0;
  if ( v10 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_packedVertices.m_data,
      4 * v10);
  this->m_packedVertices.m_data = 0i64;
  this->m_packedVertices.m_capacityAndFlags = 0x80000000;
  v11 = this->m_sharedVertices.m_capacityAndFlags;
  this->m_sharedVertices.m_size = 0;
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_sharedVertices.m_data,
      8 * v11);
  this->m_sharedVertices.m_data = 0i64;
  this->m_sharedVertices.m_capacityAndFlags = 0x80000000;
  v12 = this->m_sharedVerticesIndex.m_capacityAndFlags;
  this->m_sharedVerticesIndex.m_size = 0;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_sharedVerticesIndex.m_data,
      2 * (v12 & 0x3FFFFFFF));
  this->m_sharedVerticesIndex.m_data = 0i64;
  this->m_sharedVerticesIndex.m_capacityAndFlags = 0x80000000;
  v13 = this->m_primitiveDataRuns.m_capacityAndFlags;
  this->m_primitiveDataRuns.m_size = 0;
  if ( v13 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_primitiveDataRuns.m_data,
      8 * v13);
  this->m_primitiveDataRuns.m_capacityAndFlags = 0x80000000;
  this->m_primitiveDataRuns.m_data = 0i64;
}

// File Line: 673
// RVA: 0xDF3B50
__int64 __fastcall hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::getMemoryFootPrint(
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *this,
        hkcdStaticMeshTreeBase::MemoryStatistics *stats)
{
  int v4; // eax
  __int64 v5; // r8
  int v6; // ecx
  int v7; // edx
  int v8; // ecx
  int v9; // edx
  int v10; // r8d
  int v11; // ecx
  int v12; // eax
  __int64 result; // rax

  v4 = 0;
  stats->m_collisionSize = 5 * this->m_nodes.m_size;
  if ( this->m_sections.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      ++v4;
      stats->m_collisionSize += 4 * this->m_sections.m_data[v5++].m_nodes.m_size;
    }
    while ( v4 < this->m_sections.m_size );
  }
  stats->m_geometrySize = 160;
  v6 = 96 * this->m_sections.m_size + 160;
  stats->m_geometrySize = v6;
  v7 = v6 + 4 * this->m_primitives.m_size;
  stats->m_geometrySize = v7;
  v8 = v7 + 4 * this->m_packedVertices.m_size;
  stats->m_geometrySize = v8;
  v9 = v8 + 8 * this->m_sharedVertices.m_size;
  stats->m_geometrySize = v9;
  v10 = v9 + 2 * this->m_sharedVerticesIndex.m_size;
  stats->m_geometrySize = v10;
  v11 = 8 * this->m_primitiveDataRuns.m_size;
  v12 = v11 + stats->m_collisionSize;
  stats->m_dataSize = v11;
  result = (unsigned int)(v10 + v12);
  stats->m_totalSize = result;
  return result;
}

// File Line: 713
// RVA: 0xDF3C00
__int64 __fastcall hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::getNextKey(
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *this,
        unsigned int primitiveKey)
{
  __int64 v3; // r8
  unsigned int v4; // r10d
  int v5; // r9d
  unsigned int m_data; // edi
  __int64 v7; // rcx
  hkcdStaticMeshTreeBase::Primitive *v8; // rax
  int v9; // edx
  hkcdStaticMeshTreeBase::Primitive *v10; // r11
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // ecx
  signed int v15; // eax
  unsigned int v16; // r10d

  v3 = primitiveKey >> 8;
  v4 = primitiveKey & 1;
  v5 = (unsigned __int8)primitiveKey >> 1;
  m_data = this->m_sections.m_data[v3].m_primitives.m_data;
  v7 = (int)(v5 + (m_data >> 8));
  v8 = this->m_primitives.m_data;
  v9 = (unsigned __int8)v8[v7].m_indices[1];
  v10 = &v8[v7];
  v11 = (unsigned __int8)v10->m_indices[3];
  v12 = (unsigned __int8)v10->m_indices[2];
  if ( v11 == v12 )
  {
    v13 = 1;
    if ( v12 == v9 )
      v13 = 3;
  }
  else if ( v10->m_indices[0] == -34 && v9 == 173 && v12 == 222 && v11 == 173 )
  {
    v13 = 0;
  }
  else
  {
    v13 = 2;
  }
  v14 = hkcdStaticMeshTreeBase::Primitive::g_typeToNumTriangles[v13];
  v15 = v4;
  v16 = v4 + 1;
  if ( v15 >= v14 - 1 )
  {
    ++v5;
    v16 = 0;
    if ( v5 >= (unsigned __int8)m_data )
    {
      LODWORD(v3) = v3 + 1;
      v5 = 0;
      if ( (int)v3 >= this->m_sections.m_size )
        return 0xFFFFFFFFi64;
    }
  }
  if ( (int)v3 < 0 )
    return 0xFFFFFFFFi64;
  return v16 | (2 * (v5 | ((_DWORD)v3 << 7)));
}

// File Line: 753
// RVA: 0xDF41E0
void __fastcall hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::getTriangleVertices(
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *this,
        unsigned int primitiveKey,
        hkVector4f *verticesOut)
{
  hkVector4f v3; // xmm3
  __m128 v4; // xmm6
  signed int v5; // esi
  __int64 m_data; // r11
  int v7; // r10d
  __int64 v9; // rax
  hkVector4f v10; // xmm13
  __m128 v11; // xmm5
  __m128 v12; // xmm3
  hkcdStaticMeshTreeBase::Section *v13; // r8
  unsigned int *v14; // rbp
  unsigned __int64 *v15; // r14
  unsigned __int16 *v16; // rdx
  hkcdStaticMeshTreeBase::Primitive *v17; // rcx
  unsigned __int16 *v18; // r8
  __m128i si128; // xmm7
  __m128i v20; // xmm8
  __m128i v21; // xmm9
  unsigned __int8 *v22; // rdx
  __m128i v23; // xmm10
  __m128i v24; // xmm11
  __m128i v25; // xmm12
  __int64 v26; // rax
  __m128i v27; // xmm2
  hkVector4f v28; // xmm4
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
  __int128 v39; // [rsp+A0h] [rbp-B8h]

  v3.m_quad = (__m128)this->m_domain.m_max;
  v4 = 0i64;
  v5 = primitiveKey & 1;
  LODWORD(m_data) = 0;
  v7 = (unsigned __int8)primitiveKey >> 1;
  v9 = primitiveKey >> 8;
  v10.m_quad = (__m128)this->m_domain.m_min;
  v11 = 0i64;
  v38 = 0i64;
  v39 = 0i64;
  v12 = _mm_mul_ps(
          _mm_sub_ps(v3.m_quad, v10.m_quad),
          (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::setupParameters::`2::invBitScalesBuffer);
  if ( (_DWORD)v9 == -1 )
  {
    v18 = (unsigned __int16 *)*((_QWORD *)&v39 + 1);
    v15 = (unsigned __int64 *)v39;
    v14 = (unsigned int *)*((_QWORD *)&v38 + 1);
    v17 = (hkcdStaticMeshTreeBase::Primitive *)v38;
  }
  else
  {
    v13 = &this->m_sections.m_data[v9];
    v4 = *(__m128 *)v13->m_codecParms;
    v14 = &this->m_packedVertices.m_data[v13->m_firstPackedVertex];
    m_data = (unsigned __int8)v13->m_sharedVertices.m_data;
    v11 = (__m128)_mm_srli_si128(
                    _mm_slli_si128(
                      (__m128i)_mm_movelh_ps(
                                 (__m128)*(unsigned __int64 *)&v13->m_codecParms[3],
                                 (__m128)LODWORD(v13->m_codecParms[5])),
                      4),
                    4);
    v15 = &this->m_sharedVertices.m_data[0x10000 * (unsigned __int8)v13->m_page];
    v16 = &this->m_sharedVerticesIndex.m_data[(unsigned __int64)v13->m_sharedVertices.m_data >> 8];
    v17 = &this->m_primitives.m_data[(unsigned __int64)v13->m_primitives.m_data >> 8];
    v18 = &v16[-m_data];
  }
  si128 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskZ);
  v20 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskY);
  v21 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskX);
  v22 = (unsigned __int8 *)&v17[v7];
  v23 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskZ);
  v24 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskY);
  v25 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskX);
  v26 = *v22;
  if ( (int)v26 < (int)m_data )
  {
    v28.m_quad = _mm_add_ps(
                   _mm_mul_ps(
                     _mm_cvtepi32_ps(
                       _mm_or_si128(
                         _mm_or_si128(
                           _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32((__m128i)v14[v26], 0x16u), 0), si128),
                           _mm_and_si128((__m128i)v14[v26], v21)),
                         _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32((__m128i)v14[v26], 0xBu), 0), v20))),
                     v11),
                   v4);
  }
  else
  {
    v27 = _mm_loadl_epi64((const __m128i *)&v15[v18[*v22]]);
    v28.m_quad = _mm_add_ps(
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
  if ( (int)v29 < (int)m_data )
  {
    v35 = _mm_add_ps(
            _mm_mul_ps(
              _mm_cvtepi32_ps(
                _mm_or_si128(
                  _mm_or_si128(
                    _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32((__m128i)v14[v29], 0x16u), 0), si128),
                    _mm_and_si128((__m128i)v14[v29], v21)),
                  _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32((__m128i)v14[v29], 0xBu), 0), v20))),
              v11),
            v4);
  }
  else
  {
    v30 = _mm_loadl_epi64((const __m128i *)&v15[v18[v22[1]]]);
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
  if ( (int)v31 < (int)m_data )
  {
    v36 = _mm_add_ps(
            _mm_mul_ps(
              _mm_cvtepi32_ps(
                _mm_or_si128(
                  _mm_or_si128(
                    _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32((__m128i)v14[v31], 0x16u), 0), si128),
                    _mm_and_si128((__m128i)v14[v31], v21)),
                  _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32((__m128i)v14[v31], 0xBu), 0), v20))),
              v11),
            v4);
  }
  else
  {
    v32 = _mm_loadl_epi64((const __m128i *)&v15[v18[v22[2]]]);
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
  if ( (int)v33 < (int)m_data )
  {
    v37 = _mm_add_ps(
            _mm_mul_ps(
              _mm_cvtepi32_ps(
                _mm_or_si128(
                  _mm_or_si128(
                    _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32((__m128i)v14[v33], 0x16u), 0), si128),
                    _mm_and_si128((__m128i)v14[v33], v21)),
                  _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32((__m128i)v14[v33], 0xBu), 0), v20))),
              v11),
            v4);
  }
  else
  {
    v34 = _mm_loadl_epi64((const __m128i *)&v15[v18[v22[3]]]);
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
  *verticesOut = (hkVector4f)v28.m_quad;
  verticesOut[1] = *((hkVector4f *)&v35 + v5);
  verticesOut[2] = *((hkVector4f *)&v36 + v5);
}

// File Line: 772
// RVA: 0xDF3DE0
__int64 __fastcall hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::getQuadVertices(
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *this,
        unsigned int primitiveKey,
        hkVector4f *verticesOut)
{
  hkVector4f v3; // xmm6
  int v4; // r10d
  __m128 v5; // xmm4
  __int64 v6; // rax
  __m128 v8; // xmm3
  __m128 v9; // xmm5
  int v10; // r11d
  __int64 m_data; // rbx
  hkcdStaticMeshTreeBase::Section *v12; // r8
  unsigned int *v13; // rbp
  unsigned __int64 *v14; // r14
  unsigned __int16 *v15; // rdx
  hkcdStaticMeshTreeBase::Primitive *v16; // rcx
  unsigned __int16 *v17; // r8
  unsigned __int8 *v18; // rdx
  __int64 v19; // rax
  __m128i v20; // xmm2
  __int64 v21; // rax
  __m128i v22; // xmm2
  __int64 v23; // rax
  __m128i v24; // xmm2
  __int64 v25; // rax
  __m128i v26; // xmm2

  v3.m_quad = (__m128)this->m_domain.m_min;
  v4 = 0;
  v5 = 0i64;
  v6 = primitiveKey >> 8;
  v8 = _mm_mul_ps(
         _mm_sub_ps(this->m_domain.m_max.m_quad, v3.m_quad),
         (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::setupParameters::`2::invBitScalesBuffer);
  v9 = 0i64;
  v10 = (unsigned __int8)primitiveKey >> 1;
  LODWORD(m_data) = 0;
  if ( (_DWORD)v6 == -1 )
  {
    v17 = 0i64;
    v14 = 0i64;
    v13 = 0i64;
    v16 = 0i64;
  }
  else
  {
    v12 = &this->m_sections.m_data[v6];
    v5 = *(__m128 *)v12->m_codecParms;
    v13 = &this->m_packedVertices.m_data[v12->m_firstPackedVertex];
    m_data = (unsigned __int8)v12->m_sharedVertices.m_data;
    v9 = (__m128)_mm_srli_si128(
                   _mm_slli_si128(
                     (__m128i)_mm_movelh_ps(
                                (__m128)*(unsigned __int64 *)&v12->m_codecParms[3],
                                (__m128)LODWORD(v12->m_codecParms[5])),
                     4),
                   4);
    v14 = &this->m_sharedVertices.m_data[0x10000 * (unsigned __int8)v12->m_page];
    v15 = &this->m_sharedVerticesIndex.m_data[(unsigned __int64)v12->m_sharedVertices.m_data >> 8];
    v16 = &this->m_primitives.m_data[(unsigned __int64)v12->m_primitives.m_data >> 8];
    v17 = &v15[-m_data];
  }
  v18 = (unsigned __int8 *)&v16[v10];
  v19 = *v18;
  if ( (int)v19 < (int)m_data )
  {
    verticesOut->m_quad = _mm_add_ps(
                            _mm_mul_ps(
                              _mm_cvtepi32_ps(
                                _mm_or_si128(
                                  _mm_or_si128(
                                    _mm_and_si128(
                                      _mm_shuffle_epi32(_mm_srli_epi32((__m128i)v13[v19], 0x16u), 0),
                                      (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskZ),
                                    _mm_and_si128(
                                      (__m128i)v13[v19],
                                      (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskX)),
                                  _mm_and_si128(
                                    _mm_shuffle_epi32(_mm_srli_epi32((__m128i)v13[v19], 0xBu), 0),
                                    (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskY))),
                              v9),
                            v5);
  }
  else
  {
    v20 = _mm_loadl_epi64((const __m128i *)&v14[v17[*v18]]);
    verticesOut->m_quad = _mm_add_ps(
                            _mm_mul_ps(
                              _mm_cvtepi32_ps(
                                _mm_or_si128(
                                  _mm_or_si128(
                                    _mm_and_si128(
                                      _mm_shuffle_epi32(_mm_srli_epi32(v20, 0xAu), 85),
                                      (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskZ),
                                    _mm_and_si128(
                                      v20,
                                      (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskX)),
                                  _mm_and_si128(
                                    _mm_srli_epi32(_mm_slli_si128(v20, 2), 5u),
                                    (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskY))),
                              v8),
                            v3.m_quad);
  }
  v21 = v18[1];
  if ( (int)v21 < (int)m_data )
  {
    verticesOut[1].m_quad = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_cvtepi32_ps(
                                  _mm_or_si128(
                                    _mm_or_si128(
                                      _mm_and_si128(
                                        _mm_shuffle_epi32(_mm_srli_epi32((__m128i)v13[v21], 0x16u), 0),
                                        (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskZ),
                                      _mm_and_si128(
                                        (__m128i)v13[v21],
                                        (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskX)),
                                    _mm_and_si128(
                                      _mm_shuffle_epi32(_mm_srli_epi32((__m128i)v13[v21], 0xBu), 0),
                                      (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskY))),
                                v9),
                              v5);
  }
  else
  {
    v22 = _mm_loadl_epi64((const __m128i *)&v14[v17[v18[1]]]);
    verticesOut[1].m_quad = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_cvtepi32_ps(
                                  _mm_or_si128(
                                    _mm_or_si128(
                                      _mm_and_si128(
                                        _mm_shuffle_epi32(_mm_srli_epi32(v22, 0xAu), 85),
                                        (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskZ),
                                      _mm_and_si128(
                                        v22,
                                        (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskX)),
                                    _mm_and_si128(
                                      _mm_srli_epi32(_mm_slli_si128(v22, 2), 5u),
                                      (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskY))),
                                v8),
                              v3.m_quad);
  }
  v23 = v18[2];
  if ( (int)v23 < (int)m_data )
  {
    verticesOut[2].m_quad = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_cvtepi32_ps(
                                  _mm_or_si128(
                                    _mm_or_si128(
                                      _mm_and_si128(
                                        _mm_shuffle_epi32(_mm_srli_epi32((__m128i)v13[v23], 0x16u), 0),
                                        (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskZ),
                                      _mm_and_si128(
                                        (__m128i)v13[v23],
                                        (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskX)),
                                    _mm_and_si128(
                                      _mm_shuffle_epi32(_mm_srli_epi32((__m128i)v13[v23], 0xBu), 0),
                                      (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskY))),
                                v9),
                              v5);
  }
  else
  {
    v24 = _mm_loadl_epi64((const __m128i *)&v14[v17[v18[2]]]);
    verticesOut[2].m_quad = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_cvtepi32_ps(
                                  _mm_or_si128(
                                    _mm_or_si128(
                                      _mm_and_si128(
                                        _mm_shuffle_epi32(_mm_srli_epi32(v24, 0xAu), 85),
                                        (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskZ),
                                      _mm_and_si128(
                                        v24,
                                        (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskX)),
                                    _mm_and_si128(
                                      _mm_srli_epi32(_mm_slli_si128(v24, 2), 5u),
                                      (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskY))),
                                v8),
                              v3.m_quad);
  }
  v25 = v18[3];
  if ( (int)v25 < (int)m_data )
  {
    verticesOut[3].m_quad = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_cvtepi32_ps(
                                  _mm_or_si128(
                                    _mm_or_si128(
                                      _mm_and_si128(
                                        _mm_shuffle_epi32(_mm_srli_epi32((__m128i)v13[v25], 0x16u), 0),
                                        (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskZ),
                                      _mm_and_si128(
                                        (__m128i)v13[v25],
                                        (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskX)),
                                    _mm_and_si128(
                                      _mm_shuffle_epi32(_mm_srli_epi32((__m128i)v13[v25], 0xBu), 0),
                                      (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskY))),
                                v9),
                              v5);
  }
  else
  {
    v26 = _mm_loadl_epi64((const __m128i *)&v14[v17[v18[3]]]);
    verticesOut[3].m_quad = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_cvtepi32_ps(
                                  _mm_or_si128(
                                    _mm_or_si128(
                                      _mm_and_si128(
                                        _mm_shuffle_epi32(_mm_srli_epi32(v26, 0xAu), 85),
                                        (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskZ),
                                      _mm_and_si128(
                                        v26,
                                        (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskX)),
                                    _mm_and_si128(
                                      _mm_srli_epi32(_mm_slli_si128(v26, 2), 5u),
                                      (__m128i)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskY))),
                                v8),
                              v3.m_quad);
  }
  LOBYTE(v4) = v18[2] != v18[3];
  return (unsigned int)(v4 + 1);
}

// File Line: 788
// RVA: 0xE09E30
__int64 __fastcall hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::getPrimitiveData(
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *this,
        unsigned int primitiveKey)
{
  __int64 v2; // rax
  int v3; // r11d
  hkcdStaticMeshTreeBase::Section *v4; // rdx
  hkpBvCompressedMeshShapeTreeDataRun *v5; // rbx
  int v6; // r8d
  int v7; // edx
  int i; // ecx
  int v9; // ecx
  hkpBvCompressedMeshShapeTreeDataRun *v10; // r10
  int v11; // r9d
  int v12; // r9d
  unsigned __int8 *v13; // rdx
  int v14; // r8d

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
    v10 = &v5[v9];
    v11 = v3 - (unsigned __int8)v10->m_index;
    if ( v11 < 0 )
    {
      v7 = (v7 + v6) >> 1;
    }
    else
    {
      if ( v11 < (unsigned __int8)v10->m_count )
        return v5[v9].m_value;
      v6 = v9 + 1;
    }
  }
  v12 = 0;
  v13 = (unsigned __int8 *)&v5[v6];
  if ( i <= 0 )
    return (unsigned int)MEMORY[0];
  while ( 1 )
  {
    v14 = v3 - v13[4];
    if ( v14 >= 0 && v14 < v13[5] )
      break;
    ++v12;
    v13 += 8;
    if ( v12 >= i )
      return (unsigned int)MEMORY[0];
  }
  return *(unsigned int *)v13;
}

// File Line: 1250
// RVA: 0xE069A0
void __fastcall hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverter::appendCustomPrimitiveToGeometry(
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverter *this,
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Decoder *decoder,
        int primitiveIndex,
        hkGeometry *geometry)
{
  __int64 v5; // rbx
  hkcdStaticMeshTreeBase::Primitive *v7; // rcx
  int *v8; // rdi
  int v10; // edx
  hkcdStaticMeshTreeBase::Section *m_section; // rcx
  hkcdStaticMeshTreeBase::Section *v12; // r10
  int v13; // r9d
  __int64 v14; // rdx
  __int64 m_size; // r8
  char *p_m_data; // rcx
  const unsigned __int16 *m_sharedVerticesIndex; // rcx
  __int64 v18; // rdx
  int v19; // r14d
  unsigned __int16 v20; // r10
  int v21; // r9d
  int v22; // r9d
  int v23; // ebx
  hkOstream *v24; // rax
  hkOstream *v25; // rax
  hkVector4f v26; // xmm5
  int v27; // r9d
  const unsigned __int64 *v28; // r11
  __m128 v29; // xmm4
  hkVector4f *v30; // r10
  unsigned int v31; // eax
  __m128i v32; // xmm0
  __m128i v33; // xmm2
  __m128i v34; // xmm3
  int v35; // ecx
  int v36; // eax
  unsigned int v37; // eax
  hkVector4f *v38; // r10
  __int64 v39; // r8
  unsigned int v40; // ecx
  unsigned int v41; // eax
  hkVector4f v42; // xmm4
  int v43; // edx
  const unsigned __int64 *v44; // r10
  __m128i si128; // xmm5
  __m128i v46; // xmm6
  __m128i v47; // xmm7
  __m128 v48; // xmm3
  hkVector4f *v49; // r9
  __m128i v50; // xmm1
  int v51; // eax
  __m128i v52; // xmm0
  hkVector4f *v53; // r9
  __int64 v54; // r8
  int v55; // eax
  unsigned int v56; // ecx
  __m128i v57; // xmm0
  __m128i v58; // xmm3
  __m128i v59; // xmm4
  __m128i v60; // xmm5
  const unsigned __int64 *v61; // r10
  int v62; // ecx
  hkVector4f v63; // xmm6
  hkVector4f v64; // xmm7
  hkVector4f *v65; // rdx
  const __m128i *v66; // r9
  unsigned int v67; // eax
  __int64 v68; // r11
  __m128i v69; // xmm2
  __m128i v70; // xmm2
  hkVector4f v71; // xmm6
  hkVector4f v72; // xmm7
  hkVector4f *v73; // rdx
  __int64 v74; // r8
  __int64 v75; // rax
  __m128i v76; // xmm2
  hkpBvCompressedMeshShapeTreeDataRun *m_primitiveDataRuns; // r11
  int v78; // edx
  int v79; // r9d
  int m_data_low; // eax
  int v81; // ecx
  hkpBvCompressedMeshShapeTreeDataRun *v82; // r10
  int v83; // r8d
  __int64 v84; // rcx
  int v85; // r9d
  hkpBvCompressedMeshShapeTreeDataRun *v86; // rdx
  int v87; // r8d
  hkAabb aabb; // [rsp+20h] [rbp-1258h] BYREF
  char buf[512]; // [rsp+40h] [rbp-1238h] BYREF
  hkVector4f vertices[256]; // [rsp+240h] [rbp-1038h] BYREF

  v5 = primitiveIndex;
  v7 = &decoder->m_primitives[v5];
  v8 = 0i64;
  if ( __PAIR64__((unsigned __int8)v7->m_indices[3], (unsigned __int8)v7->m_indices[2]) == __PAIR64__(
                                                                                             (unsigned __int8)v7->m_indices[2],
                                                                                             (unsigned __int8)v7->m_indices[1]) )
  {
    v10 = (unsigned __int8)v7->m_indices[1];
    m_section = decoder->m_section;
  }
  else
  {
    v12 = decoder->m_section;
    v13 = 0;
    v14 = 0i64;
    m_size = v12->m_nodes.m_size;
    if ( m_size <= 0 )
    {
LABEL_8:
      v13 = -1;
    }
    else
    {
      p_m_data = &v12->m_nodes.m_data->m_data;
      while ( (*p_m_data & 1) != 0 || primitiveIndex != (unsigned __int8)*p_m_data >> 1 )
      {
        ++v14;
        ++v13;
        p_m_data += 4;
        if ( v14 >= m_size )
          goto LABEL_8;
      }
    }
    v10 = v13;
    m_section = decoder->m_section;
  }
  hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4>::getNodeAabb(m_section, v10, &aabb);
  m_sharedVerticesIndex = decoder->m_sharedVerticesIndex;
  v18 = (unsigned __int8)decoder->m_primitives[v5].m_indices[0];
  v19 = 256;
  v20 = m_sharedVerticesIndex[v18 + 1];
  if ( HIBYTE(m_sharedVerticesIndex[v18]) < 0x100u )
    v19 = HIBYTE(m_sharedVerticesIndex[v18]);
  v21 = (m_sharedVerticesIndex[v18] >> 4) & 3;
  if ( v21 )
  {
    v22 = v21 - 1;
    if ( v22 )
    {
      if ( v22 == 1 )
      {
        v26.m_quad = (__m128)aabb.m_min;
        v27 = 0;
        v28 = &decoder->m_sharedVertices[v20];
        v29 = _mm_mul_ps(
                _mm_sub_ps(aabb.m_max.m_quad, aabb.m_min.m_quad),
                (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned short,5,5>::setupParameters::`2::invBitScalesBuffer);
        if ( v19 - 1 > 0 )
        {
          v30 = vertices;
          do
          {
            v30 += 2;
            v31 = *((unsigned __int16 *)v28 + (int)((v27 & 0xFFFFFFFC) - (v27 & 3) + 3));
            v32 = _mm_cvtsi32_si128(v31 >> 10);
            v33 = _mm_cvtsi32_si128((v31 >> 5) & 0x1F);
            v34 = _mm_cvtsi32_si128(*((_WORD *)v28 + (int)((v27 & 0xFFFFFFFC) - (v27 & 3) + 3)) & 0x1F);
            v35 = v27 + 1;
            v36 = (v27 + 1) & 3;
            v27 += 2;
            v30[-2].m_quad = _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_cvtepi32_ps(
                                   _mm_unpacklo_epi32(
                                     _mm_unpacklo_epi32(v34, v32),
                                     _mm_unpacklo_epi32(v33, _mm_cvtsi32_si128(0)))),
                                 v29),
                               v26.m_quad);
            v37 = *((unsigned __int16 *)v28 + (int)((v35 & 0xFFFFFFFC) - v36 + 3));
            v30[-1].m_quad = _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_cvtepi32_ps(
                                   _mm_unpacklo_epi32(
                                     _mm_unpacklo_epi32(_mm_cvtsi32_si128(v37 & 0x1F), _mm_cvtsi32_si128(v37 >> 10)),
                                     _mm_unpacklo_epi32(_mm_cvtsi32_si128((v37 >> 5) & 0x1F), _mm_cvtsi32_si128(0)))),
                                 v29),
                               v26.m_quad);
          }
          while ( v27 < v19 - 1 );
        }
        if ( v27 < (__int64)v19 )
        {
          v38 = &vertices[v27];
          v39 = v19 - (__int64)v27;
          do
          {
            ++v38;
            v40 = (v27 & 0xFFFFFFFC) - (v27 & 3);
            ++v27;
            v41 = *((unsigned __int16 *)v28 + (int)(v40 + 3));
            v38[-1].m_quad = _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_cvtepi32_ps(
                                   _mm_unpacklo_epi32(
                                     _mm_unpacklo_epi32(
                                       _mm_cvtsi32_si128(*((_WORD *)v28 + (int)(v40 + 3)) & 0x1F),
                                       _mm_cvtsi32_si128(v41 >> 10)),
                                     _mm_unpacklo_epi32(_mm_cvtsi32_si128((v41 >> 5) & 0x1F), _mm_cvtsi32_si128(0)))),
                                 v29),
                               v26.m_quad);
            --v39;
          }
          while ( v39 );
        }
      }
      else
      {
        hkErrStream::hkErrStream((hkErrStream *)&aabb, buf, 512);
        v23 = (decoder->m_sharedVerticesIndex[(unsigned __int8)decoder->m_primitives[v5].m_indices[0]] >> 4) & 3;
        v24 = hkOstream::operator<<((hkOstream *)&aabb, "Compression method #");
        v25 = hkOstream::operator<<(v24, v23);
        hkOstream::operator<<(v25, " not implemented");
        if ( (unsigned int)hkError::messageError(
                             0x902F09ED,
                             buf,
                             "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Geometry/Internal/DataStructures/StaticMeshTree/hkcd"
                             "StaticMeshTree.inl",
                             499) )
          __debugbreak();
        hkOstream::~hkOstream((hkOstream *)&aabb);
      }
    }
    else
    {
      v42.m_quad = (__m128)aabb.m_min;
      v43 = 0;
      v44 = &decoder->m_sharedVertices[v20];
      si128 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskZ);
      v46 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskY);
      v47 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskX);
      v48 = _mm_mul_ps(
              _mm_sub_ps(aabb.m_max.m_quad, aabb.m_min.m_quad),
              (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::setupParameters::`2::invBitScalesBuffer);
      if ( v19 - 1 > 0 )
      {
        v49 = vertices;
        do
        {
          v49 += 2;
          v50 = (__m128i)*((unsigned int *)v44 + (int)((v43 & 0xFFFFFFFE) - (v43 & 1) + 1));
          v51 = v43 + 1;
          v43 += 2;
          v49[-2].m_quad = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_cvtepi32_ps(
                                 _mm_or_si128(
                                   _mm_or_si128(
                                     _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v50, 0x16u), 0), si128),
                                     _mm_and_si128(v50, v47)),
                                   _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v50, 0xBu), 0), v46))),
                               v48),
                             v42.m_quad);
          v52 = (__m128i)*((unsigned int *)v44 + (int)((v51 & 0xFFFFFFFE) - (v51 & 1) + 1));
          v49[-1].m_quad = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_cvtepi32_ps(
                                 _mm_or_si128(
                                   _mm_or_si128(
                                     _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v52, 0x16u), 0), si128),
                                     _mm_and_si128(v52, v47)),
                                   _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v52, 0xBu), 0), v46))),
                               v48),
                             v42.m_quad);
        }
        while ( v43 < v19 - 1 );
      }
      if ( v43 < (__int64)v19 )
      {
        v53 = &vertices[v43];
        v54 = v19 - (__int64)v43;
        do
        {
          ++v53;
          v55 = v43 & 1;
          v56 = v43++ & 0xFFFFFFFE;
          v57 = (__m128i)*((unsigned int *)v44 + (int)(v56 - v55 + 1));
          v53[-1].m_quad = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_cvtepi32_ps(
                                 _mm_or_si128(
                                   _mm_or_si128(
                                     _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v57, 0x16u), 0), si128),
                                     _mm_and_si128(v57, v47)),
                                   _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v57, 0xBu), 0), v46))),
                               v48),
                             v42.m_quad);
          --v54;
        }
        while ( v54 );
      }
    }
  }
  else
  {
    v58 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskZ);
    v59 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskY);
    v60 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskX);
    v61 = &decoder->m_sharedVertices[v20];
    v62 = 0;
    if ( v19 - 1 > 0 )
    {
      v63.m_quad = (__m128)decoder->m_sharedParms.m_scale;
      v64.m_quad = (__m128)decoder->m_sharedParms.m_origin;
      v65 = vertices;
      v66 = (const __m128i *)v61;
      v67 = ((unsigned int)(v19 - 2) >> 1) + 1;
      v68 = v67;
      v62 = 2 * v67;
      do
      {
        v69 = _mm_loadl_epi64(v66);
        v65 += 2;
        ++v66;
        v65[-2].m_quad = _mm_add_ps(
                           _mm_mul_ps(
                             _mm_cvtepi32_ps(
                               _mm_or_si128(
                                 _mm_or_si128(
                                   _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v69, 0xAu), 85), v58),
                                   _mm_and_si128(v69, v60)),
                                 _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v69, 2), 5u), v59))),
                             v63.m_quad),
                           v64.m_quad);
        v70 = _mm_loadl_epi64((const __m128i *)((char *)v66 - 8));
        v65[-1].m_quad = _mm_add_ps(
                           _mm_mul_ps(
                             _mm_cvtepi32_ps(
                               _mm_or_si128(
                                 _mm_or_si128(
                                   _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v70, 0xAu), 85), v58),
                                   _mm_and_si128(v70, v60)),
                                 _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v70, 2), 5u), v59))),
                             v63.m_quad),
                           v64.m_quad);
        --v68;
      }
      while ( v68 );
    }
    if ( v62 < (__int64)v19 )
    {
      v71.m_quad = (__m128)decoder->m_sharedParms.m_scale;
      v72.m_quad = (__m128)decoder->m_sharedParms.m_origin;
      v73 = &vertices[v62];
      v74 = v19 - (__int64)v62;
      do
      {
        v75 = v62;
        ++v73;
        ++v62;
        v76 = _mm_loadl_epi64((const __m128i *)&v61[v75]);
        v73[-1].m_quad = _mm_add_ps(
                           _mm_mul_ps(
                             _mm_cvtepi32_ps(
                               _mm_or_si128(
                                 _mm_or_si128(
                                   _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v76, 0xAu), 85), v58),
                                   _mm_and_si128(v76, v60)),
                                 _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v76, 2), 5u), v59))),
                             v71.m_quad),
                           v72.m_quad);
        --v74;
      }
      while ( v74 );
    }
  }
  m_primitiveDataRuns = decoder->m_primitiveDataRuns;
  v78 = LOBYTE(decoder->m_section->m_dataRuns.m_data) - 1;
  v79 = 0;
  m_data_low = LOBYTE(decoder->m_section->m_dataRuns.m_data);
  if ( (unsigned int)m_data_low > 4 )
  {
    do
    {
      v81 = (v79 + v78) >> 1;
      v82 = &m_primitiveDataRuns[v81];
      v83 = primitiveIndex - (unsigned __int8)v82->m_index;
      if ( v83 < 0 )
      {
        v78 = (v79 + v78) >> 1;
      }
      else
      {
        if ( v83 < (unsigned __int8)v82->m_count )
        {
          v8 = (int *)&m_primitiveDataRuns[v81];
          goto LABEL_51;
        }
        v79 = v81 + 1;
      }
      m_data_low = v78 - v79 + 1;
    }
    while ( m_data_low > 4 );
  }
  v84 = v79;
  v85 = 0;
  v86 = &m_primitiveDataRuns[v84];
  if ( m_data_low > 0 )
  {
    while ( 1 )
    {
      v87 = primitiveIndex - (unsigned __int8)v86->m_index;
      if ( v87 >= 0 && v87 < (unsigned __int8)v86->m_count )
        break;
      ++v85;
      ++v86;
      if ( v85 >= m_data_low )
        goto LABEL_51;
    }
    v8 = (int *)v86;
  }
LABEL_51:
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverter::appendVerticesAsConvexHull(
    vertices,
    v19,
    *v8,
    geometry);
}

// File Line: 1261
// RVA: 0xE09400
void __fastcall hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverter::appendVerticesAsConvexHull(
        hkVector4f *vertices,
        int numVertices,
        int material,
        hkGeometry *geometry)
{
  hkgpConvexHull::BuildConfig *v8; // rax
  hkResult result; // [rsp+30h] [rbp-19h] BYREF
  hkgpConvexHull::BuildConfig v10; // [rsp+34h] [rbp-15h] BYREF
  hkgpConvexHull v11; // [rsp+48h] [rbp-1h] BYREF
  hkGeometry geometrya; // [rsp+70h] [rbp+27h] BYREF

  hkgpConvexHull::hkgpConvexHull(&v11);
  hkgpConvexHull::BuildConfig::BuildConfig(&v10);
  if ( hkgpConvexHull::build(&v11, vertices, numVertices, v8) >= 2 )
  {
    geometrya.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable;
    *(_DWORD *)&geometrya.m_memSizeAndFlags = 0x1FFFF;
    geometrya.m_vertices.m_data = 0i64;
    geometrya.m_vertices.m_size = 0;
    geometrya.m_vertices.m_capacityAndFlags = 0x80000000;
    geometrya.m_triangles.m_data = 0i64;
    geometrya.m_triangles.m_size = 0;
    geometrya.m_triangles.m_capacityAndFlags = 0x80000000;
    hkgpConvexHull::generateGeometry(&v11, SOURCE_VERTICES, &geometrya, material, 1);
    hkGeometry::appendGeometry(geometry, &result, &geometrya, 0i64);
    geometrya.m_triangles.m_size = 0;
    if ( geometrya.m_triangles.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        geometrya.m_triangles.m_data,
        16 * geometrya.m_triangles.m_capacityAndFlags);
    geometrya.m_triangles.m_data = 0i64;
    geometrya.m_triangles.m_capacityAndFlags = 0x80000000;
    geometrya.m_vertices.m_size = 0;
    if ( geometrya.m_vertices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        geometrya.m_vertices.m_data,
        16 * geometrya.m_vertices.m_capacityAndFlags);
  }
  hkgpConvexHull::~hkgpConvexHull(&v11);
}

// File Line: 1287
// RVA: 0xE09540
void __fastcall hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::convertToGeometry(
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun> *this,
        int sectionIndex,
        hkGeometry *geometry,
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverter *gc,
        int append,
        bool weld,
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::TriangleMaterial tm)
{
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverter *v7; // rbx
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverter *v8; // rsi
  hkGeometry *v9; // r13
  __int64 v10; // rdi
  __m128 v12; // xmm4
  hkcdStaticMeshTreeBase::Section *v13; // r8
  hkpBvCompressedMeshShapeTreeDataRun *v14; // r11
  int m_data_low; // r14d
  __m128 v16; // xmm5
  hkVector4f v17; // xmm6
  __m128 v18; // xmm3
  unsigned int *v19; // rdx
  int v20; // r12d
  __int64 v21; // r15
  __m128i si128; // xmm7
  __m128i v23; // xmm8
  __m128i v24; // xmm9
  __m128i v25; // xmm10
  __m128i v26; // xmm11
  __m128i v27; // xmm12
  int v28; // edx
  int v29; // eax
  int v30; // ecx
  hkpBvCompressedMeshShapeTreeDataRun *v31; // rdi
  int v32; // r9d
  int v33; // r8d
  int i; // ecx
  int v35; // ecx
  int v36; // edx
  __int64 v37; // rax
  int v38; // r9d
  hkpBvCompressedMeshShapeTreeDataRun *v39; // rdx
  int v40; // r8d
  __int64 v41; // rax
  unsigned int m_value; // r13d
  __int64 v43; // r9
  __m128i v44; // xmm2
  __int64 v45; // rcx
  __int64 v46; // rax
  __m128i v47; // xmm2
  __int64 v48; // r8
  __m128i v49; // xmm2
  __int64 v50; // rdx
  __m128i v51; // xmm2
  int m_size; // r14d
  char v53; // si
  int v54; // r15d
  int v55; // edi
  int v56; // r12d
  unsigned int v57; // ebx
  unsigned int v58; // esi
  __m128 *p_m_quad; // rcx
  __int64 v60; // [rsp+20h] [rbp-D0h]
  __m128 m_quad; // [rsp+30h] [rbp-C0h] BYREF
  __m128 v62; // [rsp+40h] [rbp-B0h]
  __m128 v63; // [rsp+50h] [rbp-A0h]
  __m128 v64; // [rsp+60h] [rbp-90h]
  __int128 v65; // [rsp+70h] [rbp-80h]
  __int128 v66; // [rsp+80h] [rbp-70h]
  hkpBvCompressedMeshShapeTreeDataRun *v67; // [rsp+90h] [rbp-60h]
  int v68; // [rsp+98h] [rbp-58h]
  __int64 v69; // [rsp+9Ch] [rbp-54h]
  __int64 v70; // [rsp+B0h] [rbp-40h]
  hkVector4f a; // [rsp+C0h] [rbp-30h] BYREF
  __m128 v72; // [rsp+D0h] [rbp-20h]
  __m128 v73; // [rsp+E0h] [rbp-10h]
  __m128 v74; // [rsp+F0h] [rbp+0h]
  hkErrStream v75; // [rsp+100h] [rbp+10h] BYREF
  char buf[528]; // [rsp+120h] [rbp+30h] BYREF
  hkcdStaticMeshTreeBase::Section *vars0; // [rsp+3D0h] [rbp+2E0h]
  hkArrayBase<hkVector4f> *v78; // [rsp+3E0h] [rbp+2F0h]
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverter *v79; // [rsp+3E8h] [rbp+2F8h]
  int v80; // [rsp+3F0h] [rbp+300h]
  char v81; // [rsp+3F8h] [rbp+308h]

  v81 = (char)gc;
  v79 = v7;
  v8 = gc;
  v9 = geometry;
  v10 = sectionIndex;
  if ( !(_BYTE)geometry )
    hkGeometry::clear(geometry);
  v12 = 0i64;
  v13 = 0i64;
  v69 = -1i64;
  v14 = 0i64;
  m_quad = 0i64;
  v62 = 0i64;
  v63 = 0i64;
  v67 = 0i64;
  m_data_low = 0;
  vars0 = 0i64;
  v64 = 0i64;
  v65 = 0i64;
  v66 = 0i64;
  v68 = 0;
  v16 = 0i64;
  v62 = _mm_sub_ps(this->m_domain.m_max.m_quad, this->m_domain.m_min.m_quad);
  v17.m_quad = (__m128)this->m_domain.m_min;
  v18 = _mm_mul_ps(
          v62,
          (__m128)`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::setupParameters::`2::invBitScalesBuffer);
  m_quad = v17.m_quad;
  v62 = v18;
  if ( (_DWORD)v10 != -1 )
  {
    v13 = &this->m_sections.m_data[v10];
    HIDWORD(v69) = v10;
    LODWORD(v69) = v10;
    *((_QWORD *)&v65 + 1) = v13;
    v19 = &this->m_packedVertices.m_data[v13->m_firstPackedVertex];
    vars0 = v13;
    *((_QWORD *)&v65 + 1) = v19;
    *(_QWORD *)&v66 = &this->m_sharedVertices.m_data[0x10000 * (unsigned __int8)v13->m_page];
    *((_QWORD *)&v66 + 1) = &this->m_sharedVerticesIndex.m_data[(unsigned __int64)v13->m_sharedVertices.m_data >> 8];
    v14 = &this->m_primitiveDataRuns.m_data[(unsigned __int64)v13->m_dataRuns.m_data >> 8];
    v67 = v14;
    m_data_low = LOBYTE(v13->m_sharedVertices.m_data);
    v68 = m_data_low;
    *(_QWORD *)&v65 = &this->m_primitives.m_data[(unsigned __int64)v13->m_primitives.m_data >> 8];
    v12 = *(__m128 *)v13->m_codecParms;
    v63 = v12;
    v16 = (__m128)_mm_srli_si128(
                    _mm_slli_si128(
                      (__m128i)_mm_movelh_ps(
                                 (__m128)*(unsigned __int64 *)&v13->m_codecParms[3],
                                 (__m128)LODWORD(v13->m_codecParms[5])),
                      4),
                    4);
    v64 = v16;
    *((_QWORD *)&v66 + 1) -= 2i64 * LOBYTE(v13->m_sharedVertices.m_data);
  }
  v20 = 0;
  v21 = 0i64;
  v80 = 0;
  v60 = 0i64;
  v70 = LOBYTE(v13->m_primitives.m_data);
  if ( v70 )
  {
    si128 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskZ);
    v23 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskY);
    v24 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskX);
    v25 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskZ);
    v26 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskY);
    v27 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskX);
    do
    {
      v28 = *(unsigned __int8 *)(v65 + 4 * v21 + 3);
      v29 = *(unsigned __int8 *)(v65 + 4 * v21 + 2);
      v30 = *(unsigned __int8 *)(v65 + 4 * v21 + 1);
      if ( v28 == v29 )
      {
        if ( v29 == v30 )
        {
          if ( v8->vfptr->isKeyConvertionAllowed(v8, ((_DWORD)v69 << 8) | (2 * v20)) )
            v8->vfptr->appendCustomPrimitiveToGeometry(
              v8,
              (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::Decoder *)&m_quad,
              v20,
              v9);
          goto LABEL_11;
        }
      }
      else if ( *(_BYTE *)(v65 + 4 * v21) == 0xDE && v30 == 173 && v29 == 222 && v28 == 173 )
      {
        goto LABEL_60;
      }
      v31 = 0i64;
      v32 = 0;
      v33 = LOBYTE(v13->m_dataRuns.m_data) - 1;
      for ( i = v33 + 1; i > 4; i = v33 - v32 + 1 )
      {
        v35 = (v33 + v32) >> 1;
        v36 = v20 - (unsigned __int8)v14[v35].m_index;
        if ( v36 < 0 )
        {
          v33 = (v33 + v32) >> 1;
        }
        else
        {
          if ( v36 < (unsigned __int8)v14[v35].m_count )
          {
            v31 = &v14[v35];
            goto LABEL_29;
          }
          v32 = v35 + 1;
        }
      }
      v37 = v32;
      v38 = 0;
      v39 = &v14[v37];
      if ( i > 0 )
      {
        while ( 1 )
        {
          v40 = v20 - (unsigned __int8)v39->m_index;
          if ( v40 >= 0 && v40 < (unsigned __int8)v39->m_count )
            break;
          ++v38;
          ++v39;
          if ( v38 >= i )
            goto LABEL_29;
        }
        v31 = v39;
      }
LABEL_29:
      v41 = *(unsigned __int8 *)(v65 + 4 * v21);
      m_value = v31->m_value;
      v43 = v66;
      if ( (int)v41 < m_data_low )
      {
        v45 = *((_QWORD *)&v65 + 1);
        a.m_quad = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_cvtepi32_ps(
                         _mm_or_si128(
                           _mm_or_si128(
                             _mm_and_si128(
                               _mm_shuffle_epi32(
                                 _mm_srli_epi32((__m128i)*(unsigned int *)(*((_QWORD *)&v65 + 1) + 4 * v41), 0x16u),
                                 0),
                               si128),
                             _mm_and_si128((__m128i)*(unsigned int *)(*((_QWORD *)&v65 + 1) + 4 * v41), v24)),
                           _mm_and_si128(
                             _mm_shuffle_epi32(
                               _mm_srli_epi32((__m128i)*(unsigned int *)(*((_QWORD *)&v65 + 1) + 4 * v41), 0xBu),
                               0),
                             v23))),
                       v16),
                     v12);
      }
      else
      {
        v44 = _mm_loadl_epi64((const __m128i *)(v66
                                              + 8i64
                                              * *(unsigned __int16 *)(*((_QWORD *)&v66 + 1)
                                                                    + 2i64 * *(unsigned __int8 *)(v65 + 4 * v21))));
        v45 = *((_QWORD *)&v65 + 1);
        a.m_quad = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_cvtepi32_ps(
                         _mm_or_si128(
                           _mm_or_si128(
                             _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v44, 0xAu), 85), v25),
                             _mm_and_si128(v44, v27)),
                           _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v44, 2), 5u), v26))),
                       v18),
                     v17.m_quad);
      }
      v46 = *(unsigned __int8 *)(v65 + 4 * v21 + 1);
      if ( (int)v46 < m_data_low )
      {
        v72 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(
                    _mm_or_si128(
                      _mm_or_si128(
                        _mm_and_si128(
                          _mm_shuffle_epi32(_mm_srli_epi32((__m128i)*(unsigned int *)(v45 + 4 * v46), 0x16u), 0),
                          si128),
                        _mm_and_si128((__m128i)*(unsigned int *)(v45 + 4 * v46), v24)),
                      _mm_and_si128(
                        _mm_shuffle_epi32(_mm_srli_epi32((__m128i)*(unsigned int *)(v45 + 4 * v46), 0xBu), 0),
                        v23))),
                  v16),
                v12);
      }
      else
      {
        v47 = _mm_loadl_epi64((const __m128i *)(v66
                                              + 8i64
                                              * *(unsigned __int16 *)(*((_QWORD *)&v66 + 1)
                                                                    + 2i64 * *(unsigned __int8 *)(v65 + 4 * v21 + 1))));
        v45 = *((_QWORD *)&v65 + 1);
        v72 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(
                    _mm_or_si128(
                      _mm_or_si128(
                        _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v47, 0xAu), 85), v25),
                        _mm_and_si128(v47, v27)),
                      _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v47, 2), 5u), v26))),
                  v18),
                v17.m_quad);
      }
      v48 = *(unsigned __int8 *)(v65 + 4 * v21 + 2);
      if ( (int)v48 < m_data_low )
      {
        v73 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(
                    _mm_or_si128(
                      _mm_or_si128(
                        _mm_and_si128(
                          _mm_shuffle_epi32(_mm_srli_epi32((__m128i)*(unsigned int *)(v45 + 4 * v48), 0x16u), 0),
                          si128),
                        _mm_and_si128((__m128i)*(unsigned int *)(v45 + 4 * v48), v24)),
                      _mm_and_si128(
                        _mm_shuffle_epi32(_mm_srli_epi32((__m128i)*(unsigned int *)(v45 + 4 * v48), 0xBu), 0),
                        v23))),
                  v16),
                v12);
      }
      else
      {
        v49 = _mm_loadl_epi64((const __m128i *)(v66
                                              + 8i64
                                              * *(unsigned __int16 *)(*((_QWORD *)&v66 + 1)
                                                                    + 2i64 * *(unsigned __int8 *)(v65 + 4 * v21 + 2))));
        v45 = *((_QWORD *)&v65 + 1);
        v73 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(
                    _mm_or_si128(
                      _mm_or_si128(
                        _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v49, 0xAu), 85), v25),
                        _mm_and_si128(v49, v27)),
                      _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v49, 2), 5u), v26))),
                  v18),
                v17.m_quad);
      }
      v50 = *(unsigned __int8 *)(v65 + 4 * v21 + 3);
      if ( (int)v50 < m_data_low )
      {
        v74 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(
                    _mm_or_si128(
                      _mm_or_si128(
                        _mm_and_si128(
                          _mm_shuffle_epi32(_mm_srli_epi32((__m128i)*(unsigned int *)(v45 + 4 * v50), 0x16u), 0),
                          si128),
                        _mm_and_si128((__m128i)*(unsigned int *)(v45 + 4 * v50), v24)),
                      _mm_and_si128(
                        _mm_shuffle_epi32(_mm_srli_epi32((__m128i)*(unsigned int *)(v45 + 4 * v50), 0xBu), 0),
                        v23))),
                  v16),
                v12);
      }
      else
      {
        v51 = _mm_loadl_epi64((const __m128i *)(v66
                                              + 8i64
                                              * *(unsigned __int16 *)(*((_QWORD *)&v66 + 1)
                                                                    + 2i64 * *(unsigned __int8 *)(v65 + 4 * v21 + 3))));
        v74 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(
                    _mm_or_si128(
                      _mm_or_si128(
                        _mm_and_si128(_mm_shuffle_epi32(_mm_srli_epi32(v51, 0xAu), 85), v25),
                        _mm_and_si128(v51, v27)),
                      _mm_and_si128(_mm_srli_epi32(_mm_slli_si128(v51, 2), 5u), v26))),
                  v18),
                v17.m_quad);
      }
      m_size = v78[1].m_size;
      v53 = 0;
      v54 = ((_BYTE)v48 != (unsigned __int8)v50) + 1;
      v55 = 0;
      if ( v54 <= 0 )
      {
        v13 = vars0;
        v9 = (hkGeometry *)v78;
        goto LABEL_59;
      }
      v56 = 2 * v20;
      do
      {
        v57 = v55 | v56 | ((_DWORD)v69 << 8);
        if ( ((unsigned __int8 (__fastcall *)(hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::CustomGeometryConverter *, _QWORD, __int64, __int64))v79->vfptr->isKeyConvertionAllowed)(
               v79,
               v57,
               v48,
               v43) )
        {
          v58 = 0;
          if ( append )
          {
            if ( append == 1 )
            {
              v58 = v57;
            }
            else
            {
              hkErrStream::hkErrStream(&v75, buf, 512);
              hkOstream::operator<<(&v75, "Triangle material type not supported.");
              if ( (unsigned int)hkError::messageError(
                                   0xDE9101F6,
                                   buf,
                                   "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Geometry/Internal/DataStructures/StaticMeshTre"
                                   "e/hkcdStaticMeshTree.inl",
                                   1317) )
                __debugbreak();
              hkOstream::~hkOstream(&v75);
            }
          }
          else
          {
            v58 = m_value;
          }
          if ( v78[2].m_size == (v78[2].m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v78[2].m_data, 16);
          p_m_quad = &v78[2].m_data[v78[2].m_size++].m_quad;
          p_m_quad->m128_i32[3] = v58;
          p_m_quad->m128_i32[0] = m_size;
          v53 = 1;
          p_m_quad->m128_i32[1] = v55 + m_size + 1;
          p_m_quad->m128_i32[2] = v55 + m_size + 2;
        }
        ++v55;
      }
      while ( v55 < v54 );
      v9 = (hkGeometry *)v78;
      if ( v53 )
      {
        hkArrayBase<hkVector4f>::_append(v78 + 1, &hkContainerHeapAllocator::s_alloc, &a, v54 + 2);
        v13 = (hkcdStaticMeshTreeBase::Section *)*((_QWORD *)&v65 + 1);
        v14 = v67;
        v16 = v64;
        v12 = v63;
        v18 = v62;
        v20 = v80;
        vars0 = (hkcdStaticMeshTreeBase::Section *)*((_QWORD *)&v65 + 1);
        v17.m_quad = m_quad;
        v25 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskZ);
        v26 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskY);
        v27 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskX);
        si128 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskZ);
        v23 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskY);
        v24 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskX);
LABEL_59:
        v21 = v60;
        goto LABEL_60;
      }
      v20 = v80;
      v21 = v60;
LABEL_11:
      v13 = (hkcdStaticMeshTreeBase::Section *)*((_QWORD *)&v65 + 1);
      v14 = v67;
      v16 = v64;
      v12 = v63;
      v18 = v62;
      v17.m_quad = m_quad;
      vars0 = (hkcdStaticMeshTreeBase::Section *)*((_QWORD *)&v65 + 1);
      v25 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskZ);
      v26 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskY);
      v27 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned __int64,21,21>::decode::`2::maskX);
      si128 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskZ);
      v23 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskY);
      v24 = _mm_load_si128((const __m128i *)&`hkcdStaticMeshTreeBase::VertexCODEC<unsigned int,11,11>::decode::`2::maskX);
LABEL_60:
      v8 = v79;
      m_data_low = v68;
      ++v21;
      ++v20;
      v60 = v21;
      v80 = v20;
    }
    while ( v21 < v70 );
  }
  if ( v81 )
    hkGeometryUtils::weldVertices(v9, 0.0);
}

