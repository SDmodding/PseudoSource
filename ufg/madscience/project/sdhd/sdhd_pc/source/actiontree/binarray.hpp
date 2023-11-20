// File Line: 91
// RVA: 0x15E000
void __fastcall BinArray<ActionID,0>::Reallocate(BinArray<ActionID,0> *this, unsigned int newsize, const char *reason)
{
  unsigned int v3; // ebp
  BinArray<ActionID,0> *v4; // r14
  unsigned int v5; // esi
  unsigned __int64 v6; // rax
  char *v7; // rdi
  signed __int64 v8; // rbx
  __int64 v9; // rax
  __int64 v10; // rax
  __int64 v11; // r8
  signed __int64 v12; // rdx
  void *v13; // rcx

  v3 = newsize;
  v4 = this;
  v5 = this->mCount & 0x7FFFFFFF;
  if ( newsize != v5 )
  {
    v6 = 4i64 * newsize;
    if ( !is_mul_ok(newsize, 4ui64) )
      v6 = -1i64;
    v7 = UFG::qMalloc(v6, reason, 0i64);
    v8 = (signed __int64)&v4->mData;
    v9 = v4->mData.mOffset;
    if ( v9 && v9 + v8 )
    {
      if ( v5 )
      {
        v10 = 0i64;
        v11 = v5;
        do
        {
          if ( *(_QWORD *)v8 )
            v12 = *(_QWORD *)v8 + v8;
          else
            v12 = 0i64;
          *(_DWORD *)&v7[v10] = *(_DWORD *)(v10 + v12);
          v10 += 4i64;
          --v11;
        }
        while ( v11 );
      }
      if ( *(_QWORD *)v8 )
        v13 = (void *)(*(_QWORD *)v8 + v8);
      else
        v13 = 0i64;
      operator delete[](v13);
    }
    if ( v7 )
      v7 -= v8;
    *(_QWORD *)v8 = v7;
    v4->mCount &= 0x80000000;
    v4->mCount |= v3 & 0x7FFFFFFF;
  }
}

// File Line: 195
// RVA: 0x26C100
void __fastcall BinArray<ActionID,0>::Clone(BinArray<ActionID,0> *this, BinArray<ActionID,0> *_dst)
{
  BinArray<ActionID,0> *v2; // rbx
  BinArray<ActionID,0> *v3; // rdi
  signed __int64 v4; // rbp
  __int64 v5; // rax
  char *v6; // rcx
  int v7; // er14
  unsigned int v8; // er14
  __int64 v9; // rax
  signed __int64 v10; // rsi
  __int64 v11; // rdi
  unsigned __int64 v12; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::qOffset64<ActionID *> *v14; // rbx
  signed __int64 v15; // rsi

  v2 = _dst;
  v3 = this;
  v4 = 0i64;
  if ( _dst->mCount >= 0 )
  {
    v5 = _dst->mData.mOffset;
    if ( v5 )
    {
      v6 = (char *)&_dst->mData + v5;
      if ( v6 )
        operator delete[](v6);
    }
    v2->mData.mOffset = 0i64;
    v2->mCount &= 0x80000000;
  }
  v7 = v3->mCount;
  v2->mCount &= 0x80000000;
  v8 = v7 & 0x7FFFFFFF;
  if ( v8 )
  {
    v2->mCount |= v8 & 0x7FFFFFFF;
    v9 = v3->mData.mOffset;
    if ( v9 )
      v10 = (signed __int64)&v3->mData + v9;
    else
      v10 = 0i64;
    v11 = v8;
    v12 = 4i64 * v8;
    if ( !is_mul_ok(v8, 4ui64) )
      v12 = -1i64;
    v13 = UFG::qMalloc(v12, "BinArray.Clone", 0i64);
    v14 = &v2->mData;
    if ( v13 )
      v4 = (char *)v13 - (char *)v14;
    v14->mOffset = v4;
    if ( v8 )
    {
      v15 = v10 - (_QWORD)v13;
      do
      {
        LODWORD(v13->mNext) = *(_DWORD *)((char *)&v13->mNext + v15);
        v13 = (UFG::allocator::free_link *)((char *)v13 + 4);
        --v11;
      }
      while ( v11 );
    }
  }
  else
  {
    v2->mData.mOffset = 0i64;
  }
}

