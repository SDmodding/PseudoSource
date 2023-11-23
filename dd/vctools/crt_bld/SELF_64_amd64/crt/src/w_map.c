// File Line: 63
// RVA: 0x12D6240
int __fastcall _crtLCMapStringW(
        const wchar_t *LocaleName,
        unsigned int dwMapFlags,
        const wchar_t *lpSrcStr,
        int cchSrc,
        wchar_t *lpDestStr,
        int cchDest)
{
  int v6; // eax

  v6 = cchSrc;
  if ( cchSrc > 0 )
    v6 = wcsnlen(lpSrcStr, cchSrc);
  return _crtLCMapStringEx(LocaleName, dwMapFlags, lpSrcStr, v6, lpDestStr, cchDest);
}

