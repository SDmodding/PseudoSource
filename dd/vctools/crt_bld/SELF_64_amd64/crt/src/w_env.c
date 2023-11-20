// File Line: 37
// RVA: 0x1334F6C
LPWCH __fastcall _crtGetEnvironmentStringsW()
{
  LPWCH result; // rax
  wchar_t *v1; // rbx
  LPWCH v2; // rdi
  unsigned __int64 v3; // rbp
  wchar_t *v4; // rax
  wchar_t *v5; // rsi

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
    v3 = (signed int)result - (signed int)v2 + 2;
    v4 = (wchar_t *)malloc_crt(v3);
    v5 = v4;
    if ( v4 )
    {
      memmove(v4, v2, v3);
      v1 = v5;
    }
    FreeEnvironmentStringsW(v2);
    result = v1;
  }
  return result;
}

