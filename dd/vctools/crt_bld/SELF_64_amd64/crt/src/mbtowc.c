// File Line: 55
// RVA: 0x12C19F8
__int64 __fastcall mbtowc_l(wchar_t *pwc, const char *s, unsigned __int64 n, localeinfo_struct *plocinfo)
{
  unsigned int v8; // ebx
  threadlocaleinfostruct *locinfo; // rcx
  int mb_cur_max; // r9d
  int v11; // eax
  _LocaleUpdate v12; // [rsp+30h] [rbp-28h] BYREF

  if ( !s || !n )
    return 0i64;
  if ( !*s )
  {
    if ( pwc )
      *pwc = 0;
    return 0i64;
  }
  _LocaleUpdate::_LocaleUpdate(&v12, plocinfo);
  if ( !v12.localeinfo.locinfo->locale_name[2] )
  {
    if ( pwc )
      *pwc = *(unsigned __int8 *)s;
    v8 = 1;
    goto LABEL_20;
  }
  v8 = 1;
  if ( !(unsigned int)isleadbyte_l(*s, &v12.localeinfo) )
  {
    if ( MultiByteToWideChar(v12.localeinfo.locinfo->lc_codepage, 9u, s, 1, pwc, pwc != 0i64) )
      goto LABEL_20;
LABEL_19:
    v8 = -1;
    *errno() = 42;
    goto LABEL_20;
  }
  locinfo = v12.localeinfo.locinfo;
  mb_cur_max = v12.localeinfo.locinfo->mb_cur_max;
  if ( mb_cur_max <= 1
    || (int)n < mb_cur_max
    || (v11 = MultiByteToWideChar(v12.localeinfo.locinfo->lc_codepage, 9u, s, mb_cur_max, pwc, pwc != 0i64),
        locinfo = v12.localeinfo.locinfo,
        !v11) )
  {
    if ( n < locinfo->mb_cur_max || !s[1] )
      goto LABEL_19;
  }
  v8 = locinfo->mb_cur_max;
LABEL_20:
  if ( v12.updated )
    v12.ptd->_ownlocale &= ~2u;
  return v8;
}

// File Line: 123
// RVA: 0x12C1B4C
__int64 __fastcall mbtowc(wchar_t *pwc, const char *s, unsigned __int64 n)
{
  return mbtowc_l(pwc, s, n, 0i64);
}

