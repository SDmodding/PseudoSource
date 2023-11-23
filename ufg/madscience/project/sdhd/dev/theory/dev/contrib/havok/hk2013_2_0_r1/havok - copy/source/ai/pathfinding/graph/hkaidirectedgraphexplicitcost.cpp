// File Line: 21
// RVA: 0xBE7150
void __fastcall hkaiDirectedGraphExplicitCost::hkaiDirectedGraphExplicitCost(hkaiDirectedGraphExplicitCost *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiDirectedGraphExplicitCost::`vftable;
  this->m_positions.m_capacityAndFlags = 0x80000000;
  this->m_positions.m_data = 0i64;
  this->m_positions.m_size = 0;
  this->m_nodes.m_data = 0i64;
  this->m_nodes.m_size = 0;
  this->m_nodes.m_capacityAndFlags = 0x80000000;
  this->m_edges.m_data = 0i64;
  this->m_edges.m_size = 0;
  this->m_edges.m_capacityAndFlags = 0x80000000;
  this->m_nodeData.m_data = 0i64;
  this->m_nodeData.m_size = 0;
  this->m_nodeData.m_capacityAndFlags = 0x80000000;
  this->m_edgeData.m_data = 0i64;
  this->m_edgeData.m_size = 0;
  this->m_edgeData.m_capacityAndFlags = 0x80000000;
  *(_QWORD *)&this->m_nodeDataStriding = 0i64;
  this->m_streamingSets.m_data = 0i64;
  this->m_streamingSets.m_size = 0;
  this->m_streamingSets.m_capacityAndFlags = 0x80000000;
}

// File Line: 32
// RVA: 0xBE71D0
void __fastcall hkaiDirectedGraphExplicitCost::hkaiDirectedGraphExplicitCost(
        hkaiDirectedGraphExplicitCost *this,
        hkFinishLoadedObjectFlag f)
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
hkResult *__fastcall hkaiDirectedGraphExplicitCost::copy(
        hkaiDirectedGraphExplicitCost *this,
        hkResult *result,
        hkaiDirectedGraphExplicitCost *other)
{
  int m_size; // r9d
  __int64 v7; // rax
  hkaiDirectedGraphExplicitCost::Node *m_data; // rcx
  __int64 v9; // rdx
  char *v10; // r8
  hkaiDirectedGraphExplicitCost::Node v11; // rax
  int v12; // r9d
  __int64 v13; // rax
  hkaiDirectedGraphExplicitCost::Edge *v14; // r9
  __int64 v15; // rdx
  hkFlags<enum hkaiDirectedGraphExplicitCost::EdgeBits,unsigned short> *p_m_flags; // rcx
  char *v17; // r8
  unsigned __int16 v18; // ax
  int v19; // r9d
  __int64 v20; // rax
  hkVector4f *v21; // rcx
  __int64 v22; // rdx
  char *v23; // r8
  hkVector4f v24; // xmm0
  hkResultEnum m_enum; // ebx
  hkResultEnum v26; // edi
  int v27; // r9d
  __int64 v28; // rax
  unsigned int *v29; // rcx
  __int64 v30; // rdx
  char *v31; // r8
  unsigned int v32; // eax
  int v33; // r9d
  __int64 v34; // rax
  unsigned int *v35; // rcx
  __int64 v36; // rdx
  char *v37; // r8
  unsigned int v38; // eax
  hkResult v40; // [rsp+30h] [rbp-10h] BYREF
  int v41; // [rsp+34h] [rbp-Ch] BYREF
  hkResult v42; // [rsp+38h] [rbp-8h] BYREF
  hkResult v43; // [rsp+80h] [rbp+40h] BYREF
  hkResult resulta; // [rsp+90h] [rbp+50h] BYREF
  hkResult v45; // [rsp+98h] [rbp+58h] BYREF

  this->m_nodeDataStriding = other->m_nodeDataStriding;
  this->m_edgeDataStriding = other->m_edgeDataStriding;
  m_size = other->m_nodes.m_size;
  if ( (this->m_nodes.m_capacityAndFlags & 0x3FFFFFFF) >= m_size )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &this->m_nodes, m_size, 8);
    if ( resulta.m_enum )
      goto LABEL_12;
  }
  if ( (this->m_nodes.m_capacityAndFlags & 0x3FFFFFFF) < other->m_nodes.m_size )
  {
    if ( this->m_nodes.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_nodes.m_data,
        8 * this->m_nodes.m_capacityAndFlags);
    v43.m_enum = 8 * other->m_nodes.m_size;
    this->m_nodes.m_data = (hkaiDirectedGraphExplicitCost::Node *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                                    &hkContainerHeapAllocator::s_alloc,
                                                                    &v43);
    this->m_nodes.m_capacityAndFlags = v43.m_enum / 8;
  }
  v7 = other->m_nodes.m_size;
  m_data = this->m_nodes.m_data;
  this->m_nodes.m_size = v7;
  v9 = v7;
  if ( (int)v7 > 0 )
  {
    v10 = (char *)((char *)other->m_nodes.m_data - (char *)m_data);
    do
    {
      v11 = *(hkaiDirectedGraphExplicitCost::Node *)((char *)m_data++ + (_QWORD)v10);
      m_data[-1] = v11;
      --v9;
    }
    while ( v9 );
  }
LABEL_12:
  v12 = other->m_edges.m_size;
  if ( (this->m_edges.m_capacityAndFlags & 0x3FFFFFFF) >= v12 )
  {
    v45.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&v45, &hkContainerHeapAllocator::s_alloc, &this->m_edges, v12, 8);
    if ( v45.m_enum )
      goto LABEL_23;
  }
  if ( (this->m_edges.m_capacityAndFlags & 0x3FFFFFFF) < other->m_edges.m_size )
  {
    if ( this->m_edges.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_edges.m_data,
        8 * this->m_edges.m_capacityAndFlags);
    v43.m_enum = 8 * other->m_edges.m_size;
    this->m_edges.m_data = (hkaiDirectedGraphExplicitCost::Edge *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                                    &hkContainerHeapAllocator::s_alloc,
                                                                    &v43);
    this->m_edges.m_capacityAndFlags = v43.m_enum / 8;
  }
  v13 = other->m_edges.m_size;
  v14 = this->m_edges.m_data;
  this->m_edges.m_size = v13;
  v15 = v13;
  if ( (int)v13 > 0 )
  {
    p_m_flags = &v14->m_flags;
    v17 = (char *)((char *)other->m_edges.m_data - (char *)v14);
    do
    {
      v18 = *(unsigned __int16 *)((char *)&p_m_flags[-1].m_storage + (_QWORD)v17);
      p_m_flags += 4;
      p_m_flags[-5].m_storage = v18;
      p_m_flags[-4].m_storage = *(unsigned __int16 *)((char *)p_m_flags + (_QWORD)v17 - 8);
      *(_DWORD *)&p_m_flags[-3].m_storage = *(_DWORD *)((char *)&p_m_flags[-3].m_storage + (_QWORD)v17);
      --v15;
    }
    while ( v15 );
  }
LABEL_23:
  v19 = other->m_positions.m_size;
  if ( (this->m_positions.m_capacityAndFlags & 0x3FFFFFFF) >= v19 )
  {
    v40.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&v40, &hkContainerHeapAllocator::s_alloc, &this->m_positions, v19, 16);
    if ( v40.m_enum )
      goto LABEL_34;
  }
  if ( (this->m_positions.m_capacityAndFlags & 0x3FFFFFFF) < other->m_positions.m_size )
  {
    if ( this->m_positions.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_positions.m_data,
        16 * this->m_positions.m_capacityAndFlags);
    v43.m_enum = 16 * other->m_positions.m_size;
    this->m_positions.m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                               &hkContainerHeapAllocator::s_alloc,
                                               &v43);
    this->m_positions.m_capacityAndFlags = v43.m_enum / 16;
  }
  v20 = other->m_positions.m_size;
  v21 = this->m_positions.m_data;
  this->m_positions.m_size = v20;
  v22 = v20;
  if ( (int)v20 > 0 )
  {
    v23 = (char *)((char *)other->m_positions.m_data - (char *)v21);
    do
    {
      v24.m_quad = *(__m128 *)((char *)v21++ + (_QWORD)v23);
      v21[-1] = (hkVector4f)v24.m_quad;
      --v22;
    }
    while ( v22 );
  }
LABEL_34:
  m_enum = HK_SUCCESS;
  v26 = HK_SUCCESS;
  if ( !this->m_nodeDataStriding )
    goto LABEL_47;
  v27 = other->m_nodeData.m_size;
  if ( (this->m_nodeData.m_capacityAndFlags & 0x3FFFFFFF) >= v27 )
  {
    v43.m_enum = HK_SUCCESS;
LABEL_39:
    if ( (this->m_nodeData.m_capacityAndFlags & 0x3FFFFFFF) < other->m_nodeData.m_size )
    {
      if ( this->m_nodeData.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          this->m_nodeData.m_data,
          4 * this->m_nodeData.m_capacityAndFlags);
      v41 = 4 * other->m_nodeData.m_size;
      this->m_nodeData.m_data = (unsigned int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                  &hkContainerHeapAllocator::s_alloc,
                                                  &v41);
      this->m_nodeData.m_capacityAndFlags = v41 / 4;
    }
    v28 = other->m_nodeData.m_size;
    v29 = this->m_nodeData.m_data;
    this->m_nodeData.m_size = v28;
    v30 = v28;
    if ( (int)v28 > 0 )
    {
      v31 = (char *)((char *)other->m_nodeData.m_data - (char *)v29);
      do
      {
        v32 = *(unsigned int *)((char *)v29++ + (_QWORD)v31);
        *(v29 - 1) = v32;
        --v30;
      }
      while ( v30 );
    }
    goto LABEL_46;
  }
  hkArrayUtil::_reserve(&v43, &hkContainerHeapAllocator::s_alloc, &this->m_nodeData, v27, 4);
  if ( v43.m_enum == HK_SUCCESS )
    goto LABEL_39;
LABEL_46:
  m_enum = v43.m_enum;
LABEL_47:
  if ( this->m_edgeDataStriding )
  {
    v33 = other->m_edgeData.m_size;
    if ( (this->m_edgeData.m_capacityAndFlags & 0x3FFFFFFF) >= v33 )
    {
      v43.m_enum = HK_SUCCESS;
    }
    else
    {
      hkArrayUtil::_reserve(&v43, &hkContainerHeapAllocator::s_alloc, &this->m_edgeData, v33, 4);
      if ( v43.m_enum )
      {
LABEL_59:
        v26 = v43.m_enum;
        goto LABEL_60;
      }
    }
    if ( (this->m_edgeData.m_capacityAndFlags & 0x3FFFFFFF) < other->m_edgeData.m_size )
    {
      if ( this->m_edgeData.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          this->m_edgeData.m_data,
          4 * this->m_edgeData.m_capacityAndFlags);
      v41 = 4 * other->m_edgeData.m_size;
      this->m_edgeData.m_data = (unsigned int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                  &hkContainerHeapAllocator::s_alloc,
                                                  &v41);
      this->m_edgeData.m_capacityAndFlags = v41 / 4;
    }
    v34 = other->m_edgeData.m_size;
    v35 = this->m_edgeData.m_data;
    this->m_edgeData.m_size = v34;
    v36 = v34;
    if ( (int)v34 > 0 )
    {
      v37 = (char *)((char *)other->m_edgeData.m_data - (char *)v35);
      do
      {
        v38 = *(unsigned int *)((char *)v35++ + (_QWORD)v37);
        *(v35 - 1) = v38;
        --v36;
      }
      while ( v36 );
    }
    goto LABEL_59;
  }
LABEL_60:
  hkaiStreamingSet::_copy(&v42, &this->m_streamingSets, &other->m_streamingSets);
  result->m_enum = resulta.m_enum || v45.m_enum || v40.m_enum || m_enum || v26 || v42.m_enum;
  return result;
}

// File Line: 113
// RVA: 0xBE76D0
void __fastcall hkaiDirectedGraphExplicitCost::swap(
        hkaiDirectedGraphExplicitCost *this,
        hkaiDirectedGraphExplicitCost *other)
{
  int m_nodeDataStriding; // ecx
  int m_edgeDataStriding; // ecx

  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&this->m_nodes,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&other->m_nodes);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&this->m_edges,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&other->m_edges);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&this->m_positions,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&other->m_positions);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&this->m_streamingSets,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&other->m_streamingSets);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&this->m_nodeData,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&other->m_nodeData);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&this->m_edgeData,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&other->m_edgeData);
  m_nodeDataStriding = this->m_nodeDataStriding;
  this->m_nodeDataStriding = other->m_nodeDataStriding;
  other->m_nodeDataStriding = m_nodeDataStriding;
  m_edgeDataStriding = this->m_edgeDataStriding;
  this->m_edgeDataStriding = other->m_edgeDataStriding;
  other->m_edgeDataStriding = m_edgeDataStriding;
}

// File Line: 125
// RVA: 0xBE7770
hkaiUserDataUtils *__fastcall hkaiDirectedGraphExplicitCost::setNodeDataStriding(
        hkaiDirectedGraphExplicitCost *this,
        hkaiUserDataUtils *result,
        int newStride,
        int fillValue)
{
  int m_size; // eax
  hkArray<unsigned int,hkContainerHeapAllocator> *m_nodeDataStriding; // r8
  int v9; // [rsp+30h] [rbp-8h]

  m_size = this->m_nodes.m_size;
  m_nodeDataStriding = (hkArray<unsigned int,hkContainerHeapAllocator> *)(unsigned int)this->m_nodeDataStriding;
  this->m_nodeDataStriding = newStride;
  hkaiUserDataUtils::restride<unsigned int>(
    result,
    (hkResult *)&this->m_nodeData,
    m_nodeDataStriding,
    newStride,
    m_size,
    fillValue,
    v9);
  return result;
}

// File Line: 132
// RVA: 0xBE77B0
hkaiUserDataUtils *__fastcall hkaiDirectedGraphExplicitCost::setEdgeDataStriding(
        hkaiDirectedGraphExplicitCost *this,
        hkaiUserDataUtils *result,
        int newStride,
        int fillValue)
{
  int m_size; // eax
  hkArray<unsigned int,hkContainerHeapAllocator> *m_edgeDataStriding; // r8
  int v9; // [rsp+30h] [rbp-8h]

  m_size = this->m_edges.m_size;
  m_edgeDataStriding = (hkArray<unsigned int,hkContainerHeapAllocator> *)(unsigned int)this->m_edgeDataStriding;
  this->m_edgeDataStriding = newStride;
  hkaiUserDataUtils::restride<unsigned int>(
    result,
    (hkResult *)&this->m_edgeData,
    m_edgeDataStriding,
    newStride,
    m_size,
    fillValue,
    v9);
  return result;
}

// File Line: 139
// RVA: 0xBE77F0
hkaiDirectedGraphExplicitCost::Node *__fastcall hkaiDirectedGraphExplicitCost::expandNodesBy(
        hkaiDirectedGraphExplicitCost *this,
        int n)
{
  int m_nodeDataStriding; // ebx
  int v5; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // r9d
  int v10; // edx
  unsigned int *v11; // rdi
  __int64 v12; // rcx
  __int64 m_size; // rcx
  int sizeElem; // [rsp+20h] [rbp-48h]
  hkResult result; // [rsp+30h] [rbp-38h] BYREF
  int v16; // [rsp+70h] [rbp+8h] BYREF
  int v17; // [rsp+80h] [rbp+18h] BYREF
  int v18; // [rsp+88h] [rbp+20h] BYREF

  m_nodeDataStriding = this->m_nodeDataStriding;
  if ( m_nodeDataStriding )
  {
    v5 = this->m_nodeData.m_size + n * m_nodeDataStriding;
    hkaiArrayUtil::reserveSmall<int,hkContainerHeapAllocator>(
      (hkaiArrayUtil *)&v16,
      (hkResult *)&this->m_nodeData,
      (hkArray<unsigned int,hkContainerHeapAllocator> *)(unsigned int)v5,
      -1);
    if ( v16 )
      return 0i64;
    v7 = this->m_nodeData.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v7 < v5 )
    {
      v8 = 2 * v7;
      v9 = v5;
      if ( v5 < v8 )
        v9 = v8;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_nodeData, v9, 4);
    }
    v10 = v5 - this->m_nodeData.m_size;
    v11 = &this->m_nodeData.m_data[this->m_nodeData.m_size];
    v12 = v10;
    if ( v10 > 0 )
    {
      while ( v12 )
      {
        *v11++ = 0;
        --v12;
      }
    }
    this->m_nodeData.m_size = v5;
  }
  hkaiArrayUtil::reserveSmall<hkaiDirectedGraphExplicitCost::Node,hkContainerHeapAllocator>(
    (hkaiArrayUtil *)&v17,
    (hkResult *)&this->m_nodes,
    (hkArray<hkaiDirectedGraphExplicitCost::Node,hkContainerHeapAllocator> *)(unsigned int)(n + this->m_nodes.m_size),
    -1,
    sizeElem);
  if ( v17 )
    return 0i64;
  hkaiArrayUtil::reserveSmall<hkVector4f,hkContainerHeapAllocator>(
    (hkaiArrayUtil *)&v18,
    (hkResult *)&this->m_positions,
    (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(unsigned int)(n + this->m_positions.m_size),
    -1);
  if ( v18 )
    return 0i64;
  this->m_positions.m_size += n;
  m_size = this->m_nodes.m_size;
  this->m_nodes.m_size = m_size + n;
  return &this->m_nodes.m_data[m_size];
}

// File Line: 162
// RVA: 0xBE7910
hkaiDirectedGraphExplicitCost::Edge *__fastcall hkaiDirectedGraphExplicitCost::expandEdgesBy(
        hkaiDirectedGraphExplicitCost *this,
        int n)
{
  int m_edgeDataStriding; // ebx
  int v5; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // r9d
  int v10; // edx
  unsigned int *v11; // rdi
  __int64 v12; // rcx
  __int64 m_size; // rcx
  int sizeElem; // [rsp+20h] [rbp-38h]
  int v15; // [rsp+60h] [rbp+8h] BYREF
  int v16; // [rsp+70h] [rbp+18h] BYREF
  hkResult result; // [rsp+78h] [rbp+20h] BYREF

  m_edgeDataStriding = this->m_edgeDataStriding;
  if ( m_edgeDataStriding )
  {
    v5 = this->m_edgeData.m_size + n * m_edgeDataStriding;
    hkaiArrayUtil::reserveSmall<int,hkContainerHeapAllocator>(
      (hkaiArrayUtil *)&v15,
      (hkResult *)&this->m_edgeData,
      (hkArray<unsigned int,hkContainerHeapAllocator> *)(unsigned int)v5,
      -1);
    if ( v15 )
      return 0i64;
    v7 = this->m_edgeData.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v7 < v5 )
    {
      v8 = 2 * v7;
      v9 = v5;
      if ( v5 < v8 )
        v9 = v8;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_edgeData, v9, 4);
    }
    v10 = v5 - this->m_edgeData.m_size;
    v11 = &this->m_edgeData.m_data[this->m_edgeData.m_size];
    v12 = v10;
    if ( v10 > 0 )
    {
      while ( v12 )
      {
        *v11++ = 0;
        --v12;
      }
    }
    this->m_edgeData.m_size = v5;
  }
  hkaiArrayUtil::reserveSmall<hkaiDirectedGraphExplicitCost::Node,hkContainerHeapAllocator>(
    (hkaiArrayUtil *)&v16,
    (hkResult *)&this->m_edges,
    (hkArray<hkaiDirectedGraphExplicitCost::Node,hkContainerHeapAllocator> *)(unsigned int)(n + this->m_edges.m_size),
    -1,
    sizeElem);
  if ( v16 )
    return 0i64;
  m_size = this->m_edges.m_size;
  this->m_edges.m_size = m_size + n;
  return &this->m_edges.m_data[m_size];
}

// File Line: 179
// RVA: 0xBE7A00
hkResult *__fastcall hkaiDirectedGraphExplicitCost::setNodesSize(
        hkaiDirectedGraphExplicitCost *this,
        hkResult *result,
        int newSize)
{
  int m_size; // eax
  int m_nodeDataStriding; // eax

  m_size = this->m_nodes.m_size;
  if ( newSize <= m_size )
  {
    m_nodeDataStriding = this->m_nodeDataStriding;
    this->m_nodes.m_size = newSize;
    this->m_positions.m_size = newSize;
    if ( m_nodeDataStriding )
      this->m_nodeData.m_size = newSize * m_nodeDataStriding;
    goto LABEL_4;
  }
  if ( hkaiDirectedGraphExplicitCost::expandNodesBy(this, newSize - m_size) )
  {
LABEL_4:
    result->m_enum = HK_SUCCESS;
    return result;
  }
  result->m_enum = HK_FAILURE;
  return result;
}

// File Line: 203
// RVA: 0xBE7A60
hkResult *__fastcall hkaiDirectedGraphExplicitCost::setEdgesSize(
        hkaiDirectedGraphExplicitCost *this,
        hkResult *result,
        int newSize)
{
  int m_size; // eax
  int m_edgeDataStriding; // eax

  m_size = this->m_edges.m_size;
  if ( newSize <= m_size )
  {
    m_edgeDataStriding = this->m_edgeDataStriding;
    this->m_edges.m_size = newSize;
    if ( m_edgeDataStriding )
      this->m_edgeData.m_size = newSize * m_edgeDataStriding;
    goto LABEL_4;
  }
  if ( hkaiDirectedGraphExplicitCost::expandEdgesBy(this, newSize - m_size) )
  {
LABEL_4:
    result->m_enum = HK_SUCCESS;
    return result;
  }
  result->m_enum = HK_FAILURE;
  return result;
}

