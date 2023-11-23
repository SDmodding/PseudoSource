// File Line: 83
// RVA: 0xC5C390
void __fastcall hkSemaphore::hkSemaphore(hkSemaphore *this, LONG initialCount, LONG maxCount, int numSpinIterations)
{
  this->m_semaphore = CreateSemaphoreW(0i64, initialCount, maxCount, 0i64);
}

// File Line: 103
// RVA: 0xC5C3C0
void __fastcall hkSemaphore::~hkSemaphore(hkSemaphore *this)
{
  CloseHandle(this->m_semaphore);
}

// File Line: 108
// RVA: 0xC5C3D0
void __fastcall hkSemaphore::acquire(hkSemaphore *this)
{
  WaitForSingleObject(this->m_semaphore, 0xFFFFFFFF);
}

// File Line: 119
// RVA: 0xC5C3F0
void __fastcall hkSemaphore::release(hkSemaphore *this, LONG count)
{
  ReleaseSemaphore(this->m_semaphore, count, 0i64);
}

// File Line: 128
// RVA: 0xC5C410
// attributes: thunk
void __fastcall hkSemaphore::acquire(hkSemaphore *semaphore)
{
  ?acquire@hkSemaphore@@QEAAXXZ(semaphore);
}

// File Line: 134
// RVA: 0xC5C420
// attributes: thunk
void __fastcall hkSemaphore::release(hkSemaphore *semaphore, LONG count)
{
  ?release@hkSemaphore@@QEAAXH@Z(semaphore, count);
}

