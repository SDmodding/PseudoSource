// File Line: 42
// RVA: 0x12BA3F0
__int64 __fastcall fputs(char *string, _iobuf *stream)
{
  int v5; // eax
  ioinfo *v6; // rdx
  ioinfo *v7; // rcx
  unsigned __int64 v8; // r14
  int v9; // ebx
  unsigned __int64 v10; // rsi

  if ( !string || !stream )
    goto LABEL_2;
  if ( (int)ioinit() < 0 )
    return 0xFFFFFFFFi64;
  if ( (stream->_flag & 0x40) == 0 )
  {
    v5 = fileno(stream);
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
      goto LABEL_2;
    if ( (unsigned int)(v5 + 2) > 1 )
      v7 = &_pioinfo[(__int64)v5 >> 5][v5 & 0x1F];
    if ( *((char *)v7 + 56) < 0 )
    {
LABEL_2:
      *errno() = 22;
      invalid_parameter_noinfo();
      return 0xFFFFFFFFi64;
    }
  }
  v8 = strlen(string);
  lock_file(stream);
  v9 = stbuf(stream);
  v10 = fwrite_nolock(string, 1ui64, v8, stream);
  ftbuf(v9, stream);
  unlock_file(stream);
  return (unsigned int)-(v8 != v10);
}

