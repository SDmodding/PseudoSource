// File Line: 110
// RVA: 0x8E9B70
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::CSMSettings> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_text::CSMSettings::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::CSMSettings> *result, Scaleform::GFx::AS3::InstanceTraits::fl_text::CSMSettings *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_text::CSMSettings *v2; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::CSMSettings> *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl::Object *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_text::CSMSettings *v5; // rbx

  v2 = t;
  v3 = result;
  v4 = (Scaleform::GFx::AS3::Instances::fl::Object *)Scaleform::GFx::AS3::Traits::Alloc((Scaleform::GFx::AS3::Traits *)&t->vfptr);
  v5 = (Scaleform::GFx::AS3::Instances::fl_text::CSMSettings *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v4, (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_text::CSMSettings::`vftable';
    v5->fontSize = 0.0;
    v5->insideCutoff = 0.0;
    v5->outsideCutoff = 0.0;
  }
  else
  {
    v5 = 0i64;
  }
  v3->pV = v5;
  return v3;
}

