// File Line: 72
// RVA: 0x12C55B4
signed __int64 __fastcall _getlocaleinfo(localeinfo_struct *plocinfo, int lc_type, const wchar_t *localename, unsigned int fieldtype, void *address)
{
  unsigned int v5; // esi
  const wchar_t *v6; // rbp
  localeinfo_struct *v7; // r12
  char *v8; // rdi
  signed int v9; // er14
  int v10; // er15
  int v11; // eax
  int cchData; // er15
  char *v13; // rax
  char *v14; // rcx
  int v16; // eax
  int v17; // edi
  unsigned __int16 *v18; // rax
  unsigned __int16 v19[2]; // [rsp+30h] [rbp-D8h]
  char LCData; // [rsp+40h] [rbp-C8h]

  v5 = fieldtype;
  v6 = localename;
  v7 = plocinfo;
  if ( lc_type == 1 )
  {
    v8 = &LCData;
    v9 = 0;
    v10 = _crtGetLocaleInfoA(plocinfo, localename, fieldtype, &LCData, 128);
    if ( !v10 )
    {
      if ( GetLastError() != 122 )
        return 0xFFFFFFFFi64;
      v11 = _crtGetLocaleInfoA(v7, v6, v5, 0i64, 0);
      cchData = v11;
      if ( !v11 )
        return 0xFFFFFFFFi64;
      v13 = (char *)calloc_crt(v11, 1ui64);
      v8 = v13;
      if ( !v13 )
        return 0xFFFFFFFFi64;
      v9 = 1;
      v10 = _crtGetLocaleInfoA(v7, v6, v5, v13, cchData);
      if ( !v10 )
        goto LABEL_9;
    }
    v14 = (char *)calloc_crt(v10, 1ui64);
    *(_QWORD *)address = v14;
    if ( !v14 )
    {
      if ( !v9 )
        return 0xFFFFFFFFi64;
LABEL_9:
      free(v8);
      return 0xFFFFFFFFi64;
    }
    if ( (unsigned int)strncpy_s(v14, v10, v8, v10 - 1) )
    {
      invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
      JUMPOUT(*(_QWORD *)&byte_1412C5798);
    }
    if ( v9 )
      free(v8);
  }
  else if ( lc_type == 2 )
  {
    *(_QWORD *)address = 0i64;
    v16 = _crtGetLocaleInfoEx(localename, fieldtype, 0i64, 0);
    v17 = v16;
    if ( !v16
      || (v18 = (unsigned __int16 *)calloc_crt(v16, 2ui64), (*(_QWORD *)address = v18) == 0i64)
      || !_crtGetLocaleInfoEx(v6, v5, v18, v17) )
    {
      free(*(void **)address);
      *(_QWORD *)address = 0i64;
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

