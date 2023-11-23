// File Line: 113
// RVA: 0x7FC280
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::HTMLUncaughtScriptExceptionEvent> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_events::HTMLUncaughtScriptExceptionEvent::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::HTMLUncaughtScriptExceptionEvent> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_events::HTMLUncaughtScriptExceptionEvent *t)
{
  Scaleform::GFx::AS3::Instances::fl_events::HTMLUncaughtScriptExceptionEvent *v4; // rax
  int v6; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Instances::fl_events::HTMLUncaughtScriptExceptionEvent *v7; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_events::HTMLUncaughtScriptExceptionEvent *v8; // [rsp+50h] [rbp+18h]

  v6 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_events::HTMLUncaughtScriptExceptionEvent *)t->pVM->MHeap->vfptr->Alloc(
                                                                                        t->pVM->MHeap,
                                                                                        t->MemSize,
                                                                                        &v6);
  v7 = v4;
  v8 = v4;
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_events::HTMLUncaughtScriptExceptionEvent::HTMLUncaughtScriptExceptionEvent(v4, t);
  result->pV = v4;
  return result;
}

