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
  int v2; // edi
  tm *v3; // rbx
  __int64 v4; // r10
  int v5; // ecx
  int v6; // edx
  int v7; // ecx
  __int64 v8; // r11
  signed __int64 v9; // rcx
  signed __int64 v10; // r8
  int v11; // eax
  int v12; // eax
  __int64 ptime; // [rsp+30h] [rbp-40h]
  int _Daylight_savings_bias; // [rsp+38h] [rbp-38h]
  int _Timezone; // [rsp+3Ch] [rbp-34h]
  tm ptm; // [rsp+40h] [rbp-30h]

  _Daylight_savings_bias = 0;
  _Timezone = 0;
  v2 = ultflag;
  v3 = tb;
  if ( tb )
  {
    v4 = tb->tm_year;
    ptime = tb->tm_year;
    if ( (unsigned __int64)(v4 - 69) > 0x408 )
      goto $err_mktime;
    v5 = tb->tm_mon;
    if ( (unsigned int)v5 > 0xB )
    {
      v6 = v5 / 12;
      v7 = v5 % 12;
      v4 += v6;
      v3->tm_mon = v7;
      ptime = v4;
      if ( v7 < 0 )
      {
        --v4;
        v3->tm_mon = v7 + 12;
        ptime = v4;
      }
      if ( (unsigned __int64)(v4 - 69) > 0x408 )
        goto $err_mktime;
    }
    v8 = days[v3->tm_mon];
    if ( (((((v4 >> 63) & 3) + (_BYTE)v4) & 3) == ((v4 >> 63) & 3)
       && v4 != 100
              * (((unsigned __int64)(v4 + ((unsigned __int128)(v4 * (signed __int128)-6640827866535438581i64) >> 64)) >> 63)
               + ((signed __int64)(v4 + ((unsigned __int128)(v4 * (signed __int128)-6640827866535438581i64) >> 64)) >> 6))
       || v4 + 1900 == 400
                     * (((unsigned __int64)(v4
                                          + 1900
                                          + ((unsigned __int128)((v4 + 1900) * (signed __int128)-6640827866535438581i64) >> 64)) >> 63)
                      + ((signed __int64)(v4
                                        + 1900
                                        + ((unsigned __int128)((v4 + 1900) * (signed __int128)-6640827866535438581i64) >> 64)) >> 8)))
      && v3->tm_mon > 1 )
    {
      ++v8;
    }
    v9 = v4 + 299;
    v10 = v4 - 1;
    ptime = 60
          * (60
           * (24
            * (365 * v4
             + v3->tm_mday
             + ((unsigned __int64)(v9 + ((unsigned __int128)(v9 * (signed __int128)-6640827866535438581i64) >> 64)) >> 63)
             + ((signed __int64)(v9 + ((unsigned __int128)(v9 * (signed __int128)-6640827866535438581i64) >> 64)) >> 8)
             - (((unsigned __int64)(v10 + ((unsigned __int128)(v10 * (signed __int128)-6640827866535438581i64) >> 64)) >> 63)
              + ((signed __int64)(v10 + ((unsigned __int128)(v10 * (signed __int128)-6640827866535438581i64) >> 64)) >> 6))
             - 25567
             + v8
             + v10 / 4)
            + v3->tm_hour)
           + v3->tm_min)
          + v3->tm_sec;
    if ( v2 )
    {
      _tzset();
      if ( !get_dstbias(&_Daylight_savings_bias) )
      {
        if ( !get_timezone(&_Timezone) )
        {
          ptime += _Timezone;
          if ( localtime64_s(&ptm, &ptime) )
            goto $err_mktime;
          v11 = v3->tm_isdst;
          if ( v11 <= 0 && (v11 >= 0 || ptm.tm_isdst <= 0) )
            goto LABEL_23;
          ptime += _Daylight_savings_bias;
          v12 = localtime64_s(&ptm, &ptime);
LABEL_22:
          if ( !v12 )
          {
LABEL_23:
            v3->tm_sec = ptm.tm_sec;
            v3->tm_min = ptm.tm_min;
            v3->tm_hour = ptm.tm_hour;
            v3->tm_mday = ptm.tm_mday;
            v3->tm_mon = ptm.tm_mon;
            v3->tm_year = ptm.tm_year;
            v3->tm_wday = ptm.tm_wday;
            v3->tm_yday = ptm.tm_yday;
            v3->tm_isdst = ptm.tm_isdst;
            return ptime;
          }
$err_mktime:
          *errno() = 22;
          return -1i64;
        }
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        __debugbreak();
      }
      invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
      JUMPOUT(*(_QWORD *)&byte_1412BBD25);
    }
    v12 = gmtime64_s(&ptm, &ptime);
    goto LABEL_22;
  }
  *errno() = 22;
  invalid_parameter_noinfo();
  return -1i64;
}

