// File Line: 107
// RVA: 0x12B2E74
__int64 __fastcall vsnprintf_helper(
        __int64 (__fastcall *outfn)(_iobuf *, const char *, localeinfo_struct *, char *),
        char *string,
        unsigned __int64 count,
        const char *format,
        localeinfo_struct *plocinfo,
        char *ap)
{
  int v6; // ebx
  __int64 result; // rax
  int v10; // eax
  unsigned int v11; // edi
  bool v12; // sf
  _iobuf str; // [rsp+20h] [rbp-30h] BYREF

  v6 = 0;
  memset(&str, 0, sizeof(str));
  if ( !format || count && !string )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
  v10 = count;
  if ( count > 0x7FFFFFFF )
    v10 = 0x7FFFFFFF;
  str._flag = 66;
  str._base = string;
  str._ptr = string;
  str._cnt = v10;
  result = outfn(&str, format, plocinfo, ap);
  v11 = result;
  if ( string )
  {
    if ( (int)result >= 0 )
    {
      if ( --str._cnt >= 0 )
      {
        *str._ptr = 0;
        return v11;
      }
      if ( flsbuf(0, &str) != -1 )
        return v11;
    }
    v12 = str._cnt < 0;
    string[count - 1] = 0;
    LOBYTE(v6) = !v12;
    return (unsigned int)(v6 - 2);
  }
  return result;
}

// File Line: 172
// RVA: 0x12B3204
__int64 __fastcall vsprintf(char *string, const char *format, char *ap)
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
__int64 __fastcall vsprintf_s_l(
        char *string,
        unsigned __int64 sizeInBytes,
        const char *format,
        localeinfo_struct *plocinfo,
        char *ap)
{
  __int64 result; // rax

  if ( !format || !string || !sizeInBytes )
  {
    *errno() = 22;
    goto LABEL_9;
  }
  result = vsnprintf_helper(
             (__int64 (__fastcall *)(_iobuf *, const char *, localeinfo_struct *, char *))output_s_l,
             string,
             sizeInBytes,
             format,
             plocinfo,
             ap);
  if ( (int)result < 0 )
    *string = 0;
  if ( (_DWORD)result == -2 )
  {
    *errno() = 34;
LABEL_9:
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
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
__int64 __fastcall vsnprintf_s_l(
        char *string,
        unsigned __int64 sizeInBytes,
        unsigned __int64 count,
        const char *format,
        localeinfo_struct *plocinfo,
        char *ap)
{
  __int64 result; // rax
  int v11; // edi
  int v12; // r14d

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
    result = vsnprintf_helper(
               (__int64 (__fastcall *)(_iobuf *, const char *, localeinfo_struct *, char *))output_s_l,
               string,
               count + 1,
               format,
               plocinfo,
               ap);
    if ( (_DWORD)result == -2 )
    {
      if ( *errno() == 34 )
        *errno() = v11;
      return 0xFFFFFFFFi64;
    }
    goto LABEL_16;
  }
  v12 = *errno();
  result = vsnprintf_helper(
             (__int64 (__fastcall *)(_iobuf *, const char *, localeinfo_struct *, char *))output_s_l,
             string,
             sizeInBytes,
             format,
             plocinfo,
             ap);
  string[sizeInBytes - 1] = 0;
  if ( (_DWORD)result != -2 )
  {
LABEL_16:
    if ( (int)result >= 0 )
      return result;
    goto LABEL_17;
  }
  if ( count == -1i64 )
  {
    if ( *errno() == 34 )
      *errno() = v12;
    return 0xFFFFFFFFi64;
  }
LABEL_17:
  *string = 0;
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
int __fastcall vsnprintf_s(
        char *string,
        unsigned __int64 sizeInBytes,
        unsigned __int64 count,
        const char *format,
        char *ap)
{
  return vsnprintf_s_l(string, sizeInBytes, count, format, 0i64, ap);
}

