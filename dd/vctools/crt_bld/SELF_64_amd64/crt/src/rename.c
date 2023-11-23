// File Line: 44
// RVA: 0x12C1E5C
__int64 __fastcall rename(const char *oldname, const char *newname)
{
  UINT v4; // ebx
  int v5; // eax
  __int64 cchWideChar; // rsi
  int v7; // eax
  int v8; // r14d
  wchar_t *lpWideCharStr; // rax
  wchar_t *v10; // rdi
  wchar_t *v11; // rbp
  unsigned int v12; // ebx
  unsigned int v14; // eax
  unsigned int LastError; // eax

  v4 = 0;
  if ( !_crtIsPackagedApp() && !AreFileApisANSI() )
    v4 = 1;
  v5 = MultiByteToWideChar(v4, 0, oldname, -1, 0i64, 0);
  cchWideChar = v5;
  if ( !v5 || (v7 = MultiByteToWideChar(v4, 0, newname, -1, 0i64, 0), (v8 = v7) == 0) )
  {
    LastError = GetLastError();
    dosmaperr(LastError);
    return 0xFFFFFFFFi64;
  }
  lpWideCharStr = (wchar_t *)malloc_crt(2i64 * (v7 + (int)cchWideChar));
  v10 = lpWideCharStr;
  if ( !lpWideCharStr )
    return 0xFFFFFFFFi64;
  v11 = &lpWideCharStr[cchWideChar];
  if ( MultiByteToWideChar(v4, 0, oldname, -1, lpWideCharStr, cchWideChar)
    && MultiByteToWideChar(v4, 0, newname, -1, v11, v8) )
  {
    v12 = wrename(v10, v11);
    free(v10);
    return v12;
  }
  else
  {
    free(v10);
    v14 = GetLastError();
    dosmaperr(v14);
    return 0xFFFFFFFFi64;
  }
}

// File Line: 103
// RVA: 0x12BD540
__int64 __fastcall wrename(const wchar_t *oldname, const wchar_t *newname)
{
  unsigned int LastError; // eax

  if ( MoveFileExW(oldname, newname, 2u) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( !LastError )
    return 0i64;
  dosmaperr(LastError);
  return 0xFFFFFFFFi64;
}

