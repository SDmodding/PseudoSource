// File Line: 220
// RVA: 0x7FC610
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_display::InteractiveObject::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_display::InteractiveObject *t)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *v5; // rbx
  int v7; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v8; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v9; // [rsp+60h] [rbp+18h]

  v7 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)t->pVM->MHeap->vfptr->Alloc(
                                                                      t->pVM->MHeap,
                                                                      t->MemSize,
                                                                      &v7);
  v5 = (Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *)v4;
  v8 = v4;
  v9 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::DisplayObject(v4, t);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject::`vftable;
    v5->pContextMenu.pObject = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  result->pV = v5;
  return result;
}

