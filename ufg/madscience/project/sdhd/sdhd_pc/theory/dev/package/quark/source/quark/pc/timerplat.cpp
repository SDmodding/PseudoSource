// File Line: 67
// RVA: 0xA373C0
void __fastcall UFG::TimePlatSetup::TimePlatSetup(UFG::TimePlatSetup *this)
{
  double LowPart; // xmm1_8
  __int64 v3; // rbx
  unsigned __int64 v4; // rsi
  unsigned __int64 v5; // rbx
  double v6; // xmm0_8
  double v7; // xmm0_8
  __int64 v8; // rbx
  double v9; // xmm1_8
  unsigned int wPeriodMin; // ecx
  LARGE_INTEGER Frequency; // [rsp+40h] [rbp+8h] BYREF
  LARGE_INTEGER v12; // [rsp+48h] [rbp+10h] BYREF
  LARGE_INTEGER PerformanceCount; // [rsp+50h] [rbp+18h] BYREF
  timecaps_tag ptc; // [rsp+58h] [rbp+20h] BYREF

  this->mResolutionMSec = 0;
  QueryPerformanceFrequency(&Frequency);
  LowPart = (double)(int)Frequency.LowPart;
  if ( Frequency.QuadPart < 0 )
    LowPart = LowPart + 1.844674407370955e19;
  this->mSecondsPerTick = 1.0 / LowPart;
  this->mMSecsPerTick = 1.0 / LowPart * 1000.0;
  QueryPerformanceCounter(&PerformanceCount);
  v3 = 1024i64;
  v4 = __rdtsc();
  do
  {
    Sleep(0);
    --v3;
  }
  while ( v3 );
  v5 = __rdtsc();
  QueryPerformanceCounter(&v12);
  v6 = (double)(v12.LowPart - PerformanceCount.LowPart);
  if ( v12.QuadPart - PerformanceCount.QuadPart < 0 )
    v6 = v6 + 1.844674407370955e19;
  v7 = v6 * this->mSecondsPerTick;
  v8 = v5 - v4;
  v9 = (double)(int)v8;
  if ( v8 < 0 )
    v9 = v9 + 1.844674407370955e19;
  this->mRTDSCSecondsPerTick = v7 / v9;
  timeGetDevCaps(&ptc, 8u);
  wPeriodMin = 1;
  if ( ptc.wPeriodMin > 1 )
    wPeriodMin = ptc.wPeriodMin;
  this->mResolutionMSec = wPeriodMin;
  timeBeginPeriod(wPeriodMin);
}

// File Line: 126
// RVA: 0x15ADFB0
__int64 UFG::_dynamic_initializer_for__sTimePlat__()
{
  UFG::TimePlatSetup::TimePlatSetup(&sTimePlat);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sTimePlat__);
}

// File Line: 134
// RVA: 0xA39F50
unsigned __int64 __fastcall UFG::qGetTicks()
{
  return __rdtsc();
}

// File Line: 150
// RVA: 0xA39AC0
unsigned __int64 __fastcall UFG::qConvertTicksToMillisecs(__int64 ticks)
{
  double v1; // xmm0_8
  unsigned __int64 v2; // rcx
  double v3; // xmm0_8

  v1 = (double)(int)ticks;
  if ( ticks < 0 )
    v1 = v1 + 1.844674407370955e19;
  v2 = 0i64;
  v3 = v1 * sTimePlat.mMSecsPerTick + 0.5;
  if ( v3 >= 9.223372036854776e18 )
  {
    v3 = v3 - 9.223372036854776e18;
    if ( v3 < 9.223372036854776e18 )
      v2 = 0x8000000000000000ui64;
  }
  return v2 + (unsigned int)(int)v3;
}

// File Line: 155
// RVA: 0xA39A00
unsigned __int64 __fastcall UFG::qConvertMillisecsToTicks(long double milliseconds)
{
  double v1; // xmm0_8
  unsigned __int64 v2; // rcx

  v1 = milliseconds / sTimePlat.mMSecsPerTick;
  v2 = 0i64;
  if ( v1 >= 9.223372036854776e18 )
  {
    v1 = v1 - 9.223372036854776e18;
    if ( v1 < 9.223372036854776e18 )
      v2 = 0x8000000000000000ui64;
  }
  return v2 + (unsigned int)(int)v1;
}

// File Line: 161
// RVA: 0xA39F10
float __fastcall UFG::qGetTickTime(unsigned __int64 start, unsigned __int64 end)
{
  signed __int64 v2; // rdx
  double v3; // xmm0_8

  if ( end >= start )
    v2 = end - start;
  else
    v2 = end - start - 1;
  v3 = (double)(int)v2;
  if ( v2 < 0 )
    v3 = v3 + 1.844674407370955e19;
  return v3 * sTimePlat.mRTDSCSecondsPerTick;
}

// File Line: 178
// RVA: 0xA39E50
// attributes: thunk
DWORD __stdcall UFG::qGetSystemElapsedMSecs()
{
  return timeGetTime();
}

// File Line: 207
// RVA: 0xA39E60
_FILETIME __fastcall UFG::qGetSystemTime()
{
  _SYSTEMTIME SystemTime; // [rsp+20h] [rbp-18h] BYREF
  _FILETIME FileTime; // [rsp+40h] [rbp+8h] BYREF

  GetLocalTime(&SystemTime);
  SystemTimeToFileTime(&SystemTime, &FileTime);
  return FileTime;
}

// File Line: 227
// RVA: 0xA39ED0
_FILETIME __fastcall UFG::qGetSystemTimeUTC()
{
  _SYSTEMTIME SystemTime; // [rsp+20h] [rbp-18h] BYREF
  _FILETIME FileTime; // [rsp+40h] [rbp+8h] BYREF

  GetSystemTime(&SystemTime);
  SystemTimeToFileTime(&SystemTime, &FileTime);
  return FileTime;
}

// File Line: 253
// RVA: 0xA39EA0
float __fastcall UFG::qGetSystemTimeDifference(unsigned __int64 start, unsigned __int64 end)
{
  unsigned __int64 v2; // rax
  __int64 v3; // rax
  float v4; // xmm0_4

  v2 = end;
  if ( start > end )
    v2 = start;
  if ( start < end )
    end = start;
  v3 = v2 - end;
  v4 = (float)(int)v3;
  if ( v3 < 0 )
    v4 = v4 + 1.8446744e19;
  return v4 * 0.0000001;
}

// File Line: 266
// RVA: 0xA39B40
void __fastcall UFG::qGetDateTime(UFG::qDateTime *date_time)
{
  _SYSTEMTIME SystemTime; // [rsp+20h] [rbp-18h] BYREF

  if ( date_time )
  {
    GetLocalTime(&SystemTime);
    date_time->mYear = SystemTime.wYear;
    date_time->mMonth = SystemTime.wMonth;
    date_time->mDay = SystemTime.wDay;
    date_time->mHour = SystemTime.wHour;
    date_time->mMinute = SystemTime.wMinute;
    date_time->mSecond = SystemTime.wSecond;
    date_time->mMillisecond = SystemTime.wMilliseconds;
  }
}

// File Line: 302
// RVA: 0xA39A40
void __fastcall UFG::qConvertSystemTimeToDateTime(UFG::qDateTime *date_time, FILETIME system_time)
{
  _SYSTEMTIME SystemTime; // [rsp+20h] [rbp-18h] BYREF
  FILETIME FileTime; // [rsp+48h] [rbp+10h] BYREF

  if ( date_time )
  {
    FileTime = system_time;
    *(_QWORD *)&date_time->mYear = 0i64;
    *(_DWORD *)&date_time->mMinute = 0;
    date_time->mMillisecond = 0;
    if ( FileTimeToSystemTime(&FileTime, &SystemTime) )
    {
      date_time->mYear = SystemTime.wYear;
      date_time->mMonth = SystemTime.wMonth;
      date_time->mDay = SystemTime.wDay;
      date_time->mHour = SystemTime.wHour;
      date_time->mMinute = SystemTime.wMinute;
      date_time->mSecond = SystemTime.wSecond;
      date_time->mMillisecond = SystemTime.wMilliseconds;
    }
  }
}

