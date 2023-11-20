// File Line: 137
// RVA: 0x8E9B20
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_sensors::Accelerometer::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer> *result, Scaleform::GFx::AS3::InstanceTraits::fl_sensors::Accelerometer *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_sensors::Accelerometer *v2; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer> *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer *v4; // rax

  v2 = t;
  v3 = result;
  v4 = (Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer *)Scaleform::GFx::AS3::Traits::Alloc((Scaleform::GFx::AS3::Traits *)&t->vfptr);
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer::Accelerometer(
      v4,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
  v3->pV = v4;
  return v3;
}

