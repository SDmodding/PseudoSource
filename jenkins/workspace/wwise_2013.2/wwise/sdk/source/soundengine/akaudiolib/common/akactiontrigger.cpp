// File Line: 35
// RVA: 0xA97080
__int64 __fastcall CAkActionTrigger::Execute(CAkActionTrigger *this, AkPendingAction *in_pAction)
{
  CAkStateMgr::Trigger(g_pStateMgr, this->m_ulElementID, in_pAction->pGameObj);
  return 1i64;
}

// File Line: 41
// RVA: 0xA97010
CAkActionTrigger *__fastcall CAkActionTrigger::Create(AkActionType in_eActionType, unsigned int in_ulID)
{
  CAkActionTrigger *result; // rax
  CAkActionTrigger *v5; // rbx

  result = (CAkActionTrigger *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x38ui64);
  v5 = result;
  if ( result )
  {
    CAkAction::CAkAction(result, in_eActionType, in_ulID);
    v5->vfptr = (CAkIndexableVtbl *)&CAkActionTrigger::`vftable;
    CAkAction::AddToIndex(v5);
    return v5;
  }
  return result;
}

