// File Line: 56
// RVA: 0x12D7D38
__int64 __fastcall _crtGetLocaleInfoA_stat(localeinfo_struct *plocinfo, const wchar_t *LocaleName, unsigned int LCType, char *lpLCData, int cchData)
{
  unsigned int v5; // er15
  const wchar_t *v6; // r12
  unsigned int v7; // er14
  char *v8; // r13
  unsigned int v9; // edi
  int v10; // eax
  __int64 v11; // rsi
  unsigned __int64 v13; // rcx
  signed __int64 v14; // rax
  void *v15; // rsp
  wchar_t *v16; // rbx
  wchar_t *v17; // rax
  __int64 v18; // [rsp+0h] [rbp-40h]
  LPSTR lpMultiByteStr; // [rsp+20h] [rbp-20h]
  int cbMultiByte; // [rsp+28h] [rbp-18h]
  LPCSTR lpDefaultChar; // [rsp+30h] [rbp-10h]
  LPBOOL lpUsedDefaultChar; // [rsp+38h] [rbp-8h]
  __int64 v23; // [rsp+40h] [rbp+0h]

  v5 = LCType;
  v6 = LocaleName;
  v7 = plocinfo->locinfo->lc_codepage;
  v8 = lpLCData;
  v9 = 0;
  v10 = _crtGetLocaleInfoEx(LocaleName, LCType, 0i64, 0);
  v11 = v10;
  if ( !v10 )
    return 0i64;
  if ( v10 <= 0 || 0xFFFFFFFFFFFFFFE0ui64 / v10 < 2 )
  {
    v16 = 0i64;
  }
  else
  {
    v13 = 2i64 * v10 + 16;
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
      v14 = 2i64 * v10 + 31;
      if ( 2 * v11 + 31 <= (unsigned __int64)(2 * v11 + 16) )
        v14 = 1152921504606846960i64;
      v15 = alloca(v14);
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
  if ( _crtGetLocaleInfoEx(v6, v5, v16, v11) )
  {
    lpUsedDefaultChar = 0i64;
    lpDefaultChar = 0i64;
    if ( cchData )
    {
      cbMultiByte = cchData;
      lpMultiByteStr = v8;
    }
    else
    {
      cbMultiByte = 0;
      lpMultiByteStr = 0i64;
    }
    v9 = WideCharToMultiByte(v7, 0, v16, -1, lpMultiByteStr, cbMultiByte, lpDefaultChar, lpUsedDefaultChar);
  }
  if ( *((_DWORD *)v16 - 4) == 56797 )
    free(v16 - 8);
  return v9;
}

// File Line: 120
// RVA: 0x12D7E94
__int64 __fastcall _crtGetLocaleInfoA(localeinfo_struct *plocinfo, const wchar_t *LocaleName, unsigned int LCType, char *lpLCData, int cchData)
{
  const wchar_t *v5; // rsi
  char *v6; // rbx
  unsigned int v7; // edi
  __int64 result; // rax
  _LocaleUpdate v9; // [rsp+30h] [rbp-28h]

  v5 = LocaleName;
  v6 = lpLCData;
  v7 = LCType;
  _LocaleUpdate::_LocaleUpdate(&v9, plocinfo);
  result = _crtGetLocaleInfoA_stat(&v9.localeinfo, v5, v7, v6, cchData);
  if ( v9.updated )
    v9.ptd->_ownlocale &= 0xFFFFFFFD;
  return result;
}

