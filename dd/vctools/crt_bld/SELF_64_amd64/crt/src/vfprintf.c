// File Line: 51
// RVA: 0x12BF0D4
__int64 __fastcall vfprintf_helper(
        int (__fastcall *outfn)(_iobuf *, const char *, localeinfo_struct *, char *),
        _iobuf *str,
        const char *format,
        localeinfo_struct *plocinfo,
        char *ap)
{
  unsigned int v9; // edi
  int v11; // eax
  ioinfo *v12; // rdx
  ioinfo *v13; // rcx
  int v14; // ebx

  v9 = 0;
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
    v11 = fileno(str);
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
  {
    v14 = stbuf(str);
    v9 = outfn(str, format, plocinfo, ap);
    ftbuf(v14, str);
  }
  unlock_file(str);
  return v9;
}

// File Line: 117
// RVA: 0x12BF0B0
int __fastcall vfprintf(_iobuf *str, const char *format, char *ap)
{
  return vfprintf_helper(output_l, str, format, 0i64, ap);
}

