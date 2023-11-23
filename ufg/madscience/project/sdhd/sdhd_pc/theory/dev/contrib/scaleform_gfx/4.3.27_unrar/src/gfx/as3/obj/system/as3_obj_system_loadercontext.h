// File Line: 115
// RVA: 0x8E9F90
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_system::LoaderContext> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_system::LoaderContext::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_system::LoaderContext> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_system::LoaderContext *t)
{
  Scaleform::GFx::AS3::Instances::fl::Object *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_system::LoaderContext *v5; // rbx

  v4 = (Scaleform::GFx::AS3::Instances::fl::Object *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v5 = (Scaleform::GFx::AS3::Instances::fl_system::LoaderContext *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v4, t);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_system::LoaderContext::`vftable;
    v5->allowLoadBytesCodeExecution = 0;
    v5->applicationDomain.pObject = 0i64;
    v5->checkPolicyFile = 0;
    v5->securityDomain.pObject = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  result->pV = v5;
  return result;
}

