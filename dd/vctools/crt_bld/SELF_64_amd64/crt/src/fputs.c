// File Line: 42
// RVA: 0x12BA3F0
signed __int64 __fastcall fputs(const char *string, _iobuf *stream)
{
  _iobuf *v2; // rdi
  const char *v3; // rsi
  int v5; // eax
  ioinfo *v6; // rdx
  ioinfo *v7; // rcx
  unsigned __int64 v8; // r14
  int v9; // ebx
  unsigned __int64 v10; // rsi

  v2 = stream;
  v3 = string;
  if ( !string || !stream )
    goto LABEL_17;
  if ( (signed int)ioinit() < 0 )
    return 0xFFFFFFFFi64;
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
      goto LABEL_17;
    if ( (unsigned int)(v5 + 2) > 1 )
      v7 = &_pioinfo[(signed __int64)v5 >> 5][v5 & 0x1F];
    if ( *((_BYTE *)v7 + 56) < 0 )
    {
LABEL_17:
      *errno() = 22;
      invalid_parameter_noinfo();
      return 0xFFFFFFFFi64;
    }
  }
  v8 = strlen(v3);
  lock_file(v2);
  v9 = stbuf(v2);
  v10 = fwrite_nolock(v3, 1ui64, v8, v2);
  ftbuf(v9, v2);
  unlock_file(v2);
  return (unsigned int)-(v8 != v10);
}

