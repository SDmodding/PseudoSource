// File Line: 50
// RVA: 0x12DBF54
int __fastcall mbsnbcmp_l(const char *s1, const char *s2, size_t n, localeinfo_struct *plocinfo)
{
  size_t v4; // rbx
  int result; // eax
  __int64 v8; // rcx
  __int64 v9; // rdx
  _LocaleUpdate v10; // [rsp+20h] [rbp-28h] BYREF

  v4 = n;
  if ( !n )
    return 0;
  _LocaleUpdate::_LocaleUpdate(&v10, plocinfo);
  if ( !v10.localeinfo.mbcinfo->ismbcodepage )
  {
    result = strncmp(s1, s2, v4);
    goto LABEL_26;
  }
  if ( s1 && s2 )
  {
    while ( 1 )
    {
      v8 = *(unsigned __int8 *)s1;
      --v4;
      ++s1;
      if ( (v10.localeinfo.mbcinfo->mbctype[v8 + 1] & 4) == 0 )
        goto LABEL_15;
      if ( v4 )
        break;
      LOWORD(v8) = 0;
      if ( (v10.localeinfo.mbcinfo->mbctype[*(unsigned __int8 *)s2 + 1] & 4) != 0 )
        goto LABEL_24;
      LOWORD(v9) = *(unsigned __int8 *)s2;
$test:
      if ( (_WORD)v9 != (_WORD)v8 )
      {
        result = (unsigned __int16)v9 < (unsigned __int16)v8 ? 1 : -1;
        goto LABEL_26;
      }
      if ( !(_WORD)v8 || !v4 )
      {
LABEL_24:
        result = 0;
        goto LABEL_26;
      }
    }
    if ( *s1 )
      LOWORD(v8) = *(unsigned __int8 *)s1++ | (unsigned __int16)((_WORD)v8 << 8);
    else
      LOWORD(v8) = 0;
LABEL_15:
    v9 = *(unsigned __int8 *)s2++;
    if ( (v10.localeinfo.mbcinfo->mbctype[v9 + 1] & 4) != 0 )
    {
      if ( v4 )
      {
        --v4;
        if ( *s2 )
          LOWORD(v9) = *(unsigned __int8 *)s2++ | (unsigned __int16)((_WORD)v9 << 8);
        else
          LOWORD(v9) = 0;
      }
      else
      {
        LOWORD(v9) = 0;
      }
    }
    goto $test;
  }
  *errno() = 22;
  invalid_parameter_noinfo();
  result = 0x7FFFFFFF;
LABEL_26:
  if ( v10.updated )
    v10.ptd->_ownlocale &= ~2u;
  return result;
}

// File Line: 106
// RVA: 0x12DBF4C
int __fastcall mbsnbcmp(const char *s1, const char *s2, unsigned __int64 n)
{
  return mbsnbcmp_l(s1, s2, n, 0i64);
}

