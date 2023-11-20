// File Line: 183
// RVA: 0x7FD170
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_events::PressAndTapGestureEvent::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent> *result, Scaleform::GFx::AS3::InstanceTraits::fl_events::PressAndTapGestureEvent *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_events::PressAndTapGestureEvent *v2; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent> *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *v5; // rbx
  int v7; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *v8; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *v9; // [rsp+60h] [rbp+18h]

  v2 = t;
  v3 = result;
  v7 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *)t->pVM->MHeap->vfptr->Alloc(
                                                                    t->pVM->MHeap,
                                                                    t->MemSize,
                                                                    (Scaleform::AllocInfo *)&v7);
  v5 = v4;
  v8 = v4;
  v9 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl_events::GestureEvent::GestureEvent(
      v4,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent::`vftable;
    v5[1].pRCCRaw = 0i64;
    v5[1].vfptr = 0i64;
    v5[1].pPrev = 0i64;
    v5[1].pNext = 0i64;
    LOWORD(v5[1].RefCount) = 0;
  }
  else
  {
    v5 = 0i64;
  }
  v3->pV = (Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent *)v5;
  return v3;
}

