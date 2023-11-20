// File Line: 33
// RVA: 0xA96A70
signed __int64 __fastcall CAkActionUseState::Execute(CAkActionUseState *this, AkPendingAction *__formal)
{
  CAkActionUseState *v2; // rdi
  CAkParameterNodeBase *v3; // rbx

  v2 = this;
  v3 = (CAkParameterNodeBase *)CAkAction::GetAndRefTarget((CAkAction *)&this->vfptr);
  if ( v3 )
  {
    CAkParameterNodeBase::UseState(v3, v2->m_eActionType == 4098);
    v3->vfptr->Release((CAkIndexable *)&v3->vfptr);
  }
  return 1i64;
}

// File Line: 45
// RVA: 0xA96A00
CAkActionUseState *__fastcall CAkActionUseState::Create(AkActionType in_eActionType, unsigned int in_ulID)
{
  AkActionType v2; // esi
  unsigned int v3; // edi
  CAkActionUseState *result; // rax
  CAkActionUseState *v5; // rbx

  v2 = in_eActionType;
  v3 = in_ulID;
  result = (CAkActionUseState *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x38ui64);
  v5 = result;
  if ( result )
  {
    CAkAction::CAkAction((CAkAction *)&result->vfptr, v2, v3);
    v5->vfptr = (CAkIndexableVtbl *)&CAkActionUseState::`vftable';
    CAkAction::AddToIndex((CAkAction *)&v5->vfptr);
    result = v5;
  }
  return result;
}

