// File Line: 96
// RVA: 0x12B9630
__int64 __fastcall fseek(_iobuf *stream, int offset, unsigned int whence)
{
  unsigned int v7; // edi

  if ( stream && whence <= 2 )
  {
    lock_file(stream);
    v7 = fseek_nolock(stream, offset, whence);
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

// File Line: 136
// RVA: 0x12B9584
__int64 __fastcall fseek_nolock(_iobuf *str, int offset, int whence)
{
  int flag; // eax
  int v4; // esi
  int v5; // ebp
  int v8; // edi
  int v9; // eax
  int v10; // eax

  flag = str->_flag;
  v4 = whence;
  v5 = offset;
  if ( (flag & 0x83) != 0 )
  {
    v8 = 0;
    str->_flag = flag & 0xFFFFFFEF;
    if ( whence == 1 )
    {
      v4 = 0;
      v5 = ftell_nolock(str) + offset;
    }
    flush(str);
    v9 = str->_flag;
    if ( (v9 & 0x80u) == 0 )
    {
      if ( (v9 & 1) != 0 && (v9 & 8) != 0 && (v9 & 0x400) == 0 )
        str->_bufsiz = 512;
    }
    else
    {
      str->_flag = v9 & 0xFFFFFFFC;
    }
    v10 = fileno(str);
    LOBYTE(v8) = lseek(v10, v5, v4) != -1;
    return (unsigned int)(v8 - 1);
  }
  else
  {
    *errno() = 22;
    return 0xFFFFFFFFi64;
  }
}

