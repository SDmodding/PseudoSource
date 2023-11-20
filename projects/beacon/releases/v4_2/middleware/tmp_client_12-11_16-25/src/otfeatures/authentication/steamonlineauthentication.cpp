// File Line: 15
// RVA: 0xEC02CC
void __fastcall OSuite::SteamOnlineAuthentication::SteamOnlineAuthentication(OSuite::SteamOnlineAuthentication *this)
{
  OSuite::SteamOnlineAuthentication *v1; // rbx
  hkEntitySelectorAll *v2; // rax
  hkpEntity *v3; // rdx
  unsigned __int64 clock; // [rsp+30h] [rbp+8h]

  v1 = this;
  OSuite::IOnlineAuthentication::IOnlineAuthentication((OSuite::IOnlineAuthentication *)&this->vfptr);
  clock = 0i64;
  v1->vfptr = (OSuite::ZObjectVtbl *)&OSuite::SteamOnlineAuthentication::`vftable;
  OSuite::ZClock::ZClock(&v1->m_Clock, &clock);
  v2 = (hkEntitySelectorAll *)OSuite::GameInterface();
  v1->m_stTicket.m_eProvider = hkaReferencePoseAnimation::getNumOriginalFrames(v2, v3);
}

// File Line: 20
// RVA: 0xEC0314
void __fastcall OSuite::SteamOnlineAuthentication::~SteamOnlineAuthentication(OSuite::SteamOnlineAuthentication *this)
{
  OSuite::SteamOnlineAuthentication *v1; // rbx

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::SteamOnlineAuthentication::`vftable;
  OSuite::ZOEdmBase::CleanTempData((_DWORD)this + 120);
  OSuite::IOnlineAuthentication::~IOnlineAuthentication((OSuite::IOnlineAuthentication *)&v1->vfptr);
}

// File Line: 24
// RVA: 0xEC03F8
void __fastcall OSuite::SteamOnlineAuthentication::Update(OSuite::SteamOnlineAuthentication *this)
{
  OSuite::SteamOnlineAuthentication *v1; // rdi
  unsigned __int64 v2; // rax
  unsigned __int64 *v3; // rax
  OSuite::ZGameInterface *v4; // rax
  OSuite::fastdelegate::FastDelegate2<enum OSuite::IOnlineAuthentication::AuthState,OSuite::IOnlineAuthentication::AuthTicket,void> cb; // [rsp+20h] [rbp-18h]
  OSuite::ZClock v6; // [rsp+40h] [rbp+8h]

  v1 = this;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  if ( v1->m_bInitialized )
  {
    if ( v1->m_eState == AUTH_STATE_TICKET_NOT_FOUND )
    {
      v2 = OSuite::ZClock::_GetClock();
      if ( OSuite::ZClock::_ClockToTime(v2 - v1->m_Clock.m_clock, 0) >= 5 )
      {
        OSuite::ZClock::ZClock(&v6);
        v1->m_Clock.m_clock = *v3;
        OSuite::ZOEdmBase::CleanTempData((unsigned __int64)&v6);
        cb.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)v1;
        cb.m_Closure.m_pFunction = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))OSuite::SteamOnlineAuthentication::TicketReceivedCB;
        v4 = OSuite::GameInterface();
        OSuite::ZGameInterface::RequestTicket(v4, &v1->m_eState, &cb);
      }
    }
  }
  OSuite::ZMutex::Unlock(&v1->m_Mutex);
}

// File Line: 52
// RVA: 0xEC0370
signed __int64 __fastcall OSuite::SteamOnlineAuthentication::GetDefaultProvider(OSuite::SteamOnlineAuthentication *this)
{
  hkEntitySelectorAll *v1; // rax
  hkpEntity *v2; // rdx

  v1 = (hkEntitySelectorAll *)OSuite::GameInterface();
  return hkaReferencePoseAnimation::getNumOriginalFrames(v1, v2);
}

// File Line: 59
// RVA: 0xEC0388
void __fastcall OSuite::SteamOnlineAuthentication::TicketReceivedCB(OSuite::SteamOnlineAuthentication *this, OSuite::IOnlineAuthentication::AuthState eState, OSuite::IOnlineAuthentication::AuthTicket *ticket)
{
  OSuite::IOnlineAuthentication::AuthTicket *v3; // rdi
  OSuite::IOnlineAuthentication::AuthTicket *v4; // rbp

  this->m_eState = eState;
  v3 = &this->m_stTicket;
  v4 = ticket;
  OSuite::ZString::operator=(&this->m_stTicket.m_strOwner, &ticket->m_strOwner);
  OSuite::ZString::operator=(&v3->m_strTicketData, &v4->m_strTicketData);
  v3->m_eProvider = v4->m_eProvider;
  v3->m_uTicketSize = v4->m_uTicketSize;
  OSuite::ZString::operator=(&v3->m_strAccessToken, &v4->m_strAccessToken);
  OSuite::ZString::~ZString(&v4->m_strAccessToken);
  OSuite::ZString::~ZString(&v4->m_strTicketData);
  OSuite::ZString::~ZString(&v4->m_strOwner);
}

