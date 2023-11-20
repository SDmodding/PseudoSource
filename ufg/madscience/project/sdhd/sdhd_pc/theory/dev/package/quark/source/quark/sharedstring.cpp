// File Line: 22
// RVA: 0x172530
UFG::qTreeRB<UFG::qSharedStringData,UFG::qSharedStringData,0> *__fastcall UFG::GetStringDataList()
{
  if ( !(_S4_4 & 1) )
  {
    _S4_4 |= 1u;
    sStringData.mTree.mNULL.mChild[0] = &sStringData.mTree.mNULL;
    sStringData.mTree.mNULL.mChild[1] = &sStringData.mTree.mNULL;
    sStringData.mTree.mNULL.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)&sStringData.mTree.mNULL & 0xFFFFFFFFFFFFFFFEui64);
    sStringData.mTree.mNULL.mUID = 0;
    sStringData.mTree.mRoot.mChild[0] = &sStringData.mTree.mNULL;
    sStringData.mTree.mRoot.mChild[1] = &sStringData.mTree.mNULL;
    sStringData.mTree.mRoot.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)&sStringData.mTree.mNULL & 0xFFFFFFFFFFFFFFFEui64);
    sStringData.mTree.mRoot.mUID = -1;
    sStringData.mTree.mCount = 0;
    atexit(UFG::GetStringDataList_::_2_::_dynamic_atexit_destructor_for__sStringData__);
  }
  return &sStringData;
}

// File Line: 83
// RVA: 0x1702D0
UFG::qSharedStringData *__fastcall UFG::qSharedStringData::GetEmptyString()
{
  UFG::qSharedStringData *result; // rax
  UFG::qMemoryPool *v1; // rcx
  UFG::allocator::free_link *v2; // rbx
  UFG::qTreeRB<UFG::qSharedStringData,UFG::qSharedStringData,0> *v3; // rax

  result = sEmptyString;
  if ( !sEmptyString )
  {
    v1 = UFG::gMainMemoryPool;
    if ( !UFG::gMainMemoryPool )
    {
      UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
      v1 = UFG::gMainMemoryPool;
    }
    v2 = UFG::qMemoryPool::Allocate(v1, 0x31ui64, "qSharedString::Set", 0i64, 1u);
    sEmptyString = (UFG::qSharedStringData *)v2;
    if ( v2 )
    {
      v2->mNext = 0i64;
      v2[1].mNext = 0i64;
      v2[2].mNext = 0i64;
      LODWORD(v2[3].mNext) = 0;
      LOWORD(v2[5].mNext) = 0;
      LODWORD(v2[4].mNext) = 0;
      HIDWORD(v2[4].mNext) = -1;
    }
    ++LODWORD(v2[4].mNext);
    LOBYTE(v2[6].mNext) = 0;
    LOWORD(v2[5].mNext) = 0;
    v3 = UFG::GetStringDataList();
    UFG::qBaseTreeRB::Add(&v3->mTree, (UFG::qBaseNodeRB *)v2);
    result = sEmptyString;
  }
  return result;
}

// File Line: 104
// RVA: 0x161EF0
void __fastcall UFG::qSharedString::qSharedString(UFG::qSharedString *this)
{
  UFG::qSharedStringData *v1; // rax

  this->mText = 0i64;
  this->mText = (char *)&UFG::qSharedStringData::GetEmptyString()[1];
  v1 = UFG::qSharedStringData::GetEmptyString();
  ++v1->mRefCount;
}

// File Line: 111
// RVA: 0x161E00
void __fastcall UFG::qSharedString::qSharedString(UFG::qSharedString *this, UFG::qSharedString *text)
{
  this->mText = 0i64;
  UFG::qSharedString::SetData(this, (UFG::qSharedStringData *)text->mText - 1);
}

// File Line: 123
// RVA: 0x161E30
void UFG::qSharedString::qSharedString(UFG::qSharedString *this, const char *format, ...)
{
  UFG::qSharedString *v2; // rbx
  UFG::qSharedStringData *v3; // rax
  int v4; // eax
  UFG::qPrintInfo info; // [rsp+30h] [rbp-4138h]
  char text; // [rsp+160h] [rbp-4008h]
  char *fmt; // [rsp+4178h] [rbp+10h]
  va_list va; // [rsp+4180h] [rbp+18h]

  va_start(va, format);
  fmt = (char *)format;
  v2 = this;
  this->mText = 0i64;
  v3 = UFG::qSharedStringData::GetEmptyString();
  UFG::qSharedString::SetData(v2, v3);
  if ( fmt )
  {
    info.mStdOutBuffer.NumChars = 0;
    info.OutStringLen = 0x4000;
    info.PrintChannel = -1;
    info.OutString = &text;
    info.StdOut = 0;
    v4 = UFG::qPrintEngine(&info, fmt, va);
    if ( v4 )
      UFG::qSharedString::Set(v2, &text, v4, 0i64, 0);
  }
}

// File Line: 146
// RVA: 0x164380
void __fastcall UFG::qSharedString::~qSharedString(UFG::qSharedString *this)
{
  char *v1; // rbx
  unsigned int v2; // eax
  UFG::qBaseTreeVariableRB<unsigned __int64> *v3; // rax

  v1 = this->mText;
  v2 = *((_DWORD *)this->mText - 4);
  if ( v2 > 1 )
  {
    *((_DWORD *)v1 - 4) = v2 - 1;
  }
  else
  {
    v3 = (UFG::qBaseTreeVariableRB<unsigned __int64> *)UFG::GetStringDataList();
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(v3, (UFG::qBaseNodeVariableRB<unsigned __int64> *)(v1 - 48));
    *((_WORD *)v1 - 4) = 0x1FFF;
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v1 - 48);
  }
}

// File Line: 163
// RVA: 0x17CCB0
void __fastcall UFG::qSharedString::SetData(UFG::qSharedString *this, UFG::qSharedStringData *data)
{
  UFG::qSharedStringData *v2; // rbx
  UFG::qSharedString *v3; // rsi
  char *v4; // rdi
  unsigned int v5; // eax
  UFG::qBaseTreeVariableRB<unsigned __int64> *v6; // rax

  v2 = data;
  v3 = this;
  if ( data != (UFG::qSharedStringData *)this->mText - 1 )
  {
    if ( data )
      ++data->mRefCount;
    v4 = this->mText;
    if ( this->mText )
    {
      v5 = *((_DWORD *)v4 - 4);
      if ( v5 > 1 )
      {
        *((_DWORD *)v4 - 4) = v5 - 1;
      }
      else
      {
        v6 = (UFG::qBaseTreeVariableRB<unsigned __int64> *)UFG::GetStringDataList();
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(v6, (UFG::qBaseNodeVariableRB<unsigned __int64> *)(v4 - 48));
        *((_WORD *)v4 - 4) = 0x1FFF;
        UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v4 - 48);
      }
    }
    v3->mText = (char *)&v2[1];
  }
}

// File Line: 183
// RVA: 0x17C710
void __fastcall UFG::qSharedString::Set(UFG::qSharedString *this, const char *text, int length, const char *textb, int lengthb)
{
  const char *v5; // rsi
  unsigned __int64 v6; // r13
  const char *v7; // r14
  UFG::qSharedString *v8; // r15
  signed int v9; // ebx
  unsigned int v10; // er8
  const char *v11; // rdx
  unsigned int v12; // er8
  UFG::qTreeRB<UFG::qSharedStringData,UFG::qSharedStringData,0> *v13; // rax
  UFG::qSharedStringData *v14; // rax
  UFG::qSharedStringData *v15; // rdi
  char *v16; // rbx
  unsigned int v17; // eax
  UFG::qBaseTreeVariableRB<unsigned __int64> *v18; // rax
  __int64 v19; // rdi
  UFG::qMemoryPool *v20; // rcx
  UFG::allocator::free_link *v21; // rax
  UFG::allocator::free_link *v22; // rdi
  signed __int64 v23; // rbp
  UFG::allocator::free_link *v24; // rcx
  const char *v25; // r14
  unsigned __int64 v26; // rdx
  __int64 v27; // rdx
  _BYTE *v28; // rcx
  const char *v29; // rsi
  UFG::qTreeRB<UFG::qSharedStringData,UFG::qSharedStringData,0> *v30; // rax
  char *v31; // rbx
  unsigned int v32; // eax
  UFG::qBaseTreeVariableRB<unsigned __int64> *v33; // rax
  __int64 v34; // [rsp+88h] [rbp+10h]

  v5 = textb;
  v6 = length;
  v7 = text;
  v8 = this;
  v9 = -1;
  if ( text )
  {
    v10 = 0;
    if ( (_DWORD)v6 )
    {
      do
      {
        v9 = (v9 << 8) ^ sCrcTable32[(unsigned __int8)(*text++ ^ HIBYTE(v9))];
        ++v10;
      }
      while ( v10 < v6 );
    }
  }
  if ( textb )
  {
    v11 = textb;
    v12 = 0;
    if ( lengthb )
    {
      do
      {
        v9 = (v9 << 8) ^ sCrcTable32[(unsigned __int8)(*v11++ ^ HIBYTE(v9))];
        ++v12;
      }
      while ( v12 < (unsigned __int64)lengthb );
    }
  }
  if ( (unsigned int)(v9 - 1) > 0xFFFFFFFD )
  {
    v14 = UFG::qSharedStringData::GetEmptyString();
  }
  else
  {
    v13 = UFG::GetStringDataList();
    v14 = UFG::qTreeRB<UFG::qFileMapLocation,UFG::qFileMapLocation,1>::Get(v13, v9);
  }
  v15 = v14;
  if ( v14 )
  {
    if ( v14 != (UFG::qSharedStringData *)v8->mText - 1 )
    {
      ++v14->mRefCount;
      v16 = v8->mText;
      if ( v8->mText )
      {
        v17 = *((_DWORD *)v16 - 4);
        if ( v17 > 1 )
        {
          *((_DWORD *)v16 - 4) = v17 - 1;
        }
        else
        {
          v18 = (UFG::qBaseTreeVariableRB<unsigned __int64> *)UFG::GetStringDataList();
          UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
            v18,
            (UFG::qBaseNodeVariableRB<unsigned __int64> *)(v16 - 48));
          *((_WORD *)v16 - 4) = 0x1FFF;
          UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v16 - 48);
        }
      }
      v8->mText = (char *)&v15[1];
    }
  }
  else
  {
    v19 = (unsigned int)(lengthb + v6);
    v20 = UFG::gMainMemoryPool;
    if ( !UFG::gMainMemoryPool )
    {
      UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
      v20 = UFG::gMainMemoryPool;
    }
    v34 = (unsigned int)v19;
    v21 = UFG::qMemoryPool::Allocate(v20, v19 + 49, "qSharedString::Set", 0i64, 1u);
    v22 = v21;
    if ( v21 )
    {
      v21->mNext = 0i64;
      v21[1].mNext = 0i64;
      v21[2].mNext = 0i64;
      LODWORD(v21[3].mNext) = v9;
      LOWORD(v21[5].mNext) = 0;
      LODWORD(v21[4].mNext) = 0;
      HIDWORD(v21[4].mNext) = -1;
    }
    v23 = (signed __int64)&v21[6];
    if ( (signed int)v6 > 0 )
    {
      v24 = v21 + 6;
      v25 = &v7[-v23];
      v26 = v6;
      do
      {
        LOBYTE(v24->mNext) = *((_BYTE *)&v24->mNext + (_QWORD)v25);
        v24 = (UFG::allocator::free_link *)((char *)v24 + 1);
        --v26;
      }
      while ( v26 );
    }
    if ( v5 )
    {
      v27 = lengthb;
      if ( lengthb > 0 )
      {
        v28 = (_BYTE *)(v23 + v6);
        v29 = &v5[-v6 - v23];
        do
        {
          *v28 = v28[(_QWORD)v29];
          ++v28;
          --v27;
        }
        while ( v27 );
      }
    }
    *(_BYTE *)(v34 + v23) = 0;
    LOWORD(v21[5].mNext) = lengthb + v6;
    v30 = UFG::GetStringDataList();
    UFG::qBaseTreeRB::Add(&v30->mTree, (UFG::qBaseNodeRB *)v22);
    if ( v22 != (UFG::allocator::free_link *)v8->mText - 6 )
    {
      ++LODWORD(v22[4].mNext);
      v31 = v8->mText;
      if ( v8->mText )
      {
        v32 = *((_DWORD *)v31 - 4);
        if ( v32 > 1 )
        {
          *((_DWORD *)v31 - 4) = v32 - 1;
        }
        else
        {
          v33 = (UFG::qBaseTreeVariableRB<unsigned __int64> *)UFG::GetStringDataList();
          UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
            v33,
            (UFG::qBaseNodeVariableRB<unsigned __int64> *)(v31 - 48));
          *((_WORD *)v31 - 4) = 0x1FFF;
          UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v31 - 48);
        }
      }
      v8->mText = (char *)v23;
    }
  }
}

// File Line: 278
// RVA: 0x17C6D0
void __fastcall UFG::qSharedString::Set(UFG::qSharedString *this, const char *text)
{
  const char *v2; // rax
  char v3; // r8
  int v4; // eax

  if ( text )
  {
    v2 = text;
    do
      v3 = *v2++;
    while ( v3 );
    v4 = (_DWORD)v2 - (_DWORD)text - 1;
  }
  else
  {
    v4 = 0;
  }
  UFG::qSharedString::Set(this, text, v4, 0i64, 0);
}

// File Line: 289
// RVA: 0x1647B0
UFG::qSharedString *__fastcall UFG::qSharedString::operator=(UFG::qSharedString *this, const char *text)
{
  UFG::qSharedString *v2; // rbx
  int v3; // eax
  const char *v4; // rax
  char v5; // cl

  v2 = this;
  if ( text )
  {
    v4 = text;
    do
      v5 = *v4++;
    while ( v5 );
    v3 = (_DWORD)v4 - (_DWORD)text - 1;
  }
  else
  {
    v3 = 0;
  }
  UFG::qSharedString::Set(v2, text, v3, 0i64, 0);
  return v2;
}

