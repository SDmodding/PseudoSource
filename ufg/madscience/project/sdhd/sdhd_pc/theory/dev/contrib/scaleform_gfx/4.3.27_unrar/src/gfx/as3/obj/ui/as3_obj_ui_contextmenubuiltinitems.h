// File Line: 115
// RVA: 0x8E9C60
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_ui::ContextMenuBuiltInItems> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_ui::ContextMenuBuiltInItems::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_ui::ContextMenuBuiltInItems> *result, Scaleform::GFx::AS3::InstanceTraits::fl_ui::ContextMenuBuiltInItems *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_ui::ContextMenuBuiltInItems *v2; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_ui::ContextMenuBuiltInItems> *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl::Object *v4; // rax
  Scaleform::GFx::AS3::Instances::fl::Object *v5; // rbx

  v2 = t;
  v3 = result;
  v4 = (Scaleform::GFx::AS3::Instances::fl::Object *)Scaleform::GFx::AS3::Traits::Alloc((Scaleform::GFx::AS3::Traits *)&t->vfptr);
  v5 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v4, (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_ui::ContextMenuBuiltInItems::`vftable;
    LODWORD(v5[1].vfptr) = 16843009;
    HIDWORD(v5[1].vfptr) = 16843009;
  }
  else
  {
    v5 = 0i64;
  }
  v3->pV = (Scaleform::GFx::AS3::Instances::fl_ui::ContextMenuBuiltInItems *)v5;
  return v3;
}

