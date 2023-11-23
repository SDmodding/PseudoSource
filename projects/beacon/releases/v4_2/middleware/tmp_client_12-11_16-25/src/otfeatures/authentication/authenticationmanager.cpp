// File Line: 24
// RVA: 0x15D8A7C
__int64 dynamic_initializer_for__OSuite::AuthenticationManager::m_instance__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__OSuite::AuthenticationManager::m_instance__);
}

// File Line: 28
// RVA: 0xEBFF24
void __fastcall OSuite::AuthenticationManager::AuthenticationManager(OSuite::AuthenticationManager *this)
{
  OSuite::IOnlineAuthentication *v2; // rbx
  OSuite::SteamOnlineAuthentication *v3; // rax
  OSuite::IOnlineAuthentication *v4; // rax

  v2 = 0i64;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::AuthenticationManager::`vftable;
  this->m_onlineAuthentication = 0i64;
  v3 = (OSuite::SteamOnlineAuthentication *)OSuite::ZObject::operator new(0x80ui64);
  if ( v3 )
  {
    v3->m_Mutex.m_pInternalMutex = 0i64;
    OSuite::SteamOnlineAuthentication::SteamOnlineAuthentication(v3);
    v2 = v4;
  }
  this->m_onlineAuthentication = v2;
}

// File Line: 49
// RVA: 0xEBFF74
void __fastcall OSuite::AuthenticationManager::~AuthenticationManager(OSuite::AuthenticationManager *this)
{
  OSuite::IOnlineAuthentication *m_onlineAuthentication; // rcx

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::AuthenticationManager::`vftable;
  m_onlineAuthentication = this->m_onlineAuthentication;
  if ( m_onlineAuthentication )
    m_onlineAuthentication->vfptr->__vecDelDtor(m_onlineAuthentication, 1u);
  this->m_onlineAuthentication = 0i64;
}

// File Line: 55
// RVA: 0xEC0078
void __fastcall OSuite::AuthenticationManager::Update(OSuite::AuthenticationManager *this)
{
  ((void (__fastcall *)(OSuite::IOnlineAuthentication *))this->m_onlineAuthentication->vfptr[1].__vecDelDtor)(this->m_onlineAuthentication);
}

// File Line: 60
// RVA: 0xEC0048
void __fastcall OSuite::AuthenticationManager::SetAuthenticationProvider(
        OSuite::AuthenticationManager *this,
        OSuite::IOnlineAuthentication::AuthProvider eProvider)
{
  OSuite::IOnlineAuthentication::SetAuthenticationProvider(this->m_onlineAuthentication, eProvider);
}

// File Line: 65
// RVA: 0xEC000C
OSuite::IOnlineAuthentication::AuthProvider __fastcall OSuite::AuthenticationManager::GetAuthenticationProvider(
        OSuite::AuthenticationManager *this)
{
  return OSuite::IOnlineAuthentication::GetAuthenticationProvider(this->m_onlineAuthentication);
}

// File Line: 70
// RVA: 0xEC0060
void __fastcall OSuite::AuthenticationManager::SetTicketData(OSuite::AuthenticationManager *this, const char *pszData)
{
  OSuite::IOnlineAuthentication::SetTicketData(this->m_onlineAuthentication, pszData);
}

// File Line: 75
// RVA: 0xEC0018
OSuite::ZString *__fastcall OSuite::AuthenticationManager::GetTicketData(OSuite::AuthenticationManager *this)
{
  return OSuite::IOnlineAuthentication::GetTicketData((OSuite::ZUrl *)this->m_onlineAuthentication);
}

// File Line: 80
// RVA: 0xEC006C
void __fastcall OSuite::AuthenticationManager::SetTicketSize(
        OSuite::AuthenticationManager *this,
        unsigned int uTicketSize)
{
  OSuite::IOnlineAuthentication::SetTicketSize(this->m_onlineAuthentication, uTicketSize);
}

// File Line: 85
// RVA: 0xEC0030
unsigned int __fastcall OSuite::AuthenticationManager::GetTicketSize(OSuite::AuthenticationManager *this)
{
  return OSuite::IOnlineAuthentication::GetTicketSize(this->m_onlineAuthentication);
}

// File Line: 95
// RVA: 0xEC0024
OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *__fastcall OSuite::AuthenticationManager::GetTicketOwner(
        OSuite::AuthenticationManager *this)
{
  return OSuite::ZUrl::GetProtocol((OSuite::ZHttpResponseBase *)this->m_onlineAuthentication);
}

// File Line: 110
// RVA: 0xEC0054
void __fastcall OSuite::AuthenticationManager::SetInitialized(OSuite::AuthenticationManager *this, bool bInitialized)
{
  OSuite::IOnlineAuthentication::SetInitialized(this->m_onlineAuthentication, bInitialized);
}

// File Line: 120
// RVA: 0xEC003C
bool __fastcall OSuite::AuthenticationManager::IsTicketFound(OSuite::AuthenticationManager *this)
{
  return OSuite::IOnlineAuthentication::IsTicketFound(this->m_onlineAuthentication);
}

// File Line: 125
// RVA: 0xEC0000
void __fastcall OSuite::AuthenticationManager::ForceTicketUpdate(OSuite::AuthenticationManager *this)
{
  OSuite::IOnlineAuthentication::ForceTicketUpdate(this->m_onlineAuthentication);
}

