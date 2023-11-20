// File Line: 69
// RVA: 0x12B3F44
unsigned __int64 __fastcall fwrite(const void *buffer, unsigned __int64 size, unsigned __int64 count, _iobuf *stream)
{
  _iobuf *v4; // rbx
  unsigned __int64 v5; // rdi
  unsigned __int64 v6; // rsi
  const void *v7; // r14
  unsigned __int64 v8; // rdi

  v4 = stream;
  v5 = count;
  v6 = size;
  v7 = buffer;
  if ( size && count )
  {
    if ( stream )
    {
      lock_file(stream);
      v8 = fwrite_nolock(v7, v6, v5, v4);
      unlock_file(v4);
      return v8;
    }
    *errno() = 22;
    invalid_parameter_noinfo();
  }
  return 0i64;
}

// File Line: 99
// RVA: 0x12B3DB4
unsigned __int64 __fastcall fwrite_nolock(const void *buffer, unsigned __int64 size, unsigned __int64 num, _iobuf *stream)
{
  _iobuf *v4; // rsi
  unsigned __int64 v5; // r14
  char *v6; // r15
  unsigned __int64 v8; // rdi
  unsigned __int64 v9; // rbp
  unsigned int v10; // er12
  unsigned __int64 v11; // r13
  unsigned int v12; // ebx
  int v13; // eax
  unsigned int v14; // eax
  __int64 v15; // rcx
  unsigned __int64 v16; // [rsp+60h] [rbp+18h]

  v16 = num;
  v4 = stream;
  v5 = size;
  v6 = (char *)buffer;
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
  if ( stream->_flag & 0x10C )
    v10 = stream->_bufsiz;
  else
    v10 = 4096;
  if ( v8 )
  {
    do
    {
      if ( v4->_flag & 0x108 && (v11 = (unsigned int)v4->_cnt, (_DWORD)v11) )
      {
        if ( (v11 & 0x80000000) != 0i64 )
          goto LABEL_29;
        if ( v9 < v11 )
          LODWORD(v11) = v9;
        memmove(v4->_ptr, v6, (unsigned int)v11);
        v4->_cnt -= v11;
        v4->_ptr += (unsigned int)v11;
        v9 -= (unsigned int)v11;
        v6 += (unsigned int)v11;
      }
      else if ( v9 < v10 )
      {
        if ( flsbuf(*v6, v4) == -1 )
          return (v8 - v9) / v5;
        ++v6;
        --v9;
        v10 = 1;
        if ( v4->_bufsiz > 0 )
          v10 = v4->_bufsiz;
      }
      else
      {
        if ( v4->_flag & 0x108 && (unsigned int)flush(v4) )
          return (v8 - v9) / v5;
        if ( v10 )
          v12 = v9 - v9 % v10;
        else
          v12 = v9;
        v13 = fileno(v4);
        v14 = write(v13, v6, v12);
        if ( v14 == -1 )
          goto LABEL_29;
        v15 = v14;
        if ( v14 > v12 )
          v15 = v12;
        v9 -= v15;
        v6 += v15;
        if ( v14 < v12 )
        {
LABEL_29:
          v4->_flag |= 0x20u;
          return (v8 - v9) / v5;
        }
      }
    }
    while ( v9 );
    num = v16;
  }
  return num;
}

