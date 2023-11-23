// File Line: 41
// RVA: 0x12C2428
__int64 __fastcall fputc(int ch, _iobuf *str)
{
  unsigned int v4; // edi
  int v6; // eax
  ioinfo *v7; // rdx
  ioinfo *v8; // rcx

  v4 = 0;
  if ( !str )
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
    v6 = fileno(str);
    if ( (unsigned int)(v6 + 2) <= 1 )
    {
      v8 = &_badioinfo;
      v7 = &_badioinfo;
    }
    else
    {
      v7 = &_pioinfo[(__int64)v6 >> 5][v6 & 0x1F];
      v8 = &_badioinfo;
    }
    if ( (*((_BYTE *)v7 + 56) & 0x7F) != 0 )
      goto LABEL_13;
    if ( (unsigned int)(v6 + 2) > 1 )
      v8 = &_pioinfo[(__int64)v6 >> 5][v6 & 0x1F];
    if ( *((char *)v8 + 56) < 0 )
    {
LABEL_13:
      *errno() = 22;
      invalid_parameter_noinfo();
      v4 = -1;
    }
  }
  if ( !v4 )
  {
    if ( --str->_cnt < 0 )
    {
      v4 = flsbuf(ch, str);
    }
    else
    {
      *str->_ptr = ch;
      v4 = (unsigned __int8)ch;
      ++str->_ptr;
    }
  }
  unlock_file(str);
  return v4;
}

