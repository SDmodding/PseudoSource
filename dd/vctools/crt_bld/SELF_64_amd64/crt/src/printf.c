// File Line: 49
// RVA: 0x12B2DC8
__int64 printf(const char *format, ...)
{
  _iobuf *v2; // rax
  _iobuf *v3; // rax
  int v4; // ebx
  _iobuf *v5; // rax
  unsigned int v6; // edi
  _iobuf *v7; // rax
  _iobuf *v8; // rax
  va_list argptr; // [rsp+48h] [rbp+10h] BYREF

  va_start(argptr, format);
  if ( format )
  {
    v2 = _iob_func();
    lock_file2(1, &v2[1]);
    v3 = _iob_func();
    v4 = stbuf(v3 + 1);
    v5 = _iob_func();
    v6 = output_l(v5 + 1, format, 0i64, argptr);
    v7 = _iob_func();
    ftbuf(v4, v7 + 1);
    v8 = _iob_func();
    unlock_file2(1, &v8[1]);
    return v6;
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
}

// File Line: 67
// RVA: 0x1451D13
printf$fin$0

// File Line: 166
// RVA: 0x12B2DB0
_BOOL8 get_printf_count_output()
{
  return _enable_percent_n == (_security_cookie | 1);
}

