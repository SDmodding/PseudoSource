// File Line: 43
// RVA: 0x39EAD0
void __fastcall BinPtrArray<MotionKey,1,0>::~BinPtrArray<MotionKey,1,0>(BinPtrArray<ITrack,1,0> *this)
{
  BinPtrArray<JointReferences,1,0>::Clear(this);
}

// File Line: 50
// RVA: 0x273BD0
void __fastcall BinPtrArray<ActionNode,0,0>::_StableRemove(BinPtrArray<ActionNode,0,0> *this, int index)
{
  __int64 v2; // rax
  BinPtrArray<ActionNode,0,0> *v3; // r9
  char *v4; // r11
  int v5; // er10
  int v6; // edx
  char *v7; // rcx
  __int64 v8; // r8
  __int64 v9; // rax
  signed __int64 v10; // rdx

  v2 = this->mData.mOffset;
  v3 = this;
  if ( v2 )
    v4 = (char *)&this->mData + v2;
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
    v3->mCount &= 0x80000000;
    v3->mData.mOffset = 0i64;
  }
  else
  {
    v3->mCount ^= (v3->mCount ^ (v3->mCount - 1)) & 0x7FFFFFFF;
    *(_QWORD *)&v4[8 * (v5 - 1)] = 0i64;
  }
}

// File Line: 138
// RVA: 0x3A4C70
void __fastcall BinPtrArray<JointReferences,1,0>::Clear(BinPtrArray<ITrack,1,0> *this)
{
  BinPtrArray<ITrack,1,0> *v1; // rsi
  unsigned int v2; // edx
  __int64 v3; // rdi
  __int64 v4; // rbx
  __int64 v5; // rax
  signed __int64 v6; // rcx
  signed __int64 v7; // rax
  __int64 v8; // rcx
  signed __int64 v9; // rcx
  __int64 v10; // rax
  char *v11; // rcx

  v1 = this;
  if ( this->mCount >= 0 )
  {
    v2 = this->mCount & 0x7FFFFFFF;
    if ( v2 )
    {
      v3 = v2;
      v4 = 0i64;
      do
      {
        v5 = v1->mData.mOffset;
        if ( v5 )
          v6 = (signed __int64)&v1->mData + v5;
        else
          v6 = 0i64;
        v7 = v4 + v6;
        v8 = *(_QWORD *)(v4 + v6);
        if ( v8 )
        {
          v9 = v7 + v8;
          if ( v9 )
            (*(void (__fastcall **)(signed __int64, signed __int64))(*(_QWORD *)v9 + 8i64))(v9, 1i64);
        }
        v4 += 8i64;
        --v3;
      }
      while ( v3 );
    }
    v10 = v1->mData.mOffset;
    if ( v10 )
    {
      v11 = (char *)&v1->mData + v10;
      if ( v11 )
        operator delete[](v11);
    }
    v1->mData.mOffset = 0i64;
    v1->mCount &= 0x80000000;
  }
}

// File Line: 159
// RVA: 0x270D30
void __fastcall BinPtrArray<Condition,1,0>::Reallocate(BinPtrArray<ITrack,1,0> *this, unsigned int newsize, const char *reason)
{
  const char *v3; // r9
  unsigned int v4; // ebp
  BinPtrArray<ITrack,1,0> *v5; // r14
  __int64 v6; // rbx
  unsigned int v7; // er8
  unsigned __int64 v8; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::allocator::free_link *v10; // rsi
  UFG::allocator::free_link *v11; // rcx
  signed __int64 v12; // r10
  __int64 v13; // r9
  __int64 v14; // rax
  signed __int64 v15; // rdx
  _QWORD *v16; // r8
  char *v17; // rax
  UFG::allocator::free_link *v18; // rax
  UFG::qOffset64<UFG::qOffset64<ITrack *> *> *v19; // rdi
  __int64 v20; // rax
  __int64 v21; // rsi
  signed __int64 v22; // rax
  __int64 v23; // r8
  __int64 v24; // rcx
  signed __int64 v25; // rdx

  v3 = reason;
  v4 = newsize;
  v5 = this;
  v6 = (unsigned int)this->mCount;
  LODWORD(v6) = v6 & 0x7FFFFFFF;
  if ( newsize != (_DWORD)v6 )
  {
    v7 = (newsize + 3) & 0xFFFFFFFC;
    if ( (((_DWORD)v6 + 3) & 0xFFFFFFFC) != v7 )
    {
      v8 = 8i64 * v7;
      if ( !is_mul_ok(v7, 8ui64) )
        v8 = -1i64;
      v9 = UFG::qMalloc(v8, v3, 0i64);
      v10 = v9;
      if ( (_DWORD)v6 )
      {
        v11 = v9;
        v12 = -(signed __int64)v9;
        v13 = (unsigned int)v6;
        do
        {
          v14 = v5->mData.mOffset;
          if ( v14 )
            v15 = (signed __int64)&v5->mData + v14;
          else
            v15 = 0i64;
          v16 = (UFG::allocator::free_link **)((char *)&v11->mNext + v12 + v15);
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
      v19 = &v5->mData;
      v20 = v5->mData.mOffset;
      if ( v20 && (UFG::qOffset64<UFG::qOffset64<ITrack *> *> *)((char *)v19 + v20) )
        operator delete[]((char *)v19 + v20);
      if ( v10 )
        v21 = (char *)v10 - (char *)v19;
      else
        v21 = 0i64;
      v19->mOffset = v21;
    }
    if ( (unsigned int)v6 < v4 )
    {
      v22 = 8 * v6;
      v23 = v4 - (unsigned int)v6;
      do
      {
        v24 = v5->mData.mOffset;
        if ( v24 )
          v25 = (signed __int64)&v5->mData + v24;
        else
          v25 = 0i64;
        *(_QWORD *)(v22 + v25) = 0i64;
        v22 += 8i64;
        --v23;
      }
      while ( v23 );
    }
  }
}

// File Line: 290
// RVA: 0x26DB80
signed __int64 __fastcall BinPtrArray<ActionNode,0,0>::Find(BinPtrArray<ActionNode,0,0> *this, ActionNode *item)
{
  ActionNode *v2; // rbx
  signed __int64 result; // rax
  unsigned int v4; // er10
  __int64 v5; // r9
  UFG::qOffset64<UFG::qOffset64<ActionNode *> *> *v6; // r11
  __int64 v7; // r8
  char *v8; // rcx
  char *v9; // rdx
  ActionNode *v10; // rcx

  v2 = item;
  result = 0i64;
  v4 = this->mCount & 0x7FFFFFFF;
  if ( !v4 )
    return 0xFFFFFFFFi64;
  v5 = this->mData.mOffset;
  v6 = &this->mData;
  v7 = 0i64;
  while ( 1 )
  {
    v8 = (char *)(v5 ? (UFG::qOffset64<UFG::qOffset64<ActionNode *> *> *)((char *)v6 + v5) : 0i64);
    v9 = &v8[v7];
    v10 = *(ActionNode **)&v8[v7];
    if ( v10 )
      v10 = (ActionNode *)((char *)v10 + (_QWORD)v9);
    if ( v2 == v10 )
      break;
    result = (unsigned int)(result + 1);
    v7 += 8i64;
    if ( (unsigned int)result >= v4 )
      return 0xFFFFFFFFi64;
  }
  return result;
}

// File Line: 327
// RVA: 0x3ADE50
bool __fastcall BinPtrArray<UELNode,0,0>::Remove(BinPtrArray<ActionNode,0,0> *this, ActionNode *item)
{
  ActionNode *v2; // r11
  BinPtrArray<ActionNode,0,0> *v3; // rsi
  int v4; // edx
  int v5; // er10
  __int64 v6; // r9
  __int64 v7; // r8
  signed __int64 v8; // rax
  signed __int64 v9; // rcx
  __int64 v10; // rax
  ActionNode *v11; // rax
  signed __int64 v13; // rcx
  __int64 v14; // rax
  signed __int64 v15; // rdi

  v2 = item;
  v3 = this;
  v4 = 0;
  v5 = this->mCount & 0x7FFFFFFF;
  if ( !v5 )
    return 0;
  v6 = this->mData.mOffset;
  v7 = 0i64;
  while ( 1 )
  {
    v8 = (signed __int64)(v6 ? (UFG::qOffset64<UFG::qOffset64<ActionNode *> *> *)((char *)&v3->mData + v6) : 0i64);
    v9 = v7 + v8;
    v10 = *(_QWORD *)(v7 + v8);
    v11 = (ActionNode *)(v10 ? v9 + v10 : 0i64);
    if ( v2 == v11 )
      break;
    ++v4;
    v7 += 8i64;
    if ( v4 >= (unsigned int)v5 )
      return 0;
  }
  if ( v4 < 0 )
    return 0;
  if ( v4 >= v5 )
    return 0;
  if ( v6 )
    v13 = (signed __int64)&v3->mData + v6;
  else
    v13 = 0i64;
  v14 = *(_QWORD *)(v13 + 8i64 * v4);
  v15 = v14 + v13 + 8i64 * v4;
  if ( !v14 )
    v15 = 0i64;
  BinPtrArray<ActionNode,0,0>::_StableRemove(v3, v4);
  return v15 != 0;
}

// File Line: 415
// RVA: 0x26B280
void __fastcall BinPtrArray<ActionNode,0,0>::Add(BinPtrArray<Condition,1,0> *this, Condition *item, const char *reason)
{
  Condition *v3; // rsi
  BinPtrArray<Condition,1,0> *v4; // rdi
  __int64 v5; // r14
  unsigned int v6; // ebx
  unsigned int v7; // edx
  __int64 v8; // rax
  signed __int64 v9; // rcx
  char *v10; // rcx

  v5 = (unsigned int)this->mCount;
  v3 = item;
  v4 = this;
  LODWORD(v5) = v5 & 0x7FFFFFFF;
  v6 = v5 + 1;
  if ( (signed int)v5 + 1 > (unsigned int)v5 )
  {
    v7 = 1;
    if ( (_DWORD)v5 )
      v7 = 2 * v5;
    for ( ; v7 < v6; v7 *= 2 )
      ;
    if ( v7 - v6 > 0x10000 )
      v7 = v5 + 65537;
    BinPtrArray<Condition,1,0>::Reallocate((BinPtrArray<ITrack,1,0> *)this, v7, reason);
  }
  v4->mCount &= 0x80000000;
  v4->mCount |= v6 & 0x7FFFFFFF;
  v8 = v4->mData.mOffset;
  if ( v8 )
    v9 = (signed __int64)&v4->mData + v8;
  else
    v9 = 0i64;
  v10 = (char *)(v9 + 8 * v5);
  if ( v3 )
    *(_QWORD *)v10 = (char *)v3 - v10;
  else
    *(_QWORD *)v10 = 0i64;
}

// File Line: 541
// RVA: 0x2679A0
void __fastcall qNodeOrderChange<ActionNode,0>(BinPtrArray<ActionNode,0,0> *list, ActionNode *item, bool increase)
{
  __int64 v3; // r10
  bool v4; // r11
  BinPtrArray<ActionNode,0,0> *v5; // rbx
  int v6; // edi
  __int64 v7; // r9
  __int64 v8; // r8
  signed __int64 v9; // rax
  signed __int64 v10; // rcx
  ActionNode *v11; // rax
  signed __int64 v12; // rcx
  __int64 v13; // rax
  signed __int64 v14; // rcx
  __int64 v15; // r11
  signed __int64 v16; // rdx
  __int64 v17; // rax
  signed __int64 v18; // rdx
  signed __int64 v19; // r8
  signed __int64 v20; // r9
  __int64 v21; // rax
  signed __int64 v22; // rdx
  _QWORD *v23; // rdx

  v3 = 0i64;
  v4 = increase;
  v5 = list;
  v6 = list->mCount & 0x7FFFFFFF;
  if ( v6 )
  {
    v7 = list->mData.mOffset;
    v8 = 0i64;
    while ( 1 )
    {
      if ( v7 )
        v9 = (signed __int64)&v5->mData + v7;
      else
        v9 = 0i64;
      v10 = v8 + v9;
      v11 = *(ActionNode **)(v8 + v9);
      if ( v11 )
        v11 = (ActionNode *)((char *)v11 + v10);
      if ( item == v11 )
        break;
      v3 = (unsigned int)(v3 + 1);
      v8 += 8i64;
      if ( (unsigned int)v3 >= v6 )
        return;
    }
    if ( (_DWORD)v3 != -1 )
    {
      if ( v7 )
        v12 = (signed __int64)&v5->mData + v7;
      else
        v12 = 0i64;
      v13 = *(_QWORD *)(v12 + 8 * v3);
      if ( v13 )
        v14 = v13 + v12 + 8 * v3;
      else
        v14 = 0i64;
      if ( v4 )
      {
        v15 = (unsigned int)(v3 - 1);
        if ( (signed int)v15 < 0 )
          return;
      }
      else
      {
        v15 = (unsigned int)(v3 + 1);
        if ( (signed int)v15 >= v6 )
          return;
      }
      if ( v7 )
        v16 = (signed __int64)&v5->mData + v7;
      else
        v16 = 0i64;
      v17 = *(_QWORD *)(v16 + 8 * v15);
      if ( v17 )
        v18 = v17 + v16 + 8 * v15;
      else
        v18 = 0i64;
      if ( v7 )
        v19 = (signed __int64)&v5->mData + v7;
      else
        v19 = 0i64;
      v20 = v19 + 8i64 * (signed int)v3;
      if ( v18 )
        v18 -= v20;
      *(_QWORD *)v20 = v18;
      v21 = v5->mData.mOffset;
      if ( v21 )
        v22 = (signed __int64)&v5->mData + v21;
      else
        v22 = 0i64;
      v23 = (_QWORD *)(v22 + 8i64 * (signed int)v15);
      if ( v14 )
        *v23 = v14 - (_QWORD)v23;
      else
        *v23 = 0i64;
    }
  }
}

