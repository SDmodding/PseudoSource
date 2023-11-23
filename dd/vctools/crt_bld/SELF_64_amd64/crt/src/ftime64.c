// File Line: 71
// RVA: 0x12B89A4
__int64 __fastcall ftime64_s(__timeb64 *tp)
{
  int v1; // ebx
  __int64 result; // rax
  _FILETIME v4; // rcx
  unsigned __int64 v5; // rsi
  DWORD v6; // eax
  __int64 v7; // rdx
  int _Timezone; // [rsp+30h] [rbp-D8h] BYREF
  _FILETIME SystemTimeAsFileTime; // [rsp+38h] [rbp-D0h] BYREF
  _TIME_ZONE_INFORMATION TimeZoneInformation; // [rsp+40h] [rbp-C8h] BYREF

  v1 = 0;
  _Timezone = 0;
  if ( tp )
  {
    _tzset();
    if ( get_timezone(&_Timezone) )
    {
      invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
      JUMPOUT(0x1412B8B35i64);
    }
    tp->timezone = _Timezone / 60;
    GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
    v4 = SystemTimeAsFileTime;
    v5 = *(unsigned __int64 *)&SystemTimeAsFileTime / 0x23C34600;
    if ( *(unsigned __int64 *)&SystemTimeAsFileTime / 0x23C34600 == elapsed_minutes_cache )
    {
      LOWORD(v1) = dstflag_cache;
    }
    else
    {
      v6 = GetTimeZoneInformation(&TimeZoneInformation);
      if ( v6 == -1 )
      {
        v1 = -1;
      }
      else if ( v6 == 2 && TimeZoneInformation.DaylightDate.wMonth )
      {
        if ( TimeZoneInformation.DaylightBias )
          v1 = 1;
      }
      v4 = SystemTimeAsFileTime;
      dstflag_cache = v1;
      elapsed_minutes_cache = v5;
    }
    tp->dstflag = v1;
    v7 = (*(unsigned __int64 *)&v4 / 0x2710 * (unsigned __int128)0x624DD2F1A9FBE77ui64) >> 64;
    tp->millitm = *(unsigned __int64 *)&v4 / 0x2710
                - 1000 * ((v7 + ((*(unsigned __int64 *)&v4 / 0x2710 - v7) >> 1)) >> 9);
    result = 0i64;
    tp->time = (*(_QWORD *)&v4 - 116444736000000000i64) / 0x989680ui64;
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 22i64;
  }
  return result;
}

// File Line: 129
// RVA: 0x12B899C
// attributes: thunk
void __fastcall ftime64(__timeb64 *tp)
{
  ftime64_s(tp);
}

