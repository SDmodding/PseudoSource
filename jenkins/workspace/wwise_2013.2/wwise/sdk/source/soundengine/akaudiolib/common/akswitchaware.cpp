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
  CAkSwitchAware *v1; // rbx

  v1 = this;
  CAkRTPCMgr::UnSubscribeSwitch(g_pRTPCMgr, this);
  CAkStateMgr::UnregisterSwitch(g_pStateMgr, v1);
}

// File Line: 44
// RVA: 0xA9AE10
signed __int64 __fastcall CAkSwitchAware::SubscribeSwitch(CAkSwitchAware *this, unsigned int in_ulGroup, AkGroupType in_eGroupType)
{
  unsigned int v3; // esi
  CAkSwitchAware *v4; // rdi
  AkGroupType v5; // ebx

  v3 = in_ulGroup;
  v4 = this;
  v5 = in_eGroupType;
  CAkRTPCMgr::UnSubscribeSwitch(g_pRTPCMgr, this);
  CAkStateMgr::UnregisterSwitch(g_pStateMgr, v4);
  if ( !v3 )
    return 1i64;
  if ( v5 == AkGroupType_Switch )
    return CAkRTPCMgr::SubscribeSwitch(g_pRTPCMgr, v4, v3, 0);
  if ( v5 == 1 )
    return CAkStateMgr::RegisterSwitch(g_pStateMgr, v4, v3);
  return 31i64;
}

// File Line: 76
// RVA: 0xA9ADD0
__int64 __fastcall CAkSwitchAware::GetSwitchToUse(CAkSwitchAware *this, CAkRegisteredObj *in_pGameObj, unsigned int in_ulGroup, AkGroupType in_eGroupType)
{
  if ( in_eGroupType == AkGroupType_Switch )
    return CAkRTPCMgr::GetSwitch(g_pRTPCMgr, in_ulGroup, in_pGameObj);
  if ( in_eGroupType == 1 )
    return CAkStateMgr::GetState(g_pStateMgr, in_ulGroup);
  return 0i64;
}

