// File Line: 85
// RVA: 0x12CE4B0
void _tzset()
{
  if ( !first_time )
  {
    lock(6);
    if ( !first_time )
    {
      tzset_nolock();
      ++first_time;
    }
    unlock(6);
  }
}

// File Line: 98
// RVA: 0x14522D4
_isindst$fin$0

// File Line: 124
// RVA: 0x12CE7C8
void tzset_nolock()
{
  int v0; // r15d
  int v1; // esi
  char **v2; // r14
  UINT v3; // ebx
  const char *v4; // rax
  char *v5; // rdi
  size_t v6; // rax
  size_t v7; // rax
  int v8; // ebx
  int v9; // ebx
  int v10; // ebx
  char *v11; // rdi
  int v12; // ecx
  int v13; // eax
  int v14; // eax
  int v15; // ebx
  int v16; // ebx
  int _Timezone; // [rsp+90h] [rbp+8h] BYREF
  int _Daylight; // [rsp+98h] [rbp+10h] BYREF
  int _Daylight_savings_bias; // [rsp+A0h] [rbp+18h] BYREF
  int UsedDefaultChar; // [rsp+A8h] [rbp+20h] BYREF

  v0 = 0;
  v1 = 0;
  _Timezone = 0;
  _Daylight = 0;
  _Daylight_savings_bias = 0;
  lock(7);
  v2 = _tzname();
  if ( (unsigned int)get_timezone(&_Timezone) )
    goto LABEL_59;
  if ( (unsigned int)get_daylight(&_Daylight) )
  {
LABEL_58:
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
LABEL_59:
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    return;
  }
  if ( (unsigned int)get_dstbias(&_Daylight_savings_bias) )
  {
LABEL_57:
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    goto LABEL_58;
  }
  v3 = __lc_codepage_func();
  tzapiused = 0;
  dstend.yr = -1;
  dststart.yr = -1;
  v4 = getenv_helper_nolock("TZ");
  v5 = (char *)v4;
  if ( !v4 || !*v4 )
  {
LABEL_13:
    if ( lastTZ )
    {
      free(lastTZ);
      lastTZ = 0i64;
    }
    if ( GetTimeZoneInformation(&tzinfo) != -1 )
    {
      tzapiused = 1;
      _Timezone = 60 * tzinfo.Bias;
      if ( tzinfo.StandardDate.wMonth )
        _Timezone = 60 * tzinfo.StandardBias + 60 * tzinfo.Bias;
      if ( tzinfo.DaylightDate.wMonth && tzinfo.DaylightBias )
      {
        _Daylight = 1;
        _Daylight_savings_bias = 60 * (tzinfo.DaylightBias - tzinfo.StandardBias);
      }
      else
      {
        _Daylight = 0;
        _Daylight_savings_bias = 0;
      }
      if ( !WideCharToMultiByte(v3, 0, tzinfo.StandardName, -1, *v2, 63, 0i64, &UsedDefaultChar) || UsedDefaultChar )
        **v2 = 0;
      else
        (*v2)[63] = 0;
      if ( !WideCharToMultiByte(v3, 0, tzinfo.DaylightName, -1, v2[1], 63, 0i64, &UsedDefaultChar) || UsedDefaultChar )
        *v2[1] = 0;
      else
        v2[1][63] = 0;
    }
    goto LABEL_30;
  }
  if ( lastTZ )
  {
    if ( !strcmp(v4, lastTZ) )
      goto LABEL_30;
    if ( lastTZ )
      free(lastTZ);
  }
  v6 = strlen(v5);
  lastTZ = (char *)malloc_crt(v6 + 1);
  if ( lastTZ )
  {
    v7 = strlen(v5);
    if ( !(unsigned int)strcpy_s(lastTZ, v7 + 1, v5) )
      goto LABEL_31;
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    goto LABEL_13;
  }
LABEL_30:
  v1 = 1;
LABEL_31:
  v8 = _Timezone;
  *_timezone() = v8;
  v9 = _Daylight;
  *_daylight() = v9;
  v10 = _Daylight_savings_bias;
  *_dstbias() = v10;
  unlock(7);
  if ( v1 )
    return;
  if ( (unsigned int)strncpy_s(*v2, 0x40ui64, v5, 3ui64) )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    goto LABEL_57;
  }
  v11 = v5 + 3;
  if ( *v11 == 45 )
  {
    v0 = 1;
    ++v11;
  }
  v12 = 3600 * atol(v11);
  _Timezone = v12;
  while ( *v11 == 43 || (unsigned __int8)(*v11 - 48) <= 9u )
    ++v11;
  if ( *v11 == 58 )
  {
    v13 = atol(++v11);
    v12 = 60 * v13 + _Timezone;
    _Timezone = v12;
    while ( *v11 >= 48 && *v11 <= 57 )
      ++v11;
    if ( *v11 == 58 )
    {
      v14 = atol(++v11);
      v12 = v14 + _Timezone;
      _Timezone += v14;
      while ( *v11 >= 48 && *v11 <= 57 )
        ++v11;
    }
  }
  if ( v0 )
    _Timezone = -v12;
  if ( *v11 )
  {
    _Daylight = 1;
    if ( (unsigned int)strncpy_s(v2[1], 0x40ui64, v11, 3ui64) )
    {
      invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
      __debugbreak();
    }
  }
  else
  {
    _Daylight = 0;
    *v2[1] = 0;
  }
  v15 = _Timezone;
  *_timezone() = v15;
  v16 = _Daylight;
  *_daylight() = v16;
}

// File Line: 292
// RVA: 0x14522ED
_tzset_nolock$fin$0

// File Line: 413
// RVA: 0x12CEC30
void __fastcall cvtdate(
        int trantype,
        int datetype,
        int year,
        int month,
        int week,
        int dayofweek,
        int date,
        int hour,
        int min,
        int sec,
        int msec)
{
  int v12; // r11d
  __int64 v13; // rbp
  int v14; // r10d
  int v15; // r10d
  int v16; // r8d
  int v17; // eax
  int v18; // r10d
  int v19; // eax
  int v20; // r10d
  bool v21; // sf
  int v22; // ecx
  int v23; // ecx
  int _Daylight_savings_bias; // [rsp+50h] [rbp+8h] BYREF

  _Daylight_savings_bias = 0;
  if ( datetype == 1 )
  {
    v12 = year % 4;
    if ( (year % 4 || year == 100 * (year / 100)) && year + 1900 != 400 * ((year + 1900) / 400) )
    {
      v13 = month;
      v14 = dword_142126A1C[month];
    }
    else
    {
      v13 = month;
      v14 = dword_142126A54[month];
    }
    v15 = v14 + 1;
    v16 = (365 * year - 25563 + (year + 299) / 400 - (year - 1) / 100 + v15 + (year - 1) / 4) % 7;
    v17 = 7 * week - v16;
    if ( v16 <= dayofweek )
      v17 -= 7;
    v18 = dayofweek + v17 + v15;
    if ( week == 5 )
    {
      if ( (v12 || year == 100 * (year / 100)) && year + 1900 != 400 * ((year + 1900) / 400) )
        v19 = days[v13];
      else
        v19 = lpdays[v13];
      if ( v18 > v19 )
        v18 -= 7;
    }
  }
  else
  {
    if ( (year % 4 || year == 100 * (year / 100)) && year + 1900 != 400 * ((year + 1900) / 400) )
      v20 = dword_142126A1C[month];
    else
      v20 = dword_142126A54[month];
    v18 = date + v20;
  }
  if ( trantype == 1 )
  {
    dststart.yd = v18;
    dststart.ms = msec + 1000 * (sec + 60 * (min + 60 * hour));
    dststart.yr = year;
    return;
  }
  dstend.yd = v18;
  dstend.ms = msec + 1000 * (sec + 60 * (min + 60 * hour));
  if ( (unsigned int)get_dstbias(&_Daylight_savings_bias) )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    JUMPOUT(0x1412CEF01i64);
  }
  v21 = 1000 * _Daylight_savings_bias + dstend.ms < 0;
  v22 = 1000 * _Daylight_savings_bias + dstend.ms;
  dstend.ms = v22;
  if ( v21 )
  {
    v23 = v22 + 86400000;
    --dstend.yd;
LABEL_30:
    dstend.ms = v23;
    goto LABEL_31;
  }
  if ( v22 >= 86400000 )
  {
    v23 = v22 - 86400000;
    ++dstend.yd;
    goto LABEL_30;
  }
LABEL_31:
  dstend.yr = year;
}

// File Line: 542
// RVA: 0x12CE4EC
__int64 __fastcall isindst(tm *tb)
{
  lock(6);
  LODWORD(tb) = isindst_nolock(tb);
  unlock(6);
  return (unsigned int)tb;
}

// File Line: 558
// RVA: 0x12CE51C
__int64 __fastcall isindst_nolock(tm *tb)
{
  unsigned int v2; // edi
  int tm_year; // ebp
  int wMonth; // r9d
  int v6; // r8d
  int v7; // eax
  int v8; // r14d
  int v9; // ebx
  int v10; // r9d
  int tm_yday; // ecx
  int v12; // eax
  int week; // [rsp+20h] [rbp-58h]
  int dayofweek; // [rsp+28h] [rbp-50h]
  int hour; // [rsp+38h] [rbp-40h]
  int min; // [rsp+40h] [rbp-38h]
  int sec; // [rsp+48h] [rbp-30h]
  int msec; // [rsp+50h] [rbp-28h]
  int v19; // [rsp+88h] [rbp+10h] BYREF

  v2 = 0;
  v19 = 0;
  if ( (unsigned int)get_daylight(&v19) )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    JUMPOUT(0x1412CE7C4i64);
  }
  if ( !v19 )
    return 0i64;
  tm_year = tb->tm_year;
  if ( tm_year != dststart.yr || tm_year != dstend.yr )
  {
    if ( tzapiused )
    {
      if ( tzinfo.DaylightDate.wYear )
        cvtdate(
          1,
          0,
          tm_year,
          tzinfo.DaylightDate.wMonth,
          0,
          0,
          tzinfo.DaylightDate.wDay,
          tzinfo.DaylightDate.wHour,
          tzinfo.DaylightDate.wMinute,
          tzinfo.DaylightDate.wSecond,
          tzinfo.DaylightDate.wMilliseconds);
      else
        cvtdate(
          1,
          1,
          tm_year,
          tzinfo.DaylightDate.wMonth,
          tzinfo.DaylightDate.wDay,
          tzinfo.DaylightDate.wDayOfWeek,
          0,
          tzinfo.DaylightDate.wHour,
          tzinfo.DaylightDate.wMinute,
          tzinfo.DaylightDate.wSecond,
          tzinfo.DaylightDate.wMilliseconds);
      wMonth = tzinfo.StandardDate.wMonth;
      msec = tzinfo.StandardDate.wMilliseconds;
      sec = tzinfo.StandardDate.wSecond;
      min = tzinfo.StandardDate.wMinute;
      hour = tzinfo.StandardDate.wHour;
      v6 = tb->tm_year;
      if ( tzinfo.StandardDate.wYear )
      {
        cvtdate(
          0,
          0,
          v6,
          tzinfo.StandardDate.wMonth,
          0,
          0,
          tzinfo.StandardDate.wDay,
          tzinfo.StandardDate.wHour,
          tzinfo.StandardDate.wMinute,
          tzinfo.StandardDate.wSecond,
          tzinfo.StandardDate.wMilliseconds);
        goto LABEL_17;
      }
      dayofweek = tzinfo.StandardDate.wDayOfWeek;
      week = tzinfo.StandardDate.wDay;
    }
    else
    {
      v7 = 2;
      v8 = 1;
      v9 = 11;
      v10 = 3;
      if ( tm_year < 107 )
      {
        v10 = 4;
        v7 = 1;
        v9 = 10;
        v8 = 5;
      }
      cvtdate(1, 1, tm_year, v10, v7, 0, 0, 2, 0, 0, 0);
      v6 = tb->tm_year;
      msec = 0;
      sec = 0;
      min = 0;
      hour = 2;
      dayofweek = 0;
      week = v8;
      wMonth = v9;
    }
    cvtdate(0, 1, v6, wMonth, week, dayofweek, 0, hour, min, sec, msec);
  }
LABEL_17:
  tm_yday = tb->tm_yday;
  if ( dststart.yd < dstend.yd )
  {
    if ( tm_yday >= dststart.yd && tm_yday <= dstend.yd )
    {
      if ( tm_yday > dststart.yd && tm_yday < dstend.yd )
        return 1i64;
      goto LABEL_27;
    }
    return 0i64;
  }
  if ( tm_yday < dstend.yd || tm_yday > dststart.yd )
    return 1i64;
  if ( tm_yday > dstend.yd && tm_yday < dststart.yd )
    return 0i64;
LABEL_27:
  v12 = 1000 * (tb->tm_sec + 60 * (tb->tm_min + 60 * tb->tm_hour));
  if ( tm_yday == dststart.yd )
    LOBYTE(v2) = v12 >= dststart.ms;
  else
    LOBYTE(v2) = v12 < dstend.ms;
  return v2;
}

