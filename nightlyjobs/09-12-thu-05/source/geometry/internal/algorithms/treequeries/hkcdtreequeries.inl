// File Line: 14
// RVA: 0xDAE7A0
void __fastcall hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkpTreeBroadPhaseSpatialTree32,hkcdTreeQueriesStacks::Dynamic<64,unsigned int>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::CoherentKineticAabbOverlapsWrapper<hkpTreeBroadPhaseInternals::UpdatePairsQuery>>(
        hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *this,
        hkpTreeBroadPhaseSpatialTree32 *tree,
        hkcdTreeQueriesStacks::Dynamic<64,unsigned int> *stackInstance,
        hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::CoherentKineticAabbOverlapsWrapper<hkpTreeBroadPhaseInternals::UpdatePairsQuery> *query)
{
  __int64 v4; // rax
  int m_size; // r12d
  __m128 *v9; // rdx
  __m128 v10; // xmm6
  __m128 v11; // xmm7
  __int64 v12; // rax
  __int64 v13; // rsi
  int v14; // r8d
  __m128 v15; // xmm1
  __int64 v16; // rdi
  __m128 v17; // xmm3
  int v18; // r8d
  int v19; // r8d
  int v20; // r8d
  __int64 v21; // r8
  int *v22; // rdx
  unsigned int *m_data; // rsi
  __int64 v24; // rbp
  char v25; // dl
  char v26; // al
  __m128 v27; // xmm6
  int v28; // edx
  __int64 v29; // rdi
  _QWORD *v30; // rcx
  __int64 v31; // rax
  int v32; // edx
  hkcdDynamicTree::CodecRawUint *v33; // rax
  int v34; // edx

  v4 = *(unsigned int *)&this[32];
  if ( (_DWORD)v4 )
  {
    m_size = tree->m_nodes.m_size;
    v9 = (__m128 *)(*(_QWORD *)this + 48 * v4);
    v10 = *v9;
    v11 = v9[1];
    if ( (_mm_movemask_ps(
            _mm_and_ps(
              _mm_cmple_ps(*v9, (__m128)stackInstance[3].m_stack.hkArray<unsigned int,hkContainerHeapAllocator>),
              _mm_cmple_ps(*(__m128 *)&stackInstance[2].m_stack.m_localMemory, v11))) & 7) == 7 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          v12 = v9[2].m128_u32[1];
          if ( (_DWORD)v12 )
            break;
          m_data = stackInstance->m_stack.m_data;
          v24 = *(_QWORD *)(*(_QWORD *)stackInstance->m_stack.m_data + 16i64 * v9[2].m128_u32[2]);
          if ( v24 == *((_QWORD *)stackInstance->m_stack.m_data + 3) )
            goto LABEL_25;
          v25 = 0;
          v26 = _mm_movemask_ps(
                  _mm_and_ps(
                    _mm_cmple_ps(v10, (__m128)stackInstance[2].m_stack.hkArray<unsigned int,hkContainerHeapAllocator>),
                    _mm_cmple_ps(*(__m128 *)&stackInstance[1].m_stack.m_localMemory, v11))) & 7;
          v27 = _mm_and_ps(
                  _mm_cmple_ps(v10, (__m128)stackInstance[1].m_stack.hkArray<unsigned int,hkContainerHeapAllocator>),
                  _mm_cmple_ps(*(__m128 *)&stackInstance->m_stack.m_localMemory, v11));
          if ( v26 == 7 )
            v25 = 2;
          v28 = (((_mm_movemask_ps(v27) & 7) == 7) | v25 & 3) - 1;
          if ( v28 )
          {
            if ( v28 != 1 )
              goto LABEL_25;
            v29 = *((_QWORD *)m_data + 1);
          }
          else
          {
            v29 = *((_QWORD *)m_data + 2);
          }
          if ( *(_DWORD *)(v29 + 8) == (*(_DWORD *)(v29 + 12) & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)v29, 16);
          v30 = (_QWORD *)(*(_QWORD *)v29 + 16i64 * (int)(*(_DWORD *)(v29 + 8))++);
          v31 = *((_QWORD *)m_data + 3);
          v30[1] = v24;
          *v30 = v31;
LABEL_25:
          v32 = tree->m_nodes.m_size;
          if ( v32 <= m_size )
            return;
          v33 = tree->m_nodes.m_data;
          v34 = v32 - 1;
          tree->m_nodes.m_size = v34;
          v9 = (__m128 *)(*(_QWORD *)this + 48i64 * v33->m_aabb.m_min.m_quad.m128_u32[v34]);
          v10 = *v9;
          v11 = v9[1];
        }
        v13 = v9[2].m128_u32[2];
        v14 = 0;
        v15 = *(__m128 *)&stackInstance[2].m_stack.m_localMemory;
        v16 = *(_QWORD *)this + 48 * v12;
        v9 = (__m128 *)(*(_QWORD *)this + 48 * v13);
        v10 = *(__m128 *)v16;
        v11 = *(__m128 *)(v16 + 16);
        v17 = _mm_and_ps(
                _mm_cmple_ps(v15, v11),
                _mm_cmple_ps(
                  *(__m128 *)v16,
                  (__m128)stackInstance[3].m_stack.hkArray<unsigned int,hkContainerHeapAllocator>));
        if ( (_mm_movemask_ps(
                _mm_and_ps(
                  _mm_cmple_ps(v15, v9[1]),
                  _mm_cmple_ps(*v9, (__m128)stackInstance[3].m_stack.hkArray<unsigned int,hkContainerHeapAllocator>))) & 7) == 7 )
          v14 = 2;
        v18 = ((_mm_movemask_ps(v17) & 7) == 7) | v14;
        if ( !v18 )
          goto LABEL_25;
        v19 = v18 - 1;
        if ( !v19 )
          goto LABEL_13;
        v20 = v19 - 1;
        if ( v20 )
        {
          if ( v20 != 1 )
            goto LABEL_25;
          if ( tree->m_nodes.m_size == (tree->m_nodes.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&tree->m_nodes.m_data, 4);
          v21 = tree->m_nodes.m_size;
          v22 = &tree->m_nodes.m_data->m_aabb.m_min.m_quad.m128_i32[v21];
          tree->m_nodes.m_size = v21 + 1;
          *v22 = v13;
LABEL_13:
          v9 = (__m128 *)v16;
        }
        else
        {
          v10 = *v9;
          v11 = v9[1];
        }
      }
    }
  }
}

// File Line: 93
// RVA: 0xD9FAB0
void __fastcall hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::binary<hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>>,hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>>,hkcdTreeQueriesStacks::Dynamic<64,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::SlotPair<hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>>,hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>>>>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AllPairsWrapper<hkpTreeBroadPhaseInternals::InsertionQuery>>(
        hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *this,
        __int64 self,
        hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> > *treeA,
        hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> > *treeB,
        hkcdTreeQueriesStacks::Dynamic<64,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::SlotPair<hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> >,hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> > > > *stackInstance,
        hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AllPairsWrapper<hkpTreeBroadPhaseInternals::InsertionQuery> *query,
        hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> >::NodeContext *rootContextA,
        hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> >::NodeContext *rootContextB)
{
  unsigned __int64 m_root; // rdi
  __int64 v9; // rsi
  hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> > *v11; // r13
  __m128 m_quad; // xmm6
  __m128 v14; // xmm7
  hkpTreeBroadPhaseInternals::InsertionQuery *m_query; // rsi
  unsigned __int64 m_handles; // rbp
  hkVector4f v17; // xmm2
  hkVector4f v18; // xmm3
  hkcdDynamicTree::CodecRawUlong *m_node; // rdi
  unsigned __int64 m_index; // r14
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *m_pairsOut; // rsi
  __m128 v22; // xmm8
  __m128 v23; // xmm9
  _QWORD *v24; // rcx
  unsigned __int64 *v25; // rcx
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *v26; // rsi
  __m128 v27; // xmm6
  __m128 v28; // xmm8
  __m128 v29; // xmm7
  __m128 v30; // xmm9
  unsigned __int64 v31; // r14
  unsigned __int64 v32; // rdi
  __m128 v33; // xmm2
  __m128 v34; // xmm4
  __m128 v35; // xmm0
  __m128 v36; // xmm3
  __m128 v37; // xmm1
  __m128 v38; // xmm0
  BOOL v39; // r13d
  BOOL v40; // r12d
  _QWORD *v41; // rcx
  _QWORD *v42; // rcx
  unsigned __int64 *v43; // rcx
  unsigned __int64 *v44; // rcx
  int v45; // eax
  int v46; // eax
  BOOL v47; // edi
  _QWORD *v48; // rcx
  unsigned __int64 v49; // rsi
  unsigned __int64 *v50; // rcx
  unsigned __int64 *v51; // rcx
  unsigned __int64 m_nodeA; // rbp
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> **v53; // rcx
  int v54; // [rsp+20h] [rbp-88h]
  char v55; // [rsp+B0h] [rbp+8h]
  BOOL v56; // [rsp+B8h] [rbp+10h]

  v55 = (char)this;
  m_root = treeA->m_root;
  v9 = *(_QWORD *)(self + 1048);
  v11 = treeA;
  if ( v9 != 0 && m_root != 0 )
  {
    v54 = treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2];
    if ( query )
    {
      m_quad = *(__m128 *)&query->m_query;
      v14 = *(__m128 *)&query[2].m_query;
      m_query = query[4].m_query;
      m_handles = (unsigned __int64)query[5].m_query;
    }
    else
    {
      m_handles = *(_QWORD *)(self + 1048);
      m_query = (hkpTreeBroadPhaseInternals::InsertionQuery *)(self + (v9 << 6));
      m_quad = *(__m128 *)m_query;
      v14 = (__m128)m_query[1];
    }
    if ( rootContextA )
    {
      v17.m_quad = (__m128)rootContextA->m_aabb.m_min;
      v18.m_quad = (__m128)rootContextA->m_aabb.m_max;
      m_node = rootContextA->m_node;
      m_index = rootContextA->m_index;
    }
    else
    {
      m_index = treeA->m_root;
      m_node = &treeA->m_nodes[m_root];
      v17.m_quad = (__m128)m_node->m_aabb.m_min;
      v18.m_quad = (__m128)m_node->m_aabb.m_max;
    }
    if ( (_BYTE)this
      || (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(m_quad, v18.m_quad), _mm_cmple_ps(v17.m_quad, v14))) & 7) == 7 )
    {
      while ( 1 )
      {
        while ( (_BYTE)this && m_query == (hkpTreeBroadPhaseInternals::InsertionQuery *)m_node )
        {
          if ( !LODWORD(m_query[2].m_handles) )
            goto LABEL_39;
          m_handles = (unsigned __int64)m_query[2].m_handles;
          m_pairsOut = m_query[3].m_pairsOut;
          m_node = (hkcdDynamicTree::CodecRawUlong *)(self + (m_handles << 6));
          v22 = *(__m128 *)(((_QWORD)m_pairsOut << 6) + self);
          v23 = *(__m128 *)(((_QWORD)m_pairsOut << 6) + self + 16);
          m_quad = m_node->m_aabb.m_min.m_quad;
          v14 = m_node->m_aabb.m_max.m_quad;
          if ( treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2] == (treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[3] & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)treeB, 16);
          v24 = (_QWORD *)(treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_u64[0]
                         + 16i64 * treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2]++);
          *v24 = m_pairsOut;
          v24[1] = m_pairsOut;
          if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(m_quad, v23), _mm_cmple_ps(v22, v14))) & 7) == 7 )
          {
            if ( treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2] == (treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[3] & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)treeB, 16);
            v25 = (unsigned __int64 *)(treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_u64[0]
                                     + 16i64 * treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2]++);
            *v25 = m_handles;
            v25[1] = (unsigned __int64)m_pairsOut;
          }
          LOBYTE(this) = v55;
          m_index = m_handles;
          m_query = (hkpTreeBroadPhaseInternals::InsertionQuery *)(self + (m_handles << 6));
          v17.m_quad = m_quad;
          v18.m_quad = v14;
        }
        if ( LODWORD(m_query[2].m_handles) )
          break;
        if ( LODWORD(m_node->m_children[0]) )
        {
          m_index = m_node->m_children[0];
          v49 = m_node->m_children[1];
          v47 = (_mm_movemask_ps(
                   _mm_and_ps(
                     _mm_cmple_ps(v11->m_nodes[m_index].m_aabb.m_min.m_quad, v14),
                     _mm_cmple_ps(m_quad, v11->m_nodes[m_index].m_aabb.m_max.m_quad))) & 7) == 7;
          if ( (_mm_movemask_ps(
                  _mm_and_ps(
                    _mm_cmple_ps(v11->m_nodes[v49].m_aabb.m_min.m_quad, v14),
                    _mm_cmple_ps(m_quad, v11->m_nodes[v49].m_aabb.m_max.m_quad))) & 7) == 7 )
          {
            if ( treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2] == (treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[3] & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)treeB, 16);
            v50 = (unsigned __int64 *)(treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_u64[0]
                                     + 16i64 * treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2]++);
            *v50 = m_handles;
            v50[1] = v49;
          }
LABEL_50:
          if ( v47 )
          {
            if ( treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2] == (treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[3] & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)treeB, 16);
            v51 = (unsigned __int64 *)(treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_u64[0]
                                     + 16i64 * treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2]++);
            *v51 = m_handles;
            v51[1] = m_index;
          }
          goto LABEL_39;
        }
        m_nodeA = stackInstance->m_stack.m_data->m_nodeA;
        if ( *(_DWORD *)(m_nodeA + 8) == (*(_DWORD *)(m_nodeA + 12) & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            &hkContainerHeapAllocator::s_alloc,
            (const void **)stackInstance->m_stack.m_data->m_nodeA,
            16);
        v53 = (hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> **)(*(_QWORD *)m_nodeA
                                                                           + 16i64 * (int)(*(_DWORD *)(m_nodeA + 8))++);
        *v53 = m_query[3].m_pairsOut;
        v53[1] = (hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *)m_node->m_children[1];
LABEL_39:
        v45 = treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2];
        if ( v45 <= v54 )
          return;
        v46 = v45 - 1;
        this = (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)(treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_u64[0]
                                                                      + 16i64 * v46);
        treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2] = v46;
        m_handles = *(_QWORD *)this;
        m_index = *(_QWORD *)&this[8];
        LOBYTE(this) = v55;
        m_query = (hkpTreeBroadPhaseInternals::InsertionQuery *)(self + (m_handles << 6));
        m_node = &v11->m_nodes[m_index];
        v17.m_quad = (__m128)m_node->m_aabb.m_min;
        v18.m_quad = (__m128)m_node->m_aabb.m_max;
        m_quad = *(__m128 *)m_query;
        v14 = (__m128)m_query[1];
      }
      m_handles = (unsigned __int64)m_query[2].m_handles;
      v26 = m_query[3].m_pairsOut;
      v27 = *(__m128 *)((m_handles << 6) + self);
      v28 = *(__m128 *)((m_handles << 6) + self + 16);
      v29 = *(__m128 *)(((_QWORD)v26 << 6) + self);
      v30 = *(__m128 *)(((_QWORD)v26 << 6) + self + 16);
      if ( LODWORD(m_node->m_children[0]) )
      {
        v31 = m_node->m_children[0];
        v32 = m_node->m_children[1];
        v33 = v11->m_nodes[v31].m_aabb.m_max.m_quad;
        v34 = v11->m_nodes[v32].m_aabb.m_max.m_quad;
        v35 = v11->m_nodes[v31].m_aabb.m_min.m_quad;
        v36 = _mm_cmple_ps(v35, v30);
        v37 = _mm_and_ps(_mm_cmple_ps(v27, v33), _mm_cmple_ps(v35, v28));
        v38 = v11->m_nodes[v32].m_aabb.m_min.m_quad;
        v56 = (_mm_movemask_ps(v37) & 7) == 7;
        v39 = (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v27, v34), _mm_cmple_ps(v38, v28))) & 7) == 7;
        v40 = (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v29, v33), v36)) & 7) == 7;
        if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v29, v34), _mm_cmple_ps(v38, v30))) & 7) == 7 )
        {
          if ( treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2] == (treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[3] & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)treeB, 16);
          v41 = (_QWORD *)(treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_u64[0]
                         + 16i64 * treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2]++);
          *v41 = v26;
          v41[1] = v32;
        }
        if ( v40 )
        {
          if ( treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2] == (treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[3] & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)treeB, 16);
          v42 = (_QWORD *)(treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_u64[0]
                         + 16i64 * treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2]++);
          *v42 = v26;
          v42[1] = v31;
        }
        if ( v39 )
        {
          if ( treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2] == (treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[3] & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)treeB, 16);
          v43 = (unsigned __int64 *)(treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_u64[0]
                                   + 16i64 * treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2]++);
          *v43 = m_handles;
          v43[1] = v32;
        }
        if ( v56 )
        {
          if ( treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2] == (treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[3] & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)treeB, 16);
          v44 = (unsigned __int64 *)(treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_u64[0]
                                   + 16i64 * treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2]++);
          *v44 = m_handles;
          v44[1] = v31;
        }
        v11 = treeA;
        goto LABEL_39;
      }
      v47 = (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v17.m_quad, v28), _mm_cmple_ps(v27, v18.m_quad))) & 7) == 7;
      if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v17.m_quad, v30), _mm_cmple_ps(v29, v18.m_quad))) & 7) == 7 )
      {
        if ( treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2] == (treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[3] & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)treeB, 16);
        v48 = (_QWORD *)(treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_u64[0]
                       + 16i64 * treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2]++);
        *v48 = v26;
        v48[1] = m_index;
      }
      goto LABEL_50;
    }
  }
}

// File Line: 263
// RVA: 0xDA1140
void __fastcall hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::kineticAabbOverlaps<hkpTreeBroadPhaseSpatialTree16,hkpTreeBroadPhaseInternals::UpdatePairsQuery>(
        hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *this,
        hkpTreeBroadPhaseSpatialTree16 *tree,
        hkAabb *oldAabb,
        hkAabb *newAabb)
{
  hkArray<hkcdDynamicTree::Codec32,hkContainerHeapAllocator> m_nodes; // xmm2
  hkVector4f v5; // xmm5
  hkVector4f v6; // xmm4
  __m128 v8; // xmm3
  hkLifoAllocator *Value; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::CoherentKineticAabbOverlapsWrapper<hkpTreeBroadPhaseInternals::UpdatePairsQuery> *v10; // r9
  hkcdDynamicTree::Codec32 *m_cur; // rdx
  hkcdDynamicTree::Codec32 *v12; // rcx
  int m_size; // eax
  char *v14; // rdi
  signed int v15; // ebx
  hkLifoAllocator *v16; // rax
  int v17; // r8d
  hkLifoAllocator *v18; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::KineticAabbOverlapsWrapper<hkpTreeBroadPhaseInternals::UpdatePairsQuery> *v19; // r9
  hkcdDynamicTree::Codec32 *v20; // rdx
  hkcdDynamicTree::Codec32 *v21; // rcx
  int v22; // eax
  signed int v23; // ebx
  hkpTreeBroadPhaseSpatialTree16 treea; // [rsp+20h] [rbp-39h] BYREF
  hkArray<hkcdDynamicTree::Codec32,hkContainerHeapAllocator> v25; // [rsp+50h] [rbp-9h]
  __m128 v26; // [rsp+60h] [rbp+7h]
  __m128 m_quad; // [rsp+70h] [rbp+17h]
  __m128 v28; // [rsp+80h] [rbp+27h]
  __m128 v29; // [rsp+90h] [rbp+37h]
  __m128 v30; // [rsp+A0h] [rbp+47h]

  m_nodes = tree->m_nodes;
  v5.m_quad = (__m128)oldAabb->m_min;
  v6.m_quad = (__m128)oldAabb->m_max;
  *(_QWORD *)&treea.m_root = newAabb;
  treea.m_nodes.m_capacityAndFlags = 0x80000000;
  treea.m_numLeaves = 64;
  v8 = *(__m128 *)&tree->m_firstFree;
  treea.m_nodes.m_data = 0i64;
  treea.m_nodes.m_size = 0;
  v25 = m_nodes;
  v26 = v8;
  m_quad = v5.m_quad;
  v28 = v6.m_quad;
  if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v5.m_quad, v8), _mm_cmple_ps((__m128)m_nodes, v6.m_quad))) & 7) == 7 )
  {
    v29 = _mm_min_ps((__m128)m_nodes, v5.m_quad);
    v30 = _mm_max_ps(v8, v6.m_quad);
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkcdDynamicTree::Codec32 *)Value->m_cur;
    v12 = m_cur + 4;
    if ( Value->m_slabSize < 128 || v12 > Value->m_end )
      m_cur = (hkcdDynamicTree::Codec32 *)hkLifoAllocator::allocateFromNewSlab(Value, 128);
    else
      Value->m_cur = v12;
    treea.m_nodes.m_data = m_cur;
    *(_QWORD *)&treea.m_firstFree = m_cur;
    treea.m_nodes.m_capacityAndFlags = -2147483584;
    hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkpTreeBroadPhaseSpatialTree16,hkcdTreeQueriesStacks::Dynamic<64,unsigned short>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::CoherentKineticAabbOverlapsWrapper<hkpTreeBroadPhaseInternals::UpdatePairsQuery>>(
      this,
      &treea,
      (hkcdTreeQueriesStacks::Dynamic<64,unsigned short> *)&treea.m_root,
      v10);
    m_size = treea.m_nodes.m_size;
    v14 = *(char **)&treea.m_firstFree;
    if ( *(hkcdDynamicTree::Codec32 **)&treea.m_firstFree == treea.m_nodes.m_data )
      m_size = 0;
    treea.m_nodes.m_size = m_size;
    v15 = (2 * treea.m_numLeaves + 127) & 0xFFFFFF80;
    v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v17 = (v15 + 15) & 0xFFFFFFF0;
    if ( v15 <= v16->m_slabSize && &v14[v17] == v16->m_cur && v16->m_firstNonLifoEnd != v14 )
    {
      v16->m_cur = v14;
      goto LABEL_23;
    }
  }
  else
  {
    v18 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v20 = (hkcdDynamicTree::Codec32 *)v18->m_cur;
    v21 = v20 + 4;
    if ( v18->m_slabSize < 128 || v21 > v18->m_end )
      v20 = (hkcdDynamicTree::Codec32 *)hkLifoAllocator::allocateFromNewSlab(v18, 128);
    else
      v18->m_cur = v21;
    treea.m_nodes.m_data = v20;
    *(_QWORD *)&treea.m_firstFree = v20;
    treea.m_nodes.m_capacityAndFlags = -2147483584;
    hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkpTreeBroadPhaseSpatialTree16,hkcdTreeQueriesStacks::Dynamic<64,unsigned short>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::KineticAabbOverlapsWrapper<hkpTreeBroadPhaseInternals::UpdatePairsQuery>>(
      this,
      &treea,
      (hkcdTreeQueriesStacks::Dynamic<64,unsigned short> *)&treea.m_root,
      v19);
    v22 = treea.m_nodes.m_size;
    v14 = *(char **)&treea.m_firstFree;
    if ( *(hkcdDynamicTree::Codec32 **)&treea.m_firstFree == treea.m_nodes.m_data )
      v22 = 0;
    treea.m_nodes.m_size = v22;
    v23 = (2 * treea.m_numLeaves + 127) & 0xFFFFFF80;
    v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v17 = (v23 + 15) & 0xFFFFFFF0;
    if ( v23 <= v16->m_slabSize && &v14[v17] == v16->m_cur && v16->m_firstNonLifoEnd != v14 )
    {
      v16->m_cur = v14;
      goto LABEL_23;
    }
  }
  hkLifoAllocator::slowBlockFree(v16, v14, v17);
LABEL_23:
  treea.m_nodes.m_size = 0;
  if ( treea.m_nodes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      treea.m_nodes.m_data,
      2 * (treea.m_nodes.m_capacityAndFlags & 0x3FFFFFFF));
}

// File Line: 287
// RVA: 0xDA0990
void __fastcall hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::convexOverlaps<hkpTreeBroadPhaseSpatialTree16,hkpTreeBroadPhaseInternals::ConvexQuerySorted>(
        hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *this,
        hkpTreeBroadPhaseSpatialTree16 *tree,
        hkVector4f *planes,
        __int64 numPlanes)
{
  hkLifoAllocator *Value; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::ConvexOverlapsWrapper<hkpTreeBroadPhaseInternals::ConvexQuerySorted> *v6; // r9
  hkcdDynamicTree::Codec32 *m_cur; // rdx
  hkcdDynamicTree::Codec32 *v8; // rcx
  int m_size; // eax
  char *v10; // rdi
  signed int v11; // ebx
  hkLifoAllocator *v12; // rax
  int v13; // r8d
  hkpTreeBroadPhaseSpatialTree16 treea; // [rsp+20h] [rbp-48h] BYREF
  hkpTreeBroadPhaseSpatialTree16 *v15; // [rsp+50h] [rbp-18h]
  int v16; // [rsp+58h] [rbp-10h]

  *(_QWORD *)&treea.m_sortPath = this;
  *(_QWORD *)&treea.m_root = numPlanes;
  v15 = tree;
  v16 = (int)planes;
  treea.m_nodes.m_capacityAndFlags = 0x80000000;
  treea.m_numLeaves = 64;
  treea.m_nodes.m_data = 0i64;
  treea.m_nodes.m_size = 0;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (hkcdDynamicTree::Codec32 *)Value->m_cur;
  v8 = m_cur + 4;
  if ( Value->m_slabSize < 128 || v8 > Value->m_end )
    m_cur = (hkcdDynamicTree::Codec32 *)hkLifoAllocator::allocateFromNewSlab(Value, 128);
  else
    Value->m_cur = v8;
  treea.m_nodes.m_data = m_cur;
  *(_QWORD *)&treea.m_firstFree = m_cur;
  treea.m_nodes.m_capacityAndFlags = -2147483584;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkpTreeBroadPhaseSpatialTree16,hkcdTreeQueriesStacks::Dynamic<64,unsigned short>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::ConvexOverlapsWrapper<hkpTreeBroadPhaseInternals::ConvexQuerySorted>>(
    this,
    &treea,
    (hkcdTreeQueriesStacks::Dynamic<64,unsigned short> *)&treea.m_root,
    v6);
  m_size = treea.m_nodes.m_size;
  v10 = *(char **)&treea.m_firstFree;
  if ( *(hkcdDynamicTree::Codec32 **)&treea.m_firstFree == treea.m_nodes.m_data )
    m_size = 0;
  treea.m_nodes.m_size = m_size;
  v11 = (2 * treea.m_numLeaves + 127) & 0xFFFFFF80;
  v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v13 = (v11 + 15) & 0xFFFFFFF0;
  if ( v11 > v12->m_slabSize || &v10[v13] != v12->m_cur || v12->m_firstNonLifoEnd == v10 )
    hkLifoAllocator::slowBlockFree(v12, v10, v13);
  else
    v12->m_cur = v10;
  treea.m_nodes.m_size = 0;
  if ( treea.m_nodes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      treea.m_nodes.m_data,
      2 * (treea.m_nodes.m_capacityAndFlags & 0x3FFFFFFF));
}

// File Line: 322
// RVA: 0xE00CE0
hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *__fastcall hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::rayCast<hkpBvCompressedMeshShapeTree,hkpBvCompressedMeshShape_Internals::RayCastQuery>(
        hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *this,
        hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *result,
        hkpBvCompressedMeshShapeTree *tree,
        hkcdRay *ray)
{
  hkcdStaticTree::DynamicStorage5 v4; // xmm0
  hkVector4f v5; // xmm1
  hkVector4f v8; // xmm0
  hkLifoAllocator *Value; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::RayCastWrapper<hkpBvCompressedMeshShape_Internals::RayCastQuery> *v10; // r9
  __int64 m_cur; // rdx
  void *v12; // rcx
  int v13; // eax
  char *v14; // rdi
  signed int v15; // ebx
  hkLifoAllocator *v16; // rax
  int v17; // r8d
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *v18; // rax
  _BYTE v19[120]; // [rsp+20h] [rbp-78h] BYREF

  v4 = tree->hkcdStaticTree::DynamicStorage5;
  v5.m_quad = (__m128)tree->m_domain.m_min;
  *(_QWORD *)&v19[32] = ray;
  *(_DWORD *)&v19[96] = -1;
  *(_DWORD *)&v19[12] = 0x80000000;
  *(hkcdStaticTree::DynamicStorage5 *)&v19[48] = v4;
  v8.m_quad = (__m128)tree->m_domain.m_max;
  *(hkVector4f *)&v19[64] = (hkVector4f)v5.m_quad;
  *(_QWORD *)v19 = 0i64;
  *(_DWORD *)&v19[8] = 0;
  *(_DWORD *)&v19[24] = 64;
  *(hkVector4f *)&v19[80] = (hkVector4f)v8.m_quad;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (__int64)Value->m_cur;
  v12 = (void *)(m_cur + 3072);
  if ( Value->m_slabSize < 3072 || v12 > Value->m_end )
    m_cur = hkLifoAllocator::allocateFromNewSlab(Value, 3072);
  else
    Value->m_cur = v12;
  *(_QWORD *)v19 = m_cur;
  *(_QWORD *)&v19[16] = m_cur;
  *(_DWORD *)&v19[12] = -2147483584;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkpBvCompressedMeshShapeTree,hkcdTreeQueriesStacks::Dynamic<64,hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5>::Slot>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::RayCastWrapper<hkpBvCompressedMeshShape_Internals::RayCastQuery>>(
    result,
    (hkpBvCompressedMeshShapeTree *)v19,
    (hkcdTreeQueriesStacks::Dynamic<64,hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5>::Slot> *)&v19[32],
    v10);
  v13 = *(_DWORD *)&v19[8];
  v14 = *(char **)&v19[16];
  if ( *(_QWORD *)&v19[16] == *(_QWORD *)v19 )
    v13 = 0;
  *(_DWORD *)&v19[8] = v13;
  v15 = (48 * *(_DWORD *)&v19[24] + 127) & 0xFFFFFF80;
  v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (v15 + 15) & 0xFFFFFFF0;
  if ( v15 > v16->m_slabSize || &v14[v17] != v16->m_cur || v16->m_firstNonLifoEnd == v14 )
    hkLifoAllocator::slowBlockFree(v16, v14, v17);
  else
    v16->m_cur = v14;
  *(_DWORD *)&v19[8] = 0;
  if ( *(int *)&v19[12] >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      *(void **)v19,
      48 * (*(_DWORD *)&v19[12] & 0x3FFFFFFF));
  v18 = this;
  *(__m128 *)this = _mm_shuffle_ps(*(__m128 *)&v19[64], *(__m128 *)&v19[64], 255);
  return v18;
}

// File Line: 352
// RVA: 0xDADA90
void __fastcall hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::rayCastBatch<hkpTreeBroadPhaseSpatialTree32,hkpTreeBroadPhaseInternals::RayCastFanQuery>(
        hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *this,
        hkpTreeBroadPhaseSpatialTree32 *tree,
        hkcdRay *rays,
        __int64 numRays,
        hkpTreeBroadPhaseInternals::RayCastFanQuery *query)
{
  int v5; // r15d
  int v8; // r14d
  int v9; // edi
  __int64 v10; // rdx
  char *v11; // rax
  unsigned int *p_m_root; // rcx
  __int128 v13; // xmm0
  __int128 v14; // xmm1
  __int128 v15; // xmm0
  hkLifoAllocator *Value; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::RayCastBatchWrapper<hkpTreeBroadPhaseInternals::RayCastFanQuery> *v17; // r9
  hkcdDynamicTree::CodecRawUint *m_cur; // rdx
  hkVector4f *p_m_max; // rcx
  int m_size; // eax
  char *v21; // rsi
  signed int v22; // ebx
  hkLifoAllocator *v23; // rax
  int v24; // r8d
  hkpTreeBroadPhaseSpatialTree32 treea; // [rsp+20h] [rbp-B8h] BYREF
  char v26; // [rsp+70h] [rbp-68h] BYREF
  int v27; // [rsp+168h] [rbp+90h]
  int v28; // [rsp+16Ch] [rbp+94h]
  char v29; // [rsp+170h] [rbp+98h]
  char v30; // [rsp+171h] [rbp+99h]

  if ( (int)rays > 0 )
  {
    v5 = (int)rays;
    v27 = 0;
    v8 = 0;
    *(_QWORD *)&treea.m_root = numRays;
    do
    {
      v9 = v5 - v8;
      if ( v5 - v8 > 4 )
        v9 = 4;
      v10 = v9;
      if ( v9 > 0 )
      {
        v11 = &v26;
        p_m_root = &tree[v8].m_root;
        do
        {
          v13 = *((_OWORD *)p_m_root - 2);
          v14 = *((_OWORD *)p_m_root - 1);
          v11 += 48;
          p_m_root += 12;
          *((_OWORD *)v11 - 5) = v13;
          v15 = *((_OWORD *)p_m_root - 3);
          *((_OWORD *)v11 - 4) = v14;
          *((_OWORD *)v11 - 3) = v15;
          --v10;
        }
        while ( v10 );
      }
      v28 = v8;
      treea.m_nodes.m_data = 0i64;
      treea.m_nodes.m_size = 0;
      treea.m_nodes.m_capacityAndFlags = 0x80000000;
      v30 = (1 << v9) - 1;
      v29 = v30;
      treea.m_numLeaves = 64;
      Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      m_cur = (hkcdDynamicTree::CodecRawUint *)Value->m_cur;
      p_m_max = &m_cur[5].m_aabb.m_max;
      if ( Value->m_slabSize < 256 || p_m_max > Value->m_end )
        m_cur = (hkcdDynamicTree::CodecRawUint *)hkLifoAllocator::allocateFromNewSlab(Value, 256);
      else
        Value->m_cur = p_m_max;
      treea.m_nodes.m_data = m_cur;
      *(_QWORD *)&treea.m_firstFree = m_cur;
      treea.m_nodes.m_capacityAndFlags = -2147483584;
      hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkpTreeBroadPhaseSpatialTree32,hkcdTreeQueriesStacks::Dynamic<64,unsigned int>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::RayCastBatchWrapper<hkpTreeBroadPhaseInternals::RayCastFanQuery>>(
        this,
        &treea,
        (hkcdTreeQueriesStacks::Dynamic<64,unsigned int> *)&treea.m_root,
        v17);
      m_size = treea.m_nodes.m_size;
      v21 = *(char **)&treea.m_firstFree;
      if ( *(hkcdDynamicTree::CodecRawUint **)&treea.m_firstFree == treea.m_nodes.m_data )
        m_size = 0;
      treea.m_nodes.m_size = m_size;
      v22 = (4 * treea.m_numLeaves + 127) & 0xFFFFFF80;
      v23 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v24 = (v22 + 15) & 0xFFFFFFF0;
      if ( v22 > v23->m_slabSize || &v21[v24] != v23->m_cur || v23->m_firstNonLifoEnd == v21 )
        hkLifoAllocator::slowBlockFree(v23, v21, v24);
      else
        v23->m_cur = v21;
      treea.m_nodes.m_size = 0;
      if ( treea.m_nodes.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          treea.m_nodes.m_data,
          4 * treea.m_nodes.m_capacityAndFlags);
      v8 += v9;
    }
    while ( v8 < v5 );
  }
}

// File Line: 367
// RVA: 0xDA1830
void __fastcall hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::rayCastFan<hkpTreeBroadPhaseSpatialTree16,hkpTreeBroadPhaseInternals::RayCastFanQuery>(
        hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *this,
        hkpTreeBroadPhaseSpatialTree16 *tree,
        hkVector4f *from,
        hkVector4f *to,
        __int64 numRays)
{
  hkpTreeBroadPhaseInternals::RayCastFanQuery *v5; // xmm7_8
  __int64 v7; // rsi
  hkLifoAllocator *Value; // rax
  hkpTreeBroadPhaseSpatialTree16 *m_cur; // rdi
  int v12; // ebx
  char *v13; // rcx
  __int64 v14; // rdx
  unsigned __int16 *p_m_firstFree; // rcx
  __m128 m_quad; // xmm4
  __m128i v17; // xmm4
  __m128 v18; // xmm3
  __m128 v19; // xmm1
  int v20; // eax
  hkLifoAllocator *v21; // rax
  int v22; // r8d
  hkpTreeBroadPhaseInternals::RayCastFanQuery *v23; // [rsp+20h] [rbp-38h]

  v7 = (int)to;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (hkpTreeBroadPhaseSpatialTree16 *)Value->m_cur;
  v12 = (48 * v7 + 127) & 0xFFFFFF80;
  v13 = (char *)m_cur + v12;
  if ( v12 > Value->m_slabSize || v13 > Value->m_end )
    m_cur = (hkpTreeBroadPhaseSpatialTree16 *)hkLifoAllocator::allocateFromNewSlab(Value, v12);
  else
    Value->m_cur = v13;
  v14 = v7;
  if ( (int)v7 > 0 )
  {
    v23 = v5;
    p_m_firstFree = &m_cur->m_firstFree;
    do
    {
      m_quad = from->m_quad;
      p_m_firstFree += 24;
      ++from;
      v17 = (__m128i)_mm_sub_ps(m_quad, (__m128)tree->m_nodes);
      v18 = _mm_cmpeq_ps((__m128)0i64, (__m128)v17);
      v19 = _mm_rcp_ps((__m128)v17);
      *((__m128 *)p_m_firstFree - 3) = _mm_shuffle_ps((__m128)v17, _mm_unpackhi_ps((__m128)v17, query.m_quad), 196);
      v20 = _mm_movemask_ps(_mm_cmple_ps((__m128)0i64, *((__m128 *)p_m_firstFree - 3))) & 7 | 0x3F000000;
      *((__m128 *)p_m_firstFree - 2) = _mm_or_ps(
                                         _mm_and_ps(
                                           _mm_xor_ps(
                                             (__m128)_mm_slli_epi32(_mm_srli_epi32(v17, 0x1Fu), 0x1Fu),
                                             (__m128)_xmm),
                                           v18),
                                         _mm_andnot_ps(
                                           v18,
                                           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v19, (__m128)v17)), v19)));
      *((_DWORD *)p_m_firstFree - 5) = v20;
      *((_OWORD *)p_m_firstFree - 4) = tree->m_nodes;
      --v14;
    }
    while ( v14 );
  }
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::rayCastBatch<hkpTreeBroadPhaseSpatialTree16,hkpTreeBroadPhaseInternals::RayCastFanQuery>(
    this,
    m_cur,
    (hkcdRay *)(unsigned int)v7,
    numRays,
    v23);
  v21 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v22 = (v12 + 15) & 0xFFFFFFF0;
  if ( v12 > v21->m_slabSize || (char *)m_cur + v22 != v21->m_cur || v21->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v21, (char *)m_cur, v22);
  else
    v21->m_cur = m_cur;
}

// File Line: 393
// RVA: 0xE00AD0
hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *__fastcall hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::aabbCast<hkpBvCompressedMeshShapeTree,hkpBvCompressedMeshShape_Internals::AabbCastQuery>(
        hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *this,
        hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *result,
        hkpBvCompressedMeshShapeTree *tree,
        hkAabb *from,
        hkVector4f *to)
{
  hkVector4f v5; // xmm6
  hkVector4f v8; // xmm7
  hkcdStaticTree::DynamicStorage5 v9; // xmm8
  hkArray<unsigned short,hkContainerHeapAllocator> v10; // xmm7
  __m128 v11; // xmm8
  __m128i v12; // xmm6
  __m128 v13; // xmm3
  __m128 v14; // xmm1
  hkLifoAllocator *Value; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbCastWrapper<hkpBvCompressedMeshShape_Internals::AabbCastQuery> *v16; // r9
  __int64 m_cur; // rcx
  void *v18; // rdx
  int m_size; // eax
  char *v20; // rdi
  signed int v21; // ebx
  hkLifoAllocator *v22; // rax
  int v23; // r8d
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *v24; // rax
  hkpBvCompressedMeshShapeTree treea; // [rsp+18h] [rbp-69h] BYREF
  unsigned __int64 v26; // [rsp+F8h] [rbp+77h]

  v5.m_quad = (__m128)from->m_min;
  treea.m_nodes.m_capacityAndFlags = 0x80000000;
  treea.m_domain.m_min.m_quad.m128_i32[2] = 64;
  treea.m_nodes.m_data = 0i64;
  v8.m_quad = (__m128)tree->m_domain.m_min;
  treea.m_nodes.m_size = 0;
  v9 = tree->hkcdStaticTree::DynamicStorage5;
  treea.m_domain.m_max.m_quad.m128_u64[0] = v26;
  v10 = (hkArray<unsigned short,hkContainerHeapAllocator>)_mm_mul_ps(
                                                            _mm_sub_ps(v8.m_quad, (__m128)v9),
                                                            (__m128)xmmword_141A711B0);
  v11 = _mm_mul_ps(_mm_add_ps((__m128)v9, tree->m_domain.m_min.m_quad), (__m128)xmmword_141A711B0);
  treea.m_sharedVerticesIndex = v10;
  v12 = (__m128i)_mm_sub_ps(v5.m_quad, v11);
  *(__m128 *)&treea.m_numPrimitiveKeys = v11;
  v13 = _mm_cmpeq_ps((__m128)0i64, (__m128)v12);
  v14 = _mm_rcp_ps((__m128)v12);
  treea.m_sections = (hkArray<hkcdStaticMeshTreeBase::Section,hkContainerHeapAllocator>)_mm_shuffle_ps(
                                                                                          (__m128)v12,
                                                                                          _mm_unpackhi_ps(
                                                                                            (__m128)v12,
                                                                                            _mm_shuffle_ps(
                                                                                              (__m128)(unsigned int)to,
                                                                                              (__m128)(unsigned int)to,
                                                                                              0)),
                                                                                          196);
  treea.m_primitives = (hkArray<hkcdStaticMeshTreeBase::Primitive,hkContainerHeapAllocator>)_mm_or_ps(
                                                                                              _mm_and_ps(
                                                                                                _mm_xor_ps(
                                                                                                  (__m128)_mm_slli_epi32(_mm_srli_epi32(v12, 0x1Fu), 0x1Fu),
                                                                                                  (__m128)_xmm),
                                                                                                v13),
                                                                                              _mm_andnot_ps(
                                                                                                v13,
                                                                                                _mm_mul_ps(
                                                                                                  _mm_sub_ps(
                                                                                                    (__m128)_xmm,
                                                                                                    _mm_mul_ps((__m128)v12, v14)),
                                                                                                  v14)));
  treea.m_primitives.m_capacityAndFlags = _mm_movemask_ps(_mm_cmple_ps((__m128)0i64, (__m128)treea.m_sections)) & 7 | 0x3F000000;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (__int64)Value->m_cur;
  v18 = (void *)(m_cur + 3072);
  if ( Value->m_slabSize < 3072 || v18 > Value->m_end )
    m_cur = hkLifoAllocator::allocateFromNewSlab(Value, 3072);
  else
    Value->m_cur = v18;
  treea.m_domain.m_min.m_quad.m128_u64[0] = m_cur;
  treea.m_nodes.m_capacityAndFlags = -2147483584;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkpBvCompressedMeshShapeTree,hkcdTreeQueriesStacks::Dynamic<64,hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5>::Slot>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbCastWrapper<hkpBvCompressedMeshShape_Internals::AabbCastQuery>>(
    result,
    &treea,
    (hkcdTreeQueriesStacks::Dynamic<64,hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5>::Slot> *)&treea.m_domain.m_max,
    v16);
  m_size = treea.m_nodes.m_size;
  v20 = (char *)treea.m_domain.m_min.m_quad.m128_u64[0];
  if ( (hkcdStaticTree::Codec3Axis5 *)treea.m_domain.m_min.m_quad.m128_u64[0] == treea.m_nodes.m_data )
    m_size = 0;
  treea.m_nodes.m_size = m_size;
  v21 = (48 * treea.m_domain.m_min.m_quad.m128_i32[2] + 127) & 0xFFFFFF80;
  v22 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v23 = (v21 + 15) & 0xFFFFFFF0;
  if ( v21 > v22->m_slabSize || &v20[v23] != v22->m_cur || v22->m_firstNonLifoEnd == v20 )
    hkLifoAllocator::slowBlockFree(v22, v20, v23);
  else
    v22->m_cur = v20;
  treea.m_nodes.m_size = 0;
  if ( treea.m_nodes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      treea.m_nodes.m_data,
      48 * (treea.m_nodes.m_capacityAndFlags & 0x3FFFFFFF));
  v24 = this;
  *(__m128 *)this = _mm_shuffle_ps((__m128)treea.m_sections, (__m128)treea.m_sections, 255);
  return v24;
}

// File Line: 420
// RVA: 0xCD6610
hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *__fastcall hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::closest<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,NearestFeaturePolicy>(
        hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *this,
        hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *result,
        hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *tree,
        hkVector4f *point,
        NearestFeaturePolicy *query)
{
  hkVector4f v7; // xmm1
  hkLifoAllocator *Value; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::ClosestFromPointWrapper<NearestFeaturePolicy> *v9; // r9
  hkcdDynamicTree::CodecRawUlong *m_cur; // rdx
  hkcdDynamicTree::CodecRawUlong *v11; // rcx
  int m_size; // eax
  char *m_firstFree; // rdi
  signed int v14; // ebx
  hkLifoAllocator *v15; // rax
  int v16; // r8d
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *v17; // rax
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> treea; // [rsp+20h] [rbp-68h] BYREF
  hkArray<hkcdDynamicTree::CodecRawUlong,hkContainerHeapAllocator> m_nodes; // [rsp+50h] [rbp-38h]
  __m128 m_quad; // [rsp+60h] [rbp-28h]
  int v21; // [rsp+70h] [rbp-18h]

  m_nodes = tree->m_nodes;
  v7.m_quad = (__m128)query->m_normal;
  treea.m_root = (unsigned __int64)point;
  v21 = 0;
  treea.m_nodes.m_data = 0i64;
  m_quad = v7.m_quad;
  treea.m_nodes.m_size = 0;
  treea.m_nodes.m_capacityAndFlags = 0x80000000;
  treea.m_numLeaves = 64;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (hkcdDynamicTree::CodecRawUlong *)Value->m_cur;
  v11 = m_cur + 8;
  if ( Value->m_slabSize < 512 || v11 > Value->m_end )
    m_cur = (hkcdDynamicTree::CodecRawUlong *)hkLifoAllocator::allocateFromNewSlab(Value, 512);
  else
    Value->m_cur = v11;
  treea.m_nodes.m_data = m_cur;
  treea.m_firstFree = (unsigned __int64)m_cur;
  treea.m_nodes.m_capacityAndFlags = -2147483584;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,hkcdTreeQueriesStacks::Dynamic<64,unsigned __int64>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::ClosestFromPointWrapper<NearestFeaturePolicy>>(
    result,
    &treea,
    (hkcdTreeQueriesStacks::Dynamic<64,unsigned __int64> *)&treea.m_root,
    v9);
  m_size = treea.m_nodes.m_size;
  m_firstFree = (char *)treea.m_firstFree;
  if ( (hkcdDynamicTree::CodecRawUlong *)treea.m_firstFree == treea.m_nodes.m_data )
    m_size = 0;
  treea.m_nodes.m_size = m_size;
  v14 = (8 * treea.m_numLeaves + 127) & 0xFFFFFF80;
  v15 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v16 = (v14 + 15) & 0xFFFFFFF0;
  if ( v14 > v15->m_slabSize || &m_firstFree[v16] != v15->m_cur || v15->m_firstNonLifoEnd == m_firstFree )
    hkLifoAllocator::slowBlockFree(v15, m_firstFree, v16);
  else
    v15->m_cur = m_firstFree;
  treea.m_nodes.m_size = 0;
  if ( treea.m_nodes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      treea.m_nodes.m_data,
      8 * treea.m_nodes.m_capacityAndFlags);
  v17 = this;
  *(__m128 *)this = m_quad;
  return v17;
}

// File Line: 448
// RVA: 0xC90750
void __fastcall hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::allPairs<hkcdDynamicTree::DefaultTree48Storage,WrappedAllPairsQuery<hkcdDynamicTree::DefaultTree48Storage>>(
        hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *this,
        hkcdDynamicTree::DefaultTree48Storage *tree,
        WrappedAllPairsQuery<hkcdDynamicTree::DefaultTree48Storage> *query)
{
  hkLifoAllocator *Value; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *v5; // rcx
  hkcdDynamicTree::CodecRawUint *m_cur; // r8
  unsigned int *p_m_parent; // rdx
  int m_size; // eax
  char *v9; // rdi
  signed int v10; // ebx
  hkLifoAllocator *v11; // rax
  int v12; // r8d
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::NodeContext *v13; // [rsp+38h] [rbp-30h]
  hkcdDynamicTree::DefaultTree48Storage treeB; // [rsp+40h] [rbp-28h] BYREF
  hkcdDynamicTree::DefaultTree48Storage *stackInstance; // [rsp+78h] [rbp+10h] BYREF

  stackInstance = tree;
  treeB.m_nodes.m_capacityAndFlags = 0x80000000;
  treeB.m_numLeaves = 64;
  treeB.m_nodes.m_data = 0i64;
  treeB.m_nodes.m_size = 0;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (hkcdDynamicTree::CodecRawUint *)Value->m_cur;
  p_m_parent = &m_cur[10].m_parent;
  if ( Value->m_slabSize < 512 || p_m_parent > Value->m_end )
    m_cur = (hkcdDynamicTree::CodecRawUint *)hkLifoAllocator::allocateFromNewSlab(Value, 512);
  else
    Value->m_cur = p_m_parent;
  treeB.m_nodes.m_data = m_cur;
  *(_QWORD *)&treeB.m_firstFree = m_cur;
  LOBYTE(v5) = 1;
  treeB.m_nodes.m_capacityAndFlags = -2147483584;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::binary<hkcdDynamicTree::DefaultTree48Storage,hkcdDynamicTree::DefaultTree48Storage,hkcdTreeQueriesStacks::Dynamic<64,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::SlotPair<hkcdDynamicTree::DefaultTree48Storage,hkcdDynamicTree::DefaultTree48Storage>>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AllPairsWrapper<WrappedAllPairsQuery<hkcdDynamicTree::DefaultTree48Storage>>>(
    v5,
    (bool)this,
    (hkcdDynamicTree::DefaultTree48Storage *)this,
    &treeB,
    (hkcdTreeQueriesStacks::Dynamic<64,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::SlotPair<hkcdDynamicTree::DefaultTree48Storage,hkcdDynamicTree::DefaultTree48Storage> > *)&stackInstance,
    0i64,
    0i64,
    v13);
  m_size = treeB.m_nodes.m_size;
  v9 = *(char **)&treeB.m_firstFree;
  if ( *(hkcdDynamicTree::CodecRawUint **)&treeB.m_firstFree == treeB.m_nodes.m_data )
    m_size = 0;
  treeB.m_nodes.m_size = m_size;
  v10 = (8 * treeB.m_numLeaves + 127) & 0xFFFFFF80;
  v11 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (v10 + 15) & 0xFFFFFFF0;
  if ( v10 > v11->m_slabSize || &v9[v12] != v11->m_cur || v11->m_firstNonLifoEnd == v9 )
    hkLifoAllocator::slowBlockFree(v11, v9, v12);
  else
    v11->m_cur = v9;
  treeB.m_nodes.m_size = 0;
  if ( treeB.m_nodes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      treeB.m_nodes.m_data,
      8 * treeB.m_nodes.m_capacityAndFlags);
}

// File Line: 457
// RVA: 0xCD5BE0
void __fastcall hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::allPairs<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,TrianglePairCollector>(
        hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *this,
        hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *treeA,
        hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *treeB,
        TrianglePairCollector *query)
{
  char v4; // di
  hkLifoAllocator *Value; // rax
  hkcdDynamicTree::CodecRawUlong *m_cur; // r8
  hkcdDynamicTree::CodecRawUlong *v8; // rdx
  int m_size; // eax
  char *m_firstFree; // rdi
  signed int v11; // ebx
  hkLifoAllocator *v12; // rax
  int v13; // r8d
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::NodeContext *v14; // [rsp+38h] [rbp-30h]
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> treeBa; // [rsp+40h] [rbp-28h] BYREF
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *stackInstance; // [rsp+80h] [rbp+18h] BYREF

  v4 = (char)this;
  stackInstance = treeB;
  treeBa.m_nodes.m_capacityAndFlags = 0x80000000;
  treeBa.m_nodes.m_data = 0i64;
  treeBa.m_nodes.m_size = 0;
  treeBa.m_numLeaves = 64;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (hkcdDynamicTree::CodecRawUlong *)Value->m_cur;
  v8 = m_cur + 16;
  if ( Value->m_slabSize < 1024 || v8 > Value->m_end )
    m_cur = (hkcdDynamicTree::CodecRawUlong *)hkLifoAllocator::allocateFromNewSlab(Value, 1024);
  else
    Value->m_cur = v8;
  treeBa.m_nodes.m_data = m_cur;
  treeBa.m_firstFree = (unsigned __int64)m_cur;
  treeBa.m_nodes.m_capacityAndFlags = -2147483584;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::binary<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,hkcdTreeQueriesStacks::Dynamic<64,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::SlotPair<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>>>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AllPairsWrapper<TrianglePairCollector>>(
    0i64,
    v4,
    treeA,
    &treeBa,
    (hkcdTreeQueriesStacks::Dynamic<64,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::SlotPair<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> > > *)&stackInstance,
    0i64,
    0i64,
    v14);
  m_size = treeBa.m_nodes.m_size;
  m_firstFree = (char *)treeBa.m_firstFree;
  if ( (hkcdDynamicTree::CodecRawUlong *)treeBa.m_firstFree == treeBa.m_nodes.m_data )
    m_size = 0;
  treeBa.m_nodes.m_size = m_size;
  v11 = (16 * treeBa.m_numLeaves + 127) & 0xFFFFFF80;
  v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v13 = (v11 + 15) & 0xFFFFFFF0;
  if ( v11 > v12->m_slabSize || &m_firstFree[v13] != v12->m_cur || v12->m_firstNonLifoEnd == m_firstFree )
    hkLifoAllocator::slowBlockFree(v12, m_firstFree, v13);
  else
    v12->m_cur = m_firstFree;
  treeBa.m_nodes.m_size = 0;
  if ( treeBa.m_nodes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      treeBa.m_nodes.m_data,
      16 * treeBa.m_nodes.m_capacityAndFlags);
}

