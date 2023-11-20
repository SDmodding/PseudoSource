// File Line: 49
// RVA: 0x12B2DC8
signed __int64 printf(const char *format, ...)
{
  signed __int64 result; // rax
  _iobuf *v2; // rax
  _iobuf *v3; // rax
  int v4; // ebx
  _iobuf *v5; // rax
  unsigned int v6; // edi
  _iobuf *v7; // rax
  _iobuf *v8; // rax
  char *formata; // [rsp+40h] [rbp+8h]
  va_list argptr; // [rsp+48h] [rbp+10h]

  va_start(argptr, format);
  formata = (char *)format;
  if ( format )
  {
    v2 = _iob_func();
    lock_file2(1, &v2[1]);
    v3 = _iob_func();
    v4 = stbuf(v3 + 1);
    v5 = _iob_func();
    v6 = output_l(v5 + 1, formata, 0i64, argptr);
    v7 = _iob_func();
    ftbuf(v4, v7 + 1);
    v8 = _iob_func();
    unlock_file2(1, &v8[1]);
    result = v6;
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    result = 0xFFFFFFFFi64;
  }
  return result;
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

