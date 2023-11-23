// File Line: 56
// RVA: 0x12BCF14
__int64 __fastcall fseeki64(_iobuf *stream, __int64 offset, unsigned int whence)
{
  unsigned int v7; // edi

  if ( stream && whence <= 2 )
  {
    lock_file(stream);
    v7 = fseeki64_nolock(stream, offset, whence);
    unlock_file(stream);
    return v7;
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
}

// File Line: 94
// RVA: 0x12BCF88
__int64 __fastcall fseeki64_nolock(_iobuf *str, __int64 offset, unsigned int whence)
{
  int flag; // eax
  int v4; // edi
  __int64 v5; // rbp
  int v7; // esi
  int v8; // eax
  int v9; // eax

  flag = str->_flag;
  v4 = whence;
  v5 = offset;
  if ( (flag & 0x83) != 0 && whence <= 2 )
  {
    v7 = 0;
    str->_flag = flag & 0xFFFFFFEF;
    if ( whence == 1 )
    {
      v4 = 0;
      v5 = ftelli64_nolock(str) + offset;
    }
    flush(str);
    v8 = str->_flag;
    if ( (v8 & 0x80u) == 0 )
    {
      if ( (v8 & 1) != 0 && (v8 & 8) != 0 && (v8 & 0x400) == 0 )
        str->_bufsiz = 512;
    }
    else
    {
      str->_flag = v8 & 0xFFFFFFFC;
    }
    v9 = fileno(str);
    LOBYTE(v7) = lseeki64(v9, v5, v4) != -1;
    return (unsigned int)(v7 - 1);
  }
  else
  {
    *errno() = 22;
    return 0xFFFFFFFFi64;
  }
}

