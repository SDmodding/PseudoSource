// File Line: 127
// RVA: 0x7FAD50
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::AsyncErrorEvent> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_events::AsyncErrorEvent::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::AsyncErrorEvent> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_events::AsyncErrorEvent *t)
{
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_events::AsyncErrorEvent *v5; // rbx
  int v7; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent *v8; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent *v9; // [rsp+60h] [rbp+18h]

  v7 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_events::TextEvent *)t->pVM->MHeap->vfptr->Alloc(
                                                                 t->pVM->MHeap,
                                                                 t->MemSize,
                                                                 &v7);
  v5 = (Scaleform::GFx::AS3::Instances::fl_events::AsyncErrorEvent *)v4;
  v8 = v4;
  v9 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl_events::TextEvent::TextEvent(v4, t);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent::`vftable;
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::AsyncErrorEvent::`vftable;
    v5->error.pObject = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  result->pV = v5;
  return result;
}

