// File Line: 33
// RVA: 0xC6E2A0
void __fastcall hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(
        hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator> *this)
{
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *v2; // rax

  v2 = (hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *)(*((__int64 (__fastcall **)(hkContainerHeapAllocator::Allocator *, __int64))&hkContainerHeapAllocator::s_alloc.vfptr->__vecDelDtor + 1))(&hkContainerHeapAllocator::s_alloc, 256i64);
  this->m_numElems = 0;
  this->m_hashMod = 15;
  this->m_elem = v2;
  if ( v2 )
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear((hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)this);
}

// File Line: 149
// RVA: 0xC6E320
void __fastcall hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear(
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *this)
{
  int v1; // eax
  __int64 v2; // r8
  __int64 v3; // rdx

  v1 = this->m_hashMod + 1;
  v2 = v1;
  if ( v1 > 0 )
  {
    v3 = 0i64;
    do
    {
      this->m_elem[v3++].key = -1i64;
      --v2;
    }
    while ( v2 );
  }
  this->m_numElems &= 0x80000000;
}

// File Line: 174
// RVA: 0xC6E2F0
void __fastcall hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(
        hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator> *this)
{
  if ( this->m_numElems >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_elem,
      16 * (this->m_hashMod + 1));
}

// File Line: 184
// RVA: 0xC6E400
void __fastcall hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::insert(
        hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator> *this,
        unsigned __int64 key,
        unsigned __int64 val)
{
  int m_hashMod; // r8d
  int v7; // r8d
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *m_elem; // rdx
  __int64 v9; // rcx
  __int64 v10; // rax
  __int64 v11; // rcx
  hkResult result; // [rsp+30h] [rbp+8h] BYREF

  m_hashMod = this->m_hashMod;
  if ( 2 * this->m_numElems > m_hashMod )
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::resizeTable(
      this,
      &result,
      2 * m_hashMod + 2);
  v7 = this->m_hashMod;
  m_elem = this->m_elem;
  v9 = v7 & (-1640531535 * (unsigned int)(key >> 4));
  if ( this->m_elem[v9].key != -1i64 )
  {
    do
    {
      v10 = v7 & (unsigned int)(v9 + 1);
      v9 = v10;
    }
    while ( m_elem[v10].key != -1i64 );
  }
  ++this->m_numElems;
  v11 = v9;
  m_elem[v11].key = key;
  this->m_elem[v11].val = val;
}

// File Line: 212
// RVA: 0xC6E640
hkResult *__fastcall hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::tryInsert(
        hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator> *this,
        hkResult *result,
        unsigned __int64 key,
        unsigned __int64 val)
{
  int m_hashMod; // r8d
  int v9; // r8d
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *m_elem; // rdx
  __int64 v11; // rcx
  __int64 v12; // rax
  __int64 v13; // rcx
  hkResult resulta; // [rsp+30h] [rbp+8h] BYREF

  m_hashMod = this->m_hashMod;
  if ( 2 * this->m_numElems > m_hashMod
    && (hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::resizeTable(
          this,
          &resulta,
          2 * m_hashMod + 2),
        resulta.m_enum) )
  {
    result->m_enum = HK_FAILURE;
  }
  else
  {
    v9 = this->m_hashMod;
    m_elem = this->m_elem;
    v11 = v9 & (-1640531535 * (unsigned int)(key >> 4));
    if ( this->m_elem[v11].key != -1i64 )
    {
      do
      {
        v12 = v9 & (unsigned int)(v11 + 1);
        v11 = v12;
      }
      while ( m_elem[v12].key != -1i64 );
    }
    ++this->m_numElems;
    v13 = v11;
    result->m_enum = HK_SUCCESS;
    m_elem[v13].key = key;
    this->m_elem[v13].val = val;
  }
  return result;
}

// File Line: 246
// RVA: 0xC6E350
unsigned __int64 __fastcall hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::findKey(
        hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator> *this,
        unsigned __int64 key)
{
  int m_hashMod; // r9d
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *m_elem; // r10
  unsigned __int64 result; // rax
  unsigned __int64 v5; // r8
  unsigned __int64 v6; // rcx

  m_hashMod = this->m_hashMod;
  m_elem = this->m_elem;
  result = m_hashMod & (-1640531535 * (unsigned int)(key >> 4));
  v5 = this->m_elem[result].key;
  if ( v5 == -1i64 )
    return m_hashMod + 1;
  while ( v5 != key )
  {
    v6 = m_hashMod & (unsigned int)(result + 1);
    result = v6;
    v5 = m_elem[v6].key;
    if ( v5 == -1i64 )
      return m_hashMod + 1;
  }
  return result;
}

// File Line: 261
// RVA: 0xC6E3A0
Dummy *__fastcall hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::findKeyWithValue(
        hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator> *this,
        unsigned __int64 key,
        unsigned __int64 val)
{
  int m_hashMod; // r10d
  unsigned int v4; // r9d
  __int64 v5; // rax
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *v6; // rax

  m_hashMod = this->m_hashMod;
  v4 = m_hashMod & (-1640531535 * (key >> 4));
  v5 = v4;
  while ( 1 )
  {
    v6 = &this->m_elem[v5];
    if ( v6->key == -1i64 )
      break;
    if ( v6->key == key && v6->val == val )
      return (Dummy *)v4;
    v5 = m_hashMod & (v4 + 1);
    v4 = m_hashMod & (v4 + 1);
  }
  return (Dummy *)(m_hashMod + 1);
}

// File Line: 416
// RVA: 0xC6E4A0
hkResult *__fastcall hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::remove(
        hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator> *this,
        hkResult *result,
        unsigned __int64 key,
        unsigned __int64 val)
{
  Dummy *KeyWithValue; // rax

  KeyWithValue = hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::findKeyWithValue(
                   this,
                   key,
                   val);
  if ( (int)KeyWithValue > this->m_hashMod )
  {
    result->m_enum = HK_FAILURE;
  }
  else
  {
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::remove(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)this,
      (__int64)KeyWithValue);
    result->m_enum = HK_SUCCESS;
  }
  return result;
}

// File Line: 428
// RVA: 0xC6E500
void __fastcall hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::reserve(
        hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator> *this,
        int numElements)
{
  int i; // r8d
  hkResult result; // [rsp+38h] [rbp+10h] BYREF

  for ( i = 4; i < 3 * numElements; i *= 2 )
    ;
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::resizeTable(
    this,
    &result,
    i);
}

// File Line: 442
// RVA: 0xC6E530
hkResult *__fastcall hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::resizeTable(
        hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator> *this,
        hkResult *result,
        int newcap)
{
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *m_elem; // r15
  __int64 v5; // rbx
  unsigned int v7; // r12d
  int v8; // ebp
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *v9; // rax
  __int64 v10; // rdx
  __int64 v11; // rcx
  __int64 v12; // rdi
  unsigned __int64 *p_key; // rbx

  m_elem = this->m_elem;
  v5 = newcap;
  v7 = this->m_numElems & 0x80000000;
  v8 = this->m_hashMod + 1;
  v9 = (hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *)(*((__int64 (__fastcall **)(hkContainerHeapAllocator::Allocator *, _QWORD))&hkContainerHeapAllocator::s_alloc.vfptr->__vecDelDtor + 1))(&hkContainerHeapAllocator::s_alloc, (unsigned int)(16 * newcap));
  if ( v9 )
  {
    this->m_elem = v9;
    v10 = v5;
    if ( (int)v5 > 0 )
    {
      v11 = 0i64;
      do
      {
        this->m_elem[v11++].key = -1i64;
        --v10;
      }
      while ( v10 );
    }
    this->m_numElems = 0;
    v12 = v8;
    this->m_hashMod = v5 - 1;
    if ( v8 > 0 )
    {
      p_key = &m_elem->key;
      do
      {
        if ( *p_key != -1i64 )
          hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::insert(
            this,
            *p_key,
            p_key[1]);
        p_key += 2;
        --v12;
      }
      while ( v12 );
    }
    if ( !v7 )
      hkContainerHeapAllocator::s_alloc.vfptr->blockFree(&hkContainerHeapAllocator::s_alloc, m_elem, 16 * v8);
    result->m_enum = HK_SUCCESS;
  }
  else
  {
    result->m_enum = HK_FAILURE;
  }
  return result;
}

// File Line: 525
// RVA: 0xC6E3F0
__int64 __fastcall hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::getMemSize(
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *this)
{
  return (unsigned int)(16 * (this->m_hashMod + 1));
}

