// File Line: 53
// RVA: 0x12DD168
char *__fastcall mbschr_l(const char *string, unsigned int c, localeinfo_struct *plocinfo)
{
  char *v3; // rbx
  int v4; // edi
  unsigned __int16 v5; // cx
  _LocaleUpdate v7; // [rsp+20h] [rbp-28h]

  v3 = (char *)string;
  v4 = c;
  _LocaleUpdate::_LocaleUpdate(&v7, plocinfo);
  if ( !v3 )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
LABEL_13:
    v3 = 0i64;
    goto LABEL_14;
  }
  if ( !v7.localeinfo.mbcinfo->ismbcodepage )
  {
    v3 = strchr(v3, v4);
    goto LABEL_14;
  }
  while ( 1 )
  {
    v5 = (unsigned __int8)*v3;
    if ( !*v3 )
      break;
    if ( v7.localeinfo.mbcinfo->mbctype[(unsigned __int8)v5 + 1] & 4 )
    {
      if ( !*++v3 )
        goto LABEL_13;
      if ( v4 == ((unsigned __int8)*v3 | (v5 << 8)) )
      {
        --v3;
        goto LABEL_14;
      }
    }
    else if ( v4 == (unsigned __int8)*v3 )
    {
      break;
    }
    ++v3;
  }
  if ( v4 != (unsigned __int8)*v3 )
    goto LABEL_13;
LABEL_14:
  if ( v7.updated )
    v7.ptd->_ownlocale &= 0xFFFFFFFD;
  return v3;
}

// File Line: 86
// RVA: 0x12DD160
const char *__fastcall mbschr(const char *string, unsigned int c)
{
  return mbschr_l(string, c, 0i64);
}

