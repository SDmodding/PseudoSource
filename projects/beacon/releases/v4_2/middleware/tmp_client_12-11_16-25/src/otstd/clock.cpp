// File Line: 31
// RVA: 0xEE6D0C
void __fastcall OSuite::ZClock::ZClock(OSuite::ZClock *this)
{
  this->m_clock = clock();
}

// File Line: 40
// RVA: 0xEE6D00
void __fastcall OSuite::ZClock::ZClock(OSuite::ZClock *this, unsigned __int64 *clock)
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
__int64 __fastcall OSuite::ZClock::_ClockToTime(__int64 clock, OSuite::ZClock::ETimeUnit unit)
{
  int v2; // edx
  int v3; // edx
  double v5; // xmm0_8
  double v6; // xmm0_8
  unsigned __int64 v7; // rcx

  if ( unit == UNIT_SECONDS )
    return clock / 0x3E8ui64;
  v2 = unit - 1;
  if ( v2 )
  {
    v3 = v2 - 1;
    if ( v3 )
    {
      if ( v3 == 1 )
        return clock;
      else
        return 0i64;
    }
    v5 = (double)(int)clock;
    if ( clock < 0 )
      v5 = v5 + 1.844674407370955e19;
    v6 = v5 / 0.001;
  }
  else
  {
    v6 = (double)(int)clock;
    if ( clock < 0 )
      v6 = v6 + 1.844674407370955e19;
  }
  v7 = 0i64;
  if ( v6 >= 9.223372036854776e18 )
  {
    v6 = v6 - 9.223372036854776e18;
    if ( v6 < 9.223372036854776e18 )
      v7 = 0x8000000000000000ui64;
  }
  return v7 + (unsigned int)(int)v6;
}

// File Line: 136
// RVA: 0xEE6DD4
__int64 __fastcall OSuite::ZClock::_TimeToClock(__int64 time, OSuite::ZClock::ETimeUnit unit)
{
  int v2; // edx
  int v3; // edx
  double v5; // xmm0_8
  double v6; // xmm0_8
  unsigned __int64 v7; // rcx

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
    v5 = (double)(int)time;
    if ( time < 0 )
      v5 = v5 + 1.844674407370955e19;
    v6 = v5 * 0.001;
  }
  else
  {
    v6 = (double)(int)time;
    if ( time < 0 )
      v6 = v6 + 1.844674407370955e19;
  }
  v7 = 0i64;
  if ( v6 >= 9.223372036854776e18 )
  {
    v6 = v6 - 9.223372036854776e18;
    if ( v6 < 9.223372036854776e18 )
      v7 = 0x8000000000000000ui64;
  }
  return v7 + (unsigned int)(int)v6;
}

