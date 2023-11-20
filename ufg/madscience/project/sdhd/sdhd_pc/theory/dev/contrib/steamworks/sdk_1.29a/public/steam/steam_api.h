// File Line: 230
// RVA: 0xA37270
void __fastcall CCallResult<OSuite::ZGameInterface,EncryptedAppTicketResponse_t>::Run(CCallResult<OSuite::ZGameInterface,EncryptedAppTicketResponse_t> *this, void *pvParam)
{
  this->m_hAPICall = 0i64;
  this->m_Func(this->m_pObj, (EncryptedAppTicketResponse_t *)pvParam, 0);
}

// File Line: 235
// RVA: 0xA37290
void __fastcall CCallResult<OSuite::ZGameInterface,EncryptedAppTicketResponse_t>::Run(CCallResult<OSuite::ZGameInterface,EncryptedAppTicketResponse_t> *this, void *pvParam, __int64 bIOFailure, unsigned __int64 hSteamAPICall)
{
  if ( hSteamAPICall == this->m_hAPICall )
  {
    this->m_hAPICall = 0i64;
    this->m_Func(this->m_pObj, (EncryptedAppTicketResponse_t *)pvParam, bIOFailure);
  }
}

// File Line: 278
// RVA: 0xA367A0
void __fastcall CCallback<UFG::AchievementTrophyManager,UserStatsStored_t,0>::~CCallback<UFG::AchievementTrophyManager,UserStatsStored_t,0>(CCallback<UFG::AchievementTrophyManager,UserStatsStored_t,0> *this)
{
  bool v1; // zf

  v1 = (this->m_nCallbackFlags & 1) == 0;
  this->vfptr = (CCallbackBaseVtbl *)&CCallback<UFG::AchievementTrophyManager,UserStatsStored_t,0>::`vftable;
  if ( !v1 )
    SteamAPI_UnregisterCallback(this);
}

// File Line: 311
// RVA: 0xA36B60
void __fastcall CCallback<SteamImplementation,DlcInstalled_t,0>::Run(CCallback<SteamImplementation,RegisterActivationCodeResponse_t,0> *this, void *pvParam, __int64 __formal, unsigned __int64 a4)
{
  ((void (__fastcall *)(SteamImplementation *, void *, __int64, unsigned __int64))this->m_Func)(
    this->m_pObj,
    pvParam,
    __formal,
    a4);
}

// File Line: 319
// RVA: 0x427150
signed __int64 __fastcall Scaleform::GFx::AS2::StringObject::GetObjectType(hkpBoxShape *this)
{
  return 8i64;
}

