// File Line: 21
// RVA: 0x12D47C8
LPVOID __fastcall calloc_impl(unsigned __int64 num, unsigned __int64 size, int *errno_tmp)
{
  LPVOID result; // rax
  SIZE_T v5; // rbx

  if ( num && 0xFFFFFFFFFFFFFFE0ui64 / num < size )
  {
    *errno() = 12;
    return 0i64;
  }
  else
  {
    v5 = num * size;
    if ( !(num * size) )
      v5 = 1i64;
    while ( 1 )
    {
      result = 0i64;
      if ( v5 <= 0xFFFFFFFFFFFFFFE0ui64 )
      {
        result = HeapAlloc(crtheap, 8u, v5);
        if ( result )
          break;
      }
      if ( !newmode )
      {
        if ( errno_tmp )
          *errno_tmp = 12;
        return result;
      }
      if ( !callnewh(v5) )
      {
        if ( errno_tmp )
          *errno_tmp = 12;
        return 0i64;
      }
    }
  }
  return result;
}

