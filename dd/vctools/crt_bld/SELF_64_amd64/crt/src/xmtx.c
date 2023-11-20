// File Line: 27
// RVA: 0x12DF180
void __fastcall Mtxinit(_RTL_CRITICAL_SECTION *_Mtx)
{
  InitializeCriticalSectionEx(_Mtx, 0xFA0u, 0);
}

// File Line: 32
// RVA: 0x12DF178
void __stdcall Mtxdst(LPCRITICAL_SECTION lpCriticalSection)
{
  DeleteCriticalSection(lpCriticalSection);
}

// File Line: 38
// RVA: 0x12DF190
void __stdcall Mtxlock(LPCRITICAL_SECTION lpCriticalSection)
{
  EnterCriticalSection(lpCriticalSection);
}

// File Line: 47
// RVA: 0x12DF198
void __stdcall Mtxunlock(LPCRITICAL_SECTION lpCriticalSection)
{
  LeaveCriticalSection(lpCriticalSection);
}

