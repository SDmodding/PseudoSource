// File Line: 55
// RVA: 0x12C19F8
__int64 __fastcall mbtowc_l(wchar_t *pwc, const char *s, unsigned __int64 n, localeinfo_struct *plocinfo)
{
  unsigned __int64 v4; // rbp
  const char *v5; // rsi
  wchar_t *lpWideCharStr; // rdi
  unsigned int v8; // ebx
  threadlocaleinfostruct *v9; // rcx
  signed int v10; // er9
  int v11; // eax
  _LocaleUpdate v12; // [rsp+30h] [rbp-28h]

  v4 = n;
  v5 = s;
  lpWideCharStr = pwc;
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
    if ( lpWideCharStr )
      *lpWideCharStr = *(unsigned __int8 *)v5;
    v8 = 1;
    goto LABEL_21;
  }
  v8 = 1;
  if ( !(unsigned int)isleadbyte_l(*(unsigned __int8 *)v5, &v12.localeinfo) )
  {
    if ( MultiByteToWideChar(v12.localeinfo.locinfo->lc_codepage, 9u, v5, 1, lpWideCharStr, lpWideCharStr != 0i64) )
      goto LABEL_21;
LABEL_20:
    v8 = -1;
    *errno() = 42;
    goto LABEL_21;
  }
  v9 = v12.localeinfo.locinfo;
  v10 = v12.localeinfo.locinfo->mb_cur_max;
  if ( v10 <= 1
    || (signed int)v4 < v10
    || (v11 = MultiByteToWideChar(
                v12.localeinfo.locinfo->lc_codepage,
                9u,
                v5,
                v10,
                lpWideCharStr,
                lpWideCharStr != 0i64),
        v9 = v12.localeinfo.locinfo,
        !v11) )
  {
    if ( v4 < v9->mb_cur_max || !v5[1] )
      goto LABEL_20;
  }
  v8 = v9->mb_cur_max;
LABEL_21:
  if ( v12.updated )
    v12.ptd->_ownlocale &= 0xFFFFFFFD;
  return v8;
}

// File Line: 123
// RVA: 0x12C1B4C
__int64 __fastcall mbtowc(wchar_t *pwc, const char *s, unsigned __int64 n)
{
  return mbtowc_l(pwc, s, n, 0i64);
}

