// File Line: 57
// RVA: 0x12BBD28
__int64 __fastcall mktime64(tm *tb)
{
  return make__time64_t(tb, 1);
}

// File Line: 123
// RVA: 0x12BBA50
__int64 __fastcall make__time64_t(tm *tb, int ultflag)
{
  __int64 tm_year; // r10
  int tm_mon; // ecx
  int v6; // edx
  int v7; // ecx
  __int64 v8; // r11
  int tm_isdst; // eax
  int v10; // eax
  __int64 ptime; // [rsp+30h] [rbp-40h] BYREF
  int _Daylight_savings_bias; // [rsp+38h] [rbp-38h] BYREF
  int _Timezone; // [rsp+3Ch] [rbp-34h] BYREF
  tm ptm; // [rsp+40h] [rbp-30h] BYREF

  _Daylight_savings_bias = 0;
  _Timezone = 0;
  if ( tb )
  {
    tm_year = tb->tm_year;
    ptime = tm_year;
    if ( (unsigned __int64)(tm_year - 69) > 0x408 )
      goto $err_mktime;
    tm_mon = tb->tm_mon;
    if ( (unsigned int)tm_mon > 0xB )
    {
      v6 = tm_mon / 12;
      v7 = tm_mon % 12;
      tm_year += v6;
      tb->tm_mon = v7;
      ptime = tm_year;
      if ( v7 < 0 )
      {
        --tm_year;
        tb->tm_mon = v7 + 12;
        ptime = tm_year;
      }
      if ( (unsigned __int64)(tm_year - 69) > 0x408 )
        goto $err_mktime;
    }
    v8 = days[tb->tm_mon];
    if ( (((((tm_year >> 63) & 3) + (_BYTE)tm_year) & 3) == ((tm_year >> 63) & 3) && tm_year != 100 * (tm_year / 100)
       || tm_year + 1900 == 400 * ((tm_year + 1900) / 400))
      && tb->tm_mon > 1 )
    {
      ++v8;
    }
    ptime = 60
          * (60
           * (24
            * (365 * tm_year + tb->tm_mday
                             + (tm_year + 299) / 400
                             - (tm_year - 1) / 100
                             - 25567
                             + v8
                             + (tm_year - 1) / 4)
            + tb->tm_hour)
           + tb->tm_min)
          + tb->tm_sec;
    if ( ultflag )
    {
      _tzset();
      if ( get_dstbias(&_Daylight_savings_bias) )
      {
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        JUMPOUT(0x1412BBD25i64);
      }
      if ( get_timezone(&_Timezone) )
      {
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        __debugbreak();
      }
      ptime += _Timezone;
      if ( localtime64_s(&ptm, &ptime) )
        goto $err_mktime;
      tm_isdst = tb->tm_isdst;
      if ( tm_isdst <= 0 && (tm_isdst >= 0 || ptm.tm_isdst <= 0) )
        goto LABEL_23;
      ptime += _Daylight_savings_bias;
      v10 = localtime64_s(&ptm, &ptime);
    }
    else
    {
      v10 = gmtime64_s(&ptm, &ptime);
    }
    if ( !v10 )
    {
LABEL_23:
      *tb = ptm;
      return ptime;
    }
$err_mktime:
    *errno() = 22;
    return -1i64;
  }
  *errno() = 22;
  invalid_parameter_noinfo();
  return -1i64;
}

