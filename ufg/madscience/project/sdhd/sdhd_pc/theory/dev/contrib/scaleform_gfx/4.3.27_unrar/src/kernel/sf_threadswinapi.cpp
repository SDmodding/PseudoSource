// File Line: 65
// RVA: 0xA11C50
__int64 __fastcall Scaleform::Mutex_AreadyLockedAcquireInterface::TryAcquire(Scaleform::Mutex_AreadyLockedAcquireInterface *this)
{
  return this->pMutex->vfptr->TryAcquire((Scaleform::AcquireInterface *)&this->pMutex->vfptr);
}

// File Line: 66
// RVA: 0xA11C90
__int64 __fastcall Scaleform::Mutex_AreadyLockedAcquireInterface::TryAcquireCommit(Scaleform::Mutex_AreadyLockedAcquireInterface *this)
{
  return this->pMutex->vfptr->TryAcquireCommit((Scaleform::AcquireInterface *)&this->pMutex->vfptr);
}

// File Line: 67
// RVA: 0xA11C80
__int64 __fastcall Scaleform::Mutex_AreadyLockedAcquireInterface::TryAcquireCancel(Scaleform::Mutex_AreadyLockedAcquireInterface *this)
{
  return this->pMutex->vfptr->TryAcquireCancel((Scaleform::AcquireInterface *)&this->pMutex->vfptr);
}

// File Line: 119
// RVA: 0xA10C10
void __fastcall Scaleform::MutexImpl::MutexImpl(Scaleform::MutexImpl *this, Scaleform::Mutex *pmutex, bool recursive)
{
  Scaleform::MutexImpl *v3; // rbx
  HANDLE v4; // rax
  Scaleform::Mutex_AreadyLockedAcquireInterface *v5; // [rsp+48h] [rbp+10h]

  v3 = this;
  v5 = &this->AreadyLockedAcquire;
  v5->vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable';
  *(_OWORD *)&v5->vfptr = (unsigned __int64)&Scaleform::Mutex_AreadyLockedAcquireInterface::`vftable';
  this->AreadyLockedAcquire.pMutex = pmutex;
  this->Recursive = recursive;
  this->LockCount = 0;
  if ( this->Recursive )
    v4 = CreateMutexA(0i64, 0, 0i64);
  else
    v4 = CreateSemaphoreA(0i64, 1, 1, 0i64);
  v3->hMutexOrSemaphore = v4;
}

// File Line: 149
// RVA: 0xA11CE0
void __fastcall Scaleform::MutexImpl::Unlock(Scaleform::MutexImpl *this, Scaleform::Mutex *pmutex)
{
  volatile unsigned int v2; // edi
  Scaleform::Waitable::HandlerArray *v3; // rbx
  Scaleform::Waitable::HandlerArray *v4; // rax
  bool v5; // zf
  void *v6; // rcx
  BOOL v7; // eax

  v2 = --this->LockCount;
  v3 = 0i64;
  v4 = pmutex->pHandlers;
  if ( v4 )
  {
    v3 = pmutex->pHandlers;
    _InterlockedExchangeAdd(&v4->RefCount.Value, 1u);
  }
  v5 = this->Recursive == 0;
  v6 = this->hMutexOrSemaphore;
  if ( v5 )
    v7 = ReleaseSemaphore(v6, 1, 0i64);
  else
    v7 = ReleaseMutex(v6);
  if ( v7 && !v2 && v3 )
    Scaleform::Waitable::HandlerArray::CallWaitHandlers(v3);
  if ( v3 )
    Scaleform::Waitable::HandlerArray::Release(v3);
}

// File Line: 209
// RVA: 0xA10B80
void __fastcall Scaleform::Mutex::Mutex(Scaleform::Mutex *this, bool recursive, bool multiWait)
{
  bool v3; // di
  Scaleform::Mutex *v4; // rbx
  Scaleform::MutexImpl *v5; // rax

  v3 = recursive;
  v4 = this;
  Scaleform::Waitable::Waitable((Scaleform::Waitable *)&this->vfptr, multiWait);
  v4->vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable';
  v4->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Mutex::`vftable'{for `Scaleform::Waitable'};
  v4->vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Mutex::`vftable'{for `Scaleform::AcquireInterface'};
  v5 = (Scaleform::MutexImpl *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                 Scaleform::Memory::pGlobalHeap,
                                 32i64);
  if ( v5 )
    Scaleform::MutexImpl::MutexImpl(v5, v4, v3);
  v4->pImpl = v5;
}

// File Line: 214
// RVA: 0xA10FE0
void __fastcall Scaleform::Mutex::~Mutex(Scaleform::Mutex *this)
{
  Scaleform::Mutex *v1; // rbx
  Scaleform::MutexImpl *v2; // rdi

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Mutex::`vftable'{for `Scaleform::Waitable'};
  this->vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Mutex::`vftable'{for `Scaleform::AcquireInterface'};
  v2 = this->pImpl;
  if ( v2 )
  {
    CloseHandle(v2->hMutexOrSemaphore);
    v2->AreadyLockedAcquire.vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable';
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v2);
  }
  v1->vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable';
  Scaleform::Waitable::~Waitable((Scaleform::Waitable *)&v1->vfptr);
}

// File Line: 220
// RVA: 0xA11440
void __fastcall Scaleform::Mutex::DoLock(Scaleform::Mutex *this)
{
  Scaleform::MutexImpl *v1; // rbx

  v1 = this->pImpl;
  if ( !WaitForSingleObject(v1->hMutexOrSemaphore, 0xFFFFFFFF) )
    ++v1->LockCount;
}

// File Line: 224
// RVA: 0xA11CA0
char __fastcall Scaleform::Mutex::TryLock(Scaleform::Mutex *this)
{
  Scaleform::MutexImpl *v1; // rbx

  v1 = this->pImpl;
  if ( WaitForSingleObject(v1->hMutexOrSemaphore, 0) )
    return 0;
  ++v1->LockCount;
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
  Scaleform::MutexImpl *v1; // rbx
  Scaleform::Mutex *v2; // rdi

  v1 = this->pImpl;
  v2 = this;
  if ( !v1->LockCount )
    return 0;
  if ( !WaitForSingleObject(v1->hMutexOrSemaphore, 0) )
  {
    ++v1->LockCount;
    Scaleform::MutexImpl::Unlock(v1, v2);
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
  Scaleform::MutexImpl *v1; // rbx
  Scaleform::Mutex *v2; // rdi

  v1 = this->pImpl;
  v2 = this;
  if ( v1->LockCount )
  {
    if ( !v1->LockCount )
      return &v1->AreadyLockedAcquire;
    if ( !WaitForSingleObject(v1->hMutexOrSemaphore, 0) )
    {
      ++v1->LockCount;
      Scaleform::MutexImpl::Unlock(v1, v2);
      return &v1->AreadyLockedAcquire;
    }
  }
  return (Scaleform::Mutex_AreadyLockedAcquireInterface *)&v2->vfptr;
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
  Scaleform::WaitConditionImpl *v1; // rsi
  Scaleform::WaitConditionImpl::EventPoolEntry *v2; // rbx
  HANDLE *v3; // rdi

  v1 = this;
  v2 = this->pFreeEventList;
  while ( v2 )
  {
    v3 = (HANDLE *)v2;
    v2 = v2->pNext;
    CloseHandle(*v3);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3);
  }
  v1->pFreeEventList = 0i64;
  v1->pQueueTail = 0i64;
  v1->pQueueHead = 0i64;
  Scaleform::Lock::~Lock(&v1->WaitQueueLoc.cs);
}

// File Line: 349
// RVA: 0xA116C0
Scaleform::WaitConditionImpl::EventPoolEntry *__fastcall Scaleform::WaitConditionImpl::GetNewEvent(Scaleform::WaitConditionImpl *this)
{
  Scaleform::WaitConditionImpl::EventPoolEntry *result; // rax
  Scaleform::WaitConditionImpl::EventPoolEntry *v2; // rax
  Scaleform::WaitConditionImpl::EventPoolEntry *v3; // rbx

  result = this->pFreeEventList;
  if ( result )
  {
    this->pFreeEventList = result->pNext;
  }
  else
  {
    v2 = (Scaleform::WaitConditionImpl::EventPoolEntry *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                           Scaleform::Memory::pGlobalHeap,
                                                           24i64);
    v3 = v2;
    v2->pNext = 0i64;
    v2->pPrev = 0i64;
    v2->hEvent = CreateEventA(0i64, 1, 0, 0i64);
    result = v3;
  }
  return result;
}

// File Line: 458
// RVA: 0xA11D80
char __fastcall Scaleform::WaitConditionImpl::Wait(Scaleform::WaitConditionImpl *this, Scaleform::Mutex *pmutex, unsigned int delay)
{
  char v3; // r13
  unsigned int v4; // er12
  __int64 v5; // r15
  HANDLE **v6; // rbp
  Scaleform::WaitConditionImpl *v7; // rsi
  Scaleform::WaitConditionImpl::EventPoolEntry *v9; // rdi
  Scaleform::WaitConditionImpl::EventPoolEntry *v10; // rax
  HANDLE *v11; // rax
  bool v12; // zf
  __int64 v13; // rbx
  DWORD v14; // ebx
  Scaleform::WaitConditionImpl::EventPoolEntry *v15; // rax
  Scaleform::WaitConditionImpl::EventPoolEntry *v16; // rcx
  Scaleform::WaitConditionImpl::EventPoolEntry *v17; // rax
  Scaleform::WaitConditionImpl::EventPoolEntry *v18; // rcx
  Scaleform::WaitConditionImpl::EventPoolEntry *v19; // rax
  Scaleform::WaitConditionImpl::EventPoolEntry *v20; // rax
  __int64 v21; // rdi
  HANDLE *v22; // rbx

  v3 = 0;
  v4 = delay;
  v5 = pmutex->pImpl->LockCount;
  v6 = (HANDLE **)pmutex;
  v7 = this;
  if ( !(_DWORD)v5 )
    return 0;
  EnterCriticalSection(&this->WaitQueueLoc.cs);
  v9 = Scaleform::WaitConditionImpl::GetNewEvent(v7);
  v10 = v7->pQueueTail;
  if ( v10 )
  {
    v9->pPrev = v10;
    v7->pQueueTail->pNext = v9;
    v9->pNext = 0i64;
  }
  else
  {
    v9->pPrev = 0i64;
    v9->pNext = 0i64;
    v7->pQueueHead = v9;
  }
  v7->pQueueTail = v9;
  LeaveCriticalSection(&v7->WaitQueueLoc.cs);
  v11 = v6[4];
  v12 = *((_BYTE *)v11 + 8) == 0;
  *((_DWORD *)v11 + 3) = 0;
  if ( v12 )
  {
    ReleaseSemaphore(*v6[4], 1, 0i64);
  }
  else if ( (_DWORD)v5 )
  {
    v13 = v5;
    do
    {
      ReleaseMutex(*v6[4]);
      --v13;
    }
    while ( v13 );
  }
  Scaleform::Waitable::CallWaitHandlers(v6);
  if ( v4 == -1 )
    v4 = -1;
  v14 = WaitForSingleObject(v9->hEvent, v4);
  EnterCriticalSection(&v7->WaitQueueLoc.cs);
  if ( v14 & 0xFFFFFF7F )
  {
    v15 = v7->pQueueHead;
    if ( v15 )
    {
      while ( v15 != v9 )
      {
        v15 = v15->pNext;
        if ( !v15 )
          goto LABEL_26;
      }
      v16 = v9->pPrev;
      v17 = v9->pNext;
      if ( v16 )
        v16->pNext = v17;
      else
        v7->pQueueHead = v17;
      v18 = v9->pNext;
      v19 = v9->pPrev;
      if ( v18 )
        v18->pPrev = v19;
      else
        v7->pQueueTail = v19;
    }
  }
  else
  {
    v3 = 1;
  }
LABEL_26:
  ResetEvent(v9->hEvent);
  v20 = v7->pFreeEventList;
  v9->pPrev = 0i64;
  v9->pNext = v20;
  v7->pFreeEventList = v9;
  LeaveCriticalSection(&v7->WaitQueueLoc.cs);
  if ( (_DWORD)v5 )
  {
    v21 = v5;
    do
    {
      v22 = v6[4];
      if ( !WaitForSingleObject(*v22, 0xFFFFFFFF) )
        ++*((_DWORD *)v22 + 3);
      --v21;
    }
    while ( v21 );
  }
  return v3;
}

// File Line: 555
// RVA: 0xA11860
void __fastcall Scaleform::WaitConditionImpl::NotifyAll(Scaleform::WaitConditionImpl *this)
{
  Scaleform::WaitConditionImpl *v1; // rbx
  Scaleform::WaitConditionImpl::EventPoolEntry *v2; // rcx
  Scaleform::WaitConditionImpl::EventPoolEntry *v3; // rax
  Scaleform::WaitConditionImpl::EventPoolEntry *v4; // rax

  v1 = this;
  EnterCriticalSection(&this->WaitQueueLoc.cs);
  v2 = v1->pQueueHead;
  if ( v2 )
  {
    if ( v2->pNext )
    {
      v3 = v2->pNext;
      v1->pQueueHead = v3;
      v3->pPrev = 0i64;
    }
    else
    {
      v1->pQueueHead = 0i64;
      v1->pQueueTail = 0i64;
    }
    while ( v2 )
    {
      SetEvent(v2->hEvent);
      v2 = v1->pQueueHead;
      if ( !v2 )
        break;
      if ( v2->pNext )
      {
        v4 = v2->pNext;
        v1->pQueueHead = v4;
        v4->pPrev = 0i64;
      }
      else
      {
        v1->pQueueHead = 0i64;
        v1->pQueueTail = 0i64;
      }
    }
  }
  LeaveCriticalSection(&v1->WaitQueueLoc.cs);
}

// File Line: 573
// RVA: 0xA10F00
void __fastcall Scaleform::WaitCondition::WaitCondition(Scaleform::WaitCondition *this)
{
  Scaleform::WaitCondition *v1; // rdi
  Scaleform::Lock *v2; // rax
  Scaleform::WaitConditionImpl *v3; // rbx

  v1 = this;
  v2 = (Scaleform::Lock *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
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
  v1->pImpl = v3;
}

// File Line: 577
// RVA: 0xA11100
void __fastcall Scaleform::WaitCondition::~WaitCondition(Scaleform::WaitCondition *this)
{
  Scaleform::WaitConditionImpl *v1; // rbx

  v1 = this->pImpl;
  if ( this->pImpl )
  {
    Scaleform::WaitConditionImpl::~WaitConditionImpl(this->pImpl);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1);
  }
}

// File Line: 583
// RVA: 0xA11D70
bool __fastcall Scaleform::WaitCondition::Wait(Scaleform::WaitCondition *this, Scaleform::Mutex *pmutex, unsigned int delay)
{
  return Scaleform::WaitConditionImpl::Wait(this->pImpl, pmutex, delay);
}

// File Line: 588
// RVA: 0xA117E0
void __fastcall Scaleform::WaitCondition::Notify(Scaleform::WaitCondition *this)
{
  Scaleform::WaitConditionImpl *v1; // rbx
  Scaleform::WaitConditionImpl::EventPoolEntry *v2; // rdx
  Scaleform::WaitConditionImpl::EventPoolEntry *v3; // rax

  v1 = this->pImpl;
  EnterCriticalSection(&this->pImpl->WaitQueueLoc.cs);
  v2 = v1->pQueueHead;
  if ( v2 )
  {
    if ( v2->pNext )
    {
      v3 = v2->pNext;
      v1->pQueueHead = v3;
      v3->pPrev = 0i64;
    }
    else
    {
      v1->pQueueHead = 0i64;
      v1->pQueueTail = 0i64;
    }
    SetEvent(v2->hEvent);
  }
  LeaveCriticalSection(&v1->WaitQueueLoc.cs);
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
  int v3; // edi
  unsigned __int64 v4; // rbx
  Scaleform::Thread *v5; // rsi
  volatile unsigned int v6; // et1
  volatile unsigned int v7; // et1
  volatile int v8; // et1
  volatile int v9; // et1

  v3 = processor;
  v4 = stackSize;
  v5 = this;
  Scaleform::Waitable::Waitable((Scaleform::Waitable *)&this->vfptr, 1);
  v5->vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable';
  v5->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Thread::`vftable'{for `Scaleform::Waitable'};
  v5->vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Thread::`vftable'{for `Scaleform::AcquireInterface'};
  v6 = v5->ThreadFlags.Value;
  v7 = v5->ThreadFlags.Value;
  v8 = v5->SuspendCount.Value;
  v9 = v5->SuspendCount.Value;
  v5->ThreadFlags.Value = 0;
  v5->ThreadHandle = 0i64;
  v5->IdValue = 0i64;
  v5->ExitCode = 0;
  v5->SuspendCount.Value = 0;
  v5->StackSize = v4;
  v5->Processor = v3;
  v5->Priority = 3;
  v5->ThreadFunction = 0i64;
  v5->UserHandle = 0i64;
}

// File Line: 626
// RVA: 0xA10D40
void __fastcall Scaleform::Thread::Thread(Scaleform::Thread *this, int (__fastcall *threadFunction)(Scaleform::Thread *, void *), void *userHandle, unsigned __int64 stackSize, int processor, Scaleform::Thread::ThreadState initialState)
{
  unsigned __int64 v6; // rbx
  void *v7; // rsi
  int (__fastcall *v8)(Scaleform::Thread *, void *); // rdi
  Scaleform::Thread *v9; // r14
  volatile unsigned int v10; // et1
  volatile unsigned int v11; // et1
  volatile int v12; // et1
  volatile int v13; // et1

  v6 = stackSize;
  v7 = userHandle;
  v8 = threadFunction;
  v9 = this;
  Scaleform::Waitable::Waitable((Scaleform::Waitable *)&this->vfptr, 1);
  v9->vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable';
  v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Thread::`vftable'{for `Scaleform::Waitable'};
  v9->vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Thread::`vftable'{for `Scaleform::AcquireInterface'};
  v10 = v9->ThreadFlags.Value;
  v11 = v9->ThreadFlags.Value;
  v12 = v9->SuspendCount.Value;
  v13 = v9->SuspendCount.Value;
  v9->ThreadFlags.Value = 0;
  v9->ThreadHandle = 0i64;
  v9->IdValue = 0i64;
  v9->ExitCode = 0;
  v9->SuspendCount.Value = 0;
  v9->StackSize = v6;
  v9->Processor = processor;
  v9->Priority = 3;
  v9->ThreadFunction = v8;
  v9->UserHandle = v7;
  if ( initialState )
    ((void (__fastcall *)(Scaleform::Thread *))v9->vfptr[5].__vecDelDtor)(v9);
}

// File Line: 632
// RVA: 0xA10C90
void __fastcall Scaleform::Thread::Thread(Scaleform::Thread *this, Scaleform::Thread::CreateParams *params)
{
  Scaleform::Thread::CreateParams *v2; // rbx
  Scaleform::Thread *v3; // rdi
  volatile unsigned int v4; // et1
  volatile unsigned int v5; // et1
  volatile int v6; // et1
  volatile int v7; // et1

  v2 = params;
  v3 = this;
  Scaleform::Waitable::Waitable((Scaleform::Waitable *)&this->vfptr, 1);
  v3->vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable';
  v3->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Thread::`vftable'{for `Scaleform::Waitable'};
  v3->vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Thread::`vftable'{for `Scaleform::AcquireInterface'};
  v4 = v3->ThreadFlags.Value;
  v5 = v3->ThreadFlags.Value;
  v6 = v3->SuspendCount.Value;
  v7 = v3->SuspendCount.Value;
  v3->ThreadFlags.Value = 0;
  v3->ThreadHandle = 0i64;
  v3->IdValue = 0i64;
  v3->ExitCode = 0;
  v3->SuspendCount.Value = 0;
  v3->StackSize = v2->stackSize;
  v3->Processor = v2->processor;
  v3->Priority = v2->priority;
  v3->ThreadFunction = v2->threadFunction;
  v3->UserHandle = v2->userHandle;
  if ( v2->initialState )
    ((void (__fastcall *)(Scaleform::Thread *))v3->vfptr[5].__vecDelDtor)(v3);
}

// File Line: 656
// RVA: 0xA11090
void __fastcall Scaleform::Thread::~Thread(Scaleform::Thread *this)
{
  Scaleform::Thread *v1; // rbx
  void *v2; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Thread::`vftable'{for `Scaleform::Waitable'};
  this->vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Thread::`vftable'{for `Scaleform::AcquireInterface'};
  v2 = this->ThreadHandle;
  if ( v2 )
  {
    CloseHandle(v2);
    v1->ThreadHandle = 0i64;
  }
  v1->ThreadHandle = 0i64;
  v1->vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable';
  Scaleform::Waitable::~Waitable((Scaleform::Waitable *)&v1->vfptr);
}

// File Line: 671
// RVA: 0xA11940
int (__fastcall *__fastcall Scaleform::Thread::Run(Scaleform::Thread *this))(Scaleform::Thread *, void *)
{
  int (__fastcall *result)(Scaleform::Thread *, void *); // rax

  result = this->ThreadFunction;
  if ( result )
    result = (int (__fastcall *)(Scaleform::Thread *, void *))result(this, this->UserHandle);
  return result;
}

// File Line: 681
// RVA: 0xA11580
void __fastcall Scaleform::Thread::FinishAndRelease(Scaleform::Thread *this)
{
  Scaleform::Waitable::HandlerArray *v2; // rcx
  signed __int32 v3; // eax
  signed __int32 v4; // eax
  Scaleform::Waitable::HandlerArray *v5; // [rsp+40h] [rbp+8h]

  _RDX = this;
  v5 = 0i64;
  v2 = this->pHandlers;
  if ( v2 )
  {
    _InterlockedExchangeAdd(&v2->RefCount.Value, 1u);
    v5 = v2;
  }
  __asm { prefetchw byte ptr [rdx+30h]; Prefetch processor cache line into L1 data cache (mark as modified) }
  do
    v3 = _RDX->ThreadFlags.Value;
  while ( v3 != _InterlockedCompareExchange(
                  (volatile signed __int32 *)&_RDX->ThreadFlags,
                  _RDX->ThreadFlags.Value & 0xFFFFFFFE,
                  v3) );
  __asm { prefetchw byte ptr [rdx+30h]; Prefetch processor cache line into L1 data cache (mark as modified) }
  do
    v4 = _RDX->ThreadFlags.Value;
  while ( v4 != _InterlockedCompareExchange(
                  (volatile signed __int32 *)&_RDX->ThreadFlags,
                  _RDX->ThreadFlags.Value | 2,
                  v4) );
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)_RDX);
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
  Scaleform::ThreadList *v3; // rbp
  Scaleform::Mutex *v4; // rbx
  Scaleform::MutexImpl **v5; // r14
  Scaleform::MutexImpl *v6; // rdi
  Scaleform::Mutex *v7; // [rsp+50h] [rbp+8h]
  Scaleform::Thread *key; // [rsp+58h] [rbp+10h]

  key = pthread;
  v2 = pthread;
  v3 = this;
  v4 = &this->ThreadMutex;
  v7 = &this->ThreadMutex;
  v5 = &this->ThreadMutex.pImpl;
  v6 = this->ThreadMutex.pImpl;
  if ( !WaitForSingleObject(v6->hMutexOrSemaphore, 0xFFFFFFFF) )
  {
    ++v6->LockCount;
    v2 = key;
    v4 = v7;
  }
  Scaleform::HashSetBase<Scaleform::Thread *,Scaleform::ThreadList::ThreadHashOp,Scaleform::ThreadList::ThreadHashOp,Scaleform::AllocatorGH<Scaleform::Thread *,2>,Scaleform::HashsetCachedEntry<Scaleform::Thread *,Scaleform::ThreadList::ThreadHashOp>>::add<Scaleform::Thread *>(
    (Scaleform::HashSetBase<Scaleform::Thread *,Scaleform::ThreadList::ThreadHashOp,Scaleform::ThreadList::ThreadHashOp,Scaleform::AllocatorGH<Scaleform::Thread *,2>,Scaleform::HashsetCachedEntry<Scaleform::Thread *,Scaleform::ThreadList::ThreadHashOp> > *)&v3->ThreadSet.pTable,
    v3,
    &key,
    (unsigned __int64)v2 ^ ((unsigned __int64)v2 >> 6));
  Scaleform::MutexImpl::Unlock(*v5, v4);
}

// File Line: 728
// RVA: 0xA12060
void __fastcall Scaleform::ThreadList::removeThread(Scaleform::ThreadList *this, Scaleform::Thread *pthread)
{
  Scaleform::ThreadList *v2; // rdi
  Scaleform::Mutex *v3; // rbx
  Scaleform::MutexImpl **v4; // r14
  Scaleform::MutexImpl *v5; // rsi
  Scaleform::Mutex *v6; // [rsp+50h] [rbp+8h]
  Scaleform::Thread *key; // [rsp+58h] [rbp+10h]

  key = pthread;
  v2 = this;
  v3 = &this->ThreadMutex;
  v6 = &this->ThreadMutex;
  v4 = &this->ThreadMutex.pImpl;
  v5 = this->ThreadMutex.pImpl;
  if ( !WaitForSingleObject(v5->hMutexOrSemaphore, 0xFFFFFFFF) )
  {
    ++v5->LockCount;
    v3 = v6;
  }
  Scaleform::HashSetBase<Scaleform::Thread *,Scaleform::ThreadList::ThreadHashOp,Scaleform::ThreadList::ThreadHashOp,Scaleform::AllocatorGH<Scaleform::Thread *,2>,Scaleform::HashsetCachedEntry<Scaleform::Thread *,Scaleform::ThreadList::ThreadHashOp>>::RemoveAlt<Scaleform::Thread *>(
    (Scaleform::HashSetBase<Scaleform::Thread *,Scaleform::ThreadList::ThreadHashOp,Scaleform::ThreadList::ThreadHashOp,Scaleform::AllocatorGH<Scaleform::Thread *,2>,Scaleform::HashsetCachedEntry<Scaleform::Thread *,Scaleform::ThreadList::ThreadHashOp> > *)&v2->ThreadSet.pTable,
    &key);
  if ( !v2->ThreadSet.pTable || !v2->ThreadSet.pTable->EntryCount )
    Scaleform::WaitCondition::Notify(&v2->ThreadsEmpty);
  Scaleform::MutexImpl::Unlock(*v4, v3);
}

// File Line: 736
// RVA: 0xA11FD0
void __fastcall Scaleform::ThreadList::finishAllThreads(Scaleform::ThreadList *this)
{
  Scaleform::ThreadList *v1; // rdi
  Scaleform::Mutex *v2; // rbx
  Scaleform::MutexImpl **v3; // r15
  Scaleform::MutexImpl *v4; // r14
  Scaleform::Mutex *v5; // [rsp+50h] [rbp+8h]

  v1 = this;
  v2 = &this->ThreadMutex;
  v5 = &this->ThreadMutex;
  v3 = &this->ThreadMutex.pImpl;
  v4 = this->ThreadMutex.pImpl;
  if ( !WaitForSingleObject(v4->hMutexOrSemaphore, 0xFFFFFFFF) )
  {
    ++v4->LockCount;
    v2 = v5;
  }
  while ( v1->ThreadSet.pTable && v1->ThreadSet.pTable->EntryCount )
    Scaleform::WaitConditionImpl::Wait(v1->ThreadsEmpty.pImpl, &v1->ThreadMutex, 0xFFFFFFFF);
  Scaleform::MutexImpl::Unlock(*v3, v2);
}

// File Line: 744
// RVA: 0xA10EB0
void __fastcall Scaleform::ThreadList::ThreadList(Scaleform::ThreadList *this)
{
  Scaleform::ThreadList *v1; // rbx

  v1 = this;
  this->ThreadSet.pTable = 0i64;
  Scaleform::Mutex::Mutex(&this->ThreadMutex, 1, 0);
  Scaleform::WaitCondition::WaitCondition(&v1->ThreadsEmpty);
  v1->RootThreadId = (void *)GetCurrentThreadId();
}

// File Line: 752
// RVA: 0xA11320
void __fastcall Scaleform::ThreadList::AddRunningThread(Scaleform::Thread *pthread)
{
  Scaleform::Thread *v1; // rbx
  Scaleform::ThreadList *v2; // rax

  v1 = pthread;
  if ( !Scaleform::ThreadList::pRunningThreads )
  {
    v2 = (Scaleform::ThreadList *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                    Scaleform::Memory::pGlobalHeap,
                                    64i64);
    if ( v2 )
      Scaleform::ThreadList::ThreadList(v2);
    Scaleform::ThreadList::pRunningThreads = v2;
  }
  Scaleform::ThreadList::addThread(Scaleform::ThreadList::pRunningThreads, v1);
}

// File Line: 772
// RVA: 0xA114C0
void Scaleform::ThreadList::FinishAllThreads(void)
{
  Scaleform::WaitConditionImpl *v0; // rdi
  Scaleform::ThreadList *volatile v1; // [rsp+40h] [rbp+8h]

  if ( Scaleform::ThreadList::pRunningThreads )
  {
    Scaleform::ThreadList::finishAllThreads(Scaleform::ThreadList::pRunningThreads);
    v1 = Scaleform::ThreadList::pRunningThreads;
    if ( Scaleform::ThreadList::pRunningThreads )
    {
      v0 = Scaleform::ThreadList::pRunningThreads->ThreadsEmpty.pImpl;
      if ( v0 )
      {
        Scaleform::WaitConditionImpl::~WaitConditionImpl(Scaleform::ThreadList::pRunningThreads->ThreadsEmpty.pImpl);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v0);
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
  signed __int32 v2; // eax
  signed __int32 v3; // eax

  __asm { prefetchw byte ptr [rcx+30h]; Prefetch processor cache line into L1 data cache (mark as modified) }
  if ( exitFlag )
  {
    do
      v2 = this->ThreadFlags.Value;
    while ( v2 != _InterlockedCompareExchange(
                    (volatile signed __int32 *)&this->ThreadFlags,
                    this->ThreadFlags.Value | 0x10,
                    v2) );
  }
  else
  {
    do
      v3 = this->ThreadFlags.Value;
    while ( v3 != _InterlockedCompareExchange(
                    (volatile signed __int32 *)&this->ThreadFlags,
                    this->ThreadFlags.Value & 0xFFFFFFEF,
                    v3) );
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
signed __int64 __fastcall Scaleform::Thread::GetThreadState(Scaleform::Thread *this)
{
  signed __int64 result; // rax

  if ( this->SuspendCount.Value <= 0 )
    result = this->ThreadFlags.Value & 1;
  else
    result = 2i64;
  return result;
}

// File Line: 886
// RVA: 0xA11AF0
__int64 __fastcall Scaleform::Thread_Win32StartFn(void *phandle)
{
  unsigned int v2; // ebx
  HANDLE v3; // rax
  int v4; // ebx
  HANDLE v5; // rax
  signed __int32 v6; // eax
  int v7; // eax
  unsigned int v8; // ebx

  _RDI = (Scaleform::Thread *)phandle;
  if ( *((_DWORD *)phandle + 16) != -1 )
  {
    v2 = *((_DWORD *)phandle + 16);
    v3 = GetCurrentThread();
    SetThreadAffinityMask(v3, v2);
  }
  switch ( _RDI->Priority )
  {
    case 0:
      v4 = 15;
      break;
    case 1:
      v4 = 2;
      break;
    case 2:
      v4 = 1;
      break;
    case 4:
      v4 = -1;
      break;
    case 5:
      v4 = -2;
      break;
    case 6:
      v4 = -15;
      break;
    default:
      v4 = 0;
      break;
  }
  v5 = GetCurrentThread();
  SetThreadPriority(v5, v4);
  _RDI->IdValue = (void *volatile )GetCurrentThreadId();
  if ( _RDI->ThreadFlags.Value & 8 )
  {
    if ( _RDI->ThreadFlags.Value & 1 && SuspendThread(_RDI->ThreadHandle) != -1 )
      _InterlockedExchangeAdd(&_RDI->SuspendCount.Value, 1u);
    __asm { prefetchw byte ptr [rdi+30h]; Prefetch processor cache line into L1 data cache (mark as modified) }
    do
      v6 = _RDI->ThreadFlags.Value;
    while ( v6 != _InterlockedCompareExchange(
                    (volatile signed __int32 *)&_RDI->ThreadFlags,
                    _RDI->ThreadFlags.Value & 0xFFFFFFF7,
                    v6) );
  }
  v7 = ((__int64 (__fastcall *)(Scaleform::Thread *))_RDI->vfptr[3].__vecDelDtor)(_RDI);
  v8 = v7;
  _RDI->ExitCode = v7;
  Scaleform::Thread::FinishAndRelease(_RDI);
  Scaleform::ThreadList::removeThread(Scaleform::ThreadList::pRunningThreads, _RDI);
  return v8;
}

// File Line: 919
// RVA: 0xA119C0
char __fastcall Scaleform::Thread::Start(Scaleform::Thread *this, Scaleform::Thread::ThreadState initialState)
{
  Scaleform::Thread::ThreadState v2; // edi
  Scaleform::Thread *v3; // rbx
  void *v5; // rcx
  signed int v6; // eax
  unsigned __int64 v7; // rax

  v2 = initialState;
  v3 = this;
  if ( initialState == NotRunning
    || (this->SuspendCount.Value > 0 || this->ThreadFlags.Value & 1)
    && !Scaleform::Waitable::Wait((Scaleform::Waitable *)&this->vfptr, 0xFFFFFFFF) )
  {
    return 0;
  }
  v5 = v3->ThreadHandle;
  if ( v5 )
  {
    CloseHandle(v5);
    v3->ThreadHandle = 0i64;
  }
  Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v3);
  Scaleform::ThreadList::AddRunningThread(v3);
  v3->ExitCode = 0;
  v3->SuspendCount.Value = 0;
  v6 = 8;
  if ( v2 == 1 )
    v6 = 1;
  v3->ThreadFlags.Value = v6;
  v7 = beginthreadex(0i64, v3->StackSize, Scaleform::Thread_Win32StartFn, v3, 0, (unsigned int *)&v3->IdValue);
  v3->ThreadHandle = (void *)v7;
  if ( v7 )
    return 1;
  v3->ThreadFlags.Value = 0;
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v3);
  Scaleform::ThreadList::removeThread(Scaleform::ThreadList::pRunningThreads, v3);
  return 0;
}

// File Line: 955
// RVA: 0xA11AB0
char __fastcall Scaleform::Thread::Suspend(Scaleform::Thread *this)
{
  Scaleform::Thread *v1; // rbx

  v1 = this;
  if ( !(this->ThreadFlags.Value & 1) || SuspendThread(this->ThreadHandle) == -1 )
    return 0;
  _InterlockedExchangeAdd(&v1->SuspendCount.Value, 1u);
  return 1;
}

// File Line: 972
// RVA: 0xA11900
bool __fastcall Scaleform::Thread::Resume(Scaleform::Thread *this)
{
  signed __int32 v1; // eax
  bool result; // al

  result = 0;
  if ( this->ThreadFlags.Value & 1 )
  {
    v1 = _InterlockedExchangeAdd(&this->SuspendCount.Value, 0xFFFFFFFF);
    if ( v1 >= 1 && (v1 != 1 || ResumeThread(this->ThreadHandle) != -1) )
      result = 1;
  }
  return result;
}

// File Line: 999
// RVA: 0xA11470
void __fastcall __noreturn Scaleform::Thread::Exit(Scaleform::Thread *this, int exitCode)
{
  int v2; // edi
  Scaleform::Thread *v3; // rbx

  v2 = exitCode;
  v3 = this;
  ((void (*)(void))this->vfptr[4].__vecDelDtor)();
  Scaleform::Thread::FinishAndRelease(v3);
  Scaleform::ThreadList::removeThread(Scaleform::ThreadList::pRunningThreads, v3);
  endthreadex(v2);
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
char __fastcall Scaleform::Thread::MSleep(unsigned int msecs)
{
  Sleep(msecs);
  return 1;
}

// File Line: 1084
// RVA: 0xA11690
__int64 __fastcall Scaleform::Thread::GetCPUCount()
{
  _SYSTEM_INFO SystemInfo; // [rsp+20h] [rbp-38h]

  GetSystemInfo(&SystemInfo);
  return SystemInfo.dwNumberOfProcessors;
}

