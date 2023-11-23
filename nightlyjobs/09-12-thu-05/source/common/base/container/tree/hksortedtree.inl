// File Line: 27
// RVA: 0xCC22F0
void __fastcall hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::clear(
        hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16> *this,
        int numNodes)
{
  int m_capacityAndFlags; // eax

  *(_QWORD *)&this->m_root = 0i64;
  this->m_size = 0;
  this->m_prng.m_x = 123456789;
  this->m_prng.m_y = 234567891;
  this->m_prng.m_z = 345678912;
  *(_QWORD *)&this->m_prng.m_w = 456789123i64;
  m_capacityAndFlags = this->m_nodes.m_capacityAndFlags;
  this->m_nodes.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_nodes.m_data,
      24 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_nodes.m_data = 0i64;
  this->m_nodes.m_capacityAndFlags = 0x80000000;
  if ( !this->m_nodes.m_size )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_nodes.m_data, 24);
  ++this->m_nodes.m_size;
  hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::preAllocateNodes(this, numNodes);
}

// File Line: 40
// RVA: 0xCC23A0
void __fastcall hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::preAllocateNodes(
        hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16> *this,
        int count)
{
  __int64 m_size; // rsi
  int v3; // eax
  int v4; // r9d
  int v5; // ebp
  int v8; // eax
  int v9; // r8d
  __int64 v10; // rdx
  __int64 v11; // r9
  __int64 v12; // rdx
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  if ( count )
  {
    m_size = this->m_nodes.m_size;
    v3 = this->m_nodes.m_capacityAndFlags & 0x3FFFFFFF;
    v4 = m_size + count;
    v5 = m_size + count - 1;
    if ( v3 < (int)m_size + count )
    {
      v8 = 2 * v3;
      if ( v4 < v8 )
        v4 = v8;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_nodes.m_data, v4, 24);
    }
    this->m_nodes.m_size += count;
    v9 = m_size;
    if ( m_size < v5 )
    {
      v10 = m_size;
      v11 = v5 - m_size;
      do
      {
        this->m_nodes.m_data[v10++].m_parent = v9 + 1;
        this->m_nodes.m_data[v10 - 1].m_children[0] = v9++;
        --v11;
      }
      while ( v11 );
    }
    v12 = v5;
    this->m_nodes.m_data[v12].m_parent = this->m_free;
    this->m_nodes.m_data[v12].m_children[0] = v5;
    this->m_free = m_size;
  }
}

// File Line: 60
// RVA: 0xCBFDD0
__int64 __fastcall hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16>::insert(
        hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16> *this,
        hkGeometryProcessingInternals::ClusterQueueNode *value)
{
  __int64 m_free; // rsi
  hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16>::Node *m_data; // rdx
  int m_root; // r10d
  hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16>::Node *v7; // rdi
  int m_value; // r11d
  hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16>::Node *v9; // r8
  int v10; // ecx
  int v11; // eax

  if ( !this->m_free )
    hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16>::preAllocateNodes(
      this,
      16);
  m_free = this->m_free;
  m_data = this->m_nodes.m_data;
  this->m_free = this->m_nodes.m_data[m_free].m_parent;
  m_data[m_free].m_value = *value;
  m_root = this->m_root;
  v7 = &this->m_nodes.m_data[m_free];
  if ( m_root )
  {
    m_value = v7->m_value.m_value;
    while ( 1 )
    {
      v9 = &this->m_nodes.m_data[m_root];
      v10 = v9->m_value.m_value;
      v11 = m_value >= v10 ? v10 < m_value : -1;
      if ( !v9->m_children[v11 >= 0] )
        break;
      m_root = v9->m_children[v11 >= 0];
    }
    v9->m_children[v11 >= 0] = m_free;
    v7->m_parent = m_root;
  }
  else
  {
    this->m_root = m_free;
    v7->m_parent = 0;
  }
  *(_QWORD *)v7->m_children = 0i64;
  ++this->m_size;
  return (unsigned int)m_free;
}

// File Line: 224
// RVA: 0xCEA8C0
void __fastcall hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::traverseMinMax<hkgpCgoInternal::ErrorCollector>(
        hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16> *this,
        hkgpCgoInternal::ErrorCollector *functor,
        int root)
{
  hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::Node *m_data; // rsi
  __int64 v5; // rdi
  int v6; // r8d
  hkgpCgoInternal::EdgeInfo *m_value; // rbp
  hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16> *i; // [rsp+40h] [rbp+8h]

  for ( i = this; ; this = i )
  {
    if ( !root )
    {
      root = this->m_root;
      if ( !root )
        break;
    }
    m_data = this->m_nodes.m_data;
    v5 = root;
    v6 = this->m_nodes.m_data[root].m_children[0];
    if ( v6 )
      hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::traverseMinMax<hkgpCgoInternal::ErrorCollector>(
        this,
        functor,
        v6);
    m_value = m_data[v5].m_value;
    if ( m_value->m_error < 3.40282e38 )
    {
      if ( functor->m_values.m_size == (functor->m_values.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&functor->m_values.m_data, 4);
      functor->m_values.m_data[functor->m_values.m_size++] = m_value->m_error;
    }
    root = m_data[v5].m_children[1];
    if ( !root )
      break;
  }
}

// File Line: 253
// RVA: 0xCEAA50
void __fastcall hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::insertNode(
        hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16> *this,
        int nodeIndex)
{
  int m_root; // r11d
  hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::Node *m_data; // r9
  __int64 v5; // rdi
  hkgpCgoInternal::EdgeInfo *m_value; // r10
  hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::Node *v7; // rbx
  hkgpCgoInternal::EdgeInfo *v8; // rcx
  int v9; // eax
  float m_error; // xmm0_4
  float v11; // xmm1_4
  signed int m_index; // eax
  signed int v13; // edx
  unsigned __int64 v14; // rcx

  m_root = this->m_root;
  m_data = this->m_nodes.m_data;
  v5 = nodeIndex;
  if ( m_root )
  {
    m_value = m_data[nodeIndex].m_value;
    while ( 1 )
    {
      v7 = &m_data[m_root];
      v8 = v7->m_value;
      if ( m_value == v7->m_value )
      {
        v9 = 0;
      }
      else
      {
        m_error = m_value->m_error;
        v11 = v8->m_error;
        if ( m_error >= v11 )
        {
          if ( m_error <= v11 )
          {
            m_index = m_value->m_edge.m_index;
            v13 = v8->m_edge.m_index;
            if ( m_index >= v13 )
            {
              if ( m_index <= v13 )
              {
                v14 = v8->m_edge.m_triangle->m_index;
                v9 = m_value->m_edge.m_triangle->m_index >= v14 ? m_value->m_edge.m_triangle->m_index > v14 : -1;
              }
              else
              {
                v9 = 1;
              }
            }
            else
            {
              v9 = -1;
            }
          }
          else
          {
            v9 = 1;
          }
        }
        else
        {
          v9 = -1;
        }
      }
      if ( !v7->m_children[v9 >= 0] )
        break;
      m_root = v7->m_children[v9 >= 0];
    }
    v7->m_children[v9 >= 0] = nodeIndex;
    m_data[v5].m_parent = m_root;
    *(_QWORD *)m_data[v5].m_children = 0i64;
  }
  else
  {
    this->m_root = nodeIndex;
    *(_QWORD *)&m_data[nodeIndex].m_children[1] = 0i64;
    m_data[nodeIndex].m_children[0] = 0;
  }
}

// File Line: 287
// RVA: 0xCC18C0
void __fastcall hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16>::removeNode(
        hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16> *this,
        int nodeIndex)
{
  hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16>::Node *m_data; // rcx
  __int64 m_parent; // rdi
  int *v6; // rax
  int *m_children; // r10
  __int64 v8; // rcx
  unsigned int v9; // ecx
  unsigned int v10; // edx
  int v11; // r8d
  unsigned int m_w; // ecx
  bool v13; // sf
  unsigned int v14; // r8d
  int v15; // edx
  hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16>::Node *v16; // rbp
  signed int v17; // r8d
  int v18; // edx
  __int64 v19; // rcx
  __int64 v20; // r8
  int *v21; // r14
  int i; // ecx
  __int64 v23; // rcx
  __int64 v24; // rcx

  m_data = this->m_nodes.m_data;
  m_parent = m_data[nodeIndex].m_parent;
  v6 = (int *)&m_data[nodeIndex];
  if ( (_DWORD)m_parent )
  {
    m_children = m_data[m_parent].m_children;
    if ( *m_children != nodeIndex )
      m_children = &m_data[m_parent].m_children[1];
  }
  else
  {
    m_children = &this->m_root;
  }
  v8 = v6[2];
  if ( (_DWORD)v8 )
  {
    if ( v6[3] )
    {
      v9 = this->m_prng.m_y ^ (32 * this->m_prng.m_y) ^ ((this->m_prng.m_y ^ (32 * this->m_prng.m_y)) >> 7);
      v10 = this->m_prng.m_z + this->m_prng.m_c;
      v11 = v9 ^ (v9 << 22);
      m_w = this->m_prng.m_w;
      v13 = (int)(m_w + v10) < 0;
      this->m_prng.m_y = v11;
      this->m_prng.m_z = m_w;
      this->m_prng.m_x += 1411392427;
      v14 = this->m_prng.m_x + v11;
      v15 = (m_w + v10) & 0x7FFFFFFF;
      this->m_prng.m_c = v13;
      this->m_prng.m_w = v15;
      v16 = this->m_nodes.m_data;
      v17 = ((v15 + v14) >> 1) & 1;
      v18 = 1 - v17;
      v19 = v17;
      v20 = v6[v17 + 2];
      v21 = &v6[v19];
      for ( i = this->m_nodes.m_data->m_children[4 * v20 + v20 + v18]; i; i = v16->m_children[4 * i + i + v18] )
        LODWORD(v20) = i;
      v16->m_children[4 * (int)v20 + v18 + (int)v20] = v6[v18 + 2];
      this->m_nodes.m_data[v6[v18 + 2]].m_parent = v20;
      v23 = v21[2];
      *m_children = v23;
      this->m_nodes.m_data[v23].m_parent = m_parent;
      v6[4] = 0;
      v6[2] = nodeIndex;
    }
    else
    {
      *m_children = v8;
      this->m_nodes.m_data[v8].m_parent = m_parent;
      v6[4] = 0;
      v6[2] = nodeIndex;
    }
  }
  else
  {
    v24 = v6[3];
    if ( (_DWORD)v24 )
    {
      *m_children = v24;
      this->m_nodes.m_data[v24].m_parent = m_parent;
    }
    else
    {
      *m_children = 0;
    }
    v6[4] = 0;
    v6[2] = nodeIndex;
  }
}

