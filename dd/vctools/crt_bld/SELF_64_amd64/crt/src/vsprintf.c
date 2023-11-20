// File Line: 107
// RVA: 0x12B2E74
__int64 __fastcall vsnprintf_helper(int (__fastcall *outfn)(_iobuf *, const char *, localeinfo_struct *, char *), char *string, unsigned __int64 count, const char *format, localeinfo_struct *plocinfo, char *ap)
{
  int v6; // ebx
  unsigned __int64 v7; // r14
  int (__fastcall *v8)(_iobuf *, const char *, localeinfo_struct *, char *); // r15
  char *v9; // rsi
  const char *v10; // rdi
  __int64 result; // rax
  int v12; // eax
  unsigned int v13; // edi
  bool v14; // sf
  _iobuf str; // [rsp+20h] [rbp-30h]

  v6 = 0;
  v7 = count;
  v8 = outfn;
  v9 = string;
  v10 = format;
  str._ptr = 0i64;
  memset(&str._cnt, 0, 0x28ui64);
  if ( !v10 || v7 && !v9 )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
  v12 = v7;
  if ( v7 > 0x7FFFFFFF )
    v12 = 0x7FFFFFFF;
  str._flag = 66;
  str._base = v9;
  str._ptr = v9;
  str._cnt = v12;
  result = v8(&str, v10, plocinfo, ap);
  v13 = result;
  if ( v9 )
  {
    if ( (signed int)result >= 0 )
    {
      if ( --str._cnt >= 0 )
      {
        *str._ptr = 0;
        return v13;
      }
      if ( flsbuf(0, &str) != -1 )
        return v13;
    }
    v14 = str._cnt < 0;
    v9[v7 - 1] = 0;
    LOBYTE(v6) = !v14;
    result = (unsigned int)(v6 - 2);
  }
  return result;
}

// File Line: 172
// RVA: 0x12B3204
signed __int64 __fastcall vsprintf(char *string, const char *format, char *ap)
{
  return vsprintf_l(string, format, 0i64, ap);
}

// File Line: 187
// RVA: 0x12B3FD4
int __fastcall vsnprintf(char *string, unsigned __int64 count, const char *format, char *ap)
{
  return vsnprintf_l(string, count, format, 0i64, ap);
}

// File Line: 229
// RVA: 0x12B30C4
__int64 __fastcall vsprintf_s_l(char *string, unsigned __int64 sizeInBytes, const char *format, localeinfo_struct *plocinfo, char *ap)
{
  char *v5; // rbx
  __int64 result; // rax

  v5 = string;
  if ( !format || !string || !sizeInBytes )
  {
    *errno() = 22;
    goto LABEL_9;
  }
  result = vsnprintf_helper(output_s_l, string, sizeInBytes, format, plocinfo, ap);
  if ( (signed int)result < 0 )
    *v5 = 0;
  if ( (_DWORD)result == -2 )
  {
    *errno() = 34;
LABEL_9:
    invalid_parameter_noinfo();
    result = 0xFFFFFFFFi64;
  }
  return result;
}

// File Line: 260
// RVA: 0x12B3134
__int64 __fastcall vsprintf_s(char *string, unsigned __int64 sizeInBytes, const char *format, char *ap)
{
  return vsprintf_s_l(string, sizeInBytes, format, 0i64, ap);
}

// File Line: 272
// RVA: 0x12B2F7C
__int64 __fastcall vsnprintf_s_l(char *string, unsigned __int64 sizeInBytes, unsigned __int64 count, const char *format, localeinfo_struct *plocinfo, char *ap)
{
  const char *v6; // rbp
  unsigned __int64 v7; // rsi
  unsigned __int64 v8; // rdi
  char *v9; // rbx
  __int64 result; // rax
  int v11; // edi
  int v12; // er14

  v6 = format;
  v7 = count;
  v8 = sizeInBytes;
  v9 = string;
  if ( !format )
    goto LABEL_19;
  if ( count )
  {
    if ( !string )
    {
LABEL_19:
      *errno() = 22;
      goto LABEL_20;
    }
  }
  else if ( !string )
  {
    if ( !sizeInBytes )
      return 0i64;
    goto LABEL_19;
  }
  if ( !sizeInBytes )
    goto LABEL_19;
  if ( sizeInBytes > count )
  {
    v11 = *errno();
    result = vsnprintf_helper(output_s_l, v9, v7 + 1, v6, plocinfo, ap);
    if ( (_DWORD)result == -2 )
    {
      if ( *errno() == 34 )
        *errno() = v11;
      return 0xFFFFFFFFi64;
    }
    goto LABEL_16;
  }
  v12 = *errno();
  result = vsnprintf_helper(output_s_l, v9, v8, v6, plocinfo, ap);
  v9[v8 - 1] = 0;
  if ( (_DWORD)result != -2 )
  {
LABEL_16:
    if ( (signed int)result >= 0 )
      return result;
    goto LABEL_17;
  }
  if ( v7 == -1i64 )
  {
    if ( *errno() == 34 )
      *errno() = v12;
    return 0xFFFFFFFFi64;
  }
LABEL_17:
  *v9 = 0;
  if ( (_DWORD)result == -2 )
  {
    *errno() = 34;
LABEL_20:
    invalid_parameter_noinfo();
  }
  return 0xFFFFFFFFi64;
}

// File Line: 339
// RVA: 0x12B2F5C
int __fastcall vsnprintf_s(char *string, unsigned __int64 sizeInBytes, unsigned __int64 count, const char *format, char *ap)
{
  return vsnprintf_s_l(string, sizeInBytes, count, format, 0i64, ap);
}

