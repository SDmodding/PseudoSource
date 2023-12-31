// File Line: 74
// RVA: 0x1467EF0
__int64 UFG::_dynamic_initializer_for__gNullWiseSymbol__()
{
  UFG::qSymbol::qSymbol(&gNullWiseSymbol, 0xFFFFFFFF);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gNullWiseSymbol__);
}

// File Line: 78
// RVA: 0x18CD20
__int64 __fastcall UFG::qWiseSymbolUIDFromString(const char *str, unsigned int prevHash)
{
  int v4; // r10d
  const char *v5; // r10
  int v7; // edx
  char *v8; // rcx
  __int64 v9; // r9
  char v10; // al
  char *i; // rdx
  char v12; // al
  char *v13; // rax
  char *v14; // rcx
  int v15; // edx
  char *v17; // rdx
  char *v18; // r9
  int v19; // ecx
  char v20[1032]; // [rsp+0h] [rbp-408h] BYREF

  if ( str )
  {
    v5 = str;
    while ( *v5++ )
      ;
    v4 = (_DWORD)v5 - (_DWORD)str - 1;
  }
  else
  {
    v4 = 0;
  }
  v7 = 0x7FFFFFFF;
  if ( str )
  {
    v8 = v20;
    v9 = str - v20;
    do
    {
      v10 = (v8++)[v9];
      *(v8 - 1) = v10;
      if ( !v10 )
        break;
      --v7;
    }
    while ( v7 > 1 );
    if ( *(v8 - 1) )
      *v8 = 0;
    if ( v20[0] )
    {
      for ( i = v20; ; ++i )
      {
        v12 = *i;
        if ( *i <= 90 && *i >= 65 )
          v12 += 32;
        *i = v12;
        if ( !v12 )
          break;
      }
    }
  }
  else
  {
    v20[0] = 0;
  }
  v13 = &customCaption;
  v14 = v20;
  v15 = -1;
  while ( *v14 && *v14 == *v13 )
  {
    ++v14;
    ++v13;
    if ( !--v15 )
      return 0i64;
  }
  if ( *v14 == *v13 )
    return 0i64;
  v17 = v20;
  v18 = &v20[v4];
  if ( v20 < v18 )
  {
    do
    {
      v19 = (unsigned __int8)*v17++;
      prevHash = v19 ^ (0x1000193 * prevHash);
    }
    while ( v17 < v18 );
  }
  return prevHash;
}

// File Line: 207
// RVA: 0x16F120
char *__fastcall UFG::qWiseSymbolRegistry::Get(unsigned int uid)
{
  char *v1; // rbx
  int v2; // ecx
  char *result; // rax

  v1 = &byte_14235C000[16 * dword_14235C080];
  UFG::qSPrintf(v1, "0x%08x", uid);
  v2 = dword_14235C080 + 1;
  if ( dword_14235C080 == 7 )
    v2 = 0;
  result = v1;
  dword_14235C080 = v2;
  return result;
}

// File Line: 268
// RVA: 0x180020
char *__fastcall UFG::qWiseSymbol::as_cstr_dbg(UFG::qWiseSymbol *this)
{
  char *v1; // rbx
  int v2; // ecx
  char *result; // rax

  v1 = &byte_14235C000[16 * dword_14235C080];
  UFG::qSPrintf(v1, "0x%08x", this->mUID);
  v2 = dword_14235C080 + 1;
  if ( dword_14235C080 == 7 )
    v2 = 0;
  result = v1;
  dword_14235C080 = v2;
  return result;
}

// File Line: 273
// RVA: 0x18DD30
void __fastcall UFG::qWiseSymbol::set_from_symbol(UFG::qWiseSymbol *this, UFG::qWiseSymbol *sym)
{
  if ( this->mUID != sym->mUID )
    this->mUID = sym->mUID;
}

// File Line: 283
// RVA: 0x18DCF0
void __fastcall UFG::qWiseSymbol::set_from_cstr(UFG::qWiseSymbol *this, const char *pszSymbolString)
{
  unsigned int v3; // eax

  v3 = UFG::qWiseSymbolUIDFromString(pszSymbolString, 0x811C9DC5);
  if ( v3 != this->mUID )
    this->mUID = v3;
}

// File Line: 295
// RVA: 0x1648F0
UFG::qWiseSymbol *__fastcall UFG::qWiseSymbol::operator=(UFG::qWiseSymbol *this, UFG::qWiseSymbol *source)
{
  if ( this->mUID != source->mUID )
    this->mUID = source->mUID;
  return this;
}

// File Line: 307
// RVA: 0x180950
UFG::qWiseSymbol *__fastcall UFG::qWiseSymbol::create_from_string(
        UFG::qWiseSymbol *result,
        const char *pszSymbolString)
{
  result->mUID = UFG::qWiseSymbolUIDFromString(pszSymbolString, 0x811C9DC5);
  return result;
}

// File Line: 319
// RVA: 0x181140
UFG::qWiseSymbol *__fastcall UFG::qWiseSymbol::get_null()
{
  return &gNullWiseSymbol;
}

// File Line: 324
// RVA: 0x18DEA0
void __fastcall UFG::qWiseSymbol::set_null(UFG::qWiseSymbol *this)
{
  if ( this->mUID != gNullWiseSymbol.mUID )
    this->mUID = gNullWiseSymbol.mUID;
}

