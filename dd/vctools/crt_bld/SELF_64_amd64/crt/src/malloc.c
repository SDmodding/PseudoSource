// File Line: 83
// RVA: 0x12B1008
void *__fastcall malloc(unsigned __int64 size)
{
  unsigned __int64 v1; // rbx
  unsigned __int64 v2; // rdi
  void *v3; // rsi
  void *result; // rax

  v1 = size;
  if ( size > 0xFFFFFFFFFFFFFFE0ui64 )
  {
    callnewh(size);
    *errno() = 12;
    result = 0i64;
  }
  else
  {
    v2 = 1i64;
    if ( size )
      v2 = size;
    while ( 1 )
    {
      if ( !crtheap )
      {
        FF_MSGBANNER();
        NMSG_WRITE(30);
        _crtExitProcess(255);
      }
      v3 = HeapAlloc(crtheap, 0, v2);
      if ( v3 )
        break;
      if ( !newmode )
      {
        *errno() = 12;
LABEL_12:
        *errno() = 12;
        break;
      }
      if ( !callnewh(v1) )
        goto LABEL_12;
    }
    result = v3;
  }
  return result;
}

