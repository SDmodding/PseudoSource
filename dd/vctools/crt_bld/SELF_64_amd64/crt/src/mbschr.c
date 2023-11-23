// File Line: 53
// RVA: 0x12DD168
char *__fastcall mbschr_l(char *string, unsigned int c, localeinfo_struct *plocinfo)
{
  unsigned __int16 v5; // cx
  _LocaleUpdate v7; // [rsp+20h] [rbp-28h] BYREF

  _LocaleUpdate::_LocaleUpdate(&v7, plocinfo);
  if ( !string )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
LABEL_13:
    string = 0i64;
    goto LABEL_14;
  }
  if ( !v7.localeinfo.mbcinfo->ismbcodepage )
  {
    string = strchr((unsigned __int64)string, c);
    goto LABEL_14;
  }
  while ( 1 )
  {
    v5 = (unsigned __int8)*string;
    if ( !*string )
      break;
    if ( (v7.localeinfo.mbcinfo->mbctype[(unsigned __int8)v5 + 1] & 4) != 0 )
    {
      if ( !*++string )
        goto LABEL_13;
      if ( c == ((unsigned __int8)*string | (v5 << 8)) )
      {
        --string;
        goto LABEL_14;
      }
    }
    else if ( c == (unsigned __int8)*string )
    {
      break;
    }
    ++string;
  }
  if ( c != (unsigned __int8)*string )
    goto LABEL_13;
LABEL_14:
  if ( v7.updated )
    v7.ptd->_ownlocale &= ~2u;
  return string;
}

// File Line: 86
// RVA: 0x12DD160
const char *__fastcall mbschr(const char *string, unsigned int c)
{
  return mbschr_l(string, c, 0i64);
}

