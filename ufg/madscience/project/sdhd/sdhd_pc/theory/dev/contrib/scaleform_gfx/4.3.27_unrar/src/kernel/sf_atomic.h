// File Line: 1134
// RVA: 0x94B230
void __fastcall Scaleform::LockSafe::Locker::~Locker(Scaleform::Lock::Locker *this)
{
  LeaveCriticalSection(&this->pLock->cs);
}

// File Line: 1149
// RVA: 0x94D5C0
void __fastcall Scaleform::LockSafe::TmpUnlocker::~TmpUnlocker(Scaleform::LockSafe::TmpUnlocker *this)
{
  EnterCriticalSection(&this->pLock->mLock.cs);
}

