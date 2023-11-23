// File Line: 54
// RVA: 0xC6C270
void __fastcall hkUnionFind::hkUnionFind(hkUnionFind *this, hkFixedArray<int> *parents, int numnode)
{
  this->m_parents = parents;
  this->m_numNodes = numnode;
  hkUnionFind::clear(this);
}

// File Line: 63
// RVA: 0xC6C2A0
void __fastcall hkUnionFind::clear(hkUnionFind *this)
{
  int v1; // r9d
  __int64 v2; // r8

  v1 = 0;
  if ( this->m_numNodes > 0 )
  {
    v2 = 0i64;
    do
    {
      ++v1;
      this->m_parents->m_data.m_storage[v2++] = -1;
    }
    while ( v1 < this->m_numNodes );
  }
  this->m_isCollapsed = 1;
  this->m_numRoots = -1;
  this->m_isAddingEdgesDebug = 0;
}

// File Line: 102
// RVA: 0xC6C9D0
__int64 __fastcall hkUnionFind::findRootOfNode(hkUnionFind *this, int i)
{
  __int64 v2; // r10
  int *m_storage; // rdx
  int v5; // eax
  int v6; // r9d
  __int64 v7; // rdx
  int *v8; // rcx

  v2 = i;
  m_storage = this->m_parents->m_data.m_storage;
  if ( m_storage[v2] >= 0 )
  {
    v5 = m_storage[v2];
    do
    {
      v6 = v5;
      v5 = m_storage[v5];
    }
    while ( v5 >= 0 );
    do
    {
      v7 = (int)v2;
      v8 = this->m_parents->m_data.m_storage;
      v2 = v8[(int)v2];
      v8[v7] = v6;
    }
    while ( this->m_parents->m_data.m_storage[v2] >= 0 );
  }
  return (unsigned int)v2;
}

// File Line: 128
// RVA: 0xC6CA30
void __fastcall hkUnionFind::unionRoots(hkUnionFind *this, int r1, int r2)
{
  __int64 v4; // r11
  int *m_storage; // rcx
  int v6; // r10d

  v4 = r1;
  m_storage = this->m_parents->m_data.m_storage;
  v6 = m_storage[v4];
  if ( r1 >= r2 )
  {
    m_storage[r2] += v6;
    this->m_parents->m_data.m_storage[v4] = r2;
  }
  else
  {
    m_storage[r1] = v6 + m_storage[r2];
    this->m_parents->m_data.m_storage[r2] = r1;
  }
}

// File Line: 135
// RVA: 0xC6CAA0
void __fastcall hkUnionFind::merge(hkUnionFind *this, hkUnionFind *uf)
{
  int v2; // ebx
  __int64 v5; // rdi
  int v6; // r8d

  v2 = 0;
  this->m_isCollapsed = 0;
  if ( this->m_numNodes > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = uf->m_parents->m_data.m_storage[v5];
      if ( v6 >= 0 )
        hkUnionFind::addEdge(this, v2, v6);
      ++v2;
      ++v5;
    }
    while ( v2 < this->m_numNodes );
  }
}

// File Line: 158
// RVA: 0xC6C2F0
void __fastcall hkUnionFind::addEdge(hkUnionFind *this, int i1, int i2)
{
  __int64 v3; // rbx
  int *m_storage; // rcx
  __int64 v6; // r11
  int v7; // edx
  int i; // eax
  int v9; // r10d
  __int64 v10; // rdx
  int *v11; // rcx
  int *v12; // rcx
  int v13; // eax
  int v14; // r8d
  __int64 v15; // rdx
  int *v16; // rcx
  unsigned __int64 v17; // rdx
  int *v18; // rcx
  int v19; // r8d

  LODWORD(v3) = i1;
  m_storage = this->m_parents->m_data.m_storage;
  LODWORD(v6) = i2;
  v7 = m_storage[i1];
  if ( v7 >= 0 )
  {
    for ( i = v7; i >= 0; i = m_storage[i] )
      v9 = i;
    do
    {
      v10 = (int)v3;
      v11 = this->m_parents->m_data.m_storage;
      v3 = v11[(int)v3];
      v11[v10] = v9;
    }
    while ( this->m_parents->m_data.m_storage[v3] >= 0 );
  }
  v12 = this->m_parents->m_data.m_storage;
  if ( v12[i2] >= 0 )
  {
    v13 = v12[i2];
    do
    {
      v14 = v13;
      v13 = v12[v13];
    }
    while ( v13 >= 0 );
    do
    {
      v15 = (int)v6;
      v16 = this->m_parents->m_data.m_storage;
      v6 = v16[(int)v6];
      v16[v15] = v14;
    }
    while ( this->m_parents->m_data.m_storage[v6] >= 0 );
  }
  if ( (_DWORD)v3 != (_DWORD)v6 )
  {
    v17 = (int)v3;
    v18 = this->m_parents->m_data.m_storage;
    v19 = v18[v17];
    if ( (int)v3 >= (int)v6 )
    {
      v18[(int)v6] += v19;
      this->m_parents->m_data.m_storage[v17] = v6;
    }
    else
    {
      v18[v17] = v19 + v18[(int)v6];
      this->m_parents->m_data.m_storage[(int)v6] = v3;
    }
  }
}

// File Line: 175
// RVA: 0xC6CB10
__int64 __fastcall hkUnionFind::collapseTree(hkUnionFind *this)
{
  __int64 m_numNodes; // r11
  int *m_storage; // rcx
  int *i; // rbx
  __int64 v6; // rax

  if ( this->m_isCollapsed )
    return (unsigned int)this->m_numRoots;
  m_numNodes = this->m_numNodes;
  m_storage = this->m_parents->m_data.m_storage;
  for ( i = &m_storage[m_numNodes]; m_storage != i; ++m_storage )
  {
    if ( *m_storage >= 0 )
    {
      LODWORD(m_numNodes) = m_numNodes - 1;
      if ( this->m_parents->m_data.m_storage[*m_storage] >= 0 )
      {
        LODWORD(v6) = *m_storage;
        do
        {
          v6 = this->m_parents->m_data.m_storage[(int)v6];
          *m_storage = v6;
        }
        while ( this->m_parents->m_data.m_storage[v6] >= 0 );
      }
    }
  }
  this->m_isCollapsed = 1;
  this->m_numRoots = m_numNodes;
  return (unsigned int)m_numNodes;
}

// File Line: 207
// RVA: 0xC6C3E0
hkResult *__fastcall hkUnionFind::assignGroups(
        hkUnionFind *this,
        hkResult *result,
        hkArray<int,hkContainerHeapAllocator> *elementsPerGroup)
{
  int v6; // eax
  int v7; // r9d
  int v8; // r9d
  int v10; // r9d
  int v11; // r11d
  __int64 v12; // rdx
  int *m_storage; // rcx
  __int64 v14; // r8
  hkResult resulta; // [rsp+50h] [rbp+18h] BYREF

  v6 = hkUnionFind::collapseTree(this);
  v7 = elementsPerGroup->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 >= v6 )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    v8 = 2 * v7;
    if ( v6 < v8 )
      v6 = v8;
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, (const void **)&elementsPerGroup->m_data, v6, 4);
    if ( resulta.m_enum )
    {
      result->m_enum = HK_FAILURE;
      return result;
    }
  }
  v10 = 0;
  v11 = 0;
  if ( this->m_numNodes > 0 )
  {
    v12 = 0i64;
    do
    {
      m_storage = this->m_parents->m_data.m_storage;
      v14 = m_storage[v12];
      if ( (int)v14 >= 0 )
      {
        m_storage[v12] = m_storage[v14];
      }
      else
      {
        elementsPerGroup->m_data[elementsPerGroup->m_size++] = -(int)v14;
        this->m_parents->m_data.m_storage[v12] = v11++;
      }
      ++v10;
      ++v12;
    }
    while ( v10 < this->m_numNodes );
  }
  result->m_enum = HK_SUCCESS;
  return result;
}

// File Line: 241
// RVA: 0xC6C810
__int64 __fastcall hkUnionFind::moveBiggestGroupToIndexZero(
        hkUnionFind *this,
        hkArray<int,hkContainerHeapAllocator> *elementsPerGroup)
{
  __int64 m_size; // rdi
  int v3; // ebx
  int v4; // r10d
  __int64 v5; // r8
  unsigned int v8; // ebp
  __int64 v9; // rsi
  int *v10; // rax
  __int64 v11; // r9
  unsigned int *v12; // r9
  int v13; // r11d
  signed int v14; // ecx
  __m128i si128; // xmm1
  signed int v16; // edi
  __m128i v17; // xmm0
  __int64 v18; // rax
  __int64 i; // rax
  int v20; // r8d
  __int64 v21; // r10
  int v23; // [rsp+48h] [rbp+10h] BYREF

  m_size = elementsPerGroup->m_size;
  v3 = 0;
  v4 = *elementsPerGroup->m_data;
  LODWORD(v5) = 1;
  v8 = 0;
  v9 = m_size;
  if ( m_size <= 1 )
    return 0i64;
  v10 = elementsPerGroup->m_data + 1;
  v11 = m_size - 1;
  do
  {
    if ( *v10 > v4 )
    {
      v4 = *v10;
      v8 = v5;
    }
    v5 = (unsigned int)(v5 + 1);
    ++v10;
    --v11;
  }
  while ( v11 );
  if ( !v8 )
    return 0i64;
  v23 = 4 * m_size;
  v12 = (unsigned int *)((__int64 (__fastcall *)(hkContainerTempAllocator::Allocator *, int *, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufAlloc)(
                          &hkContainerTempAllocator::s_alloc,
                          &v23,
                          v5);
  v13 = 0x80000000;
  v14 = 0;
  if ( v23 / 4 )
    v13 = v23 / 4;
  if ( (unsigned int)m_size >= 4 )
  {
    si128 = _mm_load_si128((const __m128i *)&_xmm);
    v16 = m_size - (m_size & 0x80000003);
    do
    {
      v17 = _mm_cvtsi32_si128(v14);
      v18 = v14;
      v14 += 4;
      *(__m128i *)&v12[v18] = _mm_add_epi32(_mm_shuffle_epi32(v17, 0), si128);
    }
    while ( v14 < v16 );
  }
  for ( i = v14; i < v9; v12[i++] = v14++ )
    ;
  *v12 = v8;
  v12[v8] = 0;
  v20 = elementsPerGroup->m_data[v8];
  elementsPerGroup->m_data[v8] = *elementsPerGroup->m_data;
  *elementsPerGroup->m_data = v20;
  if ( this->m_numNodes > 0 )
  {
    v21 = 0i64;
    do
    {
      ++v3;
      ++v21;
      this->m_parents->m_data.m_storage[v21 - 1] = v12[this->m_parents->m_data.m_storage[v21 - 1]];
    }
    while ( v3 < this->m_numNodes );
  }
  if ( v13 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v12, 4 * v13);
  return v8;
}

// File Line: 286
// RVA: 0xC6C660
void __fastcall hkUnionFind::reindex(
        hkUnionFind *this,
        hkFixedArray<int> *rindex,
        __int64 numNewGroups,
        hkArray<int,hkContainerHeapAllocator> *elementsPerGroup)
{
  __int64 v4; // rbx
  __int64 v7; // r12
  __int64 v8; // r9
  __int64 v9; // rdi
  int v10; // eax
  _DWORD *v11; // r14
  int v12; // ebp
  _DWORD *v13; // rdi
  __int64 i; // rcx
  int v15; // r8d
  __int64 v16; // rdi
  _DWORD *v17; // rdx
  int v18; // eax
  int v19; // eax
  int v20; // r9d
  int v21; // eax
  hkResult result; // [rsp+70h] [rbp+8h] BYREF
  int v23; // [rsp+80h] [rbp+18h] BYREF

  v4 = 0i64;
  v7 = (int)numNewGroups;
  v8 = 0i64;
  if ( this->m_numNodes > 0 )
  {
    v9 = 0i64;
    do
    {
      v8 = (unsigned int)(v8 + 1);
      ++v9;
      this->m_parents->m_data.m_storage[v9 - 1] = rindex->m_data.m_storage[this->m_parents->m_data.m_storage[v9 - 1]];
    }
    while ( (int)v8 < this->m_numNodes );
  }
  v10 = numNewGroups;
  if ( (_DWORD)numNewGroups )
  {
    v23 = 4 * numNewGroups;
    v11 = (_DWORD *)((__int64 (__fastcall *)(hkContainerTempAllocator::Allocator *, int *, __int64, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufAlloc)(
                      &hkContainerTempAllocator::s_alloc,
                      &v23,
                      numNewGroups,
                      v8);
    v10 = v23 / 4;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = 0x80000000;
  if ( v10 )
    v12 = v10;
  if ( (int)v7 > 0 )
  {
    v13 = v11;
    for ( i = v7; i; --i )
      *v13++ = 0;
  }
  v15 = 0;
  if ( elementsPerGroup->m_size > 0 )
  {
    v16 = 0i64;
    do
    {
      ++v15;
      v17 = &v11[rindex->m_data.m_storage[v16++]];
      *v17 += elementsPerGroup->m_data[v16 - 1];
    }
    while ( v15 < elementsPerGroup->m_size );
  }
  v18 = elementsPerGroup->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v18 < (int)v7 )
  {
    v19 = 2 * v18;
    v20 = v7;
    if ( (int)v7 < v19 )
      v20 = v19;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&elementsPerGroup->m_data, v20, 4);
  }
  elementsPerGroup->m_size = v7;
  if ( v7 > 0 )
  {
    do
    {
      v21 = v11[v4++];
      elementsPerGroup->m_data[v4 - 1] = v21;
    }
    while ( v4 < v7 );
  }
  if ( v12 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v11, 4 * v12);
}

// File Line: 312
// RVA: 0xC6C4E0
hkResult *__fastcall hkUnionFind::sortByGroupId(
        hkUnionFind *this,
        hkResult *result,
        hkArray<int,hkContainerHeapAllocator> *elementsPerGroup,
        hkArray<int,hkContainerHeapAllocator> *orderedGroups)
{
  int m_numNodes; // edi
  int v5; // eax
  int v10; // eax
  int v11; // r9d
  __int64 m_size; // rdi
  int *v13; // r10
  int v14; // edx
  __int64 i; // rcx
  int *m_data; // r11
  int v17; // r8d
  int *j; // r9
  __int64 v19; // rax
  __int64 v20; // rdx
  int *array; // [rsp+30h] [rbp-38h] BYREF
  int v23; // [rsp+38h] [rbp-30h]
  int v24; // [rsp+3Ch] [rbp-2Ch]
  hkResult resulta; // [rsp+70h] [rbp+8h] BYREF
  hkResult v26; // [rsp+88h] [rbp+20h] BYREF

  m_numNodes = this->m_numNodes;
  v5 = orderedGroups->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v5 >= m_numNodes )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    v10 = 2 * v5;
    v11 = this->m_numNodes;
    if ( m_numNodes < v10 )
      v11 = v10;
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, (const void **)&orderedGroups->m_data, v11, 4);
    if ( resulta.m_enum )
    {
      result->m_enum = HK_FAILURE;
      return result;
    }
  }
  orderedGroups->m_size = m_numNodes;
  m_size = elementsPerGroup->m_size;
  if ( (int)m_size > 0 )
  {
    array = 0i64;
    v23 = 0;
    v24 = 0x80000000;
    hkArrayUtil::_reserve(&v26, &hkContainerTempAllocator::s_alloc, (const void **)&array, m_size, 4);
    if ( v26.m_enum )
    {
      result->m_enum = HK_FAILURE;
    }
    else
    {
      v13 = array;
      v23 = m_size;
      v14 = 0;
      for ( i = 0i64; i < m_size; v14 += elementsPerGroup->m_data[i - 1] )
        v13[i++] = v14;
      m_data = orderedGroups->m_data;
      v17 = 0;
      for ( j = this->m_parents->m_data.m_storage; v17 < this->m_numNodes; ++v17 )
      {
        v19 = *j++;
        v20 = v13[v19];
        v13[v19] = v20 + 1;
        m_data[v20] = v17;
      }
      result->m_enum = HK_SUCCESS;
    }
    v23 = 0;
    if ( v24 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v24);
  }
  else
  {
    result->m_enum = HK_SUCCESS;
  }
  return result;
}

