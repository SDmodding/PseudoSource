// File Line: 35
// RVA: 0xA97080
signed __int64 __fastcall CAkActionTrigger::Execute(CAkActionTrigger *this, AkPendingAction *in_pAction)
{
  CAkStateMgr::Trigger(g_pStateMgr, this->m_ulElementID, in_pAction->pGameObj);
  return 1i64;
}

// File Line: 41
// RVA: 0xA97010
CAkActionTrigger *__fastcall CAkActionTrigger::Create(AkActionType in_eActionType, unsigned int in_ulID)
{
  AkActionType v2; // esi
  unsigned int v3; // edi
  CAkActionTrigger *result; // rax
  CAkActionTrigger *v5; // rbx

  v2 = in_eActionType;
  v3 = in_ulID;
  result = (CAkActionTrigger *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x38ui64);
  v5 = result;
  if ( result )
  {
    CAkAction::CAkAction((CAkAction *)&result->vfptr, v2, v3);
    v5->vfptr = (CAkIndexableVtbl *)&CAkActionTrigger::`vftable;
    CAkAction::AddToIndex((CAkAction *)&v5->vfptr);
    result = v5;
  }
  return result;
}

