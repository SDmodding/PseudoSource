// File Line: 54
// RVA: 0x12CEF40
int __fastcall _crtCompareStringW(
        const wchar_t *LocaleName,
        unsigned int dwCmpFlags,
        const wchar_t *lpString1,
        int cchCount1,
        const wchar_t *lpString2,
        int cchCount2)
{
  int v6; // ebx
  int v10; // eax
  int result; // eax
  int v12; // ebx

  v6 = cchCount1;
  if ( cchCount1 > 0 )
    v6 = wcsnlen(lpString1, cchCount1);
  v10 = cchCount2;
  if ( cchCount2 > 0 )
    v10 = wcsnlen(lpString2, cchCount2);
  if ( v6 && v10 )
    return _crtCompareStringEx(LocaleName, dwCmpFlags, lpString1, v6, lpString2, v10);
  v12 = v6 - v10;
  result = 3;
  if ( v12 < 0 )
    result = 1;
  if ( !v12 )
    return 2;
  return result;
}

