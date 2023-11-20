// File Line: 53
// RVA: 0x12B36E0
double __fastcall strtod_l(const char *nptr, char **endptr, localeinfo_struct *plocinfo)
{
  const char *v3; // rsi
  const char *v4; // rbx
  char **v5; // rdi
  double v6; // xmm6_8
  threadlocaleinfostruct *v7; // rdx
  int v8; // eax
  _flt *v9; // rax
  _LocaleUpdate v11; // [rsp+20h] [rbp-58h]
  _flt flt; // [rsp+40h] [rbp-38h]

  v3 = nptr;
  v4 = nptr;
  v5 = endptr;
  _LocaleUpdate::_LocaleUpdate(&v11, plocinfo);
  if ( v5 )
    *v5 = (char *)v4;
  if ( !v3 )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    v6 = 0.0;
    goto LABEL_23;
  }
  v7 = v11.localeinfo.locinfo;
  while ( 1 )
  {
    if ( v7->mb_cur_max <= 1 )
    {
      v8 = v7->pctype[*(unsigned __int8 *)v4] & 8;
    }
    else
    {
      v8 = isctype_l(*(unsigned __int8 *)v4, 8, &v11.localeinfo);
      v7 = v11.localeinfo.locinfo;
    }
    if ( !v8 )
      break;
    ++v4;
  }
  v9 = fltin2(&flt, v4, &v11.localeinfo);
  if ( v5 )
    *v5 = (char *)&v4[v9->nbytes];
  if ( !(v9->flags & 0x240) )
  {
    if ( v9->flags & 0x81 )
    {
      v6 = HUGE;
      if ( *v4 == 45 )
        v6 = -HUGE;
    }
    else if ( !(v9->flags & 0x100) || (v6 = 0.0, v9->dval != 0.0) )
    {
      v6 = v9->dval;
      goto LABEL_23;
    }
    *errno() = 34;
    goto LABEL_23;
  }
  v6 = 0.0;
  if ( v5 )
    *v5 = (char *)v3;
LABEL_23:
  if ( v11.updated )
    v11.ptd->_ownlocale &= 0xFFFFFFFD;
  return v6;
}

// File Line: 112
// RVA: 0x12B3838
void __fastcall strtod(const char *nptr, char **endptr)
{
  strtod_l(nptr, endptr, 0i64);
}

