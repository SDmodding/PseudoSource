// File Line: 43
// RVA: 0x12B4608
__int64 __fastcall fclose(_iobuf *stream)
{
  _iobuf *v1; // rbx
  unsigned int v2; // edi

  v1 = stream;
  v2 = -1;
  if ( stream )
  {
    if ( stream->_flag & 0x40 )
    {
      stream->_flag = 0;
    }
    else
    {
      lock_file(stream);
      v2 = fclose_nolock(v1);
      unlock_file(v1);
    }
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
  }
  return v2;
}

// File Line: 85
// RVA: 0x12B458C
signed __int64 __fastcall fclose_nolock(_iobuf *str)
{
  unsigned int v1; // edi
  _iobuf *v2; // rbx
  signed __int64 result; // rax
  int v4; // eax
  char *v5; // rcx

  v1 = -1;
  v2 = str;
  if ( str )
  {
    if ( str->_flag & 0x83 )
    {
      v1 = flush(str);
      freebuf(v2);
      v4 = fileno(v2);
      if ( close(v4) >= 0 )
      {
        v5 = v2->_tmpfname;
        if ( v5 )
        {
          free(v5);
          v2->_tmpfname = 0i64;
        }
      }
      else
      {
        v1 = -1;
      }
    }
    v2->_flag = 0;
    result = v1;
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    result = 0xFFFFFFFFi64;
  }
  return result;
}

