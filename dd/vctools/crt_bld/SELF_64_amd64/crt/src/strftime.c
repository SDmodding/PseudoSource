// File Line: 188
// RVA: 0x12BC6A0
unsigned __int64 __fastcall strftime(char *string, unsigned __int64 maxsize, const char *format, tm *timeptr)
{
  return Strftime_l(string, maxsize, format, timeptr, 0i64, 0i64);
}

// File Line: 244
// RVA: 0x12BC4F8
unsigned __int64 __fastcall Strftime_l(char *string, unsigned __int64 maxsize, const char *format, tm *timeptr, void *lc_time_arg, localeinfo_struct *plocinfo)
{
  unsigned __int64 v6; // rsi
  char *v7; // r15
  tm *v8; // r13
  const char *v9; // r14
  unsigned __int64 v10; // rbx
  wchar_t *v11; // rbp
  wchar_t *v12; // rdi
  int v13; // eax
  int cchWideChar; // er12
  unsigned int v15; // eax
  wchar_t *lpWideCharStr; // rax
  const char *v17; // r8
  __int64 v18; // r14
  unsigned int v19; // eax
  __int64 v21; // [rsp+40h] [rbp-48h]
  __int64 v22; // [rsp+50h] [rbp-38h]
  char v23; // [rsp+58h] [rbp-30h]

  v6 = maxsize;
  v7 = string;
  v8 = timeptr;
  v9 = format;
  v10 = 0i64;
  v11 = 0i64;
  v12 = 0i64;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&v21, plocinfo);
  if ( !v7 || !v6 || (*v7 = 0, !v9) || !v8 )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    goto LABEL_15;
  }
  v13 = MultiByteToWideChar(*(_DWORD *)(v21 + 12), 0, v9, -1, 0i64, 0);
  cchWideChar = v13;
  if ( v13 )
  {
    lpWideCharStr = (wchar_t *)malloc_crt(2i64 * v13);
    v11 = lpWideCharStr;
    if ( !lpWideCharStr )
      goto $error_cleanup;
    v17 = v9;
    v18 = v21;
    if ( MultiByteToWideChar(*(_DWORD *)(v21 + 12), 0, v17, -1, lpWideCharStr, cchWideChar) )
    {
      v12 = (wchar_t *)malloc_crt(2 * v6);
      if ( v12 )
      {
        v10 = Wcsftime_l(v12, v6, v11, v8, lc_time_arg, plocinfo);
        if ( v10 )
        {
          if ( !WideCharToMultiByte(*(_DWORD *)(v18 + 12), 0, v12, -1, v7, v6, 0i64, 0i64) )
          {
            v19 = GetLastError();
            dosmaperr(v19);
            v10 = 0i64;
          }
        }
      }
      goto $error_cleanup;
    }
  }
  v15 = GetLastError();
  dosmaperr(v15);
$error_cleanup:
  free(v12);
  free(v11);
LABEL_15:
  if ( v23 )
    *(_DWORD *)(v22 + 200) &= 0xFFFFFFFD;
  return v10;
}

