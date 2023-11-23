// File Line: 43
// RVA: 0x12D5668
void __fastcall getbuf(_iobuf *str)
{
  char *v2; // rax
  char *base; // rax

  ++cflush;
  v2 = (char *)malloc_crt(0x1000ui64);
  str->_base = v2;
  if ( v2 )
  {
    str->_flag |= 8u;
    str->_bufsiz = 4096;
  }
  else
  {
    str->_flag |= 4u;
    str->_bufsiz = 2;
    str->_base = (char *)&str->_charbuf;
  }
  base = str->_base;
  str->_cnt = 0;
  str->_ptr = base;
}

