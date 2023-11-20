// File Line: 49
// RVA: 0x12BCDEC
signed __int64 __fastcall vfscanf(int (__fastcall *inputfn)(_iobuf *, const char *, localeinfo_struct *, char *), _iobuf *stream, const char *format, localeinfo_struct *plocinfo, char *arglist)
{
  localeinfo_struct *v5; // r14
  const char *v6; // rsi
  _iobuf *v7; // rdi
  int (__fastcall *v8)(_iobuf *, const char *, localeinfo_struct *, char *); // r15
  unsigned int v9; // ebx
  int v11; // eax
  ioinfo *v12; // rdx
  ioinfo *v13; // rcx

  v5 = plocinfo;
  v6 = format;
  v7 = stream;
  v8 = inputfn;
  v9 = 0;
  if ( !stream || !format )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
  if ( (signed int)ioinit() < 0 )
    return 0xFFFFFFFFi64;
  lock_file(v7);
  if ( !(v7->_flag & 0x40) )
  {
    v11 = fileno(v7);
    if ( (unsigned int)(v11 + 2) <= 1 )
    {
      v13 = &_badioinfo;
      v12 = &_badioinfo;
    }
    else
    {
      v12 = &_pioinfo[(signed __int64)v11 >> 5][v11 & 0x1F];
      v13 = &_badioinfo;
    }
    if ( *((_BYTE *)v12 + 56) & 0x7F )
      goto LABEL_20;
    if ( (unsigned int)(v11 + 2) > 1 )
      v13 = &_pioinfo[(signed __int64)v11 >> 5][v11 & 0x1F];
    if ( *((_BYTE *)v13 + 56) < 0 )
    {
LABEL_20:
      *errno() = 22;
      invalid_parameter_noinfo();
      v9 = -1;
    }
  }
  if ( !v9 )
    v9 = v8(v7, v6, v5, arglist);
  unlock_file(v7);
  return v9;
}

// File Line: 65
// RVA: 0x1451E29
vfscanf$fin$0

// File Line: 97
// RVA: 0x12BCDB4
int fscanf(_iobuf *stream, const char *format, ...)
{
  va_list va; // [rsp+50h] [rbp+18h]

  va_start(va, format);
  return vfscanf(input_l, stream, format, 0i64, va);
}

