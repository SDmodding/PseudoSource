// File Line: 24
// RVA: 0xA95BE0
CAkActionBreak *__fastcall CAkActionBreak::Create(AkActionType in_eActionType, unsigned int in_ulID)
{
  CAkActionBreak *result; // rax
  CAkActionBreak *v5; // rbx

  result = (CAkActionBreak *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x38ui64);
  v5 = result;
  if ( result )
  {
    CAkAction::CAkAction(result, in_eActionType, in_ulID);
    v5->vfptr = (CAkIndexableVtbl *)&CAkActionBreak::`vftable;
    CAkAction::AddToIndex(v5);
    return v5;
  }
  return result;
}

// File Line: 48
// RVA: 0xA95C50
__int64 __fastcall CAkActionBreak::Execute(CAkActionBreak *this, AkPendingAction *in_pAction)
{
  CAkParameterNodeBase *v3; // rbx
  CAkRegisteredObj *pGameObj; // rax
  unsigned int v6; // esi
  int v7; // [rsp+20h] [rbp-38h] BYREF
  CAkRegisteredObj *v8; // [rsp+28h] [rbp-30h]
  int v9; // [rsp+30h] [rbp-28h]
  __int16 v10; // [rsp+3Ch] [rbp-1Ch]
  char v11; // [rsp+3Eh] [rbp-1Ah]
  CAkParameterNodeBase *v12; // [rsp+40h] [rbp-18h]

  v3 = CAkAction::GetAndRefTarget(this);
  if ( !v3 )
    return 15i64;
  pGameObj = in_pAction->pGameObj;
  v7 = 3;
  v10 = 0;
  v8 = pGameObj;
  LODWORD(pGameObj) = in_pAction->TargetPlayingID;
  v11 = 0;
  v12 = v3;
  v9 = (int)pGameObj;
  v6 = (unsigned int)v3->vfptr[4].__vecDelDtor(v3, (unsigned int)&v7);
  if ( v6 == 1 )
    v6 = CAkAudioMgr::BreakPendingAction(g_pAudioMgr, v3, in_pAction->pGameObj, in_pAction->TargetPlayingID);
  v3->vfptr->Release(v3);
  return v6;
}

