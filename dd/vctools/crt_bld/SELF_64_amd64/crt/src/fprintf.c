// File Line: 49
// RVA: 0x12BCA10
__int64 fprintf(_iobuf *str, const char *format, ...)
{
  unsigned int v3; // edi
  int v5; // eax
  ioinfo *v6; // rdx
  ioinfo *v7; // rcx
  int v8; // ebx
  va_list argptr; // [rsp+60h] [rbp+18h] BYREF

  va_start(argptr, format);
  v3 = 0;
  if ( !str || !format )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
  if ( (int)ioinit() < 0 )
    return 0xFFFFFFFFi64;
  lock_file(str);
  if ( (str->_flag & 0x40) == 0 )
  {
    v5 = fileno(str);
    if ( (unsigned int)(v5 + 2) <= 1 )
    {
      v7 = &_badioinfo;
      v6 = &_badioinfo;
    }
    else
    {
      v6 = &_pioinfo[(__int64)v5 >> 5][v5 & 0x1F];
      v7 = &_badioinfo;
    }
    if ( (*((_BYTE *)v6 + 56) & 0x7F) != 0 )
      goto LABEL_14;
    if ( (unsigned int)(v5 + 2) > 1 )
      v7 = &_pioinfo[(__int64)v5 >> 5][v5 & 0x1F];
    if ( *((char *)v7 + 56) < 0 )
    {
LABEL_14:
      *errno() = 22;
      invalid_parameter_noinfo();
      v3 = -1;
    }
  }
  if ( !v3 )
  {
    v8 = stbuf(str);
    v3 = output_l(str, format, 0i64, argptr);
    ftbuf(v8, str);
  }
  unlock_file(str);
  return v3;
}

// File Line: 75
// RVA: 0x1451E0F
_wfsopen$fin$0

