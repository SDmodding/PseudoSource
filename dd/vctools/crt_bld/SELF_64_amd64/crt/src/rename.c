// File Line: 44
// RVA: 0x12C1E5C
signed __int64 __fastcall rename(const char *oldname, const char *newname)
{
  const char *v2; // r15
  const char *v3; // r12
  UINT v4; // ebx
  int v5; // eax
  __int64 cchWideChar; // rsi
  int v7; // eax
  int v8; // er14
  wchar_t *lpWideCharStr; // rax
  wchar_t *v10; // rdi
  wchar_t *v11; // rbp
  unsigned int v12; // ebx
  signed __int64 result; // rax
  unsigned int v14; // eax
  unsigned int v15; // eax

  v2 = newname;
  v3 = oldname;
  v4 = 0;
  if ( !_crtIsPackagedApp() && !AreFileApisANSI() )
    v4 = 1;
  v5 = MultiByteToWideChar(v4, 0, v3, -1, 0i64, 0);
  cchWideChar = v5;
  if ( !v5 || (v7 = MultiByteToWideChar(v4, 0, v2, -1, 0i64, 0), (v8 = v7) == 0) )
  {
    v15 = GetLastError();
    dosmaperr(v15);
    return 0xFFFFFFFFi64;
  }
  lpWideCharStr = (wchar_t *)malloc_crt(2i64 * (v7 + (signed int)cchWideChar));
  v10 = lpWideCharStr;
  if ( !lpWideCharStr )
    return 0xFFFFFFFFi64;
  v11 = &lpWideCharStr[cchWideChar];
  if ( MultiByteToWideChar(v4, 0, v3, -1, lpWideCharStr, cchWideChar) && MultiByteToWideChar(v4, 0, v2, -1, v11, v8) )
  {
    v12 = wrename(v10, v11);
    free(v10);
    result = v12;
  }
  else
  {
    free(v10);
    v14 = GetLastError();
    dosmaperr(v14);
    result = 0xFFFFFFFFi64;
  }
  return result;
}

// File Line: 103
// RVA: 0x12BD540
signed __int64 __fastcall wrename(const wchar_t *oldname, const wchar_t *newname)
{
  unsigned int v2; // eax

  if ( MoveFileExW(oldname, newname, 2u) )
    v2 = 0;
  else
    v2 = GetLastError();
  if ( !v2 )
    return 0i64;
  dosmaperr(v2);
  return 0xFFFFFFFFi64;
}

