// File Line: 47
// RVA: 0x12B2C40
__int64 __fastcall stricmp_l(const char *dst, const char *src, localeinfo_struct *plocinfo)
{
  const char *v3; // rsi
  const char *v4; // rdi
  unsigned int v5; // ebx
  signed __int64 v6; // rsi
  int v7; // ebx
  int v8; // eax
  _LocaleUpdate v10; // [rsp+20h] [rbp-28h]

  v3 = dst;
  v4 = src;
  _LocaleUpdate::_LocaleUpdate(&v10, plocinfo);
  if ( v3 && v4 )
  {
    if ( v10.localeinfo.locinfo->locale_name[2] )
    {
      v6 = v3 - v4;
      do
      {
        v7 = tolower_l((unsigned __int8)v4[v6], &v10.localeinfo);
        v8 = tolower_l(*(unsigned __int8 *)v4++, &v10.localeinfo);
      }
      while ( v7 && v7 == v8 );
      v5 = v7 - v8;
    }
    else
    {
      v5 = _ascii_stricmp(v3, v4);
    }
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    v5 = 0x7FFFFFFF;
  }
  if ( v10.updated )
    v10.ptd->_ownlocale &= 0xFFFFFFFD;
  return v5;
}

// File Line: 75
// RVA: 0x12B2BBC
__int64 __fastcall _ascii_stricmp(const char *dst, const char *src)
{
  const char *v2; // r9
  int v3; // er8
  int v4; // ecx

  v2 = dst;
  do
  {
    v3 = *(unsigned __int8 *)v2++;
    if ( (unsigned int)(v3 - 65) <= 0x19 )
      v3 += 32;
    v4 = *(unsigned __int8 *)src++;
    if ( (unsigned int)(v4 - 65) <= 0x19 )
      v4 += 32;
  }
  while ( v3 && v3 == v4 );
  return (unsigned int)(v3 - v4);
}

// File Line: 94
// RVA: 0x12B2BF8
int __fastcall stricmp(const char *dst, const char *src)
{
  if ( _locale_changed )
    return stricmp_l(dst, src, 0i64);
  if ( dst && src )
    return _ascii_stricmp(dst, src);
  *errno() = 22;
  invalid_parameter_noinfo();
  return 0x7FFFFFFF;
}

