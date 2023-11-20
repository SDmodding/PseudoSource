// File Line: 56
// RVA: 0x12BCF14
signed __int64 __fastcall fseeki64(_iobuf *stream, __int64 offset, int whence)
{
  int v3; // edi
  __int64 v4; // rsi
  _iobuf *v5; // rbx
  signed __int64 result; // rax
  unsigned int v7; // edi

  v3 = whence;
  v4 = offset;
  v5 = stream;
  if ( stream && (unsigned int)whence <= 2 )
  {
    lock_file(stream);
    v7 = fseeki64_nolock(v5, v4, v3);
    unlock_file(v5);
    result = v7;
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    result = 0xFFFFFFFFi64;
  }
  return result;
}

// File Line: 94
// RVA: 0x12BCF88
signed __int64 __fastcall fseeki64_nolock(_iobuf *str, __int64 offset, int whence)
{
  int v3; // eax
  int v4; // edi
  __int64 v5; // rbp
  _iobuf *v6; // rbx
  int v7; // esi
  int v8; // eax
  int v9; // eax
  signed __int64 result; // rax

  v3 = str->_flag;
  v4 = whence;
  v5 = offset;
  v6 = str;
  if ( v3 & 0x83 && (unsigned int)whence <= 2 )
  {
    v7 = 0;
    str->_flag = v3 & 0xFFFFFFEF;
    if ( whence == 1 )
    {
      v4 = 0;
      v5 = ftelli64_nolock(str) + offset;
    }
    flush(v6);
    v8 = v6->_flag;
    if ( (v8 & 0x80u) == 0 )
    {
      if ( v8 & 1 && v8 & 8 && !_bittest(&v8, 0xAu) )
        v6->_bufsiz = 512;
    }
    else
    {
      v6->_flag = v8 & 0xFFFFFFFC;
    }
    v9 = fileno(v6);
    LOBYTE(v7) = lseeki64(v9, v5, v4) != -1;
    result = (unsigned int)(v7 - 1);
  }
  else
  {
    *errno() = 22;
    result = 0xFFFFFFFFi64;
  }
  return result;
}

