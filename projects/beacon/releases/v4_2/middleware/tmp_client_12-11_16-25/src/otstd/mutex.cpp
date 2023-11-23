// File Line: 56
// RVA: 0xEE697C
void __fastcall OSuite::ZMutex::ZMutex(OSuite::ZMutex *this)
{
  OSuite::InternalMutex *v2; // rax

  this->m_nLockCount = 0;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZMutex::`vftable;
  v2 = (OSuite::InternalMutex *)OSuite::ZObject::operator new(0x30ui64);
  if ( v2 )
    v2->vfptr = (OSuite::ZObjectVtbl *)&OSuite::InternalMutex::`vftable;
  this->m_pInternalMutex = v2;
  InitializeCriticalSection(&v2->m_mutex);
}

// File Line: 90
// RVA: 0xEE69C4
void __fastcall OSuite::ZMutex::~ZMutex(OSuite::ZMutex *this)
{
  OSuite::InternalMutex *m_pInternalMutex; // rcx

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZMutex::`vftable;
  DeleteCriticalSection(&this->m_pInternalMutex->m_mutex);
  m_pInternalMutex = this->m_pInternalMutex;
  if ( m_pInternalMutex )
    m_pInternalMutex->vfptr->__vecDelDtor(m_pInternalMutex, 1u);
  this->m_pInternalMutex = 0i64;
}

// File Line: 111
// RVA: 0xEE6A50
_BOOL8 __fastcall OSuite::ZMutex::IsLocked(OSuite::ZMutex *this)
{
  return this->m_nLockCount > 0;
}

// File Line: 151
// RVA: 0xEE6A5C
void __fastcall OSuite::ZMutex::Lock(OSuite::ZMutex *this)
{
  EnterCriticalSection(&this->m_pInternalMutex->m_mutex);
  ++this->m_nLockCount;
}

// File Line: 168
// RVA: 0xEE6A7C
void __fastcall OSuite::ZMutex::Unlock(OSuite::ZMutex *this)
{
  --this->m_nLockCount;
  OSuite::ZThread::GetCurrentTID();
  LeaveCriticalSection(&this->m_pInternalMutex->m_mutex);
}

