// File Line: 96
// RVA: 0x12CDBAC
__int64 __fastcall _crtLCMapStringA_stat(localeinfo_struct *plocinfo, const wchar_t *LocaleName, unsigned int dwMapFlags, const char *lpSrcStr, int cchSrc, char *lpDestStr, int cchDest, int code_page, int bError)
{
  int v9; // ebx
  wchar_t **v10; // rdi
  const char *v11; // r12
  unsigned int v12; // er13
  int v13; // er10
  const char *v14; // rax
  UINT v15; // er14
  __int64 v16; // rsi
  int v17; // eax
  __int64 v18; // r15
  unsigned __int64 v20; // rcx
  signed __int64 v21; // rax
  void *v22; // rsp
  wchar_t **v23; // rax
  wchar_t *v24; // r12
  int v25; // eax
  unsigned __int64 v26; // rcx
  signed __int64 v27; // rax
  void *v28; // rsp
  wchar_t **v29; // rbx
  wchar_t **v30; // rax
  __int64 v31; // [rsp+0h] [rbp-40h]
  LPWSTR lpWideCharStr; // [rsp+20h] [rbp-20h]
  int cchWideChar; // [rsp+28h] [rbp-18h]
  LPCSTR lpDefaultChar; // [rsp+30h] [rbp-10h]
  LPBOOL lpUsedDefaultChar; // [rsp+38h] [rbp-8h]
  wchar_t *lpLocaleName; // [rsp+40h] [rbp+0h]

  v9 = cchSrc;
  v10 = 0i64;
  v11 = lpSrcStr;
  v12 = dwMapFlags;
  lpLocaleName = (wchar_t *)LocaleName;
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
  v15 = code_page;
  LODWORD(v16) = 0;
  if ( !code_page )
    v15 = plocinfo->locinfo->lc_codepage;
  v17 = MultiByteToWideChar(v15, bError != 0 ? 9 : 1, lpSrcStr, v9, 0i64, 0);
  v18 = v17;
  if ( !v17 )
    return 0i64;
  if ( v17 > 0 && 0xFFFFFFFFFFFFFFE0ui64 / v17 >= 2 )
  {
    v20 = 2i64 * v17 + 16;
    if ( v20 > 0x400 )
    {
      v23 = (wchar_t **)malloc(v20);
      v10 = v23;
      if ( !v23 )
        goto LABEL_22;
      *(_DWORD *)v23 = 56797;
    }
    else
    {
      v21 = 2i64 * v17 + 31;
      if ( 2 * v18 + 31 <= (unsigned __int64)(2 * v18 + 16) )
        v21 = 1152921504606846960i64;
      v22 = alloca(v21);
      v10 = &lpLocaleName;
      if ( &v31 == (__int64 *)-64i64 )
        return 0i64;
      LODWORD(lpLocaleName) = 52428;
    }
    v10 += 2;
  }
LABEL_22:
  if ( !v10 )
    return 0i64;
  if ( MultiByteToWideChar(v15, 1u, v11, v9, (LPWSTR)v10, v18) )
  {
    v24 = lpLocaleName;
    v25 = _crtLCMapStringEx(lpLocaleName, v12, (const wchar_t *)v10, v18, 0i64, 0);
    v16 = v25;
    if ( v25 )
    {
      if ( v12 & 0x400 )
      {
        if ( cchDest && v25 <= cchDest )
          _crtLCMapStringEx(v24, v12, (const wchar_t *)v10, v18, (unsigned __int16 *)lpDestStr, cchDest);
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
          v30 = (wchar_t **)malloc(v26);
          v29 = v30;
          if ( !v30 )
            goto LABEL_40;
          *(_DWORD *)v30 = 56797;
        }
        else
        {
          v27 = 2i64 * v25 + 31;
          if ( 2 * v16 + 31 <= (unsigned __int64)(2 * v16 + 16) )
            v27 = 1152921504606846960i64;
          v28 = alloca(v27);
          v29 = &lpLocaleName;
          if ( &v31 == (__int64 *)-64i64 )
            goto LABEL_48;
          LODWORD(lpLocaleName) = 52428;
        }
        v29 += 2;
      }
LABEL_40:
      if ( v29 )
      {
        if ( _crtLCMapStringEx(v24, v12, (const wchar_t *)v10, v18, (unsigned __int16 *)v29, v16) )
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
                           v15,
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
      goto LABEL_48;
    }
  }
LABEL_48:
  if ( *((_DWORD *)v10 - 4) == 56797 )
    free(v10 - 2);
  return (unsigned int)v16;
}

// File Line: 258
// RVA: 0x12CDE7C
__int64 __fastcall _crtLCMapStringA(localeinfo_struct *plocinfo, const wchar_t *LocaleName, unsigned int dwMapFlags, const char *lpSrcStr, int cchSrc, char *lpDestStr, int cchDest, int code_page, int bError)
{
  const wchar_t *v9; // rsi
  const char *v10; // rbx
  unsigned int v11; // edi
  __int64 result; // rax
  _LocaleUpdate v13; // [rsp+50h] [rbp-28h]

  v9 = LocaleName;
  v10 = lpSrcStr;
  v11 = dwMapFlags;
  _LocaleUpdate::_LocaleUpdate(&v13, plocinfo);
  result = _crtLCMapStringA_stat(&v13.localeinfo, v9, v11, v10, cchSrc, lpDestStr, cchDest, code_page, bError);
  if ( v13.updated )
    v13.ptd->_ownlocale &= 0xFFFFFFFD;
  return result;
}

