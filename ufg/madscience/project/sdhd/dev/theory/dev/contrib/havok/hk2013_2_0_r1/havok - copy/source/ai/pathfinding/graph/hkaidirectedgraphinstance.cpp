// File Line: 16
// RVA: 0xBE80C0
void __fastcall hkaiDirectedGraphInstance::hkaiDirectedGraphInstance(hkaiDirectedGraphInstance *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiDirectedGraphInstance::`vftable;
  this->m_originalGraph.m_pntr = 0i64;
  this->m_nodeMap.m_data = 0i64;
  this->m_nodeMap.m_size = 0;
  this->m_nodeMap.m_capacityAndFlags = 2147483648;
  this->m_instancedNodes.m_data = 0i64;
  this->m_instancedNodes.m_size = 0;
  this->m_instancedNodes.m_capacityAndFlags = 2147483648;
  this->m_ownedEdges.m_data = 0i64;
  this->m_ownedEdges.m_size = 0;
  this->m_ownedEdges.m_capacityAndFlags = 2147483648;
  this->m_ownedEdgeData.m_data = 0i64;
  this->m_ownedEdgeData.m_size = 0;
  this->m_ownedEdgeData.m_capacityAndFlags = 2147483648;
  this->m_userEdgeCount.m_data = 0i64;
  this->m_userEdgeCount.m_size = 0;
  this->m_userEdgeCount.m_capacityAndFlags = 2147483648;
  this->m_freeEdgeBlocks.m_data = 0i64;
  this->m_freeEdgeBlocks.m_size = 0;
  this->m_freeEdgeBlocks.m_capacityAndFlags = 2147483648;
  *(_QWORD *)&this->m_sectionUid = -1i64;
  this->m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform.m_translation = 0i64;
}

// File Line: 31
// RVA: 0xBE81A0
void __fastcall hkaiDirectedGraphInstance::hkaiDirectedGraphInstance(hkaiDirectedGraphInstance *this, hkFinishLoadedObjectFlag f)
{
  hkaiDirectedGraphExplicitCost *v2; // rdx

  this->vfptr = (hkBaseObjectVtbl *)&hkaiDirectedGraphInstance::`vftable;
  if ( f.m_finishing )
  {
    v2 = this->m_originalGraph.m_pntr;
    if ( v2 )
    {
      this->m_originalNodes = v2->m_nodes.m_data;
      this->m_numOriginalNodes = v2->m_nodes.m_size;
      this->m_originalEdges = v2->m_edges.m_data;
      this->m_numOriginalEdges = v2->m_edges.m_size;
      this->m_originalPositions = v2->m_positions.m_data;
      this->m_originalNodeData = v2->m_nodeData.m_data;
      this->m_nodeDataStriding = v2->m_nodeDataStriding;
      this->m_originalEdgeData = v2->m_edgeData.m_data;
      this->m_edgeDataStriding = v2->m_edgeDataStriding;
    }
  }
}

// File Line: 39
// RVA: 0xBE8210
void __fastcall hkaiDirectedGraphInstance::init(hkaiDirectedGraphInstance *this, hkaiDirectedGraphExplicitCost *graph, unsigned int uid)
{
  hkaiDirectedGraphExplicitCost *v3; // rbx
  hkaiDirectedGraphInstance *v4; // rsi
  hkReferencedObject *v5; // rcx
  int v6; // ebp
  int v7; // eax
  int v8; // eax
  int v9; // er9
  int v10; // edx
  int *v11; // rdi
  __int64 v12; // rcx
  hkResult result; // [rsp+60h] [rbp+18h]

  v3 = graph;
  v4 = this;
  this->m_sectionUid = uid;
  if ( graph )
    hkReferencedObject::addReference((hkReferencedObject *)&graph->vfptr);
  v5 = (hkReferencedObject *)&v4->m_originalGraph.m_pntr->vfptr;
  if ( v5 )
    hkReferencedObject::removeReference(v5);
  v4->m_originalGraph.m_pntr = v3;
  v6 = v3->m_nodes.m_size;
  v7 = v4->m_nodeMap.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < v6 )
  {
    v8 = 2 * v7;
    v9 = v3->m_nodes.m_size;
    if ( v6 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v4->m_nodeMap, v9, 4);
  }
  v10 = v6 - v4->m_nodeMap.m_size;
  v11 = &v4->m_nodeMap.m_data[v4->m_nodeMap.m_size];
  v12 = v10;
  if ( v10 > 0 )
  {
    while ( v12 )
    {
      *v11 = -1;
      ++v11;
      --v12;
    }
  }
  v4->m_nodeMap.m_size = v6;
  v4->m_originalNodes = v3->m_nodes.m_data;
  v4->m_numOriginalNodes = v3->m_nodes.m_size;
  v4->m_originalEdges = v3->m_edges.m_data;
  v4->m_numOriginalEdges = v3->m_edges.m_size;
  v4->m_originalPositions = v3->m_positions.m_data;
  v4->m_originalNodeData = v3->m_nodeData.m_data;
  v4->m_nodeDataStriding = v3->m_nodeDataStriding;
  v4->m_originalEdgeData = v3->m_edgeData.m_data;
  v4->m_edgeDataStriding = v3->m_edgeDataStriding;
}

// File Line: 50
// RVA: 0xBE8300
void __fastcall hkaiDirectedGraphInstance::tempInit(hkaiDirectedGraphInstance *this, hkaiDirectedGraphExplicitCost *graph)
{
  hkaiDirectedGraphExplicitCost *v2; // rbx
  hkaiDirectedGraphInstance *v3; // rdi
  hkReferencedObject *v4; // rcx

  v2 = graph;
  v3 = this;
  this->m_runtimeId = 0;
  if ( graph )
    hkReferencedObject::addReference((hkReferencedObject *)&graph->vfptr);
  v4 = (hkReferencedObject *)&v3->m_originalGraph.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v3->m_originalGraph.m_pntr = v2;
  if ( v2 )
  {
    v3->m_originalNodes = v2->m_nodes.m_data;
    v3->m_numOriginalNodes = v2->m_nodes.m_size;
    v3->m_originalEdges = v2->m_edges.m_data;
    v3->m_numOriginalEdges = v2->m_edges.m_size;
    v3->m_originalPositions = v2->m_positions.m_data;
    v3->m_originalNodeData = v2->m_nodeData.m_data;
    v3->m_nodeDataStriding = v2->m_nodeDataStriding;
    v3->m_originalEdgeData = v2->m_edgeData.m_data;
    v3->m_edgeDataStriding = v2->m_edgeDataStriding;
  }
}

// File Line: 63
// RVA: 0xBE8C10
int __fastcall hkaiDirectedGraphInstance::expandEdgesBy(hkaiDirectedGraphInstance *this, int n)
{
  int v2; // esi
  hkaiDirectedGraphInstance *v3; // rbx
  int v4; // eax
  int v5; // er15
  int v6; // ebp
  int v7; // eax
  int v8; // eax
  int v9; // er9
  int v10; // edx
  int *v11; // rdi
  __int64 v12; // rcx
  int v13; // er9
  int v14; // eax
  int v15; // eax
  int v16; // esi
  int v17; // eax
  int v18; // eax
  int v19; // er9
  int v20; // edx
  unsigned int *v21; // rdi
  __int64 v22; // rcx
  hkResult result; // [rsp+60h] [rbp+18h]

  v2 = n;
  v3 = this;
  v4 = hkaiDirectedGraphInstance::findFreeBlock(this, n);
  if ( v4 == -1 )
  {
    v5 = v3->m_userEdgeCount.m_size;
    v6 = v5 + v2;
    v7 = v3->m_userEdgeCount.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v7 < v5 + v2 )
    {
      v8 = 2 * v7;
      v9 = v5 + v2;
      if ( v6 < v8 )
        v9 = v8;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v3->m_userEdgeCount,
        v9,
        4);
    }
    v10 = v6 - v3->m_userEdgeCount.m_size;
    v11 = &v3->m_userEdgeCount.m_data[v3->m_userEdgeCount.m_size];
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
    v3->m_userEdgeCount.m_size = v6;
    v13 = v2 + v3->m_ownedEdges.m_size;
    v14 = v3->m_ownedEdges.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v14 < v13 )
    {
      v15 = 2 * v14;
      if ( v13 < v15 )
        v13 = v15;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v3->m_ownedEdges,
        v13,
        8);
    }
    v3->m_ownedEdges.m_size += v2;
    v16 = v6 * v3->m_edgeDataStriding;
    v17 = v3->m_ownedEdgeData.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v17 < v16 )
    {
      v18 = 2 * v17;
      v19 = v6 * v3->m_edgeDataStriding;
      if ( v16 < v18 )
        v19 = v18;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v3->m_ownedEdgeData,
        v19,
        4);
    }
    v20 = v16 - v3->m_ownedEdgeData.m_size;
    v21 = &v3->m_ownedEdgeData.m_data[v3->m_ownedEdgeData.m_size];
    v22 = v20;
    if ( v20 > 0 )
    {
      while ( v22 )
      {
        *v21 = 0;
        ++v21;
        --v22;
      }
    }
    v3->m_ownedEdgeData.m_size = v16;
    v4 = v5 + v3->m_numOriginalEdges;
  }
  return v4;
}

// File Line: 83
// RVA: 0xBE8390
signed __int64 __fastcall hkaiDirectedGraphInstance::getClosestNode(hkaiDirectedGraphInstance *this, hkVector4f *position)
{
  int v2; // er11
  float v3; // xmm3_4
  int v4; // er8
  signed int v5; // er10
  hkaiDirectedGraphInstance *v6; // r9
  int v7; // eax
  hkVector4f v8; // xmm4
  hkVector4f v9; // xmm5
  hkVector4f v10; // xmm6
  hkVector4f v11; // xmm7
  hkVector4f *v12; // rcx
  __m128 v13; // xmm2
  __m128 v14; // xmm2
  float v15; // xmm1_4

  v2 = this->m_numOriginalNodes;
  v3 = *(float *)&xmmword_141A712A0;
  v4 = 0;
  v5 = -1;
  v6 = this;
  v7 = 0;
  if ( v2 <= 0 )
    return 0xFFFFFFFFi64;
  v8.m_quad = (__m128)this->m_transform.m_rotation.m_col1;
  v9.m_quad = (__m128)this->m_transform.m_rotation.m_col0;
  v10.m_quad = (__m128)this->m_transform.m_rotation.m_col2;
  v11.m_quad = (__m128)this->m_transform.m_translation;
  v12 = this->m_originalPositions;
  do
  {
    v13 = _mm_sub_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v12->m_quad, v12->m_quad, 0), v9.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v12->m_quad, v12->m_quad, 85), v8.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v12->m_quad, v12->m_quad, 170), v10.m_quad)),
              v11.m_quad),
            position->m_quad);
    v14 = _mm_mul_ps(v13, v13);
    v15 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 0)))
        + COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 170));
    if ( v15 < v3 )
    {
      v3 = v15;
      v5 = v7;
    }
    ++v7;
    ++v12;
  }
  while ( v7 < v2 );
  if ( v5 < 0 )
    return 0xFFFFFFFFi64;
  if ( v6->m_runtimeId > 0 )
    v4 = v6->m_runtimeId;
  return v5 | (unsigned int)(v4 << 22);
}

// File Line: 115
// RVA: 0xBE8870
hkaiDirectedGraphExplicitCost::Edge *__fastcall hkaiDirectedGraphInstance::addEdgeForNode(hkaiDirectedGraphInstance *this, __int64 n, unsigned int **edgeDataPtrOut)
{
  int *v3; // rax
  int v4; // er13
  int v5; // esi
  unsigned int **v6; // r14
  hkaiDirectedGraphInstance *v7; // rbx
  __int64 v8; // rdx
  hkaiDirectedGraphExplicitCost::Node *v9; // r8
  int *v10; // rdi
  int v11; // eax
  int v12; // er9
  int v13; // ebp
  signed __int64 v14; // r12
  int *v15; // rcx
  signed __int64 v16; // r15
  int *v17; // rsi
  _DWORD *v18; // r11
  int v19; // eax
  int v20; // ecx
  hkaiDirectedGraphExplicitCost::Edge *v21; // rax
  signed __int64 v22; // rdx
  signed __int64 v23; // r10
  unsigned int *v24; // rcx
  char *v25; // r8
  char *v26; // rax
  __int64 v27; // rdx
  signed __int64 v28; // r8
  int v29; // ecx
  int v30; // ecx
  __int64 v31; // r8
  signed __int64 v32; // rsi
  int v34; // [rsp+58h] [rbp+10h]

  v3 = this->m_nodeMap.m_data;
  v4 = this->m_numOriginalEdges;
  n = (signed int)n;
  v5 = v3[(signed int)n];
  v6 = edgeDataPtrOut;
  v7 = this;
  if ( v5 == -1 )
  {
    v5 = this->m_instancedNodes.m_size;
    v3[n] = v5;
    if ( this->m_instancedNodes.m_size == (this->m_instancedNodes.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &this->m_instancedNodes,
        8);
    v8 = v7->m_instancedNodes.m_size;
    v9 = &v7->m_instancedNodes.m_data[v8];
    v7->m_instancedNodes.m_size = v8 + 1;
    v9->m_numEdges = 0;
    v9->m_startEdgeIndex = -1;
  }
  v10 = (int *)&v7->m_instancedNodes.m_data[v5];
  v11 = hkaiDirectedGraphInstance::expandEdgesBy(v7, v10[1] + 1);
  v12 = 0;
  v34 = v11;
  v13 = v11 - v7->m_numOriginalEdges;
  v14 = (signed __int64)&v7->m_ownedEdges.m_data[v13];
  v15 = v7->m_userEdgeCount.m_data;
  v16 = (signed __int64)&v15[v13];
  if ( v10[1] > 0 )
  {
    v17 = &v15[v13];
    v18 = (_DWORD *)(v14 + 4);
    do
    {
      v19 = v7->m_numOriginalEdges;
      v20 = v12 + *v10;
      if ( v20 >= v19 )
      {
        v20 -= v19;
        v21 = v7->m_ownedEdges.m_data;
      }
      else
      {
        v21 = v7->m_originalEdges;
      }
      v22 = (signed __int64)&v21[v20];
      *((_WORD *)v18 - 2) = v21[v20].m_cost.m_value;
      *((_WORD *)v18 - 1) = *(_WORD *)(v22 + 2);
      *v18 = *(_DWORD *)(v22 + 4);
      LODWORD(v22) = v12 + *v10 - v4;
      *v17 = v7->m_userEdgeCount.m_data[(signed int)v22];
      v23 = v7->m_edgeDataStriding;
      v24 = v7->m_ownedEdgeData.m_data;
      v25 = (char *)&v24[(signed int)v22 * v7->m_edgeDataStriding];
      v26 = (char *)&v24[(signed int)v23 * (v12 + v13)];
      if ( (_DWORD)v23 == 1 )
      {
        *(_DWORD *)v26 = *(_DWORD *)v25;
      }
      else
      {
        v27 = v7->m_edgeDataStriding;
        if ( v23 >= 1 )
        {
          v28 = v25 - v26;
          do
          {
            v29 = *(_DWORD *)&v26[v28];
            v26 += 4;
            *((_DWORD *)v26 - 1) = v29;
            --v27;
          }
          while ( v27 );
        }
      }
      ++v12;
      v18 += 2;
      ++v17;
    }
    while ( v12 < v10[1] );
  }
  if ( v6 )
  {
    v30 = v7->m_edgeDataStriding;
    if ( v30 )
      *v6 = &v7->m_ownedEdgeData.m_data[v30 * (v13 + v10[1])];
    else
      *v6 = 0i64;
  }
  v31 = v10[1];
  v32 = v14 + 8 * v31;
  if ( (_DWORD)v31 )
    hkaiDirectedGraphInstance::addFreeBlock(v7, *v10, v31);
  *(_DWORD *)(v16 + 4i64 * v10[1]++) = 0;
  *v10 = v34;
  return (hkaiDirectedGraphExplicitCost::Edge *)v32;
}

// File Line: 171
// RVA: 0xBE8A90
void __fastcall hkaiDirectedGraphInstance::removeOwnedEdgeForNode(hkaiDirectedGraphInstance *this, __int64 n, int e)
{
  int *v3; // rax
  int v4; // ebp
  int v5; // esi
  hkaiDirectedGraphInstance *v6; // rbx
  __int64 v7; // rdx
  hkaiDirectedGraphExplicitCost::Node *v8; // r8
  hkaiDirectedGraphExplicitCost::Node *v9; // rax
  int v10; // ebp
  int v11; // edx
  hkaiDirectedGraphExplicitCost::Node *v12; // rdi
  int v13; // esi
  int v14; // edx
  int v15; // esi
  hkaiDirectedGraphExplicitCost::Edge *v16; // rax
  signed __int64 v17; // rcx
  signed __int64 v18; // rdx
  signed __int64 v19; // rdx
  unsigned int *v20; // rcx
  char *v21; // r8
  char *v22; // rax
  signed __int64 v23; // r8
  int v24; // ecx

  v3 = this->m_nodeMap.m_data;
  n = (signed int)n;
  v4 = e;
  v5 = v3[(signed int)n];
  v6 = this;
  if ( v5 == -1 )
  {
    v5 = this->m_instancedNodes.m_size;
    v3[n] = v5;
    if ( this->m_instancedNodes.m_size == (this->m_instancedNodes.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &this->m_instancedNodes,
        8);
    v7 = v6->m_instancedNodes.m_size;
    v8 = &v6->m_instancedNodes.m_data[v7];
    v6->m_instancedNodes.m_size = v7 + 1;
    v8->m_numEdges = 0;
    v8->m_startEdgeIndex = -1;
  }
  v9 = v6->m_instancedNodes.m_data;
  v10 = v4 - v6->m_numOriginalEdges;
  v11 = v9[v5].m_startEdgeIndex;
  v12 = &v9[v5];
  v13 = v9[v5].m_numEdges - 1;
  LODWORD(v9) = v11 - v6->m_numOriginalEdges;
  v14 = v13 + v11;
  v15 = (_DWORD)v9 + v13;
  hkaiDirectedGraphInstance::addFreeBlock(v6, v14, 1);
  if ( v12->m_numEdges == 1 )
  {
    v12->m_numEdges = 0;
    v12->m_startEdgeIndex = -1;
    v6->m_userEdgeCount.m_data[v10] = 0;
  }
  else
  {
    v16 = v6->m_ownedEdges.m_data;
    v17 = (signed __int64)&v16[v10];
    v18 = (signed __int64)&v16[v15];
    *(_WORD *)v17 = v16[v15].m_cost.m_value;
    *(_WORD *)(v17 + 2) = *(_WORD *)(v18 + 2);
    *(_DWORD *)(v17 + 4) = *(_DWORD *)(v18 + 4);
    v6->m_userEdgeCount.m_data[v10] = v6->m_userEdgeCount.m_data[v15];
    v19 = v6->m_edgeDataStriding;
    v20 = v6->m_ownedEdgeData.m_data;
    v21 = (char *)&v20[v15 * v6->m_edgeDataStriding];
    v22 = (char *)&v20[v10 * v6->m_edgeDataStriding];
    if ( (_DWORD)v19 == 1 )
    {
      *(_DWORD *)v22 = *(_DWORD *)v21;
    }
    else if ( v19 >= 1 )
    {
      v23 = v21 - v22;
      do
      {
        v24 = *(_DWORD *)&v22[v23];
        v22 += 4;
        *((_DWORD *)v22 - 1) = v24;
        --v19;
      }
      while ( v19 );
    }
    --v12->m_numEdges;
  }
}

// File Line: 200
// RVA: 0xBE8E50
void __fastcall hkaiDirectedGraphInstance::addFreeBlock(hkaiDirectedGraphInstance *this, int blockStart, int blockSize)
{
  int v3; // er15
  int v4; // er12
  hkaiDirectedGraphInstance *v5; // r14
  int v6; // esi
  hkArray<hkaiDirectedGraphInstance::FreeBlockList,hkContainerHeapAllocator> *v7; // rbp
  int v8; // eax
  int v9; // eax
  int v10; // er9
  int v11; // eax
  __int64 v12; // rdi
  int *v13; // rbx
  int v14; // er8
  __int64 v15; // rax
  int v16; // ecx
  signed __int64 v17; // rax
  __int64 v18; // rdx
  hkaiDirectedGraphInstance::FreeBlockList *v19; // rbx
  __int64 v20; // [rsp+68h] [rbp+10h]

  v3 = blockSize - 1;
  v4 = blockStart;
  v5 = this;
  v6 = blockSize;
  if ( this->m_freeEdgeBlocks.m_size < blockSize )
  {
    v7 = &this->m_freeEdgeBlocks;
    v8 = this->m_freeEdgeBlocks.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v8 < blockSize )
    {
      v9 = 2 * v8;
      v10 = blockSize;
      if ( blockSize < v9 )
        v10 = v9;
      hkArrayUtil::_reserve(
        (hkResult *)&v20,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        v7,
        v10,
        16);
    }
    v11 = v7->m_size - v6 - 1;
    v12 = v11;
    if ( v11 >= 0 )
    {
      v13 = &v7->m_data[v6].m_blocks.m_capacityAndFlags + 4 * v11;
      do
      {
        v14 = *v13;
        *(v13 - 1) = 0;
        if ( v14 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            *(void **)(v13 - 3),
            4 * v14);
        *(_QWORD *)(v13 - 3) = 0i64;
        *v13 = 2147483648;
        v13 -= 4;
        --v12;
      }
      while ( v12 >= 0 );
    }
    v15 = v7->m_size;
    v16 = v6 - v15;
    v17 = (signed __int64)&v7->m_data[v15];
    v18 = v16;
    if ( v16 > 0 )
    {
      do
      {
        if ( v17 )
        {
          *(_QWORD *)v17 = 0i64;
          *(_DWORD *)(v17 + 8) = 0;
          *(_DWORD *)(v17 + 12) = 2147483648;
        }
        v17 += 16i64;
        --v18;
      }
      while ( v18 );
    }
    v7->m_size = v6;
  }
  v19 = &v5->m_freeEdgeBlocks.m_data[v3];
  if ( v19->m_blocks.m_size == (v19->m_blocks.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v19, 4);
  v19->m_blocks.m_data[v19->m_blocks.m_size++] = v4;
}

// File Line: 213
// RVA: 0xBE8FE0
signed __int64 __fastcall hkaiDirectedGraphInstance::findFreeBlock(hkaiDirectedGraphInstance *this, int blockSize)
{
  signed __int64 v2; // r9
  int v3; // er10
  int v4; // ebx
  hkaiDirectedGraphInstance *v5; // r11
  signed __int64 v7; // rcx
  int v8; // er8
  hkaiDirectedGraphInstance::FreeBlockList *v9; // rdi
  int *v10; // rdx
  signed __int64 v11; // rdx
  unsigned int v12; // edi
  int v13; // er8
  int v14; // esi
  hkaiDirectedGraphInstance::FreeBlockList *v15; // rbx

  v2 = this->m_freeEdgeBlocks.m_size;
  v3 = blockSize - 1;
  v4 = blockSize;
  v5 = this;
  if ( (signed int)v2 < blockSize )
    return 0xFFFFFFFFi64;
  v7 = v3;
  v8 = blockSize - 1;
  if ( v3 >= v2 )
    return 0xFFFFFFFFi64;
  v9 = v5->m_freeEdgeBlocks.m_data;
  v10 = &v9->m_blocks.m_size + 4 * v3;
  while ( *v10 <= 0 )
  {
    ++v7;
    ++v8;
    v10 += 4;
    if ( v7 >= v2 )
      return 0xFFFFFFFFi64;
  }
  v11 = (signed __int64)&v9[v8];
  v12 = *(_DWORD *)(*(_QWORD *)v11 + 4i64 * (signed int)(*(_DWORD *)(v11 + 8))-- - 4);
  v13 = v8 - v3;
  if ( v13 )
  {
    v14 = v12 + v4;
    v15 = &v5->m_freeEdgeBlocks.m_data[v13 - 1];
    if ( v15->m_blocks.m_size == (v15->m_blocks.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v15, 4);
    v15->m_blocks.m_data[v15->m_blocks.m_size++] = v14;
  }
  return v12;
}

// File Line: 248
// RVA: 0xBE8490
void __fastcall hkaiDirectedGraphInstance::validate(hkaiDirectedGraphInstance *this)
{
  hkaiDirectedGraphInstance *v1; // r15
  int v2; // er14
  int v3; // ebx
  hkLifoAllocator *v4; // rax
  char *v5; // rcx
  int v6; // edx
  char *v7; // rdi
  signed int v8; // eax
  int v9; // eax
  int v10; // er9
  _DWORD *v11; // rdi
  __int64 i; // rcx
  LPVOID v13; // rax
  hkLifoAllocator *v14; // rcx
  unsigned int *v15; // rax
  int v16; // edx
  char *v17; // rdi
  signed int v18; // esi
  int v19; // er9
  unsigned int *v20; // rdi
  __int64 j; // rcx
  int v22; // er10
  __int64 v23; // r11
  __int64 v24; // rbx
  hkaiDirectedGraphExplicitCost::Node *v25; // r9
  int k; // er8
  _DWORD *v27; // rdi
  char v28; // cl
  __int64 v29; // rcx
  hkaiDirectedGraphExplicitCost::Node v30; // rax
  int v31; // ecx
  int v32; // edx
  __int64 v33; // rdi
  __int64 v34; // r8
  __int64 v35; // rcx
  int v36; // ebx
  __int64 v37; // rsi
  hkaiDirectedGraphInstance::FreeBlockList *v38; // r11
  int v39; // er9
  __int64 v40; // r10
  int v41; // ecx
  int v42; // eax
  __int64 v43; // rdi
  __int64 v44; // r8
  __int64 v45; // rdx
  _DWORD *array; // [rsp+30h] [rbp-50h]
  int v47; // [rsp+38h] [rbp-48h]
  unsigned int v48; // [rsp+3Ch] [rbp-44h]
  char *v49; // [rsp+40h] [rbp-40h]
  int v50; // [rsp+48h] [rbp-38h]
  int v51; // [rsp+50h] [rbp-30h]
  hkBitFieldStorage<hkLocalArray<unsigned int> > v52; // [rsp+58h] [rbp-28h]
  hkaiDirectedGraphExplicitCost::Node result; // [rsp+B0h] [rbp+30h]

  v1 = this;
  hkaiDirectedGraphExplicitCost::validate(this->m_originalGraph.m_pntr);
  v2 = v1->m_numOriginalEdges + v1->m_ownedEdges.m_size;
  array = 0i64;
  v47 = 0;
  v48 = 2147483648;
  v3 = (v2 + 31) >> 5;
  v50 = v3;
  if ( v3 )
  {
    v4 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v5 = (char *)v4->m_cur;
    v6 = (4 * v3 + 127) & 0xFFFFFF80;
    v7 = &v5[v6];
    if ( v6 > v4->m_slabSize || v7 > v4->m_end )
      v5 = (char *)hkLifoAllocator::allocateFromNewSlab(v4, v6);
    else
      v4->m_cur = v7;
  }
  else
  {
    v5 = 0i64;
  }
  array = v5;
  v49 = v5;
  v51 = v2;
  v48 = v3 | 0x80000000;
  v8 = (v3 | 0x80000000) & 0x3FFFFFFF;
  if ( v8 < v3 )
  {
    v9 = 2 * v8;
    v10 = (v2 + 31) >> 5;
    if ( v3 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(
      (hkResult *)&result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array,
      v10,
      4);
  }
  v47 = (v2 + 31) >> 5;
  if ( v3 - 1 >= 0 )
  {
    v11 = array;
    for ( i = (unsigned int)v3; i; --i )
    {
      *v11 = 0;
      ++v11;
    }
  }
  v52.m_words.m_data = 0i64;
  v52.m_words.m_size = 0;
  v52.m_words.m_capacityAndFlags = 2147483648;
  v52.m_words.m_initialCapacity = (v2 + 31) >> 5;
  if ( v3 )
  {
    v13 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v14 = (hkLifoAllocator *)v13;
    v15 = (unsigned int *)*((_QWORD *)v13 + 3);
    v16 = (4 * v3 + 127) & 0xFFFFFF80;
    v17 = (char *)v15 + v16;
    if ( v16 > v14->m_slabSize || v17 > v14->m_end )
      v15 = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(v14, v16);
    else
      v14->m_cur = v17;
  }
  else
  {
    v15 = 0i64;
  }
  v52.m_words.m_capacityAndFlags = v3 | 0x80000000;
  v18 = (v3 | 0x80000000) & 0x3FFFFFFF;
  v52.m_numBits = v2;
  v52.m_words.m_data = v15;
  v52.m_words.m_localMemory = v15;
  if ( v18 < v3 )
  {
    v19 = (v2 + 31) >> 5;
    if ( v3 < 2 * v18 )
      v19 = 2 * v18;
    hkArrayUtil::_reserve(
      (hkResult *)&result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v52,
      v19,
      4);
  }
  v52.m_words.m_size = (v2 + 31) >> 5;
  if ( v3 - 1 >= 0 )
  {
    v20 = v52.m_words.m_data;
    for ( j = (unsigned int)v3; j; --j )
    {
      *v20 = 0;
      ++v20;
    }
  }
  v22 = 0;
  if ( v1->m_numOriginalNodes > 0 )
  {
    v23 = 0i64;
    v24 = 0i64;
    do
    {
      v25 = &v1->m_originalNodes[v24];
      for ( k = v25->m_startEdgeIndex; k < v25->m_numEdges + v25->m_startEdgeIndex; *v27 |= 1 << (v28 & 0x1F) )
      {
        v27 = &array[(signed __int64)k >> 5];
        v28 = k++;
      }
      if ( v1->m_nodeMap.m_size && (v29 = v1->m_nodeMap.m_data[v23], (_DWORD)v29 != -1) )
      {
        v30 = v1->m_instancedNodes.m_data[v29];
        result = v1->m_instancedNodes.m_data[v29];
        v31 = result.m_startEdgeIndex;
      }
      else
      {
        v31 = -1;
        result = (hkaiDirectedGraphExplicitCost::Node)0xFFFFFFFFi64;
        v30.m_numEdges = 0;
      }
      v32 = __ROL4__(1, v31);
      if ( v31 < v31 + v30.m_numEdges )
      {
        v33 = v31;
        v34 = (unsigned int)v30.m_numEdges;
        do
        {
          v35 = v33++;
          array[v35 >> 5] |= v32;
          v32 = __ROL4__(v32, 1);
          --v34;
        }
        while ( v34 );
      }
      ++v22;
      ++v24;
      ++v23;
    }
    while ( v22 < v1->m_numOriginalNodes );
  }
  v36 = 0;
  if ( v1->m_freeEdgeBlocks.m_size > 0 )
  {
    v37 = 0i64;
    do
    {
      v38 = v1->m_freeEdgeBlocks.m_data;
      v39 = 0;
      if ( v38[v37].m_blocks.m_size > 0 )
      {
        v40 = 0i64;
        do
        {
          v41 = v38[v37].m_blocks.m_data[v40];
          v42 = __ROL4__(1, v41);
          if ( v41 < v41 + v36 + 1 )
          {
            v43 = v38[v37].m_blocks.m_data[v40];
            v44 = (unsigned int)(v36 + 1);
            do
            {
              v45 = v43++;
              v52.m_words.m_data[v45 >> 5] |= v42;
              v42 = __ROL4__(v42, 1);
              --v44;
            }
            while ( v44 );
          }
          ++v39;
          ++v40;
        }
        while ( v39 < v38[v37].m_blocks.m_size );
      }
      ++v36;
      ++v37;
    }
    while ( v36 < v1->m_freeEdgeBlocks.m_size );
  }
  hkBitFieldStorage<hkLocalArray<unsigned int>>::~hkBitFieldStorage<hkLocalArray<unsigned int>>(&v52);
  hkBitFieldStorage<hkLocalArray<unsigned int>>::~hkBitFieldStorage<hkLocalArray<unsigned int>>((hkBitFieldStorage<hkLocalArray<unsigned int> > *)&array);
}

// File Line: 316
// RVA: 0xBE8D90
void __fastcall hkaiDirectedGraphInstance::clearOwnedEdges(hkaiDirectedGraphInstance *this)
{
  hkaiDirectedGraphInstance *v1; // rsi
  int v2; // eax
  hkaiDirectedGraphInstance::FreeBlockList *v3; // rcx
  int v4; // eax
  __int64 v5; // rdi
  int *v6; // rbx
  int v7; // er8

  v1 = this;
  this->m_ownedEdges.m_size = 0;
  this->m_ownedEdgeData.m_size = 0;
  v2 = this->m_freeEdgeBlocks.m_size;
  v3 = this->m_freeEdgeBlocks.m_data;
  v4 = v2 - 1;
  v5 = v4;
  if ( v4 >= 0 )
  {
    v6 = &v3->m_blocks.m_capacityAndFlags + 4 * v4;
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
      v6 -= 4;
      --v5;
    }
    while ( v5 >= 0 );
  }
  v1->m_freeEdgeBlocks.m_size = 0;
  v1->m_userEdgeCount.m_size = 0;
}

// File Line: 324
// RVA: 0xBE87E0
void __fastcall hkaiDirectedGraphInstance::updateInternalPointers(hkaiDirectedGraphInstance *this)
{
  hkaiDirectedGraphExplicitCost *v1; // rdx
  hkArray<unsigned int,hkContainerHeapAllocator> *v2; // r8
  int v3; // er9
  char v4; // [rsp+40h] [rbp+8h]

  v1 = this->m_originalGraph.m_pntr;
  v2 = (hkArray<unsigned int,hkContainerHeapAllocator> *)(unsigned int)this->m_edgeDataStriding;
  this->m_originalNodes = v1->m_nodes.m_data;
  this->m_numOriginalNodes = v1->m_nodes.m_size;
  this->m_originalEdges = v1->m_edges.m_data;
  this->m_numOriginalEdges = v1->m_edges.m_size;
  this->m_originalPositions = v1->m_positions.m_data;
  this->m_originalNodeData = v1->m_nodeData.m_data;
  this->m_nodeDataStriding = v1->m_nodeDataStriding;
  this->m_originalEdgeData = v1->m_edgeData.m_data;
  v3 = v1->m_edgeDataStriding;
  this->m_edgeDataStriding = v3;
  if ( (_DWORD)v2 != v3 )
    hkaiUserDataUtils::restride<unsigned int>(
      (hkaiUserDataUtils *)&v4,
      (hkResult *)&this->m_ownedEdgeData,
      v2,
      v3,
      this->m_ownedEdges.m_size,
      0);
}

