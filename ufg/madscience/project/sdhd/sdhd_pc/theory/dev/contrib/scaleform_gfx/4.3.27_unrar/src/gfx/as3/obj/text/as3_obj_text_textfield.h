// File Line: 735
// RVA: 0x8EA410
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::TextField> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_text::TextField::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::TextField> *result, Scaleform::GFx::AS3::InstanceTraits::fl_text::TextField *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_text::TextField *v2; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::TextField> *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_text::TextField *v5; // rbx

  v2 = t;
  v3 = result;
  v4 = (Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *)Scaleform::GFx::AS3::Traits::Alloc((Scaleform::GFx::AS3::Traits *)&t->vfptr);
  v5 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject::InteractiveObject(
      v4,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_text::TextField::`vftable;
  }
  else
  {
    v5 = 0i64;
  }
  v3->pV = v5;
  return v3;
}

