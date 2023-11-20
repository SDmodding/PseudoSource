// File Line: 14
// RVA: 0xDAE7A0
void __fastcall hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkpTreeBroadPhaseSpatialTree32,hkcdTreeQueriesStacks::Dynamic<64,unsigned int>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::CoherentKineticAabbOverlapsWrapper<hkpTreeBroadPhaseInternals::UpdatePairsQuery>>(hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *this, hkpTreeBroadPhaseSpatialTree32 *tree, hkcdTreeQueriesStacks::Dynamic<64,unsigned int> *stackInstance, hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::CoherentKineticAabbOverlapsWrapper<hkpTreeBroadPhaseInternals::UpdatePairsQuery> *query)
{
  __int64 v4; // rax
  hkcdTreeQueriesStacks::Dynamic<64,unsigned int> *v5; // r14
  hkpTreeBroadPhaseSpatialTree32 *v6; // rbx
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *v7; // r15
  int v8; // er12
  __m128 *v9; // rdx
  __m128 v10; // xmm6
  __m128 v11; // xmm7
  __int64 v12; // rax
  __int64 v13; // rsi
  signed int v14; // er8
  __m128 v15; // xmm1
  signed __int64 v16; // rdi
  __m128 v17; // xmm3
  int v18; // er8
  int v19; // er8
  int v20; // er8
  __int64 v21; // r8
  int *v22; // rdx
  unsigned int *v23; // rsi
  __int64 v24; // rbp
  char v25; // dl
  char v26; // al
  __m128 v27; // xmm6
  int v28; // edx
  _DWORD *v29; // rdi
  _QWORD *v30; // rcx
  __int64 v31; // rax
  int v32; // edx
  hkcdDynamicTree::CodecRawUint *v33; // rax
  int v34; // edx

  v4 = *(unsigned int *)&this[32];
  v5 = stackInstance;
  v6 = tree;
  v7 = this;
  if ( (_DWORD)v4 )
  {
    v8 = tree->m_nodes.m_size;
    v9 = (__m128 *)(*(_QWORD *)this + 48 * v4);
    v10 = *v9;
    v11 = v9[1];
    if ( (_mm_movemask_ps(
            _mm_and_ps(
              _mm_cmpleps(*v9, (__m128)stackInstance[3].m_stack.0),
              _mm_cmpleps(*(__m128 *)&stackInstance[2].m_stack.m_localMemory, v11))) & 7) == 7 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          v12 = v9[2].m128_u32[1];
          if ( (_DWORD)v12 )
            break;
          v23 = v5->m_stack.m_data;
          v24 = *(_QWORD *)(*(_QWORD *)v5->m_stack.m_data + 16i64 * v9[2].m128_u32[2]);
          if ( v24 == *((_QWORD *)v5->m_stack.m_data + 3) )
            goto LABEL_25;
          v25 = 0;
          v26 = _mm_movemask_ps(
                  _mm_and_ps(
                    _mm_cmpleps(v10, (__m128)v5[2].m_stack.0),
                    _mm_cmpleps(*(__m128 *)&v5[1].m_stack.m_localMemory, v11))) & 7;
          v27 = _mm_and_ps(
                  _mm_cmpleps(v10, (__m128)v5[1].m_stack.0),
                  _mm_cmpleps(*(__m128 *)&v5->m_stack.m_localMemory, v11));
          if ( v26 == 7 )
            v25 = 2;
          v28 = ((((_mm_movemask_ps(v27) & 7) == 7) | (unsigned __int8)v25) & 3) - 1;
          if ( v28 )
          {
            if ( v28 != 1 )
              goto LABEL_25;
            v29 = (_DWORD *)*((_QWORD *)v23 + 1);
          }
          else
          {
            v29 = (_DWORD *)*((_QWORD *)v23 + 2);
          }
          if ( v29[2] == (v29[3] & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v29, 16);
          v30 = (_QWORD *)(*(_QWORD *)v29 + 16i64 * (signed int)v29[2]++);
          v31 = *((_QWORD *)v23 + 3);
          v30[1] = v24;
          *v30 = v31;
LABEL_25:
          v32 = v6->m_nodes.m_size;
          if ( v32 <= v8 )
            return;
          v33 = v6->m_nodes.m_data;
          v34 = v32 - 1;
          v6->m_nodes.m_size = v34;
          v9 = (__m128 *)(*(_QWORD *)v7 + 48i64 * v33->m_aabb.m_min.m_quad.m128_u32[v34]);
          v10 = *v9;
          v11 = v9[1];
        }
        v13 = v9[2].m128_u32[2];
        v14 = 0;
        v15 = *(__m128 *)&v5[2].m_stack.m_localMemory;
        v16 = *(_QWORD *)v7 + 48 * v12;
        v9 = (__m128 *)(*(_QWORD *)v7 + 48 * v13);
        v10 = *(__m128 *)v16;
        v11 = *(__m128 *)(v16 + 16);
        v17 = _mm_and_ps(_mm_cmpleps(v15, v11), _mm_cmpleps(*(__m128 *)v16, (__m128)v5[3].m_stack.0));
        if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v15, v9[1]), _mm_cmpleps(*v9, (__m128)v5[3].m_stack.0))) & 7) == 7 )
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
          if ( v6->m_nodes.m_size == (v6->m_nodes.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, 4);
          v21 = v6->m_nodes.m_size;
          v22 = &v6->m_nodes.m_data->m_aabb.m_min.m_quad.m128_i32[v21];
          v6->m_nodes.m_size = v21 + 1;
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
void __fastcall hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::binary<hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>>,hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>>,hkcdTreeQueriesStacks::Dynamic<64,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::SlotPair<hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>>,hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>>>>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AllPairsWrapper<hkpTreeBroadPhaseInternals::InsertionQuery>>(hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *this, __int64 self, hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> > *treeA, hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> > *treeB, hkcdTreeQueriesStacks::Dynamic<64,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::SlotPair<hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> >,hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> > > > *stackInstance, hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AllPairsWrapper<hkpTreeBroadPhaseInternals::InsertionQuery> *query, hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> >::NodeContext *rootContextA, hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> >::NodeContext *rootContextB)
{
  unsigned __int64 v8; // rdi
  __int64 v9; // rsi
  hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> > *v10; // rbx
  hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> > *v11; // r13
  __int64 v12; // r15
  __m128 v13; // xmm6
  __m128 v14; // xmm7
  hkpTreeBroadPhaseInternals::InsertionQuery *v15; // rsi
  unsigned __int64 v16; // rbp
  hkVector4f v17; // xmm2
  hkVector4f v18; // xmm3
  hkcdDynamicTree::CodecRawUlong *v19; // rdi
  unsigned __int64 v20; // r14
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *v21; // rsi
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
  __m128 v34; // xmm5
  __m128 v35; // xmm4
  __m128 v36; // xmm0
  BOOL v37; // er13
  BOOL v38; // er12
  _QWORD *v39; // rcx
  _QWORD *v40; // rcx
  unsigned __int64 *v41; // rcx
  unsigned __int64 *v42; // rcx
  float v43; // eax
  int v44; // eax
  BOOL v45; // edi
  _QWORD *v46; // rcx
  unsigned __int64 v47; // rsi
  unsigned __int64 *v48; // rcx
  unsigned __int64 *v49; // rcx
  unsigned __int64 v50; // rbp
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> **v51; // rcx
  float v52; // [rsp+20h] [rbp-88h]
  char v53; // [rsp+B0h] [rbp+8h]
  BOOL v54; // [rsp+B8h] [rbp+10h]
  hkcdDynamicTree::Tree<hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> > *v55; // [rsp+C0h] [rbp+18h]

  v55 = treeA;
  v53 = (char)this;
  v8 = treeA->m_root;
  v9 = *(_QWORD *)(self + 1048);
  v10 = treeB;
  v11 = treeA;
  v12 = self;
  if ( v9 != 0 && v8 != 0 )
  {
    v52 = treeB->m_nodes[0].m_aabb.m_min.m_quad.m128_f32[2];
    if ( query )
    {
      v13 = *(__m128 *)&query->m_query;
      v14 = *(__m128 *)&query[2].m_query;
      v15 = query[4].m_query;
      v16 = (unsigned __int64)query[5].m_query;
    }
    else
    {
      v16 = *(_QWORD *)(self + 1048);
      v15 = (hkpTreeBroadPhaseInternals::InsertionQuery *)(self + (v9 << 6));
      v13 = *(__m128 *)v15;
      v14 = (__m128)v15[1];
    }
    if ( rootContextA )
    {
      v17.m_quad = (__m128)rootContextA->m_aabb.m_min;
      v18.m_quad = (__m128)rootContextA->m_aabb.m_max;
      v19 = rootContextA->m_node;
      v20 = rootContextA->m_index;
    }
    else
    {
      v20 = treeA->m_root;
      v19 = &treeA->m_nodes[v8];
      v17.m_quad = (__m128)v19->m_aabb.m_min;
      v18.m_quad = (__m128)v19->m_aabb.m_max;
    }
    if ( (_BYTE)this
      || (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v13, v18.m_quad), _mm_cmpleps(v17.m_quad, v14))) & 7) == 7 )
    {
      while ( 1 )
      {
        while ( (_BYTE)this && v15 == (hkpTreeBroadPhaseInternals::InsertionQuery *)v19 )
        {
          if ( !LODWORD(v15[2].m_handles) )
            goto LABEL_39;
          v16 = (unsigned __int64)v15[2].m_handles;
          v21 = v15[3].m_pairsOut;
          v19 = (hkcdDynamicTree::CodecRawUlong *)(v12 + (v16 << 6));
          v22 = *(__m128 *)(((_QWORD)v21 << 6) + v12);
          v23 = *(__m128 *)(((_QWORD)v21 << 6) + v12 + 16);
          v13 = v19->m_aabb.m_min.m_quad;
          v14 = v19->m_aabb.m_max.m_quad;
          if ( v10->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2] == (v10->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[3] & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v10, 16);
          v24 = (_QWORD *)(v10->m_nodes[0].m_aabb.m_min.m_quad.m128_u64[0]
                         + 16i64 * v10->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2]++);
          *v24 = v21;
          v24[1] = v21;
          if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v13, v23), _mm_cmpleps(v22, v14))) & 7) == 7 )
          {
            if ( v10->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2] == (v10->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[3] & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v10, 16);
            v25 = (unsigned __int64 *)(v10->m_nodes[0].m_aabb.m_min.m_quad.m128_u64[0]
                                     + 16i64 * v10->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2]++);
            *v25 = v16;
            v25[1] = (unsigned __int64)v21;
          }
          LOBYTE(this) = v53;
          v20 = v16;
          v15 = (hkpTreeBroadPhaseInternals::InsertionQuery *)(v12 + (v16 << 6));
          v17.m_quad = v13;
          v18.m_quad = v14;
        }
        if ( LODWORD(v15[2].m_handles) )
          break;
        if ( LODWORD(v19->m_children[0]) )
        {
          v20 = v19->m_children[0];
          v47 = v19->m_children[1];
          v45 = (_mm_movemask_ps(
                   _mm_and_ps(
                     _mm_cmpleps(v11->m_nodes[v20].m_aabb.m_min.m_quad, v14),
                     _mm_cmpleps(v13, v11->m_nodes[v20].m_aabb.m_max.m_quad))) & 7) == 7;
          if ( (_mm_movemask_ps(
                  _mm_and_ps(
                    _mm_cmpleps(v11->m_nodes[v47].m_aabb.m_min.m_quad, v14),
                    _mm_cmpleps(v13, v11->m_nodes[v47].m_aabb.m_max.m_quad))) & 7) == 7 )
          {
            if ( v10->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2] == (v10->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[3] & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v10, 16);
            v48 = (unsigned __int64 *)(v10->m_nodes[0].m_aabb.m_min.m_quad.m128_u64[0]
                                     + 16i64 * v10->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2]++);
            *v48 = v16;
            v48[1] = v47;
          }
LABEL_50:
          if ( v45 )
          {
            if ( v10->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2] == (v10->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[3] & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v10, 16);
            v49 = (unsigned __int64 *)(v10->m_nodes[0].m_aabb.m_min.m_quad.m128_u64[0]
                                     + 16i64 * v10->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2]++);
            *v49 = v16;
            v49[1] = v20;
          }
          goto LABEL_39;
        }
        v50 = stackInstance->m_stack.m_data->m_nodeA;
        if ( *(_DWORD *)(v50 + 8) == (*(_DWORD *)(v50 + 12) & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            (void *)stackInstance->m_stack.m_data->m_nodeA,
            16);
        v51 = (hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> **)(*(_QWORD *)v50
                                                                           + 16i64
                                                                           * (signed int)(*(_DWORD *)(v50 + 8))++);
        *v51 = v15[3].m_pairsOut;
        v51[1] = (hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *)v19->m_children[1];
LABEL_39:
        v43 = v10->m_nodes[0].m_aabb.m_min.m_quad.m128_f32[2];
        if ( SLODWORD(v43) <= SLODWORD(v52) )
          return;
        v44 = LODWORD(v43) - 1;
        this = (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)(v10->m_nodes[0].m_aabb.m_min.m_quad.m128_u64[0]
                                                                      + 16i64 * v44);
        v10->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2] = v44;
        v16 = *(_QWORD *)this;
        v20 = *(_QWORD *)&this[8];
        LOBYTE(this) = v53;
        v15 = (hkpTreeBroadPhaseInternals::InsertionQuery *)(v12 + (v16 << 6));
        v19 = &v11->m_nodes[v20];
        v17.m_quad = (__m128)v19->m_aabb.m_min;
        v18.m_quad = (__m128)v19->m_aabb.m_max;
        v13 = *(__m128 *)v15;
        v14 = (__m128)v15[1];
      }
      v16 = (unsigned __int64)v15[2].m_handles;
      v26 = v15[3].m_pairsOut;
      v27 = *(__m128 *)((v16 << 6) + v12);
      v28 = *(__m128 *)((v16 << 6) + v12 + 16);
      v29 = *(__m128 *)(((_QWORD)v26 << 6) + v12);
      v30 = *(__m128 *)(((_QWORD)v26 << 6) + v12 + 16);
      if ( LODWORD(v19->m_children[0]) )
      {
        v31 = v19->m_children[0];
        v32 = v19->m_children[1];
        v33 = v11->m_nodes[v31].m_aabb.m_max.m_quad;
        v34 = v11->m_nodes[v32].m_aabb.m_min.m_quad;
        v35 = v11->m_nodes[v32].m_aabb.m_max.m_quad;
        v54 = (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v27, v33), _mm_cmpleps(v11->m_nodes[v31].m_aabb.m_min.m_quad, v28))) & 7) == 7;
        v36 = _mm_and_ps(_mm_cmpleps(v29, v33), _mm_cmpleps(v11->m_nodes[v31].m_aabb.m_min.m_quad, v30));
        v37 = (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v27, v35), _mm_cmpleps(v11->m_nodes[v32].m_aabb.m_min.m_quad, v28))) & 7) == 7;
        v38 = (_mm_movemask_ps(v36) & 7) == 7;
        if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v29, v35), _mm_cmpleps(v34, v30))) & 7) == 7 )
        {
          if ( v10->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2] == (v10->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[3] & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v10, 16);
          v39 = (_QWORD *)(v10->m_nodes[0].m_aabb.m_min.m_quad.m128_u64[0]
                         + 16i64 * v10->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2]++);
          *v39 = v26;
          v39[1] = v32;
        }
        if ( v38 )
        {
          if ( v10->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2] == (v10->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[3] & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v10, 16);
          v40 = (_QWORD *)(v10->m_nodes[0].m_aabb.m_min.m_quad.m128_u64[0]
                         + 16i64 * v10->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2]++);
          *v40 = v26;
          v40[1] = v31;
        }
        if ( v37 )
        {
          if ( v10->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2] == (v10->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[3] & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v10, 16);
          v41 = (unsigned __int64 *)(v10->m_nodes[0].m_aabb.m_min.m_quad.m128_u64[0]
                                   + 16i64 * v10->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2]++);
          *v41 = v16;
          v41[1] = v32;
        }
        if ( v54 )
        {
          if ( v10->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2] == (v10->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[3] & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v10, 16);
          v42 = (unsigned __int64 *)(v10->m_nodes[0].m_aabb.m_min.m_quad.m128_u64[0]
                                   + 16i64 * v10->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2]++);
          *v42 = v16;
          v42[1] = v31;
        }
        v11 = v55;
        goto LABEL_39;
      }
      v45 = (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v17.m_quad, v28), _mm_cmpleps(v27, v18.m_quad))) & 7) == 7;
      if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v17.m_quad, v30), _mm_cmpleps(v29, v18.m_quad))) & 7) == 7 )
      {
        if ( v10->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2] == (v10->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[3] & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v10, 16);
        v46 = (_QWORD *)(v10->m_nodes[0].m_aabb.m_min.m_quad.m128_u64[0]
                       + 16i64 * v10->m_nodes[0].m_aabb.m_min.m_quad.m128_i32[2]++);
        *v46 = v26;
        v46[1] = v20;
      }
      goto LABEL_50;
    }
  }
}

// File Line: 263
// RVA: 0xDA1140
void __fastcall hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::kineticAabbOverlaps<hkpTreeBroadPhaseSpatialTree16,hkpTreeBroadPhaseInternals::UpdatePairsQuery>(hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *this, hkpTreeBroadPhaseSpatialTree16 *tree, hkAabb *oldAabb, hkAabb *newAabb)
{
  hkArray<hkcdDynamicTree::Codec32,hkContainerHeapAllocator> v4; // xmm2
  hkVector4f v5; // xmm5
  hkVector4f v6; // xmm4
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *v7; // rbx
  __m128 v8; // xmm3
  hkLifoAllocator *v9; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::CoherentKineticAabbOverlapsWrapper<hkpTreeBroadPhaseInternals::UpdatePairsQuery> *v10; // r9
  hkcdDynamicTree::Codec32 *v11; // rdx
  unsigned __int64 v12; // rcx
  int v13; // eax
  char *v14; // rdi
  signed int v15; // ebx
  hkLifoAllocator *v16; // rax
  int v17; // er8
  hkLifoAllocator *v18; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::KineticAabbOverlapsWrapper<hkpTreeBroadPhaseInternals::UpdatePairsQuery> *v19; // r9
  hkcdDynamicTree::Codec32 *v20; // rdx
  unsigned __int64 v21; // rcx
  int v22; // eax
  signed int v23; // ebx
  hkpTreeBroadPhaseSpatialTree16 treea; // [rsp+20h] [rbp-39h]
  hkArray<hkcdDynamicTree::Codec32,hkContainerHeapAllocator> v25; // [rsp+50h] [rbp-9h]
  __m128 v26; // [rsp+60h] [rbp+7h]
  __m128 v27; // [rsp+70h] [rbp+17h]
  __m128 v28; // [rsp+80h] [rbp+27h]
  __m128 v29; // [rsp+90h] [rbp+37h]
  __m128 v30; // [rsp+A0h] [rbp+47h]

  v4 = tree->m_nodes;
  v5.m_quad = (__m128)oldAabb->m_min;
  v6.m_quad = (__m128)oldAabb->m_max;
  v7 = this;
  *(_QWORD *)&treea.m_root = newAabb;
  treea.m_nodes.m_capacityAndFlags = 2147483648;
  treea.m_numLeaves = 64;
  v8 = *(__m128 *)&tree->m_firstFree;
  treea.m_nodes.m_data = 0i64;
  treea.m_nodes.m_size = 0;
  v25 = v4;
  v26 = v8;
  v27 = v5.m_quad;
  v28 = v6.m_quad;
  if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v5.m_quad, v8), _mm_cmpleps((__m128)v4, v6.m_quad))) & 7) == 7 )
  {
    v29 = _mm_min_ps((__m128)v4, v5.m_quad);
    v30 = _mm_max_ps(v8, v6.m_quad);
    v9 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v11 = (hkcdDynamicTree::Codec32 *)v9->m_cur;
    v12 = (unsigned __int64)&v11[4];
    if ( v9->m_slabSize < 128 || (void *)v12 > v9->m_end )
      v11 = (hkcdDynamicTree::Codec32 *)hkLifoAllocator::allocateFromNewSlab(v9, 128);
    else
      v9->m_cur = (void *)v12;
    treea.m_nodes.m_data = v11;
    *(_QWORD *)&treea.m_firstFree = v11;
    treea.m_nodes.m_capacityAndFlags = -2147483584;
    hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkpTreeBroadPhaseSpatialTree16,hkcdTreeQueriesStacks::Dynamic<64,unsigned short>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::CoherentKineticAabbOverlapsWrapper<hkpTreeBroadPhaseInternals::UpdatePairsQuery>>(
      v7,
      &treea,
      (hkcdTreeQueriesStacks::Dynamic<64,unsigned short> *)&treea.m_root,
      v10);
    v13 = treea.m_nodes.m_size;
    v14 = *(char **)&treea.m_firstFree;
    if ( *(hkcdDynamicTree::Codec32 **)&treea.m_firstFree == treea.m_nodes.m_data )
      v13 = 0;
    treea.m_nodes.m_size = v13;
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
    v21 = (unsigned __int64)&v20[4];
    if ( v18->m_slabSize < 128 || (void *)v21 > v18->m_end )
      v20 = (hkcdDynamicTree::Codec32 *)hkLifoAllocator::allocateFromNewSlab(v18, 128);
    else
      v18->m_cur = (void *)v21;
    treea.m_nodes.m_data = v20;
    *(_QWORD *)&treea.m_firstFree = v20;
    treea.m_nodes.m_capacityAndFlags = -2147483584;
    hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkpTreeBroadPhaseSpatialTree16,hkcdTreeQueriesStacks::Dynamic<64,unsigned short>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::KineticAabbOverlapsWrapper<hkpTreeBroadPhaseInternals::UpdatePairsQuery>>(
      v7,
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
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      treea.m_nodes.m_data,
      2 * (treea.m_nodes.m_capacityAndFlags & 0x3FFFFFFF));
}

// File Line: 287
// RVA: 0xDA0990
void __fastcall hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::convexOverlaps<hkpTreeBroadPhaseSpatialTree16,hkpTreeBroadPhaseInternals::ConvexQuerySorted>(hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *this, hkpTreeBroadPhaseSpatialTree16 *tree, hkVector4f *planes, __int64 numPlanes)
{
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *v4; // rbx
  hkLifoAllocator *v5; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::ConvexOverlapsWrapper<hkpTreeBroadPhaseInternals::ConvexQuerySorted> *v6; // r9
  hkcdDynamicTree::Codec32 *v7; // rdx
  unsigned __int64 v8; // rcx
  int v9; // eax
  char *v10; // rdi
  signed int v11; // ebx
  hkLifoAllocator *v12; // rax
  int v13; // er8
  hkpTreeBroadPhaseSpatialTree16 treea; // [rsp+20h] [rbp-48h]
  hkpTreeBroadPhaseSpatialTree16 *v15; // [rsp+50h] [rbp-18h]
  int v16; // [rsp+58h] [rbp-10h]

  v4 = this;
  *(_QWORD *)&treea.m_sortPath = this;
  *(_QWORD *)&treea.m_root = numPlanes;
  v15 = tree;
  v16 = (signed int)planes;
  treea.m_nodes.m_capacityAndFlags = 2147483648;
  treea.m_numLeaves = 64;
  treea.m_nodes.m_data = 0i64;
  treea.m_nodes.m_size = 0;
  v5 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkcdDynamicTree::Codec32 *)v5->m_cur;
  v8 = (unsigned __int64)&v7[4];
  if ( v5->m_slabSize < 128 || (void *)v8 > v5->m_end )
    v7 = (hkcdDynamicTree::Codec32 *)hkLifoAllocator::allocateFromNewSlab(v5, 128);
  else
    v5->m_cur = (void *)v8;
  treea.m_nodes.m_data = v7;
  *(_QWORD *)&treea.m_firstFree = v7;
  treea.m_nodes.m_capacityAndFlags = -2147483584;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkpTreeBroadPhaseSpatialTree16,hkcdTreeQueriesStacks::Dynamic<64,unsigned short>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::ConvexOverlapsWrapper<hkpTreeBroadPhaseInternals::ConvexQuerySorted>>(
    v4,
    &treea,
    (hkcdTreeQueriesStacks::Dynamic<64,unsigned short> *)&treea.m_root,
    v6);
  v9 = treea.m_nodes.m_size;
  v10 = *(char **)&treea.m_firstFree;
  if ( *(hkcdDynamicTree::Codec32 **)&treea.m_firstFree == treea.m_nodes.m_data )
    v9 = 0;
  treea.m_nodes.m_size = v9;
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
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      treea.m_nodes.m_data,
      2 * (treea.m_nodes.m_capacityAndFlags & 0x3FFFFFFF));
}

// File Line: 322
// RVA: 0xE00CE0
hkSimdFloat32 *__fastcall hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::rayCast<hkpBvCompressedMeshShapeTree,hkpBvCompressedMeshShape_Internals::RayCastQuery>(hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *this, hkSimdFloat32 *result, hkpBvCompressedMeshShapeTree *tree, hkcdRay *ray)
{
  hkcdStaticTree::DynamicStorage5 v4; // xmm0
  hkVector4f v5; // xmm1
  hkSimdFloat32 *v6; // rsi
  hkSimdFloat32 *v7; // rbx
  hkVector4f v8; // xmm0
  hkLifoAllocator *v9; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::RayCastWrapper<hkpBvCompressedMeshShape_Internals::RayCastQuery> *v10; // r9
  char *v11; // rdx
  unsigned __int64 v12; // rcx
  int v13; // eax
  char *v14; // rdi
  signed int v15; // ebx
  hkLifoAllocator *v16; // rax
  int v17; // er8
  hkSimdFloat32 *v18; // rax
  void *v19; // [rsp+20h] [rbp-78h]
  int v20; // [rsp+28h] [rbp-70h]
  int v21; // [rsp+2Ch] [rbp-6Ch]
  void *p; // [rsp+30h] [rbp-68h]
  int v23; // [rsp+38h] [rbp-60h]
  hkcdTreeQueriesStacks::Dynamic<64,hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5>::Slot> stackInstance; // [rsp+40h] [rbp-58h]
  __m128 v25; // [rsp+60h] [rbp-38h]
  __m128 v26; // [rsp+70h] [rbp-28h]
  int v27; // [rsp+80h] [rbp-18h]

  v4 = tree->0;
  v5.m_quad = (__m128)tree->m_domain.m_min;
  v6 = (hkSimdFloat32 *)this;
  v7 = result;
  stackInstance.m_stack.m_data = (hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5>::Slot *)ray;
  v27 = -1;
  v21 = 2147483648;
  *(hkcdStaticTree::DynamicStorage5 *)&stackInstance.m_stack.m_localMemory = v4;
  v8.m_quad = (__m128)tree->m_domain.m_max;
  v25 = v5.m_quad;
  v19 = 0i64;
  v20 = 0;
  v23 = 64;
  v26 = v8.m_quad;
  v9 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = (char *)v9->m_cur;
  v12 = (unsigned __int64)(v11 + 3072);
  if ( v9->m_slabSize < 3072 || (void *)v12 > v9->m_end )
    v11 = (char *)hkLifoAllocator::allocateFromNewSlab(v9, 3072);
  else
    v9->m_cur = (void *)v12;
  v19 = v11;
  p = v11;
  v21 = -2147483584;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkpBvCompressedMeshShapeTree,hkcdTreeQueriesStacks::Dynamic<64,hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5>::Slot>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::RayCastWrapper<hkpBvCompressedMeshShape_Internals::RayCastQuery>>(
    (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)v7,
    (hkpBvCompressedMeshShapeTree *)&v19,
    &stackInstance,
    v10);
  v13 = v20;
  v14 = (char *)p;
  if ( p == v19 )
    v13 = 0;
  v20 = v13;
  v15 = (48 * v23 + 127) & 0xFFFFFF80;
  v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (v15 + 15) & 0xFFFFFFF0;
  if ( v15 > v16->m_slabSize || &v14[v17] != v16->m_cur || v16->m_firstNonLifoEnd == v14 )
    hkLifoAllocator::slowBlockFree(v16, v14, v17);
  else
    v16->m_cur = v14;
  v20 = 0;
  if ( v21 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v19,
      48 * (v21 & 0x3FFFFFFF));
  v18 = v6;
  v6->m_real = _mm_shuffle_ps(v25, v25, 255);
  return v18;
}

// File Line: 352
// RVA: 0xDADA90
void __fastcall hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::rayCastBatch<hkpTreeBroadPhaseSpatialTree32,hkpTreeBroadPhaseInternals::RayCastFanQuery>(hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *this, hkpTreeBroadPhaseSpatialTree32 *tree, hkcdRay *rays, __int64 numRays, hkpTreeBroadPhaseInternals::RayCastFanQuery *query)
{
  int v5; // er15
  hkpTreeBroadPhaseSpatialTree32 *v6; // r12
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *v7; // r13
  int v8; // er14
  int v9; // edi
  __int64 v10; // rdx
  char *v11; // rax
  signed __int64 v12; // rcx
  __int128 v13; // xmm0
  __int128 v14; // xmm1
  __int128 v15; // xmm0
  hkLifoAllocator *v16; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::RayCastBatchWrapper<hkpTreeBroadPhaseInternals::RayCastFanQuery> *v17; // r9
  hkcdDynamicTree::CodecRawUint *v18; // rdx
  unsigned __int64 v19; // rcx
  int v20; // eax
  char *v21; // rsi
  signed int v22; // ebx
  hkLifoAllocator *v23; // rax
  int v24; // er8
  hkpTreeBroadPhaseSpatialTree32 treea; // [rsp+20h] [rbp-B8h]
  char v26; // [rsp+70h] [rbp-68h]
  int v27; // [rsp+168h] [rbp+90h]
  int v28; // [rsp+16Ch] [rbp+94h]
  char v29; // [rsp+170h] [rbp+98h]
  char v30; // [rsp+171h] [rbp+99h]

  if ( (signed int)rays > 0 )
  {
    v5 = (signed int)rays;
    v6 = tree;
    v7 = this;
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
        v12 = (signed __int64)&v6[v8].m_root;
        do
        {
          v13 = *(_OWORD *)(v12 - 32);
          v14 = *(_OWORD *)(v12 - 16);
          v11 += 48;
          v12 += 48i64;
          *((_OWORD *)v11 - 5) = v13;
          v15 = *(_OWORD *)(v12 - 48);
          *((_OWORD *)v11 - 4) = v14;
          *((_OWORD *)v11 - 3) = v15;
          --v10;
        }
        while ( v10 );
      }
      v28 = v8;
      treea.m_nodes.m_data = 0i64;
      treea.m_nodes.m_size = 0;
      treea.m_nodes.m_capacityAndFlags = 2147483648;
      v30 = (1 << v9) - 1;
      v29 = (1 << v9) - 1;
      treea.m_numLeaves = 64;
      v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v18 = (hkcdDynamicTree::CodecRawUint *)v16->m_cur;
      v19 = (unsigned __int64)&v18[5].m_aabb.m_max;
      if ( v16->m_slabSize < 256 || (void *)v19 > v16->m_end )
        v18 = (hkcdDynamicTree::CodecRawUint *)hkLifoAllocator::allocateFromNewSlab(v16, 256);
      else
        v16->m_cur = (void *)v19;
      treea.m_nodes.m_data = v18;
      *(_QWORD *)&treea.m_firstFree = v18;
      treea.m_nodes.m_capacityAndFlags = -2147483584;
      hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkpTreeBroadPhaseSpatialTree32,hkcdTreeQueriesStacks::Dynamic<64,unsigned int>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::RayCastBatchWrapper<hkpTreeBroadPhaseInternals::RayCastFanQuery>>(
        v7,
        &treea,
        (hkcdTreeQueriesStacks::Dynamic<64,unsigned int> *)&treea.m_root,
        v17);
      v20 = treea.m_nodes.m_size;
      v21 = *(char **)&treea.m_firstFree;
      if ( *(hkcdDynamicTree::CodecRawUint **)&treea.m_firstFree == treea.m_nodes.m_data )
        v20 = 0;
      treea.m_nodes.m_size = v20;
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
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          treea.m_nodes.m_data,
          4 * treea.m_nodes.m_capacityAndFlags);
      v8 += v9;
    }
    while ( v8 < v5 );
  }
}
          4 * treea.m_nodes.m_capacityAndFlags);
      v8 += v9;
    }
    while ( v8 < v5 );
  }
}

// File Line: 367
// RVA: 0xDA1830
void __fastcall hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::rayCastFan<hkpTreeBroadPhaseSpatialTree16,hkpTreeBroadPhaseInternals::RayCastFanQuery>(hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *this, hkpTreeBroadPhaseSpatialTree16 *tree, hkVector4f *from, hkVector4f *to, __int64 numRays)
{
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *v5; // r15
  __int64 v6; // rsi
  hkVector4f *v7; // rbp
  __m128 *v8; // r14
  hkLifoAllocator *v9; // rax
  hkpTreeBroadPhaseSpatialTree16 *v10; // rdi
  int v11; // ebx
  char *v12; // rcx
  __int64 v13; // rdx
  signed __int64 v14; // rcx
  __m128 v15; // xmm4
  __m128i v16; // xmm4
  __m128 v17; // xmm3
  __m128 v18; // xmm1
  int v19; // eax
  hkLifoAllocator *v20; // rax
  int v21; // er8
  hkpTreeBroadPhaseInternals::RayCastFanQuery *v22; // [rsp+20h] [rbp-38h]

  v5 = this;
  v6 = (signed int)to;
  v7 = from;
  v8 = (__m128 *)tree;
  v9 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v10 = (hkpTreeBroadPhaseSpatialTree16 *)v9->m_cur;
  v11 = (48 * v6 + 127) & 0xFFFFFF80;
  v12 = (char *)v10 + v11;
  if ( v11 > v9->m_slabSize || v12 > v9->m_end )
    v10 = (hkpTreeBroadPhaseSpatialTree16 *)hkLifoAllocator::allocateFromNewSlab(v9, v11);
  else
    v9->m_cur = v12;
  v13 = v6;
  if ( (signed int)v6 > 0 )
  {
    v14 = (signed __int64)&v10->m_firstFree;
    do
    {
      v15 = v7->m_quad;
      v14 += 48i64;
      ++v7;
      v16 = (__m128i)_mm_sub_ps(v15, *v8);
      v17 = _mm_cmpeqps((__m128)0i64, (__m128)v16);
      v18 = _mm_rcp_ps((__m128)v16);
      *(__m128 *)(v14 - 48) = _mm_shuffle_ps((__m128)v16, _mm_unpackhi_ps((__m128)v16, query.m_quad), 196);
      v19 = _mm_movemask_ps(_mm_cmpleps((__m128)0i64, *(__m128 *)(v14 - 48))) & 7 | 0x3F000000;
      *(__m128 *)(v14 - 32) = _mm_or_ps(
                                _mm_and_ps(
                                  _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v16, 0x1Fu), 0x1Fu), (__m128)_xmm),
                                  v17),
                                _mm_andnot_ps(
                                  v17,
                                  _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v18, (__m128)v16)), v18)));
      *(_DWORD *)(v14 - 20) = v19;
      *(__m128 *)(v14 - 64) = *v8;
      --v13;
    }
    while ( v13 );
  }
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::rayCastBatch<hkpTreeBroadPhaseSpatialTree16,hkpTreeBroadPhaseInternals::RayCastFanQuery>(
    v5,
    v10,
    (hkcdRay *)(unsigned int)v6,
    numRays,
    v22);
  v20 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v21 = (v11 + 15) & 0xFFFFFFF0;
  if ( v11 > v20->m_slabSize || (char *)v10 + v21 != v20->m_cur || v20->m_firstNonLifoEnd == v10 )
    hkLifoAllocator::slowBlockFree(v20, v10, v21);
  else
    v20->m_cur = v10;
}

// File Line: 393
// RVA: 0xE00AD0
hkSimdFloat32 *__fastcall hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::aabbCast<hkpBvCompressedMeshShapeTree,hkpBvCompressedMeshShape_Internals::AabbCastQuery>(hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *this, hkSimdFloat32 *result, hkpBvCompressedMeshShapeTree *tree, hkAabb *from, hkVector4f *to)
{
  hkVector4f v5; // xmm6
  hkSimdFloat32 *v6; // rsi
  hkSimdFloat32 *v7; // rbx
  hkVector4f v8; // xmm7
  hkcdStaticTree::DynamicStorage5 v9; // xmm8
  hkArray<unsigned short,hkContainerHeapAllocator> v10; // xmm7
  __m128 v11; // xmm8
  __m128i v12; // xmm6
  __m128 v13; // xmm3
  __m128 v14; // xmm1
  hkLifoAllocator *v15; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbCastWrapper<hkpBvCompressedMeshShape_Internals::AabbCastQuery> *v16; // r9
  char *v17; // rcx
  unsigned __int64 v18; // rdx
  int v19; // eax
  char *v20; // rdi
  signed int v21; // ebx
  hkLifoAllocator *v22; // rax
  int v23; // er8
  hkSimdFloat32 *v24; // rax
  hkpBvCompressedMeshShapeTree treea; // [rsp+18h] [rbp-69h]
  unsigned __int64 v26; // [rsp+F8h] [rbp+77h]

  v5.m_quad = (__m128)from->m_min;
  v6 = (hkSimdFloat32 *)this;
  v7 = result;
  treea.m_nodes.m_capacityAndFlags = 2147483648;
  treea.m_domain.m_min.m_quad.m128_i32[2] = 64;
  treea.m_nodes.m_data = 0i64;
  v8.m_quad = (__m128)tree->m_domain.m_min;
  treea.m_nodes.m_size = 0;
  v9 = tree->0;
  treea.m_domain.m_max.m_quad.m128_u64[0] = v26;
  v10 = (hkArray<unsigned short,hkContainerHeapAllocator>)_mm_mul_ps(
                                                            _mm_sub_ps(v8.m_quad, (__m128)v9),
                                                            (__m128)xmmword_141A711B0);
  v11 = _mm_mul_ps(_mm_add_ps((__m128)v9, tree->m_domain.m_min.m_quad), (__m128)xmmword_141A711B0);
  treea.m_sharedVerticesIndex = v10;
  v12 = (__m128i)_mm_sub_ps(v5.m_quad, v11);
  *(__m128 *)&treea.m_numPrimitiveKeys = v11;
  v13 = _mm_cmpeqps((__m128)0i64, (__m128)v12);
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
  treea.m_primitives.m_capacityAndFlags = _mm_movemask_ps(_mm_cmpleps((__m128)0i64, (__m128)treea.m_sections)) & 7 | 0x3F000000;
  v15 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (char *)v15->m_cur;
  v18 = (unsigned __int64)(v17 + 3072);
  if ( v15->m_slabSize < 3072 || (void *)v18 > v15->m_end )
    v17 = (char *)hkLifoAllocator::allocateFromNewSlab(v15, 3072);
  else
    v15->m_cur = (void *)v18;
  treea.m_domain.m_min.m_quad.m128_u64[0] = (unsigned __int64)v17;
  treea.m_nodes.m_capacityAndFlags = -2147483584;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkpBvCompressedMeshShapeTree,hkcdTreeQueriesStacks::Dynamic<64,hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5>::Slot>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbCastWrapper<hkpBvCompressedMeshShape_Internals::AabbCastQuery>>(
    (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)v7,
    &treea,
    (hkcdTreeQueriesStacks::Dynamic<64,hkcdStaticTree::Tree<hkcdStaticTree::DynamicStorage5>::Slot> *)&treea.m_domain.m_max,
    v16);
  v19 = treea.m_nodes.m_size;
  v20 = (char *)treea.m_domain.m_min.m_quad.m128_u64[0];
  if ( (hkcdStaticTree::Codec3Axis5 *)treea.m_domain.m_min.m_quad.m128_u64[0] == treea.m_nodes.m_data )
    v19 = 0;
  treea.m_nodes.m_size = v19;
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
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      treea.m_nodes.m_data,
      48 * (treea.m_nodes.m_capacityAndFlags & 0x3FFFFFFF));
  v24 = v6;
  v6->m_real = _mm_shuffle_ps((__m128)treea.m_sections, (__m128)treea.m_sections, 255);
  return v24;
}

// File Line: 420
// RVA: 0xCD6610
hkSimdFloat32 *__fastcall hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::closest<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,NearestFeaturePolicy>(hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *this, hkSimdFloat32 *result, hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *tree, hkVector4f *point, NearestFeaturePolicy *query)
{
  hkSimdFloat32 *v5; // rsi
  hkSimdFloat32 *v6; // rbx
  hkVector4f v7; // xmm1
  hkLifoAllocator *v8; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::ClosestFromPointWrapper<NearestFeaturePolicy> *v9; // r9
  hkcdDynamicTree::CodecRawUlong *v10; // rdx
  unsigned __int64 v11; // rcx
  int v12; // eax
  char *v13; // rdi
  signed int v14; // ebx
  hkLifoAllocator *v15; // rax
  int v16; // er8
  hkSimdFloat32 *v17; // rax
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> treea; // [rsp+20h] [rbp-68h]
  hkArray<hkcdDynamicTree::CodecRawUlong,hkContainerHeapAllocator> v19; // [rsp+50h] [rbp-38h]
  __m128i v20; // [rsp+60h] [rbp-28h]
  int v21; // [rsp+70h] [rbp-18h]

  v5 = (hkSimdFloat32 *)this;
  v6 = result;
  v19 = tree->m_nodes;
  v7.m_quad = (__m128)query->m_normal;
  treea.m_root = (unsigned __int64)point;
  v21 = 0;
  treea.m_nodes.m_data = 0i64;
  v20 = (__m128i)v7.m_quad;
  treea.m_nodes.m_size = 0;
  treea.m_nodes.m_capacityAndFlags = 2147483648;
  treea.m_numLeaves = 64;
  v8 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v10 = (hkcdDynamicTree::CodecRawUlong *)v8->m_cur;
  v11 = (unsigned __int64)&v10[8];
  if ( v8->m_slabSize < 512 || (void *)v11 > v8->m_end )
    v10 = (hkcdDynamicTree::CodecRawUlong *)hkLifoAllocator::allocateFromNewSlab(v8, 512);
  else
    v8->m_cur = (void *)v11;
  treea.m_nodes.m_data = v10;
  treea.m_firstFree = (unsigned __int64)v10;
  treea.m_nodes.m_capacityAndFlags = -2147483584;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,hkcdTreeQueriesStacks::Dynamic<64,unsigned __int64>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::ClosestFromPointWrapper<NearestFeaturePolicy>>(
    (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)v6,
    &treea,
    (hkcdTreeQueriesStacks::Dynamic<64,unsigned __int64> *)&treea.m_root,
    v9);
  v12 = treea.m_nodes.m_size;
  v13 = (char *)treea.m_firstFree;
  if ( (hkcdDynamicTree::CodecRawUlong *)treea.m_firstFree == treea.m_nodes.m_data )
    v12 = 0;
  treea.m_nodes.m_size = v12;
  v14 = (8 * treea.m_numLeaves + 127) & 0xFFFFFF80;
  v15 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v16 = (v14 + 15) & 0xFFFFFFF0;
  if ( v14 > v15->m_slabSize || &v13[v16] != v15->m_cur || v15->m_firstNonLifoEnd == v13 )
    hkLifoAllocator::slowBlockFree(v15, v13, v16);
  else
    v15->m_cur = v13;
  treea.m_nodes.m_size = 0;
  if ( treea.m_nodes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      treea.m_nodes.m_data,
      8 * treea.m_nodes.m_capacityAndFlags);
  v17 = v5;
  _mm_store_si128((__m128i *)v5, v20);
  return v17;
}

// File Line: 448
// RVA: 0xC90750
void __fastcall hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::allPairs<hkcdDynamicTree::DefaultTree48Storage,WrappedAllPairsQuery<hkcdDynamicTree::DefaultTree48Storage>>(hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *this, hkcdDynamicTree::DefaultTree48Storage *tree, WrappedAllPairsQuery<hkcdDynamicTree::DefaultTree48Storage> *query)
{
  hkcdDynamicTree::DefaultTree48Storage *v3; // rbx
  hkLifoAllocator *v4; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *v5; // rcx
  hkcdDynamicTree::CodecRawUint *v6; // r8
  unsigned __int64 v7; // rdx
  int v8; // eax
  char *v9; // rdi
  signed int v10; // ebx
  hkLifoAllocator *v11; // rax
  int v12; // er8
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::NodeContext *v13; // [rsp+38h] [rbp-30h]
  hkcdDynamicTree::DefaultTree48Storage treeB; // [rsp+40h] [rbp-28h]
  hkcdDynamicTree::DefaultTree48Storage *stackInstance; // [rsp+78h] [rbp+10h]

  v3 = (hkcdDynamicTree::DefaultTree48Storage *)this;
  stackInstance = tree;
  treeB.m_nodes.m_capacityAndFlags = 2147483648;
  treeB.m_numLeaves = 64;
  treeB.m_nodes.m_data = 0i64;
  treeB.m_nodes.m_size = 0;
  v4 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (hkcdDynamicTree::CodecRawUint *)v4->m_cur;
  v7 = (unsigned __int64)&v6[10].m_parent;
  if ( v4->m_slabSize < 512 || (void *)v7 > v4->m_end )
    v6 = (hkcdDynamicTree::CodecRawUint *)hkLifoAllocator::allocateFromNewSlab(v4, 512);
  else
    v4->m_cur = (void *)v7;
  treeB.m_nodes.m_data = v6;
  *(_QWORD *)&treeB.m_firstFree = v6;
  LOBYTE(v5) = 1;
  treeB.m_nodes.m_capacityAndFlags = -2147483584;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::binary<hkcdDynamicTree::DefaultTree48Storage,hkcdDynamicTree::DefaultTree48Storage,hkcdTreeQueriesStacks::Dynamic<64,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::SlotPair<hkcdDynamicTree::DefaultTree48Storage,hkcdDynamicTree::DefaultTree48Storage>>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AllPairsWrapper<WrappedAllPairsQuery<hkcdDynamicTree::DefaultTree48Storage>>>(
    v5,
    (bool)v3,
    v3,
    &treeB,
    (hkcdTreeQueriesStacks::Dynamic<64,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::SlotPair<hkcdDynamicTree::DefaultTree48Storage,hkcdDynamicTree::DefaultTree48Storage> > *)&stackInstance,
    0i64,
    0i64,
    v13);
  v8 = treeB.m_nodes.m_size;
  v9 = *(char **)&treeB.m_firstFree;
  if ( *(hkcdDynamicTree::CodecRawUint **)&treeB.m_firstFree == treeB.m_nodes.m_data )
    v8 = 0;
  treeB.m_nodes.m_size = v8;
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
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      treeB.m_nodes.m_data,
      8 * treeB.m_nodes.m_capacityAndFlags);
}

// File Line: 457
// RVA: 0xCD5BE0
void __fastcall hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::allPairs<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,TrianglePairCollector>(hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *this, hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *treeA, hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *treeB, TrianglePairCollector *query)
{
  char v4; // di
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *v5; // rbx
  hkLifoAllocator *v6; // rax
  hkcdDynamicTree::CodecRawUlong *v7; // r8
  unsigned __int64 v8; // rdx
  int v9; // eax
  char *v10; // rdi
  signed int v11; // ebx
  hkLifoAllocator *v12; // rax
  int v13; // er8
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::NodeContext *v14; // [rsp+38h] [rbp-30h]
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> treeBa; // [rsp+40h] [rbp-28h]
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *stackInstance; // [rsp+80h] [rbp+18h]

  v4 = (char)this;
  v5 = treeA;
  stackInstance = treeB;
  treeBa.m_nodes.m_capacityAndFlags = 2147483648;
  treeBa.m_nodes.m_data = 0i64;
  treeBa.m_nodes.m_size = 0;
  treeBa.m_numLeaves = 64;
  v6 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkcdDynamicTree::CodecRawUlong *)v6->m_cur;
  v8 = (unsigned __int64)&v7[16];
  if ( v6->m_slabSize < 1024 || (void *)v8 > v6->m_end )
    v7 = (hkcdDynamicTree::CodecRawUlong *)hkLifoAllocator::allocateFromNewSlab(v6, 1024);
  else
    v6->m_cur = (void *)v8;
  treeBa.m_nodes.m_data = v7;
  treeBa.m_firstFree = (unsigned __int64)v7;
  treeBa.m_nodes.m_capacityAndFlags = -2147483584;
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::binary<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,hkcdTreeQueriesStacks::Dynamic<64,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::SlotPair<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>>>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AllPairsWrapper<TrianglePairCollector>>(
    0i64,
    v4,
    v5,
    &treeBa,
    (hkcdTreeQueriesStacks::Dynamic<64,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::SlotPair<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> > > *)&stackInstance,
    0i64,
    0i64,
    v14);
  v9 = treeBa.m_nodes.m_size;
  v10 = (char *)treeBa.m_firstFree;
  if ( (hkcdDynamicTree::CodecRawUlong *)treeBa.m_firstFree == treeBa.m_nodes.m_data )
    v9 = 0;
  treeBa.m_nodes.m_size = v9;
  v11 = (16 * treeBa.m_numLeaves + 127) & 0xFFFFFF80;
  v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v13 = (v11 + 15) & 0xFFFFFFF0;
  if ( v11 > v12->m_slabSize || &v10[v13] != v12->m_cur || v12->m_firstNonLifoEnd == v10 )
    hkLifoAllocator::slowBlockFree(v12, v10, v13);
  else
    v12->m_cur = v10;
  treeBa.m_nodes.m_size = 0;
  if ( treeBa.m_nodes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      treeBa.m_nodes.m_data,
      16 * treeBa.m_nodes.m_capacityAndFlags);
}

