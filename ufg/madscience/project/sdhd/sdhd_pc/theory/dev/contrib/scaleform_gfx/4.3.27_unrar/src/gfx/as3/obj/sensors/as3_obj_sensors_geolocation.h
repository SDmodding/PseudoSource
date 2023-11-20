// File Line: 137
// RVA: 0x8E9F40
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_sensors::Geolocation::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation> *result, Scaleform::GFx::AS3::InstanceTraits::fl_sensors::Geolocation *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_sensors::Geolocation *v2; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation> *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *v4; // rax

  v2 = t;
  v3 = result;
  v4 = (Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *)Scaleform::GFx::AS3::Traits::Alloc((Scaleform::GFx::AS3::Traits *)&t->vfptr);
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation::Geolocation(
      v4,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
  v3->pV = v4;
  return v3;
}

