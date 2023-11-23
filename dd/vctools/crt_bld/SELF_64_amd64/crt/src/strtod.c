// File Line: 53
// RVA: 0x12B36E0
double __fastcall strtod_l(char *nptr, char **endptr, localeinfo_struct *plocinfo)
{
  char *v4; // rbx
  double dval; // xmm6_8
  threadlocaleinfostruct *locinfo; // rdx
  int v8; // eax
  _flt *v9; // rax
  _LocaleUpdate v11; // [rsp+20h] [rbp-58h] BYREF
  _flt flt; // [rsp+40h] [rbp-38h] BYREF

  v4 = nptr;
  _LocaleUpdate::_LocaleUpdate(&v11, plocinfo);
  if ( endptr )
    *endptr = v4;
  if ( !nptr )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    dval = 0.0;
    goto LABEL_23;
  }
  locinfo = v11.localeinfo.locinfo;
  while ( 1 )
  {
    if ( locinfo->mb_cur_max <= 1 )
    {
      v8 = locinfo->pctype[(unsigned __int8)*v4] & 8;
    }
    else
    {
      v8 = isctype_l((unsigned __int8)*v4, 8, &v11.localeinfo);
      locinfo = v11.localeinfo.locinfo;
    }
    if ( !v8 )
      break;
    ++v4;
  }
  v9 = fltin2(&flt, v4, &v11.localeinfo);
  if ( endptr )
    *endptr = &v4[v9->nbytes];
  if ( (v9->flags & 0x240) == 0 )
  {
    if ( (v9->flags & 0x81) != 0 )
    {
      dval = HUGE;
      if ( *v4 == 45 )
        dval = -HUGE;
    }
    else if ( (v9->flags & 0x100) == 0 || (dval = 0.0, v9->dval != 0.0) )
    {
      dval = v9->dval;
      goto LABEL_23;
    }
    *errno() = 34;
    goto LABEL_23;
  }
  dval = 0.0;
  if ( endptr )
    *endptr = nptr;
LABEL_23:
  if ( v11.updated )
    v11.ptd->_ownlocale &= ~2u;
  return dval;
}

// File Line: 112
// RVA: 0x12B3838
double __fastcall strtod(char *nptr, char **endptr)
{
  return strtod_l(nptr, endptr, 0i64);
}

