// File Line: 34
// RVA: 0x1306BF0
void __fastcall hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>(hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *this, hkStringMapOperations ops)
{
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *v2; // rbx
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::Elem *v3; // rax

  v2 = this;
  v3 = (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::Elem *)(*((__int64 (__fastcall **)(hkMemoryAllocator *, signed __int64))&hkDefaultMemoryTrackerAllocator::s_allocator->vfptr->__vecDelDtor
                                                                                        + 1))(
                                                                                         hkDefaultMemoryTrackerAllocator::s_allocator,
                                                                                         384i64);
  v2->m_elem = v3;
  hkString::memSet(v3, 255, 384);
  v2->m_numElems = 0;
  v2->m_hashMod = 15;
}

// File Line: 45
// RVA: 0xC61530
void __fastcall hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *this)
{
  hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
    this->m_elem,
    24 * (this->m_hashMod + 1));
}

// File Line: 70
// RVA: 0x1306D40
Dummy *__fastcall hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator(hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *this)
{
  __int64 v1; // r8
  Dummy *result; // rax
  __int64 v3; // rdx
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::Elem *v4; // rcx

  v1 = this->m_hashMod;
  LODWORD(result) = 0;
  v3 = 0i64;
  if ( v1 >= 0 )
  {
    v4 = this->m_elem;
    do
    {
      if ( v4->hash != -1i64 )
        break;
      ++v3;
      LODWORD(result) = (_DWORD)result + 1;
      ++v4;
    }
    while ( v3 <= v1 );
  }
  return (Dummy *)(signed int)result;
}

// File Line: 84
// RVA: 0xC61800
unsigned __int64 __fastcall hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *this, Dummy *it)
{
  return this->m_elem[(signed int)it].key;
}

// File Line: 92
// RVA: 0x1306D70
unsigned __int64 __fastcall hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *this, Dummy *it)
{
  return this->m_elem[(signed int)it].value;
}

// File Line: 100
// RVA: 0xC61C70
void __fastcall hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::setValue(hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *this, Dummy *it, unsigned __int64 val)
{
  this->m_elem[(signed int)it].value = val;
}

// File Line: 108
// RVA: 0xC61810
Dummy *__fastcall hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *this, Dummy *it)
{
  __int64 v2; // r10
  int v3; // er9
  __int64 v4; // rax
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::Elem *v5; // r8

  v2 = this->m_hashMod;
  v3 = (_DWORD)it + 1;
  v4 = (signed int)it + 1;
  if ( v4 <= v2 )
  {
    v5 = &this->m_elem[v3];
    do
    {
      if ( v5->hash != -1i64 )
        break;
      ++v4;
      ++v3;
      ++v5;
    }
    while ( v4 <= v2 );
  }
  return (Dummy *)v3;
}

// File Line: 124
// RVA: 0x1306E90
hkBool *__fastcall hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *this, hkBool *result, Dummy *it)
{
  result->m_bool = (signed int)it <= this->m_hashMod;
  return result;
}

// File Line: 132
// RVA: 0x1306D80
void __fastcall hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::insert(hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *this, unsigned __int64 key, unsigned __int64 val)
{
  char v3; // al
  signed __int64 v4; // rbx
  unsigned __int64 v5; // rbp
  const char *v6; // r14
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *v7; // rdi
  char *v8; // rcx
  int v9; // edx
  signed __int64 v10; // rbx
  unsigned __int64 v11; // rsi
  signed __int64 v12; // rcx
  signed __int64 v13; // rcx

  v3 = *(_BYTE *)key;
  v4 = 0i64;
  v5 = val;
  v6 = (const char *)key;
  v7 = this;
  if ( *(_BYTE *)key )
  {
    v8 = (char *)key;
    do
    {
      ++v8;
      v4 = v3 + 31 * v4;
      v3 = *v8;
    }
    while ( *v8 );
  }
  v9 = v7->m_hashMod;
  v10 = v4 & 0x7FFFFFFFFFFFFFFFi64;
  if ( 2 * v7->m_numElems > v9 )
    hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::resizeTable(v7, 2 * v9 + 2);
  v11 = v10 & v7->m_hashMod;
  v12 = v11;
  if ( v7->m_elem[v11].hash == -1i64 )
  {
LABEL_10:
    ++v7->m_numElems;
  }
  else
  {
    while ( v7->m_elem[v12].hash != v10 || (unsigned int)hkString::strCmp(v6, (const char *)v7->m_elem[v12].key) )
    {
      v11 = v7->m_hashMod & (v11 + 1);
      v12 = v11;
      if ( v7->m_elem[v11].hash == -1i64 )
        goto LABEL_10;
    }
  }
  v13 = v11;
  v7->m_elem[v13].hash = v10;
  v7->m_elem[v13].key = (unsigned __int64)v6;
  v7->m_elem[v13].value = v5;
}

// File Line: 167
// RVA: 0xC615A0
Dummy *__fastcall hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *this, unsigned __int64 key)
{
  char v2; // al
  signed __int64 v3; // rbx
  const char *v4; // r14
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *v5; // rsi
  char *v6; // r8
  signed __int64 v7; // rbx
  unsigned __int64 v8; // rdi
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::Elem *v9; // rdx
  unsigned __int64 v10; // rax

  v2 = *(_BYTE *)key;
  v3 = 0i64;
  v4 = (const char *)key;
  v5 = this;
  if ( *(_BYTE *)key )
  {
    v6 = (char *)key;
    do
    {
      ++v6;
      v3 = v2 + 31 * v3;
      v2 = *v6;
    }
    while ( *v6 );
  }
  v7 = v3 & 0x7FFFFFFFFFFFFFFFi64;
  v8 = v7 & this->m_hashMod;
  v9 = &this->m_elem[v8];
  v10 = v9->hash;
  if ( v10 == -1i64 )
    return (Dummy *)(v5->m_hashMod + 1);
  while ( v10 != v7 || (unsigned int)hkString::strCmp(v4, (const char *)v9->key) )
  {
    v8 = v5->m_hashMod & (v8 + 1);
    v9 = &v5->m_elem[v8];
    v10 = v9->hash;
    if ( v10 == -1i64 )
      return (Dummy *)(v5->m_hashMod + 1);
  }
  return (Dummy *)v8;
}

// File Line: 183
// RVA: 0xC61670
Dummy *__fastcall hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::findOrInsertKey(hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *this, unsigned __int64 key, unsigned __int64 value)
{
  const char *v3; // r15
  int v4; // edx
  unsigned __int64 v5; // rbp
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *v6; // rdi
  char v7; // al
  signed __int64 v8; // rsi
  char *v9; // rcx
  signed __int64 v10; // rsi
  unsigned __int64 i; // rbx
  signed __int64 v12; // r14
  signed __int64 v13; // rcx

  v3 = (const char *)key;
  v4 = this->m_hashMod;
  v5 = value;
  v6 = this;
  if ( 2 * this->m_numElems > v4 )
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::resizeTable(this, 2 * v4 + 2);
  v7 = *v3;
  v8 = 0i64;
  if ( *v3 )
  {
    v9 = (char *)v3;
    do
    {
      ++v9;
      v8 = v7 + 31 * v8;
      v7 = *v9;
    }
    while ( *v9 );
  }
  v10 = v8 & 0x7FFFFFFFFFFFFFFFi64;
  for ( i = v10 & v6->m_hashMod; ; i = v6->m_hashMod & (i + 1) )
  {
    v12 = i;
    if ( v6->m_elem[i].hash == v10 && !(unsigned int)hkString::strCmp(v3, (const char *)v6->m_elem[v12].key) )
      break;
    if ( v6->m_elem[v12].hash == -1i64 )
    {
      v13 = i;
      v6->m_elem[v13].hash = v10;
      v6->m_elem[v13].key = (unsigned __int64)v3;
      v6->m_elem[v13].value = v5;
      ++v6->m_numElems;
      return (Dummy *)i;
    }
  }
  return (Dummy *)i;
}

// File Line: 213
// RVA: 0xC61770
hkResult *__fastcall hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::get(hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *this, hkResult *result, unsigned __int64 key, unsigned __int64 *out)
{
  hkResult *v4; // rbx
  unsigned __int64 *v5; // r14
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *v6; // rdi
  Dummy *v7; // rsi
  unsigned __int64 v8; // rax
  hkBool resulta; // [rsp+20h] [rbp-18h]

  v4 = result;
  v5 = out;
  v6 = this;
  v7 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(this, key);
  if ( hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(v6, &resulta, v7)->m_bool )
  {
    v8 = hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(v6, v7);
    v4->m_enum = 0;
    *v5 = v8;
  }
  else
  {
    v4->m_enum = 1;
  }
  return v4;
}

// File Line: 225
// RVA: 0xC61850
unsigned __int64 __fastcall hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getOrInsert(hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *this, unsigned __int64 key, unsigned __int64 ifNotFound)
{
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // rsi
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *v5; // rbx
  Dummy *v6; // rbp
  hkBool result; // [rsp+48h] [rbp+20h]

  v3 = ifNotFound;
  v4 = key;
  v5 = this;
  v6 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(
         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)this,
         key);
  if ( hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)v5,
         &result,
         v6)->m_bool )
    return hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
             (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)v5,
             v6);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(v5, v4, v3);
  return v3;
}

// File Line: 238
// RVA: 0xC618C0
unsigned __int64 __fastcall hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *this, unsigned __int64 key, unsigned __int64 def)
{
  hkResult result; // [rsp+40h] [rbp+18h]
  unsigned __int64 out; // [rsp+48h] [rbp+20h]

  out = def;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::get(this, &result, key, &out);
  return out;
}

// File Line: 246
// RVA: 0xC61A80
void __fastcall hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::remove(hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *this, Dummy *it)
{
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::Elem *v2; // rax
  __int64 v3; // r9
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::Elem *v4; // rdi
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *v5; // r10
  unsigned __int64 v6; // r8
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rbx
  signed __int64 v9; // r11
  unsigned __int64 v10; // rcx
  signed __int64 v11; // r8

  v2 = this->m_elem;
  --this->m_numElems;
  v2[(_QWORD)it].hash = -1i64;
  v3 = this->m_hashMod;
  v4 = this->m_elem;
  v5 = this;
  v6 = v3 & ((unsigned __int64)it + v3);
  if ( this->m_elem[v6].hash != -1i64 )
  {
    do
      v6 = v3 & (v3 + v6);
    while ( v4[v6].hash != -1i64 );
  }
  v7 = v3 & ((unsigned __int64)it + 1);
  v8 = v3 & (v6 + 1);
  v9 = v7;
  if ( v4[v7].hash != -1i64 )
  {
    do
    {
      v10 = v3 & v5->m_elem[v9].hash;
      if ( (v7 < v8 || v10 <= (unsigned __int64)it)
        && (v7 >= (unsigned __int64)it || v10 <= (unsigned __int64)it && v10 > v7)
        && (v10 <= (unsigned __int64)it || v10 >= v8) )
      {
        v11 = (signed __int64)it;
        v5->m_elem[v11].hash = v5->m_elem[v9].hash;
        v5->m_elem[v11].key = v5->m_elem[v9].key;
        v5->m_elem[v11].value = v5->m_elem[v9].value;
        it = (Dummy *)v7;
        v5->m_elem[v9].hash = -1i64;
      }
      v3 = v5->m_hashMod;
      v7 = v3 & (v7 + 1);
      v9 = v7;
    }
    while ( v5->m_elem[v7].hash != -1i64 );
  }
}

// File Line: 312
// RVA: 0xC61A00
hkResult *__fastcall hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::remove(hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *this, hkResult *result, unsigned __int64 key)
{
  hkResult *v3; // rbx
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *v4; // rdi
  Dummy *v5; // rsi
  hkBool resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = this;
  v5 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(
         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)this,
         key);
  if ( hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)v4,
         &resulta,
         v5)->m_bool )
  {
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::remove(v4, v5);
    v3->m_enum = 0;
  }
  else
  {
    v3->m_enum = 1;
  }
  return v3;
}

// File Line: 324
// RVA: 0x1306EA0
void __fastcall hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::resizeTable(hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *this, int newcap)
{
  hkMemoryAllocator *v2; // r15
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::Elem *v3; // rbp
  int v4; // edi
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *v5; // rsi
  int v6; // ebx
  int v7; // er14
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::Elem *v8; // rax
  __int64 v9; // rdi
  unsigned __int64 *v10; // rbx

  v2 = hkDefaultMemoryTrackerAllocator::s_allocator;
  v3 = this->m_elem;
  v4 = newcap;
  v5 = this;
  v6 = 24 * newcap;
  v7 = this->m_hashMod + 1;
  v8 = (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::Elem *)(*((__int64 (__fastcall **)(hkMemoryAllocator *, _QWORD))&hkDefaultMemoryTrackerAllocator::s_allocator->vfptr->__vecDelDtor
                                                                                        + 1))(
                                                                                         hkDefaultMemoryTrackerAllocator::s_allocator,
                                                                                         (unsigned int)(24 * newcap));
  v5->m_elem = v8;
  hkString::memSet(v8, 255, v6);
  v5->m_numElems = 0;
  v5->m_hashMod = v4 - 1;
  v9 = v7;
  if ( v7 > 0 )
  {
    v10 = &v3->key;
    do
    {
      if ( *(v10 - 1) != -1i64 )
        hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::insert(v5, *v10, v10[1]);
      v10 += 3;
      --v9;
    }
    while ( v9 );
  }
  v2->vfptr->blockFree(v2, v3, 24 * v7);
}

// File Line: 379
// RVA: 0xC61560
void __fastcall hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::clear(hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *this)
{
  int v1; // er8
  __int64 v2; // rdx

  v1 = 0;
  if ( this->m_hashMod + 1 > 0 )
  {
    v2 = 0i64;
    do
    {
      ++v1;
      ++v2;
      this->m_elem[v2 - 1].hash = -1i64;
    }
    while ( v1 < this->m_hashMod + 1 );
  }
  this->m_numElems = 0;
}

// File Line: 389
// RVA: 0x1306F60
void __fastcall hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::swap(hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *this, hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *other)
{
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::Elem *v2; // r10
  int v3; // er9
  int v4; // er8

  v2 = this->m_elem;
  v3 = this->m_numElems;
  v4 = this->m_hashMod;
  this->m_elem = other->m_elem;
  this->m_numElems = other->m_numElems;
  this->m_hashMod = other->m_hashMod;
  other->m_elem = v2;
  other->m_numElems = v3;
  other->m_hashMod = v4;
}

// File Line: 418
// RVA: 0xC617F0
__int64 __fastcall hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getCapacity(hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *this)
{
  return (unsigned int)(this->m_hashMod + 1);
}

