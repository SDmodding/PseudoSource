// File Line: 112
// RVA: 0x8E9CE0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_ui::ContextMenuClipboardItems> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_ui::ContextMenuClipboardItems::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_ui::ContextMenuClipboardItems> *result, Scaleform::GFx::AS3::InstanceTraits::fl_ui::ContextMenuClipboardItems *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_ui::ContextMenuClipboardItems *v2; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_ui::ContextMenuClipboardItems> *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl::Object *v4; // rax
  Scaleform::GFx::AS3::Instances::fl::Object *v5; // rbx

  v2 = t;
  v3 = result;
  v4 = (Scaleform::GFx::AS3::Instances::fl::Object *)Scaleform::GFx::AS3::Traits::Alloc((Scaleform::GFx::AS3::Traits *)&t->vfptr);
  v5 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v4, (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_ui::ContextMenuClipboardItems::`vftable';
    LODWORD(v5[1].vfptr) = 0;
    BYTE4(v5[1].vfptr) = 1;
  }
  else
  {
    v5 = 0i64;
  }
  v3->pV = (Scaleform::GFx::AS3::Instances::fl_ui::ContextMenuClipboardItems *)v5;
  return v3;
}

