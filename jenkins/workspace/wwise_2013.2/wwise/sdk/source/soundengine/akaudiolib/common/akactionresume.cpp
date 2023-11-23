// File Line: 40
// RVA: 0xA959C0
CAkActionResume *__fastcall CAkActionResume::Create(AkActionType in_eActionType, unsigned int in_ulID)
{
  CAkActionResume *result; // rax
  CAkActionResume *v5; // rbx

  result = (CAkActionResume *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x50ui64);
  v5 = result;
  if ( result )
  {
    CAkActionActive::CAkActionActive(result, in_eActionType, in_ulID);
    v5->vfptr = (CAkIndexableVtbl *)&CAkActionResume::`vftable;
    CAkAction::AddToIndex(v5);
    return v5;
  }
  return result;
}

// File Line: 55
// RVA: 0xA95A30
__int64 __fastcall CAkActionResume::Execute(CAkActionResume *this, AkPendingAction *in_pAction)
{
  CAkRegisteredObj *pGameObj; // rsi
  AKRESULT v5; // ebp
  CAkParameterNodeBase *v6; // r14

  pGameObj = in_pAction->pGameObj;
  v5 = AK_Success;
  switch ( this->m_eActionType )
  {
    case 0x302u:
    case 0x303u:
      v6 = CAkAction::GetAndRefTarget(this);
      if ( v6 )
      {
        v5 = CAkActionActive::Exec(this, ActionParamType_Resume, pGameObj, in_pAction->TargetPlayingID);
        CAkAudioMgr::ResumePausedPendingAction(
          g_pAudioMgr,
          v6,
          pGameObj,
          this->m_bIsMasterResume,
          in_pAction->TargetPlayingID);
        v6->vfptr->Release(v6);
      }
      break;
    case 0x304u:
    case 0x305u:
      CAkActionActive::AllExec(this, ActionParamType_Resume, in_pAction->pGameObj, in_pAction->TargetPlayingID);
      CAkAudioMgr::ResumePausedPendingAction(
        g_pAudioMgr,
        0i64,
        pGameObj,
        this->m_bIsMasterResume,
        in_pAction->TargetPlayingID);
      break;
    case 0x308u:
    case 0x309u:
      CAkActionActive::AllExecExcept(this, ActionParamType_Resume, in_pAction->pGameObj, in_pAction->TargetPlayingID);
      CAkAudioMgr::ResumePausedPendingActionAllExcept(
        g_pAudioMgr,
        pGameObj,
        &this->m_listElementException,
        this->m_bIsMasterResume,
        in_pAction->TargetPlayingID);
      break;
    default:
      return (unsigned int)v5;
  }
  return (unsigned int)v5;
}

// File Line: 112
// RVA: 0xA95B80
__int64 __fastcall CAkActionResume::SetActionSpecificParams(
        CAkActionResume *this,
        char **io_rpData,
        unsigned int *io_rulDataSize)
{
  char v3; // r8

  v3 = *(*io_rpData)++;
  this->m_bIsMasterResume = v3 != 0;
  return 1i64;
}

