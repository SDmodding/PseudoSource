// File Line: 334
// RVA: 0x7FCB10
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_events::MouseEvent::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> *result, Scaleform::GFx::AS3::InstanceTraits::fl_events::MouseEvent *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_events::MouseEvent *v2; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *v4; // rax
  int v6; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *v7; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *v8; // [rsp+50h] [rbp+18h]

  v2 = t;
  v3 = result;
  v6 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)t->pVM->MHeap->vfptr->Alloc(
                                                                  t->pVM->MHeap,
                                                                  t->MemSize,
                                                                  (Scaleform::AllocInfo *)&v6);
  v7 = v4;
  v8 = v4;
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_events::MouseEvent::MouseEvent(
      v4,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
  v3->pV = v4;
  return v3;
}

