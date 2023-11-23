// File Line: 38
// RVA: 0x13340B8
__int64 __fastcall fgetc(_iobuf *stream)
{
  unsigned int v2; // edi
  int v4; // eax
  ioinfo *v5; // rdx
  ioinfo *v6; // rcx

  v2 = 0;
  if ( !stream )
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
    v4 = fileno(stream);
    if ( (unsigned int)(v4 + 2) <= 1 )
    {
      v6 = &_badioinfo;
      v5 = &_badioinfo;
    }
    else
    {
      v5 = &_pioinfo[(__int64)v4 >> 5][v4 & 0x1F];
      v6 = &_badioinfo;
    }
    if ( (*((_BYTE *)v5 + 56) & 0x7F) != 0 )
      goto LABEL_13;
    if ( (unsigned int)(v4 + 2) > 1 )
      v6 = &_pioinfo[(__int64)v4 >> 5][v4 & 0x1F];
    if ( *((char *)v6 + 56) < 0 )
    {
LABEL_13:
      *errno() = 22;
      invalid_parameter_noinfo();
      v2 = -1;
    }
  }
  if ( !v2 )
  {
    if ( --stream->_cnt < 0 )
      v2 = filbuf(stream);
    else
      v2 = *(unsigned __int8 *)stream->_ptr++;
  }
  unlock_file(stream);
  return v2;
}

