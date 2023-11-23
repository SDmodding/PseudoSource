// File Line: 55
// RVA: 0x12DCB90
__int64 __fastcall strnicoll_l(
        const char *_string1,
        const char *_string2,
        unsigned __int64 count,
        localeinfo_struct *plocinfo)
{
  unsigned int v7; // ebx
  wchar_t *v8; // rdx
  int v9; // eax
  _LocaleUpdate plocinfoa; // [rsp+40h] [rbp-28h] BYREF

  _LocaleUpdate::_LocaleUpdate(&plocinfoa, plocinfo);
  if ( count )
  {
    if ( _string1 && _string2 )
    {
      v7 = 0x7FFFFFFF;
      if ( count <= 0x7FFFFFFF )
      {
        v8 = plocinfoa.localeinfo.locinfo->locale_name[1];
        if ( v8 )
        {
          v9 = _crtCompareStringA(
                 &plocinfoa.localeinfo,
                 v8,
                 0x1001u,
                 _string1,
                 count,
                 _string2,
                 count,
                 plocinfoa.localeinfo.locinfo->lc_collate_cp);
          if ( v9 )
            v7 = v9 - 2;
          else
            *errno() = 22;
        }
        else
        {
          v7 = strnicmp_l(_string1, _string2, count, &plocinfoa.localeinfo);
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
  if ( plocinfoa.updated )
    plocinfoa.ptd->_ownlocale &= ~2u;
  return v7;
}

