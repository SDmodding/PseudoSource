// File Line: 40
// RVA: 0xA77EF0
CAkActionStop *__fastcall CAkActionStop::Create(AkActionType in_eActionType, unsigned int in_ulID)
{
  CAkActionStop *result; // rax
  CAkActionStop *v5; // rbx

  result = (CAkActionStop *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x50ui64);
  v5 = result;
  if ( result )
  {
    CAkActionActive::CAkActionActive(result, in_eActionType, in_ulID);
    v5->vfptr = (CAkIndexableVtbl *)&CAkActionStop::`vftable;
    CAkAction::AddToIndex(v5);
    return v5;
  }
  return result;
}

// File Line: 55
// RVA: 0xA77F60
__int64 __fastcall CAkActionStop::Execute(CAkActionStop *this, AkPendingAction *in_pAction)
{
  CAkRegisteredObj *pGameObj; // rsi
  AKRESULT v5; // ebp
  CAkParameterNodeBase *v6; // r14

  pGameObj = in_pAction->pGameObj;
  v5 = AK_Success;
  switch ( this->m_eActionType )
  {
    case 0x102u:
    case 0x103u:
      v6 = CAkAction::GetAndRefTarget(this);
      if ( v6 )
      {
        v5 = CAkActionActive::Exec(this, ActionParamType_Stop, pGameObj, in_pAction->TargetPlayingID);
        CAkAudioMgr::StopPendingAction(g_pAudioMgr, v6, pGameObj, in_pAction->TargetPlayingID);
        v6->vfptr->Release(v6);
      }
      break;
    case 0x104u:
    case 0x105u:
      CAkActionActive::AllExec(this, ActionParamType_Stop, in_pAction->pGameObj, in_pAction->TargetPlayingID);
      CAkAudioMgr::StopPendingAction(g_pAudioMgr, 0i64, pGameObj, in_pAction->TargetPlayingID);
      break;
    case 0x108u:
    case 0x109u:
      CAkActionActive::AllExecExcept(this, ActionParamType_Stop, in_pAction->pGameObj, in_pAction->TargetPlayingID);
      CAkAudioMgr::StopPendingActionAllExcept(
        g_pAudioMgr,
        pGameObj,
        &this->m_listElementException,
        in_pAction->TargetPlayingID);
      break;
    default:
      return (unsigned int)v5;
  }
  return (unsigned int)v5;
}

