// File Line: 56
// RVA: 0x12D7D38
__int64 __fastcall _crtGetLocaleInfoA_stat(
        localeinfo_struct *plocinfo,
        const wchar_t *LocaleName,
        unsigned int LCType,
        char *lpLCData,
        int cchData)
{
  unsigned int lc_codepage; // r14d
  unsigned int v9; // edi
  int LocaleInfo; // eax
  __int64 v11; // rsi
  unsigned __int64 v13; // rcx
  __int64 v14; // rax
  void *v15; // rsp
  wchar_t *v16; // rbx
  wchar_t *v17; // rax
  __int64 v18; // [rsp+0h] [rbp-40h] BYREF
  LPSTR lpMultiByteStr; // [rsp+20h] [rbp-20h]
  int cbMultiByte; // [rsp+28h] [rbp-18h]
  LPCSTR lpDefaultChar; // [rsp+30h] [rbp-10h]
  LPBOOL lpUsedDefaultChar; // [rsp+38h] [rbp-8h]
  __int64 v23; // [rsp+40h] [rbp+0h] BYREF

  lc_codepage = plocinfo->locinfo->lc_codepage;
  v9 = 0;
  LocaleInfo = _crtGetLocaleInfoEx(LocaleName, LCType, 0i64, 0);
  v11 = LocaleInfo;
  if ( !LocaleInfo )
    return 0i64;
  if ( LocaleInfo <= 0 || 0xFFFFFFFFFFFFFFE0ui64 / LocaleInfo < 2 )
  {
    v16 = 0i64;
  }
  else
  {
    v13 = 2i64 * LocaleInfo + 16;
    if ( v13 > 0x400 )
    {
      v17 = (wchar_t *)malloc(v13);
      v16 = v17;
      if ( !v17 )
        goto LABEL_14;
      *(_DWORD *)v17 = 56797;
    }
    else
    {
      v14 = 2i64 * LocaleInfo + 31;
      if ( 2 * v11 + 31 <= (unsigned __int64)(2 * v11 + 16) )
        v14 = 0xFFFFFFFFFFFFFF0i64;
      v15 = alloca(v14 & 0xFFFFFFFFFFFFFFF0ui64);
      v16 = (wchar_t *)&v23;
      if ( &v18 == (__int64 *)-64i64 )
        return 0i64;
      LODWORD(v23) = 52428;
    }
    v16 += 8;
  }
LABEL_14:
  if ( !v16 )
    return 0i64;
  if ( _crtGetLocaleInfoEx(LocaleName, LCType, v16, v11) )
  {
    lpUsedDefaultChar = 0i64;
    lpDefaultChar = 0i64;
    if ( cchData )
    {
      cbMultiByte = cchData;
      lpMultiByteStr = lpLCData;
    }
    else
    {
      cbMultiByte = 0;
      lpMultiByteStr = 0i64;
    }
    v9 = WideCharToMultiByte(lc_codepage, 0, v16, -1, lpMultiByteStr, cbMultiByte, lpDefaultChar, lpUsedDefaultChar);
  }
  if ( *((_DWORD *)v16 - 4) == 56797 )
    free(v16 - 8);
  return v9;
}

// File Line: 120
// RVA: 0x12D7E94
__int64 __fastcall _crtGetLocaleInfoA(
        localeinfo_struct *plocinfo,
        const wchar_t *LocaleName,
        unsigned int LCType,
        char *lpLCData,
        int cchData)
{
  __int64 result; // rax
  _LocaleUpdate v9; // [rsp+30h] [rbp-28h] BYREF

  _LocaleUpdate::_LocaleUpdate(&v9, plocinfo);
  result = _crtGetLocaleInfoA_stat(&v9.localeinfo, LocaleName, LCType, lpLCData, cchData);
  if ( v9.updated )
    v9.ptd->_ownlocale &= ~2u;
  return result;
}

