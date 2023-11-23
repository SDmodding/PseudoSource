// File Line: 10
// RVA: 0xEC0084
void __fastcall OSuite::IOnlineAuthentication::IOnlineAuthentication(OSuite::IOnlineAuthentication *this)
{
  OSuite::ZString that; // [rsp+20h] [rbp-28h] BYREF

  this->m_eState = AUTH_STATE_TICKET_NOT_FOUND;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::IOnlineAuthentication::`vftable;
  this->m_bInitialized = 0;
  OSuite::ZString::ZString(&this->m_stTicket.m_strOwner);
  OSuite::ZString::ZString(&this->m_stTicket.m_strTicketData);
  OSuite::ZString::ZString(&this->m_stTicket.m_strAccessToken);
  OSuite::ZMutex::ZMutex(&this->m_Mutex);
  this->m_stTicket.m_eProvider = AUTH_PROVIDER_INVALID;
  OSuite::ZString::ZString(&that, "0");
  OSuite::ZString::operator=(&this->m_stTicket.m_strTicketData, &that);
  OSuite::ZString::~ZString(&that);
  this->m_stTicket.m_uTicketSize = 0;
  OSuite::ZString::ZString(&that, "0");
  OSuite::ZString::operator=(&this->m_stTicket.m_strOwner, &that);
  OSuite::ZString::~ZString(&that);
  OSuite::ZString::ZString(&that, "0");
  OSuite::ZString::operator=(&this->m_stTicket.m_strAccessToken, &that);
  OSuite::ZString::~ZString(&that);
}

// File Line: 19
// RVA: 0xEC0158
void __fastcall OSuite::IOnlineAuthentication::~IOnlineAuthentication(OSuite::IOnlineAuthentication *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::IOnlineAuthentication::`vftable;
  OSuite::ZMutex::~ZMutex(&this->m_Mutex);
  OSuite::ZString::~ZString(&this->m_stTicket.m_strAccessToken);
  OSuite::ZString::~ZString(&this->m_stTicket.m_strTicketData);
  OSuite::ZString::~ZString(&this->m_stTicket.m_strOwner);
}

// File Line: 23
// RVA: 0xEC01F0
void __fastcall OSuite::IOnlineAuthentication::Reset(OSuite::IOnlineAuthentication *this)
{
  OSuite::ZObjectVtbl *vfptr; // rax
  OSuite::ZString that; // [rsp+20h] [rbp-28h] BYREF

  vfptr = this->vfptr;
  this->m_eState = AUTH_STATE_TICKET_NOT_FOUND;
  this->m_stTicket.m_eProvider = ((__int64 (__fastcall *)(OSuite::IOnlineAuthentication *))vfptr[2].__vecDelDtor)(this);
  OSuite::ZString::ZString(&that, "0");
  OSuite::ZString::operator=(&this->m_stTicket.m_strTicketData, &that);
  OSuite::ZString::~ZString(&that);
  this->m_stTicket.m_uTicketSize = 0;
  OSuite::ZString::ZString(&that, "0");
  OSuite::ZString::operator=(&this->m_stTicket.m_strOwner, &that);
  OSuite::ZString::~ZString(&that);
  OSuite::ZString::ZString(&that, "0");
  OSuite::ZString::operator=(&this->m_stTicket.m_strAccessToken, &that);
  OSuite::ZString::~ZString(&that);
}

// File Line: 33
// RVA: 0xEC028C
void __fastcall OSuite::IOnlineAuthentication::SetAuthenticationProvider(
        OSuite::IOnlineAuthentication *this,
        OSuite::IOnlineAuthentication::AuthProvider eProvider)
{
  this->m_stTicket.m_eProvider = eProvider;
}

// File Line: 38
// RVA: 0xEC01D8
__int64 __fastcall OSuite::IOnlineAuthentication::GetAuthenticationProvider(OSuite::IOnlineAuthentication *this)
{
  return (unsigned int)this->m_stTicket.m_eProvider;
}

// File Line: 43
// RVA: 0xEC0294
void __fastcall OSuite::IOnlineAuthentication::SetTicketData(OSuite::IOnlineAuthentication *this, const char *pszData)
{
  OSuite::ZString that; // [rsp+20h] [rbp-28h] BYREF

  OSuite::ZString::ZString(&that, pszData);
  OSuite::ZString::operator=(&this->m_stTicket.m_strTicketData, &that);
  OSuite::ZString::~ZString(&that);
}

// File Line: 48
// RVA: 0xEC01DC
OSuite::ZString *__fastcall OSuite::IOnlineAuthentication::GetTicketData(OSuite::ZUrl *this)
{
  return &this->m_sHost;
}

// File Line: 53
// RVA: 0xEC02C8
void __fastcall OSuite::IOnlineAuthentication::SetTicketSize(
        OSuite::IOnlineAuthentication *this,
        unsigned int uTicketSize)
{
  this->m_stTicket.m_uTicketSize = uTicketSize;
}

// File Line: 58
// RVA: 0xEC01E4
__int64 __fastcall OSuite::IOnlineAuthentication::GetTicketSize(OSuite::IOnlineAuthentication *this)
{
  return this->m_stTicket.m_uTicketSize;
}

// File Line: 83
// RVA: 0xEC0290
void __fastcall OSuite::IOnlineAuthentication::SetInitialized(OSuite::IOnlineAuthentication *this, bool bInitialized)
{
  this->m_bInitialized = bInitialized;
}

// File Line: 93
// RVA: 0xEC01E8
bool __fastcall OSuite::IOnlineAuthentication::IsTicketFound(OSuite::IOnlineAuthentication *this)
{
  return this->m_eState == AUTH_STATE_TICKET_FOUND;
}

// File Line: 98
// RVA: 0xEC01C4
void __fastcall OSuite::IOnlineAuthentication::ForceTicketUpdate(OSuite::IOnlineAuthentication *this)
{
  if ( this->m_eState == AUTH_STATE_TICKET_FOUND )
    OSuite::IOnlineAuthentication::Reset(this);
}

