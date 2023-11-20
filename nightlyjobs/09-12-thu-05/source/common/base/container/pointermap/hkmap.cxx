// File Line: 33
// RVA: 0xC608D0
void __fastcall hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>(hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *this, void *ptr, int sizeInBytes)
{
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::init(this, ptr, sizeInBytes);
}

// File Line: 39
// RVA: 0xC60A40
void __fastcall hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::init(hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *this, void *ptr, int sizeInBytes)
{
  unsigned int v3; // er8
  __int64 v4; // rdx
  __int64 v5; // rax

  v3 = (unsigned int)sizeInBytes >> 4;
  this->m_elem = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *)ptr;
  this->m_numElems = 2147483648;
  v4 = v3;
  this->m_hashMod = v3 - 1;
  if ( (signed int)v3 > 0 )
  {
    v5 = 0i64;
    do
    {
      ++v5;
      this->m_elem[v5 - 1].key = -1i64;
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 56
// RVA: 0xDF2620
void __fastcall hkMapBase<`anonymous namespace'::MapKey32,int,MapOperationsMapKey32::MapOperationsMapKey32>::clear(hkMapBase<MapKey32,int,A0x59affef2::MapOperationsMapKey32> *this)
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
      *((_BYTE *)&this->m_elem[v3] - 8) = 0;
      --v2;
    }
    while ( v2 );
  }
  this->m_numElems &= 0x80000000;
}

// File Line: 67
// RVA: 0xE4A100
void __fastcall hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle>>::clearAndDeallocate(hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle> > *this, hkMemoryAllocator *alloc)
{
  hkMemoryAllocator *v2; // rdi
  hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle> > *v3; // rbx

  v2 = alloc;
  v3 = this;
  hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle>>::clear(this);
  if ( v3->m_numElems >= 0 )
    v2->vfptr->blockFree(v2, v3->m_elem, 40 * (v3->m_hashMod + 1));
  v3->m_hashMod = -1;
  v3->m_elem = 0i64;
  v3->m_numElems = 0;
}

// File Line: 87
// RVA: 0xD50940
__int64 __fastcall hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::insert(hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations> *this, hkMemoryAllocator *alloc, hkpPairCollisionFilter::PairFilterKey *key, unsigned __int64 val)
{
  unsigned __int64 v4; // rsi
  int v5; // er9
  hkpPairCollisionFilter::PairFilterKey *v6; // rbx
  hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations> *v7; // rdi
  hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::Pair *v8; // r9
  unsigned int v9; // er10
  unsigned int i; // edx
  signed __int64 v11; // rdx
  signed __int64 v12; // rdx
  __int64 v13; // rax
  hkResult result; // [rsp+60h] [rbp+8h]

  v4 = val;
  v5 = this->m_hashMod;
  v6 = key;
  v7 = this;
  if ( 2 * this->m_numElems > v5 )
    hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::resizeTable(
      this,
      &result,
      alloc,
      2 * v5 + 2);
  v8 = v7->m_elem;
  v9 = 1;
  for ( i = -1640531535 * ((_QWORD)((_QWORD)v6->m_b + 0x10000000 * (_QWORD)v6->m_a) >> 4); ; i = v11 + 1 )
  {
    v11 = v7->m_hashMod & i;
    if ( !v8[v11].key.m_a || !v8[v11].key.m_b )
      break;
    if ( v8[v11].key.m_a == v6->m_a && v8[v11].key.m_b == v6->m_b )
    {
      v9 = 0;
      break;
    }
  }
  v7->m_numElems += v9;
  v12 = v11;
  v8[v12].key.m_a = v6->m_a;
  v8[v12].key.m_b = v6->m_b;
  v13 = v9;
  v7->m_elem[v12].val = v4;
  return v13;
}

// File Line: 124
// RVA: 0xC60BD0
__int64 __fastcall hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::tryInsert(hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *this, hkMemoryAllocator *alloc, unsigned __int64 key, unsigned __int64 val, hkResult *res)
{
  unsigned __int64 v5; // rsi
  int v6; // er9
  unsigned __int64 v7; // rbp
  hkMemoryAllocator *v8; // rdi
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v9; // rbx
  hkResult *v10; // rax
  hkResultEnum v11; // ecx
  hkResult result; // [rsp+30h] [rbp+8h]

  v5 = val;
  v6 = this->m_hashMod;
  v7 = key;
  v8 = alloc;
  v9 = this;
  if ( 2 * this->m_numElems <= v6 )
  {
    res->m_enum = 0;
  }
  else
  {
    v10 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::resizeTable(
            this,
            &result,
            alloc,
            2 * v6 + 2);
    v11 = v10->m_enum;
    res->m_enum = v10->m_enum;
    if ( v11 )
      return 0i64;
  }
  return hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(v9, v8, v7, v5);
}

// File Line: 149
// RVA: 0xC60230
Dummy *__fastcall hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64>>::findKey(hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> > *this, unsigned __int64 key)
{
  int v2; // er9
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v3; // r10
  unsigned int v4; // er8
  unsigned __int64 v5; // rcx

  v2 = this->m_hashMod;
  if ( v2 <= 0 )
    return (Dummy *)(v2 + 1);
  v3 = this->m_elem;
  v4 = v2 & -1640531535 * (key >> 4);
  v5 = this->m_elem[(unsigned __int64)(v2 & -1640531535 * (unsigned int)(key >> 4))].key;
  if ( v5 == -1i64 )
    return (Dummy *)(v2 + 1);
  while ( v5 != key )
  {
    v4 = v2 & (v4 + 1);
    v5 = v3[(unsigned __int64)v4].key;
    if ( v5 == -1i64 )
      return (Dummy *)(v2 + 1);
  }
  return (Dummy *)v4;
}

// File Line: 167
// RVA: 0xC60290
unsigned __int64 __fastcall hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findOrInsertKey(hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *this, hkMemoryAllocator *alloc, unsigned __int64 key, unsigned __int64 val)
{
  unsigned __int64 v4; // rsi
  int v5; // er9
  unsigned __int64 v6; // rbx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v7; // rdi
  int v8; // er9
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v9; // r8
  unsigned int v10; // ecx
  unsigned __int64 v11; // rdx
  unsigned __int64 v12; // rax
  signed __int64 v13; // rdx
  hkResult result; // [rsp+30h] [rbp+8h]

  v4 = val;
  v5 = this->m_hashMod;
  v6 = key;
  v7 = this;
  if ( 2 * this->m_numElems > v5 )
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::resizeTable(
      this,
      &result,
      alloc,
      2 * v5 + 2);
  v8 = v7->m_hashMod;
  v9 = v7->m_elem;
  v10 = v8 & -1640531535 * (v6 >> 4);
  v11 = v7->m_elem[v8 & -1640531535 * (unsigned int)(v6 >> 4)].key;
  if ( v11 == v6 )
    return v10;
  while ( v11 != -1i64 )
  {
    v10 = v8 & (v10 + 1);
    v11 = v9[v10].key;
    if ( v11 == v6 )
      return v10;
  }
  v12 = v10;
  v13 = v10;
  v9[v13].key = v6;
  v7->m_elem[v13].val = v4;
  ++v7->m_numElems;
  return v12;
}

// File Line: 200
// RVA: 0xC60950
hkResult *__fastcall hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::get(hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *this, hkResult *result, unsigned __int64 key, unsigned __int64 *out)
{
  hkResult *v4; // rbx
  unsigned __int64 *v5; // rsi
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v6; // rdi
  int v7; // eax
  __int64 v8; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v9; // rax
  unsigned __int64 v10; // rcx
  hkResult *v11; // rax

  v4 = result;
  v5 = out;
  v6 = this;
  v7 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                           this,
                           key);
  if ( v7 > v6->m_hashMod )
  {
    v4->m_enum = 1;
    v11 = v4;
  }
  else
  {
    v8 = v7;
    v9 = v6->m_elem;
    v4->m_enum = 0;
    v10 = v9[v8].val;
    v11 = v4;
    *v5 = v10;
  }
  return v11;
}

// File Line: 212
// RVA: 0xE4A9C0
__int64 __fastcall hkMapBase<hkDataObject_Handle,int,`anonymous namespace'::HandleOps>::getWithDefault(hkMapBase<hkDataObject_Handle,int,HandleOps> *this, hkDataObject_Handle *key, int def)
{
  int v3; // er11
  unsigned int v4; // edi
  hkDataObject_Handle *v5; // r10
  void *v6; // rbx
  hkMapBase<hkDataObject_Handle,int,HandleOps>::Pair *v7; // r8
  __int64 v8; // r9
  hkMapBase<hkDataObject_Handle,int,HandleOps>::Pair *v9; // rdx
  __int64 v10; // rax

  v3 = this->m_hashMod;
  v4 = def;
  v5 = key;
  if ( v3 <= 0 )
    return v4;
  v6 = key->p0;
  v7 = this->m_elem;
  v8 = v3 & -1640531535 * (unsigned int)((_QWORD)key->p0 >> 4);
  v9 = &this->m_elem[v8];
  if ( v9->key.p0 == (void *)-1i64 )
    return v4;
  while ( v9->key.p0 != v6 || v9->key.p1 != v5->p1 )
  {
    v10 = v3 & (unsigned int)(v8 + 1);
    v8 = v3 & (unsigned int)(v8 + 1);
    v9 = &v7[v10];
    if ( v7[v10].key.p0 == (void *)-1i64 )
      return v4;
  }
  return (unsigned int)v7[v8].val;
}

// File Line: 236
// RVA: 0xD79180
void __fastcall hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::remove(hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations> *this, Dummy *it)
{
  signed __int64 v2; // r8
  hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::Pair *v3; // rax
  int v4; // er9
  hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::Pair *v5; // r11
  int i; // er8
  __int64 v7; // r8
  int v8; // er11
  int v9; // er8
  unsigned int v10; // er11
  hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::Pair *v11; // rdi
  unsigned __int64 v12; // r8
  unsigned __int64 v13; // rbx
  unsigned int v14; // eax
  hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::Pair *v15; // rax

  --this->m_numElems;
  v2 = (unsigned int)it;
  v3 = this->m_elem;
  v3[v2].key.m_a = 0i64;
  v3[v2].key.m_b = 0i64;
  v4 = this->m_hashMod;
  v5 = this->m_elem;
  for ( i = v4 + (_DWORD)it; ; i = v4 + v7 )
  {
    v7 = v4 & (unsigned int)i;
    if ( !v5[v7].key.m_a || !v5[v7].key.m_b )
      break;
  }
  v8 = v7 + 1;
  v9 = (_DWORD)it + 1;
  v10 = v4 & v8;
  while ( 1 )
  {
    v11 = this->m_elem;
    v12 = v4 & (unsigned int)v9;
    v13 = v12;
    if ( !this->m_elem[v12].key.m_a || !this->m_elem[v12].key.m_b )
      break;
    v14 = v4 & -1640531535
             * ((_QWORD)((_QWORD)this->m_elem[v12].key.m_b + 0x10000000 * (_QWORD)this->m_elem[v12].key.m_a) >> 4);
    if ( ((unsigned int)v12 < v10 || v14 <= (unsigned int)it)
      && ((unsigned int)v12 >= (unsigned int)it || v14 <= (unsigned int)it && v14 > (unsigned int)v12)
      && (v14 <= (unsigned int)it || v14 >= v10) )
    {
      it = (Dummy *)(24i64 * (unsigned int)it);
      *(hkpEntity **)((char *)&v11->key.m_a + (_QWORD)it) = v11[v13].key.m_a;
      *(hkpEntity **)((char *)&v11->key.m_b + (_QWORD)it) = v11[v13].key.m_b;
      *(_QWORD *)((char *)it + (unsigned __int64)this->m_elem + 16) = this->m_elem[v13].val;
      v15 = this->m_elem;
      LODWORD(it) = v12;
      v15[v13].key.m_a = 0i64;
      v15[v13].key.m_b = 0i64;
    }
    v4 = this->m_hashMod;
    v9 = v12 + 1;
  }
}

// File Line: 304
// RVA: 0xD79120
hkResult *__fastcall hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::remove(hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations> *this, hkResult *result, hkpPairCollisionFilter::PairFilterKey *key)
{
  hkResult *v3; // rbx
  hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations> *v4; // rdi
  Dummy *v5; // rax
  hkpPairCollisionFilter::PairFilterKey v7; // [rsp+20h] [rbp-18h]

  v3 = result;
  v4 = this;
  v7 = *key;
  v5 = hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::findKey(
         this,
         &v7);
  if ( (signed int)v5 > v4->m_hashMod )
  {
    v3->m_enum = 1;
  }
  else
  {
    hkMapBase<hkpPairCollisionFilter::PairFilterKey,unsigned __int64,hkpPairCollisionFilter::PairFilterPointerMapOperations>::remove(
      v4,
      v5);
    v3->m_enum = 0;
  }
  return v3;
}

// File Line: 316
// RVA: 0xC60650
void __fastcall hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *this, hkMemoryAllocator *alloc, int numElements)
{
  int v3; // er8
  int i; // er9
  hkResult result; // [rsp+40h] [rbp+18h]

  v3 = 2 * numElements;
  for ( i = 8; i < v3; i *= 2 )
    ;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::resizeTable(this, &result, alloc, i);
}

// File Line: 328
// RVA: 0xE51900
hkResult *__fastcall hkMapBase<hkDataObject_Handle,int,`anonymous namespace'::Writer::HandleOps>::resizeTable(hkMapBase<hkDataObject_Handle,int,HandleOps> *this, hkResult *result, hkMemoryAllocator *alloc, int newcap)
{
  hkMapBase<hkDataObject_Handle,int,HandleOps>::Pair *v4; // rbp
  hkResult *v5; // r14
  int v6; // ebx
  hkMapBase<hkDataObject_Handle,int,HandleOps> *v7; // rsi
  hkMemoryAllocator *v8; // r15
  unsigned int v9; // er13
  int v10; // er12
  __int64 v11; // rax
  __int64 v12; // rdx
  __int64 v13; // rcx
  __int64 v14; // rdi
  hkMapBase<hkDataObject_Handle,int,HandleOps>::Pair *v15; // rbx
  int v16; // er9
  hkDataObject_Handle v18; // [rsp+20h] [rbp-38h]

  v4 = this->m_elem;
  v5 = result;
  v6 = 8;
  v7 = this;
  if ( newcap > 8 )
    v6 = newcap;
  v8 = alloc;
  v9 = this->m_numElems & 0x80000000;
  v10 = this->m_hashMod + 1;
  v11 = (*((__int64 (__fastcall **)(hkMemoryAllocator *, _QWORD))&alloc->vfptr->__vecDelDtor + 1))(
          alloc,
          (unsigned int)(24 * v6));
  if ( v11 )
  {
    v7->m_elem = (hkMapBase<hkDataObject_Handle,int,HandleOps>::Pair *)v11;
    v12 = v6;
    if ( v6 > 0 )
    {
      v13 = 0i64;
      do
      {
        ++v13;
        v7->m_elem[v13 - 1].key.p0 = (void *)-1i64;
        --v12;
      }
      while ( v12 );
    }
    v7->m_numElems = 0;
    v14 = v10;
    v7->m_hashMod = v6 - 1;
    if ( v10 > 0 )
    {
      v15 = v4;
      do
      {
        if ( v15->key.p0 != (void *)-1i64 )
        {
          v16 = v15->val;
          v18 = v15->key;
          hkMapBase<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>>::insert(v7, v8, &v18, v16);
        }
        ++v15;
        --v14;
      }
      while ( v14 );
    }
    if ( !v9 )
      v8->vfptr->blockFree(v8, v4, 24 * v10);
    v5->m_enum = 0;
  }
  else
  {
    v5->m_enum = 1;
  }
  return v5;
}

// File Line: 410
// RVA: 0xC609C0
__int64 __fastcall hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getSizeInBytesFor(int numOfKeys)
{
  int v1; // ecx
  signed int i; // eax

  v1 = 2 * numOfKeys;
  for ( i = 8; i < v1; i *= 2 )
    ;
  return (unsigned int)(16 * i);
}

// File Line: 423
// RVA: 0xC60350
__int64 __fastcall hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64>>::getMemSize(hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> > *this)
{
  return (unsigned int)((this->m_hashMod + 1) << 6);
}

