// File Line: 26
// RVA: 0xA97E60
void __fastcall CAkActionDuck::CAkActionDuck(CAkActionDuck *this, AkActionType in_eActionType, unsigned int in_ulID)
{
  CAkAction::CAkAction(this, in_eActionType, in_ulID);
  this->vfptr = (CAkIndexableVtbl *)&CAkActionDuck::`vftable;
}

// File Line: 34
// RVA: 0xA97ED0
__int64 __fastcall CAkActionDuck::Execute(CAkActionDuck *this, AkPendingAction *in_pAction)
{
  CAkBus *v2; // rax
  CAkBus *v3; // rbx

  v2 = (CAkBus *)CAkAction::GetAndRefTarget(this);
  v3 = v2;
  if ( v2 )
  {
    CAkBus::DuckNotif(v2);
    v3->vfptr->Release(v3);
  }
  return 1i64;
}

