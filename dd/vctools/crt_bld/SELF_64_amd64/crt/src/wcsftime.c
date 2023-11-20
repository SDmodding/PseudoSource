// File Line: 266
// RVA: 0x12D5488
unsigned __int64 __fastcall Wcsftime_l(wchar_t *string, unsigned __int64 maxsize, const wchar_t *format, tm *timeptr, void *lc_time_arg, localeinfo_struct *plocinfo)
{
  unsigned __int64 v6; // rbx
  wchar_t *v7; // r15
  tm *v8; // r12
  const wchar_t *v9; // rdi
  signed int v10; // er14
  __lc_time_data *lc_time; // rsi
  unsigned __int64 v12; // rax
  wchar_t *v13; // rcx
  int v14; // edx
  wchar_t *v15; // rdi
  unsigned int alternate_form; // eax
  unsigned __int64 v17; // rbx
  unsigned __int64 left; // [rsp+40h] [rbp-30h]
  _LocaleUpdate v20; // [rsp+48h] [rbp-28h]
  wchar_t *stringa; // [rsp+A0h] [rbp+30h]

  stringa = string;
  v6 = maxsize;
  v7 = string;
  v8 = timeptr;
  v9 = format;
  v10 = 0;
  _LocaleUpdate::_LocaleUpdate(&v20, plocinfo);
  if ( !stringa )
    goto LABEL_24;
  if ( !v6 )
    goto LABEL_24;
  *stringa = 0;
  if ( !v9 )
    goto LABEL_24;
  lc_time = (__lc_time_data *)lc_time_arg;
  if ( !lc_time_arg )
    lc_time = v20.localeinfo.locinfo->lc_time_curr;
  v12 = v6;
  left = v6;
  if ( !v6 )
  {
$done_7:
    *v7 = 0;
    if ( !v10 && left <= 0 )
    {
      *errno() = 34;
LABEL_25:
      v17 = 0i64;
      goto LABEL_26;
    }
LABEL_24:
    *errno() = 22;
    invalid_parameter_noinfo();
    goto LABEL_25;
  }
  v13 = stringa;
  do
  {
    v14 = *v9;
    if ( !*v9 )
      break;
    if ( v14 == 37 )
    {
      if ( !v8 )
        goto LABEL_24;
      v15 = (wchar_t *)(v9 + 1);
      alternate_form = 0;
      if ( *v15 == 35 )
      {
        alternate_form = 1;
        ++v15;
      }
      if ( !(unsigned int)W_expandtime(&v20.localeinfo, *v15, v8, &stringa, &left, lc_time, alternate_form) )
      {
        if ( left > 0 )
          v10 = 1;
        goto $done_7;
      }
      v13 = stringa;
      v12 = left;
      v9 = v15 + 1;
    }
    else
    {
      *v13 = v14;
      v13 = stringa + 1;
      ++v9;
      v12 = left-- - 1;
      ++stringa;
    }
  }
  while ( v12 );
  if ( !v12 )
    goto $done_7;
  *v13 = 0;
  v17 = v6 - left;
LABEL_26:
  if ( v20.updated )
    v20.ptd->_ownlocale &= 0xFFFFFFFD;
  return v17;
}

// File Line: 450
// RVA: 0x12D4864
signed __int64 __fastcall W_expandtime(localeinfo_struct *plocinfo, wchar_t specifier, tm *timeptr, wchar_t **string, unsigned __int64 *left, __lc_time_data *lc_time, unsigned int alternate_form)
{
  wchar_t **v7; // rdi
  tm *v8; // rsi
  localeinfo_struct *v9; // rbp
  unsigned int v10; // ecx
  bool v11; // cf
  bool v12; // zf
  wchar_t *v13; // rdx
  wchar_t v14; // r8
  wchar_t *v15; // rdx
  wchar_t v16; // r8
  int v17; // ecx
  int v18; // ecx
  int v19; // ebx
  unsigned int v20; // eax
  int v21; // er8
  int v22; // er8
  int v23; // edx
  unsigned int v24; // ecx
  int v25; // edx
  wchar_t *v26; // rdx
  wchar_t v27; // r8
  wchar_t *v29; // rdx
  wchar_t v30; // r8
  unsigned int v31; // ecx
  char **v32; // rax
  unsigned __int64 v33; // rcx
  int v34; // ecx
  wchar_t *v35; // rdx
  wchar_t v36; // r8
  wchar_t *v37; // r8
  wchar_t v38; // r9
  unsigned __int64 *no_lead_zeros; // [rsp+20h] [rbp-38h]
  __lc_time_data *v40; // [rsp+28h] [rbp-30h]
  unsigned __int64 pConvertedChars; // [rsp+30h] [rbp-28h]

  v7 = string;
  v8 = timeptr;
  v9 = plocinfo;
  if ( (signed int)specifier > 89 )
  {
    if ( (signed int)specifier > 109 )
    {
      switch ( specifier )
      {
        case 0x70u:
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
                  **v7 = v38;
                  ++*v7;
                  v12 = (*left)-- == 1;
                }
                while ( !v12 );
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
                  **string = v36;
                  ++*string;
                  v12 = (*left)-- == 1;
                }
                while ( !v12 );
              }
            }
            return 1i64;
          }
          goto LABEL_75;
        case 0x77u:
          if ( timeptr->tm_wday <= 6u )
          {
            v10 = timeptr->tm_wday;
            v23 = 1;
            goto LABEL_62;
          }
          goto LABEL_75;
        case 0x78u:
          v40 = lc_time;
          no_lead_zeros = left;
          v25 = alternate_form != 0;
LABEL_67:
          if ( !W_store_winword(plocinfo, v25, timeptr, string, no_lead_zeros, v40) )
            return 0i64;
          return 1i64;
        case 0x79u:
          v34 = timeptr->tm_year;
          if ( v34 < 0 )
            goto LABEL_75;
          v10 = v34 % 100;
          goto LABEL_61;
      }
      if ( specifier != 122 )
        return 0i64;
    }
    else
    {
      if ( specifier == 109 )
      {
        v31 = timeptr->tm_mon;
        if ( v31 > 0xB )
          goto LABEL_75;
        v10 = v31 + 1;
        goto LABEL_61;
      }
      if ( specifier != 90 )
      {
        switch ( specifier )
        {
          case 0x61u:
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
                  **string = v30;
                  ++*string;
                  v12 = (*left)-- == 1;
                }
                while ( !v12 );
              }
              return 1i64;
            }
            goto LABEL_75;
          case 0x62u:
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
                  **string = v27;
                  ++*string;
                  v12 = (*left)-- == 1;
                }
                while ( !v12 );
              }
              return 1i64;
            }
            goto LABEL_75;
          case 0x63u:
            if ( !W_store_winword(plocinfo, alternate_form != 0, timeptr, string, left, lc_time) || !*left )
              return 0i64;
            v40 = lc_time;
            **v7 = 32;
            ++*v7;
            --*left;
            no_lead_zeros = left;
            string = v7;
            timeptr = v8;
LABEL_66:
            v25 = 2;
            plocinfo = v9;
            goto LABEL_67;
          case 0x64u:
            v10 = timeptr->tm_mday;
            if ( v10 - 1 > 0x1E )
              goto LABEL_75;
            goto LABEL_61;
        }
        if ( specifier != 106 )
          return 0i64;
        v24 = timeptr->tm_yday;
        if ( v24 > 0x16D )
          goto LABEL_75;
        v10 = v24 + 1;
        v23 = 3;
LABEL_62:
        W_store_num(v10, v23, string, left, alternate_form);
        return 1i64;
      }
    }
    _tzset();
    pConvertedChars = 0i64;
    v32 = _tzname();
    if ( (unsigned int)mbstowcs_s_l(&pConvertedChars, *v7, *left, v32[v8->tm_isdst != 0], 0xFFFFFFFFFFFFFFFFui64, v9) )
    {
      invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
      JUMPOUT(*(_QWORD *)&byte_1412D4EB9);
    }
    v33 = pConvertedChars;
    *v7 += pConvertedChars - 1;
    *left += 1 - v33;
    return 1i64;
  }
  if ( specifier == 89 )
  {
    v22 = timeptr->tm_year;
    if ( (unsigned int)(v22 + 1900) > 0x270F )
      goto LABEL_75;
    v23 = 4;
    v10 = v22 % 100 + 100 * (v22 / 100 + 19);
    goto LABEL_62;
  }
  if ( (signed int)specifier > 73 )
  {
    if ( specifier == 77 )
    {
      v10 = timeptr->tm_min;
      v11 = v10 < 0x3B;
      v12 = v10 == 59;
LABEL_12:
      if ( !v11 && !v12 )
        goto LABEL_75;
      goto LABEL_61;
    }
    v18 = 6;
    if ( specifier == 83 )
    {
      if ( timeptr->tm_sec > 0x3Bu )
        goto LABEL_75;
      v10 = timeptr->tm_sec;
      goto LABEL_61;
    }
    v19 = 0;
    switch ( specifier )
    {
      case 0x55u:
        if ( timeptr->tm_wday > 6u )
          goto LABEL_75;
        v18 = timeptr->tm_wday;
        break;
      case 0x57u:
        v20 = timeptr->tm_wday;
        if ( v20 > 6 )
          goto LABEL_75;
        if ( v20 )
          v18 = v20 - 1;
        break;
      case 0x58u:
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
    v10 = v19;
    goto LABEL_61;
  }
  if ( specifier == 73 )
  {
    v17 = timeptr->tm_hour;
    if ( (unsigned int)v17 > 0x17 )
      goto LABEL_75;
    v10 = v17 % 12;
    if ( !v10 )
      v10 = 12;
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
      case 0x41u:
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
              **string = v16;
              ++*string;
              v12 = (*left)-- == 1;
            }
            while ( !v12 );
          }
          return 1i64;
        }
        break;
      case 0x42u:
        if ( timeptr->tm_mon <= 0xBu )
        {
          v13 = lc_time->_W_month[timeptr->tm_mon];
          if ( *left )
          {
            do
            {
              v14 = *v13;
              if ( !*v13 )
                break;
              ++v13;
              **string = v14;
              ++*string;
              v12 = (*left)-- == 1;
            }
            while ( !v12 );
          }
          return 1i64;
        }
        break;
      case 0x48u:
        v10 = timeptr->tm_hour;
        v11 = v10 < 0x17;
        v12 = v10 == 23;
        goto LABEL_12;
      default:
        return 0i64;
    }
LABEL_75:
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0i64;
  }
  **string = 37;
  ++*string;
  --*left;
  return 1i64;
}

// File Line: 818
// RVA: 0x12D4EBC
void __fastcall W_store_num(int num, int digits, wchar_t **out, unsigned __int64 *count, unsigned int no_lead_zeros)
{
  int v5; // ebx
  int v6; // er11
  wchar_t *v7; // r10
  wchar_t *v8; // rdx
  wchar_t *v9; // r10
  wchar_t v10; // cx
  int v11; // edx
  int v12; // er10
  __int64 v13; // rdi

  v5 = 0;
  v6 = num;
  if ( no_lead_zeros )
  {
    v7 = *out;
    do
    {
      if ( *count <= 1 )
        break;
      *v7 = v6 % 10 + 48;
      --*count;
      ++v7;
      v6 /= 10;
    }
    while ( v6 > 0 );
    v8 = *out;
    *out = v7;
    v9 = v7 - 1;
    do
    {
      v10 = *v9;
      *v9 = *v8;
      *v8 = v10;
      ++v8;
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
        (*out)[v13] = v6 % 10 + 48;
        v6 /= 10;
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
signed __int64 __fastcall W_store_winword(localeinfo_struct *plocinfo, int field_code, tm *tmptr, wchar_t **out, unsigned __int64 *count, __lc_time_data *lc_time)
{
  unsigned __int16 *v6; // r11
  __int64 v7; // r8
  wchar_t **v8; // r12
  localeinfo_struct *v9; // r14
  wchar_t *v10; // rdi
  unsigned __int16 v11; // ax
  signed int v12; // er14
  wchar_t *v13; // rcx
  unsigned __int16 v14; // ax
  int v15; // eax
  int v16; // esi
  unsigned __int64 v17; // rcx
  signed __int64 v18; // rax
  void *v19; // rsp
  unsigned __int16 *v20; // rbx
  unsigned __int16 *v21; // rax
  wchar_t *v22; // rcx
  int v23; // eax
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
  int v45; // eax
  wchar_t v46; // r9
  __int64 v47; // [rsp+0h] [rbp-40h]
  unsigned __int16 *lpTimeStr; // [rsp+20h] [rbp-20h]
  int cchTime[2]; // [rsp+28h] [rbp-18h]
  tm *timeptr; // [rsp+40h] [rbp+0h]
  localeinfo_struct *v51; // [rsp+48h] [rbp+8h]
  _SYSTEMTIME Time; // [rsp+50h] [rbp+10h]

  v6 = (unsigned __int16 *)tmptr;
  timeptr = tmptr;
  v7 = 0i64;
  v8 = out;
  v9 = plocinfo;
  v51 = plocinfo;
  if ( field_code )
  {
    if ( field_code == 1 )
      v10 = lc_time->_W_ww_ldatefmt;
    else
      v10 = lc_time->_W_ww_timefmt;
  }
  else
  {
    v10 = lc_time->_W_ww_sdatefmt;
  }
  if ( lc_time->ww_caltype == 1 )
    goto LABEL_113;
  v11 = v6[10];
  v12 = 1;
  cchTime[0] = 0;
  Time.wMilliseconds = 0;
  if ( field_code != 2 )
    v12 = 0;
  v13 = lc_time->_W_ww_locale_name;
  Time.wYear = v11 + 1900;
  v14 = v6[8] + 1;
  lpTimeStr = 0i64;
  Time.wMonth = v14;
  Time.wDay = v6[6];
  Time.wHour = v6[4];
  Time.wMinute = v6[2];
  Time.wSecond = *v6;
  if ( v12 )
    v15 = _crtGetTimeFormatEx(v13, 0, &Time, v10, lpTimeStr, cchTime[0]);
  else
    v15 = _crtGetDateFormatEx(v13, 0, &Time, v10, lpTimeStr, cchTime[0]);
  v7 = 0i64;
  v16 = v15;
  if ( !v15 )
    goto LABEL_32;
  v17 = 2i64 * v15 + 16;
  if ( v17 > 0x400 )
  {
    v21 = (unsigned __int16 *)malloc(v17);
    v7 = 0i64;
    v20 = v21;
    if ( !v21 )
      goto LABEL_21;
    *(_DWORD *)v21 = 56797;
  }
  else
  {
    v18 = 2i64 * v15 + 31;
    if ( v17 + 15 <= v17 )
      v18 = 1152921504606846960i64;
    v19 = alloca(v18);
    v20 = (unsigned __int16 *)&timeptr;
    if ( &v47 == (__int64 *)-64i64 )
      goto LABEL_32;
    LODWORD(timeptr) = 52428;
  }
  v20 += 8;
LABEL_21:
  if ( !v20 )
  {
LABEL_32:
    v9 = v51;
    while ( 1 )
    {
      while ( 1 )
      {
        v6 = (unsigned __int16 *)timeptr;
LABEL_113:
        v46 = *v10;
        if ( !*v10 || !*count )
          return 1i64;
        alternate_form = 0;
        v29 = 0;
        v30 = v10;
        do
        {
          ++v30;
          ++v29;
          ++v7;
        }
        while ( *v30 == v46 );
        v31 = 100;
        if ( (signed int)v46 > 100 )
          break;
        switch ( v46 )
        {
          case 0x64u:
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
            ++v10;
            **v8 = v46;
            ++*v8;
            --*count;
LABEL_68:
            v7 = 0i64;
            break;
          case 0x27u:
            if ( !(v29 & 1) )
            {
              v10 += v29;
              goto LABEL_68;
            }
            v10 += v7;
            v7 = 0i64;
            v36 = *v10;
            if ( !*v10 )
              return 1i64;
            do
            {
              if ( !*count )
                break;
              ++v10;
              if ( v36 == 39 )
                break;
              **v8 = v36;
              ++*v8;
              --*count;
              v36 = *v10;
            }
            while ( *v10 );
            break;
          case 0x41u:
LABEL_43:
            if ( wcsicmp(v10, L"am/pm") )
            {
              if ( !wcsicmp(v10, L"a/p") )
                v30 = v10 + 3;
            }
            else
            {
              v30 = v10 + 5;
            }
            v31 = 112;
LABEL_110:
            v45 = W_expandtime(v9, v31, timeptr, v8, count, lc_time, alternate_form);
            v7 = 0i64;
            if ( !v45 )
              return 0i64;
            v10 = v30;
            break;
          case 0x48u:
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
          case 0x4Du:
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
          case 0x61u:
            goto LABEL_43;
          default:
            goto LABEL_107;
        }
      }
      switch ( v46 )
      {
        case 0x68u:
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
        case 0x6Du:
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
        case 0x73u:
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
      if ( *((_DWORD *)v6 + 2) > 11 )
        v40 = lc_time->_W_ampm[1];
      else
        v40 = lc_time->_W_ampm[0];
      v7 = 0i64;
      if ( v29 != 1 || *count <= 0 )
      {
        while ( 1 )
        {
          v41 = *v40;
          if ( !*v40 || *count <= 0 )
            break;
          ++v40;
          **v8 = v41;
          ++*v8;
          --*count;
        }
      }
      else
      {
        **v8 = *v40;
        ++*v8;
        --*count;
      }
      v10 = v30;
    }
  }
  v22 = lc_time->_W_ww_locale_name;
  cchTime[0] = v16;
  lpTimeStr = v20;
  if ( v12 )
    v23 = _crtGetTimeFormatEx(v22, 0, &Time, v10, lpTimeStr, cchTime[0]);
  else
    v23 = _crtGetDateFormatEx(v22, 0, &Time, v10, lpTimeStr, cchTime[0]);
  v24 = v20;
  for ( i = v23 - 1; i > 0 && *count > 0; --i )
  {
    v26 = *v24;
    ++v24;
    **v8 = v26;
    ++*v8;
    --*count;
  }
  if ( *((_DWORD *)v20 - 4) == 56797 )
    free(v20 - 8);
  return 1i64;
}ormatEx(v22, 0, &Time, v10, lpTimeStr, cchTime[0]);
  else
    v23 = _crtGetDateFormatEx(v22, 0, &Time, v10, lpTimeStr, cchTime[0]);
  v24 = v20;
  for ( i = v23 - 1; i > 0 && *count > 0; --i )
  {
    v26 = *v24;
    ++v24;
    **v8 = v26;
    ++*v8;
    --*count;

