// File Line: 41
// RVA: 0xA965A0
__int64 __fastcall CAkActionSetState::Execute(CAkActionSetState *this, AkPendingAction *in_pAction)
{
  CAkStateMgr::SetStateInternal(g_pStateMgr, this->m_ulStateGroupID, this->m_ulTargetStateID, 0, 0);
  return 1i64;
}

// File Line: 52
// RVA: 0xA96520
CAkActionSetState *__fastcall CAkActionSetState::Create(AkActionType in_eActionType, unsigned int in_ulID)
{
  CAkActionSetState *result; // rax
  CAkAction *v5; // rbx

  result = (CAkActionSetState *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x40ui64);
  v5 = result;
  if ( result )
  {
    CAkAction::CAkAction(result, in_eActionType, in_ulID);
    v5->vfptr = (CAkIndexableVtbl *)&CAkActionSetState::`vftable;
    v5[1].vfptr = 0i64;
    CAkAction::AddToIndex(v5);
    return (CAkActionSetState *)v5;
  }
  return result;
}

