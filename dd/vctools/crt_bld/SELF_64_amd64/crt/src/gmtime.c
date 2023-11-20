// File Line: 167
// RVA: 0x12D5620
void *_getgmtimebuf()
{
  _tiddata *v0; // rax
  _tiddata *v1; // rbx
  void *v3; // rax

  v0 = getptd_noexit();
  v1 = v0;
  if ( v0 )
  {
    if ( v0->_gmtimebuf )
      return v1->_gmtimebuf;
    v3 = malloc_crt(0x24ui64);
    v1->_gmtimebuf = v3;
    if ( v3 )
      return v1->_gmtimebuf;
  }
  *errno() = 12;
  return 0i64;
}

