// File Line: 392
// RVA: 0x8EA480
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_text::TextFormat::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *result, Scaleform::GFx::AS3::InstanceTraits::fl_text::TextFormat *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_text::TextFormat *v2; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl_text::TextFormat *v4; // rax

  v2 = t;
  v3 = result;
  v4 = (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)Scaleform::GFx::AS3::Traits::Alloc((Scaleform::GFx::AS3::Traits *)&t->vfptr);
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_text::TextFormat::TextFormat(
      v4,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
  v3->pV = v4;
  return v3;
}

