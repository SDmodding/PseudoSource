// File Line: 735
// RVA: 0x8EA410
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::TextField> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_text::TextField::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::TextField> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_text::TextField *t)
{
  Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_text::TextField *v5; // rbx

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v5 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject::InteractiveObject(v4, t);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_text::TextField::`vftable;
  }
  else
  {
    v5 = 0i64;
  }
  result->pV = v5;
  return result;
}

