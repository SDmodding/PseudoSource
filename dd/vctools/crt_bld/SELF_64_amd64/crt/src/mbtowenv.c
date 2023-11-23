// File Line: 43
// RVA: 0x1334EA4
__int64 __fastcall _mbtow_environ()
{
  LPCSTR *v0; // rbx
  const char *v1; // rax
  int v2; // eax
  int cchWideChar; // edi
  unsigned __int16 *lpWideCharStr; // rax
  unsigned __int16 *v6; // rcx
  unsigned __int16 *poption; // [rsp+40h] [rbp+8h] BYREF

  poption = 0i64;
  v0 = (LPCSTR *)environ;
  v1 = *environ;
  if ( !*environ )
    return 0i64;
  while ( 1 )
  {
    v2 = MultiByteToWideChar(0, 0, v1, -1, 0i64, 0);
    cchWideChar = v2;
    if ( !v2 )
      return 0xFFFFFFFFi64;
    lpWideCharStr = (unsigned __int16 *)calloc_crt(v2, 2ui64);
    poption = lpWideCharStr;
    if ( !lpWideCharStr )
      return 0xFFFFFFFFi64;
    if ( !MultiByteToWideChar(0, 0, *v0, -1, lpWideCharStr, cchWideChar) )
    {
      v6 = poption;
LABEL_11:
      free(v6);
      return 0xFFFFFFFFi64;
    }
    if ( (int)_crtwsetenv((__m128i **)&poption, 0) < 0 )
    {
      v6 = poption;
      if ( !poption )
        return 0xFFFFFFFFi64;
      goto LABEL_11;
    }
    v1 = *++v0;
    if ( !*v0 )
      return 0i64;
  }
}

