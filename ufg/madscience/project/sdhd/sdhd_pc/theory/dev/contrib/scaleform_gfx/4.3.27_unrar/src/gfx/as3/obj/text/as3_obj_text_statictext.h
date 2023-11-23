// File Line: 130
// RVA: 0x8EA330
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::StaticText> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_text::StaticText::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::StaticText> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_text::StaticText *t)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_text::StaticText *v5; // rbx

  v4 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v5 = (Scaleform::GFx::AS3::Instances::fl_text::StaticText *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::DisplayObject(v4, t);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_text::StaticText::`vftable;
  }
  else
  {
    v5 = 0i64;
  }
  result->pV = v5;
  return result;
}

