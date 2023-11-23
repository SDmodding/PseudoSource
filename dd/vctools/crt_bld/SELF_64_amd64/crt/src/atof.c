// File Line: 49
// RVA: 0x12B0234
long double __fastcall atof_l(const char *nptr, localeinfo_struct *plocinfo)
{
  long double result; // xmm0_8
  threadlocaleinfostruct *locinfo; // rdx
  int v5; // eax
  _LocaleUpdate v6; // [rsp+20h] [rbp-48h] BYREF
  _flt flt; // [rsp+40h] [rbp-28h] BYREF

  _LocaleUpdate::_LocaleUpdate(&v6, plocinfo);
  if ( nptr )
  {
    locinfo = v6.localeinfo.locinfo;
    while ( 1 )
    {
      if ( locinfo->mb_cur_max <= 1 )
      {
        v5 = locinfo->pctype[*(unsigned __int8 *)nptr] & 8;
      }
      else
      {
        v5 = isctype_l(*(unsigned __int8 *)nptr, 8, &v6.localeinfo);
        locinfo = v6.localeinfo.locinfo;
      }
      if ( !v5 )
        break;
      ++nptr;
    }
    result = fltin2(&flt, nptr, &v6.localeinfo)->dval;
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    result = 0.0;
  }
  if ( v6.updated )
    v6.ptd->_ownlocale &= ~2u;
  return result;
}

// File Line: 70
// RVA: 0x12B02F0
long double __fastcall atof(const char *nptr)
{
  return atof_l(nptr, 0i64);
}

