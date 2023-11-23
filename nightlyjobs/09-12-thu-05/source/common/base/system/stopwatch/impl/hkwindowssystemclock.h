// File Line: 22
// RVA: 0xC833B0
unsigned __int64 __fastcall hkSystemClock::getTickCounter()
{
  return __rdtsc();
}

// File Line: 54
// RVA: 0xC833C0
unsigned __int64 __fastcall hkSystemClock::getTicksPerSecond()
{
  unsigned __int64 result; // rax
  double v1; // xmm6_8
  __int64 v2; // rdi
  unsigned __int64 TickCounter; // rsi
  __int64 v4; // rdx
  unsigned __int64 v5; // rbx
  __int64 v6; // rbx
  double v7; // xmm0_8
  double v8; // xmm1_8
  double v9; // xmm6_8
  double LowPart; // xmm0_8
  double v11; // xmm6_8
  unsigned __int64 v12; // rcx
  int v13; // [rsp+60h] [rbp+8h]
  LARGE_INTEGER v14; // [rsp+68h] [rbp+10h] BYREF
  LARGE_INTEGER PerformanceCount; // [rsp+70h] [rbp+18h] BYREF

  result = freq.QuadPart;
  if ( !freq.QuadPart )
  {
    v1 = 0.0;
    v2 = freq.LowPart + 100;
    do
    {
      TickCounter = hkSystemClock::getTickCounter();
      QueryPerformanceCounter(&PerformanceCount);
      v13 = 1;
      v4 = 50000i64;
      do
      {
        v13 += v13 * v13;
        --v4;
      }
      while ( v4 );
      v5 = hkSystemClock::getTickCounter();
      QueryPerformanceCounter(&v14);
      QueryPerformanceFrequency(&freq);
      v6 = v5 - TickCounter;
      v7 = (double)(int)v6;
      if ( v6 < 0 )
        v7 = v7 + 1.844674407370955e19;
      v8 = (double)(v14.LowPart - PerformanceCount.LowPart);
      if ( v14.QuadPart - PerformanceCount.QuadPart < 0 )
        v8 = v8 + 1.844674407370955e19;
      v1 = v1 + v7 / v8;
      --v2;
    }
    while ( v2 );
    v9 = v1 * 0.01;
    LowPart = (double)(int)freq.LowPart;
    if ( freq.QuadPart < 0 )
      LowPart = LowPart + 1.844674407370955e19;
    v11 = v9 * LowPart;
    v12 = 0i64;
    if ( v11 >= 9.223372036854776e18 )
    {
      v11 = v11 - 9.223372036854776e18;
      if ( v11 < 9.223372036854776e18 )
        v12 = 0x8000000000000000ui64;
    }
    result = v12 + (unsigned int)(int)v11;
    freq.QuadPart = result;
  }
  return result;
}

