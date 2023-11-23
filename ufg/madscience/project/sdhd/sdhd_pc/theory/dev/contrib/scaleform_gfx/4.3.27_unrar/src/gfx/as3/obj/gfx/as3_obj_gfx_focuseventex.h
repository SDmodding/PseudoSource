// File Line: 112
// RVA: 0x7FB970
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::FocusEventEx> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_gfx::FocusEventEx::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::FocusEventEx> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_gfx::FocusEventEx *t)
{
  Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_gfx::FocusEventEx *v5; // rbx
  int v7; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *v8; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *v9; // [rsp+60h] [rbp+18h]

  v7 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *)t->pVM->MHeap->vfptr->Alloc(
                                                                  t->pVM->MHeap,
                                                                  t->MemSize,
                                                                  &v7);
  v5 = (Scaleform::GFx::AS3::Instances::fl_gfx::FocusEventEx *)v4;
  v8 = v4;
  v9 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl_events::FocusEvent::FocusEvent(v4, t);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_gfx::FocusEventEx::`vftable;
    v5->controllerIdx = 0;
  }
  else
  {
    v5 = 0i64;
  }
  result->pV = v5;
  return result;
}

