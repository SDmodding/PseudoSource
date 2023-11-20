// File Line: 21
// RVA: 0x12D47C8
LPVOID __fastcall calloc_impl(unsigned __int64 num, unsigned __int64 size, int *errno_tmp)
{
  int *v3; // rdi
  LPVOID result; // rax
  SIZE_T v5; // rbx

  v3 = errno_tmp;
  if ( num && 0xFFFFFFFFFFFFFFE0ui64 / num < size )
  {
    *errno() = 12;
LABEL_4:
    result = 0i64;
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
        if ( v3 )
          *v3 = 12;
        return result;
      }
      if ( !(unsigned int)callnewh(v5) )
      {
        if ( v3 )
          *v3 = 12;
        goto LABEL_4;
      }
    }
  }
  return result;
}

