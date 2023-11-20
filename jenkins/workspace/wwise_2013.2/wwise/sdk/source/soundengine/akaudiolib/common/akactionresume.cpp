// File Line: 40
// RVA: 0xA959C0
CAkActionResume *__fastcall CAkActionResume::Create(AkActionType in_eActionType, unsigned int in_ulID)
{
  AkActionType v2; // esi
  unsigned int v3; // edi
  CAkActionResume *result; // rax
  CAkActionResume *v5; // rbx

  v2 = in_eActionType;
  v3 = in_ulID;
  result = (CAkActionResume *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x50ui64);
  v5 = result;
  if ( result )
  {
    CAkActionActive::CAkActionActive((CAkActionActive *)&result->vfptr, v2, v3);
    v5->vfptr = (CAkIndexableVtbl *)&CAkActionResume::`vftable';
    CAkAction::AddToIndex((CAkAction *)&v5->vfptr);
    result = v5;
  }
  return result;
}

// File Line: 55
// RVA: 0xA95A30
__int64 __fastcall CAkActionResume::Execute(CAkActionResume *this, AkPendingAction *in_pAction)
{
  CAkRegisteredObj *v2; // rsi
  AkPendingAction *v3; // rdi
  CAkActionResume *v4; // rbx
  AKRESULT v5; // ebp
  CAkParameterNodeBase *v6; // r14

  v2 = in_pAction->pGameObj;
  v3 = in_pAction;
  v4 = this;
  v5 = 1;
  switch ( this->m_eActionType )
  {
    case 0x302u:
    case 0x303u:
      v6 = (CAkParameterNodeBase *)CAkAction::GetAndRefTarget((CAkAction *)&this->vfptr);
      if ( v6 )
      {
        v5 = CAkActionActive::Exec((CAkActionActive *)&v4->vfptr, ActionParamType_Resume, v2, v3->TargetPlayingID);
        CAkAudioMgr::ResumePausedPendingAction(g_pAudioMgr, v6, v2, v4->m_bIsMasterResume, v3->TargetPlayingID);
        v6->vfptr->Release((CAkIndexable *)&v6->vfptr);
      }
      break;
    case 0x304u:
    case 0x305u:
      CAkActionActive::AllExec(
        (CAkActionActive *)&this->vfptr,
        ActionParamType_Resume,
        in_pAction->pGameObj,
        in_pAction->TargetPlayingID);
      CAkAudioMgr::ResumePausedPendingAction(g_pAudioMgr, 0i64, v2, v4->m_bIsMasterResume, v3->TargetPlayingID);
      break;
    case 0x308u:
    case 0x309u:
      CAkActionActive::AllExecExcept(
        (CAkActionActive *)&this->vfptr,
        ActionParamType_Resume,
        in_pAction->pGameObj,
        in_pAction->TargetPlayingID);
      CAkAudioMgr::ResumePausedPendingActionAllExcept(
        g_pAudioMgr,
        v2,
        &v4->m_listElementException,
        v4->m_bIsMasterResume,
        v3->TargetPlayingID);
      break;
    default:
      return (unsigned int)v5;
  }
  return (unsigned int)v5;
}

// File Line: 112
// RVA: 0xA95B80
signed __int64 __fastcall CAkActionResume::SetActionSpecificParams(CAkActionResume *this, char **io_rpData, unsigned int *io_rulDataSize)
{
  char v3; // r8

  v3 = *(*io_rpData)++;
  this->m_bIsMasterResume = v3 != 0;
  return 1i64;
}

