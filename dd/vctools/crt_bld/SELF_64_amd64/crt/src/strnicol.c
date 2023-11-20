// File Line: 55
// RVA: 0x12DCB90
__int64 __fastcall strnicoll_l(const char *_string1, const char *_string2, unsigned __int64 count, localeinfo_struct *plocinfo)
{
  const char *v4; // rbp
  const char *lpString2; // rsi
  unsigned __int64 cchCount1; // rdi
  unsigned int v7; // ebx
  const wchar_t *v8; // rdx
  int v9; // eax
  localeinfo_struct plocinfoa; // [rsp+40h] [rbp-28h]
  __int64 v12; // [rsp+50h] [rbp-18h]
  char v13; // [rsp+58h] [rbp-10h]

  v4 = _string1;
  lpString2 = _string2;
  cchCount1 = count;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&plocinfoa, plocinfo);
  if ( cchCount1 )
  {
    if ( v4 && lpString2 )
    {
      v7 = 0x7FFFFFFF;
      if ( cchCount1 <= 0x7FFFFFFF )
      {
        v8 = plocinfoa.locinfo->locale_name[1];
        if ( v8 )
        {
          v9 = _crtCompareStringA(
                 &plocinfoa,
                 v8,
                 0x1001u,
                 v4,
                 cchCount1,
                 lpString2,
                 cchCount1,
                 plocinfoa.locinfo->lc_collate_cp);
          if ( v9 )
            v7 = v9 - 2;
          else
            *errno() = 22;
        }
        else
        {
          v7 = strnicmp_l(v4, lpString2, cchCount1, &plocinfoa);
        }
      }
      else
      {
        *errno() = 22;
        invalid_parameter_noinfo();
      }
    }
    else
    {
      *errno() = 22;
      invalid_parameter_noinfo();
      v7 = 0x7FFFFFFF;
    }
  }
  else
  {
    v7 = 0;
  }
  if ( v13 )
    *(_DWORD *)(v12 + 200) &= 0xFFFFFFFD;
  return v7;
}

