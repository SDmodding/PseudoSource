// File Line: 144
// RVA: 0x7FAC00
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_events::AppLifecycleEvent::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent> *result, Scaleform::GFx::AS3::InstanceTraits::fl_events::AppLifecycleEvent *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_events::AppLifecycleEvent *v2; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent> *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent *v4; // rax
  int v6; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent *v7; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent *v8; // [rsp+50h] [rbp+18h]

  v2 = t;
  v3 = result;
  v6 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent *)t->pVM->MHeap->vfptr->Alloc(
                                                                         t->pVM->MHeap,
                                                                         t->MemSize,
                                                                         (Scaleform::AllocInfo *)&v6);
  v7 = v4;
  v8 = v4;
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent::AppLifecycleEvent(
      v4,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
  v3->pV = v4;
  return v3;
}

