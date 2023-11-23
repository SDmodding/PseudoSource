// File Line: 69
// RVA: 0x12B3F44
unsigned __int64 __fastcall fwrite(char *buffer, unsigned __int64 size, unsigned __int64 count, _iobuf *stream)
{
  unsigned __int64 v8; // rdi

  if ( size && count )
  {
    if ( stream )
    {
      lock_file(stream);
      v8 = fwrite_nolock(buffer, size, count, stream);
      unlock_file(stream);
      return v8;
    }
    *errno() = 22;
    invalid_parameter_noinfo();
  }
  return 0i64;
}

// File Line: 99
// RVA: 0x12B3DB4
unsigned __int64 __fastcall fwrite_nolock(char *buffer, unsigned __int64 size, unsigned __int64 num, _iobuf *stream)
{
  char *v6; // r15
  unsigned __int64 v8; // rdi
  unsigned __int64 v9; // rbp
  unsigned int bufsiz; // r12d
  unsigned __int64 cnt; // r13
  unsigned int v12; // ebx
  int v13; // eax
  unsigned int v14; // eax
  __int64 v15; // rcx
  unsigned __int64 v16; // [rsp+60h] [rbp+18h]

  v16 = num;
  v6 = buffer;
  if ( !size || !num )
    return 0i64;
  if ( !stream || !buffer || num > 0xFFFFFFFFFFFFFFFFui64 / size )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0i64;
  }
  v8 = num * size;
  v9 = num * size;
  if ( (stream->_flag & 0x10C) != 0 )
    bufsiz = stream->_bufsiz;
  else
    bufsiz = 4096;
  if ( v8 )
  {
    do
    {
      if ( (stream->_flag & 0x108) != 0 && (cnt = (unsigned int)stream->_cnt, (_DWORD)cnt) )
      {
        if ( (cnt & 0x80000000) != 0i64 )
          goto LABEL_28;
        if ( v9 < cnt )
          LODWORD(cnt) = v9;
        memmove(stream->_ptr, v6, (unsigned int)cnt);
        stream->_cnt -= cnt;
        stream->_ptr += (unsigned int)cnt;
        v9 -= (unsigned int)cnt;
        v6 += (unsigned int)cnt;
      }
      else if ( v9 < bufsiz )
      {
        if ( flsbuf(*v6, stream) == -1 )
          return (v8 - v9) / size;
        ++v6;
        --v9;
        bufsiz = 1;
        if ( stream->_bufsiz > 0 )
          bufsiz = stream->_bufsiz;
      }
      else
      {
        if ( (stream->_flag & 0x108) != 0 && (unsigned int)flush(stream) )
          return (v8 - v9) / size;
        if ( bufsiz )
          v12 = v9 - v9 % bufsiz;
        else
          v12 = v9;
        v13 = fileno(stream);
        v14 = write(v13, v6, v12);
        if ( v14 == -1 )
          goto LABEL_28;
        v15 = v14;
        if ( v14 > v12 )
          v15 = v12;
        v9 -= v15;
        v6 += v15;
        if ( v14 < v12 )
        {
LABEL_28:
          stream->_flag |= 0x20u;
          return (v8 - v9) / size;
        }
      }
    }
    while ( v9 );
    return v16;
  }
  return num;
}

