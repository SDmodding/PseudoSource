// File Line: 41
// RVA: 0x12C2428
signed __int64 __fastcall fputc(int ch, _iobuf *str)
{
  _iobuf *v2; // rbx
  int v3; // esi
  unsigned int v4; // edi
  int v6; // eax
  ioinfo *v7; // rdx
  ioinfo *v8; // rcx
  bool v9; // sf

  v2 = str;
  v3 = ch;
  v4 = 0;
  if ( !str )
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
    v6 = fileno(v2);
    if ( (unsigned int)(v6 + 2) <= 1 )
    {
      v8 = &_badioinfo;
      v7 = &_badioinfo;
    }
    else
    {
      v7 = &_pioinfo[(signed __int64)v6 >> 5][v6 & 0x1F];
      v8 = &_badioinfo;
    }
    if ( *((_BYTE *)v7 + 56) & 0x7F )
      goto LABEL_21;
    if ( (unsigned int)(v6 + 2) > 1 )
      v8 = &_pioinfo[(signed __int64)v6 >> 5][v6 & 0x1F];
    if ( *((_BYTE *)v8 + 56) < 0 )
    {
LABEL_21:
      *errno() = 22;
      invalid_parameter_noinfo();
      v4 = -1;
    }
  }
  if ( !v4 )
  {
    v9 = v2->_cnt-- - 1 < 0;
    if ( v9 )
    {
      v4 = flsbuf(v3, v2);
    }
    else
    {
      *v2->_ptr = v3;
      v4 = (unsigned __int8)v3;
      ++v2->_ptr;
    }
  }
  unlock_file(v2);
  return v4;
}

