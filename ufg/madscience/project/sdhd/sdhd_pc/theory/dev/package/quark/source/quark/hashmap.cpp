// File Line: 37
// RVA: 0x1614F0
void __fastcall UFG::qHashMapBase::qHashMapBase(
        UFG::qHashMapBase *this,
        UFG::qMemoryPool *pool,
        unsigned int initialSize)
{
  unsigned int v4; // ebx
  unsigned int v5; // ecx
  unsigned int v6; // eax
  unsigned int v7; // ebx
  char *v8; // rax

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
  this->mMask = v6;
  v8 = UFG::qMemoryPool::Allocate(pool, v7, "qHashMapBase", 0i64, 1u);
  this->mTable = (UFG::qHashMapBase::Entry *)v8;
  UFG::qMemSet(v8, 0, v7);
}

// File Line: 52
// RVA: 0x17C3C0
char __fastcall UFG::qHashMapBase::Set(UFG::qHashMapBase *this, unsigned int hash, void *value)
{
  UFG::qHashMapBase::Entry *v6; // rax
  unsigned int mMask; // eax
  unsigned int v8; // r8d
  int v9; // edx

  if ( !hash )
    return 0;
  if ( !value )
    return 0;
  v6 = UFG::qHashMapBase::Lookup(this, hash);
  if ( v6->value )
    return 0;
  if ( !v6->hash )
    ++this->mFillCount;
  v6->hash = hash;
  v6->value = value;
  mMask = this->mMask;
  v8 = ++this->mUsedCount;
  if ( 3 * this->mFillCount >= 2 * mMask + 2 )
  {
    v9 = 4;
    if ( v8 > 0xC350 )
      v9 = 2;
    UFG::qHashMapBase::Resize(this, v8 * v9);
  }
  return 1;
}

// File Line: 94
// RVA: 0x177490
UFG::qHashMapBase::Entry *__fastcall UFG::qHashMapBase::Lookup(UFG::qHashMapBase *this, unsigned int hash)
{
  unsigned int mMask; // r11d
  UFG::qHashMapBase::Entry *mTable; // rbx
  unsigned int v5; // edx
  UFG::qHashMapBase::Entry *result; // rax
  unsigned int v7; // r10d
  unsigned int v8; // r8d
  UFG::qHashMapBase::Entry *v9; // rcx
  unsigned int i; // edx

  mMask = this->mMask;
  mTable = this->mTable;
  v5 = hash & mMask;
  result = &mTable[v5];
  if ( result->hash )
  {
    if ( result->value )
    {
      if ( result->hash == hash )
        return result;
      result = 0i64;
    }
    v7 = hash;
    v8 = v5 + 1 + hash + 4 * v5;
    v9 = &mTable[mMask & v8];
    for ( i = v9->hash; v9->hash; i = v9->hash )
    {
      if ( v9->value )
      {
        if ( i == hash )
          return v9;
      }
      else if ( !result )
      {
        result = v9;
      }
      v7 >>= 5;
      v8 += v7 + 4 * v8 + 1;
      v9 = &mTable[mMask & v8];
    }
    if ( !result )
      return v9;
  }
  return result;
}

// File Line: 151
// RVA: 0x17ACD0
void __fastcall UFG::qHashMapBase::Resize(UFG::qHashMapBase *this, unsigned int newsize)
{
  unsigned int v3; // ebx
  unsigned int v4; // ecx
  UFG::qMemoryPool *mPool; // rcx
  char *mTable; // rbp
  unsigned int v7; // eax
  unsigned int v8; // ebx
  UFG::allocator::free_link *v9; // rax
  unsigned int mUsedCount; // esi
  char *v11; // rbx
  unsigned int mMask; // r11d
  unsigned int v13; // r9d
  UFG::qHashMapBase::Entry *v14; // rdi
  UFG::qHashMapBase::Entry *v15; // rax
  UFG::qHashMapBase::Entry *v16; // rcx
  unsigned int v17; // r10d
  int v18; // r8d
  unsigned int i; // edx

  if ( newsize >= 8 )
  {
    v4 = (newsize - 1) | ((newsize - 1) >> 1) | (((newsize - 1) | ((newsize - 1) >> 1)) >> 2) | (((newsize - 1) | ((newsize - 1) >> 1) | (((newsize - 1) | ((newsize - 1) >> 1)) >> 2)) >> 4);
    v3 = (v4 | (v4 >> 8) | ((v4 | (v4 >> 8)) >> 16)) + 1;
  }
  else
  {
    v3 = 8;
  }
  mPool = this->mPool;
  mTable = (char *)this->mTable;
  this->mFillCount = this->mUsedCount;
  v7 = v3 - 1;
  v8 = 16 * v3;
  this->mMask = v7;
  v9 = UFG::qMemoryPool::Allocate(mPool, v8, "qHashMapBase", 0i64, 1u);
  this->mTable = (UFG::qHashMapBase::Entry *)v9;
  UFG::qMemSet(v9, 0, v8);
  mUsedCount = this->mUsedCount;
  v11 = mTable;
  if ( mUsedCount )
  {
    while ( !*((_QWORD *)v11 + 1) )
    {
LABEL_22:
      v11 += 16;
      if ( !mUsedCount )
        goto LABEL_23;
    }
    mMask = this->mMask;
    v13 = *(_DWORD *)v11;
    v14 = this->mTable;
    v15 = &v14[*(_DWORD *)v11 & mMask];
    if ( v15->hash )
    {
      if ( !v15->value )
      {
        v16 = &v14[v13 & this->mMask];
LABEL_11:
        v17 = *(_DWORD *)v11;
        v18 = (*(_DWORD *)v11 & mMask) + 1 + v13 + 4 * (*(_DWORD *)v11 & mMask);
        v15 = &v14[mMask & v18];
        for ( i = v15->hash; v15->hash; i = v15->hash )
        {
          if ( v15->value )
          {
            if ( i == v13 )
              goto LABEL_21;
          }
          else if ( !v16 )
          {
            v16 = v15;
          }
          v17 >>= 5;
          v18 += v17 + 4 * v18 + 1;
          v15 = &v14[mMask & v18];
        }
        if ( !v16 )
          v16 = v15;
        v15 = v16;
        goto LABEL_21;
      }
      if ( v15->hash != v13 )
      {
        v16 = 0i64;
        goto LABEL_11;
      }
    }
LABEL_21:
    v15->hash = v13;
    --mUsedCount;
    v15->value = (void *)*((_QWORD *)v11 + 1);
    goto LABEL_22;
  }
LABEL_23:
  UFG::qMemoryPool::Free(this->mPool, mTable);
}

