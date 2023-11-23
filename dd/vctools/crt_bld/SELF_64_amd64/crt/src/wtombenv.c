// File Line: 43
// RVA: 0x12D59F0
__int64 __fastcall _wtomb_environ()
{
  LPCWSTR *v0; // rbx
  const wchar_t *v1; // rax
  int v2; // eax
  int cbMultiByte; // edi
  char *lpMultiByteStr; // rax
  char *poption; // [rsp+50h] [rbp+8h] BYREF

  poption = 0i64;
  v0 = (LPCWSTR *)wenviron;
  v1 = *wenviron;
  if ( !*wenviron )
    return 0i64;
  while ( 1 )
  {
    v2 = WideCharToMultiByte(0, 0, v1, -1, 0i64, 0, 0i64, 0i64);
    cbMultiByte = v2;
    if ( !v2 )
      break;
    lpMultiByteStr = (char *)calloc_crt(v2, 1ui64);
    poption = lpMultiByteStr;
    if ( !lpMultiByteStr )
      break;
    if ( !WideCharToMultiByte(0, 0, *v0, -1, lpMultiByteStr, cbMultiByte, 0i64, 0i64) )
    {
      free(poption);
      return 0xFFFFFFFFi64;
    }
    if ( _crtsetenv(&poption, 0) < 0 )
    {
      if ( poption )
      {
        free(poption);
        poption = 0i64;
      }
    }
    v1 = *++v0;
    if ( !*v0 )
      return 0i64;
  }
  return 0xFFFFFFFFi64;
}

