// File Line: 47
// RVA: 0x12B9494
__int64 __fastcall wcsicmp_l(const wchar_t *dst, const wchar_t *src, localeinfo_struct *plocinfo)
{
  __int64 result; // rax
  signed __int64 v6; // rsi
  unsigned __int16 v7; // bx
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // ax
  _LocaleUpdate plocinfoa; // [rsp+20h] [rbp-28h] BYREF

  _LocaleUpdate::_LocaleUpdate(&plocinfoa, plocinfo);
  if ( dst && src )
  {
    if ( plocinfoa.localeinfo.locinfo->locale_name[2] )
    {
      do
      {
        v7 = towlower_l(*dst++, &plocinfoa.localeinfo);
        v9 = towlower_l(*src++, &plocinfoa.localeinfo);
        v8 = v9;
      }
      while ( v7 && v7 == v9 );
    }
    else
    {
      v6 = (char *)dst - (char *)src;
      do
      {
        v7 = *(const wchar_t *)((char *)src + v6);
        if ( (unsigned __int16)(v7 - 65) <= 0x19u )
          v7 += 32;
        v8 = *src;
        if ( (unsigned __int16)(*src - 65) <= 0x19u )
          v8 += 32;
        ++src;
      }
      while ( v7 && v7 == v8 );
    }
    result = v7 - (unsigned int)v8;
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    result = 0x7FFFFFFFi64;
  }
  if ( plocinfoa.updated )
    plocinfoa.ptd->_ownlocale &= ~2u;
  return result;
}

// File Line: 82
// RVA: 0x12B9410
int __fastcall wcsicmp(const wchar_t *dst, const wchar_t *src)
{
  const wchar_t *v2; // r9
  signed __int64 v4; // r10
  unsigned __int16 v5; // dx
  wchar_t v6; // cx

  v2 = src;
  if ( _locale_changed )
    return wcsicmp_l(dst, src, 0i64);
  if ( dst && src )
  {
    v4 = (char *)dst - (char *)src;
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

