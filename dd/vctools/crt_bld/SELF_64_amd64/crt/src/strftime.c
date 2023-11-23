// File Line: 188
// RVA: 0x12BC6A0
unsigned __int64 __fastcall strftime(char *string, unsigned __int64 maxsize, const char *format, tm *timeptr)
{
  return Strftime_l(string, maxsize, format, timeptr, 0i64, 0i64);
}

// File Line: 244
// RVA: 0x12BC4F8
unsigned __int64 __fastcall Strftime_l(
        char *string,
        unsigned __int64 maxsize,
        const char *format,
        tm *timeptr,
        void *lc_time_arg,
        localeinfo_struct *plocinfo)
{
  unsigned __int64 v10; // rbx
  wchar_t *v11; // rbp
  wchar_t *v12; // rdi
  int v13; // eax
  int cchWideChar; // r12d
  unsigned int v15; // eax
  wchar_t *lpWideCharStr; // rax
  const char *v17; // r8
  threadlocaleinfostruct *locinfo; // r14
  unsigned int LastError; // eax
  _LocaleUpdate v21; // [rsp+40h] [rbp-48h] BYREF

  v10 = 0i64;
  v11 = 0i64;
  v12 = 0i64;
  _LocaleUpdate::_LocaleUpdate(&v21, plocinfo);
  if ( !string || !maxsize || (*string = 0, !format) || !timeptr )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    goto LABEL_15;
  }
  v13 = MultiByteToWideChar(v21.localeinfo.locinfo->lc_time_cp, 0, format, -1, 0i64, 0);
  cchWideChar = v13;
  if ( v13 )
  {
    lpWideCharStr = (wchar_t *)malloc_crt(2i64 * v13);
    v11 = lpWideCharStr;
    if ( !lpWideCharStr )
      goto $error_cleanup;
    v17 = format;
    locinfo = v21.localeinfo.locinfo;
    if ( MultiByteToWideChar(v21.localeinfo.locinfo->lc_time_cp, 0, v17, -1, lpWideCharStr, cchWideChar) )
    {
      v12 = (wchar_t *)malloc_crt(2 * maxsize);
      if ( v12 )
      {
        v10 = Wcsftime_l(v12, maxsize, v11, timeptr, lc_time_arg, plocinfo);
        if ( v10 )
        {
          if ( !WideCharToMultiByte(locinfo->lc_time_cp, 0, v12, -1, string, maxsize, 0i64, 0i64) )
          {
            LastError = GetLastError();
            dosmaperr(LastError);
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
  if ( v21.updated )
    v21.ptd->_ownlocale &= ~2u;
  return v10;
}

