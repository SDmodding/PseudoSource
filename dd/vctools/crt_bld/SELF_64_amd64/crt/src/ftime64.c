// File Line: 71
// RVA: 0x12B89A4
__int64 __fastcall ftime64_s(__timeb64 *tp)
{
  signed int v1; // ebx
  __timeb64 *v2; // rdi
  __int64 result; // rax
  _FILETIME v4; // rcx
  unsigned __int64 v5; // rsi
  DWORD v6; // eax
  unsigned __int64 v7; // r8
  int _Timezone; // [rsp+30h] [rbp-D8h]
  _FILETIME SystemTimeAsFileTime; // [rsp+38h] [rbp-D0h]
  _TIME_ZONE_INFORMATION TimeZoneInformation; // [rsp+40h] [rbp-C8h]

  v1 = 0;
  v2 = tp;
  _Timezone = 0;
  if ( tp )
  {
    _tzset();
    if ( get_timezone(&_Timezone) )
    {
      invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
      JUMPOUT(*(_QWORD *)&byte_1412B8B35);
    }
    v2->timezone = _Timezone / 60;
    GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
    v4 = SystemTimeAsFileTime;
    v5 = (unsigned __int64)(*(unsigned __int64 *)&SystemTimeAsFileTime * (unsigned __int128)0xE5109EC205D7BEA7ui64 >> 64) >> 29;
    if ( v5 == elapsed_minutes_cache )
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
    v2->dstflag = v1;
    v7 = (unsigned __int64)(*(unsigned __int64 *)&v4 * (unsigned __int128)0x346DC5D63886594Bui64 >> 64) >> 11;
    v2->millitm = v7
                - 1000
                * ((unsigned __int64)((v7 * (unsigned __int128)0x624DD2F1A9FBE77ui64 >> 64)
                                    + ((unsigned __int64)(v7 - (v7 * (unsigned __int128)0x624DD2F1A9FBE77ui64 >> 64)) >> 1)) >> 9);
    result = 0i64;
    v2->time = (unsigned __int64)((unsigned __int64)(*(_QWORD *)&v4 - 116444736000000000i64)
                                * (unsigned __int128)0xD6BF94D5E57A42BDui64 >> 64) >> 23;
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    result = (unsigned int)((_DWORD)v2 + 22);
  }
  return result;
}

// File Line: 129
// RVA: 0x12B899C
void __fastcall ftime64(__timeb64 *tp)
{
  ftime64_s(tp);
}

