// File Line: 15
// RVA: 0xEC02CC
void __fastcall OSuite::SteamOnlineAuthentication::SteamOnlineAuthentication(OSuite::SteamOnlineAuthentication *this)
{
  hkEntitySelectorAll *v2; // rax
  hkpEntity *v3; // rdx
  unsigned __int64 clock; // [rsp+30h] [rbp+8h] BYREF

  OSuite::IOnlineAuthentication::IOnlineAuthentication(this);
  clock = 0i64;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::SteamOnlineAuthentication::`vftable;
  OSuite::ZClock::ZClock(&this->m_Clock, &clock);
  v2 = (hkEntitySelectorAll *)OSuite::GameInterface();
  this->m_stTicket.m_eProvider = hkaReferencePoseAnimation::getNumOriginalFrames(v2, v3);
}

// File Line: 20
// RVA: 0xEC0314
void __fastcall OSuite::SteamOnlineAuthentication::~SteamOnlineAuthentication(OSuite::SteamOnlineAuthentication *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::SteamOnlineAuthentication::`vftable;
  OSuite::ZOEdmBase::CleanTempData((_DWORD)this + 120);
  OSuite::IOnlineAuthentication::~IOnlineAuthentication(this);
}

// File Line: 24
// RVA: 0xEC03F8
void __fastcall OSuite::SteamOnlineAuthentication::Update(OSuite::SteamOnlineAuthentication *this)
{
  unsigned __int64 Clock; // rax
  unsigned __int64 *v3; // rax
  OSuite::ZGameInterface *v4; // rax
  OSuite::fastdelegate::FastDelegate2<enum OSuite::IOnlineAuthentication::AuthState,OSuite::IOnlineAuthentication::AuthTicket,void> cb; // [rsp+20h] [rbp-18h] BYREF
  OSuite::ZClock v6; // [rsp+40h] [rbp+8h] BYREF

  OSuite::ZMutex::Lock(&this->m_Mutex);
  if ( this->m_bInitialized && this->m_eState == AUTH_STATE_TICKET_NOT_FOUND )
  {
    Clock = OSuite::ZClock::_GetClock();
    if ( OSuite::ZClock::_ClockToTime(Clock - this->m_Clock.m_clock, UNIT_SECONDS) >= 5 )
    {
      OSuite::ZClock::ZClock(&v6);
      this->m_Clock.m_clock = *v3;
      OSuite::ZOEdmBase::CleanTempData((int)&v6);
      cb.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)this;
      cb.m_Closure.m_pFunction = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))OSuite::SteamOnlineAuthentication::TicketReceivedCB;
      v4 = OSuite::GameInterface();
      OSuite::ZGameInterface::RequestTicket(v4, &this->m_eState, &cb);
    }
  }
  OSuite::ZMutex::Unlock(&this->m_Mutex);
}

// File Line: 52
// RVA: 0xEC0370
__int64 __fastcall OSuite::SteamOnlineAuthentication::GetDefaultProvider(OSuite::SteamOnlineAuthentication *this)
{
  hkEntitySelectorAll *v1; // rax
  hkpEntity *v2; // rdx

  v1 = (hkEntitySelectorAll *)OSuite::GameInterface();
  return hkaReferencePoseAnimation::getNumOriginalFrames(v1, v2);
}

// File Line: 59
// RVA: 0xEC0388
void __fastcall OSuite::SteamOnlineAuthentication::TicketReceivedCB(
        OSuite::SteamOnlineAuthentication *this,
        OSuite::IOnlineAuthentication::AuthState eState,
        OSuite::IOnlineAuthentication::AuthTicket *ticket)
{
  OSuite::IOnlineAuthentication::AuthTicket *p_m_stTicket; // rdi

  this->m_eState = eState;
  p_m_stTicket = &this->m_stTicket;
  OSuite::ZString::operator=(&this->m_stTicket.m_strOwner, &ticket->m_strOwner);
  OSuite::ZString::operator=(&p_m_stTicket->m_strTicketData, &ticket->m_strTicketData);
  p_m_stTicket->m_eProvider = ticket->m_eProvider;
  p_m_stTicket->m_uTicketSize = ticket->m_uTicketSize;
  OSuite::ZString::operator=(&p_m_stTicket->m_strAccessToken, &ticket->m_strAccessToken);
  OSuite::ZString::~ZString(&ticket->m_strAccessToken);
  OSuite::ZString::~ZString(&ticket->m_strTicketData);
  OSuite::ZString::~ZString(&ticket->m_strOwner);
}

