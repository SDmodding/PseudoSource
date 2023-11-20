// File Line: 31
// RVA: 0xEE6D0C
void __fastcall OSuite::ZClock::ZClock(OSuite::ZClock *this)
{
  this->m_clock = clock();
}

// File Line: 40
// RVA: 0xEE6D00
void __fastcall OSuite::ZClock::ZClock(OSuite::ZClock *this, const unsigned __int64 *clock)
{
  this->m_clock = *clock;
}

// File Line: 74
// RVA: 0xEE6DC4
unsigned __int64 __fastcall OSuite::ZClock::_GetClock()
{
  return clock();
}

// File Line: 112
// RVA: 0xEE6D2C
unsigned __int64 __fastcall OSuite::ZClock::_ClockToTime(const unsigned __int64 clock, OSuite::ZClock::ETimeUnit unit)
{
  __int32 v2; // edx
  int v3; // edx
  unsigned __int64 result; // rax
  double v5; // xmm0_8
  double v6; // xmm0_8
  signed __int64 v7; // rcx

  if ( unit == UNIT_SECONDS )
    return (unsigned __int64)((clock * (unsigned __int128)0x624DD2F1A9FBE77ui64 >> 64)
                            + ((unsigned __int64)(clock - (clock * (unsigned __int128)0x624DD2F1A9FBE77ui64 >> 64)) >> 1)) >> 9;
  v2 = unit - 1;
  if ( v2 )
  {
    v3 = v2 - 1;
    if ( v3 )
    {
      if ( v3 == 1 )
        result = clock;
      else
        result = 0i64;
      return result;
    }
    v5 = (double)(signed int)clock;
    if ( (clock & 0x8000000000000000ui64) != 0i64 )
      v5 = v5 + 1.844674407370955e19;
    v6 = v5 / 0.001;
  }
  else
  {
    v6 = (double)(signed int)clock;
    if ( (clock & 0x8000000000000000ui64) != 0i64 )
      v6 = v6 + 1.844674407370955e19;
  }
  v7 = 0i64;
  if ( v6 >= 9.223372036854776e18 )
  {
    v6 = v6 - 9.223372036854776e18;
    if ( v6 < 9.223372036854776e18 )
      v7 = 0x8000000000000000i64;
  }
  return v7 + (unsigned int)(signed int)v6;
}

// File Line: 136
// RVA: 0xEE6DD4
signed __int64 __fastcall OSuite::ZClock::_TimeToClock(unsigned __int64 time, OSuite::ZClock::ETimeUnit unit)
{
  __int32 v2; // edx
  int v3; // edx
  double v5; // xmm0_8
  double v6; // xmm0_8
  signed __int64 v7; // rcx

  if ( unit == UNIT_SECONDS )
  {
    time *= 1000i64;
    return time;
  }
  v2 = unit - 1;
  if ( v2 )
  {
    v3 = v2 - 1;
    if ( v3 )
    {
      if ( v3 != 1 )
        return 0i64;
      return time;
    }
    v5 = (double)(signed int)time;
    if ( (time & 0x8000000000000000ui64) != 0i64 )
      v5 = v5 + 1.844674407370955e19;
    v6 = v5 * 0.001;
  }
  else
  {
    v6 = (double)(signed int)time;
    if ( (time & 0x8000000000000000ui64) != 0i64 )
      v6 = v6 + 1.844674407370955e19;
  }
  v7 = 0i64;
  if ( v6 >= 9.223372036854776e18 )
  {
    v6 = v6 - 9.223372036854776e18;
    if ( v6 < 9.223372036854776e18 )
      v7 = 0x8000000000000000i64;
  }
  return v7 + (unsigned int)(signed int)v6;
}

