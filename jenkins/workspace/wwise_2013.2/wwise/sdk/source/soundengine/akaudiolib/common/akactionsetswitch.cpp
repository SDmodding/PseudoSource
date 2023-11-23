// File Line: 39
// RVA: 0xA96690
__int64 __fastcall CAkActionSetSwitch::Execute(CAkActionSetSwitch *this, AkPendingAction *in_pAction)
{
  CAkRTPCMgr::SetSwitchInternal(g_pRTPCMgr, this->m_ulSwitchGroupID, this->m_ulSwitchStateID, in_pAction->pGameObj);
  return 1i64;
}

// File Line: 46
// RVA: 0xA96610
CAkActionSetSwitch *__fastcall CAkActionSetSwitch::Create(AkActionType in_eActionType, unsigned int in_ulID)
{
  CAkActionSetSwitch *result; // rax
  CAkAction *v5; // rbx

  result = (CAkActionSetSwitch *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x40ui64);
  v5 = result;
  if ( result )
  {
    CAkAction::CAkAction(result, in_eActionType, in_ulID);
    v5->vfptr = (CAkIndexableVtbl *)&CAkActionSetSwitch::`vftable;
    v5[1].vfptr = 0i64;
    CAkAction::AddToIndex(v5);
    return (CAkActionSetSwitch *)v5;
  }
  return result;
}

// File Line: 71
// RVA: 0xA966C0
__int64 __fastcall CAkActionSetSwitch::SetActionParams(
        CAkActionSetSwitch *this,
        char **io_rpData,
        unsigned int *io_rulDataSize)
{
  unsigned int v3; // r8d
  unsigned int v4; // r8d

  v3 = *(_DWORD *)*io_rpData;
  *io_rpData += 4;
  this->m_ulSwitchGroupID = v3;
  v4 = *(_DWORD *)*io_rpData;
  *io_rpData += 4;
  this->m_ulSwitchStateID = v4;
  return 1i64;
}

