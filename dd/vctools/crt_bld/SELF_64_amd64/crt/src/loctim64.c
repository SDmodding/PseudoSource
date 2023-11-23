// File Line: 62
// RVA: 0x12BC704
int __fastcall localtime64_s(tm *ptm, const __int64 *ptime)
{
  int result; // eax
  int v5; // eax
  __int64 v6; // rax
  __int64 v7; // rcx
  int v8; // eax
  __int64 v9; // r9
  int v10; // ecx
  __int64 v11; // r8
  int v12; // edx
  unsigned __int64 v13; // r8
  __int64 v14; // r8
  int v15; // ecx
  int tm_wday; // ecx
  int tm_mday; // eax
  __int64 timp[2]; // [rsp+30h] [rbp-10h] BYREF
  int _Timezone; // [rsp+60h] [rbp+20h] BYREF
  int _Daylight; // [rsp+70h] [rbp+30h] BYREF
  int _Daylight_savings_bias; // [rsp+78h] [rbp+38h] BYREF

  _Daylight = 0;
  _Daylight_savings_bias = 0;
  _Timezone = 0;
  if ( !ptm || (memset(ptm, 255, sizeof(tm)), !ptime) )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 22;
  }
  if ( *ptime >= 0x793407000ui64 )
  {
    *errno() = 22;
    return 22;
  }
  _tzset();
  if ( get_daylight(&_Daylight) )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    __debugbreak();
  }
  if ( get_dstbias(&_Daylight_savings_bias) )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    __debugbreak();
  }
  if ( get_timezone(&_Timezone) )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    __debugbreak();
  }
  if ( *ptime <= 259200 )
  {
    result = gmtime64_s(ptm, ptime);
    if ( !result )
    {
      if ( _Daylight && isindst(ptm) )
      {
        v5 = _Timezone;
        ptm->tm_isdst = 1;
        v6 = _Daylight_savings_bias + v5;
      }
      else
      {
        v6 = _Timezone;
      }
      v7 = ptm->tm_sec - v6;
      v8 = (int)v7 % 60;
      ptm->tm_sec = (int)v7 % 60;
      if ( (int)v7 % 60 < 0 )
      {
        v7 -= 60i64;
        ptm->tm_sec = v8 + 60;
      }
      v9 = ptm->tm_min + v7 / 60;
      v10 = (int)v9 % 60;
      ptm->tm_min = (int)v9 % 60;
      if ( (int)v9 % 60 < 0 )
      {
        v9 -= 60i64;
        ptm->tm_min = v10 + 60;
      }
      v11 = ptm->tm_hour + v9 / 60;
      v12 = (int)v11 % 24;
      ptm->tm_hour = (int)v11 % 24;
      if ( (int)v11 % 24 < 0 )
      {
        v11 -= 24i64;
        ptm->tm_hour = v12 + 24;
      }
      v13 = (__int64)((unsigned __int128)(v11 * (__int128)0x2AAAAAAAAAAAAAABi64) >> 64) >> 2;
      v14 = (v13 >> 63) + v13;
      if ( v14 <= 0 )
      {
        if ( v14 >= 0 )
          return 0;
        tm_wday = ptm->tm_wday;
        ptm->tm_mday += v14;
        tm_mday = ptm->tm_mday;
        ptm->tm_wday = ((int)v14 + tm_wday + 7) % 7;
        if ( tm_mday <= 0 )
        {
          ptm->tm_mon = 11;
          ptm->tm_mday = tm_mday + 31;
          ptm->tm_yday += v14 + 365;
          --ptm->tm_year;
          return 0;
        }
      }
      else
      {
        v15 = v14 + ptm->tm_wday;
        ptm->tm_mday += v14;
        ptm->tm_wday = v15 % 7;
      }
      ptm->tm_yday += v14;
      return 0;
    }
  }
  else
  {
    timp[0] = *ptime - _Timezone;
    result = gmtime64_s(ptm, timp);
    if ( !result )
    {
      if ( !_Daylight || !isindst(ptm) )
        return 0;
      timp[0] -= _Daylight_savings_bias;
      result = gmtime64_s(ptm, timp);
      if ( !result )
      {
        ptm->tm_isdst = 1;
        return 0;
      }
    }
  }
  return result;
}

// File Line: 234
// RVA: 0x12BC6BC
tm *__fastcall localtime64(const __int64 *ptime)
{
  tm *result; // rax
  tm *v3; // rbx

  result = (tm *)_getgmtimebuf();
  v3 = result;
  if ( result )
  {
    if ( localtime64_s(result, ptime) )
      return 0i64;
    return v3;
  }
  return result;
}

