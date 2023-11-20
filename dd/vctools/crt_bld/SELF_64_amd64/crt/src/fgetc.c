// File Line: 38
// RVA: 0x13340B8
signed __int64 __fastcall fgetc(_iobuf *stream)
{
  _iobuf *v1; // rbx
  unsigned int v2; // edi
  int v4; // eax
  ioinfo *v5; // rdx
  ioinfo *v6; // rcx
  bool v7; // sf

  v1 = stream;
  v2 = 0;
  if ( !stream )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
  if ( (signed int)ioinit() < 0 )
    return 0xFFFFFFFFi64;
  lock_file(v1);
  if ( !(v1->_flag & 0x40) )
  {
    v4 = fileno(v1);
    if ( (unsigned int)(v4 + 2) <= 1 )
    {
      v6 = &_badioinfo;
      v5 = &_badioinfo;
    }
    else
    {
      v5 = &_pioinfo[(signed __int64)v4 >> 5][v4 & 0x1F];
      v6 = &_badioinfo;
    }
    if ( *((_BYTE *)v5 + 56) & 0x7F )
      goto LABEL_21;
    if ( (unsigned int)(v4 + 2) > 1 )
      v6 = &_pioinfo[(signed __int64)v4 >> 5][v4 & 0x1F];
    if ( *((_BYTE *)v6 + 56) < 0 )
    {
LABEL_21:
      *errno() = 22;
      invalid_parameter_noinfo();
      v2 = -1;
    }
  }
  if ( !v2 )
  {
    v7 = v1->_cnt-- - 1 < 0;
    if ( v7 )
      v2 = filbuf(v1);
    else
      v2 = *(unsigned __int8 *)v1->_ptr++;
  }
  unlock_file(v1);
  return v2;
}

