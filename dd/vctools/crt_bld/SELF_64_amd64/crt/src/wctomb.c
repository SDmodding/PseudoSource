// File Line: 56
// RVA: 0x12C1B54
__int64 __fastcall wctomb_s_l(
        int *pRetValue,
        char *dst,
        size_t sizeInBytes,
        wchar_t wchar,
        localeinfo_struct *plocinfo)
{
  unsigned int v9; // ebx
  int v10; // eax
  _LocaleUpdate v11; // [rsp+40h] [rbp-28h] BYREF
  int UsedDefaultChar; // [rsp+78h] [rbp+10h] BYREF
  wchar_t WideCharStr; // [rsp+88h] [rbp+20h] BYREF

  WideCharStr = wchar;
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
        if ( dst && sizeInBytes )
          memset(dst, 0, sizeInBytes);
        goto LABEL_15;
      }
      if ( !dst )
        goto LABEL_22;
      if ( sizeInBytes )
      {
        *dst = WideCharStr;
LABEL_22:
        if ( pRetValue )
          *pRetValue = 1;
LABEL_28:
        v9 = 0;
        goto LABEL_16;
      }
LABEL_33:
      v9 = 34;
      *errno() = 34;
      invalid_parameter_noinfo();
LABEL_16:
      if ( v11.updated )
        v11.ptd->_ownlocale &= ~2u;
      return v9;
    }
    UsedDefaultChar = 0;
    v10 = WideCharToMultiByte(
            v11.localeinfo.locinfo->lc_codepage,
            0,
            &WideCharStr,
            1,
            dst,
            sizeInBytes,
            0i64,
            &UsedDefaultChar);
    if ( v10 )
    {
      if ( !UsedDefaultChar )
      {
        if ( pRetValue )
          *pRetValue = v10;
        goto LABEL_28;
      }
    }
    else if ( GetLastError() == 122 )
    {
      if ( dst && sizeInBytes )
        memset(dst, 0, sizeInBytes);
      goto LABEL_33;
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
__int64 __fastcall wctomb_s(int *pRetValue, char *dst, size_t sizeInBytes, wchar_t wchar)
{
  return wctomb_s_l(pRetValue, dst, sizeInBytes, wchar, 0i64);
}

// File Line: 191
// RVA: 0x12C1CE0
__int64 __fastcall wctomb(char *s, wchar_t wchar)
{
  unsigned int v2; // esi
  int v5; // eax
  int pRetValue; // [rsp+50h] [rbp+18h] BYREF

  v2 = -1;
  pRetValue = -1;
  v5 = __mb_cur_max_func();
  if ( !(unsigned int)wctomb_s_l(&pRetValue, s, v5, wchar, 0i64) )
    return (unsigned int)pRetValue;
  return v2;
}

