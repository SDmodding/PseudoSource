// File Line: 199
// RVA: 0x7FBB80
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_gfx::GamePadAnalogEvent::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent> *result, Scaleform::GFx::AS3::InstanceTraits::fl_gfx::GamePadAnalogEvent *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_gfx::GamePadAnalogEvent *v2; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent> *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *v4; // rax
  int v6; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *v7; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *v8; // [rsp+50h] [rbp+18h]

  v2 = t;
  v3 = result;
  v6 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *)t->pVM->MHeap->vfptr->Alloc(
                                                                       t->pVM->MHeap,
                                                                       t->MemSize,
                                                                       (Scaleform::AllocInfo *)&v6);
  v7 = v4;
  v8 = v4;
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent::GamePadAnalogEvent(
      v4,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
  v3->pV = v4;
  return v3;
}

