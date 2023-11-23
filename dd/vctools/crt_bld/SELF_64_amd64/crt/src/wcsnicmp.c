// File Line: 54
// RVA: 0x12DC2D0
__int64 __fastcall wcsnicmp_l(wchar_t *first, wchar_t *last, unsigned __int64 count, localeinfo_struct *plocinfo)
{
  unsigned __int64 v4; // rbp
  wchar_t *v5; // rdi
  wchar_t *v6; // rsi
  __int64 result; // rax
  signed __int64 v8; // rsi
  unsigned __int16 v9; // bx
  wchar_t v10; // cx
  wchar_t v11; // ax
  _LocaleUpdate v12; // [rsp+20h] [rbp-28h] BYREF

  v4 = count;
  v5 = last;
  v6 = first;
  result = 0i64;
  if ( count )
  {
    if ( first && last )
    {
      _LocaleUpdate::_LocaleUpdate(&v12, plocinfo);
      if ( v12.localeinfo.locinfo->locale_name[2] )
      {
        do
        {
          v9 = towlower_l(*v6, &v12.localeinfo);
          v11 = towlower_l(*v5, &v12.localeinfo);
          ++v6;
          ++v5;
          v10 = v11;
          --v4;
        }
        while ( v4 && v9 && v9 == v11 );
      }
      else
      {
        v8 = (char *)v6 - (char *)v5;
        do
        {
          v9 = *(wchar_t *)((char *)v5 + v8);
          if ( (unsigned __int16)(v9 - 65) <= 0x19u )
            v9 += 32;
          v10 = *v5;
          if ( (unsigned __int16)(*v5 - 65) <= 0x19u )
            v10 += 32;
          ++v5;
          --v4;
        }
        while ( v4 && v9 && v9 == v10 );
      }
      result = v9 - (unsigned int)v10;
      if ( v12.updated )
        v12.ptd->_ownlocale &= ~2u;
    }
    else
    {
      *errno() = 22;
      invalid_parameter_noinfo();
      return 0x7FFFFFFFi64;
    }
  }
  return result;
}

// File Line: 99
// RVA: 0x12DC238
int __fastcall wcsnicmp(const wchar_t *first, const wchar_t *last, unsigned __int64 count)
{
  int v3; // r9d
  unsigned __int64 v4; // r11
  signed __int64 v6; // r10
  unsigned __int16 v7; // cx
  wchar_t v8; // r8

  v3 = 0;
  v4 = count;
  if ( _locale_changed )
    return wcsnicmp_l(first, last, count, 0i64);
  if ( count )
  {
    if ( !first || !last )
    {
      *errno() = 22;
      invalid_parameter_noinfo();
      return 0x7FFFFFFF;
    }
    v6 = (char *)first - (char *)last;
    do
    {
      v7 = *(const wchar_t *)((char *)last + v6);
      if ( (unsigned __int16)(v7 - 65) <= 0x19u )
        v7 += 32;
      v8 = *last;
      if ( (unsigned __int16)(*last - 65) <= 0x19u )
        v8 += 32;
      ++last;
      --v4;
    }
    while ( v4 && v7 && v7 == v8 );
    return v7 - v8;
  }
  return v3;
}

