// File Line: 59
// RVA: 0x12CBDF4
signed __int64 __fastcall stbuf(_iobuf *str)
{
  _iobuf *v1; // rbx
  int v2; // eax
  signed int v3; // eax
  __int64 v4; // rdi
  char *v5; // rax

  v1 = str;
  v2 = fileno(str);
  if ( !(unsigned int)isatty(v2) )
    return 0i64;
  if ( v1 == &_iob_func()[1] )
  {
    v3 = 0;
  }
  else
  {
    if ( v1 != &_iob_func()[2] )
      return 0i64;
    v3 = 1;
  }
  ++cflush;
  if ( v1->_flag & 0x10C )
    return 0i64;
  v4 = v3;
  v5 = (char *)stdbuf[v3];
  if ( v5 || (v5 = (char *)malloc_crt(0x1000ui64), (stdbuf[v4] = v5) != 0i64) )
  {
    v1->_base = v5;
    v1->_ptr = v5;
    v1->_bufsiz = 4096;
    v1->_cnt = 4096;
  }
  else
  {
    v1->_base = (char *)&v1->_charbuf;
    v1->_ptr = (char *)&v1->_charbuf;
    v1->_bufsiz = 2;
    v1->_cnt = 2;
  }
  v1->_flag |= 0x1102u;
  return 1i64;
}

// File Line: 138
// RVA: 0x12CBDBC
void __fastcall ftbuf(int flag, _iobuf *str)
{
  _iobuf *v2; // rbx

  if ( flag )
  {
    v2 = str;
    if ( str->_flag & 0x1000 )
    {
      flush(str);
      v2->_flag &= 0xFFFFEEFF;
      v2->_bufsiz = 0;
      v2->_ptr = 0i64;
      v2->_base = 0i64;
    }
  }
}

