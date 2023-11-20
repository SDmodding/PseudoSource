// File Line: 60
// RVA: 0x12D628C
__int64 __fastcall _crtGetStringTypeA_stat(localeinfo_struct *plocinfo, unsigned int dwInfoType, const char *lpSrcStr, int cchSrc, unsigned __int16 *lpCharType, int code_page, int bError)
{
  UINT v7; // er14
  unsigned int v8; // edi
  int v9; // er15
  const char *v10; // r12
  unsigned int v11; // er13
  int v12; // eax
  __int64 cchWideChar; // rsi
  unsigned __int64 v15; // rcx
  signed __int64 v16; // rax
  void *v17; // rsp
  __int64 *lpWideCharStr; // rbx
  __int64 *v19; // rax
  int v20; // eax
  __int64 v21; // [rsp+0h] [rbp-30h]
  __int64 v22; // [rsp+30h] [rbp+0h]

  v7 = code_page;
  v8 = 0;
  v9 = cchSrc;
  v10 = lpSrcStr;
  v11 = dwInfoType;
  if ( !code_page )
    v7 = plocinfo->locinfo->lc_codepage;
  v12 = MultiByteToWideChar(v7, bError != 0 ? 9 : 1, lpSrcStr, cchSrc, 0i64, 0);
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
        v16 = 1152921504606846960i64;
      v17 = alloca(v16);
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
  v20 = MultiByteToWideChar(v7, 1u, v10, v9, (LPWSTR)lpWideCharStr, cchWideChar);
  if ( v20 )
    v8 = GetStringTypeW(v11, (LPCWSTR)lpWideCharStr, v20, lpCharType);
  if ( *((_DWORD *)lpWideCharStr - 4) == 56797 )
    free(lpWideCharStr - 2);
  return v8;
}

// File Line: 129
// RVA: 0x12D63F4
__int64 __fastcall _crtGetStringTypeA(localeinfo_struct *plocinfo, unsigned int dwInfoType, const char *lpSrcStr, int cchSrc, unsigned __int16 *lpCharType, int code_page, int bError)
{
  unsigned int v7; // esi
  int v8; // ebx
  const char *v9; // rdi
  __int64 result; // rax
  _LocaleUpdate v11; // [rsp+40h] [rbp-28h]

  v7 = dwInfoType;
  v8 = cchSrc;
  v9 = lpSrcStr;
  _LocaleUpdate::_LocaleUpdate(&v11, plocinfo);
  result = _crtGetStringTypeA_stat(&v11.localeinfo, v7, v9, v8, lpCharType, code_page, bError);
  if ( v11.updated )
    v11.ptd->_ownlocale &= 0xFFFFFFFD;
  return result;
}

