// File Line: 91
// RVA: 0x15E000
void __fastcall BinArray<ActionID,0>::Reallocate(BinArray<ActionID,0> *this, unsigned int newsize, const char *reason)
{
  unsigned int v5; // esi
  unsigned __int64 v6; // rax
  char *v7; // rdi
  UFG::qOffset64<ActionID *> *p_mData; // rbx
  __int64 mOffset; // rax
  __int64 v10; // rax
  __int64 v11; // r8
  char *v12; // rdx
  char *v13; // rcx

  v5 = this->mCount & 0x7FFFFFFF;
  if ( newsize != v5 )
  {
    v6 = 4i64 * newsize;
    if ( !is_mul_ok(newsize, 4ui64) )
      v6 = -1i64;
    v7 = UFG::qMalloc(v6, reason, 0i64);
    p_mData = &this->mData;
    mOffset = this->mData.mOffset;
    if ( mOffset && (UFG::qOffset64<ActionID *> *)((char *)p_mData + mOffset) )
    {
      if ( v5 )
      {
        v10 = 0i64;
        v11 = v5;
        do
        {
          if ( p_mData->mOffset )
            v12 = (char *)p_mData + p_mData->mOffset;
          else
            v12 = 0i64;
          *(_DWORD *)&v7[v10] = *(_DWORD *)&v12[v10];
          v10 += 4i64;
          --v11;
        }
        while ( v11 );
      }
      if ( p_mData->mOffset )
        v13 = (char *)p_mData + p_mData->mOffset;
      else
        v13 = 0i64;
      operator delete[](v13);
    }
    if ( v7 )
      v7 -= (__int64)p_mData;
    p_mData->mOffset = (__int64)v7;
    this->mCount &= 0x80000000;
    this->mCount |= newsize & 0x7FFFFFFF;
  }
}

// File Line: 195
// RVA: 0x26C100
void __fastcall BinArray<ActionID,0>::Clone(BinArray<ActionID,0> *this, BinArray<ActionID,0> *_dst)
{
  __int64 v4; // rbp
  __int64 mOffset; // rax
  char *v6; // rcx
  int mCount; // r14d
  unsigned int v8; // r14d
  __int64 v9; // rax
  char *v10; // rsi
  __int64 v11; // rdi
  unsigned __int64 v12; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::qOffset64<ActionID *> *p_mData; // rbx
  __int64 v15; // rsi

  v4 = 0i64;
  if ( _dst->mCount >= 0 )
  {
    mOffset = _dst->mData.mOffset;
    if ( mOffset )
    {
      v6 = (char *)&_dst->mData + mOffset;
      if ( v6 )
        operator delete[](v6);
    }
    _dst->mData.mOffset = 0i64;
    _dst->mCount &= 0x80000000;
  }
  mCount = this->mCount;
  _dst->mCount &= 0x80000000;
  v8 = mCount & 0x7FFFFFFF;
  if ( v8 )
  {
    _dst->mCount |= v8 & 0x7FFFFFFF;
    v9 = this->mData.mOffset;
    if ( v9 )
      v10 = (char *)&this->mData + v9;
    else
      v10 = 0i64;
    v11 = v8;
    v12 = 4i64 * v8;
    if ( !is_mul_ok(v8, 4ui64) )
      v12 = -1i64;
    v13 = UFG::qMalloc(v12, "BinArray.Clone", 0i64);
    p_mData = &_dst->mData;
    if ( v13 )
      v4 = (char *)v13 - (char *)p_mData;
    p_mData->mOffset = v4;
    v15 = v10 - (char *)v13;
    do
    {
      LODWORD(v13->mNext) = *(_DWORD *)((char *)&v13->mNext + v15);
      v13 = (UFG::allocator::free_link *)((char *)v13 + 4);
      --v11;
    }
    while ( v11 );
  }
  else
  {
    _dst->mData.mOffset = 0i64;
  }
}

