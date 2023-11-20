// File Line: 144
// RVA: 0x15DE50
void __fastcall ActionPath::Append(ActionPath *this, const char *value)
{
  ActionPath *v2; // r14
  char *i; // rax
  char *j; // rdi
  char v5; // r15
  int v6; // eax
  int v7; // edx
  int v8; // ebx
  __int64 v9; // rbp
  unsigned int v10; // esi
  unsigned int v11; // edx
  __int64 v12; // rax
  signed __int64 v13; // rcx
  char dest; // [rsp+20h] [rbp-218h]

  v2 = this;
  UFG::qStringCopy(&dest, 0x7FFFFFFF, value, -1);
  for ( i = &dest; *i == 92 || *i == 47; ++i )
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
    v7 = v2->mPath.mCount;
    v9 = (unsigned int)v2->mPath.mCount;
    v8 = v6;
    LODWORD(v9) = v9 & 0x7FFFFFFF;
    v10 = v9 + 1;
    if ( (unsigned int)(v9 + 1) > v2->mPath.mCount )
    {
      if ( v7 )
        v11 = 2 * v7;
      else
        v11 = 1;
      for ( ; v11 < v10; v11 *= 2 )
        ;
      if ( v11 - v10 > 0x10000 )
        v11 = v9 + 65537;
      BinArray<ActionID,0>::Reallocate(&v2->mPath, v11, "ActionPath::Append");
    }
    v2->mPath.mCount &= 0x80000000;
    v2->mPath.mCount |= v10 & 0x7FFFFFFF;
    v12 = v2->mPath.mData.mOffset;
    if ( v12 )
      v13 = (signed __int64)&v2->mPath.mData + v12;
    else
      v13 = 0i64;
    *(_DWORD *)(v13 + 4 * v9) = v8;
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
  unsigned int v2; // er9
  unsigned int v3; // er8
  __int64 v4; // r10
  __int64 v5; // r11
  UFG::qOffset64<ActionID *> *v6; // rdi
  UFG::qOffset64<ActionID *> *v7; // rbx
  __int64 v8; // rcx
  char *v9; // rax
  char *v10; // rdx

  v2 = this->mPath.mCount & 0x7FFFFFFF;
  if ( v2 != (other->mPath.mCount & 0x7FFFFFFF) )
    return 0;
  v3 = 0;
  if ( !v2 )
    return 1;
  v4 = other->mPath.mData.mOffset;
  v5 = this->mPath.mData.mOffset;
  v6 = &this->mPath.mData;
  v7 = &other->mPath.mData;
  v8 = 0i64;
  while ( 1 )
  {
    v9 = (char *)(v4 ? (UFG::qOffset64<ActionID *> *)((char *)v7 + v4) : 0i64);
    v10 = (char *)(v5 ? (UFG::qOffset64<ActionID *> *)((char *)v6 + v5) : 0i64);
    if ( *(_DWORD *)&v10[v8] != *(_DWORD *)&v9[v8] )
      break;
    ++v3;
    v8 += 4i64;
    if ( v3 >= v2 )
      return 1;
  }
  return 0;
}

// File Line: 242
// RVA: 0x26ECE0
char *__fastcall ActionPath::GetString_DBG(ActionPath *this)
{
  ActionPath *v1; // rsi
  int v3; // eax
  unsigned int v4; // eax
  unsigned int v5; // eax
  __int64 v6; // rax
  UFG::qString *v7; // rdi
  __int64 v8; // rcx
  _DWORD *v9; // rdx
  _DWORD *v10; // rdx
  bool v11; // zf
  const char *v12; // rdx
  __int64 v13; // rbx
  __int64 v14; // rax
  signed __int64 v15; // rcx
  char *v16; // rax

  v1 = this;
  if ( !(this->mPath.mCount & 0x7FFFFFFF) )
    return &customWorldMapCaption;
  v3 = `ActionPath::GetString_DBG::`5::`local static guard;
  if ( !(`ActionPath::GetString_DBG::`5::`local static guard & 1) )
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
  if ( !(v3 & 2) )
  {
    `ActionPath::GetString_DBG::`5::`local static guard = v3 | 2;
    v4 = UFG::qStringHashUpper32(".", 0xFFFFFFFF);
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&`ActionPath::GetString_DBG::`5::symDot, v4);
    atexit(`ActionPath::GetString_DBG::`5::`dynamic atexit destructor for symDot);
    v3 = `ActionPath::GetString_DBG::`5::`local static guard;
  }
  if ( !(v3 & 4) )
  {
    `ActionPath::GetString_DBG::`5::`local static guard = v3 | 4;
    v5 = UFG::qStringHashUpper32("..", 0xFFFFFFFF);
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&`ActionPath::GetString_DBG::`5::symDotDot, v5);
    atexit(`ActionPath::GetString_DBG::`5::`dynamic atexit destructor for symDotDot);
  }
  v6 = ((_BYTE)`ActionPath::GetString_DBG::`5::sPathIndex + 1) & 7;
  `ActionPath::GetString_DBG::`5::sPathIndex = ((_BYTE)`ActionPath::GetString_DBG::`5::sPathIndex + 1) & 7;
  v7 = &`ActionPath::GetString_DBG::`5::sPathHack[v6];
  v8 = v1->mPath.mData.mOffset;
  if ( v8 )
    v9 = (_DWORD *)((char *)&v1->mPath.mData + v8);
  else
    v9 = 0i64;
  if ( *v9 == `ActionPath::GetString_DBG::`5::symDot.mUID
    || (!v8 ? (v10 = 0i64) : (v10 = (_DWORD *)((char *)&v1->mPath.mData + v8)),
        v11 = *v10 == `ActionPath::GetString_DBG::`5::symDotDot.mUID,
        v12 = "\\",
        v11) )
  {
    v12 = &customWorldMapCaption;
  }
  UFG::qString::Set(v7, v12);
  v13 = 0i64;
  if ( v1->mPath.mCount & 0x7FFFFFFF )
  {
    do
    {
      v14 = v1->mPath.mData.mOffset;
      if ( v14 )
        v15 = (signed __int64)&v1->mPath.mData + v14;
      else
        v15 = 0i64;
      v16 = UFG::qSymbolRegistry::Get(*(_DWORD *)(v15 + 4 * v13));
      UFG::qString::operator+=(v7, v16);
      if ( (unsigned int)v13 < (v1->mPath.mCount & 0x7FFFFFFFu) - 1 )
        UFG::qString::operator+=(v7, "\\");
      v13 = (unsigned int)(v13 + 1);
    }
    while ( (unsigned int)v13 < (v1->mPath.mCount & 0x7FFFFFFFu) );
  }
  return v7->mData;
}

