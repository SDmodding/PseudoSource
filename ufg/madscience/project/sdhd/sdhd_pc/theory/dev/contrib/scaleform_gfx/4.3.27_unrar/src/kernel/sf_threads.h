// File Line: 231
// RVA: 0x48FF0
void __fastcall Scaleform::AcquireInterface::~AcquireInterface(Scaleform::AcquireInterface *this)
{
  this->vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable;
}

// File Line: 270
// RVA: 0x49000
void __fastcall Scaleform::DefaultAcquireInterface::~DefaultAcquireInterface(Scaleform::DefaultAcquireInterface *this)
{
  this->vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::DefaultAcquireInterface::`vftable;
  this->vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable;
}

// File Line: 353
// RVA: 0x93DDD0
void __fastcall Scaleform::Waitable::HandlerArray::HandlerArray(Scaleform::Waitable::HandlerArray *this)
{
  this->Handlers.Data.Data = 0i64;
  this->Handlers.Data.Size = 0i64;
  this->Handlers.Data.Policy.Capacity = 0i64;
  Scaleform::Lock::Lock(&this->HandlersLock, 0);
  this->RefCount.Value = 1;
}

// File Line: 472
// RVA: 0x8A5D90
void __fastcall Scaleform::Mutex::Locker::~Locker(Scaleform::Mutex::Locker *this)
{
  Scaleform::Mutex::Unlock(this->pMutex);
}

// File Line: 851
// RVA: 0x8E78A0
__int64 __fastcall Scaleform::Thread::IsSignaled(Scaleform::Thread *this)
{
  return (this->ThreadFlags.Value >> 1) & 1;
}

