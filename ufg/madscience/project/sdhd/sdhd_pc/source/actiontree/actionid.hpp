// File Line: 144
// RVA: 0x15DE50
void __fastcall ActionPath::Append(ActionPath *this, const char *value)
{
  char *i; // rax
  char *j; // rdi
  char v5; // r15
  int v6; // eax
  int mCount; // edx
  int v8; // ebx
  __int64 v9; // rbp
  unsigned int v10; // esi
  unsigned int v11; // edx
  __int64 mOffset; // rax
  char *v13; // rcx
  char dest[512]; // [rsp+20h] [rbp-218h] BYREF

  UFG::qStringCopy(dest, 0x7FFFFFFF, value, -1);
  for ( i = dest; *i == 92 || *i == 47; ++i )
    ;
  while ( *i )
  {
    for ( j = i; *j != 92; ++j )
    {
      if ( *j == 47 )
        break;
      if ( !*j )
        break;
    }
    v5 = *j;
    *j = 0;
    v6 = UFG::qStringHashUpper32(i, 0xFFFFFFFF);
    mCount = this->mPath.mCount;
    v9 = (unsigned int)this->mPath.mCount;
    v8 = v6;
    LODWORD(v9) = v9 & 0x7FFFFFFF;
    v10 = v9 + 1;
    if ( (unsigned int)(v9 + 1) > this->mPath.mCount )
    {
      if ( mCount )
        v11 = 2 * mCount;
      else
        v11 = 1;
      for ( ; v11 < v10; v11 *= 2 )
        ;
      if ( v11 - v10 > 0x10000 )
        v11 = v9 + 65537;
      BinArray<ActionID,0>::Reallocate(&this->mPath, v11, "ActionPath::Append");
    }
    this->mPath.mCount &= 0x80000000;
    this->mPath.mCount |= v10 & 0x7FFFFFFF;
    mOffset = this->mPath.mData.mOffset;
    if ( mOffset )
      v13 = (char *)&this->mPath.mData + mOffset;
    else
      v13 = 0i64;
    *(_DWORD *)&v13[4 * v9] = v8;
    i = j;
    *j = v5;
    while ( *i == 92 || *i == 47 )
      ++i;
  }
}

// File Line: 214
// RVA: 0x2967C0
char __fastcall ActionPath::operator==(ActionPath *this, ActionPath *other)
{
  unsigned int v2; // r9d
  int v3; // r8d
  __int64 mOffset; // r10
  __int64 v5; // r11
  UFG::qOffset64<ActionID *> *p_mData; // rdi
  UFG::qOffset64<ActionID *> *v7; // rbx
  __int64 i; // rcx
  char *v9; // rax
  char *v10; // rdx

  v2 = this->mPath.mCount & 0x7FFFFFFF;
  if ( v2 != (other->mPath.mCount & 0x7FFFFFFF) )
    return 0;
  v3 = 0;
  if ( !v2 )
    return 1;
  mOffset = other->mPath.mData.mOffset;
  v5 = this->mPath.mData.mOffset;
  p_mData = &this->mPath.mData;
  v7 = &other->mPath.mData;
  for ( i = 0i64; ; i += 4i64 )
  {
    v9 = mOffset ? (char *)v7 + mOffset : 0i64;
    v10 = v5 ? (char *)p_mData + v5 : 0i64;
    if ( *(_DWORD *)&v10[i] != *(_DWORD *)&v9[i] )
      break;
    if ( ++v3 >= v2 )
      return 1;
  }
  return 0;
}

// File Line: 242
// RVA: 0x26ECE0
char *__fastcall ActionPath::GetString_DBG(ActionPath *this)
{
  int v3; // eax
  unsigned int v4; // eax
  unsigned int v5; // eax
  __int64 v6; // rax
  UFG::qString *v7; // rdi
  __int64 mOffset; // rcx
  _DWORD *v9; // rdx
  _DWORD *v10; // rdx
  bool v11; // zf
  const char *v12; // rdx
  __int64 v13; // rbx
  __int64 v14; // rax
  char *v15; // rcx
  char *v16; // rax

  if ( (this->mPath.mCount & 0x7FFFFFFF) == 0 )
    return &customCaption;
  v3 = `ActionPath::GetString_DBG::`5::`local static guard;
  if ( (`ActionPath::GetString_DBG::`5::`local static guard & 1) == 0 )
  {
    `ActionPath::GetString_DBG::`5::`local static guard |= 1u;
    `eh vector constructor iterator(
      `ActionPath::GetString_DBG::`5::sPathHack,
      0x28ui64,
      8,
      (void (__fastcall *)(void *))UFG::qString::qString);
    atexit(`ActionPath::GetString_DBG::`5::`dynamic atexit destructor for sPathHack);
    v3 = `ActionPath::GetString_DBG::`5::`local static guard;
  }
  if ( (v3 & 2) == 0 )
  {
    `ActionPath::GetString_DBG::`5::`local static guard = v3 | 2;
    v4 = UFG::qStringHashUpper32(".", -1);
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&`ActionPath::GetString_DBG::`5::symDot, v4);
    atexit(`ActionPath::GetString_DBG::`5::`dynamic atexit destructor for symDot);
    v3 = `ActionPath::GetString_DBG::`5::`local static guard;
  }
  if ( (v3 & 4) == 0 )
  {
    `ActionPath::GetString_DBG::`5::`local static guard = v3 | 4;
    v5 = UFG::qStringHashUpper32("..", -1);
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&`ActionPath::GetString_DBG::`5::symDotDot, v5);
    atexit(`ActionPath::GetString_DBG::`5::`dynamic atexit destructor for symDotDot);
  }
  v6 = ((_BYTE)`ActionPath::GetString_DBG::`5::sPathIndex + 1) & 7;
  `ActionPath::GetString_DBG::`5::sPathIndex = ((_BYTE)`ActionPath::GetString_DBG::`5::sPathIndex + 1) & 7;
  v7 = &`ActionPath::GetString_DBG::`5::sPathHack[v6];
  mOffset = this->mPath.mData.mOffset;
  if ( mOffset )
    v9 = (_DWORD *)((char *)&this->mPath.mData + mOffset);
  else
    v9 = 0i64;
  if ( *v9 == `ActionPath::GetString_DBG::`5::symDot.mUID
    || (!mOffset ? (v10 = 0i64) : (v10 = (_DWORD *)((char *)&this->mPath.mData + mOffset)),
        v11 = *v10 == `ActionPath::GetString_DBG::`5::symDotDot.mUID,
        v12 = "\\",
        v11) )
  {
    v12 = &customCaption;
  }
  UFG::qString::Set(v7, v12);
  v13 = 0i64;
  if ( (this->mPath.mCount & 0x7FFFFFFF) != 0 )
  {
    do
    {
      v14 = this->mPath.mData.mOffset;
      if ( v14 )
        v15 = (char *)&this->mPath.mData + v14;
      else
        v15 = 0i64;
      v16 = UFG::qSymbolRegistry::Get(*(_DWORD *)&v15[4 * v13]);
      UFG::qString::operator+=(v7, v16);
      if ( (unsigned int)v13 < (this->mPath.mCount & 0x7FFFFFFFu) - 1 )
        UFG::qString::operator+=(v7, "\\");
      v13 = (unsigned int)(v13 + 1);
    }
    while ( (unsigned int)v13 < (this->mPath.mCount & 0x7FFFFFFFu) );
  }
  return v7->mData;
}

