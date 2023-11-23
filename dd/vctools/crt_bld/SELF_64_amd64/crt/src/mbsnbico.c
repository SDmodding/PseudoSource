// File Line: 53
// RVA: 0x12D5AEC
__int64 __fastcall mbsnbicoll_l(const char *s1, const char *s2, unsigned __int64 n, localeinfo_struct *plocinfo)
{
  unsigned int v8; // ebx
  int v9; // eax
  _LocaleUpdate plocinfoa; // [rsp+40h] [rbp-28h] BYREF

  _LocaleUpdate::_LocaleUpdate(&plocinfoa, plocinfo);
  if ( n )
  {
    if ( s1 && s2 )
    {
      v8 = 0x7FFFFFFF;
      if ( n <= 0x7FFFFFFF )
      {
        if ( plocinfoa.localeinfo.mbcinfo->ismbcodepage )
        {
          v9 = _crtCompareStringA(
                 &plocinfoa.localeinfo,
                 plocinfoa.localeinfo.mbcinfo->mblocalename,
                 0x1001u,
                 s1,
                 n,
                 s2,
                 n,
                 plocinfoa.localeinfo.mbcinfo->mbcodepage);
          if ( v9 )
            v8 = v9 - 2;
        }
        else
        {
          v8 = strnicoll_l(s1, s2, n, plocinfo);
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
  if ( plocinfoa.updated )
    plocinfoa.ptd->_ownlocale &= ~2u;
  return v8;
}

// File Line: 86
// RVA: 0x12D5AE4
int __fastcall mbsnbicoll(const char *s1, const char *s2, unsigned __int64 n)
{
  return mbsnbicoll_l(s1, s2, n, 0i64);
}

