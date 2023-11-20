// File Line: 87
// RVA: 0x7E96C0
const char *__fastcall Scaleform::GFx::AS3::Instances::fl_events::TimerEvent::GetEventName(Scaleform::GFx::AS3::Instances::fl_events::TimerEvent *this)
{
  return "TimerEvent";
}

// File Line: 137
// RVA: 0x7FDC00
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::TimerEvent> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_events::TimerEvent::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::TimerEvent> *result, Scaleform::GFx::AS3::InstanceTraits::fl_events::TimerEvent *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_events::TimerEvent *v2; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::TimerEvent> *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl_events::TimerEvent *v4; // rax
  int v6; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::AS3::Instances::fl_events::TimerEvent *v7; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_events::TimerEvent *v8; // [rsp+50h] [rbp+18h]

  v2 = t;
  v3 = result;
  v6 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_events::TimerEvent *)t->pVM->MHeap->vfptr->Alloc(
                                                                  t->pVM->MHeap,
                                                                  t->MemSize,
                                                                  (Scaleform::AllocInfo *)&v6);
  v7 = v4;
  v8 = v4;
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_events::TimerEvent::TimerEvent(
      v4,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
  v3->pV = v4;
  return v3;
}

