// File Line: 170
// RVA: 0x12DB1F4
signed __int64 __fastcall _get_qualified_locale(tagLC_STRINGS *const lpInStr, unsigned int *lpOutCodePage, tagLC_STRINGS *lpOutStr)
{
  tagLC_STRINGS *v3; // rbp
  unsigned int *v4; // rsi
  tagLC_STRINGS *v5; // r14
  _tiddata *v6; // rax
  setloc_struct *v7; // rbx
  const wchar_t *v8; // r15
  wchar_t **v9; // rdi
  UINT v10; // eax
  int v11; // ebx
  signed __int64 v12; // rax
  signed __int64 v14; // rax
  unsigned __int16 LocaleName; // [rsp+30h] [rbp-F8h]

  v3 = lpOutStr;
  v4 = lpOutCodePage;
  v5 = lpInStr;
  v6 = getptd();
  v7 = &v6->_setloc_data;
  v8 = v6->_setloc_data._cacheLocaleName;
  v9 = &v6->_setloc_data.pchCountry;
  v7->iLocState = 0;
  v7->_cacheLocaleName[0] = 0;
  v7->pchCountry = v5->szCountry;
  v7->pchLanguage = (wchar_t *)v5;
  if ( v5->szCountry[0] )
    TranslateName(_rg_country, 22, (const wchar_t **)&v6->_setloc_data.pchCountry);
  if ( *v7->pchLanguage )
  {
    if ( **v9 )
      GetLocaleNameFromLangCountry(v7);
    else
      GetLocaleNameFromLanguage(v7);
    if ( v7->iLocState )
      goto LABEL_12;
    if ( (unsigned int)TranslateName(_rg_language, 64, (const wchar_t **)&v7->pchLanguage) )
    {
      if ( **v9 )
        GetLocaleNameFromLangCountry(v7);
      else
        GetLocaleNameFromLanguage(v7);
    }
  }
  else
  {
    v7->iLocState |= 0x104u;
    if ( (signed int)_crtGetUserDefaultLocaleName(&LocaleName, 85i64) > 1 )
    {
      v14 = wcslen(&LocaleName);
      if ( (unsigned int)wcsncpy_s(v7->_cacheLocaleName, 0x55ui64, &LocaleName, v14 + 1) )
      {
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        __debugbreak();
        goto LABEL_32;
      }
    }
  }
  if ( !v7->iLocState )
    return 0i64;
LABEL_12:
  v10 = ProcessCodePage(v5->szCodePage, v7);
  v11 = v10;
  if ( !v10 || v10 - 65000 <= 1 || !IsValidCodePage((unsigned __int16)v10) )
    return 0i64;
  if ( v4 )
    *v4 = v11;
  if ( !v3 )
    return 1i64;
  v3->szLocaleName[0] = 0;
  v12 = wcslen(v8);
  if ( (unsigned int)wcsncpy_s(v3->szLocaleName, 0x55ui64, v8, v12 + 1) )
  {
LABEL_32:
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    __debugbreak();
    JUMPOUT(*(_QWORD *)_I10_OUTPUT);
  }
  if ( _crtGetLocaleInfoEx(v3->szLocaleName, 0x1001u, v3->szLanguage, 64)
    && _crtGetLocaleInfoEx(v3->szLocaleName, 0x1002u, v3->szCountry, 64)
    && (!wcschr(v3->szCountry, 0x5Fu) && !wcschr(v3->szCountry, 0x2Eu)
     || _crtGetLocaleInfoEx(v3->szLocaleName, 7u, v3->szCountry, 64)) )
  {
    itow_s(v11, v3->szCodePage, 0x10ui64, 10);
    return 1i64;
  }
  return 0i64;
}

// File Line: 301
// RVA: 0x12DB158
__int64 __fastcall TranslateName(tagLOCALETAB *lpTable, int high, const wchar_t **ppchName)
{
  unsigned int v3; // ebx
  const wchar_t **v4; // r15
  int v5; // edi
  tagLOCALETAB *v6; // r12
  int v7; // eax
  int v8; // esi
  bool v9; // zf
  int v10; // eax
  int v11; // ebp
  signed __int64 v12; // r14

  v3 = 0;
  v4 = ppchName;
  v5 = high;
  v6 = lpTable;
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
      v11 = v10;
      v12 = v10;
      v7 = wcsicmp(*v4, v6[v12].szName);
      if ( v7 )
      {
        if ( v7 >= 0 )
          v8 = v11 + 1;
        else
          v5 = v11 - 1;
      }
      else
      {
        *v4 = v6[v12].chAbbrev;
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
  setloc_struct *v1; // rbx
  signed __int64 v2; // rax
  const wchar_t *v3; // rcx
  signed __int64 v4; // rax
  bool v5; // zf
  signed int v6; // edx
  wchar_t *v7; // rcx
  signed int v8; // er9
  wchar_t v9; // r8

  v1 = _psetloc_data;
  v2 = wcslen(_psetloc_data->pchLanguage);
  v3 = v1->pchCountry;
  v1->bAbbrevLanguage = v2 == 3;
  v4 = wcslen(v3);
  v5 = v1->bAbbrevLanguage == 0;
  v1->bAbbrevCountry = v4 == 3;
  if ( v5 )
  {
    v7 = v1->pchLanguage;
    v8 = 0;
    if ( v1->pchLanguage )
    {
      while ( 1 )
      {
        v9 = *v7;
        ++v7;
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
  v1->iPrimaryLen = v6;
  _crtEnumSystemLocalesEx(LangCountryEnumProcEx, 3i64, 0i64);
  if ( !(v1->iLocState & 0x100) || !(v1->iLocState & 0x200) || !(v1->iLocState & 7) )
    v1->iLocState = 0;
}

// File Line: 396
// RVA: 0x12DABD0
signed __int64 __fastcall LangCountryEnumProcEx(unsigned __int16 *lpLocaleString, unsigned int dwFlags, __int64 lParam)
{
  unsigned __int16 *v3; // rdi
  _tiddata *v4; // rax
  signed __int64 v5; // rbx
  signed __int64 v7; // rax
  signed __int64 v8; // rax
  signed __int64 v9; // rax
  signed __int64 v10; // rax
  const wchar_t *v11; // rcx
  int v12; // esi
  wchar_t v13; // dx
  signed __int64 v14; // rax
  signed __int64 v15; // rax
  unsigned __int16 LCData; // [rsp+30h] [rbp-A8h]

  v3 = lpLocaleString;
  v4 = getptd();
  v5 = (signed __int64)&v4->_setloc_data;
  if ( !_crtGetLocaleInfoEx(v3, v4->_setloc_data.bAbbrevCountry != 0 ? 7 : 4098, &LCData, 64) )
    goto LABEL_2;
  if ( !wcsicmp(*(const wchar_t **)(v5 + 8), &LCData) )
  {
    if ( !GetLocaleInfoEx(v3, *(_DWORD *)(v5 + 24) != 0 ? 3 : 4097, &LCData, 64) )
      goto LABEL_2;
    if ( wcsicmp(*(const wchar_t **)v5, &LCData) )
    {
      if ( !(*(_BYTE *)(v5 + 16) & 2) )
      {
        if ( !*(_DWORD *)(v5 + 20) || wcsnicmp(*(const wchar_t **)v5, &LCData, *(signed int *)(v5 + 20)) )
        {
          if ( !(*(_BYTE *)(v5 + 16) & 1) )
          {
            if ( TestDefaultCountry(v3) )
            {
              *(_DWORD *)(v5 + 16) |= 1u;
              v9 = wcslen(v3);
              if ( (unsigned int)wcsncpy_s((unsigned __int16 *)(v5 + 600), 0x55ui64, v3, v9 + 1) )
                goto LABEL_39;
            }
          }
        }
        else
        {
          *(_DWORD *)(v5 + 16) |= 2u;
          v8 = wcslen(v3);
          if ( (unsigned int)wcsncpy_s((unsigned __int16 *)(v5 + 600), 0x55ui64, v3, v8 + 1) )
            goto LABEL_38;
        }
      }
    }
    else
    {
      *(_DWORD *)(v5 + 16) |= 0x304u;
      v7 = wcslen(v3);
      if ( (unsigned int)wcsncpy_s((unsigned __int16 *)(v5 + 600), 0x55ui64, v3, v7 + 1) )
      {
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        __debugbreak();
LABEL_38:
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        __debugbreak();
LABEL_39:
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        __debugbreak();
LABEL_40:
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        __debugbreak();
LABEL_41:
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        __debugbreak();
        goto LABEL_42;
      }
    }
  }
  if ( (*(_DWORD *)(v5 + 16) & 0x300) == 768 )
    return ~(unsigned __int8)(*(_DWORD *)(v5 + 16) >> 2) & 1;
  if ( !_crtGetLocaleInfoEx(v3, *(_DWORD *)(v5 + 24) != 0 ? 3 : 4097, &LCData, 128) )
  {
LABEL_2:
    *(_DWORD *)(v5 + 16) = 0;
    return 1i64;
  }
  if ( !wcsicmp(*(const wchar_t **)v5, &LCData) )
  {
    *(_DWORD *)(v5 + 16) |= 0x200u;
    if ( *(_DWORD *)(v5 + 24) )
    {
      *(_DWORD *)(v5 + 16) |= 0x100u;
      if ( !*(_WORD *)(v5 + 600) )
      {
        v10 = wcslen(v3);
        if ( (unsigned int)wcsncpy_s((unsigned __int16 *)(v5 + 600), 0x55ui64, v3, v10 + 1) )
          goto LABEL_40;
      }
    }
    else if ( *(_DWORD *)(v5 + 20) && (unsigned int)wcslen(*(const wchar_t **)v5) == *(_DWORD *)(v5 + 20) )
    {
      if ( TestDefaultCountry(v3) )
        goto LABEL_46;
      v11 = *(const wchar_t **)v5;
      v12 = 0;
      if ( *(_QWORD *)v5 )
      {
        while ( 1 )
        {
          v13 = *v11;
          ++v11;
          if ( (unsigned __int16)(v13 - 65) > 0x19u && (unsigned __int16)(v13 - 97) > 0x19u )
            break;
          ++v12;
        }
      }
      if ( v12 != (unsigned int)wcslen(*(const wchar_t **)v5) )
      {
LABEL_46:
        *(_DWORD *)(v5 + 16) |= 0x100u;
        if ( !*(_WORD *)(v5 + 600) )
        {
          v14 = wcslen(v3);
          if ( (unsigned int)wcsncpy_s((unsigned __int16 *)(v5 + 600), 0x55ui64, v3, v14 + 1) )
            goto LABEL_41;
        }
      }
    }
    else
    {
      *(_DWORD *)(v5 + 16) |= 0x100u;
      if ( !*(_WORD *)(v5 + 600) )
      {
        v15 = wcslen(v3);
        if ( (unsigned int)wcsncpy_s((unsigned __int16 *)(v5 + 600), 0x55ui64, v3, v15 + 1) )
        {
LABEL_42:
          invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
          __debugbreak();
          JUMPOUT(*(_QWORD *)LanguageEnumProcEx);
        }
      }
    }
  }
  return ~(unsigned __int8)(*(_DWORD *)(v5 + 16) >> 2) & 1;
}

// File Line: 538
// RVA: 0x12DAB48
void __fastcall GetLocaleNameFromLanguage(setloc_struct *_psetloc_data)
{
  setloc_struct *v1; // rbx
  signed __int64 v2; // rax
  signed int v3; // edx
  wchar_t *v4; // rcx
  signed int v5; // er9
  wchar_t v6; // r8

  v1 = _psetloc_data;
  v2 = wcslen(_psetloc_data->pchLanguage);
  v1->bAbbrevLanguage = v2 == 3;
  if ( v2 == 3 )
  {
    v3 = 2;
  }
  else
  {
    v4 = v1->pchLanguage;
    v5 = 0;
    if ( v1->pchLanguage )
    {
      while ( 1 )
      {
        v6 = *v4;
        ++v4;
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
  v1->iPrimaryLen = v3;
  _crtEnumSystemLocalesEx(LanguageEnumProcEx, 3i64, 0i64);
  if ( !(v1->iLocState & 4) )
    v1->iLocState = 0;
}

// File Line: 573
// RVA: 0x12DAF5C
signed __int64 __fastcall LanguageEnumProcEx(unsigned __int16 *lpLocaleString, unsigned int dwFlags, __int64 lParam)
{
  unsigned __int16 *v3; // rdi
  _tiddata *v4; // rax
  signed __int64 v5; // rbx
  signed __int64 result; // rax
  signed __int64 v7; // rax
  unsigned __int16 LCData; // [rsp+30h] [rbp-108h]

  v3 = lpLocaleString;
  v4 = getptd();
  v5 = (signed __int64)&v4->_setloc_data;
  if ( _crtGetLocaleInfoEx(v3, v4->_setloc_data.bAbbrevLanguage != 0 ? 3 : 4097, &LCData, 120) )
  {
    if ( !wcsicmp(*(const wchar_t **)v5, &LCData) )
    {
      v7 = wcslen(v3);
      if ( (unsigned int)wcsncpy_s((unsigned __int16 *)(v5 + 600), 0x55ui64, v3, v7 + 1) )
      {
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        JUMPOUT(*(_QWORD *)&byte_1412DB038);
      }
      *(_DWORD *)(v5 + 16) |= 4u;
    }
    result = ~(unsigned __int8)(*(_DWORD *)(v5 + 16) >> 2) & 1;
  }
  else
  {
    *(_DWORD *)(v5 + 16) = 0;
    result = 1i64;
  }
  return result;
}

// File Line: 642
// RVA: 0x12DB03C
UINT __fastcall ProcessCodePage(unsigned __int16 *lpCodePageStr, setloc_struct *_psetloc_data)
{
  setloc_struct *v2; // rdi
  unsigned __int16 *v3; // rbx
  UINT result; // eax
  unsigned __int16 LCData; // [rsp+30h] [rbp+8h]

  v2 = _psetloc_data;
  v3 = lpCodePageStr;
  if ( lpCodePageStr && *lpCodePageStr && (unsigned int)wcscmp(lpCodePageStr, L"ACP") )
  {
    if ( (unsigned int)wcscmp(v3, L"OCP") )
      return wtol(v3);
    if ( _crtGetLocaleInfoEx(v2->_cacheLocaleName, 0x2000000Bu, &LCData, 2) )
      return *(_DWORD *)&LCData;
    return 0;
  }
  if ( !_crtGetLocaleInfoEx(v2->_cacheLocaleName, 0x20001004u, &LCData, 2) )
    return 0;
  result = *(_DWORD *)&LCData;
  if ( !*(_DWORD *)&LCData )
    result = GetACP();
  return result;
}

// File Line: 688
// RVA: 0x12DB0F0
int __fastcall TestDefaultCountry(const wchar_t *localeName)
{
  const wchar_t *v1; // rdi
  int result; // eax
  int v3; // ebx
  unsigned __int16 LCData; // [rsp+20h] [rbp-28h]

  v1 = localeName;
  result = _crtGetLocaleInfoEx(localeName, 0x59u, &LCData, 9);
  v3 = 0;
  if ( result )
  {
    LOBYTE(v3) = (unsigned int)wcsncmp(&LCData, v1, 9ui64) == 0;
    result = v3;
  }
  return result;
}

