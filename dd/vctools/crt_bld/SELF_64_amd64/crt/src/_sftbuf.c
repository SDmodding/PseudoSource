// File Line: 59
// RVA: 0x12CBDF4
__int64 __fastcall stbuf(_iobuf *str)
{
  int v2; // eax
  int v3; // eax
  __int64 v4; // rdi
  char *v5; // rax

  v2 = fileno(str);
  if ( !(unsigned int)isatty(v2) )
    return 0i64;
  if ( str == &_iob_func()[1] )
  {
    v3 = 0;
  }
  else
  {
    if ( str != &_iob_func()[2] )
      return 0i64;
    v3 = 1;
  }
  ++cflush;
  if ( (str->_flag & 0x10C) != 0 )
    return 0i64;
  v4 = v3;
  v5 = (char *)stdbuf[v3];
  if ( v5 || (v5 = (char *)malloc_crt(0x1000ui64), (stdbuf[v4] = v5) != 0i64) )
  {
    str->_base = v5;
    str->_ptr = v5;
    str->_bufsiz = 4096;
    str->_cnt = 4096;
  }
  else
  {
    str->_base = (char *)&str->_charbuf;
    str->_ptr = (char *)&str->_charbuf;
    str->_bufsiz = 2;
    str->_cnt = 2;
  }
  str->_flag |= 0x1102u;
  return 1i64;
}

// File Line: 138
// RVA: 0x12CBDBC
void __fastcall ftbuf(int flag, _iobuf *str)
{
  if ( flag )
  {
    if ( (str->_flag & 0x1000) != 0 )
    {
      flush(str);
      str->_flag &= 0xFFFFEEFF;
      str->_bufsiz = 0;
      str->_ptr = 0i64;
      str->_base = 0i64;
    }
  }
}

