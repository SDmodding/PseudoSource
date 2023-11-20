// File Line: 13
// RVA: 0xC70710
float __fastcall hkStopwatch::divide64(unsigned __int64 a, unsigned __int64 b)
{
  return (double)(signed int)a / (double)(signed int)b;
}

// File Line: 18
// RVA: 0xC706C0
unsigned __int64 __fastcall hkStopwatch::getTickCounter()
{
  return hkSystemClock::getTickCounter();
}

// File Line: 23
// RVA: 0xC706D0
unsigned __int64 __fastcall hkStopwatch::getTicksPerSecond()
{
  return hkSystemClock::getTicksPerSecond();
}

// File Line: 28
// RVA: 0xC706E0
void __fastcall hkStopwatch::secondsFromTicks(unsigned __int64 ticks)
{
  unsigned __int64 v1; // rbx
  unsigned __int64 v2; // rax

  v1 = ticks;
  v2 = hkSystemClock::getTicksPerSecond();
  hkStopwatch::divide64(v1, v2);
}

