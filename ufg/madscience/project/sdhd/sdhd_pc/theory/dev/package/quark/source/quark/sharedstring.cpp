// File Line: 22
// RVA: 0x172530
UFG::qTreeRB<UFG::qSharedStringData,UFG::qSharedStringData,0> *__fastcall UFG::GetStringDataList()
{
  if ( (_S4_4 & 1) == 0 )
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
  UFG::qTreeRB<UFG::qSharedStringData,UFG::qSharedStringData,0> *StringDataList; // rax

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
    StringDataList = UFG::GetStringDataList();
    UFG::qBaseTreeRB::Add(&StringDataList->mTree, (UFG::qBaseNodeRB *)v2);
    return sEmptyString;
  }
  return result;
}

// File Line: 104
// RVA: 0x161EF0
void __fastcall UFG::qSharedString::qSharedString(UFG::qSharedString *this)
{
  UFG::qSharedStringData *EmptyString; // rax

  this->mText = 0i64;
  this->mText = (char *)&UFG::qSharedStringData::GetEmptyString()[1];
  EmptyString = UFG::qSharedStringData::GetEmptyString();
  ++EmptyString->mRefCount;
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
  UFG::qSharedStringData *EmptyString; // rax
  int v4; // eax
  UFG::qPrintInfo info; // [rsp+30h] [rbp-4138h] BYREF
  char text[16392]; // [rsp+160h] [rbp-4008h] BYREF
  va_list va; // [rsp+4180h] [rbp+18h] BYREF

  va_start(va, format);
  this->mText = 0i64;
  EmptyString = UFG::qSharedStringData::GetEmptyString();
  UFG::qSharedString::SetData(this, EmptyString);
  if ( format )
  {
    info.mStdOutBuffer.NumChars = 0;
    info.OutStringLen = 0x4000;
    info.PrintChannel = -1;
    info.OutString = text;
    info.StdOut = 0;
    v4 = UFG::qPrintEngine(&info, format, va);
    if ( v4 )
      UFG::qSharedString::Set(this, text, v4, 0i64, 0);
  }
}

// File Line: 146
// RVA: 0x164380
void __fastcall UFG::qSharedString::~qSharedString(UFG::qSharedString *this)
{
  char *mText; // rbx
  unsigned int v2; // eax
  UFG::qBaseTreeVariableRB<unsigned __int64> *StringDataList; // rax

  mText = this->mText;
  v2 = *((_DWORD *)this->mText - 4);
  if ( v2 > 1 )
  {
    *((_DWORD *)mText - 4) = v2 - 1;
  }
  else
  {
    StringDataList = (UFG::qBaseTreeVariableRB<unsigned __int64> *)UFG::GetStringDataList();
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      StringDataList,
      (UFG::qBaseNodeVariableRB<unsigned __int64> *)(mText - 48));
    *((_WORD *)mText - 4) = 0x1FFF;
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, mText - 48);
  }
}

// File Line: 163
// RVA: 0x17CCB0
void __fastcall UFG::qSharedString::SetData(UFG::qSharedString *this, UFG::qSharedStringData *data)
{
  char *mText; // rdi
  unsigned int v5; // eax
  UFG::qBaseTreeVariableRB<unsigned __int64> *StringDataList; // rax

  if ( data != (UFG::qSharedStringData *)this->mText - 1 )
  {
    if ( data )
      ++data->mRefCount;
    mText = this->mText;
    if ( this->mText )
    {
      v5 = *((_DWORD *)mText - 4);
      if ( v5 > 1 )
      {
        *((_DWORD *)mText - 4) = v5 - 1;
      }
      else
      {
        StringDataList = (UFG::qBaseTreeVariableRB<unsigned __int64> *)UFG::GetStringDataList();
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
          StringDataList,
          (UFG::qBaseNodeVariableRB<unsigned __int64> *)(mText - 48));
        *((_WORD *)mText - 4) = 0x1FFF;
        UFG::qMemoryPool::Free(UFG::gMainMemoryPool, mText - 48);
      }
    }
    this->mText = (char *)&data[1];
  }
}

// File Line: 183
// RVA: 0x17C710
void __fastcall UFG::qSharedString::Set(
        UFG::qSharedString *this,
        const char *text,
        int length,
        const char *textb,
        int lengthb)
{
  unsigned __int64 v6; // r13
  const char *v7; // r14
  unsigned int v9; // ebx
  unsigned int v10; // r8d
  const char *v11; // rdx
  unsigned int v12; // r8d
  UFG::qTreeRB<UFG::qSharedStringData,UFG::qSharedStringData,0> *StringDataList; // rax
  UFG::qTreeRB<UFG::qSharedStringData,UFG::qSharedStringData,0> *EmptyString; // rax
  UFG::qTreeRB<UFG::qSharedStringData,UFG::qSharedStringData,0> *v15; // rdi
  char *mText; // rbx
  unsigned int v17; // eax
  UFG::qBaseTreeVariableRB<unsigned __int64> *v18; // rax
  __int64 v19; // rdi
  UFG::qMemoryPool *v20; // rcx
  UFG::allocator::free_link *v21; // rax
  UFG::allocator::free_link *v22; // rdi
  char *v23; // rbp
  UFG::allocator::free_link *v24; // rcx
  signed __int64 v25; // r14
  unsigned __int64 v26; // rdx
  __int64 v27; // rdx
  char *v28; // rcx
  const char *v29; // rsi
  UFG::qTreeRB<UFG::qSharedStringData,UFG::qSharedStringData,0> *v30; // rax
  char *v31; // rbx
  unsigned int v32; // eax
  UFG::qBaseTreeVariableRB<unsigned __int64> *v33; // rax
  __int64 v34; // [rsp+88h] [rbp+10h]

  v6 = length;
  v7 = text;
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
  if ( v9 - 1 > 0xFFFFFFFD )
  {
    EmptyString = (UFG::qTreeRB<UFG::qSharedStringData,UFG::qSharedStringData,0> *)UFG::qSharedStringData::GetEmptyString();
  }
  else
  {
    StringDataList = UFG::GetStringDataList();
    EmptyString = UFG::qTreeRB<UFG::qFileMapLocation,UFG::qFileMapLocation,1>::Get(StringDataList, v9);
  }
  v15 = EmptyString;
  if ( EmptyString )
  {
    if ( EmptyString != (UFG::qTreeRB<UFG::qSharedStringData,UFG::qSharedStringData,0> *)(this->mText - 48) )
    {
      ++LODWORD(EmptyString->mTree.mNULL.mParent);
      mText = this->mText;
      if ( this->mText )
      {
        v17 = *((_DWORD *)mText - 4);
        if ( v17 > 1 )
        {
          *((_DWORD *)mText - 4) = v17 - 1;
        }
        else
        {
          v18 = (UFG::qBaseTreeVariableRB<unsigned __int64> *)UFG::GetStringDataList();
          UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
            v18,
            (UFG::qBaseNodeVariableRB<unsigned __int64> *)(mText - 48));
          *((_WORD *)mText - 4) = 0x1FFF;
          UFG::qMemoryPool::Free(UFG::gMainMemoryPool, mText - 48);
        }
      }
      this->mText = (char *)&v15->mTree.mNULL.mChild[1];
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
    v23 = (char *)&v21[6];
    if ( (int)v6 > 0 )
    {
      v24 = v21 + 6;
      v25 = v7 - v23;
      v26 = v6;
      do
      {
        LOBYTE(v24->mNext) = *((_BYTE *)&v24->mNext + v25);
        v24 = (UFG::allocator::free_link *)((char *)v24 + 1);
        --v26;
      }
      while ( v26 );
    }
    if ( textb )
    {
      v27 = lengthb;
      if ( lengthb > 0 )
      {
        v28 = &v23[v6];
        v29 = (const char *)(&textb[-v6] - v23);
        do
        {
          *v28 = v28[(_QWORD)v29];
          ++v28;
          --v27;
        }
        while ( v27 );
      }
    }
    v23[v34] = 0;
    LOWORD(v21[5].mNext) = lengthb + v6;
    v30 = UFG::GetStringDataList();
    UFG::qBaseTreeRB::Add(&v30->mTree, (UFG::qBaseNodeRB *)v22);
    if ( v22 != (UFG::allocator::free_link *)this->mText - 6 )
    {
      ++LODWORD(v22[4].mNext);
      v31 = this->mText;
      if ( this->mText )
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
      this->mText = v23;
    }
  }
}

// File Line: 278
// RVA: 0x17C6D0
void __fastcall UFG::qSharedString::Set(UFG::qSharedString *this, const char *text)
{
  const char *v2; // rax
  int v4; // eax

  if ( text )
  {
    v2 = text;
    while ( *v2++ )
      ;
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
  int v3; // eax
  const char *v4; // rax

  if ( text )
  {
    v4 = text;
    while ( *v4++ )
      ;
    v3 = (_DWORD)v4 - (_DWORD)text - 1;
  }
  else
  {
    v3 = 0;
  }
  UFG::qSharedString::Set(this, text, v3, 0i64, 0);
  return this;
}

