// File Line: 11
// RVA: 0xBCCB80
void __fastcall hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>(
        hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *this,
        unsigned int *ptr,
        unsigned int sizeInBytes)
{
  int v3; // r8d
  __int64 v4; // rax

  v3 = sizeInBytes >> 2;
  this->m_elem.m_data = ptr;
  this->m_elem.m_size = v3;
  this->m_elem.m_capacityAndFlags = v3 | 0x80000000;
  v4 = 0i64;
  for ( this->m_numElems = 0; v4 < (unsigned int)v3; this->m_elem.m_data[v4 - 1] = -1 )
    ++v4;
}

// File Line: 44
// RVA: 0xBF2E80
void __fastcall hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::remove(
        hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *this,
        Dummy *it)
{
  int m_size; // r9d
  unsigned int *m_data; // rax
  int v4; // r9d
  unsigned int *v6; // r11
  int v7; // r8d
  unsigned int v8; // ecx
  unsigned int v9; // edi
  __int64 v10; // r8
  unsigned int v11; // eax
  __int64 v12; // rax

  m_size = this->m_elem.m_size;
  m_data = this->m_elem.m_data;
  --this->m_numElems;
  v4 = m_size - 1;
  m_data[(int)it] = -1;
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
  v10 = (int)v8;
  if ( v6[v10] != -1 )
  {
    do
    {
      v11 = v4 & (-1640531535 * (this->m_elem.m_data[v10] >> 4));
      if ( (v8 < v9 || v11 <= (unsigned int)it)
        && (v8 >= (unsigned int)it || v11 <= (unsigned int)it && v11 > v8)
        && (v11 <= (unsigned int)it || v11 >= v9) )
      {
        v12 = (int)it;
        LODWORD(it) = v8;
        this->m_elem.m_data[v12] = this->m_elem.m_data[v10];
        this->m_elem.m_data[v10] = -1;
      }
      v8 = v4 & (v8 + 1);
      v10 = (int)v8;
    }
    while ( this->m_elem.m_data[v10] != -1 );
  }
}

// File Line: 132
// RVA: 0xBF8000
hkResult *__fastcall hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair>>::remove(
        hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair> > *this,
        hkResult *result,
        hkIntRealPair key)
{
  int v5; // r10d
  hkIntRealPair *m_data; // rdx
  int v7; // r9d
  int m_key; // ecx
  Dummy *v9; // rdx

  v5 = this->m_elem.m_size - 1;
  if ( v5 <= 0
    || (m_data = this->m_elem.m_data,
        v7 = v5 & (-1640531535 * key.m_key),
        m_key = this->m_elem.m_data[v7].m_key,
        m_key == -1) )
  {
LABEL_5:
    v9 = (Dummy *)(v5 + 1);
  }
  else
  {
    while ( m_key != key.m_key )
    {
      v7 = v5 & (v7 + 1);
      m_key = m_data[v7].m_key;
      if ( m_key == -1 )
        goto LABEL_5;
    }
    v9 = (Dummy *)(unsigned int)v7;
  }
  if ( (int)v9 > v5 )
  {
    result->m_enum = HK_FAILURE;
  }
  else
  {
    hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair>>::remove(this, v9);
    result->m_enum = HK_SUCCESS;
  }
  return result;
}

// File Line: 197
// RVA: 0xBBF490
hkResult *__fastcall hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::resizeTable(
        hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *this,
        hkResult *result,
        int newcap)
{
  __int64 m_size; // rbp
  int v4; // edi
  int m_capacityAndFlags; // r8d
  __int64 v9; // rcx
  __int64 v10; // rsi
  hkRelocationInfo::Import *m_data; // rax
  unsigned int v12; // edi
  int v13; // r8d
  unsigned int *v14; // r9
  int v15; // r8d
  int v16; // r10d
  int v17; // eax
  unsigned int v18; // edx
  __int64 v19; // rcx
  hkResult *v20; // rbx
  int v21; // r8d
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> v22; // [rsp+30h] [rbp-28h] BYREF
  hkResult v23; // [rsp+60h] [rbp+8h] BYREF
  hkResult *v24; // [rsp+68h] [rbp+10h]
  hkResult resulta; // [rsp+70h] [rbp+18h] BYREF

  v24 = result;
  m_size = this->m_elem.m_size;
  v4 = 8;
  if ( newcap > 8 )
    v4 = newcap;
  v22.m_data = 0i64;
  v22.m_size = 0;
  v22.m_capacityAndFlags = 0x80000000;
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    &v22,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)this);
  if ( (this->m_elem.m_capacityAndFlags & 0x3FFFFFFF) >= v4 )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, this, v4, 4);
    if ( resulta.m_enum )
    {
      m_capacityAndFlags = v22.m_capacityAndFlags;
      result->m_enum = HK_FAILURE;
      if ( m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v22.m_data,
          4 * m_capacityAndFlags);
      return result;
    }
  }
  v9 = 0i64;
  this->m_elem.m_size = v4;
  do
    this->m_elem.m_data[v9++] = -1;
  while ( v9 < v4 );
  v10 = 0i64;
  this->m_numElems = 0;
  if ( m_size > 0 )
  {
    m_data = v22.m_data;
    do
    {
      v12 = *(&m_data->m_fromOffset + v10);
      if ( v12 != -1 )
      {
        v13 = this->m_elem.m_size - 1;
        if ( 2 * this->m_numElems > v13 )
          hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::resizeTable(
            this,
            &v23,
            2 * v13 + 2);
        v14 = this->m_elem.m_data;
        v15 = this->m_elem.m_size - 1;
        v16 = 1;
        v17 = v15 & (-1640531535 * (v12 >> 4));
        v18 = this->m_elem.m_data[v17];
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
        this->m_numElems += v16;
        v19 = v17;
        m_data = v22.m_data;
        v14[v19] = v12;
      }
      ++v10;
    }
    while ( v10 < m_size );
  }
  v20 = v24;
  v21 = v22.m_capacityAndFlags;
  v24->m_enum = HK_SUCCESS;
  if ( v21 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v22.m_data, 4 * v21);
  return v20;
}

// File Line: 302
// RVA: 0xBF7D90
void __fastcall hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair>>::clear(
        hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair> > *this)
{
  __int64 m_size; // r8
  __int64 v2; // rdx
  hkIntRealPair *m_data; // rax
  hkIntRealPair *v4; // rax
  hkIntRealPair *v5; // rax
  hkIntRealPair *v6; // rax
  hkIntRealPair *v7; // rax

  m_size = this->m_elem.m_size;
  v2 = 0i64;
  if ( m_size >= 4 )
  {
    do
    {
      m_data = this->m_elem.m_data;
      v2 += 4i64;
      m_data[v2 - 4].m_key = -1;
      *((_DWORD *)&m_data[v2 - 3] - 1) = -1082130432;
      v4 = this->m_elem.m_data;
      v4[v2 - 3].m_key = -1;
      *((_DWORD *)&v4[v2 - 2] - 1) = -1082130432;
      v5 = this->m_elem.m_data;
      v5[v2 - 2].m_key = -1;
      *((_DWORD *)&v5[v2 - 1] - 1) = -1082130432;
      v6 = this->m_elem.m_data;
      v6[v2 - 1].m_key = -1;
      v6[v2 - 1].m_value = -1.0;
    }
    while ( v2 < m_size - 3 );
  }
  for ( ; v2 < m_size; v7[v2 - 1].m_value = -1.0 )
  {
    v7 = this->m_elem.m_data;
    v7[v2++].m_key = -1;
  }
  this->m_numElems = 0;
}

// File Line: 314
// RVA: 0xBF2F60
void __fastcall hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::reserve(
        hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *this,
        int numElements)
{
  int v2; // edx
  int i; // r8d
  hkResult result; // [rsp+38h] [rbp+10h] BYREF

  v2 = 2 * numElements;
  for ( i = 8; i < v2; i *= 2 )
    ;
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::resizeTable(this, &result, i);
}

// File Line: 326
// RVA: 0xBF7FC0
void __fastcall hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair>>::optimizeCapacity(
        hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair> > *this,
        int numFreeElemsLeft)
{
  int CapacityFor; // eax
  hkResult result; // [rsp+38h] [rbp+10h] BYREF

  CapacityFor = hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::getCapacityFor(numFreeElemsLeft + this->m_numElems);
  if ( CapacityFor != (this->m_elem.m_size & 0x7FFFFFFF) )
    hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair>>::resizeTable(
      this,
      &result,
      CapacityFor);
}

// File Line: 338
// RVA: 0xBCCF30
__int64 __fastcall hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::getSizeInBytesFor(
        int numOfKeys)
{
  return (unsigned int)(4
                      * hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::getCapacityFor(numOfKeys));
}

// File Line: 344
// RVA: 0xBF7EF0
__int64 __fastcall hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::getCapacityFor(
        int numOfKeys)
{
  int v1; // ecx
  __int64 result; // rax

  v1 = 2 * numOfKeys;
  result = 8i64;
  if ( v1 > 8 )
  {
    do
      result = (unsigned int)(2 * result);
    while ( (int)result < v1 );
  }
  return result;
}

