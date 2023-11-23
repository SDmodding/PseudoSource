// File Line: 13
// RVA: 0xC70710
float __fastcall hkStopwatch::divide64(unsigned __int64 a, unsigned __int64 b)
{
  return (double)(int)a / (double)(int)b;
}

// File Line: 18
// RVA: 0xC706C0
// attributes: thunk
unsigned __int64 __fastcall hkStopwatch::getTickCounter()
{
  return hkSystemClock::getTickCounter();
}

// File Line: 23
// RVA: 0xC706D0
// attributes: thunk
unsigned __int64 __fastcall hkStopwatch::getTicksPerSecond()
{
  return hkSystemClock::getTicksPerSecond();
}

// File Line: 28
// RVA: 0xC706E0
double __fastcall hkStopwatch::secondsFromTicks(unsigned __int64 ticks)
{
  unsigned __int64 TicksPerSecond; // rax
  double result; // xmm0_8

  TicksPerSecond = hkSystemClock::getTicksPerSecond();
  *(float *)&result = hkStopwatch::divide64(ticks, TicksPerSecond);
  return result;
}

