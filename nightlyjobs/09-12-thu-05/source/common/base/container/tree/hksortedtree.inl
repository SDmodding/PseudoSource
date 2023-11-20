// File Line: 27
// RVA: 0xCC22F0
void __fastcall hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::clear(hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16> *this, int numNodes)
{
  int v2; // edi
  hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16> *v3; // rbx
  int v4; // eax

  v2 = numNodes;
  v3 = this;
  *(_QWORD *)&this->m_root = 0i64;
  this->m_size = 0;
  this->m_prng.m_x = 123456789;
  this->m_prng.m_y = 234567891;
  this->m_prng.m_z = 345678912;
  *(_QWORD *)&this->m_prng.m_w = 456789123i64;
  v4 = this->m_nodes.m_capacityAndFlags;
  this->m_nodes.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_nodes.m_data,
      24 * (v4 & 0x3FFFFFFF));
  v3->m_nodes.m_data = 0i64;
  v3->m_nodes.m_capacityAndFlags = 2147483648;
  if ( !v3->m_nodes.m_size )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 24);
  ++v3->m_nodes.m_size;
  hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::preAllocateNodes(v3, v2);
}

// File Line: 40
// RVA: 0xCC23A0
void __fastcall hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::preAllocateNodes(hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16> *this, int count)
{
  signed __int64 v2; // rsi
  int v3; // eax
  int v4; // er9
  int v5; // ebp
  int v6; // edi
  hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16> *v7; // rbx
  int v8; // eax
  int v9; // er8
  signed __int64 v10; // rdx
  signed __int64 v11; // r9
  signed __int64 v12; // rdx
  hkResult result; // [rsp+48h] [rbp+10h]

  if ( count )
  {
    v2 = this->m_nodes.m_size;
    v3 = this->m_nodes.m_capacityAndFlags & 0x3FFFFFFF;
    v4 = v2 + count;
    v5 = v2 + count - 1;
    v6 = count;
    v7 = this;
    if ( v3 < (signed int)v2 + count )
    {
      v8 = 2 * v3;
      if ( v4 < v8 )
        v4 = v8;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, this, v4, 24);
    }
    v7->m_nodes.m_size += v6;
    v9 = v2;
    if ( v2 < v5 )
    {
      v10 = v2;
      v11 = v5 - v2;
      do
      {
        ++v10;
        *((_DWORD *)&v7->m_nodes.m_data[v10] - 2) = v9 + 1;
        *((_DWORD *)&v7->m_nodes.m_data[v10] - 4) = v9++;
        --v11;
      }
      while ( v11 );
    }
    v12 = v5;
    v7->m_nodes.m_data[v12].m_parent = v7->m_free;
    v7->m_nodes.m_data[v12].m_children[0] = v5;
    v7->m_free = v2;
  }
}

// File Line: 60
// RVA: 0xCBFDD0
__int64 __fastcall hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16>::insert(hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16> *this, hkGeometryProcessingInternals::ClusterQueueNode *value)
{
  hkGeometryProcessingInternals::ClusterQueueNode *v2; // rdi
  hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16> *v3; // rbx
  __int64 v4; // rsi
  hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16>::Node *v5; // rdx
  hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16>::Node *v6; // r14
  int v7; // er10
  signed __int64 v8; // rdi
  int v9; // er11
  signed __int64 v10; // r8
  int v11; // ecx
  int v12; // eax

  v2 = value;
  v3 = this;
  if ( !this->m_free )
    hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16>::preAllocateNodes(
      this,
      16);
  v4 = v3->m_free;
  v5 = v3->m_nodes.m_data;
  v3->m_free = v3->m_nodes.m_data[v4].m_parent;
  v5[v4].m_value = *v2;
  v6 = v3->m_nodes.m_data;
  v7 = v3->m_root;
  v8 = (signed __int64)&v3->m_nodes.m_data[v4];
  if ( v7 )
  {
    v9 = *(_DWORD *)(v8 + 4);
    while ( 1 )
    {
      v10 = (signed __int64)&v6[v7];
      v11 = v6[v7].m_value.m_value;
      v12 = v9 >= v11 ? (unsigned __int8)(v11 < v9) : -1;
      if ( !*(_DWORD *)(v10 + 4i64 * (v12 >= 0) + 8) )
        break;
      v7 = *(_DWORD *)(v10 + 4i64 * (v12 >= 0) + 8);
    }
    *(_DWORD *)(v10 + 4i64 * (v12 >= 0) + 8) = v4;
    *(_DWORD *)(v8 + 16) = v7;
  }
  else
  {
    v3->m_root = v4;
    *(_DWORD *)(v8 + 16) = 0;
  }
  *(_QWORD *)(v8 + 8) = 0i64;
  ++v3->m_size;
  return (unsigned int)v4;
}

// File Line: 224
// RVA: 0xCEA8C0
void __fastcall hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::traverseMinMax<hkgpCgoInternal::ErrorCollector>(hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16> *this, hkgpCgoInternal::ErrorCollector *functor, int root)
{
  hkgpCgoInternal::ErrorCollector *v3; // rbx
  hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::Node *v4; // rsi
  signed __int64 v5; // rdi
  int v6; // er8
  hkgpCgoInternal::EdgeInfo *v7; // rbp
  hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16> *v8; // [rsp+40h] [rbp+8h]

  v8 = this;
  v3 = functor;
  while ( 1 )
  {
    if ( !root )
    {
      root = this->m_root;
      if ( !root )
        break;
    }
    v4 = this->m_nodes.m_data;
    v5 = root;
    v6 = this->m_nodes.m_data[root].m_children[0];
    if ( v6 )
      hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::traverseMinMax<hkgpCgoInternal::ErrorCollector>(
        this,
        v3,
        v6);
    v7 = v4[v5].m_value;
    if ( v7->m_error < 3.40282e38 )
    {
      if ( v3->m_values.m_size == (v3->m_values.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 4);
      v3->m_values.m_data[v3->m_values.m_size++] = v7->m_error;
    }
    root = v4[v5].m_children[1];
    if ( !root )
      break;
    this = v8;
  }
}

// File Line: 253
// RVA: 0xCEAA50
void __fastcall hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::insertNode(hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16> *this, int nodeIndex)
{
  int v2; // er11
  hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::Node *v3; // r9
  int v4; // esi
  signed __int64 v5; // rdi
  hkgpCgoInternal::EdgeInfo *v6; // r10
  signed __int64 v7; // rbx
  hkgpCgoInternal::EdgeInfo *v8; // rcx
  signed int v9; // eax
  float v10; // xmm0_4
  float v11; // xmm1_4
  signed int v12; // eax
  signed int v13; // edx
  unsigned __int64 v14; // rcx

  v2 = this->m_root;
  v3 = this->m_nodes.m_data;
  v4 = nodeIndex;
  v5 = nodeIndex;
  if ( v2 )
  {
    v6 = v3[nodeIndex].m_value;
    while ( 1 )
    {
      v7 = (signed __int64)&v3[v2];
      v8 = v3[v2].m_value;
      if ( v6 == v8 )
      {
        v9 = 0;
      }
      else
      {
        v10 = v6->m_error;
        v11 = v8->m_error;
        if ( v10 >= v11 )
        {
          if ( v10 <= v11 )
          {
            v12 = v6->m_edge.m_index;
            v13 = v8->m_edge.m_index;
            if ( v12 >= v13 )
            {
              if ( v12 <= v13 )
              {
                v14 = v8->m_edge.m_triangle->m_index;
                v9 = v6->m_edge.m_triangle->m_index >= v14 ? (unsigned __int8)(v6->m_edge.m_triangle->m_index > v14) : -1;
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
      if ( !*(_DWORD *)(v7 + 4i64 * (v9 >= 0) + 8) )
        break;
      v2 = *(_DWORD *)(v7 + 4i64 * (v9 >= 0) + 8);
    }
    *(_DWORD *)(v7 + 4i64 * (v9 >= 0) + 8) = v4;
    v3[v5].m_parent = v2;
    *(_QWORD *)v3[v5].m_children = 0i64;
  }
  else
  {
    this->m_root = nodeIndex;
    *(_QWORD *)&v3[nodeIndex].m_children[1] = 0i64;
    v3[nodeIndex].m_children[0] = 0;
  }
}

// File Line: 287
// RVA: 0xCC18C0
void __fastcall hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16>::removeNode(hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16> *this, int nodeIndex)
{
  int v2; // ebx
  hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16> *v3; // r11
  hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16>::Node *v4; // rcx
  __int64 v5; // rdi
  signed int *v6; // rax
  int *v7; // r10
  __int64 v8; // rcx
  unsigned int v9; // ecx
  int v10; // edx
  int v11; // er8
  unsigned int v12; // ecx
  bool v13; // sf
  int v14; // er8
  int v15; // edx
  hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16>::Node *v16; // rbp
  signed int v17; // er8
  int v18; // edx
  __int64 v19; // rcx
  __int64 v20; // r8
  signed __int64 v21; // r14
  int i; // ecx
  __int64 v23; // rcx
  __int64 v24; // rcx

  v2 = nodeIndex;
  v3 = this;
  v4 = this->m_nodes.m_data;
  v5 = v4[nodeIndex].m_parent;
  v6 = (signed int *)&v4[nodeIndex];
  if ( (_DWORD)v5 )
  {
    v7 = v4[v5].m_children;
    if ( *v7 != nodeIndex )
      v7 = &v4[v5].m_children[1];
  }
  else
  {
    v7 = &v3->m_root;
  }
  v8 = v6[2];
  if ( (_DWORD)v8 )
  {
    if ( v6[3] )
    {
      v9 = v3->m_prng.m_y ^ 32 * v3->m_prng.m_y ^ ((v3->m_prng.m_y ^ 32 * v3->m_prng.m_y) >> 7);
      v10 = v3->m_prng.m_z + v3->m_prng.m_c;
      v11 = v9 ^ (v9 << 22);
      v12 = v3->m_prng.m_w;
      v13 = (signed int)(v12 + v10) < 0;
      v3->m_prng.m_y = v11;
      v3->m_prng.m_z = v12;
      v3->m_prng.m_x += 1411392427;
      v14 = v3->m_prng.m_x + v11;
      v15 = (v12 + v10) & 0x7FFFFFFF;
      v3->m_prng.m_c = v13;
      v3->m_prng.m_w = v15;
      v16 = v3->m_nodes.m_data;
      v17 = ((unsigned int)(v15 + v14) >> 1) & 1;
      v18 = 1 - v17;
      v19 = v17;
      v20 = v6[v17 + 2];
      v21 = (signed __int64)&v6[v19];
      for ( i = v3->m_nodes.m_data->m_children[v20 + v18 + 4 * v20]; i; i = v16->m_children[i + v18 + 4i64 * i] )
        LODWORD(v20) = i;
      v16->m_children[v18 + 4i64 * (signed int)v20 + (signed int)v20] = v6[v18 + 2];
      v3->m_nodes.m_data[v6[v18 + 2]].m_parent = v20;
      v23 = *(signed int *)(v21 + 8);
      *v7 = v23;
      v3->m_nodes.m_data[v23].m_parent = v5;
      v6[4] = 0;
      v6[2] = v2;
    }
    else
    {
      *v7 = v8;
      v3->m_nodes.m_data[v8].m_parent = v5;
      v6[4] = 0;
      v6[2] = nodeIndex;
    }
  }
  else
  {
    v24 = v6[3];
    if ( (_DWORD)v24 )
    {
      *v7 = v24;
      v3->m_nodes.m_data[v24].m_parent = v5;
    }
    else
    {
      *v7 = 0;
    }
    v6[4] = 0;
    v6[2] = nodeIndex;
  }
}

