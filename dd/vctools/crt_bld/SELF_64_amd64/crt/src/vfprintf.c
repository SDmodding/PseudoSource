// File Line: 51
// RVA: 0x12BF0D4
signed __int64 __fastcall vfprintf_helper(int (__fastcall *outfn)(_iobuf *, const char *, localeinfo_struct *, char *), _iobuf *str, const char *format, localeinfo_struct *plocinfo, char *ap)
{
  localeinfo_struct *v5; // r15
  const char *v6; // r14
  _iobuf *v7; // rsi
  int (__fastcall *v8)(_iobuf *, const char *, localeinfo_struct *, char *); // r12
  unsigned int v9; // edi
  int v11; // eax
  ioinfo *v12; // rdx
  ioinfo *v13; // rcx
  int v14; // ebx

  v5 = plocinfo;
  v6 = format;
  v7 = str;
  v8 = outfn;
  v9 = 0;
  if ( !str || !format )
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
  {
    v14 = stbuf(v7);
    v9 = v8(v7, v6, v5, ap);
    ftbuf(v14, v7);
  }
  unlock_file(v7);
  return v9;
}

// File Line: 117
// RVA: 0x12BF0B0
int __fastcall vfprintf(_iobuf *str, const char *format, char *ap)
{
  return vfprintf_helper(output_l, str, format, 0i64, ap);
}

