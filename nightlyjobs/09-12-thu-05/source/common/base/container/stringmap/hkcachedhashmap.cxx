// File Line: 34
// RVA: 0x1306BF0
void __fastcall hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>(
        hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *this,
        hkStringMapOperations ops)
{
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::Elem *v3; // rax

  v3 = (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::Elem *)(*((__int64 (__fastcall **)(hkMemoryAllocator *, __int64))&hkDefaultMemoryTrackerAllocator::s_allocator->vfptr->__vecDelDtor
                                                                                        + 1))(
                                                                                         hkDefaultMemoryTrackerAllocator::s_allocator,
                                                                                         384i64);
  this->m_elem = v3;
  hkString::memSet(v3, 255, 0x180u);
  this->m_numElems = 0;
  this->m_hashMod = 15;
}

// File Line: 45
// RVA: 0xC61530
void __fastcall hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
        hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *this)
{
  hkContainerHeapAllocator::s_alloc.vfptr->blockFree(
    &hkContainerHeapAllocator::s_alloc,
    this->m_elem,
    24 * (this->m_hashMod + 1));
}

// File Line: 70
// RVA: 0x1306D40
Dummy *__fastcall hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator(
        hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *this)
{
  __int64 m_hashMod; // r8
  Dummy *result; // rax
  __int64 v3; // rdx
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::Elem *m_elem; // rcx

  m_hashMod = this->m_hashMod;
  LODWORD(result) = 0;
  v3 = 0i64;
  if ( m_hashMod >= 0 )
  {
    m_elem = this->m_elem;
    do
    {
      if ( m_elem->hash != -1i64 )
        break;
      ++v3;
      LODWORD(result) = (_DWORD)result + 1;
      ++m_elem;
    }
    while ( v3 <= m_hashMod );
  }
  return (Dummy *)(int)result;
}

// File Line: 84
// RVA: 0xC61800
unsigned __int64 __fastcall hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(
        hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *this,
        Dummy *it)
{
  return this->m_elem[(int)it].key;
}

// File Line: 92
// RVA: 0x1306D70
unsigned __int64 __fastcall hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
        hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *this,
        Dummy *it)
{
  return this->m_elem[(int)it].value;
}

// File Line: 100
// RVA: 0xC61C70
void __fastcall hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::setValue(
        hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *this,
        Dummy *it,
        unsigned __int64 val)
{
  this->m_elem[(int)it].value = val;
}

// File Line: 108
// RVA: 0xC61810
Dummy *__fastcall hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(
        hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *this,
        Dummy *it)
{
  __int64 m_hashMod; // r10
  int v3; // r9d
  __int64 v4; // rax
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::Elem *v5; // r8

  m_hashMod = this->m_hashMod;
  v3 = (_DWORD)it + 1;
  v4 = (int)it + 1;
  if ( v4 <= m_hashMod )
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
    while ( v4 <= m_hashMod );
  }
  return (Dummy *)v3;
}

// File Line: 124
// RVA: 0x1306E90
hkBool *__fastcall hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
        hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *this,
        hkBool *result,
        Dummy *it)
{
  result->m_bool = (int)it <= this->m_hashMod;
  return result;
}

// File Line: 132
// RVA: 0x1306D80
void __fastcall hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::insert(
        hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *this,
        const char *key,
        unsigned __int64 val)
{
  char v3; // al
  __int64 v4; // rbx
  const char *v8; // rcx
  int m_hashMod; // edx
  __int64 v10; // rbx
  unsigned __int64 v11; // rsi
  unsigned __int64 v12; // rcx
  unsigned __int64 v13; // rcx

  v3 = *key;
  v4 = 0i64;
  if ( *key )
  {
    v8 = key;
    do
    {
      ++v8;
      v4 = v3 + 31 * v4;
      v3 = *v8;
    }
    while ( *v8 );
  }
  m_hashMod = this->m_hashMod;
  v10 = v4 & 0x7FFFFFFFFFFFFFFFi64;
  if ( 2 * this->m_numElems > m_hashMod )
    hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::resizeTable(this, 2 * m_hashMod + 2);
  v11 = v10 & this->m_hashMod;
  v12 = v11;
  if ( this->m_elem[v11].hash == -1i64 )
  {
LABEL_10:
    ++this->m_numElems;
  }
  else
  {
    while ( this->m_elem[v12].hash != v10 || (unsigned int)hkString::strCmp(key, (const char *)this->m_elem[v12].key) )
    {
      v11 = this->m_hashMod & (v11 + 1);
      v12 = v11;
      if ( this->m_elem[v11].hash == -1i64 )
        goto LABEL_10;
    }
  }
  v13 = v11;
  this->m_elem[v13].hash = v10;
  this->m_elem[v13].key = (unsigned __int64)key;
  this->m_elem[v13].value = val;
}

// File Line: 167
// RVA: 0xC615A0
Dummy *__fastcall hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(
        hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *this,
        const char *key)
{
  char v2; // al
  __int64 v3; // rbx
  const char *v6; // r8
  __int64 v7; // rbx
  unsigned __int64 v8; // rdi
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::Elem *v9; // rdx
  unsigned __int64 hash; // rax

  v2 = *key;
  v3 = 0i64;
  if ( *key )
  {
    v6 = key;
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
  hash = v9->hash;
  if ( v9->hash == -1i64 )
    return (Dummy *)(this->m_hashMod + 1);
  while ( hash != v7 || (unsigned int)hkString::strCmp(key, (const char *)v9->key) )
  {
    v8 = this->m_hashMod & (v8 + 1);
    v9 = &this->m_elem[v8];
    hash = v9->hash;
    if ( v9->hash == -1i64 )
      return (Dummy *)(this->m_hashMod + 1);
  }
  return (Dummy *)v8;
}

// File Line: 183
// RVA: 0xC61670
Dummy *__fastcall hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::findOrInsertKey(
        hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *this,
        const char *key,
        unsigned __int64 value)
{
  int m_hashMod; // edx
  char v7; // al
  __int64 v8; // rsi
  const char *v9; // rcx
  __int64 v10; // rsi
  unsigned __int64 i; // rbx
  unsigned __int64 v12; // r14
  unsigned __int64 v13; // rcx

  m_hashMod = this->m_hashMod;
  if ( 2 * this->m_numElems > m_hashMod )
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::resizeTable(this, 2 * m_hashMod + 2);
  v7 = *key;
  v8 = 0i64;
  if ( *key )
  {
    v9 = key;
    do
    {
      ++v9;
      v8 = v7 + 31 * v8;
      v7 = *v9;
    }
    while ( *v9 );
  }
  v10 = v8 & 0x7FFFFFFFFFFFFFFFi64;
  for ( i = v10 & this->m_hashMod; ; i = this->m_hashMod & (i + 1) )
  {
    v12 = i;
    if ( this->m_elem[i].hash == v10 && !(unsigned int)hkString::strCmp(key, (const char *)this->m_elem[v12].key) )
      break;
    if ( this->m_elem[v12].hash == -1i64 )
    {
      v13 = i;
      this->m_elem[v13].hash = v10;
      this->m_elem[v13].key = (unsigned __int64)key;
      this->m_elem[v13].value = value;
      ++this->m_numElems;
      return (Dummy *)i;
    }
  }
  return (Dummy *)i;
}

// File Line: 213
// RVA: 0xC61770
hkResult *__fastcall hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::get(
        hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *this,
        hkResult *result,
        const char *key,
        unsigned __int64 *out)
{
  Dummy *v7; // rsi
  unsigned __int64 Value; // rax
  hkBool resulta; // [rsp+20h] [rbp-18h] BYREF

  v7 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(this, key);
  if ( hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(this, &resulta, v7)->m_bool )
  {
    Value = hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(this, v7);
    result->m_enum = HK_SUCCESS;
    *out = Value;
  }
  else
  {
    result->m_enum = HK_FAILURE;
  }
  return result;
}

// File Line: 225
// RVA: 0xC61850
unsigned __int64 __fastcall hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getOrInsert(
        hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *this,
        const char *key,
        unsigned __int64 ifNotFound)
{
  Dummy *v6; // rbp
  hkBool result; // [rsp+48h] [rbp+20h] BYREF

  v6 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(
         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)this,
         key);
  if ( hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)this,
         &result,
         v6)->m_bool )
    return hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
             (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)this,
             v6);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(this, (unsigned __int64)key, ifNotFound);
  return ifNotFound;
}

// File Line: 238
// RVA: 0xC618C0
unsigned __int64 __fastcall hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
        hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *this,
        const char *key,
        unsigned __int64 def)
{
  hkResult result; // [rsp+40h] [rbp+18h] BYREF
  unsigned __int64 out; // [rsp+48h] [rbp+20h] BYREF

  out = def;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::get(this, &result, key, &out);
  return out;
}

// File Line: 246
// RVA: 0xC61A80
void __fastcall hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::remove(
        hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *this,
        unsigned __int64 it)
{
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::Elem *m_elem; // rax
  __int64 m_hashMod; // r9
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::Elem *v4; // rdi
  unsigned __int64 v6; // r8
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rbx
  unsigned __int64 v9; // r11
  unsigned __int64 v10; // rcx
  unsigned __int64 v11; // r8

  m_elem = this->m_elem;
  --this->m_numElems;
  m_elem[it].hash = -1i64;
  m_hashMod = this->m_hashMod;
  v4 = this->m_elem;
  v6 = m_hashMod & (m_hashMod + it);
  if ( this->m_elem[v6].hash != -1i64 )
  {
    do
      v6 = m_hashMod & (m_hashMod + v6);
    while ( v4[v6].hash != -1i64 );
  }
  v7 = m_hashMod & (it + 1);
  v8 = m_hashMod & (v6 + 1);
  v9 = v7;
  if ( v4[v7].hash != -1i64 )
  {
    do
    {
      v10 = m_hashMod & this->m_elem[v9].hash;
      if ( (v7 < v8 || v10 <= it) && (v7 >= it || v10 <= it && v10 > v7) && (v10 <= it || v10 >= v8) )
      {
        v11 = it;
        this->m_elem[v11].hash = this->m_elem[v9].hash;
        this->m_elem[v11].key = this->m_elem[v9].key;
        this->m_elem[v11].value = this->m_elem[v9].value;
        it = v7;
        this->m_elem[v9].hash = -1i64;
      }
      m_hashMod = this->m_hashMod;
      v7 = m_hashMod & (v7 + 1);
      v9 = v7;
    }
    while ( this->m_elem[v7].hash != -1i64 );
  }
}

// File Line: 312
// RVA: 0xC61A00
hkResult *__fastcall hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::remove(
        hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *this,
        hkResult *result,
        const char *key)
{
  Dummy *v5; // rsi
  hkBool resulta; // [rsp+48h] [rbp+20h] BYREF

  v5 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(
         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)this,
         key);
  if ( hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)this,
         &resulta,
         v5)->m_bool )
  {
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::remove(this, v5);
    result->m_enum = HK_SUCCESS;
  }
  else
  {
    result->m_enum = HK_FAILURE;
  }
  return result;
}

// File Line: 324
// RVA: 0x1306EA0
void __fastcall hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::resizeTable(
        hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *this,
        int newcap)
{
  hkMemoryAllocator *v2; // r15
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::Elem *m_elem; // rbp
  unsigned int v6; // ebx
  int v7; // r14d
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::Elem *v8; // rax
  __int64 v9; // rdi
  unsigned __int64 *p_key; // rbx

  v2 = hkDefaultMemoryTrackerAllocator::s_allocator;
  m_elem = this->m_elem;
  v6 = 24 * newcap;
  v7 = this->m_hashMod + 1;
  v8 = (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::Elem *)(*((__int64 (__fastcall **)(hkMemoryAllocator *, _QWORD))&hkDefaultMemoryTrackerAllocator::s_allocator->vfptr->__vecDelDtor
                                                                                        + 1))(
                                                                                         hkDefaultMemoryTrackerAllocator::s_allocator,
                                                                                         (unsigned int)(24 * newcap));
  this->m_elem = v8;
  hkString::memSet(v8, 255, v6);
  this->m_numElems = 0;
  this->m_hashMod = newcap - 1;
  v9 = v7;
  if ( v7 > 0 )
  {
    p_key = &m_elem->key;
    do
    {
      if ( *(p_key - 1) != -1i64 )
        hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::insert(
          this,
          (const char *)*p_key,
          p_key[1]);
      p_key += 3;
      --v9;
    }
    while ( v9 );
  }
  v2->vfptr->blockFree(v2, m_elem, 24 * v7);
}

// File Line: 379
// RVA: 0xC61560
void __fastcall hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::clear(
        hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *this)
{
  int v1; // r8d
  __int64 v2; // rdx

  v1 = 0;
  if ( this->m_hashMod + 1 > 0 )
  {
    v2 = 0i64;
    do
    {
      ++v1;
      this->m_elem[v2++].hash = -1i64;
    }
    while ( v1 < this->m_hashMod + 1 );
  }
  this->m_numElems = 0;
}

// File Line: 389
// RVA: 0x1306F60
void __fastcall hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::swap(
        hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *this,
        hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *other)
{
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::Elem *m_elem; // r10
  int m_numElems; // r9d
  int m_hashMod; // r8d

  m_elem = this->m_elem;
  m_numElems = this->m_numElems;
  m_hashMod = this->m_hashMod;
  *this = *other;
  other->m_elem = m_elem;
  other->m_numElems = m_numElems;
  other->m_hashMod = m_hashMod;
}

// File Line: 418
// RVA: 0xC617F0
__int64 __fastcall hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getCapacity(
        hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *this)
{
  return (unsigned int)(this->m_hashMod + 1);
}

