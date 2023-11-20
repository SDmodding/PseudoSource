// File Line: 111
// RVA: 0x8EA020
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_sampler::NewObjectSample> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_sampler::NewObjectSample::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_sampler::NewObjectSample> *result, Scaleform::GFx::AS3::InstanceTraits::fl_sampler::NewObjectSample *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_sampler::NewObjectSample *v2; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_sampler::NewObjectSample> *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl::Object *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_sampler::NewObjectSample *v5; // rbx

  v2 = t;
  v3 = result;
  v4 = (Scaleform::GFx::AS3::Instances::fl::Object *)Scaleform::GFx::AS3::Traits::Alloc((Scaleform::GFx::AS3::Traits *)&t->vfptr);
  v5 = (Scaleform::GFx::AS3::Instances::fl_sampler::NewObjectSample *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v4, (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_sampler::Sample::`vftable';
    v5->stack.pObject = 0i64;
    v5->time = 0.0;
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_sampler::NewObjectSample::`vftable';
    v5->id = 0.0;
    v5->type.pObject = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  v3->pV = v5;
  return v3;
}

