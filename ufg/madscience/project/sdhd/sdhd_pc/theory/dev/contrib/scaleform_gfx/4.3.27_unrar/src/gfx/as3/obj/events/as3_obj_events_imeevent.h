// File Line: 129
// RVA: 0x7FC480
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::IMEEvent> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_events::IMEEvent::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::IMEEvent> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_events::IMEEvent *t)
{
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_events::IMEEvent *v5; // rbx
  int v7; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent *v8; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent *v9; // [rsp+60h] [rbp+18h]

  v7 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_events::TextEvent *)t->pVM->MHeap->vfptr->Alloc(
                                                                 t->pVM->MHeap,
                                                                 t->MemSize,
                                                                 &v7);
  v5 = (Scaleform::GFx::AS3::Instances::fl_events::IMEEvent *)v4;
  v8 = v4;
  v9 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl_events::TextEvent::TextEvent(v4, t);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::IMEEvent::`vftable;
  }
  else
  {
    v5 = 0i64;
  }
  result->pV = v5;
  return result;
}

