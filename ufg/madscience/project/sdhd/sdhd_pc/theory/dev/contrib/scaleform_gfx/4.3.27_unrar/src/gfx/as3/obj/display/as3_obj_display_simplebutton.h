// File Line: 227
// RVA: 0x7FD600
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::SimpleButton> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_display::SimpleButton::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::SimpleButton> *result, Scaleform::GFx::AS3::InstanceTraits::fl_display::SimpleButton *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_display::SimpleButton *v2; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::SimpleButton> *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_display::SimpleButton *v5; // rbx
  int v7; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v8; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v9; // [rsp+60h] [rbp+18h]

  v2 = t;
  v3 = result;
  v7 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)t->pVM->MHeap->vfptr->Alloc(
                                                                      t->pVM->MHeap,
                                                                      t->MemSize,
                                                                      (Scaleform::AllocInfo *)&v7);
  v5 = (Scaleform::GFx::AS3::Instances::fl_display::SimpleButton *)v4;
  v8 = v4;
  v9 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::DisplayObject(
      v4,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject::`vftable';
    v5->pContextMenu.pObject = 0i64;
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_display::SimpleButton::`vftable';
    v5->OverStateObject.pObject = 0i64;
    v5->UpStateObject.pObject = 0i64;
    v5->DownStateObject.pObject = 0i64;
    v5->HitTestStateObject.pObject = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  v3->pV = v5;
  return v3;
}

