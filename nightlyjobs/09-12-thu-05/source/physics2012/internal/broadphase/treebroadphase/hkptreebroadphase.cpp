// File Line: 428
// RVA: 0xD99530
void __fastcall hkpTreeBroadPhase::hkpTreeBroadPhase(hkpTreeBroadPhase *this, hkpBroadPhase *broadphase)
{
  hkpTreeBroadPhase::Handle *v4; // rcx
  __int64 v5; // rsi
  char *v6; // rbx
  void **v7; // rdi
  int v8; // r8d
  __int64 v9; // [rsp+28h] [rbp-10h]

  hkpBroadPhase::hkpBroadPhase(this, BROADPHASE_TREE_16BIT, 0x140u, 7u);
  this->vfptr = (hkBaseObjectVtbl *)&hkpTreeBroadPhase::`vftable;
  this->m_handles[0].m_data = 0i64;
  this->m_handles[0].m_size = 0;
  this->m_handles[0].m_capacityAndFlags = 0x80000000;
  this->m_handles[1].m_data = 0i64;
  this->m_handles[1].m_size = 0;
  this->m_handles[1].m_capacityAndFlags = 0x80000000;
  this->m_childBroadPhase = broadphase;
  if ( broadphase )
    hkReferencedObject::addReference(broadphase);
  this->m_parameters.m_quad.m128_i32[0] = 1008981770;
  this->m_parameters.m_quad.m128_i32[1] = 1015580809;
  this->m_parameters.m_quad.m128_i32[2] = 0x40000000;
  this->m_parameters.m_quad.m128_i32[3] = 1056964608;
  LODWORD(v9) = 0;
  this->m_offsetAndTimeStep = 0i64;
  this->m_scale = 0i64;
  this->m_optimized.m_bool = 0;
  if ( this->m_handles[0].m_size == (this->m_handles[0].m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_handles[0].m_data, 16);
  v4 = &this->m_handles[0].m_data[this->m_handles[0].m_size];
  if ( v4 )
  {
    v4->m_bpHandle = 0i64;
    *((_QWORD *)v4 + 1) = v9;
  }
  ++this->m_handles[0].m_size;
  v5 = 5i64;
  v6 = &this->m_internals[0].m_real.m128_i8[12];
  do
  {
    v7 = (void **)(v6 - 12);
    if ( v6 != (char *)12 )
    {
      *v7 = 0i64;
      *(_DWORD *)v6 = 0x80000000;
      *((_WORD *)v6 + 2) = 0;
      v8 = *(_DWORD *)v6;
      *((_DWORD *)v6 - 1) = 0;
      if ( v8 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, *v7, 32 * v8);
      *v7 = 0i64;
      *(_DWORD *)v6 = 0x80000000;
      *((_WORD *)v6 + 2) = 0;
      *((_WORD *)v6 + 10) = 0;
      *(_QWORD *)(v6 + 12) = 0i64;
      *((_DWORD *)v6 + 7) = 0;
    }
    v6 += 48;
    --v5;
  }
  while ( v5 );
}

// File Line: 453
// RVA: 0xDA6E60
void __fastcall hkpTreeBroadPhase32::~hkpTreeBroadPhase32(hkpTreeBroadPhase32 *this)
{
  hkpBroadPhase *m_childBroadPhase; // rcx
  int *v3; // rbx
  __int64 v4; // rdi
  int v5; // eax
  int v6; // edi
  int *v7; // rbx
  int v8; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkpTreeBroadPhase32::`vftable;
  m_childBroadPhase = this->m_childBroadPhase;
  if ( m_childBroadPhase )
    hkReferencedObject::removeReference(m_childBroadPhase);
  v3 = &this->m_internals[0].m_real.m128_i32[3];
  v4 = 5i64;
  do
  {
    v5 = *v3;
    *(v3 - 1) = 0;
    if ( v5 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        *(void **)(v3 - 3),
        48 * (v5 & 0x3FFFFFFF));
    *(_QWORD *)(v3 - 3) = 0i64;
    *v3 = 0x80000000;
    v3 += 12;
    --v4;
  }
  while ( v4 );
  v6 = 1;
  v7 = &this->m_parameters.m_quad.m128_i32[3];
  do
  {
    v8 = *(v7 - 4);
    v7 -= 4;
    *(v7 - 1) = 0;
    if ( v8 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, *(void **)(v7 - 3), 16 * v8);
    --v6;
    *(_QWORD *)(v7 - 3) = 0i64;
    *v7 = 0x80000000;
  }
  while ( v6 >= 0 );
  hkpBroadPhase::~hkpBroadPhase(this);
}

// File Line: 460
// RVA: 0xDA6F50
void __fastcall hkpTreeBroadPhase32::update(hkpTreeBroadPhase32 *this, float timeStep)
{
  this->m_offsetAndTimeStep.m_quad.m128_f32[3] = timeStep * this->m_parameters.m_quad.m128_f32[2];
  hkpTreeBroadPhase32::optimize(
    this,
    this->m_parameters.m_quad.m128_f32[1],
    this->m_parameters.m_quad.m128_i32[3] & 0xC0FFFFFF);
  if ( !this->m_optimized.m_bool )
  {
    hkpTreeBroadPhase32::fullOptimize(this);
    this->m_optimized.m_bool = 1;
  }
}

// File Line: 474
// RVA: 0xD99810
__int64 __fastcall hkpTreeBroadPhase::getMemoryFootPrint(hkpTreeBroadPhase *this)
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
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> *m_internals; // rbx
  __int64 v4; // rbp
  unsigned int m_root; // r9d
  hkpTreeBroadPhase32::Handle *v6; // rdx
  hkcdDynamicTree::CodecRawUint *m_data; // r10
  unsigned int m_parent; // eax
  unsigned int v9; // r8d

  v1 = 0;
  m_internals = (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> *)this->m_internals;
  v4 = 5i64;
  do
  {
    hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::rebuildBranchSAH(
      m_internals,
      m_internals->m_root,
      (hkBool)1,
      32,
      16);
    hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::compactIndices(m_internals);
    m_root = m_internals->m_root;
    while ( m_root )
    {
      if ( !m_internals->m_nodes.m_data[m_root].m_children[0] )
      {
        v6 = &this->m_handles[v1 == 4].m_data[m_internals->m_nodes.m_data[m_root].m_children[1]];
        *((_DWORD *)v6 + 2) &= 0xFFE00000;
        *((_DWORD *)v6 + 2) |= m_root & 0x1FFFFF;
      }
      m_data = m_internals->m_nodes.m_data;
      if ( m_internals->m_nodes.m_data[m_root].m_children[0] )
      {
        m_root = m_internals->m_nodes.m_data[m_root].m_children[0];
      }
      else
      {
        m_parent = m_internals->m_nodes.m_data[m_root].m_parent;
        v9 = m_root;
        if ( m_parent )
        {
          while ( m_data[m_parent].m_children[1] == v9 )
          {
            v9 = m_parent;
            m_parent = m_data[m_parent].m_parent;
            if ( !m_parent )
              goto LABEL_10;
          }
          m_root = m_data[m_parent].m_children[1];
        }
        else
        {
LABEL_10:
          m_root = v9;
        }
        if ( !m_parent && m_root == v9 )
          m_root = 0;
      }
    }
    ++v1;
    m_internals = (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> *)((char *)m_internals + 48);
    --v4;
  }
  while ( v4 );
}

// File Line: 511
// RVA: 0xDA7140
void __fastcall hkpTreeBroadPhase32::compact(hkpTreeBroadPhase32 *this)
{
  int v1; // esi
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> *m_internals; // rbx
  __int64 v4; // rbp
  unsigned int m_root; // r8d
  hkpTreeBroadPhase32::Handle *v6; // rdx
  hkcdDynamicTree::CodecRawUint *m_data; // r10
  unsigned int m_parent; // eax
  unsigned int v9; // r9d

  v1 = 0;
  m_internals = (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> *)this->m_internals;
  v4 = 5i64;
  do
  {
    if ( m_internals->m_numLeaves > 1 )
    {
      hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::compactIndices(m_internals);
      m_root = m_internals->m_root;
      while ( m_root )
      {
        if ( !m_internals->m_nodes.m_data[m_root].m_children[0] )
        {
          v6 = &this->m_handles[v1 == 4].m_data[m_internals->m_nodes.m_data[m_root].m_children[1]];
          *((_DWORD *)v6 + 2) &= 0xFFE00000;
          *((_DWORD *)v6 + 2) |= m_root & 0x1FFFFF;
        }
        m_data = m_internals->m_nodes.m_data;
        if ( m_internals->m_nodes.m_data[m_root].m_children[0] )
        {
          m_root = m_internals->m_nodes.m_data[m_root].m_children[0];
        }
        else
        {
          m_parent = m_internals->m_nodes.m_data[m_root].m_parent;
          v9 = m_root;
          if ( m_parent )
          {
            while ( m_data[m_parent].m_children[1] == v9 )
            {
              v9 = m_parent;
              m_parent = m_data[m_parent].m_parent;
              if ( !m_parent )
                goto LABEL_11;
            }
            m_root = m_data[m_parent].m_children[1];
          }
          else
          {
LABEL_11:
            m_root = v9;
          }
          if ( !m_parent && m_root == v9 )
            m_root = 0;
        }
      }
    }
    ++v1;
    m_internals = (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> *)((char *)m_internals + 48);
    --v4;
  }
  while ( v4 );
}

// File Line: 534
// RVA: 0xDA7280
void __fastcall hkpTreeBroadPhase32::optimize(
        hkpTreeBroadPhase32 *this,
        float updateQuality,
        unsigned int cacheQuality)
{
  int v3; // esi
  __int64 v4; // rbp
  __int64 v6; // r14
  int *v7; // rbx
  __int64 v8; // rdi
  int v9; // edx
  unsigned __int64 *v10; // rbx
  bool v11; // zf
  __int64 v12; // rdi
  unsigned int v13; // edx
  hkpTreeBroadPhaseInternals::MappingUpdater mapping; // [rsp+78h] [rbp+20h] BYREF

  v3 = 1;
  v4 = cacheQuality;
  v6 = 4i64;
  if ( updateQuality > 0.0 )
  {
    v7 = &this->m_internals[4].m_real.m128_i32[2];
    v8 = 4i64;
    do
    {
      if ( *v7 )
      {
        v9 = (int)(float)((float)((float)*v7 * updateQuality) + 0.5);
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
  if ( (int)v4 > 0 )
  {
    v10 = &this->m_internals[5].m_real.m128_u64[1];
    do
    {
      v11 = *((_DWORD *)v10 - 4) == 0;
      mapping.m_handles = this->m_handles[v3 == 4].m_data;
      if ( !v11 )
      {
        v12 = v4;
        do
        {
          v13 = (*(_DWORD *)v10)++;
          hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::sortBranch<hkpTreeBroadPhaseInternals::MappingUpdater>(
            (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> *)v10 - 1,
            v13,
            &mapping,
            0xFFFF);
          --v12;
        }
        while ( v12 );
      }
      ++v3;
      v10 += 6;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 591
// RVA: 0xD99C20
void __fastcall hkpTreeBroadPhase::addUserObjects(
        hkpTreeBroadPhase *this,
        int numObjects,
        hkpBroadPhaseHandle *const *handles,
        hkAabb *aabbs)
{
  hkpTreeBroadPhase *v4; // rax
  hkSimdFloat32 *v5; // rbx
  hkAabb *v6; // r14
  hkArray<hkpTreeBroadPhase::Handle,hkContainerHeapAllocator> *v7; // rsi
  __int64 v8; // r13
  int m_size; // ebp
  __int64 v10; // rax
  __int64 v11; // rdi
  hkpBroadPhaseHandle *v12; // rax
  unsigned __int64 v13; // rcx
  int v14; // r15d
  __int64 v15; // r12
  unsigned __int64 v16; // rcx
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
  __int64 v39; // r11
  int v40; // ecx
  __int64 v41; // rax
  __m128 v42; // xmm1
  __m128 v43; // xmm2
  hkResult result; // [rsp+20h] [rbp-C8h] BYREF
  hkResult v45; // [rsp+24h] [rbp-C4h] BYREF
  __int64 v46; // [rsp+28h] [rbp-C0h]
  __int64 v47[2]; // [rsp+30h] [rbp-B8h]
  unsigned __int16 v49; // [rsp+F8h] [rbp+10h]
  hkpBroadPhaseHandle *const *v50; // [rsp+100h] [rbp+18h]
  hkAabb *v51; // [rsp+108h] [rbp+20h]

  if ( numObjects > 0 )
  {
    v51 = aabbs;
    v50 = handles;
    v4 = this;
    v5 = &this->m_internals[12];
    v6 = aabbs;
    v7 = &this->m_handles[1];
    v8 = 0i64;
    v46 = numObjects;
    do
    {
      m_size = v4->m_handles[1].m_size;
      if ( v7->m_size == (v7->m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v7->m_data, 16);
        handles = v50;
      }
      v10 = (__int64)&v7->m_data[v7->m_size];
      if ( v10 )
      {
        *(_QWORD *)v10 = 0i64;
        *(_DWORD *)(v10 + 8) = 0;
      }
      v11 = (__int64)&v7->m_data[v7->m_size++];
      v12 = handles[v8];
      *(_DWORD *)(v11 + 8) &= 0x1FFFFFu;
      *(_QWORD *)v11 = v12;
      *(_DWORD *)(v11 + 8) |= (m_size << 25) | 0x800000;
      if ( !v5[1].m_real.m128_i16[0] )
        hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::Codec32>::reserveNodes(
          (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::Codec32> *)v5,
          &result,
          1);
      v13 = v5->m_real.m128_u64[0];
      v14 = v5[1].m_real.m128_u16[0];
      v15 = 32i64 * v5[1].m_real.m128_u16[0];
      v5[1].m_real.m128_i16[0] = *(_WORD *)(v15 + v5->m_real.m128_u64[0]);
      *(_WORD *)(v15 + v13 + 28) = 0;
      *(_WORD *)(v15 + v13 + 30) = m_size;
      *(__m128 *)(v15 + v13) = _mm_shuffle_ps(
                                 v6->m_min.m_quad,
                                 _mm_unpackhi_ps(v6->m_min.m_quad, *(__m128 *)(v15 + v13)),
                                 196);
      *(__m128 *)(v15 + v13 + 16) = _mm_shuffle_ps(
                                      v6->m_max.m_quad,
                                      _mm_unpackhi_ps(v6->m_max.m_quad, *(__m128 *)(v15 + v13 + 16)),
                                      196);
      v16 = v5->m_real.m128_u64[0];
      v17 = v5[2].m_real.m128_u16[0];
      v49 = v17;
      v18 = *(__m128 *)(v5->m_real.m128_u64[0] + v15);
      v19 = _mm_shuffle_ps(
              *(__m128 *)(v5->m_real.m128_u64[0] + v15 + 16),
              _mm_unpackhi_ps(*(__m128 *)(v5->m_real.m128_u64[0] + v15 + 16), (__m128)0i64),
              196);
      if ( v17 )
      {
        if ( !v5[1].m_real.m128_i16[0] )
        {
          hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::Codec32>::reserveNodes(
            (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::Codec32> *)v5,
            &v45,
            1);
          v17 = v49;
        }
        v20 = (__m128 *)(v5->m_real.m128_u64[0] + 32i64 * v17);
        v21 = (__m128 *)(v5->m_real.m128_u64[0] + 32i64 * v5[1].m_real.m128_u16[0]);
        v5[1].m_real.m128_i16[0] = v21->m128_i16[0];
        v22 = v20[1].m128_u16[6];
        if ( v22 )
        {
          v23 = _mm_add_ps(v18, v19);
          v24 = _mm_sub_ps(v19, v18);
          do
          {
            v25 = (__m128 *)(v5->m_real.m128_u64[0] + 32i64 * v22);
            v26 = (__m128 *)(v5->m_real.m128_u64[0] + 32i64 * v20[1].m128_u16[7]);
            v27 = _mm_min_ps(v18, *v20);
            v28 = _mm_max_ps(v19, _mm_shuffle_ps(v20[1], _mm_unpackhi_ps(v20[1], (__m128)0i64), 196));
            v47[0] = (__int64)v25;
            v47[1] = (__int64)v26;
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
            v20 = (__m128 *)v47[(float)((float)((float)(_mm_shuffle_ps(v34, v34, 85).m128_f32[0]
                                                      + _mm_shuffle_ps(v34, v34, 0).m128_f32[0])
                                              + _mm_shuffle_ps(v34, v34, 170).m128_f32[0])
                                      * (float)((float)(_mm_shuffle_ps(v33, v33, 85).m128_f32[0]
                                                      + _mm_shuffle_ps(v33, v33, 0).m128_f32[0])
                                              + _mm_shuffle_ps(v33, v33, 170).m128_f32[0])) > (float)((float)((float)(_mm_shuffle_ps(v37, v37, 85).m128_f32[0] + _mm_shuffle_ps(v37, v37, 0).m128_f32[0]) + _mm_shuffle_ps(v37, v37, 170).m128_f32[0]) * (float)((float)(_mm_shuffle_ps(v35, v35, 85).m128_f32[0] + _mm_shuffle_ps(v35, v35, 0).m128_f32[0]) + _mm_shuffle_ps(v35, v35, 170).m128_f32[0]))];
            v22 = v20[1].m128_u16[6];
          }
          while ( v22 );
        }
        v38 = v20->m128_u16[6];
        v39 = (__int64)((__int64)v21 - v5->m_real.m128_u64[0]) >> 5;
        if ( v38 )
          *(_WORD *)(v5->m_real.m128_u64[0]
                   + 2
                   * (16i64 * v38
                    + (*(_WORD *)(32i64 * v38 + v5->m_real.m128_u64[0] + 30) == (unsigned __int16)((__int64)((__int64)v20 - v5->m_real.m128_u64[0]) >> 5)))
                   + 28) = v39;
        else
          v5[2].m_real.m128_i16[0] = v39;
        v6 = v51;
        v40 = (unsigned __int16)v39 | 0x3F000000;
        v21->m128_i32[3] = v20->m128_u16[6] | 0x3F000000;
        v41 = (unsigned int)((_DWORD)v20 - v5->m_real.m128_i32[0]);
        v21[1].m128_i16[7] = v14;
        v21[1].m128_i16[6] = v41 >> 5;
        v20->m128_i32[3] = v40;
        *(_DWORD *)(v15 + v5->m_real.m128_u64[0] + 12) = v40;
        v42 = _mm_min_ps(*v20, v18);
        v43 = _mm_max_ps(_mm_shuffle_ps(v20[1], _mm_unpackhi_ps(v20[1], (__m128)0i64), 196), v19);
        *v21 = _mm_shuffle_ps(v42, _mm_unpackhi_ps(v42, *v21), 196);
        v21[1] = _mm_shuffle_ps(v43, _mm_unpackhi_ps(v43, v21[1]), 196);
      }
      else
      {
        v5[2].m_real.m128_i16[0] = v14;
        *(_DWORD *)(v16 + v15 + 12) = 1056964608;
      }
      ++v5[1].m_real.m128_i32[2];
      *(_DWORD *)(v11 + 8) &= 0xFFE00000;
      handles = v50;
      ++v6;
      ++v8;
      v51 = v6;
      *(_DWORD *)(v11 + 8) |= v14 & 0x1FFFFF;
      **(_DWORD **)v11 = m_size | 0x80000000;
      v4 = this;
    }
    while ( v8 < v46 );
  }
}1 = m_size | 0x80000000;
      v4 = this;
    }
    while ( v8 < v46 );
  }
}

// File Line: 607
// RVA: 0xD9A100
void __fastcall hkpTreeBroadPhase::updateUserObjects(
        hkpTreeBroadPhase *this,
        int numObjects,
        hkpBroadPhaseHandle *const *handles,
        hkAabb *aabbs,
        hkVector4f *velocities)
{
  hkVector4f v5; // xmm12
  hkpTreeBroadPhase *v7; // r13
  hkpBroadPhaseHandle *const *v8; // r9
  hkSimdFloat32 *v9; // rbx
  __int64 v10; // r15
  __m128 m_enum; // xmm13
  __m128 v12; // xmm13
  __m128 v13; // xmm12
  hkVector4f *v14; // r8
  hkVector4f *i; // r12
  hkVector4f v16; // xmm2
  hkVector4f v17; // xmm3
  __int64 m_id; // rdx
  __int64 v19; // rdx
  unsigned int v20; // ecx
  __int64 v21; // rbp
  unsigned __int64 v22; // rdx
  __m128 v23; // xmm1
  unsigned __int16 v24; // r9
  __m128 v25; // xmm1
  __m128 v26; // xmm4
  __m128 v27; // xmm5
  unsigned __int64 v28; // rdi
  unsigned __int64 v29; // r8
  unsigned __int16 v30; // ax
  unsigned __int64 v31; // r11
  unsigned __int16 v32; // r8
  unsigned __int64 v33; // rdx
  __int64 v34; // rdi
  unsigned __int16 v35; // r8
  __int64 v36; // rdi
  __m128 *v37; // rcx
  __int64 v38; // rax
  __m128 v39; // xmm3
  __m128 v40; // xmm2
  __int64 v41; // rax
  __m128 v42; // xmm0
  __m128 v43; // xmm3
  unsigned __int64 v44; // rax
  __int64 v45; // rsi
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
  __int64 v68; // r11
  __int64 v69; // rax
  int v70; // ecx
  __m128 v71; // xmm1
  __m128 v72; // xmm2
  unsigned __int64 v73; // rsi
  unsigned __int16 v74; // r8
  __int64 v75; // rdi
  __m128 v76; // xmm5
  __m128 v77; // xmm4
  unsigned __int64 v78; // rdx
  unsigned __int16 v79; // ax
  unsigned __int64 v80; // r11
  unsigned __int16 v81; // r8
  unsigned __int64 v82; // rdx
  __int64 v83; // rax
  unsigned __int16 v84; // r8
  __m128 *v85; // rcx
  __int64 v86; // rax
  __m128 v87; // xmm3
  __m128 v88; // xmm2
  __int64 v89; // rax
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
  __int64 v112; // r11
  __int64 v113; // rax
  int v114; // ecx
  hkResult v115; // [rsp+20h] [rbp-E8h] BYREF
  __int64 v116; // [rsp+28h] [rbp-E0h]
  __int64 v117[2]; // [rsp+30h] [rbp-D8h]
  __int64 v118[2]; // [rsp+40h] [rbp-C8h]
  hkResult result; // [rsp+118h] [rbp+10h] BYREF
  hkpBroadPhaseHandle *const *v121; // [rsp+120h] [rbp+18h]

  v121 = handles;
  v5.m_quad = (__m128)this->m_offsetAndTimeStep;
  result.m_enum = this->m_parameters.m_quad.m128_i32[0];
  v7 = this;
  v8 = handles;
  v9 = &this->m_internals[12];
  v10 = 0i64;
  m_enum = (__m128)(unsigned int)result.m_enum;
  result.m_enum = this->m_parameters.m_quad.m128_i32[2];
  v116 = numObjects;
  v12 = _mm_shuffle_ps(m_enum, m_enum, 0);
  v13 = _mm_mul_ps(
          _mm_shuffle_ps(v5.m_quad, v5.m_quad, 255),
          _mm_shuffle_ps((__m128)(unsigned int)result.m_enum, (__m128)(unsigned int)result.m_enum, 0));
  if ( numObjects > 0 )
  {
    v14 = velocities;
    for ( i = velocities; ; ++i )
    {
      v16.m_quad = (__m128)aabbs->m_min;
      v17.m_quad = (__m128)aabbs->m_max;
      m_id = v8[v10]->m_id;
      LODWORD(m_id) = m_id & 0x7FFFFFFF;
      v19 = (__int64)&v7->m_handles[1].m_data[m_id];
      v20 = *(_DWORD *)(v19 + 8) & 0x1FFFFFF ^ ((*(_DWORD *)(v19 + 8) & 0xFE000000) + 0x2000000);
      *(_DWORD *)(v19 + 8) = v20;
      v21 = (unsigned __int16)v20;
      if ( (v20 & 0xFE000000) == 0 )
        break;
      v22 = v9->m_real.m128_u64[0];
      if ( (_mm_movemask_ps(
              _mm_or_ps(
                _mm_cmplt_ps(v16.m_quad, *(__m128 *)(32i64 * (unsigned __int16)v20 + v9->m_real.m128_u64[0])),
                _mm_cmplt_ps(
                  _mm_shuffle_ps(
                    *(__m128 *)(32i64 * (unsigned __int16)v20 + v9->m_real.m128_u64[0] + 16),
                    _mm_unpackhi_ps(
                      *(__m128 *)(32i64 * (unsigned __int16)v20 + v9->m_real.m128_u64[0] + 16),
                      (__m128)0i64),
                    196),
                  v17.m_quad))) & 7) != 0 )
      {
        v23 = 0i64;
        if ( v14 )
          v23 = _mm_mul_ps(i->m_quad, v13);
        v24 = v9[2].m_real.m128_u16[0];
        v25 = _mm_shuffle_ps(v23, _mm_unpackhi_ps(v23, v12), 196);
        v26 = _mm_min_ps(_mm_add_ps(v16.m_quad, v25), v16.m_quad);
        v27 = _mm_max_ps(_mm_add_ps(v17.m_quad, v25), v17.m_quad);
        if ( (_WORD)v20 == v24 )
        {
          v9[2].m_real.m128_i16[0] = 0;
        }
        else
        {
          v28 = v22 + 32i64 * (unsigned __int16)v20;
          v29 = v22 + 32i64 * *(unsigned __int16 *)(v28 + 12);
          v30 = *(_WORD *)(v29 + 12);
          v31 = v22 + 32i64 * *(unsigned __int16 *)(v29 + 2 * (15i64 - (*(_WORD *)(v29 + 30) == (unsigned __int16)v20)));
          if ( v30 )
          {
            *(_DWORD *)(v31 + 12) = v30 | 0x3F000000;
            *(_WORD *)(v9->m_real.m128_u64[0]
                     + 2
                     * (16i64 * *(unsigned __int16 *)(v29 + 12)
                      + (*(_WORD *)(32i64 * *(unsigned __int16 *)(v29 + 12) + v9->m_real.m128_u64[0] + 30) == *(_WORD *)(v28 + 12)))
                     + 28) = (__int64)(v31 - v9->m_real.m128_u64[0]) >> 5;
            v32 = *(_WORD *)(v28 + 12);
            *(_WORD *)(32i64 * v32 + v9->m_real.m128_u64[0]) = v9[1].m_real.m128_i16[0];
            v33 = v9->m_real.m128_u64[0];
            v9[1].m_real.m128_i16[0] = v32;
            v34 = v33 + 32i64 * *(unsigned __int16 *)(v31 + 12);
            while ( 1 )
            {
              v35 = *(_WORD *)(v34 + 12);
              v36 = (__int64)(v34 - v33) >> 5;
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
              if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v27, v43), _mm_cmple_ps(v42, v26))) & 7) == 7 )
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
              v9[1].m_real.m128_i16[0] = v50->m128_i16[0];
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
                  v117[0] = (__int64)v54;
                  v117[1] = (__int64)v55;
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
                  v49 = (__m128 *)v117[(float)((float)((float)(_mm_shuffle_ps(v62, v62, 85).m128_f32[0]
                                                             + _mm_shuffle_ps(v62, v62, 0).m128_f32[0])
                                                     + _mm_shuffle_ps(v62, v62, 170).m128_f32[0])
                                             * (float)((float)(_mm_shuffle_ps(v63, v63, 85).m128_f32[0]
                                                             + _mm_shuffle_ps(v63, v63, 0).m128_f32[0])
                                                     + _mm_shuffle_ps(v63, v63, 170).m128_f32[0])) > (float)((float)((float)(_mm_shuffle_ps(v66, v66, 85).m128_f32[0] + _mm_shuffle_ps(v66, v66, 0).m128_f32[0]) + _mm_shuffle_ps(v66, v66, 170).m128_f32[0]) * (float)((float)(_mm_shuffle_ps(v64, v64, 85).m128_f32[0] + _mm_shuffle_ps(v64, v64, 0).m128_f32[0]) + _mm_shuffle_ps(v64, v64, 170).m128_f32[0]))];
                  v51 = v49[1].m128_u16[6];
                }
                while ( v51 );
                v7 = this;
              }
              v67 = v49->m128_u16[6];
              v68 = (__int64)((__int64)v50 - v9->m_real.m128_u64[0]) >> 5;
              if ( v67 )
                *(_WORD *)(v9->m_real.m128_u64[0]
                         + 2
                         * (16i64 * v67
                          + (*(_WORD *)(32i64 * v67 + v9->m_real.m128_u64[0] + 30) == (unsigned __int16)((__int64)((__int64)v49 - v9->m_real.m128_u64[0]) >> 5)))
                         + 28) = v68;
              else
                v9[2].m_real.m128_i16[0] = v68;
              v50->m128_i32[3] = v49->m128_u16[6] | 0x3F000000;
              v69 = (unsigned int)((_DWORD)v49 - v9->m_real.m128_i32[0]);
              v50[1].m128_i16[7] = v21;
              v70 = (unsigned __int16)v68 | 0x3F000000;
              v50[1].m128_i16[6] = v69 >> 5;
              v49->m128_i32[3] = v70;
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
          v9[2].m_real.m128_i16[0] = (__int64)(unsigned int)(v31 - v9->m_real.m128_i32[0]) >> 5;
          *(_DWORD *)(v31 + 12) = 1056964608;
        }
LABEL_16:
        LOWORD(v36) = v9[2].m_real.m128_i16[0];
        goto LABEL_17;
      }
LABEL_52:
      v8 = v121;
      ++v10;
      ++aabbs;
      if ( v10 >= v116 )
        return;
    }
    v73 = v9->m_real.m128_u64[0];
    v74 = v9[2].m_real.m128_u16[0];
    v75 = 32i64 * (unsigned __int16)v20;
    v76 = *(__m128 *)(v9->m_real.m128_u64[0] + v75);
    v77 = _mm_shuffle_ps(
            *(__m128 *)(v9->m_real.m128_u64[0] + v75 + 16),
            _mm_unpackhi_ps(*(__m128 *)(v9->m_real.m128_u64[0] + v75 + 16), (__m128)0i64),
            196);
    if ( (_WORD)v20 == v74 )
    {
      v9[2].m_real.m128_i16[0] = 0;
    }
    else
    {
      v78 = v73 + 32i64 * *(unsigned __int16 *)(v73 + v75 + 12);
      v79 = *(_WORD *)(v78 + 12);
      v80 = v73 + 32i64 * *(unsigned __int16 *)(v78 + 2 * (15i64 - (*(_WORD *)(v78 + 30) == (unsigned __int16)v20)));
      if ( v79 )
      {
        *(_DWORD *)(v80 + 12) = v79 | 0x3F000000;
        *(_WORD *)(v9->m_real.m128_u64[0]
                 + 2
                 * (16i64 * *(unsigned __int16 *)(v78 + 12)
                  + (*(_WORD *)(32i64 * *(unsigned __int16 *)(v78 + 12) + v9->m_real.m128_u64[0] + 30) == *(_WORD *)(v73 + v75 + 12)))
                 + 28) = (__int64)(v80 - v9->m_real.m128_u64[0]) >> 5;
        v81 = *(_WORD *)(v73 + v75 + 12);
        *(_WORD *)(32i64 * v81 + v9->m_real.m128_u64[0]) = v9[1].m_real.m128_i16[0];
        v82 = v9->m_real.m128_u64[0];
        v9[1].m_real.m128_i16[0] = v81;
        v83 = v82 + 32i64 * *(unsigned __int16 *)(v80 + 12);
        do
        {
          v84 = *(_WORD *)(v83 + 12);
          v85 = (__m128 *)(v82 + 32i64 * (unsigned __int16)((__int64)(v83 - v82) >> 5));
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
          if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v77, v91), _mm_cmple_ps(v90, v76))) & 7) == 7 )
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
        v9[2].m_real.m128_i16[0] = (__int64)(unsigned int)(v80 - v9->m_real.m128_i32[0]) >> 5;
        *(_DWORD *)(v80 + 12) = 1056964608;
      }
    }
    v92 = v9->m_real.m128_u64[0];
    *(__m128 *)(v75 + v92) = _mm_shuffle_ps(
                               aabbs->m_min.m_quad,
                               _mm_unpackhi_ps(aabbs->m_min.m_quad, *(__m128 *)(v75 + v9->m_real.m128_u64[0])),
                               196);
    *(__m128 *)(v75 + v92 + 16) = _mm_shuffle_ps(
                                    aabbs->m_max.m_quad,
                                    _mm_unpackhi_ps(aabbs->m_max.m_quad, *(__m128 *)(v75 + v92 + 16)),
                                    196);
    v93 = v9->m_real.m128_u64[0];
    v94 = v9[2].m_real.m128_u16[0];
    v47 = *(__m128 *)(v9->m_real.m128_u64[0] + 32 * v21);
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
      v9[1].m_real.m128_i16[0] = v50->m128_i16[0];
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
          v118[0] = (__int64)v98;
          v118[1] = (__int64)v99;
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
          v49 = (__m128 *)v118[(float)((float)((float)(_mm_shuffle_ps(v107, v107, 85).m128_f32[0]
                                                     + _mm_shuffle_ps(v107, v107, 0).m128_f32[0])
                                             + _mm_shuffle_ps(v107, v107, 170).m128_f32[0])
                                     * (float)((float)(_mm_shuffle_ps(v106, v106, 0).m128_f32[0]
                                                     + _mm_shuffle_ps(v106, v106, 85).m128_f32[0])
                                             + _mm_shuffle_ps(v106, v106, 170).m128_f32[0])) > (float)((float)((float)(_mm_shuffle_ps(v108, v108, 85).m128_f32[0] + _mm_shuffle_ps(v108, v108, 0).m128_f32[0]) + _mm_shuffle_ps(v108, v108, 170).m128_f32[0]) * (float)((float)(_mm_shuffle_ps(v110, v110, 85).m128_f32[0] + _mm_shuffle_ps(v110, v110, 0).m128_f32[0]) + _mm_shuffle_ps(v110, v110, 170).m128_f32[0]))];
          v95 = v49[1].m128_u16[6];
        }
        while ( v95 );
        v7 = this;
      }
      v111 = v49->m128_u16[6];
      v112 = (__int64)((__int64)v50 - v9->m_real.m128_u64[0]) >> 5;
      if ( v111 )
        *(_WORD *)(v9->m_real.m128_u64[0]
                 + 2
                 * (16i64 * v111
                  + (*(_WORD *)(32i64 * v111 + v9->m_real.m128_u64[0] + 30) == (unsigned __int16)((__int64)((__int64)v49 - v9->m_real.m128_u64[0]) >> 5)))
                 + 28) = v112;
      else
        v9[2].m_real.m128_i16[0] = v112;
      v50->m128_i32[3] = v49->m128_u16[6] | 0x3F000000;
      v113 = (unsigned int)((_DWORD)v49 - v9->m_real.m128_i32[0]);
      v50[1].m128_i16[7] = v21;
      v114 = (unsigned __int16)v112 | 0x3F000000;
      v50[1].m128_i16[6] = v113 >> 5;
      v49->m128_i32[3] = v114;
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
void __fastcall hkpTreeBroadPhase32::removeUserObjects(
        hkpTreeBroadPhase32 *this,
        int numObjects,
        hkpBroadPhaseHandle *const *handles)
{
  __int64 v3; // r9
  hkpBroadPhaseHandle *const *v4; // rax
  __int64 v6; // r14
  int v7; // edi
  bool v8; // r13
  __int64 v9; // r15
  hkpTreeBroadPhase32::Handle *v10; // r12
  unsigned __int64 v11; // rdx
  __int64 v12; // r10
  __int64 v13; // rsi
  __m128 *v14; // rbp
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  unsigned __int64 v17; // r9
  int v18; // eax
  unsigned __int64 v19; // r8
  unsigned int *v20; // r11
  __int64 v21; // r8
  unsigned __int64 v22; // r8
  unsigned __int64 v23; // rcx
  __int64 v24; // r9
  __m128 *v25; // rdx
  __m128 v26; // xmm2
  __m128 v27; // xmm1
  __int64 v28; // rcx
  __int64 v29; // r8
  __int64 v30; // rdx
  hkpTreeBroadPhase32::Handle *v31; // rcx
  __int64 v32; // rdx
  __int64 v33; // rax
  signed __int64 v34; // rcx
  __int64 v35; // [rsp+40h] [rbp+8h]

  if ( numObjects > 0 )
  {
    v3 = numObjects;
    v4 = handles;
    v6 = 0i64;
    v35 = numObjects;
    do
    {
      v7 = v4[v6]->m_id & 0x7FFFFFFF;
      v8 = v7 < this->m_handles[1].m_size - 1;
      v9 = v7;
      v10 = &this->m_handles[1].m_data[v9];
      v10->m_bpHandle->m_id = 0;
      v11 = this->m_internals[12].m_real.m128_u64[0];
      v12 = this->m_internals[14].m_real.m128_i32[0];
      v13 = *((_DWORD *)v10 + 2) & 0x1FFFFF;
      v14 = (__m128 *)(v11 + 48 * v13);
      v15 = *v14;
      v16 = v14[1];
      if ( (_DWORD)v13 == (_DWORD)v12 )
      {
        this->m_internals[14].m_real.m128_i32[0] = 0;
      }
      else
      {
        v17 = v11 + 48i64 * v14[2].m128_u32[0];
        v18 = *(_DWORD *)(v17 + 32);
        v19 = v11 + 48i64 * *(unsigned int *)(v17 + 4 * (10i64 - (*(_DWORD *)(v17 + 40) == (_DWORD)v13)));
        if ( v18 )
        {
          *(_DWORD *)(v19 + 32) = v18;
          v20 = (unsigned int *)(v19 + 32);
          *(_DWORD *)(this->m_internals[12].m_real.m128_u64[0]
                    + 4
                    * ((*(_DWORD *)(this->m_internals[12].m_real.m128_u64[0] + 48i64 * *(unsigned int *)(v17 + 32) + 40) == v14[2].m128_i32[0])
                     + 12i64 * *(unsigned int *)(v17 + 32))
                    + 36) = (int)(v19 - this->m_internals[12].m_real.m128_u64[0]) / 48;
          v21 = v14[2].m128_i32[0];
          *(_DWORD *)(this->m_internals[12].m_real.m128_u64[0] + 48 * v21) = this->m_internals[13].m_real.m128_i32[0];
          this->m_internals[13].m_real.m128_i32[0] = v21;
          v22 = this->m_internals[12].m_real.m128_u64[0];
          v23 = v22 + 48i64 * *v20;
          do
          {
            v24 = *(unsigned int *)(v23 + 32);
            v25 = (__m128 *)(v22 + 48i64 * (unsigned int)(((int)v23 - (int)v22) / 48));
            v26 = _mm_min_ps(
                    *(__m128 *)(v22 + 48i64 * v25[2].m128_u32[1]),
                    *(__m128 *)(v22 + 48i64 * v25[2].m128_u32[2]));
            v27 = _mm_max_ps(
                    *(__m128 *)(v22 + 48i64 * v25[2].m128_u32[1] + 16),
                    *(__m128 *)(v22 + 48i64 * v25[2].m128_u32[2] + 16));
            *v25 = v26;
            v25[1] = v27;
            if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v16, v27), _mm_cmple_ps(v26, v15))) & 7) == 7 )
              break;
            if ( !(_DWORD)v24 )
              break;
            v22 = this->m_internals[12].m_real.m128_u64[0];
            v23 = v22 + 48 * v24;
          }
          while ( v23 );
        }
        else
        {
          *(_DWORD *)(v11 + 48 * v12) = this->m_internals[13].m_real.m128_i32[0];
          v34 = v19 - this->m_internals[12].m_real.m128_u64[0];
          this->m_internals[13].m_real.m128_i32[0] = v12;
          this->m_internals[14].m_real.m128_i32[0] = v34 / 48;
          *(_DWORD *)(v19 + 32) = 0;
        }
        v3 = v35;
      }
      *(_DWORD *)(this->m_internals[12].m_real.m128_u64[0] + 48i64 * (int)v13) = this->m_internals[13].m_real.m128_i32[0];
      --this->m_internals[13].m_real.m128_i32[2];
      this->m_internals[13].m_real.m128_i32[0] = v13;
      v28 = --this->m_handles[1].m_size;
      if ( (_DWORD)v28 != v7 )
      {
        v29 = 2i64;
        v30 = 16 * v28;
        v31 = &this->m_handles[1].m_data[v9];
        v32 = v30 - v9 * 16;
        do
        {
          v33 = *(__int64 *)((char *)&v31->m_bpHandle + v32);
          v31 = (hkpTreeBroadPhase32::Handle *)((char *)v31 + 8);
          *((_QWORD *)&v31[-1] + 1) = v33;
          --v29;
        }
        while ( v29 );
      }
      if ( v8 )
      {
        *(_DWORD *)(this->m_internals[12].m_real.m128_u64[0] + 48i64 * (*((_DWORD *)v10 + 2) & 0x1FFFFF) + 40) = v7;
        v10->m_bpHandle->m_id = v7 | 0x80000000;
      }
      v4 = handles;
      ++v6;
    }
    while ( v6 < v3 );
  }
}

// File Line: 662
// RVA: 0xD9C950
void __fastcall hkpTreeBroadPhase::addHandles(
        hkpTreeBroadPhase *this,
        hkpBroadPhaseHandle *const *handles,
        hkAabb *aabbs,
        int count)
{
  hkpBroadPhaseHandle *const *v5; // r10
  hkArray<hkpTreeBroadPhase::Handle,hkContainerHeapAllocator> *m_handles; // rsi
  hkpTreeBroadPhase *v7; // r8
  __int64 v8; // r12
  hkpBroadPhaseHandle *v9; // rdx
  char v10; // bl
  __int64 v11; // rax
  __int64 v12; // rdi
  hkpBroadPhaseHandle *v13; // rdx
  int v14; // ecx
  unsigned int v15; // eax
  __int16 m_id; // bp
  hkSimdFloat32 *v17; // rbx
  unsigned __int64 v18; // rcx
  int v19; // r14d
  __int64 v20; // r15
  unsigned __int64 v21; // rcx
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
  __int64 v44; // r11
  int v45; // ecx
  __int64 v46; // rax
  __m128 v47; // xmm1
  __m128 v48; // xmm2
  hkResult v49; // [rsp+20h] [rbp-B8h] BYREF
  __int64 v50; // [rsp+28h] [rbp-B0h]
  __int64 v51[2]; // [rsp+30h] [rbp-A8h]
  hkResult result; // [rsp+F8h] [rbp+20h] BYREF

  if ( count > 0 )
  {
    v5 = handles;
    m_handles = this->m_handles;
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
      else if ( (unsigned int)(SLOBYTE(v9[1].m_id) - 2) < 2 )
      {
        v10 = 1;
      }
      else
      {
        v10 = 2;
      }
      if ( m_handles->m_size == (m_handles->m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_handles->m_data, 16);
        v7 = this;
        v5 = handles;
      }
      v11 = (__int64)&m_handles->m_data[m_handles->m_size];
      if ( v11 )
      {
        *(_QWORD *)v11 = 0i64;
        *(_DWORD *)(v11 + 8) = 0;
      }
      v12 = (__int64)&m_handles->m_data[m_handles->m_size++];
      v13 = v5[v8];
      *(_DWORD *)(v12 + 8) &= 0xFE1FFFFF;
      *(_DWORD *)(v12 + 8) |= (v10 & 0xF) << 21;
      v14 = *(_DWORD *)(v12 + 8);
      *(_QWORD *)v12 = v13;
      v15 = v14 & 0x1FFFFFF | (v13->m_id << 25);
      *(_DWORD *)(v12 + 8) = v15;
      m_id = v13->m_id;
      v17 = &v7->m_internals[3 * ((v15 >> 21) & 0xF)];
      if ( !v17[1].m_real.m128_i16[0] )
        hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::Codec32>::reserveNodes(
          (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::Codec32> *)v17,
          &result,
          1);
      v18 = v17->m_real.m128_u64[0];
      v19 = v17[1].m_real.m128_u16[0];
      v20 = 32i64 * v17[1].m_real.m128_u16[0];
      v17[1].m_real.m128_i16[0] = *(_WORD *)(v20 + v17->m_real.m128_u64[0]);
      *(_WORD *)(v20 + v18 + 28) = 0;
      *(_WORD *)(v20 + v18 + 30) = m_id;
      *(__m128 *)(v20 + v18) = _mm_shuffle_ps(
                                 aabbs->m_min.m_quad,
                                 _mm_unpackhi_ps(aabbs->m_min.m_quad, *(__m128 *)(v20 + v18)),
                                 196);
      *(__m128 *)(v20 + v18 + 16) = _mm_shuffle_ps(
                                      aabbs->m_max.m_quad,
                                      _mm_unpackhi_ps(aabbs->m_max.m_quad, *(__m128 *)(v20 + v18 + 16)),
                                      196);
      v21 = v17->m_real.m128_u64[0];
      v22 = v17[2].m_real.m128_u16[0];
      v23 = *(__m128 *)(v17->m_real.m128_u64[0] + v20);
      v24 = _mm_shuffle_ps(
              *(__m128 *)(v17->m_real.m128_u64[0] + v20 + 16),
              _mm_unpackhi_ps(*(__m128 *)(v17->m_real.m128_u64[0] + v20 + 16), (__m128)0i64),
              196);
      if ( v22 )
      {
        if ( !v17[1].m_real.m128_i16[0] )
          hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::Codec32>::reserveNodes(
            (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::Codec32> *)v17,
            &v49,
            1);
        v25 = (__m128 *)(v17->m_real.m128_u64[0] + 32i64 * v22);
        v26 = (__m128 *)(v17->m_real.m128_u64[0] + 32i64 * v17[1].m_real.m128_u16[0]);
        v17[1].m_real.m128_i16[0] = v26->m128_i16[0];
        v27 = v25[1].m128_u16[6];
        if ( v27 )
        {
          v28 = _mm_add_ps(v24, v23);
          v29 = _mm_sub_ps(v24, v23);
          do
          {
            v30 = (__m128 *)(v17->m_real.m128_u64[0] + 32i64 * v27);
            v31 = (__m128 *)(v17->m_real.m128_u64[0] + 32i64 * v25[1].m128_u16[7]);
            v32 = _mm_min_ps(v23, *v25);
            v33 = _mm_max_ps(v24, _mm_shuffle_ps(v25[1], _mm_unpackhi_ps(v25[1], (__m128)0i64), 196));
            v51[0] = (__int64)v30;
            v51[1] = (__int64)v31;
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
            v25 = (__m128 *)v51[(float)((float)((float)(_mm_shuffle_ps(v39, v39, 85).m128_f32[0]
                                                      + _mm_shuffle_ps(v39, v39, 0).m128_f32[0])
                                              + _mm_shuffle_ps(v39, v39, 170).m128_f32[0])
                                      * (float)((float)(_mm_shuffle_ps(v38, v38, 85).m128_f32[0]
                                                      + _mm_shuffle_ps(v38, v38, 0).m128_f32[0])
                                              + _mm_shuffle_ps(v38, v38, 170).m128_f32[0])) > (float)((float)((float)(_mm_shuffle_ps(v42, v42, 85).m128_f32[0] + _mm_shuffle_ps(v42, v42, 0).m128_f32[0]) + _mm_shuffle_ps(v42, v42, 170).m128_f32[0]) * (float)((float)(_mm_shuffle_ps(v40, v40, 85).m128_f32[0] + _mm_shuffle_ps(v40, v40, 0).m128_f32[0]) + _mm_shuffle_ps(v40, v40, 170).m128_f32[0]))];
            v27 = v25[1].m128_u16[6];
          }
          while ( v27 );
        }
        v43 = v25->m128_u16[6];
        v44 = (__int64)((__int64)v26 - v17->m_real.m128_u64[0]) >> 5;
        if ( v43 )
          *(_WORD *)(v17->m_real.m128_u64[0]
                   + 2
                   * (16i64 * v43
                    + (*(_WORD *)(32i64 * v43 + v17->m_real.m128_u64[0] + 30) == (unsigned __int16)((__int64)((__int64)v25 - v17->m_real.m128_u64[0]) >> 5)))
                   + 28) = v44;
        else
          v17[2].m_real.m128_i16[0] = v44;
        v45 = (unsigned __int16)v44 | 0x3F000000;
        v26->m128_i32[3] = v25->m128_u16[6] | 0x3F000000;
        v46 = (unsigned int)((_DWORD)v25 - v17->m_real.m128_i32[0]);
        v26[1].m128_i16[7] = v19;
        v26[1].m128_i16[6] = v46 >> 5;
        v25->m128_i32[3] = v45;
        *(_DWORD *)(v17->m_real.m128_u64[0] + v20 + 12) = v45;
        v47 = _mm_min_ps(*v25, v23);
        v48 = _mm_max_ps(_mm_shuffle_ps(v25[1], _mm_unpackhi_ps(v25[1], (__m128)0i64), 196), v24);
        *v26 = _mm_shuffle_ps(v47, _mm_unpackhi_ps(v47, *v26), 196);
        v26[1] = _mm_shuffle_ps(v48, _mm_unpackhi_ps(v48, v26[1]), 196);
      }
      else
      {
        v17[2].m_real.m128_i16[0] = v19;
        *(_DWORD *)(v21 + v20 + 12) = 1056964608;
      }
      ++v17[1].m_real.m128_i32[2];
      *(_DWORD *)(v12 + 8) &= 0xFFE00000;
      v7 = this;
      v5 = handles;
      ++v8;
      ++aabbs;
      *(_DWORD *)(v12 + 8) |= v19 & 0x1FFFFF;
    }
    while ( v8 < v50 );
  }
}

// File Line: 705
// RVA: 0xDAA3E0
void __fastcall hkpTreeBroadPhase32::addHandlesStandalone(
        hkpTreeBroadPhase32 *this,
        hkpBroadPhaseHandle **handles,
        hkAabb *aabbs,
        int count,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *addPairs)
{
  int v5; // esi
  int m_size; // r9d
  int v7; // r9d
  hkpBroadPhaseHandle *const *v8; // rbx
  int v9; // eax
  int v11; // eax
  int v12; // r14d
  __int64 v13; // r8
  int v14; // r15d
  __int64 v15; // rdi
  __int64 v16; // r12
  hkAabb *v17; // rsi
  __int64 v18; // r14
  __m128 m_quad; // xmm0
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
  __int64 v41; // r9
  __m128 v42; // xmm1
  hkpTreeBroadPhaseInternals::InsertionQuery *v43; // r9
  int v44; // ebx
  hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> > *v45; // rdi
  bool v46; // zf
  hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> > tree; // [rsp+30h] [rbp-D0h] BYREF
  __int64 v48; // [rsp+450h] [rbp+350h]
  __int64 v49; // [rsp+460h] [rbp+360h]
  __int64 v50; // [rsp+468h] [rbp+368h]
  __int64 v51; // [rsp+510h] [rbp+410h]
  hkpBroadPhaseHandle **handlesa; // [rsp+518h] [rbp+418h]
  int v54; // [rsp+528h] [rbp+428h]

  v54 = count;
  handlesa = handles;
  v5 = count;
  m_size = this->m_handles[0].m_size;
  tree.m_nodes[0].m_aabb.m_min.m_quad.m128_u64[0] = (unsigned __int64)addPairs;
  v7 = v5 + m_size + 1;
  v8 = handles;
  v9 = this->m_handles[0].m_capacityAndFlags & 0x3FFFFFFF;
  if ( v9 < v7 )
  {
    v11 = 2 * v9;
    if ( v7 < v11 )
      v7 = v11;
    hkArrayUtil::_reserve(
      (hkResult *)&addPairs,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_handles[0].m_data,
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
      v14 = this->m_handles[0].m_size;
      v50 = 0i64;
      v49 = 0i64;
      v15 = 0i64;
      v16 = v12;
      if ( v12 > 0 )
      {
        v17 = aabbs;
        do
        {
          v8[v15]->m_id = v14;
          v18 = v48;
          m_quad = v17->m_min.m_quad;
          v20 = v17->m_max.m_quad;
          v21 = v48 << 6;
          v22 = m_quad;
          v23 = v20;
          v48 = *(&tree.m_nodes[0].m_parent + 8 * (__int64)(int)v48);
          v24 = (unsigned __int64)v8[v15];
          *(unsigned __int64 *)((char *)&tree.m_nodes[1].m_aabb.m_min.m_quad.m128_u64[1] + v21) = 0i64;
          *(unsigned __int64 *)((char *)tree.m_nodes[1].m_aabb.m_max.m_quad.m128_u64 + v21) = v24;
          *(__m128 *)((char *)&tree.m_nodes[0].m_parent + v21) = m_quad;
          *(__m128 *)((char *)&tree.m_nodes[0].m_children[1] + v21) = v20;
          if ( v50 )
          {
            v25 = &tree.m_nodes[0].m_parent + 8 * v48;
            v48 = *(&tree.m_nodes[0].m_parent + 8 * (__int64)(int)v48);
            v26 = (__m128 *)(&tree.m_nodes[0].m_parent + 8 * v50);
            if ( v26[2].m128_i32[2] )
            {
              v27 = _mm_add_ps(m_quad, v20);
              v28 = _mm_sub_ps(v20, m_quad);
              do
              {
                v29 = _mm_min_ps(*v26, v22);
                v30 = _mm_max_ps(v26[1], v23);
                v31 = v26[3].m128_u64[0] << 6;
                tree.m_nodes[0].m_aabb.m_max.m_quad.m128_u64[0] = (unsigned __int64)(&tree.m_nodes[0].m_parent
                                                                                   + 8 * v26[2].m128_u64[1]);
                v13 = tree.m_nodes[0].m_aabb.m_max.m_quad.m128_i64[0];
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
                v26 = (__m128 *)tree.m_nodes[0].m_aabb.m_max.m_quad.m128_u64[(float)((float)((float)(_mm_shuffle_ps(v34, v34, 85).m128_f32[0] + _mm_shuffle_ps(v34, v34, 0).m128_f32[0])
                                                                                           + _mm_shuffle_ps(
                                                                                               v34,
                                                                                               v34,
                                                                                               170).m128_f32[0])
                                                                                   * (float)((float)(_mm_shuffle_ps(v37, v37, 85).m128_f32[0] + _mm_shuffle_ps(v37, v37, 0).m128_f32[0])
                                                                                           + _mm_shuffle_ps(
                                                                                               v37,
                                                                                               v37,
                                                                                               170).m128_f32[0])) > (float)((float)((float)(_mm_shuffle_ps(v39, v39, 85).m128_f32[0] + _mm_shuffle_ps(v39, v39, 0).m128_f32[0]) + _mm_shuffle_ps(v39, v39, 170).m128_f32[0]) * (float)((float)(_mm_shuffle_ps(v35, v35, 85).m128_f32[0] + _mm_shuffle_ps(v35, v35, 0).m128_f32[0]) + _mm_shuffle_ps(v35, v35, 170).m128_f32[0]))];
              }
              while ( v26[2].m128_i32[2] );
            }
            v40 = v26[2].m128_u64[0];
            v41 = ((char *)v25 - (char *)&tree.m_nodes[0].m_parent) >> 6;
            if ( v40 )
            {
              v13 = ((char *)v26 - (char *)&tree.m_nodes[0].m_parent) >> 6;
              tree.m_nodes[1].m_aabb.m_min.m_quad.m128_u64[8 * v40
                                                         + 1
                                                         + (tree.m_nodes[1].m_aabb.m_max.m_quad.m128_u64[8 * v40] == v13)] = v41;
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
        v12 = (int)addPairs;
      }
      hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::allPairs<hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>>,hkpTreeBroadPhaseInternals::InsertionQuery>(
        (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)&tree.m_nodes[0].m_parent,
        &tree,
        (hkpTreeBroadPhaseInternals::InsertionQuery *)v13);
      v44 = 1;
      v45 = (hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> > *)&this->m_internals[3];
      do
      {
        tree.m_nodes[0].m_aabb.m_min.m_quad.m128_u64[1] = (unsigned __int64)this->m_handles[v44 == 4].m_data;
        hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::allPairs<hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>>,hkpTreeBroadPhaseSpatialTree32,hkpTreeBroadPhaseInternals::InsertionQuery>(
          (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)&tree.m_nodes[0].m_parent,
          v45,
          (hkpTreeBroadPhaseSpatialTree32 *)&tree,
          v43);
        ++v44;
        v45 = (hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> > *)((char *)v45 + 48);
      }
      while ( v44 <= 3 );
      hkpTreeBroadPhase32::addHandles(this, handlesa, aabbs, v12);
      v8 = &handlesa[v16];
      v5 -= 8;
      v46 = v51-- == 1;
      aabbs += v16;
      handlesa = (hkpBroadPhaseHandle **)v8;
      v54 = v5;
    }
    while ( !v46 );
  }
}

// File Line: 743
// RVA: 0xD9E9A0
void __fastcall hkpTreeBroadPhase::removeHandles(
        hkpTreeBroadPhase *this,
        hkpBroadPhaseHandle *const *handles,
        int count)
{
  __int64 v4; // rcx
  hkpBroadPhaseHandle *const *v5; // rax
  __int64 v6; // r13
  __int64 v7; // rbp
  hkpTreeBroadPhase::Handle *v8; // rdi
  unsigned __int16 v9; // r14
  __int64 v10; // r15
  hkSimdFloat32 *v11; // r11
  unsigned __int64 v12; // rsi
  unsigned __int16 v13; // r8
  __m128 v14; // xmm6
  __m128 v15; // xmm4
  unsigned __int64 v16; // rdx
  unsigned __int16 v17; // ax
  unsigned __int64 v18; // rbx
  unsigned __int16 v19; // r8
  unsigned __int64 v20; // rdx
  __int64 v21; // rax
  unsigned __int16 v22; // r8
  __m128 *v23; // rcx
  __int64 v24; // rax
  __m128 v25; // xmm3
  __m128 v26; // xmm2
  __int64 v27; // rax
  __m128 v28; // xmm0
  __m128 v29; // xmm3
  __int64 v30; // [rsp+8h] [rbp-40h]

  if ( count > 0 )
  {
    v4 = 0i64;
    v5 = handles;
    v6 = count;
    v7 = 0i64;
    do
    {
      v8 = &this->m_handles[0].m_data[v5[v7]->m_id];
      v9 = *((_WORD *)v8 + 4);
      v10 = 32i64 * v9;
      v11 = &this->m_internals[3 * ((*((_DWORD *)v8 + 2) >> 21) & 0xF)];
      v12 = v11->m_real.m128_u64[0];
      v13 = v11[2].m_real.m128_u16[0];
      v14 = *(__m128 *)(v11->m_real.m128_u64[0] + v10);
      v15 = _mm_shuffle_ps(
              *(__m128 *)(v11->m_real.m128_u64[0] + v10 + 16),
              _mm_unpackhi_ps(*(__m128 *)(v11->m_real.m128_u64[0] + v10 + 16), (__m128)0i64),
              196);
      if ( v9 == v13 )
      {
        v11[2].m_real.m128_i16[0] = 0;
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
          *(_WORD *)(v11->m_real.m128_u64[0]
                   + 2
                   * (16i64 * *(unsigned __int16 *)(v16 + 12)
                    + (*(_WORD *)(32i64 * *(unsigned __int16 *)(v16 + 12) + v11->m_real.m128_u64[0] + 30) == *(_WORD *)(v12 + v10 + 12)))
                   + 28) = (__int64)(v18 - v11->m_real.m128_u64[0]) >> 5;
          v19 = *(_WORD *)(v12 + v10 + 12);
          *(_WORD *)(32i64 * v19 + v11->m_real.m128_u64[0]) = v11[1].m_real.m128_i16[0];
          v20 = v11->m_real.m128_u64[0];
          v11[1].m_real.m128_i16[0] = v19;
          v21 = v20 + 32i64 * *(unsigned __int16 *)(v18 + 12);
          do
          {
            v22 = *(_WORD *)(v21 + 12);
            v23 = (__m128 *)(v20 + 32i64 * (unsigned __int16)((__int64)(v21 - v20) >> 5));
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
            if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v15, v29), _mm_cmple_ps(v28, v14))) & 7) == 7 )
              break;
            if ( !v22 )
              break;
            v20 = v11->m_real.m128_u64[0];
            v21 = v11->m_real.m128_u64[0] + 32i64 * v22;
          }
          while ( v21 );
        }
        else
        {
          *(_WORD *)(32i64 * v13 + v12) = v11[1].m_real.m128_i16[0];
          v11[1].m_real.m128_i16[0] = v13;
          v11[2].m_real.m128_i16[0] = (__int64)(unsigned int)(v18 - v11->m_real.m128_i32[0]) >> 5;
          *(_DWORD *)(v18 + 12) = 1056964608;
        }
      }
      ++v7;
      *(_WORD *)(v10 + v11->m_real.m128_u64[0]) = v11[1].m_real.m128_i16[0];
      --v11[1].m_real.m128_i32[2];
      v4 = 0i64;
      v11[1].m_real.m128_i16[0] = v9;
      LODWORD(v30) = 0;
      v8->m_bpHandle = 0i64;
      *((_QWORD *)v8 + 1) = v30;
      v5 = handles;
    }
    while ( v7 < v6 );
  }
}

// File Line: 758
// RVA: 0xD9EC30
void __fastcall hkpTreeBroadPhase::removeHandlesStandalone(
        hkpTreeBroadPhase *this,
        hkpBroadPhaseHandle *const *handles,
        int count,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *remPairs)
{
  __int64 v5; // rcx
  __int64 v6; // r12
  signed int m_id; // r14d
  __int64 v8; // r10
  hkpTreeBroadPhase::Handle *v9; // rsi
  unsigned __int16 v10; // r12
  hkSimdFloat32 *v11; // r11
  __int64 v12; // rax
  unsigned __int64 v13; // r8
  unsigned __int16 v14; // r9
  __int128 v15; // xmm7
  char v16; // bl
  __int64 v17; // r13
  __m128 *v18; // rdi
  __m128 v19; // xmm6
  __m128 v20; // xmm5
  __m128 v21; // xmm4
  unsigned __int64 v22; // rdx
  unsigned __int16 v23; // ax
  unsigned __int64 v24; // rbx
  unsigned __int16 v25; // r8
  unsigned __int64 v26; // rdx
  __int64 v27; // rax
  unsigned __int16 v28; // r8
  __m128 *v29; // rcx
  __int64 v30; // rax
  __m128 v31; // xmm3
  __m128 v32; // xmm2
  __int64 v33; // rax
  __m128 v34; // xmm0
  __m128 v35; // xmm3
  __int64 v36; // rcx
  __int64 v37; // r8
  __int64 v38; // rdx
  hkpTreeBroadPhase::Handle *v39; // rcx
  __int64 v40; // rdx
  __int64 v41; // rax
  __int64 v42; // r12
  int v43; // esi
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *v44; // r14
  hkLifoAllocator *Value; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsNoEarlyExitWrapper<hkpTreeBroadPhaseInternals::NewPairsQuery> *v46; // r9
  hkcdDynamicTree::Codec32 *m_cur; // rcx
  hkcdDynamicTree::Codec32 *v48; // rdx
  int m_size; // eax
  char *v50; // rdi
  signed int v51; // ebx
  hkLifoAllocator *v52; // rax
  int v53; // r8d
  int v54; // [rsp+14h] [rbp-7Dh]
  hkcdDynamicTree::Codec32 *p; // [rsp+18h] [rbp-79h]
  hkpTreeBroadPhaseSpatialTree16 tree; // [rsp+20h] [rbp-71h] BYREF
  hkcdTreeQueriesStacks::Dynamic<64,unsigned short> stackInstance; // [rsp+58h] [rbp-39h] BYREF
  __m128 v58; // [rsp+78h] [rbp-19h]
  hkpBroadPhaseHandle *const *vars0; // [rsp+100h] [rbp+6Fh]
  void *retaddr; // [rsp+108h] [rbp+77h]

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
      m_id = handles[v6]->m_id;
      v8 = m_id;
      v9 = &this->m_handles[0].m_data[v8];
      v10 = *((_WORD *)v9 + 4);
      v11 = &this->m_internals[3 * ((*((_DWORD *)v9 + 2) >> 21) & 0xF)];
      v12 = v11->m_real.m128_u64[0] + 32i64 * v10;
      v13 = v11->m_real.m128_u64[0];
      v14 = v11[2].m_real.m128_u16[0];
      v15 = *(_OWORD *)v12;
      v16 = m_id < this->m_handles[0].m_size - 1;
      v17 = 32i64 * v10;
      v18 = (__m128 *)(v11->m_real.m128_u64[0] + v17);
      LOBYTE(retaddr) = v16;
      v19 = _mm_shuffle_ps(*(__m128 *)(v12 + 16), _mm_unpackhi_ps(*(__m128 *)(v12 + 16), (__m128)0i64), 196);
      v20 = *v18;
      v21 = _mm_shuffle_ps(v18[1], _mm_unpackhi_ps(v18[1], (__m128)0i64), 196);
      if ( v10 == v14 )
      {
        v11[2].m_real.m128_i16[0] = 0;
      }
      else
      {
        v22 = v13 + 32i64 * v18->m128_u16[6];
        LOBYTE(v5) = *(_WORD *)(v22 + 30) == v10;
        v23 = *(_WORD *)(v22 + 12);
        v24 = v13 + 32i64 * *(unsigned __int16 *)(v22 + 2 * (15 - v5));
        if ( v23 )
        {
          *(_DWORD *)(v24 + 12) = v23 | 0x3F000000;
          *(_WORD *)(v11->m_real.m128_u64[0]
                   + 2
                   * (16i64 * *(unsigned __int16 *)(v22 + 12)
                    + (*(_WORD *)(32i64 * *(unsigned __int16 *)(v22 + 12) + v11->m_real.m128_u64[0] + 30) == v18->m128_i16[6]))
                   + 28) = (__int64)(v24 - v11->m_real.m128_u64[0]) >> 5;
          v25 = v18->m128_u16[6];
          *(_WORD *)(32i64 * v25 + v11->m_real.m128_u64[0]) = v11[1].m_real.m128_i16[0];
          v26 = v11->m_real.m128_u64[0];
          v11[1].m_real.m128_i16[0] = v25;
          v27 = v26 + 32i64 * *(unsigned __int16 *)(v24 + 12);
          do
          {
            v28 = *(_WORD *)(v27 + 12);
            v29 = (__m128 *)(v26 + 32i64 * (unsigned __int16)((__int64)(v27 - v26) >> 5));
            v30 = 32i64 * v29[1].m128_u16[6];
            v31 = *(__m128 *)(v30 + v26 + 16);
            v32 = *(__m128 *)(v30 + v26);
            v33 = 32i64 * v29[1].m128_u16[7];
            v34 = _mm_min_ps(v32, *(__m128 *)(v33 + v26));
            v35 = _mm_max_ps(
                    _mm_shuffle_ps(v31, _mm_unpackhi_ps(v31, (__m128)0i64), 196),
                    _mm_shuffle_ps(
                      *(__m128 *)(v33 + v26 + 16),
                      _mm_unpackhi_ps(*(__m128 *)(v33 + v26 + 16), (__m128)0i64),
                      196));
            *v29 = _mm_shuffle_ps(v34, _mm_unpackhi_ps(v34, *v29), 196);
            v29[1] = _mm_shuffle_ps(v35, _mm_unpackhi_ps(v35, v29[1]), 196);
            if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v21, v35), _mm_cmple_ps(v34, v20))) & 7) == 7 )
              break;
            if ( !v28 )
              break;
            v26 = v11->m_real.m128_u64[0];
            v27 = v11->m_real.m128_u64[0] + 32i64 * v28;
          }
          while ( v27 );
          v8 = m_id;
        }
        else
        {
          *(_WORD *)(32i64 * v14 + v13) = v11[1].m_real.m128_i16[0];
          v11[1].m_real.m128_i16[0] = v14;
          v11[2].m_real.m128_i16[0] = (__int64)(unsigned int)(v24 - v11->m_real.m128_i32[0]) >> 5;
          *(_DWORD *)(v24 + 12) = 1056964608;
        }
        v16 = (char)retaddr;
      }
      *(_WORD *)(v17 + v11->m_real.m128_u64[0]) = v11[1].m_real.m128_i16[0];
      --v11[1].m_real.m128_i32[2];
      v11[1].m_real.m128_i16[0] = v10;
      v9->m_bpHandle->m_id = 0;
      v36 = --this->m_handles[0].m_size;
      if ( (_DWORD)v36 != m_id )
      {
        v37 = 2i64;
        v38 = 16 * v36;
        v39 = &this->m_handles[0].m_data[v8];
        v40 = v38 - v8 * 16;
        do
        {
          v41 = *(__int64 *)((char *)&v39->m_bpHandle + v40);
          v39 = (hkpTreeBroadPhase::Handle *)((char *)v39 + 8);
          *((_QWORD *)&v39[-1] + 1) = v41;
          --v37;
        }
        while ( v37 );
      }
      if ( v16 )
      {
        v9->m_bpHandle->m_id = m_id;
        *(_WORD *)(this->m_internals[3 * ((*((_DWORD *)v9 + 2) >> 21) & 0xF)].m_real.m128_u64[0]
                 + 32i64 * *((unsigned __int16 *)v9 + 4)
                 + 30) = m_id;
      }
      v42 = *(_QWORD *)&tree.m_nodes.m_size;
      v43 = 1;
      v44 = (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)&this->m_internals[3];
      *(hkpBroadPhaseHandle **)&tree.m_sortPath = vars0[*(_QWORD *)&tree.m_nodes.m_size];
      do
      {
        *(_OWORD *)&stackInstance.m_stack.m_localMemory = v15;
        v58 = v19;
        tree.m_nodes.m_size = 0;
        tree.m_nodes.m_data = (hkcdDynamicTree::Codec32 *)64;
        *(_QWORD *)&tree.m_numLeaves = this->m_handles[v43 == 4].m_data;
        stackInstance.m_stack.m_data = (unsigned __int16 *)&tree.m_numLeaves;
        Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        m_cur = (hkcdDynamicTree::Codec32 *)Value->m_cur;
        v48 = m_cur + 4;
        if ( Value->m_slabSize < 128 || v48 > Value->m_end )
          m_cur = (hkcdDynamicTree::Codec32 *)hkLifoAllocator::allocateFromNewSlab(Value, 128);
        else
          Value->m_cur = v48;
        tree.m_nodes.m_data = m_cur;
        hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkpTreeBroadPhaseSpatialTree16,hkcdTreeQueriesStacks::Dynamic<64,unsigned short>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsNoEarlyExitWrapper<hkpTreeBroadPhaseInternals::NewPairsQuery>>(
          v44,
          &tree,
          &stackInstance,
          v46);
        m_size = tree.m_nodes.m_size;
        v50 = (char *)p;
        if ( p == tree.m_nodes.m_data )
          m_size = 0;
        tree.m_nodes.m_size = m_size;
        v51 = (2 * LODWORD(tree.m_nodes.m_data) + 127) & 0xFFFFFF80;
        v52 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v53 = (v51 + 15) & 0xFFFFFFF0;
        if ( v51 > v52->m_slabSize || &v50[v53] != v52->m_cur || v52->m_firstNonLifoEnd == v50 )
          hkLifoAllocator::slowBlockFree(v52, v50, v53);
        else
          v52->m_cur = v50;
        tree.m_nodes.m_size = 0;
        if ( v54 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            tree.m_nodes.m_data,
            2 * (v54 & 0x3FFFFFFF));
        ++v43;
        v44 += 48;
      }
      while ( v43 <= 3 );
      handles = vars0;
      v6 = v42 + 1;
      v5 = 0i64;
      *(_QWORD *)&tree.m_nodes.m_size = v6;
    }
    while ( v6 < *(__int64 *)&tree.m_firstFree );
  }
}

// File Line: 791
// RVA: 0xDAA890
void __fastcall hkpTreeBroadPhase32::updateHandles(
        hkpTreeBroadPhase32 *this,
        hkpBroadPhaseHandle *const *handles,
        hkAabb *aabbs,
        int count)
{
  __int64 v4; // r12
  __m128 v7; // xmm11
  __m128 v8; // xmm12
  hkpTreeBroadPhase32::Handle *v9; // r8
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint> *v10; // rbx
  unsigned int v11; // eax
  hkcdDynamicTree::CodecRawUint *v12; // r9
  hkVector4f v13; // xmm2
  __int64 v14; // r10
  char *v15; // rcx
  __int64 v16; // rbp
  __m128 v17; // xmm1
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  __m128 v20; // xmm4
  hkcdDynamicTree::CodecRawUint *v21; // rdi
  hkcdDynamicTree::CodecRawUint *v22; // rdx
  unsigned int v23; // eax
  hkcdDynamicTree::CodecRawUint *v24; // r8
  unsigned int *v25; // r11
  __int64 v26; // r8
  hkcdDynamicTree::CodecRawUint *v27; // r9
  __int64 v28; // rcx
  __int64 v29; // r10
  __int64 v30; // rdi
  __m128 *v31; // r8
  __m128 v32; // xmm2
  __m128 v33; // xmm1
  signed __int64 v34; // rcx
  hkcdDynamicTree::CodecRawUint *v35; // rax
  __int64 v36; // rsi
  hkcdDynamicTree::CodecRawUint *v37; // rax
  __m128 v38; // xmm7
  __m128 v39; // xmm8
  __int64 v40; // rdx
  hkcdDynamicTree::CodecRawUint *v41; // r8
  __int64 v42; // r11
  __m128 *v43; // r9
  __int64 v44; // rax
  __m128 v45; // xmm9
  __m128 v46; // xmm10
  __int64 v47; // r8
  __m128 v48; // xmm0
  __m128 v49; // xmm1
  __int64 v50; // rdx
  __m128 *v51; // rdx
  __m128 v52; // xmm3
  __m128 v53; // xmm2
  __m128 v54; // xmm5
  __m128 v55; // xmm3
  __m128 v56; // xmm3
  __m128 v57; // xmm6
  __m128 v58; // xmm6
  __int64 v59; // r10
  int v60; // eax
  signed __int64 v61; // rcx
  __m128 v62; // xmm1
  hkcdDynamicTree::CodecRawUint *m_data; // rsi
  __int64 m_size; // r9
  __int64 v65; // rdx
  int v66; // r14d
  __int64 v67; // rdi
  __m128 m_quad; // xmm3
  __m128 v69; // xmm4
  hkcdDynamicTree::CodecRawUint *v70; // rdx
  unsigned int m_parent; // eax
  hkcdDynamicTree::CodecRawUint *v72; // r8
  unsigned int *p_m_parent; // r11
  __int64 v74; // r8
  hkcdDynamicTree::CodecRawUint *v75; // r8
  __int64 v76; // rcx
  __int64 v77; // r9
  __m128 *p_m_quad; // rdx
  __m128 v79; // xmm2
  __m128 v80; // xmm1
  signed __int64 v81; // rcx
  hkcdDynamicTree::CodecRawUint *v82; // rax
  hkcdDynamicTree::CodecRawUint *v83; // rax
  __int64 v84; // rsi
  __m128 v85; // xmm7
  __m128 v86; // xmm8
  __int64 m_firstFree; // rdx
  __m128 *v88; // r9
  __int64 v89; // r11
  __int64 v90; // rax
  __m128 v91; // xmm9
  __m128 v92; // xmm10
  __int64 v93; // r8
  __m128 v94; // xmm0
  __m128 v95; // xmm1
  __int64 v96; // rdx
  __m128 *v97; // rdx
  __m128 v98; // xmm2
  __m128 v99; // xmm3
  __m128 v100; // xmm2
  __m128 v101; // xmm2
  __m128 v102; // xmm6
  __m128 v103; // xmm5
  __m128 v104; // xmm5
  __int64 v105; // r10
  int v106; // eax
  signed __int64 v107; // rcx
  __m128 v108; // xmm1
  __int64 v109; // [rsp+20h] [rbp-D8h]
  __int64 v110[2]; // [rsp+28h] [rbp-D0h]
  __int64 v111[3]; // [rsp+38h] [rbp-C0h]
  hkResult v112; // [rsp+100h] [rbp+8h] BYREF
  hkpBroadPhaseHandle *const *v113; // [rsp+108h] [rbp+10h]
  hkResult result; // [rsp+118h] [rbp+20h] BYREF

  v113 = handles;
  result.m_enum = this->m_parameters.m_quad.m128_i32[0];
  v4 = 0i64;
  v109 = count;
  v7 = _mm_shuffle_ps((__m128)(unsigned int)result.m_enum, (__m128)(unsigned int)result.m_enum, 0);
  v8 = _mm_shuffle_ps(this->m_offsetAndTimeStep.m_quad, this->m_offsetAndTimeStep.m_quad, 255);
  if ( count > 0 )
  {
    while ( 1 )
    {
      v9 = &this->m_handles[0].m_data[handles[v4]->m_id];
      v10 = (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint> *)&this->m_internals[3 * ((*((_DWORD *)v9 + 2) >> 21) & 0xF)];
      v11 = *((_DWORD *)v9 + 2) & 0x1FFFFFF ^ ((*((_DWORD *)v9 + 2) & 0xFE000000) + 0x2000000);
      *((_DWORD *)v9 + 2) = v11;
      if ( (v11 & 0xFE000000) == 0 || (v11 & 0x1E00000) != 6291456 )
      {
        m_data = v10->m_nodes.m_data;
        m_size = v10[1].m_nodes.m_size;
        v65 = v11 & 0x1FFFFF;
        v66 = v11 & 0x1FFFFF;
        v67 = v65;
        m_quad = v10->m_nodes.m_data[v65].m_aabb.m_min.m_quad;
        v69 = v10->m_nodes.m_data[v65].m_aabb.m_max.m_quad;
        if ( (_DWORD)v65 == (_DWORD)m_size )
        {
          v10[1].m_nodes.m_size = 0;
        }
        else
        {
          v70 = &m_data[m_data[v65].m_parent];
          m_parent = v70->m_parent;
          v72 = &m_data[v70->m_aabb.m_min.m_quad.m128_u32[10i64 - (v70->m_children[1] == v66)]];
          if ( m_parent )
          {
            v72->m_parent = m_parent;
            p_m_parent = &v72->m_parent;
            v10->m_nodes.m_data[v70->m_parent].m_children[v10->m_nodes.m_data[v70->m_parent].m_children[1] == m_data[v67].m_parent] = ((int)v72 - LODWORD(v10->m_nodes.m_data)) / 48;
            v74 = (int)m_data[v67].m_parent;
            v10->m_nodes.m_data[v74].m_aabb.m_min.m_quad.m128_i32[0] = v10->m_firstFree;
            v10->m_firstFree = v74;
            v75 = v10->m_nodes.m_data;
            v76 = (__int64)&v10->m_nodes.m_data[*p_m_parent];
            do
            {
              v77 = *(unsigned int *)(v76 + 32);
              p_m_quad = &v75[((int)v76 - (int)v75) / 48].m_aabb.m_min.m_quad;
              v79 = _mm_min_ps(
                      v75[p_m_quad[2].m128_u32[1]].m_aabb.m_min.m_quad,
                      v75[p_m_quad[2].m128_u32[2]].m_aabb.m_min.m_quad);
              v80 = _mm_max_ps(
                      v75[p_m_quad[2].m128_u32[1]].m_aabb.m_max.m_quad,
                      v75[p_m_quad[2].m128_u32[2]].m_aabb.m_max.m_quad);
              *p_m_quad = v79;
              p_m_quad[1] = v80;
              if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v69, v80), _mm_cmple_ps(v79, m_quad))) & 7) == 7 )
                break;
              if ( !(_DWORD)v77 )
                break;
              v75 = v10->m_nodes.m_data;
              v76 = (__int64)&v10->m_nodes.m_data[v77];
            }
            while ( v76 );
          }
          else
          {
            m_data[m_size].m_aabb.m_min.m_quad.m128_i32[0] = v10->m_firstFree;
            v81 = (char *)v72 - (char *)v10->m_nodes.m_data;
            v10->m_firstFree = m_size;
            v10[1].m_nodes.m_size = v81 / 48;
            v72->m_parent = 0;
          }
        }
        v82 = v10->m_nodes.m_data;
        v82[v67].m_aabb.m_min = aabbs->m_min;
        v82[v67].m_aabb.m_max = aabbs->m_max;
        v83 = v10->m_nodes.m_data;
        v84 = (unsigned int)v10[1].m_nodes.m_size;
        v85 = v10->m_nodes.m_data[v67].m_aabb.m_min.m_quad;
        v86 = v10->m_nodes.m_data[v67].m_aabb.m_max.m_quad;
        if ( (_DWORD)v84 )
        {
          if ( !v10->m_firstFree )
            hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
              v10,
              &v112,
              1);
          m_firstFree = v10->m_firstFree;
          v88 = &v10->m_nodes.m_data[v84].m_aabb.m_min.m_quad;
          v89 = (__int64)&v10->m_nodes.m_data[m_firstFree];
          v10->m_firstFree = v10->m_nodes.m_data[(int)m_firstFree].m_aabb.m_min.m_quad.m128_u32[0];
          v90 = v88[2].m128_u32[1];
          if ( (_DWORD)v90 )
          {
            v91 = _mm_add_ps(v86, v85);
            v92 = _mm_sub_ps(v86, v85);
            do
            {
              v94 = _mm_min_ps(*v88, v85);
              v95 = _mm_max_ps(v88[1], v86);
              v96 = v88[2].m128_u32[2];
              v111[0] = (__int64)&v10->m_nodes.m_data[v90];
              v93 = v111[0];
              v97 = &v10->m_nodes.m_data[v96].m_aabb.m_min.m_quad;
              v111[1] = (__int64)v97;
              *v88 = v94;
              v88[1] = v95;
              v98 = *(__m128 *)(v93 + 16);
              v99 = _mm_add_ps(_mm_sub_ps(v98, *(__m128 *)v93), v92);
              v100 = _mm_sub_ps(_mm_add_ps(v98, *(__m128 *)v93), v91);
              v101 = _mm_mul_ps(v100, v100);
              v102 = _mm_add_ps(_mm_sub_ps(v97[1], *v97), v92);
              v103 = _mm_sub_ps(_mm_add_ps(v97[1], *v97), v91);
              v104 = _mm_mul_ps(v103, v103);
              v88 = (__m128 *)v111[(float)((float)((float)(_mm_shuffle_ps(v101, v101, 85).m128_f32[0]
                                                         + _mm_shuffle_ps(v101, v101, 0).m128_f32[0])
                                                 + _mm_shuffle_ps(v101, v101, 170).m128_f32[0])
                                         * (float)((float)(_mm_shuffle_ps(v99, v99, 85).m128_f32[0]
                                                         + _mm_shuffle_ps(v99, v99, 0).m128_f32[0])
                                                 + _mm_shuffle_ps(v99, v99, 170).m128_f32[0])) > (float)((float)((float)(_mm_shuffle_ps(v104, v104, 85).m128_f32[0] + _mm_shuffle_ps(v104, v104, 0).m128_f32[0]) + _mm_shuffle_ps(v104, v104, 170).m128_f32[0]) * (float)((float)(_mm_shuffle_ps(v102, v102, 85).m128_f32[0] + _mm_shuffle_ps(v102, v102, 0).m128_f32[0]) + _mm_shuffle_ps(v102, v102, 170).m128_f32[0]))];
              v90 = v88[2].m128_u32[1];
            }
            while ( (_DWORD)v90 );
          }
          v105 = (signed __int64)(v89 - (unsigned __int64)v10->m_nodes.m_data) / 48;
          v106 = v88[2].m128_i32[0];
          if ( v106 )
            v10->m_nodes.m_data[v106].m_children[v10->m_nodes.m_data[v106].m_children[1] == (unsigned int)(((char *)v88 - (char *)v10->m_nodes.m_data) / 48)] = v105;
          else
            v10[1].m_nodes.m_size = v105;
          *(_DWORD *)(v89 + 32) = v88[2].m128_i32[0];
          v107 = (char *)v88 - (char *)v10->m_nodes.m_data;
          *(_DWORD *)(v89 + 40) = v66;
          *(_DWORD *)(v89 + 36) = v107 / 48;
          v88[2].m128_i32[0] = v105;
          v10->m_nodes.m_data[v67].m_parent = v105;
          v108 = _mm_max_ps(v88[1], v86);
          *(__m128 *)v89 = _mm_min_ps(*v88, v85);
          *(__m128 *)(v89 + 16) = v108;
        }
        else
        {
          v10[1].m_nodes.m_size = v66;
          v83[v67].m_parent = 0;
        }
        goto LABEL_46;
      }
      v12 = v10->m_nodes.m_data;
      v13.m_quad = (__m128)aabbs->m_max;
      if ( (_mm_movemask_ps(
              _mm_or_ps(
                _mm_cmplt_ps(aabbs->m_min.m_quad, v10->m_nodes.m_data[v11 & 0x1FFFFF].m_aabb.m_min.m_quad),
                _mm_cmplt_ps(v10->m_nodes.m_data[v11 & 0x1FFFFF].m_aabb.m_max.m_quad, v13.m_quad))) & 7) != 0 )
        break;
LABEL_46:
      handles = v113;
      ++v4;
      ++aabbs;
      if ( v4 >= v109 )
        return;
    }
    v14 = v10[1].m_nodes.m_size;
    v15 = (char *)v9->m_bpHandle + SBYTE1(v9->m_bpHandle[1].m_id);
    v16 = v11 & 0x1FFFFF;
    v17 = _mm_mul_ps(*(__m128 *)&v15[v15[32] + 560], v8);
    v18 = _mm_shuffle_ps(v17, _mm_unpackhi_ps(v17, v7), 196);
    v19 = _mm_min_ps(_mm_add_ps(aabbs->m_min.m_quad, v18), aabbs->m_min.m_quad);
    v20 = _mm_max_ps(_mm_add_ps(v13.m_quad, v18), v13.m_quad);
    if ( (v11 & 0x1FFFFF) == (_DWORD)v14 )
    {
      v10[1].m_nodes.m_size = 0;
    }
    else
    {
      v21 = &v12[v11 & 0x1FFFFF];
      v22 = &v12[v21->m_parent];
      v23 = v22->m_parent;
      v24 = &v12[v22->m_aabb.m_min.m_quad.m128_u32[10i64 - (v22->m_children[1] == (_DWORD)v16)]];
      if ( v23 )
      {
        v24->m_parent = v23;
        v25 = &v24->m_parent;
        v10->m_nodes.m_data[v22->m_parent].m_children[v10->m_nodes.m_data[v22->m_parent].m_children[1] == v21->m_parent] = ((int)v24 - LODWORD(v10->m_nodes.m_data)) / 48;
        v26 = (int)v21->m_parent;
        v10->m_nodes.m_data[v26].m_aabb.m_min.m_quad.m128_i32[0] = v10->m_firstFree;
        v27 = v10->m_nodes.m_data;
        v10->m_firstFree = v26;
        v28 = (__int64)&v27[*v25];
        while ( 1 )
        {
          v29 = *(unsigned int *)(v28 + 32);
          v30 = (v28 - (__int64)v27) / 48;
          v31 = &v27[((int)v28 - (int)v27) / 48].m_aabb.m_min.m_quad;
          v32 = _mm_min_ps(v27[v31[2].m128_u32[1]].m_aabb.m_min.m_quad, v27[v31[2].m128_u32[2]].m_aabb.m_min.m_quad);
          v33 = _mm_max_ps(v27[v31[2].m128_u32[1]].m_aabb.m_max.m_quad, v27[v31[2].m128_u32[2]].m_aabb.m_max.m_quad);
          *v31 = v32;
          v31[1] = v33;
          if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v20, v33), _mm_cmple_ps(v32, v19))) & 7) == 7 )
            goto LABEL_15;
          if ( (_DWORD)v29 )
          {
            v27 = v10->m_nodes.m_data;
            v28 = (__int64)&v10->m_nodes.m_data[v29];
            if ( v28 )
              continue;
          }
          goto LABEL_14;
        }
      }
      v12[v14].m_aabb.m_min.m_quad.m128_i32[0] = v10->m_firstFree;
      v34 = (char *)v24 - (char *)v10->m_nodes.m_data;
      v10->m_firstFree = v14;
      v10[1].m_nodes.m_size = v34 / 48;
      v24->m_parent = 0;
    }
LABEL_14:
    LODWORD(v30) = v10[1].m_nodes.m_size;
LABEL_15:
    v35 = v10->m_nodes.m_data;
    v36 = v16;
    v35[v36].m_aabb.m_min.m_quad = v19;
    v35[v36].m_aabb.m_max.m_quad = v20;
    v37 = v10->m_nodes.m_data;
    v38 = v10->m_nodes.m_data[v16].m_aabb.m_min.m_quad;
    v39 = v10->m_nodes.m_data[v16].m_aabb.m_max.m_quad;
    if ( (_DWORD)v30 )
    {
      if ( !v10->m_firstFree )
        hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
          v10,
          &result,
          1);
      v40 = v10->m_firstFree;
      v41 = v10->m_nodes.m_data;
      v42 = (__int64)&v10->m_nodes.m_data[v40];
      v10->m_firstFree = v10->m_nodes.m_data[(int)v40].m_aabb.m_min.m_quad.m128_u32[0];
      v43 = &v41[(unsigned int)v30].m_aabb.m_min.m_quad;
      v44 = v43[2].m128_u32[1];
      if ( (_DWORD)v44 )
      {
        v45 = _mm_add_ps(v39, v38);
        v46 = _mm_sub_ps(v39, v38);
        do
        {
          v48 = _mm_min_ps(*v43, v38);
          v49 = _mm_max_ps(v43[1], v39);
          v50 = v43[2].m128_u32[2];
          v110[0] = (__int64)&v10->m_nodes.m_data[v44];
          v47 = v110[0];
          v51 = &v10->m_nodes.m_data[v50].m_aabb.m_min.m_quad;
          v110[1] = (__int64)v51;
          *v43 = v48;
          v43[1] = v49;
          v52 = *(__m128 *)(v47 + 16);
          v53 = _mm_add_ps(_mm_sub_ps(v52, *(__m128 *)v47), v46);
          v54 = _mm_add_ps(_mm_sub_ps(v51[1], *v51), v46);
          v55 = _mm_sub_ps(_mm_add_ps(v52, *(__m128 *)v47), v45);
          v56 = _mm_mul_ps(v55, v55);
          v57 = _mm_sub_ps(_mm_add_ps(v51[1], *v51), v45);
          v58 = _mm_mul_ps(v57, v57);
          v43 = (__m128 *)v110[(float)((float)((float)(_mm_shuffle_ps(v53, v53, 85).m128_f32[0]
                                                     + _mm_shuffle_ps(v53, v53, 0).m128_f32[0])
                                             + _mm_shuffle_ps(v53, v53, 170).m128_f32[0])
                                     * (float)((float)(_mm_shuffle_ps(v56, v56, 85).m128_f32[0]
                                                     + _mm_shuffle_ps(v56, v56, 0).m128_f32[0])
                                             + _mm_shuffle_ps(v56, v56, 170).m128_f32[0])) > (float)((float)((float)(_mm_shuffle_ps(v54, v54, 85).m128_f32[0] + _mm_shuffle_ps(v54, v54, 0).m128_f32[0]) + _mm_shuffle_ps(v54, v54, 170).m128_f32[0]) * (float)((float)(_mm_shuffle_ps(v58, v58, 85).m128_f32[0] + _mm_shuffle_ps(v58, v58, 0).m128_f32[0]) + _mm_shuffle_ps(v58, v58, 170).m128_f32[0]))];
          v44 = v43[2].m128_u32[1];
        }
        while ( (_DWORD)v44 );
      }
      v59 = (signed __int64)(v42 - (unsigned __int64)v10->m_nodes.m_data) / 48;
      v60 = v43[2].m128_i32[0];
      if ( v60 )
        v10->m_nodes.m_data[v60].m_children[v10->m_nodes.m_data[v60].m_children[1] == (unsigned int)(((char *)v43 - (char *)v10->m_nodes.m_data) / 48)] = v59;
      else
        v10[1].m_nodes.m_size = v59;
      *(_DWORD *)(v42 + 32) = v43[2].m128_i32[0];
      v61 = (char *)v43 - (char *)v10->m_nodes.m_data;
      *(_DWORD *)(v42 + 40) = v16;
      *(_DWORD *)(v42 + 36) = v61 / 48;
      v43[2].m128_i32[0] = v59;
      v10->m_nodes.m_data[v16].m_parent = v59;
      v62 = _mm_max_ps(v43[1], v39);
      *(__m128 *)v42 = _mm_min_ps(*v43, v38);
      *(__m128 *)(v42 + 16) = v62;
    }
    else
    {
      v10[1].m_nodes.m_size = v16;
      v37[v16].m_parent = 0;
    }
    goto LABEL_46;
  }
}ata;
      *(_DWORD *)(v42 + 40) = v16;
      *(_DWORD *)(v42 + 36) = v61 

// File Line: 805
// RVA: 0xDAB2A0
void __fastcall hkpTreeBroadPhase32::updateHandlesStandalone(
        hkpTreeBroadPhase32 *this,
        hkpBroadPhaseHandle *const *handles,
        hkAabb *aabbs,
        int count,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *addPairs,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *remPairs)
{
  unsigned int v6; // xmm0_4
  hkVector4f v7; // xmm14
  __int64 v8; // r12
  __m128 v9; // xmm13
  __m128 v10; // xmm14
  hkVector4f v13; // xmm3
  hkVector4f v14; // xmm4
  hkpTreeBroadPhase32::Handle *v15; // r9
  unsigned int v16; // edx
  unsigned int v17; // r8d
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint> *v18; // rbx
  __int64 v19; // rcx
  hkArray<hkcdDynamicTree::CodecRawUint,hkContainerHeapAllocator> v20; // xmm2
  __m128 v21; // xmm1
  __int64 m_size; // r10
  __int64 v23; // r8
  __int64 v24; // r14
  char *v25; // rcx
  __m128 v26; // xmm1
  __m128 v27; // xmm1
  hkArray<hkcdDynamicTree::CodecRawUint,hkContainerHeapAllocator> v28; // xmm7
  __m128 v29; // xmm8
  __int64 v30; // rdi
  __int64 v31; // r9
  int v32; // eax
  __int64 v33; // r8
  unsigned int *v34; // r11
  __int64 v35; // r8
  hkcdDynamicTree::CodecRawUint *m_data; // r9
  __int64 v37; // rcx
  __int64 v38; // r10
  __int64 v39; // rdi
  __m128 *p_m_quad; // r8
  __m128 v41; // xmm2
  __m128 v42; // xmm1
  unsigned __int64 v43; // rcx
  hkcdDynamicTree::CodecRawUint *v44; // rax
  __int64 v45; // rsi
  hkcdDynamicTree::CodecRawUint *v46; // rax
  __m128 m_quad; // xmm9
  __m128 v48; // xmm10
  __int64 m_firstFree; // rdx
  hkcdDynamicTree::CodecRawUint *v50; // r8
  __int64 v51; // r11
  __m128 *v52; // r9
  __int64 v53; // rax
  __m128 v54; // xmm11
  __m128 v55; // xmm12
  hkpTreeBroadPhaseInternals::UpdatePairsQuery *v56; // r8
  __m128 v57; // xmm0
  __m128 v58; // xmm1
  __int64 v59; // rdx
  hkcdDynamicTree::CodecRawUint *v60; // rdx
  __m128 v61; // xmm6
  __m128 v62; // xmm2
  __m128 v63; // xmm3
  __m128 v64; // xmm5
  __m128 v65; // xmm2
  __m128 v66; // xmm3
  __m128 v67; // xmm6
  __m128 v68; // xmm2
  __m128 v69; // xmm5
  __m128 v70; // xmm5
  __int64 v71; // r10
  int v72; // eax
  int v73; // eax
  signed __int64 v74; // rcx
  __m128 v75; // xmm1
  hkcdDynamicTree::CodecRawUint *v76; // rsi
  __int64 v77; // r9
  __int64 v78; // r8
  hkArray<hkcdDynamicTree::CodecRawUint,hkContainerHeapAllocator> v79; // xmm3
  __m128 v80; // xmm4
  int v81; // r14d
  __int64 v82; // rdi
  __m128 v83; // xmm5
  __m128 v84; // xmm6
  hkcdDynamicTree::CodecRawUint *v85; // rdx
  unsigned int m_parent; // eax
  hkcdDynamicTree::CodecRawUint *v87; // r8
  unsigned int *p_m_parent; // r11
  __int64 v89; // r8
  hkcdDynamicTree::CodecRawUint *v90; // r8
  __int64 v91; // rcx
  __int64 v92; // r9
  __m128 *v93; // rdx
  __m128 v94; // xmm2
  __m128 v95; // xmm1
  signed __int64 v96; // rcx
  hkcdDynamicTree::CodecRawUint *v97; // rax
  hkcdDynamicTree::CodecRawUint *v98; // rax
  __int64 v99; // rsi
  __m128 v100; // xmm7
  __m128 v101; // xmm8
  __int64 v102; // rdx
  __m128 *v103; // r9
  __int64 v104; // r11
  __int64 v105; // rax
  __m128 v106; // xmm9
  __m128 v107; // xmm10
  __int64 v108; // r8
  __m128 v109; // xmm0
  __m128 v110; // xmm1
  __int64 v111; // rdx
  __m128 *v112; // rdx
  __m128 v113; // xmm2
  __m128 v114; // xmm3
  __m128 v115; // xmm2
  __m128 v116; // xmm2
  __m128 v117; // xmm6
  __m128 v118; // xmm5
  __m128 v119; // xmm5
  __int64 v120; // r10
  int v121; // eax
  signed __int64 v122; // rcx
  __m128 v123; // xmm1
  int v124; // ebx
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *v125; // rdi
  hkpTreeBroadPhaseInternals::UpdatePairsQuery *v126[2]; // [rsp+20h] [rbp-C0h]
  __int64 v127[2]; // [rsp+30h] [rbp-B0h]
  hkAabb newAabb; // [rsp+40h] [rbp-A0h] BYREF
  hkpTreeBroadPhaseSpatialTree32 tree; // [rsp+60h] [rbp-80h] BYREF
  hkpBroadPhaseHandle *const *v130; // [rsp+158h] [rbp+78h]
  void *retaddr; // [rsp+168h] [rbp+88h] BYREF
  unsigned __int64 result; // [rsp+170h] [rbp+90h] BYREF
  __int64 v133; // [rsp+178h] [rbp+98h]

  v133 = (__int64)handles;
  v6 = this->m_parameters.m_quad.m128_u32[0];
  newAabb.m_min.m_quad.m128_u64[1] = result;
  LODWORD(retaddr) = v6;
  v7.m_quad = (__m128)this->m_offsetAndTimeStep;
  newAabb.m_max.m_quad.m128_u64[0] = (unsigned __int64)handles;
  v8 = 0i64;
  v9 = _mm_shuffle_ps((__m128)v6, (__m128)v6, 0);
  v10 = _mm_shuffle_ps(v7.m_quad, v7.m_quad, 255);
  newAabb.m_min.m_quad.m128_u64[0] = 0i64;
  v133 = count;
  if ( count > 0 )
  {
    while ( 1 )
    {
      v13.m_quad = (__m128)aabbs->m_min;
      v14.m_quad = (__m128)aabbs->m_max;
      v15 = &this->m_handles[0].m_data[handles[v8]->m_id];
      v16 = *((_DWORD *)v15 + 2);
      v17 = v16 & 0x1FFFFFF ^ ((v16 & 0xFE000000) + 0x2000000);
      v18 = (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint> *)&this->m_internals[3 * ((v16 >> 21) & 0xF)];
      v19 = (__int64)&v18->m_nodes.m_data[v16 & 0x1FFFFF];
      v20 = *(hkArray<hkcdDynamicTree::CodecRawUint,hkContainerHeapAllocator> *)v19;
      v21 = *(__m128 *)(v19 + 16);
      *((_DWORD *)v15 + 2) = v17;
      tree.m_nodes = v20;
      *(__m128 *)&tree.m_firstFree = v21;
      if ( (v17 & 0xFE000000) == 0 || (v17 & 0x1E00000) != 6291456 )
        break;
      if ( (_mm_movemask_ps(_mm_or_ps(_mm_cmplt_ps(v21, v14.m_quad), _mm_cmplt_ps(v13.m_quad, (__m128)v20))) & 7) != 0 )
      {
        m_size = v18[1].m_nodes.m_size;
        v23 = v17 & 0x1FFFFF;
        v24 = (unsigned int)v23;
        v25 = (char *)v15->m_bpHandle + SBYTE1(v15->m_bpHandle[1].m_id);
        v26 = _mm_mul_ps(*(__m128 *)&v25[v25[32] + 560], v10);
        v27 = _mm_shuffle_ps(v26, _mm_unpackhi_ps(v26, v9), 196);
        v28 = (hkArray<hkcdDynamicTree::CodecRawUint,hkContainerHeapAllocator>)_mm_min_ps(
                                                                                 _mm_add_ps(v13.m_quad, v27),
                                                                                 v13.m_quad);
        v29 = _mm_max_ps(_mm_add_ps(v14.m_quad, v27), v14.m_quad);
        if ( (_DWORD)v23 == (_DWORD)m_size )
        {
          v18[1].m_nodes.m_size = 0;
        }
        else
        {
          v30 = (__int64)&v18->m_nodes.m_data[v23];
          v31 = (__int64)&v18->m_nodes.m_data[*(unsigned int *)(v30 + 32)];
          v32 = *(_DWORD *)(v31 + 32);
          v33 = (__int64)&v18->m_nodes.m_data[*(unsigned int *)(v31
                                                              + 4 * (10i64 - (*(_DWORD *)(v31 + 40) == (_DWORD)v23)))];
          if ( v32 )
          {
            *(_DWORD *)(v33 + 32) = v32;
            v34 = (unsigned int *)(v33 + 32);
            v18->m_nodes.m_data[*(unsigned int *)(v31 + 32)].m_children[v18->m_nodes.m_data[*(unsigned int *)(v31 + 32)].m_children[1] == *(_DWORD *)(v30 + 32)] = ((int)v33 - LODWORD(v18->m_nodes.m_data)) / 48;
            v35 = *(int *)(v30 + 32);
            v18->m_nodes.m_data[v35].m_aabb.m_min.m_quad.m128_i32[0] = v18->m_firstFree;
            m_data = v18->m_nodes.m_data;
            v18->m_firstFree = v35;
            v37 = (__int64)&m_data[*v34];
            while ( 1 )
            {
              v38 = *(unsigned int *)(v37 + 32);
              v39 = (v37 - (__int64)m_data) / 48;
              p_m_quad = &m_data[((int)v37 - (int)m_data) / 48].m_aabb.m_min.m_quad;
              v41 = _mm_min_ps(
                      m_data[p_m_quad[2].m128_u32[1]].m_aabb.m_min.m_quad,
                      m_data[p_m_quad[2].m128_u32[2]].m_aabb.m_min.m_quad);
              v42 = _mm_max_ps(
                      m_data[p_m_quad[2].m128_u32[1]].m_aabb.m_max.m_quad,
                      m_data[p_m_quad[2].m128_u32[2]].m_aabb.m_max.m_quad);
              *p_m_quad = v41;
              p_m_quad[1] = v42;
              if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v29, v42), _mm_cmple_ps(v41, (__m128)v28))) & 7) == 7 )
                break;
              if ( (_DWORD)v38 )
              {
                m_data = v18->m_nodes.m_data;
                v37 = (__int64)&v18->m_nodes.m_data[v38];
                if ( v37 )
                  continue;
              }
              goto LABEL_14;
            }
LABEL_15:
            v44 = v18->m_nodes.m_data;
            v45 = v24;
            v44[v45].m_aabb.m_min = (hkVector4f)v28;
            v44[v45].m_aabb.m_max.m_quad = v29;
            v46 = v18->m_nodes.m_data;
            m_quad = v18->m_nodes.m_data[v24].m_aabb.m_min.m_quad;
            v48 = v18->m_nodes.m_data[v24].m_aabb.m_max.m_quad;
            if ( (_DWORD)v39 )
            {
              if ( !v18->m_firstFree )
                hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
                  v18,
                  (hkResult *)&retaddr,
                  1);
              m_firstFree = v18->m_firstFree;
              v50 = v18->m_nodes.m_data;
              v51 = (__int64)&v18->m_nodes.m_data[m_firstFree];
              v18->m_firstFree = v18->m_nodes.m_data[(int)m_firstFree].m_aabb.m_min.m_quad.m128_u32[0];
              v52 = &v50[(unsigned int)v39].m_aabb.m_min.m_quad;
              v53 = v52[2].m128_u32[1];
              if ( (_DWORD)v53 )
              {
                v54 = _mm_add_ps(v48, m_quad);
                v55 = _mm_sub_ps(v48, m_quad);
                do
                {
                  v57 = _mm_min_ps(*v52, m_quad);
                  v58 = _mm_max_ps(v52[1], v48);
                  v59 = v52[2].m128_u32[2];
                  v126[0] = (hkpTreeBroadPhaseInternals::UpdatePairsQuery *)&v18->m_nodes.m_data[v53];
                  v56 = v126[0];
                  v60 = &v18->m_nodes.m_data[v59];
                  v126[1] = (hkpTreeBroadPhaseInternals::UpdatePairsQuery *)v60;
                  *v52 = v57;
                  v52[1] = v58;
                  v61 = v60->m_aabb.m_max.m_quad;
                  v62 = *(__m128 *)&v56->m_remPairsOut;
                  v63 = _mm_sub_ps(v62, *(__m128 *)&v56->m_handles);
                  v64 = _mm_add_ps(v60->m_aabb.m_min.m_quad, v61);
                  v65 = _mm_sub_ps(_mm_add_ps(v62, *(__m128 *)&v56->m_handles), v54);
                  v66 = _mm_add_ps(v63, v55);
                  v67 = _mm_add_ps(_mm_sub_ps(v61, v60->m_aabb.m_min.m_quad), v55);
                  v68 = _mm_mul_ps(v65, v65);
                  v69 = _mm_sub_ps(v64, v54);
                  v70 = _mm_mul_ps(v69, v69);
                  v52 = (__m128 *)v126[(float)((float)((float)(_mm_shuffle_ps(v68, v68, 85).m128_f32[0]
                                                             + _mm_shuffle_ps(v68, v68, 0).m128_f32[0])
                                                     + _mm_shuffle_ps(v68, v68, 170).m128_f32[0])
                                             * (float)((float)(_mm_shuffle_ps(v66, v66, 85).m128_f32[0]
                                                             + _mm_shuffle_ps(v66, v66, 0).m128_f32[0])
                                                     + _mm_shuffle_ps(v66, v66, 170).m128_f32[0])) > (float)((float)((float)(_mm_shuffle_ps(v70, v70, 85).m128_f32[0] + _mm_shuffle_ps(v70, v70, 0).m128_f32[0]) + _mm_shuffle_ps(v70, v70, 170).m128_f32[0]) * (float)((float)(_mm_shuffle_ps(v67, v67, 85).m128_f32[0] + _mm_shuffle_ps(v67, v67, 0).m128_f32[0]) + _mm_shuffle_ps(v67, v67, 170).m128_f32[0]))];
                  v53 = v52[2].m128_u32[1];
                }
                while ( (_DWORD)v53 );
              }
              v71 = (signed __int64)(v51 - (unsigned __int64)v18->m_nodes.m_data) / 48;
              v72 = v52[2].m128_i32[0];
              if ( v72 )
                v18->m_nodes.m_data[v72].m_children[v18->m_nodes.m_data[v72].m_children[1] == (unsigned int)(((char *)v52 - (char *)v18->m_nodes.m_data) / 48)] = v71;
              else
                v18[1].m_nodes.m_size = v71;
              v73 = v52[2].m128_i32[0];
              tree.m_nodes = v28;
              *(_DWORD *)(v51 + 32) = v73;
              v74 = (char *)v52 - (char *)v18->m_nodes.m_data;
              *(_DWORD *)(v51 + 40) = v24;
              *(__m128 *)&tree.m_firstFree = v29;
              *(_DWORD *)(v51 + 36) = v74 / 48;
              v52[2].m128_i32[0] = v71;
              v18->m_nodes.m_data[v24].m_parent = v71;
              v75 = _mm_max_ps(v52[1], v48);
              *(__m128 *)v51 = _mm_min_ps(*v52, m_quad);
              *(__m128 *)(v51 + 16) = v75;
            }
            else
            {
              v18[1].m_nodes.m_size = v24;
              tree.m_nodes = v28;
              *(__m128 *)&tree.m_firstFree = v29;
              v46[v24].m_parent = 0;
            }
LABEL_46:
            v124 = 1;
            v125 = (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)&this->m_internals[3];
            newAabb.m_max.m_quad.m128_u64[1] = (unsigned __int64)v130[v8];
            do
            {
              newAabb.m_min.m_quad.m128_u64[0] = (unsigned __int64)this->m_handles[v124 == 4].m_data;
              hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::kineticAabbOverlaps<hkpTreeBroadPhaseSpatialTree32,hkpTreeBroadPhaseInternals::UpdatePairsQuery>(
                v125,
                &tree,
                (hkAabb *)&tree,
                &newAabb,
                v126[0]);
              ++v124;
              v125 += 48;
            }
            while ( v124 <= 3 );
            goto LABEL_48;
          }
          v18->m_nodes.m_data[m_size].m_aabb.m_min.m_quad.m128_i32[0] = v18->m_firstFree;
          v43 = v33 - (unsigned __int64)v18->m_nodes.m_data;
          v18->m_firstFree = m_size;
          v18[1].m_nodes.m_size = (int)v43 / 48;
          *(_DWORD *)(v33 + 32) = 0;
        }
LABEL_14:
        LODWORD(v39) = v18[1].m_nodes.m_size;
        goto LABEL_15;
      }
LABEL_48:
      handles = v130;
      ++v8;
      ++aabbs;
      if ( v8 >= v133 )
        return;
    }
    v76 = v18->m_nodes.m_data;
    v77 = v18[1].m_nodes.m_size;
    v78 = v17 & 0x1FFFFF;
    v79 = (hkArray<hkcdDynamicTree::CodecRawUint,hkContainerHeapAllocator>)_mm_sub_ps(v13.m_quad, v9);
    v80 = _mm_add_ps(v14.m_quad, v9);
    v81 = v78;
    tree.m_nodes = v79;
    *(__m128 *)&tree.m_firstFree = v80;
    v82 = v78;
    v83 = v76[v78].m_aabb.m_min.m_quad;
    v84 = v76[v78].m_aabb.m_max.m_quad;
    if ( (_DWORD)v78 == (_DWORD)v77 )
    {
      v18[1].m_nodes.m_size = 0;
    }
    else
    {
      v85 = &v76[v76[v78].m_parent];
      m_parent = v85->m_parent;
      v87 = &v76[v85->m_aabb.m_min.m_quad.m128_u32[10i64 - (v85->m_children[1] == (_DWORD)v78)]];
      if ( m_parent )
      {
        v87->m_parent = m_parent;
        p_m_parent = &v87->m_parent;
        v18->m_nodes.m_data[v85->m_parent].m_children[v18->m_nodes.m_data[v85->m_parent].m_children[1] == v76[v82].m_parent] = ((int)v87 - LODWORD(v18->m_nodes.m_data)) / 48;
        v89 = (int)v76[v82].m_parent;
        v18->m_nodes.m_data[v89].m_aabb.m_min.m_quad.m128_i32[0] = v18->m_firstFree;
        v18->m_firstFree = v89;
        v90 = v18->m_nodes.m_data;
        v91 = (__int64)&v18->m_nodes.m_data[*p_m_parent];
        do
        {
          v92 = *(unsigned int *)(v91 + 32);
          v93 = &v90[((int)v91 - (int)v90) / 48].m_aabb.m_min.m_quad;
          v94 = _mm_min_ps(v90[v93[2].m128_u32[1]].m_aabb.m_min.m_quad, v90[v93[2].m128_u32[2]].m_aabb.m_min.m_quad);
          v95 = _mm_max_ps(v90[v93[2].m128_u32[1]].m_aabb.m_max.m_quad, v90[v93[2].m128_u32[2]].m_aabb.m_max.m_quad);
          *v93 = v94;
          v93[1] = v95;
          if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v84, v95), _mm_cmple_ps(v94, v83))) & 7) == 7 )
            break;
          if ( !(_DWORD)v92 )
            break;
          v90 = v18->m_nodes.m_data;
          v91 = (__int64)&v18->m_nodes.m_data[v92];
        }
        while ( v91 );
      }
      else
      {
        v76[v77].m_aabb.m_min.m_quad.m128_i32[0] = v18->m_firstFree;
        v96 = (char *)v87 - (char *)v18->m_nodes.m_data;
        v18->m_firstFree = v77;
        v18[1].m_nodes.m_size = v96 / 48;
        v87->m_parent = 0;
      }
    }
    v97 = v18->m_nodes.m_data;
    v97[v82].m_aabb.m_min = (hkVector4f)v79;
    v97[v82].m_aabb.m_max.m_quad = v80;
    v98 = v18->m_nodes.m_data;
    v99 = (unsigned int)v18[1].m_nodes.m_size;
    v100 = v18->m_nodes.m_data[v82].m_aabb.m_min.m_quad;
    v101 = v18->m_nodes.m_data[v82].m_aabb.m_max.m_quad;
    if ( (_DWORD)v99 )
    {
      if ( !v18->m_firstFree )
        hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
          v18,
          (hkResult *)&result,
          1);
      v102 = v18->m_firstFree;
      v103 = &v18->m_nodes.m_data[v99].m_aabb.m_min.m_quad;
      v104 = (__int64)&v18->m_nodes.m_data[v102];
      v18->m_firstFree = v18->m_nodes.m_data[(int)v102].m_aabb.m_min.m_quad.m128_u32[0];
      v105 = v103[2].m128_u32[1];
      if ( (_DWORD)v105 )
      {
        v106 = _mm_add_ps(v101, v100);
        v107 = _mm_sub_ps(v101, v100);
        do
        {
          v109 = _mm_min_ps(*v103, v100);
          v110 = _mm_max_ps(v103[1], v101);
          v111 = v103[2].m128_u32[2];
          v127[0] = (__int64)&v18->m_nodes.m_data[v105];
          v108 = v127[0];
          v112 = &v18->m_nodes.m_data[v111].m_aabb.m_min.m_quad;
          v127[1] = (__int64)v112;
          *v103 = v109;
          v103[1] = v110;
          v113 = *(__m128 *)(v108 + 16);
          v114 = _mm_add_ps(_mm_sub_ps(v113, *(__m128 *)v108), v107);
          v115 = _mm_sub_ps(_mm_add_ps(v113, *(__m128 *)v108), v106);
          v116 = _mm_mul_ps(v115, v115);
          v117 = _mm_add_ps(_mm_sub_ps(v112[1], *v112), v107);
          v118 = _mm_sub_ps(_mm_add_ps(v112[1], *v112), v106);
          v119 = _mm_mul_ps(v118, v118);
          v103 = (__m128 *)v127[(float)((float)((float)(_mm_shuffle_ps(v116, v116, 85).m128_f32[0]
                                                      + _mm_shuffle_ps(v116, v116, 0).m128_f32[0])
                                              + _mm_shuffle_ps(v116, v116, 170).m128_f32[0])
                                      * (float)((float)(_mm_shuffle_ps(v114, v114, 85).m128_f32[0]
                                                      + _mm_shuffle_ps(v114, v114, 0).m128_f32[0])
                                              + _mm_shuffle_ps(v114, v114, 170).m128_f32[0])) > (float)((float)((float)(_mm_shuffle_ps(v119, v119, 85).m128_f32[0] + _mm_shuffle_ps(v119, v119, 0).m128_f32[0]) + _mm_shuffle_ps(v119, v119, 170).m128_f32[0]) * (float)((float)(_mm_shuffle_ps(v117, v117, 85).m128_f32[0] + _mm_shuffle_ps(v117, v117, 0).m128_f32[0]) + _mm_shuffle_ps(v117, v117, 170).m128_f32[0]))];
          v105 = v103[2].m128_u32[1];
        }
        while ( (_DWORD)v105 );
      }
      v120 = (signed __int64)(v104 - (unsigned __int64)v18->m_nodes.m_data) / 48;
      v121 = v103[2].m128_i32[0];
      if ( v121 )
        v18->m_nodes.m_data[v121].m_children[v18->m_nodes.m_data[v121].m_children[1] == (unsigned int)(((char *)v103 - (char *)v18->m_nodes.m_data) / 48)] = v120;
      else
        v18[1].m_nodes.m_size = v120;
      *(_DWORD *)(v104 + 32) = v103[2].m128_i32[0];
      v122 = (char *)v103 - (char *)v18->m_nodes.m_data;
      *(_DWORD *)(v104 + 40) = v81;
      *(_DWORD *)(v104 + 36) = v122 / 48;
      v103[2].m128_i32[0] = v120;
      v18->m_nodes.m_data[v82].m_parent = v120;
      v123 = _mm_max_ps(v103[1], v101);
      *(__m128 *)v104 = _mm_min_ps(*v103, v100);
      *(__m128 *)(v104 + 16) = v123;
    }
    else
    {
      v18[1].m_nodes.m_size = v81;
      v98[v82].m_parent = 0;
    }
    goto LABEL_46;
  }
}s.m_size = v81;
      v98[v82].m_parent = 0;
    }
    goto LABEL_46;
  }
}

// File Line: 834
// RVA: 0xDAC550
void __fastcall hkpTreeBroadPhase32::updateHandlesMapping(hkpTreeBroadPhase32 *this)
{
  int v1; // edi
  __int64 m_size; // rcx
  __int64 v4; // rbx
  hkRelocationInfo::Import *v5; // r10
  int v6; // eax
  __int64 v7; // rcx
  __int64 v8; // rdx
  hkRelocationInfo::Import *v9; // rax
  __int64 v10; // r9
  hkpTreeBroadPhase32::Handle *m_data; // rdx
  hkpBroadPhaseHandle *m_bpHandle; // rax
  __int64 m_id; // rcx
  const char *v14; // rax
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> v15; // [rsp+20h] [rbp-28h] BYREF
  __int64 v16; // [rsp+38h] [rbp-10h]
  int v17; // [rsp+50h] [rbp+8h] BYREF

  v1 = 0;
  m_size = this->m_handles[0].m_size;
  LODWORD(v16) = 0;
  v4 = m_size;
  if ( (_DWORD)m_size )
  {
    v17 = 16 * m_size;
    v5 = (hkRelocationInfo::Import *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                       &hkContainerHeapAllocator::s_alloc,
                                       &v17);
    LODWORD(m_size) = v17 / 16;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = 0x80000000;
  v15.m_data = v5;
  if ( (_DWORD)m_size )
    v6 = m_size;
  v15.m_size = v4;
  v7 = v4;
  v15.m_capacityAndFlags = v6;
  if ( (int)v4 > 0 )
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
  if ( this->m_handles[0].m_size > 0 )
  {
    v10 = 0i64;
    do
    {
      m_data = this->m_handles[0].m_data;
      m_bpHandle = m_data[v10].m_bpHandle;
      if ( m_bpHandle )
      {
        m_id = (int)m_bpHandle->m_id;
        *(_QWORD *)&v5[m_id].m_fromOffset = m_bpHandle;
        v14 = (const char *)*((_QWORD *)&m_data[v10] + 1);
        v5[m_id].m_identifier = v14;
        *(_DWORD *)(this->m_internals[3 * (((unsigned int)v14 >> 21) & 0xF)].m_real.m128_u64[0]
                  + 48i64 * ((unsigned int)v14 & 0x1FFFFF)
                  + 40) = **(_DWORD **)&v5[m_id].m_fromOffset;
      }
      ++v1;
      ++v10;
    }
    while ( v1 < this->m_handles[0].m_size );
  }
  for ( ; (int)v4 > 1; v15.m_size = v4 )
  {
    if ( *(_QWORD *)&v5[(int)v4 - 1].m_fromOffset )
      break;
    LODWORD(v4) = v4 - 1;
  }
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    &v15,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)this->m_handles);
  if ( v15.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v15.m_data,
      16 * v15.m_capacityAndFlags);
}

// File Line: 853
// RVA: 0xD9F280
void __fastcall hkpTreeBroadPhase::indexAndCompact(hkpTreeBroadPhase *this, unsigned int count)
{
  hkpTreeBroadPhase::Handle *v3; // rax
  __int64 v4; // r10
  hkpBroadPhaseHandle *m_bpHandle; // rcx
  hkpTreeBroadPhase::Handle *v6; // r8
  unsigned __int64 v7; // rcx

  v3 = &this->m_handles[0].m_data[this->m_handles[0].m_size - count];
  if ( (int)count <= 0 )
  {
    this->m_handles[0].m_size -= count;
  }
  else
  {
    v4 = count;
    do
    {
      m_bpHandle = v3->m_bpHandle;
      if ( v3->m_bpHandle )
      {
        v6 = &this->m_handles[0].m_data[m_bpHandle->m_id];
        v6->m_bpHandle = m_bpHandle;
        v7 = *((_QWORD *)v3 + 1);
        *((_QWORD *)v6 + 1) = v7;
        *(_WORD *)(this->m_internals[3 * ((v7 >> 21) & 0xF)].m_real.m128_u64[0]
                 + 32i64 * *((unsigned __int16 *)v6 + 4)
                 + 30) = v6->m_bpHandle->m_id;
      }
      ++v3;
      --v4;
    }
    while ( v4 );
    this->m_handles[0].m_size -= count;
  }
}

// File Line: 870
// RVA: 0xDA8590
hkpTreeBroadPhase32 *__fastcall hkpTreeBroadPhase32::getCapabilityDelegate(
        hkpTreeBroadPhase32 *this,
        hkpBroadPhase::Capabilities cap)
{
  hkpBroadPhase *m_childBroadPhase; // rcx

  if ( (cap & this->m_caps) != 0 )
    return this;
  m_childBroadPhase = this->m_childBroadPhase;
  if ( m_childBroadPhase )
    return (hkpTreeBroadPhase32 *)((__int64 (__fastcall *)(hkpBroadPhase *))m_childBroadPhase->vfptr[2].__vecDelDtor)(m_childBroadPhase);
  else
    return 0i64;
}

// File Line: 888
// RVA: 0xD9AF30
__int64 __fastcall hkpTreeBroadPhase::getNumObjects(hkpTreeBroadPhase *this)
{
  hkpBroadPhase *m_childBroadPhase; // rdx

  m_childBroadPhase = this->m_childBroadPhase;
  if ( m_childBroadPhase )
    return ((__int64 (__fastcall *)(hkpBroadPhase *))m_childBroadPhase->vfptr[5].__vecDelDtor)(this->m_childBroadPhase);
  else
    return (unsigned int)(this->m_internals[1].m_real.m128_i32[2]
                        + this->m_internals[4].m_real.m128_i32[2]
                        + this->m_internals[7].m_real.m128_i32[2]
                        + this->m_internals[10].m_real.m128_i32[2]
                        + this->m_internals[13].m_real.m128_i32[2]);
}

// File Line: 903
// RVA: 0xD9AF70
void __fastcall hkpTreeBroadPhase::getAllAabbs(
        hkpTreeBroadPhase *this,
        hkArray<hkAabb,hkContainerHeapAllocator> *allAabbs)
{
  hkpBroadPhase *m_childBroadPhase; // rcx
  hkSimdFloat32 *m_internals; // r14
  __int64 v6; // r15
  unsigned __int16 v7; // bp
  __int64 v8; // rdi
  unsigned __int16 v9; // bx
  __int64 v10; // rdi
  hkAabb *v11; // rcx
  unsigned __int64 v12; // rax
  unsigned __int64 v13; // rdx
  int i; // eax
  __int64 v15; // rcx
  unsigned __int16 v16; // r8
  hkAabb *v17; // rcx
  unsigned __int64 v18; // rax

  m_childBroadPhase = this->m_childBroadPhase;
  if ( m_childBroadPhase )
  {
    m_childBroadPhase->vfptr[7].__first_virtual_table_function__(m_childBroadPhase);
  }
  else
  {
    allAabbs->m_size = 0;
    m_internals = this->m_internals;
    v6 = 5i64;
    do
    {
      v7 = m_internals[2].m_real.m128_u16[0];
      if ( v7 )
      {
        v8 = 32i64 * v7;
        v9 = *(_WORD *)(v8 + m_internals->m_real.m128_u64[0] + 28);
        if ( v9 )
        {
          do
          {
            v10 = 32i64 * v9;
            if ( !*(_WORD *)(v10 + m_internals->m_real.m128_u64[0] + 28) )
            {
              if ( allAabbs->m_size == (allAabbs->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&allAabbs->m_data, 32);
              v11 = &allAabbs->m_data[allAabbs->m_size++];
              v12 = m_internals->m_real.m128_u64[0];
              v11->m_max.m_quad = _mm_shuffle_ps(
                                    *(__m128 *)(v10 + m_internals->m_real.m128_u64[0] + 16),
                                    _mm_unpackhi_ps(
                                      *(__m128 *)(v10 + m_internals->m_real.m128_u64[0] + 16),
                                      (__m128)0i64),
                                    196);
              v11->m_min = *(hkVector4f *)(v10 + v12);
            }
            v13 = m_internals->m_real.m128_u64[0];
            if ( *(_WORD *)(m_internals->m_real.m128_u64[0] + v10 + 28) )
            {
              v9 = *(_WORD *)(m_internals->m_real.m128_u64[0] + v10 + 28);
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
              if ( (_WORD)i == v7 && v16 == v9 )
                v9 = 0;
              else
                v9 = v16;
            }
          }
          while ( v9 );
        }
        else
        {
          if ( allAabbs->m_size == (allAabbs->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&allAabbs->m_data, 32);
          v17 = &allAabbs->m_data[allAabbs->m_size++];
          v18 = m_internals->m_real.m128_u64[0];
          v17->m_max.m_quad = _mm_shuffle_ps(
                                *(__m128 *)(v8 + m_internals->m_real.m128_u64[0] + 16),
                                _mm_unpackhi_ps(*(__m128 *)(v8 + m_internals->m_real.m128_u64[0] + 16), (__m128)0i64),
                                196);
          v17->m_min = *(hkVector4f *)(v8 + v18);
        }
      }
      m_internals += 3;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 918
// RVA: 0xDA87D0
void __fastcall hkpTreeBroadPhase32::getExtents(
        hkpTreeBroadPhase32 *this,
        hkVector4f *worldMinOut,
        hkVector4f *worldMaxOut)
{
  hkpBroadPhase *m_childBroadPhase; // rcx
  hkSimdFloat32 *v7; // rdx
  __int64 v8; // r8
  __m128 v9; // xmm3
  __m128 v10; // xmm5
  __m128 v11; // xmm2
  __int64 v12; // rax
  __m128 *v13; // rcx
  __m128 v14; // xmm1
  __m128 v15; // xmm0

  m_childBroadPhase = this->m_childBroadPhase;
  if ( m_childBroadPhase )
  {
    ((void (__fastcall *)(hkpBroadPhase *, hkVector4f *, hkVector4f *, hkVector4f *))m_childBroadPhase->vfptr[8].__first_virtual_table_function__)(
      m_childBroadPhase,
      worldMinOut,
      worldMaxOut,
      worldMaxOut);
  }
  else
  {
    v7 = &this->m_internals[2];
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
    *worldMinOut = (hkVector4f)v9;
    *worldMaxOut = (hkVector4f)v11;
  }
}

// File Line: 938
// RVA: 0xDA8870
void __fastcall hkpTreeBroadPhase32::reQuerySingleObject(
        hkpTreeBroadPhase32 *this,
        hkpBroadPhaseHandle *object,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *pairs_out)
{
  hkpBroadPhase *m_childBroadPhase; // rcx
  hkAabb aabb; // [rsp+20h] [rbp-28h] BYREF

  m_childBroadPhase = this->m_childBroadPhase;
  if ( m_childBroadPhase )
  {
    m_childBroadPhase->vfptr[9].__first_virtual_table_function__(m_childBroadPhase);
  }
  else
  {
    ((void (__fastcall *)(hkpTreeBroadPhase32 *, hkpBroadPhaseHandle *, hkAabb *))this->vfptr[8].__vecDelDtor)(
      this,
      object,
      &aabb);
    hkpTreeBroadPhase32::querySingleAabb(this, &aabb, object, pairs_out);
  }
}

// File Line: 952
// RVA: 0xD9B2B0
void __fastcall hkpTreeBroadPhase::querySingleAabbWithCollector(
        hkpTreeBroadPhase *this,
        hkAabb *aabb,
        hkpBroadPhaseCastCollector *collector)
{
  hkpBroadPhase *m_childBroadPhase; // rcx
  int v7; // edi
  __int64 v8; // rbx
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> array; // [rsp+30h] [rbp-18h] BYREF
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  m_childBroadPhase = this->m_childBroadPhase;
  if ( m_childBroadPhase )
  {
    ((void (__fastcall *)(hkpBroadPhase *))m_childBroadPhase->vfptr[10].__vecDelDtor)(m_childBroadPhase);
  }
  else
  {
    array.m_data = 0i64;
    array.m_size = 0;
    array.m_capacityAndFlags = 0x80000000;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, 32, 16);
    hkpTreeBroadPhase::querySingleAabb(this, aabb, 0i64, &array);
    v7 = 0;
    if ( array.m_size > 0 )
    {
      v8 = 0i64;
      do
      {
        collector->vfptr->addBroadPhaseHandle(collector, array.m_data[v8].m_b, 0);
        ++v7;
        ++v8;
      }
      while ( v7 < array.m_size );
    }
    array.m_size = 0;
    if ( array.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        array.m_data,
        16 * array.m_capacityAndFlags);
  }
}

// File Line: 967
// RVA: 0xDA8A00
void __fastcall hkpTreeBroadPhase32::shiftBroadPhase(
        hkpTreeBroadPhase32 *this,
        hkVector4f *shiftDistance,
        hkVector4f *effectiveShiftDistanceOut,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *newCollisionPairs)
{
  hkErrStream v5; // [rsp+20h] [rbp-228h] BYREF
  char buf[520]; // [rsp+40h] [rbp-208h] BYREF

  hkErrStream::hkErrStream(&v5, buf, 512);
  hkOstream::operator<<(&v5, "shiftBroadPhase is not supported by the tree broadphase");
  hkError::messageWarning(
    0xA2B0295F,
    buf,
    "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Physics2012/Internal/BroadPhase/TreeBroadPhase/hkpTreeBroadPhase.cpp",
    968);
  hkOstream::~hkOstream(&v5);
  *effectiveShiftDistanceOut = 0i64;
}

// File Line: 974
// RVA: 0xD9B430
void __fastcall hkpTreeBroadPhase::getOffsetLowHigh32bit(
        hkpTreeBroadPhase *this,
        hkVector4f *offsetLow32bit,
        hkVector4f *offsetHigh32bit)
{
  hkpBroadPhase *m_childBroadPhase; // r10

  m_childBroadPhase = this->m_childBroadPhase;
  if ( m_childBroadPhase )
  {
    m_childBroadPhase->vfptr[12].__vecDelDtor(this->m_childBroadPhase, (unsigned int)offsetHigh32bit);
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
  hkpBroadPhase *m_childBroadPhase; // rcx

  m_childBroadPhase = this->m_childBroadPhase;
  if ( m_childBroadPhase )
    return ((__int64 (__fastcall *)(hkpBroadPhase *))m_childBroadPhase->vfptr[13].__vecDelDtor)(m_childBroadPhase);
  else
    return 0i64;
}

// File Line: 1001
// RVA: 0xD9B490
void __fastcall hkpTreeBroadPhase::calcAabbCache(hkpTreeBroadPhase *this, hkAabb *aabb, char *aabbCacheOut)
{
  hkpBroadPhase *m_childBroadPhase; // rcx

  m_childBroadPhase = this->m_childBroadPhase;
  if ( m_childBroadPhase )
    ((void (__fastcall *)(hkpBroadPhase *, hkAabb *, char *))m_childBroadPhase->vfptr[14].__vecDelDtor)(
      m_childBroadPhase,
      aabb,
      aabbCacheOut);
}

// File Line: 1010
// RVA: 0xD9B4B0
void __fastcall hkpTreeBroadPhase::calcAabbCache(
        hkpTreeBroadPhase *this,
        hkArrayBase<hkpCollidable *> *overlappingCollidables,
        char *aabbCacheOut)
{
  hkpBroadPhase *m_childBroadPhase; // rcx

  m_childBroadPhase = this->m_childBroadPhase;
  if ( m_childBroadPhase )
    ((void (__fastcall *)(hkpBroadPhase *, hkArrayBase<hkpCollidable *> *, char *))m_childBroadPhase->vfptr[13].__first_virtual_table_function__)(
      m_childBroadPhase,
      overlappingCollidables,
      aabbCacheOut);
}

// File Line: 1019
// RVA: 0xD9B4D0
void __fastcall hkpTreeBroadPhase::getAabb(hkpTreeBroadPhase *this, hkpBroadPhaseHandle *object, hkAabb *aabb)
{
  hkpBroadPhase *m_childBroadPhase; // rcx
  __int64 m_id; // rcx
  unsigned __int64 v6; // rax
  unsigned __int64 v7; // rax
  hkVector4f *v8; // rcx

  m_childBroadPhase = this->m_childBroadPhase;
  if ( m_childBroadPhase && (object->m_id & 0x80000000) == 0 )
  {
    ((void (__fastcall *)(hkpBroadPhase *, hkpBroadPhaseHandle *, hkAabb *, hkpTreeBroadPhase *))m_childBroadPhase->vfptr[8].__vecDelDtor)(
      m_childBroadPhase,
      object,
      aabb,
      this);
  }
  else
  {
    m_id = object->m_id;
    v6 = (unsigned int)m_id;
    LODWORD(m_id) = m_id & 0x7FFFFFFF;
    v7 = *((unsigned int *)&this->m_handles[v6 >> 31].m_data[m_id] + 2);
    v8 = (hkVector4f *)(this->m_internals[3 * ((v7 >> 21) & 0xF)].m_real.m128_u64[0] + 32i64 * (unsigned __int16)v7);
    aabb->m_max.m_quad = _mm_shuffle_ps(v8[1].m_quad, _mm_unpackhi_ps(v8[1].m_quad, (__m128)0i64), 196);
    aabb->m_min = (hkVector4f)v8->m_quad;
  }
}

// File Line: 1033
// RVA: 0xD9B550
bool __fastcall hkpTreeBroadPhase::areAabbsOverlapping(
        hkpTreeBroadPhase *this,
        hkpBroadPhaseHandle *bhA,
        hkpBroadPhaseHandle *bhB)
{
  hkpBroadPhase *m_childBroadPhase; // rcx
  __m128 v7[2]; // [rsp+20h] [rbp-48h] BYREF
  __m128 v8[2]; // [rsp+40h] [rbp-28h] BYREF

  m_childBroadPhase = this->m_childBroadPhase;
  if ( m_childBroadPhase && (bhA->m_id & 0x80000000) == 0 && (bhB->m_id & 0x80000000) == 0 )
    return ((__int64 (__fastcall *)(hkpBroadPhase *))m_childBroadPhase->vfptr[10].__first_virtual_table_function__)(m_childBroadPhase);
  ((void (__fastcall *)(hkpTreeBroadPhase *, hkpBroadPhaseHandle *, __m128 *))this->vfptr[8].__vecDelDtor)(
    this,
    bhA,
    v7);
  ((void (__fastcall *)(hkpTreeBroadPhase *, hkpBroadPhaseHandle *, __m128 *))this->vfptr[8].__vecDelDtor)(
    this,
    bhB,
    v8);
  return (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v8[0], v7[1]), _mm_cmple_ps(v7[0], v8[1]))) & 7) == 7;
}

// File Line: 1048
// RVA: 0xDA8C30
void __fastcall hkpTreeBroadPhase32::addObject(
        hkpTreeBroadPhase32 *this,
        hkpBroadPhaseHandle *object,
        hkAabbUint32 *aabb,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *newPairs)
{
  hkpBroadPhase *m_childBroadPhase; // rcx
  hkVector4f v7; // xmm2
  hkVector4f v8; // xmm3
  hkVector4f v9; // xmm1
  __m128 v10; // xmm1
  hkVector4f v11; // xmm2
  hkVector4f v12; // xmm3
  char addPairs; // [rsp+20h] [rbp-38h]
  hkAabb aabbs; // [rsp+30h] [rbp-28h] BYREF
  hkpBroadPhaseHandle *handles; // [rsp+68h] [rbp+10h] BYREF

  handles = object;
  m_childBroadPhase = this->m_childBroadPhase;
  if ( m_childBroadPhase )
  {
    addPairs = 0;
    ((void (__fastcall *)(hkpBroadPhase *, hkpBroadPhaseHandle *, hkAabbUint32 *, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *, char))m_childBroadPhase->vfptr[3].__vecDelDtor)(
      m_childBroadPhase,
      object,
      aabb,
      newPairs,
      addPairs);
    v7.m_quad = (__m128)this->m_scale;
    v8.m_quad = (__m128)this->m_offsetAndTimeStep;
    v9.m_quad = _mm_add_ps(_mm_mul_ps(_mm_cvtepi32_ps(*(__m128i *)aabb->m_max), v7.m_quad), v8.m_quad);
    aabbs.m_min.m_quad = _mm_add_ps(_mm_mul_ps(_mm_cvtepi32_ps(*(__m128i *)aabb->m_min), v7.m_quad), v8.m_quad);
    aabbs.m_max = (hkVector4f)v9.m_quad;
    hkpTreeBroadPhase32::addHandles(this, &handles, &aabbs, 1);
  }
  else
  {
    v10 = _mm_cvtepi32_ps(*(__m128i *)aabb->m_max);
    v11.m_quad = (__m128)this->m_scale;
    v12.m_quad = (__m128)this->m_offsetAndTimeStep;
    aabbs.m_min.m_quad = _mm_add_ps(_mm_mul_ps(_mm_cvtepi32_ps(*(__m128i *)aabb->m_min), v11.m_quad), v12.m_quad);
    aabbs.m_max.m_quad = _mm_add_ps(_mm_mul_ps(v10, v11.m_quad), v12.m_quad);
    hkpTreeBroadPhase32::addHandlesStandalone(this, &handles, &aabbs, 1, newPairs);
  }
}

// File Line: 1070
// RVA: 0xDA8D10
void __fastcall hkpTreeBroadPhase32::addObject(
        hkpTreeBroadPhase32 *this,
        hkpBroadPhaseHandle *object,
        hkAabb *aabb,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *newPairs)
{
  hkpBroadPhase *m_childBroadPhase; // rcx
  char addPairs; // [rsp+20h] [rbp-18h]
  hkpBroadPhaseHandle *handles; // [rsp+48h] [rbp+10h] BYREF

  handles = object;
  m_childBroadPhase = this->m_childBroadPhase;
  if ( m_childBroadPhase )
  {
    addPairs = 0;
    ((void (__fastcall *)(hkpBroadPhase *, hkpBroadPhaseHandle *, hkAabb *, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *, char))m_childBroadPhase->vfptr[2].__first_virtual_table_function__)(
      m_childBroadPhase,
      object,
      aabb,
      newPairs,
      addPairs);
    hkpTreeBroadPhase32::addHandles(this, &handles, aabb, 1);
  }
  else
  {
    hkpTreeBroadPhase32::addHandlesStandalone(this, &handles, aabb, 1, newPairs);
  }
}

// File Line: 1103
// RVA: 0xD9B750
void __fastcall hkpTreeBroadPhase::addObjectBatch(
        hkpTreeBroadPhase *this,
        hkArrayBase<hkpBroadPhaseHandle *> *addObjectList,
        hkArrayBase<hkAabb> *addAabbList,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *newPairs)
{
  hkpBroadPhase *m_childBroadPhase; // rcx

  m_childBroadPhase = this->m_childBroadPhase;
  if ( m_childBroadPhase )
  {
    ((void (__fastcall *)(hkpBroadPhase *, hkArrayBase<hkpBroadPhaseHandle *> *, hkArrayBase<hkAabb> *, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *))m_childBroadPhase->vfptr[3].__first_virtual_table_function__)(
      m_childBroadPhase,
      addObjectList,
      addAabbList,
      newPairs);
    hkpTreeBroadPhase::addHandles(this, addObjectList->m_data, addAabbList->m_data, addObjectList->m_size);
  }
  else
  {
    hkpTreeBroadPhase::addHandlesStandalone(
      this,
      addObjectList->m_data,
      addAabbList->m_data,
      addObjectList->m_size,
      newPairs);
  }
}

// File Line: 1123
// RVA: 0xD9B7D0
void __fastcall hkpTreeBroadPhase::removeObject(
        hkpTreeBroadPhase *this,
        hkpBroadPhaseHandle *object,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *pairsOut)
{
  hkpBroadPhaseHandle *handles; // [rsp+38h] [rbp+10h] BYREF

  handles = object;
  if ( this->m_childBroadPhase )
  {
    hkpTreeBroadPhase::removeHandles(this, &handles, 1);
    ((void (__fastcall *)(hkpBroadPhase *, hkpBroadPhaseHandle *, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *))this->m_childBroadPhase->vfptr[4].__vecDelDtor)(
      this->m_childBroadPhase,
      object,
      pairsOut);
    hkpTreeBroadPhase::indexAndCompact(this, 1);
  }
  else
  {
    hkpTreeBroadPhase::removeHandlesStandalone(this, &handles, 1, pairsOut);
  }
}

// File Line: 1146
// RVA: 0xD9B860
void __fastcall hkpTreeBroadPhase::removeObjectBatch(
        hkpTreeBroadPhase *this,
        hkArrayBase<hkpBroadPhaseHandle *> *removeObjectList,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *delPairsOut)
{
  if ( this->m_childBroadPhase )
  {
    hkpTreeBroadPhase::removeHandles(this, removeObjectList->m_data, removeObjectList->m_size);
    ((void (__fastcall *)(hkpBroadPhase *, hkArrayBase<hkpBroadPhaseHandle *> *, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *))this->m_childBroadPhase->vfptr[4].__first_virtual_table_function__)(
      this->m_childBroadPhase,
      removeObjectList,
      delPairsOut);
    hkpTreeBroadPhase::indexAndCompact(this, removeObjectList->m_size);
  }
  else
  {
    hkpTreeBroadPhase::removeHandlesStandalone(this, removeObjectList->m_data, removeObjectList->m_size, delPairsOut);
  }
}

// File Line: 1169
// RVA: 0xDA8F20
void __fastcall hkpTreeBroadPhase32::updateAabbs(
        hkpTreeBroadPhase32 *this,
        hkpBroadPhaseHandle **objects,
        hkAabb *aabbs,
        int numObjects,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *addedPairs,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *removedPairs)
{
  hkpTreeBroadPhase32::updateAabbs(this, objects, aabbs, 0i64, numObjects, addedPairs, removedPairs);
}

// File Line: 1175
// RVA: 0xDA8F50
void __fastcall hkpTreeBroadPhase32::updateAabbsUint32(
        hkpTreeBroadPhase32 *this,
        hkpBroadPhaseHandle **objects,
        __m128i *aabbs,
        unsigned int numObjects,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *addedPairs,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *removedPairs)
{
  __int64 v7; // rbp
  hkLifoAllocator *Value; // rax
  hkAabb *m_cur; // rbx
  int v12; // edi
  char *v13; // rcx
  hkAabb *v14; // rax
  __m128i *v15; // rcx
  __int64 v16; // rdx
  __m128 v17; // xmm0
  __m128i si128; // xmm1
  hkLifoAllocator *v19; // rax
  int v20; // r8d

  v7 = numObjects;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (hkAabb *)Value->m_cur;
  v12 = (32 * v7 + 127) & 0xFFFFFF80;
  v13 = (char *)m_cur + v12;
  if ( v12 > Value->m_slabSize || v13 > Value->m_end )
    m_cur = (hkAabb *)hkLifoAllocator::allocateFromNewSlab(Value, v12);
  else
    Value->m_cur = v13;
  if ( (int)v7 > 0 )
  {
    v14 = m_cur;
    v15 = aabbs;
    v16 = v7;
    do
    {
      v17 = _mm_cvtepi32_ps(*v15);
      si128 = _mm_load_si128(v15 + 1);
      ++v14;
      v15 += 2;
      v14[-1].m_min.m_quad = _mm_add_ps(_mm_mul_ps(v17, this->m_scale.m_quad), this->m_offsetAndTimeStep.m_quad);
      v14[-1].m_max.m_quad = _mm_add_ps(
                               _mm_mul_ps(_mm_cvtepi32_ps(si128), this->m_scale.m_quad),
                               this->m_offsetAndTimeStep.m_quad);
      --v16;
    }
    while ( v16 );
  }
  hkpTreeBroadPhase32::updateAabbs(this, objects, m_cur, (hkAabbUint32 *)aabbs, v7, addedPairs, removedPairs);
  v19 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v20 = (v12 + 15) & 0xFFFFFFF0;
  if ( v12 > v19->m_slabSize || (char *)m_cur + v20 != v19->m_cur || v19->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v19, (char *)m_cur, v20);
  else
    v19->m_cur = m_cur;
}

// File Line: 1189
// RVA: 0xDAC780
void __fastcall hkpTreeBroadPhase32::updateAabbs(
        hkpTreeBroadPhase32 *this,
        hkpBroadPhaseHandle **objects,
        hkAabb *aabbs,
        hkAabbUint32 *aabbsInt,
        unsigned int numObjects,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *addedPairs,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *removedPairs)
{
  hkpBroadPhase *m_childBroadPhase; // rcx
  hkBaseObjectVtbl *vfptr; // r10

  m_childBroadPhase = this->m_childBroadPhase;
  if ( m_childBroadPhase )
  {
    vfptr = m_childBroadPhase->vfptr;
    if ( aabbsInt )
      ((void (__fastcall *)(hkpBroadPhase *, hkpBroadPhaseHandle **, hkAabbUint32 *, _QWORD, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *))vfptr[6].__vecDelDtor)(
        m_childBroadPhase,
        objects,
        aabbsInt,
        numObjects,
        addedPairs,
        removedPairs);
    else
      ((void (__fastcall *)(hkpBroadPhase *, hkpBroadPhaseHandle **, hkAabb *, _QWORD, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *))vfptr[5].__first_virtual_table_function__)(
        m_childBroadPhase,
        objects,
        aabbs,
        numObjects,
        addedPairs,
        removedPairs);
    hkpTreeBroadPhase32::updateHandles(this, objects, aabbs, numObjects);
  }
  else
  {
    hkpTreeBroadPhase32::updateHandlesStandalone(this, objects, aabbs, numObjects, addedPairs, removedPairs);
  }
}

// File Line: 1212
// RVA: 0xDA9090
void __fastcall hkpTreeBroadPhase32::defragment(hkpTreeBroadPhase32 *this)
{
  hkpBroadPhase *m_childBroadPhase; // rcx
  int requestedCapacity; // ecx
  int m_size; // r9d

  m_childBroadPhase = this->m_childBroadPhase;
  if ( m_childBroadPhase )
  {
    m_childBroadPhase->vfptr[6].__first_virtual_table_function__(m_childBroadPhase);
    hkpTreeBroadPhase32::updateHandlesMapping(this);
  }
  requestedCapacity = this->m_handles[0].m_size;
  if ( requestedCapacity < (this->m_handles[0].m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reduce(
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_handles[0].m_data,
      16,
      0i64,
      requestedCapacity);
  m_size = this->m_handles[1].m_size;
  if ( m_size < (this->m_handles[1].m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reduce(
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_handles[1].m_data,
      16,
      0i64,
      m_size);
}

// File Line: 1225
// RVA: 0xD9BAE0
void __fastcall hkpTreeBroadPhase::shiftAllObjects(
        hkpTreeBroadPhase *this,
        hkVector4f *shiftDistance,
        hkVector4f *effectiveShiftDistanceOut,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *newCollisionPairs)
{
  hkpTreeBroadPhase *v4; // rbp
  hkpBroadPhase *m_childBroadPhase; // rcx
  int v7; // r15d
  __int64 v8; // r12
  hkpTreeBroadPhase::Handle *m_data; // rcx
  unsigned __int64 v10; // rax
  unsigned __int16 v11; // si
  __int64 v12; // r14
  hkSimdFloat32 *v13; // rbx
  unsigned __int64 v14; // rdx
  unsigned __int16 v15; // r9
  __m128 *v16; // rdi
  __m128 v17; // xmm6
  __m128 v18; // xmm8
  __m128 v19; // xmm4
  __m128 v20; // xmm5
  unsigned __int64 v21; // r8
  unsigned __int16 v22; // ax
  unsigned __int64 v23; // r11
  unsigned __int16 v24; // r8
  unsigned __int64 v25; // rdx
  __int64 v26; // rax
  unsigned __int16 v27; // r8
  __m128 *v28; // rcx
  __int64 v29; // rax
  __m128 v30; // xmm3
  __m128 v31; // xmm2
  __int64 v32; // rax
  __m128 v33; // xmm0
  __m128 v34; // xmm3
  unsigned __int64 v35; // rax
  unsigned __int64 v36; // rcx
  unsigned __int16 v37; // di
  __m128 v38; // xmm9
  __m128 v39; // xmm8
  __m128 *v40; // r9
  __m128 *v41; // r10
  unsigned __int16 v42; // cx
  __m128 v43; // xmm10
  __m128 v44; // xmm11
  __m128 *v45; // rcx
  __m128 *v46; // rdx
  __m128 v47; // xmm4
  __m128 v48; // xmm3
  __m128 v49; // xmm4
  __m128 v50; // xmm6
  __m128 v51; // xmm2
  __m128 v52; // xmm5
  __m128 v53; // xmm2
  __m128 v54; // xmm4
  __m128 v55; // xmm6
  __m128 v56; // xmm5
  __m128 v57; // xmm5
  unsigned __int16 v58; // ax
  __int64 v59; // r11
  __int64 v60; // rax
  int v61; // ecx
  __m128 v62; // xmm1
  __m128 v63; // xmm2
  hkResult result; // [rsp+20h] [rbp-A8h] BYREF
  __int64 v65[3]; // [rsp+28h] [rbp-A0h]

  v4 = this;
  m_childBroadPhase = this->m_childBroadPhase;
  if ( m_childBroadPhase )
  {
    ((void (__fastcall *)(hkpBroadPhase *, hkVector4f *, hkVector4f *, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *))m_childBroadPhase->vfptr[11].__vecDelDtor)(
      m_childBroadPhase,
      shiftDistance,
      effectiveShiftDistanceOut,
      newCollisionPairs);
    v7 = 0;
    if ( v4->m_handles[0].m_size > 0 )
    {
      v8 = 0i64;
      do
      {
        m_data = v4->m_handles[0].m_data;
        v10 = *((unsigned int *)&m_data[v8] + 2);
        if ( (v10 & 0x1FFFFF) != 0 )
        {
          v11 = *((_WORD *)&m_data[v8] + 4);
          v12 = 32i64 * v11;
          v13 = &v4->m_internals[3 * ((v10 >> 21) & 0xF)];
          v14 = v13->m_real.m128_u64[0];
          v15 = v13[2].m_real.m128_u16[0];
          v16 = (__m128 *)(v12 + v13->m_real.m128_u64[0]);
          v17 = _mm_add_ps(*v16, effectiveShiftDistanceOut->m_quad);
          v18 = *v16;
          v19 = _mm_add_ps(
                  _mm_shuffle_ps(v16[1], _mm_unpackhi_ps(v16[1], (__m128)0i64), 196),
                  effectiveShiftDistanceOut->m_quad);
          v20 = _mm_shuffle_ps(v16[1], _mm_unpackhi_ps(v16[1], (__m128)0i64), 196);
          if ( v11 == v15 )
          {
            v13[2].m_real.m128_i16[0] = 0;
          }
          else
          {
            v21 = v14 + 32i64 * v16->m128_u16[6];
            v22 = *(_WORD *)(v21 + 12);
            v23 = v14 + 32i64 * *(unsigned __int16 *)(v21 + 2 * (15i64 - (*(_WORD *)(v21 + 30) == v11)));
            if ( v22 )
            {
              *(_DWORD *)(v23 + 12) = v22 | 0x3F000000;
              *(_WORD *)(v13->m_real.m128_u64[0]
                       + 2
                       * (16i64 * *(unsigned __int16 *)(v21 + 12)
                        + (*(_WORD *)(32i64 * *(unsigned __int16 *)(v21 + 12) + v13->m_real.m128_u64[0] + 30) == v16->m128_i16[6]))
                       + 28) = (__int64)(v23 - v13->m_real.m128_u64[0]) >> 5;
              v24 = v16->m128_u16[6];
              *(_WORD *)(32i64 * v24 + v13->m_real.m128_u64[0]) = v13[1].m_real.m128_i16[0];
              v25 = v13->m_real.m128_u64[0];
              v13[1].m_real.m128_i16[0] = v24;
              v26 = v25 + 32i64 * *(unsigned __int16 *)(v23 + 12);
              do
              {
                v27 = *(_WORD *)(v26 + 12);
                v28 = (__m128 *)(v25 + 32i64 * (unsigned __int16)((__int64)(v26 - v25) >> 5));
                v29 = 32i64 * v28[1].m128_u16[6];
                v30 = *(__m128 *)(v29 + v25 + 16);
                v31 = *(__m128 *)(v29 + v25);
                v32 = 32i64 * v28[1].m128_u16[7];
                v33 = _mm_min_ps(v31, *(__m128 *)(v32 + v25));
                v34 = _mm_max_ps(
                        _mm_shuffle_ps(v30, _mm_unpackhi_ps(v30, (__m128)0i64), 196),
                        _mm_shuffle_ps(
                          *(__m128 *)(v32 + v25 + 16),
                          _mm_unpackhi_ps(*(__m128 *)(v32 + v25 + 16), (__m128)0i64),
                          196));
                *v28 = _mm_shuffle_ps(v33, _mm_unpackhi_ps(v33, *v28), 196);
                v28[1] = _mm_shuffle_ps(v34, _mm_unpackhi_ps(v34, v28[1]), 196);
                if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v33, v18), _mm_cmple_ps(v20, v34))) & 7) == 7 )
                  break;
                if ( !v27 )
                  break;
                v25 = v13->m_real.m128_u64[0];
                v26 = v13->m_real.m128_u64[0] + 32i64 * v27;
              }
              while ( v26 );
            }
            else
            {
              *(_WORD *)(32i64 * v15 + v14) = v13[1].m_real.m128_i16[0];
              v13[1].m_real.m128_i16[0] = v15;
              v13[2].m_real.m128_i16[0] = (__int64)(unsigned int)(v23 - v13->m_real.m128_i32[0]) >> 5;
              *(_DWORD *)(v23 + 12) = 1056964608;
            }
          }
          v35 = v13->m_real.m128_u64[0];
          *(__m128 *)(v12 + v35) = _mm_shuffle_ps(
                                     v17,
                                     _mm_unpackhi_ps(v17, *(__m128 *)(v12 + v13->m_real.m128_u64[0])),
                                     196);
          *(__m128 *)(v12 + v35 + 16) = _mm_shuffle_ps(v19, _mm_unpackhi_ps(v19, *(__m128 *)(v12 + v35 + 16)), 196);
          v36 = v13->m_real.m128_u64[0];
          v37 = v13[2].m_real.m128_u16[0];
          v38 = *(__m128 *)(v13->m_real.m128_u64[0] + 32i64 * v11);
          v39 = _mm_shuffle_ps(
                  *(__m128 *)(v13->m_real.m128_u64[0] + v12 + 16),
                  _mm_unpackhi_ps(*(__m128 *)(v13->m_real.m128_u64[0] + v12 + 16), (__m128)0i64),
                  196);
          if ( v37 )
          {
            if ( !v13[1].m_real.m128_i16[0] )
              hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::Codec32>::reserveNodes(
                (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::Codec32> *)v13,
                &result,
                1);
            v40 = (__m128 *)(v13->m_real.m128_u64[0] + 32i64 * v37);
            v41 = (__m128 *)(v13->m_real.m128_u64[0] + 32i64 * v13[1].m_real.m128_u16[0]);
            v13[1].m_real.m128_i16[0] = v41->m128_i16[0];
            v42 = v40[1].m128_u16[6];
            if ( v42 )
            {
              v43 = _mm_add_ps(v38, v39);
              v44 = _mm_sub_ps(v39, v38);
              do
              {
                v45 = (__m128 *)(v13->m_real.m128_u64[0] + 32i64 * v42);
                v46 = (__m128 *)(v13->m_real.m128_u64[0] + 32i64 * v40[1].m128_u16[7]);
                v47 = _mm_min_ps(v38, *v40);
                v48 = _mm_max_ps(v39, _mm_shuffle_ps(v40[1], _mm_unpackhi_ps(v40[1], (__m128)0i64), 196));
                v65[0] = (__int64)v45;
                v65[1] = (__int64)v46;
                *v40 = _mm_shuffle_ps(v47, _mm_unpackhi_ps(v47, *v40), 196);
                v40[1] = _mm_shuffle_ps(v48, _mm_unpackhi_ps(v48, v40[1]), 196);
                v49 = _mm_shuffle_ps(v45[1], _mm_unpackhi_ps(v45[1], (__m128)0i64), 196);
                v50 = _mm_shuffle_ps(v46[1], _mm_unpackhi_ps(v46[1], (__m128)0i64), 196);
                v51 = _mm_sub_ps(_mm_add_ps(*v45, v49), v43);
                v52 = _mm_add_ps(*v46, v50);
                v53 = _mm_mul_ps(v51, v51);
                v54 = _mm_add_ps(_mm_sub_ps(v49, *v45), v44);
                v55 = _mm_add_ps(_mm_sub_ps(v50, *v46), v44);
                v56 = _mm_sub_ps(v52, v43);
                v57 = _mm_mul_ps(v56, v56);
                v40 = (__m128 *)v65[(float)((float)((float)(_mm_shuffle_ps(v54, v54, 85).m128_f32[0]
                                                          + _mm_shuffle_ps(v54, v54, 0).m128_f32[0])
                                                  + _mm_shuffle_ps(v54, v54, 170).m128_f32[0])
                                          * (float)((float)(_mm_shuffle_ps(v53, v53, 85).m128_f32[0]
                                                          + _mm_shuffle_ps(v53, v53, 0).m128_f32[0])
                                                  + _mm_shuffle_ps(v53, v53, 170).m128_f32[0])) > (float)((float)((float)(_mm_shuffle_ps(v57, v57, 85).m128_f32[0] + _mm_shuffle_ps(v57, v57, 0).m128_f32[0]) + _mm_shuffle_ps(v57, v57, 170).m128_f32[0]) * (float)((float)(_mm_shuffle_ps(v55, v55, 85).m128_f32[0] + _mm_shuffle_ps(v55, v55, 0).m128_f32[0]) + _mm_shuffle_ps(v55, v55, 170).m128_f32[0]))];
                v42 = v40[1].m128_u16[6];
              }
              while ( v42 );
              v4 = this;
            }
            v58 = v40->m128_u16[6];
            v59 = (__int64)((__int64)v41 - v13->m_real.m128_u64[0]) >> 5;
            if ( v58 )
              *(_WORD *)(v13->m_real.m128_u64[0]
                       + 2
                       * (16i64 * v58
                        + (*(_WORD *)(32i64 * v58 + v13->m_real.m128_u64[0] + 30) == (unsigned __int16)((__int64)((__int64)v40 - v13->m_real.m128_u64[0]) >> 5)))
                       + 28) = v59;
            else
              v13[2].m_real.m128_i16[0] = v59;
            v41->m128_i32[3] = v40->m128_u16[6] | 0x3F000000;
            v60 = (unsigned int)((_DWORD)v40 - v13->m_real.m128_i32[0]);
            v41[1].m128_i16[7] = v11;
            v61 = (unsigned __int16)v59 | 0x3F000000;
            v41[1].m128_i16[6] = v60 >> 5;
            v40->m128_i32[3] = v61;
            *(_DWORD *)(v12 + v13->m_real.m128_u64[0] + 12) = v61;
            v62 = _mm_min_ps(*v40, v38);
            v63 = _mm_max_ps(_mm_shuffle_ps(v40[1], _mm_unpackhi_ps(v40[1], (__m128)0i64), 196), v39);
            *v41 = _mm_shuffle_ps(v62, _mm_unpackhi_ps(v62, *v41), 196);
            v41[1] = _mm_shuffle_ps(v63, _mm_unpackhi_ps(v63, v41[1]), 196);
          }
          else
          {
            v13[2].m_real.m128_i16[0] = v11;
            *(_DWORD *)(v36 + v12 + 12) = 1056964608;
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
void __fastcall hkpTreeBroadPhase::set32BitOffsetAndScale(
        hkpTreeBroadPhase *this,
        hkVector4f *offsetLow,
        hkVector4f *offsetHigh,
        hkVector4f *scale)
{
  __m128 v8; // xmm6
  hkVector4f v9; // xmm7
  hkpBroadPhase *m_childBroadPhase; // rcx
  __m128 v11; // xmm7
  __m128 v12; // xmm1
  __m128 v13; // xmm1
  __m128 v14; // xmm2

  v8 = _mm_shuffle_ps(this->m_offsetAndTimeStep.m_quad, this->m_offsetAndTimeStep.m_quad, 255);
  v9.m_quad = (__m128)this->m_scale;
  m_childBroadPhase = this->m_childBroadPhase;
  v11 = _mm_shuffle_ps(v9.m_quad, v9.m_quad, 255);
  if ( m_childBroadPhase )
    ((void (__fastcall *)(hkpBroadPhase *))m_childBroadPhase->vfptr[15].__vecDelDtor)(m_childBroadPhase);
  v12 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64), offsetLow->m_quad);
  this->m_offsetAndTimeStep.m_quad = _mm_shuffle_ps(v12, _mm_unpackhi_ps(v12, v8), 196);
  v13 = _mm_rcp_ps(scale->m_quad);
  v14 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(scale->m_quad, v13)), v13);
  this->m_scale.m_quad = _mm_shuffle_ps(v14, _mm_unpackhi_ps(v14, v11), 196);
  this->m_offsetLow = (hkVector4f)offsetLow->m_quad;
  this->m_offsetHigh = (hkVector4f)offsetHigh->m_quad;
}

// File Line: 1275
// RVA: 0xDA9780
void __fastcall hkpTreeBroadPhase32::castRay(
        hkpTreeBroadPhase32 *this,
        hkpTreeBroadPhaseSpatialTree32 *input,
        hkpBroadPhaseCastCollector *collectorBase,
        int collectorStriding)
{
  int m_firstFree; // ebx
  hkLifoAllocator *Value; // rax
  __int64 m_cur; // r8
  int v11; // edx
  void *v12; // rcx
  int v13; // ebx
  hkLifoAllocator *v14; // rax
  __int64 v15; // rdx
  int v16; // ebx
  void *v17; // rcx
  int v18; // ebx
  hkLifoAllocator *v19; // rax
  __int64 v20; // rdx
  int v21; // ebx
  void *v22; // rcx
  __int64 v23; // rdx
  int v24; // r9d
  __int64 v25; // r8
  int v26; // r10d
  __int64 v27; // rcx
  __int128 v28; // xmm0
  char *v29; // rcx
  int v30; // ebx
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *v31; // rsi
  hkVector4f *v32; // r9
  char *v33; // rsi
  signed int v34; // ebx
  hkLifoAllocator *v35; // rax
  int v36; // r8d
  char *v37; // rsi
  signed int v38; // ebx
  hkLifoAllocator *v39; // rax
  int v40; // r8d
  char *v41; // rsi
  signed int v42; // ebx
  hkLifoAllocator *v43; // rax
  int v44; // r8d
  __m128 m_quad; // xmm1
  int v46; // ebx
  hkSimdFloat32 *v47; // rsi
  __m128i v48; // xmm5
  __m128 v49; // xmm3
  __m128 v50; // xmm2
  hkpTreeBroadPhaseInternals::RayCastQuery *numRays; // [rsp+20h] [rbp-79h]
  hkpTreeBroadPhaseInternals::RayCastFanQuery *v52; // [rsp+28h] [rbp-71h]
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> v53; // [rsp+30h] [rbp-69h] BYREF
  hkcdRay ray; // [rsp+40h] [rbp-59h] BYREF
  hkpTreeBroadPhaseSpatialTree32 tree; // [rsp+70h] [rbp-29h] BYREF

  m_firstFree = input->m_firstFree;
  if ( m_firstFree <= 1 )
  {
    m_quad = query.m_quad;
    ray.m_invDirection.m_quad.m128_u64[0] = (unsigned __int64)collectorBase;
    ray.m_invDirection.m_quad.m128_i32[2] = 0;
    v46 = 1;
    v47 = &this->m_internals[3];
    for ( ray.m_direction = (hkVector4f)query.m_quad; ; m_quad = ray.m_direction.m_quad )
    {
      tree.m_nodes = input->m_nodes;
      ray.m_origin.m_quad.m128_u64[0] = (unsigned __int64)this->m_handles[v46 == 4].m_data;
      v48 = (__m128i)_mm_sub_ps(*(__m128 *)*(_QWORD *)&input->m_numLeaves, (__m128)tree.m_nodes);
      v49 = _mm_cmpeq_ps((__m128)0i64, (__m128)v48);
      v50 = _mm_rcp_ps((__m128)v48);
      *(__m128 *)&tree.m_firstFree = _mm_shuffle_ps((__m128)v48, _mm_unpackhi_ps((__m128)v48, m_quad), 196);
      *(__m128 *)&tree.m_root = _mm_or_ps(
                                  _mm_andnot_ps(
                                    v49,
                                    _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v50, (__m128)v48)), v50)),
                                  _mm_and_ps(
                                    _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v48, 0x1Fu), 0x1Fu), (__m128)_xmm),
                                    v49));
      *(&tree.m_sortPath + 1) = _mm_movemask_ps(_mm_cmple_ps((__m128)0i64, *(__m128 *)&tree.m_firstFree)) & 7 | 0x3F000000;
      hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::rayCast<hkpTreeBroadPhaseSpatialTree32,hkpTreeBroadPhaseInternals::RayCastQuery>(
        &v53,
        v47,
        &tree,
        &ray,
        numRays);
      ++v46;
      v47 += 3;
      if ( v46 >= 5 )
        break;
    }
  }
  else
  {
    ray.m_origin.m_quad.m128_u64[0] = 0i64;
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (__int64)Value->m_cur;
    v11 = (8 * m_firstFree + 127) & 0xFFFFFF80;
    v12 = (void *)(m_cur + v11);
    if ( v11 > Value->m_slabSize || v12 > Value->m_end )
      m_cur = hkLifoAllocator::allocateFromNewSlab(Value, v11);
    else
      Value->m_cur = v12;
    v13 = input->m_firstFree;
    ray.m_origin.m_quad.m128_u64[1] = m_cur;
    v14 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v15 = (__int64)v14->m_cur;
    v16 = (16 * v13 + 127) & 0xFFFFFF80;
    v17 = (void *)(v15 + v16);
    if ( v16 > v14->m_slabSize || v17 > v14->m_end )
      v15 = hkLifoAllocator::allocateFromNewSlab(v14, v16);
    else
      v14->m_cur = v17;
    v18 = input->m_firstFree;
    ray.m_direction.m_quad.m128_u64[0] = v15;
    v19 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v20 = (__int64)v19->m_cur;
    v21 = (16 * v18 + 127) & 0xFFFFFF80;
    v22 = (void *)(v20 + v21);
    if ( v21 > v19->m_slabSize || v22 > v19->m_end )
      v20 = hkLifoAllocator::allocateFromNewSlab(v19, v21);
    else
      v19->m_cur = v22;
    ray.m_direction.m_quad.m128_u64[1] = v20;
    v23 = 0i64;
    v24 = 0;
    ray.m_invDirection.m_quad.m128_i32[0] = collectorStriding == 0;
    if ( (int)input->m_firstFree > 0 )
    {
      v25 = 0i64;
      v26 = 0;
      do
      {
        ++v24;
        v25 += 16i64;
        v27 = v23 * (int)input->m_root;
        ++v23;
        v28 = *(_OWORD *)(v27 + *(_QWORD *)&input->m_numLeaves);
        v29 = (char *)collectorBase + v26;
        v26 += collectorStriding;
        *(_OWORD *)(v25 + ray.m_direction.m_quad.m128_u64[0] - 16) = v28;
        *(_QWORD *)(ray.m_origin.m_quad.m128_u64[1] + 8 * v23 - 8) = v29;
        *(hkVector4f *)(v25 + ray.m_direction.m_quad.m128_u64[1] - 16) = (hkVector4f)query.m_quad;
      }
      while ( v24 < (signed int)input->m_firstFree );
    }
    v30 = 1;
    v31 = (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)&this->m_internals[3];
    do
    {
      v32 = (hkVector4f *)input->m_firstFree;
      ray.m_origin.m_quad.m128_u64[0] = (unsigned __int64)this->m_handles[v30 == 4].m_data;
      hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::rayCastFan<hkpTreeBroadPhaseSpatialTree32,hkpTreeBroadPhaseInternals::RayCastFanQuery>(
        v31,
        input,
        (hkVector4f *)ray.m_direction.m_quad.m128_u64[0],
        v32,
        (int)&ray,
        v52);
      ++v30;
      v31 += 48;
    }
    while ( v30 < 5 );
    v33 = (char *)ray.m_direction.m_quad.m128_u64[1];
    v34 = (16 * input->m_firstFree + 127) & 0xFFFFFF80;
    v35 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v36 = (v34 + 15) & 0xFFFFFFF0;
    if ( v34 > v35->m_slabSize || &v33[v36] != v35->m_cur || v35->m_firstNonLifoEnd == v33 )
      hkLifoAllocator::slowBlockFree(v35, v33, v36);
    else
      v35->m_cur = v33;
    v37 = (char *)ray.m_direction.m_quad.m128_u64[0];
    v38 = (16 * input->m_firstFree + 127) & 0xFFFFFF80;
    v39 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v40 = (v38 + 15) & 0xFFFFFFF0;
    if ( v38 > v39->m_slabSize || &v37[v40] != v39->m_cur || v39->m_firstNonLifoEnd == v37 )
      hkLifoAllocator::slowBlockFree(v39, v37, v40);
    else
      v39->m_cur = v37;
    v41 = (char *)ray.m_origin.m_quad.m128_u64[1];
    v42 = (8 * input->m_firstFree + 127) & 0xFFFFFF80;
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
void __fastcall hkpTreeBroadPhase::castAabb(
        hkpTreeBroadPhase *this,
        hkpBroadPhase::hkpCastAabbInput *input,
        hkpBroadPhaseCastCollector *collector)
{
  hkVector4f v3; // xmm2
  int v5; // ebx
  hkAabb *p_m_to; // rbp
  hkSimdFloat32 *v7; // rdi
  hkArray<hkcdDynamicTree::Codec32,hkContainerHeapAllocator> v8; // xmm0
  int v9; // xmm0_4
  hkpTreeBroadPhaseInternals::AabbCastQuery *query; // [rsp+28h] [rbp-70h]
  float v11[4]; // [rsp+30h] [rbp-68h] BYREF
  hkpTreeBroadPhaseSpatialTree16 tree; // [rsp+40h] [rbp-58h] BYREF
  __m128 i; // [rsp+70h] [rbp-28h]
  hkpBroadPhaseCastCollector *v14; // [rsp+80h] [rbp-18h]
  int v15; // [rsp+88h] [rbp-10h]

  v3.m_quad = (__m128)input->m_from;
  v14 = collector;
  v15 = 0;
  v5 = 1;
  p_m_to = (hkAabb *)&input->m_to;
  v7 = &this->m_internals[3];
  v8 = (hkArray<hkcdDynamicTree::Codec32,hkContainerHeapAllocator>)_mm_sub_ps(v3.m_quad, input->m_halfExtents.m_quad);
  *(__m128 *)&tree.m_firstFree = _mm_add_ps(v3.m_quad, input->m_halfExtents.m_quad);
  tree.m_nodes = v8;
  v9 = 1065353216;
  for ( i = ::query.m_quad; ; v9 = i.m128_i32[0] )
  {
    LODWORD(query) = v9;
    *(_QWORD *)&tree.m_root = this->m_handles[v5 == 4].m_data;
    hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::aabbCast<hkpTreeBroadPhaseSpatialTree16,hkpTreeBroadPhaseInternals::AabbCastQuery>(
      (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)v11,
      v7,
      &tree,
      p_m_to,
      (hkVector4f *)&tree.m_root,
      query,
      v11[0]);
    ++v5;
    v7 += 3;
    if ( v5 >= 5 )
      break;
  }
}

// File Line: 1333
// RVA: 0xD9C680
void __fastcall hkpTreeBroadPhase::querySingleAabb(
        hkpTreeBroadPhase *this,
        hkAabb *aabb,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *pairs_out)
{
  hkpTreeBroadPhase::querySingleAabb(this, aabb, 0i64, pairs_out);
}

// File Line: 1339
// RVA: 0xD9F3D0
void __fastcall hkpTreeBroadPhase::querySingleAabb(
        hkpTreeBroadPhase *this,
        hkAabb *aabb,
        hkpBroadPhaseHandle *object,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *pairs_out)
{
  int v6; // esi
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *v7; // r14
  hkVector4f v8; // xmm0
  hkVector4f v9; // xmm1
  hkLifoAllocator *Value; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsNoEarlyExitWrapper<hkpTreeBroadPhaseInternals::AabbQuery> *v11; // r9
  hkcdDynamicTree::Codec32 *m_cur; // rdx
  hkcdDynamicTree::Codec32 *v13; // rcx
  int m_size; // eax
  char *v15; // rdi
  signed int v16; // ebx
  hkLifoAllocator *v17; // rax
  int v18; // r8d
  __int64 v19[3]; // [rsp+20h] [rbp-39h] BYREF
  hkpTreeBroadPhaseSpatialTree16 tree; // [rsp+38h] [rbp-21h] BYREF
  __m128 m_quad; // [rsp+70h] [rbp+17h]
  __m128 v22; // [rsp+80h] [rbp+27h]

  v19[1] = (__int64)pairs_out;
  v19[2] = (__int64)object;
  v6 = 1;
  v7 = (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)&this->m_internals[3];
  do
  {
    v8.m_quad = (__m128)aabb->m_min;
    v9.m_quad = (__m128)aabb->m_max;
    tree.m_nodes.m_data = 0i64;
    tree.m_nodes.m_size = 0;
    tree.m_nodes.m_capacityAndFlags = 0x80000000;
    m_quad = v8.m_quad;
    v22 = v9.m_quad;
    tree.m_numLeaves = 64;
    v19[0] = (__int64)this->m_handles[v6 == 4].m_data;
    *(_QWORD *)&tree.m_sortPath = v19;
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkcdDynamicTree::Codec32 *)Value->m_cur;
    v13 = m_cur + 4;
    if ( Value->m_slabSize < 128 || v13 > Value->m_end )
      m_cur = (hkcdDynamicTree::Codec32 *)hkLifoAllocator::allocateFromNewSlab(Value, 128);
    else
      Value->m_cur = v13;
    tree.m_nodes.m_data = m_cur;
    *(_QWORD *)&tree.m_firstFree = m_cur;
    tree.m_nodes.m_capacityAndFlags = -2147483584;
    hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkpTreeBroadPhaseSpatialTree16,hkcdTreeQueriesStacks::Dynamic<64,unsigned short>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsNoEarlyExitWrapper<hkpTreeBroadPhaseInternals::AabbQuery>>(
      v7,
      &tree,
      (hkcdTreeQueriesStacks::Dynamic<64,unsigned short> *)&tree.m_sortPath,
      v11);
    m_size = tree.m_nodes.m_size;
    v15 = *(char **)&tree.m_firstFree;
    if ( *(hkcdDynamicTree::Codec32 **)&tree.m_firstFree == tree.m_nodes.m_data )
      m_size = 0;
    tree.m_nodes.m_size = m_size;
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
        &hkContainerHeapAllocator::s_alloc,
        tree.m_nodes.m_data,
        2 * (tree.m_nodes.m_capacityAndFlags & 0x3FFFFFFF));
    ++v6;
    v7 += 48;
  }
  while ( v6 < 5 );
}

// File Line: 1355
// RVA: 0xD9C6A0
void __fastcall hkpTreeBroadPhase::queryConvex(
        hkpTreeBroadPhase *this,
        hkpTreeBroadPhaseSpatialTree16 *planes,
        unsigned int numPlanes,
        hkArray<hkpBroadPhaseHandle const *,hkContainerHeapAllocator> *objects,
        unsigned int groupsMask)
{
  int v5; // edi
  int v9; // ebx
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *v10; // rsi
  int numPlanesa[2]; // [rsp+20h] [rbp-28h] BYREF
  hkArray<hkpBroadPhaseHandle const *,hkContainerHeapAllocator> *v12; // [rsp+28h] [rbp-20h]

  v5 = 1;
  v12 = objects;
  v9 = 2;
  v10 = (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)&this->m_internals[3];
  do
  {
    *(_QWORD *)numPlanesa = this->m_handles[v5 == 4].m_data;
    if ( (v9 & groupsMask) != 0 )
      hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::convexOverlaps<hkpTreeBroadPhaseSpatialTree16,hkpTreeBroadPhaseInternals::ConvexQuery>(
        v10,
        planes,
        (hkVector4f *)numPlanes,
        (int)numPlanesa,
        *(hkpTreeBroadPhaseInternals::ConvexQuery **)numPlanesa);
    v9 = __ROL4__(v9, 1);
    ++v5;
    v10 += 48;
  }
  while ( v5 < 5 );
}

// File Line: 1371
// RVA: 0xDA9D30
void __fastcall hkpTreeBroadPhase32::queryConvexSorted(
        hkpTreeBroadPhase32 *this,
        hkVector4f *axis,
        hkpTreeBroadPhaseSpatialTree32 *planes,
        unsigned int numPlanes,
        hkArray<hkpBroadPhaseHandle const *,hkContainerHeapAllocator> *objects,
        unsigned int groupsMask)
{
  hkArray<hkpBroadPhaseHandle const *,hkContainerHeapAllocator> *v6; // r14
  __int64 v7; // rax
  int m_capacityAndFlags; // r9d
  int v11; // r9d
  unsigned int v12; // r12d
  int v13; // edi
  hkpTreeBroadPhaseSpatialTree32 *v14; // r14
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *v15; // rsi
  int v16; // ebx
  __int64 v17; // rbx
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v18; // r14
  __int64 v19; // r8
  __int64 v20; // r9
  hkpTreeBroadPhaseInternals::ConvexQuerySorted *sizeElem; // [rsp+20h] [rbp-50h]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> a; // [rsp+30h] [rbp-40h] BYREF
  int numPlanesa[2]; // [rsp+40h] [rbp-30h] BYREF
  hkArray<hkpBroadPhaseHandle const *,hkContainerHeapAllocator> *v24; // [rsp+48h] [rbp-28h]
  hkVector4f *array; // [rsp+50h] [rbp-20h] BYREF
  int v26; // [rsp+58h] [rbp-18h]
  int v27; // [rsp+5Ch] [rbp-14h]
  __m128 m_quad; // [rsp+60h] [rbp-10h]
  hkResult result; // [rsp+B8h] [rbp+48h] BYREF
  hkpTreeBroadPhaseSpatialTree32 *tree; // [rsp+C0h] [rbp+50h]

  tree = planes;
  v6 = objects;
  v7 = 0i64;
  m_capacityAndFlags = objects->m_capacityAndFlags;
  m_quad = axis->m_quad;
  *(_QWORD *)numPlanesa = 0i64;
  array = 0i64;
  v11 = (m_capacityAndFlags & 0x3FFFFFFF) + 1;
  v26 = 0;
  v27 = 0x80000000;
  v24 = objects;
  if ( v11 > 0 )
  {
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v11, 16);
    v7 = 0i64;
  }
  v12 = groupsMask;
  v13 = 1;
  v6->m_size = 0;
  v14 = tree;
  v15 = (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)&this->m_internals[3];
  v16 = 2;
  do
  {
    LOBYTE(v7) = v13 == 4;
    *(_QWORD *)numPlanesa = this->m_handles[v7].m_data;
    if ( (v16 & v12) != 0 )
      hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::convexOverlaps<hkpTreeBroadPhaseSpatialTree32,hkpTreeBroadPhaseInternals::ConvexQuerySorted>(
        v15,
        v14,
        (hkVector4f *)numPlanes,
        (int)numPlanesa,
        sizeElem);
    v16 = __ROL4__(v16, 1);
    ++v13;
    v15 += 48;
    v7 = 0i64;
  }
  while ( v13 < 5 );
  v17 = v26;
  v18 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)objects;
  if ( v26 > 1 )
    hkAlgorithm::quickSortRecursive<hkVector4f,hkpTreeBroadPhaseInternals::DepthSort>(array, 0, v26 - 1, 0);
  a.m_capacityAndFlags = 0x80000000;
  a.m_data = 0i64;
  a.m_size = 0;
  if ( (int)v17 > 0 )
    hkArrayUtil::_reserve((hkResult *)&objects, &hkContainerHeapAllocator::s_alloc, (const void **)&a.m_data, v17, 8);
  a.m_size = v17;
  v19 = 0i64;
  if ( (int)v17 > 0 )
  {
    v20 = 0i64;
    do
      *((_QWORD *)a.m_data + v19++) = *((_QWORD *)&v18->m_data->m_fromOffset
                                      + (array[v20++].m_quad.m128_i32[3] & 0xFFFFFFFFC0FFFFFFui64));
    while ( v19 < v17 );
  }
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(v18, &a);
  a.m_size = 0;
  if ( a.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      a.m_data,
      8 * a.m_capacityAndFlags);
  a.m_data = 0i64;
  a.m_capacityAndFlags = 0x80000000;
  v26 = 0;
  if ( v27 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v27);
}

// File Line: 1404
// RVA: 0xDA8580
__int64 __fastcall hkpTreeBroadPhase32::getType(hkpTreeBroadPhase32 *this)
{
  return 3i64;
}

// File Line: 1415
// RVA: 0xD9F580
void __fastcall hkpTreeBroadPhase_createTreeBroadPhase(hkpBroadPhase *childBroadPhase)
{
  _QWORD **Value; // rax
  hkpTreeBroadPhase *v3; // rax

  hkOptionalComponent_hkpTreeBroadPhase.m_isUsed.m_bool = 1;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkpTreeBroadPhase *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 416i64);
  if ( v3 )
    hkpTreeBroadPhase::hkpTreeBroadPhase(v3, childBroadPhase);
}

// File Line: 1421
// RVA: 0xD9F5D0
// attributes: thunk
void __fastcall hkpTreeBroadPhase_updateTreeBroadPhase(hkpTreeBroadPhase *broadPhase, float physicsDeltaStep)
{
  hkpTreeBroadPhase::update(broadPhase, physicsDeltaStep);
}

// File Line: 1427
// RVA: 0xD9F5E0
void (__fastcall *hkpTreeBroadPhase_registerSelf())(hkpTreeBroadPhase *broadPhase, float physicsDeltaStep)
{
  void (__fastcall *result)(hkpTreeBroadPhase *, float); // rax

  hkpBroadPhase::s_createTreeBroadPhaseFunction = (hkpBroadPhase *(__fastcall *)(hkpBroadPhase *))hkpTreeBroadPhase_createTreeBroadPhase;
  result = hkpTreeBroadPhase_updateTreeBroadPhase;
  hkpBroadPhase::s_updateTreeBroadPhaseFunction = (void (__fastcall *)(hkpBroadPhase *, float))hkpTreeBroadPhase_updateTreeBroadPhase;
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

