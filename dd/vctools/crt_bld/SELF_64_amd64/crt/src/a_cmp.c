// File Line: 93
// RVA: 0x12D5E04
signed __int64 __fastcall _crtCompareStringA_stat(localeinfo_struct *plocinfo, const wchar_t *LocaleName, unsigned int dwCmpFlags, const char *lpString1, int cchCount1, const char *lpString2, int cchCount2, int code_page)
{
  int v8; // edi
  unsigned int v9; // ebx
  const char *v10; // r12
  int v11; // edx
  const char *v12; // rax
  int v13; // esi
  int v14; // eax
  const char *v15; // rdx
  UINT v17; // er15
  bool v18; // zf
  char *i; // rax
  bool v20; // zf
  char *j; // rax
  int v22; // eax
  __int64 cchWideChar; // r13
  unsigned __int64 v24; // rcx
  signed __int64 v25; // rax
  void *v26; // rsp
  unsigned int *lpWideCharStr; // r14
  unsigned int *v28; // rax
  int v29; // eax
  __int64 v30; // r12
  unsigned __int64 v31; // rcx
  signed __int64 v32; // rax
  void *v33; // rsp
  unsigned int *v34; // rdi
  unsigned int *v35; // rax
  __int64 v36; // [rsp+0h] [rbp-30h]
  unsigned int dwCmpFlagsa; // [rsp+30h] [rbp+0h]
  LPCSTR lpMultiByteStr; // [rsp+38h] [rbp+8h]
  wchar_t *lpLocaleName; // [rsp+40h] [rbp+10h]
  _cpinfo CPInfo; // [rsp+48h] [rbp+18h]

  v8 = cchCount1;
  v9 = 0;
  dwCmpFlagsa = dwCmpFlags;
  v10 = lpString1;
  lpLocaleName = (wchar_t *)LocaleName;
  lpMultiByteStr = lpString2;
  if ( cchCount1 <= 0 )
  {
    if ( cchCount1 < -1 )
      return 0i64;
  }
  else
  {
    v11 = cchCount1;
    v12 = lpString1;
    while ( 1 )
    {
      --v11;
      if ( !*v12 )
        break;
      ++v12;
      if ( !v11 )
      {
        v11 = -1;
        break;
      }
    }
    v8 = -1 - v11 + cchCount1;
  }
  v13 = cchCount2;
  if ( cchCount2 <= 0 )
  {
    if ( cchCount2 < -1 )
      return 0i64;
  }
  else
  {
    v14 = cchCount2;
    v15 = lpString2;
    while ( 1 )
    {
      --v14;
      if ( !*v15 )
        break;
      ++v15;
      if ( !v14 )
      {
        v14 = -1;
        break;
      }
    }
    v13 = -1 - v14 + cchCount2;
  }
  v17 = code_page;
  if ( !code_page )
    v17 = plocinfo->locinfo->lc_codepage;
  if ( v8 && v13 )
    goto LABEL_43;
  if ( v8 == v13 )
    return 2i64;
  if ( v13 > 1 )
    return 1i64;
  if ( v8 > 1 )
    return 3i64;
  if ( !GetCPInfo(v17, &CPInfo) )
    return 0i64;
  if ( v8 > 0 )
  {
    if ( CPInfo.MaxCharSize >= 2 )
    {
      v18 = CPInfo.LeadByte[0] == 0;
      for ( i = CPInfo.LeadByte; !v18 && i[1]; v18 = *i == 0 )
      {
        if ( *v10 >= (unsigned __int8)*i && *v10 <= (unsigned __int8)i[1] )
          return 2i64;
        i += 2;
      }
    }
    return 3i64;
  }
  if ( v13 > 0 )
  {
    if ( CPInfo.MaxCharSize >= 2 )
    {
      v20 = CPInfo.LeadByte[0] == 0;
      for ( j = CPInfo.LeadByte; !v20 && j[1]; v20 = *j == 0 )
      {
        if ( *lpString2 >= (unsigned __int8)*j && *lpString2 <= (unsigned __int8)j[1] )
          return 2i64;
        j += 2;
      }
    }
    return 1i64;
  }
LABEL_43:
  v22 = MultiByteToWideChar(v17, 9u, v10, v8, 0i64, 0);
  cchWideChar = v22;
  if ( !v22 )
    return 0i64;
  if ( v22 <= 0 || 0xFFFFFFFFFFFFFFE0ui64 / v22 < 2 )
  {
    lpWideCharStr = 0i64;
  }
  else
  {
    v24 = 2i64 * v22 + 16;
    if ( v24 > 0x400 )
    {
      v28 = (unsigned int *)malloc(v24);
      lpWideCharStr = v28;
      if ( !v28 )
        goto LABEL_55;
      *v28 = 56797;
    }
    else
    {
      v25 = 2i64 * v22 + 31;
      if ( 2 * cchWideChar + 31 <= (unsigned __int64)(2 * cchWideChar + 16) )
        v25 = 1152921504606846960i64;
      v26 = alloca(v25);
      lpWideCharStr = &dwCmpFlagsa;
      if ( &v36 == (__int64 *)-48i64 )
        return 0i64;
      dwCmpFlagsa = 52428;
    }
    lpWideCharStr += 4;
  }
LABEL_55:
  if ( !lpWideCharStr )
    return 0i64;
  if ( MultiByteToWideChar(v17, 1u, v10, v8, (LPWSTR)lpWideCharStr, cchWideChar) )
  {
    v29 = MultiByteToWideChar(v17, 9u, lpMultiByteStr, v13, 0i64, 0);
    v30 = v29;
    if ( v29 )
    {
      if ( v29 <= 0 || 0xFFFFFFFFFFFFFFE0ui64 / v29 < 2 )
      {
        v34 = 0i64;
      }
      else
      {
        v31 = 2i64 * v29 + 16;
        if ( v31 > 0x400 )
        {
          v35 = (unsigned int *)malloc(v31);
          v34 = v35;
          if ( !v35 )
            goto LABEL_69;
          *v35 = 56797;
        }
        else
        {
          v32 = 2i64 * v29 + 31;
          if ( 2 * v30 + 31 <= (unsigned __int64)(2 * v30 + 16) )
            v32 = 1152921504606846960i64;
          v33 = alloca(v32);
          v34 = &dwCmpFlagsa;
          if ( &v36 == (__int64 *)-48i64 )
            goto $error_cleanup_2;
          dwCmpFlagsa = 52428;
        }
        v34 += 4;
      }
LABEL_69:
      if ( v34 )
      {
        if ( MultiByteToWideChar(v17, 1u, lpMultiByteStr, v13, (LPWSTR)v34, v30) )
          v9 = _crtCompareStringEx(
                 lpLocaleName,
                 dwCmpFlagsa,
                 (const wchar_t *)lpWideCharStr,
                 cchWideChar,
                 (const wchar_t *)v34,
                 v30);
        if ( *(v34 - 4) == 56797 )
          free(v34 - 4);
      }
      goto $error_cleanup_2;
    }
  }
$error_cleanup_2:
  if ( *(lpWideCharStr - 4) == 56797 )
    free(lpWideCharStr - 4);
  return v9;
}

// File Line: 266
// RVA: 0x12D614C
signed __int64 __fastcall _crtCompareStringA(localeinfo_struct *plocinfo, const wchar_t *LocaleName, unsigned int dwCmpFlags, const char *lpString1, int cchCount1, const char *lpString2, int cchCount2, int code_page)
{
  const wchar_t *v8; // rsi
  const char *v9; // rbx
  unsigned int v10; // edi
  signed __int64 result; // rax
  _LocaleUpdate v12; // [rsp+40h] [rbp-28h]

  v8 = LocaleName;
  v9 = lpString1;
  v10 = dwCmpFlags;
  _LocaleUpdate::_LocaleUpdate(&v12, plocinfo);
  result = _crtCompareStringA_stat(&v12.localeinfo, v8, v10, v9, cchCount1, lpString2, cchCount2, code_page);
  if ( v12.updated )
    v12.ptd->_ownlocale &= 0xFFFFFFFD;
  return result;
}

