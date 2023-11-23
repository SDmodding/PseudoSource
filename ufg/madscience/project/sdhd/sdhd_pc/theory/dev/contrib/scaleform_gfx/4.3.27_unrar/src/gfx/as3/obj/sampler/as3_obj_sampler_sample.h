// File Line: 110
// RVA: 0x8EA1C0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_sampler::Sample> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_sampler::Sample::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_sampler::Sample> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_sampler::Sample *t)
{
  Scaleform::GFx::AS3::Instances::fl::Object *v4; // rax
  Scaleform::GFx::AS3::Instances::fl::Object *v5; // rbx

  v4 = (Scaleform::GFx::AS3::Instances::fl::Object *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v5 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v4, t);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_sampler::Sample::`vftable;
    v5[1].vfptr = 0i64;
    v5[1].pRCCRaw = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  result->pV = (Scaleform::GFx::AS3::Instances::fl_sampler::Sample *)v5;
  return result;
}

