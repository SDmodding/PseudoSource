// File Line: 72
// RVA: 0x12C55B4
__int64 __fastcall _getlocaleinfo(
        localeinfo_struct *plocinfo,
        int lc_type,
        const wchar_t *localename,
        unsigned int fieldtype,
        void **address)
{
  char *v8; // rdi
  int v9; // r14d
  int LocaleInfoA; // r15d
  int v11; // eax
  int cchData; // r15d
  char *v13; // rax
  char *v14; // rcx
  int LocaleInfo; // eax
  int v17; // edi
  unsigned __int16 *v18; // rax
  unsigned __int16 v19[2]; // [rsp+30h] [rbp-D8h] BYREF
  char LCData[128]; // [rsp+40h] [rbp-C8h] BYREF

  if ( lc_type == 1 )
  {
    v8 = LCData;
    v9 = 0;
    LocaleInfoA = _crtGetLocaleInfoA(plocinfo, localename, fieldtype, LCData, 128);
    if ( !LocaleInfoA )
    {
      if ( GetLastError() != 122 )
        return 0xFFFFFFFFi64;
      v11 = _crtGetLocaleInfoA(plocinfo, localename, fieldtype, 0i64, 0);
      cchData = v11;
      if ( !v11 )
        return 0xFFFFFFFFi64;
      v13 = (char *)calloc_crt(v11, 1ui64);
      v8 = v13;
      if ( !v13 )
        return 0xFFFFFFFFi64;
      v9 = 1;
      LocaleInfoA = _crtGetLocaleInfoA(plocinfo, localename, fieldtype, v13, cchData);
      if ( !LocaleInfoA )
        goto LABEL_9;
    }
    v14 = (char *)calloc_crt(LocaleInfoA, 1ui64);
    *address = v14;
    if ( !v14 )
    {
      if ( !v9 )
        return 0xFFFFFFFFi64;
LABEL_9:
      free(v8);
      return 0xFFFFFFFFi64;
    }
    if ( (unsigned int)strncpy_s(v14, LocaleInfoA, v8, LocaleInfoA - 1) )
    {
      invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
      JUMPOUT(0x1412C5798i64);
    }
    if ( v9 )
      free(v8);
  }
  else if ( lc_type == 2 )
  {
    *address = 0i64;
    LocaleInfo = _crtGetLocaleInfoEx(localename, fieldtype, 0i64, 0);
    v17 = LocaleInfo;
    if ( !LocaleInfo
      || (v18 = (unsigned __int16 *)calloc_crt(LocaleInfo, 2ui64), (*address = v18) == 0i64)
      || !_crtGetLocaleInfoEx(localename, fieldtype, v18, v17) )
    {
      free(*address);
      *address = 0i64;
      return 0xFFFFFFFFi64;
    }
  }
  else
  {
    if ( lc_type )
      return 0xFFFFFFFFi64;
    *(_DWORD *)v19 = 0;
    if ( !_crtGetLocaleInfoEx(localename, fieldtype | 0x20000000, v19, 2) )
      return 0xFFFFFFFFi64;
    *(_BYTE *)address = v19[0];
  }
  return 0i64;
}

// File Line: 179
// RVA: 0x12C579C
void __fastcall initp_misc_purevirt(void *enull)
{
  _pPurecall = enull;
}

