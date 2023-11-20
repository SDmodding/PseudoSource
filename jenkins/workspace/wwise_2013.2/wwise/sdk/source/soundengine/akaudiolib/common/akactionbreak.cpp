// File Line: 24
// RVA: 0xA95BE0
CAkActionBreak *__fastcall CAkActionBreak::Create(AkActionType in_eActionType, unsigned int in_ulID)
{
  AkActionType v2; // esi
  unsigned int v3; // edi
  CAkActionBreak *result; // rax
  CAkActionBreak *v5; // rbx

  v2 = in_eActionType;
  v3 = in_ulID;
  result = (CAkActionBreak *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x38ui64);
  v5 = result;
  if ( result )
  {
    CAkAction::CAkAction((CAkAction *)&result->vfptr, v2, v3);
    v5->vfptr = (CAkIndexableVtbl *)&CAkActionBreak::`vftable;
    CAkAction::AddToIndex((CAkAction *)&v5->vfptr);
    result = v5;
  }
  return result;
}

// File Line: 48
// RVA: 0xA95C50
signed __int64 __fastcall CAkActionBreak::Execute(CAkActionBreak *this, AkPendingAction *in_pAction)
{
  AkPendingAction *v2; // rdi
  CAkParameterNodeBase *v3; // rbx
  __int64 v5; // rax
  unsigned int v6; // esi
  int v7; // [rsp+20h] [rbp-38h]
  __int64 v8; // [rsp+28h] [rbp-30h]
  int v9; // [rsp+30h] [rbp-28h]
  __int16 v10; // [rsp+3Ch] [rbp-1Ch]
  char v11; // [rsp+3Eh] [rbp-1Ah]
  CAkParameterNodeBase *v12; // [rsp+40h] [rbp-18h]

  v2 = in_pAction;
  v3 = (CAkParameterNodeBase *)CAkAction::GetAndRefTarget((CAkAction *)&this->vfptr);
  if ( !v3 )
    return 15i64;
  v5 = (__int64)v2->pGameObj;
  v7 = 3;
  v10 = 0;
  v8 = v5;
  LODWORD(v5) = v2->TargetPlayingID;
  v11 = 0;
  v12 = v3;
  v9 = v5;
  v6 = (__int64)v3->vfptr[4].__vecDelDtor((CAkIndexable *)&v3->vfptr, (unsigned int)&v7);
  if ( v6 == 1 )
    v6 = CAkAudioMgr::BreakPendingAction(g_pAudioMgr, v3, v2->pGameObj, v2->TargetPlayingID);
  v3->vfptr->Release((CAkIndexable *)&v3->vfptr);
  return v6;
}

