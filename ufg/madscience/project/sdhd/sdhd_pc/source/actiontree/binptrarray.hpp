// File Line: 43
// RVA: 0x39EAD0
// attributes: thunk
void __fastcall BinPtrArray<MotionKey,1,0>::~BinPtrArray<MotionKey,1,0>(BinPtrArray<ITrack,1,0> *this)
{
  BinPtrArray<JointReferences,1,0>::Clear(this);
}

// File Line: 50
// RVA: 0x273BD0
void __fastcall BinPtrArray<ActionNode,0,0>::_StableRemove(BinPtrArray<ActionNode,0,0> *this, int index)
{
  __int64 mOffset; // rax
  char *v4; // r11
  int v5; // r10d
  int v6; // edx
  char *v7; // rcx
  __int64 v8; // r8
  __int64 v9; // rax
  __int64 v10; // rdx

  mOffset = this->mData.mOffset;
  if ( mOffset )
    v4 = (char *)&this->mData + mOffset;
  else
    v4 = 0i64;
  v5 = this->mCount & 0x7FFFFFFF;
  v6 = index + 1;
  if ( v6 != v5 )
  {
    v7 = &v4[8 * v6];
    v8 = (unsigned int)(v5 - v6);
    do
    {
      v9 = *(_QWORD *)v7;
      if ( *(_QWORD *)v7 && &v7[v9] )
        v10 = v9 + 8;
      else
        v10 = 0i64;
      *((_QWORD *)v7 - 1) = v10;
      v7 += 8;
      --v8;
    }
    while ( v8 );
  }
  if ( v5 == 1 )
  {
    this->mCount &= 0x80000000;
    this->mData.mOffset = 0i64;
  }
  else
  {
    this->mCount ^= (this->mCount ^ (this->mCount - 1)) & 0x7FFFFFFF;
    *(_QWORD *)&v4[8 * (v5 - 1)] = 0i64;
  }
}

// File Line: 138
// RVA: 0x3A4C70
void __fastcall BinPtrArray<JointReferences,1,0>::Clear(BinPtrArray<ITrack,1,0> *this)
{
  unsigned int v2; // edx
  __int64 v3; // rdi
  __int64 v4; // rbx
  __int64 mOffset; // rax
  char *v6; // rcx
  char *v7; // rax
  __int64 v8; // rcx
  char *v9; // rcx
  __int64 v10; // rax
  char *v11; // rcx

  if ( this->mCount >= 0 )
  {
    v2 = this->mCount & 0x7FFFFFFF;
    if ( v2 )
    {
      v3 = v2;
      v4 = 0i64;
      do
      {
        mOffset = this->mData.mOffset;
        if ( mOffset )
          v6 = (char *)&this->mData + mOffset;
        else
          v6 = 0i64;
        v7 = &v6[v4];
        v8 = *(_QWORD *)&v6[v4];
        if ( v8 )
        {
          v9 = &v7[v8];
          if ( v9 )
            (*(void (__fastcall **)(char *, __int64))(*(_QWORD *)v9 + 8i64))(v9, 1i64);
        }
        v4 += 8i64;
        --v3;
      }
      while ( v3 );
    }
    v10 = this->mData.mOffset;
    if ( v10 )
    {
      v11 = (char *)&this->mData + v10;
      if ( v11 )
        operator delete[](v11);
    }
    this->mData.mOffset = 0i64;
    this->mCount &= 0x80000000;
  }
}

// File Line: 159
// RVA: 0x270D30
void __fastcall BinPtrArray<Condition,1,0>::Reallocate(
        BinPtrArray<ITrack,1,0> *this,
        unsigned int newsize,
        const char *reason)
{
  __int64 mCount; // rbx
  unsigned int v7; // r8d
  unsigned __int64 v8; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::allocator::free_link *v10; // rsi
  UFG::allocator::free_link *v11; // rcx
  __int64 v12; // r10
  __int64 v13; // r9
  __int64 mOffset; // rax
  char *v15; // rdx
  _QWORD *v16; // r8
  char *v17; // rax
  UFG::allocator::free_link *v18; // rax
  UFG::qOffset64<UFG::qOffset64<ITrack *> *> *p_mData; // rdi
  __int64 v20; // rax
  __int64 v21; // rsi
  __int64 v22; // rax
  __int64 v23; // r8
  __int64 v24; // rcx
  char *v25; // rdx

  mCount = (unsigned int)this->mCount;
  LODWORD(mCount) = mCount & 0x7FFFFFFF;
  if ( newsize != (_DWORD)mCount )
  {
    v7 = (newsize + 3) & 0xFFFFFFFC;
    if ( (((_DWORD)mCount + 3) & 0xFFFFFFFC) != v7 )
    {
      v8 = 8i64 * v7;
      if ( !is_mul_ok(v7, 8ui64) )
        v8 = -1i64;
      v9 = UFG::qMalloc(v8, reason, 0i64);
      v10 = v9;
      if ( (_DWORD)mCount )
      {
        v11 = v9;
        v12 = -(__int64)v9;
        v13 = (unsigned int)mCount;
        do
        {
          mOffset = this->mData.mOffset;
          if ( mOffset )
            v15 = (char *)&this->mData + mOffset;
          else
            v15 = 0i64;
          v16 = (UFG::allocator::free_link **)((char *)&v11->mNext + v12 + (_QWORD)v15);
          if ( *v16 && (v17 = (char *)v16 + *v16) != 0i64 )
            v18 = (UFG::allocator::free_link *)(v17 - (char *)v11);
          else
            v18 = 0i64;
          v11->mNext = v18;
          ++v11;
          --v13;
        }
        while ( v13 );
      }
      p_mData = &this->mData;
      v20 = this->mData.mOffset;
      if ( v20 && (UFG::qOffset64<UFG::qOffset64<ITrack *> *> *)((char *)p_mData + v20) )
        operator delete[]((char *)p_mData + v20);
      if ( v10 )
        v21 = (char *)v10 - (char *)p_mData;
      else
        v21 = 0i64;
      p_mData->mOffset = v21;
    }
    if ( (unsigned int)mCount < newsize )
    {
      v22 = 8 * mCount;
      v23 = newsize - (unsigned int)mCount;
      do
      {
        v24 = this->mData.mOffset;
        if ( v24 )
          v25 = (char *)&this->mData + v24;
        else
          v25 = 0i64;
        *(_QWORD *)&v25[v22] = 0i64;
        v22 += 8i64;
        --v23;
      }
      while ( v23 );
    }
  }
}

// File Line: 290
// RVA: 0x26DB80
__int64 __fastcall BinPtrArray<ActionNode,0,0>::Find(BinPtrArray<ActionNode,0,0> *this, ActionNode *item)
{
  __int64 result; // rax
  unsigned int v4; // r10d
  __int64 mOffset; // r9
  UFG::qOffset64<UFG::qOffset64<ActionNode *> *> *p_mData; // r11
  __int64 i; // r8
  char *v8; // rcx
  char *v9; // rdx
  ActionNode *v10; // rcx

  result = 0i64;
  v4 = this->mCount & 0x7FFFFFFF;
  if ( !v4 )
    return 0xFFFFFFFFi64;
  mOffset = this->mData.mOffset;
  p_mData = &this->mData;
  for ( i = 0i64; ; i += 8i64 )
  {
    v8 = mOffset ? (char *)p_mData + mOffset : 0i64;
    v9 = &v8[i];
    v10 = *(ActionNode **)&v8[i];
    if ( v10 )
      v10 = (ActionNode *)((char *)v10 + (_QWORD)v9);
    if ( item == v10 )
      break;
    result = (unsigned int)(result + 1);
    if ( (unsigned int)result >= v4 )
      return 0xFFFFFFFFi64;
  }
  return result;
}

// File Line: 327
// RVA: 0x3ADE50
bool __fastcall BinPtrArray<UELNode,0,0>::Remove(BinPtrArray<ActionNode,0,0> *this, ActionNode *item)
{
  int v4; // edx
  int v5; // r10d
  __int64 mOffset; // r9
  __int64 i; // r8
  char *v8; // rax
  char *v9; // rcx
  __int64 v10; // rax
  ActionNode *v11; // rax
  char *v13; // rcx
  char *v14; // r8
  char *v15; // rdi

  v4 = 0;
  v5 = this->mCount & 0x7FFFFFFF;
  if ( !v5 )
    return 0;
  mOffset = this->mData.mOffset;
  for ( i = 0i64; ; i += 8i64 )
  {
    v8 = mOffset ? (char *)&this->mData + mOffset : 0i64;
    v9 = &v8[i];
    v10 = *(_QWORD *)&v8[i];
    v11 = v10 ? (ActionNode *)&v9[v10] : 0i64;
    if ( item == v11 )
      break;
    if ( ++v4 >= (unsigned int)v5 )
      return 0;
  }
  if ( v4 < 0 )
    return 0;
  if ( v4 >= v5 )
    return 0;
  if ( mOffset )
    v13 = (char *)&this->mData + mOffset;
  else
    v13 = 0i64;
  v14 = &v13[8 * v4];
  v15 = &v14[*(_QWORD *)v14];
  if ( !*(_QWORD *)v14 )
    v15 = 0i64;
  BinPtrArray<ActionNode,0,0>::_StableRemove(this, v4);
  return v15 != 0i64;
}

// File Line: 415
// RVA: 0x26B280
void __fastcall BinPtrArray<ActionNode,0,0>::Add(BinPtrArray<Condition,1,0> *this, Condition *item, const char *reason)
{
  __int64 mCount; // r14
  unsigned int v6; // ebx
  unsigned int v7; // edx
  __int64 mOffset; // rax
  char *v9; // rcx
  char *v10; // rcx

  mCount = (unsigned int)this->mCount;
  LODWORD(mCount) = mCount & 0x7FFFFFFF;
  v6 = mCount + 1;
  if ( (int)mCount + 1 > (unsigned int)mCount )
  {
    v7 = 1;
    if ( (_DWORD)mCount )
      v7 = 2 * mCount;
    for ( ; v7 < v6; v7 *= 2 )
      ;
    if ( v7 - v6 > 0x10000 )
      v7 = mCount + 65537;
    BinPtrArray<Condition,1,0>::Reallocate((BinPtrArray<ITrack,1,0> *)this, v7, reason);
  }
  this->mCount &= 0x80000000;
  this->mCount |= v6 & 0x7FFFFFFF;
  mOffset = this->mData.mOffset;
  if ( mOffset )
    v9 = (char *)&this->mData + mOffset;
  else
    v9 = 0i64;
  v10 = &v9[8 * mCount];
  if ( item )
    *(_QWORD *)v10 = (char *)item - v10;
  else
    *(_QWORD *)v10 = 0i64;
}

// File Line: 541
// RVA: 0x2679A0
void __fastcall qNodeOrderChange<ActionNode,0>(BinPtrArray<ActionNode,0,0> *list, ActionNode *item, bool increase)
{
  __int64 v3; // r10
  int v6; // edi
  __int64 mOffset; // r9
  __int64 i; // r8
  char *v9; // rax
  char *v10; // rcx
  ActionNode *v11; // rax
  char *v12; // rcx
  __int64 v13; // rax
  char *v14; // rcx
  __int64 v15; // r11
  char *v16; // rdx
  __int64 v17; // rax
  char *v18; // rdx
  char *v19; // r8
  __int64 v20; // r9
  __int64 v21; // rax
  char *v22; // rdx
  char *v23; // rdx

  v3 = 0i64;
  v6 = list->mCount & 0x7FFFFFFF;
  if ( v6 )
  {
    mOffset = list->mData.mOffset;
    for ( i = 0i64; ; i += 8i64 )
    {
      if ( mOffset )
        v9 = (char *)&list->mData + mOffset;
      else
        v9 = 0i64;
      v10 = &v9[i];
      v11 = *(ActionNode **)&v9[i];
      if ( v11 )
        v11 = (ActionNode *)((char *)v11 + (_QWORD)v10);
      if ( item == v11 )
        break;
      v3 = (unsigned int)(v3 + 1);
      if ( (unsigned int)v3 >= v6 )
        return;
    }
    if ( (_DWORD)v3 != -1 )
    {
      if ( mOffset )
        v12 = (char *)&list->mData + mOffset;
      else
        v12 = 0i64;
      v13 = *(_QWORD *)&v12[8 * v3];
      if ( v13 )
        v14 = &v12[8 * v3 + v13];
      else
        v14 = 0i64;
      if ( increase )
      {
        v15 = (unsigned int)(v3 - 1);
        if ( (int)v15 < 0 )
          return;
      }
      else
      {
        v15 = (unsigned int)(v3 + 1);
        if ( (int)v15 >= v6 )
          return;
      }
      if ( mOffset )
        v16 = (char *)&list->mData + mOffset;
      else
        v16 = 0i64;
      v17 = *(_QWORD *)&v16[8 * v15];
      if ( v17 )
        v18 = &v16[8 * v15 + v17];
      else
        v18 = 0i64;
      if ( mOffset )
        v19 = (char *)&list->mData + mOffset;
      else
        v19 = 0i64;
      v20 = (__int64)&v19[8 * (int)v3];
      if ( v18 )
        v18 -= v20;
      *(_QWORD *)v20 = v18;
      v21 = list->mData.mOffset;
      if ( v21 )
        v22 = (char *)&list->mData + v21;
      else
        v22 = 0i64;
      v23 = &v22[8 * (int)v15];
      if ( v14 )
        *(_QWORD *)v23 = v14 - v23;
      else
        *(_QWORD *)v23 = 0i64;
    }
  }
}

