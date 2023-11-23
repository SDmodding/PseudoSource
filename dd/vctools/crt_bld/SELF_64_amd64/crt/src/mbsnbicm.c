// File Line: 52
// RVA: 0x12DC088
int __fastcall mbsnbicmp_l(const char *s1, const char *s2, unsigned __int64 n, localeinfo_struct *plocinfo)
{
  int result; // eax
  __int64 v8; // r8
  __int64 v9; // rdx
  __int16 v10; // ax
  __int16 v11; // ax
  _LocaleUpdate v12; // [rsp+20h] [rbp-28h] BYREF

  _LocaleUpdate::_LocaleUpdate(&v12, plocinfo);
  if ( !n )
  {
LABEL_37:
    result = 0;
    goto LABEL_39;
  }
  if ( !v12.localeinfo.mbcinfo->ismbcodepage )
  {
    result = strnicmp(s1, s2, n);
    goto LABEL_39;
  }
  if ( !s1 || !s2 )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    result = 0x7FFFFFFF;
    goto LABEL_39;
  }
  while ( 1 )
  {
    v8 = *(unsigned __int8 *)s1;
    --n;
    ++s1;
    if ( (v12.localeinfo.mbcinfo->mbctype[v8 + 1] & 4) == 0 )
    {
      if ( (v12.localeinfo.mbcinfo->mbctype[(unsigned __int16)v8 + 1] & 0x10) != 0 )
        LOWORD(v8) = (unsigned __int8)v12.localeinfo.mbcinfo->mbcasemap[(unsigned __int16)v8];
      goto LABEL_21;
    }
    if ( n )
    {
      if ( *s1 )
      {
        v10 = *(unsigned __int8 *)s1++;
        LOWORD(v8) = v10 | ((_WORD)v8 << 8);
        if ( (unsigned __int16)v8 < v12.localeinfo.mbcinfo->mbulinfo[0]
          || (unsigned __int16)v8 > v12.localeinfo.mbcinfo->mbulinfo[1] )
        {
          if ( (unsigned __int16)v8 >= v12.localeinfo.mbcinfo->mbulinfo[3]
            && (unsigned __int16)v8 <= v12.localeinfo.mbcinfo->mbulinfo[4] )
          {
            LOWORD(v8) = v12.localeinfo.mbcinfo->mbulinfo[5] + v8;
          }
        }
        else
        {
          LOWORD(v8) = v12.localeinfo.mbcinfo->mbulinfo[2] + v8;
        }
      }
      else
      {
        LOWORD(v8) = 0;
      }
LABEL_21:
      v9 = *(unsigned __int8 *)s2++;
      if ( (v12.localeinfo.mbcinfo->mbctype[v9 + 1] & 4) != 0 )
      {
        if ( n )
        {
          --n;
          if ( *s2 )
          {
            v11 = *(unsigned __int8 *)s2++;
            LOWORD(v9) = v11 | ((_WORD)v9 << 8);
            if ( (unsigned __int16)v9 < v12.localeinfo.mbcinfo->mbulinfo[0]
              || (unsigned __int16)v9 > v12.localeinfo.mbcinfo->mbulinfo[1] )
            {
              if ( (unsigned __int16)v9 >= v12.localeinfo.mbcinfo->mbulinfo[3]
                && (unsigned __int16)v9 <= v12.localeinfo.mbcinfo->mbulinfo[4] )
              {
                LOWORD(v9) = v12.localeinfo.mbcinfo->mbulinfo[5] + v9;
              }
            }
            else
            {
              LOWORD(v9) = v12.localeinfo.mbcinfo->mbulinfo[2] + v9;
            }
          }
          else
          {
            LOWORD(v9) = 0;
          }
        }
        else
        {
          LOWORD(v9) = 0;
        }
      }
      else if ( (v12.localeinfo.mbcinfo->mbctype[(unsigned __int16)v9 + 1] & 0x10) != 0 )
      {
        LOWORD(v9) = (unsigned __int8)v12.localeinfo.mbcinfo->mbcasemap[(unsigned __int16)v9];
      }
      goto $test_0;
    }
    LOWORD(v8) = 0;
    if ( (v12.localeinfo.mbcinfo->mbctype[*(unsigned __int8 *)s2 + 1] & 4) != 0 )
      goto LABEL_37;
    LOWORD(v9) = *(unsigned __int8 *)s2;
$test_0:
    if ( (_WORD)v9 != (_WORD)v8 )
      break;
    if ( !(_WORD)v8 || !n )
      goto LABEL_37;
  }
  result = (unsigned __int16)v9 < (unsigned __int16)v8 ? 1 : -1;
LABEL_39:
  if ( v12.updated )
    v12.ptd->_ownlocale &= ~2u;
  return result;
}

// File Line: 134
// RVA: 0x12DC080
int __fastcall mbsnbicmp(const char *s1, const char *s2, unsigned __int64 n)
{
  return mbsnbicmp_l(s1, s2, n, 0i64);
}

