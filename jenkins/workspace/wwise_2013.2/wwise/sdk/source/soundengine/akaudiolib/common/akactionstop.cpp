// File Line: 40
// RVA: 0xA77EF0
CAkActionStop *__fastcall CAkActionStop::Create(AkActionType in_eActionType, unsigned int in_ulID)
{
  AkActionType v2; // esi
  unsigned int v3; // edi
  CAkActionStop *result; // rax
  CAkActionStop *v5; // rbx

  v2 = in_eActionType;
  v3 = in_ulID;
  result = (CAkActionStop *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x50ui64);
  v5 = result;
  if ( result )
  {
    CAkActionActive::CAkActionActive((CAkActionActive *)&result->vfptr, v2, v3);
    v5->vfptr = (CAkIndexableVtbl *)&CAkActionStop::`vftable;
    CAkAction::AddToIndex((CAkAction *)&v5->vfptr);
    result = v5;
  }
  return result;
}

// File Line: 55
// RVA: 0xA77F60
__int64 __fastcall CAkActionStop::Execute(CAkActionStop *this, AkPendingAction *in_pAction)
{
  CAkRegisteredObj *v2; // rsi
  AkPendingAction *v3; // rdi
  CAkActionStop *v4; // rbx
  AKRESULT v5; // ebp
  CAkParameterNodeBase *v6; // r14

  v2 = in_pAction->pGameObj;
  v3 = in_pAction;
  v4 = this;
  v5 = 1;
  switch ( this->m_eActionType )
  {
    case 0x102u:
    case 0x103u:
      v6 = (CAkParameterNodeBase *)CAkAction::GetAndRefTarget((CAkAction *)&this->vfptr);
      if ( v6 )
      {
        v5 = CAkActionActive::Exec((CAkActionActive *)&v4->vfptr, 0, v2, v3->TargetPlayingID);
        CAkAudioMgr::StopPendingAction(g_pAudioMgr, v6, v2, v3->TargetPlayingID);
        v6->vfptr->Release((CAkIndexable *)&v6->vfptr);
      }
      break;
    case 0x104u:
    case 0x105u:
      CAkActionActive::AllExec((CAkActionActive *)&this->vfptr, 0, in_pAction->pGameObj, in_pAction->TargetPlayingID);
      CAkAudioMgr::StopPendingAction(g_pAudioMgr, 0i64, v2, v3->TargetPlayingID);
      break;
    case 0x108u:
    case 0x109u:
      CAkActionActive::AllExecExcept(
        (CAkActionActive *)&this->vfptr,
        0,
        in_pAction->pGameObj,
        in_pAction->TargetPlayingID);
      CAkAudioMgr::StopPendingActionAllExcept(g_pAudioMgr, v2, &v4->m_listElementException, v3->TargetPlayingID);
      break;
    default:
      return (unsigned int)v5;
  }
  return (unsigned int)v5;
}

