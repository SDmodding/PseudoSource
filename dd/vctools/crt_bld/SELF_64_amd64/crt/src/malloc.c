// File Line: 83
// RVA: 0x12B1008
LPVOID __fastcall malloc(unsigned __int64 size)
{
  SIZE_T v2; // rdi
  LPVOID v3; // rsi

  if ( size > 0xFFFFFFFFFFFFFFE0ui64 )
  {
    callnewh(size);
    *errno() = 12;
    return 0i64;
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
        return v3;
      if ( !newmode )
      {
        *errno() = 12;
LABEL_11:
        *errno() = 12;
        return v3;
      }
      if ( !callnewh(size) )
        goto LABEL_11;
    }
  }
}

