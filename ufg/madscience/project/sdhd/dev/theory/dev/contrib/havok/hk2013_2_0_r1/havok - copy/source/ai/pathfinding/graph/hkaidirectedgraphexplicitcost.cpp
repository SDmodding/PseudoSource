// File Line: 21
// RVA: 0xBE7150
void __fastcall hkaiDirectedGraphExplicitCost::hkaiDirectedGraphExplicitCost(hkaiDirectedGraphExplicitCost *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiDirectedGraphExplicitCost::`vftable;
  this->m_positions.m_capacityAndFlags = 2147483648;
  this->m_positions.m_data = 0i64;
  this->m_positions.m_size = 0;
  this->m_nodes.m_data = 0i64;
  this->m_nodes.m_size = 0;
  this->m_nodes.m_capacityAndFlags = 2147483648;
  this->m_edges.m_data = 0i64;
  this->m_edges.m_size = 0;
  this->m_edges.m_capacityAndFlags = 2147483648;
  this->m_nodeData.m_data = 0i64;
  this->m_nodeData.m_size = 0;
  this->m_nodeData.m_capacityAndFlags = 2147483648;
  this->m_edgeData.m_data = 0i64;
  this->m_edgeData.m_size = 0;
  this->m_edgeData.m_capacityAndFlags = 2147483648;
  *(_QWORD *)&this->m_nodeDataStriding = 0i64;
  this->m_streamingSets.m_data = 0i64;
  this->m_streamingSets.m_size = 0;
  this->m_streamingSets.m_capacityAndFlags = 2147483648;
}

// File Line: 32
// RVA: 0xBE71D0
void __fastcall hkaiDirectedGraphExplicitCost::hkaiDirectedGraphExplicitCost(hkaiDirectedGraphExplicitCost *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiDirectedGraphExplicitCost::`vftable;
}

// File Line: 37
// RVA: 0xBE7760
void __fastcall hkaiDirectedGraphExplicitCost::validate(hkaiDirectedGraphExplicitCost *this)
{
  ;
}

// File Line: 83
// RVA: 0xBE71F0
hkResult *__fastcall hkaiDirectedGraphExplicitCost::copy(hkaiDirectedGraphExplicitCost *this, hkResult *result, hkaiDirectedGraphExplicitCost *other)
{
  hkaiDirectedGraphExplicitCost *v3; // rsi
  hkResult *v4; // r15
  int v5; // er9
  hkaiDirectedGraphExplicitCost *v6; // r14
  __int64 v7; // rax
  hkaiDirectedGraphExplicitCost::Node *v8; // rcx
  __int64 v9; // rdx
  char *v10; // r8
  hkaiDirectedGraphExplicitCost::Node v11; // rax
  int v12; // er9
  __int64 v13; // rax
  hkaiDirectedGraphExplicitCost::Edge *v14; // r9
  __int64 v15; // rdx
  signed __int64 v16; // rcx
  char *v17; // r8
  __int16 v18; // ax
  int v19; // er9
  __int64 v20; // rax
  hkVector4f *v21; // rcx
  __int64 v22; // rdx
  char *v23; // r8
  hkVector4f v24; // xmm0
  hkResultEnum v25; // ebx
  hkResultEnum v26; // edi
  int v27; // er9
  __int64 v28; // rax
  unsigned int *v29; // rcx
  __int64 v30; // rdx
  char *v31; // r8
  unsigned int v32; // eax
  int v33; // er9
  __int64 v34; // rax
  unsigned int *v35; // rcx
  __int64 v36; // rdx
  char *v37; // r8
  unsigned int v38; // eax
  hkResult v40; // [rsp+30h] [rbp-10h]
  int v41; // [rsp+34h] [rbp-Ch]
  hkResult v42; // [rsp+38h] [rbp-8h]
  hkResult v43; // [rsp+80h] [rbp+40h]
  hkResult resulta; // [rsp+90h] [rbp+50h]
  hkResult v45; // [rsp+98h] [rbp+58h]

  v3 = other;
  this->m_nodeDataStriding = other->m_nodeDataStriding;
  v4 = result;
  this->m_edgeDataStriding = other->m_edgeDataStriding;
  v5 = other->m_nodes.m_size;
  v6 = this;
  if ( (this->m_nodes.m_capacityAndFlags & 0x3FFFFFFF) >= v5 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    hkArrayUtil::_reserve(
      &resulta,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_nodes,
      v5,
      8);
    if ( resulta.m_enum )
      goto LABEL_12;
  }
  if ( (v6->m_nodes.m_capacityAndFlags & 0x3FFFFFFF) < v3->m_nodes.m_size )
  {
    if ( v6->m_nodes.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v6->m_nodes.m_data,
        8 * v6->m_nodes.m_capacityAndFlags);
    v43.m_enum = 8 * v3->m_nodes.m_size;
    v6->m_nodes.m_data = (hkaiDirectedGraphExplicitCost::Node *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                                  (int *)&v43);
    v6->m_nodes.m_capacityAndFlags = v43.m_enum / 8;
  }
  v7 = v3->m_nodes.m_size;
  v8 = v6->m_nodes.m_data;
  v6->m_nodes.m_size = v7;
  v9 = v7;
  if ( (signed int)v7 > 0 )
  {
    v10 = (char *)((char *)v3->m_nodes.m_data - (char *)v8);
    do
    {
      v11 = *(hkaiDirectedGraphExplicitCost::Node *)((char *)v8 + (_QWORD)v10);
      ++v8;
      v8[-1] = v11;
      --v9;
    }
    while ( v9 );
  }
LABEL_12:
  v12 = v3->m_edges.m_size;
  if ( (v6->m_edges.m_capacityAndFlags & 0x3FFFFFFF) >= v12 )
  {
    v45.m_enum = 0;
  }
  else
  {
    hkArrayUtil::_reserve(&v45, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v6->m_edges, v12, 8);
    if ( v45.m_enum )
      goto LABEL_23;
  }
  if ( (v6->m_edges.m_capacityAndFlags & 0x3FFFFFFF) < v3->m_edges.m_size )
  {
    if ( v6->m_edges.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v6->m_edges.m_data,
        8 * v6->m_edges.m_capacityAndFlags);
    v43.m_enum = 8 * v3->m_edges.m_size;
    v6->m_edges.m_data = (hkaiDirectedGraphExplicitCost::Edge *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                                  (int *)&v43);
    v6->m_edges.m_capacityAndFlags = v43.m_enum / 8;
  }
  v13 = v3->m_edges.m_size;
  v14 = v6->m_edges.m_data;
  v6->m_edges.m_size = v13;
  v15 = v13;
  if ( (signed int)v13 > 0 )
  {
    v16 = (signed __int64)&v14->m_flags;
    v17 = (char *)((char *)v3->m_edges.m_data - (char *)v14);
    do
    {
      v18 = *(_WORD *)&v17[v16 - 2];
      v16 += 8i64;
      *(_WORD *)(v16 - 10) = v18;
      *(_WORD *)(v16 - 8) = *(_WORD *)&v17[v16 - 8];
      *(_DWORD *)(v16 - 6) = *(_DWORD *)&v17[v16 - 6];
      --v15;
    }
    while ( v15 );
  }
LABEL_23:
  v19 = v3->m_positions.m_size;
  if ( (v6->m_positions.m_capacityAndFlags & 0x3FFFFFFF) >= v19 )
  {
    v40.m_enum = 0;
  }
  else
  {
    hkArrayUtil::_reserve(
      &v40,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v6->m_positions,
      v19,
      16);
    if ( v40.m_enum )
      goto LABEL_34;
  }
  if ( (v6->m_positions.m_capacityAndFlags & 0x3FFFFFFF) < v3->m_positions.m_size )
  {
    if ( v6->m_positions.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v6->m_positions.m_data,
        16 * v6->m_positions.m_capacityAndFlags);
    v43.m_enum = 16 * v3->m_positions.m_size;
    v6->m_positions.m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                             (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                             (int *)&v43);
    v6->m_positions.m_capacityAndFlags = v43.m_enum / 16;
  }
  v20 = v3->m_positions.m_size;
  v21 = v6->m_positions.m_data;
  v6->m_positions.m_size = v20;
  v22 = v20;
  if ( (signed int)v20 > 0 )
  {
    v23 = (char *)((char *)v3->m_positions.m_data - (char *)v21);
    do
    {
      v24.m_quad = *(__m128 *)((char *)v21 + (_QWORD)v23);
      ++v21;
      v21[-1] = (hkVector4f)v24.m_quad;
      --v22;
    }
    while ( v22 );
  }
LABEL_34:
  v25 = 0;
  v26 = 0;
  if ( !v6->m_nodeDataStriding )
    goto LABEL_47;
  v27 = v3->m_nodeData.m_size;
  if ( (v6->m_nodeData.m_capacityAndFlags & 0x3FFFFFFF) >= v27 )
  {
    v43.m_enum = 0;
LABEL_39:
    if ( (v6->m_nodeData.m_capacityAndFlags & 0x3FFFFFFF) < v3->m_nodeData.m_size )
    {
      if ( v6->m_nodeData.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v6->m_nodeData.m_data,
          4 * v6->m_nodeData.m_capacityAndFlags);
      v41 = 4 * v3->m_nodeData.m_size;
      v6->m_nodeData.m_data = (unsigned int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                &v41);
      v6->m_nodeData.m_capacityAndFlags = v41 / 4;
    }
    v28 = v3->m_nodeData.m_size;
    v29 = v6->m_nodeData.m_data;
    v6->m_nodeData.m_size = v28;
    v30 = v28;
    if ( (signed int)v28 > 0 )
    {
      v31 = (char *)((char *)v3->m_nodeData.m_data - (char *)v29);
      do
      {
        v32 = *(unsigned int *)((char *)v29 + (_QWORD)v31);
        ++v29;
        *(v29 - 1) = v32;
        --v30;
      }
      while ( v30 );
    }
    goto LABEL_46;
  }
  hkArrayUtil::_reserve(&v43, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v6->m_nodeData, v27, 4);
  if ( v43.m_enum == HK_SUCCESS )
    goto LABEL_39;
LABEL_46:
  v25 = v43.m_enum;
LABEL_47:
  if ( v6->m_edgeDataStriding )
  {
    v33 = v3->m_edgeData.m_size;
    if ( (v6->m_edgeData.m_capacityAndFlags & 0x3FFFFFFF) >= v33 )
    {
      v43.m_enum = 0;
    }
    else
    {
      hkArrayUtil::_reserve(
        &v43,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v6->m_edgeData,
        v33,
        4);
      if ( v43.m_enum )
      {
LABEL_59:
        v26 = v43.m_enum;
        goto LABEL_60;
      }
    }
    if ( (v6->m_edgeData.m_capacityAndFlags & 0x3FFFFFFF) < v3->m_edgeData.m_size )
    {
      if ( v6->m_edgeData.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v6->m_edgeData.m_data,
          4 * v6->m_edgeData.m_capacityAndFlags);
      v41 = 4 * v3->m_edgeData.m_size;
      v6->m_edgeData.m_data = (unsigned int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                &v41);
      v6->m_edgeData.m_capacityAndFlags = v41 / 4;
    }
    v34 = v3->m_edgeData.m_size;
    v35 = v6->m_edgeData.m_data;
    v6->m_edgeData.m_size = v34;
    v36 = v34;
    if ( (signed int)v34 > 0 )
    {
      v37 = (char *)((char *)v3->m_edgeData.m_data - (char *)v35);
      do
      {
        v38 = *(unsigned int *)((char *)v35 + (_QWORD)v37);
        ++v35;
        *(v35 - 1) = v38;
        --v36;
      }
      while ( v36 );
    }
    goto LABEL_59;
  }
LABEL_60:
  hkaiStreamingSet::_copy(&v42, &v6->m_streamingSets, (hkArrayBase<hkaiStreamingSet> *)&v3->m_streamingSets.m_data);
  v4->m_enum = resulta.m_enum || v45.m_enum || v40.m_enum || v25 || v26 || v42.m_enum;
  return v4;
}

// File Line: 113
// RVA: 0xBE76D0
void __fastcall hkaiDirectedGraphExplicitCost::swap(hkaiDirectedGraphExplicitCost *this, hkaiDirectedGraphExplicitCost *other)
{
  hkaiDirectedGraphExplicitCost *v2; // rdi
  hkaiDirectedGraphExplicitCost *v3; // rbx
  int v4; // ecx
  int v5; // ecx

  v2 = other;
  v3 = this;
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&this->m_nodes,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&other->m_nodes);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v3->m_edges,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v2->m_edges);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v3->m_positions,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v2->m_positions);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v3->m_streamingSets,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v2->m_streamingSets);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v3->m_nodeData,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v2->m_nodeData);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v3->m_edgeData,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v2->m_edgeData);
  v4 = v3->m_nodeDataStriding;
  v3->m_nodeDataStriding = v2->m_nodeDataStriding;
  v2->m_nodeDataStriding = v4;
  v5 = v3->m_edgeDataStriding;
  v3->m_edgeDataStriding = v2->m_edgeDataStriding;
  v2->m_edgeDataStriding = v5;
}

// File Line: 125
// RVA: 0xBE7770
hkResult *__fastcall hkaiDirectedGraphExplicitCost::setNodeDataStriding(hkaiDirectedGraphExplicitCost *this, hkResult *result, int newStride, unsigned int fillValue)
{
  int v4; // eax
  int v5; // er10
  hkArray<unsigned int,hkContainerHeapAllocator> *v6; // r8
  hkResult *v7; // rbx
  int v9; // [rsp+30h] [rbp-8h]

  v4 = this->m_nodes.m_size;
  v5 = newStride;
  v6 = (hkArray<unsigned int,hkContainerHeapAllocator> *)(unsigned int)this->m_nodeDataStriding;
  v7 = result;
  this->m_nodeDataStriding = v5;
  hkaiUserDataUtils::restride<unsigned int>(
    (hkaiUserDataUtils *)result,
    (hkResult *)&this->m_nodeData,
    v6,
    v5,
    v4,
    fillValue,
    v9);
  return v7;
}

// File Line: 132
// RVA: 0xBE77B0
hkResult *__fastcall hkaiDirectedGraphExplicitCost::setEdgeDataStriding(hkaiDirectedGraphExplicitCost *this, hkResult *result, int newStride, unsigned int fillValue)
{
  int v4; // eax
  int v5; // er10
  hkArray<unsigned int,hkContainerHeapAllocator> *v6; // r8
  hkResult *v7; // rbx
  int v9; // [rsp+30h] [rbp-8h]

  v4 = this->m_edges.m_size;
  v5 = newStride;
  v6 = (hkArray<unsigned int,hkContainerHeapAllocator> *)(unsigned int)this->m_edgeDataStriding;
  v7 = result;
  this->m_edgeDataStriding = v5;
  hkaiUserDataUtils::restride<unsigned int>(
    (hkaiUserDataUtils *)result,
    (hkResult *)&this->m_edgeData,
    v6,
    v5,
    v4,
    fillValue,
    v9);
  return v7;
}

// File Line: 139
// RVA: 0xBE77F0
hkaiDirectedGraphExplicitCost::Node *__fastcall hkaiDirectedGraphExplicitCost::expandNodesBy(hkaiDirectedGraphExplicitCost *this, int n)
{
  int v2; // ebx
  int v3; // er15
  hkaiDirectedGraphExplicitCost *v4; // rsi
  int v5; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // er9
  int v10; // edx
  unsigned int *v11; // rdi
  __int64 v12; // rcx
  __int64 v13; // rcx
  int sizeElem; // [rsp+20h] [rbp-48h]
  hkResult result; // [rsp+30h] [rbp-38h]
  int v16; // [rsp+70h] [rbp+8h]
  int v17; // [rsp+80h] [rbp+18h]
  int v18; // [rsp+88h] [rbp+20h]

  v2 = this->m_nodeDataStriding;
  v3 = n;
  v4 = this;
  if ( v2 )
  {
    v5 = this->m_nodeData.m_size + n * v2;
    hkaiArrayUtil::reserveSmall<int,hkContainerHeapAllocator>(
      (hkaiArrayUtil *)&v16,
      (hkResult *)&this->m_nodeData,
      (hkArray<unsigned int,hkContainerHeapAllocator> *)(unsigned int)v5,
      -1);
    if ( v16 )
      return 0i64;
    v7 = v4->m_nodeData.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v7 < v5 )
    {
      v8 = 2 * v7;
      v9 = v5;
      if ( v5 < v8 )
        v9 = v8;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v4->m_nodeData,
        v9,
        4);
    }
    v10 = v5 - v4->m_nodeData.m_size;
    v11 = &v4->m_nodeData.m_data[v4->m_nodeData.m_size];
    v12 = v10;
    if ( v10 > 0 )
    {
      while ( v12 )
      {
        *v11 = 0;
        ++v11;
        --v12;
      }
    }
    v4->m_nodeData.m_size = v5;
  }
  hkaiArrayUtil::reserveSmall<hkaiDirectedGraphExplicitCost::Node,hkContainerHeapAllocator>(
    (hkaiArrayUtil *)&v17,
    (hkResult *)&v4->m_nodes,
    (hkArray<hkaiDirectedGraphExplicitCost::Node,hkContainerHeapAllocator> *)(unsigned int)(v3 + v4->m_nodes.m_size),
    -1,
    sizeElem);
  if ( v17 )
    return 0i64;
  hkaiArrayUtil::reserveSmall<hkVector4f,hkContainerHeapAllocator>(
    (hkaiArrayUtil *)&v18,
    (hkResult *)&v4->m_positions,
    (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(unsigned int)(v3 + v4->m_positions.m_size),
    -1);
  if ( v18 )
    return 0i64;
  v4->m_positions.m_size += v3;
  v13 = v4->m_nodes.m_size;
  v4->m_nodes.m_size = v13 + v3;
  return &v4->m_nodes.m_data[v13];
}

// File Line: 162
// RVA: 0xBE7910
hkaiDirectedGraphExplicitCost::Edge *__fastcall hkaiDirectedGraphExplicitCost::expandEdgesBy(hkaiDirectedGraphExplicitCost *this, int n)
{
  int v2; // ebx
  int v3; // er14
  hkaiDirectedGraphExplicitCost *v4; // rbp
  int v5; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // er9
  int v10; // edx
  unsigned int *v11; // rdi
  __int64 v12; // rcx
  __int64 v13; // rcx
  int sizeElem; // [rsp+20h] [rbp-38h]
  int v15; // [rsp+60h] [rbp+8h]
  int v16; // [rsp+70h] [rbp+18h]
  hkResult result; // [rsp+78h] [rbp+20h]

  v2 = this->m_edgeDataStriding;
  v3 = n;
  v4 = this;
  if ( v2 )
  {
    v5 = this->m_edgeData.m_size + n * v2;
    hkaiArrayUtil::reserveSmall<int,hkContainerHeapAllocator>(
      (hkaiArrayUtil *)&v15,
      (hkResult *)&this->m_edgeData,
      (hkArray<unsigned int,hkContainerHeapAllocator> *)(unsigned int)v5,
      -1);
    if ( v15 )
      return 0i64;
    v7 = v4->m_edgeData.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v7 < v5 )
    {
      v8 = 2 * v7;
      v9 = v5;
      if ( v5 < v8 )
        v9 = v8;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v4->m_edgeData,
        v9,
        4);
    }
    v10 = v5 - v4->m_edgeData.m_size;
    v11 = &v4->m_edgeData.m_data[v4->m_edgeData.m_size];
    v12 = v10;
    if ( v10 > 0 )
    {
      while ( v12 )
      {
        *v11 = 0;
        ++v11;
        --v12;
      }
    }
    v4->m_edgeData.m_size = v5;
  }
  hkaiArrayUtil::reserveSmall<hkaiDirectedGraphExplicitCost::Node,hkContainerHeapAllocator>(
    (hkaiArrayUtil *)&v16,
    (hkResult *)&v4->m_edges,
    (hkArray<hkaiDirectedGraphExplicitCost::Node,hkContainerHeapAllocator> *)(unsigned int)(v3 + v4->m_edges.m_size),
    -1,
    sizeElem);
  if ( v16 )
    return 0i64;
  v13 = v4->m_edges.m_size;
  v4->m_edges.m_size = v13 + v3;
  return &v4->m_edges.m_data[v13];
}

// File Line: 179
// RVA: 0xBE7A00
hkResult *__fastcall hkaiDirectedGraphExplicitCost::setNodesSize(hkaiDirectedGraphExplicitCost *this, hkResult *result, int newSize)
{
  int v3; // eax
  hkResult *v4; // rbx
  int v5; // eax

  v3 = this->m_nodes.m_size;
  v4 = result;
  if ( newSize <= v3 )
  {
    v5 = this->m_nodeDataStriding;
    this->m_nodes.m_size = newSize;
    this->m_positions.m_size = newSize;
    if ( v5 )
      this->m_nodeData.m_size = newSize * v5;
    goto LABEL_4;
  }
  if ( hkaiDirectedGraphExplicitCost::expandNodesBy(this, newSize - v3) )
  {
LABEL_4:
    v4->m_enum = 0;
    return v4;
  }
  v4->m_enum = 1;
  return v4;
}

// File Line: 203
// RVA: 0xBE7A60
hkResult *__fastcall hkaiDirectedGraphExplicitCost::setEdgesSize(hkaiDirectedGraphExplicitCost *this, hkResult *result, int newSize)
{
  int v3; // eax
  hkResult *v4; // rbx
  int v5; // eax

  v3 = this->m_edges.m_size;
  v4 = result;
  if ( newSize <= v3 )
  {
    v5 = this->m_edgeDataStriding;
    this->m_edges.m_size = newSize;
    if ( v5 )
      this->m_edgeData.m_size = newSize * v5;
    goto LABEL_4;
  }
  if ( hkaiDirectedGraphExplicitCost::expandEdgesBy(this, newSize - v3) )
  {
LABEL_4:
    v4->m_enum = 0;
    return v4;
  }
  v4->m_enum = 1;
  return v4;
}

