// File Line: 51
// RVA: 0x12B9240
__int64 __fastcall strnicmp_l(const char *dst, const char *src, unsigned __int64 count, localeinfo_struct *plocinfo)
{
  unsigned __int64 v4; // rbp
  unsigned int v7; // ebx
  __int64 v8; // rsi
  int v9; // ebx
  int v10; // eax
  _LocaleUpdate plocinfoa; // [rsp+20h] [rbp-28h] BYREF

  v4 = count;
  if ( !count )
    return 0i64;
  _LocaleUpdate::_LocaleUpdate(&plocinfoa, plocinfo);
  v7 = 0x7FFFFFFF;
  if ( dst && src && v4 <= 0x7FFFFFFF )
  {
    if ( plocinfoa.localeinfo.locinfo->locale_name[2] )
    {
      v8 = dst - src;
      do
      {
        v9 = tolower_l((unsigned __int8)src[v8], &plocinfoa.localeinfo);
        v10 = tolower_l(*(unsigned __int8 *)src++, &plocinfoa.localeinfo);
        --v4;
      }
      while ( v4 && v9 && v9 == v10 );
      v7 = v9 - v10;
    }
    else
    {
      v7 = _ascii_strnicmp(dst, src, v4);
    }
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
  }
  if ( plocinfoa.updated )
    plocinfoa.ptd->_ownlocale &= ~2u;
  return v7;
}

// File Line: 90
// RVA: 0x12B91A8
__int64 __fastcall _ascii_strnicmp(const char *first, const char *last, unsigned __int64 count)
{
  int v4; // r9d
  int v5; // ecx

  if ( !count )
    return 0i64;
  do
  {
    v4 = *(unsigned __int8 *)first++;
    if ( (unsigned int)(v4 - 65) <= 0x19 )
      v4 += 32;
    v5 = *(unsigned __int8 *)last++;
    if ( (unsigned int)(v5 - 65) <= 0x19 )
      v5 += 32;
    --count;
  }
  while ( count && v4 && v4 == v5 );
  return (unsigned int)(v4 - v5);
}

// File Line: 125
// RVA: 0x12B91F0
int __fastcall strnicmp(const char *dst, const char *src, unsigned __int64 count)
{
  if ( _locale_changed )
    return strnicmp_l(dst, src, count, 0i64);
  if ( dst && src && count <= 0x7FFFFFFF )
    return _ascii_strnicmp(dst, src, count);
  *errno() = 22;
  invalid_parameter_noinfo();
  return 0x7FFFFFFF;
}

