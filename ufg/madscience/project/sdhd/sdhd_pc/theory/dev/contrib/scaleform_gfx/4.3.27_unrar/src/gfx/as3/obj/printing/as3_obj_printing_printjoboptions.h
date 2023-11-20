// File Line: 108
// RVA: 0x8EA0B0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_printing::PrintJobOptions> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_printing::PrintJobOptions::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_printing::PrintJobOptions> *result, Scaleform::GFx::AS3::InstanceTraits::fl_printing::PrintJobOptions *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_printing::PrintJobOptions *v2; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_printing::PrintJobOptions> *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl::Object *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_printing::PrintJobOptions *v5; // rbx

  v2 = t;
  v3 = result;
  v4 = (Scaleform::GFx::AS3::Instances::fl::Object *)Scaleform::GFx::AS3::Traits::Alloc((Scaleform::GFx::AS3::Traits *)&t->vfptr);
  v5 = (Scaleform::GFx::AS3::Instances::fl_printing::PrintJobOptions *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v4, (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_printing::PrintJobOptions::`vftable;
    v5->printAsBitmap = 0;
  }
  else
  {
    v5 = 0i64;
  }
  v3->pV = v5;
  return v3;
}

