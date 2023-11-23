// File Line: 15
// RVA: 0xDF0E50
void __fastcall hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5>::convertFromDynamicTree<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree>(
        hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5> *this,
        hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *dTree)
{
  int v3; // esi
  int v4; // eax
  hkVector4f *v5; // rdi
  int v6; // r13d
  hkcdDynamicTree::CodecRawUlong *m_data; // rax
  int v8; // eax
  int v9; // eax
  int v10; // r9d
  hkResultEnum m_enum; // r15d
  __int64 v12; // r12
  hkcdStaticTree::Codec3Axis5 *v13; // rcx
  __int64 v14; // r13
  unsigned __int64 *p_m_parent; // rbp
  char *p_m_loData; // r14
  hkVector4f v17; // xmm1
  unsigned __int64 v18; // rbx
  hkAabb *v19; // rsi
  hkcdStaticTree::Codec3Axis *v20; // rdi
  char v21; // al
  hkcdStaticTree::Codec3Axis5 *v22; // [rsp+30h] [rbp-A8h]
  hkAabb child; // [rsp+40h] [rbp-98h] BYREF
  hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree v24; // [rsp+60h] [rbp-78h] BYREF
  int v25; // [rsp+E0h] [rbp+8h] BYREF
  hkResult result; // [rsp+E8h] [rbp+10h] BYREF
  int v27; // [rsp+F0h] [rbp+18h]
  hkVector4f *v28; // [rsp+F8h] [rbp+20h]

  this->m_nodes.m_size = 0;
  this->m_domain.m_min = (hkVector4f)xmmword_141A712A0;
  this->m_domain.m_max.m_quad = _mm_xor_ps(
                                  (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                  this->m_domain.m_min.m_quad);
  if ( dTree->m_numLeaves )
  {
    v24.m_nodes.m_size = 0;
    v24.m_nodes.m_data = 0i64;
    v24.m_nodes.m_capacityAndFlags = 0x80000000;
    memset(&v24.m_firstFree, 0, 24);
    hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::copyTo<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>>(
      dTree,
      &v24);
    v3 = 2 * v24.m_numLeaves - 1;
    v4 = 2 * v24.m_numLeaves;
    if ( 2 * v24.m_numLeaves )
    {
      v25 = v24.m_numLeaves << 6;
      v5 = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &v25);
      v4 = v25 / 32;
    }
    else
    {
      v5 = 0i64;
    }
    v6 = 0x80000000;
    v28 = v5;
    if ( v4 )
      v6 = v4;
    m_data = v24.m_nodes.m_data;
    v27 = v6;
    *v5 = v24.m_nodes.m_data[1].m_aabb.m_min;
    v5[1] = m_data[1].m_aabb.m_max;
    v8 = this->m_nodes.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v8 < v3 )
    {
      v9 = 2 * v8;
      v10 = v3;
      if ( v3 < v9 )
        v10 = v9;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_nodes.m_data, v10, 5);
    }
    this->m_nodes.m_size = v3;
    m_enum = HK_SUCCESS;
    this->m_domain.m_min = (hkVector4f)v5->m_quad;
    v12 = v3;
    this->m_domain.m_max = (hkVector4f)v5[1].m_quad;
    v13 = this->m_nodes.m_data;
    v22 = this->m_nodes.m_data;
    if ( v3 > 0 )
    {
      v14 = (__int64)v28;
      p_m_parent = &v24.m_nodes.m_data[1].m_parent;
      p_m_loData = &v13->m_loData;
      do
      {
        v17.m_quad = (__m128)*((_OWORD *)p_m_parent - 1);
        v18 = p_m_parent[2];
        v19 = (hkAabb *)(v14 + 32i64 * *(int *)p_m_parent);
        child.m_min = (hkVector4f)*((_OWORD *)p_m_parent - 2);
        child.m_max = (hkVector4f)v17.m_quad;
        v20 = (hkcdStaticTree::Codec3Axis5 *)((char *)v13 + 4 * m_enum + m_enum);
        hkcdStaticTree::Codec3Axis::pack(v19, &child, v20);
        result.m_enum = m_enum + 1;
        hkcdStaticTree::Codec3Axis::unpack(v19, v20, (hkAabb *)(v14 + 32i64 * (m_enum + 1)));
        if ( *((_DWORD *)p_m_parent + 2) )
        {
          LODWORD(v18) = ((int)v18 - m_enum - 1) >> 1;
          v21 = BYTE1(v18) | 0x80;
        }
        else
        {
          v21 = BYTE1(v18) & 0x7F;
        }
        m_enum = result.m_enum;
        v13 = v22;
        *p_m_loData = v18;
        *(p_m_loData - 1) = v21;
        p_m_loData += 5;
        p_m_parent += 8;
        --v12;
      }
      while ( v12 );
      v6 = v27;
      v5 = v28;
    }
    if ( v6 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v5, 32 * v6);
    v24.m_nodes.m_size = 0;
    if ( v24.m_nodes.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        v24.m_nodes.m_data,
        v24.m_nodes.m_capacityAndFlags << 6);
  }
}

// File Line: 134
// RVA: 0xDF3040
__int64 __fastcall hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4>::findLeafByValue(
        hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *this,
        int value)
{
  __int64 m_size; // r10
  unsigned int v3; // r9d
  __int64 v4; // r8
  char *i; // rcx

  m_size = this->m_nodes.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( m_size <= 0 )
    return 0xFFFFFFFFi64;
  for ( i = &this->m_nodes.m_data->m_data; (*i & 1) != 0 || value != (unsigned __int8)*i >> 1; i += 4 )
  {
    ++v4;
    ++v3;
    if ( v4 >= m_size )
      return 0xFFFFFFFFi64;
  }
  return v3;
}

// File Line: 149
// RVA: 0xDF3D10
void __fastcall hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4>::getNodeAabb(
        hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *this,
        int node,
        hkAabb *aabb)
{
  hkVector4f v3; // xmm0
  hkVector4f v4; // xmm1
  __int64 v5; // rbx
  hkcdStaticTree::Codec3Axis4 *m_data; // rdx
  hkVector4f v10; // xmm1
  hkAabb parent; // [rsp+20h] [rbp-48h] BYREF
  hkAabb aabbOut; // [rsp+40h] [rbp-28h] BYREF
  int v13; // [rsp+70h] [rbp+8h]
  int v14; // [rsp+74h] [rbp+Ch]

  v3.m_quad = (__m128)this->m_domain.m_min;
  v4.m_quad = (__m128)this->m_domain.m_max;
  LODWORD(v5) = 0;
  parent.m_min = (hkVector4f)v3.m_quad;
  parent.m_max = (hkVector4f)v4.m_quad;
  if ( node )
  {
    do
    {
      m_data = this->m_nodes.m_data;
      v13 = v5 + 1;
      v14 = v5 + (m_data[(int)v5].m_data & 0xFE);
      v5 = *(&v13 + (node >= v14));
      hkcdStaticTree::Codec3Axis::unpack(&parent, &m_data[v5], &aabbOut);
      v10.m_quad = (__m128)aabbOut.m_max;
      parent = aabbOut;
    }
    while ( (_DWORD)v5 != node );
    aabb->m_min = aabbOut.m_min;
    aabb->m_max = (hkVector4f)v10.m_quad;
  }
  else
  {
    aabb->m_min = (hkVector4f)v3.m_quad;
    aabb->m_max = (hkVector4f)v4.m_quad;
  }
}

// File Line: 336
// RVA: 0xC986F0
bool __fastcall hkcdStaticTree::Filtering<1>::computeFilter<hkcdStaticMeshTreeBase>(
        hkcdStaticTree::Filtering<1> *this,
        hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5>::NodeContext *tree,
        unsigned int *clusters,
        unsigned int *a4)
{
  __int128 v4; // xmm0
  __int128 v5; // xmm1
  __int64 v6; // rax
  _BYTE v8[72]; // [rsp+20h] [rbp-48h] BYREF

  if ( !*(_DWORD *)&this[8] )
    return 0;
  v4 = *(_OWORD *)&this[16];
  v5 = *(_OWORD *)&this[32];
  v6 = *(_QWORD *)this;
  *(_DWORD *)&v8[32] = 0;
  *(_OWORD *)v8 = v4;
  *(_OWORD *)&v8[16] = v5;
  *(_QWORD *)&v8[48] = v6;
  return hkcdStaticTree::Filtering<1>::computeFilter<hkcdStaticMeshTreeBase>(
           this,
           (hkcdStaticMeshTreeBase *)v8,
           tree,
           a4);
}

// File Line: 349
// RVA: 0xC98510
_BOOL8 __fastcall hkcdStaticTree::Filtering<1>::computeFilter<hkcdStaticMeshTreeBase>(
        hkcdStaticTree::Filtering<1> *this,
        hkcdStaticMeshTreeBase *tree,
        hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5>::NodeContext *node,
        unsigned int *clusters)
{
  __int64 v4; // rax
  int v8; // r10d
  __int64 v9; // rcx
  hkVector4f v10; // xmm8
  __m128 v11; // xmm7
  __m128i v12; // xmm0
  __m128 v13; // xmm2
  __m128 v14; // xmm4
  __m128i v15; // xmm0
  __m128 v16; // xmm5
  __m128 v17; // xmm1
  hkcdStaticTree::DynamicStorage5 v18; // xmm2
  hkArray<hkcdStaticMeshTreeBase::Section,hkContainerHeapAllocator> v19; // xmm5
  bool v20; // bl
  unsigned int *v21; // r9
  bool v22; // bl
  hkcdStaticMeshTreeBase treea; // [rsp+20h] [rbp-A8h] BYREF
  unsigned int *v25; // [rsp+90h] [rbp-38h]

  v4 = *(_QWORD *)&tree->m_numPrimitiveKeys;
  if ( *(char *)(v4 + 3) >= 0 )
    return ((unsigned int)node->m_aabb.m_min.m_quad.m128_i32[tree->m_domain.m_max.m_quad.m128_i32[0] / 32] >> (tree->m_domain.m_max.m_quad.m128_i32[0] % 32)) & 1;
  v8 = tree->m_domain.m_max.m_quad.m128_i32[0];
  v9 = *(_QWORD *)this;
  v10.m_quad = (__m128)tree->m_domain.m_min;
  treea.m_domain.m_max.m_quad.m128_i32[0] = v8 + 1;
  v11 = _mm_mul_ps(_mm_sub_ps(v10.m_quad, (__m128)tree->hkcdStaticTree::DynamicStorage5), (__m128)xmmword_141A71240);
  LODWORD(treea.m_sharedVerticesIndex.m_data) = v8
                                              + 2 * (*(unsigned __int8 *)(v4 + 4) | ((*(_BYTE *)(v4 + 3) & 0x7F) << 8));
  *(_QWORD *)&treea.m_numPrimitiveKeys = v9
                                       + 4i64 * treea.m_domain.m_max.m_quad.m128_i32[0]
                                       + treea.m_domain.m_max.m_quad.m128_i32[0];
  v25 = (unsigned int *)(v9
                       + 4i64 * SLODWORD(treea.m_sharedVerticesIndex.m_data)
                       + SLODWORD(treea.m_sharedVerticesIndex.m_data));
  v12 = _mm_unpacklo_epi16(
          _mm_unpacklo_epi8((__m128i)(unsigned int)**(_DWORD **)&treea.m_numPrimitiveKeys, (__m128i)0i64),
          (__m128i)0i64);
  v13 = _mm_cvtepi32_ps(_mm_srli_epi32(v12, 4u));
  v14 = _mm_cvtepi32_ps(_mm_and_si128(v12, hkcdStaticTree::Codec3Axis::v_mask.m_quad));
  v15 = _mm_unpacklo_epi16(_mm_unpacklo_epi8((__m128i)*v25, (__m128i)0i64), (__m128i)0i64);
  v16 = _mm_cvtepi32_ps(_mm_srli_epi32(v15, 4u));
  v17 = _mm_cvtepi32_ps(_mm_and_si128(v15, hkcdStaticTree::Codec3Axis::v_mask.m_quad));
  v18 = (hkcdStaticTree::DynamicStorage5)_mm_add_ps(
                                           _mm_mul_ps(_mm_mul_ps(v13, v13), v11),
                                           (__m128)tree->hkcdStaticTree::DynamicStorage5);
  treea.m_domain.m_min.m_quad = _mm_sub_ps(v10.m_quad, _mm_mul_ps(_mm_mul_ps(v14, v14), v11));
  treea.hkcdStaticTree::DynamicStorage5 = v18;
  v19 = (hkArray<hkcdStaticMeshTreeBase::Section,hkContainerHeapAllocator>)_mm_add_ps(
                                                                             _mm_mul_ps(_mm_mul_ps(v16, v16), v11),
                                                                             (__m128)tree->hkcdStaticTree::DynamicStorage5);
  treea.m_primitives = (hkArray<hkcdStaticMeshTreeBase::Primitive,hkContainerHeapAllocator>)_mm_sub_ps(
                                                                                              v10.m_quad,
                                                                                              _mm_mul_ps(
                                                                                                _mm_mul_ps(v17, v17),
                                                                                                v11));
  treea.m_sections = v19;
  v20 = hkcdStaticTree::Filtering<1>::computeFilter<hkcdStaticMeshTreeBase>(
          this,
          (hkcdStaticMeshTreeBase *)&treea.m_sections,
          node,
          v25);
  v22 = hkcdStaticTree::Filtering<1>::computeFilter<hkcdStaticMeshTreeBase>(this, &treea, node, v21) || v20;
  node->m_aabb.m_min.m_quad.m128_i32[tree->m_domain.m_max.m_quad.m128_i32[0] / 32] = (v22 << (tree->m_domain.m_max.m_quad.m128_i32[0]
                                                                                            % 32)) | node->m_aabb.m_min.m_quad.m128_i32[tree->m_domain.m_max.m_quad.m128_i32[0] / 32] & ~(1 << (tree->m_domain.m_max.m_quad.m128_i32[0] % 32));
  return v22;
}

