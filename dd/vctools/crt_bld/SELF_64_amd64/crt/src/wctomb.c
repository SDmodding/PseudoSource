// File Line: 56
// RVA: 0x12C1B54
__int64 __fastcall wctomb_s_l(int *pRetValue, char *dst, unsigned __int64 sizeInBytes, wchar_t wchar, localeinfo_struct *plocinfo)
{
  unsigned __int64 cbMultiByte; // rdi
  char *lpMultiByteStr; // rsi
  int *v7; // rbx
  unsigned int v9; // ebx
  int v10; // eax
  _LocaleUpdate v11; // [rsp+40h] [rbp-28h]
  int UsedDefaultChar; // [rsp+78h] [rbp+10h]
  wchar_t WideCharStr; // [rsp+88h] [rbp+20h]

  WideCharStr = wchar;
  cbMultiByte = sizeInBytes;
  lpMultiByteStr = dst;
  v7 = pRetValue;
  if ( dst || !sizeInBytes )
  {
    if ( pRetValue )
      *pRetValue = -1;
    if ( sizeInBytes > 0x7FFFFFFF )
    {
      v9 = 22;
      *errno() = 22;
      invalid_parameter_noinfo();
      return v9;
    }
    _LocaleUpdate::_LocaleUpdate(&v11, plocinfo);
    if ( !v11.localeinfo.locinfo->locale_name[2] )
    {
      if ( WideCharStr > 0xFFu )
      {
        if ( lpMultiByteStr && cbMultiByte )
          memset(lpMultiByteStr, 0, cbMultiByte);
        goto LABEL_15;
      }
      if ( !lpMultiByteStr )
        goto LABEL_23;
      if ( cbMultiByte )
      {
        *lpMultiByteStr = WideCharStr;
LABEL_23:
        if ( v7 )
          *v7 = 1;
LABEL_29:
        v9 = 0;
        goto LABEL_16;
      }
LABEL_34:
      v9 = 34;
      *errno() = 34;
      invalid_parameter_noinfo();
LABEL_16:
      if ( v11.updated )
        v11.ptd->_ownlocale &= 0xFFFFFFFD;
      return v9;
    }
    UsedDefaultChar = 0;
    v10 = WideCharToMultiByte(
            v11.localeinfo.locinfo->lc_codepage,
            0,
            &WideCharStr,
            1,
            lpMultiByteStr,
            cbMultiByte,
            0i64,
            &UsedDefaultChar);
    if ( v10 )
    {
      if ( !UsedDefaultChar )
      {
        if ( v7 )
          *v7 = v10;
        goto LABEL_29;
      }
    }
    else if ( GetLastError() == 122 )
    {
      if ( lpMultiByteStr && cbMultiByte )
        memset(lpMultiByteStr, 0, cbMultiByte);
      goto LABEL_34;
    }
LABEL_15:
    *errno() = 42;
    v9 = *errno();
    goto LABEL_16;
  }
  if ( pRetValue )
    *pRetValue = 0;
  return 0i64;
}

// File Line: 144
// RVA: 0x12C1D34
__int64 __fastcall wctomb_s(int *pRetValue, char *dst, unsigned __int64 sizeInBytes, wchar_t wchar)
{
  return wctomb_s_l(pRetValue, dst, sizeInBytes, wchar, 0i64);
}

// File Line: 191
// RVA: 0x12C1CE0
__int64 __fastcall wctomb(char *s, wchar_t wchar)
{
  unsigned int v2; // esi
  wchar_t v3; // bx
  char *v4; // rdi
  int v5; // eax
  int pRetValue; // [rsp+50h] [rbp+18h]

  v2 = -1;
  v3 = wchar;
  v4 = s;
  pRetValue = -1;
  v5 = __mb_cur_max_func();
  if ( !(unsigned int)wctomb_s_l(&pRetValue, v4, v5, v3, 0i64) )
    v2 = pRetValue;
  return v2;
}

