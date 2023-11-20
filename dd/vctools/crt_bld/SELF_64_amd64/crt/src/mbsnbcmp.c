// File Line: 50
// RVA: 0x12DBF54
int __fastcall mbsnbcmp_l(const char *s1, const char *s2, unsigned __int64 n, localeinfo_struct *plocinfo)
{
  unsigned __int64 v4; // rbx
  const char *v5; // rdi
  const char *v6; // rsi
  int result; // eax
  __int64 v8; // rcx
  __int64 v9; // rax
  __int64 v10; // rdx
  _LocaleUpdate v11; // [rsp+20h] [rbp-28h]

  v4 = n;
  v5 = s2;
  v6 = s1;
  if ( !n )
    return 0;
  _LocaleUpdate::_LocaleUpdate(&v11, plocinfo);
  if ( !v11.localeinfo.mbcinfo->ismbcodepage )
  {
    result = strncmp(v6, v5, v4);
    goto LABEL_26;
  }
  if ( v6 && v5 )
  {
    while ( 1 )
    {
      v8 = *(unsigned __int8 *)v6;
      --v4;
      ++v6;
      if ( !(v11.localeinfo.mbcinfo->mbctype[v8 + 1] & 4) )
        goto LABEL_15;
      if ( v4 )
        break;
      v9 = *(unsigned __int8 *)v5;
      LOWORD(v8) = 0;
      if ( v11.localeinfo.mbcinfo->mbctype[v9 + 1] & 4 )
        goto LABEL_24;
      LOWORD(v10) = *(unsigned __int8 *)v5;
$test:
      if ( (_WORD)v10 != (_WORD)v8 )
      {
        result = (unsigned __int16)v10 < (unsigned __int16)v8 ? 1 : -1;
        goto LABEL_26;
      }
      if ( !(_WORD)v8 || !v4 )
      {
LABEL_24:
        result = 0;
        goto LABEL_26;
      }
    }
    if ( *v6 )
      LOWORD(v8) = *(unsigned __int8 *)v6++ | (unsigned __int16)((_WORD)v8 << 8);
    else
      LOWORD(v8) = 0;
LABEL_15:
    v10 = *(unsigned __int8 *)v5++;
    if ( v11.localeinfo.mbcinfo->mbctype[v10 + 1] & 4 )
    {
      if ( v4 )
      {
        --v4;
        if ( *v5 )
          LOWORD(v10) = *(unsigned __int8 *)v5++ | (unsigned __int16)((_WORD)v10 << 8);
        else
          LOWORD(v10) = 0;
      }
      else
      {
        LOWORD(v10) = 0;
      }
    }
    goto $test;
  }
  *errno() = 22;
  invalid_parameter_noinfo();
  result = 0x7FFFFFFF;
LABEL_26:
  if ( v11.updated )
    v11.ptd->_ownlocale &= 0xFFFFFFFD;
  return result;
}

// File Line: 106
// RVA: 0x12DBF4C
int __fastcall mbsnbcmp(const char *s1, const char *s2, unsigned __int64 n)
{
  return mbsnbcmp_l(s1, s2, n, 0i64);
}

