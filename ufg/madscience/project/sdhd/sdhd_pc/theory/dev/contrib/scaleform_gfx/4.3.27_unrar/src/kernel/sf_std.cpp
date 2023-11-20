// File Line: 106
// RVA: 0x9AD810
wchar_t *__fastcall Scaleform::SFwcsncpy(wchar_t *dest, unsigned __int64 destsize, const wchar_t *src, unsigned __int64 count)
{
  wchar_t *v4; // rbx

  v4 = dest;
  wcsncpy_s(dest, destsize, src, count);
  return v4;
}

// File Line: 146
// RVA: 0x9AD800
unsigned __int64 __fastcall Scaleform::SFwcslen(const wchar_t *str)
{
  unsigned __int64 result; // rax

  result = -1i64;
  do
    ++result;
  while ( str[result] );
  return result;
}

// File Line: 219
// RVA: 0x9AD630
long double __fastcall Scaleform::SFstrtod(const char *string, char **tailptr)
{
  char **v2; // rsi
  const char *v3; // rbx
  char v4; // di
  char *v5; // rax
  char *v6; // rcx
  char _Dst; // [rsp+20h] [rbp-168h]

  v2 = tailptr;
  v3 = string;
  v4 = *localeconv()->decimal_point;
  if ( v4 == 46 )
  {
    v6 = (char *)v3;
  }
  else
  {
    strcpy_s(&_Dst, 0x15Cui64, v3);
    v5 = &_Dst;
    if ( _Dst )
    {
      while ( *v5 != 46 )
      {
        if ( !*++v5 )
        {
          v6 = &_Dst;
          return strtod(v6, v2);
        }
      }
      *v5 = v4;
    }
    v6 = &_Dst;
  }
  return strtod(v6, v2);
}

// File Line: 1024
// RVA: 0x9AD760
__int64 __fastcall Scaleform::SFtowupper(wchar_t charCode)
{
  unsigned __int16 v1; // r9
  unsigned __int64 v2; // rax
  int v3; // er10
  signed __int64 v4; // r8
  int v5; // eax
  signed __int64 v6; // rax
  signed __int64 v7; // rcx

  v1 = charCode;
  v2 = (unsigned __int64)charCode >> 8;
  v3 = UnicodeToUpperBits[v2];
  if ( !UnicodeToUpperBits[v2] )
    return charCode;
  v4 = 0i64;
  if ( v3 != 1 )
  {
    v5 = UnicodeToUpperBits[v3 + (((unsigned int)charCode >> 4) & 0xF)];
    if ( !_bittest(&v5, charCode & 0xF) )
      return charCode;
  }
  v6 = 640i64;
  do
  {
    v7 = (v6 >> 1) + v4;
    if ( UnicodeToUpperTable[v7].Key >= v1 )
    {
      v6 >>= 1;
    }
    else
    {
      v4 = v7 + 1;
      v6 += -1 - (v6 >> 1);
    }
  }
  while ( v6 > 0 );
  return (unsigned __int16)word_1418AC562[2 * v4];
}

// File Line: 1042
// RVA: 0x9AD6C0
__int64 __fastcall Scaleform::SFtowlower(wchar_t charCode)
{
  unsigned __int16 v1; // r9
  unsigned __int64 v2; // rax
  int v3; // er10
  signed __int64 v4; // r8
  int v5; // eax
  signed __int64 v6; // rax
  signed __int64 v7; // rcx

  v1 = charCode;
  v2 = (unsigned __int64)charCode >> 8;
  v3 = UnicodeToLowerBits[v2];
  if ( !UnicodeToLowerBits[v2] )
    return charCode;
  v4 = 0i64;
  if ( v3 != 1 )
  {
    v5 = UnicodeToLowerBits[v3 + (((unsigned int)charCode >> 4) & 0xF)];
    if ( !_bittest(&v5, charCode & 0xF) )
      return charCode;
  }
  v6 = 676i64;
  do
  {
    v7 = (v6 >> 1) + v4;
    if ( UnicodeToLowerTable[v7].Key >= v1 )
    {
      v6 >>= 1;
    }
    else
    {
      v4 = v7 + 1;
      v6 += -1 - (v6 >> 1);
    }
  }
  while ( v6 > 0 );
  return (unsigned __int16)word_1418ACF72[2 * v4];
}

