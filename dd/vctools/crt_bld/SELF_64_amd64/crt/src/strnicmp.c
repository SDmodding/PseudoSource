// File Line: 51
// RVA: 0x12B9240
__int64 __fastcall strnicmp_l(const char *dst, const char *src, unsigned __int64 count, localeinfo_struct *plocinfo)
{
  unsigned __int64 v4; // rbp
  const char *v5; // rdi
  const char *v6; // rsi
  unsigned int v7; // ebx
  signed __int64 v8; // rsi
  int v9; // ebx
  int v10; // eax
  localeinfo_struct plocinfoa; // [rsp+20h] [rbp-28h]
  __int64 v13; // [rsp+30h] [rbp-18h]
  char v14; // [rsp+38h] [rbp-10h]

  v4 = count;
  v5 = src;
  v6 = dst;
  if ( !count )
    return 0i64;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&plocinfoa, plocinfo);
  v7 = 0x7FFFFFFF;
  if ( v6 && v5 && v4 <= 0x7FFFFFFF )
  {
    if ( plocinfoa.locinfo->locale_name[2] )
    {
      v8 = v6 - v5;
      do
      {
        v9 = tolower_l((unsigned __int8)v5[v8], &plocinfoa);
        v10 = tolower_l(*(unsigned __int8 *)v5++, &plocinfoa);
        --v4;
      }
      while ( v4 && v9 && v9 == v10 );
      v7 = v9 - v10;
    }
    else
    {
      v7 = _ascii_strnicmp(v6, v5, v4);
    }
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
  }
  if ( v14 )
    *(_DWORD *)(v13 + 200) &= 0xFFFFFFFD;
  return v7;
}

// File Line: 90
// RVA: 0x12B91A8
__int64 __fastcall _ascii_strnicmp(const char *first, const char *last, unsigned __int64 count)
{
  const char *v3; // r10
  int v4; // er9
  int v5; // ecx

  v3 = first;
  if ( !count )
    return 0i64;
  do
  {
    v4 = *(unsigned __int8 *)v3++;
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

