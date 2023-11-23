// File Line: 99
// RVA: 0x12B520C
int snprintf(char *string, unsigned __int64 count, const char *format, ...)
{
  int v3; // ebx
  int result; // eax
  int v6; // ebx
  _iobuf stream; // [rsp+20h] [rbp-38h] BYREF
  va_list argptr; // [rsp+98h] [rbp+40h] BYREF

  va_start(argptr, format);
  memset(&stream, 0, sizeof(stream));
  v3 = count;
  if ( format && (!count || string) )
  {
    stream._flag = 66;
    if ( count > 0x7FFFFFFF )
      v3 = 0x7FFFFFFF;
    stream._base = string;
    stream._cnt = v3;
    stream._ptr = string;
    result = output_l(&stream, format, 0i64, argptr);
    v6 = result;
    if ( string )
    {
      if ( --stream._cnt < 0 )
        flsbuf(0, &stream);
      else
        *stream._ptr = 0;
      return v6;
    }
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return -1;
  }
  return result;
}

// File Line: 212
// RVA: 0x12B0C3C
int sprintf_s(char *string, unsigned __int64 sizeInBytes, const char *format, ...)
{
  va_list va; // [rsp+58h] [rbp+20h] BYREF

  va_start(va, format);
  return vsprintf_s_l(string, sizeInBytes, format, 0i64, va);
}

// File Line: 238
// RVA: 0x12B0B78
int snprintf_s(char *string, unsigned __int64 sizeInBytes, unsigned __int64 count, const char *format, ...)
{
  va_list va; // [rsp+60h] [rbp+28h] BYREF

  va_start(va, format);
  return vsnprintf_s_l(string, sizeInBytes, count, format, 0i64, va);
}

