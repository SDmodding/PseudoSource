// File Line: 56
// RVA: 0x12C0688
size_t __fastcall mbstowcs_l_helper(wchar_t *pwcs, const char *s, size_t n, localeinfo_struct *plocinfo)
{
  wchar_t *lpWideCharStr; // rdi
  size_t v7; // rbx
  int v9; // eax
  __int64 v10; // rcx
  int v11; // r15d
  const char *v12; // rsi
  bool i; // zf
  int v14; // eax
  int v15; // eax
  _LocaleUpdate v16; // [rsp+30h] [rbp-38h] BYREF

  lpWideCharStr = pwcs;
  v7 = 0i64;
  if ( pwcs )
  {
    if ( !n )
      return 0i64;
    *pwcs = 0;
  }
  if ( !s )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return -1i64;
  }
  _LocaleUpdate::_LocaleUpdate(&v16, plocinfo);
  if ( lpWideCharStr )
  {
    if ( !v16.localeinfo.locinfo->locale_name[2] )
    {
      if ( n )
      {
        do
        {
          *lpWideCharStr = (unsigned __int8)s[v7];
          if ( !s[v7] )
            break;
          ++v7;
          ++lpWideCharStr;
        }
        while ( v7 < n );
      }
      goto LABEL_29;
    }
    v7 = -1i64;
    v9 = MultiByteToWideChar(v16.localeinfo.locinfo->lc_codepage, 9u, s, -1, lpWideCharStr, n);
    v10 = v9;
    if ( !v9 )
    {
      if ( GetLastError() != 122 )
        goto LABEL_22;
      v11 = n;
      v12 = s;
      for ( i = (_DWORD)n == 0; !i; i = v11 == 0 )
      {
        --v11;
        if ( !*v12 )
          break;
        if ( isleadbyte_l(*(unsigned __int8 *)v12, &v16.localeinfo) )
        {
          if ( !*++v12 )
            goto LABEL_22;
        }
        ++v12;
      }
      v14 = MultiByteToWideChar(v16.localeinfo.locinfo->lc_codepage, 1u, s, (_DWORD)v12 - (_DWORD)s, lpWideCharStr, n);
      if ( v14 )
      {
        v7 = v14;
      }
      else
      {
LABEL_22:
        *errno() = 42;
        *lpWideCharStr = 0;
      }
      goto LABEL_29;
    }
    goto LABEL_28;
  }
  if ( v16.localeinfo.locinfo->locale_name[2] )
  {
    v7 = -1i64;
    v15 = MultiByteToWideChar(v16.localeinfo.locinfo->lc_codepage, 9u, s, -1, 0i64, 0);
    v10 = v15;
    if ( v15 )
    {
LABEL_28:
      v7 = v10 - 1;
      goto LABEL_29;
    }
    *errno() = 42;
  }
  else
  {
    v7 = strlen(s);
  }
LABEL_29:
  if ( v16.updated )
    v16.ptd->_ownlocale &= ~2u;
  return v7;
}

// File Line: 190
// RVA: 0x12C0994
size_t __fastcall mbstowcs(wchar_t *pwcs, const char *s, size_t n)
{
  localeinfo_struct *v3; // r9

  if ( _locale_changed )
    v3 = 0i64;
  else
    v3 = &_initiallocalestructinfo;
  return mbstowcs_l_helper(pwcs, s, n, v3);
}

// File Line: 236
// RVA: 0x12C0864
__int64 __fastcall mbstowcs_s_l(
        unsigned __int64 *pConvertedChars,
        wchar_t *pwcs,
        unsigned __int64 sizeInWords,
        const char *s,
        unsigned __int64 n,
        localeinfo_struct *plocinfo)
{
  unsigned int v10; // ebx
  size_t v11; // r8
  int *v12; // rax
  size_t v13; // rax
  unsigned __int64 v14; // rax
  _LocaleUpdate v16; // [rsp+20h] [rbp-38h] BYREF

  v10 = 0;
  if ( pwcs )
  {
    if ( !sizeInWords )
    {
LABEL_5:
      v10 = 22;
      *errno() = 22;
      invalid_parameter_noinfo();
      return v10;
    }
    *pwcs = 0;
  }
  else if ( sizeInWords )
  {
    goto LABEL_5;
  }
  if ( pConvertedChars )
    *pConvertedChars = 0i64;
  _LocaleUpdate::_LocaleUpdate(&v16, plocinfo);
  v11 = n;
  if ( n > sizeInWords )
    v11 = sizeInWords;
  if ( v11 <= 0x7FFFFFFF )
  {
    v13 = mbstowcs_l_helper(pwcs, s, v11, &v16.localeinfo);
    if ( v13 == -1i64 )
    {
      if ( pwcs )
        *pwcs = 0;
      v10 = *errno();
      goto LABEL_26;
    }
    v14 = v13 + 1;
    if ( pwcs )
    {
      if ( v14 > sizeInWords )
      {
        if ( n != -1i64 )
        {
          *pwcs = 0;
          v12 = errno();
          v10 = 34;
          goto LABEL_21;
        }
        v14 = sizeInWords;
        v10 = 80;
      }
      pwcs[v14 - 1] = 0;
    }
    if ( pConvertedChars )
      *pConvertedChars = v14;
    goto LABEL_26;
  }
  v12 = errno();
  v10 = 22;
LABEL_21:
  *v12 = v10;
  invalid_parameter_noinfo();
LABEL_26:
  if ( v16.updated )
    v16.ptd->_ownlocale &= ~2u;
  return v10;
}

// File Line: 308
// RVA: 0x12C09B0
__int64 __fastcall mbstowcs_s(
        unsigned __int64 *pConvertedChars,
        wchar_t *pwcs,
        unsigned __int64 sizeInWords,
        const char *s,
        unsigned __int64 n)
{
  return mbstowcs_s_l(pConvertedChars, pwcs, sizeInWords, s, n, 0i64);
}

