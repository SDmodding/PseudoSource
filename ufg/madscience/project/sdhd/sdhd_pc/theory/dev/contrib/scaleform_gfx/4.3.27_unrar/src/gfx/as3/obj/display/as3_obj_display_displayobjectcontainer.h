// File Line: 253
// RVA: 0x7FB4B0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_display::DisplayObjectContainer::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_display::DisplayObjectContainer *t)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *v5; // rbx
  int v7; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v8; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v9; // [rsp+60h] [rbp+18h]

  v7 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)t->pVM->MHeap->vfptr->Alloc(
                                                                      t->pVM->MHeap,
                                                                      t->MemSize,
                                                                      &v7);
  v5 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *)v4;
  v8 = v4;
  v9 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::DisplayObject(v4, t);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject::`vftable;
    v5->pContextMenu.pObject = 0i64;
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::`vftable;
  }
  else
  {
    v5 = 0i64;
  }
  result->pV = v5;
  return result;
}

