// File Line: 60
// RVA: 0x12D628C
__int64 __fastcall _crtGetStringTypeA_stat(
        localeinfo_struct *plocinfo,
        DWORD dwInfoType,
        const char *lpSrcStr,
        int cchSrc,
        unsigned __int16 *lpCharType,
        int code_page,
        int bError)
{
  unsigned int lc_codepage; // r14d
  unsigned int StringTypeW; // edi
  int v12; // eax
  __int64 cchWideChar; // rsi
  unsigned __int64 v15; // rcx
  __int64 v16; // rax
  void *v17; // rsp
  __int64 *lpWideCharStr; // rbx
  __int64 *v19; // rax
  int v20; // eax
  __int64 v21; // [rsp+0h] [rbp-30h] BYREF
  __int64 v22; // [rsp+30h] [rbp+0h] BYREF

  lc_codepage = code_page;
  StringTypeW = 0;
  if ( !code_page )
    lc_codepage = plocinfo->locinfo->lc_codepage;
  v12 = MultiByteToWideChar(lc_codepage, bError != 0 ? 9 : 1, lpSrcStr, cchSrc, 0i64, 0);
  cchWideChar = v12;
  if ( !v12 )
    return 0i64;
  if ( v12 <= 0 || (unsigned __int64)v12 > 0x7FFFFFFFFFFFFFF0i64 )
  {
    lpWideCharStr = 0i64;
  }
  else
  {
    v15 = 2i64 * v12 + 16;
    if ( v15 > 0x400 )
    {
      v19 = (__int64 *)malloc(v15);
      lpWideCharStr = v19;
      if ( !v19 )
        goto LABEL_16;
      *(_DWORD *)v19 = 56797;
    }
    else
    {
      v16 = 2i64 * v12 + 31;
      if ( 2 * cchWideChar + 31 <= (unsigned __int64)(2 * cchWideChar + 16) )
        v16 = 0xFFFFFFFFFFFFFF0i64;
      v17 = alloca(v16 & 0xFFFFFFFFFFFFFFF0ui64);
      lpWideCharStr = &v22;
      if ( &v21 == (__int64 *)-48i64 )
        return 0i64;
      LODWORD(v22) = 52428;
    }
    lpWideCharStr += 2;
  }
LABEL_16:
  if ( !lpWideCharStr )
    return 0i64;
  memset(lpWideCharStr, 0, 2 * cchWideChar);
  v20 = MultiByteToWideChar(lc_codepage, 1u, lpSrcStr, cchSrc, (LPWSTR)lpWideCharStr, cchWideChar);
  if ( v20 )
    StringTypeW = GetStringTypeW(dwInfoType, (LPCWSTR)lpWideCharStr, v20, lpCharType);
  if ( *((_DWORD *)lpWideCharStr - 4) == 56797 )
    free(lpWideCharStr - 2);
  return StringTypeW;
}

// File Line: 129
// RVA: 0x12D63F4
__int64 __fastcall _crtGetStringTypeA(
        localeinfo_struct *plocinfo,
        DWORD dwInfoType,
        const char *lpSrcStr,
        int cchSrc,
        unsigned __int16 *lpCharType,
        int code_page,
        int bError)
{
  __int64 result; // rax
  _LocaleUpdate v11; // [rsp+40h] [rbp-28h] BYREF

  _LocaleUpdate::_LocaleUpdate(&v11, plocinfo);
  result = _crtGetStringTypeA_stat(&v11.localeinfo, dwInfoType, lpSrcStr, cchSrc, lpCharType, code_page, bError);
  if ( v11.updated )
    v11.ptd->_ownlocale &= ~2u;
  return result;
}

