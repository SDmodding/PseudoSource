// File Line: 49
// RVA: 0x12B0234
long double __fastcall atof_l(const char *nptr, localeinfo_struct *plocinfo)
{
  const char *v2; // rbx
  long double result; // xmm0_8
  threadlocaleinfostruct *v4; // rdx
  int v5; // eax
  _LocaleUpdate v6; // [rsp+20h] [rbp-48h]
  _flt flt; // [rsp+40h] [rbp-28h]

  v2 = nptr;
  _LocaleUpdate::_LocaleUpdate(&v6, plocinfo);
  if ( v2 )
  {
    v4 = v6.localeinfo.locinfo;
    while ( 1 )
    {
      if ( v4->mb_cur_max <= 1 )
      {
        v5 = v4->pctype[*(unsigned __int8 *)v2] & 8;
      }
      else
      {
        v5 = isctype_l(*(unsigned __int8 *)v2, 8, &v6.localeinfo);
        v4 = v6.localeinfo.locinfo;
      }
      if ( !v5 )
        break;
      ++v2;
    }
    result = fltin2(&flt, v2, &v6.localeinfo)->dval;
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    result = 0.0;
  }
  if ( v6.updated )
    v6.ptd->_ownlocale &= 0xFFFFFFFD;
  return result;
}

// File Line: 70
// RVA: 0x12B02F0
void __fastcall atof(const char *nptr)
{
  atof_l(nptr, 0i64);
}

