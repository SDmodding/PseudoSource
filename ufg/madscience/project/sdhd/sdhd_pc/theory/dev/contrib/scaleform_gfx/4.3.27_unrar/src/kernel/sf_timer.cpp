// File Line: 54
// RVA: 0x98ABD0
unsigned __int64 __fastcall Scaleform::Timer::GetProfileTicks()
{
  Scaleform::Timer::TimerOverride *v0; // rcx
  unsigned __int64 v1; // rax
  LARGE_INTEGER v2; // rbx
  LARGE_INTEGER v3; // r8
  LARGE_INTEGER PerformanceCount; // [rsp+30h] [rbp+8h]
  LARGE_INTEGER Frequency; // [rsp+38h] [rbp+10h]

  QueryPerformanceCounter(&PerformanceCount);
  v0 = TimerOverrideInstance;
  if ( TimerOverrideInstance )
  {
    v1 = TimerOverrideInstance->vfptr->GetRawTicks(TimerOverrideInstance, PerformanceCount.QuadPart);
    v0 = TimerOverrideInstance;
    v2.QuadPart = v1;
  }
  else
  {
    v2 = PerformanceCount;
  }
  v3.QuadPart = qword_142452408;
  if ( !qword_142452408 )
  {
    QueryPerformanceFrequency(&Frequency);
    v3 = Frequency;
    v0 = TimerOverrideInstance;
    qword_142452408 = Frequency.QuadPart;
  }
  if ( v0 )
    v3.QuadPart = ((__int64 (__fastcall *)(Scaleform::Timer::TimerOverride *, LARGE_INTEGER))v0->vfptr->GetRawFrequency)(
                    v0,
                    v3);
  return (unsigned __int64)(1000000 * v2.QuadPart) / v3.QuadPart;
}

// File Line: 93
// RVA: 0x98DC90
unsigned int __fastcall Scaleform::Timer::GetTicksMs()
{
  unsigned int result; // eax

  result = timeGetTime();
  if ( TimerOverrideInstance )
    result = TimerOverrideInstance->vfptr->GetTicksMs(TimerOverrideInstance, result);
  return result;
}

// File Line: 108
// RVA: 0x98DC10
signed __int64 __fastcall Scaleform::Timer::GetTicks()
{
  unsigned int v0; // eax
  unsigned int v1; // ecx
  unsigned __int64 v2; // rbx

  EnterCriticalSection(&Scaleform::WinAPI_GetTimeCS);
  v0 = timeGetTime();
  v1 = v0;
  if ( TimerOverrideInstance )
    v1 = TimerOverrideInstance->vfptr->GetTicksMs(TimerOverrideInstance, v0);
  if ( Scaleform::WinAPI_OldTime > v1 )
    ++Scaleform::WinAPI_WrapCounter;
  Scaleform::WinAPI_OldTime = v1;
  v2 = v1 | ((unsigned __int64)Scaleform::WinAPI_WrapCounter << 32);
  LeaveCriticalSection(&Scaleform::WinAPI_GetTimeCS);
  return 1000 * v2;
}

