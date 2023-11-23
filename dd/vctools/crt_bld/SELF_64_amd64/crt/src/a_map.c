// File Line: 96
// RVA: 0x12CDBAC
__int64 __fastcall _crtLCMapStringA_stat(
        localeinfo_struct *plocinfo,
        wchar_t *LocaleName,
        unsigned int dwMapFlags,
        const char *lpSrcStr,
        int cchSrc,
        char *lpDestStr,
        int cchDest,
        int code_page,
        int bError)
{
  int v9; // ebx
  wchar_t **p_lpLocaleName; // rdi
  int v13; // r10d
  const char *v14; // rax
  unsigned int lc_codepage; // r14d
  __int64 v16; // rsi
  int v17; // eax
  __int64 v18; // r15
  unsigned __int64 v20; // rcx
  __int64 v21; // rax
  void *v22; // rsp
  _DWORD *v23; // rax
  wchar_t *v24; // r12
  int v25; // eax
  unsigned __int64 v26; // rcx
  __int64 v27; // rax
  void *v28; // rsp
  wchar_t **v29; // rbx
  _DWORD *v30; // rax
  _BYTE v31[32]; // [rsp+0h] [rbp-40h] BYREF
  LPWSTR lpWideCharStr; // [rsp+20h] [rbp-20h]
  int cchWideChar; // [rsp+28h] [rbp-18h]
  LPCSTR lpDefaultChar; // [rsp+30h] [rbp-10h]
  LPBOOL lpUsedDefaultChar; // [rsp+38h] [rbp-8h]
  wchar_t *lpLocaleName; // [rsp+40h] [rbp+0h] BYREF

  v9 = cchSrc;
  p_lpLocaleName = 0i64;
  lpLocaleName = LocaleName;
  if ( cchSrc > 0 )
  {
    v13 = cchSrc;
    v14 = lpSrcStr;
    while ( 1 )
    {
      --v13;
      if ( !*v14 )
        break;
      ++v14;
      if ( !v13 )
      {
        v13 = -1;
        break;
      }
    }
    v9 = cchSrc - v13;
    if ( cchSrc - v13 - 1 >= cchSrc )
      v9 = cchSrc - v13 - 1;
  }
  lc_codepage = code_page;
  LODWORD(v16) = 0;
  if ( !code_page )
    lc_codepage = plocinfo->locinfo->lc_codepage;
  v17 = MultiByteToWideChar(lc_codepage, bError != 0 ? 9 : 1, lpSrcStr, v9, 0i64, 0);
  v18 = v17;
  if ( !v17 )
    return 0i64;
  if ( v17 > 0 && 0xFFFFFFFFFFFFFFE0ui64 / v17 >= 2 )
  {
    v20 = 2i64 * v17 + 16;
    if ( v20 > 0x400 )
    {
      v23 = malloc(v20);
      p_lpLocaleName = (wchar_t **)v23;
      if ( !v23 )
        goto LABEL_22;
      *v23 = 56797;
    }
    else
    {
      v21 = 2i64 * v17 + 31;
      if ( 2 * v18 + 31 <= (unsigned __int64)(2 * v18 + 16) )
        v21 = 0xFFFFFFFFFFFFFF0i64;
      v22 = alloca(v21 & 0xFFFFFFFFFFFFFFF0ui64);
      p_lpLocaleName = &lpLocaleName;
      if ( v31 == (_BYTE *)-64i64 )
        return 0i64;
      LODWORD(lpLocaleName) = 52428;
    }
    p_lpLocaleName += 2;
  }
LABEL_22:
  if ( !p_lpLocaleName )
    return 0i64;
  if ( MultiByteToWideChar(lc_codepage, 1u, lpSrcStr, v9, (LPWSTR)p_lpLocaleName, v18) )
  {
    v24 = lpLocaleName;
    v25 = _crtLCMapStringEx(lpLocaleName, dwMapFlags, (const wchar_t *)p_lpLocaleName, v18, 0i64, 0);
    v16 = v25;
    if ( v25 )
    {
      if ( (dwMapFlags & 0x400) != 0 )
      {
        if ( cchDest && v25 <= cchDest )
          _crtLCMapStringEx(
            v24,
            dwMapFlags,
            (const wchar_t *)p_lpLocaleName,
            v18,
            (unsigned __int16 *)lpDestStr,
            cchDest);
        goto LABEL_48;
      }
      if ( v25 <= 0 || 0xFFFFFFFFFFFFFFE0ui64 / v25 < 2 )
      {
        v29 = 0i64;
      }
      else
      {
        v26 = 2i64 * v25 + 16;
        if ( v26 > 0x400 )
        {
          v30 = malloc(v26);
          v29 = (wchar_t **)v30;
          if ( !v30 )
            goto LABEL_40;
          *v30 = 56797;
        }
        else
        {
          v27 = 2i64 * v25 + 31;
          if ( 2 * v16 + 31 <= (unsigned __int64)(2 * v16 + 16) )
            v27 = 0xFFFFFFFFFFFFFF0i64;
          v28 = alloca(v27 & 0xFFFFFFFFFFFFFFF0ui64);
          v29 = &lpLocaleName;
          if ( v31 == (_BYTE *)-64i64 )
            goto LABEL_48;
          LODWORD(lpLocaleName) = 52428;
        }
        v29 += 2;
      }
LABEL_40:
      if ( v29 )
      {
        if ( _crtLCMapStringEx(v24, dwMapFlags, (const wchar_t *)p_lpLocaleName, v18, (unsigned __int16 *)v29, v16) )
        {
          lpUsedDefaultChar = 0i64;
          lpDefaultChar = 0i64;
          if ( cchDest )
          {
            cchWideChar = cchDest;
            lpWideCharStr = (LPWSTR)lpDestStr;
          }
          else
          {
            cchWideChar = 0;
            lpWideCharStr = 0i64;
          }
          LODWORD(v16) = WideCharToMultiByte(
                           lc_codepage,
                           0,
                           (LPCWSTR)v29,
                           v16,
                           (LPSTR)lpWideCharStr,
                           cchWideChar,
                           lpDefaultChar,
                           lpUsedDefaultChar);
        }
        if ( *((_DWORD *)v29 - 4) == 56797 )
          free(v29 - 2);
      }
    }
  }
LABEL_48:
  if ( *((_DWORD *)p_lpLocaleName - 4) == 56797 )
    free(p_lpLocaleName - 2);
  return (unsigned int)v16;
}

// File Line: 258
// RVA: 0x12CDE7C
__int64 __fastcall _crtLCMapStringA(
        localeinfo_struct *plocinfo,
        wchar_t *LocaleName,
        unsigned int dwMapFlags,
        const char *lpSrcStr,
        int cchSrc,
        char *lpDestStr,
        int cchDest,
        int code_page,
        int bError)
{
  __int64 result; // rax
  _LocaleUpdate v13; // [rsp+50h] [rbp-28h] BYREF

  _LocaleUpdate::_LocaleUpdate(&v13, plocinfo);
  result = _crtLCMapStringA_stat(
             &v13.localeinfo,
             LocaleName,
             dwMapFlags,
             lpSrcStr,
             cchSrc,
             lpDestStr,
             cchDest,
             code_page,
             bError);
  if ( v13.updated )
    v13.ptd->_ownlocale &= ~2u;
  return result;
}

