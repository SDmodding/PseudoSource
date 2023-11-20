// File Line: 42
// RVA: 0x12BA884
__int64 __fastcall vscan_fn_0(int (__fastcall *inputfn)(_iobuf *, const wchar_t *, localeinfo_struct *, char *), const wchar_t *string, const wchar_t *format, localeinfo_struct *plocinfo, char *arglist)
{
  const wchar_t *v5; // rbx
  const wchar_t *v6; // rdi
  int (__fastcall *v7)(_iobuf *, const wchar_t *, localeinfo_struct *, char *); // rbp
  localeinfo_struct *v8; // rsi
  __int64 result; // rax
  unsigned __int64 v10; // rax
  const wchar_t *v11; // [rsp+20h] [rbp-38h]
  int v12; // [rsp+28h] [rbp-30h]
  const wchar_t *v13; // [rsp+30h] [rbp-28h]
  int v14; // [rsp+38h] [rbp-20h]

  v11 = 0i64;
  v5 = string;
  v6 = format;
  v7 = inputfn;
  v8 = plocinfo;
  memset(&v12, 0, 0x28ui64);
  if ( v5 && v6 )
  {
    v10 = wcslen(v5);
    v14 = 73;
    v13 = v5;
    v11 = v5;
    if ( v10 <= 0x3FFFFFFF )
      v12 = 2 * v10;
    else
      v12 = 0x7FFFFFFF;
    result = ((__int64 (__fastcall *)(const wchar_t **, const wchar_t *, localeinfo_struct *, char *, const wchar_t *, _QWORD, const wchar_t *, _QWORD))v7)(
               &v11,
               v6,
               v8,
               arglist,
               v11,
               *(_QWORD *)&v12,
               v13,
               *(_QWORD *)&v14);
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    result = 0xFFFFFFFFi64;
  }
  return result;
}

// File Line: 157
// RVA: 0x12AF7A8
int sscanf(const char *string, const char *format, ...)
{
  va_list va; // [rsp+50h] [rbp+18h]

  va_start(va, format);
  return vscan_fn(input_l, string, format, 0i64, va);
}

