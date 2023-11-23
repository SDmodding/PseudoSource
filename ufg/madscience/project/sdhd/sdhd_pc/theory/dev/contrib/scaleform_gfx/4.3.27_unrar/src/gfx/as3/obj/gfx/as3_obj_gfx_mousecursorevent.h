// File Line: 112
// RVA: 0x7FCAA0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::MouseCursorEvent> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_gfx::MouseCursorEvent::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::MouseCursorEvent> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_gfx::MouseCursorEvent *t)
{
  Scaleform::GFx::AS3::Instances::fl_gfx::MouseCursorEvent *v4; // rax
  int v6; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Instances::fl_gfx::MouseCursorEvent *v7; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_gfx::MouseCursorEvent *v8; // [rsp+50h] [rbp+18h]

  v6 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_gfx::MouseCursorEvent *)t->pVM->MHeap->vfptr->Alloc(
                                                                     t->pVM->MHeap,
                                                                     t->MemSize,
                                                                     &v6);
  v7 = v4;
  v8 = v4;
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_gfx::MouseCursorEvent::MouseCursorEvent(v4, t);
  result->pV = v4;
  return result;
}

