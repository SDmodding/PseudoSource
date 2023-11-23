// File Line: 170
// RVA: 0x12DB1F4
__int64 __fastcall _get_qualified_locale(
        tagLC_STRINGS *const lpInStr,
        unsigned int *lpOutCodePage,
        tagLC_STRINGS *lpOutStr)
{
  _tiddata *v6; // rax
  setloc_struct *p_setloc_data; // rbx
  const wchar_t *cacheLocaleName; // r15
  wchar_t **p_pchCountry; // rdi
  UINT v10; // eax
  int v11; // ebx
  __int64 v12; // rax
  __int64 v14; // rax
  unsigned __int16 LocaleName[88]; // [rsp+30h] [rbp-F8h] BYREF

  v6 = getptd();
  p_setloc_data = &v6->_setloc_data;
  cacheLocaleName = v6->_setloc_data._cacheLocaleName;
  p_pchCountry = &v6->_setloc_data.pchCountry;
  v6->_setloc_data.iLocState = 0;
  v6->_setloc_data._cacheLocaleName[0] = 0;
  v6->_setloc_data.pchCountry = lpInStr->szCountry;
  v6->_setloc_data.pchLanguage = (wchar_t *)lpInStr;
  if ( lpInStr->szCountry[0] )
    TranslateName(_rg_country, 22, &v6->_setloc_data.pchCountry);
  if ( !*p_setloc_data->pchLanguage )
  {
    p_setloc_data->iLocState |= 0x104u;
    if ( (int)_crtGetUserDefaultLocaleName(LocaleName, 85i64) > 1 )
    {
      v14 = wcslen(LocaleName);
      if ( (unsigned int)wcsncpy_s((char *)p_setloc_data->_cacheLocaleName, 0x55ui64, LocaleName, v14 + 1) )
      {
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        __debugbreak();
      }
    }
LABEL_11:
    if ( !p_setloc_data->iLocState )
      return 0i64;
    goto LABEL_12;
  }
  if ( **p_pchCountry )
    GetLocaleNameFromLangCountry(p_setloc_data);
  else
    GetLocaleNameFromLanguage(p_setloc_data);
  if ( !p_setloc_data->iLocState )
  {
    if ( (unsigned int)TranslateName(_rg_language, 64, &p_setloc_data->pchLanguage) )
    {
      if ( **p_pchCountry )
        GetLocaleNameFromLangCountry(p_setloc_data);
      else
        GetLocaleNameFromLanguage(p_setloc_data);
    }
    goto LABEL_11;
  }
LABEL_12:
  v10 = ProcessCodePage(lpInStr->szCodePage, p_setloc_data);
  v11 = v10;
  if ( v10 && v10 - 65000 > 1 && IsValidCodePage((unsigned __int16)v10) )
  {
    if ( lpOutCodePage )
      *lpOutCodePage = v11;
    if ( !lpOutStr )
      return 1i64;
    lpOutStr->szLocaleName[0] = 0;
    v12 = wcslen(cacheLocaleName);
    if ( (unsigned int)wcsncpy_s((char *)lpOutStr->szLocaleName, 0x55ui64, cacheLocaleName, v12 + 1) )
    {
      invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
      __debugbreak();
    }
    if ( _crtGetLocaleInfoEx(lpOutStr->szLocaleName, 0x1001u, lpOutStr->szLanguage, 64)
      && _crtGetLocaleInfoEx(lpOutStr->szLocaleName, 0x1002u, lpOutStr->szCountry, 64)
      && (!wcschr((const __m128i *)lpOutStr->szCountry, 0x5Fu) && !wcschr((const __m128i *)lpOutStr->szCountry, 0x2Eu)
       || _crtGetLocaleInfoEx(lpOutStr->szLocaleName, 7u, lpOutStr->szCountry, 64)) )
    {
      itow_s(v11, lpOutStr->szCodePage, 0x10ui64, 10);
      return 1i64;
    }
  }
  return 0i64;
}

// File Line: 301
// RVA: 0x12DB158
__int64 __fastcall TranslateName(tagLOCALETAB *lpTable, int high, wchar_t **ppchName)
{
  unsigned int v3; // ebx
  int v5; // edi
  int v7; // eax
  int v8; // esi
  bool v9; // zf
  __int64 v10; // rbp

  v3 = 0;
  v5 = high;
  v7 = 1;
  v8 = 0;
  if ( high < 0 )
  {
LABEL_9:
    v9 = v7 == 0;
  }
  else
  {
    while ( 1 )
    {
      v9 = v7 == 0;
      if ( !v7 )
        break;
      v10 = (v8 + v5) / 2;
      v7 = wcsicmp(*ppchName, lpTable[v10].szName);
      if ( v7 )
      {
        if ( v7 >= 0 )
          v8 = v10 + 1;
        else
          v5 = v10 - 1;
      }
      else
      {
        *ppchName = lpTable[v10].chAbbrev;
      }
      if ( v8 > v5 )
        goto LABEL_9;
    }
  }
  LOBYTE(v3) = v9;
  return v3;
}

// File Line: 346
// RVA: 0x12DAA98
void __fastcall GetLocaleNameFromLangCountry(setloc_struct *_psetloc_data)
{
  __int64 v2; // rax
  wchar_t *pchCountry; // rcx
  __int64 v4; // rax
  bool v5; // zf
  int v6; // edx
  wchar_t *pchLanguage; // rcx
  int v8; // r9d
  __int16 v9; // r8

  v2 = wcslen(_psetloc_data->pchLanguage);
  pchCountry = _psetloc_data->pchCountry;
  _psetloc_data->bAbbrevLanguage = v2 == 3;
  v4 = wcslen(pchCountry);
  v5 = _psetloc_data->bAbbrevLanguage == 0;
  _psetloc_data->bAbbrevCountry = v4 == 3;
  if ( v5 )
  {
    pchLanguage = _psetloc_data->pchLanguage;
    v8 = 0;
    if ( _psetloc_data->pchLanguage )
    {
      while ( 1 )
      {
        v9 = *pchLanguage++;
        if ( (unsigned __int16)(v9 - 65) > 0x19u && (unsigned __int16)(v9 - 97) > 0x19u )
          break;
        ++v8;
      }
      v6 = v8;
    }
    else
    {
      v6 = 0;
    }
  }
  else
  {
    v6 = 2;
  }
  _psetloc_data->iPrimaryLen = v6;
  _crtEnumSystemLocalesEx(LangCountryEnumProcEx, 3i64, 0i64);
  if ( (_psetloc_data->iLocState & 0x100) == 0
    || (_psetloc_data->iLocState & 0x200) == 0
    || (_psetloc_data->iLocState & 7) == 0 )
  {
    _psetloc_data->iLocState = 0;
  }
}

// File Line: 396
// RVA: 0x12DABD0
__int64 __fastcall LangCountryEnumProcEx(unsigned __int16 *lpLocaleString, unsigned int dwFlags, __int64 lParam)
{
  _tiddata *v4; // rax
  setloc_struct *p_setloc_data; // rbx
  __int64 v7; // rax
  __int64 v8; // rax
  __int64 v9; // rax
  __int64 v10; // rax
  const wchar_t *pchLanguage; // rcx
  int v12; // esi
  __int16 v13; // dx
  __int64 v14; // rax
  __int64 v15; // rax
  unsigned __int16 LCData[64]; // [rsp+30h] [rbp-A8h] BYREF

  v4 = getptd();
  p_setloc_data = &v4->_setloc_data;
  if ( !_crtGetLocaleInfoEx(lpLocaleString, v4->_setloc_data.bAbbrevCountry != 0 ? 7 : 4098, LCData, 64) )
    goto LABEL_2;
  if ( !wcsicmp(p_setloc_data->pchCountry, LCData) )
  {
    if ( !GetLocaleInfoEx(lpLocaleString, p_setloc_data->bAbbrevLanguage != 0 ? 3 : 4097, LCData, 64) )
      goto LABEL_2;
    if ( wcsicmp(p_setloc_data->pchLanguage, LCData) )
    {
      if ( (p_setloc_data->iLocState & 2) == 0 )
      {
        if ( !p_setloc_data->iPrimaryLen || wcsnicmp(p_setloc_data->pchLanguage, LCData, p_setloc_data->iPrimaryLen) )
        {
          if ( (p_setloc_data->iLocState & 1) == 0 )
          {
            if ( TestDefaultCountry(lpLocaleString) )
            {
              p_setloc_data->iLocState |= 1u;
              v9 = wcslen(lpLocaleString);
              if ( (unsigned int)wcsncpy_s((char *)p_setloc_data->_cacheLocaleName, 0x55ui64, lpLocaleString, v9 + 1) )
              {
                invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
                __debugbreak();
              }
            }
          }
        }
        else
        {
          p_setloc_data->iLocState |= 2u;
          v8 = wcslen(lpLocaleString);
          if ( (unsigned int)wcsncpy_s((char *)p_setloc_data->_cacheLocaleName, 0x55ui64, lpLocaleString, v8 + 1) )
          {
            invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
            __debugbreak();
          }
        }
      }
    }
    else
    {
      p_setloc_data->iLocState |= 0x304u;
      v7 = wcslen(lpLocaleString);
      if ( (unsigned int)wcsncpy_s((char *)p_setloc_data->_cacheLocaleName, 0x55ui64, lpLocaleString, v7 + 1) )
      {
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        __debugbreak();
      }
    }
  }
  if ( (p_setloc_data->iLocState & 0x300) != 768 )
  {
    if ( _crtGetLocaleInfoEx(lpLocaleString, p_setloc_data->bAbbrevLanguage != 0 ? 3 : 4097, LCData, 128) )
    {
      if ( !wcsicmp(p_setloc_data->pchLanguage, LCData) )
      {
        p_setloc_data->iLocState |= 0x200u;
        if ( p_setloc_data->bAbbrevLanguage )
        {
          p_setloc_data->iLocState |= 0x100u;
          if ( !p_setloc_data->_cacheLocaleName[0] )
          {
            v10 = wcslen(lpLocaleString);
            if ( (unsigned int)wcsncpy_s((char *)p_setloc_data->_cacheLocaleName, 0x55ui64, lpLocaleString, v10 + 1) )
            {
              invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
              __debugbreak();
            }
          }
        }
        else if ( p_setloc_data->iPrimaryLen
               && (unsigned int)wcslen(p_setloc_data->pchLanguage) == p_setloc_data->iPrimaryLen )
        {
          if ( TestDefaultCountry(lpLocaleString) )
            goto LABEL_31;
          pchLanguage = p_setloc_data->pchLanguage;
          v12 = 0;
          if ( p_setloc_data->pchLanguage )
          {
            while ( 1 )
            {
              v13 = *pchLanguage++;
              if ( (unsigned __int16)(v13 - 65) > 0x19u && (unsigned __int16)(v13 - 97) > 0x19u )
                break;
              ++v12;
            }
          }
          if ( v12 != (unsigned int)wcslen(p_setloc_data->pchLanguage) )
          {
LABEL_31:
            p_setloc_data->iLocState |= 0x100u;
            if ( !p_setloc_data->_cacheLocaleName[0] )
            {
              v14 = wcslen(lpLocaleString);
              if ( (unsigned int)wcsncpy_s((char *)p_setloc_data->_cacheLocaleName, 0x55ui64, lpLocaleString, v14 + 1) )
              {
                invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
                __debugbreak();
              }
            }
          }
        }
        else
        {
          p_setloc_data->iLocState |= 0x100u;
          if ( !p_setloc_data->_cacheLocaleName[0] )
          {
            v15 = wcslen(lpLocaleString);
            if ( (unsigned int)wcsncpy_s((char *)p_setloc_data->_cacheLocaleName, 0x55ui64, lpLocaleString, v15 + 1) )
            {
              invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
              __debugbreak();
            }
          }
        }
      }
      return (p_setloc_data->iLocState & 4) == 0;
    }
LABEL_2:
    p_setloc_data->iLocState = 0;
    return 1i64;
  }
  return (p_setloc_data->iLocState & 4) == 0;
}

// File Line: 538
// RVA: 0x12DAB48
void __fastcall GetLocaleNameFromLanguage(setloc_struct *_psetloc_data)
{
  __int64 v2; // rax
  int v3; // edx
  wchar_t *pchLanguage; // rcx
  int v5; // r9d
  __int16 v6; // r8

  v2 = wcslen(_psetloc_data->pchLanguage);
  _psetloc_data->bAbbrevLanguage = v2 == 3;
  if ( v2 == 3 )
  {
    v3 = 2;
  }
  else
  {
    pchLanguage = _psetloc_data->pchLanguage;
    v5 = 0;
    if ( _psetloc_data->pchLanguage )
    {
      while ( 1 )
      {
        v6 = *pchLanguage++;
        if ( (unsigned __int16)(v6 - 65) > 0x19u && (unsigned __int16)(v6 - 97) > 0x19u )
          break;
        ++v5;
      }
      v3 = v5;
    }
    else
    {
      v3 = 0;
    }
  }
  _psetloc_data->iPrimaryLen = v3;
  _crtEnumSystemLocalesEx(LanguageEnumProcEx, 3i64, 0i64);
  if ( (_psetloc_data->iLocState & 4) == 0 )
    _psetloc_data->iLocState = 0;
}

// File Line: 573
// RVA: 0x12DAF5C
_BOOL8 __fastcall LanguageEnumProcEx(unsigned __int16 *lpLocaleString, unsigned int dwFlags, __int64 lParam)
{
  _tiddata *v4; // rax
  setloc_struct *p_setloc_data; // rbx
  __int64 v7; // rax
  unsigned __int16 LCData[120]; // [rsp+30h] [rbp-108h] BYREF

  v4 = getptd();
  p_setloc_data = &v4->_setloc_data;
  if ( _crtGetLocaleInfoEx(lpLocaleString, v4->_setloc_data.bAbbrevLanguage != 0 ? 3 : 4097, LCData, 120) )
  {
    if ( !wcsicmp(p_setloc_data->pchLanguage, LCData) )
    {
      v7 = wcslen(lpLocaleString);
      if ( (unsigned int)wcsncpy_s((char *)p_setloc_data->_cacheLocaleName, 0x55ui64, lpLocaleString, v7 + 1) )
      {
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        JUMPOUT(0x1412DB038i64);
      }
      p_setloc_data->iLocState |= 4u;
    }
    return (p_setloc_data->iLocState & 4) == 0;
  }
  else
  {
    p_setloc_data->iLocState = 0;
    return 1i64;
  }
}

// File Line: 642
// RVA: 0x12DB03C
UINT __fastcall ProcessCodePage(unsigned __int16 *lpCodePageStr, setloc_struct *_psetloc_data)
{
  UINT result; // eax
  UINT LCData; // [rsp+30h] [rbp+8h] BYREF

  if ( lpCodePageStr && *lpCodePageStr && (unsigned int)wcscmp(lpCodePageStr, L"ACP") )
  {
    if ( (unsigned int)wcscmp(lpCodePageStr, L"OCP") )
      return wtol(lpCodePageStr);
    if ( _crtGetLocaleInfoEx(_psetloc_data->_cacheLocaleName, 0x2000000Bu, (unsigned __int16 *)&LCData, 2) )
      return LCData;
    return 0;
  }
  if ( !_crtGetLocaleInfoEx(_psetloc_data->_cacheLocaleName, 0x20001004u, (unsigned __int16 *)&LCData, 2) )
    return 0;
  result = LCData;
  if ( !LCData )
    return GetACP();
  return result;
}

// File Line: 688
// RVA: 0x12DB0F0
int __fastcall TestDefaultCountry(const wchar_t *localeName)
{
  int result; // eax
  int v3; // ebx
  unsigned __int16 LCData[12]; // [rsp+20h] [rbp-28h] BYREF

  result = _crtGetLocaleInfoEx(localeName, 0x59u, LCData, 9);
  v3 = 0;
  if ( result )
  {
    LOBYTE(v3) = (unsigned int)wcsncmp(LCData, localeName, 9ui64) == 0;
    return v3;
  }
  return result;
}

