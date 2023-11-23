// File Line: 110
// RVA: 0x8E9B70
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::CSMSettings> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_text::CSMSettings::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::CSMSettings> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_text::CSMSettings *t)
{
  Scaleform::GFx::AS3::Instances::fl::Object *v4; // rax
  Scaleform::GFx::AS3::Instances::fl::Object *v5; // rbx

  v4 = (Scaleform::GFx::AS3::Instances::fl::Object *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v5 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v4, t);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_text::CSMSettings::`vftable;
    v5[1].vfptr = 0i64;
    v5[1].pRCCRaw = 0i64;
    v5[1].pNext = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  result->pV = (Scaleform::GFx::AS3::Instances::fl_text::CSMSettings *)v5;
  return result;
}

