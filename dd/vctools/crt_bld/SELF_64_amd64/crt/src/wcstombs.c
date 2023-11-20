// File Line: 91
// RVA: 0x12B19E0
unsigned __int64 __fastcall wcstombs_l_helper(char *s, const wchar_t *pwcs, unsigned __int64 n, localeinfo_struct *plocinfo)
{
  unsigned __int64 cbMultiByte; // rsi
  const wchar_t *v5; // r14
  char *lpMultiByteStr; // r15
  signed __int64 v7; // rbx
  threadlocaleinfostruct *v9; // r13
  wchar_t v10; // ax
  int *v11; // rax
  const wchar_t *v12; // rax
  unsigned __int64 v13; // rcx
  int v14; // eax
  int v15; // eax
  unsigned __int64 v16; // rdi
  int v17; // eax
  __int64 v18; // rdx
  __int64 v19; // rcx
  char v20; // al
  wchar_t v21; // ax
  int v22; // eax
  int UsedDefaultChar; // [rsp+40h] [rbp-40h]
  _LocaleUpdate v24; // [rsp+48h] [rbp-38h]
  char MultiByteStr[8]; // [rsp+68h] [rbp-18h]

  cbMultiByte = n;
  v5 = pwcs;
  lpMultiByteStr = s;
  v7 = 0i64;
  UsedDefaultChar = 0;
  if ( s && !n )
    return 0i64;
  if ( !pwcs )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return -1i64;
  }
  _LocaleUpdate::_LocaleUpdate(&v24, plocinfo);
  if ( lpMultiByteStr )
  {
    v9 = v24.localeinfo.locinfo;
    if ( !v24.localeinfo.locinfo->locale_name[2] )
    {
      if ( cbMultiByte )
      {
        while ( *v5 <= 0xFFu )
        {
          lpMultiByteStr[v7] = *(_BYTE *)v5;
          v10 = *v5;
          ++v5;
          if ( v10 )
          {
            if ( ++v7 < cbMultiByte )
              continue;
          }
          goto LABEL_53;
        }
LABEL_13:
        v11 = errno();
        v7 = -1i64;
LABEL_52:
        *v11 = 42;
      }
LABEL_53:
      v16 = v7;
      goto LABEL_54;
    }
    if ( v24.localeinfo.locinfo->mb_cur_max == 1 )
    {
      if ( cbMultiByte )
      {
        v12 = v5;
        v13 = cbMultiByte;
        do
        {
          if ( !*v12 )
            break;
          ++v12;
          --v13;
        }
        while ( v13 );
        if ( v13 && !*v12 )
          LODWORD(cbMultiByte) = (unsigned __int64)(v12 - v5) + 1;
      }
      v14 = WideCharToMultiByte(
              v24.localeinfo.locinfo->lc_codepage,
              0,
              v5,
              cbMultiByte,
              lpMultiByteStr,
              cbMultiByte,
              0i64,
              &UsedDefaultChar);
      v7 = v14;
      if ( v14 && !UsedDefaultChar )
      {
        if ( !lpMultiByteStr[v14 - 1] )
          v7 = v14 - 1i64;
        goto LABEL_53;
      }
      goto LABEL_13;
    }
    v7 = -1i64;
    v15 = WideCharToMultiByte(
            v24.localeinfo.locinfo->lc_codepage,
            0,
            v5,
            -1,
            lpMultiByteStr,
            cbMultiByte,
            0i64,
            &UsedDefaultChar);
    v16 = v15;
    if ( v15 )
    {
      if ( !UsedDefaultChar )
      {
        v7 = v15 - 1i64;
        goto LABEL_53;
      }
LABEL_51:
      v11 = errno();
      goto LABEL_52;
    }
    if ( UsedDefaultChar || GetLastError() != 122 )
      goto LABEL_51;
    if ( cbMultiByte )
    {
      do
      {
        v17 = WideCharToMultiByte(v9->lc_codepage, 0, v5, 1, MultiByteStr, v9->mb_cur_max, 0i64, &UsedDefaultChar);
        if ( !v17 )
          goto LABEL_51;
        if ( UsedDefaultChar )
          goto LABEL_51;
        if ( v17 < 0 )
          goto LABEL_51;
        v18 = v17;
        if ( (unsigned __int64)v17 > 5 )
          goto LABEL_51;
        if ( v17 + v16 > cbMultiByte )
          break;
        v19 = 0i64;
        if ( v17 > 0i64 )
        {
          do
          {
            v20 = MultiByteStr[v19];
            lpMultiByteStr[v16] = v20;
            if ( !v20 )
              goto LABEL_54;
            ++v19;
            ++v16;
          }
          while ( v19 < v18 );
        }
        ++v5;
      }
      while ( v16 < cbMultiByte );
    }
  }
  else
  {
    if ( !v24.localeinfo.locinfo->locale_name[2] )
    {
      v21 = *v5;
      v16 = 0i64;
      if ( *v5 )
      {
        while ( v21 <= 0xFFu )
        {
          ++v5;
          ++v16;
          v21 = *v5;
          if ( !*v5 )
            goto LABEL_54;
        }
        v16 = -1i64;
        *errno() = 42;
      }
      goto LABEL_54;
    }
    v7 = -1i64;
    v22 = WideCharToMultiByte(v24.localeinfo.locinfo->lc_codepage, 0, v5, -1, 0i64, 0, 0i64, &UsedDefaultChar);
    if ( !v22 || UsedDefaultChar )
      goto LABEL_51;
    v16 = v22 - 1i64;
  }
LABEL_54:
  if ( v24.updated )
    v24.ptd->_ownlocale &= 0xFFFFFFFD;
  return v16;
}

// File Line: 278
// RVA: 0x12B1DFC
unsigned __int64 __fastcall wcstombs(char *s, const wchar_t *pwcs, unsigned __int64 n)
{
  return wcstombs_l_helper(s, pwcs, n, 0i64);
}

// File Line: 315
// RVA: 0x12B1D10
__int64 __fastcall wcstombs_s_l(unsigned __int64 *pConvertedChars, char *dst, unsigned __int64 sizeInBytes, const wchar_t *src, unsigned __int64 n, localeinfo_struct *plocinfo)
{
  unsigned int v6; // er14
  unsigned __int64 v7; // rdi
  char *v8; // rbx
  unsigned __int64 *v9; // rsi
  unsigned __int64 v10; // r8
  unsigned __int64 v11; // rax
  int *v13; // rax
  unsigned int v14; // ebx
  unsigned __int64 v15; // rax

  v6 = 0;
  v7 = sizeInBytes;
  v8 = dst;
  v9 = pConvertedChars;
  if ( dst )
  {
    if ( sizeInBytes )
      goto LABEL_3;
LABEL_15:
    v13 = errno();
    v14 = 22;
LABEL_16:
    *v13 = v14;
    invalid_parameter_noinfo();
    return v14;
  }
  if ( sizeInBytes )
    goto LABEL_15;
LABEL_3:
  if ( dst )
    *dst = 0;
  if ( pConvertedChars )
    *pConvertedChars = 0i64;
  v10 = n;
  if ( n > v7 )
    v10 = v7;
  if ( v10 > 0x7FFFFFFF )
    goto LABEL_15;
  v11 = wcstombs_l_helper(dst, src, v10, plocinfo);
  if ( v11 == -1i64 )
  {
    if ( v8 )
      *v8 = 0;
    return (unsigned int)*errno();
  }
  v15 = v11 + 1;
  if ( v8 )
  {
    if ( v15 > v7 )
    {
      if ( n != -1i64 )
      {
        *v8 = 0;
        if ( v7 <= v15 )
        {
          v13 = errno();
          v14 = 34;
          goto LABEL_16;
        }
      }
      v15 = v7;
      v6 = 80;
    }
    v8[v15 - 1] = 0;
  }
  if ( v9 )
    *v9 = v15;
  return v6;
}

// File Line: 381
// RVA: 0x12B1E04
__int64 __fastcall wcstombs_s(unsigned __int64 *pConvertedChars, char *dst, unsigned __int64 sizeInBytes, const wchar_t *src, unsigned __int64 n)
{
  return wcstombs_s_l(pConvertedChars, dst, sizeInBytes, src, n, 0i64);
}

