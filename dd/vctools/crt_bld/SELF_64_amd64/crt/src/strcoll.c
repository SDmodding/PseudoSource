// File Line: 52
// RVA: 0x12C0C8C
int __fastcall strcoll_l(const char *_string1, const char *_string2, localeinfo_struct *plocinfo)
{
  const char *v3; // rdi
  const char *lpString2; // rbx
  const wchar_t *v5; // rdx
  int result; // eax
  int v7; // eax
  _LocaleUpdate v8; // [rsp+40h] [rbp-28h]

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
    result = strcmp(v3, lpString2);
    goto LABEL_10;
  }
  v7 = _crtCompareStringA(&v8.localeinfo, v5, 0x1000u, v3, -1, lpString2, -1, v8.localeinfo.locinfo->lc_collate_cp);
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

// File Line: 84
// RVA: 0x12C0D44
int __fastcall strcoll(const char *_string1, const char *_string2)
{
  return strcoll_l(_string1, _string2, 0i64);
}

