// File Line: 200
// RVA: 0x8EA560
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_text::TextSnapshot::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot> *result, Scaleform::GFx::AS3::InstanceTraits::fl_text::TextSnapshot *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_text::TextSnapshot *v2; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot> *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl::Object *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *v5; // rbx

  v2 = t;
  v3 = result;
  v4 = (Scaleform::GFx::AS3::Instances::fl::Object *)Scaleform::GFx::AS3::Traits::Alloc((Scaleform::GFx::AS3::Traits *)&t->vfptr);
  v5 = (Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v4, (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot::`vftable;
  }
  else
  {
    v5 = 0i64;
  }
  v3->pV = v5;
  return v3;
}

