// File Line: 49
// RVA: 0x12BCA10
signed __int64 fprintf(_iobuf *str, const char *format, ...)
{
  _iobuf *v2; // rsi
  unsigned int v3; // edi
  int v5; // eax
  ioinfo *v6; // rdx
  ioinfo *v7; // rcx
  int v8; // ebx
  char *formata; // [rsp+58h] [rbp+10h]
  va_list argptr; // [rsp+60h] [rbp+18h]

  va_start(argptr, format);
  formata = (char *)format;
  v2 = str;
  v3 = 0;
  if ( !str || !format )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
  if ( (signed int)ioinit() < 0 )
    return 0xFFFFFFFFi64;
  lock_file(v2);
  if ( !(v2->_flag & 0x40) )
  {
    v5 = fileno(v2);
    if ( (unsigned int)(v5 + 2) <= 1 )
    {
      v7 = &_badioinfo;
      v6 = &_badioinfo;
    }
    else
    {
      v6 = &_pioinfo[(signed __int64)v5 >> 5][v5 & 0x1F];
      v7 = &_badioinfo;
    }
    if ( *((_BYTE *)v6 + 56) & 0x7F )
      goto LABEL_20;
    if ( (unsigned int)(v5 + 2) > 1 )
      v7 = &_pioinfo[(signed __int64)v5 >> 5][v5 & 0x1F];
    if ( *((_BYTE *)v7 + 56) < 0 )
    {
LABEL_20:
      *errno() = 22;
      invalid_parameter_noinfo();
      v3 = -1;
    }
  }
  if ( !v3 )
  {
    v8 = stbuf(v2);
    v3 = output_l(v2, formata, 0i64, argptr);
    ftbuf(v8, v2);
  }
  unlock_file(v2);
  return v3;
}

// File Line: 75
// RVA: 0x1451E0F
_wfsopen$fin$0

