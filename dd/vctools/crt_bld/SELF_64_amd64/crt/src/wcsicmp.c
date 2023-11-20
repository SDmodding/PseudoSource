// File Line: 47
// RVA: 0x12B9494
signed __int64 __fastcall wcsicmp_l(const wchar_t *dst, const wchar_t *src, localeinfo_struct *plocinfo)
{
  unsigned __int16 *v3; // rsi
  unsigned __int16 *v4; // rdi
  signed __int64 result; // rax
  signed __int64 v6; // rsi
  unsigned __int16 v7; // bx
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // ax
  localeinfo_struct plocinfoa; // [rsp+20h] [rbp-28h]
  __int64 v11; // [rsp+30h] [rbp-18h]
  char v12; // [rsp+38h] [rbp-10h]

  v3 = (unsigned __int16 *)dst;
  v4 = (unsigned __int16 *)src;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&plocinfoa, plocinfo);
  if ( v3 && v4 )
  {
    if ( plocinfoa.locinfo->locale_name[2] )
    {
      do
      {
        v7 = towlower_l(*v3, &plocinfoa);
        ++v3;
        v9 = towlower_l(*v4, &plocinfoa);
        ++v4;
        v8 = v9;
      }
      while ( v7 && v7 == v9 );
    }
    else
    {
      v6 = (char *)v3 - (char *)v4;
      do
      {
        v7 = *(unsigned __int16 *)((char *)v4 + v6);
        if ( (unsigned __int16)(v7 - 65) <= 0x19u )
          v7 += 32;
        v8 = *v4;
        if ( (unsigned __int16)(*v4 - 65) <= 0x19u )
          v8 += 32;
        ++v4;
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
  if ( v12 )
    *(_DWORD *)(v11 + 200) &= 0xFFFFFFFD;
  return result;
}

// File Line: 82
// RVA: 0x12B9410
int __fastcall wcsicmp(const wchar_t *dst, const wchar_t *src)
{
  const wchar_t *v2; // r9
  int result; // eax
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
    result = v5 - v6;
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    result = 0x7FFFFFFF;
  }
  return result;
}

