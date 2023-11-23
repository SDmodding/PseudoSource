// File Line: 164
// RVA: 0x8E9EF0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::Font> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_text::Font::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::Font> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_text::Font *t)
{
  Scaleform::GFx::AS3::Instances::fl_text::Font *v4; // rax

  v4 = (Scaleform::GFx::AS3::Instances::fl_text::Font *)Scaleform::GFx::AS3::Traits::Alloc(t);
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_text::Font::Font(v4, t);
  result->pV = v4;
  return result;
}

