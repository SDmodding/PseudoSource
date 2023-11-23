// File Line: 62
// RVA: 0x9928B0
void __fastcall Scaleform::System::Init(
        Scaleform::MemoryHeap::HeapDesc *rootHeapDesc,
        Scaleform::SysAllocBase *psysAlloc)
{
  if ( !System_pSysAlloc )
  {
    timeBeginPeriod(1u);
    InitializeCriticalSection(&Scaleform::WinAPI_GetTimeCS);
    psysAlloc->vfptr->initHeapEngine(psysAlloc, rootHeapDesc);
    System_pSysAlloc = psysAlloc;
  }
}

// File Line: 90
// RVA: 0x96D420
void Scaleform::System::Destroy(void)
{
  bool v0; // al

  if ( System_pSysAlloc )
  {
    Scaleform::Thread::FinishAllThreads();
    v0 = System_pSysAlloc->vfptr->shutdownHeapEngine(System_pSysAlloc);
    System_pSysAlloc = 0i64;
    Scaleform::System::HasMemoryLeaks = !v0;
    DeleteCriticalSection(&Scaleform::WinAPI_GetTimeCS);
    timeEndPeriod(1u);
  }
}

