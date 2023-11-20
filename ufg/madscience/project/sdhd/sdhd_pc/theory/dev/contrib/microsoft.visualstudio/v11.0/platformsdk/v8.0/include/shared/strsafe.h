// File Line: 656
// RVA: 0xA147B0
signed __int64 __fastcall StringCchCopyW(wchar_t *pszDest, unsigned __int64 cchDest, const wchar_t *pszSrc)
{
  signed int v3; // er10
  unsigned __int64 v4; // r9
  signed __int64 v5; // r8
  wchar_t v6; // ax

  v3 = 0;
  if ( cchDest - 1 > 0x7FFFFFFE )
    v3 = -2147024809;
  if ( v3 >= 0 )
  {
    v3 = 0;
    if ( !cchDest )
      goto LABEL_17;
    v4 = 2147483646 - cchDest;
    v5 = (char *)pszSrc - (char *)pszDest;
    while ( v4 + cchDest )
    {
      v6 = *(wchar_t *)((char *)pszDest + v5);
      if ( !v6 )
        break;
      *pszDest = v6;
      ++pszDest;
      if ( !--cchDest )
      {
        *(pszDest - 1) = 0;
        return 2147942522i64;
      }
    }
    if ( !cchDest )
    {
LABEL_17:
      *(pszDest - 1) = 0;
      return 2147942522i64;
    }
    goto LABEL_13;
  }
  if ( cchDest )
LABEL_13:
    *pszDest = 0;
  return (unsigned int)v3;
}

