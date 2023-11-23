// File Line: 266
// RVA: 0x12D5488
__int64 __fastcall Wcsftime_l(
        wchar_t *string,
        unsigned __int64 maxsize,
        const wchar_t *format,
        tm *timeptr,
        __lc_time_data *lc_time_arg,
        localeinfo_struct *plocinfo)
{
  int v10; // r14d
  __lc_time_data *lc_time; // rsi
  unsigned __int64 v12; // rax
  wchar_t *v13; // rcx
  int v14; // edx
  const wchar_t *v15; // rdi
  unsigned int alternate_form; // eax
  __int64 v17; // rbx
  unsigned __int64 left; // [rsp+40h] [rbp-30h] BYREF
  _LocaleUpdate v20; // [rsp+48h] [rbp-28h] BYREF
  wchar_t *stringa; // [rsp+A0h] [rbp+30h] BYREF

  stringa = string;
  v10 = 0;
  _LocaleUpdate::_LocaleUpdate(&v20, plocinfo);
  if ( !stringa )
    goto LABEL_24;
  if ( !maxsize )
    goto LABEL_24;
  *stringa = 0;
  if ( !format )
    goto LABEL_24;
  lc_time = lc_time_arg;
  if ( !lc_time_arg )
    lc_time = v20.localeinfo.locinfo->lc_time_curr;
  v12 = maxsize;
  left = maxsize;
  v13 = stringa;
  do
  {
    v14 = *format;
    if ( !*format )
      break;
    if ( v14 == 37 )
    {
      if ( !timeptr )
        goto LABEL_24;
      v15 = format + 1;
      alternate_form = 0;
      if ( *v15 == 35 )
      {
        alternate_form = 1;
        ++v15;
      }
      if ( !W_expandtime(&v20.localeinfo, *v15, timeptr, &stringa, &left, lc_time, alternate_form) )
      {
        if ( left )
          v10 = 1;
        goto $done_7;
      }
      v13 = stringa;
      v12 = left;
      format = v15 + 1;
    }
    else
    {
      *v13 = v14;
      v13 = stringa + 1;
      ++format;
      v12 = --left;
      ++stringa;
    }
  }
  while ( v12 );
  if ( v12 )
  {
    *v13 = 0;
    v17 = maxsize - left;
    goto LABEL_26;
  }
$done_7:
  *string = 0;
  if ( !v10 && !left )
  {
    *errno() = 34;
  }
  else
  {
LABEL_24:
    *errno() = 22;
    invalid_parameter_noinfo();
  }
  v17 = 0i64;
LABEL_26:
  if ( v20.updated )
    v20.ptd->_ownlocale &= ~2u;
  return v17;
}

// File Line: 450
// RVA: 0x12D4864
_BOOL8 __fastcall W_expandtime(
        localeinfo_struct *plocinfo,
        wchar_t specifier,
        tm *timeptr,
        wchar_t **string,
        unsigned __int64 *left,
        __lc_time_data *lc_time,
        unsigned int alternate_form)
{
  wchar_t **v7; // rdi
  tm *v8; // rsi
  localeinfo_struct *v9; // rbp
  unsigned int tm_wday; // ecx
  bool v11; // cc
  wchar_t *v12; // rdx
  wchar_t v13; // r8
  bool v14; // zf
  wchar_t *v15; // rdx
  wchar_t v16; // r8
  int tm_hour; // ecx
  int v18; // ecx
  int v19; // ebx
  unsigned int v20; // eax
  int v21; // r8d
  int v22; // r8d
  int v23; // edx
  unsigned int tm_yday; // ecx
  int v25; // edx
  wchar_t *v26; // rdx
  wchar_t v27; // r8
  wchar_t *v29; // rdx
  wchar_t v30; // r8
  unsigned int tm_mon; // ecx
  char **v32; // rax
  unsigned __int64 v33; // rcx
  int tm_year; // ecx
  wchar_t *v35; // rdx
  wchar_t v36; // r8
  wchar_t *v37; // r8
  wchar_t v38; // r9
  unsigned __int64 *no_lead_zeros; // [rsp+20h] [rbp-38h]
  __lc_time_data *v40; // [rsp+28h] [rbp-30h]
  unsigned __int64 pConvertedChars[5]; // [rsp+30h] [rbp-28h] BYREF

  v7 = string;
  v8 = timeptr;
  v9 = plocinfo;
  if ( specifier > 0x59u )
  {
    if ( specifier > 0x6Du )
    {
      switch ( specifier )
      {
        case p:
          if ( timeptr->tm_hour <= 0x17u )
          {
            if ( timeptr->tm_hour > 11 )
            {
              v37 = lc_time->_W_ampm[1];
              if ( *left )
              {
                do
                {
                  v38 = *v37;
                  if ( !*v37 )
                    break;
                  ++v37;
                  *(*v7)++ = v38;
                  v14 = (*left)-- == 1;
                }
                while ( !v14 );
              }
            }
            else
            {
              v35 = lc_time->_W_ampm[0];
              if ( *left )
              {
                do
                {
                  v36 = *v35;
                  if ( !*v35 )
                    break;
                  ++v35;
                  *(*string)++ = v36;
                  v14 = (*left)-- == 1;
                }
                while ( !v14 );
              }
            }
            return 1i64;
          }
          goto LABEL_75;
        case w:
          if ( timeptr->tm_wday <= 6u )
          {
            tm_wday = timeptr->tm_wday;
            v23 = 1;
            goto LABEL_62;
          }
          goto LABEL_75;
        case x:
          v40 = lc_time;
          no_lead_zeros = left;
          v25 = alternate_form != 0;
          return W_store_winword(plocinfo, v25, timeptr, string, no_lead_zeros, v40) != 0;
        case y:
          tm_year = timeptr->tm_year;
          if ( tm_year < 0 )
            goto LABEL_75;
          tm_wday = tm_year % 100;
          goto LABEL_61;
      }
      if ( specifier != 122 )
        return 0i64;
    }
    else
    {
      if ( specifier == 109 )
      {
        tm_mon = timeptr->tm_mon;
        if ( tm_mon > 0xB )
          goto LABEL_75;
        tm_wday = tm_mon + 1;
        goto LABEL_61;
      }
      if ( specifier != 90 )
      {
        switch ( specifier )
        {
          case a:
            if ( timeptr->tm_wday <= 6u )
            {
              v29 = lc_time->_W_wday_abbr[timeptr->tm_wday];
              if ( *left )
              {
                do
                {
                  v30 = *v29;
                  if ( !*v29 )
                    break;
                  ++v29;
                  *(*string)++ = v30;
                  v14 = (*left)-- == 1;
                }
                while ( !v14 );
              }
              return 1i64;
            }
            goto LABEL_75;
          case b:
            if ( timeptr->tm_mon <= 0xBu )
            {
              v26 = lc_time->_W_month_abbr[timeptr->tm_mon];
              if ( *left )
              {
                do
                {
                  v27 = *v26;
                  if ( !*v26 )
                    break;
                  ++v26;
                  *(*string)++ = v27;
                  v14 = (*left)-- == 1;
                }
                while ( !v14 );
              }
              return 1i64;
            }
            goto LABEL_75;
          case c:
            if ( !W_store_winword(plocinfo, alternate_form != 0, timeptr, string, left, lc_time) || !*left )
              return 0i64;
            v40 = lc_time;
            *(*v7)++ = 32;
            --*left;
            no_lead_zeros = left;
            string = v7;
            timeptr = v8;
LABEL_66:
            v25 = 2;
            plocinfo = v9;
            return W_store_winword(plocinfo, v25, timeptr, string, no_lead_zeros, v40) != 0;
          case d:
            tm_wday = timeptr->tm_mday;
            if ( tm_wday - 1 > 0x1E )
              goto LABEL_75;
            goto LABEL_61;
        }
        if ( specifier != 106 )
          return 0i64;
        tm_yday = timeptr->tm_yday;
        if ( tm_yday > 0x16D )
          goto LABEL_75;
        tm_wday = tm_yday + 1;
        v23 = 3;
LABEL_62:
        W_store_num(tm_wday, v23, string, left, alternate_form);
        return 1i64;
      }
    }
    _tzset();
    pConvertedChars[0] = 0i64;
    v32 = _tzname();
    if ( (unsigned int)mbstowcs_s_l(pConvertedChars, *v7, *left, v32[v8->tm_isdst != 0], 0xFFFFFFFFFFFFFFFFui64, v9) )
    {
      invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
      JUMPOUT(0x1412D4EB9i64);
    }
    v33 = pConvertedChars[0];
    *v7 += pConvertedChars[0] - 1;
    *left += 1 - v33;
    return 1i64;
  }
  if ( specifier == 89 )
  {
    v22 = timeptr->tm_year;
    if ( (unsigned int)(v22 + 1900) > 0x270F )
      goto LABEL_75;
    v23 = 4;
    tm_wday = v22 % 100 + 100 * (v22 / 100 + 19);
    goto LABEL_62;
  }
  if ( specifier > 0x49u )
  {
    if ( specifier == 77 )
    {
      tm_wday = timeptr->tm_min;
      v11 = tm_wday <= 0x3B;
LABEL_12:
      if ( !v11 )
        goto LABEL_75;
      goto LABEL_61;
    }
    v18 = 6;
    if ( specifier == 83 )
    {
      if ( timeptr->tm_sec > 0x3Bu )
        goto LABEL_75;
      tm_wday = timeptr->tm_sec;
      goto LABEL_61;
    }
    v19 = 0;
    switch ( specifier )
    {
      case U:
        if ( timeptr->tm_wday > 6u )
          goto LABEL_75;
        v18 = timeptr->tm_wday;
        break;
      case W:
        v20 = timeptr->tm_wday;
        if ( v20 > 6 )
          goto LABEL_75;
        if ( v20 )
          v18 = v20 - 1;
        break;
      case X:
        v40 = lc_time;
        no_lead_zeros = left;
        goto LABEL_66;
      default:
        return 0i64;
    }
    v21 = timeptr->tm_yday;
    if ( (unsigned int)v21 > 0x16D )
      goto LABEL_75;
    if ( v21 >= v18 )
    {
      v19 = v21 / 7;
      if ( v21 % 7 >= v18 )
        ++v19;
    }
    tm_wday = v19;
    goto LABEL_61;
  }
  if ( specifier == 73 )
  {
    tm_hour = timeptr->tm_hour;
    if ( (unsigned int)tm_hour > 0x17 )
      goto LABEL_75;
    tm_wday = tm_hour % 12;
    if ( !tm_wday )
      tm_wday = 12;
LABEL_61:
    v23 = 2;
    goto LABEL_62;
  }
  if ( specifier == 4 || specifier == 13 )
    return 1i64;
  if ( specifier != 37 )
  {
    switch ( specifier )
    {
      case A:
        if ( timeptr->tm_wday <= 6u )
        {
          v15 = lc_time->_W_wday[timeptr->tm_wday];
          if ( *left )
          {
            do
            {
              v16 = *v15;
              if ( !*v15 )
                break;
              ++v15;
              *(*string)++ = v16;
              v14 = (*left)-- == 1;
            }
            while ( !v14 );
          }
          return 1i64;
        }
        break;
      case B:
        if ( timeptr->tm_mon <= 0xBu )
        {
          v12 = lc_time->_W_month[timeptr->tm_mon];
          if ( *left )
          {
            do
            {
              v13 = *v12;
              if ( !*v12 )
                break;
              ++v12;
              *(*string)++ = v13;
              v14 = (*left)-- == 1;
            }
            while ( !v14 );
          }
          return 1i64;
        }
        break;
      case H:
        tm_wday = timeptr->tm_hour;
        v11 = tm_wday <= 0x17;
        goto LABEL_12;
      default:
        return 0i64;
    }
LABEL_75:
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0i64;
  }
  *(*string)++ = 37;
  --*left;
  return 1i64;
}

// File Line: 818
// RVA: 0x12D4EBC
void __fastcall W_store_num(int num, int digits, wchar_t **out, unsigned __int64 *count, unsigned int no_lead_zeros)
{
  int v5; // ebx
  wchar_t *v7; // r10
  wchar_t *v8; // rdx
  wchar_t *v9; // r10
  wchar_t v10; // cx
  int v11; // edx
  int v12; // r10d
  __int64 v13; // rdi

  v5 = 0;
  if ( no_lead_zeros )
  {
    v7 = *out;
    do
    {
      if ( *count <= 1 )
        break;
      *v7 = num % 10 + 48;
      --*count;
      ++v7;
      num /= 10;
    }
    while ( num > 0 );
    v8 = *out;
    *out = v7;
    v9 = v7 - 1;
    do
    {
      v10 = *v9;
      *v9 = *v8;
      *v8++ = v10;
      --v9;
    }
    while ( v8 < v9 );
  }
  else if ( digits >= *count )
  {
    *count = 0i64;
  }
  else
  {
    v11 = digits - 1;
    v12 = v11 + 1;
    if ( v11 != -1 )
    {
      v13 = v11;
      do
      {
        ++v5;
        (*out)[v13] = num % 10 + 48;
        num /= 10;
        --v13;
        --v12;
      }
      while ( v12 );
    }
    *out += v5;
    *count -= v5;
  }
}

// File Line: 944
// RVA: 0x12D4FB4
__int64 __fastcall W_store_winword(
        localeinfo_struct *plocinfo,
        int field_code,
        tm *tmptr,
        wchar_t **out,
        unsigned __int64 *count,
        __lc_time_data *lc_time)
{
  unsigned __int16 *v6; // r11
  __int64 v7; // r8
  localeinfo_struct *v9; // r14
  wchar_t *W_ww_ldatefmt; // rdi
  unsigned __int16 v11; // ax
  int v12; // r14d
  wchar_t *W_ww_locale_name; // rcx
  unsigned __int16 v14; // ax
  int TimeFormat; // eax
  int v16; // esi
  unsigned __int64 v17; // rcx
  __int64 v18; // rax
  void *v19; // rsp
  unsigned __int16 *p_timeptr; // rbx
  unsigned __int16 *v21; // rax
  wchar_t *v22; // rcx
  int DateFormat; // eax
  unsigned __int16 *v24; // r8
  int i; // edx
  wchar_t v26; // ax
  unsigned int alternate_form; // ebx
  int v29; // ecx
  wchar_t *v30; // rsi
  wchar_t v31; // ax
  int v32; // ecx
  int v33; // ecx
  int v34; // ecx
  int v35; // ecx
  wchar_t v36; // cx
  int v37; // ecx
  int v38; // ecx
  int v39; // ecx
  wchar_t *v40; // rdx
  wchar_t v41; // cx
  int v42; // ecx
  int v43; // ecx
  int v44; // ecx
  BOOL v45; // eax
  wchar_t v46; // r9
  __int64 v47; // [rsp+0h] [rbp-40h] BYREF
  unsigned __int16 *lpTimeStr; // [rsp+20h] [rbp-20h]
  int cchTime[2]; // [rsp+28h] [rbp-18h]
  tm *timeptr; // [rsp+40h] [rbp+0h] BYREF
  localeinfo_struct *v51; // [rsp+48h] [rbp+8h]
  _SYSTEMTIME Time; // [rsp+50h] [rbp+10h] BYREF

  v6 = (unsigned __int16 *)tmptr;
  timeptr = tmptr;
  v7 = 0i64;
  v9 = plocinfo;
  v51 = plocinfo;
  if ( field_code )
  {
    if ( field_code == 1 )
      W_ww_ldatefmt = lc_time->_W_ww_ldatefmt;
    else
      W_ww_ldatefmt = lc_time->_W_ww_timefmt;
  }
  else
  {
    W_ww_ldatefmt = lc_time->_W_ww_sdatefmt;
  }
  if ( lc_time->ww_caltype == 1 )
    goto LABEL_113;
  v11 = v6[10];
  v12 = 1;
  cchTime[0] = 0;
  Time.wMilliseconds = 0;
  if ( field_code != 2 )
    v12 = 0;
  W_ww_locale_name = lc_time->_W_ww_locale_name;
  Time.wYear = v11 + 1900;
  v14 = v6[8] + 1;
  lpTimeStr = 0i64;
  Time.wMonth = v14;
  Time.wDay = v6[6];
  Time.wHour = v6[4];
  Time.wMinute = v6[2];
  Time.wSecond = *v6;
  if ( v12 )
    TimeFormat = _crtGetTimeFormatEx(W_ww_locale_name, 0, &Time, W_ww_ldatefmt, lpTimeStr, cchTime[0]);
  else
    TimeFormat = _crtGetDateFormatEx(W_ww_locale_name, 0, &Time, W_ww_ldatefmt, lpTimeStr, cchTime[0]);
  v7 = 0i64;
  v16 = TimeFormat;
  if ( !TimeFormat )
    goto LABEL_32;
  v17 = 2i64 * TimeFormat + 16;
  if ( v17 > 0x400 )
  {
    v21 = (unsigned __int16 *)malloc(v17);
    v7 = 0i64;
    p_timeptr = v21;
    if ( !v21 )
      goto LABEL_21;
    *(_DWORD *)v21 = 56797;
  }
  else
  {
    v18 = 2i64 * TimeFormat + 31;
    if ( v17 + 15 <= v17 )
      v18 = 0xFFFFFFFFFFFFFF0i64;
    v19 = alloca(v18 & 0xFFFFFFFFFFFFFFF0ui64);
    p_timeptr = (unsigned __int16 *)&timeptr;
    if ( &v47 == (__int64 *)-64i64 )
      goto LABEL_32;
    LODWORD(timeptr) = 52428;
  }
  p_timeptr += 8;
LABEL_21:
  if ( !p_timeptr )
  {
LABEL_32:
    v9 = v51;
    while ( 1 )
    {
      while ( 1 )
      {
        v6 = (unsigned __int16 *)timeptr;
LABEL_113:
        v46 = *W_ww_ldatefmt;
        if ( !*W_ww_ldatefmt || !*count )
          return 1i64;
        alternate_form = 0;
        v29 = 0;
        v30 = W_ww_ldatefmt;
        do
        {
          ++v30;
          ++v29;
          ++v7;
        }
        while ( *v30 == v46 );
        v31 = 100;
        if ( v46 > 0x64u )
          break;
        switch ( v46 )
        {
          case d:
            v37 = v29 - 1;
            if ( !v37 )
            {
              alternate_form = 1;
              goto LABEL_110;
            }
            v38 = v37 - 1;
            if ( !v38 )
              goto LABEL_110;
            v39 = v38 - 1;
            if ( !v39 )
            {
              v31 = 97;
              goto LABEL_110;
            }
            if ( v39 == 1 )
            {
              v31 = 65;
              goto LABEL_110;
            }
LABEL_107:
            ++W_ww_ldatefmt;
            *(*out)++ = v46;
            --*count;
LABEL_68:
            v7 = 0i64;
            break;
          case \:
            if ( (v29 & 1) == 0 )
            {
              W_ww_ldatefmt += v29;
              goto LABEL_68;
            }
            W_ww_ldatefmt += v7;
            v7 = 0i64;
            v36 = *W_ww_ldatefmt;
            if ( !*W_ww_ldatefmt )
              return 1i64;
            do
            {
              if ( !*count )
                break;
              ++W_ww_ldatefmt;
              if ( v36 == 39 )
                break;
              *(*out)++ = v36;
              --*count;
              v36 = *W_ww_ldatefmt;
            }
            while ( *W_ww_ldatefmt );
            break;
          case A:
LABEL_43:
            if ( wcsicmp(W_ww_ldatefmt, L"am/pm") )
            {
              if ( !wcsicmp(W_ww_ldatefmt, L"a/p") )
                v30 = W_ww_ldatefmt + 3;
            }
            else
            {
              v30 = W_ww_ldatefmt + 5;
            }
            v31 = 112;
LABEL_110:
            v45 = W_expandtime(v9, v31, timeptr, out, count, lc_time, alternate_form);
            v7 = 0i64;
            if ( !v45 )
              return 0i64;
            W_ww_ldatefmt = v30;
            break;
          case H:
            v35 = v29 - 1;
            if ( !v35 )
            {
              alternate_form = 1;
LABEL_57:
              v31 = 72;
              goto LABEL_110;
            }
            if ( v35 == 1 )
              goto LABEL_57;
            break;
          case M:
            v32 = v29 - 1;
            if ( !v32 )
            {
              alternate_form = 1;
LABEL_52:
              v31 = 109;
              goto LABEL_110;
            }
            v33 = v32 - 1;
            if ( !v33 )
              goto LABEL_52;
            v34 = v33 - 1;
            if ( !v34 )
            {
              v31 = 98;
              goto LABEL_110;
            }
            if ( v34 == 1 )
            {
              v31 = 66;
              goto LABEL_110;
            }
            break;
          case a:
            goto LABEL_43;
          default:
            goto LABEL_107;
        }
      }
      switch ( v46 )
      {
        case h:
          v44 = v29 - 1;
          if ( !v44 )
          {
            alternate_form = 1;
LABEL_109:
            v31 = 73;
            goto LABEL_110;
          }
          if ( v44 == 1 )
            goto LABEL_109;
          goto LABEL_107;
        case m:
          v43 = v29 - 1;
          if ( !v43 )
          {
            alternate_form = 1;
LABEL_104:
            v31 = 77;
            goto LABEL_110;
          }
          if ( v43 == 1 )
            goto LABEL_104;
          goto LABEL_107;
        case s:
          v42 = v29 - 1;
          if ( !v42 )
          {
            alternate_form = 1;
LABEL_99:
            v31 = 83;
            goto LABEL_110;
          }
          if ( v42 == 1 )
            goto LABEL_99;
          goto LABEL_107;
      }
      if ( v46 != 116 )
      {
        if ( v46 == 121 )
        {
          if ( v29 == 2 )
          {
            v31 = 121;
            goto LABEL_110;
          }
          if ( v29 == 4 )
          {
            v31 = 89;
            goto LABEL_110;
          }
        }
        goto LABEL_107;
      }
      if ( *((int *)v6 + 2) > 11 )
        v40 = lc_time->_W_ampm[1];
      else
        v40 = lc_time->_W_ampm[0];
      v7 = 0i64;
      if ( v29 == 1 && *count )
      {
        *(*out)++ = *v40;
        --*count;
      }
      else
      {
        while ( 1 )
        {
          v41 = *v40;
          if ( !*v40 || !*count )
            break;
          ++v40;
          *(*out)++ = v41;
          --*count;
        }
      }
      W_ww_ldatefmt = v30;
    }
  }
  v22 = lc_time->_W_ww_locale_name;
  cchTime[0] = v16;
  lpTimeStr = p_timeptr;
  if ( v12 )
    DateFormat = _crtGetTimeFormatEx(v22, 0, &Time, W_ww_ldatefmt, lpTimeStr, cchTime[0]);
  else
    DateFormat = _crtGetDateFormatEx(v22, 0, &Time, W_ww_ldatefmt, lpTimeStr, cchTime[0]);
  v24 = p_timeptr;
  for ( i = DateFormat - 1; i > 0 && *count; --i )
  {
    v26 = *v24++;
    *(*out)++ = v26;
    --*count;
  }
  if ( *((_DWORD *)p_timeptr - 4) == 56797 )
    free(p_timeptr - 8);
  return 1i64;
}

