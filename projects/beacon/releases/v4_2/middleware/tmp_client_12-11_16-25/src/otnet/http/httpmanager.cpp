// File Line: 9
// RVA: 0xECE76C
void __fastcall OSuite::ZHttpManager::ZHttpManager(OSuite::ZHttpManager *this)
{
  OSuite::ZHttpConnectionManager *v2; // rax
  OSuite::ZHttpRequestManager *v3; // rbx
  OSuite::ZHttpConnectionManager *v4; // rax
  OSuite::ZHttpRequestManager *v5; // rax
  OSuite::ZHttpRequestManager *v6; // rax

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpManager::`vftable;
  v2 = (OSuite::ZHttpConnectionManager *)OSuite::ZObject::operator new(0x40ui64);
  v3 = 0i64;
  if ( v2 )
  {
    v2->m_freeHttpConnectionsList.m_pHead = 0i64;
    v2->m_ConnectionMutex.m_pInternalMutex = 0i64;
    OSuite::ZHttpConnectionManager::ZHttpConnectionManager(v2);
  }
  else
  {
    v4 = 0i64;
  }
  this->m_httpConnectionManager = v4;
  v5 = (OSuite::ZHttpRequestManager *)OSuite::ZObject::operator new(0x80ui64);
  if ( v5 )
  {
    v5->m_scheduledForDeleteHttpRequestsList.m_pHead = 0i64;
    v5->m_pendingHttpRequestsList.m_pHead = 0i64;
    v5->m_RequestMutex.m_pInternalMutex = 0i64;
    v5->m_osPlatform.m_pString = 0i64;
    v5->m_userAgent.m_pString = 0i64;
    OSuite::ZHttpRequestManager::ZHttpRequestManager(v5);
    v3 = v6;
  }
  this->m_httpRequestManager = v3;
}

// File Line: 15
// RVA: 0xECE7F0
void __fastcall OSuite::ZHttpManager::~ZHttpManager(OSuite::ZHttpManager *this)
{
  OSuite::ZHttpRequestManager *m_httpRequestManager; // rcx
  OSuite::ZHttpConnectionManager *m_httpConnectionManager; // rcx

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpManager::`vftable;
  m_httpRequestManager = this->m_httpRequestManager;
  if ( m_httpRequestManager )
    m_httpRequestManager->vfptr->__vecDelDtor(m_httpRequestManager, 1u);
  m_httpConnectionManager = this->m_httpConnectionManager;
  if ( m_httpConnectionManager )
    m_httpConnectionManager->vfptr->__vecDelDtor(m_httpConnectionManager, 1u);
}

