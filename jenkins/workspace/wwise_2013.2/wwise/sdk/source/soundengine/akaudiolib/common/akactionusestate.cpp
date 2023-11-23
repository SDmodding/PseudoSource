// File Line: 33
// RVA: 0xA96A70
__int64 __fastcall CAkActionUseState::Execute(CAkActionUseState *this, AkPendingAction *__formal)
{
  CAkParameterNodeBase *v3; // rbx

  v3 = CAkAction::GetAndRefTarget(this);
  if ( v3 )
  {
    CAkParameterNodeBase::UseState(v3, this->m_eActionType == 4098);
    v3->vfptr->Release(v3);
  }
  return 1i64;
}

// File Line: 45
// RVA: 0xA96A00
CAkActionUseState *__fastcall CAkActionUseState::Create(AkActionType in_eActionType, unsigned int in_ulID)
{
  CAkActionUseState *result; // rax
  CAkActionUseState *v5; // rbx

  result = (CAkActionUseState *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x38ui64);
  v5 = result;
  if ( result )
  {
    CAkAction::CAkAction(result, in_eActionType, in_ulID);
    v5->vfptr = (CAkIndexableVtbl *)&CAkActionUseState::`vftable;
    CAkAction::AddToIndex(v5);
    return v5;
  }
  return result;
}

