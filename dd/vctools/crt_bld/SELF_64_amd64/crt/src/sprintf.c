// File Line: 99
// RVA: 0x12B520C
int snprintf(char *string, unsigned __int64 count, const char *format, ...)
{
  unsigned __int64 v3; // rbx
  const char *v4; // rsi
  char *v5; // rdi
  int result; // eax
  int v7; // ebx
  _iobuf stream; // [rsp+20h] [rbp-38h]
  va_list argptr; // [rsp+98h] [rbp+40h]

  va_start(argptr, format);
  stream._ptr = 0i64;
  v3 = count;
  v4 = format;
  v5 = string;
  memset(&stream._cnt, 0, 0x28ui64);
  if ( v4 && (!v3 || v5) )
  {
    stream._flag = 66;
    if ( v3 > 0x7FFFFFFF )
      LODWORD(v3) = 0x7FFFFFFF;
    stream._base = v5;
    stream._cnt = v3;
    stream._ptr = v5;
    result = output_l(&stream, v4, 0i64, argptr);
    v7 = result;
    if ( v5 )
    {
      if ( --stream._cnt < 0 )
        flsbuf(0, &stream);
      else
        *stream._ptr = 0;
      result = v7;
    }
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    result = -1;
  }
  return result;
}

// File Line: 212
// RVA: 0x12B0C3C
int sprintf_s(char *string, unsigned __int64 sizeInBytes, const char *format, ...)
{
  va_list va; // [rsp+58h] [rbp+20h]

  va_start(va, format);
  return vsprintf_s_l(string, sizeInBytes, format, 0i64, va);
}

// File Line: 238
// RVA: 0x12B0B78
int snprintf_s(char *string, unsigned __int64 sizeInBytes, unsigned __int64 count, const char *format, ...)
{
  va_list va; // [rsp+60h] [rbp+28h]

  va_start(va, format);
  return vsnprintf_s_l(string, sizeInBytes, count, format, 0i64, va);
}

