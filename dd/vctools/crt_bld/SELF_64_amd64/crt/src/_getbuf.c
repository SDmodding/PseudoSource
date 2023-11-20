// File Line: 43
// RVA: 0x12D5668
void __fastcall getbuf(_iobuf *str)
{
  _iobuf *v1; // rbx
  char *v2; // rax
  char *v3; // rax

  ++cflush;
  v1 = str;
  v2 = (char *)malloc_crt(0x1000ui64);
  v1->_base = v2;
  if ( v2 )
  {
    v1->_flag |= 8u;
    v1->_bufsiz = 4096;
  }
  else
  {
    v1->_flag |= 4u;
    v1->_bufsiz = 2;
    v1->_base = (char *)&v1->_charbuf;
  }
  v3 = v1->_base;
  v1->_cnt = 0;
  v1->_ptr = v3;
}

