// File Line: 96
// RVA: 0x12B9630
signed __int64 __fastcall fseek(_iobuf *stream, int offset, int whence)
{
  int v3; // edi
  int v4; // esi
  _iobuf *v5; // rbx
  signed __int64 result; // rax
  unsigned int v7; // edi

  v3 = whence;
  v4 = offset;
  v5 = stream;
  if ( stream && (unsigned int)whence <= 2 )
  {
    lock_file(stream);
    v7 = fseek_nolock(v5, v4, v3);
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

// File Line: 136
// RVA: 0x12B9584
signed __int64 __fastcall fseek_nolock(_iobuf *str, int offset, int whence)
{
  int v3; // eax
  int v4; // esi
  int v5; // ebp
  _iobuf *v6; // rbx
  signed __int64 result; // rax
  int v8; // edi
  int v9; // eax
  int v10; // eax

  v3 = str->_flag;
  v4 = whence;
  v5 = offset;
  v6 = str;
  if ( v3 & 0x83 )
  {
    v8 = 0;
    str->_flag = v3 & 0xFFFFFFEF;
    if ( whence == 1 )
    {
      v4 = 0;
      v5 = ftell_nolock(str) + offset;
    }
    flush(v6);
    v9 = v6->_flag;
    if ( (v9 & 0x80u) == 0 )
    {
      if ( v9 & 1 && v9 & 8 && !_bittest(&v9, 0xAu) )
        v6->_bufsiz = 512;
    }
    else
    {
      v6->_flag = v9 & 0xFFFFFFFC;
    }
    v10 = fileno(v6);
    LOBYTE(v8) = lseek(v10, v5, v4) != -1;
    result = (unsigned int)(v8 - 1);
  }
  else
  {
    *errno() = 22;
    result = 0xFFFFFFFFi64;
  }
  return result;
}

