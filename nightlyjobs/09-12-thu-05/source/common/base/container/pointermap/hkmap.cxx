// File Line: 33
// RVA: 0xC608D0
void __fastcall hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>(
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *this,
        void *ptr,
        int sizeInBytes)
{
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::init(this, ptr, sizeInBytes);
}

// File Line: 39
// RVA: 0xC60A40
void __fastcall hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::init(
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *this,
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *ptr,
        unsigned int sizeInBytes)
{
  signed int v3; // r8d
  __int64 v4; // rdx
  __int64 v5; // rax

  v3 = sizeInBytes >> 4;
  this->m_elem = ptr;
  this->m_numElems = 0x80000000;
  v4 = (unsigned int)v3;
  this->m_hashMod = v3 - 1;
  if ( v3 > 0 )
  {
    v5 = 0i64;
    do
    {
      this->m_elem[v5++].key = -1i64;
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 56
// RVA: 0xDF2620
void __fastcall hkMapBase<`anonymous namespace::MapKey32,int,A0x59affef2::MapOperationsMapKey32>::clear(
        hkMapBase<MapKey32,int,A0x59affef2::MapOperationsMapKey32> *this)
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
      this->m_elem[v3++].key.m_isValid.m_bool = 0;
      --v2;
    }
    while ( v2 );
  }
  this->m_numElems &= 0x80000000;
}

// File Line: 67
// RVA: 0xE4A100
void __fastcall hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle>>::clearAndDeallocate(
        hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle> > *this,
        hkMemoryAllocator *alloc)
{
  hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle>>::clear(this);
  if ( this->m_numElems >= 0 )
    alloc->vfptr->blockFree(alloc, this->m_elem, 40 * (this->m_hashMod + 1));
  this->m_hashMod = -1;
  this->m_elem = 0i64;
  this->m_numElems = 0;
}

// File Line: 87
// RVA: 0xD50940
__int64 __fastcall hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::insert(
        hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations> *this,
        hkMemoryAllocator *alloc,
        hkpPairCollisionFilter::PairFilterKey *key,
        unsigned __int64 val)
{
  int m_hashMod; // r9d
  hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::Pair *m_elem; // r9
  unsigned int v9; // r10d
  unsigned int i; // edx
  unsigned __int64 v11; // rdx
  unsigned __int64 v12; // rdx
  __int64 v13; // rax
  hkResult result; // [rsp+60h] [rbp+8h] BYREF

  m_hashMod = this->m_hashMod;
  if ( 2 * this->m_numElems > m_hashMod )
    hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::resizeTable(
      this,
      &result,
      alloc,
      2 * m_hashMod + 2);
  m_elem = this->m_elem;
  v9 = 1;
  for ( i = -1640531535 * (((unsigned __int64)key->m_b + 0x10000000 * (__int64)key->m_a) >> 4); ; i = v11 + 1 )
  {
    v11 = this->m_hashMod & i;
    if ( !m_elem[v11].key.m_a || !m_elem[v11].key.m_b )
      break;
    if ( m_elem[v11].key.m_a == key->m_a && m_elem[v11].key.m_b == key->m_b )
    {
      v9 = 0;
      break;
    }
  }
  this->m_numElems += v9;
  v12 = v11;
  m_elem[v12].key.m_a = key->m_a;
  m_elem[v12].key.m_b = key->m_b;
  v13 = v9;
  this->m_elem[v12].val = val;
  return v13;
}

// File Line: 124
// RVA: 0xC60BD0
__int64 __fastcall hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::tryInsert(
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *this,
        hkMemoryAllocator *alloc,
        unsigned __int64 key,
        unsigned __int64 val,
        hkResult *res)
{
  int m_hashMod; // r9d
  hkResult *v10; // rax
  hkResultEnum m_enum; // ecx
  hkResult result; // [rsp+30h] [rbp+8h] BYREF

  m_hashMod = this->m_hashMod;
  if ( 2 * this->m_numElems <= m_hashMod )
  {
    res->m_enum = HK_SUCCESS;
  }
  else
  {
    v10 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::resizeTable(
            this,
            &result,
            alloc,
            2 * m_hashMod + 2);
    m_enum = v10->m_enum;
    res->m_enum = v10->m_enum;
    if ( m_enum )
      return 0i64;
  }
  return hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(this, alloc, key, val);
}

// File Line: 149
// RVA: 0xC60230
Dummy *__fastcall hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64>>::findKey(
        hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> > *this,
        unsigned __int64 key)
{
  int m_hashMod; // r9d
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *m_elem; // r10
  unsigned int v4; // r8d
  unsigned __int64 v5; // rcx

  m_hashMod = this->m_hashMod;
  if ( m_hashMod <= 0 )
    return (Dummy *)(m_hashMod + 1);
  m_elem = this->m_elem;
  v4 = m_hashMod & (-1640531535 * (key >> 4));
  v5 = this->m_elem[(unsigned __int64)v4].key;
  if ( v5 == -1i64 )
    return (Dummy *)(m_hashMod + 1);
  while ( v5 != key )
  {
    v4 = m_hashMod & (v4 + 1);
    v5 = m_elem[(unsigned __int64)v4].key;
    if ( v5 == -1i64 )
      return (Dummy *)(m_hashMod + 1);
  }
  return (Dummy *)v4;
}

// File Line: 167
// RVA: 0xC60290
unsigned __int64 __fastcall hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findOrInsertKey(
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *this,
        hkMemoryAllocator *alloc,
        unsigned __int64 key,
        unsigned __int64 val)
{
  int m_hashMod; // r9d
  int v8; // r9d
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *m_elem; // r8
  unsigned int v10; // ecx
  unsigned __int64 v11; // rdx
  unsigned __int64 v12; // rax
  __int64 v13; // rdx
  hkResult result; // [rsp+30h] [rbp+8h] BYREF

  m_hashMod = this->m_hashMod;
  if ( 2 * this->m_numElems > m_hashMod )
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::resizeTable(
      this,
      &result,
      alloc,
      2 * m_hashMod + 2);
  v8 = this->m_hashMod;
  m_elem = this->m_elem;
  v10 = v8 & (-1640531535 * (key >> 4));
  v11 = this->m_elem[v10].key;
  if ( v11 == key )
    return v10;
  while ( v11 != -1i64 )
  {
    v10 = v8 & (v10 + 1);
    v11 = m_elem[v10].key;
    if ( v11 == key )
      return v10;
  }
  v12 = v10;
  v13 = v10;
  m_elem[v13].key = key;
  this->m_elem[v13].val = val;
  ++this->m_numElems;
  return v12;
}

// File Line: 200
// RVA: 0xC60950
hkResult *__fastcall hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::get(
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *this,
        hkResult *result,
        unsigned __int64 key,
        unsigned __int64 *out)
{
  int v7; // eax
  __int64 v8; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *m_elem; // rax
  unsigned __int64 val; // rcx
  hkResult *v11; // rax

  v7 = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(this, key);
  if ( v7 > this->m_hashMod )
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
  else
  {
    v8 = v7;
    m_elem = this->m_elem;
    result->m_enum = HK_SUCCESS;
    val = m_elem[v8].val;
    v11 = result;
    *out = val;
  }
  return v11;
}

// File Line: 212
// RVA: 0xE4A9C0
__int64 __fastcall hkMapBase<hkDataObject_Handle,int,`anonymous namespace::HandleOps>::getWithDefault(
        hkMapBase<hkDataObject_Handle,int,HandleOps> *this,
        hkDataObject_Handle *key,
        unsigned int def)
{
  int m_hashMod; // r11d
  void *p0; // rbx
  hkMapBase<hkDataObject_Handle,int,HandleOps>::Pair *m_elem; // r8
  __int64 v8; // r9
  hkMapBase<hkDataObject_Handle,int,HandleOps>::Pair *v9; // rdx
  __int64 v10; // rax

  m_hashMod = this->m_hashMod;
  if ( m_hashMod <= 0 )
    return def;
  p0 = key->p0;
  m_elem = this->m_elem;
  v8 = m_hashMod & (-1640531535 * (unsigned int)((unsigned __int64)key->p0 >> 4));
  v9 = &this->m_elem[v8];
  if ( v9->key.p0 == (void *)-1i64 )
    return def;
  while ( v9->key.p0 != p0 || v9->key.p1 != key->p1 )
  {
    v10 = m_hashMod & (unsigned int)(v8 + 1);
    v8 = v10;
    v9 = &m_elem[v10];
    if ( v9->key.p0 == (void *)-1i64 )
      return def;
  }
  return (unsigned int)m_elem[v8].val;
}

// File Line: 236
// RVA: 0xD79180
void __fastcall hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::remove(
        hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations> *this,
        __int64 it)
{
  __int64 v2; // r8
  hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::Pair *m_elem; // rax
  int m_hashMod; // r9d
  hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::Pair *v5; // r11
  unsigned int i; // r8d
  __int64 v7; // r8
  int v8; // r11d
  int v9; // r8d
  unsigned int v10; // r11d
  hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::Pair *v11; // rdi
  unsigned __int64 v12; // r8
  unsigned __int64 v13; // rbx
  unsigned int v14; // eax
  hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::Pair *v15; // rax

  --this->m_numElems;
  v2 = (unsigned int)it;
  m_elem = this->m_elem;
  m_elem[v2].key.m_a = 0i64;
  m_elem[v2].key.m_b = 0i64;
  m_hashMod = this->m_hashMod;
  v5 = this->m_elem;
  for ( i = m_hashMod + it; ; i = m_hashMod + v7 )
  {
    v7 = m_hashMod & i;
    if ( !v5[v7].key.m_a || !v5[v7].key.m_b )
      break;
  }
  v8 = v7 + 1;
  v9 = it + 1;
  v10 = m_hashMod & v8;
  while ( 1 )
  {
    v11 = this->m_elem;
    v12 = m_hashMod & (unsigned int)v9;
    v13 = v12;
    if ( !this->m_elem[v12].key.m_a || !this->m_elem[v12].key.m_b )
      break;
    v14 = m_hashMod & (-1640531535
                     * (((unsigned __int64)this->m_elem[v12].key.m_b + 0x10000000 * (__int64)this->m_elem[v12].key.m_a) >> 4));
    if ( ((unsigned int)v12 < v10 || v14 <= (unsigned int)it)
      && ((unsigned int)v12 >= (unsigned int)it || v14 <= (unsigned int)it && v14 > (unsigned int)v12)
      && (v14 <= (unsigned int)it || v14 >= v10) )
    {
      it = 24i64 * (unsigned int)it;
      *(hkpEntity **)((char *)&v11->key.m_a + it) = v11[v12].key.m_a;
      *(hkpEntity **)((char *)&v11->key.m_b + it) = v11[v13].key.m_b;
      *(unsigned __int64 *)((char *)&this->m_elem->val + it) = this->m_elem[v13].val;
      v15 = this->m_elem;
      LODWORD(it) = v12;
      v15[v13].key.m_a = 0i64;
      v15[v13].key.m_b = 0i64;
    }
    m_hashMod = this->m_hashMod;
    v9 = v12 + 1;
  }
}

// File Line: 304
// RVA: 0xD79120
hkResult *__fastcall hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::remove(
        hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations> *this,
        hkResult *result,
        hkpPairCollisionFilter::PairFilterKey *key)
{
  Dummy *v5; // rax
  hkpPairCollisionFilter::PairFilterKey v7; // [rsp+20h] [rbp-18h] BYREF

  v7 = *key;
  v5 = hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::findKey(
         this,
         &v7);
  if ( (int)v5 > this->m_hashMod )
  {
    result->m_enum = HK_FAILURE;
  }
  else
  {
    hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::remove(
      this,
      v5);
    result->m_enum = HK_SUCCESS;
  }
  return result;
}

// File Line: 316
// RVA: 0xC60650
void __fastcall hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *this,
        hkMemoryAllocator *alloc,
        int numElements)
{
  int v3; // r8d
  int i; // r9d
  hkResult result; // [rsp+40h] [rbp+18h] BYREF

  v3 = 2 * numElements;
  for ( i = 8; i < v3; i *= 2 )
    ;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::resizeTable(this, &result, alloc, i);
}

// File Line: 328
// RVA: 0xE51900
hkResult *__fastcall hkMapBase<hkDataObject_Handle,int,`anonymous namespace::Writer::HandleOps>::resizeTable(
        hkMapBase<hkDataObject_Handle,int,HandleOps> *this,
        hkResult *result,
        hkMemoryAllocator *alloc,
        int newcap)
{
  hkMapBase<hkDataObject_Handle,int,HandleOps>::Pair *m_elem; // rbp
  int v6; // ebx
  unsigned int v9; // r13d
  int v10; // r12d
  hkMapBase<hkDataObject_Handle,int,HandleOps>::Pair *v11; // rax
  __int64 v12; // rdx
  __int64 v13; // rcx
  __int64 v14; // rdi
  hkMapBase<hkDataObject_Handle,int,HandleOps>::Pair *v15; // rbx
  int val; // r9d
  hkDataObject_Handle key; // [rsp+20h] [rbp-38h] BYREF

  m_elem = this->m_elem;
  v6 = 8;
  if ( newcap > 8 )
    v6 = newcap;
  v9 = this->m_numElems & 0x80000000;
  v10 = this->m_hashMod + 1;
  v11 = (hkMapBase<hkDataObject_Handle,int,HandleOps>::Pair *)(*((__int64 (__fastcall **)(hkMemoryAllocator *, _QWORD))&alloc->vfptr->__vecDelDtor
                                                               + 1))(
                                                                alloc,
                                                                (unsigned int)(24 * v6));
  if ( v11 )
  {
    this->m_elem = v11;
    v12 = v6;
    v13 = 0i64;
    do
    {
      this->m_elem[v13++].key.p0 = (void *)-1i64;
      --v12;
    }
    while ( v12 );
    this->m_numElems = 0;
    v14 = v10;
    this->m_hashMod = v6 - 1;
    if ( v10 > 0 )
    {
      v15 = m_elem;
      do
      {
        if ( v15->key.p0 != (void *)-1i64 )
        {
          val = v15->val;
          key = v15->key;
          hkMapBase<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>>::insert(this, alloc, &key, val);
        }
        ++v15;
        --v14;
      }
      while ( v14 );
    }
    if ( !v9 )
      alloc->vfptr->blockFree(alloc, m_elem, 24 * v10);
    result->m_enum = HK_SUCCESS;
  }
  else
  {
    result->m_enum = HK_FAILURE;
  }
  return result;
}

// File Line: 410
// RVA: 0xC609C0
__int64 __fastcall hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getSizeInBytesFor(
        int numOfKeys)
{
  int v1; // ecx
  int i; // eax

  v1 = 2 * numOfKeys;
  for ( i = 8; i < v1; i *= 2 )
    ;
  return (unsigned int)(16 * i);
}

// File Line: 423
// RVA: 0xC60350
__int64 __fastcall hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64>>::getMemSize(
        hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> > *this)
{
  return (unsigned int)((this->m_hashMod + 1) << 6);
}

