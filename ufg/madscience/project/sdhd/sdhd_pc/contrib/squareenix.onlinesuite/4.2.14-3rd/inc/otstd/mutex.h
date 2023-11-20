// File Line: 60
// RVA: 0x429680
void __fastcall OSuite::ZScopeMutexLock::~ZScopeMutexLock(OSuite::ZScopeMutexLock *this)
{
  OSuite::ZMutex::Unlock(this->m_pMutex);
}

