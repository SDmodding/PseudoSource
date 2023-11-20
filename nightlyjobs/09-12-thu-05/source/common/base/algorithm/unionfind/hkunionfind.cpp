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
  int v1; // er9
  __int64 v2; // r8

  v1 = 0;
  if ( this->m_numNodes > 0 )
  {
    v2 = 0i64;
    do
    {
      ++v1;
      ++v2;
      this->m_parents->m_data.m_storage[v2 - 1] = -1;
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
  hkUnionFind *v3; // r11
  int *v4; // rdx
  int v5; // ecx
  int v6; // eax
  int v7; // er9
  __int64 v8; // rdx
  int *v9; // rcx

  v2 = i;
  v3 = this;
  v4 = this->m_parents->m_data.m_storage;
  v5 = v4[v2];
  if ( v5 >= 0 )
  {
    v6 = v4[v2];
    do
    {
      v7 = v6;
      v6 = v4[v6];
    }
    while ( v6 >= 0 );
    if ( v5 >= 0 )
    {
      do
      {
        v8 = (signed int)v2;
        v9 = v3->m_parents->m_data.m_storage;
        v2 = v9[(signed int)v2];
        v9[v8] = v7;
      }
      while ( v3->m_parents->m_data.m_storage[v2] >= 0 );
    }
  }
  return (unsigned int)v2;
}

// File Line: 128
// RVA: 0xC6CA30
void __fastcall hkUnionFind::unionRoots(hkUnionFind *this, int r1, int r2)
{
  hkUnionFind *v3; // r9
  signed __int64 v4; // r11
  int *v5; // rcx
  int v6; // er10

  v3 = this;
  v4 = r1;
  v5 = this->m_parents->m_data.m_storage;
  v6 = v5[v4];
  if ( r1 >= r2 )
  {
    v5[r2] += v6;
    v3->m_parents->m_data.m_storage[v4] = r2;
  }
  else
  {
    v5[v4] = v6 + v5[r2];
    v3->m_parents->m_data.m_storage[r2] = r1;
  }
}

// File Line: 135
// RVA: 0xC6CAA0
void __fastcall hkUnionFind::merge(hkUnionFind *this, hkUnionFind *uf)
{
  int v2; // ebx
  hkUnionFind *v3; // r14
  hkUnionFind *v4; // rsi
  __int64 v5; // rdi
  int v6; // er8

  v2 = 0;
  v3 = uf;
  v4 = this;
  this->m_isCollapsed = 0;
  if ( this->m_numNodes > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = v3->m_parents->m_data.m_storage[v5];
      if ( v6 >= 0 )
        hkUnionFind::addEdge(v4, v2, v6);
      ++v2;
      ++v5;
    }
    while ( v2 < v4->m_numNodes );
  }
}

// File Line: 158
// RVA: 0xC6C2F0
void __fastcall hkUnionFind::addEdge(hkUnionFind *this, int i1, int i2)
{
  __int64 v3; // rbx
  hkUnionFind *v4; // r9
  int *v5; // rcx
  __int64 v6; // r11
  int v7; // edx
  int v8; // eax
  int v9; // er10
  __int64 v10; // rdx
  int *v11; // rcx
  int *v12; // rcx
  int v13; // edx
  int v14; // eax
  int v15; // er8
  __int64 v16; // rdx
  int *v17; // rcx
  signed __int64 v18; // rdx
  int *v19; // rcx
  int v20; // er8

  LODWORD(v3) = i1;
  v4 = this;
  v5 = this->m_parents->m_data.m_storage;
  LODWORD(v6) = i2;
  v7 = v5[i1];
  if ( v7 >= 0 )
  {
    v8 = v7;
    do
    {
      v9 = v8;
      v8 = v5[v8];
    }
    while ( v8 >= 0 );
    if ( v7 >= 0 )
    {
      do
      {
        v10 = (signed int)v3;
        v11 = v4->m_parents->m_data.m_storage;
        v3 = v11[(signed int)v3];
        v11[v10] = v9;
      }
      while ( v4->m_parents->m_data.m_storage[v3] >= 0 );
    }
  }
  v12 = v4->m_parents->m_data.m_storage;
  v13 = v12[i2];
  if ( v13 >= 0 )
  {
    v14 = v12[i2];
    do
    {
      v15 = v14;
      v14 = v12[v14];
    }
    while ( v14 >= 0 );
    if ( v13 >= 0 )
    {
      do
      {
        v16 = (signed int)v6;
        v17 = v4->m_parents->m_data.m_storage;
        v6 = v17[(signed int)v6];
        v17[v16] = v15;
      }
      while ( v4->m_parents->m_data.m_storage[v6] >= 0 );
    }
  }
  if ( (_DWORD)v3 != (_DWORD)v6 )
  {
    v18 = (signed int)v3;
    v19 = v4->m_parents->m_data.m_storage;
    v20 = v19[v18];
    if ( (signed int)v3 >= (signed int)v6 )
    {
      v19[(signed int)v6] += v20;
      v4->m_parents->m_data.m_storage[v18] = v6;
    }
    else
    {
      v19[v18] = v20 + v19[(signed int)v6];
      v4->m_parents->m_data.m_storage[(signed int)v6] = v3;
    }
  }
}

// File Line: 175
// RVA: 0xC6CB10
__int64 __fastcall hkUnionFind::collapseTree(hkUnionFind *this)
{
  hkUnionFind *v1; // r10
  __int64 v3; // r11
  int *v4; // rcx
  signed __int64 i; // rbx
  __int64 v6; // rax

  v1 = this;
  if ( this->m_isCollapsed )
    return (unsigned int)this->m_numRoots;
  v3 = this->m_numNodes;
  v4 = this->m_parents->m_data.m_storage;
  for ( i = (signed __int64)&v4[v3]; v4 != (int *)i; ++v4 )
  {
    if ( *v4 >= 0 )
    {
      LODWORD(v3) = v3 - 1;
      if ( v1->m_parents->m_data.m_storage[*v4] >= 0 )
      {
        LODWORD(v6) = *v4;
        do
        {
          v6 = v1->m_parents->m_data.m_storage[(signed int)v6];
          *v4 = v6;
        }
        while ( v1->m_parents->m_data.m_storage[v6] >= 0 );
      }
    }
  }
  v1->m_isCollapsed = 1;
  v1->m_numRoots = v3;
  return (unsigned int)v3;
}

// File Line: 207
// RVA: 0xC6C3E0
hkResult *__fastcall hkUnionFind::assignGroups(hkUnionFind *this, hkResult *result, hkArray<int,hkContainerHeapAllocator> *elementsPerGroup)
{
  hkArray<int,hkContainerHeapAllocator> *v3; // rdi
  hkResult *v4; // rsi
  hkUnionFind *v5; // rbx
  int v6; // eax
  int v7; // er9
  int v8; // er9
  int v10; // er9
  int v11; // er11
  __int64 v12; // rdx
  int *v13; // rcx
  __int64 v14; // r8
  hkResult resulta; // [rsp+50h] [rbp+18h]

  v3 = elementsPerGroup;
  v4 = result;
  v5 = this;
  v6 = hkUnionFind::collapseTree(this);
  v7 = v3->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 >= v6 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    v8 = 2 * v7;
    if ( v6 < v8 )
      v6 = v8;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, v6, 4);
    if ( resulta.m_enum )
    {
      v4->m_enum = 1;
      return v4;
    }
  }
  v10 = 0;
  v11 = 0;
  if ( v5->m_numNodes > 0 )
  {
    v12 = 0i64;
    do
    {
      v13 = v5->m_parents->m_data.m_storage;
      v14 = v13[v12];
      if ( (signed int)v14 >= 0 )
      {
        v13[v12] = v13[v14];
      }
      else
      {
        v3->m_data[v3->m_size++] = -(signed int)v14;
        v5->m_parents->m_data.m_storage[v12] = v11++;
      }
      ++v10;
      ++v12;
    }
    while ( v10 < v5->m_numNodes );
  }
  v4->m_enum = 0;
  return v4;
}

// File Line: 241
// RVA: 0xC6C810
__int64 __fastcall hkUnionFind::moveBiggestGroupToIndexZero(hkUnionFind *this, hkArray<int,hkContainerHeapAllocator> *elementsPerGroup)
{
  signed __int64 v2; // rdi
  int v3; // ebx
  int v4; // er10
  __int64 v5; // r8
  hkArray<int,hkContainerHeapAllocator> *v6; // r15
  hkUnionFind *v7; // r14
  unsigned int v8; // ebp
  signed __int64 v9; // rsi
  int *v10; // rax
  signed __int64 v11; // r9
  int v12; // eax
  unsigned int *v13; // r9
  signed int v14; // er11
  signed int v15; // ecx
  __m128i v16; // xmm1
  signed int v17; // edi
  __m128i v18; // xmm0
  __int64 v19; // rax
  signed __int64 i; // rax
  int v21; // er8
  __int64 v22; // r10
  int v24; // [rsp+48h] [rbp+10h]

  v2 = elementsPerGroup->m_size;
  v3 = 0;
  v4 = *elementsPerGroup->m_data;
  LODWORD(v5) = 1;
  v6 = elementsPerGroup;
  v7 = this;
  v8 = 0;
  v9 = v2;
  if ( v2 <= 1 )
    return 0i64;
  v10 = elementsPerGroup->m_data + 1;
  v11 = v2 - 1;
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
  v12 = elementsPerGroup->m_size;
  if ( (_DWORD)v2 )
  {
    v24 = 4 * v2;
    v13 = (unsigned int *)((__int64 (__fastcall *)(hkContainerTempAllocator::Allocator *, int *, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufAlloc)(
                            &hkContainerTempAllocator::s_alloc,
                            &v24,
                            v5);
    v12 = v24 / 4;
  }
  else
  {
    v13 = 0i64;
  }
  v14 = 2147483648;
  v15 = 0;
  if ( v12 )
    v14 = v12;
  if ( (signed int)v2 > 0 && (unsigned int)v2 >= 4 )
  {
    v16 = _mm_load_si128((const __m128i *)&_xmm);
    v17 = v2 - (signed int)v2 % 4;
    do
    {
      v18 = _mm_cvtsi32_si128(v15);
      v19 = v15;
      v15 += 4;
      _mm_storeu_si128((__m128i *)&v13[v19], _mm_add_epi32(_mm_shuffle_epi32(v18, 0), v16));
    }
    while ( v15 < v17 );
  }
  for ( i = v15; i < v9; ++v15 )
    v13[i++] = v15;
  *v13 = v8;
  v13[v8] = 0;
  v21 = v6->m_data[v8];
  v6->m_data[v8] = *v6->m_data;
  *v6->m_data = v21;
  if ( v7->m_numNodes > 0 )
  {
    v22 = 0i64;
    do
    {
      ++v3;
      ++v22;
      v7->m_parents->m_data.m_storage[v22 - 1] = v13[v7->m_parents->m_data.m_storage[v22 - 1]];
    }
    while ( v3 < v7->m_numNodes );
  }
  if ( v14 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v13,
      4 * v14);
  return v8;
}

// File Line: 286
// RVA: 0xC6C660
void __fastcall hkUnionFind::reindex(hkUnionFind *this, hkFixedArray<int> *rindex, __int64 numNewGroups, hkArray<int,hkContainerHeapAllocator> *elementsPerGroup)
{
  __int64 v4; // rbx
  hkArray<int,hkContainerHeapAllocator> *v5; // rsi
  hkFixedArray<int> *v6; // r13
  __int64 v7; // r12
  __int64 v8; // r9
  __int64 v9; // rdi
  int v10; // eax
  _DWORD *v11; // r14
  signed int v12; // ebp
  _DWORD *v13; // rdi
  __int64 i; // rcx
  int v15; // er8
  __int64 v16; // rdi
  _DWORD *v17; // rdx
  int v18; // eax
  int v19; // eax
  int v20; // er9
  int v21; // eax
  hkResult result; // [rsp+70h] [rbp+8h]
  int v23; // [rsp+80h] [rbp+18h]

  v4 = 0i64;
  v5 = elementsPerGroup;
  v6 = rindex;
  v7 = (signed int)numNewGroups;
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
    while ( (signed int)v8 < this->m_numNodes );
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
  v12 = 2147483648;
  if ( v10 )
    v12 = v10;
  if ( (signed int)v7 > 0 )
  {
    v13 = v11;
    for ( i = v7; i; --i )
    {
      *v13 = 0;
      ++v13;
    }
  }
  v15 = 0;
  if ( v5->m_size > 0 )
  {
    v16 = 0i64;
    do
    {
      ++v15;
      ++v16;
      v17 = &v11[v6->m_data.m_storage[v16 - 1]];
      *v17 += v5->m_data[v16 - 1];
    }
    while ( v15 < v5->m_size );
  }
  v18 = v5->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v18 < (signed int)v7 )
  {
    v19 = 2 * v18;
    v20 = v7;
    if ( (signed int)v7 < v19 )
      v20 = v19;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, v20, 4);
  }
  v5->m_size = v7;
  if ( v7 > 0 )
  {
    do
    {
      v21 = v11[v4++];
      v5->m_data[v4 - 1] = v21;
    }
    while ( v4 < v7 );
  }
  if ( v12 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v11,
      4 * v12);
}

// File Line: 312
// RVA: 0xC6C4E0
hkResult *__fastcall hkUnionFind::sortByGroupId(hkUnionFind *this, hkResult *result, hkArray<int,hkContainerHeapAllocator> *elementsPerGroup, hkArray<int,hkContainerHeapAllocator> *orderedGroups)
{
  int v4; // edi
  int v5; // eax
  hkArray<int,hkContainerHeapAllocator> *v6; // r15
  hkArray<int,hkContainerHeapAllocator> *v7; // rsi
  hkResult *v8; // rbx
  hkUnionFind *v9; // r14
  int v10; // eax
  int v11; // er9
  __int64 v12; // rdi
  signed int *v13; // r10
  signed int v14; // edx
  __int64 v15; // rcx
  int *v16; // r11
  int v17; // er8
  int *i; // r9
  __int64 v19; // rax
  __int64 v20; // rdx
  signed int *array; // [rsp+30h] [rbp-38h]
  int v23; // [rsp+38h] [rbp-30h]
  int v24; // [rsp+3Ch] [rbp-2Ch]
  hkResult resulta; // [rsp+70h] [rbp+8h]
  hkResult v26; // [rsp+88h] [rbp+20h]

  v4 = this->m_numNodes;
  v5 = orderedGroups->m_capacityAndFlags & 0x3FFFFFFF;
  v6 = orderedGroups;
  v7 = elementsPerGroup;
  v8 = result;
  v9 = this;
  if ( v5 >= v4 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    v10 = 2 * v5;
    v11 = this->m_numNodes;
    if ( v4 < v10 )
      v11 = v10;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, v11, 4);
    if ( resulta.m_enum )
    {
      v8->m_enum = 1;
      return v8;
    }
  }
  v6->m_size = v4;
  v12 = v7->m_size;
  if ( (signed int)v12 <= 0 )
  {
    v8->m_enum = 0;
    return v8;
  }
  array = 0i64;
  v23 = 0;
  v24 = 2147483648;
  if ( (signed int)v12 <= 0 )
  {
    v26.m_enum = 0;
    goto LABEL_13;
  }
  hkArrayUtil::_reserve(&v26, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v12, 4);
  if ( v26.m_enum == HK_SUCCESS )
  {
LABEL_13:
    v13 = array;
    v23 = v12;
    v14 = 0;
    v15 = 0i64;
    if ( (signed int)v12 > 0 )
    {
      do
      {
        v13[v15++] = v14;
        v14 += v7->m_data[v15 - 1];
      }
      while ( v15 < v12 );
    }
    v16 = v6->m_data;
    v17 = 0;
    for ( i = v9->m_parents->m_data.m_storage; v17 < v9->m_numNodes; ++v17 )
    {
      v19 = *i;
      ++i;
      v20 = v13[v19];
      v13[v19] = v20 + 1;
      v16[v20] = v17;
    }
    v8->m_enum = 0;
    goto LABEL_18;
  }
  v8->m_enum = 1;
LABEL_18:
  v23 = 0;
  if ( v24 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      4 * v24);
  return v8;
}

