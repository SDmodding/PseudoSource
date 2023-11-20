// File Line: 33
// RVA: 0xC6E2A0
void __fastcall hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator> *this)
{
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v1; // rbx
  __int64 v2; // rax

  v1 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)this;
  v2 = (*((__int64 (__fastcall **)(hkContainerHeapAllocator::Allocator *, signed __int64))&hkContainerHeapAllocator::s_alloc.vfptr->__vecDelDtor
        + 1))(
         &hkContainerHeapAllocator::s_alloc,
         256i64);
  v1->m_numElems = 0;
  v1->m_hashMod = 15;
  v1->m_elem = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *)v2;
  if ( v2 )
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear(v1);
}

// File Line: 149
// RVA: 0xC6E320
void __fastcall hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear(hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *this)
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
      ++v3;
      this->m_elem[v3 - 1].key = -1i64;
      --v2;
    }
    while ( v2 );
  }
  this->m_numElems &= 0x80000000;
}

// File Line: 174
// RVA: 0xC6E2F0
void __fastcall hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator> *this)
{
  if ( this->m_numElems >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_elem,
      16 * (this->m_hashMod + 1));
}

// File Line: 184
// RVA: 0xC6E400
void __fastcall hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::insert(hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator> *this, unsigned __int64 key, unsigned __int64 val)
{
  unsigned __int64 v3; // rsi
  int v4; // er8
  unsigned __int64 v5; // rdi
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator> *v6; // rbx
  int v7; // er8
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *v8; // rdx
  signed __int64 v9; // rcx
  __int64 v10; // rax
  signed __int64 v11; // rcx
  hkResult result; // [rsp+30h] [rbp+8h]

  v3 = val;
  v4 = this->m_hashMod;
  v5 = key;
  v6 = this;
  if ( 2 * this->m_numElems > v4 )
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::resizeTable(
      this,
      &result,
      2 * v4 + 2);
  v7 = v6->m_hashMod;
  v8 = v6->m_elem;
  v9 = v7 & -1640531535 * (unsigned int)(v5 >> 4);
  if ( v6->m_elem[v9].key != -1i64 )
  {
    do
    {
      v10 = v7 & (unsigned int)(v9 + 1);
      v9 = v7 & (unsigned int)(v9 + 1);
    }
    while ( v8[v10].key != -1i64 );
  }
  ++v6->m_numElems;
  v11 = v9;
  v8[v11].key = v5;
  v6->m_elem[v11].val = v3;
}

// File Line: 212
// RVA: 0xC6E640
hkResult *__fastcall hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::tryInsert(hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator> *this, hkResult *result, unsigned __int64 key, unsigned __int64 val)
{
  unsigned __int64 v4; // rsi
  int v5; // er8
  unsigned __int64 v6; // rbp
  hkResult *v7; // rdi
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator> *v8; // rbx
  int v9; // er8
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *v10; // rdx
  signed __int64 v11; // rcx
  __int64 v12; // rax
  signed __int64 v13; // rcx
  hkResult resulta; // [rsp+30h] [rbp+8h]

  v4 = key;
  v5 = this->m_hashMod;
  v6 = val;
  v7 = result;
  v8 = this;
  if ( 2 * this->m_numElems > v5
    && (hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::resizeTable(
          this,
          &resulta,
          2 * v5 + 2),
        resulta.m_enum) )
  {
    v7->m_enum = 1;
  }
  else
  {
    v9 = v8->m_hashMod;
    v10 = v8->m_elem;
    v11 = v9 & -1640531535 * (unsigned int)(v4 >> 4);
    if ( v8->m_elem[v11].key != -1i64 )
    {
      do
      {
        v12 = v9 & (unsigned int)(v11 + 1);
        v11 = v9 & (unsigned int)(v11 + 1);
      }
      while ( v10[v12].key != -1i64 );
    }
    ++v8->m_numElems;
    v13 = v11;
    v7->m_enum = 0;
    v10[v13].key = v4;
    v8->m_elem[v13].val = v6;
  }
  return v7;
}

// File Line: 246
// RVA: 0xC6E350
unsigned __int64 __fastcall hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::findKey(hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator> *this, unsigned __int64 key)
{
  int v2; // er9
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *v3; // r10
  unsigned __int64 result; // rax
  unsigned __int64 v5; // r8
  __int64 v6; // rcx

  v2 = this->m_hashMod;
  v3 = this->m_elem;
  result = v2 & -1640531535 * (unsigned int)(key >> 4);
  v5 = this->m_elem[result].key;
  if ( v5 == -1i64 )
    return v2 + 1;
  while ( v5 != key )
  {
    v6 = v2 & (unsigned int)(result + 1);
    result = v2 & (unsigned int)(result + 1);
    v5 = v3[v6].key;
    if ( v5 == -1i64 )
      return v2 + 1;
  }
  return result;
}

// File Line: 261
// RVA: 0xC6E3A0
Dummy *__fastcall hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::findKeyWithValue(hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator> *this, unsigned __int64 key, unsigned __int64 val)
{
  int v3; // er10
  unsigned int v4; // er9
  __int64 v5; // rax
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *v6; // rax

  v3 = this->m_hashMod;
  v4 = v3 & -1640531535 * (key >> 4);
  v5 = v3 & -1640531535 * (unsigned int)(key >> 4);
  while ( 1 )
  {
    v6 = &this->m_elem[v5];
    if ( v6->key == -1i64 )
      break;
    if ( *(_OWORD *)v6 == __PAIR__(val, key) )
      return (Dummy *)v4;
    v5 = v3 & (v4 + 1);
    v4 = v3 & (v4 + 1);
  }
  return (Dummy *)(v3 + 1);
}

// File Line: 416
// RVA: 0xC6E4A0
hkResult *__fastcall hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::remove(hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator> *this, hkResult *result, unsigned __int64 key, unsigned __int64 val)
{
  hkResult *v4; // rbx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v5; // rdi
  Dummy *v6; // rax

  v4 = result;
  v5 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)this;
  v6 = hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::findKeyWithValue(
         this,
         key,
         val);
  if ( (signed int)v6 > v5->m_hashMod )
  {
    v4->m_enum = 1;
  }
  else
  {
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::remove(
      v5,
      v6);
    v4->m_enum = 0;
  }
  return v4;
}

// File Line: 428
// RVA: 0xC6E500
void __fastcall hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::reserve(hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator> *this, int numElements)
{
  int i; // er8
  hkResult result; // [rsp+38h] [rbp+10h]

  for ( i = 4; i < 3 * numElements; i *= 2 )
    ;
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::resizeTable(
    this,
    &result,
    i);
}

// File Line: 442
// RVA: 0xC6E530
hkResult *__fastcall hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::resizeTable(hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator> *this, hkResult *result, int newcap)
{
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *v3; // r15
  hkResult *v4; // r14
  __int64 v5; // rbx
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator> *v6; // rsi
  unsigned int v7; // er12
  int v8; // ebp
  __int64 v9; // rax
  __int64 v10; // rdx
  __int64 v11; // rcx
  __int64 v12; // rdi
  unsigned __int64 *v13; // rbx

  v3 = this->m_elem;
  v4 = result;
  v5 = newcap;
  v6 = this;
  v7 = this->m_numElems & 0x80000000;
  v8 = this->m_hashMod + 1;
  v9 = (*((__int64 (__fastcall **)(hkContainerHeapAllocator::Allocator *, _QWORD))&hkContainerHeapAllocator::s_alloc.vfptr->__vecDelDtor
        + 1))(
         &hkContainerHeapAllocator::s_alloc,
         (unsigned int)(16 * newcap));
  if ( v9 )
  {
    v6->m_elem = (hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *)v9;
    v10 = v5;
    if ( (signed int)v5 > 0 )
    {
      v11 = 0i64;
      do
      {
        ++v11;
        v6->m_elem[v11 - 1].key = -1i64;
        --v10;
      }
      while ( v10 );
    }
    v6->m_numElems = 0;
    v12 = v8;
    v6->m_hashMod = v5 - 1;
    if ( v8 > 0 )
    {
      v13 = &v3->key;
      do
      {
        if ( *v13 != -1i64 )
          hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::insert(
            v6,
            *v13,
            v13[1]);
        v13 += 2;
        --v12;
      }
      while ( v12 );
    }
    if ( !v7 )
      hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v3,
        16 * v8);
    v4->m_enum = 0;
  }
  else
  {
    v4->m_enum = 1;
  }
  return v4;
}

// File Line: 525
// RVA: 0xC6E3F0
__int64 __fastcall hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::getMemSize(hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *this)
{
  return (unsigned int)(16 * (this->m_hashMod + 1));
}

