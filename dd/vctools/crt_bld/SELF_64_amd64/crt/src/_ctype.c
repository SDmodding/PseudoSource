// File Line: 66
// RVA: 0x12B25E8
__int64 __fastcall isalpha(int c)
{
  __int64 v1; // rbx
  unsigned int v3; // ecx
  _LocaleUpdate v4; // [rsp+20h] [rbp-28h]

  v1 = c;
  if ( !_locale_changed )
    return _initiallocinfo.pctype[c] & 0x103;
  _LocaleUpdate::_LocaleUpdate(&v4, 0i64);
  if ( v4.localeinfo.locinfo->mb_cur_max <= 1 )
    v3 = v4.localeinfo.locinfo->pctype[v1] & 0x103;
  else
    v3 = isctype_l(v1, 259, &v4.localeinfo);
  if ( v4.updated )
    v4.ptd->_ownlocale &= 0xFFFFFFFD;
  return v3;
}

// File Line: 90
// RVA: 0x12B29D4
__int64 __fastcall isupper(int c)
{
  __int64 v1; // rbx
  unsigned int v3; // ecx
  _LocaleUpdate v4; // [rsp+20h] [rbp-28h]

  v1 = c;
  if ( !_locale_changed )
    return _initiallocinfo.pctype[c] & 1;
  _LocaleUpdate::_LocaleUpdate(&v4, 0i64);
  if ( v4.localeinfo.locinfo->mb_cur_max <= 1 )
    v3 = v4.localeinfo.locinfo->pctype[v1] & 1;
  else
    v3 = isctype_l(v1, 1, &v4.localeinfo);
  if ( v4.updated )
    v4.ptd->_ownlocale &= 0xFFFFFFFD;
  return v3;
}

// File Line: 114
// RVA: 0x12B27E0
__int64 __fastcall islower(int c)
{
  __int64 v1; // rbx
  unsigned int v3; // ecx
  _LocaleUpdate v4; // [rsp+20h] [rbp-28h]

  v1 = c;
  if ( !_locale_changed )
    return _initiallocinfo.pctype[c] & 2;
  _LocaleUpdate::_LocaleUpdate(&v4, 0i64);
  if ( v4.localeinfo.locinfo->mb_cur_max <= 1 )
    v3 = v4.localeinfo.locinfo->pctype[v1] & 2;
  else
    v3 = isctype_l(v1, 2, &v4.localeinfo);
  if ( v4.updated )
    v4.ptd->_ownlocale &= 0xFFFFFFFD;
  return v3;
}

// File Line: 138
// RVA: 0x12B26E4
__int64 __fastcall isdigit(int c)
{
  __int64 v1; // rbx
  unsigned int v3; // ecx
  _LocaleUpdate v4; // [rsp+20h] [rbp-28h]

  v1 = c;
  if ( !_locale_changed )
    return _initiallocinfo.pctype[c] & 4;
  _LocaleUpdate::_LocaleUpdate(&v4, 0i64);
  if ( v4.localeinfo.locinfo->mb_cur_max <= 1 )
    v3 = v4.localeinfo.locinfo->pctype[v1] & 4;
  else
    v3 = isctype_l(v1, 4, &v4.localeinfo);
  if ( v4.updated )
    v4.ptd->_ownlocale &= 0xFFFFFFFD;
  return v3;
}

// File Line: 162
// RVA: 0x12B2A50
__int64 __fastcall isxdigit(int c)
{
  __int64 v1; // rbx
  unsigned int v3; // ecx
  _LocaleUpdate v4; // [rsp+20h] [rbp-28h]

  v1 = c;
  if ( !_locale_changed )
    return _initiallocinfo.pctype[c] & 0x80;
  _LocaleUpdate::_LocaleUpdate(&v4, 0i64);
  if ( v4.localeinfo.locinfo->mb_cur_max <= 1 )
    v3 = v4.localeinfo.locinfo->pctype[v1] & 0x80;
  else
    v3 = isctype_l(v1, 128, &v4.localeinfo);
  if ( v4.updated )
    v4.ptd->_ownlocale &= 0xFFFFFFFD;
  return v3;
}

// File Line: 186
// RVA: 0x12B2958
__int64 __fastcall isspace(int c)
{
  __int64 v1; // rbx
  unsigned int v3; // ecx
  _LocaleUpdate v4; // [rsp+20h] [rbp-28h]

  v1 = c;
  if ( !_locale_changed )
    return _initiallocinfo.pctype[c] & 8;
  _LocaleUpdate::_LocaleUpdate(&v4, 0i64);
  if ( v4.localeinfo.locinfo->mb_cur_max <= 1 )
    v3 = v4.localeinfo.locinfo->pctype[v1] & 8;
  else
    v3 = isctype_l(v1, 8, &v4.localeinfo);
  if ( v4.updated )
    v4.ptd->_ownlocale &= 0xFFFFFFFD;
  return v3;
}

// File Line: 210
// RVA: 0x12B28DC
__int64 __fastcall ispunct(int c)
{
  __int64 v1; // rbx
  unsigned int v3; // ecx
  _LocaleUpdate v4; // [rsp+20h] [rbp-28h]

  v1 = c;
  if ( !_locale_changed )
    return _initiallocinfo.pctype[c] & 0x10;
  _LocaleUpdate::_LocaleUpdate(&v4, 0i64);
  if ( v4.localeinfo.locinfo->mb_cur_max <= 1 )
    v3 = v4.localeinfo.locinfo->pctype[v1] & 0x10;
  else
    v3 = isctype_l(v1, 16, &v4.localeinfo);
  if ( v4.updated )
    v4.ptd->_ownlocale &= 0xFFFFFFFD;
  return v3;
}

// File Line: 234
// RVA: 0x12B2568
__int64 __fastcall isalnum(int c)
{
  __int64 v1; // rbx
  unsigned int v3; // ecx
  _LocaleUpdate v4; // [rsp+20h] [rbp-28h]

  v1 = c;
  if ( !_locale_changed )
    return _initiallocinfo.pctype[c] & 0x107;
  _LocaleUpdate::_LocaleUpdate(&v4, 0i64);
  if ( v4.localeinfo.locinfo->mb_cur_max <= 1 )
    v3 = v4.localeinfo.locinfo->pctype[v1] & 0x107;
  else
    v3 = isctype_l(v1, 263, &v4.localeinfo);
  if ( v4.updated )
    v4.ptd->_ownlocale &= 0xFFFFFFFD;
  return v3;
}

// File Line: 258
// RVA: 0x12B285C
__int64 __fastcall isprint(int c)
{
  __int64 v1; // rbx
  unsigned int v3; // ecx
  _LocaleUpdate v4; // [rsp+20h] [rbp-28h]

  v1 = c;
  if ( !_locale_changed )
    return _initiallocinfo.pctype[c] & 0x157;
  _LocaleUpdate::_LocaleUpdate(&v4, 0i64);
  if ( v4.localeinfo.locinfo->mb_cur_max <= 1 )
    v3 = v4.localeinfo.locinfo->pctype[v1] & 0x157;
  else
    v3 = isctype_l(v1, 343, &v4.localeinfo);
  if ( v4.updated )
    v4.ptd->_ownlocale &= 0xFFFFFFFD;
  return v3;
}

// File Line: 282
// RVA: 0x12B2760
__int64 __fastcall isgraph(int c)
{
  __int64 v1; // rbx
  unsigned int v3; // ecx
  _LocaleUpdate v4; // [rsp+20h] [rbp-28h]

  v1 = c;
  if ( !_locale_changed )
    return _initiallocinfo.pctype[c] & 0x117;
  _LocaleUpdate::_LocaleUpdate(&v4, 0i64);
  if ( v4.localeinfo.locinfo->mb_cur_max <= 1 )
    v3 = v4.localeinfo.locinfo->pctype[v1] & 0x117;
  else
    v3 = isctype_l(v1, 279, &v4.localeinfo);
  if ( v4.updated )
    v4.ptd->_ownlocale &= 0xFFFFFFFD;
  return v3;
}

// File Line: 306
// RVA: 0x12B2668
__int64 __fastcall iscntrl(int c)
{
  __int64 v1; // rbx
  unsigned int v3; // ecx
  _LocaleUpdate v4; // [rsp+20h] [rbp-28h]

  v1 = c;
  if ( !_locale_changed )
    return _initiallocinfo.pctype[c] & 0x20;
  _LocaleUpdate::_LocaleUpdate(&v4, 0i64);
  if ( v4.localeinfo.locinfo->mb_cur_max <= 1 )
    v3 = v4.localeinfo.locinfo->pctype[v1] & 0x20;
  else
    v3 = isctype_l(v1, 32, &v4.localeinfo);
  if ( v4.updated )
    v4.ptd->_ownlocale &= 0xFFFFFFFD;
  return v3;
}

