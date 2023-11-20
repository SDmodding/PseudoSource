// File Line: 41
// RVA: 0xA957A0
CAkActionPause *__fastcall CAkActionPause::Create(AkActionType in_eActionType, unsigned int in_ulID)
{
  AkActionType v2; // esi
  unsigned int v3; // edi
  CAkActionPause *result; // rax
  CAkActionPause *v5; // rbx

  v2 = in_eActionType;
  v3 = in_ulID;
  result = (CAkActionPause *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x58ui64);
  v5 = result;
  if ( result )
  {
    CAkActionActive::CAkActionActive((CAkActionActive *)&result->vfptr, v2, v3);
    v5->vfptr = (CAkIndexableVtbl *)&CAkActionPause::`vftable;
    v5->m_bPausePendingResume = 1;
    CAkAction::AddToIndex((CAkAction *)&v5->vfptr);
    result = v5;
  }
  return result;
}

// File Line: 56
// RVA: 0xA95820
__int64 __fastcall CAkActionPause::Execute(CAkActionPause *this, AkPendingAction *in_pAction)
{
  CAkRegisteredObj *v2; // rbp
  AkPendingAction *v3; // rdi
  CAkActionPause *v4; // rbx
  AKRESULT v5; // esi
  CAkParameterNodeBase *v6; // r14

  v2 = in_pAction->pGameObj;
  v3 = in_pAction;
  v4 = this;
  v5 = 1;
  switch ( this->m_eActionType )
  {
    case 0x202u:
    case 0x203u:
      v6 = (CAkParameterNodeBase *)CAkAction::GetAndRefTarget((CAkAction *)&this->vfptr);
      if ( v6 )
      {
        v5 = CAkActionActive::Exec((CAkActionActive *)&v4->vfptr, ActionParamType_Pause, v2, v3->TargetPlayingID);
        CAkAudioMgr::PausePendingAction(g_pAudioMgr, v6, v2, v4->m_bPausePendingResume, v3->TargetPlayingID);
        v6->vfptr->Release((CAkIndexable *)&v6->vfptr);
      }
      break;
    case 0x204u:
    case 0x205u:
      CAkActionActive::AllExec(
        (CAkActionActive *)&this->vfptr,
        ActionParamType_Pause,
        in_pAction->pGameObj,
        in_pAction->TargetPlayingID);
      CAkAudioMgr::PausePendingAction(g_pAudioMgr, 0i64, v2, v4->m_bPausePendingResume, v3->TargetPlayingID);
      break;
    case 0x208u:
    case 0x209u:
      CAkActionActive::AllExecExcept(
        (CAkActionActive *)&this->vfptr,
        ActionParamType_Pause,
        in_pAction->pGameObj,
        in_pAction->TargetPlayingID);
      CAkAudioMgr::PausePendingActionAllExcept(
        g_pAudioMgr,
        v2,
        &v4->m_listElementException,
        v4->m_bPausePendingResume,
        v3->TargetPlayingID);
      break;
    default:
      return (unsigned int)v5;
  }
  return (unsigned int)v5;
}

// File Line: 114
// RVA: 0xA95960
signed __int64 __fastcall CAkActionPause::SetActionSpecificParams(CAkActionPause *this, char **io_rpData, unsigned int *io_rulDataSize)
{
  char v3; // r8

  v3 = *(*io_rpData)++;
  this->m_bPausePendingResume = v3 != 0;
  return 1i64;
}

