// File Line: 231
// RVA: 0x48FF0
void __fastcall Scaleform::AcquireInterface::~AcquireInterface(Scaleform::AcquireInterface *this)
{
  this->vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable';
}

// File Line: 270
// RVA: 0x49000
void __fastcall Scaleform::DefaultAcquireInterface::~DefaultAcquireInterface(Scaleform::DefaultAcquireInterface *this)
{
  this->vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::DefaultAcquireInterface::`vftable';
  this->vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable';
}

// File Line: 353
// RVA: 0x93DDD0
void __fastcall Scaleform::Waitable::HandlerArray::HandlerArray(Scaleform::Waitable::HandlerArray *this)
{
  Scaleform::Waitable::HandlerArray *v1; // rbx
  volatile int v2; // et1
  volatile int v3; // et1
  Scaleform::Array<Scaleform::Waitable::HandlerStruct,2,Scaleform::ArrayConstPolicy<0,16,1> > *v4; // [rsp+48h] [rbp+10h]

  v1 = this;
  v2 = this->RefCount.Value;
  v3 = this->RefCount.Value;
  v4 = &this->Handlers;
  *(_OWORD *)&v4->Data.Data = 0ui64;
  v4->Data.Policy.Capacity = 0i64;
  Scaleform::Lock::Lock(&this->HandlersLock, 0);
  v1->RefCount.Value = 1;
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

