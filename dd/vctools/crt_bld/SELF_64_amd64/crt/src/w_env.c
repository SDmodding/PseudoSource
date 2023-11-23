// File Line: 37
// RVA: 0x1334F6C
LPWCH __fastcall _crtGetEnvironmentStringsW()
{
  LPWCH result; // rax
  void *v1; // rbx
  LPWCH v2; // rdi
  unsigned __int64 v3; // rbp
  void *v4; // rax
  void *v5; // rsi

  result = GetEnvironmentStringsW();
  v1 = 0i64;
  v2 = result;
  if ( result )
  {
    while ( *result )
    {
      do
        ++result;
      while ( *result );
      ++result;
    }
    v3 = (int)result - (int)v2 + 2;
    v4 = malloc_crt(v3);
    v5 = v4;
    if ( v4 )
    {
      memmove(v4, v2, v3);
      v1 = v5;
    }
    FreeEnvironmentStringsW(v2);
    return (LPWCH)v1;
  }
  return result;
}

