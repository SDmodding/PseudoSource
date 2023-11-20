// File Line: 15
// RVA: 0xDF0E50
void __fastcall hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5>::convertFromDynamicTree<hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree>(hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5> *this, hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *dTree)
{
  hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5> *v2; // rbx
  int v3; // esi
  int v4; // eax
  hkVector4f *v5; // rdi
  signed int v6; // er13
  hkVector4f *v7; // rax
  int v8; // eax
  int v9; // eax
  int v10; // er9
  hkResultEnum v11; // er15
  __int64 v12; // r12
  hkcdStaticTree::Codec3Axis5 *v13; // rcx
  __int64 v14; // r13
  hkVector4f *v15; // rbp
  char *v16; // r14
  hkVector4f v17; // xmm1
  __int64 v18; // rbx
  hkAabb *v19; // rsi
  hkcdStaticTree::Codec3Axis *v20; // rdi
  char v21; // al
  hkcdStaticTree::Codec3Axis5 *v22; // [rsp+30h] [rbp-A8h]
  hkAabb child; // [rsp+40h] [rbp-98h]
  hkVector4f *v24; // [rsp+60h] [rbp-78h]
  int v25; // [rsp+68h] [rbp-70h]
  int v26; // [rsp+6Ch] [rbp-6Ch]
  __int64 v27; // [rsp+70h] [rbp-68h]
  __int64 v28; // [rsp+78h] [rbp-60h]
  __int64 v29; // [rsp+80h] [rbp-58h]
  int v30; // [rsp+E0h] [rbp+8h]
  hkResult result; // [rsp+E8h] [rbp+10h]
  int v32; // [rsp+F0h] [rbp+18h]
  hkVector4f *v33; // [rsp+F8h] [rbp+20h]

  v2 = this;
  this->m_nodes.m_size = 0;
  this->m_domain.m_min = (hkVector4f)xmmword_141A712A0;
  this->m_domain.m_max.m_quad = _mm_xor_ps(
                                  (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                  this->m_domain.m_min.m_quad);
  if ( dTree->m_numLeaves )
  {
    v25 = 0;
    v24 = 0i64;
    v26 = 2147483648;
    v27 = 0i64;
    v29 = 0i64;
    v28 = 0i64;
    hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::copyTo<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>>(
      (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *)&dTree->m_nodes,
      (hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<unsigned int,unsigned __int64,11,21>,hkpBvCompressedMeshShapeTreeDataRun>::DynamicTree *)&v24);
    v3 = 2 * v28 - 1;
    v4 = 2 * v28;
    if ( 2 * (_DWORD)v28 )
    {
      v30 = (_DWORD)v28 << 6;
      v5 = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                           (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                           &v30);
      v4 = v30 / 32;
    }
    else
    {
      v5 = 0i64;
    }
    v6 = 2147483648;
    v33 = v5;
    if ( v4 )
      v6 = v4;
    v7 = v24;
    v32 = v6;
    *v5 = (hkVector4f)v24[4].m_quad;
    v5[1] = (hkVector4f)v7[5].m_quad;
    v8 = v2->m_nodes.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v8 < v3 )
    {
      v9 = 2 * v8;
      v10 = v3;
      if ( v3 < v9 )
        v10 = v9;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, v10, 5);
    }
    v2->m_nodes.m_size = v3;
    v11 = 0;
    v2->m_domain.m_min = (hkVector4f)v5->m_quad;
    v12 = v3;
    v2->m_domain.m_max = (hkVector4f)v5[1].m_quad;
    v13 = v2->m_nodes.m_data;
    v22 = v2->m_nodes.m_data;
    if ( v3 > 0 )
    {
      v14 = (__int64)v33;
      v15 = v24 + 6;
      v16 = &v13->m_loData;
      do
      {
        v17.m_quad = (__m128)v15[-1];
        v18 = v15[1].m_quad.m128_i64[0];
        v19 = (hkAabb *)(v14 + 32i64 * v15->m_quad.m128_i32[0]);
        child.m_min = (hkVector4f)v15[-2].m_quad;
        child.m_max = (hkVector4f)v17.m_quad;
        v20 = (hkcdStaticTree::Codec3Axis *)&v13->m_xyz[4 * v11 + v11];
        hkcdStaticTree::Codec3Axis::pack(v19, &child, v20);
        result.m_enum = v11 + 1;
        hkcdStaticTree::Codec3Axis::unpack(v19, v20, (hkAabb *)(v14 + 32i64 * (v11 + 1)));
        if ( v15->m_quad.m128_i32[2] )
        {
          LODWORD(v18) = ((signed int)v18 - v11 - 1) >> 1;
          v21 = BYTE1(v18) | 0x80;
        }
        else
        {
          v21 = BYTE1(v18) & 0x7F;
        }
        v11 = result.m_enum;
        v13 = v22;
        *v16 = v18;
        *(v16 - 1) = v21;
        v16 += 5;
        v15 += 4;
        --v12;
      }
      while ( v12 );
      v6 = v32;
      v5 = v33;
    }
    if ( v6 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v5,
        32 * v6);
    v25 = 0;
    if ( v26 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v24,
        v26 << 6);
  }
}

// File Line: 134
// RVA: 0xDF3040
signed __int64 __fastcall hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4>::findLeafByValue(hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *this, int value)
{
  __int64 v2; // r10
  unsigned int v3; // er9
  __int64 v4; // r8
  char *v5; // rcx

  v2 = this->m_nodes.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( v2 <= 0 )
    return 0xFFFFFFFFi64;
  v5 = &this->m_nodes.m_data->m_data;
  while ( *v5 & 1 || value != (unsigned int)(unsigned __int8)*v5 >> 1 )
  {
    ++v4;
    ++v3;
    v5 += 4;
    if ( v4 >= v2 )
      return 0xFFFFFFFFi64;
  }
  return v3;
}

// File Line: 149
// RVA: 0xDF3D10
void __fastcall hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4>::getNodeAabb(hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *this, int node, hkAabb *aabb)
{
  hkVector4f v3; // xmm0
  hkVector4f v4; // xmm1
  __int64 v5; // rbx
  hkAabb *v6; // rdi
  int v7; // esi
  hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage4> *v8; // r14
  hkcdStaticTree::Codec3Axis4 *v9; // rdx
  hkVector4f v10; // xmm1
  hkAabb parent; // [rsp+20h] [rbp-48h]
  hkAabb aabbOut; // [rsp+40h] [rbp-28h]
  int v13; // [rsp+70h] [rbp+8h]
  int v14; // [rsp+74h] [rbp+Ch]

  v3.m_quad = (__m128)this->m_domain.m_min;
  v4.m_quad = (__m128)this->m_domain.m_max;
  LODWORD(v5) = 0;
  v6 = aabb;
  v7 = node;
  v8 = this;
  parent.m_min = this->m_domain.m_min;
  parent.m_max = (hkVector4f)v4.m_quad;
  if ( node )
  {
    do
    {
      v9 = v8->m_nodes.m_data;
      v13 = v5 + 1;
      v14 = v5 + (unsigned __int8)(v9[(signed int)v5].m_data & 0xFE);
      v5 = *(&v13 + (v7 >= v14));
      hkcdStaticTree::Codec3Axis::unpack(&parent, (hkcdStaticTree::Codec3Axis *)v9[v5].m_xyz, &aabbOut);
      v10.m_quad = (__m128)aabbOut.m_max;
      parent = aabbOut;
    }
    while ( (_DWORD)v5 != v7 );
    v6->m_min = aabbOut.m_min;
    v6->m_max = (hkVector4f)v10.m_quad;
  }
  else
  {
    aabb->m_min = (hkVector4f)v3.m_quad;
    aabb->m_max = (hkVector4f)v4.m_quad;
  }
}

// File Line: 336
// RVA: 0xC986F0
bool __fastcall hkcdStaticTree::Filtering<1>::computeFilter<hkcdStaticMeshTreeBase>(hkcdStaticTree::Filtering<1> *this, hkcdStaticMeshTreeBase *tree, unsigned int *clusters, unsigned int *a4)
{
  __int128 v4; // xmm0
  __int128 v5; // xmm1
  __int64 v6; // rax
  __int128 v8; // [rsp+20h] [rbp-48h]
  __int128 v9; // [rsp+30h] [rbp-38h]
  int v10; // [rsp+40h] [rbp-28h]
  __int64 v11; // [rsp+50h] [rbp-18h]

  if ( !*(_DWORD *)&this[8] )
    return 0;
  v4 = *(_OWORD *)&this[16];
  v5 = *(_OWORD *)&this[32];
  v6 = *(_QWORD *)this;
  v10 = 0;
  v8 = v4;
  v9 = v5;
  v11 = v6;
  return hkcdStaticTree::Filtering<1>::computeFilter<hkcdStaticMeshTreeBase>(
           this,
           (hkcdStaticMeshTreeBase *)&v8,
           (hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5>::NodeContext *)tree,
           a4);
}

// File Line: 349
// RVA: 0xC98510
_BOOL8 __fastcall hkcdStaticTree::Filtering<1>::computeFilter<hkcdStaticMeshTreeBase>(hkcdStaticTree::Filtering<1> *this, hkcdStaticMeshTreeBase *tree, hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5>::NodeContext *node, unsigned int *clusters)
{
  __int64 v4; // rax
  hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5>::NodeContext *v5; // rsi
  hkcdStaticMeshTreeBase *v6; // rdi
  hkcdStaticTree::Filtering<1> *v7; // rbp
  float v8; // er10
  __int64 v9; // rcx
  hkVector4f v10; // xmm8
  __m128 v11; // xmm7
  __m128i v12; // xmm4
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
  float v23; // eax
  int v24; // edx
  hkcdStaticMeshTreeBase treea; // [rsp+20h] [rbp-A8h]
  unsigned int *v27; // [rsp+90h] [rbp-38h]

  v4 = *(_QWORD *)&tree->m_numPrimitiveKeys;
  v5 = node;
  v6 = tree;
  v7 = this;
  if ( *(_BYTE *)(v4 + 3) >= 0 )
    return ((unsigned int)node->m_aabb.m_min.m_quad.m128_i32[tree->m_domain.m_max.m_quad.m128_i32[0] / 32] >> (char)LODWORD(tree->m_domain.m_max.m_quad.m128_f32[0]) % -32) & 1;
  v8 = tree->m_domain.m_max.m_quad.m128_f32[0];
  v9 = *(_QWORD *)this;
  v10.m_quad = (__m128)tree->m_domain.m_min;
  treea.m_domain.m_max.m_quad.m128_i32[0] = LODWORD(v8) + 1;
  v11 = _mm_mul_ps(_mm_sub_ps(v10.m_quad, (__m128)tree->0), (__m128)xmmword_141A71240);
  LODWORD(treea.m_sharedVerticesIndex.m_data) = LODWORD(v8)
                                              + 2 * (*(unsigned __int8 *)(v4 + 4) | ((*(_BYTE *)(v4 + 3) & 0x7F) << 8));
  *(_QWORD *)&treea.m_numPrimitiveKeys = v9
                                       + 4i64 * treea.m_domain.m_max.m_quad.m128_i32[0]
                                       + treea.m_domain.m_max.m_quad.m128_i32[0];
  v27 = (unsigned int *)(v9
                       + 4i64 * SLODWORD(treea.m_sharedVerticesIndex.m_data)
                       + SLODWORD(treea.m_sharedVerticesIndex.m_data));
  v12 = _mm_unpacklo_epi16(
          _mm_unpacklo_epi8((__m128i)(unsigned int)**(_DWORD **)&treea.m_numPrimitiveKeys, (__m128i)0i64),
          (__m128i)0i64);
  v13 = _mm_cvtepi32_ps(_mm_srli_epi32(v12, 4u));
  v14 = _mm_cvtepi32_ps(_mm_and_si128(v12, hkcdStaticTree::Codec3Axis::v_mask.m_quad));
  v15 = _mm_unpacklo_epi16(_mm_unpacklo_epi8((__m128i)*v27, (__m128i)0i64), (__m128i)0i64);
  v16 = _mm_cvtepi32_ps(_mm_srli_epi32(v15, 4u));
  v17 = _mm_cvtepi32_ps(_mm_and_si128(v15, hkcdStaticTree::Codec3Axis::v_mask.m_quad));
  v18 = (hkcdStaticTree::DynamicStorage5)_mm_add_ps(_mm_mul_ps(_mm_mul_ps(v13, v13), v11), (__m128)tree->0);
  treea.m_domain.m_min.m_quad = _mm_sub_ps(v10.m_quad, _mm_mul_ps(_mm_mul_ps(v14, v14), v11));
  treea.0 = v18;
  v19 = (hkArray<hkcdStaticMeshTreeBase::Section,hkContainerHeapAllocator>)_mm_add_ps(
                                                                             _mm_mul_ps(_mm_mul_ps(v16, v16), v11),
                                                                             (__m128)tree->0);
  treea.m_primitives = (hkArray<hkcdStaticMeshTreeBase::Primitive,hkContainerHeapAllocator>)_mm_sub_ps(
                                                                                              v10.m_quad,
                                                                                              _mm_mul_ps(
                                                                                                _mm_mul_ps(v17, v17),
                                                                                                v11));
  treea.m_sections = v19;
  v20 = hkcdStaticTree::Filtering<1>::computeFilter<hkcdStaticMeshTreeBase>(
          v7,
          (hkcdStaticMeshTreeBase *)((char *)&treea + 64),
          node,
          v27);
  v22 = hkcdStaticTree::Filtering<1>::computeFilter<hkcdStaticMeshTreeBase>(v7, &treea, v5, v21) || v20;
  v23 = v6->m_domain.m_max.m_quad.m128_f32[0];
  v24 = (v6->m_domain.m_max.m_quad.m128_i32[0] >> 31) & 0x1F;
  v5->m_aabb.m_min.m_quad.m128_i32[(v24 + LODWORD(v23)) >> 5] = ((v22 != 0) << (((v24 + LOBYTE(v23)) & 0x1F) - v24)) | v5->m_aabb.m_min.m_quad.m128_i32[(v24 + LODWORD(v23)) >> 5] & ~(1 << (((v24 + LOBYTE(v23)) & 0x1F) - v24));
  return v22;
}

