// File Line: 51
// RVA: 0x12B8B38
int __fastcall wcscoll_l(const wchar_t *_string1, const wchar_t *_string2, localeinfo_struct *plocinfo)
{
  const wchar_t *v3; // rdi
  const wchar_t *lpString2; // rbx
  const wchar_t *v5; // rcx
  int result; // eax
  int v7; // eax
  _LocaleUpdate v8; // [rsp+30h] [rbp-28h]

  v3 = _string1;
  lpString2 = _string2;
  _LocaleUpdate::_LocaleUpdate(&v8, plocinfo);
  if ( !v3 || !lpString2 )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
LABEL_8:
    result = 0x7FFFFFFF;
    goto LABEL_10;
  }
  v5 = v8.localeinfo.locinfo->locale_name[1];
  if ( !v5 )
  {
    result = wcscmp(v3, lpString2);
    goto LABEL_10;
  }
  v7 = _crtCompareStringW(v5, 0x1000u, v3, -1, lpString2, -1);
  if ( !v7 )
  {
    *errno() = 22;
    goto LABEL_8;
  }
  result = v7 - 2;
LABEL_10:
  if ( v8.updated )
    v8.ptd->_ownlocale &= 0xFFFFFFFD;
  return result;
}

// File Line: 82
// RVA: 0x12B8BE4
int __fastcall wcscoll(const wchar_t *_string1, const wchar_t *_string2)
{
  if ( _locale_changed )
    return wcscoll_l(_string1, _string2, 0i64);
  if ( _string1 && _string2 )
    return wcscmp(_string1, _string2);
  *errno() = 22;
  invalid_parameter_noinfo();
  return 0x7FFFFFFF;
}

