// File Line: 65
// RVA: 0xA11C50
__int64 __fastcall Scaleform::Mutex_AreadyLockedAcquireInterface::TryAcquire(
        Scaleform::Mutex_AreadyLockedAcquireInterface *this)
{
  return ((__int64 (__fastcall *)(Scaleform::AcquireInterface *))this->pMutex->vfptr->TryAcquire)(&this->pMutex->Scaleform::AcquireInterface);
}

// File Line: 66
// RVA: 0xA11C90
__int64 __fastcall Scaleform::Mutex_AreadyLockedAcquireInterface::TryAcquireCommit(
        Scaleform::Mutex_AreadyLockedAcquireInterface *this)
{
  return ((__int64 (__fastcall *)(Scaleform::AcquireInterface *))this->pMutex->vfptr->TryAcquireCommit)(&this->pMutex->Scaleform::AcquireInterface);
}

// File Line: 67
// RVA: 0xA11C80
__int64 __fastcall Scaleform::Mutex_AreadyLockedAcquireInterface::TryAcquireCancel(
        Scaleform::Mutex_AreadyLockedAcquireInterface *this)
{
  return ((__int64 (__fastcall *)(Scaleform::AcquireInterface *))this->pMutex->vfptr->TryAcquireCancel)(&this->pMutex->Scaleform::AcquireInterface);
}

// File Line: 119
// RVA: 0xA10C10
void __fastcall Scaleform::MutexImpl::MutexImpl(Scaleform::MutexImpl *this, Scaleform::Mutex *pmutex, bool recursive)
{
  HANDLE MutexA; // rax

  this->AreadyLockedAcquire.vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable;
  this->AreadyLockedAcquire.vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Mutex_AreadyLockedAcquireInterface::`vftable;
  this->AreadyLockedAcquire.pMutex = 0i64;
  this->AreadyLockedAcquire.pMutex = pmutex;
  this->Recursive = recursive;
  this->LockCount = 0;
  if ( this->Recursive )
    MutexA = CreateMutexA(0i64, 0, 0i64);
  else
    MutexA = CreateSemaphoreA(0i64, 1, 1, 0i64);
  this->hMutexOrSemaphore = MutexA;
}

// File Line: 149
// RVA: 0xA11CE0
void __fastcall Scaleform::MutexImpl::Unlock(Scaleform::MutexImpl *this, Scaleform::Mutex *pmutex)
{
  volatile unsigned int v2; // edi
  Scaleform::Waitable::HandlerArray *v3; // rbx
  Scaleform::Waitable::HandlerArray *pHandlers; // rax
  bool v5; // zf
  void *hMutexOrSemaphore; // rcx
  BOOL v7; // eax

  v2 = --this->LockCount;
  v3 = 0i64;
  pHandlers = pmutex->pHandlers;
  if ( pHandlers )
  {
    v3 = pmutex->pHandlers;
    _InterlockedExchangeAdd(&pHandlers->RefCount.Value, 1u);
  }
  v5 = !this->Recursive;
  hMutexOrSemaphore = this->hMutexOrSemaphore;
  if ( v5 )
    v7 = ReleaseSemaphore(hMutexOrSemaphore, 1, 0i64);
  else
    v7 = ReleaseMutex(hMutexOrSemaphore);
  if ( v7 && !v2 && v3 )
    Scaleform::Waitable::HandlerArray::CallWaitHandlers(v3);
  if ( v3 )
    Scaleform::Waitable::HandlerArray::Release(v3);
}

// File Line: 209
// RVA: 0xA10B80
void __fastcall Scaleform::Mutex::Mutex(Scaleform::Mutex *this, bool recursive, bool multiWait)
{
  Scaleform::MutexImpl *v5; // rax

  Scaleform::Waitable::Waitable(this, multiWait);
  this->Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable;
  this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Mutex::`vftable{for `Scaleform::Waitable};
  this->Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Mutex::`vftable{for `Scaleform::AcquireInterface};
  v5 = (Scaleform::MutexImpl *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                 Scaleform::Memory::pGlobalHeap,
                                 32i64);
  if ( v5 )
    Scaleform::MutexImpl::MutexImpl(v5, this, recursive);
  this->pImpl = v5;
}

// File Line: 214
// RVA: 0xA10FE0
void __fastcall Scaleform::Mutex::~Mutex(Scaleform::Mutex *this)
{
  Scaleform::MutexImpl *pImpl; // rdi

  this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Mutex::`vftable{for `Scaleform::Waitable};
  this->Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Mutex::`vftable{for `Scaleform::AcquireInterface};
  pImpl = this->pImpl;
  if ( pImpl )
  {
    CloseHandle(pImpl->hMutexOrSemaphore);
    pImpl->AreadyLockedAcquire.vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pImpl);
  }
  this->Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable;
  Scaleform::Waitable::~Waitable(this);
}

// File Line: 220
// RVA: 0xA11440
void __fastcall Scaleform::Mutex::DoLock(Scaleform::Mutex *this)
{
  Scaleform::MutexImpl *pImpl; // rbx

  pImpl = this->pImpl;
  if ( !WaitForSingleObject(pImpl->hMutexOrSemaphore, 0xFFFFFFFF) )
    ++pImpl->LockCount;
}

// File Line: 224
// RVA: 0xA11CA0
char __fastcall Scaleform::Mutex::TryLock(Scaleform::Mutex *this)
{
  Scaleform::MutexImpl *pImpl; // rbx

  pImpl = this->pImpl;
  if ( WaitForSingleObject(pImpl->hMutexOrSemaphore, 0) )
    return 0;
  ++pImpl->LockCount;
  return 1;
}

// File Line: 228
// RVA: 0xA11CD0
void __fastcall Scaleform::Mutex::Unlock(Scaleform::Mutex *this)
{
  Scaleform::MutexImpl::Unlock(this->pImpl, this);
}

// File Line: 232
// RVA: 0xA11750
char __fastcall Scaleform::Mutex::IsLockedByAnotherThread(Scaleform::Mutex *this)
{
  Scaleform::MutexImpl *pImpl; // rbx

  pImpl = this->pImpl;
  if ( !pImpl->LockCount )
    return 0;
  if ( !WaitForSingleObject(pImpl->hMutexOrSemaphore, 0) )
  {
    ++pImpl->LockCount;
    Scaleform::MutexImpl::Unlock(pImpl, this);
    return 0;
  }
  return 1;
}

// File Line: 236
// RVA: 0xA117A0
bool __fastcall Scaleform::Mutex::IsSignaled(Scaleform::Mutex *this)
{
  return this->pImpl->LockCount == 0;
}

// File Line: 241
// RVA: 0xA11630
Scaleform::Mutex_AreadyLockedAcquireInterface *__fastcall Scaleform::Mutex::GetAcquireInterface(Scaleform::Mutex *this)
{
  Scaleform::MutexImpl *pImpl; // rbx

  pImpl = this->pImpl;
  if ( !pImpl->LockCount || WaitForSingleObject(pImpl->hMutexOrSemaphore, 0) )
    return (Scaleform::Mutex_AreadyLockedAcquireInterface *)&this->Scaleform::AcquireInterface;
  ++pImpl->LockCount;
  Scaleform::MutexImpl::Unlock(pImpl, this);
  return &pImpl->AreadyLockedAcquire;
}

// File Line: 247
// RVA: 0xA11380
char __fastcall Scaleform::Mutex::CanAcquire(Scaleform::Mutex *this)
{
  Scaleform::MutexImpl *v1; // rbx
  Scaleform::Mutex *v2; // rdi

  v1 = *(Scaleform::MutexImpl **)&this->RefCount;
  v2 = (Scaleform::Mutex *)((char *)this - 24);
  if ( !v1->LockCount )
    return 1;
  if ( !WaitForSingleObject(v1->hMutexOrSemaphore, 0) )
  {
    ++v1->LockCount;
    Scaleform::MutexImpl::Unlock(v1, v2);
    return 1;
  }
  return 0;
}

// File Line: 251
// RVA: 0xA11C20
char __fastcall Scaleform::Mutex::TryAcquire(Scaleform::Mutex *this)
{
  __int64 v1; // rbx

  v1 = *(_QWORD *)&this->RefCount;
  if ( WaitForSingleObject(*(HANDLE *)v1, 0) )
    return 0;
  ++*(_DWORD *)(v1 + 12);
  return 1;
}

// File Line: 260
// RVA: 0xA11C60
char __fastcall Scaleform::Mutex::TryAcquireCancel(Scaleform::Mutex *this)
{
  Scaleform::MutexImpl::Unlock(*(Scaleform::MutexImpl **)&this->RefCount, (Scaleform::Mutex *)((char *)this - 24));
  return 1;
}

// File Line: 324
// RVA: 0xA11140
void __fastcall Scaleform::WaitConditionImpl::~WaitConditionImpl(Scaleform::WaitConditionImpl *this)
{
  Scaleform::WaitConditionImpl::EventPoolEntry *pFreeEventList; // rbx
  HANDLE *v3; // rdi

  pFreeEventList = this->pFreeEventList;
  while ( pFreeEventList )
  {
    v3 = (HANDLE *)pFreeEventList;
    pFreeEventList = pFreeEventList->pNext;
    CloseHandle(*v3);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3);
  }
  this->pFreeEventList = 0i64;
  this->pQueueTail = 0i64;
  this->pQueueHead = 0i64;
  Scaleform::Lock::~Lock(&this->WaitQueueLoc.cs);
}

// File Line: 349
// RVA: 0xA116C0
Scaleform::WaitConditionImpl::EventPoolEntry *__fastcall Scaleform::WaitConditionImpl::GetNewEvent(
        Scaleform::WaitConditionImpl *this)
{
  Scaleform::WaitConditionImpl::EventPoolEntry *result; // rax
  HANDLE *v2; // rbx

  result = this->pFreeEventList;
  if ( result )
  {
    this->pFreeEventList = result->pNext;
  }
  else
  {
    v2 = (HANDLE *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                     Scaleform::Memory::pGlobalHeap,
                     24i64);
    v2[1] = 0i64;
    v2[2] = 0i64;
    *v2 = CreateEventA(0i64, 1, 0, 0i64);
    return (Scaleform::WaitConditionImpl::EventPoolEntry *)v2;
  }
  return result;
}

// File Line: 458
// RVA: 0xA11D80
char __fastcall Scaleform::WaitConditionImpl::Wait(
        Scaleform::WaitConditionImpl *this,
        Scaleform::Mutex *pmutex,
        DWORD delay)
{
  char v3; // r13
  __int64 LockCount; // r15
  Scaleform::WaitConditionImpl::EventPoolEntry *NewEvent; // rdi
  Scaleform::WaitConditionImpl::EventPoolEntry *pQueueTail; // rax
  Scaleform::MutexImpl *pImpl; // rax
  bool v12; // zf
  __int64 v13; // rbx
  DWORD v14; // ebx
  Scaleform::WaitConditionImpl::EventPoolEntry *pQueueHead; // rax
  Scaleform::WaitConditionImpl::EventPoolEntry *pPrev; // rcx
  Scaleform::WaitConditionImpl::EventPoolEntry *pNext; // rax
  Scaleform::WaitConditionImpl::EventPoolEntry *v18; // rcx
  Scaleform::WaitConditionImpl::EventPoolEntry *v19; // rax
  Scaleform::WaitConditionImpl::EventPoolEntry *pFreeEventList; // rax
  __int64 v21; // rdi
  Scaleform::MutexImpl *v22; // rbx

  v3 = 0;
  LockCount = pmutex->pImpl->LockCount;
  if ( !(_DWORD)LockCount )
    return 0;
  EnterCriticalSection(&this->WaitQueueLoc.cs);
  NewEvent = Scaleform::WaitConditionImpl::GetNewEvent(this);
  pQueueTail = this->pQueueTail;
  if ( pQueueTail )
  {
    NewEvent->pPrev = pQueueTail;
    this->pQueueTail->pNext = NewEvent;
    NewEvent->pNext = 0i64;
  }
  else
  {
    NewEvent->pPrev = 0i64;
    NewEvent->pNext = 0i64;
    this->pQueueHead = NewEvent;
  }
  this->pQueueTail = NewEvent;
  LeaveCriticalSection(&this->WaitQueueLoc.cs);
  pImpl = pmutex->pImpl;
  v12 = !pImpl->Recursive;
  pImpl->LockCount = 0;
  if ( v12 )
  {
    ReleaseSemaphore(pmutex->pImpl->hMutexOrSemaphore, 1, 0i64);
  }
  else
  {
    v13 = LockCount;
    do
    {
      ReleaseMutex(pmutex->pImpl->hMutexOrSemaphore);
      --v13;
    }
    while ( v13 );
  }
  Scaleform::Waitable::CallWaitHandlers(pmutex);
  if ( delay == -1 )
    delay = -1;
  v14 = WaitForSingleObject(NewEvent->hEvent, delay);
  EnterCriticalSection(&this->WaitQueueLoc.cs);
  if ( (v14 & 0xFFFFFF7F) != 0 )
  {
    pQueueHead = this->pQueueHead;
    if ( pQueueHead )
    {
      while ( pQueueHead != NewEvent )
      {
        pQueueHead = pQueueHead->pNext;
        if ( !pQueueHead )
          goto LABEL_25;
      }
      pPrev = NewEvent->pPrev;
      pNext = NewEvent->pNext;
      if ( pPrev )
        pPrev->pNext = pNext;
      else
        this->pQueueHead = pNext;
      v18 = NewEvent->pNext;
      v19 = NewEvent->pPrev;
      if ( v18 )
        v18->pPrev = v19;
      else
        this->pQueueTail = v19;
    }
  }
  else
  {
    v3 = 1;
  }
LABEL_25:
  ResetEvent(NewEvent->hEvent);
  pFreeEventList = this->pFreeEventList;
  NewEvent->pPrev = 0i64;
  NewEvent->pNext = pFreeEventList;
  this->pFreeEventList = NewEvent;
  LeaveCriticalSection(&this->WaitQueueLoc.cs);
  v21 = LockCount;
  do
  {
    v22 = pmutex->pImpl;
    if ( !WaitForSingleObject(v22->hMutexOrSemaphore, 0xFFFFFFFF) )
      ++v22->LockCount;
    --v21;
  }
  while ( v21 );
  return v3;
}

// File Line: 555
// RVA: 0xA11860
void __fastcall Scaleform::WaitConditionImpl::NotifyAll(Scaleform::WaitConditionImpl *this)
{
  Scaleform::WaitConditionImpl::EventPoolEntry *pQueueHead; // rcx
  Scaleform::WaitConditionImpl::EventPoolEntry *pNext; // rax
  Scaleform::WaitConditionImpl::EventPoolEntry *v4; // rax

  EnterCriticalSection(&this->WaitQueueLoc.cs);
  pQueueHead = this->pQueueHead;
  if ( pQueueHead )
  {
    if ( pQueueHead->pNext )
    {
      pNext = pQueueHead->pNext;
      this->pQueueHead = pNext;
      pNext->pPrev = 0i64;
    }
    else
    {
      this->pQueueHead = 0i64;
      this->pQueueTail = 0i64;
    }
    while ( 1 )
    {
      SetEvent(pQueueHead->hEvent);
      pQueueHead = this->pQueueHead;
      if ( !pQueueHead )
        break;
      if ( pQueueHead->pNext )
      {
        v4 = pQueueHead->pNext;
        this->pQueueHead = v4;
        v4->pPrev = 0i64;
      }
      else
      {
        this->pQueueHead = 0i64;
        this->pQueueTail = 0i64;
      }
    }
  }
  LeaveCriticalSection(&this->WaitQueueLoc.cs);
}

// File Line: 573
// RVA: 0xA10F00
void __fastcall Scaleform::WaitCondition::WaitCondition(Scaleform::WaitCondition *this)
{
  Scaleform::Lock *v2; // rax
  Scaleform::WaitConditionImpl *v3; // rbx

  v2 = (Scaleform::Lock *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                            Scaleform::Memory::pGlobalHeap,
                            64i64);
  v3 = (Scaleform::WaitConditionImpl *)v2;
  if ( v2 )
  {
    Scaleform::Lock::Lock(v2, 0);
    v3->pFreeEventList = 0i64;
    v3->pQueueTail = 0i64;
    v3->pQueueHead = 0i64;
  }
  else
  {
    v3 = 0i64;
  }
  this->pImpl = v3;
}

// File Line: 577
// RVA: 0xA11100
void __fastcall Scaleform::WaitCondition::~WaitCondition(Scaleform::WaitCondition *this)
{
  Scaleform::WaitConditionImpl *pImpl; // rbx

  pImpl = this->pImpl;
  if ( this->pImpl )
  {
    Scaleform::WaitConditionImpl::~WaitConditionImpl(this->pImpl);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pImpl);
  }
}

// File Line: 583
// RVA: 0xA11D70
bool __fastcall Scaleform::WaitCondition::Wait(
        Scaleform::WaitCondition *this,
        Scaleform::Mutex *pmutex,
        unsigned int delay)
{
  return Scaleform::WaitConditionImpl::Wait(this->pImpl, pmutex, delay);
}

// File Line: 588
// RVA: 0xA117E0
void __fastcall Scaleform::WaitCondition::Notify(Scaleform::WaitCondition *this)
{
  Scaleform::WaitConditionImpl *pImpl; // rbx
  Scaleform::WaitConditionImpl::EventPoolEntry *pQueueHead; // rdx
  Scaleform::WaitConditionImpl::EventPoolEntry *pNext; // rax

  pImpl = this->pImpl;
  EnterCriticalSection(&this->pImpl->WaitQueueLoc.cs);
  pQueueHead = pImpl->pQueueHead;
  if ( pQueueHead )
  {
    if ( pQueueHead->pNext )
    {
      pNext = pQueueHead->pNext;
      pImpl->pQueueHead = pNext;
      pNext->pPrev = 0i64;
    }
    else
    {
      pImpl->pQueueHead = 0i64;
      pImpl->pQueueTail = 0i64;
    }
    SetEvent(pQueueHead->hEvent);
  }
  LeaveCriticalSection(&pImpl->WaitQueueLoc.cs);
}

// File Line: 592
// RVA: 0xA11850
void __fastcall Scaleform::WaitCondition::NotifyAll(Scaleform::WaitCondition *this)
{
  Scaleform::WaitConditionImpl::NotifyAll(this->pImpl);
}

// File Line: 615
// RVA: 0xA10E10
void __fastcall Scaleform::Thread::Thread(Scaleform::Thread *this, unsigned __int64 stackSize, int processor)
{
  Scaleform::Waitable::Waitable(this, 1);
  this->Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable;
  this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Thread::`vftable{for `Scaleform::Waitable};
  this->Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Thread::`vftable{for `Scaleform::AcquireInterface};
  this->ThreadFlags.Value = 0;
  this->ThreadHandle = 0i64;
  this->IdValue = 0i64;
  this->ExitCode = 0;
  this->SuspendCount.Value = 0;
  this->StackSize = stackSize;
  this->Processor = processor;
  this->Priority = NormalPriority;
  this->ThreadFunction = 0i64;
  this->UserHandle = 0i64;
}

// File Line: 626
// RVA: 0xA10D40
void __fastcall Scaleform::Thread::Thread(
        Scaleform::Thread *this,
        int (__fastcall *threadFunction)(Scaleform::Thread *, void *),
        void *userHandle,
        unsigned __int64 stackSize,
        int processor,
        Scaleform::Thread::ThreadState initialState)
{
  Scaleform::Waitable::Waitable(this, 1);
  this->Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable;
  this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Thread::`vftable{for `Scaleform::Waitable};
  this->Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Thread::`vftable{for `Scaleform::AcquireInterface};
  this->ThreadFlags.Value = 0;
  this->ThreadHandle = 0i64;
  this->IdValue = 0i64;
  this->ExitCode = 0;
  this->SuspendCount.Value = 0;
  this->StackSize = stackSize;
  this->Processor = processor;
  this->Priority = NormalPriority;
  this->ThreadFunction = threadFunction;
  this->UserHandle = userHandle;
  if ( initialState )
    ((void (__fastcall *)(Scaleform::Thread *))this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[5].__vecDelDtor)(this);
}

// File Line: 632
// RVA: 0xA10C90
void __fastcall Scaleform::Thread::Thread(Scaleform::Thread *this, Scaleform::Thread::CreateParams *params)
{
  Scaleform::Waitable::Waitable(this, 1);
  this->Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable;
  this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Thread::`vftable{for `Scaleform::Waitable};
  this->Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Thread::`vftable{for `Scaleform::AcquireInterface};
  this->ThreadFlags.Value = 0;
  this->ThreadHandle = 0i64;
  this->IdValue = 0i64;
  this->ExitCode = 0;
  this->SuspendCount.Value = 0;
  this->StackSize = params->stackSize;
  this->Processor = params->processor;
  this->Priority = params->priority;
  this->ThreadFunction = params->threadFunction;
  this->UserHandle = params->userHandle;
  if ( params->initialState )
    ((void (__fastcall *)(Scaleform::Thread *))this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[5].__vecDelDtor)(this);
}

// File Line: 656
// RVA: 0xA11090
void __fastcall Scaleform::Thread::~Thread(Scaleform::Thread *this)
{
  void *ThreadHandle; // rcx

  this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Thread::`vftable{for `Scaleform::Waitable};
  this->Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Thread::`vftable{for `Scaleform::AcquireInterface};
  ThreadHandle = this->ThreadHandle;
  if ( ThreadHandle )
  {
    CloseHandle(ThreadHandle);
    this->ThreadHandle = 0i64;
  }
  this->ThreadHandle = 0i64;
  this->Scaleform::AcquireInterface::vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable;
  Scaleform::Waitable::~Waitable(this);
}

// File Line: 671
// RVA: 0xA11940
int (__fastcall *__fastcall Scaleform::Thread::Run(Scaleform::Thread *this))(Scaleform::Thread *, void *)
{
  int (__fastcall *result)(Scaleform::Thread *, void *); // rax

  result = this->ThreadFunction;
  if ( result )
    return (int (__fastcall *)(Scaleform::Thread *, void *))((__int64 (__fastcall *)(Scaleform::Thread *, void *))result)(
                                                              this,
                                                              this->UserHandle);
  return result;
}

// File Line: 681
// RVA: 0xA11580
void __fastcall Scaleform::Thread::FinishAndRelease(Scaleform::Thread *this)
{
  Scaleform::Waitable::HandlerArray *pHandlers; // rcx
  signed __int32 Value; // ett
  signed __int32 v4; // ett
  Scaleform::Waitable::HandlerArray *v5; // [rsp+40h] [rbp+8h]

  v5 = 0i64;
  pHandlers = this->pHandlers;
  if ( pHandlers )
  {
    _InterlockedExchangeAdd(&pHandlers->RefCount.Value, 1u);
    v5 = pHandlers;
  }
  _m_prefetchw(&this->ThreadFlags);
  do
    Value = this->ThreadFlags.Value;
  while ( Value != _InterlockedCompareExchange((volatile signed __int32 *)&this->ThreadFlags, Value & 0xFFFFFFFE, Value) );
  _m_prefetchw(&this->ThreadFlags);
  do
    v4 = this->ThreadFlags.Value;
  while ( v4 != _InterlockedCompareExchange((volatile signed __int32 *)&this->ThreadFlags, v4 | 2, v4) );
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)this);
  if ( v5 )
    Scaleform::Waitable::HandlerArray::CallWaitHandlers(v5);
  if ( v5 )
    Scaleform::Waitable::HandlerArray::Release(v5);
}

// File Line: 722
// RVA: 0xA11F40
void __fastcall Scaleform::ThreadList::addThread(Scaleform::ThreadList *this, Scaleform::Thread *pthread)
{
  Scaleform::Thread *v2; // rsi
  Scaleform::Mutex *p_ThreadMutex; // rbx
  Scaleform::MutexImpl **p_pImpl; // r14
  Scaleform::MutexImpl *pImpl; // rdi
  Scaleform::Mutex *v7; // [rsp+50h] [rbp+8h]
  Scaleform::Thread *key; // [rsp+58h] [rbp+10h] BYREF

  key = pthread;
  v2 = pthread;
  p_ThreadMutex = &this->ThreadMutex;
  v7 = &this->ThreadMutex;
  p_pImpl = &this->ThreadMutex.pImpl;
  pImpl = this->ThreadMutex.pImpl;
  if ( !WaitForSingleObject(pImpl->hMutexOrSemaphore, 0xFFFFFFFF) )
  {
    ++pImpl->LockCount;
    v2 = key;
    p_ThreadMutex = v7;
  }
  Scaleform::HashSetBase<Scaleform::Thread *,Scaleform::ThreadList::ThreadHashOp,Scaleform::ThreadList::ThreadHashOp,Scaleform::AllocatorGH<Scaleform::Thread *,2>,Scaleform::HashsetCachedEntry<Scaleform::Thread *,Scaleform::ThreadList::ThreadHashOp>>::add<Scaleform::Thread *>(
    &this->ThreadSet,
    this,
    &key,
    (unsigned __int64)v2 ^ ((unsigned __int64)v2 >> 6));
  Scaleform::MutexImpl::Unlock(*p_pImpl, p_ThreadMutex);
}

// File Line: 728
// RVA: 0xA12060
void __fastcall Scaleform::ThreadList::removeThread(Scaleform::ThreadList *this, Scaleform::Thread *pthread)
{
  Scaleform::Mutex *p_ThreadMutex; // rbx
  Scaleform::MutexImpl **p_pImpl; // r14
  Scaleform::MutexImpl *pImpl; // rsi
  Scaleform::Mutex *v6; // [rsp+50h] [rbp+8h]
  Scaleform::Thread *key; // [rsp+58h] [rbp+10h] BYREF

  key = pthread;
  p_ThreadMutex = &this->ThreadMutex;
  v6 = &this->ThreadMutex;
  p_pImpl = &this->ThreadMutex.pImpl;
  pImpl = this->ThreadMutex.pImpl;
  if ( !WaitForSingleObject(pImpl->hMutexOrSemaphore, 0xFFFFFFFF) )
  {
    ++pImpl->LockCount;
    p_ThreadMutex = v6;
  }
  Scaleform::HashSetBase<Scaleform::Thread *,Scaleform::ThreadList::ThreadHashOp,Scaleform::ThreadList::ThreadHashOp,Scaleform::AllocatorGH<Scaleform::Thread *,2>,Scaleform::HashsetCachedEntry<Scaleform::Thread *,Scaleform::ThreadList::ThreadHashOp>>::RemoveAlt<Scaleform::Thread *>(
    &this->ThreadSet,
    &key);
  if ( !this->ThreadSet.pTable || !this->ThreadSet.pTable->EntryCount )
    Scaleform::WaitCondition::Notify(&this->ThreadsEmpty);
  Scaleform::MutexImpl::Unlock(*p_pImpl, p_ThreadMutex);
}

// File Line: 736
// RVA: 0xA11FD0
void __fastcall Scaleform::ThreadList::finishAllThreads(Scaleform::ThreadList *this)
{
  Scaleform::Mutex *p_ThreadMutex; // rbx
  Scaleform::MutexImpl **p_pImpl; // r15
  Scaleform::MutexImpl *pImpl; // r14
  Scaleform::Mutex *v5; // [rsp+50h] [rbp+8h]

  p_ThreadMutex = &this->ThreadMutex;
  v5 = &this->ThreadMutex;
  p_pImpl = &this->ThreadMutex.pImpl;
  pImpl = this->ThreadMutex.pImpl;
  if ( !WaitForSingleObject(pImpl->hMutexOrSemaphore, 0xFFFFFFFF) )
  {
    ++pImpl->LockCount;
    p_ThreadMutex = v5;
  }
  while ( this->ThreadSet.pTable && this->ThreadSet.pTable->EntryCount )
    Scaleform::WaitConditionImpl::Wait(this->ThreadsEmpty.pImpl, &this->ThreadMutex, 0xFFFFFFFF);
  Scaleform::MutexImpl::Unlock(*p_pImpl, p_ThreadMutex);
}

// File Line: 744
// RVA: 0xA10EB0
void __fastcall Scaleform::ThreadList::ThreadList(Scaleform::ThreadList *this)
{
  this->ThreadSet.pTable = 0i64;
  Scaleform::Mutex::Mutex(&this->ThreadMutex, 1, 0);
  Scaleform::WaitCondition::WaitCondition(&this->ThreadsEmpty);
  this->RootThreadId = (void *)GetCurrentThreadId();
}

// File Line: 752
// RVA: 0xA11320
void __fastcall Scaleform::ThreadList::AddRunningThread(Scaleform::Thread *pthread)
{
  Scaleform::ThreadList *v2; // rax

  if ( !Scaleform::ThreadList::pRunningThreads )
  {
    v2 = (Scaleform::ThreadList *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                    Scaleform::Memory::pGlobalHeap,
                                    64i64);
    if ( v2 )
      Scaleform::ThreadList::ThreadList(v2);
    Scaleform::ThreadList::pRunningThreads = v2;
  }
  Scaleform::ThreadList::addThread(Scaleform::ThreadList::pRunningThreads, pthread);
}

// File Line: 772
// RVA: 0xA114C0
void Scaleform::ThreadList::FinishAllThreads(void)
{
  Scaleform::WaitConditionImpl *pImpl; // rdi
  Scaleform::ThreadList *volatile v1; // [rsp+40h] [rbp+8h]

  if ( Scaleform::ThreadList::pRunningThreads )
  {
    Scaleform::ThreadList::finishAllThreads(Scaleform::ThreadList::pRunningThreads);
    v1 = Scaleform::ThreadList::pRunningThreads;
    if ( Scaleform::ThreadList::pRunningThreads )
    {
      pImpl = Scaleform::ThreadList::pRunningThreads->ThreadsEmpty.pImpl;
      if ( pImpl )
      {
        Scaleform::WaitConditionImpl::~WaitConditionImpl(Scaleform::ThreadList::pRunningThreads->ThreadsEmpty.pImpl);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pImpl);
      }
      Scaleform::Mutex::~Mutex(&v1->ThreadMutex);
      Scaleform::HashSet<Scaleform::Thread *,Scaleform::ThreadList::ThreadHashOp,Scaleform::ThreadList::ThreadHashOp,Scaleform::AllocatorGH<Scaleform::Thread *,2>,Scaleform::HashsetCachedEntry<Scaleform::Thread *,Scaleform::ThreadList::ThreadHashOp>>::~HashSet<Scaleform::Thread *,Scaleform::ThreadList::ThreadHashOp,Scaleform::ThreadList::ThreadHashOp,Scaleform::AllocatorGH<Scaleform::Thread *,2>,Scaleform::HashsetCachedEntry<Scaleform::Thread *,Scaleform::ThreadList::ThreadHashOp>>(&v1->ThreadSet);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1);
    }
    Scaleform::ThreadList::pRunningThreads = 0i64;
  }
}

// File Line: 789
// RVA: 0xA114B0
// attributes: thunk
void Scaleform::Thread::FinishAllThreads(void)
{
  Scaleform::ThreadList::FinishAllThreads();
}

// File Line: 831
// RVA: 0xA116B0
__int64 __fastcall Scaleform::Thread::GetExitFlag(Scaleform::Thread *this)
{
  return (this->ThreadFlags.Value >> 4) & 1;
}

// File Line: 836
// RVA: 0xA11960
void __fastcall Scaleform::Thread::SetExitFlag(Scaleform::Thread *this, bool exitFlag)
{
  signed __int32 Value; // ett
  signed __int32 v3; // ett

  _m_prefetchw(&this->ThreadFlags);
  if ( exitFlag )
  {
    do
      Value = this->ThreadFlags.Value;
    while ( Value != _InterlockedCompareExchange((volatile signed __int32 *)&this->ThreadFlags, Value | 0x10, Value) );
  }
  else
  {
    do
      v3 = this->ThreadFlags.Value;
    while ( v3 != _InterlockedCompareExchange((volatile signed __int32 *)&this->ThreadFlags, v3 & 0xFFFFFFEF, v3) );
  }
}

// File Line: 852
// RVA: 0xA117B0
bool __fastcall Scaleform::Thread::IsSuspended(Scaleform::Thread *this)
{
  return this->SuspendCount.Value > 0;
}

// File Line: 857
// RVA: 0xA11730
__int64 __fastcall Scaleform::Thread::GetThreadState(Scaleform::Thread *this)
{
  if ( this->SuspendCount.Value <= 0 )
    return this->ThreadFlags.Value & 1;
  else
    return 2i64;
}

// File Line: 886
// RVA: 0xA11AF0
__int64 __fastcall Scaleform::Thread_Win32StartFn(Scaleform::Thread *phandle)
{
  unsigned int Processor; // ebx
  HANDLE CurrentThread; // rax
  int v4; // ebx
  HANDLE v5; // rax
  signed __int32 Value; // ett
  unsigned int v7; // ebx

  if ( phandle->Processor != -1 )
  {
    Processor = phandle->Processor;
    CurrentThread = GetCurrentThread();
    SetThreadAffinityMask(CurrentThread, Processor);
  }
  switch ( phandle->Priority )
  {
    case CriticalPriority:
      v4 = 15;
      break;
    case HighestPriority:
      v4 = 2;
      break;
    case AboveNormalPriority:
      v4 = 1;
      break;
    case BelowNormalPriority:
      v4 = -1;
      break;
    case LowestPriority:
      v4 = -2;
      break;
    case IdlePriority:
      v4 = -15;
      break;
    default:
      v4 = 0;
      break;
  }
  v5 = GetCurrentThread();
  SetThreadPriority(v5, v4);
  phandle->IdValue = (void *volatile)GetCurrentThreadId();
  if ( (phandle->ThreadFlags.Value & 8) != 0 )
  {
    if ( (phandle->ThreadFlags.Value & 1) != 0 && SuspendThread(phandle->ThreadHandle) != -1 )
      _InterlockedExchangeAdd(&phandle->SuspendCount.Value, 1u);
    _m_prefetchw(&phandle->ThreadFlags);
    do
      Value = phandle->ThreadFlags.Value;
    while ( Value != _InterlockedCompareExchange(
                       (volatile signed __int32 *)&phandle->ThreadFlags,
                       Value & 0xFFFFFFF7,
                       Value) );
  }
  v7 = ((__int64 (__fastcall *)(Scaleform::Thread *))phandle->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[3].__vecDelDtor)(phandle);
  phandle->ExitCode = v7;
  Scaleform::Thread::FinishAndRelease(phandle);
  Scaleform::ThreadList::removeThread(Scaleform::ThreadList::pRunningThreads, phandle);
  return v7;
}

// File Line: 919
// RVA: 0xA119C0
char __fastcall Scaleform::Thread::Start(Scaleform::Thread *this, Scaleform::Thread::ThreadState initialState)
{
  void *ThreadHandle; // rcx
  volatile unsigned int v6; // eax
  void *v7; // rax

  if ( initialState == NotRunning
    || (this->SuspendCount.Value > 0 || (this->ThreadFlags.Value & 1) != 0)
    && !Scaleform::Waitable::Wait(this, 0xFFFFFFFF) )
  {
    return 0;
  }
  ThreadHandle = this->ThreadHandle;
  if ( ThreadHandle )
  {
    CloseHandle(ThreadHandle);
    this->ThreadHandle = 0i64;
  }
  Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)this);
  Scaleform::ThreadList::AddRunningThread(this);
  this->ExitCode = 0;
  this->SuspendCount.Value = 0;
  v6 = 8;
  if ( initialState == Running )
    v6 = 1;
  this->ThreadFlags.Value = v6;
  v7 = (void *)beginthreadex(
                 0i64,
                 this->StackSize,
                 Scaleform::Thread_Win32StartFn,
                 this,
                 0,
                 (unsigned int *)&this->IdValue);
  this->ThreadHandle = v7;
  if ( v7 )
    return 1;
  this->ThreadFlags.Value = 0;
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)this);
  Scaleform::ThreadList::removeThread(Scaleform::ThreadList::pRunningThreads, this);
  return 0;
}

// File Line: 955
// RVA: 0xA11AB0
char __fastcall Scaleform::Thread::Suspend(Scaleform::Thread *this)
{
  if ( (this->ThreadFlags.Value & 1) == 0 || SuspendThread(this->ThreadHandle) == -1 )
    return 0;
  _InterlockedExchangeAdd(&this->SuspendCount.Value, 1u);
  return 1;
}

// File Line: 972
// RVA: 0xA11900
bool __fastcall Scaleform::Thread::Resume(Scaleform::Thread *this)
{
  int v1; // eax
  bool result; // al

  result = 0;
  if ( (this->ThreadFlags.Value & 1) != 0 )
  {
    v1 = _InterlockedExchangeAdd(&this->SuspendCount.Value, 0xFFFFFFFF);
    if ( v1 >= 1 && (v1 != 1 || ResumeThread(this->ThreadHandle) != -1) )
      return 1;
  }
  return result;
}

// File Line: 999
// RVA: 0xA11470
void __fastcall __noreturn Scaleform::Thread::Exit(Scaleform::Thread *this, unsigned int exitCode)
{
  ((void (__fastcall *)(Scaleform::Thread *))this->Scaleform::Waitable::Scaleform::RefCountBase<Scaleform::Waitable,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[4].__vecDelDtor)(this);
  Scaleform::Thread::FinishAndRelease(this);
  Scaleform::ThreadList::removeThread(Scaleform::ThreadList::pRunningThreads, this);
  endthreadex(exitCode);
}

// File Line: 1032
// RVA: 0xA119A0
char __fastcall Scaleform::Thread::Sleep(unsigned int secs)
{
  Sleep(1000 * secs);
  return 1;
}

// File Line: 1038
// RVA: 0xA117C0
char __fastcall Scaleform::Thread::MSleep(DWORD msecs)
{
  Sleep(msecs);
  return 1;
}

// File Line: 1084
// RVA: 0xA11690
__int64 __fastcall Scaleform::Thread::GetCPUCount()
{
  _SYSTEM_INFO SystemInfo; // [rsp+20h] [rbp-38h] BYREF

  GetSystemInfo(&SystemInfo);
  return SystemInfo.dwNumberOfProcessors;
}

