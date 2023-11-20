// File Line: 428
// RVA: 0xD99530
void __fastcall hkpTreeBroadPhase::hkpTreeBroadPhase(hkpTreeBroadPhase *this, hkpBroadPhase *broadphase)
{
  hkpBroadPhase *v2; // rdi
  hkpTreeBroadPhase *v3; // r14
  signed __int64 v4; // rbx
  _QWORD *v5; // rcx
  signed __int64 v6; // rsi
  signed __int64 v7; // rbx
  void **v8; // rdi
  int v9; // er8
  __int64 v10; // [rsp+28h] [rbp-10h]

  v2 = broadphase;
  v3 = this;
  hkpBroadPhase::hkpBroadPhase((hkpBroadPhase *)&this->vfptr, BROADPHASE_TREE_16BIT, 320, 7);
  v4 = (signed __int64)v3->m_handles;
  v3->vfptr = (hkBaseObjectVtbl *)&hkpTreeBroadPhase::`vftable;
  *(_QWORD *)v4 = 0i64;
  *(_DWORD *)(v4 + 8) = 0;
  *(_DWORD *)(v4 + 12) = 2147483648;
  *(_QWORD *)(v4 + 16) = 0i64;
  *(_DWORD *)(v4 + 24) = 0;
  *(_DWORD *)(v4 + 28) = 2147483648;
  v3->m_childBroadPhase = v2;
  if ( v2 )
    hkReferencedObject::addReference((hkReferencedObject *)&v2->vfptr);
  v3->m_parameters.m_quad.m128_i32[0] = 1008981770;
  v3->m_parameters.m_quad.m128_i32[1] = 1015580809;
  v3->m_parameters.m_quad.m128_i32[2] = 0x40000000;
  v3->m_parameters.m_quad.m128_i32[3] = 1056964608;
  LODWORD(v10) = 0;
  v3->m_offsetAndTimeStep = 0i64;
  v3->m_scale = 0i64;
  v3->m_optimized.m_bool = 0;
  if ( v3->m_handles[0].m_size == (v3->m_handles[0].m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3->m_handles, 16);
  v5 = (_QWORD *)(*(_QWORD *)v4 + 16i64 * v3->m_handles[0].m_size);
  if ( v5 )
  {
    *v5 = 0i64;
    v5[1] = v10;
  }
  ++v3->m_handles[0].m_size;
  v6 = 5i64;
  v7 = (signed __int64)&v3->m_internals[0].m_real.m128_i64[1] + 4;
  do
  {
    v8 = (void **)(v7 - 12);
    if ( v7 != 12 )
    {
      *v8 = 0i64;
      *(_DWORD *)v7 = 2147483648;
      *(_WORD *)(v7 + 4) = 0;
      v9 = *(_DWORD *)v7;
      *(_DWORD *)(v7 - 4) = 0;
      if ( v9 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *v8,
          32 * v9);
      *v8 = 0i64;
      *(_DWORD *)v7 = 2147483648;
      *(_WORD *)(v7 + 4) = 0;
      *(_WORD *)(v7 + 20) = 0;
      *(_QWORD *)(v7 + 12) = 0i64;
      *(_DWORD *)(v7 + 28) = 0;
    }
    v7 += 48i64;
    --v6;
  }
  while ( v6 );
}

// File Line: 453
// RVA: 0xDA6E60
void __fastcall hkpTreeBroadPhase32::~hkpTreeBroadPhase32(hkpTreeBroadPhase32 *this)
{
  hkpTreeBroadPhase32 *v1; // rsi
  hkpBroadPhase *v2; // rcx
  int *v3; // rbx
  signed __int64 v4; // rdi
  int v5; // eax
  signed int v6; // edi
  int *v7; // rbx
  int v8; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpTreeBroadPhase32::`vftable;
  v2 = this->m_childBroadPhase;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v3 = &v1->m_internals[0].m_real.m128_i32[3];
  v4 = 5i64;
  do
  {
    v5 = *v3;
    *(v3 - 1) = 0;
    if ( v5 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        *(void **)(v3 - 3),
        48 * (v5 & 0x3FFFFFFF));
    *(_QWORD *)(v3 - 3) = 0i64;
    *v3 = 2147483648;
    v3 += 12;
    --v4;
  }
  while ( v4 );
  v6 = 1;
  v7 = &v1->m_parameters.m_quad.m128_i32[3];
  do
  {
    v8 = *(v7 - 4);
    v7 -= 4;
    *(v7 - 1) = 0;
    if ( v8 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        *(void **)(v7 - 3),
        16 * v8);
    --v6;
    *(_QWORD *)(v7 - 3) = 0i64;
    *v7 = 2147483648;
  }
  while ( v6 >= 0 );
  hkpBroadPhase::~hkpBroadPhase((hkpBroadPhase *)&v1->vfptr);
}

// File Line: 460
// RVA: 0xDA6F50
void __fastcall hkpTreeBroadPhase32::update(hkpTreeBroadPhase32 *this, float timeStep)
{
  hkpTreeBroadPhase32 *v2; // rbx

  v2 = this;
  this->m_offsetAndTimeStep.m_quad.m128_f32[3] = timeStep * this->m_parameters.m_quad.m128_f32[2];
  hkpTreeBroadPhase32::optimize(
    this,
    this->m_parameters.m_quad.m128_f32[1],
    this->m_parameters.m_quad.m128_i32[3] & 0xC0FFFFFF);
  if ( !v2->m_optimized.m_bool )
  {
    hkpTreeBroadPhase32::fullOptimize(v2);
    v2->m_optimized.m_bool = 1;
  }
}

// File Line: 474
// RVA: 0xD99810
signed __int64 __fastcall hkpTreeBroadPhase::getMemoryFootPrint(hkpTreeBroadPhase *this)
{
  return (unsigned int)(32
                      * (this->m_internals[0].m_real.m128_i32[2]
                       + this->m_internals[3].m_real.m128_i32[2]
                       + this->m_internals[6].m_real.m128_i32[2]
                       + this->m_internals[9].m_real.m128_i32[2]
                       + this->m_internals[12].m_real.m128_i32[2])
                      + 248)
       + 16i64 * (unsigned int)(this->m_handles[0].m_size + this->m_handles[1].m_size);
}

// File Line: 487
// RVA: 0xDA6FF0
void __fastcall hkpTreeBroadPhase32::fullOptimize(hkpTreeBroadPhase32 *this)
{
  int v1; // esi
  hkpTreeBroadPhase32 *v2; // r14
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> *v3; // rbx
  signed __int64 v4; // rbp
  unsigned int v5; // er9
  signed __int64 v6; // rdx
  hkcdDynamicTree::CodecRawUint *v7; // r10
  unsigned int v8; // eax
  unsigned int v9; // er8

  v1 = 0;
  v2 = this;
  v3 = (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> *)this->m_internals;
  v4 = 5i64;
  do
  {
    hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::rebuildBranchSAH(v3, v3->m_root, (hkBool)1, 32, 16);
    hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::compactIndices(v3);
    v5 = v3->m_root;
    while ( v5 )
    {
      if ( !v3->m_nodes.m_data[v5].m_children[0] )
      {
        v6 = (signed __int64)&(&v2->vfptr)[2 * ((v1 == 4) + 18i64)][v3->m_nodes.m_data[v5].m_children[1]];
        *(_DWORD *)(v6 + 8) &= 0xFFE00000;
        *(_DWORD *)(v6 + 8) |= v5 & 0x1FFFFF;
      }
      v7 = v3->m_nodes.m_data;
      if ( v3->m_nodes.m_data[v5].m_children[0] )
      {
        v5 = v3->m_nodes.m_data[v5].m_children[0];
      }
      else
      {
        v8 = v3->m_nodes.m_data[v5].m_parent;
        v9 = v5;
        if ( !v8 )
          goto LABEL_10;
        while ( v7[v8].m_children[1] == v9 )
        {
          v9 = v8;
          v8 = v7[v8].m_parent;
          if ( !v8 )
            goto LABEL_10;
        }
        if ( v8 )
          v5 = v7[v8].m_children[1];
        else
LABEL_10:
          v5 = v9;
        if ( !v8 && v5 == v9 )
          v5 = 0;
      }
    }
    ++v1;
    v3 = (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> *)((char *)v3 + 48);
    --v4;
  }
  while ( v4 );
}

// File Line: 511
// RVA: 0xDA7140
void __fastcall hkpTreeBroadPhase32::compact(hkpTreeBroadPhase32 *this)
{
  int v1; // esi
  hkpTreeBroadPhase32 *v2; // r14
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> *v3; // rbx
  signed __int64 v4; // rbp
  unsigned int v5; // er8
  signed __int64 v6; // rdx
  hkcdDynamicTree::CodecRawUint *v7; // r10
  unsigned int v8; // eax
  unsigned int v9; // er9

  v1 = 0;
  v2 = this;
  v3 = (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> *)this->m_internals;
  v4 = 5i64;
  do
  {
    if ( v3->m_numLeaves > 1 )
    {
      hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::compactIndices(v3);
      v5 = v3->m_root;
      while ( v5 )
      {
        if ( !v3->m_nodes.m_data[v5].m_children[0] )
        {
          v6 = (signed __int64)&(&v2->vfptr)[2 * ((v1 == 4) + 18i64)][v3->m_nodes.m_data[v5].m_children[1]];
          *(_DWORD *)(v6 + 8) &= 0xFFE00000;
          *(_DWORD *)(v6 + 8) |= v5 & 0x1FFFFF;
        }
        v7 = v3->m_nodes.m_data;
        if ( v3->m_nodes.m_data[v5].m_children[0] )
        {
          v5 = v3->m_nodes.m_data[v5].m_children[0];
        }
        else
        {
          v8 = v3->m_nodes.m_data[v5].m_parent;
          v9 = v5;
          if ( !v8 )
            goto LABEL_11;
          while ( v7[v8].m_children[1] == v9 )
          {
            v9 = v8;
            v8 = v7[v8].m_parent;
            if ( !v8 )
              goto LABEL_11;
          }
          if ( v8 )
            v5 = v7[v8].m_children[1];
          else
LABEL_11:
            v5 = v9;
          if ( !v8 && v5 == v9 )
            v5 = 0;
        }
      }
    }
    ++v1;
    v3 = (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> *)((char *)v3 + 48);
    --v4;
  }
  while ( v4 );
}

// File Line: 534
// RVA: 0xDA7280
void __fastcall hkpTreeBroadPhase32::optimize(hkpTreeBroadPhase32 *this, float updateQuality, int cacheQuality)
{
  signed int v3; // esi
  __int64 v4; // rbp
  hkpTreeBroadPhase32 *v5; // r15
  signed __int64 v6; // r14
  signed int *v7; // rbx
  signed __int64 v8; // rdi
  int v9; // edx
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> *v10; // rbx
  bool v11; // zf
  __int64 v12; // rdi
  unsigned int v13; // edx
  hkpTreeBroadPhaseInternals::MappingUpdater mapping; // [rsp+78h] [rbp+20h]

  v3 = 1;
  v4 = (unsigned int)cacheQuality;
  v5 = this;
  v6 = 4i64;
  if ( updateQuality > 0.0 )
  {
    v7 = &this->m_internals[4].m_real.m128_i32[2];
    v8 = 4i64;
    do
    {
      if ( *v7 )
      {
        v9 = (signed int)(float)((float)((float)*v7 * updateQuality) + 0.5);
        if ( v9 < 1 )
          v9 = 1;
        hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::optimizeIncremental(
          (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> *)(v7 - 6),
          v9,
          2);
      }
      v7 += 12;
      --v8;
    }
    while ( v8 );
  }
  if ( (signed int)v4 > 0 )
  {
    v10 = (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> *)&v5->m_internals[5].m_real.m128_u16[4];
    do
    {
      v11 = v10[-1].m_numLeaves == 0;
      mapping.m_handles = (hkpTreeBroadPhase32::Handle *)(&v5->vfptr)[2 * ((v3 == 4) + 18i64)];
      if ( !v11 && (signed int)v4 > 0 )
      {
        v12 = v4;
        do
        {
          v13 = LODWORD(v10->m_nodes.m_data)++;
          hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::sortBranch<hkpTreeBroadPhaseInternals::MappingUpdater>(
            v10 - 1,
            v13,
            &mapping,
            0xFFFF);
          --v12;
        }
        while ( v12 );
      }
      ++v3;
      v10 = (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> *)((char *)v10 + 48);
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 591
// RVA: 0xD99C20
void __fastcall hkpTreeBroadPhase::addUserObjects(hkpTreeBroadPhase *this, int numObjects, hkpBroadPhaseHandle *const *handles, hkAabb *aabbs)
{
  hkpTreeBroadPhase *v4; // rax
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::Codec32> *v5; // rbx
  hkAabb *v6; // r14
  hkArray<hkpTreeBroadPhase::Handle,hkContainerHeapAllocator> *v7; // rsi
  __int64 v8; // r13
  int v9; // ebp
  signed __int64 v10; // rax
  signed __int64 v11; // rdi
  hkpBroadPhaseHandle *v12; // rax
  hkcdDynamicTree::Codec32 *v13; // rcx
  int v14; // er15
  signed __int64 v15; // r12
  hkcdDynamicTree::Codec32 *v16; // rcx
  unsigned __int16 v17; // dx
  __m128 v18; // xmm8
  __m128 v19; // xmm7
  __m128 *v20; // r9
  __m128 *v21; // r10
  unsigned __int16 v22; // cx
  __m128 v23; // xmm9
  __m128 v24; // xmm10
  __m128 *v25; // rcx
  __m128 *v26; // rdx
  __m128 v27; // xmm4
  __m128 v28; // xmm3
  __m128 v29; // xmm4
  __m128 v30; // xmm6
  __m128 v31; // xmm2
  __m128 v32; // xmm5
  __m128 v33; // xmm2
  __m128 v34; // xmm4
  __m128 v35; // xmm6
  __m128 v36; // xmm5
  __m128 v37; // xmm5
  unsigned __int16 v38; // ax
  signed __int64 v39; // r11
  int v40; // ecx
  __int64 v41; // rax
  __m128 v42; // xmm1
  __m128 v43; // xmm2
  hkResult result; // [rsp+20h] [rbp-C8h]
  hkResult v45; // [rsp+24h] [rbp-C4h]
  __int64 v46; // [rsp+28h] [rbp-C0h]
  __m128 *v47; // [rsp+30h] [rbp-B8h]
  __m128 *v48; // [rsp+38h] [rbp-B0h]
  hkpTreeBroadPhase *v49; // [rsp+F0h] [rbp+8h]
  unsigned __int16 v50; // [rsp+F8h] [rbp+10h]
  hkpBroadPhaseHandle *const *v51; // [rsp+100h] [rbp+18h]
  hkAabb *v52; // [rsp+108h] [rbp+20h]

  if ( numObjects > 0 )
  {
    v52 = aabbs;
    v51 = handles;
    v49 = this;
    v4 = this;
    v5 = (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::Codec32> *)&this->m_internals[12];
    v6 = aabbs;
    v7 = &this->m_handles[1];
    v8 = 0i64;
    v46 = numObjects;
    do
    {
      v9 = v4->m_handles[1].m_size;
      if ( v7->m_size == (v7->m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 16);
        handles = v51;
      }
      v10 = (signed __int64)&v7->m_data[v7->m_size];
      if ( v10 )
      {
        *(_QWORD *)v10 = 0i64;
        *(_DWORD *)(v10 + 8) = 0;
      }
      v11 = (signed __int64)&v7->m_data[v7->m_size++];
      v12 = handles[v8];
      *(_DWORD *)(v11 + 8) &= 0x1FFFFFu;
      *(_QWORD *)v11 = v12;
      *(_DWORD *)(v11 + 8) |= (v9 << 25) | 0x800000;
      if ( !v5->m_firstFree )
        hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::Codec32>::reserveNodes(
          v5,
          &result,
          1);
      v13 = v5->m_nodes.m_data;
      v14 = v5->m_firstFree;
      v15 = v5->m_firstFree;
      v5->m_firstFree = v5->m_nodes.m_data[v5->m_firstFree].m_aabb.m_min.m_quad.m128_u16[0];
      v13[v15].m_aabb.m_max.m_quad.m128_i16[6] = 0;
      v13[v15].m_aabb.m_max.m_quad.m128_i16[7] = v9;
      v13[v15].m_aabb.m_min.m_quad = _mm_shuffle_ps(
                                       v6->m_min.m_quad,
                                       _mm_unpackhi_ps(v6->m_min.m_quad, v13[v15].m_aabb.m_min.m_quad),
                                       196);
      v13[v15].m_aabb.m_max.m_quad = _mm_shuffle_ps(
                                       v6->m_max.m_quad,
                                       _mm_unpackhi_ps(v6->m_max.m_quad, v13[v15].m_aabb.m_max.m_quad),
                                       196);
      v16 = v5->m_nodes.m_data;
      v17 = v5[1].m_nodes.m_size;
      v50 = v17;
      v18 = v5->m_nodes.m_data[v15].m_aabb.m_min.m_quad;
      v19 = _mm_shuffle_ps(
              v5->m_nodes.m_data[v15].m_aabb.m_max.m_quad,
              _mm_unpackhi_ps(v5->m_nodes.m_data[v15].m_aabb.m_max.m_quad, (__m128)0i64),
              196);
      if ( v17 )
      {
        if ( !v5->m_firstFree )
        {
          hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::Codec32>::reserveNodes(
            v5,
            &v45,
            1);
          v17 = v50;
        }
        v20 = &v5->m_nodes.m_data[v17].m_aabb.m_min.m_quad;
        v21 = &v5->m_nodes.m_data[v5->m_firstFree].m_aabb.m_min.m_quad;
        v5->m_firstFree = v21->m128_u64[0];
        v22 = v20[1].m128_u16[6];
        if ( v22 )
        {
          v23 = _mm_add_ps(v18, v19);
          v24 = _mm_sub_ps(v19, v18);
          do
          {
            v25 = &v5->m_nodes.m_data[v22].m_aabb.m_min.m_quad;
            v26 = &v5->m_nodes.m_data[v20[1].m128_u16[7]].m_aabb.m_min.m_quad;
            v27 = _mm_min_ps(v18, *v20);
            v28 = _mm_max_ps(v19, _mm_shuffle_ps(v20[1], _mm_unpackhi_ps(v20[1], (__m128)0i64), 196));
            v47 = v25;
            v48 = v26;
            *v20 = _mm_shuffle_ps(v27, _mm_unpackhi_ps(v27, *v20), 196);
            v20[1] = _mm_shuffle_ps(v28, _mm_unpackhi_ps(v28, v20[1]), 196);
            v29 = _mm_shuffle_ps(v25[1], _mm_unpackhi_ps(v25[1], (__m128)0i64), 196);
            v30 = _mm_shuffle_ps(v26[1], _mm_unpackhi_ps(v26[1], (__m128)0i64), 196);
            v31 = _mm_sub_ps(_mm_add_ps(*v25, v29), v23);
            v32 = _mm_add_ps(*v26, v30);
            v33 = _mm_mul_ps(v31, v31);
            v34 = _mm_add_ps(_mm_sub_ps(v29, *v25), v24);
            v35 = _mm_add_ps(_mm_sub_ps(v30, *v26), v24);
            v36 = _mm_sub_ps(v32, v23);
            v37 = _mm_mul_ps(v36, v36);
            v20 = *(&v47
                  + ((float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 85))
                                           + COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 0)))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 170)))
                           * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 85))
                                           + COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 0)))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 170)))) > (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v37, v37, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v37, v37, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v37, v37, 170)))
                                                                                           * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v35, v35, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v35, v35, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v35, v35, 170))))));
            v22 = v20[1].m128_u16[6];
          }
          while ( v22 );
        }
        v38 = WORD2(v20->m128_u64[1]);
        v39 = ((char *)v21 - (char *)v5->m_nodes.m_data) >> 5;
        if ( v38 )
          v5->m_nodes.m_data->m_aabb.m_max.m_quad.m128_i16[16i64 * v38
                                                         + (v5->m_nodes.m_data[v38].m_aabb.m_max.m_quad.m128_i16[7] == (unsigned __int16)(((char *)v20 - (char *)v5->m_nodes.m_data) >> 5))
                                                         + 6] = v39;
        else
          LOWORD(v5[1].m_nodes.m_size) = v39;
        v6 = v52;
        v40 = (unsigned __int16)v39 | 0x3F000000;
        HIDWORD(v21->m128_u64[1]) = WORD2(v20->m128_u64[1]) | 0x3F000000;
        v41 = (unsigned int)((_DWORD)v20 - LODWORD(v5->m_nodes.m_data));
        v21[1].m128_i16[7] = v14;
        v21[1].m128_i16[6] = v41 >> 5;
        HIDWORD(v20->m128_u64[1]) = v40;
        v5->m_nodes.m_data[v15].m_aabb.m_min.m_quad.m128_i32[3] = v40;
        v42 = _mm_min_ps(*v20, v18);
        v43 = _mm_max_ps(_mm_shuffle_ps(v20[1], _mm_unpackhi_ps(v20[1], (__m128)0i64), 196), v19);
        *v21 = _mm_shuffle_ps(v42, _mm_unpackhi_ps(v42, *v21), 196);
        v21[1] = _mm_shuffle_ps(v43, _mm_unpackhi_ps(v43, v21[1]), 196);
      }
      else
      {
        LOWORD(v5[1].m_nodes.m_size) = v14;
        v16[v15].m_aabb.m_min.m_quad.m128_i32[3] = 1056964608;
      }
      ++LODWORD(v5[1].m_nodes.m_data);
      *(_DWORD *)(v11 + 8) &= 0xFFE00000;
      handles = v51;
      ++v6;
      ++v8;
      v52 = v6;
      *(_DWORD *)(v11 + 8) |= v14 & 0x1FFFFF;
      **(_DWORD **)v11 = v9 | 0x80000000;
      v4 = v49;
    }
    while ( v8 < v46 );
  }
}= v51;
      ++v6;
      ++v8;
      

// File Line: 607
// RVA: 0xD9A100
void __fastcall hkpTreeBroadPhase::updateUserObjects(hkpTreeBroadPhase *this, int numObjects, hkpBroadPhaseHandle *const *handles, hkAabb *aabbs, hkVector4f *velocities)
{
  hkVector4f v5; // xmm12
  hkAabb *v6; // r14
  hkpTreeBroadPhase *v7; // r13
  hkpBroadPhaseHandle *const *v8; // r9
  hkSimdFloat32 *v9; // rbx
  __int64 v10; // r15
  __m128 v11; // xmm13
  __m128 v12; // xmm13
  __m128 v13; // xmm12
  hkVector4f *v14; // r8
  hkVector4f *v15; // r12
  __m128 v16; // xmm2
  __m128 v17; // xmm3
  __int64 v18; // rdx
  signed __int64 v19; // rdx
  unsigned int v20; // ecx
  __int64 v21; // rbp
  unsigned __int64 v22; // rdx
  __m128 v23; // xmm1
  unsigned __int16 v24; // r9
  __m128 v25; // xmm1
  __m128 v26; // xmm4
  __m128 v27; // xmm5
  signed __int64 v28; // rdi
  signed __int64 v29; // r8
  unsigned __int16 v30; // ax
  signed __int64 v31; // r11
  __int16 v32; // r8
  unsigned __int64 v33; // rdx
  signed __int64 v34; // rdi
  unsigned __int16 v35; // r8
  signed __int64 v36; // rdi
  __m128 *v37; // rcx
  signed __int64 v38; // rax
  __m128 v39; // xmm3
  __m128 v40; // xmm2
  signed __int64 v41; // rax
  __m128 v42; // xmm0
  __m128 v43; // xmm3
  unsigned __int64 v44; // rax
  signed __int64 v45; // rsi
  unsigned __int64 v46; // rax
  __m128 v47; // xmm9
  __m128 v48; // xmm8
  __m128 *v49; // r9
  __m128 *v50; // r10
  unsigned __int16 v51; // cx
  __m128 v52; // xmm10
  __m128 v53; // xmm11
  __m128 *v54; // rcx
  __m128 *v55; // rdx
  __m128 v56; // xmm4
  __m128 v57; // xmm3
  __m128 v58; // xmm5
  __m128 v59; // xmm6
  __m128 v60; // xmm2
  __m128 v61; // xmm4
  __m128 v62; // xmm2
  __m128 v63; // xmm5
  __m128 v64; // xmm6
  __m128 v65; // xmm4
  __m128 v66; // xmm4
  unsigned __int16 v67; // ax
  signed __int64 v68; // r11
  __int64 v69; // rax
  int v70; // ecx
  __m128 v71; // xmm1
  __m128 v72; // xmm2
  unsigned __int64 v73; // rsi
  unsigned __int16 v74; // r8
  signed __int64 v75; // rdi
  __m128 v76; // xmm5
  __m128 v77; // xmm4
  signed __int64 v78; // rdx
  unsigned __int16 v79; // ax
  signed __int64 v80; // r11
  __int16 v81; // r8
  unsigned __int64 v82; // rdx
  signed __int64 v83; // rax
  unsigned __int16 v84; // r8
  __m128 *v85; // rcx
  signed __int64 v86; // rax
  __m128 v87; // xmm3
  __m128 v88; // xmm2
  signed __int64 v89; // rax
  __m128 v90; // xmm0
  __m128 v91; // xmm3
  unsigned __int64 v92; // rax
  unsigned __int64 v93; // rax
  unsigned __int16 v94; // si
  unsigned __int16 v95; // cx
  __m128 v96; // xmm10
  __m128 v97; // xmm11
  __m128 *v98; // rcx
  __m128 *v99; // rdx
  __m128 v100; // xmm4
  __m128 v101; // xmm3
  __m128 v102; // xmm4
  __m128 v103; // xmm6
  __m128 v104; // xmm2
  __m128 v105; // xmm5
  __m128 v106; // xmm2
  __m128 v107; // xmm4
  __m128 v108; // xmm6
  __m128 v109; // xmm5
  __m128 v110; // xmm5
  unsigned __int16 v111; // ax
  signed __int64 v112; // r11
  __int64 v113; // rax
  int v114; // ecx
  hkResult v115; // [rsp+20h] [rbp-E8h]
  __int64 v116; // [rsp+28h] [rbp-E0h]
  __m128 *v117; // [rsp+30h] [rbp-D8h]
  __m128 *v118; // [rsp+38h] [rbp-D0h]
  __m128 *v119; // [rsp+40h] [rbp-C8h]
  __m128 *v120; // [rsp+48h] [rbp-C0h]
  hkpTreeBroadPhase *v121; // [rsp+110h] [rbp+8h]
  hkResult result; // [rsp+118h] [rbp+10h]
  hkpBroadPhaseHandle *const *v123; // [rsp+120h] [rbp+18h]

  v123 = handles;
  v121 = this;
  v5.m_quad = (__m128)this->m_offsetAndTimeStep;
  result.m_enum = this->m_parameters.m_quad.m128_i32[0];
  v6 = aabbs;
  v7 = this;
  v8 = handles;
  v9 = &this->m_internals[12];
  v10 = 0i64;
  v11 = (__m128)(unsigned int)result.m_enum;
  result.m_enum = this->m_parameters.m_quad.m128_i32[2];
  v116 = numObjects;
  v12 = _mm_shuffle_ps(v11, v11, 0);
  v13 = _mm_mul_ps(
          _mm_shuffle_ps(v5.m_quad, v5.m_quad, 255),
          _mm_shuffle_ps((__m128)(unsigned int)result.m_enum, (__m128)(unsigned int)result.m_enum, 0));
  if ( numObjects > 0 )
  {
    v14 = velocities;
    v15 = velocities;
    while ( 1 )
    {
      v16 = v6->m_min.m_quad;
      v17 = v6->m_max.m_quad;
      v18 = v8[v10]->m_id;
      LODWORD(v18) = v18 & 0x7FFFFFFF;
      v19 = (signed __int64)&v7->m_handles[1].m_data[v18];
      v20 = *(_DWORD *)(v19 + 8) & 0x1FFFFFF ^ ((*(_DWORD *)(v19 + 8) & 0xFE000000) + 0x2000000);
      *(_DWORD *)(v19 + 8) = v20;
      v21 = (unsigned __int16)v20;
      if ( !(v20 & 0xFE000000) )
        break;
      v22 = v9->m_real.m128_u64[0];
      if ( _mm_movemask_ps(
             _mm_or_ps(
               _mm_cmpltps(v16, *(__m128 *)(32i64 * (unsigned __int16)v20 + v9->m_real.m128_u64[0])),
               _mm_cmpltps(
                 _mm_shuffle_ps(
                   *(__m128 *)(32i64 * (unsigned __int16)v20 + v9->m_real.m128_u64[0] + 16),
                   _mm_unpackhi_ps(
                     *(__m128 *)(32i64 * (unsigned __int16)v20 + v9->m_real.m128_u64[0] + 16),
                     (__m128)0i64),
                   196),
                 v17))) & 7 )
      {
        v23 = 0i64;
        if ( v14 )
          v23 = _mm_mul_ps(v15->m_quad, v13);
        v24 = v9[2].m_real.m128_u16[0];
        v25 = _mm_shuffle_ps(v23, _mm_unpackhi_ps(v23, v12), 196);
        v26 = _mm_min_ps(_mm_add_ps(v16, v25), v16);
        v27 = _mm_max_ps(_mm_add_ps(v17, v25), v17);
        if ( (_WORD)v20 == v24 )
        {
          v9[2].m_real.m128_i16[0] = 0;
        }
        else
        {
          v28 = v22 + 32i64 * (unsigned __int16)v20;
          v29 = v22 + 32i64 * *(unsigned __int16 *)(v28 + 12);
          v30 = *(_WORD *)(v29 + 12);
          v31 = v22 + 32i64 * *(unsigned __int16 *)(v29 + 2 * (15i64 - (*(_WORD *)(v29 + 30) == (_WORD)v20)));
          if ( v30 )
          {
            *(_DWORD *)(v31 + 12) = v30 | 0x3F000000;
            *(_WORD *)(v9->m_real.m128_u64[0]
                     + 2
                     * (16i64 * *(unsigned __int16 *)(v29 + 12)
                      + (*(_WORD *)(32i64 * *(unsigned __int16 *)(v29 + 12) + v9->m_real.m128_u64[0] + 30) == *(_WORD *)(v28 + 12)))
                     + 28) = (signed __int64)(v31 - v9->m_real.m128_u64[0]) >> 5;
            v32 = *(_WORD *)(v28 + 12);
            *(_WORD *)(32i64 * *(unsigned __int16 *)(v28 + 12) + v9->m_real.m128_u64[0]) = v9[1].m_real.m128_i16[0];
            v33 = v9->m_real.m128_u64[0];
            v9[1].m_real.m128_i16[0] = v32;
            v34 = v33 + 32i64 * *(unsigned __int16 *)(v31 + 12);
            while ( 1 )
            {
              v35 = *(_WORD *)(v34 + 12);
              v36 = (signed __int64)(v34 - v33) >> 5;
              v37 = (__m128 *)(v33 + 32i64 * (unsigned __int16)v36);
              v38 = 32i64 * v37[1].m128_u16[6];
              v39 = *(__m128 *)(v38 + v33 + 16);
              v40 = *(__m128 *)(v38 + v33);
              v41 = 32i64 * v37[1].m128_u16[7];
              v42 = _mm_min_ps(v40, *(__m128 *)(v41 + v33));
              v43 = _mm_max_ps(
                      _mm_shuffle_ps(v39, _mm_unpackhi_ps(v39, (__m128)0i64), 196),
                      _mm_shuffle_ps(
                        *(__m128 *)(v41 + v33 + 16),
                        _mm_unpackhi_ps(*(__m128 *)(v41 + v33 + 16), (__m128)0i64),
                        196));
              *v37 = _mm_shuffle_ps(v42, _mm_unpackhi_ps(v42, *v37), 196);
              v37[1] = _mm_shuffle_ps(v43, _mm_unpackhi_ps(v43, v37[1]), 196);
              if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v27, v43), _mm_cmpleps(v42, v26))) & 7) == 7 )
                break;
              if ( v35 )
              {
                v33 = v9->m_real.m128_u64[0];
                v34 = v9->m_real.m128_u64[0] + 32i64 * v35;
                if ( v34 )
                  continue;
              }
              goto LABEL_16;
            }
LABEL_17:
            v44 = v9->m_real.m128_u64[0];
            v45 = 32 * v21;
            *(__m128 *)(v45 + v44) = _mm_shuffle_ps(
                                       v26,
                                       _mm_unpackhi_ps(v26, *(__m128 *)(32 * v21 + v9->m_real.m128_u64[0])),
                                       196);
            *(__m128 *)(v45 + v44 + 16) = _mm_shuffle_ps(
                                            v27,
                                            _mm_unpackhi_ps(v27, *(__m128 *)(32 * v21 + v44 + 16)),
                                            196);
            v46 = v9->m_real.m128_u64[0];
            v47 = *(__m128 *)(32 * v21 + v9->m_real.m128_u64[0]);
            v48 = _mm_shuffle_ps(
                    *(__m128 *)(32 * v21 + v9->m_real.m128_u64[0] + 16),
                    _mm_unpackhi_ps(*(__m128 *)(32 * v21 + v9->m_real.m128_u64[0] + 16), (__m128)0i64),
                    196);
            if ( (_WORD)v36 )
            {
              if ( !v9[1].m_real.m128_i16[0] )
                hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::Codec32>::reserveNodes(
                  (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::Codec32> *)v9,
                  &result,
                  1);
              v49 = (__m128 *)(v9->m_real.m128_u64[0] + 32i64 * (unsigned __int16)v36);
              v50 = (__m128 *)(v9->m_real.m128_u64[0] + 32i64 * v9[1].m_real.m128_u16[0]);
              v9[1].m_real.m128_i16[0] = v50->m128_u64[0];
              v51 = v49[1].m128_u16[6];
              if ( v51 )
              {
                v52 = _mm_add_ps(v47, v48);
                v53 = _mm_sub_ps(v48, v47);
                do
                {
                  v54 = (__m128 *)(v9->m_real.m128_u64[0] + 32i64 * v51);
                  v55 = (__m128 *)(v9->m_real.m128_u64[0] + 32i64 * v49[1].m128_u16[7]);
                  v56 = _mm_min_ps(v47, *v49);
                  v57 = _mm_max_ps(v48, _mm_shuffle_ps(v49[1], _mm_unpackhi_ps(v49[1], (__m128)0i64), 196));
                  v117 = v54;
                  v118 = v55;
                  *v49 = _mm_shuffle_ps(v56, _mm_unpackhi_ps(v56, *v49), 196);
                  v49[1] = _mm_shuffle_ps(v57, _mm_unpackhi_ps(v57, v49[1]), 196);
                  v58 = _mm_shuffle_ps(v54[1], _mm_unpackhi_ps(v54[1], (__m128)0i64), 196);
                  v59 = _mm_shuffle_ps(v55[1], _mm_unpackhi_ps(v55[1], (__m128)0i64), 196);
                  v60 = _mm_sub_ps(_mm_add_ps(*v54, v58), v52);
                  v61 = _mm_add_ps(*v55, v59);
                  v62 = _mm_mul_ps(v60, v60);
                  v63 = _mm_add_ps(_mm_sub_ps(v58, *v54), v53);
                  v64 = _mm_add_ps(_mm_sub_ps(v59, *v55), v53);
                  v65 = _mm_sub_ps(v61, v52);
                  v66 = _mm_mul_ps(v65, v65);
                  v49 = *(&v117
                        + ((float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v62, v62, 85))
                                                 + COERCE_FLOAT(_mm_shuffle_ps(v62, v62, 0)))
                                         + COERCE_FLOAT(_mm_shuffle_ps(v62, v62, 170)))
                                 * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v63, v63, 85))
                                                 + COERCE_FLOAT(_mm_shuffle_ps(v63, v63, 0)))
                                         + COERCE_FLOAT(_mm_shuffle_ps(v63, v63, 170)))) > (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v66, v66, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v66, v66, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v66, v66, 170)))
                                                                                                 * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v64, v64, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v64, v64, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v64, v64, 170))))));
                  v51 = v49[1].m128_u16[6];
                }
                while ( v51 );
                v7 = v121;
              }
              v67 = WORD2(v49->m128_u64[1]);
              v68 = (signed __int64)((signed __int64)v50 - v9->m_real.m128_u64[0]) >> 5;
              if ( v67 )
                *(_WORD *)(v9->m_real.m128_u64[0]
                         + 2
                         * (16i64 * v67
                          + (*(_WORD *)(32i64 * v67 + v9->m_real.m128_u64[0] + 30) == (unsigned __int16)((signed __int64)((signed __int64)v49 - v9->m_real.m128_u64[0]) >> 5)))
                         + 28) = v68;
              else
                v9[2].m_real.m128_i16[0] = v68;
              HIDWORD(v50->m128_u64[1]) = WORD2(v49->m128_u64[1]) | 0x3F000000;
              v69 = (unsigned int)((_DWORD)v49 - v9->m_real.m128_i32[0]);
              v50[1].m128_i16[7] = v21;
              v70 = (unsigned __int16)v68 | 0x3F000000;
              v50[1].m128_i16[6] = v69 >> 5;
              HIDWORD(v49->m128_u64[1]) = v70;
              *(_DWORD *)(v45 + v9->m_real.m128_u64[0] + 12) = v70;
              goto LABEL_28;
            }
            v9[2].m_real.m128_i16[0] = v21;
            *(_DWORD *)(v45 + v46 + 12) = 1056964608;
LABEL_51:
            v14 = velocities;
            goto LABEL_52;
          }
          *(_WORD *)(32i64 * v24 + v22) = v9[1].m_real.m128_i16[0];
          v9[1].m_real.m128_i16[0] = v24;
          v9[2].m_real.m128_i16[0] = (signed __int64)(unsigned int)(v31 - v9->m_real.m128_i32[0]) >> 5;
          *(_DWORD *)(v31 + 12) = 1056964608;
        }
LABEL_16:
        LOWORD(v36) = v9[2].m_real.m128_i16[0];
        goto LABEL_17;
      }
LABEL_52:
      v8 = v123;
      ++v10;
      ++v15;
      ++v6;
      if ( v10 >= v116 )
        return;
    }
    v73 = v9->m_real.m128_u64[0];
    v74 = v9[2].m_real.m128_u16[0];
    v75 = 32i64 * (unsigned __int16)v20;
    v76 = *(__m128 *)(v9->m_real.m128_u64[0] + 32i64 * (unsigned __int16)v20);
    v77 = _mm_shuffle_ps(
            *(__m128 *)(v9->m_real.m128_u64[0] + 32i64 * (unsigned __int16)v20 + 16),
            _mm_unpackhi_ps(*(__m128 *)(v9->m_real.m128_u64[0] + 32i64 * (unsigned __int16)v20 + 16), (__m128)0i64),
            196);
    if ( (_WORD)v20 == v74 )
    {
      v9[2].m_real.m128_i16[0] = 0;
    }
    else
    {
      v78 = v73 + 32i64 * *(unsigned __int16 *)(v73 + v75 + 12);
      v79 = *(_WORD *)(v78 + 12);
      v80 = v73 + 32i64 * *(unsigned __int16 *)(v78 + 2 * (15i64 - (*(_WORD *)(v78 + 30) == (_WORD)v20)));
      if ( v79 )
      {
        *(_DWORD *)(v80 + 12) = v79 | 0x3F000000;
        *(_WORD *)(v9->m_real.m128_u64[0]
                 + 2
                 * (16i64 * *(unsigned __int16 *)(v78 + 12)
                  + (*(_WORD *)(32i64 * *(unsigned __int16 *)(v78 + 12) + v9->m_real.m128_u64[0] + 30) == *(_WORD *)(v73 + v75 + 12)))
                 + 28) = (signed __int64)(v80 - v9->m_real.m128_u64[0]) >> 5;
        v81 = *(_WORD *)(v73 + v75 + 12);
        *(_WORD *)(32i64 * *(unsigned __int16 *)(v73 + v75 + 12) + v9->m_real.m128_u64[0]) = v9[1].m_real.m128_i16[0];
        v82 = v9->m_real.m128_u64[0];
        v9[1].m_real.m128_i16[0] = v81;
        v83 = v82 + 32i64 * *(unsigned __int16 *)(v80 + 12);
        do
        {
          v84 = *(_WORD *)(v83 + 12);
          v85 = (__m128 *)(v82 + 32i64 * (unsigned __int16)((signed __int64)(v83 - v82) >> 5));
          v86 = 32i64 * v85[1].m128_u16[6];
          v87 = *(__m128 *)(v86 + v82 + 16);
          v88 = *(__m128 *)(v86 + v82);
          v89 = 32i64 * v85[1].m128_u16[7];
          v90 = _mm_min_ps(v88, *(__m128 *)(v89 + v82));
          v91 = _mm_max_ps(
                  _mm_shuffle_ps(v87, _mm_unpackhi_ps(v87, (__m128)0i64), 196),
                  _mm_shuffle_ps(
                    *(__m128 *)(v89 + v82 + 16),
                    _mm_unpackhi_ps(*(__m128 *)(v89 + v82 + 16), (__m128)0i64),
                    196));
          *v85 = _mm_shuffle_ps(v90, _mm_unpackhi_ps(v90, *v85), 196);
          v85[1] = _mm_shuffle_ps(v91, _mm_unpackhi_ps(v91, v85[1]), 196);
          if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v77, v91), _mm_cmpleps(v90, v76))) & 7) == 7 )
            break;
          if ( !v84 )
            break;
          v82 = v9->m_real.m128_u64[0];
          v83 = v9->m_real.m128_u64[0] + 32i64 * v84;
        }
        while ( v83 );
      }
      else
      {
        *(_WORD *)(32i64 * v74 + v73) = v9[1].m_real.m128_i16[0];
        v9[1].m_real.m128_i16[0] = v74;
        v9[2].m_real.m128_i16[0] = (signed __int64)(unsigned int)(v80 - v9->m_real.m128_i32[0]) >> 5;
        *(_DWORD *)(v80 + 12) = 1056964608;
      }
    }
    v92 = v9->m_real.m128_u64[0];
    *(__m128 *)(v75 + v92) = _mm_shuffle_ps(
                               v6->m_min.m_quad,
                               _mm_unpackhi_ps(v6->m_min.m_quad, *(__m128 *)(v75 + v9->m_real.m128_u64[0])),
                               196);
    *(__m128 *)(v75 + v92 + 16) = _mm_shuffle_ps(
                                    v6->m_max.m_quad,
                                    _mm_unpackhi_ps(v6->m_max.m_quad, *(__m128 *)(v75 + v92 + 16)),
                                    196);
    v93 = v9->m_real.m128_u64[0];
    v94 = v9[2].m_real.m128_u16[0];
    v47 = *(__m128 *)(v9->m_real.m128_u64[0] + v75);
    v48 = _mm_shuffle_ps(
            *(__m128 *)(v9->m_real.m128_u64[0] + v75 + 16),
            _mm_unpackhi_ps(*(__m128 *)(v9->m_real.m128_u64[0] + v75 + 16), (__m128)0i64),
            196);
    if ( v94 )
    {
      if ( !v9[1].m_real.m128_i16[0] )
        hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::Codec32>::reserveNodes(
          (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::Codec32> *)v9,
          &v115,
          1);
      v49 = (__m128 *)(v9->m_real.m128_u64[0] + 32i64 * v94);
      v50 = (__m128 *)(v9->m_real.m128_u64[0] + 32i64 * v9[1].m_real.m128_u16[0]);
      v9[1].m_real.m128_i16[0] = v50->m128_u64[0];
      v95 = v49[1].m128_u16[6];
      if ( v95 )
      {
        v96 = _mm_add_ps(v47, v48);
        v97 = _mm_sub_ps(v48, v47);
        do
        {
          v98 = (__m128 *)(v9->m_real.m128_u64[0] + 32i64 * v95);
          v99 = (__m128 *)(v9->m_real.m128_u64[0] + 32i64 * v49[1].m128_u16[7]);
          v100 = _mm_min_ps(v47, *v49);
          v101 = _mm_max_ps(v48, _mm_shuffle_ps(v49[1], _mm_unpackhi_ps(v49[1], (__m128)0i64), 196));
          v119 = v98;
          v120 = v99;
          *v49 = _mm_shuffle_ps(v100, _mm_unpackhi_ps(v100, *v49), 196);
          v49[1] = _mm_shuffle_ps(v101, _mm_unpackhi_ps(v101, v49[1]), 196);
          v102 = _mm_shuffle_ps(v98[1], _mm_unpackhi_ps(v98[1], (__m128)0i64), 196);
          v103 = _mm_shuffle_ps(v99[1], _mm_unpackhi_ps(v99[1], (__m128)0i64), 196);
          v104 = _mm_sub_ps(_mm_add_ps(*v98, v102), v96);
          v105 = _mm_add_ps(*v99, v103);
          v106 = _mm_mul_ps(v104, v104);
          v107 = _mm_add_ps(_mm_sub_ps(v102, *v98), v97);
          v108 = _mm_add_ps(_mm_sub_ps(v103, *v99), v97);
          v109 = _mm_sub_ps(v105, v96);
          v110 = _mm_mul_ps(v109, v109);
          v49 = *(&v119
                + ((float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v107, v107, 85))
                                         + COERCE_FLOAT(_mm_shuffle_ps(v107, v107, 0)))
                                 + COERCE_FLOAT(_mm_shuffle_ps(v107, v107, 170)))
                         * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v106, v106, 0))
                                         + COERCE_FLOAT(_mm_shuffle_ps(v106, v106, 85)))
                                 + COERCE_FLOAT(_mm_shuffle_ps(v106, v106, 170)))) > (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v108, v108, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v108, v108, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v108, v108, 170)))
                                                                                           * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v110, v110, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v110, v110, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v110, v110, 170))))));
          v95 = v49[1].m128_u16[6];
        }
        while ( v95 );
        v7 = v121;
      }
      v111 = WORD2(v49->m128_u64[1]);
      v112 = (signed __int64)((signed __int64)v50 - v9->m_real.m128_u64[0]) >> 5;
      if ( v111 )
        *(_WORD *)(v9->m_real.m128_u64[0]
                 + 2
                 * (16i64 * v111
                  + (*(_WORD *)(32i64 * v111 + v9->m_real.m128_u64[0] + 30) == (unsigned __int16)((signed __int64)((signed __int64)v49 - v9->m_real.m128_u64[0]) >> 5)))
                 + 28) = v112;
      else
        v9[2].m_real.m128_i16[0] = v112;
      HIDWORD(v50->m128_u64[1]) = WORD2(v49->m128_u64[1]) | 0x3F000000;
      v113 = (unsigned int)((_DWORD)v49 - v9->m_real.m128_i32[0]);
      v50[1].m128_i16[7] = v21;
      v114 = (unsigned __int16)v112 | 0x3F000000;
      v50[1].m128_i16[6] = v113 >> 5;
      HIDWORD(v49->m128_u64[1]) = v114;
      *(_DWORD *)(v9->m_real.m128_u64[0] + v75 + 12) = v114;
LABEL_28:
      v71 = _mm_min_ps(*v49, v47);
      v72 = _mm_max_ps(_mm_shuffle_ps(v49[1], _mm_unpackhi_ps(v49[1], (__m128)0i64), 196), v48);
      *v50 = _mm_shuffle_ps(v71, _mm_unpackhi_ps(v71, *v50), 196);
      v50[1] = _mm_shuffle_ps(v72, _mm_unpackhi_ps(v72, v50[1]), 196);
    }
    else
    {
      v9[2].m_real.m128_i16[0] = v21;
      *(_DWORD *)(v93 + v75 + 12) = 1056964608;
    }
    goto LABEL_51;
  }
}

// File Line: 640
// RVA: 0xDA8230
void __fastcall hkpTreeBroadPhase32::removeUserObjects(hkpTreeBroadPhase32 *this, int numObjects, hkpBroadPhaseHandle *const *handles)
{
  __int64 v3; // r9
  hkpBroadPhaseHandle *const *v4; // rax
  hkpTreeBroadPhase32 *v5; // rbx
  __int64 v6; // r14
  int v7; // edi
  bool v8; // r13
  signed __int64 v9; // r15
  hkpTreeBroadPhase32::Handle *v10; // r12
  unsigned __int64 v11; // rdx
  __int64 v12; // r10
  __int64 v13; // rsi
  signed __int64 v14; // rbp
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  signed __int64 v17; // r9
  int v18; // eax
  signed __int64 v19; // r8
  unsigned __int64 v20; // r10
  unsigned int *v21; // r11
  unsigned __int64 v22; // rdx
  __int64 v23; // r8
  unsigned __int64 v24; // r8
  signed __int64 v25; // rcx
  __int64 v26; // r9
  unsigned __int64 v27; // rdx
  __m128 v28; // xmm2
  __m128 v29; // xmm1
  __int64 v30; // rcx
  signed __int64 v31; // r8
  signed __int64 v32; // rdx
  hkpTreeBroadPhase32::Handle *v33; // rcx
  signed __int64 v34; // rdx
  __int64 v35; // rax
  signed __int64 v36; // rcx
  __int64 v37; // [rsp+40h] [rbp+8h]
  hkpBroadPhaseHandle *const *v38; // [rsp+50h] [rbp+18h]

  if ( numObjects > 0 )
  {
    v38 = handles;
    v3 = numObjects;
    v4 = handles;
    v5 = this;
    v6 = 0i64;
    v37 = numObjects;
    do
    {
      v7 = v4[v6]->m_id & 0x7FFFFFFF;
      v8 = v7 < v5->m_handles[1].m_size - 1;
      v9 = v7;
      v10 = &v5->m_handles[1].m_data[v9];
      v10->m_bpHandle->m_id = 0;
      v11 = v5->m_internals[12].m_real.m128_u64[0];
      v12 = v5->m_internals[14].m_real.m128_i32[0];
      v13 = *((_DWORD *)v10 + 2) & 0x1FFFFF;
      v14 = v11 + 48 * v13;
      v15 = *(__m128 *)v14;
      v16 = *(__m128 *)(v14 + 16);
      if ( (_DWORD)v13 == (_DWORD)v12 )
      {
        v5->m_internals[14].m_real.m128_i32[0] = 0;
      }
      else
      {
        v17 = v11 + 48i64 * *(unsigned int *)(v14 + 32);
        v18 = *(_DWORD *)(v17 + 32);
        v19 = v11 + 48i64 * *(unsigned int *)(v17 + 4 * (10i64 - (*(_DWORD *)(v17 + 40) == (_DWORD)v13)));
        if ( v18 )
        {
          *(_DWORD *)(v19 + 32) = v18;
          v20 = v5->m_internals[12].m_real.m128_u64[0];
          v21 = (unsigned int *)(v19 + 32);
          v22 = (signed __int64)((unsigned __int128)((signed __int64)(v19 - v20)
                                                   * (signed __int128)3074457345618258603i64) >> 64) >> 3;
          *(_DWORD *)(v20
                    + 4
                    * ((*(_DWORD *)(v20 + 48i64 * *(unsigned int *)(v17 + 32) + 40) == *(_DWORD *)(v14 + 32))
                     + 12i64 * *(unsigned int *)(v17 + 32))
                    + 36) = (v22 >> 63) + v22;
          v23 = *(signed int *)(v14 + 32);
          *(float *)(v5->m_internals[12].m_real.m128_u64[0] + 48 * v23) = v5->m_internals[13].m_real.m128_f32[0];
          v5->m_internals[13].m_real.m128_i32[0] = v23;
          v24 = v5->m_internals[12].m_real.m128_u64[0];
          v25 = v24 + 48i64 * *v21;
          do
          {
            v26 = *(unsigned int *)(v25 + 32);
            v27 = v24
                + 48
                * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)(v25 - v24)
                                                                     * (signed __int128)3074457345618258603i64) >> 64) >> 3)
                 + ((unsigned __int64)((unsigned __int128)((signed __int64)(v25 - v24)
                                                         * (signed __int128)3074457345618258603i64) >> 64) >> 63));
            v28 = _mm_min_ps(
                    *(__m128 *)(v24 + 48i64 * *(unsigned int *)(v27 + 36)),
                    *(__m128 *)(v24 + 48i64 * *(unsigned int *)(v27 + 40)));
            v29 = _mm_max_ps(
                    *(__m128 *)(v24 + 48i64 * *(unsigned int *)(v27 + 36) + 16),
                    *(__m128 *)(v24 + 48i64 * *(unsigned int *)(v27 + 40) + 16));
            *(__m128 *)v27 = v28;
            *(__m128 *)(v27 + 16) = v29;
            if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v16, v29), _mm_cmpleps(v28, v15))) & 7) == 7 )
              break;
            if ( !(_DWORD)v26 )
              break;
            v24 = v5->m_internals[12].m_real.m128_u64[0];
            v25 = v24 + 48 * v26;
          }
          while ( v25 );
        }
        else
        {
          *(float *)(v11 + 48 * v12) = v5->m_internals[13].m_real.m128_f32[0];
          v36 = v19 - v5->m_internals[12].m_real.m128_u64[0];
          v5->m_internals[13].m_real.m128_i32[0] = v12;
          v5->m_internals[14].m_real.m128_i32[0] = ((unsigned __int64)((unsigned __int128)(v36
                                                                                         * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                                                 + ((signed __int64)((unsigned __int128)(v36
                                                                                       * (signed __int128)3074457345618258603i64) >> 64) >> 3);
          *(_DWORD *)(v19 + 32) = 0;
        }
        v3 = v37;
      }
      *(float *)(v5->m_internals[12].m_real.m128_u64[0] + 48i64 * (signed int)v13) = v5->m_internals[13].m_real.m128_f32[0];
      --v5->m_internals[13].m_real.m128_i32[2];
      v5->m_internals[13].m_real.m128_i32[0] = v13;
      v30 = --v5->m_handles[1].m_size;
      if ( (_DWORD)v30 != v7 )
      {
        v31 = 2i64;
        v32 = 16 * v30;
        v33 = &v5->m_handles[1].m_data[v9];
        v34 = v32 - v9 * 16;
        do
        {
          v35 = *(__int64 *)((char *)&v33->m_bpHandle + v34);
          v33 = (hkpTreeBroadPhase32::Handle *)((char *)v33 + 8);
          *((_QWORD *)&v33[-1] + 1) = v35;
          --v31;
        }
        while ( v31 );
      }
      if ( v8 )
      {
        *(_DWORD *)(v5->m_internals[12].m_real.m128_u64[0] + 48i64 * (*((_DWORD *)v10 + 2) & 0x1FFFFF) + 40) = v7;
        v10->m_bpHandle->m_id = v7 | 0x80000000;
      }
      v4 = v38;
      ++v6;
    }
    while ( v6 < v3 );
  }
}

// File Line: 662
// RVA: 0xD9C950
void __fastcall hkpTreeBroadPhase::addHandles(hkpTreeBroadPhase *this, hkpBroadPhaseHandle *const *handles, hkAabb *aabbs, int count)
{
  hkAabb *v4; // r13
  hkpBroadPhaseHandle *const *v5; // r10
  hkArray<hkpTreeBroadPhase::Handle,hkContainerHeapAllocator> *v6; // rsi
  hkpTreeBroadPhase *v7; // r8
  __int64 v8; // r12
  hkpBroadPhaseHandle *v9; // rdx
  char v10; // bl
  signed __int64 v11; // rax
  signed __int64 v12; // rdi
  hkpBroadPhaseHandle *v13; // rdx
  int v14; // ecx
  unsigned int v15; // eax
  __int16 v16; // bp
  signed __int64 v17; // rbx
  __int64 v18; // rcx
  int v19; // er14
  signed __int64 v20; // r15
  __int64 v21; // rcx
  unsigned __int16 v22; // bp
  __m128 v23; // xmm8
  __m128 v24; // xmm7
  __m128 *v25; // r9
  __m128 *v26; // r10
  unsigned __int16 v27; // cx
  __m128 v28; // xmm9
  __m128 v29; // xmm10
  __m128 *v30; // rcx
  __m128 *v31; // rdx
  __m128 v32; // xmm4
  __m128 v33; // xmm3
  __m128 v34; // xmm4
  __m128 v35; // xmm6
  __m128 v36; // xmm2
  __m128 v37; // xmm5
  __m128 v38; // xmm2
  __m128 v39; // xmm4
  __m128 v40; // xmm6
  __m128 v41; // xmm5
  __m128 v42; // xmm5
  unsigned __int16 v43; // ax
  signed __int64 v44; // r11
  int v45; // ecx
  __int64 v46; // rax
  __m128 v47; // xmm1
  __m128 v48; // xmm2
  hkResult v49; // [rsp+20h] [rbp-B8h]
  __int64 v50; // [rsp+28h] [rbp-B0h]
  __m128 *v51; // [rsp+30h] [rbp-A8h]
  __m128 *v52; // [rsp+38h] [rbp-A0h]
  hkpTreeBroadPhase *v53; // [rsp+E0h] [rbp+8h]
  hkpBroadPhaseHandle *const *v54; // [rsp+E8h] [rbp+10h]
  hkResult result; // [rsp+F8h] [rbp+20h]

  if ( count > 0 )
  {
    v54 = handles;
    v53 = this;
    v4 = aabbs;
    v5 = handles;
    v6 = this->m_handles;
    v7 = this;
    v8 = 0i64;
    v50 = count;
    do
    {
      v9 = v5[v8];
      if ( LOBYTE(v9[1].m_id) == 1 )
      {
        v10 = ((unsigned int)*((unsigned __int8 *)&v9[88].m_id
                             + SBYTE1(v9[1].m_id)
                             + *((char *)&v9[8].m_id + SBYTE1(v9[1].m_id)))
             - 4 > 1)
            + 2;
      }
      else if ( LOBYTE(v9[1].m_id) == 2 || LOBYTE(v9[1].m_id) == 3 )
      {
        v10 = 1;
      }
      else
      {
        v10 = 2;
      }
      if ( v6->m_size == (v6->m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, 16);
        v7 = v53;
        v5 = v54;
      }
      v11 = (signed __int64)&v6->m_data[v6->m_size];
      if ( v11 )
      {
        *(_QWORD *)v11 = 0i64;
        *(_DWORD *)(v11 + 8) = 0;
      }
      v12 = (signed __int64)&v6->m_data[v6->m_size++];
      v13 = v5[v8];
      *(_DWORD *)(v12 + 8) &= 0xFE1FFFFF;
      *(_DWORD *)(v12 + 8) |= (v10 & 0xF) << 21;
      v14 = *(_DWORD *)(v12 + 8);
      *(_QWORD *)v12 = v13;
      v15 = v14 & 0x1FFFFFF | (v13->m_id << 25);
      *(_DWORD *)(v12 + 8) = v15;
      v16 = v13->m_id;
      v17 = (signed __int64)v7 + 48 * (((v15 >> 21) & 0xF) + 1i64);
      if ( !*(_WORD *)(v17 + 16) )
        hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::Codec32>::reserveNodes(
          (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::Codec32> *)v17,
          &result,
          1);
      v18 = *(_QWORD *)v17;
      v19 = *(unsigned __int16 *)(v17 + 16);
      v20 = 32i64 * *(unsigned __int16 *)(v17 + 16);
      *(_WORD *)(v17 + 16) = *(_WORD *)(32i64 * *(unsigned __int16 *)(v17 + 16) + *(_QWORD *)v17);
      *(_WORD *)(v20 + v18 + 28) = 0;
      *(_WORD *)(v20 + v18 + 30) = v16;
      *(__m128 *)(v20 + v18) = _mm_shuffle_ps(
                                 v4->m_min.m_quad,
                                 _mm_unpackhi_ps(v4->m_min.m_quad, *(__m128 *)(v20 + v18)),
                                 196);
      *(__m128 *)(v20 + v18 + 16) = _mm_shuffle_ps(
                                      v4->m_max.m_quad,
                                      _mm_unpackhi_ps(v4->m_max.m_quad, *(__m128 *)(v20 + v18 + 16)),
                                      196);
      v21 = *(_QWORD *)v17;
      v22 = *(_WORD *)(v17 + 32);
      v23 = *(__m128 *)(*(_QWORD *)v17 + v20);
      v24 = _mm_shuffle_ps(
              *(__m128 *)(*(_QWORD *)v17 + v20 + 16),
              _mm_unpackhi_ps(*(__m128 *)(*(_QWORD *)v17 + v20 + 16), (__m128)0i64),
              196);
      if ( v22 )
      {
        if ( !*(_WORD *)(v17 + 16) )
          hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::Codec32>::reserveNodes(
            (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::Codec32> *)v17,
            &v49,
            1);
        v25 = (__m128 *)(*(_QWORD *)v17 + 32i64 * v22);
        v26 = (__m128 *)(*(_QWORD *)v17 + 32i64 * *(unsigned __int16 *)(v17 + 16));
        *(_WORD *)(v17 + 16) = v26->m128_u64[0];
        v27 = v25[1].m128_u16[6];
        if ( v27 )
        {
          v28 = _mm_add_ps(v24, v23);
          v29 = _mm_sub_ps(v24, v23);
          do
          {
            v30 = (__m128 *)(*(_QWORD *)v17 + 32i64 * v27);
            v31 = (__m128 *)(*(_QWORD *)v17 + 32i64 * v25[1].m128_u16[7]);
            v32 = _mm_min_ps(v23, *v25);
            v33 = _mm_max_ps(v24, _mm_shuffle_ps(v25[1], _mm_unpackhi_ps(v25[1], (__m128)0i64), 196));
            v51 = v30;
            v52 = v31;
            *v25 = _mm_shuffle_ps(v32, _mm_unpackhi_ps(v32, *v25), 196);
            v25[1] = _mm_shuffle_ps(v33, _mm_unpackhi_ps(v33, v25[1]), 196);
            v34 = _mm_shuffle_ps(v30[1], _mm_unpackhi_ps(v30[1], (__m128)0i64), 196);
            v35 = _mm_shuffle_ps(v31[1], _mm_unpackhi_ps(v31[1], (__m128)0i64), 196);
            v36 = _mm_sub_ps(_mm_add_ps(*v30, v34), v28);
            v37 = _mm_add_ps(*v31, v35);
            v38 = _mm_mul_ps(v36, v36);
            v39 = _mm_add_ps(_mm_sub_ps(v34, *v30), v29);
            v40 = _mm_add_ps(_mm_sub_ps(v35, *v31), v29);
            v41 = _mm_sub_ps(v37, v28);
            v42 = _mm_mul_ps(v41, v41);
            v25 = *(&v51
                  + ((float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v39, v39, 85))
                                           + COERCE_FLOAT(_mm_shuffle_ps(v39, v39, 0)))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v39, v39, 170)))
                           * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v38, v38, 85))
                                           + COERCE_FLOAT(_mm_shuffle_ps(v38, v38, 0)))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v38, v38, 170)))) > (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v42, v42, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v42, v42, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v42, v42, 170)))
                                                                                           * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 170))))));
            v27 = v25[1].m128_u16[6];
          }
          while ( v27 );
        }
        v43 = WORD2(v25->m128_u64[1]);
        v44 = ((signed __int64)v26 - *(_QWORD *)v17) >> 5;
        if ( v43 )
          *(_WORD *)(*(_QWORD *)v17
                   + 2
                   * (16i64 * v43
                    + (*(_WORD *)(32i64 * v43 + *(_QWORD *)v17 + 30) == (unsigned __int16)(((signed __int64)v25
                                                                                          - *(_QWORD *)v17) >> 5)))
                   + 28) = v44;
        else
          *(_WORD *)(v17 + 32) = v44;
        v45 = (unsigned __int16)v44 | 0x3F000000;
        HIDWORD(v26->m128_u64[1]) = WORD2(v25->m128_u64[1]) | 0x3F000000;
        v46 = (unsigned int)((_DWORD)v25 - *(_DWORD *)v17);
        v26[1].m128_i16[7] = v19;
        v26[1].m128_i16[6] = v46 >> 5;
        HIDWORD(v25->m128_u64[1]) = v45;
        *(_DWORD *)(*(_QWORD *)v17 + v20 + 12) = v45;
        v47 = _mm_min_ps(*v25, v23);
        v48 = _mm_max_ps(_mm_shuffle_ps(v25[1], _mm_unpackhi_ps(v25[1], (__m128)0i64), 196), v24);
        *v26 = _mm_shuffle_ps(v47, _mm_unpackhi_ps(v47, *v26), 196);
        v26[1] = _mm_shuffle_ps(v48, _mm_unpackhi_ps(v48, v26[1]), 196);
      }
      else
      {
        *(_WORD *)(v17 + 32) = v19;
        *(_DWORD *)(v21 + v20 + 12) = 1056964608;
      }
      ++*(_DWORD *)(v17 + 24);
      *(_DWORD *)(v12 + 8) &= 0xFFE00000;
      v7 = v53;
      v5 = v54;
      ++v8;
      ++v4;
      *(_DWORD *)(v12 + 8) |= v19 & 0x1FFFFF;
    }
    while ( v8 < v50 );
  }
}

// File Line: 705
// RVA: 0xDAA3E0
void __fastcall hkpTreeBroadPhase32::addHandlesStandalone(hkpTreeBroadPhase32 *this, hkpBroadPhaseHandle *const *handles, hkAabb *aabbs, int count, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *addPairs)
{
  int v5; // esi
  int v6; // er9
  int v7; // er9
  hkpBroadPhaseHandle *const *v8; // rbx
  int v9; // eax
  hkpTreeBroadPhase32 *v10; // r13
  int v11; // eax
  int v12; // er14
  unsigned __int64 v13; // r8
  int v14; // er15
  __int64 v15; // rdi
  __int64 v16; // r12
  hkAabb *v17; // rsi
  __int64 v18; // r14
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  __int64 v21; // r11
  __m128 v22; // xmm7
  __m128 v23; // xmm8
  unsigned __int64 v24; // rax
  unsigned __int64 *v25; // r10
  __m128 *v26; // rax
  __m128 v27; // xmm9
  __m128 v28; // xmm10
  __m128 v29; // xmm0
  __m128 v30; // xmm1
  unsigned __int64 v31; // rcx
  __m128 v32; // xmm2
  __m128 v33; // xmm3
  __m128 v34; // xmm2
  __m128 v35; // xmm6
  __m128 v36; // xmm3
  __m128 v37; // xmm3
  __m128 v38; // xmm5
  __m128 v39; // xmm5
  unsigned __int64 v40; // rbx
  unsigned __int64 v41; // r9
  __m128 v42; // xmm1
  hkpTreeBroadPhaseInternals::InsertionQuery *v43; // r9
  signed int v44; // ebx
  hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> > *v45; // rdi
  bool v46; // zf
  hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> > tree; // [rsp+30h] [rbp-D0h]
  __int64 v48; // [rsp+450h] [rbp+350h]
  __int64 v49; // [rsp+460h] [rbp+360h]
  __int64 v50; // [rsp+468h] [rbp+368h]
  __int64 v51; // [rsp+510h] [rbp+410h]
  hkpBroadPhaseHandle **handlesa; // [rsp+518h] [rbp+418h]
  hkAabb *aabbsa; // [rsp+520h] [rbp+420h]
  int v54; // [rsp+528h] [rbp+428h]

  v54 = count;
  aabbsa = aabbs;
  handlesa = (hkpBroadPhaseHandle **)handles;
  v5 = count;
  v6 = this->m_handles[0].m_size;
  tree.m_nodes[0].m_aabb.m_min.m_quad.m128_u64[0] = (unsigned __int64)addPairs;
  v7 = v5 + v6 + 1;
  v8 = handles;
  v9 = this->m_handles[0].m_capacityAndFlags & 0x3FFFFFFF;
  v10 = this;
  if ( v9 < v7 )
  {
    v11 = 2 * v9;
    if ( v7 < v11 )
      v7 = v11;
    hkArrayUtil::_reserve(
      (hkResult *)&addPairs,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      this->m_handles,
      v7,
      16);
  }
  if ( v5 > 0 )
  {
    v51 = ((unsigned int)(v5 - 1) >> 3) + 1;
    do
    {
      v12 = 8;
      if ( v5 < 8 )
        v12 = v5;
      LODWORD(addPairs) = v12;
      hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::releaseAll((hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *)&tree.m_nodes[0].m_parent);
      hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::releaseAll((hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *)&tree.m_nodes[0].m_parent);
      v14 = v10->m_handles[0].m_size;
      v50 = 0i64;
      v49 = 0i64;
      v15 = 0i64;
      v16 = v12;
      if ( v12 > 0 )
      {
        v17 = aabbsa;
        do
        {
          v8[v15]->m_id = v14;
          v18 = v48;
          v19 = v17->m_min.m_quad;
          v20 = v17->m_max.m_quad;
          v21 = v48 << 6;
          v22 = v19;
          v23 = v20;
          v48 = *(&tree.m_nodes[0].m_parent + 8 * (signed __int64)(signed int)v48);
          v24 = (unsigned __int64)v8[v15];
          *(unsigned __int64 *)((char *)&tree.m_nodes[1].m_aabb.m_min.m_quad.m128_u64[1] + v21) = 0i64;
          *(unsigned __int64 *)((char *)tree.m_nodes[1].m_aabb.m_max.m_quad.m128_u64 + v21) = v24;
          *(__m128 *)((char *)&tree.m_nodes[0].m_parent + v21) = v19;
          *(__m128 *)((char *)&tree.m_nodes[0].m_children[1] + v21) = v20;
          if ( v50 )
          {
            v25 = &tree.m_nodes[0].m_parent + 8 * v48;
            v48 = *(&tree.m_nodes[0].m_parent + 8 * (signed __int64)(signed int)v48);
            v26 = (__m128 *)(&tree.m_nodes[0].m_parent + 8 * v50);
            if ( v26[2].m128_i32[2] )
            {
              v27 = _mm_add_ps(v19, v20);
              v28 = _mm_sub_ps(v20, v19);
              do
              {
                v29 = _mm_min_ps(*v26, v22);
                v30 = _mm_max_ps(v26[1], v23);
                v31 = v26[3].m128_u64[0] << 6;
                tree.m_nodes[0].m_aabb.m_max.m_quad.m128_u64[0] = (unsigned __int64)(&tree.m_nodes[0].m_parent
                                                                                   + 8 * v26[2].m128_u64[1]);
                v13 = tree.m_nodes[0].m_aabb.m_max.m_quad.m128_u64[0];
                *v26 = v29;
                v26[1] = v30;
                v32 = *(__m128 *)(v13 + 16);
                tree.m_nodes[0].m_aabb.m_max.m_quad.m128_u64[1] = (unsigned __int64)&tree.m_nodes[0].m_parent + v31;
                v33 = v32;
                v34 = _mm_add_ps(_mm_sub_ps(v32, *(__m128 *)v13), v28);
                v35 = _mm_add_ps(
                        _mm_sub_ps(
                          *(__m128 *)(tree.m_nodes[0].m_aabb.m_max.m_quad.m128_u64[1] + 16),
                          *(__m128 *)tree.m_nodes[0].m_aabb.m_max.m_quad.m128_u64[1]),
                        v28);
                v36 = _mm_sub_ps(_mm_add_ps(v33, *(__m128 *)v13), v27);
                v37 = _mm_mul_ps(v36, v36);
                v38 = _mm_sub_ps(
                        _mm_add_ps(
                          *(__m128 *)(tree.m_nodes[0].m_aabb.m_max.m_quad.m128_u64[1] + 16),
                          *(__m128 *)tree.m_nodes[0].m_aabb.m_max.m_quad.m128_u64[1]),
                        v27);
                v39 = _mm_mul_ps(v38, v38);
                v26 = (__m128 *)tree.m_nodes[0].m_aabb.m_max.m_quad.m128_u64[(float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 0)))
                                                                                           + COERCE_FLOAT(
                                                                                               _mm_shuffle_ps(
                                                                                                 v34,
                                                                                                 v34,
                                                                                                 170)))
                                                                                   * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v37, v37, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v37, v37, 0)))
                                                                                           + COERCE_FLOAT(
                                                                                               _mm_shuffle_ps(
                                                                                                 v37,
                                                                                                 v37,
                                                                                                 170)))) > (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v39, v39, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v39, v39, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v39, v39, 170))) * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v35, v35, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v35, v35, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v35, v35, 170))))];
              }
              while ( v26[2].m128_i32[2] );
            }
            v40 = v26[2].m128_u64[0];
            v41 = ((char *)v25 - (char *)&tree.m_nodes[0].m_parent) >> 6;
            if ( v40 )
            {
              v13 = ((char *)v26 - (char *)&tree.m_nodes[0].m_parent) >> 6;
              tree.m_nodes[1].m_aabb.m_min.m_quad.m128_u64[(tree.m_nodes[1].m_aabb.m_max.m_quad.m128_u64[8 * v40] == v13)
                                                         + 8 * v40
                                                         + 1] = v41;
            }
            else
            {
              v50 = ((char *)v25 - (char *)&tree.m_nodes[0].m_parent) >> 6;
            }
            v8 = handlesa;
            v25[4] = v26[2].m128_u64[0];
            v25[6] = v18;
            v25[5] = ((char *)v26 - (char *)&tree.m_nodes[0].m_parent) >> 6;
            v26[2].m128_u64[0] = v41;
            *(unsigned __int64 *)((char *)tree.m_nodes[1].m_aabb.m_min.m_quad.m128_u64 + v21) = v41;
            v42 = _mm_max_ps(v26[1], v23);
            *(__m128 *)v25 = _mm_min_ps(*v26, v22);
            *((__m128 *)v25 + 1) = v42;
          }
          else
          {
            v50 = v18;
            *(unsigned __int64 *)((char *)tree.m_nodes[1].m_aabb.m_min.m_quad.m128_u64 + v21) = 0i64;
          }
          LODWORD(v49) = v49 + 1;
          ++v15;
          ++v14;
          ++v17;
        }
        while ( v15 < v16 );
        v5 = v54;
        v12 = (signed int)addPairs;
      }
      hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::allPairs<hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>>,hkpTreeBroadPhaseInternals::InsertionQuery>(
        (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)&tree.m_nodes[0].m_parent,
        &tree,
        (hkpTreeBroadPhaseInternals::InsertionQuery *)v13);
      v44 = 1;
      v45 = (hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> > *)&v10->m_internals[3];
      do
      {
        tree.m_nodes[0].m_aabb.m_min.m_quad.m128_u64[1] = (unsigned __int64)(&v10->vfptr)[2 * ((v44 == 4) + 18i64)];
        hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::allPairs<hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>>,hkpTreeBroadPhaseSpatialTree32,hkpTreeBroadPhaseInternals::InsertionQuery>(
          (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)&tree.m_nodes[0].m_parent,
          v45,
          (hkpTreeBroadPhaseSpatialTree32 *)&tree,
          v43);
        ++v44;
        v45 = (hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> > *)((char *)v45 + 48);
      }
      while ( v44 <= 3 );
      hkpTreeBroadPhase32::addHandles(v10, handlesa, aabbsa, v12);
      v8 = &handlesa[v16];
      v5 -= 8;
      v46 = v51-- == 1;
      aabbsa += v16;
      handlesa += v16;
      v54 = v5;
    }
    while ( !v46 );
  }
}

// File Line: 743
// RVA: 0xD9E9A0
void __fastcall hkpTreeBroadPhase::removeHandles(hkpTreeBroadPhase *this, hkpBroadPhaseHandle *const *handles, int count)
{
  hkpTreeBroadPhase *v3; // r12
  __int64 v4; // rcx
  hkpBroadPhaseHandle *const *v5; // rax
  __int64 v6; // r13
  __int64 v7; // rbp
  signed __int64 v8; // rdi
  __int16 v9; // r14
  signed __int64 v10; // r15
  signed __int64 v11; // r11
  __int64 v12; // rsi
  unsigned __int16 v13; // r8
  __m128 v14; // xmm6
  __m128 v15; // xmm4
  signed __int64 v16; // rdx
  unsigned __int16 v17; // ax
  signed __int64 v18; // rbx
  __int16 v19; // r8
  __int64 v20; // rdx
  signed __int64 v21; // rax
  unsigned __int16 v22; // r8
  __m128 *v23; // rcx
  signed __int64 v24; // rax
  __m128 v25; // xmm3
  __m128 v26; // xmm2
  signed __int64 v27; // rax
  __m128 v28; // xmm0
  __m128 v29; // xmm3
  __int64 v30; // [rsp+8h] [rbp-40h]
  hkpBroadPhaseHandle *const *v31; // [rsp+58h] [rbp+10h]

  if ( count > 0 )
  {
    v31 = handles;
    v3 = this;
    v4 = 0i64;
    v5 = handles;
    v6 = count;
    v7 = 0i64;
    do
    {
      v8 = (signed __int64)&v3->m_handles[0].m_data[v5[v7]->m_id];
      v9 = *(_WORD *)(v8 + 8);
      v10 = 32i64 * *(unsigned __int16 *)(v8 + 8);
      v11 = (signed __int64)v3 + 48 * (((*(_DWORD *)(v8 + 8) >> 21) & 0xF) + 1i64);
      v12 = *(_QWORD *)v11;
      v13 = *(_WORD *)(v11 + 32);
      v14 = *(__m128 *)(*(_QWORD *)v11 + v10);
      v15 = _mm_shuffle_ps(
              *(__m128 *)(*(_QWORD *)v11 + v10 + 16),
              _mm_unpackhi_ps(*(__m128 *)(*(_QWORD *)v11 + v10 + 16), (__m128)0i64),
              196);
      if ( v9 == v13 )
      {
        *(_WORD *)(v11 + 32) = 0;
      }
      else
      {
        v16 = v12 + 32i64 * *(unsigned __int16 *)(v12 + v10 + 12);
        LOBYTE(v4) = *(_WORD *)(v16 + 30) == v9;
        v17 = *(_WORD *)(v16 + 12);
        v18 = v12 + 32i64 * *(unsigned __int16 *)(v16 + 2 * (15 - v4));
        if ( v17 )
        {
          *(_DWORD *)(v18 + 12) = v17 | 0x3F000000;
          *(_WORD *)(*(_QWORD *)v11
                   + 2
                   * (16i64 * *(unsigned __int16 *)(v16 + 12)
                    + (*(_WORD *)(32i64 * *(unsigned __int16 *)(v16 + 12) + *(_QWORD *)v11 + 30) == *(_WORD *)(v12 + v10 + 12)))
                   + 28) = (v18 - *(_QWORD *)v11) >> 5;
          v19 = *(_WORD *)(v12 + v10 + 12);
          *(_WORD *)(32i64 * *(unsigned __int16 *)(v12 + v10 + 12) + *(_QWORD *)v11) = *(_WORD *)(v11 + 16);
          v20 = *(_QWORD *)v11;
          *(_WORD *)(v11 + 16) = v19;
          v21 = v20 + 32i64 * *(unsigned __int16 *)(v18 + 12);
          do
          {
            v22 = *(_WORD *)(v21 + 12);
            v23 = (__m128 *)(v20 + 32i64 * (unsigned __int16)((v21 - v20) >> 5));
            v24 = 32i64 * v23[1].m128_u16[6];
            v25 = *(__m128 *)(v24 + v20 + 16);
            v26 = *(__m128 *)(v24 + v20);
            v27 = 32i64 * v23[1].m128_u16[7];
            v28 = _mm_min_ps(v26, *(__m128 *)(v27 + v20));
            v29 = _mm_max_ps(
                    _mm_shuffle_ps(v25, _mm_unpackhi_ps(v25, (__m128)0i64), 196),
                    _mm_shuffle_ps(
                      *(__m128 *)(v27 + v20 + 16),
                      _mm_unpackhi_ps(*(__m128 *)(v27 + v20 + 16), (__m128)0i64),
                      196));
            *v23 = _mm_shuffle_ps(v28, _mm_unpackhi_ps(v28, *v23), 196);
            v23[1] = _mm_shuffle_ps(v29, _mm_unpackhi_ps(v29, v23[1]), 196);
            if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v15, v29), _mm_cmpleps(v28, v14))) & 7) == 7 )
              break;
            if ( !v22 )
              break;
            v20 = *(_QWORD *)v11;
            v21 = *(_QWORD *)v11 + 32i64 * v22;
          }
          while ( v21 );
        }
        else
        {
          *(_WORD *)(32i64 * v13 + v12) = *(_WORD *)(v11 + 16);
          *(_WORD *)(v11 + 16) = v13;
          *(_WORD *)(v11 + 32) = (signed __int64)(unsigned int)(v18 - *(_DWORD *)v11) >> 5;
          *(_DWORD *)(v18 + 12) = 1056964608;
        }
      }
      ++v7;
      *(_WORD *)(v10 + *(_QWORD *)v11) = *(_WORD *)(v11 + 16);
      --*(_DWORD *)(v11 + 24);
      v4 = 0i64;
      *(_WORD *)(v11 + 16) = v9;
      LODWORD(v30) = 0;
      *(_QWORD *)v8 = 0i64;
      *(_QWORD *)(v8 + 8) = v30;
      v5 = v31;
    }
    while ( v7 < v6 );
  }
}

// File Line: 758
// RVA: 0xD9EC30
void __fastcall hkpTreeBroadPhase::removeHandlesStandalone(hkpTreeBroadPhase *this, hkpBroadPhaseHandle *const *handles, int count, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *remPairs)
{
  hkpTreeBroadPhase *v4; // r15
  __int64 v5; // rcx
  signed __int64 v6; // r12
  signed int v7; // er14
  signed __int64 v8; // r10
  char *v9; // rsi
  __int16 v10; // r12
  signed __int64 v11; // r11
  __m128 *v12; // rax
  __int64 v13; // r8
  unsigned __int16 v14; // r9
  __m128 v15; // xmm6
  __m128 v16; // xmm7
  bool v17; // bl
  signed __int64 v18; // r13
  __m128 *v19; // rdi
  __m128 v20; // xmm6
  __m128 v21; // xmm5
  __m128 v22; // xmm4
  signed __int64 v23; // rdx
  unsigned __int16 v24; // ax
  signed __int64 v25; // rbx
  __int16 v26; // r8
  __int64 v27; // rdx
  signed __int64 v28; // rax
  unsigned __int16 v29; // r8
  __m128 *v30; // rcx
  signed __int64 v31; // rax
  __m128 v32; // xmm3
  __m128 v33; // xmm2
  signed __int64 v34; // rax
  __m128 v35; // xmm0
  __m128 v36; // xmm3
  __int64 v37; // rcx
  signed __int64 v38; // r8
  signed __int64 v39; // rdx
  char *v40; // rcx
  signed __int64 v41; // rdx
  __int64 v42; // rax
  __int64 v43; // r12
  signed int v44; // esi
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *v45; // r14
  hkLifoAllocator *v46; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsNoEarlyExitWrapper<hkpTreeBroadPhaseInternals::NewPairsQuery> *v47; // r9
  hkcdDynamicTree::Codec32 *v48; // rcx
  unsigned __int64 v49; // rdx
  int v50; // eax
  hkcdDynamicTree::Codec32 *p; // ST18_8
  hkcdDynamicTree::Codec32 *v52; // rdi
  signed int v53; // ebx
  hkLifoAllocator *v54; // rax
  int v55; // er8
  int v56; // [rsp+14h] [rbp-7Dh]
  hkpTreeBroadPhaseSpatialTree16 tree; // [rsp+20h] [rbp-71h]
  hkcdTreeQueriesStacks::Dynamic<64,unsigned short> stackInstance; // [rsp+58h] [rbp-39h]
  __m128 v59; // [rsp+78h] [rbp-19h]
  hkpBroadPhaseHandle *const *vars0; // [rsp+100h] [rbp+6Fh]
  bool retaddr; // [rsp+108h] [rbp+77h]
  signed __int64 v62; // [rsp+110h] [rbp+7Fh]

  v4 = this;
  v5 = 0i64;
  *(_QWORD *)&tree.m_root = remPairs;
  *(_QWORD *)&tree.m_numLeaves = 0i64;
  v6 = 0i64;
  *(_QWORD *)&tree.m_nodes.m_size = 0i64;
  *(_QWORD *)&tree.m_firstFree = count;
  if ( count > 0 )
  {
    do
    {
      v7 = handles[v6]->m_id;
      v8 = 16i64 * handles[v6]->m_id;
      v9 = (char *)v4->m_handles[0].m_data + v8;
      v62 = 16i64 * handles[v6]->m_id;
      v10 = *((_WORD *)v9 + 4);
      v11 = (signed __int64)v4 + 48 * (((*((_DWORD *)v9 + 2) >> 21) & 0xF) + 1i64);
      v12 = (__m128 *)(*(_QWORD *)v11 + 32i64 * *((unsigned __int16 *)v9 + 4));
      v13 = *(_QWORD *)v11;
      v14 = *(_WORD *)(v11 + 32);
      v15 = v12[1];
      v16 = *v12;
      LODWORD(v12) = v4->m_handles[0].m_size - 1;
      v17 = v7 < (signed int)v12;
      v18 = 32i64 * *((unsigned __int16 *)v9 + 4);
      v19 = (__m128 *)(*(_QWORD *)v11 + v18);
      retaddr = v7 < (signed int)v12;
      v20 = _mm_shuffle_ps(v15, _mm_unpackhi_ps(v15, (__m128)0i64), 196);
      v21 = *v19;
      v22 = _mm_shuffle_ps(v19[1], _mm_unpackhi_ps(v19[1], (__m128)0i64), 196);
      if ( v10 == v14 )
      {
        *(_WORD *)(v11 + 32) = v5;
      }
      else
      {
        v23 = v13 + 32i64 * WORD2(v19->m128_u64[1]);
        LOBYTE(v5) = *(_WORD *)(v23 + 30) == v10;
        v24 = *(_WORD *)(v23 + 12);
        v25 = v13 + 32i64 * *(unsigned __int16 *)(v23 + 2 * (15 - v5));
        if ( v24 )
        {
          *(_DWORD *)(v25 + 12) = v24 | 0x3F000000;
          *(_WORD *)(*(_QWORD *)v11
                   + 2
                   * (16i64 * *(unsigned __int16 *)(v23 + 12)
                    + (*(_WORD *)(32i64 * *(unsigned __int16 *)(v23 + 12) + *(_QWORD *)v11 + 30) == WORD2(v19->m128_u64[1])))
                   + 28) = (v25 - *(_QWORD *)v11) >> 5;
          v26 = WORD2(v19->m128_u64[1]);
          *(_WORD *)(32i64 * WORD2(v19->m128_u64[1]) + *(_QWORD *)v11) = *(_WORD *)(v11 + 16);
          v27 = *(_QWORD *)v11;
          *(_WORD *)(v11 + 16) = v26;
          v28 = v27 + 32i64 * *(unsigned __int16 *)(v25 + 12);
          do
          {
            v29 = *(_WORD *)(v28 + 12);
            v30 = (__m128 *)(v27 + 32i64 * (unsigned __int16)((v28 - v27) >> 5));
            v31 = 32i64 * v30[1].m128_u16[6];
            v32 = *(__m128 *)(v31 + v27 + 16);
            v33 = *(__m128 *)(v31 + v27);
            v34 = 32i64 * v30[1].m128_u16[7];
            v35 = _mm_min_ps(v33, *(__m128 *)(v34 + v27));
            v36 = _mm_max_ps(
                    _mm_shuffle_ps(v32, _mm_unpackhi_ps(v32, (__m128)0i64), 196),
                    _mm_shuffle_ps(
                      *(__m128 *)(v34 + v27 + 16),
                      _mm_unpackhi_ps(*(__m128 *)(v34 + v27 + 16), (__m128)0i64),
                      196));
            *v30 = _mm_shuffle_ps(v35, _mm_unpackhi_ps(v35, *v30), 196);
            v30[1] = _mm_shuffle_ps(v36, _mm_unpackhi_ps(v36, v30[1]), 196);
            if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v22, v36), _mm_cmpleps(v35, v21))) & 7) == 7 )
              break;
            if ( !v29 )
              break;
            v27 = *(_QWORD *)v11;
            v28 = *(_QWORD *)v11 + 32i64 * v29;
          }
          while ( v28 );
          v8 = v62;
        }
        else
        {
          *(_WORD *)(32i64 * v14 + v13) = *(_WORD *)(v11 + 16);
          *(_WORD *)(v11 + 16) = v14;
          *(_WORD *)(v11 + 32) = (signed __int64)(unsigned int)(v25 - *(_DWORD *)v11) >> 5;
          *(_DWORD *)(v25 + 12) = 1056964608;
        }
        v17 = retaddr;
      }
      *(_WORD *)(v18 + *(_QWORD *)v11) = *(_WORD *)(v11 + 16);
      --*(_DWORD *)(v11 + 24);
      *(_WORD *)(v11 + 16) = v10;
      **(_DWORD **)v9 = 0;
      v37 = --v4->m_handles[0].m_size;
      if ( (_DWORD)v37 != v7 )
      {
        v38 = 2i64;
        v39 = 16 * v37;
        v40 = (char *)v4->m_handles[0].m_data + v8;
        v41 = v39 - v8;
        do
        {
          v42 = *(_QWORD *)&v40[v41];
          v40 += 8;
          *((_QWORD *)v40 - 1) = v42;
          --v38;
        }
        while ( v38 );
      }
      if ( v17 )
      {
        **(_DWORD **)v9 = v7;
        HIWORD((&v4->vfptr)[6 * (((*((_DWORD *)v9 + 2) >> 21) & 0xF) + 1i64)][2 * *((unsigned __int16 *)v9 + 4) + 1].__first_virtual_table_function__) = v7;
      }
      v43 = *(_QWORD *)&tree.m_nodes.m_size;
      v44 = 1;
      v45 = (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)&v4->m_internals[3];
      *(hkpBroadPhaseHandle **)&tree.m_sortPath = vars0[*(_QWORD *)&tree.m_nodes.m_size];
      do
      {
        *(__m128 *)&stackInstance.m_stack.m_localMemory = v16;
        v59 = v20;
        tree.m_nodes.m_data = 0i64;
        tree.m_nodes.m_size = 0;
        LODWORD(tree.m_nodes.m_data) = 64;
        *(_QWORD *)&tree.m_numLeaves = (&v4->vfptr)[2 * ((v44 == 4) + 18i64)];
        stackInstance.m_stack.m_data = (unsigned __int16 *)&tree.m_numLeaves;
        v46 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v48 = (hkcdDynamicTree::Codec32 *)v46->m_cur;
        v49 = (unsigned __int64)&v48[4];
        if ( v46->m_slabSize < 128 || (void *)v49 > v46->m_end )
          v48 = (hkcdDynamicTree::Codec32 *)hkLifoAllocator::allocateFromNewSlab(v46, 128);
        else
          v46->m_cur = (void *)v49;
        tree.m_nodes.m_data = v48;
        hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkpTreeBroadPhaseSpatialTree16,hkcdTreeQueriesStacks::Dynamic<64,unsigned short>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsNoEarlyExitWrapper<hkpTreeBroadPhaseInternals::NewPairsQuery>>(
          v45,
          &tree,
          &stackInstance,
          v47);
        v50 = tree.m_nodes.m_size;
        v52 = p;
        if ( p == tree.m_nodes.m_data )
          v50 = 0;
        tree.m_nodes.m_size = v50;
        v53 = (2 * LODWORD(tree.m_nodes.m_data) + 127) & 0xFFFFFF80;
        v54 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v55 = (v53 + 15) & 0xFFFFFFF0;
        if ( v53 > v54->m_slabSize || (char *)v52 + v55 != v54->m_cur || v54->m_firstNonLifoEnd == v52 )
          hkLifoAllocator::slowBlockFree(v54, v52, v55);
        else
          v54->m_cur = v52;
        tree.m_nodes.m_size = 0;
        if ( v56 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            tree.m_nodes.m_data,
            2 * (v56 & 0x3FFFFFFF));
        ++v44;
        v45 += 48;
      }
      while ( v44 <= 3 );
      handles = vars0;
      v6 = v43 + 1;
      v5 = 0i64;
      *(_QWORD *)&tree.m_nodes.m_size = v6;
    }
    while ( v6 < *(_QWORD *)&tree.m_firstFree );
  }
}

// File Line: 791
// RVA: 0xDAA890
void __fastcall hkpTreeBroadPhase32::updateHandles(hkpTreeBroadPhase32 *this, hkpBroadPhaseHandle *const *handles, hkAabb *aabbs, int count)
{
  __int64 v4; // r12
  hkAabb *v5; // r15
  hkpTreeBroadPhase32 *v6; // r13
  __m128 v7; // xmm11
  __m128 v8; // xmm12
  hkpTreeBroadPhase32::Handle *v9; // r8
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint> *v10; // rbx
  unsigned int v11; // eax
  hkcdDynamicTree::CodecRawUint *v12; // r9
  __m128 v13; // xmm2
  __int64 v14; // r10
  char *v15; // rcx
  signed __int64 v16; // rbp
  __m128 v17; // xmm1
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  __m128 v20; // xmm4
  signed __int64 v21; // rdi
  signed __int64 v22; // rdx
  int v23; // eax
  signed __int64 v24; // r8
  __int64 v25; // r9
  unsigned int *v26; // r11
  unsigned __int64 v27; // rdx
  __int64 v28; // r8
  hkcdDynamicTree::CodecRawUint *v29; // r9
  signed __int64 v30; // rcx
  __int64 v31; // r10
  unsigned __int64 v32; // rdi
  unsigned __int64 v33; // r8
  __m128 v34; // xmm2
  __m128 v35; // xmm1
  signed __int64 v36; // rcx
  hkcdDynamicTree::CodecRawUint *v37; // rax
  signed __int64 v38; // rsi
  hkcdDynamicTree::CodecRawUint *v39; // rax
  __m128 v40; // xmm7
  __m128 v41; // xmm8
  __int64 v42; // rdx
  hkcdDynamicTree::CodecRawUint *v43; // r8
  signed __int64 v44; // r11
  __m128 *v45; // r9
  __int64 v46; // rax
  __m128 v47; // xmm9
  __m128 v48; // xmm10
  __int64 v49; // r8
  __m128 v50; // xmm0
  __m128 v51; // xmm1
  signed __int64 v52; // rdx
  __m128 *v53; // rdx
  __m128 v54; // xmm2
  __m128 v55; // xmm3
  __m128 v56; // xmm2
  __m128 v57; // xmm5
  __m128 v58; // xmm3
  __m128 v59; // xmm3
  __m128 v60; // xmm6
  __m128 v61; // xmm6
  hkcdDynamicTree::CodecRawUint *v62; // rdi
  unsigned __int64 v63; // rdx
  unsigned __int64 v64; // r10
  float v65; // eax
  signed __int64 v66; // rcx
  __m128 v67; // xmm1
  hkcdDynamicTree::CodecRawUint *v68; // rsi
  __int64 v69; // r9
  signed __int64 v70; // rdx
  int v71; // er14
  signed __int64 v72; // rdi
  __m128 v73; // xmm3
  __m128 v74; // xmm4
  signed __int64 v75; // rdx
  int v76; // eax
  signed __int64 v77; // r8
  __int64 v78; // r9
  unsigned int *v79; // r11
  unsigned __int64 v80; // rdx
  __int64 v81; // r8
  hkcdDynamicTree::CodecRawUint *v82; // r8
  signed __int64 v83; // rcx
  __int64 v84; // r9
  unsigned __int64 v85; // rdx
  __m128 v86; // xmm2
  __m128 v87; // xmm1
  signed __int64 v88; // rcx
  hkcdDynamicTree::CodecRawUint *v89; // rax
  hkcdDynamicTree::CodecRawUint *v90; // rax
  __int64 v91; // rsi
  __m128 v92; // xmm7
  __m128 v93; // xmm8
  __int64 v94; // rdx
  __m128 *v95; // r9
  signed __int64 v96; // r11
  __int64 v97; // rax
  __m128 v98; // xmm9
  __m128 v99; // xmm10
  __int64 v100; // r8
  __m128 v101; // xmm0
  __m128 v102; // xmm1
  signed __int64 v103; // rdx
  __m128 *v104; // rdx
  __m128 v105; // xmm3
  __m128 v106; // xmm2
  __m128 v107; // xmm3
  __m128 v108; // xmm2
  __m128 v109; // xmm2
  __m128 v110; // xmm6
  __m128 v111; // xmm5
  __m128 v112; // xmm5
  hkcdDynamicTree::CodecRawUint *v113; // rsi
  unsigned __int64 v114; // rdx
  unsigned __int64 v115; // r10
  float v116; // eax
  signed __int64 v117; // rcx
  __m128 v118; // xmm1
  __int64 v119; // [rsp+20h] [rbp-D8h]
  hkcdDynamicTree::CodecRawUint *v120; // [rsp+28h] [rbp-D0h]
  __m128 *v121; // [rsp+30h] [rbp-C8h]
  hkcdDynamicTree::CodecRawUint *v122; // [rsp+38h] [rbp-C0h]
  __m128 *v123; // [rsp+40h] [rbp-B8h]
  hkResult v124; // [rsp+100h] [rbp+8h]
  hkpBroadPhaseHandle *const *v125; // [rsp+108h] [rbp+10h]
  hkResult result; // [rsp+118h] [rbp+20h]

  v125 = handles;
  result.m_enum = this->m_parameters.m_quad.m128_i32[0];
  v4 = 0i64;
  v5 = aabbs;
  v6 = this;
  v119 = count;
  v7 = _mm_shuffle_ps((__m128)(unsigned int)result.m_enum, (__m128)(unsigned int)result.m_enum, 0);
  v8 = _mm_shuffle_ps(this->m_offsetAndTimeStep.m_quad, this->m_offsetAndTimeStep.m_quad, 255);
  if ( count > 0 )
  {
    while ( 1 )
    {
      v9 = &v6->m_handles[0].m_data[handles[v4]->m_id];
      v10 = (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint> *)&(&v6->vfptr)[6 * (((*((_DWORD *)v9 + 2) >> 21) & 0xF) + 1i64)];
      v11 = *((_DWORD *)v9 + 2) & 0x1FFFFFF ^ ((*((_DWORD *)v9 + 2) & 0xFE000000) + 0x2000000);
      *((_DWORD *)v9 + 2) = v11;
      if ( !(v11 & 0xFE000000) || (v11 & 0x1E00000) != 6291456 )
      {
        v68 = v10->m_nodes.m_data;
        v69 = v10[1].m_nodes.m_size;
        v70 = v11 & 0x1FFFFF;
        v71 = v11 & 0x1FFFFF;
        v72 = v70;
        v73 = v10->m_nodes.m_data[v70].m_aabb.m_min.m_quad;
        v74 = v10->m_nodes.m_data[v70].m_aabb.m_max.m_quad;
        if ( (_DWORD)v70 == (_DWORD)v69 )
        {
          v10[1].m_nodes.m_size = 0;
        }
        else
        {
          v75 = (signed __int64)&v68[v68[v70].m_parent];
          v76 = *(_DWORD *)(v75 + 32);
          v77 = (signed __int64)&v68[*(unsigned int *)(v75 + 4 * (10i64 - (*(_DWORD *)(v75 + 40) == v71)))];
          if ( v76 )
          {
            *(_DWORD *)(v77 + 32) = v76;
            v78 = *(unsigned int *)(v75 + 32);
            v79 = (unsigned int *)(v77 + 32);
            v80 = (signed __int64)((unsigned __int128)((v77 - (unsigned __int64)v10->m_nodes.m_data)
                                                     * (signed __int128)3074457345618258603i64) >> 64) >> 3;
            v10->m_nodes.m_data->m_children[(v10->m_nodes.m_data[v78].m_children[1] == v68[v72].m_parent) + 12 * v78] = (v80 >> 63) + v80;
            v81 = (signed int)v68[v72].m_parent;
            v10->m_nodes.m_data[v81].m_aabb.m_min.m_quad.m128_i32[0] = v10->m_firstFree;
            v10->m_firstFree = v81;
            v82 = v10->m_nodes.m_data;
            v83 = (signed __int64)&v10->m_nodes.m_data[*v79];
            do
            {
              v84 = *(unsigned int *)(v83 + 32);
              v85 = (unsigned __int64)&v82[(unsigned int)((signed __int64)((unsigned __int128)((v83 - (signed __int64)v82)
                                                                                             * (signed __int128)3074457345618258603i64) >> 64) >> 3)
                                         + ((unsigned __int64)((unsigned __int128)((v83 - (signed __int64)v82)
                                                                                 * (signed __int128)3074457345618258603i64) >> 64) >> 63)];
              v86 = _mm_min_ps(
                      v82[*(unsigned int *)(v85 + 36)].m_aabb.m_min.m_quad,
                      v82[*(unsigned int *)(v85 + 40)].m_aabb.m_min.m_quad);
              v87 = _mm_max_ps(
                      v82[*(unsigned int *)(v85 + 36)].m_aabb.m_max.m_quad,
                      v82[*(unsigned int *)(v85 + 40)].m_aabb.m_max.m_quad);
              *(__m128 *)v85 = v86;
              *(__m128 *)(v85 + 16) = v87;
              if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v74, v87), _mm_cmpleps(v86, v73))) & 7) == 7 )
                break;
              if ( !(_DWORD)v84 )
                break;
              v82 = v10->m_nodes.m_data;
              v83 = (signed __int64)&v10->m_nodes.m_data[v84];
            }
            while ( v83 );
          }
          else
          {
            v68[v69].m_aabb.m_min.m_quad.m128_i32[0] = v10->m_firstFree;
            v88 = v77 - (unsigned __int64)v10->m_nodes.m_data;
            v10->m_firstFree = v69;
            v10[1].m_nodes.m_size = ((unsigned __int64)((unsigned __int128)(v88 * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                                  + ((signed __int64)((unsigned __int128)(v88 * (signed __int128)3074457345618258603i64) >> 64) >> 3);
            *(_DWORD *)(v77 + 32) = 0;
          }
        }
        v89 = v10->m_nodes.m_data;
        v89[v72].m_aabb.m_min = v5->m_min;
        v89[v72].m_aabb.m_max = v5->m_max;
        v90 = v10->m_nodes.m_data;
        v91 = (unsigned int)v10[1].m_nodes.m_size;
        v92 = v10->m_nodes.m_data[v72].m_aabb.m_min.m_quad;
        v93 = v10->m_nodes.m_data[v72].m_aabb.m_max.m_quad;
        if ( (_DWORD)v91 )
        {
          if ( !v10->m_firstFree )
            hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
              v10,
              &v124,
              1);
          v94 = v10->m_firstFree;
          v95 = &v10->m_nodes.m_data[v91].m_aabb.m_min.m_quad;
          v96 = (signed __int64)&v10->m_nodes.m_data[v94];
          v10->m_firstFree = v10->m_nodes.m_data[(signed int)v94].m_aabb.m_min.m_quad.m128_u32[0];
          v97 = v95[2].m128_u32[1];
          if ( (_DWORD)v97 )
          {
            v98 = _mm_add_ps(v93, v92);
            v99 = _mm_sub_ps(v93, v92);
            do
            {
              v101 = _mm_min_ps(*v95, v92);
              v102 = _mm_max_ps(v95[1], v93);
              v103 = v95[2].m128_u32[2];
              v122 = &v10->m_nodes.m_data[v97];
              v100 = (__int64)v122;
              v104 = &v10->m_nodes.m_data[v103].m_aabb.m_min.m_quad;
              v123 = v104;
              *v95 = v101;
              v95[1] = v102;
              v105 = *(__m128 *)(v100 + 16);
              v106 = v105;
              v107 = _mm_add_ps(_mm_sub_ps(v105, *(__m128 *)v100), v99);
              v108 = _mm_sub_ps(_mm_add_ps(v106, *(__m128 *)v100), v98);
              v109 = _mm_mul_ps(v108, v108);
              v110 = _mm_add_ps(_mm_sub_ps(v104[1], *v104), v99);
              v111 = _mm_sub_ps(_mm_add_ps(v104[1], *v104), v98);
              v112 = _mm_mul_ps(v111, v111);
              v95 = (__m128 *)*(&v122
                              + ((float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v109, v109, 85))
                                                       + COERCE_FLOAT(_mm_shuffle_ps(v109, v109, 0)))
                                               + COERCE_FLOAT(_mm_shuffle_ps(v109, v109, 170)))
                                       * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v107, v107, 85))
                                                       + COERCE_FLOAT(_mm_shuffle_ps(v107, v107, 0)))
                                               + COERCE_FLOAT(_mm_shuffle_ps(v107, v107, 170)))) > (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v112, v112, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v112, v112, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v112, v112, 170))) * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v110, v110, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v110, v110, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v110, v110, 170))))));
              v97 = v95[2].m128_u32[1];
            }
            while ( (_DWORD)v97 );
          }
          v114 = (unsigned __int128)((v96 - (unsigned __int64)v10->m_nodes.m_data)
                                   * (signed __int128)3074457345618258603i64) >> 64;
          v115 = (v114 >> 63) + ((signed __int64)v114 >> 3);
          v116 = v95[2].m128_f32[0];
          if ( v116 == 0.0 )
          {
            v10[1].m_nodes.m_size = v115;
          }
          else
          {
            v113 = v10->m_nodes.m_data;
            v113->m_children[(v113[LODWORD(v116)].m_children[1] == ((unsigned __int64)((unsigned __int128)(((char *)v95 - (char *)v113) * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                                                                 + (unsigned int)((signed __int64)((unsigned __int128)(((char *)v95 - (char *)v113) * (signed __int128)3074457345618258603i64) >> 64) >> 3))
                           + 12i64 * LODWORD(v116)] = v115;
          }
          *(float *)(v96 + 32) = v95[2].m128_f32[0];
          v117 = (char *)v95 - (char *)v10->m_nodes.m_data;
          *(_DWORD *)(v96 + 40) = v71;
          *(_DWORD *)(v96 + 36) = ((unsigned __int64)((unsigned __int128)(v117 * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                                + ((signed __int64)((unsigned __int128)(v117 * (signed __int128)3074457345618258603i64) >> 64) >> 3);
          v95[2].m128_i32[0] = v115;
          v10->m_nodes.m_data[v72].m_parent = v115;
          v118 = _mm_max_ps(v95[1], v93);
          *(__m128 *)v96 = _mm_min_ps(*v95, v92);
          *(__m128 *)(v96 + 16) = v118;
        }
        else
        {
          v10[1].m_nodes.m_size = v71;
          v90[v72].m_parent = 0;
        }
        goto LABEL_46;
      }
      v12 = v10->m_nodes.m_data;
      v13 = v5->m_max.m_quad;
      if ( _mm_movemask_ps(
             _mm_or_ps(
               _mm_cmpltps(v5->m_min.m_quad, v10->m_nodes.m_data[v11 & 0x1FFFFF].m_aabb.m_min.m_quad),
               _mm_cmpltps(v10->m_nodes.m_data[v11 & 0x1FFFFF].m_aabb.m_max.m_quad, v13))) & 7 )
        break;
LABEL_46:
      handles = v125;
      ++v4;
      ++v5;
      if ( v4 >= v119 )
        return;
    }
    v14 = v10[1].m_nodes.m_size;
    v15 = (char *)v9->m_bpHandle + SBYTE1(v9->m_bpHandle[1].m_id);
    v16 = v11 & 0x1FFFFF;
    v17 = _mm_mul_ps(*(__m128 *)&v15[v15[32] + 560], v8);
    v18 = _mm_shuffle_ps(v17, _mm_unpackhi_ps(v17, v7), 196);
    v19 = _mm_min_ps(_mm_add_ps(v5->m_min.m_quad, v18), v5->m_min.m_quad);
    v20 = _mm_max_ps(_mm_add_ps(v13, v18), v13);
    if ( (v11 & 0x1FFFFF) == (_DWORD)v14 )
    {
      v10[1].m_nodes.m_size = 0;
    }
    else
    {
      v21 = (signed __int64)&v12[v11 & 0x1FFFFF];
      v22 = (signed __int64)&v12[*(unsigned int *)(v21 + 32)];
      v23 = *(_DWORD *)(v22 + 32);
      v24 = (signed __int64)&v12[*(unsigned int *)(v22 + 4 * (10i64 - (*(_DWORD *)(v22 + 40) == (_DWORD)v16)))];
      if ( v23 )
      {
        *(_DWORD *)(v24 + 32) = v23;
        v25 = *(unsigned int *)(v22 + 32);
        v26 = (unsigned int *)(v24 + 32);
        v27 = (unsigned __int128)((v24 - (unsigned __int64)v10->m_nodes.m_data) * (signed __int128)3074457345618258603i64) >> 64;
        v10->m_nodes.m_data->m_children[(v10->m_nodes.m_data[v25].m_children[1] == *(_DWORD *)(v21 + 32)) + 12 * v25] = (v27 >> 63) + ((signed __int64)v27 >> 3);
        v28 = *(signed int *)(v21 + 32);
        v10->m_nodes.m_data[v28].m_aabb.m_min.m_quad.m128_i32[0] = v10->m_firstFree;
        v29 = v10->m_nodes.m_data;
        v10->m_firstFree = v28;
        v30 = (signed __int64)&v29[*v26];
        while ( 1 )
        {
          v31 = *(unsigned int *)(v30 + 32);
          v32 = ((unsigned __int64)((unsigned __int128)((v30 - (signed __int64)v29)
                                                      * (signed __int128)3074457345618258603i64) >> 64) >> 63)
              + ((signed __int64)((unsigned __int128)((v30 - (signed __int64)v29)
                                                    * (signed __int128)3074457345618258603i64) >> 64) >> 3);
          v33 = (unsigned __int64)&v29[((unsigned __int64)((unsigned __int128)((v30 - (signed __int64)v29)
                                                                             * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                                     + (unsigned int)((signed __int64)((unsigned __int128)((v30 - (signed __int64)v29)
                                                                                         * (signed __int128)3074457345618258603i64) >> 64) >> 3)];
          v34 = _mm_min_ps(
                  v29[*(unsigned int *)(v33 + 36)].m_aabb.m_min.m_quad,
                  v29[*(unsigned int *)(v33 + 40)].m_aabb.m_min.m_quad);
          v35 = _mm_max_ps(
                  v29[*(unsigned int *)(v33 + 36)].m_aabb.m_max.m_quad,
                  v29[*(unsigned int *)(v33 + 40)].m_aabb.m_max.m_quad);
          *(__m128 *)v33 = v34;
          *(__m128 *)(v33 + 16) = v35;
          if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v20, v35), _mm_cmpleps(v34, v19))) & 7) == 7 )
            goto LABEL_15;
          if ( (_DWORD)v31 )
          {
            v29 = v10->m_nodes.m_data;
            v30 = (signed __int64)&v10->m_nodes.m_data[v31];
            if ( v30 )
              continue;
          }
          goto LABEL_14;
        }
      }
      v12[v14].m_aabb.m_min.m_quad.m128_i32[0] = v10->m_firstFree;
      v36 = v24 - (unsigned __int64)v10->m_nodes.m_data;
      v10->m_firstFree = v14;
      v10[1].m_nodes.m_size = ((unsigned __int64)((unsigned __int128)(v36 * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                            + ((signed __int64)((unsigned __int128)(v36 * (signed __int128)3074457345618258603i64) >> 64) >> 3);
      *(_DWORD *)(v24 + 32) = 0;
    }
LABEL_14:
    LODWORD(v32) = v10[1].m_nodes.m_size;
LABEL_15:
    v37 = v10->m_nodes.m_data;
    v38 = v16;
    v37[v38].m_aabb.m_min.m_quad = v19;
    v37[v38].m_aabb.m_max.m_quad = v20;
    v39 = v10->m_nodes.m_data;
    v40 = v10->m_nodes.m_data[v16].m_aabb.m_min.m_quad;
    v41 = v10->m_nodes.m_data[v16].m_aabb.m_max.m_quad;
    if ( (_DWORD)v32 )
    {
      if ( !v10->m_firstFree )
        hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
          v10,
          &result,
          1);
      v42 = v10->m_firstFree;
      v43 = v10->m_nodes.m_data;
      v44 = (signed __int64)&v10->m_nodes.m_data[v42];
      v10->m_firstFree = v10->m_nodes.m_data[(signed int)v42].m_aabb.m_min.m_quad.m128_u32[0];
      v45 = &v43[(unsigned int)v32].m_aabb.m_min.m_quad;
      v46 = v45[2].m128_u32[1];
      if ( (_DWORD)v46 )
      {
        v47 = _mm_add_ps(v41, v40);
        v48 = _mm_sub_ps(v41, v40);
        do
        {
          v50 = _mm_min_ps(*v45, v40);
          v51 = _mm_max_ps(v45[1], v41);
          v52 = v45[2].m128_u32[2];
          v120 = &v10->m_nodes.m_data[v46];
          v49 = (__int64)v120;
          v53 = &v10->m_nodes.m_data[v52].m_aabb.m_min.m_quad;
          v121 = v53;
          *v45 = v50;
          v45[1] = v51;
          v54 = *(__m128 *)(v49 + 16);
          v55 = v54;
          v56 = _mm_add_ps(_mm_sub_ps(v54, *(__m128 *)v49), v48);
          v57 = _mm_add_ps(_mm_sub_ps(v53[1], *v53), v48);
          v58 = _mm_sub_ps(_mm_add_ps(v55, *(__m128 *)v49), v47);
          v59 = _mm_mul_ps(v58, v58);
          v60 = _mm_sub_ps(_mm_add_ps(v53[1], *v53), v47);
          v61 = _mm_mul_ps(v60, v60);
          v45 = (__m128 *)*(&v120
                          + ((float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v56, v56, 85))
                                                   + COERCE_FLOAT(_mm_shuffle_ps(v56, v56, 0)))
                                           + COERCE_FLOAT(_mm_shuffle_ps(v56, v56, 170)))
                                   * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v59, v59, 85))
                                                   + COERCE_FLOAT(_mm_shuffle_ps(v59, v59, 0)))
                                           + COERCE_FLOAT(_mm_shuffle_ps(v59, v59, 170)))) > (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v57, v57, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v57, v57, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v57, v57, 170))) * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v61, v61, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v61, v61, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v61, v61, 170))))));
          v46 = v45[2].m128_u32[1];
        }
        while ( (_DWORD)v46 );
      }
      v63 = (unsigned __int128)((v44 - (unsigned __int64)v10->m_nodes.m_data) * (signed __int128)3074457345618258603i64) >> 64;
      v64 = (v63 >> 63) + ((signed __int64)v63 >> 3);
      v65 = v45[2].m128_f32[0];
      if ( v65 == 0.0 )
      {
        v10[1].m_nodes.m_size = v64;
      }
      else
      {
        v62 = v10->m_nodes.m_data;
        v62->m_children[(v62[LODWORD(v65)].m_children[1] == ((unsigned __int64)((unsigned __int128)(((char *)v45 - (char *)v62)
                                                                                                  * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                                                          + (unsigned int)((signed __int64)((unsigned __int128)(((char *)v45 - (char *)v62) * (signed __int128)3074457345618258603i64) >> 64) >> 3))
                      + 12i64 * LODWORD(v65)] = v64;
      }
      *(float *)(v44 + 32) = v45[2].m128_f32[0];
      v66 = (char *)v45 - (char *)v10->m_nodes.m_data;
      *(_DWORD *)(v44 + 40) = v16;
      *(_DWORD *)(v44 + 36) = ((unsigned __int64)((unsigned __int128)(v66 * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                            + ((signed __int64)((unsigned __int128)(v66 * (signed __int128)3074457345618258603i64) >> 64) >> 3);
      v45[2].m128_i32[0] = v64;
      v10->m_nodes.m_data[v16].m_parent = v64;
      v67 = _mm_max_ps(v45[1], v41);
      *(__m128 *)v44 = _mm_min_ps(*v45, v40);
      *(__m128 *)(v44 + 16) = v67;
    }
    else
    {
      v10[1].m_nodes.m_size = v16;
      v39[v16].m_parent = 0;
    }
    goto LABEL_46;
  }
}

// File Line: 805
// RVA: 0xDAB2A0
void __fastcall hkpTreeBroadPhase32::updateHandlesStandalone(hkpTreeBroadPhase32 *this, hkpBroadPhaseHandle *const *handles, hkAabb *aabbs, int count, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *addPairs, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *remPairs)
{
  float v6; // xmm0_4
  hkVector4f v7; // xmm14
  signed __int64 v8; // r12
  __m128 v9; // xmm13
  __m128 v10; // xmm14
  hkAabb *v11; // r13
  hkpTreeBroadPhase32 *v12; // r15
  __m128 v13; // xmm3
  __m128 v14; // xmm4
  hkpTreeBroadPhase32::Handle *v15; // r9
  unsigned int v16; // edx
  unsigned int v17; // er8
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint> *v18; // rbx
  signed __int64 v19; // rcx
  hkArray<hkcdDynamicTree::CodecRawUint,hkContainerHeapAllocator> v20; // xmm2
  __m128 v21; // xmm1
  __int64 v22; // r10
  __int64 v23; // r8
  signed __int64 v24; // r14
  char *v25; // rcx
  __m128 v26; // xmm1
  __m128 v27; // xmm1
  hkArray<hkcdDynamicTree::CodecRawUint,hkContainerHeapAllocator> v28; // xmm7
  __m128 v29; // xmm8
  signed __int64 v30; // rdi
  signed __int64 v31; // r9
  int v32; // eax
  signed __int64 v33; // r8
  unsigned int *v34; // r11
  unsigned __int64 v35; // rdx
  __int64 v36; // r8
  hkcdDynamicTree::CodecRawUint *v37; // r9
  signed __int64 v38; // rcx
  __int64 v39; // r10
  unsigned __int64 v40; // rdi
  unsigned __int64 v41; // r8
  __m128 v42; // xmm2
  __m128 v43; // xmm1
  signed __int64 v44; // rcx
  hkcdDynamicTree::CodecRawUint *v45; // rax
  signed __int64 v46; // rsi
  hkcdDynamicTree::CodecRawUint *v47; // rax
  __m128 v48; // xmm9
  __m128 v49; // xmm10
  __int64 v50; // rdx
  hkcdDynamicTree::CodecRawUint *v51; // r8
  signed __int64 v52; // r11
  __m128 *v53; // r9
  __int64 v54; // rax
  __m128 v55; // xmm11
  __m128 v56; // xmm12
  __m128 *v57; // r8
  __m128 v58; // xmm0
  __m128 v59; // xmm1
  signed __int64 v60; // rdx
  __int64 v61; // rdx
  __m128 v62; // xmm6
  __m128 v63; // xmm5
  __m128 v64; // xmm2
  __m128 v65; // xmm3
  __m128 v66; // xmm6
  __m128 v67; // xmm2
  __m128 v68; // xmm5
  __m128 v69; // xmm5
  hkcdDynamicTree::CodecRawUint *v70; // rdi
  unsigned __int64 v71; // rdx
  unsigned __int64 v72; // r10
  float v73; // eax
  float v74; // eax
  signed __int64 v75; // rcx
  __m128 v76; // xmm1
  hkcdDynamicTree::CodecRawUint *v77; // rsi
  __int64 v78; // r9
  signed __int64 v79; // r8
  hkArray<hkcdDynamicTree::CodecRawUint,hkContainerHeapAllocator> v80; // xmm3
  __m128 v81; // xmm4
  int v82; // er14
  signed __int64 v83; // rdi
  __m128 v84; // xmm5
  __m128 v85; // xmm6
  signed __int64 v86; // rdx
  int v87; // eax
  signed __int64 v88; // r8
  __int64 v89; // r9
  unsigned int *v90; // r11
  unsigned __int64 v91; // rdx
  __int64 v92; // r8
  hkcdDynamicTree::CodecRawUint *v93; // r8
  signed __int64 v94; // rcx
  __int64 v95; // r9
  unsigned __int64 v96; // rdx
  __m128 v97; // xmm2
  __m128 v98; // xmm1
  signed __int64 v99; // rcx
  hkcdDynamicTree::CodecRawUint *v100; // rax
  hkcdDynamicTree::CodecRawUint *v101; // rax
  __int64 v102; // rsi
  __m128 v103; // xmm7
  __m128 v104; // xmm8
  __int64 v105; // rdx
  __m128 *v106; // r9
  signed __int64 v107; // r11
  __int64 v108; // rax
  __m128 v109; // xmm9
  __m128 v110; // xmm10
  __int64 v111; // r8
  __m128 v112; // xmm0
  __m128 v113; // xmm1
  signed __int64 v114; // rdx
  __m128 *v115; // rdx
  __m128 v116; // xmm3
  __m128 v117; // xmm2
  __m128 v118; // xmm3
  __m128 v119; // xmm2
  __m128 v120; // xmm2
  __m128 v121; // xmm6
  __m128 v122; // xmm5
  __m128 v123; // xmm5
  hkcdDynamicTree::CodecRawUint *v124; // rsi
  unsigned __int64 v125; // rdx
  unsigned __int64 v126; // r10
  float v127; // eax
  signed __int64 v128; // rcx
  __m128 v129; // xmm1
  signed int v130; // ebx
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *v131; // rdi
  hkpTreeBroadPhaseInternals::UpdatePairsQuery *v132; // [rsp+20h] [rbp-C0h]
  __int64 v133; // [rsp+28h] [rbp-B8h]
  hkcdDynamicTree::CodecRawUint *v134; // [rsp+30h] [rbp-B0h]
  __m128 *v135; // [rsp+38h] [rbp-A8h]
  hkAabb newAabb; // [rsp+40h] [rbp-A0h]
  hkpTreeBroadPhaseSpatialTree32 tree; // [rsp+60h] [rbp-80h]
  hkpBroadPhaseHandle *const *v138; // [rsp+158h] [rbp+78h]
  float retaddr; // [rsp+168h] [rbp+88h]
  unsigned __int64 result; // [rsp+170h] [rbp+90h]
  hkpBroadPhaseHandle *const *v141; // [rsp+178h] [rbp+98h]

  v141 = handles;
  v6 = this->m_parameters.m_quad.m128_f32[0];
  newAabb.m_min.m_quad.m128_u64[1] = result;
  retaddr = v6;
  v7.m_quad = (__m128)this->m_offsetAndTimeStep;
  newAabb.m_max.m_quad.m128_u64[0] = (unsigned __int64)handles;
  v8 = 0i64;
  v9 = _mm_shuffle_ps((__m128)LODWORD(v6), (__m128)LODWORD(v6), 0);
  v10 = _mm_shuffle_ps(v7.m_quad, v7.m_quad, 255);
  v11 = aabbs;
  v12 = this;
  newAabb.m_min.m_quad.m128_u64[0] = 0i64;
  v141 = (hkpBroadPhaseHandle *const *)count;
  if ( count > 0 )
  {
    while ( 1 )
    {
      v13 = v11->m_min.m_quad;
      v14 = v11->m_max.m_quad;
      v15 = &v12->m_handles[0].m_data[handles[v8]->m_id];
      v16 = *((_DWORD *)v15 + 2);
      v17 = v16 & 0x1FFFFFF ^ ((*((_DWORD *)v15 + 2) & 0xFE000000) + 0x2000000);
      v18 = (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint> *)&(&v12->vfptr)[6 * (((v16 >> 21) & 0xF) + 1i64)];
      v19 = (signed __int64)&v18->m_nodes.m_data[*((_DWORD *)v15 + 2) & 0x1FFFFF];
      v20 = *(hkArray<hkcdDynamicTree::CodecRawUint,hkContainerHeapAllocator> *)v19;
      v21 = *(__m128 *)(v19 + 16);
      *((_DWORD *)v15 + 2) = v17;
      tree.m_nodes = v20;
      *(__m128 *)&tree.m_firstFree = v21;
      if ( !(v17 & 0xFE000000) || (v17 & 0x1E00000) != 6291456 )
        break;
      if ( _mm_movemask_ps(_mm_or_ps(_mm_cmpltps(v21, v14), _mm_cmpltps(v13, (__m128)v20))) & 7 )
      {
        v22 = v18[1].m_nodes.m_size;
        v23 = v17 & 0x1FFFFF;
        v24 = (unsigned int)v23;
        v25 = (char *)v15->m_bpHandle + SBYTE1(v15->m_bpHandle[1].m_id);
        v26 = _mm_mul_ps(*(__m128 *)&v25[v25[32] + 560], v10);
        v27 = _mm_shuffle_ps(v26, _mm_unpackhi_ps(v26, v9), 196);
        v28 = (hkArray<hkcdDynamicTree::CodecRawUint,hkContainerHeapAllocator>)_mm_min_ps(_mm_add_ps(v13, v27), v13);
        v29 = _mm_max_ps(_mm_add_ps(v14, v27), v14);
        if ( (_DWORD)v23 == (_DWORD)v22 )
        {
          v18[1].m_nodes.m_size = 0;
        }
        else
        {
          v30 = (signed __int64)&v18->m_nodes.m_data[v23];
          v31 = (signed __int64)&v18->m_nodes.m_data[*(unsigned int *)(v30 + 32)];
          v32 = *(_DWORD *)(v31 + 32);
          v33 = (signed __int64)&v18->m_nodes.m_data[*(unsigned int *)(v31
                                                                     + 4
                                                                     * (10i64 - (*(_DWORD *)(v31 + 40) == (_DWORD)v23)))];
          if ( v32 )
          {
            *(_DWORD *)(v33 + 32) = v32;
            v34 = (unsigned int *)(v33 + 32);
            v35 = (unsigned __int128)((v33 - (unsigned __int64)v18->m_nodes.m_data)
                                    * (signed __int128)3074457345618258603i64) >> 64;
            v18->m_nodes.m_data->m_children[(v18->m_nodes.m_data[*(unsigned int *)(v31 + 32)].m_children[1] == *(_DWORD *)(v30 + 32))
                                          + 12i64 * *(unsigned int *)(v31 + 32)] = (v35 >> 63)
                                                                                 + ((signed __int64)v35 >> 3);
            v36 = *(signed int *)(v30 + 32);
            v18->m_nodes.m_data[v36].m_aabb.m_min.m_quad.m128_i32[0] = v18->m_firstFree;
            v37 = v18->m_nodes.m_data;
            v18->m_firstFree = v36;
            v38 = (signed __int64)&v37[*v34];
            while ( 1 )
            {
              v39 = *(unsigned int *)(v38 + 32);
              v40 = ((unsigned __int64)((unsigned __int128)((v38 - (signed __int64)v37)
                                                          * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                  + ((signed __int64)((unsigned __int128)((v38 - (signed __int64)v37)
                                                        * (signed __int128)3074457345618258603i64) >> 64) >> 3);
              v41 = (unsigned __int64)&v37[((unsigned __int64)((unsigned __int128)((v38 - (signed __int64)v37)
                                                                                 * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                                         + (unsigned int)((signed __int64)((unsigned __int128)((v38 - (signed __int64)v37)
                                                                                             * (signed __int128)3074457345618258603i64) >> 64) >> 3)];
              v42 = _mm_min_ps(
                      v37[*(unsigned int *)(v41 + 36)].m_aabb.m_min.m_quad,
                      v37[*(unsigned int *)(v41 + 40)].m_aabb.m_min.m_quad);
              v43 = _mm_max_ps(
                      v37[*(unsigned int *)(v41 + 36)].m_aabb.m_max.m_quad,
                      v37[*(unsigned int *)(v41 + 40)].m_aabb.m_max.m_quad);
              *(__m128 *)v41 = v42;
              *(__m128 *)(v41 + 16) = v43;
              if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v29, v43), _mm_cmpleps(v42, (__m128)v28))) & 7) == 7 )
                break;
              if ( (_DWORD)v39 )
              {
                v37 = v18->m_nodes.m_data;
                v38 = (signed __int64)&v18->m_nodes.m_data[v39];
                if ( v38 )
                  continue;
              }
              goto LABEL_14;
            }
LABEL_15:
            v45 = v18->m_nodes.m_data;
            v46 = v24;
            v45[v46].m_aabb.m_min = (hkVector4f)v28;
            v45[v46].m_aabb.m_max.m_quad = v29;
            v47 = v18->m_nodes.m_data;
            v48 = v18->m_nodes.m_data[v24].m_aabb.m_min.m_quad;
            v49 = v18->m_nodes.m_data[v24].m_aabb.m_max.m_quad;
            if ( (_DWORD)v40 )
            {
              if ( !v18->m_firstFree )
                hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
                  v18,
                  (hkResult *)&retaddr,
                  1);
              v50 = v18->m_firstFree;
              v51 = v18->m_nodes.m_data;
              v52 = (signed __int64)&v18->m_nodes.m_data[v50];
              v18->m_firstFree = v18->m_nodes.m_data[(signed int)v50].m_aabb.m_min.m_quad.m128_u32[0];
              v53 = &v51[(unsigned int)v40].m_aabb.m_min.m_quad;
              v54 = v53[2].m128_u32[1];
              if ( (_DWORD)v54 )
              {
                v55 = _mm_add_ps(v49, v48);
                v56 = _mm_sub_ps(v49, v48);
                do
                {
                  v58 = _mm_min_ps(*v53, v48);
                  v59 = _mm_max_ps(v53[1], v49);
                  v60 = v53[2].m128_u32[2];
                  v132 = (hkpTreeBroadPhaseInternals::UpdatePairsQuery *)&v18->m_nodes.m_data[v54];
                  v57 = (__m128 *)v132;
                  v61 = (__int64)&v18->m_nodes.m_data[v60];
                  v133 = v61;
                  *v53 = v58;
                  v53[1] = v59;
                  v62 = *(__m128 *)(v61 + 16);
                  v63 = _mm_add_ps(*(__m128 *)v61, v62);
                  v64 = _mm_sub_ps(_mm_add_ps(v57[1], *v57), v55);
                  v65 = _mm_add_ps(_mm_sub_ps(v57[1], *v57), v56);
                  v66 = _mm_add_ps(_mm_sub_ps(v62, *(__m128 *)v61), v56);
                  v67 = _mm_mul_ps(v64, v64);
                  v68 = _mm_sub_ps(v63, v55);
                  v69 = _mm_mul_ps(v68, v68);
                  v53 = (__m128 *)*(&v132
                                  + ((float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v67, v67, 85))
                                                           + COERCE_FLOAT(_mm_shuffle_ps(v67, v67, 0)))
                                                   + COERCE_FLOAT(_mm_shuffle_ps(v67, v67, 170)))
                                           * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v65, v65, 85))
                                                           + COERCE_FLOAT(_mm_shuffle_ps(v65, v65, 0)))
                                                   + COERCE_FLOAT(_mm_shuffle_ps(v65, v65, 170)))) > (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v69, v69, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v69, v69, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v69, v69, 170))) * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v66, v66, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v66, v66, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v66, v66, 170))))));
                  v54 = v53[2].m128_u32[1];
                }
                while ( (_DWORD)v54 );
              }
              v71 = (unsigned __int128)((v52 - (unsigned __int64)v18->m_nodes.m_data)
                                      * (signed __int128)3074457345618258603i64) >> 64;
              v72 = (v71 >> 63) + ((signed __int64)v71 >> 3);
              v73 = v53[2].m128_f32[0];
              if ( v73 == 0.0 )
              {
                v18[1].m_nodes.m_size = v72;
              }
              else
              {
                v70 = v18->m_nodes.m_data;
                v70->m_children[(v70[LODWORD(v73)].m_children[1] == ((unsigned __int64)((unsigned __int128)(((char *)v53 - (char *)v70) * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                                                                  + (unsigned int)((signed __int64)((unsigned __int128)(((char *)v53 - (char *)v70) * (signed __int128)3074457345618258603i64) >> 64) >> 3))
                              + 12i64 * LODWORD(v73)] = v72;
              }
              v74 = v53[2].m128_f32[0];
              tree.m_nodes = v28;
              *(float *)(v52 + 32) = v74;
              v75 = (char *)v53 - (char *)v18->m_nodes.m_data;
              *(_DWORD *)(v52 + 40) = v24;
              *(__m128 *)&tree.m_firstFree = v29;
              *(_DWORD *)(v52 + 36) = ((unsigned __int64)((unsigned __int128)(v75
                                                                            * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                                    + ((signed __int64)((unsigned __int128)(v75 * (signed __int128)3074457345618258603i64) >> 64) >> 3);
              v53[2].m128_i32[0] = v72;
              v18->m_nodes.m_data[v24].m_parent = v72;
              v76 = _mm_max_ps(v53[1], v49);
              *(__m128 *)v52 = _mm_min_ps(*v53, v48);
              *(__m128 *)(v52 + 16) = v76;
            }
            else
            {
              v18[1].m_nodes.m_size = v24;
              tree.m_nodes = v28;
              *(__m128 *)&tree.m_firstFree = v29;
              v47[v24].m_parent = 0;
            }
LABEL_46:
            v130 = 1;
            v131 = (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)&v12->m_internals[3];
            newAabb.m_max.m_quad.m128_u64[1] = (unsigned __int64)v138[v8];
            do
            {
              newAabb.m_min.m_quad.m128_u64[0] = (unsigned __int64)(&v12->vfptr)[2 * ((v130 == 4) + 18i64)];
              hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::kineticAabbOverlaps<hkpTreeBroadPhaseSpatialTree32,hkpTreeBroadPhaseInternals::UpdatePairsQuery>(
                v131,
                &tree,
                (hkAabb *)&tree,
                &newAabb,
                v132);
              ++v130;
              v131 += 48;
            }
            while ( v130 <= 3 );
            goto LABEL_48;
          }
          v18->m_nodes.m_data[v22].m_aabb.m_min.m_quad.m128_i32[0] = v18->m_firstFree;
          v44 = v33 - (unsigned __int64)v18->m_nodes.m_data;
          v18->m_firstFree = v22;
          v18[1].m_nodes.m_size = ((unsigned __int64)((unsigned __int128)(v44 * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                                + ((signed __int64)((unsigned __int128)(v44 * (signed __int128)3074457345618258603i64) >> 64) >> 3);
          *(_DWORD *)(v33 + 32) = 0;
        }
LABEL_14:
        LODWORD(v40) = v18[1].m_nodes.m_size;
        goto LABEL_15;
      }
LABEL_48:
      handles = v138;
      ++v8;
      ++v11;
      if ( v8 >= (signed __int64)v141 )
        return;
    }
    v77 = v18->m_nodes.m_data;
    v78 = v18[1].m_nodes.m_size;
    v79 = v17 & 0x1FFFFF;
    v80 = (hkArray<hkcdDynamicTree::CodecRawUint,hkContainerHeapAllocator>)_mm_sub_ps(v13, v9);
    v81 = _mm_add_ps(v14, v9);
    v82 = v79;
    tree.m_nodes = v80;
    *(__m128 *)&tree.m_firstFree = v81;
    v83 = v79;
    v84 = v77[v79].m_aabb.m_min.m_quad;
    v85 = v77[v79].m_aabb.m_max.m_quad;
    if ( (_DWORD)v79 == (_DWORD)v78 )
    {
      v18[1].m_nodes.m_size = 0;
    }
    else
    {
      v86 = (signed __int64)&v77[v77[v79].m_parent];
      v87 = *(_DWORD *)(v86 + 32);
      v88 = (signed __int64)&v77[*(unsigned int *)(v86 + 4 * (10i64 - (*(_DWORD *)(v86 + 40) == (_DWORD)v79)))];
      if ( v87 )
      {
        *(_DWORD *)(v88 + 32) = v87;
        v89 = *(unsigned int *)(v86 + 32);
        v90 = (unsigned int *)(v88 + 32);
        v91 = (signed __int64)((unsigned __int128)((v88 - (unsigned __int64)v18->m_nodes.m_data)
                                                 * (signed __int128)3074457345618258603i64) >> 64) >> 3;
        v18->m_nodes.m_data->m_children[(v18->m_nodes.m_data[v89].m_children[1] == v77[v83].m_parent) + 12 * v89] = (v91 >> 63) + v91;
        v92 = (signed int)v77[v83].m_parent;
        v18->m_nodes.m_data[v92].m_aabb.m_min.m_quad.m128_i32[0] = v18->m_firstFree;
        v18->m_firstFree = v92;
        v93 = v18->m_nodes.m_data;
        v94 = (signed __int64)&v18->m_nodes.m_data[*v90];
        do
        {
          v95 = *(unsigned int *)(v94 + 32);
          v96 = (unsigned __int64)&v93[(unsigned int)((signed __int64)((unsigned __int128)((v94 - (signed __int64)v93)
                                                                                         * (signed __int128)3074457345618258603i64) >> 64) >> 3)
                                     + ((unsigned __int64)((unsigned __int128)((v94 - (signed __int64)v93)
                                                                             * (signed __int128)3074457345618258603i64) >> 64) >> 63)];
          v97 = _mm_min_ps(
                  v93[*(unsigned int *)(v96 + 36)].m_aabb.m_min.m_quad,
                  v93[*(unsigned int *)(v96 + 40)].m_aabb.m_min.m_quad);
          v98 = _mm_max_ps(
                  v93[*(unsigned int *)(v96 + 36)].m_aabb.m_max.m_quad,
                  v93[*(unsigned int *)(v96 + 40)].m_aabb.m_max.m_quad);
          *(__m128 *)v96 = v97;
          *(__m128 *)(v96 + 16) = v98;
          if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v85, v98), _mm_cmpleps(v97, v84))) & 7) == 7 )
            break;
          if ( !(_DWORD)v95 )
            break;
          v93 = v18->m_nodes.m_data;
          v94 = (signed __int64)&v18->m_nodes.m_data[v95];
        }
        while ( v94 );
      }
      else
      {
        v77[v78].m_aabb.m_min.m_quad.m128_i32[0] = v18->m_firstFree;
        v99 = v88 - (unsigned __int64)v18->m_nodes.m_data;
        v18->m_firstFree = v78;
        v18[1].m_nodes.m_size = ((unsigned __int64)((unsigned __int128)(v99 * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                              + ((signed __int64)((unsigned __int128)(v99 * (signed __int128)3074457345618258603i64) >> 64) >> 3);
        *(_DWORD *)(v88 + 32) = 0;
      }
    }
    v100 = v18->m_nodes.m_data;
    v100[v83].m_aabb.m_min = (hkVector4f)v80;
    v100[v83].m_aabb.m_max.m_quad = v81;
    v101 = v18->m_nodes.m_data;
    v102 = (unsigned int)v18[1].m_nodes.m_size;
    v103 = v18->m_nodes.m_data[v83].m_aabb.m_min.m_quad;
    v104 = v18->m_nodes.m_data[v83].m_aabb.m_max.m_quad;
    if ( (_DWORD)v102 )
    {
      if ( !v18->m_firstFree )
        hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
          v18,
          (hkResult *)&result,
          1);
      v105 = v18->m_firstFree;
      v106 = &v18->m_nodes.m_data[v102].m_aabb.m_min.m_quad;
      v107 = (signed __int64)&v18->m_nodes.m_data[v105];
      v18->m_firstFree = v18->m_nodes.m_data[(signed int)v105].m_aabb.m_min.m_quad.m128_u32[0];
      v108 = v106[2].m128_u32[1];
      if ( (_DWORD)v108 )
      {
        v109 = _mm_add_ps(v104, v103);
        v110 = _mm_sub_ps(v104, v103);
        do
        {
          v112 = _mm_min_ps(*v106, v103);
          v113 = _mm_max_ps(v106[1], v104);
          v114 = v106[2].m128_u32[2];
          v134 = &v18->m_nodes.m_data[v108];
          v111 = (__int64)v134;
          v115 = &v18->m_nodes.m_data[v114].m_aabb.m_min.m_quad;
          v135 = v115;
          *v106 = v112;
          v106[1] = v113;
          v116 = *(__m128 *)(v111 + 16);
          v117 = v116;
          v118 = _mm_add_ps(_mm_sub_ps(v116, *(__m128 *)v111), v110);
          v119 = _mm_sub_ps(_mm_add_ps(v117, *(__m128 *)v111), v109);
          v120 = _mm_mul_ps(v119, v119);
          v121 = _mm_add_ps(_mm_sub_ps(v115[1], *v115), v110);
          v122 = _mm_sub_ps(_mm_add_ps(v115[1], *v115), v109);
          v123 = _mm_mul_ps(v122, v122);
          v106 = (__m128 *)*(&v134
                           + ((float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v120, v120, 85))
                                                    + COERCE_FLOAT(_mm_shuffle_ps(v120, v120, 0)))
                                            + COERCE_FLOAT(_mm_shuffle_ps(v120, v120, 170)))
                                    * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v118, v118, 85))
                                                    + COERCE_FLOAT(_mm_shuffle_ps(v118, v118, 0)))
                                            + COERCE_FLOAT(_mm_shuffle_ps(v118, v118, 170)))) > (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v123, v123, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v123, v123, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v123, v123, 170))) * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v121, v121, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v121, v121, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v121, v121, 170))))));
          v108 = v106[2].m128_u32[1];
        }
        while ( (_DWORD)v108 );
      }
      v125 = (unsigned __int128)((v107 - (unsigned __int64)v18->m_nodes.m_data) * (signed __int128)3074457345618258603i64) >> 64;
      v126 = (v125 >> 63) + ((signed __int64)v125 >> 3);
      v127 = v106[2].m128_f32[0];
      if ( v127 == 0.0 )
      {
        v18[1].m_nodes.m_size = v126;
      }
      else
      {
        v124 = v18->m_nodes.m_data;
        v124->m_children[(v124[LODWORD(v127)].m_children[1] == ((unsigned __int64)((unsigned __int128)(((char *)v106 - (char *)v124) * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                                                             + (unsigned int)((signed __int64)((unsigned __int128)(((char *)v106 - (char *)v124) * (signed __int128)3074457345618258603i64) >> 64) >> 3))
                       + 12i64 * LODWORD(v127)] = v126;
      }
      *(float *)(v107 + 32) = v106[2].m128_f32[0];
      v128 = (char *)v106 - (char *)v18->m_nodes.m_data;
      *(_DWORD *)(v107 + 40) = v82;
      *(_DWORD *)(v107 + 36) = ((unsigned __int64)((unsigned __int128)(v128 * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                             + ((signed __int64)((unsigned __int128)(v128 * (signed __int128)3074457345618258603i64) >> 64) >> 3);
      v106[2].m128_i32[0] = v126;
      v18->m_nodes.m_data[v83].m_parent = v126;
      v129 = _mm_max_ps(v106[1], v104);
      *(__m128 *)v107 = _mm_min_ps(*v106, v103);
      *(__m128 *)(v107 + 16) = v129;
    }
    else
    {
      v18[1].m_nodes.m_size = v82;
      v101[v83].m_parent = 0;
    }
    goto LABEL_46;
  }
} = v82;
      v101[v83].m_parent = 0;
    }
    goto LABEL_46;
  }
}

// File Line: 834
// RVA: 0xDAC550
void __fastcall hkpTreeBroadPhase32::updateHandlesMapping(hkpTreeBroadPhase32 *this)
{
  int v1; // edi
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v2; // rsi
  __int64 v3; // rcx
  __int64 v4; // rbx
  hkRelocationInfo::Import *v5; // r10
  int v6; // eax
  __int64 v7; // rcx
  __int64 v8; // rdx
  hkRelocationInfo::Import *v9; // rax
  __int64 v10; // r9
  hkRelocationInfo::Import *v11; // rdx
  signed int *v12; // rax
  signed __int64 v13; // rcx
  const char *v14; // rax
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> v15; // [rsp+20h] [rbp-28h]
  __int64 v16; // [rsp+38h] [rbp-10h]
  int v17; // [rsp+50h] [rbp+8h]

  v1 = 0;
  v2 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)this;
  v3 = this->m_handles[0].m_size;
  LODWORD(v16) = 0;
  v4 = v3;
  if ( (_DWORD)v3 )
  {
    v17 = 16 * v3;
    v5 = (hkRelocationInfo::Import *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                       (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                       &v17);
    LODWORD(v3) = v17 / 16;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = 2147483648;
  v15.m_data = v5;
  if ( (_DWORD)v3 )
    v6 = v3;
  v15.m_size = v4;
  v7 = v4;
  v15.m_capacityAndFlags = v6;
  if ( (signed int)v4 > 0 )
  {
    v8 = v16;
    v9 = v5;
    do
    {
      if ( v9 )
      {
        *(_QWORD *)&v9->m_fromOffset = 0i64;
        v9->m_identifier = (const char *)v8;
      }
      ++v9;
      --v7;
    }
    while ( v7 );
  }
  if ( v2[18].m_size > 0 )
  {
    v10 = 0i64;
    do
    {
      v11 = v2[18].m_data;
      v12 = *(signed int **)&v11[v10].m_fromOffset;
      if ( v12 )
      {
        v13 = *v12;
        *(_QWORD *)&v5[v13].m_fromOffset = v12;
        v14 = v11[v10].m_identifier;
        v5[v13].m_identifier = v14;
        LODWORD(v2[3 * ((((unsigned int)v14 >> 21) & 0xF) + 1i64)].m_data[3 * ((unsigned int)v14 & 0x1FFFFF) + 2].m_identifier) = **(_DWORD **)&v5[v13].m_fromOffset;
      }
      ++v1;
      ++v10;
    }
    while ( v1 < v2[18].m_size );
  }
  for ( ; (signed int)v4 > 1; v15.m_size = v4 )
  {
    if ( *(_QWORD *)&v5[(signed int)v4 - 1].m_fromOffset )
      break;
    LODWORD(v4) = v4 - 1;
  }
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(&v15, v2 + 18);
  if ( v15.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v15.m_data,
      16 * v15.m_capacityAndFlags);
}

// File Line: 853
// RVA: 0xD9F280
void __fastcall hkpTreeBroadPhase::indexAndCompact(hkpTreeBroadPhase *this, int count)
{
  hkpTreeBroadPhase *v2; // r11
  hkpTreeBroadPhase::Handle *v3; // rax
  __int64 v4; // r10
  hkpBroadPhaseHandle *v5; // rcx
  signed __int64 v6; // r8
  unsigned __int64 v7; // rcx

  v2 = this;
  v3 = &this->m_handles[0].m_data[this->m_handles[0].m_size - count];
  if ( count <= 0 )
  {
    this->m_handles[0].m_size -= count;
  }
  else
  {
    v4 = (unsigned int)count;
    do
    {
      v5 = v3->m_bpHandle;
      if ( v3->m_bpHandle )
      {
        v6 = (signed __int64)&v2->m_handles[0].m_data[v5->m_id];
        *(_QWORD *)v6 = v5;
        v7 = *((_QWORD *)v3 + 1);
        *(_QWORD *)(v6 + 8) = v7;
        HIWORD((&v2->vfptr)[6 * (((v7 >> 21) & 0xF) + 1)][2 * *(unsigned __int16 *)(v6 + 8) + 1].__first_virtual_table_function__) = **(_WORD **)v6;
      }
      ++v3;
      --v4;
    }
    while ( v4 );
    v2->m_handles[0].m_size -= count;
  }
}

// File Line: 870
// RVA: 0xDA8590
hkpTreeBroadPhase32 *__fastcall hkpTreeBroadPhase32::getCapabilityDelegate(hkpTreeBroadPhase32 *this, hkpBroadPhase::Capabilities cap)
{
  hkpTreeBroadPhase32 *result; // rax
  hkpBroadPhase *v3; // rcx

  if ( cap & this->m_caps )
    return this;
  v3 = this->m_childBroadPhase;
  if ( v3 )
    result = (hkpTreeBroadPhase32 *)((__int64 (*)(void))v3->vfptr[2].__vecDelDtor)();
  else
    result = 0i64;
  return result;
}

// File Line: 888
// RVA: 0xD9AF30
__int64 __fastcall hkpTreeBroadPhase::getNumObjects(hkpTreeBroadPhase *this)
{
  hkpBroadPhase *v1; // rdx
  __int64 result; // rax

  v1 = this->m_childBroadPhase;
  if ( v1 )
    result = ((__int64 (__fastcall *)(hkpBroadPhase *))v1->vfptr[5].__vecDelDtor)(this->m_childBroadPhase);
  else
    result = (unsigned int)(this->m_internals[1].m_real.m128_i32[2]
                          + this->m_internals[4].m_real.m128_i32[2]
                          + this->m_internals[7].m_real.m128_i32[2]
                          + this->m_internals[10].m_real.m128_i32[2]
                          + this->m_internals[13].m_real.m128_i32[2]);
  return result;
}

// File Line: 903
// RVA: 0xD9AF70
void __fastcall hkpTreeBroadPhase::getAllAabbs(hkpTreeBroadPhase *this, hkArray<hkAabb,hkContainerHeapAllocator> *allAabbs)
{
  hkpTreeBroadPhase *v2; // r14
  hkpBroadPhase *v3; // rcx
  hkArray<hkAabb,hkContainerHeapAllocator> *v4; // rsi
  signed __int64 v5; // r14
  signed __int64 v6; // r15
  unsigned __int16 v7; // bp
  signed __int64 v8; // rdi
  unsigned __int16 v9; // bx
  signed __int64 v10; // rdi
  signed __int64 v11; // rcx
  __int64 v12; // rax
  __int64 v13; // rdx
  int i; // eax
  signed __int64 v15; // rcx
  unsigned __int16 v16; // r8
  signed __int64 v17; // rcx
  __int64 v18; // rax

  v2 = this;
  v3 = this->m_childBroadPhase;
  v4 = allAabbs;
  if ( v3 )
  {
    ((void (*)(void))v3->vfptr[7].__first_virtual_table_function__)();
  }
  else
  {
    allAabbs->m_size = 0;
    v5 = (signed __int64)v2->m_internals;
    v6 = 5i64;
    do
    {
      v7 = *(_WORD *)(v5 + 32);
      if ( v7 )
      {
        v8 = 32i64 * v7;
        v9 = *(_WORD *)(v8 + *(_QWORD *)v5 + 28);
        if ( v9 )
        {
          do
          {
            v10 = 32i64 * v9;
            if ( !*(_WORD *)(v10 + *(_QWORD *)v5 + 28) )
            {
              if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 32);
              v11 = (signed __int64)&v4->m_data[v4->m_size++];
              v12 = *(_QWORD *)v5;
              *(__m128 *)(v11 + 16) = _mm_shuffle_ps(
                                        *(__m128 *)(v10 + *(_QWORD *)v5 + 16),
                                        _mm_unpackhi_ps(*(__m128 *)(v10 + *(_QWORD *)v5 + 16), (__m128)0i64),
                                        196);
              *(_OWORD *)v11 = *(_OWORD *)(v10 + v12);
            }
            v13 = *(_QWORD *)v5;
            if ( *(_WORD *)(*(_QWORD *)v5 + v10 + 28) )
            {
              v9 = *(_WORD *)(*(_QWORD *)v5 + v10 + 28);
            }
            else
            {
              for ( i = *(unsigned __int16 *)(v13 + v10 + 12); i != v7; i = *(unsigned __int16 *)(v15 + v13 + 12) )
              {
                v15 = 32i64 * (unsigned __int16)i;
                if ( *(_WORD *)(v15 + v13 + 30) != v9 )
                  break;
                v9 = i;
              }
              if ( (_WORD)i )
                v16 = *(_WORD *)(32i64 * (unsigned __int16)i + v13 + 30);
              else
                v16 = v9;
              if ( (_WORD)i != v7 || v16 != v9 )
                v9 = v16;
              else
                v9 = 0;
            }
          }
          while ( v9 );
        }
        else
        {
          if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 32);
          v17 = (signed __int64)&v4->m_data[v4->m_size++];
          v18 = *(_QWORD *)v5;
          *(__m128 *)(v17 + 16) = _mm_shuffle_ps(
                                    *(__m128 *)(v8 + *(_QWORD *)v5 + 16),
                                    _mm_unpackhi_ps(*(__m128 *)(v8 + *(_QWORD *)v5 + 16), (__m128)0i64),
                                    196);
          *(_OWORD *)v17 = *(_OWORD *)(v8 + v18);
        }
      }
      v5 += 48i64;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 918
// RVA: 0xDA87D0
void __fastcall hkpTreeBroadPhase32::getExtents(hkpTreeBroadPhase32 *this, hkVector4f *worldMinOut, hkVector4f *worldMaxOut)
{
  hkVector4f *v3; // r10
  hkpTreeBroadPhase32 *v4; // rdx
  hkpBroadPhase *v5; // rcx
  hkVector4f *v6; // r9
  hkSimdFloat32 *v7; // rdx
  signed __int64 v8; // r8
  __m128 v9; // xmm3
  __m128 v10; // xmm5
  __m128 v11; // xmm2
  __int64 v12; // rax
  __m128 *v13; // rcx
  __m128 v14; // xmm1
  __m128 v15; // xmm0

  v3 = worldMinOut;
  v4 = this;
  v5 = this->m_childBroadPhase;
  v6 = worldMaxOut;
  if ( v5 )
  {
    ((void (__fastcall *)(hkpBroadPhase *, hkVector4f *, hkVector4f *, hkVector4f *))v5->vfptr[8].__first_virtual_table_function__)(
      v5,
      v3,
      worldMaxOut,
      worldMaxOut);
  }
  else
  {
    v7 = &v4->m_internals[2];
    v8 = 5i64;
    v9 = (__m128)xmmword_141A712A0;
    v10 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
    v11 = _mm_xor_ps(v10, (__m128)xmmword_141A712A0);
    do
    {
      v12 = v7->m_real.m128_u32[0];
      if ( (_DWORD)v12 )
      {
        v13 = (__m128 *)(v7[-2].m_real.m128_u64[0] + 48 * v12);
        v14 = *v13;
        v15 = v13[1];
      }
      else
      {
        v14 = (__m128)xmmword_141A712A0;
        v15 = _mm_xor_ps(v10, (__m128)xmmword_141A712A0);
      }
      v7 += 3;
      v9 = _mm_min_ps(v9, v14);
      v11 = _mm_max_ps(v11, v15);
      --v8;
    }
    while ( v8 );
    *v3 = (hkVector4f)v9;
    *v6 = (hkVector4f)v11;
  }
}

// File Line: 938
// RVA: 0xDA8870
void __fastcall hkpTreeBroadPhase32::reQuerySingleObject(hkpTreeBroadPhase32 *this, hkpBroadPhaseHandle *object, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *pairs_out)
{
  hkpTreeBroadPhase32 *v3; // rbx
  hkpBroadPhase *v4; // rcx
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *v5; // rsi
  hkpBroadPhaseHandle *v6; // rdi
  hkAabb aabb; // [rsp+20h] [rbp-28h]

  v3 = this;
  v4 = this->m_childBroadPhase;
  v5 = pairs_out;
  v6 = object;
  if ( v4 )
  {
    ((void (*)(void))v4->vfptr[9].__first_virtual_table_function__)();
  }
  else
  {
    ((void (__fastcall *)(hkpTreeBroadPhase32 *, hkpBroadPhaseHandle *, hkAabb *))v3->vfptr[8].__vecDelDtor)(
      v3,
      object,
      &aabb);
    hkpTreeBroadPhase32::querySingleAabb(v3, &aabb, v6, v5);
  }
}

// File Line: 952
// RVA: 0xD9B2B0
void __fastcall hkpTreeBroadPhase::querySingleAabbWithCollector(hkpTreeBroadPhase *this, hkAabb *aabb, hkpBroadPhaseCastCollector *collector)
{
  hkpTreeBroadPhase *v3; // rdi
  hkpBroadPhase *v4; // rcx
  hkpBroadPhaseCastCollector *v5; // rsi
  hkAabb *v6; // rbx
  int v7; // edi
  __int64 v8; // rbx
  char *array; // [rsp+30h] [rbp-18h]
  int v10; // [rsp+38h] [rbp-10h]
  int v11; // [rsp+3Ch] [rbp-Ch]
  hkResult result; // [rsp+50h] [rbp+8h]

  v3 = this;
  v4 = this->m_childBroadPhase;
  v5 = collector;
  v6 = aabb;
  if ( v4 )
  {
    ((void (*)(void))v4->vfptr[10].__vecDelDtor)();
  }
  else
  {
    array = 0i64;
    v10 = 0;
    v11 = 2147483648;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 32, 16);
    hkpTreeBroadPhase::querySingleAabb(
      v3,
      v6,
      0i64,
      (hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *)&array);
    v7 = 0;
    if ( v10 > 0 )
    {
      v8 = 0i64;
      do
      {
        v5->vfptr->addBroadPhaseHandle(v5, *(hkpBroadPhaseHandle **)&array[v8 + 8], 0);
        ++v7;
        v8 += 16i64;
      }
      while ( v7 < v10 );
    }
    v10 = 0;
    if ( v11 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        16 * v11);
  }
}

// File Line: 967
// RVA: 0xDA8A00
void __fastcall hkpTreeBroadPhase32::shiftBroadPhase(hkpTreeBroadPhase32 *this, hkVector4f *shiftDistance, hkVector4f *effectiveShiftDistanceOut, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *newCollisionPairs)
{
  hkVector4f *v4; // rbx
  hkErrStream v5; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v4 = effectiveShiftDistanceOut;
  hkErrStream::hkErrStream(&v5, &buf, 512);
  hkOstream::operator<<((hkOstream *)&v5.vfptr, "shiftBroadPhase is not supported by the tree broadphase");
  hkError::messageWarning(
    -1565513377,
    &buf,
    "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Physics2012/Internal/BroadPhase/TreeBroadPhase/hkpTreeBroadPhase.cpp",
    968);
  hkOstream::~hkOstream((hkOstream *)&v5.vfptr);
  *v4 = 0i64;
}

// File Line: 974
// RVA: 0xD9B430
void __fastcall hkpTreeBroadPhase::getOffsetLowHigh32bit(hkpTreeBroadPhase *this, hkVector4f *offsetLow32bit, hkVector4f *offsetHigh32bit)
{
  hkpBroadPhase *v3; // r10

  v3 = this->m_childBroadPhase;
  if ( v3 )
  {
    v3->vfptr[12].__vecDelDtor((hkBaseObject *)&this->m_childBroadPhase->vfptr, (unsigned int)offsetHigh32bit);
  }
  else
  {
    *offsetLow32bit = this->m_offsetLow;
    *offsetHigh32bit = this->m_offsetHigh;
  }
}

// File Line: 988
// RVA: 0xD9B470
__int64 __fastcall hkpTreeBroadPhase::getAabbCacheSize(hkpTreeBroadPhase *this)
{
  hkpBroadPhase *v1; // rcx
  __int64 result; // rax

  v1 = this->m_childBroadPhase;
  if ( v1 )
    result = ((__int64 (*)(void))v1->vfptr[13].__vecDelDtor)();
  else
    result = 0i64;
  return result;
}

// File Line: 1001
// RVA: 0xD9B490
void __fastcall hkpTreeBroadPhase::calcAabbCache(hkpTreeBroadPhase *this, hkAabb *aabb, char *aabbCacheOut)
{
  hkpBroadPhase *v3; // rcx

  v3 = this->m_childBroadPhase;
  if ( v3 )
    ((void (__fastcall *)(hkpBroadPhase *, hkAabb *, char *))v3->vfptr[14].__vecDelDtor)(v3, aabb, aabbCacheOut);
}

// File Line: 1010
// RVA: 0xD9B4B0
void __fastcall hkpTreeBroadPhase::calcAabbCache(hkpTreeBroadPhase *this, hkArrayBase<hkpCollidable *> *overlappingCollidables, char *aabbCacheOut)
{
  hkpBroadPhase *v3; // rcx

  v3 = this->m_childBroadPhase;
  if ( v3 )
    ((void (__fastcall *)(hkpBroadPhase *, hkArrayBase<hkpCollidable *> *, char *))v3->vfptr[13].__first_virtual_table_function__)(
      v3,
      overlappingCollidables,
      aabbCacheOut);
}

// File Line: 1019
// RVA: 0xD9B4D0
void __fastcall hkpTreeBroadPhase::getAabb(hkpTreeBroadPhase *this, hkpBroadPhaseHandle *object, hkAabb *aabb)
{
  hkpTreeBroadPhase *v3; // r9
  hkpBroadPhase *v4; // rcx
  __int64 v5; // rcx
  unsigned __int64 v6; // rax
  signed __int64 v7; // rcx
  hkVector4f *v8; // rcx

  v3 = this;
  v4 = this->m_childBroadPhase;
  if ( v4 && (object->m_id & 0x80000000) == 0 )
  {
    ((void (__fastcall *)(hkpBroadPhase *, hkpBroadPhaseHandle *, hkAabb *, hkpTreeBroadPhase *))v4->vfptr[8].__vecDelDtor)(
      v4,
      object,
      aabb,
      v3);
  }
  else
  {
    v5 = object->m_id;
    v6 = (unsigned int)v5;
    LODWORD(v5) = v5 & 0x7FFFFFFF;
    v7 = (signed __int64)&(&v3->vfptr)[2 * ((v6 >> 31) + 18)][v5];
    v8 = (hkVector4f *)&(&v3->vfptr)[6 * ((((unsigned __int64)*(unsigned int *)(v7 + 8) >> 21) & 0xF) + 1)][2 * *(unsigned __int16 *)(v7 + 8)];
    aabb->m_max.m_quad = _mm_shuffle_ps(v8[1].m_quad, _mm_unpackhi_ps(v8[1].m_quad, (__m128)0i64), 196);
    aabb->m_min = (hkVector4f)v8->m_quad;
  }
}

// File Line: 1033
// RVA: 0xD9B550
bool __fastcall hkpTreeBroadPhase::areAabbsOverlapping(hkpTreeBroadPhase *this, hkpBroadPhaseHandle *bhA, hkpBroadPhaseHandle *bhB)
{
  hkpTreeBroadPhase *v3; // rdi
  hkpBroadPhase *v4; // rcx
  hkpBroadPhaseHandle *v5; // rbx
  __m128 v7; // [rsp+20h] [rbp-48h]
  __m128 v8; // [rsp+30h] [rbp-38h]
  __m128 v9; // [rsp+40h] [rbp-28h]
  __m128 v10; // [rsp+50h] [rbp-18h]

  v3 = this;
  v4 = this->m_childBroadPhase;
  v5 = bhB;
  if ( v4 && (bhA->m_id & 0x80000000) == 0 && (bhB->m_id & 0x80000000) == 0 )
    return ((__int64 (*)(void))v4->vfptr[10].__first_virtual_table_function__)();
  ((void (__fastcall *)(hkpTreeBroadPhase *, hkpBroadPhaseHandle *, __m128 *))v3->vfptr[8].__vecDelDtor)(v3, bhA, &v7);
  ((void (__fastcall *)(hkpTreeBroadPhase *, hkpBroadPhaseHandle *, __m128 *))v3->vfptr[8].__vecDelDtor)(v3, v5, &v9);
  return (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v9, v8), _mm_cmpleps(v7, v10))) & 7) == 7;
}

// File Line: 1048
// RVA: 0xDA8C30
void __fastcall hkpTreeBroadPhase32::addObject(hkpTreeBroadPhase32 *this, hkpBroadPhaseHandle *object, hkAabbUint32 *aabb, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *newPairs)
{
  hkpTreeBroadPhase32 *v4; // rbx
  hkpBroadPhase *v5; // rcx
  __m128i *v6; // rdi
  char addPairs; // ST20_1
  __m128 v8; // xmm2
  __m128 v9; // xmm3
  hkVector4f v10; // xmm1
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  hkAabb aabbs; // [rsp+30h] [rbp-28h]
  hkpBroadPhaseHandle *handles; // [rsp+68h] [rbp+10h]

  handles = object;
  v4 = this;
  v5 = this->m_childBroadPhase;
  v6 = (__m128i *)aabb;
  if ( v5 )
  {
    addPairs = 0;
    ((void (__fastcall *)(hkpBroadPhase *, hkpBroadPhaseHandle *, hkAabbUint32 *, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *, char))v5->vfptr[3].__vecDelDtor)(
      v5,
      object,
      aabb,
      newPairs,
      addPairs);
    v8 = v4->m_scale.m_quad;
    v9 = v4->m_offsetAndTimeStep.m_quad;
    v10.m_quad = _mm_add_ps(_mm_mul_ps(_mm_cvtepi32_ps(v6[1]), v8), v9);
    aabbs.m_min.m_quad = _mm_add_ps(_mm_mul_ps(_mm_cvtepi32_ps(*v6), v8), v9);
    aabbs.m_max = (hkVector4f)v10.m_quad;
    hkpTreeBroadPhase32::addHandles(v4, &handles, &aabbs, 1);
  }
  else
  {
    v11 = _mm_cvtepi32_ps(*(__m128i *)aabb->m_max);
    v12 = v4->m_scale.m_quad;
    v13 = v4->m_offsetAndTimeStep.m_quad;
    aabbs.m_min.m_quad = _mm_add_ps(_mm_mul_ps(_mm_cvtepi32_ps(*(__m128i *)aabb->m_min), v12), v13);
    aabbs.m_max.m_quad = _mm_add_ps(_mm_mul_ps(v11, v12), v13);
    hkpTreeBroadPhase32::addHandlesStandalone(v4, &handles, &aabbs, 1, newPairs);
  }
}

// File Line: 1070
// RVA: 0xDA8D10
void __fastcall hkpTreeBroadPhase32::addObject(hkpTreeBroadPhase32 *this, hkpBroadPhaseHandle *object, hkAabb *aabb, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *newPairs)
{
  hkpTreeBroadPhase32 *v4; // rbx
  hkpBroadPhase *v5; // rcx
  hkAabb *v6; // rdi
  char addPairs; // ST20_1
  hkpBroadPhaseHandle *handles; // [rsp+48h] [rbp+10h]

  handles = object;
  v4 = this;
  v5 = this->m_childBroadPhase;
  v6 = aabb;
  if ( v5 )
  {
    addPairs = 0;
    ((void (__fastcall *)(hkpBroadPhase *, hkpBroadPhaseHandle *, hkAabb *, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *, char))v5->vfptr[2].__first_virtual_table_function__)(
      v5,
      object,
      aabb,
      newPairs,
      addPairs);
    hkpTreeBroadPhase32::addHandles(v4, &handles, v6, 1);
  }
  else
  {
    hkpTreeBroadPhase32::addHandlesStandalone(v4, &handles, aabb, 1, newPairs);
  }
}

// File Line: 1103
// RVA: 0xD9B750
void __fastcall hkpTreeBroadPhase::addObjectBatch(hkpTreeBroadPhase *this, hkArrayBase<hkpBroadPhaseHandle *> *addObjectList, hkArrayBase<hkAabb> *addAabbList, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *newPairs)
{
  hkpTreeBroadPhase *v4; // rdi
  hkpBroadPhase *v5; // rcx
  hkArrayBase<hkAabb> *v6; // rsi
  hkArrayBase<hkpBroadPhaseHandle *> *v7; // rbx

  v4 = this;
  v5 = this->m_childBroadPhase;
  v6 = addAabbList;
  v7 = addObjectList;
  if ( v5 )
  {
    ((void (__fastcall *)(hkpBroadPhase *, hkArrayBase<hkpBroadPhaseHandle *> *, hkArrayBase<hkAabb> *, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *))v5->vfptr[3].__first_virtual_table_function__)(
      v5,
      addObjectList,
      addAabbList,
      newPairs);
    hkpTreeBroadPhase::addHandles(v4, v7->m_data, v6->m_data, v7->m_size);
  }
  else
  {
    hkpTreeBroadPhase::addHandlesStandalone(
      v4,
      addObjectList->m_data,
      addAabbList->m_data,
      addObjectList->m_size,
      newPairs);
  }
}

// File Line: 1123
// RVA: 0xD9B7D0
void __fastcall hkpTreeBroadPhase::removeObject(hkpTreeBroadPhase *this, hkpBroadPhaseHandle *object, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *pairsOut)
{
  hkpBroadPhaseHandle *v3; // rsi
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *v4; // rdi
  hkpTreeBroadPhase *v5; // rbx
  hkpBroadPhaseHandle *handles; // [rsp+38h] [rbp+10h]

  handles = object;
  v3 = object;
  v4 = pairsOut;
  v5 = this;
  if ( this->m_childBroadPhase )
  {
    hkpTreeBroadPhase::removeHandles(this, &handles, 1);
    ((void (__fastcall *)(hkpBroadPhase *, hkpBroadPhaseHandle *, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *))v5->m_childBroadPhase->vfptr[4].__vecDelDtor)(
      v5->m_childBroadPhase,
      v3,
      v4);
    hkpTreeBroadPhase::indexAndCompact(v5, 1);
  }
  else
  {
    hkpTreeBroadPhase::removeHandlesStandalone(this, &handles, 1, pairsOut);
  }
}

// File Line: 1146
// RVA: 0xD9B860
void __fastcall hkpTreeBroadPhase::removeObjectBatch(hkpTreeBroadPhase *this, hkArrayBase<hkpBroadPhaseHandle *> *removeObjectList, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *delPairsOut)
{
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *v3; // rsi
  hkArrayBase<hkpBroadPhaseHandle *> *v4; // rbx
  hkpTreeBroadPhase *v5; // rdi

  v3 = delPairsOut;
  v4 = removeObjectList;
  v5 = this;
  if ( this->m_childBroadPhase )
  {
    hkpTreeBroadPhase::removeHandles(this, removeObjectList->m_data, removeObjectList->m_size);
    ((void (__fastcall *)(hkpBroadPhase *, hkArrayBase<hkpBroadPhaseHandle *> *, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *))v5->m_childBroadPhase->vfptr[4].__first_virtual_table_function__)(
      v5->m_childBroadPhase,
      v4,
      v3);
    hkpTreeBroadPhase::indexAndCompact(v5, v4->m_size);
  }
  else
  {
    hkpTreeBroadPhase::removeHandlesStandalone(this, removeObjectList->m_data, removeObjectList->m_size, delPairsOut);
  }
}

// File Line: 1169
// RVA: 0xDA8F20
void __fastcall hkpTreeBroadPhase32::updateAabbs(hkpTreeBroadPhase32 *this, hkpBroadPhaseHandle **objects, hkAabb *aabbs, int numObjects, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *addedPairs, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *removedPairs)
{
  hkpTreeBroadPhase32::updateAabbs(this, objects, aabbs, 0i64, numObjects, addedPairs, removedPairs);
}

// File Line: 1175
// RVA: 0xDA8F50
void __fastcall hkpTreeBroadPhase32::updateAabbsUint32(hkpTreeBroadPhase32 *this, hkpBroadPhaseHandle **objects, hkAabbUint32 *aabbs, int numObjects, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *addedPairs, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *removedPairs)
{
  hkpTreeBroadPhase32 *v6; // rsi
  __int64 v7; // rbp
  hkAabbUint32 *v8; // r14
  hkpBroadPhaseHandle **v9; // r15
  hkLifoAllocator *v10; // rax
  hkAabb *v11; // rbx
  int v12; // edi
  char *v13; // rcx
  hkAabb *v14; // rax
  __m128i *v15; // rcx
  __int64 v16; // rdx
  __m128 v17; // xmm0
  __m128i v18; // xmm1
  hkLifoAllocator *v19; // rax
  int v20; // er8

  v6 = this;
  v7 = (unsigned int)numObjects;
  v8 = aabbs;
  v9 = objects;
  v10 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = (hkAabb *)v10->m_cur;
  v12 = (32 * v7 + 127) & 0xFFFFFF80;
  v13 = (char *)v11 + v12;
  if ( v12 > v10->m_slabSize || v13 > v10->m_end )
    v11 = (hkAabb *)hkLifoAllocator::allocateFromNewSlab(v10, v12);
  else
    v10->m_cur = v13;
  if ( (signed int)v7 > 0 )
  {
    v14 = v11;
    v15 = (__m128i *)v8;
    v16 = v7;
    do
    {
      v17 = _mm_cvtepi32_ps(*v15);
      v18 = _mm_load_si128(v15 + 1);
      ++v14;
      v15 += 2;
      v14[-1].m_min.m_quad = _mm_add_ps(_mm_mul_ps(v17, v6->m_scale.m_quad), v6->m_offsetAndTimeStep.m_quad);
      v14[-1].m_max.m_quad = _mm_add_ps(
                               _mm_mul_ps(_mm_cvtepi32_ps(v18), v6->m_scale.m_quad),
                               v6->m_offsetAndTimeStep.m_quad);
      --v16;
    }
    while ( v16 );
  }
  hkpTreeBroadPhase32::updateAabbs(v6, v9, v11, v8, v7, addedPairs, removedPairs);
  v19 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v20 = (v12 + 15) & 0xFFFFFFF0;
  if ( v12 > v19->m_slabSize || (char *)v11 + v20 != v19->m_cur || v19->m_firstNonLifoEnd == v11 )
    hkLifoAllocator::slowBlockFree(v19, v11, v20);
  else
    v19->m_cur = v11;
}

// File Line: 1189
// RVA: 0xDAC780
void __fastcall hkpTreeBroadPhase32::updateAabbs(hkpTreeBroadPhase32 *this, hkpBroadPhaseHandle **objects, hkAabb *aabbs, hkAabbUint32 *aabbsInt, int numObjects, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *addedPairs, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *removedPairs)
{
  hkpTreeBroadPhase32 *v7; // rdi
  hkpBroadPhase *v8; // rcx
  hkAabb *v9; // rsi
  hkpBroadPhaseHandle **v10; // rbx
  hkBaseObjectVtbl *v11; // r10

  v7 = this;
  v8 = this->m_childBroadPhase;
  v9 = aabbs;
  v10 = objects;
  if ( v8 )
  {
    v11 = v8->vfptr;
    if ( aabbsInt )
      ((void (__fastcall *)(hkpBroadPhase *, hkpBroadPhaseHandle **, hkAabbUint32 *, _QWORD, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *))v11[6].__vecDelDtor)(
        v8,
        objects,
        aabbsInt,
        (unsigned int)numObjects,
        addedPairs,
        removedPairs);
    else
      ((void (__fastcall *)(hkpBroadPhase *, hkpBroadPhaseHandle **, hkAabb *, _QWORD, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *))v11[5].__first_virtual_table_function__)(
        v8,
        objects,
        aabbs,
        (unsigned int)numObjects,
        addedPairs,
        removedPairs);
    hkpTreeBroadPhase32::updateHandles(v7, v10, v9, numObjects);
  }
  else
  {
    hkpTreeBroadPhase32::updateHandlesStandalone(v7, objects, aabbs, numObjects, addedPairs, removedPairs);
  }
}

// File Line: 1212
// RVA: 0xDA9090
void __fastcall hkpTreeBroadPhase32::defragment(hkpTreeBroadPhase32 *this)
{
  hkpTreeBroadPhase32 *v1; // rbx
  hkpBroadPhase *v2; // rcx
  int requestedCapacity; // ecx
  int v4; // er9

  v1 = this;
  v2 = this->m_childBroadPhase;
  if ( v2 )
  {
    ((void (*)(void))v2->vfptr[6].__first_virtual_table_function__)();
    hkpTreeBroadPhase32::updateHandlesMapping(v1);
  }
  requestedCapacity = v1->m_handles[0].m_size;
  if ( requestedCapacity < (v1->m_handles[0].m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reduce(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v1->m_handles,
      16,
      0i64,
      requestedCapacity);
  v4 = v1->m_handles[1].m_size;
  if ( v4 < (v1->m_handles[1].m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reduce((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v1->m_handles[1], 16, 0i64, v4);
}

// File Line: 1225
// RVA: 0xD9BAE0
void __fastcall hkpTreeBroadPhase::shiftAllObjects(hkpTreeBroadPhase *this, hkVector4f *shiftDistance, hkVector4f *effectiveShiftDistanceOut, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *newCollisionPairs)
{
  hkpTreeBroadPhase *v4; // rbp
  hkpBroadPhase *v5; // rcx
  hkVector4f *v6; // r13
  int v7; // er15
  __int64 v8; // r12
  hkpTreeBroadPhase::Handle *v9; // rcx
  unsigned __int64 v10; // rax
  __int16 v11; // si
  signed __int64 v12; // r14
  signed __int64 v13; // rbx
  signed __int64 v14; // rax
  signed __int64 v15; // rbx
  __int64 v16; // rdx
  unsigned __int16 v17; // r9
  __m128 *v18; // rdi
  __m128 v19; // xmm6
  __m128 v20; // xmm8
  __m128 v21; // xmm4
  __m128 v22; // xmm5
  signed __int64 v23; // r8
  unsigned __int16 v24; // ax
  signed __int64 v25; // r11
  __int16 v26; // r8
  __int64 v27; // rdx
  signed __int64 v28; // rax
  unsigned __int16 v29; // r8
  __m128 *v30; // rcx
  signed __int64 v31; // rax
  __m128 v32; // xmm3
  __m128 v33; // xmm2
  signed __int64 v34; // rax
  __m128 v35; // xmm0
  __m128 v36; // xmm3
  __int64 v37; // rax
  __int64 v38; // rcx
  unsigned __int16 v39; // di
  __m128 v40; // xmm9
  __m128 v41; // xmm8
  __m128 *v42; // r9
  __m128 *v43; // r10
  unsigned __int16 v44; // cx
  __m128 v45; // xmm10
  __m128 v46; // xmm11
  __m128 *v47; // rcx
  __m128 *v48; // rdx
  __m128 v49; // xmm4
  __m128 v50; // xmm3
  __m128 v51; // xmm4
  __m128 v52; // xmm6
  __m128 v53; // xmm2
  __m128 v54; // xmm5
  __m128 v55; // xmm2
  __m128 v56; // xmm4
  __m128 v57; // xmm6
  __m128 v58; // xmm5
  __m128 v59; // xmm5
  unsigned __int16 v60; // ax
  signed __int64 v61; // r11
  __int64 v62; // rax
  int v63; // ecx
  __m128 v64; // xmm1
  __m128 v65; // xmm2
  hkResult result; // [rsp+20h] [rbp-A8h]
  __m128 *v67; // [rsp+28h] [rbp-A0h]
  __m128 *v68; // [rsp+30h] [rbp-98h]
  hkpTreeBroadPhase *v69; // [rsp+D0h] [rbp+8h]

  v69 = this;
  v4 = this;
  v5 = this->m_childBroadPhase;
  v6 = effectiveShiftDistanceOut;
  if ( v5 )
  {
    ((void (__fastcall *)(hkpBroadPhase *, hkVector4f *, hkVector4f *, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *))v5->vfptr[11].__vecDelDtor)(
      v5,
      shiftDistance,
      effectiveShiftDistanceOut,
      newCollisionPairs);
    v7 = 0;
    if ( v4->m_handles[0].m_size > 0 )
    {
      v8 = 0i64;
      do
      {
        v9 = v4->m_handles[0].m_data;
        v10 = *((unsigned int *)&v9[v8] + 2);
        if ( v10 & 0x1FFFFF )
        {
          v11 = *((_WORD *)&v9[v8] + 4);
          v12 = 32i64 * *((unsigned __int16 *)&v9[v8] + 4);
          v13 = 3 * (((v10 >> 21) & 0xF) + 1);
          v14 = 32i64 * *((unsigned __int16 *)&v9[v8] + 4);
          v15 = (signed __int64)v4 + 16 * v13;
          v16 = *(_QWORD *)v15;
          v17 = *(_WORD *)(v15 + 32);
          v18 = (__m128 *)(v12 + *(_QWORD *)v15);
          v19 = _mm_add_ps(*(__m128 *)(v14 + *(_QWORD *)v15), v6->m_quad);
          v20 = *v18;
          v21 = _mm_add_ps(
                  _mm_shuffle_ps(
                    *(__m128 *)(v14 + *(_QWORD *)v15 + 16),
                    _mm_unpackhi_ps(*(__m128 *)(v14 + *(_QWORD *)v15 + 16), (__m128)0i64),
                    196),
                  v6->m_quad);
          v22 = _mm_shuffle_ps(v18[1], _mm_unpackhi_ps(v18[1], (__m128)0i64), 196);
          if ( v11 == v17 )
          {
            *(_WORD *)(v15 + 32) = 0;
          }
          else
          {
            v23 = v16 + 32i64 * WORD2(v18->m128_u64[1]);
            v24 = *(_WORD *)(v23 + 12);
            v25 = v16 + 32i64 * *(unsigned __int16 *)(v23 + 2 * (15i64 - (*(_WORD *)(v23 + 30) == v11)));
            if ( v24 )
            {
              *(_DWORD *)(v25 + 12) = v24 | 0x3F000000;
              *(_WORD *)(*(_QWORD *)v15
                       + 2
                       * (16i64 * *(unsigned __int16 *)(v23 + 12)
                        + (*(_WORD *)(32i64 * *(unsigned __int16 *)(v23 + 12) + *(_QWORD *)v15 + 30) == WORD2(v18->m128_u64[1])))
                       + 28) = (v25 - *(_QWORD *)v15) >> 5;
              v26 = WORD2(v18->m128_u64[1]);
              *(_WORD *)(32i64 * WORD2(v18->m128_u64[1]) + *(_QWORD *)v15) = *(_WORD *)(v15 + 16);
              v27 = *(_QWORD *)v15;
              *(_WORD *)(v15 + 16) = v26;
              v28 = v27 + 32i64 * *(unsigned __int16 *)(v25 + 12);
              do
              {
                v29 = *(_WORD *)(v28 + 12);
                v30 = (__m128 *)(v27 + 32i64 * (unsigned __int16)((v28 - v27) >> 5));
                v31 = 32i64 * v30[1].m128_u16[6];
                v32 = *(__m128 *)(v31 + v27 + 16);
                v33 = *(__m128 *)(v31 + v27);
                v34 = 32i64 * v30[1].m128_u16[7];
                v35 = _mm_min_ps(v33, *(__m128 *)(v34 + v27));
                v36 = _mm_max_ps(
                        _mm_shuffle_ps(v32, _mm_unpackhi_ps(v32, (__m128)0i64), 196),
                        _mm_shuffle_ps(
                          *(__m128 *)(v34 + v27 + 16),
                          _mm_unpackhi_ps(*(__m128 *)(v34 + v27 + 16), (__m128)0i64),
                          196));
                *v30 = _mm_shuffle_ps(v35, _mm_unpackhi_ps(v35, *v30), 196);
                v30[1] = _mm_shuffle_ps(v36, _mm_unpackhi_ps(v36, v30[1]), 196);
                if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v35, v20), _mm_cmpleps(v22, v36))) & 7) == 7 )
                  break;
                if ( !v29 )
                  break;
                v27 = *(_QWORD *)v15;
                v28 = *(_QWORD *)v15 + 32i64 * v29;
              }
              while ( v28 );
            }
            else
            {
              *(_WORD *)(32i64 * v17 + v16) = *(_WORD *)(v15 + 16);
              *(_WORD *)(v15 + 16) = v17;
              *(_WORD *)(v15 + 32) = (signed __int64)(unsigned int)(v25 - *(_DWORD *)v15) >> 5;
              *(_DWORD *)(v25 + 12) = 1056964608;
            }
          }
          v37 = *(_QWORD *)v15;
          *(__m128 *)(v12 + v37) = _mm_shuffle_ps(v19, _mm_unpackhi_ps(v19, *(__m128 *)(v12 + *(_QWORD *)v15)), 196);
          *(__m128 *)(v12 + v37 + 16) = _mm_shuffle_ps(v21, _mm_unpackhi_ps(v21, *(__m128 *)(v12 + v37 + 16)), 196);
          v38 = *(_QWORD *)v15;
          v39 = *(_WORD *)(v15 + 32);
          v40 = *(__m128 *)(*(_QWORD *)v15 + v12);
          v41 = _mm_shuffle_ps(
                  *(__m128 *)(*(_QWORD *)v15 + v12 + 16),
                  _mm_unpackhi_ps(*(__m128 *)(*(_QWORD *)v15 + v12 + 16), (__m128)0i64),
                  196);
          if ( v39 )
          {
            if ( !*(_WORD *)(v15 + 16) )
              hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::Codec32>::reserveNodes(
                (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::Codec32> *)v15,
                &result,
                1);
            v42 = (__m128 *)(*(_QWORD *)v15 + 32i64 * v39);
            v43 = (__m128 *)(*(_QWORD *)v15 + 32i64 * *(unsigned __int16 *)(v15 + 16));
            *(_WORD *)(v15 + 16) = v43->m128_u64[0];
            v44 = v42[1].m128_u16[6];
            if ( v44 )
            {
              v45 = _mm_add_ps(v40, v41);
              v46 = _mm_sub_ps(v41, v40);
              do
              {
                v47 = (__m128 *)(*(_QWORD *)v15 + 32i64 * v44);
                v48 = (__m128 *)(*(_QWORD *)v15 + 32i64 * v42[1].m128_u16[7]);
                v49 = _mm_min_ps(v40, *v42);
                v50 = _mm_max_ps(v41, _mm_shuffle_ps(v42[1], _mm_unpackhi_ps(v42[1], (__m128)0i64), 196));
                v67 = v47;
                v68 = v48;
                *v42 = _mm_shuffle_ps(v49, _mm_unpackhi_ps(v49, *v42), 196);
                v42[1] = _mm_shuffle_ps(v50, _mm_unpackhi_ps(v50, v42[1]), 196);
                v51 = _mm_shuffle_ps(v47[1], _mm_unpackhi_ps(v47[1], (__m128)0i64), 196);
                v52 = _mm_shuffle_ps(v48[1], _mm_unpackhi_ps(v48[1], (__m128)0i64), 196);
                v53 = _mm_sub_ps(_mm_add_ps(*v47, v51), v45);
                v54 = _mm_add_ps(*v48, v52);
                v55 = _mm_mul_ps(v53, v53);
                v56 = _mm_add_ps(_mm_sub_ps(v51, *v47), v46);
                v57 = _mm_add_ps(_mm_sub_ps(v52, *v48), v46);
                v58 = _mm_sub_ps(v54, v45);
                v59 = _mm_mul_ps(v58, v58);
                v42 = *(&v67
                      + ((float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v56, v56, 85))
                                               + COERCE_FLOAT(_mm_shuffle_ps(v56, v56, 0)))
                                       + COERCE_FLOAT(_mm_shuffle_ps(v56, v56, 170)))
                               * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v55, v55, 85))
                                               + COERCE_FLOAT(_mm_shuffle_ps(v55, v55, 0)))
                                       + COERCE_FLOAT(_mm_shuffle_ps(v55, v55, 170)))) > (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v59, v59, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v59, v59, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v59, v59, 170)))
                                                                                               * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v57, v57, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v57, v57, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v57, v57, 170))))));
                v44 = v42[1].m128_u16[6];
              }
              while ( v44 );
              v4 = v69;
            }
            v60 = WORD2(v42->m128_u64[1]);
            v61 = ((signed __int64)v43 - *(_QWORD *)v15) >> 5;
            if ( v60 )
              *(_WORD *)(*(_QWORD *)v15
                       + 2
                       * (16i64 * v60
                        + (*(_WORD *)(32i64 * v60 + *(_QWORD *)v15 + 30) == (unsigned __int16)(((signed __int64)v42
                                                                                              - *(_QWORD *)v15) >> 5)))
                       + 28) = v61;
            else
              *(_WORD *)(v15 + 32) = v61;
            HIDWORD(v43->m128_u64[1]) = WORD2(v42->m128_u64[1]) | 0x3F000000;
            v62 = (unsigned int)((_DWORD)v42 - *(_DWORD *)v15);
            v43[1].m128_i16[7] = v11;
            v63 = (unsigned __int16)v61 | 0x3F000000;
            v43[1].m128_i16[6] = v62 >> 5;
            HIDWORD(v42->m128_u64[1]) = v63;
            *(_DWORD *)(v12 + *(_QWORD *)v15 + 12) = v63;
            v64 = _mm_min_ps(*v42, v40);
            v65 = _mm_max_ps(_mm_shuffle_ps(v42[1], _mm_unpackhi_ps(v42[1], (__m128)0i64), 196), v41);
            *v43 = _mm_shuffle_ps(v64, _mm_unpackhi_ps(v64, *v43), 196);
            v43[1] = _mm_shuffle_ps(v65, _mm_unpackhi_ps(v65, v43[1]), 196);
          }
          else
          {
            *(_WORD *)(v15 + 32) = v11;
            *(_DWORD *)(v38 + v12 + 12) = 1056964608;
          }
        }
        ++v7;
        ++v8;
      }
      while ( v7 < v4->m_handles[0].m_size );
    }
  }
}

// File Line: 1248
// RVA: 0xD9C0C0
void __fastcall hkpTreeBroadPhase::set32BitOffsetAndScale(hkpTreeBroadPhase *this, hkVector4f *offsetLow, hkVector4f *offsetHigh, hkVector4f *scale)
{
  hkpTreeBroadPhase *v4; // rbx
  hkVector4f *v5; // rsi
  hkVector4f *v6; // rbp
  hkVector4f *v7; // rdi
  __m128 v8; // xmm6
  hkVector4f v9; // xmm7
  hkpBroadPhase *v10; // rcx
  __m128 v11; // xmm7
  __m128 v12; // xmm1
  __m128 v13; // xmm1
  __m128 v14; // xmm2

  v4 = this;
  v5 = scale;
  v6 = offsetHigh;
  v7 = offsetLow;
  v8 = _mm_shuffle_ps(this->m_offsetAndTimeStep.m_quad, this->m_offsetAndTimeStep.m_quad, 255);
  v9.m_quad = (__m128)this->m_scale;
  v10 = this->m_childBroadPhase;
  v11 = _mm_shuffle_ps(v9.m_quad, v9.m_quad, 255);
  if ( v10 )
    ((void (*)(void))v10->vfptr[15].__vecDelDtor)();
  v12 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64), v7->m_quad);
  v4->m_offsetAndTimeStep.m_quad = _mm_shuffle_ps(v12, _mm_unpackhi_ps(v12, v8), 196);
  v13 = _mm_rcp_ps(v5->m_quad);
  v14 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v5->m_quad, v13)), v13);
  v4->m_scale.m_quad = _mm_shuffle_ps(v14, _mm_unpackhi_ps(v14, v11), 196);
  v4->m_offsetLow = (hkVector4f)v7->m_quad;
  v4->m_offsetHigh = (hkVector4f)v6->m_quad;
}

// File Line: 1275
// RVA: 0xDA9780
void __fastcall hkpTreeBroadPhase32::castRay(hkpTreeBroadPhase32 *this, hkpBroadPhase::hkpCastRayInput *input, hkpBroadPhaseCastCollector *collectorBase, int collectorStriding)
{
  int v4; // ebx
  int v5; // esi
  hkpBroadPhaseCastCollector *v6; // r15
  hkpBroadPhase::hkpCastRayInput *v7; // rdi
  hkpTreeBroadPhase32 *v8; // r14
  hkLifoAllocator *v9; // rax
  char *v10; // r8
  int v11; // edx
  char *v12; // rcx
  int v13; // ebx
  hkLifoAllocator *v14; // rax
  char *v15; // rdx
  int v16; // ebx
  char *v17; // rcx
  int v18; // ebx
  hkLifoAllocator *v19; // rax
  char *v20; // rdx
  int v21; // ebx
  char *v22; // rcx
  __int64 v23; // rdx
  int v24; // er9
  __int64 v25; // r8
  int v26; // er10
  __int64 v27; // rcx
  __int128 v28; // xmm0
  char *v29; // rcx
  signed int v30; // ebx
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *v31; // rsi
  hkVector4f *v32; // r9
  char *v33; // rsi
  signed int v34; // ebx
  hkLifoAllocator *v35; // rax
  int v36; // er8
  char *v37; // rsi
  signed int v38; // ebx
  hkLifoAllocator *v39; // rax
  int v40; // er8
  char *v41; // rsi
  signed int v42; // ebx
  hkLifoAllocator *v43; // rax
  int v44; // er8
  __m128 v45; // xmm1
  signed int v46; // ebx
  hkSimdFloat32 *v47; // rsi
  __m128i v48; // xmm5
  __m128 v49; // xmm3
  __m128 v50; // xmm2
  hkpTreeBroadPhaseInternals::RayCastQuery *numRays; // [rsp+20h] [rbp-79h]
  hkpTreeBroadPhaseInternals::RayCastFanQuery *v52; // [rsp+28h] [rbp-71h]
  char v53; // [rsp+30h] [rbp-69h]
  hkcdRay ray; // [rsp+40h] [rbp-59h]
  hkpTreeBroadPhaseSpatialTree32 tree; // [rsp+70h] [rbp-29h]

  v4 = input->m_numCasts;
  v5 = collectorStriding;
  v6 = collectorBase;
  v7 = input;
  v8 = this;
  if ( v4 <= 1 )
  {
    v45 = query.m_quad;
    ray.m_invDirection.m_quad.m128_u64[0] = (unsigned __int64)collectorBase;
    ray.m_invDirection.m_quad.m128_i32[2] = 0;
    v46 = 1;
    v47 = &this->m_internals[3];
    ray.m_direction = (hkVector4f)query.m_quad;
    while ( 1 )
    {
      tree.m_nodes = (hkArray<hkcdDynamicTree::CodecRawUint,hkContainerHeapAllocator>)v7->m_from;
      ray.m_origin.m_quad.m128_u64[0] = (unsigned __int64)(&v8->vfptr)[2 * ((v46 == 4) + 18i64)];
      v48 = (__m128i)_mm_sub_ps(v7->m_toBase->m_quad, (__m128)tree.m_nodes);
      v49 = _mm_cmpeqps((__m128)0i64, (__m128)v48);
      v50 = _mm_rcp_ps((__m128)v48);
      *(__m128 *)&tree.m_firstFree = _mm_shuffle_ps((__m128)v48, _mm_unpackhi_ps((__m128)v48, v45), 196);
      *(__m128 *)&tree.m_root = _mm_or_ps(
                                  _mm_andnot_ps(
                                    v49,
                                    _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v50, (__m128)v48)), v50)),
                                  _mm_and_ps(
                                    _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v48, 0x1Fu), 0x1Fu), (__m128)_xmm),
                                    v49));
      *(&tree.m_sortPath + 1) = _mm_movemask_ps(_mm_cmpleps((__m128)0i64, *(__m128 *)&tree.m_firstFree)) & 7 | 0x3F000000;
      hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::rayCast<hkpTreeBroadPhaseSpatialTree32,hkpTreeBroadPhaseInternals::RayCastQuery>(
        (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)&v53,
        v47,
        &tree,
        &ray,
        numRays);
      ++v46;
      v47 += 3;
      if ( v46 >= 5 )
        break;
      v45 = ray.m_direction.m_quad;
    }
  }
  else
  {
    ray.m_origin.m_quad.m128_u64[0] = 0i64;
    v9 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v10 = (char *)v9->m_cur;
    v11 = (8 * v4 + 127) & 0xFFFFFF80;
    v12 = &v10[v11];
    if ( v11 > v9->m_slabSize || v12 > v9->m_end )
      v10 = (char *)hkLifoAllocator::allocateFromNewSlab(v9, v11);
    else
      v9->m_cur = v12;
    v13 = v7->m_numCasts;
    ray.m_origin.m_quad.m128_u64[1] = (unsigned __int64)v10;
    v14 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v15 = (char *)v14->m_cur;
    v16 = (16 * v13 + 127) & 0xFFFFFF80;
    v17 = &v15[v16];
    if ( v16 > v14->m_slabSize || v17 > v14->m_end )
      v15 = (char *)hkLifoAllocator::allocateFromNewSlab(v14, v16);
    else
      v14->m_cur = v17;
    v18 = v7->m_numCasts;
    ray.m_direction.m_quad.m128_u64[0] = (unsigned __int64)v15;
    v19 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v20 = (char *)v19->m_cur;
    v21 = (16 * v18 + 127) & 0xFFFFFF80;
    v22 = &v20[v21];
    if ( v21 > v19->m_slabSize || v22 > v19->m_end )
      v20 = (char *)hkLifoAllocator::allocateFromNewSlab(v19, v21);
    else
      v19->m_cur = v22;
    ray.m_direction.m_quad.m128_u64[1] = (unsigned __int64)v20;
    v23 = 0i64;
    v24 = 0;
    ray.m_invDirection.m_quad.m128_i32[0] = v5 == 0;
    if ( v7->m_numCasts > 0 )
    {
      v25 = 0i64;
      v26 = 0;
      do
      {
        ++v24;
        v25 += 16i64;
        v27 = v23++ * v7->m_toStriding;
        v28 = *(__int128 *)((char *)v7->m_toBase + v27);
        v29 = (char *)v6 + v26;
        v26 += v5;
        *(_OWORD *)(v25 + ray.m_direction.m_quad.m128_u64[0] - 16) = v28;
        *(_QWORD *)(ray.m_origin.m_quad.m128_u64[1] + 8 * v23 - 8) = v29;
        *(hkVector4f *)(v25 + ray.m_direction.m_quad.m128_u64[1] - 16) = (hkVector4f)query.m_quad;
      }
      while ( v24 < v7->m_numCasts );
    }
    v30 = 1;
    v31 = (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)&v8->m_internals[3];
    do
    {
      v32 = (hkVector4f *)(unsigned int)v7->m_numCasts;
      ray.m_origin.m_quad.m128_u64[0] = (unsigned __int64)(&v8->vfptr)[2 * ((v30 == 4) + 18i64)];
      hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::rayCastFan<hkpTreeBroadPhaseSpatialTree32,hkpTreeBroadPhaseInternals::RayCastFanQuery>(
        v31,
        (hkpTreeBroadPhaseSpatialTree32 *)v7,
        (hkVector4f *)ray.m_direction.m_quad.m128_u64[0],
        v32,
        (unsigned __int64)&ray,
        v52);
      ++v30;
      v31 += 48;
    }
    while ( v30 < 5 );
    v33 = (char *)ray.m_direction.m_quad.m128_u64[1];
    v34 = (16 * v7->m_numCasts + 127) & 0xFFFFFF80;
    v35 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v36 = (v34 + 15) & 0xFFFFFFF0;
    if ( v34 > v35->m_slabSize || &v33[v36] != v35->m_cur || v35->m_firstNonLifoEnd == v33 )
      hkLifoAllocator::slowBlockFree(v35, v33, v36);
    else
      v35->m_cur = v33;
    v37 = (char *)ray.m_direction.m_quad.m128_u64[0];
    v38 = (16 * v7->m_numCasts + 127) & 0xFFFFFF80;
    v39 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v40 = (v38 + 15) & 0xFFFFFFF0;
    if ( v38 > v39->m_slabSize || &v37[v40] != v39->m_cur || v39->m_firstNonLifoEnd == v37 )
      hkLifoAllocator::slowBlockFree(v39, v37, v40);
    else
      v39->m_cur = v37;
    v41 = (char *)ray.m_origin.m_quad.m128_u64[1];
    v42 = (8 * v7->m_numCasts + 127) & 0xFFFFFF80;
    v43 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v44 = (v42 + 15) & 0xFFFFFFF0;
    if ( v42 > v43->m_slabSize || &v41[v44] != v43->m_cur || v43->m_firstNonLifoEnd == v41 )
      hkLifoAllocator::slowBlockFree(v43, v41, v44);
    else
      v43->m_cur = v41;
  }
}

// File Line: 1316
// RVA: 0xD9C5B0
void __fastcall hkpTreeBroadPhase::castAabb(hkpTreeBroadPhase *this, hkpBroadPhase::hkpCastAabbInput *input, hkpBroadPhaseCastCollector *collector)
{
  hkVector4f v3; // xmm2
  hkpTreeBroadPhase *v4; // rsi
  signed int v5; // ebx
  hkAabb *v6; // rbp
  hkSimdFloat32 *v7; // rdi
  hkArray<hkcdDynamicTree::Codec32,hkContainerHeapAllocator> v8; // xmm0
  int v9; // xmm0_4
  hkpTreeBroadPhaseInternals::AabbCastQuery *query; // [rsp+28h] [rbp-70h]
  float v11[4]; // [rsp+30h] [rbp-68h]
  hkpTreeBroadPhaseSpatialTree16 tree; // [rsp+40h] [rbp-58h]
  __m128 v13; // [rsp+70h] [rbp-28h]
  hkpBroadPhaseCastCollector *v14; // [rsp+80h] [rbp-18h]
  int v15; // [rsp+88h] [rbp-10h]

  v3.m_quad = (__m128)input->m_from;
  v4 = this;
  v14 = collector;
  v15 = 0;
  v5 = 1;
  v6 = (hkAabb *)&input->m_to;
  v7 = &this->m_internals[3];
  v8 = (hkArray<hkcdDynamicTree::Codec32,hkContainerHeapAllocator>)_mm_sub_ps(v3.m_quad, input->m_halfExtents.m_quad);
  *(__m128 *)&tree.m_firstFree = _mm_add_ps(v3.m_quad, input->m_halfExtents.m_quad);
  tree.m_nodes = v8;
  v9 = ::query.m_quad.m128_i32[0];
  v13 = ::query.m_quad;
  while ( 1 )
  {
    LODWORD(query) = v9;
    *(_QWORD *)&tree.m_root = (&v4->vfptr)[2 * ((v5 == 4) + 18i64)];
    hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::aabbCast<hkpTreeBroadPhaseSpatialTree16,hkpTreeBroadPhaseInternals::AabbCastQuery>(
      (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)v11,
      v7,
      &tree,
      v6,
      (hkVector4f *)&tree.m_root,
      query,
      v11[0]);
    ++v5;
    v7 += 3;
    if ( v5 >= 5 )
      break;
    v9 = v13.m128_i32[0];
  }
}

// File Line: 1333
// RVA: 0xD9C680
void __fastcall hkpTreeBroadPhase::querySingleAabb(hkpTreeBroadPhase *this, hkAabb *aabb, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *pairs_out)
{
  hkpTreeBroadPhase::querySingleAabb(this, aabb, 0i64, pairs_out);
}

// File Line: 1339
// RVA: 0xD9F3D0
void __fastcall hkpTreeBroadPhase::querySingleAabb(hkpTreeBroadPhase *this, hkAabb *aabb, hkpBroadPhaseHandle *object, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *pairs_out)
{
  hkAabb *v4; // r15
  hkpTreeBroadPhase *v5; // r13
  signed int v6; // esi
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *v7; // r14
  __int128 v8; // xmm0
  __int128 v9; // xmm1
  hkLifoAllocator *v10; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsNoEarlyExitWrapper<hkpTreeBroadPhaseInternals::AabbQuery> *v11; // r9
  hkcdDynamicTree::Codec32 *v12; // rdx
  unsigned __int64 v13; // rcx
  int v14; // eax
  char *v15; // rdi
  signed int v16; // ebx
  hkLifoAllocator *v17; // rax
  int v18; // er8
  hkBaseObjectVtbl *v19; // [rsp+20h] [rbp-39h]
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *v20; // [rsp+28h] [rbp-31h]
  hkpBroadPhaseHandle *v21; // [rsp+30h] [rbp-29h]
  hkpTreeBroadPhaseSpatialTree16 tree; // [rsp+38h] [rbp-21h]
  __int128 v23; // [rsp+70h] [rbp+17h]
  __int128 v24; // [rsp+80h] [rbp+27h]

  v4 = aabb;
  v5 = this;
  v20 = pairs_out;
  v21 = object;
  v6 = 1;
  v7 = (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)&this->m_internals[3];
  do
  {
    v8 = (__int128)v4->m_min;
    v9 = (__int128)v4->m_max;
    tree.m_nodes.m_data = 0i64;
    tree.m_nodes.m_size = 0;
    tree.m_nodes.m_capacityAndFlags = 2147483648;
    v23 = v8;
    v24 = v9;
    tree.m_numLeaves = 64;
    v19 = (&v5->vfptr)[2 * ((v6 == 4) + 18i64)];
    *(_QWORD *)&tree.m_sortPath = &v19;
    v10 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v12 = (hkcdDynamicTree::Codec32 *)v10->m_cur;
    v13 = (unsigned __int64)&v12[4];
    if ( v10->m_slabSize < 128 || (void *)v13 > v10->m_end )
      v12 = (hkcdDynamicTree::Codec32 *)hkLifoAllocator::allocateFromNewSlab(v10, 128);
    else
      v10->m_cur = (void *)v13;
    tree.m_nodes.m_data = v12;
    *(_QWORD *)&tree.m_firstFree = v12;
    tree.m_nodes.m_capacityAndFlags = -2147483584;
    hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkpTreeBroadPhaseSpatialTree16,hkcdTreeQueriesStacks::Dynamic<64,unsigned short>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsNoEarlyExitWrapper<hkpTreeBroadPhaseInternals::AabbQuery>>(
      v7,
      &tree,
      (hkcdTreeQueriesStacks::Dynamic<64,unsigned short> *)&tree.m_sortPath,
      v11);
    v14 = tree.m_nodes.m_size;
    v15 = *(char **)&tree.m_firstFree;
    if ( *(hkcdDynamicTree::Codec32 **)&tree.m_firstFree == tree.m_nodes.m_data )
      v14 = 0;
    tree.m_nodes.m_size = v14;
    v16 = (2 * tree.m_numLeaves + 127) & 0xFFFFFF80;
    v17 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v18 = (v16 + 15) & 0xFFFFFFF0;
    if ( v16 > v17->m_slabSize || &v15[v18] != v17->m_cur || v17->m_firstNonLifoEnd == v15 )
      hkLifoAllocator::slowBlockFree(v17, v15, v18);
    else
      v17->m_cur = v15;
    tree.m_nodes.m_size = 0;
    if ( tree.m_nodes.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        tree.m_nodes.m_data,
        2 * (tree.m_nodes.m_capacityAndFlags & 0x3FFFFFFF));
    ++v6;
    v7 += 48;
  }
  while ( v6 < 5 );
}

// File Line: 1355
// RVA: 0xD9C6A0
void __fastcall hkpTreeBroadPhase::queryConvex(hkpTreeBroadPhase *this, hkVector4f *planes, int numPlanes, hkArray<hkpBroadPhaseHandle const *,hkContainerHeapAllocator> *objects, unsigned int groupsMask)
{
  signed int v5; // edi
  unsigned int v6; // er14
  hkVector4f *v7; // r15
  hkpTreeBroadPhase *v8; // rbp
  signed int v9; // ebx
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *v10; // rsi
  int numPlanesa[2]; // [rsp+20h] [rbp-28h]
  hkArray<hkpBroadPhaseHandle const *,hkContainerHeapAllocator> *v12; // [rsp+28h] [rbp-20h]

  v5 = 1;
  v6 = numPlanes;
  v7 = planes;
  v8 = this;
  v12 = objects;
  v9 = 2;
  v10 = (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)&this->m_internals[3];
  do
  {
    *(_QWORD *)numPlanesa = (&v8->vfptr)[2 * ((v5 == 4) + 18i64)];
    if ( v9 & groupsMask )
      hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::convexOverlaps<hkpTreeBroadPhaseSpatialTree16,hkpTreeBroadPhaseInternals::ConvexQuery>(
        v10,
        (hkpTreeBroadPhaseSpatialTree16 *)v7,
        (hkVector4f *)v6,
        (unsigned __int64)numPlanesa,
        *(hkpTreeBroadPhaseInternals::ConvexQuery **)numPlanesa);
    v9 = __ROL4__(v9, 1);
    ++v5;
    v10 += 48;
  }
  while ( v5 < 5 );
}

// File Line: 1371
// RVA: 0xDA9D30
void __fastcall hkpTreeBroadPhase32::queryConvexSorted(hkpTreeBroadPhase32 *this, hkVector4f *axis, hkVector4f *planes, int numPlanes, hkArray<hkpBroadPhaseHandle const *,hkContainerHeapAllocator> *objects, unsigned int groupsMask)
{
  hkArray<hkpBroadPhaseHandle const *,hkContainerHeapAllocator> *v6; // r14
  __int64 v7; // rax
  unsigned int v8; // er13
  int v9; // er9
  hkpTreeBroadPhase32 *v10; // r15
  int v11; // er9
  unsigned int v12; // er12
  signed int v13; // edi
  hkpTreeBroadPhaseSpatialTree32 *v14; // r14
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *v15; // rsi
  signed int v16; // ebx
  __int64 v17; // rbx
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v18; // r14
  int v19; // er9
  __int64 v20; // r8
  __int64 v21; // r9
  hkpTreeBroadPhaseInternals::ConvexQuerySorted *sizeElem; // [rsp+20h] [rbp-50h]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> a; // [rsp+30h] [rbp-40h]
  int numPlanesa[2]; // [rsp+40h] [rbp-30h]
  hkArray<hkpBroadPhaseHandle const *,hkContainerHeapAllocator> *v25; // [rsp+48h] [rbp-28h]
  hkVector4f *array; // [rsp+50h] [rbp-20h]
  int v27; // [rsp+58h] [rbp-18h]
  int v28; // [rsp+5Ch] [rbp-14h]
  __m128 v29; // [rsp+60h] [rbp-10h]
  hkResult result; // [rsp+B8h] [rbp+48h]
  hkpTreeBroadPhaseSpatialTree32 *tree; // [rsp+C0h] [rbp+50h]

  tree = (hkpTreeBroadPhaseSpatialTree32 *)planes;
  v6 = objects;
  v7 = 0i64;
  v8 = numPlanes;
  v9 = objects->m_capacityAndFlags;
  v10 = this;
  v29 = axis->m_quad;
  *(_QWORD *)numPlanesa = 0i64;
  array = 0i64;
  v11 = (v9 & 0x3FFFFFFF) + 1;
  v27 = 0;
  v28 = 2147483648;
  v25 = objects;
  if ( v11 > 0 )
  {
    if ( v11 < 0 )
      v11 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v11, 16);
    v7 = 0i64;
  }
  v12 = groupsMask;
  v13 = 1;
  v6->m_size = v7;
  v14 = tree;
  v15 = (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)&v10->m_internals[3];
  v16 = 2;
  do
  {
    LOBYTE(v7) = v13 == 4;
    *(_QWORD *)numPlanesa = (&v10->vfptr)[2 * (v7 + 18)];
    if ( v16 & v12 )
      hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::convexOverlaps<hkpTreeBroadPhaseSpatialTree32,hkpTreeBroadPhaseInternals::ConvexQuerySorted>(
        v15,
        v14,
        (hkVector4f *)v8,
        (unsigned __int64)numPlanesa,
        sizeElem);
    v16 = __ROL4__(v16, 1);
    ++v13;
    v15 += 48;
    v7 = 0i64;
  }
  while ( v13 < 5 );
  v17 = v27;
  v18 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)objects;
  if ( v27 > 1 )
    hkAlgorithm::quickSortRecursive<hkVector4f,hkpTreeBroadPhaseInternals::DepthSort>(array, 0, v27 - 1, 0);
  a.m_capacityAndFlags = 2147483648;
  a.m_data = 0i64;
  a.m_size = 0;
  if ( (signed int)v17 > 0 )
  {
    v19 = v17;
    if ( (signed int)v17 < 0 )
      v19 = 0;
    hkArrayUtil::_reserve(
      (hkResult *)&objects,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &a,
      v19,
      8);
  }
  a.m_size = v17;
  v20 = 0i64;
  if ( (signed int)v17 > 0 )
  {
    v21 = 0i64;
    do
    {
      ++v20;
      ++v21;
      *((_QWORD *)a.m_data + v20 - 1) = *((_QWORD *)&v18->m_data->m_fromOffset
                                        + (*((signed int *)&array[v21] - 1) & 0xFFFFFFFFC0FFFFFFui64));
    }
    while ( v20 < v17 );
  }
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(v18, &a);
  a.m_size = 0;
  if ( a.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      a.m_data,
      8 * a.m_capacityAndFlags);
  a.m_data = 0i64;
  a.m_capacityAndFlags = 2147483648;
  v27 = 0;
  if ( v28 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * v28);
}

// File Line: 1404
// RVA: 0xDA8580
signed __int64 __fastcall hkpTreeBroadPhase32::getType(hkpTreeBroadPhase32 *this)
{
  return 3i64;
}

// File Line: 1415
// RVA: 0xD9F580
void __fastcall hkpTreeBroadPhase_createTreeBroadPhase(hkpBroadPhase *childBroadPhase)
{
  hkpBroadPhase *v1; // rbx
  _QWORD **v2; // rax
  hkpTreeBroadPhase *v3; // rax

  v1 = childBroadPhase;
  hkOptionalComponent_hkpTreeBroadPhase.m_isUsed.m_bool = 1;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkpTreeBroadPhase *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 416i64);
  if ( v3 )
    hkpTreeBroadPhase::hkpTreeBroadPhase(v3, v1);
}

// File Line: 1421
// RVA: 0xD9F5D0
void __fastcall hkpTreeBroadPhase_updateTreeBroadPhase(hkpBroadPhase *broadPhase, float physicsDeltaStep)
{
  hkpTreeBroadPhase::update((hkpTreeBroadPhase *)broadPhase, physicsDeltaStep);
}

// File Line: 1427
// RVA: 0xD9F5E0
void (__fastcall *hkpTreeBroadPhase_registerSelf())(hkpBroadPhase *broadPhase, float physicsDeltaStep)
{
  void (__fastcall *result)(hkpBroadPhase *, float); // rax

  hkpBroadPhase::s_createTreeBroadPhaseFunction = (hkpBroadPhase *(__fastcall *)(hkpBroadPhase *))hkpTreeBroadPhase_createTreeBroadPhase;
  result = hkpTreeBroadPhase_updateTreeBroadPhase;
  hkpBroadPhase::s_updateTreeBroadPhaseFunction = hkpTreeBroadPhase_updateTreeBroadPhase;
  return result;
}

// File Line: 1432
// RVA: 0x15D2A10
void dynamic_initializer_for__hkOptionalComponent_hkpTreeBroadPhase__()
{
  hkOptionalComponent::hkOptionalComponent(
    &hkOptionalComponent_hkpTreeBroadPhase,
    "hkpTreeBroadPhase",
    (void (__fastcall *)())hkpTreeBroadPhase_registerSelf);
}

