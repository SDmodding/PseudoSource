// File Line: 42
// RVA: 0x12BA884
__int64 __fastcall vscan_fn_0(
        __int64 (__fastcall *inputfn)(__int64 *, const wchar_t *, localeinfo_struct *, char *),
        const wchar_t *string,
        const wchar_t *format,
        localeinfo_struct *plocinfo,
        char *arglist)
{
  unsigned __int64 v10; // rax
  __int64 v11[7]; // [rsp+20h] [rbp-38h] BYREF

  memset(v11, 0, 48);
  if ( string && format )
  {
    v10 = wcslen(string);
    LODWORD(v11[3]) = 73;
    v11[2] = (__int64)string;
    v11[0] = (__int64)string;
    if ( v10 <= 0x3FFFFFFF )
      LODWORD(v11[1]) = 2 * v10;
    else
      LODWORD(v11[1]) = 0x7FFFFFFF;
    return inputfn(v11, format, plocinfo, arglist);
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
}

// File Line: 157
// RVA: 0x12AF7A8
int sscanf(const char *string, const char *format, ...)
{
  va_list va; // [rsp+50h] [rbp+18h] BYREF

  va_start(va, format);
  return vscan_fn(input_l, string, format, 0i64, va);
}

