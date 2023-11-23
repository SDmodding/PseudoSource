// File Line: 43
// RVA: 0x12B4608
__int64 __fastcall fclose(_iobuf *stream)
{
  unsigned int v2; // edi

  v2 = -1;
  if ( stream )
  {
    if ( (stream->_flag & 0x40) != 0 )
    {
      stream->_flag = 0;
    }
    else
    {
      lock_file(stream);
      v2 = fclose_nolock(stream);
      unlock_file(stream);
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
__int64 __fastcall fclose_nolock(_iobuf *str)
{
  unsigned int v1; // edi
  int v4; // eax
  char *tmpfname; // rcx

  v1 = -1;
  if ( str )
  {
    if ( (str->_flag & 0x83) != 0 )
    {
      v1 = flush(str);
      freebuf(str);
      v4 = fileno(str);
      if ( close(v4) >= 0 )
      {
        tmpfname = str->_tmpfname;
        if ( tmpfname )
        {
          free(tmpfname);
          str->_tmpfname = 0i64;
        }
      }
      else
      {
        v1 = -1;
      }
    }
    str->_flag = 0;
    return v1;
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
}

