// File Line: 49
// RVA: 0x12BCDEC
__int64 __fastcall vfscanf(
        int (__fastcall *inputfn)(_iobuf *, const char *, localeinfo_struct *, char *),
        _iobuf *stream,
        const char *format,
        localeinfo_struct *plocinfo,
        char *arglist)
{
  unsigned int v9; // ebx
  int v11; // eax
  ioinfo *v12; // rdx
  ioinfo *v13; // rcx

  v9 = 0;
  if ( !stream || !format )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
  if ( (int)ioinit() < 0 )
    return 0xFFFFFFFFi64;
  lock_file(stream);
  if ( (stream->_flag & 0x40) == 0 )
  {
    v11 = fileno(stream);
    if ( (unsigned int)(v11 + 2) <= 1 )
    {
      v13 = &_badioinfo;
      v12 = &_badioinfo;
    }
    else
    {
      v12 = &_pioinfo[(__int64)v11 >> 5][v11 & 0x1F];
      v13 = &_badioinfo;
    }
    if ( (*((_BYTE *)v12 + 56) & 0x7F) != 0 )
      goto LABEL_14;
    if ( (unsigned int)(v11 + 2) > 1 )
      v13 = &_pioinfo[(__int64)v11 >> 5][v11 & 0x1F];
    if ( *((char *)v13 + 56) < 0 )
    {
LABEL_14:
      *errno() = 22;
      invalid_parameter_noinfo();
      v9 = -1;
    }
  }
  if ( !v9 )
    v9 = inputfn(stream, format, plocinfo, arglist);
  unlock_file(stream);
  return v9;
}

// File Line: 65
// RVA: 0x1451E29
vfscanf$fin$0

// File Line: 97
// RVA: 0x12BCDB4
int fscanf(_iobuf *stream, const char *format, ...)
{
  va_list va; // [rsp+50h] [rbp+18h] BYREF

  va_start(va, format);
  return vfscanf(input_l, stream, format, 0i64, va);
}

