// File Line: 62
// RVA: 0x9928B0
void __fastcall Scaleform::System::Init(Scaleform::MemoryHeap::HeapDesc *rootHeapDesc, Scaleform::SysAllocBase *psysAlloc)
{
  Scaleform::SysAllocBase *v2; // rbx
  Scaleform::MemoryHeap::HeapDesc *v3; // rdi

  v2 = psysAlloc;
  v3 = rootHeapDesc;
  if ( !System_pSysAlloc )
  {
    timeBeginPeriod(1u);
    InitializeCriticalSection(&Scaleform::WinAPI_GetTimeCS);
    v2->vfptr->initHeapEngine(v2, v3);
    System_pSysAlloc = v2;
  }
}

// File Line: 90
// RVA: 0x96D420
void Scaleform::System::Destroy(void)
{
  char v0; // al

  if ( System_pSysAlloc )
  {
    Scaleform::Thread::FinishAllThreads();
    v0 = ((__int64 (*)(void))System_pSysAlloc->vfptr->shutdownHeapEngine)();
    System_pSysAlloc = 0i64;
    Scaleform::System::HasMemoryLeaks = v0 == 0;
    DeleteCriticalSection(&Scaleform::WinAPI_GetTimeCS);
    timeEndPeriod(1u);
  }
}

