// File Line: 114
// RVA: 0x8EA4D0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::TextLineMetrics> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_text::TextLineMetrics::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::TextLineMetrics> *result, Scaleform::GFx::AS3::InstanceTraits::fl_text::TextLineMetrics *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_text::TextLineMetrics *v2; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::TextLineMetrics> *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl::Object *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_text::TextLineMetrics *v5; // rbx

  v2 = t;
  v3 = result;
  v4 = (Scaleform::GFx::AS3::Instances::fl::Object *)Scaleform::GFx::AS3::Traits::Alloc((Scaleform::GFx::AS3::Traits *)&t->vfptr);
  v5 = (Scaleform::GFx::AS3::Instances::fl_text::TextLineMetrics *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v4, (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_text::TextLineMetrics::`vftable';
    v5->ascent = 0.0;
    v5->descent = 0.0;
    v5->height = 0.0;
    v5->leading = 0.0;
    v5->width = 0.0;
    v5->x = 0.0;
  }
  else
  {
    v5 = 0i64;
  }
  v3->pV = v5;
  return v3;
}

