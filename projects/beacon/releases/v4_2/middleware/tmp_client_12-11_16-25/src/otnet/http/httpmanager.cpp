// File Line: 9
// RVA: 0xECE76C
void __fastcall OSuite::ZHttpManager::ZHttpManager(OSuite::ZHttpManager *this)
{
  OSuite::ZHttpManager *v1; // rdi
  OSuite::ZHttpConnectionManager *v2; // rax
  OSuite::ZHttpRequestManager *v3; // rbx
  OSuite::ZHttpConnectionManager *v4; // rax
  OSuite::ZHttpRequestManager *v5; // rax
  OSuite::ZHttpRequestManager *v6; // rax

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpManager::`vftable';
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
  v1->m_httpConnectionManager = v4;
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
  v1->m_httpRequestManager = v3;
}

// File Line: 15
// RVA: 0xECE7F0
void __fastcall OSuite::ZHttpManager::~ZHttpManager(OSuite::ZHttpManager *this)
{
  OSuite::ZHttpManager *v1; // rbx
  OSuite::ZHttpRequestManager *v2; // rcx
  OSuite::ZHttpConnectionManager *v3; // rcx

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpManager::`vftable';
  v2 = this->m_httpRequestManager;
  if ( v2 )
    v2->vfptr->__vecDelDtor((OSuite::ZObject *)&v2->vfptr, 1u);
  v3 = v1->m_httpConnectionManager;
  if ( v3 )
    v3->vfptr->__vecDelDtor((OSuite::ZObject *)&v3->vfptr, 1u);
}

