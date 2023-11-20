// File Line: 56
// RVA: 0xEE697C
void __fastcall OSuite::ZMutex::ZMutex(OSuite::ZMutex *this)
{
  OSuite::ZMutex *v1; // rbx
  __int64 v2; // rax

  this->m_nLockCount = 0;
  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZMutex::`vftable;
  v2 = OSuite::ZObject::operator new(0x30ui64);
  if ( v2 )
    *(_QWORD *)v2 = &OSuite::InternalMutex::`vftable;
  v1->m_pInternalMutex = (OSuite::InternalMutex *)v2;
  InitializeCriticalSection((LPCRITICAL_SECTION)(v2 + 8));
}

// File Line: 90
// RVA: 0xEE69C4
void __fastcall OSuite::ZMutex::~ZMutex(OSuite::ZMutex *this)
{
  OSuite::ZMutex *v1; // rbx
  OSuite::InternalMutex *v2; // rcx

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZMutex::`vftable;
  DeleteCriticalSection(&this->m_pInternalMutex->m_mutex);
  v2 = v1->m_pInternalMutex;
  if ( v2 )
    v2->vfptr->__vecDelDtor((OSuite::ZObject *)&v2->vfptr, 1u);
  v1->m_pInternalMutex = 0i64;
}

// File Line: 111
// RVA: 0xEE6A50
bool __fastcall OSuite::ZMutex::IsLocked(OSuite::ZMutex *this)
{
  return this->m_nLockCount > 0;
}

// File Line: 151
// RVA: 0xEE6A5C
void __fastcall OSuite::ZMutex::Lock(OSuite::ZMutex *this)
{
  OSuite::ZMutex *v1; // rbx

  v1 = this;
  EnterCriticalSection(&this->m_pInternalMutex->m_mutex);
  ++v1->m_nLockCount;
}

// File Line: 168
// RVA: 0xEE6A7C
void __fastcall OSuite::ZMutex::Unlock(OSuite::ZMutex *this)
{
  OSuite::ZMutex *v1; // rbx

  --this->m_nLockCount;
  v1 = this;
  OSuite::ZThread::GetCurrentTID();
  LeaveCriticalSection(&v1->m_pInternalMutex->m_mutex);
}

