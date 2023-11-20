// File Line: 41
// RVA: 0xA965A0
signed __int64 __fastcall CAkActionSetState::Execute(CAkActionSetState *this, AkPendingAction *in_pAction)
{
  CAkStateMgr::SetStateInternal(g_pStateMgr, this->m_ulStateGroupID, this->m_ulTargetStateID, 0, 0);
  return 1i64;
}

// File Line: 52
// RVA: 0xA96520
CAkActionSetState *__fastcall CAkActionSetState::Create(AkActionType in_eActionType, unsigned int in_ulID)
{
  AkActionType v2; // esi
  unsigned int v3; // edi
  CAkActionSetState *result; // rax
  CAkActionSetState *v5; // rbx

  v2 = in_eActionType;
  v3 = in_ulID;
  result = (CAkActionSetState *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x40ui64);
  v5 = result;
  if ( result )
  {
    CAkAction::CAkAction((CAkAction *)&result->vfptr, v2, v3);
    v5->vfptr = (CAkIndexableVtbl *)&CAkActionSetState::`vftable';
    *(_QWORD *)&v5->m_ulStateGroupID = 0i64;
    CAkAction::AddToIndex((CAkAction *)&v5->vfptr);
    result = v5;
  }
  return result;
}

