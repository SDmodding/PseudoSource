// File Line: 40
// RVA: 0x12D8114
signed __int64 __fastcall atodbl_l(_CRT_DOUBLE *d, char *str, localeinfo_struct *plocinfo)
{
  _CRT_DOUBLE *v3; // rdi
  char *v4; // rbx
  char v5; // bl
  INTRNCVT_STATUS v6; // ecx
  signed __int64 result; // rax
  _LocaleUpdate _Locale; // [rsp+40h] [rbp-48h]
  char *p_end_ptr; // [rsp+60h] [rbp-28h]
  _LDBL12 pld12; // [rsp+68h] [rbp-20h]

  v3 = d;
  v4 = str;
  _LocaleUpdate::_LocaleUpdate(&_Locale, plocinfo);
  v5 = _strgtold12_l(&pld12, (const char **)&p_end_ptr, v4, 0, 0, 0, 0, &_Locale.localeinfo);
  v6 = ld12tod(&pld12, v3);
  result = 3i64;
  if ( !(v5 & 3) )
  {
    if ( v6 == 1 )
      goto LABEL_9;
    if ( v6 == 2 )
      goto LABEL_6;
LABEL_8:
    result = 0i64;
    goto LABEL_9;
  }
  if ( v5 & 1 )
  {
LABEL_6:
    result = 4i64;
    goto LABEL_9;
  }
  if ( !(v5 & 2) )
    goto LABEL_8;
LABEL_9:
  if ( _Locale.updated )
    _Locale.ptd->_ownlocale &= 0xFFFFFFFD;
  return result;
}

// File Line: 125
// RVA: 0x12D81DC
signed __int64 __fastcall atoflt_l(_CRT_FLOAT *d, char *str, localeinfo_struct *plocinfo)
{
  _CRT_FLOAT *v3; // rdi
  char *v4; // rbx
  char v5; // bl
  INTRNCVT_STATUS v6; // ecx
  signed __int64 result; // rax
  _LocaleUpdate _Locale; // [rsp+40h] [rbp-48h]
  char *p_end_ptr; // [rsp+60h] [rbp-28h]
  _LDBL12 pld12; // [rsp+68h] [rbp-20h]

  v3 = d;
  v4 = str;
  _LocaleUpdate::_LocaleUpdate(&_Locale, plocinfo);
  v5 = _strgtold12_l(&pld12, (const char **)&p_end_ptr, v4, 0, 0, 0, 0, &_Locale.localeinfo);
  v6 = ld12tof(&pld12, v3);
  result = 3i64;
  if ( !(v5 & 3) )
  {
    if ( v6 == 1 )
      goto LABEL_9;
    if ( v6 == 2 )
      goto LABEL_6;
LABEL_8:
    result = 0i64;
    goto LABEL_9;
  }
  if ( v5 & 1 )
  {
LABEL_6:
    result = 4i64;
    goto LABEL_9;
  }
  if ( !(v5 & 2) )
    goto LABEL_8;
LABEL_9:
  if ( _Locale.updated )
    _Locale.ptd->_ownlocale &= 0xFFFFFFFD;
  return result;
}

