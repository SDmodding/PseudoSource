// File Line: 41
// RVA: 0xA957A0
CAkActionPause *__fastcall CAkActionPause::Create(AkActionType in_eActionType, unsigned int in_ulID)
{
  CAkActionPause *result; // rax
  CAkActionPause *v5; // rbx

  result = (CAkActionPause *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x58ui64);
  v5 = result;
  if ( result )
  {
    CAkActionActive::CAkActionActive(result, in_eActionType, in_ulID);
    v5->vfptr = (CAkIndexableVtbl *)&CAkActionPause::`vftable;
    v5->m_bPausePendingResume = 1;
    CAkAction::AddToIndex(v5);
    return v5;
  }
  return result;
}

// File Line: 56
// RVA: 0xA95820
__int64 __fastcall CAkActionPause::Execute(CAkActionPause *this, AkPendingAction *in_pAction)
{
  CAkRegisteredObj *pGameObj; // rbp
  AKRESULT v5; // esi
  CAkParameterNodeBase *v6; // r14

  pGameObj = in_pAction->pGameObj;
  v5 = AK_Success;
  switch ( this->m_eActionType )
  {
    case 0x202u:
    case 0x203u:
      v6 = CAkAction::GetAndRefTarget(this);
      if ( v6 )
      {
        v5 = CAkActionActive::Exec(this, ActionParamType_Pause, pGameObj, in_pAction->TargetPlayingID);
        CAkAudioMgr::PausePendingAction(
          g_pAudioMgr,
          v6,
          pGameObj,
          this->m_bPausePendingResume,
          in_pAction->TargetPlayingID);
        v6->vfptr->Release(v6);
      }
      break;
    case 0x204u:
    case 0x205u:
      CAkActionActive::AllExec(this, ActionParamType_Pause, in_pAction->pGameObj, in_pAction->TargetPlayingID);
      CAkAudioMgr::PausePendingAction(
        g_pAudioMgr,
        0i64,
        pGameObj,
        this->m_bPausePendingResume,
        in_pAction->TargetPlayingID);
      break;
    case 0x208u:
    case 0x209u:
      CAkActionActive::AllExecExcept(this, ActionParamType_Pause, in_pAction->pGameObj, in_pAction->TargetPlayingID);
      CAkAudioMgr::PausePendingActionAllExcept(
        g_pAudioMgr,
        pGameObj,
        &this->m_listElementException,
        this->m_bPausePendingResume,
        in_pAction->TargetPlayingID);
      break;
    default:
      return (unsigned int)v5;
  }
  return (unsigned int)v5;
}

// File Line: 114
// RVA: 0xA95960
__int64 __fastcall CAkActionPause::SetActionSpecificParams(
        CAkActionPause *this,
        char **io_rpData,
        unsigned int *io_rulDataSize)
{
  char v3; // r8

  v3 = *(*io_rpData)++;
  this->m_bPausePendingResume = v3 != 0;
  return 1i64;
}

