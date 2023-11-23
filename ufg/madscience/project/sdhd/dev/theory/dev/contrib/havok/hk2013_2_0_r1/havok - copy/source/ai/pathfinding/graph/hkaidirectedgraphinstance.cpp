// File Line: 16
// RVA: 0xBE80C0
void __fastcall hkaiDirectedGraphInstance::hkaiDirectedGraphInstance(hkaiDirectedGraphInstance *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiDirectedGraphInstance::`vftable;
  this->m_originalGraph.m_pntr = 0i64;
  this->m_nodeMap.m_data = 0i64;
  this->m_nodeMap.m_size = 0;
  this->m_nodeMap.m_capacityAndFlags = 0x80000000;
  this->m_instancedNodes.m_data = 0i64;
  this->m_instancedNodes.m_size = 0;
  this->m_instancedNodes.m_capacityAndFlags = 0x80000000;
  this->m_ownedEdges.m_data = 0i64;
  this->m_ownedEdges.m_size = 0;
  this->m_ownedEdges.m_capacityAndFlags = 0x80000000;
  this->m_ownedEdgeData.m_data = 0i64;
  this->m_ownedEdgeData.m_size = 0;
  this->m_ownedEdgeData.m_capacityAndFlags = 0x80000000;
  this->m_userEdgeCount.m_data = 0i64;
  this->m_userEdgeCount.m_size = 0;
  this->m_userEdgeCount.m_capacityAndFlags = 0x80000000;
  this->m_freeEdgeBlocks.m_data = 0i64;
  this->m_freeEdgeBlocks.m_size = 0;
  this->m_freeEdgeBlocks.m_capacityAndFlags = 0x80000000;
  *(_QWORD *)&this->m_sectionUid = -1i64;
  this->m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform.m_translation = 0i64;
}

// File Line: 31
// RVA: 0xBE81A0
void __fastcall hkaiDirectedGraphInstance::hkaiDirectedGraphInstance(
        hkaiDirectedGraphInstance *this,
        hkFinishLoadedObjectFlag f)
{
  hkaiDirectedGraphExplicitCost *m_pntr; // rdx

  this->vfptr = (hkBaseObjectVtbl *)&hkaiDirectedGraphInstance::`vftable;
  if ( f.m_finishing )
  {
    m_pntr = this->m_originalGraph.m_pntr;
    if ( m_pntr )
    {
      this->m_originalNodes = m_pntr->m_nodes.m_data;
      this->m_numOriginalNodes = m_pntr->m_nodes.m_size;
      this->m_originalEdges = m_pntr->m_edges.m_data;
      this->m_numOriginalEdges = m_pntr->m_edges.m_size;
      this->m_originalPositions = m_pntr->m_positions.m_data;
      this->m_originalNodeData = m_pntr->m_nodeData.m_data;
      this->m_nodeDataStriding = m_pntr->m_nodeDataStriding;
      this->m_originalEdgeData = m_pntr->m_edgeData.m_data;
      this->m_edgeDataStriding = m_pntr->m_edgeDataStriding;
    }
  }
}

// File Line: 39
// RVA: 0xBE8210
void __fastcall hkaiDirectedGraphInstance::init(
        hkaiDirectedGraphInstance *this,
        hkaiDirectedGraphExplicitCost *graph,
        unsigned int uid)
{
  hkaiDirectedGraphExplicitCost *m_pntr; // rcx
  int m_size; // ebp
  int v7; // eax
  int v8; // eax
  int v9; // r9d
  int v10; // edx
  int *v11; // rdi
  __int64 v12; // rcx
  hkResult result; // [rsp+60h] [rbp+18h] BYREF

  this->m_sectionUid = uid;
  if ( graph )
    hkReferencedObject::addReference(graph);
  m_pntr = this->m_originalGraph.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_originalGraph.m_pntr = graph;
  m_size = graph->m_nodes.m_size;
  v7 = this->m_nodeMap.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < m_size )
  {
    v8 = 2 * v7;
    v9 = graph->m_nodes.m_size;
    if ( m_size < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_nodeMap, v9, 4);
  }
  v10 = m_size - this->m_nodeMap.m_size;
  v11 = &this->m_nodeMap.m_data[this->m_nodeMap.m_size];
  v12 = v10;
  if ( v10 > 0 )
  {
    while ( v12 )
    {
      *v11++ = -1;
      --v12;
    }
  }
  this->m_nodeMap.m_size = m_size;
  this->m_originalNodes = graph->m_nodes.m_data;
  this->m_numOriginalNodes = graph->m_nodes.m_size;
  this->m_originalEdges = graph->m_edges.m_data;
  this->m_numOriginalEdges = graph->m_edges.m_size;
  this->m_originalPositions = graph->m_positions.m_data;
  this->m_originalNodeData = graph->m_nodeData.m_data;
  this->m_nodeDataStriding = graph->m_nodeDataStriding;
  this->m_originalEdgeData = graph->m_edgeData.m_data;
  this->m_edgeDataStriding = graph->m_edgeDataStriding;
}

// File Line: 50
// RVA: 0xBE8300
void __fastcall hkaiDirectedGraphInstance::tempInit(
        hkaiDirectedGraphInstance *this,
        hkaiDirectedGraphExplicitCost *graph)
{
  hkaiDirectedGraphExplicitCost *m_pntr; // rcx

  this->m_runtimeId = 0;
  if ( graph )
    hkReferencedObject::addReference(graph);
  m_pntr = this->m_originalGraph.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_originalGraph.m_pntr = graph;
  if ( graph )
  {
    this->m_originalNodes = graph->m_nodes.m_data;
    this->m_numOriginalNodes = graph->m_nodes.m_size;
    this->m_originalEdges = graph->m_edges.m_data;
    this->m_numOriginalEdges = graph->m_edges.m_size;
    this->m_originalPositions = graph->m_positions.m_data;
    this->m_originalNodeData = graph->m_nodeData.m_data;
    this->m_nodeDataStriding = graph->m_nodeDataStriding;
    this->m_originalEdgeData = graph->m_edgeData.m_data;
    this->m_edgeDataStriding = graph->m_edgeDataStriding;
  }
}

// File Line: 63
// RVA: 0xBE8C10
int __fastcall hkaiDirectedGraphInstance::expandEdgesBy(hkaiDirectedGraphInstance *this, int n)
{
  int FreeBlock; // eax
  int m_size; // r15d
  int v6; // ebp
  int v7; // eax
  int v8; // eax
  int v9; // r9d
  int v10; // edx
  int *v11; // rdi
  __int64 v12; // rcx
  int v13; // r9d
  int v14; // eax
  int v15; // eax
  int v16; // esi
  int v17; // eax
  int v18; // eax
  int v19; // r9d
  int v20; // edx
  unsigned int *v21; // rdi
  __int64 v22; // rcx
  hkResult result; // [rsp+60h] [rbp+18h] BYREF

  FreeBlock = hkaiDirectedGraphInstance::findFreeBlock(this, n);
  if ( FreeBlock == -1 )
  {
    m_size = this->m_userEdgeCount.m_size;
    v6 = m_size + n;
    v7 = this->m_userEdgeCount.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v7 < m_size + n )
    {
      v8 = 2 * v7;
      v9 = m_size + n;
      if ( v6 < v8 )
        v9 = v8;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_userEdgeCount, v9, 4);
    }
    v10 = v6 - this->m_userEdgeCount.m_size;
    v11 = &this->m_userEdgeCount.m_data[this->m_userEdgeCount.m_size];
    v12 = v10;
    if ( v10 > 0 )
    {
      while ( v12 )
      {
        *v11++ = 0;
        --v12;
      }
    }
    this->m_userEdgeCount.m_size = v6;
    v13 = n + this->m_ownedEdges.m_size;
    v14 = this->m_ownedEdges.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v14 < v13 )
    {
      v15 = 2 * v14;
      if ( v13 < v15 )
        v13 = v15;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_ownedEdges, v13, 8);
    }
    this->m_ownedEdges.m_size += n;
    v16 = v6 * this->m_edgeDataStriding;
    v17 = this->m_ownedEdgeData.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v17 < v16 )
    {
      v18 = 2 * v17;
      v19 = v6 * this->m_edgeDataStriding;
      if ( v16 < v18 )
        v19 = v18;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_ownedEdgeData, v19, 4);
    }
    v20 = v16 - this->m_ownedEdgeData.m_size;
    v21 = &this->m_ownedEdgeData.m_data[this->m_ownedEdgeData.m_size];
    v22 = v20;
    if ( v20 > 0 )
    {
      while ( v22 )
      {
        *v21++ = 0;
        --v22;
      }
    }
    this->m_ownedEdgeData.m_size = v16;
    return m_size + this->m_numOriginalEdges;
  }
  return FreeBlock;
}

// File Line: 83
// RVA: 0xBE8390
__int64 __fastcall hkaiDirectedGraphInstance::getClosestNode(hkaiDirectedGraphInstance *this, hkVector4f *position)
{
  int m_numOriginalNodes; // r11d
  float v3; // xmm3_4
  int m_runtimeId; // r8d
  int v5; // r10d
  int v7; // eax
  hkVector4f v8; // xmm4
  hkVector4f v9; // xmm5
  hkVector4f v10; // xmm6
  hkVector4f v11; // xmm7
  hkVector4f *m_originalPositions; // rcx
  __m128 v13; // xmm2
  __m128 v14; // xmm2
  float v15; // xmm1_4

  m_numOriginalNodes = this->m_numOriginalNodes;
  v3 = 3.40282e38;
  m_runtimeId = 0;
  v5 = -1;
  v7 = 0;
  if ( m_numOriginalNodes <= 0 )
    return 0xFFFFFFFFi64;
  v8.m_quad = (__m128)this->m_transform.m_rotation.m_col1;
  v9.m_quad = (__m128)this->m_transform.m_rotation.m_col0;
  v10.m_quad = (__m128)this->m_transform.m_rotation.m_col2;
  v11.m_quad = (__m128)this->m_transform.m_translation;
  m_originalPositions = this->m_originalPositions;
  do
  {
    v13 = _mm_sub_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(m_originalPositions->m_quad, m_originalPositions->m_quad, 0), v9.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(m_originalPositions->m_quad, m_originalPositions->m_quad, 85), v8.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(m_originalPositions->m_quad, m_originalPositions->m_quad, 170), v10.m_quad)),
              v11.m_quad),
            position->m_quad);
    v14 = _mm_mul_ps(v13, v13);
    v15 = (float)(_mm_shuffle_ps(v14, v14, 85).m128_f32[0] + _mm_shuffle_ps(v14, v14, 0).m128_f32[0])
        + _mm_shuffle_ps(v14, v14, 170).m128_f32[0];
    if ( v15 < v3 )
    {
      v3 = v15;
      v5 = v7;
    }
    ++v7;
    ++m_originalPositions;
  }
  while ( v7 < m_numOriginalNodes );
  if ( v5 < 0 )
    return 0xFFFFFFFFi64;
  if ( this->m_runtimeId > 0 )
    m_runtimeId = this->m_runtimeId;
  return v5 | (unsigned int)(m_runtimeId << 22);
}

// File Line: 115
// RVA: 0xBE8870
hkaiDirectedGraphExplicitCost::Edge *__fastcall hkaiDirectedGraphInstance::addEdgeForNode(
        hkaiDirectedGraphInstance *this,
        int n,
        unsigned int **edgeDataPtrOut)
{
  int *m_data; // rax
  int m_numOriginalEdges; // r13d
  int m_size; // esi
  __int64 v8; // rdx
  hkaiDirectedGraphExplicitCost::Node *v9; // r8
  hkaiDirectedGraphExplicitCost::Node *v10; // rdi
  int v11; // eax
  int v12; // r9d
  int v13; // ebp
  hkaiDirectedGraphExplicitCost::Edge *v14; // r12
  int *v15; // rcx
  int *v16; // r15
  int *v17; // rsi
  unsigned int *p_m_target; // r11
  int v19; // eax
  int v20; // ecx
  hkaiDirectedGraphExplicitCost::Edge *m_originalEdges; // rax
  hkaiDirectedGraphExplicitCost::Edge *v22; // rdx
  __int64 m_edgeDataStriding; // r10
  unsigned int *v24; // rcx
  char *v25; // r8
  char *v26; // rax
  __int64 v27; // rdx
  signed __int64 v28; // r8
  int v29; // ecx
  int v30; // ecx
  __int64 m_numEdges; // r8
  hkaiDirectedGraphExplicitCost::Edge *v32; // rsi
  int v34; // [rsp+58h] [rbp+10h]

  m_data = this->m_nodeMap.m_data;
  m_numOriginalEdges = this->m_numOriginalEdges;
  m_size = m_data[n];
  if ( m_size == -1 )
  {
    m_size = this->m_instancedNodes.m_size;
    m_data[n] = m_size;
    if ( this->m_instancedNodes.m_size == (this->m_instancedNodes.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->m_instancedNodes, 8);
    v8 = this->m_instancedNodes.m_size;
    v9 = &this->m_instancedNodes.m_data[v8];
    this->m_instancedNodes.m_size = v8 + 1;
    v9->m_numEdges = 0;
    v9->m_startEdgeIndex = -1;
  }
  v10 = &this->m_instancedNodes.m_data[m_size];
  v11 = hkaiDirectedGraphInstance::expandEdgesBy(this, v10->m_numEdges + 1);
  v12 = 0;
  v34 = v11;
  v13 = v11 - this->m_numOriginalEdges;
  v14 = &this->m_ownedEdges.m_data[v13];
  v15 = this->m_userEdgeCount.m_data;
  v16 = &v15[v13];
  if ( v10->m_numEdges > 0 )
  {
    v17 = &v15[v13];
    p_m_target = &v14->m_target;
    do
    {
      v19 = this->m_numOriginalEdges;
      v20 = v12 + v10->m_startEdgeIndex;
      if ( v20 >= v19 )
      {
        v20 -= v19;
        m_originalEdges = this->m_ownedEdges.m_data;
      }
      else
      {
        m_originalEdges = this->m_originalEdges;
      }
      v22 = &m_originalEdges[v20];
      *((_WORD *)p_m_target - 2) = v22->m_cost.m_value;
      *((_WORD *)p_m_target - 1) = v22->m_flags.m_storage;
      *p_m_target = v22->m_target;
      LODWORD(v22) = v12 + v10->m_startEdgeIndex - m_numOriginalEdges;
      *v17 = this->m_userEdgeCount.m_data[(int)v22];
      m_edgeDataStriding = this->m_edgeDataStriding;
      v24 = this->m_ownedEdgeData.m_data;
      v25 = (char *)&v24[(int)v22 * this->m_edgeDataStriding];
      v26 = (char *)&v24[(int)m_edgeDataStriding * (v12 + v13)];
      if ( (_DWORD)m_edgeDataStriding == 1 )
      {
        *(_DWORD *)v26 = *(_DWORD *)v25;
      }
      else
      {
        v27 = this->m_edgeDataStriding;
        if ( m_edgeDataStriding >= 1 )
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
      p_m_target += 2;
      ++v17;
    }
    while ( v12 < v10->m_numEdges );
  }
  if ( edgeDataPtrOut )
  {
    v30 = this->m_edgeDataStriding;
    if ( v30 )
      *edgeDataPtrOut = &this->m_ownedEdgeData.m_data[v30 * (v13 + v10->m_numEdges)];
    else
      *edgeDataPtrOut = 0i64;
  }
  m_numEdges = v10->m_numEdges;
  v32 = &v14[m_numEdges];
  if ( (_DWORD)m_numEdges )
    hkaiDirectedGraphInstance::addFreeBlock(this, v10->m_startEdgeIndex, m_numEdges);
  v16[v10->m_numEdges++] = 0;
  v10->m_startEdgeIndex = v34;
  return v32;
}

// File Line: 171
// RVA: 0xBE8A90
void __fastcall hkaiDirectedGraphInstance::removeOwnedEdgeForNode(hkaiDirectedGraphInstance *this, int n, int e)
{
  int *m_data; // rax
  int m_size; // esi
  __int64 v7; // rdx
  hkaiDirectedGraphExplicitCost::Node *v8; // r8
  hkaiDirectedGraphExplicitCost::Node *v9; // rax
  int v10; // ebp
  int m_startEdgeIndex; // edx
  hkaiDirectedGraphExplicitCost::Node *v12; // rdi
  int v13; // esi
  int v14; // edx
  int v15; // esi
  hkaiDirectedGraphExplicitCost::Edge *v16; // rax
  hkaiDirectedGraphExplicitCost::Edge *v17; // rcx
  hkaiDirectedGraphExplicitCost::Edge *v18; // rdx
  __int64 m_edgeDataStriding; // rdx
  unsigned int *v20; // rcx
  char *v21; // r8
  char *v22; // rax
  signed __int64 v23; // r8
  int v24; // ecx

  m_data = this->m_nodeMap.m_data;
  m_size = m_data[n];
  if ( m_size == -1 )
  {
    m_size = this->m_instancedNodes.m_size;
    m_data[n] = m_size;
    if ( this->m_instancedNodes.m_size == (this->m_instancedNodes.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->m_instancedNodes, 8);
    v7 = this->m_instancedNodes.m_size;
    v8 = &this->m_instancedNodes.m_data[v7];
    this->m_instancedNodes.m_size = v7 + 1;
    v8->m_numEdges = 0;
    v8->m_startEdgeIndex = -1;
  }
  v9 = this->m_instancedNodes.m_data;
  v10 = e - this->m_numOriginalEdges;
  m_startEdgeIndex = v9[m_size].m_startEdgeIndex;
  v12 = &v9[m_size];
  v13 = v12->m_numEdges - 1;
  LODWORD(v9) = m_startEdgeIndex - this->m_numOriginalEdges;
  v14 = v13 + m_startEdgeIndex;
  v15 = (_DWORD)v9 + v13;
  hkaiDirectedGraphInstance::addFreeBlock(this, v14, 1);
  if ( v12->m_numEdges == 1 )
  {
    v12->m_numEdges = 0;
    v12->m_startEdgeIndex = -1;
    this->m_userEdgeCount.m_data[v10] = 0;
  }
  else
  {
    v16 = this->m_ownedEdges.m_data;
    v17 = &v16[v10];
    v18 = &v16[v15];
    v17->m_cost.m_value = v18->m_cost.m_value;
    v17->m_flags.m_storage = v18->m_flags.m_storage;
    v17->m_target = v18->m_target;
    this->m_userEdgeCount.m_data[v10] = this->m_userEdgeCount.m_data[v15];
    m_edgeDataStriding = this->m_edgeDataStriding;
    v20 = this->m_ownedEdgeData.m_data;
    v21 = (char *)&v20[v15 * this->m_edgeDataStriding];
    v22 = (char *)&v20[v10 * this->m_edgeDataStriding];
    if ( (_DWORD)m_edgeDataStriding == 1 )
    {
      *(_DWORD *)v22 = *(_DWORD *)v21;
    }
    else if ( m_edgeDataStriding >= 1 )
    {
      v23 = v21 - v22;
      do
      {
        v24 = *(_DWORD *)&v22[v23];
        v22 += 4;
        *((_DWORD *)v22 - 1) = v24;
        --m_edgeDataStriding;
      }
      while ( m_edgeDataStriding );
    }
    --v12->m_numEdges;
  }
}

// File Line: 200
// RVA: 0xBE8E50
void __fastcall hkaiDirectedGraphInstance::addFreeBlock(hkaiDirectedGraphInstance *this, int blockStart, int blockSize)
{
  int v3; // r15d
  hkArray<hkaiDirectedGraphInstance::FreeBlockList,hkContainerHeapAllocator> *p_m_freeEdgeBlocks; // rbp
  int v8; // eax
  int v9; // eax
  int v10; // r9d
  int v11; // eax
  __int64 v12; // rdi
  int *v13; // rbx
  int v14; // r8d
  __int64 m_size; // rax
  int v16; // ecx
  __int64 v17; // rax
  __int64 v18; // rdx
  hkaiDirectedGraphInstance::FreeBlockList *v19; // rbx
  hkResult v20; // [rsp+68h] [rbp+10h] BYREF

  v3 = blockSize - 1;
  if ( this->m_freeEdgeBlocks.m_size < blockSize )
  {
    p_m_freeEdgeBlocks = &this->m_freeEdgeBlocks;
    v8 = this->m_freeEdgeBlocks.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v8 < blockSize )
    {
      v9 = 2 * v8;
      v10 = blockSize;
      if ( blockSize < v9 )
        v10 = v9;
      hkArrayUtil::_reserve(&v20, &hkContainerHeapAllocator::s_alloc, p_m_freeEdgeBlocks, v10, 16);
    }
    v11 = p_m_freeEdgeBlocks->m_size - blockSize - 1;
    v12 = v11;
    if ( v11 >= 0 )
    {
      v13 = &p_m_freeEdgeBlocks->m_data[blockSize].m_blocks.m_capacityAndFlags + 4 * v11;
      do
      {
        v14 = *v13;
        *(v13 - 1) = 0;
        if ( v14 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            *(void **)(v13 - 3),
            4 * v14);
        *(_QWORD *)(v13 - 3) = 0i64;
        *v13 = 0x80000000;
        v13 -= 4;
        --v12;
      }
      while ( v12 >= 0 );
    }
    m_size = p_m_freeEdgeBlocks->m_size;
    v16 = blockSize - m_size;
    v17 = (__int64)&p_m_freeEdgeBlocks->m_data[m_size];
    v18 = v16;
    if ( v16 > 0 )
    {
      do
      {
        if ( v17 )
        {
          *(_QWORD *)v17 = 0i64;
          *(_DWORD *)(v17 + 8) = 0;
          *(_DWORD *)(v17 + 12) = 0x80000000;
        }
        v17 += 16i64;
        --v18;
      }
      while ( v18 );
    }
    p_m_freeEdgeBlocks->m_size = blockSize;
  }
  v19 = &this->m_freeEdgeBlocks.m_data[v3];
  if ( v19->m_blocks.m_size == (v19->m_blocks.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v19, 4);
  v19->m_blocks.m_data[v19->m_blocks.m_size++] = blockStart;
}

// File Line: 213
// RVA: 0xBE8FE0
__int64 __fastcall hkaiDirectedGraphInstance::findFreeBlock(hkaiDirectedGraphInstance *this, int blockSize)
{
  __int64 m_size; // r9
  int v3; // r10d
  __int64 v7; // rcx
  int v8; // r8d
  hkaiDirectedGraphInstance::FreeBlockList *m_data; // rdi
  int *i; // rdx
  hkaiDirectedGraphInstance::FreeBlockList *v11; // rdx
  unsigned int v12; // edi
  int v13; // r8d
  int v14; // esi
  hkaiDirectedGraphInstance::FreeBlockList *v15; // rbx

  m_size = this->m_freeEdgeBlocks.m_size;
  v3 = blockSize - 1;
  if ( (int)m_size < blockSize )
    return 0xFFFFFFFFi64;
  v7 = v3;
  v8 = blockSize - 1;
  if ( v3 >= m_size )
    return 0xFFFFFFFFi64;
  m_data = this->m_freeEdgeBlocks.m_data;
  for ( i = &m_data->m_blocks.m_size + 4 * v3; *i <= 0; i += 4 )
  {
    ++v7;
    ++v8;
    if ( v7 >= m_size )
      return 0xFFFFFFFFi64;
  }
  v11 = &m_data[v8];
  v12 = v11->m_blocks.m_data[--v11->m_blocks.m_size];
  v13 = v8 - v3;
  if ( v13 )
  {
    v14 = v12 + blockSize;
    v15 = &this->m_freeEdgeBlocks.m_data[v13 - 1];
    if ( v15->m_blocks.m_size == (v15->m_blocks.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v15, 4);
    v15->m_blocks.m_data[v15->m_blocks.m_size++] = v14;
  }
  return v12;
}

// File Line: 248
// RVA: 0xBE8490
void __fastcall hkaiDirectedGraphInstance::validate(hkaiDirectedGraphInstance *this)
{
  int v2; // r14d
  int v3; // ebx
  hkLifoAllocator *Value; // rax
  unsigned int *m_cur; // rcx
  int v6; // edx
  char *v7; // rdi
  int v8; // r9d
  unsigned int *m_data; // rdi
  __int64 i; // rcx
  hkLifoAllocator *v11; // rcx
  unsigned int *v12; // rax
  int v13; // edx
  char *v14; // rdi
  int v15; // esi
  int v16; // r9d
  unsigned int *v17; // rdi
  __int64 j; // rcx
  int v19; // r10d
  __int64 v20; // r11
  __int64 v21; // rbx
  hkaiDirectedGraphExplicitCost::Node *v22; // r9
  int k; // r8d
  unsigned int *v24; // rdi
  char v25; // cl
  __int64 v26; // rcx
  hkaiDirectedGraphExplicitCost::Node v27; // rax
  int m_startEdgeIndex; // ecx
  int v29; // edx
  __int64 v30; // rdi
  __int64 m_numEdges; // r8
  __int64 v32; // rcx
  int v33; // ebx
  __int64 v34; // rsi
  hkaiDirectedGraphInstance::FreeBlockList *v35; // r11
  int v36; // r9d
  __int64 v37; // r10
  int v38; // ecx
  int v39; // eax
  __int64 v40; // rdi
  __int64 v41; // r8
  __int64 v42; // rdx
  hkBitFieldStorage<hkLocalArray<unsigned int> > array; // [rsp+30h] [rbp-50h] BYREF
  hkBitFieldStorage<hkLocalArray<unsigned int> > v44; // [rsp+58h] [rbp-28h] BYREF
  hkaiDirectedGraphExplicitCost::Node result; // [rsp+B0h] [rbp+30h] BYREF

  hkaiDirectedGraphExplicitCost::validate(this->m_originalGraph.m_pntr);
  v2 = this->m_numOriginalEdges + this->m_ownedEdges.m_size;
  array.m_words.m_data = 0i64;
  array.m_words.m_size = 0;
  array.m_words.m_capacityAndFlags = 0x80000000;
  v3 = (v2 + 31) >> 5;
  array.m_words.m_initialCapacity = v3;
  if ( v3 )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (unsigned int *)Value->m_cur;
    v6 = (4 * v3 + 127) & 0xFFFFFF80;
    v7 = (char *)m_cur + v6;
    if ( v6 > Value->m_slabSize || v7 > Value->m_end )
      m_cur = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(Value, v6);
    else
      Value->m_cur = v7;
  }
  else
  {
    m_cur = 0i64;
  }
  array.m_words.m_data = m_cur;
  array.m_words.m_localMemory = m_cur;
  array.m_numBits = v2;
  array.m_words.m_capacityAndFlags = v3 | 0x80000000;
  if ( (v3 & 0x3FFFFFFF) < v3 )
  {
    v8 = (v2 + 31) >> 5;
    if ( v3 < 2 * (v3 & 0x3FFFFFFF) )
      v8 = 2 * (v3 & 0x3FFFFFFF);
    hkArrayUtil::_reserve((hkResult *)&result, &hkContainerHeapAllocator::s_alloc, &array, v8, 4);
  }
  array.m_words.m_size = (v2 + 31) >> 5;
  if ( v3 - 1 >= 0 )
  {
    m_data = array.m_words.m_data;
    for ( i = (unsigned int)v3; i; --i )
      *m_data++ = 0;
  }
  v44.m_words.m_data = 0i64;
  v44.m_words.m_size = 0;
  v44.m_words.m_capacityAndFlags = 0x80000000;
  v44.m_words.m_initialCapacity = (v2 + 31) >> 5;
  if ( v3 )
  {
    v11 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v12 = (unsigned int *)v11->m_cur;
    v13 = (4 * v3 + 127) & 0xFFFFFF80;
    v14 = (char *)v12 + v13;
    if ( v13 > v11->m_slabSize || v14 > v11->m_end )
      v12 = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(v11, v13);
    else
      v11->m_cur = v14;
  }
  else
  {
    v12 = 0i64;
  }
  v44.m_words.m_capacityAndFlags = v3 | 0x80000000;
  v15 = v3 & 0x3FFFFFFF;
  v44.m_numBits = v2;
  v44.m_words.m_data = v12;
  v44.m_words.m_localMemory = v12;
  if ( (v3 & 0x3FFFFFFF) < v3 )
  {
    v16 = (v2 + 31) >> 5;
    if ( v3 < 2 * v15 )
      v16 = 2 * v15;
    hkArrayUtil::_reserve((hkResult *)&result, &hkContainerHeapAllocator::s_alloc, &v44, v16, 4);
  }
  v44.m_words.m_size = (v2 + 31) >> 5;
  if ( v3 - 1 >= 0 )
  {
    v17 = v44.m_words.m_data;
    for ( j = (unsigned int)v3; j; --j )
      *v17++ = 0;
  }
  v19 = 0;
  if ( this->m_numOriginalNodes > 0 )
  {
    v20 = 0i64;
    v21 = 0i64;
    do
    {
      v22 = &this->m_originalNodes[v21];
      for ( k = v22->m_startEdgeIndex; k < v22->m_numEdges + v22->m_startEdgeIndex; *v24 |= 1 << (v25 & 0x1F) )
      {
        v24 = &array.m_words.m_data[(__int64)k >> 5];
        v25 = k++;
      }
      if ( !this->m_nodeMap.m_size || (v26 = this->m_nodeMap.m_data[v20], (_DWORD)v26 == -1) )
      {
        m_startEdgeIndex = -1;
        result = (hkaiDirectedGraphExplicitCost::Node)0xFFFFFFFFi64;
        v27.m_numEdges = 0;
      }
      else
      {
        v27 = this->m_instancedNodes.m_data[v26];
        result = v27;
        m_startEdgeIndex = v27.m_startEdgeIndex;
      }
      v29 = __ROL4__(1, m_startEdgeIndex);
      if ( m_startEdgeIndex < m_startEdgeIndex + v27.m_numEdges )
      {
        v30 = m_startEdgeIndex;
        m_numEdges = (unsigned int)v27.m_numEdges;
        do
        {
          v32 = v30++;
          array.m_words.m_data[v32 >> 5] |= v29;
          v29 = __ROL4__(v29, 1);
          --m_numEdges;
        }
        while ( m_numEdges );
      }
      ++v19;
      ++v21;
      ++v20;
    }
    while ( v19 < this->m_numOriginalNodes );
  }
  v33 = 0;
  if ( this->m_freeEdgeBlocks.m_size > 0 )
  {
    v34 = 0i64;
    do
    {
      v35 = this->m_freeEdgeBlocks.m_data;
      v36 = 0;
      if ( v35[v34].m_blocks.m_size > 0 )
      {
        v37 = 0i64;
        do
        {
          v38 = v35[v34].m_blocks.m_data[v37];
          v39 = __ROL4__(1, v38);
          if ( v38 < v38 + v33 + 1 )
          {
            v40 = v35[v34].m_blocks.m_data[v37];
            v41 = (unsigned int)(v33 + 1);
            do
            {
              v42 = v40++;
              v44.m_words.m_data[v42 >> 5] |= v39;
              v39 = __ROL4__(v39, 1);
              --v41;
            }
            while ( v41 );
          }
          ++v36;
          ++v37;
        }
        while ( v36 < v35[v34].m_blocks.m_size );
      }
      ++v33;
      ++v34;
    }
    while ( v33 < this->m_freeEdgeBlocks.m_size );
  }
  hkBitFieldStorage<hkLocalArray<unsigned int>>::~hkBitFieldStorage<hkLocalArray<unsigned int>>(&v44);
  hkBitFieldStorage<hkLocalArray<unsigned int>>::~hkBitFieldStorage<hkLocalArray<unsigned int>>(&array);
}

// File Line: 316
// RVA: 0xBE8D90
void __fastcall hkaiDirectedGraphInstance::clearOwnedEdges(hkaiDirectedGraphInstance *this)
{
  int m_size; // eax
  hkaiDirectedGraphInstance::FreeBlockList *m_data; // rcx
  int v4; // eax
  __int64 v5; // rdi
  int *v6; // rbx
  int v7; // r8d

  this->m_ownedEdges.m_size = 0;
  this->m_ownedEdgeData.m_size = 0;
  m_size = this->m_freeEdgeBlocks.m_size;
  m_data = this->m_freeEdgeBlocks.m_data;
  v4 = m_size - 1;
  v5 = v4;
  if ( v4 >= 0 )
  {
    v6 = &m_data->m_blocks.m_capacityAndFlags + 4 * v4;
    do
    {
      v7 = *v6;
      *(v6 - 1) = 0;
      if ( v7 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, *(void **)(v6 - 3), 4 * v7);
      *(_QWORD *)(v6 - 3) = 0i64;
      *v6 = 0x80000000;
      v6 -= 4;
      --v5;
    }
    while ( v5 >= 0 );
  }
  this->m_freeEdgeBlocks.m_size = 0;
  this->m_userEdgeCount.m_size = 0;
}

// File Line: 324
// RVA: 0xBE87E0
void __fastcall hkaiDirectedGraphInstance::updateInternalPointers(hkaiDirectedGraphInstance *this)
{
  hkaiDirectedGraphExplicitCost *m_pntr; // rdx
  hkArray<unsigned int,hkContainerHeapAllocator> *m_edgeDataStriding; // r8
  int v3; // r9d
  hkaiUserDataUtils v4; // [rsp+40h] [rbp+8h] BYREF

  m_pntr = this->m_originalGraph.m_pntr;
  m_edgeDataStriding = (hkArray<unsigned int,hkContainerHeapAllocator> *)(unsigned int)this->m_edgeDataStriding;
  this->m_originalNodes = m_pntr->m_nodes.m_data;
  this->m_numOriginalNodes = m_pntr->m_nodes.m_size;
  this->m_originalEdges = m_pntr->m_edges.m_data;
  this->m_numOriginalEdges = m_pntr->m_edges.m_size;
  this->m_originalPositions = m_pntr->m_positions.m_data;
  this->m_originalNodeData = m_pntr->m_nodeData.m_data;
  this->m_nodeDataStriding = m_pntr->m_nodeDataStriding;
  this->m_originalEdgeData = m_pntr->m_edgeData.m_data;
  v3 = m_pntr->m_edgeDataStriding;
  this->m_edgeDataStriding = v3;
  if ( (_DWORD)m_edgeDataStriding != v3 )
    hkaiUserDataUtils::restride<unsigned int>(
      &v4,
      (hkResult *)&this->m_ownedEdgeData,
      m_edgeDataStriding,
      v3,
      this->m_ownedEdges.m_size,
      0);
}

