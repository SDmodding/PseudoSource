// File Line: 39
// RVA: 0xA96690
signed __int64 __fastcall CAkActionSetSwitch::Execute(CAkActionSetSwitch *this, AkPendingAction *in_pAction)
{
  CAkRTPCMgr::SetSwitchInternal(g_pRTPCMgr, this->m_ulSwitchGroupID, this->m_ulSwitchStateID, in_pAction->pGameObj);
  return 1i64;
}

// File Line: 46
// RVA: 0xA96610
CAkActionSetSwitch *__fastcall CAkActionSetSwitch::Create(AkActionType in_eActionType, unsigned int in_ulID)
{
  AkActionType v2; // esi
  unsigned int v3; // edi
  CAkActionSetSwitch *result; // rax
  CAkActionSetSwitch *v5; // rbx

  v2 = in_eActionType;
  v3 = in_ulID;
  result = (CAkActionSetSwitch *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x40ui64);
  v5 = result;
  if ( result )
  {
    CAkAction::CAkAction((CAkAction *)&result->vfptr, v2, v3);
    v5->vfptr = (CAkIndexableVtbl *)&CAkActionSetSwitch::`vftable;
    *(_QWORD *)&v5->m_ulSwitchGroupID = 0i64;
    CAkAction::AddToIndex((CAkAction *)&v5->vfptr);
    result = v5;
  }
  return result;
}

// File Line: 71
// RVA: 0xA966C0
signed __int64 __fastcall CAkActionSetSwitch::SetActionParams(CAkActionSetSwitch *this, char **io_rpData, unsigned int *io_rulDataSize)
{
  unsigned int v3; // er8
  unsigned int v4; // er8

  v3 = *(_DWORD *)*io_rpData;
  *io_rpData += 4;
  this->m_ulSwitchGroupID = v3;
  v4 = *(_DWORD *)*io_rpData;
  *io_rpData += 4;
  this->m_ulSwitchStateID = v4;
  return 1i64;
}

