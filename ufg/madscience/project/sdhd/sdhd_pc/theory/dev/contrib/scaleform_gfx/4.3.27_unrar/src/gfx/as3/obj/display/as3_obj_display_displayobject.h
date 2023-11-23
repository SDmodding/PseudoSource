// File Line: 579
// RVA: 0x7FB440
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_display::DisplayObject::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_display::DisplayObject *t)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v4; // rax
  int v6; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v7; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v8; // [rsp+50h] [rbp+18h]

  v6 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)t->pVM->MHeap->vfptr->Alloc(
                                                                      t->pVM->MHeap,
                                                                      t->MemSize,
                                                                      &v6);
  v7 = v4;
  v8 = v4;
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::DisplayObject(v4, t);
  result->pV = v4;
  return result;
}

