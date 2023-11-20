// File Line: 112
// RVA: 0x7FC780
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::KeyboardEventEx> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_gfx::KeyboardEventEx::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::KeyboardEventEx> *result, Scaleform::GFx::AS3::InstanceTraits::fl_gfx::KeyboardEventEx *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_gfx::KeyboardEventEx *v2; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::KeyboardEventEx> *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_gfx::KeyboardEventEx *v5; // rbx
  int v7; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *v8; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *v9; // [rsp+60h] [rbp+18h]

  v2 = t;
  v3 = result;
  v7 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *)t->pVM->MHeap->vfptr->Alloc(
                                                                     t->pVM->MHeap,
                                                                     t->MemSize,
                                                                     (Scaleform::AllocInfo *)&v7);
  v5 = (Scaleform::GFx::AS3::Instances::fl_gfx::KeyboardEventEx *)v4;
  v8 = v4;
  v9 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent::KeyboardEvent(
      v4,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_gfx::KeyboardEventEx::`vftable';
    v5->controllerIdx = 0;
  }
  else
  {
    v5 = 0i64;
  }
  v3->pV = v5;
  return v3;
}

