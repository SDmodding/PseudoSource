// File Line: 40
// RVA: 0x12D209C
char *__fastcall _crtGetEnvironmentStringsA()
{
  const wchar_t *EnvironmentStringsW; // rax
  wchar_t *v1; // rdi
  const wchar_t *i; // rbx
  __int64 v3; // rbx
  int v4; // eax
  int cbMultiByte; // ebp
  char *lpMultiByteStr; // rax
  char *v7; // rsi

  EnvironmentStringsW = GetEnvironmentStringsW();
  v1 = (wchar_t *)EnvironmentStringsW;
  if ( !EnvironmentStringsW )
    return 0i64;
  for ( i = EnvironmentStringsW; *i; ++i )
  {
    do
      ++i;
    while ( *i );
  }
  v3 = i - EnvironmentStringsW;
  v4 = WideCharToMultiByte(0, 0, EnvironmentStringsW, v3 + 1, 0i64, 0, 0i64, 0i64);
  cbMultiByte = v4;
  if ( !v4 || (lpMultiByteStr = (char *)malloc_crt(v4), (v7 = lpMultiByteStr) == 0i64) )
  {
    FreeEnvironmentStringsW(v1);
    return 0i64;
  }
  if ( !WideCharToMultiByte(0, 0, v1, v3 + 1, lpMultiByteStr, cbMultiByte, 0i64, 0i64) )
  {
    free(v7);
    v7 = 0i64;
  }
  FreeEnvironmentStringsW(v1);
  return v7;
}

