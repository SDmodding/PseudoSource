// File Line: 11
// RVA: 0xBCCB80
void __fastcall hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>(hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *this, void *ptr, int sizeInBytes)
{
  int v3; // er8
  signed __int64 v4; // rax

  v3 = (unsigned int)sizeInBytes >> 2;
  this->m_elem.m_data = (unsigned int *)ptr;
  this->m_elem.m_size = v3;
  this->m_elem.m_capacityAndFlags = v3 | 0x80000000;
  v4 = 0i64;
  this->m_numElems = 0;
  if ( v3 > 0 )
  {
    do
      this->m_elem.m_data[++v4 - 1] = -1;
    while ( v4 < (unsigned int)v3 );
  }
}

// File Line: 44
// RVA: 0xBF2E80
void __fastcall hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::remove(hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *this, Dummy *it)
{
  int v2; // er9
  unsigned int *v3; // rax
  int v4; // er9
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *v5; // r10
  unsigned int *v6; // r11
  int v7; // er8
  unsigned int v8; // ecx
  unsigned int v9; // edi
  signed __int64 v10; // r8
  unsigned int v11; // eax
  __int64 v12; // rax

  v2 = this->m_elem.m_size;
  v3 = this->m_elem.m_data;
  --this->m_numElems;
  v4 = v2 - 1;
  v5 = this;
  v3[(signed int)it] = -1;
  v6 = this->m_elem.m_data;
  v7 = v4 & ((_DWORD)it + v4);
  if ( this->m_elem.m_data[v7] != -1 )
  {
    do
      v7 = v4 & (v4 + v7);
    while ( v6[v7] != -1 );
  }
  v8 = v4 & ((_DWORD)it + 1);
  v9 = v4 & (v7 + 1);
  v10 = (signed int)v8;
  if ( v6[v10] != -1 )
  {
    do
    {
      v11 = v4 & -1640531535 * (v5->m_elem.m_data[v10] >> 4);
      if ( (v8 < v9 || v11 <= (unsigned int)it)
        && (v8 >= (unsigned int)it || v11 <= (unsigned int)it && v11 > v8)
        && (v11 <= (unsigned int)it || v11 >= v9) )
      {
        v12 = (signed int)it;
        LODWORD(it) = v8;
        v5->m_elem.m_data[v12] = v5->m_elem.m_data[v10];
        v5->m_elem.m_data[v10] = -1;
      }
      v8 = v4 & (v8 + 1);
      v10 = (signed int)v8;
    }
    while ( v5->m_elem.m_data[v10] != -1 );
  }
}

// File Line: 132
// RVA: 0xBF8000
hkResult *__fastcall hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair>>::remove(hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair> > *this, hkResult *result, hkIntRealPair key)
{
  hkResult *v3; // rbx
  hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair> > *v4; // r11
  int v5; // er10
  hkIntRealPair *v6; // rdx
  int v7; // er9
  int v8; // ecx
  Dummy *v9; // rdx

  v3 = result;
  v4 = this;
  v5 = this->m_elem.m_size - 1;
  if ( v5 <= 0
    || (v6 = this->m_elem.m_data, v7 = v5 & -1640531535 * key.m_key, v8 = this->m_elem.m_data[v7].m_key, v8 == -1) )
  {
LABEL_5:
    v9 = (Dummy *)(v5 + 1);
  }
  else
  {
    while ( v8 != key.m_key )
    {
      v7 = v5 & (v7 + 1);
      v8 = v6[v7].m_key;
      if ( v8 == -1 )
        goto LABEL_5;
    }
    v9 = (Dummy *)(unsigned int)v7;
  }
  if ( (signed int)v9 > v5 )
  {
    v3->m_enum = 1;
  }
  else
  {
    hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair>>::remove(v4, v9);
    v3->m_enum = 0;
  }
  return v3;
}

// File Line: 197
// RVA: 0xBBF490
hkResult *__fastcall hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::resizeTable(hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *this, hkResult *result, int newcap)
{
  __int64 v3; // rbp
  signed int v4; // edi
  hkResult *v5; // rsi
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *v6; // rbx
  int v7; // er8
  signed __int64 v9; // rcx
  __int64 v10; // rsi
  hkRelocationInfo::Import *v11; // rax
  unsigned int v12; // edi
  int v13; // er8
  unsigned int *v14; // r9
  int v15; // er8
  signed int v16; // er10
  int v17; // eax
  unsigned int v18; // edx
  __int64 v19; // rcx
  hkResult *v20; // rbx
  int v21; // er8
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> v22; // [rsp+30h] [rbp-28h]
  hkResult v23; // [rsp+60h] [rbp+8h]
  hkResult *v24; // [rsp+68h] [rbp+10h]
  hkResult resulta; // [rsp+70h] [rbp+18h]

  v24 = result;
  v3 = this->m_elem.m_size;
  v4 = 8;
  v5 = result;
  v6 = this;
  if ( newcap > 8 )
    v4 = newcap;
  v22.m_data = 0i64;
  v22.m_size = 0;
  v22.m_capacityAndFlags = 2147483648;
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    &v22,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)this);
  if ( (v6->m_elem.m_capacityAndFlags & 0x3FFFFFFF) >= v4 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, v4, 4);
    if ( resulta.m_enum )
    {
      v7 = v22.m_capacityAndFlags;
      v5->m_enum = 1;
      if ( v7 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v22.m_data,
          4 * v7);
      return v5;
    }
  }
  v9 = 0i64;
  v6->m_elem.m_size = v4;
  if ( v4 > 0 )
  {
    do
      v6->m_elem.m_data[++v9 - 1] = -1;
    while ( v9 < v4 );
  }
  v10 = 0i64;
  v6->m_numElems = 0;
  if ( v3 > 0 )
  {
    v11 = v22.m_data;
    do
    {
      v12 = *(&v11->m_fromOffset + v10);
      if ( v12 != -1 )
      {
        v13 = v6->m_elem.m_size - 1;
        if ( 2 * v6->m_numElems > v13 )
          hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::resizeTable(v6, &v23, 2 * v13 + 2);
        v14 = v6->m_elem.m_data;
        v15 = v6->m_elem.m_size - 1;
        v16 = 1;
        v17 = v15 & -1640531535 * (v12 >> 4);
        v18 = v6->m_elem.m_data[v17];
        if ( v18 != -1 )
        {
          while ( v18 != v12 )
          {
            v17 = v15 & (v17 + 1);
            v18 = v14[v17];
            if ( v18 == -1 )
              goto LABEL_21;
          }
          v16 = 0;
        }
LABEL_21:
        v6->m_numElems += v16;
        v19 = v17;
        v11 = v22.m_data;
        v14[v19] = v12;
      }
      ++v10;
    }
    while ( v10 < v3 );
  }
  v20 = v24;
  v21 = v22.m_capacityAndFlags;
  v24->m_enum = 0;
  if ( v21 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v22.m_data,
      4 * v21);
  return v20;
}

// File Line: 302
// RVA: 0xBF7D90
void __fastcall hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair>>::clear(hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair> > *this)
{
  signed __int64 v1; // r8
  signed __int64 v2; // rdx
  hkIntRealPair *v3; // rax
  hkIntRealPair *v4; // rax
  hkIntRealPair *v5; // rax
  hkIntRealPair *v6; // rax
  hkIntRealPair *v7; // rax

  v1 = this->m_elem.m_size;
  v2 = 0i64;
  if ( v1 >= 4 )
  {
    do
    {
      v3 = this->m_elem.m_data;
      v2 += 4i64;
      v3[v2 - 4].m_key = -1;
      *((_DWORD *)&v3[v2 - 3] - 1) = -1082130432;
      v4 = this->m_elem.m_data;
      v4[v2 - 3].m_key = -1;
      *((_DWORD *)&v4[v2 - 2] - 1) = -1082130432;
      v5 = this->m_elem.m_data;
      v5[v2 - 2].m_key = -1;
      *((_DWORD *)&v5[v2 - 1] - 1) = -1082130432;
      v6 = this->m_elem.m_data;
      v6[v2 - 1].m_key = -1;
      *((_DWORD *)&v6[v2] - 1) = -1082130432;
    }
    while ( v2 < v1 - 3 );
  }
  for ( ; v2 < v1; *((_DWORD *)&v7[v2] - 1) = -1082130432 )
  {
    v7 = this->m_elem.m_data;
    v7[++v2 - 1].m_key = -1;
  }
  this->m_numElems = 0;
}

// File Line: 314
// RVA: 0xBF2F60
void __fastcall hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::reserve(hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *this, int numElements)
{
  int v2; // edx
  int i; // er8
  hkResult result; // [rsp+38h] [rbp+10h]

  v2 = 2 * numElements;
  for ( i = 8; i < v2; i *= 2 )
    ;
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::resizeTable(this, &result, i);
}

// File Line: 326
// RVA: 0xBF7FC0
void __fastcall hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair>>::optimizeCapacity(hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair> > *this, int numFreeElemsLeft)
{
  hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair> > *v2; // rbx
  int v3; // eax
  hkResult result; // [rsp+38h] [rbp+10h]

  v2 = this;
  v3 = hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::getCapacityFor(numFreeElemsLeft + this->m_numElems);
  if ( v3 != (v2->m_elem.m_size & 0x7FFFFFFF) )
    hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair>>::resizeTable(v2, &result, v3);
}

// File Line: 338
// RVA: 0xBCCF30
__int64 __fastcall hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::getSizeInBytesFor(int numOfKeys)
{
  return (unsigned int)(4
                      * hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::getCapacityFor(numOfKeys));
}

// File Line: 344
// RVA: 0xBF7EF0
signed __int64 __fastcall hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::getCapacityFor(int numOfKeys)
{
  int v1; // ecx
  signed __int64 result; // rax

  v1 = 2 * numOfKeys;
  result = 8i64;
  if ( v1 > 8 )
  {
    do
      result = (unsigned int)(2 * result);
    while ( (signed int)result < v1 );
  }
  return result;
}

