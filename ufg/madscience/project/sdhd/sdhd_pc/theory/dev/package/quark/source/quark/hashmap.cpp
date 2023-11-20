// File Line: 37
// RVA: 0x1614F0
void __fastcall UFG::qHashMapBase::qHashMapBase(UFG::qHashMapBase *this, UFG::qMemoryPool *pool, unsigned int initialSize)
{
  UFG::qHashMapBase *v3; // rdi
  unsigned int v4; // ebx
  unsigned int v5; // ecx
  int v6; // eax
  unsigned int v7; // ebx
  char *v8; // rax

  v3 = this;
  this->mPool = pool;
  *(_QWORD *)&this->mFillCount = 0i64;
  if ( initialSize >= 8 )
  {
    v5 = (initialSize - 1) | ((initialSize - 1) >> 1) | (((initialSize - 1) | ((initialSize - 1) >> 1)) >> 2) | (((initialSize - 1) | ((initialSize - 1) >> 1) | (((initialSize - 1) | ((initialSize - 1) >> 1)) >> 2)) >> 4);
    v4 = (v5 | (v5 >> 8) | ((v5 | (v5 >> 8)) >> 16)) + 1;
  }
  else
  {
    v4 = 8;
  }
  v6 = v4 - 1;
  v7 = 16 * v4;
  v3->mMask = v6;
  v8 = UFG::qMemoryPool::Allocate(pool, v7, "qHashMapBase", 0i64, 1u);
  v3->mTable = (UFG::qHashMapBase::Entry *)v8;
  UFG::qMemSet(v8, 0, v7);
}

// File Line: 52
// RVA: 0x17C3C0
char __fastcall UFG::qHashMapBase::Set(UFG::qHashMapBase *this, unsigned int hash, void *value)
{
  void *v3; // rsi
  unsigned int v4; // edi
  UFG::qHashMapBase *v5; // rbx
  UFG::qHashMapBase::Entry *v6; // rax
  unsigned int v7; // eax
  unsigned int v8; // er8
  signed int v9; // edx

  v3 = value;
  v4 = hash;
  v5 = this;
  if ( !hash )
    return 0;
  if ( !value )
    return 0;
  v6 = UFG::qHashMapBase::Lookup(this, hash);
  if ( v6->value )
    return 0;
  if ( !v6->hash )
    ++v5->mFillCount;
  v6->hash = v4;
  v6->value = v3;
  v7 = v5->mMask;
  v8 = ++v5->mUsedCount;
  if ( 3 * v5->mFillCount >= 2 * v7 + 2 )
  {
    v9 = 4;
    if ( v8 > 0xC350 )
      v9 = 2;
    UFG::qHashMapBase::Resize(v5, v8 * v9);
  }
  return 1;
}

// File Line: 94
// RVA: 0x177490
UFG::qHashMapBase::Entry *__fastcall UFG::qHashMapBase::Lookup(UFG::qHashMapBase *this, unsigned int hash)
{
  unsigned int v2; // er11
  UFG::qHashMapBase::Entry *v3; // rbx
  unsigned int v4; // er9
  unsigned int v5; // edx
  UFG::qHashMapBase::Entry *result; // rax
  unsigned int v7; // er10
  int v8; // er8
  UFG::qHashMapBase::Entry *v9; // rcx
  unsigned int i; // edx

  v2 = this->mMask;
  v3 = this->mTable;
  v4 = hash;
  v5 = hash & this->mMask;
  result = &v3[v5];
  if ( result->hash )
  {
    if ( result->value )
    {
      if ( result->hash == v4 )
        return result;
      result = 0i64;
    }
    v7 = v4;
    v8 = v5 + 1 + v4 + 4 * v5;
    v9 = &v3[v2 & v8];
    for ( i = v9->hash; v9->hash; i = v9->hash )
    {
      if ( v9->value )
      {
        if ( i == v4 )
          return v9;
      }
      else if ( !result )
      {
        result = v9;
      }
      v7 >>= 5;
      v8 += v7 + 4 * v8 + 1;
      v9 = &v3[v2 & v8];
    }
    if ( !result )
      result = v9;
  }
  return result;
}

// File Line: 151
// RVA: 0x17ACD0
void __fastcall UFG::qHashMapBase::Resize(UFG::qHashMapBase *this, unsigned int newsize)
{
  UFG::qHashMapBase *v2; // r14
  unsigned int v3; // ebx
  unsigned int v4; // ecx
  UFG::qMemoryPool *v5; // rcx
  UFG::qHashMapBase::Entry *v6; // rbp
  int v7; // eax
  unsigned int v8; // ebx
  UFG::allocator::free_link *v9; // rax
  unsigned int v10; // esi
  UFG::qHashMapBase::Entry *v11; // rbx
  unsigned int v12; // er11
  unsigned int v13; // er9
  UFG::qHashMapBase::Entry *v14; // rdi
  unsigned int v15; // edx
  signed __int64 v16; // rax
  signed __int64 v17; // rcx
  unsigned int v18; // er10
  int v19; // er8
  int i; // edx

  v2 = this;
  if ( newsize >= 8 )
  {
    v4 = (newsize - 1) | ((newsize - 1) >> 1) | (((newsize - 1) | ((newsize - 1) >> 1)) >> 2) | (((newsize - 1) | ((newsize - 1) >> 1) | (((newsize - 1) | ((newsize - 1) >> 1)) >> 2)) >> 4);
    v3 = (v4 | (v4 >> 8) | ((v4 | (v4 >> 8)) >> 16)) + 1;
  }
  else
  {
    v3 = 8;
  }
  v5 = v2->mPool;
  v6 = v2->mTable;
  v2->mFillCount = v2->mUsedCount;
  v7 = v3 - 1;
  v8 = 16 * v3;
  v2->mMask = v7;
  v9 = UFG::qMemoryPool::Allocate(v5, v8, "qHashMapBase", 0i64, 1u);
  v2->mTable = (UFG::qHashMapBase::Entry *)v9;
  UFG::qMemSet(v9, 0, v8);
  v10 = v2->mUsedCount;
  v11 = v6;
  if ( v10 )
  {
    while ( !v11->value )
    {
LABEL_22:
      ++v11;
      if ( !v10 )
        goto LABEL_23;
    }
    v12 = v2->mMask;
    v13 = v11->hash;
    v14 = v2->mTable;
    v15 = v11->hash & v2->mMask;
    v16 = (signed __int64)&v14[v15];
    if ( *(_DWORD *)v16 )
    {
      if ( !*(_QWORD *)(v16 + 8) )
      {
        v17 = (signed __int64)&v14[v13 & v2->mMask];
LABEL_11:
        v18 = v11->hash;
        v19 = v15 + 1 + v13 + 4 * v15;
        v16 = (signed __int64)&v14[v12 & v19];
        for ( i = *(_DWORD *)v16; *(_DWORD *)v16; i = *(_DWORD *)v16 )
        {
          if ( *(_QWORD *)(v16 + 8) )
          {
            if ( i == v13 )
              goto LABEL_21;
          }
          else if ( !v17 )
          {
            v17 = v16;
          }
          v18 >>= 5;
          v19 += v18 + 4 * v19 + 1;
          v16 = (signed __int64)&v14[v12 & v19];
        }
        if ( !v17 )
          v17 = v16;
        v16 = v17;
        goto LABEL_21;
      }
      if ( *(_DWORD *)v16 != v13 )
      {
        v17 = 0i64;
        goto LABEL_11;
      }
    }
LABEL_21:
    *(_DWORD *)v16 = v13;
    --v10;
    *(_QWORD *)(v16 + 8) = v11->value;
    goto LABEL_22;
  }
LABEL_23:
  UFG::qMemoryPool::Free(v2->mPool, v6);
}

