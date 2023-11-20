// File Line: 63
// RVA: 0x12D6240
int __fastcall _crtLCMapStringW(const wchar_t *LocaleName, unsigned int dwMapFlags, const wchar_t *lpSrcStr, int cchSrc, wchar_t *lpDestStr, int cchDest)
{
  int v6; // eax
  const wchar_t *v7; // rbx
  unsigned int v8; // edi
  const wchar_t *v9; // rsi

  v6 = cchSrc;
  v7 = lpSrcStr;
  v8 = dwMapFlags;
  v9 = LocaleName;
  if ( cchSrc > 0 )
    v6 = wcsnlen(lpSrcStr, cchSrc);
  return _crtLCMapStringEx(v9, v8, v7, v6, lpDestStr, cchDest);
}

