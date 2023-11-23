// File Line: 27
// RVA: 0xA9AD80
void __fastcall CAkSwitchAware::CAkSwitchAware(CAkSwitchAware *this)
{
  this->vfptr = (CAkSwitchAwareVtbl *)&AkMusicAction::`vftable;
}

// File Line: 31
// RVA: 0xA9AD90
void __fastcall CAkSwitchAware::~CAkSwitchAware(CAkSwitchAware *this)
{
  this->vfptr = (CAkSwitchAwareVtbl *)&AkMusicAction::`vftable;
}

// File Line: 35
// RVA: 0xA9AEC0
void __fastcall CAkSwitchAware::UnsubscribeSwitches(CAkSwitchAware *this)
{
  CAkRTPCMgr::UnSubscribeSwitch(g_pRTPCMgr, this);
  CAkStateMgr::UnregisterSwitch(g_pStateMgr, this);
}

// File Line: 44
// RVA: 0xA9AE10
__int64 __fastcall CAkSwitchAware::SubscribeSwitch(
        CAkSwitchAware *this,
        unsigned int in_ulGroup,
        AkGroupType in_eGroupType)
{
  CAkRTPCMgr::UnSubscribeSwitch(g_pRTPCMgr, this);
  CAkStateMgr::UnregisterSwitch(g_pStateMgr, this);
  if ( !in_ulGroup )
    return 1i64;
  if ( in_eGroupType == AkGroupType_Switch )
    return CAkRTPCMgr::SubscribeSwitch(g_pRTPCMgr, this, in_ulGroup, 0);
  if ( in_eGroupType == AkGroupType_State )
    return CAkStateMgr::RegisterSwitch(g_pStateMgr, this, in_ulGroup);
  return 31i64;
}

// File Line: 76
// RVA: 0xA9ADD0
__int64 __fastcall CAkSwitchAware::GetSwitchToUse(
        CAkSwitchAware *this,
        CAkRegisteredObj *in_pGameObj,
        unsigned int in_ulGroup,
        AkGroupType in_eGroupType)
{
  if ( in_eGroupType == AkGroupType_Switch )
    return CAkRTPCMgr::GetSwitch(g_pRTPCMgr, in_ulGroup, in_pGameObj);
  if ( in_eGroupType == AkGroupType_State )
    return CAkStateMgr::GetState(g_pStateMgr, in_ulGroup);
  return 0i64;
}

