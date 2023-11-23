// File Line: 53
// RVA: 0x12B8CB0
__int64 __fastcall wcsicoll_l(const wchar_t *_string1, const wchar_t *_string2, localeinfo_struct *plocinfo)
{
  const wchar_t *v5; // rcx
  signed __int64 v6; // rdi
  unsigned __int16 v7; // cx
  wchar_t v8; // dx
  unsigned int v9; // edx
  int v10; // eax
  _LocaleUpdate v12; // [rsp+30h] [rbp-28h] BYREF

  _LocaleUpdate::_LocaleUpdate(&v12, plocinfo);
  if ( !_string1 || !_string2 )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
LABEL_15:
    v9 = 0x7FFFFFFF;
    goto LABEL_17;
  }
  v5 = v12.localeinfo.locinfo->locale_name[1];
  if ( v5 )
  {
    v10 = _crtCompareStringW(v5, 0x1001u, _string1, -1, _string2, -1);
    if ( !v10 )
    {
      *errno() = 22;
      goto LABEL_15;
    }
    v9 = v10 - 2;
  }
  else
  {
    v6 = (char *)_string1 - (char *)_string2;
    do
    {
      v7 = *(const wchar_t *)((char *)_string2 + v6);
      if ( (unsigned __int16)(v7 - 65) <= 0x19u )
        v7 += 32;
      v8 = *_string2;
      if ( (unsigned __int16)(*_string2 - 65) <= 0x19u )
        v8 += 32;
      ++_string2;
    }
    while ( v7 && v7 == v8 );
    v9 = v7 - v8;
  }
LABEL_17:
  if ( v12.updated )
    v12.ptd->_ownlocale &= ~2u;
  return v9;
}

// File Line: 95
// RVA: 0x12B8C2C
int __fastcall wcsicoll(const wchar_t *_string1, const wchar_t *_string2)
{
  const wchar_t *v2; // r9
  signed __int64 v4; // r10
  unsigned __int16 v5; // dx
  wchar_t v6; // cx

  v2 = _string2;
  if ( _locale_changed )
    return wcsicoll_l(_string1, _string2, 0i64);
  if ( _string1 && _string2 )
  {
    v4 = (char *)_string1 - (char *)_string2;
    do
    {
      v5 = *(const wchar_t *)((char *)v2 + v4);
      if ( (unsigned __int16)(v5 - 65) <= 0x19u )
        v5 += 32;
      v6 = *v2;
      if ( (unsigned __int16)(*v2 - 65) <= 0x19u )
        v6 += 32;
      ++v2;
    }
    while ( v5 && v5 == v6 );
    return v5 - v6;
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0x7FFFFFFF;
  }
}

