// File Line: 53
// RVA: 0x12D5AEC
__int64 __fastcall mbsnbicoll_l(const char *s1, const char *s2, unsigned __int64 n, localeinfo_struct *plocinfo)
{
  const char *v4; // rbp
  const char *lpString2; // rsi
  localeinfo_struct *v6; // r14
  unsigned __int64 cchCount1; // rdi
  unsigned int v8; // ebx
  int v9; // eax
  localeinfo_struct plocinfoa; // [rsp+40h] [rbp-28h]
  __int64 v12; // [rsp+50h] [rbp-18h]
  char v13; // [rsp+58h] [rbp-10h]

  v4 = s1;
  lpString2 = s2;
  v6 = plocinfo;
  cchCount1 = n;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&plocinfoa, plocinfo);
  if ( cchCount1 )
  {
    if ( v4 && lpString2 )
    {
      v8 = 0x7FFFFFFF;
      if ( cchCount1 <= 0x7FFFFFFF )
      {
        if ( plocinfoa.mbcinfo->ismbcodepage )
        {
          v9 = _crtCompareStringA(
                 &plocinfoa,
                 plocinfoa.mbcinfo->mblocalename,
                 0x1001u,
                 v4,
                 cchCount1,
                 lpString2,
                 cchCount1,
                 plocinfoa.mbcinfo->mbcodepage);
          if ( v9 )
            v8 = v9 - 2;
        }
        else
        {
          v8 = strnicoll_l(v4, lpString2, cchCount1, v6);
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
      v8 = 0x7FFFFFFF;
    }
  }
  else
  {
    v8 = 0;
  }
  if ( v13 )
    *(_DWORD *)(v12 + 200) &= 0xFFFFFFFD;
  return v8;
}

// File Line: 86
// RVA: 0x12D5AE4
int __fastcall mbsnbicoll(const char *s1, const char *s2, unsigned __int64 n)
{
  return mbsnbicoll_l(s1, s2, n, 0i64);
}

